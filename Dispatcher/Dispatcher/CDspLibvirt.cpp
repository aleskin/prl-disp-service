/*
 * Copyright (c) 2015 Parallels IP Holdings GmbH
 *
 * This file is part of Virtuozzo Core. Virtuozzo Core is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later
 * version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * Our contact details: Parallels IP Holdings GmbH, Vordergasse 59, 8200
 * Schaffhausen, Switzerland.
 */

#include "CDspService.h"
#include "CDspLibvirt_p.h"
#include <QtCore/qmetatype.h>
#include "CDspVmStateSender.h"
#include "CDspVmNetworkHelper.h"
#include "Tasks/Task_CreateProblemReport.h"
#include "Tasks/Task_BackgroundJob.h"
#include "Tasks/Task_ManagePrlNetService.h"
#include "Tasks/Task_EditVm.h"
#include <prlcommon/PrlUuid/PrlUuid.h>
#include <Libraries/PrlNetworking/netconfig.h>
#include <Libraries/StatesUtils/StatesHelper.h>
#include <Libraries/Transponster/Direct.h>
#include <Libraries/Transponster/Reverse.h>
#include <Libraries/Transponster/Reverse_p.h>

namespace Libvirt
{
namespace Instrument
{
///////////////////////////////////////////////////////////////////////////////
// struct Domain

Domain::Domain(virDomainPtr model_, QSharedPointer<Model::Domain> view_):
	m_agent(model_), m_view(view_)
{
	virDomainRef(model_);
}

void Domain::run()
{
	VIRTUAL_MACHINE_STATE s;
	Result r = m_agent.getState(s);

	CVmConfiguration c;
	if (m_agent.getConfig(c).isSucceed())
	{
		CVmConfiguration runtime;
		if (r.isSucceed() && (s == VMS_RUNNING || s == VMS_PAUSED)
				&& m_agent.getConfig(runtime, true).isSucceed())
			Vm::Config::Repairer<Vm::Config::revise_types>::type::do_(c, runtime);

		m_view->setConfig(c);
	}

	if (r.isSucceed() && !QMetaObject::invokeMethod(m_view.data(), "setState", Q_ARG(VIRTUAL_MACHINE_STATE, s)))
		WRITE_TRACE(DBG_FATAL, "Unable to invoke VM 'setState' method");
}

namespace Agent
{
namespace Parameters
{
///////////////////////////////////////////////////////////////////////////////
// struct Builder

Builder::Builder() : m_pointer(NULL), m_size(0), m_capacity(0)
{
}

Builder::~Builder()
{
	virTypedParamsFree(m_pointer, m_size);
}

bool Builder::add(const char *key_, const QString& value_)
{
	return virTypedParamsAddString(&m_pointer, &m_size, &m_capacity, key_, QSTR2UTF8(value_)) == 0;
}

Result_type Builder::extract()
{
	Result_type r(QSharedPointer<virTypedParameter>(m_pointer, boost::bind(virTypedParamsFree, _1, m_size)),
		m_size);
	m_pointer = NULL;
	m_capacity = 0;
	m_size = 0;
	return r;
}

} // namespace Parameters

namespace Vm
{
namespace Migration
{
///////////////////////////////////////////////////////////////////////////////
// struct Offline

Result Offline::operator()(Parameters::Builder& builder_)
{
	const QString n = m_config->getVmIdentification()->getVmName();
	if (!builder_.add(VIR_MIGRATE_PARAM_DEST_NAME, n))
		return Failure(PRL_ERR_FAILURE);

	Prl::Expected<QString, Error::Simple> x = m_agent.mixup(*m_config);
	if (x.isFailed())
		return x.error();

	if (!builder_.add(VIR_MIGRATE_PARAM_DEST_XML, x.value()))
		return Failure(PRL_ERR_FAILURE);

	return Result();
}

///////////////////////////////////////////////////////////////////////////////
// struct Online

Result Online::operator()(Parameters::Builder& builder_)
{
	Result e = Offline::operator()(builder_);
	if (e.isFailed())
		return e;

	foreach (CVmHardDisk* d, m_disks)
	{
		QString t = Transponster::Device::Clustered::Model
			<CVmHardDisk>(*d).getTargetName();
		if (!builder_.add(VIR_MIGRATE_PARAM_MIGRATE_DISKS, t))
			return Failure(PRL_ERR_FAILURE);
	}

	return Result();
}


} // namespace Migration
} // namespace Vm

///////////////////////////////////////////////////////////////////////////////
// struct Config

Config::Config(QSharedPointer<virDomain> domain_,
		QSharedPointer<virConnect> link_,
		unsigned int flags_) :
	m_domain(domain_), m_link(link_), m_flags(flags_)
{
}

char* Config::read_() const
{
	return virDomainGetXMLDesc(m_domain.data(), m_flags | VIR_DOMAIN_XML_SECURE);
}

Prl::Expected<QString, Error::Simple> Config::read() const
{
	char* x = read_();
	if (NULL == x)
		return Error::Simple(PRL_ERR_VM_GET_CONFIG_FAILED);

	QString s = x;
	free(x);
	return s;
}

Result Config::convert(CVmConfiguration& dst_) const
{
	Prl::Expected<VtInfo, Error::Simple> i = Host(m_link).getVt();
	if (i.isFailed())
		return i.error();

	char* x = read_();
	if (NULL == x)
		return Error::Simple(PRL_ERR_VM_GET_CONFIG_FAILED);

//	WRITE_TRACE(DBG_FATAL, "xml:\n%s", x);
	Transponster::Vm::Direct::Vm u(x);
	if (PRL_FAILED(Transponster::Director::domain(u, i.value())))
		return Error::Simple(PRL_ERR_PARSE_VM_CONFIG);

	CVmConfiguration* output = u.getResult();
	if (NULL == output)
		return Error::Simple(PRL_ERR_FAILURE);

	output->getVmIdentification()
		->setServerUuid(CDspService::instance()
                        ->getDispConfigGuard().getDispConfig()
                        ->getVmServerIdentification()->getServerUuid());
	dst_ = *output;
	delete output;
	return Result();
}

Prl::Expected<QString, Error::Simple> Config::mixup(const CVmConfiguration& value_) const
{
	Prl::Expected<VtInfo, Error::Simple> i = Host(m_link).getVt();
	if (i.isFailed())
		return i.error();

	Transponster::Vm::Reverse::Mixer u(value_, read_());
	PRL_RESULT res = Transponster::Director::domain(u, i.value());
	if (PRL_FAILED(res))
		return Error::Simple(res);

	return u.getResult();
}

} // namespace Agent

namespace Breeding
{
///////////////////////////////////////////////////////////////////////////////
// struct Vm

void Vm::operator()(Agent::Hub& hub_)
{
	QList<Agent::Vm::Unit> a;
	hub_.vms().all(a);
	foreach (Agent::Vm::Unit m, a)
	{
		QString u;
		m.getUuid(u);
		QSharedPointer<Model::Domain> v = m_view->add(u);
		if (v.isNull())
			v = m_view->find(u);

		if (!v.isNull())
			Domain(m, v).run();
	}
}

///////////////////////////////////////////////////////////////////////////////
// struct Network

Network::Network(const QFileInfo& config_):
	m_digested(config_.absoluteDir(), QString("digested.").append(config_.fileName()))
{
}

void Network::operator()(Agent::Hub& hub_)
{
	if (m_digested.exists())
		return;

	CParallelsNetworkConfig f;
	PRL_RESULT e = PrlNet::ReadNetworkConfig(f);
	if (PRL_ERR_FILE_NOT_FOUND == e)
		PrlNet::FillDefaultConfiguration(&f);
	else if (PRL_FAILED(e))
	{
		WRITE_TRACE(DBG_FATAL, "cannot read the networks config: %s",
			PRL_RESULT_TO_STRING(e));
		return;
	}
	QTemporaryFile t(m_digested.absoluteFilePath());
	if (!t.open())
	{
		WRITE_TRACE(DBG_FATAL, "cannot create a temporary file");
		return;
	}
	if (PRL_FAILED(e = f.saveToFile(&t)))
	{
		WRITE_TRACE(DBG_FATAL, "cannot save the xml model into a temporary file: %s",
			PRL_RESULT_TO_STRING(e));
		return;
	}
	CVirtualNetworks* s = f.getVirtualNetworks();
	if (NULL != s)
	{
		foreach (CVirtualNetwork* k, s->m_lstVirtualNetwork)
		{
			if (NULL != k && k->isEnabled())
				::Network::Dao(hub_).create(*k);
		}
	}
	if (!QFile::rename(t.fileName(), m_digested.absoluteFilePath()))
	{
		WRITE_TRACE(DBG_FATAL, "cannot rename %s -> %s",
			QSTR2UTF8(t.fileName()),
			QSTR2UTF8(m_digested.absoluteFilePath()));
		return;
	}
	t.setAutoRemove(false);
}

///////////////////////////////////////////////////////////////////////////////
// struct Subject

Subject::Subject(QSharedPointer<virConnect> libvirtd_, QSharedPointer<Model::System> view_):
	m_vm(view_), m_network(ParallelsDirs::getNetworkConfigFilePath())
{
	m_hub.setLink(libvirtd_);
}

void Subject::run()
{
	m_vm(m_hub);
	m_network(m_hub);
}

} // namespace Breeding

///////////////////////////////////////////////////////////////////////////////
// struct Performance

void Performance::run()
{
	QList<Agent::Vm::Unit> a;
	m_agent.all(a);
	foreach (Agent::Vm::Unit m, a)
	{
		QString u;
		m.getUuid(u);
		QSharedPointer<Model::Domain> v = m_view->find(u);
		if (v.isNull())
			continue;

		Agent::Vm::Performance p = m.getPerformance();
		VIRTUAL_MACHINE_STATE s = VMS_UNKNOWN;
		m.getState(s);
		if (VMS_RUNNING == s)
		{
			quint64 u;
			p.getCpu(u);
			p.getMemory();
		}
			
	}
}

/*
void Performance::pull(Agent::Vm::Unit agent_)
{
	QString u;
	m.getUuid(u);
	QSharedPointer<Model::Domain> d = m_view->find(domain_);
	if (d.isNull())
		return;

	int n;
	n = virDomainGetCPUStats(&domain_, NULL, 0, -1, 1, 0);
	if (0 < n)
	{
		QVector<virTypedParameter> q(n);
		virDomainGetCPUStats(&domain_, q.data(), n, -1, 1, 0);
		d->setCpuUsage();
	}
	n = virDomainMemoryStats(&domain_, NULL, 0,
		VIR_DOMAIN_MEMORY_STAT_UNUSED |
		VIR_DOMAIN_MEMORY_STAT_AVAILABLE |
		VIR_DOMAIN_MEMORY_STAT_ACTUAL_BALLOON);
	if (0 < n)
	{
		QVector<virDomainMemoryStatStruct> q(n);
		virDomainMemoryStats(&domain_, q.data(), n,
			VIR_DOMAIN_MEMORY_STAT_UNUSED |
			VIR_DOMAIN_MEMORY_STAT_AVAILABLE |
			VIR_DOMAIN_MEMORY_STAT_ACTUAL_BALLOON);
		d->setMemoryUsage();
	}
//	virDomainBlockStats();
//	virDomainInterfaceStats();
}
*/
} // namespace Instrument

namespace Callback
{
///////////////////////////////////////////////////////////////////////////////
// struct Timeout

Timeout::Timeout(virEventTimeoutCallback impl_, int id_): Base(id_), m_impl(impl_)
{
	this->connect(&m_timer, SIGNAL(timeout()), SLOT(handle()));
}

Timeout::~Timeout()
{
	m_timer.disconnect(this);
}

void Timeout::enable(int interval_)
{
	m_timer.stop();
	if (0 <= interval_)
		m_timer.start(1000 * interval_);
}

void Timeout::handle()
{
	m_impl(getId(), getOpaque());
}

///////////////////////////////////////////////////////////////////////////////
// struct Socket

Socket::Socket(int socket_, virEventHandleCallback impl_, int id_):
	Base(id_), m_impl(impl_), m_read(socket_, QSocketNotifier::Read),
	m_write(socket_, QSocketNotifier::Write),
	m_error(socket_, QSocketNotifier::Exception)
{
	m_read.setEnabled(false);
	this->connect(&m_read, SIGNAL(activated(int)), SLOT(read(int)));
	m_error.setEnabled(false);
	this->connect(&m_error, SIGNAL(activated(int)), SLOT(error(int)));
	m_write.setEnabled(false);
	this->connect(&m_write, SIGNAL(activated(int)), SLOT(write(int)));
}

Socket::~Socket()
{
	m_read.disconnect(this);
	m_error.disconnect(this);
	m_write.disconnect(this);
}

void Socket::enable(int events_)
{
	m_read.setEnabled(VIR_EVENT_HANDLE_READABLE & events_);
	m_error.setEnabled(true);
	m_write.setEnabled(VIR_EVENT_HANDLE_WRITABLE & events_);
}

void Socket::disable()
{
	m_read.setEnabled(false);
	m_error.setEnabled(false);
	m_write.setEnabled(false);
}

void Socket::read(int socket_)
{
	m_impl(getId(), socket_, VIR_EVENT_HANDLE_READABLE, getOpaque());
}

void Socket::error(int socket_)
{
	m_impl(getId(), socket_, VIR_EVENT_HANDLE_ERROR, getOpaque());
}

void Socket::write(int socket_)
{
	m_impl(getId(), socket_, VIR_EVENT_HANDLE_WRITABLE, getOpaque());
}

///////////////////////////////////////////////////////////////////////////////
// struct Hub

void Hub::add(int id_, virEventTimeoutCallback callback_)
{
	m_timeoutMap.insert(id_, new Timeout(callback_, id_));
}

void Hub::add(int id_, int socket_, virEventHandleCallback callback_)
{
	m_socketMap.insert(id_, new Socket(socket_, callback_, id_));
}

void Hub::setOpaque(int id_, void* opaque_, virFreeCallback free_)
{
	boost::ptr_map<int, Socket>::iterator a = m_socketMap.find(id_);
	if (m_socketMap.end() != a)
		return a->second->setOpaque(opaque_, free_);

	boost::ptr_map<int, Timeout>::iterator b = m_timeoutMap.find(id_);
	if (m_timeoutMap.end() != b)
		return b->second->setOpaque(opaque_, free_);
}

void Hub::setEvents(int id_, int value_)
{
	boost::ptr_map<int, Socket>::iterator p = m_socketMap.find(id_);
	if (m_socketMap.end() != p)
		return p->second->enable(value_);
}

void Hub::setInterval(int id_, int value_)
{
	boost::ptr_map<int, Timeout>::iterator p = m_timeoutMap.find(id_);
	if (m_timeoutMap.end() != p)
		return p->second->enable(value_);
}

void Hub::remove(int id_)
{
	boost::ptr_map<int, Sweeper>::iterator p = m_sweeperMap.find(id_);
	if (m_sweeperMap.end() != p)
	{
		m_sweeperMap.release(p).release()->deleteLater();
		return;
	}
	Sweeper* s = new Sweeper(id_);
	s->startTimer(0);
	boost::ptr_map<int, Socket>::iterator x = m_socketMap.find(id_);
	if (m_socketMap.end() != x)
	{
		boost::ptr_map<int, Socket>::auto_type p = m_socketMap.release(x);
		p->disable();
		s->care(p.release());
	}
	boost::ptr_map<int, Timeout>::iterator y = m_timeoutMap.find(id_);
	if (m_timeoutMap.end() != y)
	{
		boost::ptr_map<int, Timeout>::auto_type p = m_timeoutMap.release(y);
		p->disable();
		s->care(p.release());
	}
	m_sweeperMap.insert(id_, s);
}

///////////////////////////////////////////////////////////////////////////////
// struct Access

void Access::setHub(const QSharedPointer<Hub>& hub_)
{
	qRegisterMetaType<virFreeCallback>("virFreeCallback");
	qRegisterMetaType<virEventHandleCallback>("virEventHandleCallback");
	qRegisterMetaType<virEventTimeoutCallback>("virEventTimeoutCallback");
	m_generator = QAtomicInt(1);
	m_hub = hub_;
}

int Access::add(int interval_, virEventTimeoutCallback callback_, void* opaque_, virFreeCallback free_)
{
	QSharedPointer<Hub> h = m_hub.toStrongRef();
	if (h.isNull())
		return -1;

	int output = m_generator.fetchAndAddOrdered(1);
	QMetaObject::invokeMethod(h.data(), "add", Q_ARG(int, output),
		Q_ARG(virEventTimeoutCallback, callback_));
	QMetaObject::invokeMethod(h.data(), "setOpaque", Q_ARG(int, output), Q_ARG(void*, opaque_),
		Q_ARG(virFreeCallback, free_));
	QMetaObject::invokeMethod(h.data(), "setInterval", Q_ARG(int, output), Q_ARG(int, interval_));
	return output;
}

int Access::add(int socket_, int events_, virEventHandleCallback callback_, void* opaque_, virFreeCallback free_)
{
	QSharedPointer<Hub> h = m_hub.toStrongRef();
	if (h.isNull())
		return -1;

	int output = m_generator.fetchAndAddOrdered(1);
	QMetaObject::invokeMethod(h.data(), "add", Q_ARG(int, output), Q_ARG(int, socket_),
		Q_ARG(virEventHandleCallback, callback_));
	QMetaObject::invokeMethod(h.data(), "setOpaque", Q_ARG(int, output), Q_ARG(void*, opaque_),
		Q_ARG(virFreeCallback, free_));
	QMetaObject::invokeMethod(h.data(), "setEvents", Q_ARG(int, output), Q_ARG(int, events_));
	return output;
}

void Access::setEvents(int id_, int value_)
{
	QSharedPointer<Hub> h = m_hub.toStrongRef();
	if (h.isNull())
		return;

	QMetaObject::invokeMethod(h.data(), "setEvents", Q_ARG(int, id_), Q_ARG(int, value_));
}

void Access::setInterval(int id_, int value_)
{
	QSharedPointer<Hub> h = m_hub.toStrongRef();
	if (h.isNull())
		return;

	QMetaObject::invokeMethod(h.data(), "setInterval", Q_ARG(int, id_), Q_ARG(int, value_));
}

int Access::remove(int id_)
{
	QSharedPointer<Hub> h = m_hub.toStrongRef();
	if (h.isNull())
		return -1;

	QMetaObject::invokeMethod(h.data(), "remove", Q_ARG(int, id_));
	return 0;
}

static Access g_access;

///////////////////////////////////////////////////////////////////////////////
// struct Sweeper

void Sweeper::timerEvent(QTimerEvent* event_)
{
	if (NULL != event_)
		killTimer(event_->timerId());

	m_pet1.reset();
	m_pet2.reset();
	QSharedPointer<Hub> h = g_access.getHub();
	if (!h.isNull())
		h->remove(m_id);	
}

namespace Plain
{
template<class T>
void delete_(void* opaque_)
{
        delete (T* )opaque_;
}

int addSocket(int socket_, int events_, virEventHandleCallback callback_,
                void* opaque_, virFreeCallback free_)
{
	int output = g_access.add(socket_, events_, callback_, opaque_, free_);
	WRITE_TRACE(DBG_FATAL, "add socket %d %d", socket_, output);
	return output;
//	return g_access.add(socket_, events_, callback_, opaque_, free_);
}

void setSocket(int id_, int events_)
{
	return g_access.setEvents(id_, events_);
}

int addTimeout(int interval_, virEventTimeoutCallback callback_,
                void* opaque_, virFreeCallback free_)
{
	return g_access.add(interval_, callback_, opaque_, free_);
}

void setTimeout(int id_, int interval_)
{
	return g_access.setInterval(id_, interval_);
}

int remove(int id_)
{
	return g_access.remove(id_);
}

int wakeUp(virConnectPtr , virDomainPtr domain_, int , void* opaque_)
{
	Model::Coarse* v = (Model::Coarse* )opaque_;
	v->setState(domain_, VMS_RUNNING);
	return 0;
}

int reboot(virConnectPtr connect_, virDomainPtr domain_, void* opaque_)
{
	return wakeUp(connect_, domain_, 0, opaque_);
}

int deviceConnect(virConnectPtr , virDomainPtr domain_, const char *device_,
	void *opaque_)
{
	Q_UNUSED(device_);
	Q_UNUSED(domain_);
	Q_UNUSED(opaque_);
/*
	// XXX: enable this for vme* devices when network device hotplug is fixed
	Model::Coarse* v = (Model::Coarse* )opaque_;
	QSharedPointer<Model::Domain> d = v->access(domain_);
	if (!d.isNull())
	{
		CVmConfiguration c = d->getConfig();
		Instrument::Traffic::Accounting(c.getVmIdentification()->getVmUuid())(device_);
	}
*/
	return 0;
}

int deviceDisconnect(virConnectPtr , virDomainPtr domain_, const char* device_,
                        void* opaque_)
{
	Q_UNUSED(device_);
	Q_UNUSED(domain_);
	Q_UNUSED(opaque_);
/*
        Adapter::System* b = (Adapter::System* )opaque_;
        Adapter::Domain a = b.getDomain(*domain_);
        SmartPtr<CVmConfiguration> x = a.getAdaptee().getConfig();
        // update the device state
	a.getAdaptee().setConfig(x);
*/
	return 0;
}

int trayChange(virConnectPtr , virDomainPtr domain_,
		const char* device_, int reason_, void* opaque_)
{
	Model::Coarse* v = (Model::Coarse* )opaque_;
	if (reason_ == 0) // Tray opened
		v->disconnectCd(domain_, device_);
	return 0;
}

int lifecycle(virConnectPtr , virDomainPtr domain_, int event_,
                int detail_, void* opaque_)
{

	QSharedPointer<Model::Domain> d;
	Model::Coarse* v = (Model::Coarse* )opaque_;
	switch (event_)
	{
	case VIR_DOMAIN_EVENT_DEFINED:
		if (detail_ == VIR_DOMAIN_EVENT_DEFINED_FROM_SNAPSHOT)
			v->prepareToSwitch(domain_);
		break;
	case VIR_DOMAIN_EVENT_UNDEFINED:
		v->remove(domain_);
		return 0;
	case VIR_DOMAIN_EVENT_STARTED:
		if (detail_ == VIR_DOMAIN_EVENT_STARTED_FROM_SNAPSHOT)
			break;
		// This event means that live migration is started, but VM has
		// not been defined yet. Ignore it.
		if (detail_ == VIR_DOMAIN_EVENT_STARTED_MIGRATED)
			return 0;
		v->setState(domain_, VMS_RUNNING);
		return 0;
	case VIR_DOMAIN_EVENT_RESUMED:
		if (detail_ == VIR_DOMAIN_EVENT_RESUMED_FROM_SNAPSHOT)
			break;

		v->setState(domain_, VMS_RUNNING);
		return 0;
	case VIR_DOMAIN_EVENT_SUSPENDED:
		if (detail_ == VIR_DOMAIN_EVENT_SUSPENDED_FROM_SNAPSHOT)
		{
			v->prepareToSwitch(domain_);
			break;
		}

		switch (detail_)
		{
		case VIR_DOMAIN_EVENT_SUSPENDED_PAUSED:
		case VIR_DOMAIN_EVENT_SUSPENDED_MIGRATED:
		case VIR_DOMAIN_EVENT_SUSPENDED_IOERROR:
		case VIR_DOMAIN_EVENT_SUSPENDED_WATCHDOG:
		case VIR_DOMAIN_EVENT_SUSPENDED_RESTORED:
		case VIR_DOMAIN_EVENT_SUSPENDED_API_ERROR:
			v->setState(domain_, VMS_PAUSED);
			break;
		}
		return 0;
	case VIR_DOMAIN_EVENT_PMSUSPENDED:
		switch (detail_)
		{
		case VIR_DOMAIN_EVENT_PMSUSPENDED_MEMORY:
			v->setState(domain_, VMS_PAUSED);
			break;
		case VIR_DOMAIN_EVENT_PMSUSPENDED_DISK:
			v->setState(domain_, VMS_SUSPENDED);
			break;
		}
		return 0;
	case VIR_DOMAIN_EVENT_STOPPED:
		if (detail_ == VIR_DOMAIN_EVENT_STOPPED_FROM_SNAPSHOT)
			break;

		switch (detail_)
		{
		case VIR_DOMAIN_EVENT_STOPPED_SAVED:
			v->setState(domain_, VMS_SUSPENDED);
			break;
		default:
			v->setState(domain_, VMS_STOPPED);
			break;
		}
		return 0;
	case VIR_DOMAIN_EVENT_SHUTDOWN:
		return 0;
	case VIR_DOMAIN_EVENT_CRASHED:
		switch (detail_)
		{
		case VIR_DOMAIN_EVENT_CRASHED_PANICKED:
			WRITE_TRACE(DBG_FATAL, "VM \"%s\" got guest panic.", virDomainGetName(domain_));
			v->setState(domain_, VMS_PAUSED);
			v->sendProblemReport(domain_);
			break;
		default:
			v->setState(domain_, VMS_STOPPED);
			break;
		}
		return 0;

	default:
		return 0;
	}

	// update vm configuration and state
	d = v->access(domain_);
	if (!d.isNull())
	{
		QRunnable* q = new Instrument::Domain(domain_, d);
		q->setAutoDelete(true);
		QThreadPool::globalInstance()->start(q);
	}

	return 0;
}

void error(void* opaque_, virErrorPtr value_)
{
	Q_UNUSED(value_);
	Q_UNUSED(opaque_);
	WRITE_TRACE(DBG_FATAL, "connection error: %s", value_->message);
}

} // namespace Plain
} // namespace Callback

namespace Model
{
///////////////////////////////////////////////////////////////////////////////
// struct Vm

Vm::Vm(const QString& uuid_, const SmartPtr<CDspClient>& user_,
		const QSharedPointer< ::Network::Routing>& routing_):
	::Vm::State::Machine(uuid_, user_, routing_), m_routing(routing_)
{
}

void Vm::updateState(VIRTUAL_MACHINE_STATE value_)
{
	switch(value_)
	{
	case VMS_RUNNING:
		process_event(::Vm::State::Event<VMS_RUNNING>());
		break;
	case VMS_STOPPED:
		process_event(::Vm::State::Event<VMS_STOPPED>());
		break;
	case VMS_PAUSED:
		process_event(::Vm::State::Event<VMS_PAUSED>());
		break;
	case VMS_MOUNTED:
		process_event(::Vm::State::Event<VMS_MOUNTED>());
		break;
	case VMS_SUSPENDED:
		process_event(::Vm::State::Event<VMS_SUSPENDED>());
		break;
	default:
		process_event(::Vm::State::Event<VMS_UNKNOWN>());
		return;
	}
}

void Vm::updateConfig(CVmConfiguration value_)
{
	boost::optional<CVmConfiguration> y = getConfig();
	if (y)
	{
		::Vm::Config::Repairer< ::Vm::Config::untranslatable_types>
			::type::do_(value_, y.get());
		
		if (is_flag_active< ::Vm::State::Running>())
			m_routing->reconfigure(y.get(), value_);
	}
	else
		WRITE_TRACE(DBG_DEBUG, "New VM registered directly from libvirt");

	if (value_.getVmIdentification()->getHomePath().isEmpty())
		value_.getVmIdentification()->setHomePath(getHome());
	else
		setHome(value_.getVmIdentification()->getHomePath());

	updateDirectory(value_.getVmType());

	::Vm::State::Machine::setConfig(value_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Domain

Domain::Domain(const Vm& vm_): m_vm(vm_), m_pid()
{
}

void Domain::setState(VIRTUAL_MACHINE_STATE value_)
{
	m_vm.updateState(value_);
}

void Domain::setConfig(CVmConfiguration& value_)
{
	m_vm.setName(value_.getVmIdentification()->getVmName());
	Kit.vms().at(m_vm.getUuid()).completeConfig(value_);
	m_vm.updateConfig(value_);
}

void Domain::prepareToSwitch()
{
	m_vm.process_event(::Vm::State::Switch());
}

void Domain::setCpuUsage()
{
}

void Domain::setDiskUsage()
{
}

void Domain::setMemoryUsage()
{
}

void Domain::setNetworkUsage()
{
}

///////////////////////////////////////////////////////////////////////////////
// struct System

System::System(): m_configGuard(&CDspService::instance()->getDispConfigGuard()),
	m_routing(new ::Network::Routing())
{
}

void System::remove(const QString& uuid_)
{
	domainMap_type::iterator p = m_domainMap.find(uuid_);
	if (m_domainMap.end() == p)
		return;

	p.value()->setState(VMS_UNKNOWN);
	m_domainMap.erase(p);
}

QSharedPointer<Domain> System::add(const QString& uuid_)
{
	if (uuid_.isEmpty() || m_domainMap.contains(uuid_))
		return QSharedPointer<Domain>();

	SmartPtr<CDspClient> u;
	QString d = m_configGuard->getDispWorkSpacePrefs()->getDefaultVmDirectory();
	foreach (CDispUser* s, m_configGuard->getDispUserPreferences()->m_lstDispUsers)
	{
		if (d == s->getUserWorkspace()->getVmDirectory())
		{
			u = CDspClient::makeServiceUser(d);
			u->setUserSettings(s->getUserId(), s->getUserName());
			break;
		}
	}
	if (!u.isValid())
		return QSharedPointer<Domain>();

	QSharedPointer<Domain> x(new Domain(Vm(uuid_, u, m_routing)));
	x->moveToThread(this->thread());
	return m_domainMap[uuid_] = x;
}

QSharedPointer<Domain> System::find(const QString& uuid_) const
{
	domainMap_type::const_iterator p = m_domainMap.find(uuid_);
	if (m_domainMap.end() == p)
		return QSharedPointer<Domain>();

	return p.value();
}

///////////////////////////////////////////////////////////////////////////////
// struct Coarse

QString Coarse::getUuid(virDomainPtr domain_)
{
	QString output;
	virDomainRef(domain_);
	Instrument::Agent::Vm::Unit(domain_).getUuid(output);
	return output;
}

void Coarse::setState(virDomainPtr domain_, VIRTUAL_MACHINE_STATE value_)
{
	QSharedPointer<Domain> d = m_fine->find(getUuid(domain_));
	if (!d.isNull() && !QMetaObject::invokeMethod(d.data(), "setState", Q_ARG(VIRTUAL_MACHINE_STATE, value_)))
		WRITE_TRACE(DBG_FATAL, "Unable to invoke VM 'setState' method");
}

void Coarse::prepareToSwitch(virDomainPtr domain_)
{
	QSharedPointer<Domain> d = m_fine->find(getUuid(domain_));
	if (!d.isNull() && !QMetaObject::invokeMethod(d.data(), "prepareToSwitch"))
		WRITE_TRACE(DBG_FATAL, "Unable to invoke VM 'setState' method");
}

void Coarse::remove(virDomainPtr domain_)
{
	m_fine->remove(getUuid(domain_));
}

void Coarse::sendProblemReport(virDomainPtr domain_)
{
	CProtoCommandPtr cmd(new CProtoSendProblemReport(QString(), getUuid(domain_), 0));
	SmartPtr<IOPackage> p = DispatcherPackage::createInstance(PVE::DspCmdSendProblemReport, cmd);
	QString vmDir = CDspService::instance()->getDispConfigGuard().getDispWorkSpacePrefs()->getDefaultVmDirectory();
	SmartPtr<CDspClient> c = CDspClient::makeServiceUser(vmDir);
	CDspService::instance()->getTaskManager().schedule(new Task_CreateProblemReport(c, p));
}

QSharedPointer<Domain> Coarse::access(virDomainPtr domain_)
{
	QString u = getUuid(domain_);
	QSharedPointer<Domain> output = m_fine->find(u);
	if (output.isNull())
		output = m_fine->add(u);

	return output;
}

void Coarse::disconnectCd(virDomainPtr domain_, const QString& alias_)
{
	PRL_RESULT res;
	QString vmUuid(getUuid(domain_));
	QString vmDir = CDspService::instance()->getDispConfigGuard().getDispWorkSpacePrefs()->getDefaultVmDirectory();

	SmartPtr<CVmConfiguration> vm = CDspService::instance()->getVmDirHelper()
		.getVmConfigByUuid(vmDir, vmUuid, res);

	QList<CVmOpticalDisk* >::iterator last(vm->getVmHardwareList()->m_lstOpticalDisks.end());
	QList<CVmOpticalDisk* >::iterator it(
			std::find_if(vm->getVmHardwareList()->m_lstOpticalDisks.begin(), last,
				boost::bind(&CVmOpticalDisk::getAlias, _1) == boost::cref(alias_)));
	if (it == last)
		return;
	(*it)->setConnected(PVE::DeviceDisconnected);
	CVmEvent e;
	e.addEventParameter(new CVmEventParameter(PVE::String,
				(*it)->toString(), EVT_PARAM_VMCFG_DEVICE_CONFIG_WITH_NEW_STATE));
	Task_EditVm::atomicEditVmConfigByVm(vmDir, vmUuid,
			e, CDspClient::makeServiceUser(vmDir));
}

} // namespace Model

namespace Monitor
{
///////////////////////////////////////////////////////////////////////////////
// struct Link

Link::Link(int timeout_)
{
	this->connect(&m_timer, SIGNAL(timeout()), SLOT(setOpen()));
	m_timer.start();
	m_timer.setInterval(timeout_);
}

void Link::setOpen()
{
	WRITE_TRACE(DBG_FATAL, "libvirt connect");
	if (!m_libvirtd.isNull())
		return;

	virConnectPtr c = virConnectOpen("qemu+unix:///system");
	if (NULL == c)
		return setClosed();

	int e = virConnectRegisterCloseCallback(c, &disconnect, this, NULL);
	if (0 != e)
	{
		virConnectClose(c);
		return setClosed();
	}
	m_timer.stop();
	m_libvirtd = QSharedPointer<virConnect>(c, &virConnectClose);
	emit connected(m_libvirtd);
}

void Link::setClosed()
{
	WRITE_TRACE(DBG_FATAL, "libvirt reconnect");
	m_libvirtd.clear();
	m_timer.start();
}

void Link::disconnect(virConnectPtr libvirtd_, int reason_, void* opaque_)
{
	WRITE_TRACE(DBG_FATAL, "libvirt connection is lost");
	Q_UNUSED(reason_);
	Q_UNUSED(libvirtd_);
	Link* x = (Link* )opaque_;
	emit x->disconnected();
	if (QThread::currentThread() == x->thread())
		x->setClosed();
	else
		QMetaObject::invokeMethod(x, "setClosed");
}

///////////////////////////////////////////////////////////////////////////////
// struct Domains

Domains::Domains(int timeout_): m_eventState(-1), m_eventReboot(-1),
	m_eventWakeUp(-1), m_eventDeviceConnect(-1), m_eventDeviceDisconnect(-1),
	m_eventTrayChange(-1), m_view(new Model::System())
{
	m_timer.stop();
	m_timer.setInterval(timeout_);
	m_timer.setSingleShot(false);
	this->connect(&m_timer, SIGNAL(timeout()), SLOT(getPerformance()));
}

void Domains::setConnected(QSharedPointer<virConnect> libvirtd_)
{
	m_libvirtd = libvirtd_.toWeakRef();
	Kit.setLink(libvirtd_);
	m_timer.start();
	m_eventState = virConnectDomainEventRegisterAny(libvirtd_.data(),
							NULL,
							VIR_DOMAIN_EVENT_ID_LIFECYCLE,
							VIR_DOMAIN_EVENT_CALLBACK(&Callback::Plain::lifecycle),
							new Model::Coarse(m_view),
							&Callback::Plain::delete_<Model::Coarse>);
	m_eventReboot = virConnectDomainEventRegisterAny(libvirtd_.data(),
							NULL,
							VIR_DOMAIN_EVENT_ID_REBOOT,
							VIR_DOMAIN_EVENT_CALLBACK(&Callback::Plain::reboot),
							new Model::Coarse(m_view),
							&Callback::Plain::delete_<Model::Coarse>);
	m_eventWakeUp = virConnectDomainEventRegisterAny(libvirtd_.data(),
							NULL,
							VIR_DOMAIN_EVENT_ID_PMWAKEUP,
							VIR_DOMAIN_EVENT_CALLBACK(&Callback::Plain::wakeUp),
							new Model::Coarse(m_view),
							&Callback::Plain::delete_<Model::Coarse>);
	m_eventDeviceConnect = virConnectDomainEventRegisterAny(libvirtd_.data(),
							NULL,
							VIR_DOMAIN_EVENT_ID_DEVICE_ADDED,
							VIR_DOMAIN_EVENT_CALLBACK(Callback::Plain::deviceConnect),
							new Model::Coarse(m_view),
							&Callback::Plain::delete_<Model::Coarse>);
	m_eventDeviceDisconnect = virConnectDomainEventRegisterAny(libvirtd_.data(),
							NULL,
							VIR_DOMAIN_EVENT_ID_DEVICE_REMOVED,
							VIR_DOMAIN_EVENT_CALLBACK(Callback::Plain::deviceDisconnect),
							new Model::Coarse(m_view),
							&Callback::Plain::delete_<Model::Coarse>);
	m_eventTrayChange = virConnectDomainEventRegisterAny(libvirtd_.data(),
							NULL,
							VIR_DOMAIN_EVENT_ID_TRAY_CHANGE,
							VIR_DOMAIN_EVENT_CALLBACK(Callback::Plain::trayChange),
							new Model::Coarse(m_view),
							&Callback::Plain::delete_<Model::Coarse>);
	QRunnable* q = new Instrument::Breeding::Subject(m_libvirtd, m_view);
	q->setAutoDelete(true);
	QThreadPool::globalInstance()->start(q);
}

void Domains::getPerformance()
{
	QSharedPointer<virConnect> x = m_libvirtd.toStrongRef();
	if (x.isNull())
		return;

	QRunnable* q = new Instrument::Performance(x, m_view);
	q->setAutoDelete(true);
	QThreadPool::globalInstance()->start(q);
}

void Domains::setDisconnected()
{
	m_timer.stop();
	QSharedPointer<virConnect> x;
	Kit.setLink(x);
	x = m_libvirtd.toStrongRef();
	virConnectDomainEventDeregisterAny(x.data(), m_eventState);
	m_eventState = -1;
	virConnectDomainEventDeregisterAny(x.data(), m_eventReboot);
	m_eventReboot = -1;
	virConnectDomainEventDeregisterAny(x.data(), m_eventWakeUp);
	m_eventWakeUp = -1;
	virConnectDomainEventDeregisterAny(x.data(), m_eventDeviceConnect);
	m_eventDeviceConnect = -1;
	virConnectDomainEventDeregisterAny(x.data(), m_eventDeviceDisconnect);
	m_eventDeviceDisconnect = -1;
	virConnectDomainEventDeregisterAny(x.data(), m_eventTrayChange);
	m_eventTrayChange = -1;
	m_libvirtd.clear();
}

} // namespace Monitor

///////////////////////////////////////////////////////////////////////////////
// struct Host

void Host::run()
{
	Monitor::Link a;
	Monitor::Domains b;
	b.connect(&a, SIGNAL(disconnected()), SLOT(setDisconnected()));
	b.connect(&a, SIGNAL(connected(QSharedPointer<virConnect>)),
		SLOT(setConnected(QSharedPointer<virConnect>)));

	QSharedPointer<Callback::Hub> h(new Callback::Hub());
	Callback::g_access.setHub(h);
	virSetErrorFunc(NULL, &Callback::Plain::error);
	virEventRegisterImpl(&Callback::Plain::addSocket,
			&Callback::Plain::setSocket,
			&Callback::Plain::remove,
			&Callback::Plain::addTimeout,
			&Callback::Plain::setTimeout,
			&Callback::Plain::remove);
	exec();
	a.setClosed();
}

} // namespace Libvirt
