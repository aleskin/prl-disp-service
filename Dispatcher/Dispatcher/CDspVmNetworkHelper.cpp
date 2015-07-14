///////////////////////////////////////////////////////////////////////////////
///
/// @file CDspVmNetworkHelper.cpp
///
///	This class implements functions to help manage vm network parameters
///
/// @author andreydanin
///
/// Copyright (c) 2005-2015 Parallels IP Holdings GmbH
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
/// Our contact details: Parallels IP Holdings GmbH, Vordergasse 59, 8200
/// Schaffhausen, Switzerland.
///
///////////////////////////////////////////////////////////////////////////////

#include <QMutexLocker>

#include "CDspVmNetworkHelper.h"
#include "CDspService.h"
#include "Tasks/Task_ManagePrlNetService.h"

#include "Libraries/HostUtils/HostUtils.h"
#include <Libraries/PrlNetworking/netconfig.h>
#include "Libraries/PrlNetworking/PrlNetLibrary.h"


void CDspVmNetworkHelper::getUsedHostMacAddresses(QSet< QString >& hostMacs)
{
	bool bHostMac = true;
	extractAllVmMacAddresses(hostMacs, bHostMac);
	Task_ManagePrlNetService::getHostMacAddresses(hostMacs);
}


void CDspVmNetworkHelper::extractMacAddressesFromVMConfiguration(SmartPtr<CVmConfiguration> config,
		QSet<QString>& macs,
		bool hostAddresses)
{
	QListIterator<CVmHardware*> itH(config->m_lstHardware);
	while (itH.hasNext())
	{
		CVmHardware* hard = itH.next();
		if (!hard)
			continue;

		QListIterator<CVmGenericNetworkAdapter*> itN(hard->m_lstNetworkAdapters);
		while (itN.hasNext())
		{
			CVmGenericNetworkAdapter* adapter(itN.next());
			if (!adapter)
				continue;

			QString mac = hostAddresses ? adapter->getHostMacAddress() : adapter->getMacAddress();
			if (!mac.isEmpty())
				macs.insert(mac.toUpper());
		}
	}
}


bool CDspVmNetworkHelper::extractAllVmMacAddresses(QSet<QString>& macs, bool hostAddresses)
{
	QMultiHash< QString, SmartPtr<CVmConfiguration> >
		vmTotalHash = CDspService::instance()->getVmDirHelper().getAllVmList();
	foreach( QString dirUuid, vmTotalHash.keys() )
	{
		QList< SmartPtr<CVmConfiguration> >
			vmList = vmTotalHash.values( dirUuid );
		for( int idx=0; idx<vmList.size(); idx++)
		{
			SmartPtr<CVmConfiguration> pConfig( vmList[idx] );
			if (!pConfig)
				continue;

			extractMacAddressesFromVMConfiguration(pConfig, macs, hostAddresses);
		}//for idx
	} //foreach( QString dirUuid

	return true;
}


bool CDspVmNetworkHelper::isMacAddrConflicts(const QString& mac,
		const QSet<QString>& used)
{
	foreach (const QString& usedMac, used)
	{
		if (PrlNet::isEqualEthAddress(mac, usedMac))
		{
			WRITE_TRACE(DBG_WARNING, "addr %s conflicts", QSTR2UTF8(mac));
			return true;
		}
	}
	return false;
}


bool CDspVmNetworkHelper::checkAndMakeUniqueMacAddr(QString& mac, const QSet<QString>& used,
		HostUtils::MacPrefixType prefix)
{
	if (mac.isEmpty())
		mac = HostUtils::generateMacAddress(prefix);

	int i = 0;
	while (isMacAddrConflicts(mac, used) && i++ < 20)
	{
		mac = HostUtils::generateMacAddress(prefix);
	}

	if (i > 20)
	{
		WRITE_TRACE(DBG_FATAL, "Failed to gen vm hwaddr");
		return false;
	}

	return true;
}


