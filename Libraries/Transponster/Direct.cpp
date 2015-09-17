/*
 * Copyright (c) 2015 Parallels IP Holdings GmbH
 *
 * This file is part of Virtuozzo Core Libraries. Virtuozzo Core
 * Libraries is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/> or write to Free Software Foundation,
 * 51 Franklin Street, Fifth Floor Boston, MA 02110, USA.
 *
 * Our contact details: Parallels IP Holdings GmbH, Vordergasse 59, 8200
 * Schaffhausen, Switzerland.
 */

#include "Direct.h"
#include "Direct_p.h"
#include "Reverse_p.h"

namespace Transponster
{
namespace Visitor
{
namespace Source
{
///////////////////////////////////////////////////////////////////////////////
// struct Unit

bool Unit<CVmHardDisk>::operator()(const mpl::at_c<Libvirt::Domain::Xml::VDiskSource::types, 4>::type& source_) const
{
	const Libvirt::Domain::Xml::Source4* v = source_.getValue().get_ptr();
	if (NULL == v)
		return false;

	getDevice().setSystemName(v->getVolume());
	getDevice().setEmulatedType(PVE::BootCampHardDisk);
	return true;
}

} // namespace Source

///////////////////////////////////////////////////////////////////////////////
// struct Floppy

PRL_RESULT Floppy::operator()(const Libvirt::Domain::Xml::Disk& disk_)
{
	if (!Clustered<CVmFloppyDisk>::operator()(disk_))
		return PRL_ERR_UNIMPLEMENTED;

	CVmFloppyDisk* d = getResult();
	if (NULL == d)
		return PRL_ERR_UNEXPECTED;

	d->setIndex(m_hardware->m_lstFloppyDisks.size());
	m_hardware->addFloppyDisk(d);
	return PRL_ERR_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
// struct Disk

PRL_RESULT Disk::operator()(const Libvirt::Domain::Xml::Disk& disk_)
{
	if (!Clustered<CVmHardDisk>::operator()(disk_))
		return PRL_ERR_UNIMPLEMENTED;

	getDevice().setEncrypted(disk_.getEncryption());
	CVmHardDisk* d = getResult();
	if (NULL == d)
		return PRL_ERR_UNEXPECTED;

	d->setIndex(m_hardware->m_lstHardDisks.size());
	m_hardware->addHardDisk(d);
	m_boot->operator()(*d, disk_.getBoot());
	return PRL_ERR_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
// struct Cdrom

PRL_RESULT Cdrom::operator()(const Libvirt::Domain::Xml::Disk& disk_)
{
	Clustered<CVmOpticalDisk>::operator()(disk_);
	getDevice().setPassthrough(disk_.getTransient() ?
		PVE::PassthroughEnabled : PVE::PassthroughDisabled);

	CVmOpticalDisk* d = getResult();
	if (NULL == d)
		return PRL_ERR_UNEXPECTED;

	d->setIndex(m_hardware->m_lstOpticalDisks.size());
	m_hardware->addOpticalDisk(d);
	m_boot->operator()(*d, disk_.getBoot());
	return PRL_ERR_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
// struct Graphics

PRL_RESULT Graphics::operator()(const mpl::at_c<Libvirt::Domain::Xml::VGraphics::types, 1>::type& vnc_) const
{
	if (0 != vnc_.getValue().getChoice683().which())
		return PRL_ERR_UNIMPLEMENTED;
		
	QScopedPointer<CVmRemoteDisplay> v(new CVmRemoteDisplay());
	if (vnc_.getValue().getPasswd())
	{
		v->setPassword(vnc_.getValue().getPasswd().get());
	}
	const mpl::at_c<Libvirt::Domain::Xml::VChoice683::types, 0>::type* s =
		boost::get<mpl::at_c<Libvirt::Domain::Xml::VChoice683::types, 0>::type>
			(&vnc_.getValue().getChoice683());
	if (s->getValue().getPort())
	{
		v->setPortNumber(s->getValue().getPort().get());
	}
	if (s->getValue().getListen())
	{
		v->setHostName(s->getValue().getListen().get());
	}
	if (s->getValue().getAutoport())
	{
		v->setMode(Libvirt::Domain::Xml::EVirYesNoYes == s->getValue().getAutoport().get() ?
			PRD_AUTO : PRD_MANUAL);
	}
	m_vm->getVmSettings()->setVmRemoteDisplay(v.take());
	return PRL_ERR_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
// struct Network

PRL_VM_NET_ADAPTER_TYPE Network::parseAdapterType(const QString& type)
{
	if (type == "ne2k_pci")
		return PNT_RTL;
	else if (type == "e1000")
		return PNT_E1000;
	else if (type == "virtio")
		return PNT_VIRTIO;
	return PNT_UNDEFINED;
}

PRL_RESULT Network::operator()(const mpl::at_c<Libvirt::Domain::Xml::VInterface::types, 0>::type& bridge_) const
{
	QScopedPointer<CVmGenericNetworkAdapter> a(new CVmGenericNetworkAdapter());
	a->setIndex(m_hardware->m_lstNetworkAdapters.size());
	a->setConnected();
	a->setEnabled(PVE::DeviceEnabled);
	a->setEmulatedType(PNA_BRIDGED_ETHERNET);
	if (bridge_.getValue().getModel())
	{
		a->setAdapterType(parseAdapterType(bridge_.getValue().getModel().get()));
	}
	if (bridge_.getValue().getSource())
	{
		a->setHostInterfaceName(bridge_.getValue().getSource().get());
		a->setBoundAdapterName(bridge_.getValue().getSource().get());
	}
	if (bridge_.getValue().getMac())
	{
		a->setMacAddress(bridge_.getValue().getMac().get());
	}
	if (bridge_.getValue().getTarget())
	{
		a->setSystemName(bridge_.getValue().getTarget().get());
	}
	if (bridge_.getValue().getFilterref())
	{
		CNetPktFilter* f = new CNetPktFilter();
		a->setPktFilter(f);
	}
	m_hardware->addNetworkAdapter(a.take());
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Network::operator()(const mpl::at_c<Libvirt::Domain::Xml::VInterface::types, 3>::type& network_) const
{
	QScopedPointer<CVmGenericNetworkAdapter> a(new CVmGenericNetworkAdapter());
	a->setIndex(m_hardware->m_lstNetworkAdapters.size());
	a->setConnected();
	a->setEnabled(PVE::DeviceEnabled);
	a->setEmulatedType(PNA_BRIDGED_ETHERNET);
	if (network_.getValue().getModel())
	{
		a->setAdapterType(parseAdapterType(network_.getValue().getModel().get()));
	}
	a->setVirtualNetworkID(network_.getValue().getSource().getNetwork());
	if (network_.getValue().getMac())
	{
		a->setMacAddress(network_.getValue().getMac().get());
	}
	if (network_.getValue().getTarget())
	{
		a->setSystemName(network_.getValue().getTarget().get());
	}
	m_hardware->addNetworkAdapter(a.take());
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Network::operator()(const mpl::at_c<Libvirt::Domain::Xml::VInterface::types, 4>::type& direct_) const
{
	QScopedPointer<CVmGenericNetworkAdapter> a(new CVmGenericNetworkAdapter());
	a->setIndex(m_hardware->m_lstNetworkAdapters.size());
	a->setConnected();
	a->setEnabled(PVE::DeviceEnabled);
	a->setEmulatedType(PNA_DIRECT_ASSIGN);
	if (direct_.getValue().getModel())
	{
		a->setAdapterType(parseAdapterType(direct_.getValue().getModel().get()));
	}
	a->setHostInterfaceName(direct_.getValue().getSource().getDev());
	if (direct_.getValue().getMac())
	{
		a->setMacAddress(direct_.getValue().getMac().get());
	}
	if (direct_.getValue().getTarget())
	{
		a->setSystemName(direct_.getValue().getTarget().get());
	}
	m_hardware->addNetworkAdapter(a.take());
	return PRL_ERR_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
// struct Device

PRL_RESULT Device::operator()(const mpl::at_c<Libvirt::Domain::Xml::VChoice928::types, 4>::type& interface_) const
{
	CVmHardware* h = m_vm->getVmHardwareList();
	if (NULL == h)
		return PRL_ERR_UNEXPECTED;

	return boost::apply_visitor(Network(*h), interface_.getValue());
}

PRL_RESULT Device::operator()(const mpl::at_c<Libvirt::Domain::Xml::VChoice928::types, 6>::type& sound_) const
{
	CVmHardware* h = m_vm->getVmHardwareList();
	if (NULL == h)
		return PRL_ERR_UNEXPECTED;

	CVmSoundDevice* d = new CVmSoundDevice();
	d->setIndex(h->m_lstSoundDevices.size());
	if (sound_.getValue().getAlias())
		d->setUserFriendlyName(sound_.getValue().getAlias().get());

	h->addSoundDevice(d);
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Device::operator()(const mpl::at_c<Libvirt::Domain::Xml::VChoice928::types, 11>::type& parallel_) const
{
	CVmHardware* h = m_vm->getVmHardwareList();
	if (NULL == h)
		return PRL_ERR_UNEXPECTED;

	CVmParallelPort* p = new CVmParallelPort();
	p->setIndex(h->m_lstParallelPorts.size());
	if (parallel_.getValue().getAlias())
	{
		p->setUserFriendlyName(parallel_.getValue().getAlias().get());
		p->setSystemName(p->getUserFriendlyName());
	}

	h->addParallelPort(p);
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Device::operator()(const mpl::at_c<Libvirt::Domain::Xml::VChoice928::types, 12>::type& serial_) const
{
	CVmHardware* h = m_vm->getVmHardwareList();
	if (NULL == h)
		return PRL_ERR_UNEXPECTED;

	if (Libvirt::Domain::Xml::EQemucdevSrcTypeChoiceFile != serial_.getValue().getType())
		return PRL_ERR_SUCCESS;

	if (serial_.getValue().getQemucdevSrcDef().getSourceList().isEmpty())
		return PRL_ERR_SUCCESS;

	if (!serial_.getValue().getQemucdevSrcDef().getSourceList().front().getPath())
		return PRL_ERR_SUCCESS;

	CVmSerialPort* p = new CVmSerialPort();
	p->setIndex(h->m_lstSerialPorts.size());
	p->setEnabled(true);
	p->setEmulatedType(PVE::SerialOutputFile);
	p->setUserFriendlyName(serial_.getValue().getQemucdevSrcDef()
		.getSourceList().front().getPath().get());
	p->setSystemName(p->getUserFriendlyName());
	h->addSerialPort(p);
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Device::operator()(const mpl::at_c<Libvirt::Domain::Xml::VChoice928::types, 0>::type& disk_) const
{
	if (0 != disk_.getValue().getDisk().which())
		return PRL_ERR_SUCCESS;

	const Libvirt::Domain::Xml::EDevice* e = boost::get<mpl::at_c<Libvirt::Domain::Xml::VDisk::types, 0>::type>
		(disk_.getValue().getDisk()).getValue().get_ptr();
	if (NULL != e)
	{
		CVmHardware* h = m_vm->getVmHardwareList();
		if (NULL == h)
			return PRL_ERR_UNEXPECTED;

		switch (*e)
		{
		case Libvirt::Domain::Xml::EDeviceDisk:
			return Disk(*h, *m_boot)(disk_.getValue());
		case Libvirt::Domain::Xml::EDeviceCdrom:
			return Cdrom(*h, *m_boot)(disk_.getValue());
		case Libvirt::Domain::Xml::EDeviceFloppy:
			return Floppy(*h)(disk_.getValue());
		}
	}
	return PRL_ERR_UNIMPLEMENTED;
}

PRL_RESULT Device::operator()(const mpl::at_c<Libvirt::Domain::Xml::VChoice928::types, 9>::type& video_) const
{
	CVmHardware* h = m_vm->getVmHardwareList();
	if (NULL == h)
		return PRL_ERR_UNEXPECTED;

	CVmVideo* v = new CVmVideo();
	if (video_.getValue().getModel())
	{
		if (video_.getValue().getModel().get().getVram())
		{
			v->setMemorySize(video_.getValue().getModel()
				.get().getVram().get() >> 10);
		}
		if (video_.getValue().getModel().get().getAcceleration())
		{
			const Libvirt::Domain::Xml::EVirYesNo* a3 = video_.getValue().getModel()
				.get().getAcceleration().get().getAccel3d().get_ptr();
			v->setEnable3DAcceleration(NULL != a3 && *a3 == Libvirt::Domain::Xml::EVirYesNoYes ?
				P3D_DISABLED : P3D_ENABLED_HIGHEST);
		}
	}
	v->setEnabled(true);
	h->setVideo(v);
	return PRL_ERR_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
// struct Clock

void Clock::operator()(const mpl::at_c<Libvirt::Domain::Xml::VClock::types, 0>::type& fixed_) const
{
	if (!fixed_.getValue().getAdjustment())
		return;

	const Libvirt::Domain::Xml::VAdjustment& a = fixed_.getValue().getAdjustment().get();
	m_clock->setTimeShift(boost::get<mpl::at_c<Libvirt::Domain::Xml::VAdjustment::types, 1>::type>
		(a).getValue().toLongLong());
}

void Clock::operator()(const mpl::at_c<Libvirt::Domain::Xml::VClock::types, 2>::type& variable_) const
{
	if (!variable_.getValue().getAdjustment())
		return;

	m_clock->setTimeShift(variable_.getValue().getAdjustment().get().toLongLong());
}

} // namespace Visitor

namespace
{
template<class T>
void shape(char* xml_, QScopedPointer<T>& dst_)
{
	if (NULL == xml_)
		return;

	QByteArray b(xml_);
	free(xml_);
	QDomDocument x;
	if (!x.setContent(b, true))
		return;

	QScopedPointer<T> g(new T());
	if (g->load(x.documentElement()))
		dst_.reset(g.take());
}

} // namespace

namespace Vm
{
///////////////////////////////////////////////////////////////////////////////
// struct Direct

Direct::Direct(char* xml_)
{
	shape(xml_, m_input);
}

PRL_RESULT Direct::setBlank()
{
	if (m_input.isNull())
		return PRL_ERR_READ_XML_CONTENT;
 
	if (Libvirt::Domain::Xml::ETypeKvm != m_input->getType())
		return PRL_ERR_BAD_VM_CONFIG_FILE_SPECIFIED;

	m_result.reset(new CVmConfiguration());
	m_result->setVmType(PVT_VM);
	m_result->setVmHardwareList(new CVmHardware());
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Direct::setIdentification()
{
	if (m_result.isNull())
		return PRL_ERR_UNINITIALIZED;

	CVmIdentification* i = new CVmIdentification();
        i->setVmName(m_input->getIds().getName());
	if (m_input->getIds().getUuid())
	{
		Visitor::Uuid<Libvirt::Domain::Xml::VUUID> v
			(boost::bind(&CVmIdentification::setVmUuid, &*i, _1));
		boost::apply_visitor(v, m_input->getIds().getUuid().get());
	}
	m_result->setVmIdentification(i);
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Direct::setSettings()
{
	if (m_result.isNull())
		return PRL_ERR_UNINITIALIZED;

	CVmSettings* s = new CVmSettings();
	CVmCommonOptions* o = new CVmCommonOptions();
	s->setVmCommonOptions(o);
	if (m_input->getDescription())
		o->setVmDescription(m_input->getDescription().get());

	m_result->setVmSettings(s);
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Direct::setDevices()
{
	if (m_result.isNull())
		return PRL_ERR_UNINITIALIZED;

	const Libvirt::Domain::Xml::Devices* d = m_input->getDevices().get_ptr();
	if (NULL != d)
	{
		Boot::Direct b;
		foreach (const Libvirt::Domain::Xml::VChoice928& v, d->getChoice928List())
		{
			boost::apply_visitor(Visitor::Device(*m_result, b), v);
		}
		m_result->getVmSettings()->
			getVmStartupOptions()->setBootDeviceList(b.getResult());
	}
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Direct::setResources()
{
	if (m_result.isNull())
		return PRL_ERR_UNINITIALIZED;

	Resources r(*m_result->getVmHardwareList());
	r.setMemory(m_input->getMemory());
	if (m_input->getVcpu())
		r.setCpu(m_input->getVcpu().get());
	if (m_input->getClock())
		r.setClock(m_input->getClock().get());
	if (m_input->getSysinfo())
		r.setChipset(m_input->getSysinfo().get());

	return PRL_ERR_SUCCESS;
}

} // namespace Vm

namespace Network
{
///////////////////////////////////////////////////////////////////////////////
// struct Direct

Direct::Direct(char* xml_, bool enabled_)
{
	m_result.setEnabled(enabled_);
	shape(xml_, m_input);
}

PRL_RESULT Direct::setUuid()
{
	if (m_input.isNull())
		return PRL_ERR_READ_XML_CONTENT;
 
	if (m_input->getUuid())
	{
		Visitor::Uuid<Libvirt::Network::Xml::VUUID> v
			(boost::bind(&CVirtualNetwork::setUuid, &m_result, _1));
		boost::apply_visitor(v, m_input->getUuid().get());
	}
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Direct::setName()
{
	if (m_input.isNull())
		return PRL_ERR_READ_XML_CONTENT;
 
	m_result.setNetworkID(m_input->getName());
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Direct::setType()
{
	if (m_input.isNull())
		return PRL_ERR_READ_XML_CONTENT;

	if (!m_input->getForward()) 
		m_result.setNetworkType(PVN_HOST_ONLY);
	else if (m_input->getForward().get().getMode() && 
		m_input->getForward().get().getMode().get() == Libvirt::Network::Xml::EModeBridge)
		m_result.setNetworkType(PVN_BRIDGED_ETHERNET);
	else
		return PRL_ERR_UNIMPLEMENTED;
		
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Direct::setBridge()
{
	if (m_input.isNull())
		return PRL_ERR_READ_XML_CONTENT;
 
	if (m_input->getBridge())
	{
                CVZVirtualNetwork* z = new CVZVirtualNetwork();
                z->setBridgeName(m_input->getBridge().get().getName().get());
		m_result.setVZVirtualNetwork(z);
	}
	else if (m_input->getMac())
		m_result.setBoundCardMac(m_input->getMac().get());

	return PRL_ERR_SUCCESS;
}

PRL_RESULT Direct::setVlan()
{
	if (m_input.isNull())
		return PRL_ERR_READ_XML_CONTENT;
 
	if (m_input->getVlan() && !m_input->getVlan().get().isEmpty())
		m_result.setVLANTag(m_input->getVlan().get().front().getId());

	return PRL_ERR_SUCCESS;
}

PRL_RESULT Direct::setHostOnly()
{
	return PRL_ERR_SUCCESS;
}

} // namespace Network

namespace Interface
{
namespace Physical
{
///////////////////////////////////////////////////////////////////////////////
// struct Direct

Direct::Direct(char* xml_, bool enabled_)
{
	m_result.setEnabled(enabled_);
	shape(xml_, m_input);
}

PRL_RESULT Direct::operator()()
{
	if (m_input.isNull())
		return PRL_ERR_READ_XML_CONTENT;

	m_result.setDeviceName(m_input->getName());
	if (m_input->getMac())
		m_result.setMacAddress(m_input->getMac().get());

	boost::apply_visitor(Visitor::Addressing(m_result),
		m_input->getInterfaceAddressing());

	if (m_result.isConfigureWithDhcp())
		m_result.setConfigureWithDhcpIPv6(true);

	return PRL_ERR_SUCCESS;
}

} // namespace Physical

namespace Bridge
{
///////////////////////////////////////////////////////////////////////////////
// struct Direct

Direct::Direct(char* xml_, bool enabled_): m_stp(), m_enabled(enabled_), m_delay()
{
	shape(xml_, m_input);
}

PRL_RESULT Direct::setMaster()
{
	if (m_input.isNull())
		return PRL_ERR_READ_XML_CONTENT;
 
	typedef mpl::at_c<Libvirt::Iface::Xml::VChoice1227::types, 0>::type eth_type;
	foreach (const Libvirt::Iface::Xml::VChoice1227& a,
		m_input->getBridge().getChoice1227List())
	{
		if (0 != a.which())
			continue;

		m_master.setDeviceName(boost::get<eth_type>(a).getValue().getName());
		if (boost::get<eth_type>(a).getValue().getMac())
			m_master.setMacAddress(boost::get<eth_type>(a).getValue().getMac().get());

		return PRL_ERR_SUCCESS;
	}
	return PRL_ERR_FILE_NOT_FOUND;
}

PRL_RESULT Direct::setBridge()
{
	if (m_input.isNull())
		return PRL_ERR_READ_XML_CONTENT;

	if (m_input->getBridge().getStp())
	{
		m_stp = Libvirt::Iface::Xml::EVirOnOffOn ==
			m_input->getBridge().getStp().get();
	}
	if (m_input->getBridge().getDelay())
		m_delay = m_input->getBridge().getDelay().get();

	return PRL_ERR_SUCCESS;
}

PRL_RESULT Direct::setInterface()
{
	if (m_input.isNull())
		return PRL_ERR_READ_XML_CONTENT;
 
	m_name = m_input->getName();
	return PRL_ERR_SUCCESS;
}

} // namespace Bridge
} // namespace Interface

namespace Boot
{
///////////////////////////////////////////////////////////////////////////////
// struct Direct

void Direct::operator()(const CVmDevice& device_, const order_type& order_)
{
	order_type::pointer_const_type o = order_.get_ptr();
	if (NULL == o)
		return;

	m_map[*o] = std::make_pair(device_.getDeviceType(), device_.getIndex());
}

QList<Direct::device_type*> Direct::getResult() const
{
	unsigned o = 0;
	QList<device_type*> output;
	foreach (map_type::const_reference x, m_map)
	{
		output << new device_type(x.second.first, x.second.second,
			++o, true);
	}
	return output;
}

} // namespace Boot
} // namespace Transponster

