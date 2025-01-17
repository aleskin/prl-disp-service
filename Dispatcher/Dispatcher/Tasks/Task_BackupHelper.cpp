///////////////////////////////////////////////////////////////////////////////
///
/// @file Task_BackupHelper.cpp
///
/// Common functions for backup tasks
///
/// @author krasnov@
///
/// Copyright (c) 2005-2017, Parallels International GmbH
/// Copyright (c) 2017-2023 Virtuozzo International GmbH, All rights reserved.
///
/// This file is part of Virtuozzo Core. Virtuozzo Core is free
/// software; you can redistribute it and/or modify it under the terms
/// of the GNU General Public License as published by the Free Software
/// Foundation; either version 2 of the License, or (at your option) any
/// later version.
/// 
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
/// GNU General Public License for more details.
/// 
/// You should have received a copy of the GNU General Public License
/// along with this program; if not, write to the Free Software
/// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
/// 02110-1301, USA.
///
/// Our contact details: Virtuozzo International GmbH, Vordergasse 59, 8200
/// Schaffhausen, Switzerland.
///
///////////////////////////////////////////////////////////////////////////////

//#define LOGGING_ON
//#define FORCE_LOGGING_LEVEL DBG_DEBUG

#include <QProcess>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "CDspClientManager.h"
#include "Task_CloneVm.h"
#include "Task_CloneVm_p.h"
#include <prlcommon/Interfaces/Debug.h>
#include "prlcommon/Interfaces/VirtuozzoQt.h"
#include "prlcommon/Interfaces/VirtuozzoNamespace.h"

#include "prlcommon/Logging/Logging.h"

#include "Task_BackupHelper.h"
#include "Task_BackupHelper_p.h"
#include "CDspService.h"
#include "prlcommon/Std/PrlAssert.h"
#include "prlcommon/HostUtils/HostUtils.h"
#include <prlcommon/PrlCommonUtilsBase/CFileHelper.h>
#include <prlcommon/PrlCommonUtilsBase/CRsaHelper.hpp>
#include <prlsdk/PrlEnums.h>
#include "CDspVmStateSender.h"
#include "CDspVmManager_p.h"
#include "CDspVzHelper.h"
#include <sys/resource.h>
#include "Libraries/Virtuozzo/CVzHelper.h"
#include "prlcommon/IOService/IOCommunication/Socket/Socket_p.h"
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <vzctl/libvzctl.h>