void CDspVmNetworkHelper::updateHostMacAddresses(SmartPtr<CVmConfiguration> pVmConfig,
		QSet<QString>* pMacs, HostMacUpdateFlags flags)
{
	QSet<QString> localUsed;
	QSet<QString>* pUsed = (pMacs ? pMacs : &localUsed);

	getUsedHostMacAddresses(*pUsed);

	QListIterator<CVmHardware*> itH(pVmConfig->m_lstHardware);
	while (itH.hasNext())
	{
		CVmHardware* hard = itH.next();
		if (!hard)
			continue;

		QListIterator<CVmGenericNetworkAdapter*> itN(hard->m_lstNetworkAdapters);
		while (itN.hasNext())
		{
			CVmGenericNetworkAdapter* adapter(itN.next());
			updateHostMacAddress(pVmConfig, adapter, *pUsed, flags);
		}
	}
}


void CDspVmNetworkHelper::updateHostMacAddress(SmartPtr<CVmConfiguration> pVmConfig,
		CVmGenericNetworkAdapter *pAdapter, const QSet<QString>& used, HostMacUpdateFlags flags)
{
	if (!pAdapter)
		return;

	QString mac = pAdapter->getHostMacAddress();
	if (!mac.isEmpty() && !(flags & HMU_CHECK_NONEMPTY))
		return;

	// Form own mac address list
	QSet<QString> own;
	bool hostAddresses = true;
	CDspVmNetworkHelper::extractMacAddressesFromVMConfiguration(pVmConfig, own, hostAddresses);
	own.insert(pAdapter->getMacAddress()); // add guiest mac to used list

	HostUtils::MacPrefixType prefix = HostUtils::MAC_PREFIX_VM;
	switch (pVmConfig->getVmType()) {
	case PVT_CT:
		prefix = HostUtils::MAC_PREFIX_CT;
		break;
	case PVT_VM:
		prefix = HostUtils::MAC_PREFIX_VM;
		break;
	}

	if (!checkAndMakeUniqueMacAddr(mac, own + used, prefix))
		return;

	WRITE_TRACE(DBG_FATAL, "Update host hwaddr %s of adapter[%d] vm %s (%s)",
			QSTR2UTF8(mac), pAdapter->getIndex(),
			QSTR2UTF8(pVmConfig->getVmIdentification()->getVmName()),
			QSTR2UTF8(pVmConfig->getVmIdentification()->getVmUuid()));

	pAdapter->setHostMacAddress(mac);
}