namespace Backup
{
namespace Process
{
///////////////////////////////////////////////////////////////////////////////
// struct Flop
// m_name, m_task

void Flop::operator()(const QString& program_, int code_, const QString& stderr_)
{
	PRL_RESULT e = (program_ == "restore" || program_ == "restore_ct") ?
		PRL_ERR_BACKUP_RESTORE_CMD_FAILED : PRL_ERR_BACKUP_BACKUP_CMD_FAILED;

	CDspTaskFailure f(*m_task);
	f.setCode(e)(m_name, QString::number(code_));
	m_task->getLastError()->addEventParameter(new CVmEventParameter(PVE::String,
		stderr_, EVT_PARAM_DETAIL_DESCRIPTION));
}

///////////////////////////////////////////////////////////////////////////////
// struct Driver

Driver::Driver(int channel_): m_channel(channel_)
{
	long f = fcntl(channel_, F_GETFL);
	if (-1 != f)
		fcntl(channel_, F_SETFL, f | O_NONBLOCK);
}

void Driver::setupChildProcess()
{
	QProcess::setupChildProcess(); // requires vz-built qt version
	fcntl(m_channel, F_SETFD, ~FD_CLOEXEC);
}

void Driver::write_(SmartPtr<char> data_, quint32 size_)
{
	if (0 > write(data_.getImpl(), size_))
	{
		WRITE_TRACE(DBG_FATAL, "write() error : %s",
			QSTR2UTF8(errorString()));
	}
}

///////////////////////////////////////////////////////////////////////////////
// struct Unit

void Unit::reset()
{
	if (NULL != m_driver)
	{
		m_driver->disconnect(this);
		m_driver->deleteLater();
		m_driver = NULL;
	}
}

PRL_RESULT Unit::start(QStringList args_, int version_)
{
	PRL_ASSERT(args_.size());
	QMutexLocker g(&m_mutex);
	if (NULL != m_driver)
		return PRL_ERR_DOUBLE_INIT;

	int p[2] = {};
	QString x = args_.takeFirst();
	if (socketpair(AF_UNIX, SOCK_STREAM, 0, p) < 0)
	{
		WRITE_TRACE(DBG_FATAL, "socketpair() error : %s", strerror(errno));
		return PRL_ERR_BACKUP_INTERNAL_ERROR;
	}
	if (BACKUP_PROTO_V4 > version_) {
		// old syntax, prepend arguments by fds
		args_.insert(0, QString::number(STDIN_FILENO));
		args_.insert(1, QString::number(p[1]));
	} else {
		// new syntax, append arguments by named fd args
		args_ << "--fdin" << QString::number(STDIN_FILENO);
		args_ << "--fdout" << QString::number(p[1]);
	}
	WRITE_TRACE(DBG_WARNING, "Run cmd: %s", QSTR2UTF8(args_.join(" ")));

	m_driver = new Driver(p[1]);
	connect(m_driver, SIGNAL(finished(int, QProcess::ExitStatus)),
		SLOT(reactFinish(int, QProcess::ExitStatus)), Qt::DirectConnection);

	m_driver->start(x, args_, QIODevice::Unbuffered | QIODevice::ReadWrite);
	::close(p[1]);
	if (!m_driver->waitForStarted())
	{
		reset();
		::close(p[0]);
		return PRL_ERR_BACKUP_TOOL_CANNOT_START;
	}
	m_program = x;
	m_driver->moveToThread(QCoreApplication::instance()->thread());
	m_channel = QSharedPointer<QLocalSocket>(new QLocalSocket, &QObject::deleteLater);
	m_channel->setSocketDescriptor(p[0], QLocalSocket::ConnectedState, QIODevice::ReadOnly);
//	m_channel->moveToThread(m_driver->thread());
	return PRL_ERR_SUCCESS;
}

void Unit::reactFinish(int code_, QProcess::ExitStatus status_)
{
	QString x;
	QMutexLocker g(&m_mutex);
	std::swap(x, m_program);
	QString y = m_driver->readAllStandardError();
	if (QProcess::CrashExit == status_)
		WRITE_TRACE(DBG_FATAL, "%s have crashed, error: %s ", qPrintable(x), qPrintable(y));
	else if (0 != code_)
	{
		WRITE_TRACE(DBG_FATAL, "%s exited with code %d, error: %s", QSTR2UTF8(x),
			code_, QSTR2UTF8(y));
		if (!m_callback.empty())
			m_callback(x, code_, y);
	}
	m_channel.clear();
	m_event.wakeAll();
	m_driver->disconnect(this);
}

PRL_RESULT Unit::waitForFinished()
{
	QMutexLocker g(&m_mutex);
	if (NULL == m_driver)
		return PRL_ERR_UNINITIALIZED;

	if (!m_program.isEmpty())
		m_event.wait(&m_mutex);

	if (QProcess::CrashExit == m_driver->exitStatus())
		return PRL_ERR_DISK_OPERATION_ABORTED;

	if (0 != m_driver->exitCode())
		return PRL_ERR_BACKUP_ACRONIS_ERR;

	return PRL_ERR_SUCCESS;
}

PRL_RESULT Unit::write(char* data_, quint32 size_)
{
	IOService::IODataBuffer b;
	b.open(QIODevice::ReadWrite);
	b.write(data_, size_);
	return write(SmartPtr<char>(b.takeBuffer(), SmartPtrPolicy::ArrayStorage), size_);
}

PRL_RESULT Unit::write(const SmartPtr<char>& data_, quint32 size_)
{
	if (size_ == 0)
		return PRL_ERR_SUCCESS;

	if (!data_.isValid())
		return PRL_ERR_INVALID_ARG;

	QMutexLocker g(&m_mutex);
	if (NULL == m_driver)
		return PRL_ERR_UNINITIALIZED;

	if (m_program.isEmpty())
		return PRL_ERR_UNEXPECTED;

	qRegisterMetaType<SmartPtr<char> >("SmartPtr<char>");
	if (!QMetaObject::invokeMethod(m_driver, "write_", Qt::QueuedConnection,
		Q_ARG(SmartPtr<char>, data_),
		Q_ARG(quint32, size_)))
		return PRL_ERR_UNEXPECTED;

	QCoreApplication::sendPostedEvents();
	return PRL_ERR_SUCCESS;
}

void Unit::kill()
{
	QMutexLocker g(&m_mutex);
	if (NULL != m_driver && m_driver->state() != QProcess::NotRunning)
		m_driver->terminate();

	m_channel.clear();
}

Prl::Expected<QPair<char*, qint32>, PRL_RESULT>
	Unit::read_(const QSharedPointer<QLocalSocket>& channel_, char* buffer_, qint32 capacity_)
{
	if (channel_.isNull())
		return PRL_ERR_OPERATION_WAS_CANCELED;

	if (QLocalSocket::ConnectedState != channel_->state() ||
		channel_->error() == QLocalSocket::PeerClosedError)
	{
		WRITE_TRACE(DBG_FATAL, "read() error: the channel is aborted");
		return PRL_ERR_BACKUP_INTERNAL_ERROR;
	}
	qint64 a = channel_->bytesAvailable();
	if (0 == a)
		return qMakePair(buffer_, capacity_);

	qint64 r = channel_->read(buffer_, qMin<qint64>(capacity_, a));
	if (-1 == r)
	{
		WRITE_TRACE(DBG_FATAL, "read() error: %s", QSTR2UTF8(channel_->errorString()));
		return PRL_ERR_BACKUP_INTERNAL_ERROR;
	}
	if (capacity_ > r)
		return qMakePair(buffer_ + r, qint32(capacity_ - r));

	return PRL_ERR_SUCCESS;
}

PRL_RESULT Unit::read(char *data, qint32 size, UINT32 tmo)
{
	m_mutex.lock();
	QSharedPointer<QLocalSocket> x = m_channel;
	m_mutex.unlock();
	if (x.isNull())
		return PRL_ERR_UNINITIALIZED;

	Prl::Expected<QPair<char*, qint32>, PRL_RESULT> y(qMakePair(data, size));
	for (; 0 == tmo; x->waitForReadyRead(-1))
	{
		m_mutex.lock();
		x = m_channel;
		m_mutex.unlock();
		y = read_(x, y.value().first, y.value().second);
		if (y.isFailed())
			return y.error();
	}
	unsigned s = TARGET_DISPATCHER_TIMEOUT_COUNTS;
	unsigned t = tmo / s; // in sec
	forever
	{
		m_mutex.lock();
		x = m_channel;
		m_mutex.unlock();
		y = read_(x, y.value().first, y.value().second);
		if (y.isFailed())
			return y.error();

		if (0 == --s)
			break;
		if (x->waitForReadyRead(t * 1000))
			s = TARGET_DISPATCHER_TIMEOUT_COUNTS;
	}
	WRITE_TRACE(DBG_FATAL, "full timeout expired (%d sec)", tmo);
	return PRL_ERR_BACKUP_INTERNAL_ERROR;
}

} // namespace Process

namespace Work
{
///////////////////////////////////////////////////////////////////////////////
// struct Ct

Ct::Ct(Task_BackupMixin& task_) : m_context(&task_)
{
}

QStringList Ct::buildArgs(const Product::component_type& t_, const QFileInfo* f_) const
{
	QStringList a;
	a << QString((m_context->getFlags() & PBT_INCREMENTAL) ? "append_ct" : "create_ct");

	// <private area> <backup path> <tib> <ct_id> <ve_root> <is_running>
	a << f_->absoluteFilePath()
		<< m_context->getProduct()->getStore().absolutePath()
		<< t_.second.toLocalFile()
		<< m_context->getProduct()->getObject().getConfig()->getVmIdentification()->getCtId()
		<< m_context->getProduct()->getObject().getConfig()->getCtSettings()->getMountPath()
		<< (m_context->isRunning() ? "1" : "0");

	a << "--last-tib" << QString::number(m_context->getBackupNumber());
	return a;
}

///////////////////////////////////////////////////////////////////////////////
// struct Vm

Vm::Vm(Task_BackupMixin& task_) : m_context(&task_)
{
}

QStringList Vm::buildArgs(const QString& snapshot_,
	const Product::component_type& t_, const QFileInfo* f_) const
{
	QStringList a;
	a << QString((m_context->getFlags() & PBT_INCREMENTAL) ? "append" : "create");

	a << t_.first.getFolder() << m_context->getProduct()->getStore().absolutePath()
		<< t_.second.toLocalFile() << snapshot_ << f_->absoluteFilePath();

	return a;
}

///////////////////////////////////////////////////////////////////////////////
// struct Command

const QUrl* Command::findArchive(const Product::component_type& t_,
	const Activity::Object::Model& a_)
{
	foreach (const Product::component_type& c, a_.getSnapshot().getComponents())
	{
		if (t_.first.getFolder() == c.first.getFolder())
			return &c.second;
	}
	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
// struct Loader

Prl::Expected<SmartPtr<CVmConfiguration>, PRL_RESULT> Loader::operator()(const char* basename_) const
{
	QFile f(QFileInfo(m_path, basename_).absoluteFilePath());
	SmartPtr<CVmConfiguration> output = SmartPtr<CVmConfiguration>(new CVmConfiguration());
	PRL_RESULT e = output->loadFromFile(&f, false);
	if (PRL_FAILED(e))
		return e;

	output->setRelativePath(output->getVmIdentification()->getHomePath());

	return output;
}

Prl::Expected<SmartPtr<CVmConfiguration>, PRL_RESULT> Loader::operator()(const Ct&) const
{
	Prl::Expected<SmartPtr<CVmConfiguration>, PRL_RESULT> x =
		(*this)(VZ_CT_XML_CONFIG_FILE);
	if (x.isSucceed())
		return x;

	PRL_RESULT e = PRL_ERR_SUCCESS;
	QString s = QString("%1/" VZ_CT_CONFIG_FILE).arg(m_path);
	SmartPtr<CVmConfiguration> output = CVzHelper::get_env_config_from_file(
			s, e, ::Ct::Config::LoadOps().
				setLayout(VZCTL_LAYOUT_5).setRelative());
	if (!output.isValid())
		return e;

	return output;
}

Prl::Expected<SmartPtr<CVmConfiguration>, PRL_RESULT> Loader::operator()(const Vm&) const
{
	return (*this)(VMDIR_DEFAULT_VM_CONFIG_FILE);
}

namespace Acronis
{
///////////////////////////////////////////////////////////////////////////////
// struct Builder

QStringList Builder::operator()(Ct& variant_) const
{
	return variant_.buildArgs(m_component, m_file);
}

QStringList Builder::operator()(Vm& variant_) const
{
	return variant_.buildArgs(m_snapshot, m_component, m_file);
}

///////////////////////////////////////////////////////////////////////////////
// struct Archives

Product::componentList_type Archives::operator()(Ct&) const
{
	return m_product.getCtTibs();
}

Product::componentList_type Archives::operator()(Vm&) const
{
	return m_product.getVmTibs();
}

///////////////////////////////////////////////////////////////////////////////
// struct ACommand

QStringList ACommand::buildArgs(const ::Backup::Product::component_type& t_, const QFileInfo* f_,
		object_type& variant_)
{
	QStringList a(boost::apply_visitor(
			Builder(m_activity.getSnapshot().getUuid(), t_, f_), variant_));
	CDispBackupSourcePreferences* pPref = CDspService::instance()->getDispConfigGuard().getDispCommonPrefs()
			->getBackupSourcePreferences();

	QString b = pPref->getSandbox();
	a << "--sandbox" << b;

	if ((m_context->getFlags() & PBT_UNCOMPRESSED) || !pPref->isCompression())
		a << "--uncompressed";
	return a;
}

PRL_RESULT ACommand::do_(object_type& variant_)
{
	PRL_RESULT output = PRL_ERR_SUCCESS;
	foreach (const Product::component_type& t,
		boost::apply_visitor(Archives(*(m_context->getProduct().get())), variant_))
	{
		const QUrl* u = findArchive(t, m_activity);
		if (NULL == u || !u->isLocalFile())
		{
			output = PRL_ERR_INVALID_HANDLE;
			break;
		}
		QFileInfo f(u->toLocalFile());
		QStringList args = buildArgs(t, &f, variant_);
		if (PRL_FAILED(output = m_worker(args, t.first.getDevice().getIndex())))
			break;
	}
	return output;
}

} // namespace Acronis

namespace Push
{
namespace Flavor
{
///////////////////////////////////////////////////////////////////////////////
// struct Basic

QStringList Basic::craftEpilog(Task_BackupMixin& context_)
{
	QStringList output;
	output << "-p" << context_.getBackupUuid();
	CDispBackupSourcePreferences* pPref = CDspService::instance()->getDispConfigGuard().getDispCommonPrefs()->getBackupSourcePreferences();
	if ((context_.getFlags() & PBT_UNCOMPRESSED) || !pPref->isCompression())
		output << "--uncompressed";

	output << "--limit-speed" << QString::number(context_.getDegree());
	output << "--disp-mode";
	return output;
}

///////////////////////////////////////////////////////////////////////////////
// struct Ct

QString Ct::craftProlog(Task_BackupMixin& context_)
{
	return (context_.getFlags() & PBT_INCREMENTAL) ? "append_ct" : "create_ct";
}

QString Ct::craftImage(const component_type& component_, const QString& url_) const
{
	const QUrl* f = Command::findArchive(component_, *m_activity);
	return QString("ploop://%1::%2").arg(f->toLocalFile())
		.arg(url_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Vm

QStringList Vm::craftProlog(Task_BackupMixin& context_)
{
	QStringList a;
	a << QString((context_.getFlags() & PBT_INCREMENTAL) ? "append" : "create");

	CDispBackupSourcePreferences* BackupPref =
			CDspService::instance()->getDispConfigGuard().getDispCommonPrefs()->
		getBackupSourcePreferences();

	if (BackupPref->getBackupMode() != nullptr)
	{
		PRL_VM_BACKUP_MODE current_mode = BackupPref->getBackupMode()->getMode();

		if (!(context_.getFlags() & PBT_DIRECT_DELTA) && current_mode == PBM_PUSH_REVERSED_DELTA)
		{
			QString d = BackupPref->getTmpDir();

			if (d.isEmpty())
				d = context_.getVmHomePath();

			a << "--cached" << "--backup-dir" << d;

			//get user ID of libvirt/qemu-kvm
			//[The directories /var/run/libvirt/qemu/, /var/lib/libvirt/qemu/ and
			///var/cache/libvirt/qemu/ must all have their ownership set
			//to match the user / group ID that QEMU guests will be run as]
			//https://docs.virtuozzo.com/libvirt-docs-5.6.0/html/drvqemu.html#securitydac
			//if stat command fail - use 'prlctl' userId
			QString ownerid;
			struct stat libvirt_st;
			if (!stat("/var/lib/libvirt/qemu", &libvirt_st))
			{
				ownerid = QString::number(libvirt_st.st_uid);
			}
			else
			{
				ownerid = QString::number(context_.getTask().getClient()->getAuthHelper().GetAuth()->GetUserId());
			}

			a << "--ownerid" << ownerid;
		}
	}

	return a << "-n" << context_.getProduct()->getObject()
		.getConfig()->getVmIdentification()->getVmName();
}

QString Vm::craftImage(const component_type& component_, const QString& url_)
{
	return QString("%1::%2").arg(component_.first.getImage()).arg(url_);
}

} // namespace Flavor

///////////////////////////////////////////////////////////////////////////////
// struct Mode

Prl::Expected<mode_type, PRL_RESULT> Mode::operator()(Ct&) const
{
	return mode_type(boost::blank());
}

Prl::Expected<mode_type, PRL_RESULT> Mode::operator()(Vm&) const
{
	Libvirt::Instrument::Agent::Vm::Unit u = Libvirt::Kit.vms().at(m_uuid);
	VIRTUAL_MACHINE_STATE s = VMS_UNKNOWN;
	if (u.getState().getValue(s).isFailed())
		return PRL_ERR_VM_UUID_NOT_FOUND;

	if (!m_context->getProduct()->getObject().getImages().isEmpty())
	{
		if (s == VMS_STOPPED)
			return mode_type(Stopped(m_uuid));
		if (m_context->getProduct()->getObject().canFreeze())
			return mode_type(Frozen(m_context, m_uuid));
	}
	return mode_type(boost::blank());
}

///////////////////////////////////////////////////////////////////////////////
// struct Builder

QStringList Builder::operator()(Ct& variant_) const
{
	Q_UNUSED(variant_);
	return craft(Flavor::Ct(*m_activity));
}

QStringList Builder::operator()(Vm& variant_) const
{
	Q_UNUSED(variant_);
	return craft(Flavor::Vm());
}

void Builder::addMap(const Activity::Object::component_type& component_, const QUrl& url_)
{
	m_map[component_.first.absoluteFilePath()] = url_;
}

template<class T>
QStringList Builder::craft(T subject_) const
{
	QStringList a;
	a << subject_.craftProlog(*m_context);
	foreach (const Product::component_type& t, m_context->getProduct()->getVmTibs())
	{
		a << "--image" <<
			subject_.craftImage(t, m_map[t.second.toLocalFile()].toString(QUrl::DecodeReserved));
	}
	return a << subject_.craftEpilog(*m_context);
}

///////////////////////////////////////////////////////////////////////////////
// struct VCommand

PRL_RESULT VCommand::operator()(const Activity::Object::componentList_type& components_,
	object_type& variant_)
{
	Prl::Expected<mode_type, PRL_RESULT> m =
		boost::apply_visitor(Mode(m_uuid, m_context), variant_);
	if (m.isFailed())
		return m.error();

	Builder b(*m_context, m_activity);
	if (m_tunnel.isNull())
	{
		foreach (const Activity::Object::component_type& c, components_)
		{
			b.addMap(c, m_context->patch(c.second));
		}
	}
	else
	{
		foreach (const Activity::Object::component_type& c, components_)
		{
			Prl::Expected<QUrl, PRL_RESULT> x = m_tunnel->addStrand(c.second);
			if (x.isFailed())
				return x.error();

			b.addMap(c, x.value());
		}
	}
	QStringList a(boost::apply_visitor(b, variant_));
	SmartPtr<Chain> p(m_builder(a));
	return boost::apply_visitor(Visitor(m_worker, p, a), m.value());
}

///////////////////////////////////////////////////////////////////////////////
// struct Visitor

PRL_RESULT Visitor::operator()(const boost::blank&) const
{
	PRL_RESULT r = m_worker(m_args, m_chain);
	if (r == PRL_ERR_DISK_OPERATION_ABORTED && !m_args.isEmpty())
	{
		QStringList a(m_args);
		a[0] = "abort_ct";
		a.prepend(VZ_BACKUP_CLIENT);
		
		//enable debug log for libvirt
		bool bVerbose = CDspService::instance()->getDispConfigGuard()
				.getDispCommonPrefs()->getDebug()->isVerboseLogEnabled();
		if (bVerbose)
			a << "--verbose" << "5";

		WRITE_TRACE(DBG_FATAL, "Run cmd: %s", QSTR2UTF8(a.join(" ")));
		QProcess p;
		DefaultExecHandler h(p, a.join(" "));
		if (!HostUtils::RunCmdLineUtilityEx(a, p, 0, NULL)(h).isSuccess())
			WRITE_TRACE(DBG_FATAL, "Failed to abort backup");
	}

	return r;
}

PRL_RESULT Visitor::operator()(Stopped& variant_) const
{
	return variant_.wrap(boost::bind(m_worker, m_args, m_chain));
}

PRL_RESULT Visitor::operator()(Frozen& variant_) const
{
	return m_worker(m_args, variant_.decorate(m_chain));
}

///////////////////////////////////////////////////////////////////////////////
// struct Frozen

SmartPtr<Chain> Frozen::decorate(SmartPtr<Chain> chain_)
{
	::Backup::Task::Reporter r(m_context->getTask(), m_uuid);
	::Backup::Task::Workbench w(m_context->getTask(), r, CDspService::instance()->getDispConfigGuard());
	if (PRL_FAILED(m_object.freeze(w)))
		return chain_;

	Thaw* t = new Thaw(m_object);
	t->next(chain_);
	t->moveToThread(QCoreApplication::instance()->thread());

	QTimer* T = new QTimer();
	T->moveToThread(t->thread());
	T->setInterval(20 * 1000);
	t->connect(T, SIGNAL(timeout()), SLOT(release()));
	T->connect(T, SIGNAL(timeout()), SLOT(deleteLater()));
	QMetaObject::invokeMethod(T, "start", Qt::QueuedConnection);

	return SmartPtr<Chain>(t, Emancipator(t));
}

///////////////////////////////////////////////////////////////////////////////
// struct Thaw

void Thaw::release()
{
	if (QThread::currentThread() == thread())
	{
		// NB. timeout case
		if (!m_lock.tryLock())
		{
			WRITE_TRACE(DBG_FATAL, "Another thaw is pending. Do nothing");
			return;
		}
		if (m_object)
		{
			QtConcurrent::run(boost::bind(&::Backup::Snapshot::Vm::Object::thaw,
				m_object.get()));
			m_object = boost::none;
		}
		m_lock.unlock();
	}
	else
	{
		QMutexLocker l(&m_lock);
		if (m_object && PRL_SUCCEEDED(m_object->thaw()))
			m_object = boost::none;
	}
}

PRL_RESULT Thaw::do_(SmartPtr<IOPackage> request_, process_type& dst_)
{
	release();
	return forward(request_, dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Emancipator

void Emancipator::operator()(Chain* object_)
{
	if (NULL == object_)
		return;

	if (m_object != object_)
		return;

	m_object->next(SmartPtr<Chain>());
	m_object->release();
	m_object->deleteLater();
	m_object = NULL;
}

typedef ::Command::Tag::State< ::Command::Vm::Frankenstein,
		::Command::Vm::Fork::State::Strict<VMS_PAUSED> > startPaused_type;

///////////////////////////////////////////////////////////////////////////////
// struct Stopped

template<class T>
PRL_RESULT Stopped::wrap(const T& worker_) const
{
	Libvirt::Result e = ::Command::Vm::Gear<startPaused_type>::run(m_uuid);
	if (e.isFailed()) {
		WRITE_TRACE(DBG_FATAL, "Failed to start a qemu process!");
		return e.error().code();
	}

	PRL_RESULT output = worker_();

	Libvirt::Instrument::Agent::Vm::Unit u = Libvirt::Kit.vms().at(m_uuid);
	VIRTUAL_MACHINE_STATE s = VMS_UNKNOWN;
	u.getState().getValue(s);
	if (s == VMS_PAUSED) // check that vm is in an expected state
	{
		e = ::Command::Vm::Gear< ::Command::Tag::State<
			::Command::Vm::Shutdown::Killer, ::Command::Vm::Fork::State::Plural
				<boost::mpl::vector_c<unsigned, VMS_STOPPED, VMS_SUSPENDED> > > >::run(m_uuid);
	}

	return output;
}

namespace Bitmap
{
///////////////////////////////////////////////////////////////////////////////
// struct Builder

QStringList Builder::operator()(Ct&) const
{
	QStringList a;
	a << "bitmaps_ct";
	foreach (const Product::component_type& c, m_components)
	{
		a << "--image" << QString("ploop://").append(c.second.toLocalFile());
	}
	return a;
}

QStringList Builder::operator()(Vm&) const
{
	QStringList a;
	a << "bitmaps";
	a << "-n" << m_config->getVmIdentification()->getVmName();
	foreach (const Product::component_type& c, m_components)
		a << "--image" << c.first.getImage();
	return a;
}

///////////////////////////////////////////////////////////////////////////////
// struct Worker 

PRL_RESULT Worker::operator()(Stopped& variant_) const
{
	return variant_.wrap(m_worker);
}

template<class T>
PRL_RESULT Worker::operator()(const T&) const
{
	return m_worker();
}

///////////////////////////////////////////////////////////////////////////////
// struct Getter

PRL_RESULT Getter::run(const QStringList& args_, QString& output_)
{
	QProcess process;
	DefaultExecHandler h(process, args_.join(" "));
	WRITE_TRACE(DBG_INFO, "Run cmd: %s", QSTR2UTF8(args_.join(" ")));
	if (!HostUtils::RunCmdLineUtilityEx(args_, process, 60 * 1000, NULL)(h).isSuccess())
	{
		WRITE_TRACE(DBG_FATAL, "Cannot retrieve bitmap information: %s", h.getStderr().constData());
		return PRL_ERR_BACKUP_INTERNAL_ERROR;
	}
	output_ = process.readAllStandardOutput(); 
	return PRL_ERR_SUCCESS;
}

QStringList Getter::process(const QString& data_)
{
	typedef boost::property_tree::ptree tree_type;

	QStringList output;
	std::istringstream is(data_.toUtf8().data());
	tree_type r;
	try {
		boost::property_tree::json_parser::read_json(is, r);
	} catch (const boost::property_tree::json_parser::json_parser_error&) {
		WRITE_TRACE(DBG_FATAL, "Exception during parse of bitmap data");
		return output;
	}

	QMap<QString, int> m;
	BOOST_FOREACH(const tree_type::value_type& it, r) {
		if (it.first != "image")
			continue;
		boost::optional<const tree_type& > b = it.second.get_child_optional("bitmaps");
		if (!b)
			return output;
		BOOST_FOREACH(const tree_type::value_type& bit, (*b)) {
			boost::optional<std::string> s = bit.second.get_value_optional<std::string>();
			if (!s)
				continue;
			QString q((*s).c_str());
			m.insert(q, m.value(q, 0) + 1);
		}
	}
	qint32 count =  m_context->getProduct()->getVmTibs().size();
	foreach(QString u, m.keys()) {
		if (m.value(u) == count)
			output << u;
	}
	return output;
}

Prl::Expected<QStringList, PRL_RESULT> Getter::operator()(
		const Activity::Object::Model& activity_, object_type& variant_)
{
	if (activity_.getSnapshot().getComponents().isEmpty())
		return QStringList();

	QString u = m_config->getVmIdentification()->getVmUuid();
	Prl::Expected<mode_type, PRL_RESULT> m =
		boost::apply_visitor(Mode(u, m_context), variant_);
	if (m.isFailed())
		return m.error();

	QStringList a = boost::apply_visitor(Builder(m_config,
			activity_.getSnapshot().getComponents()), variant_);
	a.prepend(VZ_BACKUP_CLIENT);

	//enable debug log for libvirt 
	bool bVerbose = CDspService::instance()->getDispConfigGuard()
				.getDispCommonPrefs()->getDebug()->isVerboseLogEnabled();
	if (bVerbose)
		a << "--verbose" << "5";

	QString out;
	PRL_RESULT e = boost::apply_visitor(Worker(
			boost::bind(&run, a, boost::ref(out))), m.value());
	if (PRL_FAILED(e))
		return e;
	return process(out);
}

} // namespace Bitmap
} // namespace Push
} // namespace Work

namespace Storage
{
///////////////////////////////////////////////////////////////////////////////
// struct Builder

Builder::Builder(const QString& path_): m_path(path_)
{
}

Builder& Builder::withBaseNbd(const QString& url_)
{
	m_policyList.push_back(VirtualDisk::Policy::Qcow2::base_type(url_, "nbd"));
	return *this;
}

Builder& Builder::withBaseFile(const QString& path_)
{
	m_policyList.push_back(VirtualDisk::Policy::Qcow2::base_type(path_));
	return *this;
}

Builder& Builder::withCompression()
{
	/* Was requested by den@ #PSBM-63826
	 * compressed writes will work only if they are aligned by cluster-size
	 * and here writes to backup by 256k. so, they can't work with 1m
	 * cluster size
	 */
	m_policyList.push_back(VirtualDisk::Policy::Qcow2::clusterSize_type(64*1024));
	m_policyList.push_back(VirtualDisk::Policy::Qcow2::extend_l2_type(false));//disable extend_l2 for 64K clusters
	return *this;
}

PRL_RESULT Builder::operator()(quint64 size_)
{
	VirtualDisk::qcow2PolicyList_type p(m_policyList);
	//qemu image has to be aligned by 65536 bytes - we will align on 1 Mb
	p.push_back(VirtualDisk::Policy::Qcow2::size_type(BYTE2MB(size_) << 20 ));

	return VirtualDisk::Qcow2::create(m_path, p);
}

///////////////////////////////////////////////////////////////////////////////
// struct Image

void Image::remove() const
{
	QFile(m_path).remove();
}

///////////////////////////////////////////////////////////////////////////////
// struct Nbd

PRL_RESULT Nbd::start(const Image& image_, quint32 flags_)
{
	QTcpServer s;
	if (!s.listen()) {
		WRITE_TRACE(DBG_FATAL, "Failed to reserve port for NBD server!");
		return PRL_ERR_BACKUP_INTERNAL_ERROR;
	}

	// Check if backup target is an NFS share
	// Enforce cached mode for NFS to avoid performance issues
	QFileInfo imagePath(image_.getPath());
	QDir imageDir = imagePath.absoluteDir();

	if (!imageDir.exists()) {
		WRITE_TRACE(DBG_FATAL, "Failed to get backup directory");
		return PRL_ERR_BACKUP_CANNOT_CREATE_DIRECTORY;
	}

	if (HostUtils::GetFSType(imageDir.absolutePath()) == PRL_FS_NFS)
		m_cached = true;

	VirtualDisk::qcow2PolicyList_type p(1, VirtualDisk::Policy::Qcow2::fd_type(s.socketDescriptor()));
	CDispBackupSourcePreferences* pPref = CDspService::instance()->getDispConfigGuard().getDispCommonPrefs()->getBackupSourcePreferences();
	if (pPref->isCompression() && !(flags_ & PBT_UNCOMPRESSED))
	{
		p.push_back(VirtualDisk::Policy::Qcow2::compressed_type(true));
	}
	if (m_cached)
	{
		p.push_back(VirtualDisk::Policy::Qcow2::cached_type(true));
	}
	if (!m_exportName.isEmpty())
		p.push_back(VirtualDisk::Policy::Qcow2::exportName_type(m_exportName));

	PRL_RESULT e = m_nbd.open(image_.getPath(), PRL_DISK_WRITE, p);
	if (PRL_FAILED(e))
		return e;

	QUrl u;
	u.setScheme("nbd");
	u.setHost(s.serverAddress().toString());
	u.setPort(s.serverPort());
	if (!m_exportName.isEmpty()){
		// Qt4 QUrl creates absolute paths from relative paths in setPath method.
		// Qt5 distinguishes relative and absolute paths in setPath method. QUrl generate
		// error with enum AuthorityPresentAndPathIsRelative in QUrl validation in case relative path setting.
		// For considered enum QUrl::errorString() method returns
		// "Path component is relative and authority is present" and QUrl is no valid. QUrl::toString method
		// returns empty string for not valid QUrl.
		// For the sake of compatibility we'll turn relative path into absolute, which is consistent with qt4 behavior
		u.setPath("/" + m_exportName);
	}

	m_url = u.toString(QUrl::DecodeReserved);
	WRITE_TRACE(DBG_DEBUG, "NBD server is started at %s", QSTR2UTF8(m_url));
	return PRL_ERR_SUCCESS;
}

void Nbd::stop()
{
	if (m_url.isEmpty())
		return;
	WRITE_TRACE(DBG_DEBUG, "NBD server at %s is stopped", QSTR2UTF8(m_url));
	m_url.clear();
	m_nbd.close();
}

QString Nbd::getUrl() const
{
	return m_url;
}

} // namespace Storage

namespace Object
{
///////////////////////////////////////////////////////////////////////////////
// struct State

State::State(const SmartPtr<CVmConfiguration>& model_)
{
	if (!model_.isValid())
		return;

	QString h = model_->getVmIdentification()->getHomePath();
	::Backup::Product::Model p(::Backup::Object::Model(model_), h);
	::Backup::Product::componentList_type x =
		PVT_VM == model_->getVmType() ?
			p.getVmTibs() : p.getCtTibs();
	foreach (::Backup::Product::componentList_type::const_reference c, x)
	{
		m_list[c.first.getImage()] = c.first.getDeviceSizeInBytes();
	}
}

bool State::equals(const State& other_) const
{
	return m_list.size() == other_.m_list.size() &&
		std::equal(m_list.begin(), m_list.end(), other_.m_list.begin());
}

} // namespace Object
} // namespace Backup

///////////////////////////////////////////////////////////////////////////////
// struct Chain

Chain::~Chain()
{
}

PRL_RESULT Chain::forward(SmartPtr<IOPackage> request_, process_type& dst_)
{
	if (NULL == m_next.getImpl())
		return PRL_ERR_SUCCESS;

	return m_next->do_(request_, dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct GoodBye

struct GoodBye: Chain
{
	GoodBye(): m_yes(false)
	{
	}

	bool no() const
	{
		return !m_yes;
	}
	PRL_RESULT do_(SmartPtr<IOPackage> request_, process_type& dst_);
private:
        bool m_yes;
};

PRL_RESULT GoodBye::do_(SmartPtr<IOPackage> request_, process_type& dst_)
{
	if (ABackupProxyGoodBye != request_->header.type)
		return forward(request_, dst_);

	m_yes = true;
	WRITE_TRACE(DBG_DEBUG, "Backup client exited");
	return PRL_ERR_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
// struct Close

struct Close: Chain
{
	explicit Close(quint32 timeout_): m_timeout(timeout_)
	{
	}

	PRL_RESULT do_(SmartPtr<IOPackage> request_, process_type& dst_);
private:
	quint32 m_timeout;
};

PRL_RESULT Close::do_(SmartPtr<IOPackage> request_, process_type& dst_)
{
	if (ABackupProxyCloseRequest != request_->header.type)
		return forward(request_, dst_);

	// ABackupProxyCloseRequest is not implemented prior
	// to V3 but so backup_client wait reply from dst, will send valid reply
	// from local dispatcher
	qint32 nReply = ABackupProxyResponse;
	quint32 uReplySize = sizeof(nReply);
	PRL_RESULT e = dst_.write((char *)&uReplySize, sizeof(uReplySize));
	if (PRL_FAILED(e))
		return e;

	return dst_.write((char *)&nReply, sizeof(uReplySize));
}

///////////////////////////////////////////////////////////////////////////////
// struct Forward

PRL_RESULT Forward::do_(SmartPtr<IOPackage> request_, process_type& dst_)
{
	IOSendJob::Handle hJob = m_client->sendPackage(request_);
	IOSendJob::Result res = m_client->waitForSend(hJob, m_timeout*1000);
	if (res != IOSendJob::Success)
	{
		WRITE_TRACE(DBG_FATAL, "Package sending failure, retcode %d", res);
		return PRL_ERR_BACKUP_INTERNAL_PROTO_ERROR;
	}
	res = m_client->waitForResponse(hJob, m_timeout*1000);
	if (res != IOSendJob::Success)
	{
		WRITE_TRACE(DBG_FATAL, "Responce receiving failure, retcode %d", res);
		return PRL_ERR_BACKUP_INTERNAL_PROTO_ERROR;
	}
	IOSendJob::Response resp = m_client->takeResponse(hJob);
	if (resp.responseResult != IOSendJob::Success)
	{
		WRITE_TRACE(DBG_FATAL, "Job failure: responseResult:%x", resp.responseResult);
		return PRL_ERR_BACKUP_INTERNAL_PROTO_ERROR;
	}
	SmartPtr<IOPackage> pResponse = resp.responsePackages[0];
	if (!pResponse.isValid())
	{
		WRITE_TRACE(DBG_FATAL, "Invalid reply");
		return PRL_ERR_BACKUP_INTERNAL_PROTO_ERROR;
	}
	quint32 uSize = 0;
	SmartPtr<char> b = pResponse->toBuffer(uSize);
	if (!b.getImpl())
	{
		WRITE_TRACE(DBG_FATAL, "IOPackage::toBuffer() error");
		return PRL_ERR_BACKUP_INTERNAL_ERROR;
	}
	// send reply to proc
	PRL_RESULT e = dst_.write((char *)&uSize, sizeof(uSize));
	if (PRL_FAILED(e))
		return e;

	return dst_.write(b, uSize);
}

///////////////////////////////////////////////////////////////////////////////
// struct Progress

struct Progress: Chain
{
	Progress(CVmEvent& stub_, quint32 disk_, SmartPtr<IOPackage> src_);

	PRL_RESULT do_(SmartPtr<IOPackage> request_, process_type& dst_);
private:
	quint32 m_disk;
	CVmEvent m_stub;
	SmartPtr<IOPackage> m_src;
};

Progress::Progress(CVmEvent& stub_, quint32 disk_, SmartPtr<IOPackage> src_):
	m_disk(disk_), m_stub(&stub_), m_src(src_)
{
}

PRL_RESULT Progress::do_(SmartPtr<IOPackage> request_, process_type& dst_)
{
	if (ABackupProxyProgress != request_->header.type)
		return forward(request_, dst_);

	QString buffer = request_->buffers[0].getImpl();
	WRITE_TRACE(DBG_DEBUG, "handleProgress: progress=%s nDiskIdx=%d",
				QSTR2UTF8(buffer), m_disk);
	CVmEvent event(&m_stub);
	event.addEventParameter(new CVmEventParameter( PVE::UnsignedInt,
				buffer,
				EVT_PARAM_PROGRESS_CHANGED));
	event.addEventParameter(new CVmEventParameter( PVE::UnsignedInt,
				QString::number(m_disk),
				EVT_PARAM_DEVICE_INDEX));

	SmartPtr<IOPackage> p = DispatcherPackage::createInstance(PVE::DspVmEvent, event, m_src);
	// Use sendPackageToAllClients there to send event for use case:
	// restore non exists VM
	CDspService::instance()->getClientManager().sendPackageToAllClients(p);
	return PRL_ERR_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
// struct Client

struct Client: boost::noncopyable
{
	Client(Backup::Process::Unit* process_, const QStringList& args_);

	PRL_RESULT result(bool cancelled_, CVmEvent* event_);
	Prl::Expected<SmartPtr<IOPackage>, PRL_RESULT> pull(quint32 version_, SmartPtr<char> buffer_, qint64 cb_);
private:
	Prl::Expected<SmartPtr<IOPackage>, PRL_RESULT>  doPull(SmartPtr<char> buffer_, qint64 cb_);

	PRL_RESULT m_start;
	QStringList m_argv;
	QSharedPointer<Backup::Process::Unit> m_process;
};

Client::Client(Backup::Process::Unit* process_, const QStringList& argv_):
	m_start(PRL_ERR_UNINITIALIZED), m_argv(argv_),
	m_process(process_, &Backup::Process::Unit::deleteLater)
{
}

Prl::Expected<SmartPtr<IOPackage>, PRL_RESULT> Client::doPull(SmartPtr<char> buffer_, qint64 cb_)
{
	// read block size.
	qint32 nSize = 0;
	PRL_RESULT e = m_process->read((char *)&nSize, sizeof(nSize));
	if (PRL_FAILED(e))
	{
		WRITE_TRACE(DBG_FATAL, "Read block size failed 0x%08x", e);
		return e;
	}
	// read data.
	if (cb_ < nSize)
	{
		WRITE_TRACE(DBG_FATAL, "Too small read buffer: %ld, requres: %ld", (long)cb_, (long)nSize);
		return PRL_ERR_UNEXPECTED;
	}
	e = m_process->read(buffer_.getImpl(), nSize);
	if (PRL_FAILED(e)) {
		WRITE_TRACE(DBG_FATAL, "Read data failed 0x%08x", e);
		return e;
	}

	SmartPtr<IOPackage> output;
	try
	{
		// handle incoming request, response will place into data
		output = IOPackage::createInstance(buffer_, nSize);
	}
	catch ( IOPackage::MalformedPackageException& )
	{
		WRITE_TRACE(DBG_FATAL, "MalformedPackageException in IOPackage::createInstance()");
	}
	if (NULL == output.getImpl())
		WRITE_TRACE(DBG_FATAL, "IOPackage::createInstance() error");

	return output;
}

Prl::Expected<SmartPtr<IOPackage>, PRL_RESULT> Client::pull(quint32 version_, SmartPtr<char> buffer_, qint64 cb_)
{
	PRL_RESULT e = m_start;
	if (PRL_ERR_UNINITIALIZED == e)
		m_start = m_process->start(m_argv, version_);

	if (PRL_FAILED(m_start))
		return m_start;
	if (PRL_ERR_UNINITIALIZED == e)
		WRITE_TRACE(DBG_INFO, "BACKUP_PROTO client version %u", version_);

	return doPull(buffer_, cb_);
}

PRL_RESULT Client::result(bool cancelled_, CVmEvent* event_)
{
	if (PRL_FAILED(m_start))
		return m_start;

	m_start = PRL_ERR_UNINITIALIZED;
	PRL_RESULT output = m_process->waitForFinished();
	if (cancelled_)
		return PRL_ERR_OPERATION_WAS_CANCELED;

	if (NULL != event_ && output == PRL_ERR_BACKUP_ACRONIS_ERR)
		return event_->getEventCode();

	return output;
}

namespace Backup
{
///////////////////////////////////////////////////////////////////////////////
// struct Suffix
//

QString Suffix::operator()() const
{
	QString output;
	if (m_index >= PRL_PARTIAL_BACKUP_START_NUMBER)
		output.append(QString(".%1").arg(m_index));
	return output.append(".qcow2");
}

namespace Tunnel
{
namespace Source
{
///////////////////////////////////////////////////////////////////////////////
// struct Connector

void Connector::reactReceive(const SmartPtr<IOPackage>& package_)
{
	switch (package_->header.type)
	{
	case Virtuozzo::VmMigrateQemuDiskTunnelChunk:
		return handle(Migrate::Vm::Pump::Event
			<Virtuozzo::VmMigrateQemuDiskTunnelChunk>(package_));
	default:
		WRITE_TRACE(DBG_DEBUG, "Unknown package type: %d.", package_->header.type);
	}
}

void Connector::reactAccept()
{
	QSharedPointer<QTcpSocket> a;
	QTcpServer* s = (QTcpServer* )sender();
	if (NULL != s)
	{
		a = QSharedPointer<QTcpSocket>(s->nextPendingConnection());
		a->setReadBufferSize(1 << 24);
		a->setProperty("channel", s->property("channel"));
		handle(a);
	}
	handle(Migrate::Vm::Source::Tunnel::Qemu::Launch<Virtuozzo::VmMigrateConnectQemuDiskCmd>
		(m_service, a.data()));
}

void Connector::reactDisconnect()
{
	handle(Migrate::Vm::Flop::Event(PRL_ERR_OPERATION_WAS_CANCELED));
}

///////////////////////////////////////////////////////////////////////////////
// struct Agent

void Agent::cancel()
{
	m_backend->process_event(Migrate::Vm::Flop::Event(PRL_ERR_OPERATION_WAS_CANCELED));
}

qint32 Agent::addStrand(quint16 spice_)
{
	QSharedPointer<QTcpServer> s(new QTcpServer());
	if (!s->listen(QHostAddress::LocalHost))
	{
		WRITE_TRACE(DBG_FATAL, "can't listen");
		return -1;
	}
	s->setProperty("channel", QVariant(uint(spice_)));
	m_backend->process_event(s);
	return s->serverPort();
}

///////////////////////////////////////////////////////////////////////////////
// struct Frontend

template <typename Event, typename FSM>
void Frontend::on_entry(const Event& event_, FSM& fsm_)
{
	def_type::on_entry(event_, fsm_);
	getConnector()->setService(m_service);
	getConnector()->connect(m_service,
		SIGNAL(onReceived(const SmartPtr<IOPackage>&)),
		SLOT(reactReceive(const SmartPtr<IOPackage>&)));
	getConnector()->connect(m_service,
		SIGNAL(disconnected()),
		SLOT(reactDisconnect()));
}

template <typename Event, typename FSM>
void Frontend::on_exit(const Event& event_, FSM& fsm_)
{
	def_type::on_exit(event_, fsm_);
	m_service->disconnect(SIGNAL(disconnected()), getConnector());
	m_service->disconnect(SIGNAL(onReceived(const SmartPtr<IOPackage>&)), getConnector());
	foreach (const client_type& c, m_clients)
	{
		c->close();
	}
	foreach (const server_type& s, m_servers)
	{
		s->close();
		s->disconnect(SIGNAL(newConnection()), getConnector());
	}
	getConnector()->setService(NULL);
}

void Frontend::accept(const client_type& client_)
{
	m_clients << client_;
}

void Frontend::listen(const server_type& server_)
{
	if (server_.isNull())
		return;

	m_servers << server_;
	getConnector()->connect(server_.data(), SIGNAL(newConnection()),
		SLOT(reactAccept()), Qt::QueuedConnection);
}

///////////////////////////////////////////////////////////////////////////////
// struct Subject

void Subject::run()
{
	Migrate::Vm::Source::Tunnel::IO io(*m_channel);

	QEventLoop x;
	backend_type b(boost::msm::back::states_ << Terminal(x), boost::ref(io));
	x.connect(&io, SIGNAL(disconnected()), SLOT(quit()), Qt::QueuedConnection);

	(Migrate::Vm::Walker<backend_type>(b))();
	b.start();

	QSharedPointer<Agent> a(new Agent(b), &Agent::deleteLater);
	m_promise.set_value(a.toWeakRef());
	x.exec();
	io.disconnect(SIGNAL(disconnected()), &x);
	b.stop();
	a.clear();
}

///////////////////////////////////////////////////////////////////////////////
// struct Unit

Unit::~Unit()
{
	bool x = QMetaObject::invokeMethod(m_agent.data(),
				"cancel", Qt::QueuedConnection);
	if (!x)
		WRITE_TRACE(DBG_FATAL, "cannot cancel");
}

PRL_RESULT Unit::operator()(const SmartPtr<IOClient>& channel_)
{
	if (!m_agent.isNull())
		return PRL_ERR_INVALID_HANDLE;

	Subject::promise_type p;
	boost::future<QWeakPointer<Agent> > f = p.get_future();
	Subject* s = new Subject(channel_, p);
	s->setAutoDelete(true);
	m_pool.start(s);
	if (boost::future_status::ready != f.wait_for(boost::chrono::seconds(5)))
	{
		m_pool.waitForDone();
		return PRL_ERR_TIMEOUT;
	}
	m_agent = f.get();
	return PRL_ERR_SUCCESS;
}

Prl::Expected<QUrl, PRL_RESULT> Unit::addStrand(const QUrl& remote_)
{
	if ("nbd" != remote_.scheme())
		return PRL_ERR_INVALID_ARG;

	if (m_agent.isNull())
		return PRL_ERR_INVALID_HANDLE;

	qint32 p = 0;
	bool x = QMetaObject::invokeMethod(m_agent.data(),
				"addStrand",
				Qt::BlockingQueuedConnection,
				Q_RETURN_ARG(qint32, p),
				Q_ARG(quint16, remote_.port()));
	if (!x) 
		return PRL_ERR_UNEXPECTED;
	if (0 > p)
		return PRL_ERR_FAILURE;

	QUrl output = remote_;
	output.setHost(QHostAddress(QHostAddress::LocalHost).toString());
	output.setPort(p);
	return output;
}

///////////////////////////////////////////////////////////////////////////////
// struct Factory

Factory::result_type Factory::operator()(quint32 flags_) const
{
	value_type output;
	if (flags_ & PBT_DIRECT_DATA_CONNECTION)
		return output;

	CDispBackupSourcePreferences* pPref = CDspService::instance()->getDispConfigGuard().getDispCommonPrefs()->getBackupSourcePreferences();
	if (!pPref->isTunnel())
			return output;

	if (CDspService::instance()->getShellServiceHelper().isLocalAddress(m_target))
		return output;

	output = value_type(new Unit());
	PRL_RESULT e = (*output)(m_channel);
	if (PRL_FAILED(e))
		return e;

	return output;
}

} // namespace Source

namespace Target
{
///////////////////////////////////////////////////////////////////////////////
// struct Connector

void Connector::reactReceive(const SmartPtr<IOPackage>& package_)
{
	WRITE_TRACE(DBG_DEBUG, "react package %d.", package_->header.type);
	switch (package_->header.type)
	{
	case Virtuozzo::VmMigrateConnectQemuDiskCmd:
		return handle(Migrate::Vm::Pump::Event
			<Virtuozzo::VmMigrateConnectQemuDiskCmd>(package_));
	case Virtuozzo::VmMigrateQemuDiskTunnelChunk:
		return handle(Migrate::Vm::Pump::Event
			<Virtuozzo::VmMigrateQemuDiskTunnelChunk>(package_));
	default:
		WRITE_TRACE(DBG_DEBUG, "Unknown package type: %d.", package_->header.type);
	}
}

///////////////////////////////////////////////////////////////////////////////
// struct Frontend

void Frontend::spin(const qemuDisk_type::Good&)
{
	if (m_service.isNull())
		getConnector()->handle(Migrate::Vm::Flop::Event(PRL_ERR_INVALID_HANDLE));
	else
		getConnector()->handle(boost::phoenix::ref(*m_service));
}

} // namespace Target
} // namespace Tunnel
} // namespace Backup

///////////////////////////////////////////////////////////////////////////////
// struct Task_BackupMixin

Backup::Metadata::Lock Task_BackupMixin::s_metadataLock;

Task_BackupMixin::Task_BackupMixin(CDspTaskHelper& task_):
	Task_DispToDispConnHelper(task_.getLastError()),
	m_pVmConfig(new CVmConfiguration()), m_nInternalFlags(),
	// will assume first backup proto version on dst side by default
	m_nRemoteVersion(BACKUP_PROTO_V1), m_nBackupNumber(), m_service(NULL),
	m_cABackupClient(), m_bKillCalled(),
	/* block size + our header size */
	m_nBufSize(IOPACKAGESIZE(1) + PRL_DISP_IO_BUFFER_SIZE), m_task(&task_)
{
	m_pBuffer = SmartPtr<char>(new char[m_nBufSize], SmartPtrPolicy::ArrayStorage);
	m_cABackupServer.reset(new Backup::Process::Unit());
	// set backup client/server interface timeout (https://jira.sw.ru/browse/PSBM-10020)
	m_nBackupTimeout = CDspService::instance()->getDispConfigGuard().
			getDispCommonPrefs()->getBackupSourcePreferences()->getTimeout(); // in secs
}

Task_BackupMixin::~Task_BackupMixin()
{
}

PRL_RESULT Task_BackupMixin::connect()
{
	if (m_task->operationIsCancelled())
		return PRL_ERR_OPERATION_WAS_CANCELED;

	QString sLogin;
	QString sPw;
	auto nLoginFlags = m_nFlags & PACF_MASK;

	{
		CDspLockedPointer<CDispCommonPreferences> dispPref = CDspService::instance()->
				getDispConfigGuard().getDispCommonPrefs();

		CDispBackupSourcePreferences *pBackupSource = dispPref->getBackupSourcePreferences();

		sLogin = pBackupSource->getLogin();
		sPw = pBackupSource->getPassword();

		if (m_sServerSessionUuid.isEmpty())
		{
			if (pBackupSource->getDefaultBackupServer().isEmpty())
			{
				m_sServerHostname = "127.0.0.1";
				m_nServerPort = CDspService::getDefaultListenPort();
				//local backup. use current session
				SmartPtr<CDspClient> client = m_task->getClient();
				m_sServerSessionUuid = client->getClientHandle();
			}
			else
			{
				if (sLogin.isEmpty())
					return PRL_ERR_BACKUP_REQUIRE_LOGIN_PASSWORD;
				m_sServerHostname = pBackupSource->getDefaultBackupServer();
				m_nServerPort = CDspService::getDefaultListenPort();

				if (sPw.isEmpty())
				{
					auto pubKeyResult = CRsaHelper().getOpenSshPublicKey();
					if (pubKeyResult.isFailed())
						return pubKeyResult.error().code();
					sPw = pubKeyResult.value();
					nLoginFlags |= PLLF_LOGIN_WITH_RSA_KEYS;
				}
			}
		}
	}

	return Task_DispToDispConnHelper::Connect(
			m_sServerHostname,
			m_nServerPort,
			m_sServerSessionUuid,
			sLogin,
			sPw,
			nLoginFlags);
}

BackupItem* Task_BackupMixin::getLastBaseBackup(const QString &sVmUuid,
			CAuthHelper *pAuthHelper, BackupCheckMode mode)
{

	QStringList lstBackupUuid;
	std::auto_ptr<BackupItem> a;
	QDateTime lastDateTime(QDate(1970, 1, 1));
	Backup::Metadata::Catalog c = getCatalog(sVmUuid);
	if (PRL_BACKUP_CHECK_MODE_WRITE == mode && pAuthHelper != NULL)
		lstBackupUuid = c.getIndexForWrite(*pAuthHelper);
	else
		lstBackupUuid = c.getIndexForRead(pAuthHelper);

	foreach(const QString& u, lstBackupUuid)
	{
		if (PRL_FAILED(getMetadataLock().grabShared(u)))
			continue;
		Backup::Metadata::Sequence s = c.getSequence(u);
		Prl::Expected<BackupItem, PRL_RESULT> b =
			s.getHeadItem(s.getIndex().first());
		getMetadataLock().releaseShared(u);
		if (b.isFailed())
			continue;
		if (lastDateTime <= b.value().getDateTime())
		{
			lastDateTime = b.value().getDateTime();
			a.reset(new BackupItem(b.value()));
		}
	}
	return a.release();
}

PRL_RESULT Task_BackupMixin::checkFreeDiskSpace(
	quint64 nRequiredSize, quint64 nAvailableSize, bool bIsCreateOp)
{
	if (nRequiredSize == 0)
	{
		WRITE_TRACE(DBG_FATAL, "Warning: check available disk space is skipped");
		return PRL_ERR_SUCCESS;
	}
	PRL_RESULT nRetCode = 0;
	if (nRequiredSize > nAvailableSize)
	{

		QString strFree;
		strFree.sprintf("%.1f", (float)nAvailableSize / 1024.0 / 1024.0 / 1024.0);
		QString strSize;
		strSize.sprintf("%.1f", (float)nRequiredSize / 1024.0 / 1024.0 / 1024.0);

		nRetCode = CDspTaskFailure(*m_task)
				.setCode(bIsCreateOp ? PRL_ERR_BACKUP_CREATE_NOT_ENOUGH_FREE_DISK_SPACE :
					PRL_ERR_BACKUP_RESTORE_NOT_ENOUGH_FREE_DISK_SPACE)
				(strSize, strFree);
		WRITE_TRACE(DBG_FATAL, "Not enought free disk space avail=%llu required=%llu",
				nAvailableSize, nRequiredSize);

	}
	return nRetCode;
}

PRL_RESULT Task_BackupMixin::parseBackupId(const QString &sBackupId, QString &sBackupUuid, unsigned &nBackupNumber)
{
	int nIndex;

	if ((nIndex = sBackupId.indexOf(".")) == -1) {
		sBackupUuid = sBackupId;
		nBackupNumber = PRL_BASE_BACKUP_NUMBER;
	} else {
		QString sBackupDir;
		bool ok;
		/* parse {BackupUuid}.BackupNumber pair */
		sBackupUuid = sBackupId.left(nIndex);
		sBackupDir = sBackupId.right(sBackupId.size() - nIndex - 1);
		nBackupNumber = sBackupDir.toUInt(&ok);
		if (!ok)
			return PRL_ERR_INVALID_ARG;
	}
	if (!Uuid::isUuid(sBackupUuid))
		return PRL_ERR_INVALID_ARG;
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Task_BackupMixin::findVmUuidForBackupUuid(const QString &sBackupUuid, QString &sVmUuid)
{
	QDir dir, dirVm;
	QFileInfoList listVm, listBackup;
	int i, j;

	if (m_task->operationIsCancelled())
		return PRL_ERR_OPERATION_WAS_CANCELED;

	dir.setPath(getBackupDirectory());
	if (!dir.exists())
		return PRL_ERR_FAILURE;

	listVm = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs);
	for (i = 0; i < listVm.size(); ++i) {
		if (!Uuid::isUuid(listVm.at(i).fileName()))
			continue;
		dirVm.setPath(listVm.at(i).absoluteFilePath());
		if (!dirVm.exists())
			continue;

		listBackup = dirVm.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs);
		for (j = 0; j < listBackup.size(); ++j) {
			if (sBackupUuid == listBackup.at(j).fileName()) {
				sVmUuid = listVm.at(i).fileName();
				return PRL_ERR_SUCCESS;
			}
		}
	}
	return PRL_ERR_FAILURE;
}

QString Task_BackupMixin::getBackupDirectory()
{
	QString sBackupDirectory = m_sServerDirectory;

	if (sBackupDirectory.isEmpty()) {
		PRL_RESULT e;
		SmartPtr <CVmConfiguration> pVmConfig =
			CDspService::instance()->getVmDirHelper().getVmConfigByUuid(m_task->getClient(), m_sVmUuid, e);

		if (pVmConfig)
			sBackupDirectory = pVmConfig->getVmSettings()->getVmCommonOptions()
				->getBackupTargetPreferences()->getDefaultBackupDirectory();
	}

	if (sBackupDirectory.isEmpty()) {
		CDspLockedPointer<CDispatcherConfig> pLockedDispConfig =
			CDspService::instance()->getDispConfigGuard().getDispConfig();
		sBackupDirectory =
			pLockedDispConfig->getDispatcherSettings()->getCommonPreferences()
				->getBackupTargetPreferences()->getDefaultBackupDirectory();
	}

	if (sBackupDirectory.isEmpty())
		sBackupDirectory = VirtuozzoDirs::getDefaultBackupDir();

	WRITE_TRACE(DBG_INFO, "vmuuid='%s' backup_dir='%s'", qPrintable(m_sVmUuid), qPrintable(sBackupDirectory));

	return sBackupDirectory;
}

PRL_RESULT Task_BackupMixin::handleABackupPackage(
				const SmartPtr<CDspDispConnection> &pDispConnection,
				const SmartPtr<IOPackage> &pRequest,
				UINT32 tmo)
{
	PRL_RESULT nRetCode = PRL_ERR_SUCCESS;
	SmartPtr<IOPackage> pResponse;
	SmartPtr<char> pBuffer;
	qint32 nSize;
	quint32 uSize;
	IOSendJob::Handle hJob;

	if (!IS_ABACKUP_PROXY_PACKAGE(pRequest->header.type))
		return PRL_ERR_SUCCESS;

	pBuffer = pRequest->toBuffer(uSize);
	if (!pBuffer.getImpl()) {
		WRITE_TRACE(DBG_FATAL, "IOPackage::toBuffer() error");
		return PRL_ERR_BACKUP_INTERNAL_ERROR;
	}
	if (pRequest->header.type == ABackupProxyProgress)
		return PRL_ERR_SUCCESS;
	else if (pRequest->header.type == ABackupProxyCancelCmd)
		WRITE_TRACE(DBG_FATAL, "receive ABackupProxyCancelCmd command");
	/* write request to process */
	if (PRL_FAILED(nRetCode = m_cABackupServer->write((char *)&uSize, sizeof(uSize))))
		return nRetCode;
	if (PRL_FAILED(nRetCode = m_cABackupServer->write(pBuffer, uSize)))
		return nRetCode;
	/* and read reply */
	if (PRL_FAILED(nRetCode = m_cABackupServer->read((char *)&nSize, sizeof(nSize), tmo)))
		return nRetCode;
	if (m_nBufSize < nSize) {
		WRITE_TRACE(DBG_FATAL, "Too small read buffer: %ld, requires: %ld", (long)m_nBufSize, (long)nSize);
		return PRL_ERR_BACKUP_INTERNAL_ERROR;
	}
	if (PRL_FAILED(nRetCode = m_cABackupServer->read(m_pBuffer.getImpl(), nSize, tmo)))
		return nRetCode;

	// send reply to client
	pResponse = IOPackage::createInstance(m_pBuffer, nSize, pRequest);
	if (!pResponse.getImpl()) {
		WRITE_TRACE(DBG_FATAL, "IOPackage::createInstance() error");
		return PRL_ERR_BACKUP_INTERNAL_ERROR;
	}
	hJob = pDispConnection->sendPackage(pResponse);
	if (CDspService::instance()->getIOServer().waitForSend(hJob, tmo*1000) != IOSendJob::Success) {
		WRITE_TRACE(DBG_FATAL, "Package sending failure");
		return PRL_ERR_BACKUP_INTERNAL_PROTO_ERROR;
	}
	return PRL_ERR_SUCCESS;
}

void Task_BackupMixin::killABackupClient()
{
	if (m_cABackupClient) {
		m_bKillCalled = true;
		m_cABackupClient->kill();
	}
}

PRL_RESULT Task_BackupMixin::startABackupClient(const QString& sVmName_, const QStringList& args_,
		SmartPtr<Chain> custom_)
{
	if (m_task->operationIsCancelled())
		return PRL_ERR_OPERATION_WAS_CANCELED;

	SmartPtr<Chain> y = custom_;
	// NB. should not allow to override bye and close logic.
	// put them in the very beginning of the chain. the rest
	// is optional.
	if (BACKUP_PROTO_V3 > m_nRemoteVersion)
	{
		Chain* z = new Close(m_nBackupTimeout);
		z->next(y);
		y = SmartPtr<Chain>(z);
	}
	GoodBye* b = new GoodBye;
	b->next(y);
	y = SmartPtr<Chain>(b);

	QStringList a(args_);
	if (BACKUP_PROTO_V4 > m_nRemoteVersion)
		a.prepend(QString(PRL_ABACKUP_CLIENT));
	else
	{
		a.prepend(QString(VZ_BACKUP_CLIENT));
		//enable debug log for libvirt
		bool bVerbose = CDspService::instance()->getDispConfigGuard()
				.getDispCommonPrefs()->getDebug()->isVerboseLogEnabled();
		if (bVerbose)
			a << "--verbose" << "5";
	}
	a << "--timeout" << QString::number(m_nBackupTimeout);

	Client x(m_cABackupClient = new Backup::Process::Unit(boost::bind<void>(
		Backup::Process::Flop(sVmName_, *m_task), _1, _2, _3)), a);
	PRL_RESULT e = PRL_ERR_SUCCESS;
	while (b->no())
	{
		Prl::Expected<SmartPtr<IOPackage>, PRL_RESULT> q = x.pull(m_nRemoteVersion, m_pBuffer, m_nBufSize);
		if (q.isFailed())
		{
			e = q.error();
			if (e == PRL_ERR_UNINITIALIZED)
				e = PRL_ERR_SUCCESS;
			break;
		}
		if (NULL == q.value().getImpl()) {
			e = PRL_ERR_BACKUP_INTERNAL_ERROR;
			break;
		}
		e = y->do_(q.value(), *m_cABackupClient);
		if (PRL_FAILED(e))
			break;
	}
	PRL_RESULT output = x.result(m_bKillCalled, m_task->getLastError());
	if (!m_bKillCalled && !isConnected()) {
		WRITE_TRACE(DBG_FATAL, "Backup client IO no connection");
		output = PRL_ERR_IO_NO_CONNECTION;
	}
	if (PRL_SUCCEEDED(output) && PRL_FAILED(e)) {
		WRITE_TRACE(DBG_FATAL, "Backup client terminated successfully, but server error was 0x%08X", e);
		output = e;
	}

	m_bKillCalled = false;
	m_cABackupClient = NULL;
	return output;
}

Chain * Task_BackupMixin::prepareABackupChain(const QStringList& args_,
		const QString &sNotificationVmUuid, unsigned int nDiskIdx)
{
	bool bRestore = (args_.at(0) == "restore" || args_.at(0) == "restore_ct");
	PRL_EVENT_TYPE event_type = bRestore ? PET_DSP_EVT_RESTORE_PROGRESS_CHANGED : PET_DSP_EVT_BACKUP_PROGRESS_CHANGED;
	CVmEvent e(event_type, sNotificationVmUuid, PIE_DISPATCHER);
	Chain *p = new Progress(e, nDiskIdx, m_task->getRequestPackage());
	if (args_.indexOf("--local") == -1)
		p->next(SmartPtr<Chain>(new Forward(m_pIoClient, m_nBackupTimeout)));
	return p;
}

PRL_RESULT Task_BackupMixin::startABackupClient(const QString& sVmName_, const QStringList& args_,
		const QString &sNotificationVmUuid, unsigned int nDiskIdx)
{
	Chain *p = prepareABackupChain(args_, sNotificationVmUuid, nDiskIdx);
	return startABackupClient(sVmName_, args_, SmartPtr<Chain>(p));
}

PRL_RESULT Task_BackupMixin::GetBackupTreeRequest(const QString &sVmUuid, const QString &sBackupDir, QString &sBackupTree)
{
	PRL_RESULT nRetCode = PRL_ERR_SUCCESS;
	CDispToDispCommandPtr pCmd;
	SmartPtr<IOPackage> pPackage;
	SmartPtr<IOPackage> pReply;

	pCmd = CDispToDispProtoSerializer::CreateGetBackupTreeCommand(sVmUuid, sBackupDir, m_nFlags);

	pPackage = DispatcherPackage::createInstance(
			pCmd->GetCommandId(),
			pCmd->GetCommand()->toString());

	if (PRL_FAILED(nRetCode = SendReqAndWaitReply(pPackage, pReply)))
		return nRetCode;

	if (	(pReply->header.type != VmBackupGetTreeReply) &&
		(pReply->header.type != DispToDispResponseCmd))
	{
		WRITE_TRACE(DBG_FATAL, "Invalid package header:%x, expected header:%x or %x",
			pReply->header.type, DispToDispResponseCmd, VmBackupGetTreeReply);
		return PRL_ERR_BACKUP_INTERNAL_PROTO_ERROR;
	}

	CDispToDispCommandPtr pDspReply = CDispToDispProtoSerializer::ParseCommand(
		DispToDispResponseCmd, UTF8_2QSTR(pReply->buffers[0].getImpl()));

	if (pReply->header.type == DispToDispResponseCmd) {
		CDispToDispResponseCommand *pResponseCmd =
			CDispToDispProtoSerializer::CastToDispToDispCommand<CDispToDispResponseCommand>(pDspReply);

		if (PRL_FAILED(nRetCode = pResponseCmd->GetRetCode())) {
			m_task->getLastError()->fromString(pResponseCmd->GetErrorInfo()->toString());
			return nRetCode;
		}
		return PRL_ERR_BACKUP_INTERNAL_PROTO_ERROR;
	}
	CGetBackupTreeReply *pTreeReply =
		CDispToDispProtoSerializer::CastToDispToDispCommand<CGetBackupTreeReply>(pDspReply);

	sBackupTree = pTreeReply->GetBackupTree();

	return nRetCode;
}

QString Task_BackupMixin::patch(QUrl url_) const
{
	if (url_.scheme() == "nbd") {
		// replace INADDR_ANY by a real remote server hostname
		url_.setHost(m_sServerHostname);
	}
	return url_.toString(QUrl::DecodeReserved);
}

Backup::Metadata::Lock& Task_BackupMixin::getMetadataLock()
{
	return s_metadataLock;
}

Backup::Metadata::Catalog Task_BackupMixin::getCatalog(const QString& vm_)
{
	return Backup::Metadata::Catalog(Backup::Metadata::Carcass
		(getBackupDirectory(), vm_));
}