namespace Network
{
///////////////////////////////////////////////////////////////////////////////
// struct Dao

Dao::Dao(Libvirt::Tools::Agent::Hub& libvirt_):
	m_networks(libvirt_.networks()), m_interfaces(libvirt_.interfaces())
{
}

PRL_RESULT Dao::list(QList<CVirtualNetwork>& dst_)
{
	QList<Libvirt::Tools::Agent::Network::Unit> a;
	PRL_RESULT e = m_networks.all(a);
	if (PRL_FAILED(e))
	{
		WRITE_TRACE(DBG_FATAL, "Cannot list networks!");
		return PRL_ERR_UNEXPECTED;
	}
	QStringList x;
	foreach(Libvirt::Tools::Agent::Network::Unit n, a)
	{
		CVirtualNetwork y;
		if (PRL_FAILED(e = n.getConfig(y)))
		{
			WRITE_TRACE(DBG_FATAL, "Cannot get the network config!");
			return e;
		}
		dst_ << y;
	}
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Dao::define(CVirtualNetwork model_)
{
	PRL_RESULT e;
	if (PVN_HOST_ONLY == model_.getNetworkType())
		e = PrlNet::ValidateHostOnlyNetworkParams(&model_);
	else
		e = craftBridge(model_);

	if (PRL_FAILED(e))
		return e;

	Libvirt::Tools::Agent::Network::Unit u;
	if (PRL_FAILED(e = m_networks.define(model_, &u)))
		return e;

	u.stop();
	u.start();
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Dao::create(const CVirtualNetwork& model_)
{
	QString x = model_.getNetworkID();
	if (PRL_SUCCEEDED(m_networks.find(x)))
	{
		WRITE_TRACE(DBG_FATAL, "Duplicated new network ID '%s' !", QSTR2UTF8(x));
		return PRL_NET_DUPLICATE_VIRTUAL_NETWORK_ID;
	}
	return define(model_);
}

PRL_RESULT Dao::remove(const CVirtualNetwork& model_)
{
	QString x = model_.getNetworkID();
	Libvirt::Tools::Agent::Network::Unit u;
	if (PRL_FAILED(m_networks.find(x, &u)))
	{
		WRITE_TRACE(DBG_FATAL, "The network ID '%s' does not exist !",
			QSTR2UTF8(x));
		return PRL_NET_VIRTUAL_NETWORK_ID_NOT_EXISTS;
	}
	u.stop();
	return u.undefine();
}

PRL_RESULT Dao::update(const CVirtualNetwork& model_)
{
	CVirtualNetwork w;
	QString x = model_.getNetworkID();
	Libvirt::Tools::Agent::Network::Unit u = m_networks.at(model_.getUuid());
	if (PRL_FAILED(u.getConfig(w)))
	{
		WRITE_TRACE(DBG_FATAL, "The network ID '%s' was not found by uuid!", QSTR2UTF8(x));
		return PRL_NET_VIRTUAL_NETWORK_NOT_FOUND;
	}
	if (w.getNetworkID() != x)
	{
		WRITE_TRACE(DBG_FATAL, "Cannot change the network ID '%s' !", QSTR2UTF8(x));
		return PRL_NET_DUPLICATE_VIRTUAL_NETWORK_ID;
	}
	return define(model_);
}

PRL_RESULT Dao::craftBridge(CVirtualNetwork& network_)
{
	if (PVN_HOST_ONLY == network_.getNetworkType())
		return PRL_ERR_INVALID_PARAM;

	PRL_RESULT e;
	CHwNetAdapter m;
	if (network_.isBridgedToDefaultAdapter())
	{
		PrlNet::EthAdaptersList a;
		PrlNet::EthAdaptersList::Iterator p;
		e = PrlNet::getDefaultBridgedAdapter(a, p);
		if (a.end() != p)
		{
			m.setDeviceName(p->_name);
			m.setMacAddress(PrlNet::ethAddressToString(p->_macAddr));
		}
		else if (PRL_SUCCEEDED(e))
			e = PRL_ERR_FILE_NOT_FOUND;
	}
	else
		e = m_interfaces.find(network_.getBoundCardMac(), m);

	if (PRL_FAILED(e))
		return e;

	Libvirt::Tools::Agent::Interface::Bridge b;
	e = m_interfaces.find(m, b);
	if (PRL_ERR_FILE_NOT_FOUND == e)
	{
		if (PRL_FAILED(e = m_interfaces.define(m, b)))
			return e;

		QProcess::execute("ifdown", QStringList() << m.getDeviceName());
		QProcess::execute("ifup", QStringList() << b.getName());
		QProcess::execute("ifup", QStringList() << m.getDeviceName());
	}
	else if (PRL_FAILED(e))
		return e;
	else
		b.start();
	CVZVirtualNetwork* z = new CVZVirtualNetwork();
	z->setBridgeName(b.getName());
	z->setMasterInterface(m.getDeviceName());
	network_.setVZVirtualNetwork(z);
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Dao::attachExisting(CVirtualNetwork model_,
	const QString& bridge_)
{
	if (PVN_HOST_ONLY == model_.getNetworkType())
		return PRL_ERR_INVALID_ARG;

	CVZVirtualNetwork* z = new CVZVirtualNetwork();
	z->setBridgeName(bridge_);
	model_.setVZVirtualNetwork(z);
	Libvirt::Tools::Agent::Network::Unit u;
	PRL_RESULT e = m_networks.define(model_, &u);
	if (PRL_FAILED(e))
		return e;

	u.start();
	return PRL_ERR_SUCCESS;
}

} // namespace Network

