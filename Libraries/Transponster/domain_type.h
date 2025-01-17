/*
 * Copyright (c) 2015-2017, Parallels International GmbH
 * Copyright (c) 2017-2021 Virtuozzo International GmbH. All rights reserved.
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
 * Our contact details: Virtuozzo International GmbH, Vordergasse 59, 8200
 * Schaffhausen, Switzerland.
 */

#ifndef __DOMAIN_TYPE_H__
#define __DOMAIN_TYPE_H__
#include "base.h"
#include "domain_data.h"
#include "domain_enum.h"
#include "patterns.h"
#include <boost/any.hpp>

namespace Libvirt
{
namespace Domain
{
namespace Xml
{
struct VDiskBackingChainBin;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Ids

namespace Domain
{
namespace Xml
{
struct Ids
{
	const boost::optional<PUnsignedInt::value_type >& getId() const
	{
		return m_id;
	}
	void setId(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_id = value_;
	}
	const PDomainName::value_type& getName() const
	{
		return m_name;
	}
	void setName(const PDomainName::value_type& value_)
	{
		m_name = value_;
	}
	const boost::optional<VUUID >& getUuid() const
	{
		return m_uuid;
	}
	void setUuid(const boost::optional<VUUID >& value_)
	{
		m_uuid = value_;
	}
	const boost::optional<VUUID >& getGenid() const
	{
		return m_genid;
	}
	void setGenid(const boost::optional<VUUID >& value_)
	{
		m_genid = value_;
	}
	const boost::optional<PGenericName::value_type >& getExtraId() const
	{
		return m_extraId;
	}
	void setExtraId(const boost::optional<PGenericName::value_type >& value_)
	{
		m_extraId = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	boost::optional<PUnsignedInt::value_type > m_id;
	PDomainName::value_type m_name;
	boost::optional<VUUID > m_uuid;
	boost::optional<VUUID > m_genid;
	boost::optional<PGenericName::value_type > m_extraId;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Model

namespace Domain
{
namespace Xml
{
struct Model
{
	const boost::optional<EFallback >& getFallback() const
	{
		return m_fallback;
	}
	void setFallback(const boost::optional<EFallback >& value_)
	{
		m_fallback = value_;
	}
	const boost::optional<PVendorId::value_type >& getVendorId() const
	{
		return m_vendorId;
	}
	void setVendorId(const boost::optional<PVendorId::value_type >& value_)
	{
		m_vendorId = value_;
	}
	const QString& getOwnValue() const
	{
		return m_ownValue;
	}
	void setOwnValue(const QString& value_)
	{
		m_ownValue = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EFallback > m_fallback;
	boost::optional<PVendorId::value_type > m_vendorId;
	QString m_ownValue;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Topology

namespace Domain
{
namespace Xml
{
struct Topology
{
	Topology();

	PPositiveInteger::value_type getSockets() const
	{
		return m_sockets;
	}
	void setSockets(PPositiveInteger::value_type value_)
	{
		m_sockets = value_;
	}
	const boost::optional<PPositiveInteger::value_type >& getDies() const
	{
		return m_dies;
	}
	void setDies(const boost::optional<PPositiveInteger::value_type >& value_)
	{
		m_dies = value_;
	}
	PPositiveInteger::value_type getCores() const
	{
		return m_cores;
	}
	void setCores(PPositiveInteger::value_type value_)
	{
		m_cores = value_;
	}
	PPositiveInteger::value_type getThreads() const
	{
		return m_threads;
	}
	void setThreads(PPositiveInteger::value_type value_)
	{
		m_threads = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PPositiveInteger::value_type m_sockets;
	boost::optional<PPositiveInteger::value_type > m_dies;
	PPositiveInteger::value_type m_cores;
	PPositiveInteger::value_type m_threads;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Feature

namespace Domain
{
namespace Xml
{
struct Feature
{
	Feature();

	EPolicy getPolicy() const
	{
		return m_policy;
	}
	void setPolicy(EPolicy value_)
	{
		m_policy = value_;
	}
	const PFeatureName::value_type& getName() const
	{
		return m_name;
	}
	void setName(const PFeatureName::value_type& value_)
	{
		m_name = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EPolicy m_policy;
	PFeatureName::value_type m_name;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Sibling

namespace Domain
{
namespace Xml
{
struct Sibling
{
	Sibling();

	PUnsignedInt::value_type getId() const
	{
		return m_id;
	}
	void setId(PUnsignedInt::value_type value_)
	{
		m_id = value_;
	}
	PNumaDistanceValue::value_type getValue() const
	{
		return m_value;
	}
	void setValue(PNumaDistanceValue::value_type value_)
	{
		m_value = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_id;
	PNumaDistanceValue::value_type m_value;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Size

namespace Domain
{
namespace Xml
{
struct Size
{
	Size();

	PUnsignedInt::value_type getValue() const
	{
		return m_value;
	}
	void setValue(PUnsignedInt::value_type value_)
	{
		m_value = value_;
	}
	const PUnit::value_type& getUnit() const
	{
		return m_unit;
	}
	void setUnit(const PUnit::value_type& value_)
	{
		m_unit = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_value;
	PUnit::value_type m_unit;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Line

namespace Domain
{
namespace Xml
{
struct Line
{
	Line();

	PUnsignedInt::value_type getValue() const
	{
		return m_value;
	}
	void setValue(PUnsignedInt::value_type value_)
	{
		m_value = value_;
	}
	const PUnit::value_type& getUnit() const
	{
		return m_unit;
	}
	void setUnit(const PUnit::value_type& value_)
	{
		m_unit = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_value;
	PUnit::value_type m_unit;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Cache

namespace Domain
{
namespace Xml
{
struct Cache
{
	Cache();

	PUnsignedInt::value_type getLevel() const
	{
		return m_level;
	}
	void setLevel(PUnsignedInt::value_type value_)
	{
		m_level = value_;
	}
	EAssociativity getAssociativity() const
	{
		return m_associativity;
	}
	void setAssociativity(EAssociativity value_)
	{
		m_associativity = value_;
	}
	EPolicy1 getPolicy() const
	{
		return m_policy;
	}
	void setPolicy(EPolicy1 value_)
	{
		m_policy = value_;
	}
	const Size& getSize() const
	{
		return m_size;
	}
	void setSize(const Size& value_)
	{
		m_size = value_;
	}
	const Line& getLine() const
	{
		return m_line;
	}
	void setLine(const Line& value_)
	{
		m_line = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_level;
	EAssociativity m_associativity;
	EPolicy1 m_policy;
	Size m_size;
	Line m_line;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Cell

namespace Domain
{
namespace Xml
{
struct Cell
{
	Cell();

	const boost::optional<PUnsignedInt::value_type >& getId() const
	{
		return m_id;
	}
	void setId(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_id = value_;
	}
	const boost::optional<PCpuset::value_type >& getCpus() const
	{
		return m_cpus;
	}
	void setCpus(const boost::optional<PCpuset::value_type >& value_)
	{
		m_cpus = value_;
	}
	PMemoryKB1::value_type getMemory() const
	{
		return m_memory;
	}
	void setMemory(PMemoryKB1::value_type value_)
	{
		m_memory = value_;
	}
	const boost::optional<PUnit::value_type >& getUnit() const
	{
		return m_unit;
	}
	void setUnit(const boost::optional<PUnit::value_type >& value_)
	{
		m_unit = value_;
	}
	const boost::optional<EMemAccess >& getMemAccess() const
	{
		return m_memAccess;
	}
	void setMemAccess(const boost::optional<EMemAccess >& value_)
	{
		m_memAccess = value_;
	}
	const boost::optional<EVirYesNo >& getDiscard() const
	{
		return m_discard;
	}
	void setDiscard(const boost::optional<EVirYesNo >& value_)
	{
		m_discard = value_;
	}
	const boost::optional<QList<Sibling > >& getDistances() const
	{
		return m_distances;
	}
	void setDistances(const boost::optional<QList<Sibling > >& value_)
	{
		m_distances = value_;
	}
	const QList<Cache >& getCacheList() const
	{
		return m_cacheList;
	}
	void setCacheList(const QList<Cache >& value_)
	{
		m_cacheList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PUnsignedInt::value_type > m_id;
	boost::optional<PCpuset::value_type > m_cpus;
	PMemoryKB1::value_type m_memory;
	boost::optional<PUnit::value_type > m_unit;
	boost::optional<EMemAccess > m_memAccess;
	boost::optional<EVirYesNo > m_discard;
	boost::optional<QList<Sibling > > m_distances;
	QList<Cache > m_cacheList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Latency

namespace Domain
{
namespace Xml
{
struct Latency
{
	Latency();

	PUnsignedInt::value_type getInitiator() const
	{
		return m_initiator;
	}
	void setInitiator(PUnsignedInt::value_type value_)
	{
		m_initiator = value_;
	}
	PUnsignedInt::value_type getTarget() const
	{
		return m_target;
	}
	void setTarget(PUnsignedInt::value_type value_)
	{
		m_target = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getCache() const
	{
		return m_cache;
	}
	void setCache(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_cache = value_;
	}
	EType1 getType() const
	{
		return m_type;
	}
	void setType(EType1 value_)
	{
		m_type = value_;
	}
	PUnsignedInt::value_type getValue() const
	{
		return m_value;
	}
	void setValue(PUnsignedInt::value_type value_)
	{
		m_value = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_initiator;
	PUnsignedInt::value_type m_target;
	boost::optional<PUnsignedInt::value_type > m_cache;
	EType1 m_type;
	PUnsignedInt::value_type m_value;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Bandwidth

namespace Domain
{
namespace Xml
{
struct Bandwidth
{
	Bandwidth();

	PUnsignedInt::value_type getInitiator() const
	{
		return m_initiator;
	}
	void setInitiator(PUnsignedInt::value_type value_)
	{
		m_initiator = value_;
	}
	PUnsignedInt::value_type getTarget() const
	{
		return m_target;
	}
	void setTarget(PUnsignedInt::value_type value_)
	{
		m_target = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getCache() const
	{
		return m_cache;
	}
	void setCache(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_cache = value_;
	}
	EType2 getType() const
	{
		return m_type;
	}
	void setType(EType2 value_)
	{
		m_type = value_;
	}
	PUnsignedInt::value_type getValue() const
	{
		return m_value;
	}
	void setValue(PUnsignedInt::value_type value_)
	{
		m_value = value_;
	}
	const PUnit::value_type& getUnit() const
	{
		return m_unit;
	}
	void setUnit(const PUnit::value_type& value_)
	{
		m_unit = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_initiator;
	PUnsignedInt::value_type m_target;
	boost::optional<PUnsignedInt::value_type > m_cache;
	EType2 m_type;
	PUnsignedInt::value_type m_value;
	PUnit::value_type m_unit;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Interconnects

namespace Domain
{
namespace Xml
{
struct Interconnects
{
	const QList<Latency >& getLatencyList() const
	{
		return m_latencyList;
	}
	void setLatencyList(const QList<Latency >& value_)
	{
		m_latencyList = value_;
	}
	const QList<Bandwidth >& getBandwidthList() const
	{
		return m_bandwidthList;
	}
	void setBandwidthList(const QList<Bandwidth >& value_)
	{
		m_bandwidthList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	QList<Latency > m_latencyList;
	QList<Bandwidth > m_bandwidthList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Numa

namespace Domain
{
namespace Xml
{
struct Numa
{
	const QList<Cell >& getCellList() const
	{
		return m_cellList;
	}
	void setCellList(const QList<Cell >& value_)
	{
		m_cellList = value_;
	}
	const boost::optional<Interconnects >& getInterconnects() const
	{
		return m_interconnects;
	}
	void setInterconnects(const boost::optional<Interconnects >& value_)
	{
		m_interconnects = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	QList<Cell > m_cellList;
	boost::optional<Interconnects > m_interconnects;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Cache1

namespace Domain
{
namespace Xml
{
struct Cache1
{
	Cache1();

	const boost::optional<ELevel >& getLevel() const
	{
		return m_level;
	}
	void setLevel(const boost::optional<ELevel >& value_)
	{
		m_level = value_;
	}
	EMode1 getMode() const
	{
		return m_mode;
	}
	void setMode(EMode1 value_)
	{
		m_mode = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<ELevel > m_level;
	EMode1 m_mode;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Cpu

namespace Domain
{
namespace Xml
{
struct Cpu
{
	const boost::optional<EMode >& getMode() const
	{
		return m_mode;
	}
	void setMode(const boost::optional<EMode >& value_)
	{
		m_mode = value_;
	}
	const boost::optional<EMatch >& getMatch() const
	{
		return m_match;
	}
	void setMatch(const boost::optional<EMatch >& value_)
	{
		m_match = value_;
	}
	const boost::optional<ECheck >& getCheck() const
	{
		return m_check;
	}
	void setCheck(const boost::optional<ECheck >& value_)
	{
		m_check = value_;
	}
	const boost::optional<EVirOnOff >& getMigratable() const
	{
		return m_migratable;
	}
	void setMigratable(const boost::optional<EVirOnOff >& value_)
	{
		m_migratable = value_;
	}
	const boost::optional<Model >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<Model >& value_)
	{
		m_model = value_;
	}
	const boost::optional<QString >& getVendor() const
	{
		return m_vendor;
	}
	void setVendor(const boost::optional<QString >& value_)
	{
		m_vendor = value_;
	}
	const boost::optional<Topology >& getTopology() const
	{
		return m_topology;
	}
	void setTopology(const boost::optional<Topology >& value_)
	{
		m_topology = value_;
	}
	const QList<Feature >& getFeatureList() const
	{
		return m_featureList;
	}
	void setFeatureList(const QList<Feature >& value_)
	{
		m_featureList = value_;
	}
	const boost::optional<Numa >& getNuma() const
	{
		return m_numa;
	}
	void setNuma(const boost::optional<Numa >& value_)
	{
		m_numa = value_;
	}
	const boost::optional<Cache1 >& getCache() const
	{
		return m_cache;
	}
	void setCache(const boost::optional<Cache1 >& value_)
	{
		m_cache = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EMode > m_mode;
	boost::optional<EMatch > m_match;
	boost::optional<ECheck > m_check;
	boost::optional<EVirOnOff > m_migratable;
	boost::optional<Model > m_model;
	boost::optional<QString > m_vendor;
	boost::optional<Topology > m_topology;
	QList<Feature > m_featureList;
	boost::optional<Numa > m_numa;
	boost::optional<Cache1 > m_cache;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Entry

namespace Domain
{
namespace Xml
{
struct Entry
{
	Entry();

	ESysinfoBiosName getName() const
	{
		return m_name;
	}
	void setName(ESysinfoBiosName value_)
	{
		m_name = value_;
	}
	const PSysinfoValue::value_type& getOwnValue() const
	{
		return m_ownValue;
	}
	void setOwnValue(const PSysinfoValue::value_type& value_)
	{
		m_ownValue = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	ESysinfoBiosName m_name;
	PSysinfoValue::value_type m_ownValue;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Entry1

namespace Domain
{
namespace Xml
{
struct Entry1
{
	Entry1();

	ESysinfoSystemName getName() const
	{
		return m_name;
	}
	void setName(ESysinfoSystemName value_)
	{
		m_name = value_;
	}
	const PSysinfoValue::value_type& getOwnValue() const
	{
		return m_ownValue;
	}
	void setOwnValue(const PSysinfoValue::value_type& value_)
	{
		m_ownValue = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	ESysinfoSystemName m_name;
	PSysinfoValue::value_type m_ownValue;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Entry2

namespace Domain
{
namespace Xml
{
struct Entry2
{
	Entry2();

	ESysinfoBaseBoardName getName() const
	{
		return m_name;
	}
	void setName(ESysinfoBaseBoardName value_)
	{
		m_name = value_;
	}
	const PSysinfoValue::value_type& getOwnValue() const
	{
		return m_ownValue;
	}
	void setOwnValue(const PSysinfoValue::value_type& value_)
	{
		m_ownValue = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	ESysinfoBaseBoardName m_name;
	PSysinfoValue::value_type m_ownValue;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Entry3

namespace Domain
{
namespace Xml
{
struct Entry3
{
	Entry3();

	ESysinfoChassisName getName() const
	{
		return m_name;
	}
	void setName(ESysinfoChassisName value_)
	{
		m_name = value_;
	}
	const PSysinfoValue::value_type& getOwnValue() const
	{
		return m_ownValue;
	}
	void setOwnValue(const PSysinfoValue::value_type& value_)
	{
		m_ownValue = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	ESysinfoChassisName m_name;
	PSysinfoValue::value_type m_ownValue;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Sysinfo

namespace Domain
{
namespace Xml
{
struct Sysinfo
{
	const boost::optional<QList<Entry > >& getBios() const
	{
		return m_bios;
	}
	void setBios(const boost::optional<QList<Entry > >& value_)
	{
		m_bios = value_;
	}
	const boost::optional<QList<Entry1 > >& getSystem() const
	{
		return m_system;
	}
	void setSystem(const boost::optional<QList<Entry1 > >& value_)
	{
		m_system = value_;
	}
	const QList<QList<Entry2 > >& getBaseBoardList() const
	{
		return m_baseBoardList;
	}
	void setBaseBoardList(const QList<QList<Entry2 > >& value_)
	{
		m_baseBoardList = value_;
	}
	const boost::optional<QList<Entry3 > >& getChassis() const
	{
		return m_chassis;
	}
	void setChassis(const boost::optional<QList<Entry3 > >& value_)
	{
		m_chassis = value_;
	}
	const boost::optional<QList<PSysinfoValue::value_type > >& getOemStrings() const
	{
		return m_oemStrings;
	}
	void setOemStrings(const boost::optional<QList<PSysinfoValue::value_type > >& value_)
	{
		m_oemStrings = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<QList<Entry > > m_bios;
	boost::optional<QList<Entry1 > > m_system;
	QList<QList<Entry2 > > m_baseBoardList;
	boost::optional<QList<Entry3 > > m_chassis;
	boost::optional<QList<PSysinfoValue::value_type > > m_oemStrings;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Bootloader

namespace Domain
{
namespace Xml
{
struct Bootloader
{
	const boost::optional<QString >& getBootloader() const
	{
		return m_bootloader;
	}
	void setBootloader(const boost::optional<QString >& value_)
	{
		m_bootloader = value_;
	}
	const boost::optional<QString >& getBootloaderArgs() const
	{
		return m_bootloaderArgs;
	}
	void setBootloaderArgs(const boost::optional<QString >& value_)
	{
		m_bootloaderArgs = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	boost::optional<QString > m_bootloader;
	boost::optional<QString > m_bootloaderArgs;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Type

namespace Domain
{
namespace Xml
{
struct Type
{
	Type();

	const boost::optional<EArch >& getArch() const
	{
		return m_arch;
	}
	void setArch(const boost::optional<EArch >& value_)
	{
		m_arch = value_;
	}
	const boost::optional<EMachine >& getMachine() const
	{
		return m_machine;
	}
	void setMachine(const boost::optional<EMachine >& value_)
	{
		m_machine = value_;
	}
	EType3 getType() const
	{
		return m_type;
	}
	void setType(EType3 value_)
	{
		m_type = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EArch > m_arch;
	boost::optional<EMachine > m_machine;
	EType3 m_type;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Osbootkernel

namespace Domain
{
namespace Xml
{
struct Osbootkernel
{
	const boost::optional<PAbsFilePath::value_type >& getKernel() const
	{
		return m_kernel;
	}
	void setKernel(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_kernel = value_;
	}
	const boost::optional<PAbsFilePath::value_type >& getInitrd() const
	{
		return m_initrd;
	}
	void setInitrd(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_initrd = value_;
	}
	const boost::optional<PAbsFilePath::value_type >& getRoot() const
	{
		return m_root;
	}
	void setRoot(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_root = value_;
	}
	const boost::optional<QString >& getCmdline() const
	{
		return m_cmdline;
	}
	void setCmdline(const boost::optional<QString >& value_)
	{
		m_cmdline = value_;
	}
	const boost::optional<PAbsFilePath::value_type >& getDtb() const
	{
		return m_dtb;
	}
	void setDtb(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_dtb = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	boost::optional<PAbsFilePath::value_type > m_kernel;
	boost::optional<PAbsFilePath::value_type > m_initrd;
	boost::optional<PAbsFilePath::value_type > m_root;
	boost::optional<QString > m_cmdline;
	boost::optional<PAbsFilePath::value_type > m_dtb;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Os

namespace Domain
{
namespace Xml
{
struct Os
{
	const Type& getType() const
	{
		return m_type;
	}
	void setType(const Type& value_)
	{
		m_type = value_;
	}
	const Osbootkernel& getOsbootkernel() const
	{
		return m_osbootkernel;
	}
	void setOsbootkernel(const Osbootkernel& value_)
	{
		m_osbootkernel = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	Type m_type;
	Osbootkernel m_osbootkernel;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Osxen6979

namespace Domain
{
namespace Xml
{
struct Osxen6979
{
	const boost::optional<Bootloader >& getBootloader() const
	{
		return m_bootloader;
	}
	void setBootloader(const boost::optional<Bootloader >& value_)
	{
		m_bootloader = value_;
	}
	const Os& getOs() const
	{
		return m_os;
	}
	void setOs(const Os& value_)
	{
		m_os = value_;
	}

private:
	boost::optional<Bootloader > m_bootloader;
	Os m_os;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Os1

namespace Domain
{
namespace Xml
{
struct Os1
{
	const Type& getType() const
	{
		return m_type;
	}
	void setType(const Type& value_)
	{
		m_type = value_;
	}
	const boost::optional<Osbootkernel >& getOsbootkernel() const
	{
		return m_osbootkernel;
	}
	void setOsbootkernel(const boost::optional<Osbootkernel >& value_)
	{
		m_osbootkernel = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	Type m_type;
	boost::optional<Osbootkernel > m_osbootkernel;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Osxen6980

namespace Domain
{
namespace Xml
{
struct Osxen6980
{
	const Bootloader& getBootloader() const
	{
		return m_bootloader;
	}
	void setBootloader(const Bootloader& value_)
	{
		m_bootloader = value_;
	}
	const boost::optional<Os1 >& getOs() const
	{
		return m_os;
	}
	void setOs(const boost::optional<Os1 >& value_)
	{
		m_os = value_;
	}

private:
	Bootloader m_bootloader;
	boost::optional<Os1 > m_os;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VOsxen

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Osxen6979, Osxen6980 > > VOsxenImpl;
typedef VOsxenImpl::value_type VOsxen;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hvmx86

namespace Domain
{
namespace Xml
{
struct Hvmx86
{
	const boost::optional<EArch1 >& getArch() const
	{
		return m_arch;
	}
	void setArch(const boost::optional<EArch1 >& value_)
	{
		m_arch = value_;
	}
	const boost::optional<PMachine::value_type >& getMachine() const
	{
		return m_machine;
	}
	void setMachine(const boost::optional<PMachine::value_type >& value_)
	{
		m_machine = value_;
	}

private:
	boost::optional<EArch1 > m_arch;
	boost::optional<PMachine::value_type > m_machine;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hvmmips

namespace Domain
{
namespace Xml
{
struct Hvmmips
{
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hvmsparc

namespace Domain
{
namespace Xml
{
struct Hvmsparc
{
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hvms390

namespace Domain
{
namespace Xml
{
struct Hvms390
{
	const boost::optional<EArch2 >& getArch() const
	{
		return m_arch;
	}
	void setArch(const boost::optional<EArch2 >& value_)
	{
		m_arch = value_;
	}
	const boost::optional<EMachine3 >& getMachine() const
	{
		return m_machine;
	}
	void setMachine(const boost::optional<EMachine3 >& value_)
	{
		m_machine = value_;
	}

private:
	boost::optional<EArch2 > m_arch;
	boost::optional<EMachine3 > m_machine;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hvmarm

namespace Domain
{
namespace Xml
{
struct Hvmarm
{
	const boost::optional<EArch3 >& getArch() const
	{
		return m_arch;
	}
	void setArch(const boost::optional<EArch3 >& value_)
	{
		m_arch = value_;
	}
	const boost::optional<PMachine::value_type >& getMachine() const
	{
		return m_machine;
	}
	void setMachine(const boost::optional<PMachine::value_type >& value_)
	{
		m_machine = value_;
	}

private:
	boost::optional<EArch3 > m_arch;
	boost::optional<PMachine::value_type > m_machine;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hvmaarch64

namespace Domain
{
namespace Xml
{
struct Hvmaarch64
{
	const boost::optional<EArch4 >& getArch() const
	{
		return m_arch;
	}
	void setArch(const boost::optional<EArch4 >& value_)
	{
		m_arch = value_;
	}
	const boost::optional<PMachine::value_type >& getMachine() const
	{
		return m_machine;
	}
	void setMachine(const boost::optional<PMachine::value_type >& value_)
	{
		m_machine = value_;
	}

private:
	boost::optional<EArch4 > m_arch;
	boost::optional<PMachine::value_type > m_machine;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice5114

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Hvmx86, Hvmmips, Hvmsparc, Ordered<mpl::vector<Optional<Attribute<mpl::int_<89>, Name::Strict<285> > >, Optional<Attribute<Domain::Xml::EMachine1, Name::Strict<286> > > > >, Ordered<mpl::vector<Optional<Attribute<mpl::int_<90>, Name::Strict<285> > >, Optional<Attribute<Domain::Xml::EMachine2, Name::Strict<286> > > > >, Hvms390, Hvmarm, Hvmaarch64 > > VChoice5114Impl;
typedef VChoice5114Impl::value_type VChoice5114;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Loader

namespace Domain
{
namespace Xml
{
struct Loader
{
	const boost::optional<EReadonly >& getReadonly() const
	{
		return m_readonly;
	}
	void setReadonly(const boost::optional<EReadonly >& value_)
	{
		m_readonly = value_;
	}
	const boost::optional<ESecure >& getSecure() const
	{
		return m_secure;
	}
	void setSecure(const boost::optional<ESecure >& value_)
	{
		m_secure = value_;
	}
	const boost::optional<EType4 >& getType() const
	{
		return m_type;
	}
	void setType(const boost::optional<EType4 >& value_)
	{
		m_type = value_;
	}
	const boost::optional<PAbsFilePath::value_type >& getOwnValue() const
	{
		return m_ownValue;
	}
	void setOwnValue(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_ownValue = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EReadonly > m_readonly;
	boost::optional<ESecure > m_secure;
	boost::optional<EType4 > m_type;
	boost::optional<PAbsFilePath::value_type > m_ownValue;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6973

namespace Domain
{
namespace Xml
{
struct Seclabel6973
{
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6974

namespace Domain
{
namespace Xml
{
struct Seclabel6974
{
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VSeclabel

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Seclabel6973, Seclabel6974, Ordered<mpl::vector<Optional<Attribute<mpl::int_<135>, Name::Strict<233> > >, OneOrMore<Element<Text<QString >, Name::Strict<234> > > > > > > VSeclabelImpl;
typedef VSeclabelImpl::value_type VSeclabel;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel

namespace Domain
{
namespace Xml
{
struct Seclabel
{
	const boost::optional<QString >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<QString >& value_)
	{
		m_model = value_;
	}
	const VSeclabel& getSeclabel() const
	{
		return m_seclabel;
	}
	void setSeclabel(const VSeclabel& value_)
	{
		m_seclabel = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<QString > m_model;
	VSeclabel m_seclabel;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source

namespace Domain
{
namespace Xml
{
struct Source
{
	const boost::optional<PAbsFilePath::value_type >& getDev() const
	{
		return m_dev;
	}
	void setDev(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_dev = value_;
	}
	const boost::optional<EStartupPolicy >& getStartupPolicy() const
	{
		return m_startupPolicy;
	}
	void setStartupPolicy(const boost::optional<EStartupPolicy >& value_)
	{
		m_startupPolicy = value_;
	}
	const QList<Seclabel >& getSeclabelList() const
	{
		return m_seclabelList;
	}
	void setSeclabelList(const QList<Seclabel >& value_)
	{
		m_seclabelList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PAbsFilePath::value_type > m_dev;
	boost::optional<EStartupPolicy > m_startupPolicy;
	QList<Seclabel > m_seclabelList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VSecret

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Attribute<Domain::Xml::VUUID, Name::Strict<151> >, Attribute<QString, Name::Strict<640> > > > VSecretImpl;
typedef VSecretImpl::value_type VSecret;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous7117

namespace Domain
{
namespace Xml
{
struct Anonymous7117
{
	const QString& getMode() const
	{
		return m_mode;
	}
	void setMode(const QString& value_)
	{
		m_mode = value_;
	}
	const QString& getHash() const
	{
		return m_hash;
	}
	void setHash(const QString& value_)
	{
		m_hash = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	QString m_mode;
	QString m_hash;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Keycipher

namespace Domain
{
namespace Xml
{
struct Keycipher
{
	Keycipher();

	const QString& getName() const
	{
		return m_name;
	}
	void setName(const QString& value_)
	{
		m_name = value_;
	}
	PUnsignedInt::value_type getSize() const
	{
		return m_size;
	}
	void setSize(PUnsignedInt::value_type value_)
	{
		m_size = value_;
	}
	const boost::optional<Anonymous7117 >& getAnonymous7117() const
	{
		return m_anonymous7117;
	}
	void setAnonymous7117(const boost::optional<Anonymous7117 >& value_)
	{
		m_anonymous7117 = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	QString m_name;
	PUnsignedInt::value_type m_size;
	boost::optional<Anonymous7117 > m_anonymous7117;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Keyivgen

namespace Domain
{
namespace Xml
{
struct Keyivgen
{
	const QString& getName() const
	{
		return m_name;
	}
	void setName(const QString& value_)
	{
		m_name = value_;
	}
	const boost::optional<QString >& getHash() const
	{
		return m_hash;
	}
	void setHash(const boost::optional<QString >& value_)
	{
		m_hash = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	QString m_name;
	boost::optional<QString > m_hash;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous7118

namespace Domain
{
namespace Xml
{
struct Anonymous7118
{
	const Keycipher& getCipher() const
	{
		return m_cipher;
	}
	void setCipher(const Keycipher& value_)
	{
		m_cipher = value_;
	}
	const Keyivgen& getIvgen() const
	{
		return m_ivgen;
	}
	void setIvgen(const Keyivgen& value_)
	{
		m_ivgen = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	Keycipher m_cipher;
	Keyivgen m_ivgen;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Encryption

namespace Domain
{
namespace Xml
{
struct Encryption
{
	Encryption();

	EFormat getFormat() const
	{
		return m_format;
	}
	void setFormat(EFormat value_)
	{
		m_format = value_;
	}
	const VSecret& getSecret() const
	{
		return m_secret;
	}
	void setSecret(const VSecret& value_)
	{
		m_secret = value_;
	}
	const boost::optional<Anonymous7118 >& getAnonymous7118() const
	{
		return m_anonymous7118;
	}
	void setAnonymous7118(const boost::optional<Anonymous7118 >& value_)
	{
		m_anonymous7118 = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EFormat m_format;
	VSecret m_secret;
	boost::optional<Anonymous7118 > m_anonymous7118;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source1

namespace Domain
{
namespace Xml
{
struct Source1
{
	const PAbsFilePath::value_type& getDir() const
	{
		return m_dir;
	}
	void setDir(const PAbsFilePath::value_type& value_)
	{
		m_dir = value_;
	}
	const boost::optional<EStartupPolicy >& getStartupPolicy() const
	{
		return m_startupPolicy;
	}
	void setStartupPolicy(const boost::optional<EStartupPolicy >& value_)
	{
		m_startupPolicy = value_;
	}
	const boost::optional<Encryption >& getEncryption() const
	{
		return m_encryption;
	}
	void setEncryption(const boost::optional<Encryption >& value_)
	{
		m_encryption = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PAbsFilePath::value_type m_dir;
	boost::optional<EStartupPolicy > m_startupPolicy;
	boost::optional<Encryption > m_encryption;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Host7010

namespace Domain
{
namespace Xml
{
struct Host7010
{
	const boost::optional<ETransport >& getTransport() const
	{
		return m_transport;
	}
	void setTransport(const boost::optional<ETransport >& value_)
	{
		m_transport = value_;
	}
	const VName& getName() const
	{
		return m_name;
	}
	void setName(const VName& value_)
	{
		m_name = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_port = value_;
	}

private:
	boost::optional<ETransport > m_transport;
	VName m_name;
	boost::optional<PUnsignedInt::value_type > m_port;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VHost

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Host7010, Ordered<mpl::vector<Attribute<mpl::int_<520>, Name::Strict<514> >, Attribute<Domain::Xml::PAbsFilePath, Name::Strict<521> > > > > > VHostImpl;
typedef VHostImpl::value_type VHost;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source2

namespace Domain
{
namespace Xml
{
struct Source2
{
	Source2();

	EProtocol getProtocol() const
	{
		return m_protocol;
	}
	void setProtocol(EProtocol value_)
	{
		m_protocol = value_;
	}
	const boost::optional<QString >& getName() const
	{
		return m_name;
	}
	void setName(const boost::optional<QString >& value_)
	{
		m_name = value_;
	}
	const QList<VHost >& getHostList() const
	{
		return m_hostList;
	}
	void setHostList(const QList<VHost >& value_)
	{
		m_hostList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EProtocol m_protocol;
	boost::optional<QString > m_name;
	QList<VHost > m_hostList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source3

namespace Domain
{
namespace Xml
{
struct Source3
{
	const PGenericName::value_type& getPool() const
	{
		return m_pool;
	}
	void setPool(const PGenericName::value_type& value_)
	{
		m_pool = value_;
	}
	const PVolName::value_type& getVolume() const
	{
		return m_volume;
	}
	void setVolume(const PVolName::value_type& value_)
	{
		m_volume = value_;
	}
	const boost::optional<EMode2 >& getMode() const
	{
		return m_mode;
	}
	void setMode(const boost::optional<EMode2 >& value_)
	{
		m_mode = value_;
	}
	const boost::optional<EStartupPolicy >& getStartupPolicy() const
	{
		return m_startupPolicy;
	}
	void setStartupPolicy(const boost::optional<EStartupPolicy >& value_)
	{
		m_startupPolicy = value_;
	}
	const boost::optional<Encryption >& getEncryption() const
	{
		return m_encryption;
	}
	void setEncryption(const boost::optional<Encryption >& value_)
	{
		m_encryption = value_;
	}
	const QList<Seclabel >& getSeclabelList() const
	{
		return m_seclabelList;
	}
	void setSeclabelList(const QList<Seclabel >& value_)
	{
		m_seclabelList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PGenericName::value_type m_pool;
	PVolName::value_type m_volume;
	boost::optional<EMode2 > m_mode;
	boost::optional<EStartupPolicy > m_startupPolicy;
	boost::optional<Encryption > m_encryption;
	QList<Seclabel > m_seclabelList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source4

namespace Domain
{
namespace Xml
{
struct Source4
{
	const boost::optional<PAbsFilePath::value_type >& getFile() const
	{
		return m_file;
	}
	void setFile(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_file = value_;
	}
	const boost::optional<EStartupPolicy >& getStartupPolicy() const
	{
		return m_startupPolicy;
	}
	void setStartupPolicy(const boost::optional<EStartupPolicy >& value_)
	{
		m_startupPolicy = value_;
	}
	const QList<Seclabel >& getSeclabelList() const
	{
		return m_seclabelList;
	}
	void setSeclabelList(const QList<Seclabel >& value_)
	{
		m_seclabelList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PAbsFilePath::value_type > m_file;
	boost::optional<EStartupPolicy > m_startupPolicy;
	QList<Seclabel > m_seclabelList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VDiskSource

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Ordered<mpl::vector<Attribute<mpl::int_<502>, Name::Strict<105> >, Optional<Element<Domain::Xml::Source, Name::Strict<501> > > > >, Ordered<mpl::vector<Attribute<mpl::int_<164>, Name::Strict<105> >, Optional<Element<Domain::Xml::Source1, Name::Strict<501> > > > >, Ordered<mpl::vector<Attribute<mpl::int_<445>, Name::Strict<105> >, Element<Domain::Xml::Source2, Name::Strict<501> > > >, Ordered<mpl::vector<Attribute<mpl::int_<523>, Name::Strict<105> >, Optional<Element<Domain::Xml::Source3, Name::Strict<501> > > > >, Ordered<mpl::vector<Optional<Attribute<mpl::int_<500>, Name::Strict<105> > >, Optional<Element<Domain::Xml::Source4, Name::Strict<501> > > > > > > VDiskSourceImpl;
typedef VDiskSourceImpl::value_type VDiskSource;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Nvram

namespace Domain
{
namespace Xml
{
struct Nvram
{
	const boost::optional<PAbsFilePath::value_type >& getTemplate() const
	{
		return m_template;
	}
	void setTemplate(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_template = value_;
	}
	const boost::optional<VDiskSource >& getDiskSource() const
	{
		return m_diskSource;
	}
	void setDiskSource(const boost::optional<VDiskSource >& value_)
	{
		m_diskSource = value_;
	}
	const boost::optional<EFormat1 >& getFormat() const
	{
		return m_format;
	}
	void setFormat(const boost::optional<EFormat1 >& value_)
	{
		m_format = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PAbsFilePath::value_type > m_template;
	boost::optional<VDiskSource > m_diskSource;
	boost::optional<EFormat1 > m_format;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Bootmenu

namespace Domain
{
namespace Xml
{
struct Bootmenu
{
	Bootmenu();

	EVirYesNo getEnable() const
	{
		return m_enable;
	}
	void setEnable(EVirYesNo value_)
	{
		m_enable = value_;
	}
	const boost::optional<PUnsignedShort::value_type >& getTimeout() const
	{
		return m_timeout;
	}
	void setTimeout(const boost::optional<PUnsignedShort::value_type >& value_)
	{
		m_timeout = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EVirYesNo m_enable;
	boost::optional<PUnsignedShort::value_type > m_timeout;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Bios

namespace Domain
{
namespace Xml
{
struct Bios
{
	const boost::optional<EVirYesNo >& getUseserial() const
	{
		return m_useserial;
	}
	void setUseserial(const boost::optional<EVirYesNo >& value_)
	{
		m_useserial = value_;
	}
	const boost::optional<PRebootTimeoutDelay::value_type >& getRebootTimeout() const
	{
		return m_rebootTimeout;
	}
	void setRebootTimeout(const boost::optional<PRebootTimeoutDelay::value_type >& value_)
	{
		m_rebootTimeout = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirYesNo > m_useserial;
	boost::optional<PRebootTimeoutDelay::value_type > m_rebootTimeout;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Os2

namespace Domain
{
namespace Xml
{
struct Os2
{
	const boost::optional<VChoice5114 >& getType() const
	{
		return m_type;
	}
	void setType(const boost::optional<VChoice5114 >& value_)
	{
		m_type = value_;
	}
	const boost::optional<Loader >& getLoader() const
	{
		return m_loader;
	}
	void setLoader(const boost::optional<Loader >& value_)
	{
		m_loader = value_;
	}
	const boost::optional<Nvram >& getNvram() const
	{
		return m_nvram;
	}
	void setNvram(const boost::optional<Nvram >& value_)
	{
		m_nvram = value_;
	}
	const boost::optional<Osbootkernel >& getOsbootkernel() const
	{
		return m_osbootkernel;
	}
	void setOsbootkernel(const boost::optional<Osbootkernel >& value_)
	{
		m_osbootkernel = value_;
	}
	const QList<EDev >& getBootList() const
	{
		return m_bootList;
	}
	void setBootList(const QList<EDev >& value_)
	{
		m_bootList = value_;
	}
	const boost::optional<Bootmenu >& getBootmenu() const
	{
		return m_bootmenu;
	}
	void setBootmenu(const boost::optional<Bootmenu >& value_)
	{
		m_bootmenu = value_;
	}
	const boost::optional<EMode3 >& getSmbios() const
	{
		return m_smbios;
	}
	void setSmbios(const boost::optional<EMode3 >& value_)
	{
		m_smbios = value_;
	}
	const boost::optional<Bios >& getBios() const
	{
		return m_bios;
	}
	void setBios(const boost::optional<Bios >& value_)
	{
		m_bios = value_;
	}
	const boost::optional<QList<PAbsFilePath::value_type > >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<QList<PAbsFilePath::value_type > >& value_)
	{
		m_acpi = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<VChoice5114 > m_type;
	boost::optional<Loader > m_loader;
	boost::optional<Nvram > m_nvram;
	boost::optional<Osbootkernel > m_osbootkernel;
	QList<EDev > m_bootList;
	boost::optional<Bootmenu > m_bootmenu;
	boost::optional<EMode3 > m_smbios;
	boost::optional<Bios > m_bios;
	boost::optional<QList<PAbsFilePath::value_type > > m_acpi;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Initenv

namespace Domain
{
namespace Xml
{
struct Initenv
{
	const PName::value_type& getName() const
	{
		return m_name;
	}
	void setName(const PName::value_type& value_)
	{
		m_name = value_;
	}
	const QString& getOwnValue() const
	{
		return m_ownValue;
	}
	void setOwnValue(const QString& value_)
	{
		m_ownValue = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PName::value_type m_name;
	QString m_ownValue;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Os3

namespace Domain
{
namespace Xml
{
struct Os3
{
	const boost::optional<EArch5 >& getType() const
	{
		return m_type;
	}
	void setType(const boost::optional<EArch5 >& value_)
	{
		m_type = value_;
	}
	const boost::optional<PAbsFilePath::value_type >& getInit() const
	{
		return m_init;
	}
	void setInit(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_init = value_;
	}
	const QList<QString >& getInitargList() const
	{
		return m_initargList;
	}
	void setInitargList(const QList<QString >& value_)
	{
		m_initargList = value_;
	}
	const QList<Initenv >& getInitenvList() const
	{
		return m_initenvList;
	}
	void setInitenvList(const QList<Initenv >& value_)
	{
		m_initenvList = value_;
	}
	const boost::optional<PAbsFilePath::value_type >& getInitdir() const
	{
		return m_initdir;
	}
	void setInitdir(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_initdir = value_;
	}
	const boost::optional<PGenericName::value_type >& getInituser() const
	{
		return m_inituser;
	}
	void setInituser(const boost::optional<PGenericName::value_type >& value_)
	{
		m_inituser = value_;
	}
	const boost::optional<PGenericName::value_type >& getInitgroup() const
	{
		return m_initgroup;
	}
	void setInitgroup(const boost::optional<PGenericName::value_type >& value_)
	{
		m_initgroup = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EArch5 > m_type;
	boost::optional<PAbsFilePath::value_type > m_init;
	QList<QString > m_initargList;
	QList<Initenv > m_initenvList;
	boost::optional<PAbsFilePath::value_type > m_initdir;
	boost::optional<PGenericName::value_type > m_inituser;
	boost::optional<PGenericName::value_type > m_initgroup;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VOs

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Domain::Xml::VOsxenImpl, Element<Domain::Xml::Os2, Name::Strict<222> >, Element<Domain::Xml::Os3, Name::Strict<222> > > > VOsImpl;
typedef VOsImpl::value_type VOs;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Clock6991

namespace Domain
{
namespace Xml
{
struct Clock6991
{
	Clock6991();

	EOffset getOffset() const
	{
		return m_offset;
	}
	void setOffset(EOffset value_)
	{
		m_offset = value_;
	}
	const boost::optional<VAdjustment >& getAdjustment() const
	{
		return m_adjustment;
	}
	void setAdjustment(const boost::optional<VAdjustment >& value_)
	{
		m_adjustment = value_;
	}

private:
	EOffset m_offset;
	boost::optional<VAdjustment > m_adjustment;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Clock6993

namespace Domain
{
namespace Xml
{
struct Clock6993
{
	const boost::optional<PTimeDelta::value_type >& getAdjustment() const
	{
		return m_adjustment;
	}
	void setAdjustment(const boost::optional<PTimeDelta::value_type >& value_)
	{
		m_adjustment = value_;
	}
	const boost::optional<EBasis >& getBasis() const
	{
		return m_basis;
	}
	void setBasis(const boost::optional<EBasis >& value_)
	{
		m_basis = value_;
	}

private:
	boost::optional<PTimeDelta::value_type > m_adjustment;
	boost::optional<EBasis > m_basis;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VClock

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Clock6991, Ordered<mpl::vector<Attribute<mpl::int_<397>, Name::Strict<389> >, Optional<Attribute<Domain::Xml::PTimeZone, Name::Strict<397> > > > >, Clock6993 > > VClockImpl;
typedef VClockImpl::value_type VClock;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Catchup

namespace Domain
{
namespace Xml
{
struct Catchup
{
	const boost::optional<PUnsignedInt::value_type >& getThreshold() const
	{
		return m_threshold;
	}
	void setThreshold(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_threshold = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getSlew() const
	{
		return m_slew;
	}
	void setSlew(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_slew = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getLimit() const
	{
		return m_limit;
	}
	void setLimit(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_limit = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PUnsignedInt::value_type > m_threshold;
	boost::optional<PUnsignedInt::value_type > m_slew;
	boost::optional<PUnsignedInt::value_type > m_limit;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VTickpolicy

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Attribute<Domain::Xml::ETickpolicy, Name::Strict<410> >, Ordered<mpl::vector<Attribute<mpl::int_<430>, Name::Strict<410> >, Optional<Element<Domain::Xml::Catchup, Name::Strict<430> > > > > > > VTickpolicyImpl;
typedef VTickpolicyImpl::value_type VTickpolicy;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Timer6994

namespace Domain
{
namespace Xml
{
struct Timer6994
{
	Timer6994();

	EName getName() const
	{
		return m_name;
	}
	void setName(EName value_)
	{
		m_name = value_;
	}
	const boost::optional<ETrack >& getTrack() const
	{
		return m_track;
	}
	void setTrack(const boost::optional<ETrack >& value_)
	{
		m_track = value_;
	}
	const boost::optional<VTickpolicy >& getTickpolicy() const
	{
		return m_tickpolicy;
	}
	void setTickpolicy(const boost::optional<VTickpolicy >& value_)
	{
		m_tickpolicy = value_;
	}

private:
	EName m_name;
	boost::optional<ETrack > m_track;
	boost::optional<VTickpolicy > m_tickpolicy;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Timer6995

namespace Domain
{
namespace Xml
{
struct Timer6995
{
	const boost::optional<VTickpolicy >& getTickpolicy() const
	{
		return m_tickpolicy;
	}
	void setTickpolicy(const boost::optional<VTickpolicy >& value_)
	{
		m_tickpolicy = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getFrequency() const
	{
		return m_frequency;
	}
	void setFrequency(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_frequency = value_;
	}
	const boost::optional<EMode4 >& getMode() const
	{
		return m_mode;
	}
	void setMode(const boost::optional<EMode4 >& value_)
	{
		m_mode = value_;
	}

private:
	boost::optional<VTickpolicy > m_tickpolicy;
	boost::optional<PUnsignedInt::value_type > m_frequency;
	boost::optional<EMode4 > m_mode;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Timer6996

namespace Domain
{
namespace Xml
{
struct Timer6996
{
	Timer6996();

	EName1 getName() const
	{
		return m_name;
	}
	void setName(EName1 value_)
	{
		m_name = value_;
	}
	const boost::optional<VTickpolicy >& getTickpolicy() const
	{
		return m_tickpolicy;
	}
	void setTickpolicy(const boost::optional<VTickpolicy >& value_)
	{
		m_tickpolicy = value_;
	}

private:
	EName1 m_name;
	boost::optional<VTickpolicy > m_tickpolicy;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VTimer

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Timer6994, Timer6995, Timer6996, Attribute<Domain::Xml::EName2, Name::Strict<107> > > > VTimerImpl;
typedef VTimerImpl::value_type VTimer;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Timer

namespace Domain
{
namespace Xml
{
struct Timer
{
	const VTimer& getTimer() const
	{
		return m_timer;
	}
	void setTimer(const VTimer& value_)
	{
		m_timer = value_;
	}
	const boost::optional<EVirYesNo >& getPresent() const
	{
		return m_present;
	}
	void setPresent(const boost::optional<EVirYesNo >& value_)
	{
		m_present = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VTimer m_timer;
	boost::optional<EVirYesNo > m_present;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Clock

namespace Domain
{
namespace Xml
{
struct Clock
{
	const VClock& getClock() const
	{
		return m_clock;
	}
	void setClock(const VClock& value_)
	{
		m_clock = value_;
	}
	const QList<Timer >& getTimerList() const
	{
		return m_timerList;
	}
	void setTimerList(const QList<Timer >& value_)
	{
		m_timerList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VClock m_clock;
	QList<Timer > m_timerList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct ScaledInteger

namespace Domain
{
namespace Xml
{
struct ScaledInteger
{
	ScaledInteger();

	const boost::optional<PUnit::value_type >& getUnit() const
	{
		return m_unit;
	}
	void setUnit(const boost::optional<PUnit::value_type >& value_)
	{
		m_unit = value_;
	}
	PUnsignedLong::value_type getOwnValue() const
	{
		return m_ownValue;
	}
	void setOwnValue(PUnsignedLong::value_type value_)
	{
		m_ownValue = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PUnit::value_type > m_unit;
	PUnsignedLong::value_type m_ownValue;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Memory

namespace Domain
{
namespace Xml
{
struct Memory
{
	const ScaledInteger& getScaledInteger() const
	{
		return m_scaledInteger;
	}
	void setScaledInteger(const ScaledInteger& value_)
	{
		m_scaledInteger = value_;
	}
	const boost::optional<EVirOnOff >& getDumpCore() const
	{
		return m_dumpCore;
	}
	void setDumpCore(const boost::optional<EVirOnOff >& value_)
	{
		m_dumpCore = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	ScaledInteger m_scaledInteger;
	boost::optional<EVirOnOff > m_dumpCore;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct MaxMemory

namespace Domain
{
namespace Xml
{
struct MaxMemory
{
	MaxMemory();

	const ScaledInteger& getScaledInteger() const
	{
		return m_scaledInteger;
	}
	void setScaledInteger(const ScaledInteger& value_)
	{
		m_scaledInteger = value_;
	}
	PUnsignedInt::value_type getSlots() const
	{
		return m_slots;
	}
	void setSlots(PUnsignedInt::value_type value_)
	{
		m_slots = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	ScaledInteger m_scaledInteger;
	PUnsignedInt::value_type m_slots;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Page

namespace Domain
{
namespace Xml
{
struct Page
{
	Page();

	PUnsignedLong::value_type getSize() const
	{
		return m_size;
	}
	void setSize(PUnsignedLong::value_type value_)
	{
		m_size = value_;
	}
	const boost::optional<PUnit::value_type >& getUnit() const
	{
		return m_unit;
	}
	void setUnit(const boost::optional<PUnit::value_type >& value_)
	{
		m_unit = value_;
	}
	const boost::optional<PCpuset::value_type >& getNodeset() const
	{
		return m_nodeset;
	}
	void setNodeset(const boost::optional<PCpuset::value_type >& value_)
	{
		m_nodeset = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedLong::value_type m_size;
	boost::optional<PUnit::value_type > m_unit;
	boost::optional<PCpuset::value_type > m_nodeset;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct MemoryBacking

namespace Domain
{
namespace Xml
{
struct MemoryBacking
{
	MemoryBacking();

	const boost::optional<QList<Page > >& getHugepages() const
	{
		return m_hugepages;
	}
	void setHugepages(const boost::optional<QList<Page > >& value_)
	{
		m_hugepages = value_;
	}
	bool getNosharepages() const
	{
		return m_nosharepages;
	}
	void setNosharepages(bool value_)
	{
		m_nosharepages = value_;
	}
	bool getLocked() const
	{
		return m_locked;
	}
	void setLocked(bool value_)
	{
		m_locked = value_;
	}
	const boost::optional<EType5 >& getSource() const
	{
		return m_source;
	}
	void setSource(const boost::optional<EType5 >& value_)
	{
		m_source = value_;
	}
	const boost::optional<EMode5 >& getAccess() const
	{
		return m_access;
	}
	void setAccess(const boost::optional<EMode5 >& value_)
	{
		m_access = value_;
	}
	const boost::optional<EMode6 >& getAllocation() const
	{
		return m_allocation;
	}
	void setAllocation(const boost::optional<EMode6 >& value_)
	{
		m_allocation = value_;
	}
	bool getDiscard() const
	{
		return m_discard;
	}
	void setDiscard(bool value_)
	{
		m_discard = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<QList<Page > > m_hugepages;
	bool m_nosharepages;
	bool m_locked;
	boost::optional<EType5 > m_source;
	boost::optional<EMode5 > m_access;
	boost::optional<EMode6 > m_allocation;
	bool m_discard;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Vcpu

namespace Domain
{
namespace Xml
{
struct Vcpu
{
	Vcpu();

	const boost::optional<EPlacement >& getPlacement() const
	{
		return m_placement;
	}
	void setPlacement(const boost::optional<EPlacement >& value_)
	{
		m_placement = value_;
	}
	const boost::optional<PCpuset::value_type >& getCpuset() const
	{
		return m_cpuset;
	}
	void setCpuset(const boost::optional<PCpuset::value_type >& value_)
	{
		m_cpuset = value_;
	}
	const boost::optional<PCountCPU::value_type >& getCurrent() const
	{
		return m_current;
	}
	void setCurrent(const boost::optional<PCountCPU::value_type >& value_)
	{
		m_current = value_;
	}
	PCountCPU::value_type getOwnValue() const
	{
		return m_ownValue;
	}
	void setOwnValue(PCountCPU::value_type value_)
	{
		m_ownValue = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EPlacement > m_placement;
	boost::optional<PCpuset::value_type > m_cpuset;
	boost::optional<PCountCPU::value_type > m_current;
	PCountCPU::value_type m_ownValue;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Vcpu1

namespace Domain
{
namespace Xml
{
struct Vcpu1
{
	Vcpu1();

	PUnsignedInt::value_type getId() const
	{
		return m_id;
	}
	void setId(PUnsignedInt::value_type value_)
	{
		m_id = value_;
	}
	EVirYesNo getEnabled() const
	{
		return m_enabled;
	}
	void setEnabled(EVirYesNo value_)
	{
		m_enabled = value_;
	}
	const boost::optional<EVirYesNo >& getHotpluggable() const
	{
		return m_hotpluggable;
	}
	void setHotpluggable(const boost::optional<EVirYesNo >& value_)
	{
		m_hotpluggable = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getOrder() const
	{
		return m_order;
	}
	void setOrder(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_order = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_id;
	EVirYesNo m_enabled;
	boost::optional<EVirYesNo > m_hotpluggable;
	boost::optional<PUnsignedInt::value_type > m_order;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Device

namespace Domain
{
namespace Xml
{
struct Device
{
	const PAbsFilePath::value_type& getPath() const
	{
		return m_path;
	}
	void setPath(const PAbsFilePath::value_type& value_)
	{
		m_path = value_;
	}
	const boost::optional<PWeight::value_type >& getWeight() const
	{
		return m_weight;
	}
	void setWeight(const boost::optional<PWeight::value_type >& value_)
	{
		m_weight = value_;
	}
	const boost::optional<PReadIopsSec::value_type >& getReadIopsSec() const
	{
		return m_readIopsSec;
	}
	void setReadIopsSec(const boost::optional<PReadIopsSec::value_type >& value_)
	{
		m_readIopsSec = value_;
	}
	const boost::optional<PWriteIopsSec::value_type >& getWriteIopsSec() const
	{
		return m_writeIopsSec;
	}
	void setWriteIopsSec(const boost::optional<PWriteIopsSec::value_type >& value_)
	{
		m_writeIopsSec = value_;
	}
	const boost::optional<PReadBytesSec::value_type >& getReadBytesSec() const
	{
		return m_readBytesSec;
	}
	void setReadBytesSec(const boost::optional<PReadBytesSec::value_type >& value_)
	{
		m_readBytesSec = value_;
	}
	const boost::optional<PWriteBytesSec::value_type >& getWriteBytesSec() const
	{
		return m_writeBytesSec;
	}
	void setWriteBytesSec(const boost::optional<PWriteBytesSec::value_type >& value_)
	{
		m_writeBytesSec = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PAbsFilePath::value_type m_path;
	boost::optional<PWeight::value_type > m_weight;
	boost::optional<PReadIopsSec::value_type > m_readIopsSec;
	boost::optional<PWriteIopsSec::value_type > m_writeIopsSec;
	boost::optional<PReadBytesSec::value_type > m_readBytesSec;
	boost::optional<PWriteBytesSec::value_type > m_writeBytesSec;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Blkiotune

namespace Domain
{
namespace Xml
{
struct Blkiotune
{
	const boost::optional<PWeight::value_type >& getWeight() const
	{
		return m_weight;
	}
	void setWeight(const boost::optional<PWeight::value_type >& value_)
	{
		m_weight = value_;
	}
	const QList<Device >& getDeviceList() const
	{
		return m_deviceList;
	}
	void setDeviceList(const QList<Device >& value_)
	{
		m_deviceList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PWeight::value_type > m_weight;
	QList<Device > m_deviceList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VMinGuarantee

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Attribute<Domain::Xml::EVirYesNo, Name::Strict<5194> >, Attribute<Domain::Xml::PVzRelative, Name::Strict<5682> >, ScaledInteger > > VMinGuaranteeImpl;
typedef VMinGuaranteeImpl::value_type VMinGuarantee;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Memtune

namespace Domain
{
namespace Xml
{
struct Memtune
{
	const boost::optional<ScaledInteger >& getHardLimit() const
	{
		return m_hardLimit;
	}
	void setHardLimit(const boost::optional<ScaledInteger >& value_)
	{
		m_hardLimit = value_;
	}
	const boost::optional<ScaledInteger >& getSoftLimit() const
	{
		return m_softLimit;
	}
	void setSoftLimit(const boost::optional<ScaledInteger >& value_)
	{
		m_softLimit = value_;
	}
	const boost::optional<VMinGuarantee >& getMinGuarantee() const
	{
		return m_minGuarantee;
	}
	void setMinGuarantee(const boost::optional<VMinGuarantee >& value_)
	{
		m_minGuarantee = value_;
	}
	const boost::optional<ScaledInteger >& getSwapHardLimit() const
	{
		return m_swapHardLimit;
	}
	void setSwapHardLimit(const boost::optional<ScaledInteger >& value_)
	{
		m_swapHardLimit = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<ScaledInteger > m_hardLimit;
	boost::optional<ScaledInteger > m_softLimit;
	boost::optional<VMinGuarantee > m_minGuarantee;
	boost::optional<ScaledInteger > m_swapHardLimit;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Vcpupin

namespace Domain
{
namespace Xml
{
struct Vcpupin
{
	Vcpupin();

	PVcpuid::value_type getVcpu() const
	{
		return m_vcpu;
	}
	void setVcpu(PVcpuid::value_type value_)
	{
		m_vcpu = value_;
	}
	const PCpuset::value_type& getCpuset() const
	{
		return m_cpuset;
	}
	void setCpuset(const PCpuset::value_type& value_)
	{
		m_cpuset = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PVcpuid::value_type m_vcpu;
	PCpuset::value_type m_cpuset;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Iothreadpin

namespace Domain
{
namespace Xml
{
struct Iothreadpin
{
	Iothreadpin();

	PUnsignedInt::value_type getIothread() const
	{
		return m_iothread;
	}
	void setIothread(PUnsignedInt::value_type value_)
	{
		m_iothread = value_;
	}
	const PCpuset::value_type& getCpuset() const
	{
		return m_cpuset;
	}
	void setCpuset(const PCpuset::value_type& value_)
	{
		m_cpuset = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_iothread;
	PCpuset::value_type m_cpuset;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Schedparam9370

namespace Domain
{
namespace Xml
{
struct Schedparam9370
{
	Schedparam9370();

	EScheduler1 getScheduler() const
	{
		return m_scheduler;
	}
	void setScheduler(EScheduler1 value_)
	{
		m_scheduler = value_;
	}
	PUnsignedShort::value_type getPriority() const
	{
		return m_priority;
	}
	void setPriority(PUnsignedShort::value_type value_)
	{
		m_priority = value_;
	}

private:
	EScheduler1 m_scheduler;
	PUnsignedShort::value_type m_priority;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VSchedparam

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Attribute<Domain::Xml::EScheduler, Name::Strict<9365> >, Schedparam9370 > > VSchedparamImpl;
typedef VSchedparamImpl::value_type VSchedparam;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Vcpusched

namespace Domain
{
namespace Xml
{
struct Vcpusched
{
	const boost::optional<PCpuset::value_type >& getVcpus() const
	{
		return m_vcpus;
	}
	void setVcpus(const boost::optional<PCpuset::value_type >& value_)
	{
		m_vcpus = value_;
	}
	const VSchedparam& getSchedparam() const
	{
		return m_schedparam;
	}
	void setSchedparam(const VSchedparam& value_)
	{
		m_schedparam = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PCpuset::value_type > m_vcpus;
	VSchedparam m_schedparam;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Iothreadsched

namespace Domain
{
namespace Xml
{
struct Iothreadsched
{
	const boost::optional<PCpuset::value_type >& getIothreads() const
	{
		return m_iothreads;
	}
	void setIothreads(const boost::optional<PCpuset::value_type >& value_)
	{
		m_iothreads = value_;
	}
	const VSchedparam& getSchedparam() const
	{
		return m_schedparam;
	}
	void setSchedparam(const VSchedparam& value_)
	{
		m_schedparam = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PCpuset::value_type > m_iothreads;
	VSchedparam m_schedparam;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Cache2

namespace Domain
{
namespace Xml
{
struct Cache2
{
	Cache2();

	PUnsignedInt::value_type getId() const
	{
		return m_id;
	}
	void setId(PUnsignedInt::value_type value_)
	{
		m_id = value_;
	}
	PUnsignedInt::value_type getLevel() const
	{
		return m_level;
	}
	void setLevel(PUnsignedInt::value_type value_)
	{
		m_level = value_;
	}
	EType6 getType() const
	{
		return m_type;
	}
	void setType(EType6 value_)
	{
		m_type = value_;
	}
	PUnsignedLong::value_type getSize() const
	{
		return m_size;
	}
	void setSize(PUnsignedLong::value_type value_)
	{
		m_size = value_;
	}
	const boost::optional<PUnit::value_type >& getUnit() const
	{
		return m_unit;
	}
	void setUnit(const boost::optional<PUnit::value_type >& value_)
	{
		m_unit = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_id;
	PUnsignedInt::value_type m_level;
	EType6 m_type;
	PUnsignedLong::value_type m_size;
	boost::optional<PUnit::value_type > m_unit;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Monitor

namespace Domain
{
namespace Xml
{
struct Monitor
{
	Monitor();

	PUnsignedInt::value_type getLevel() const
	{
		return m_level;
	}
	void setLevel(PUnsignedInt::value_type value_)
	{
		m_level = value_;
	}
	const PCpuset::value_type& getVcpus() const
	{
		return m_vcpus;
	}
	void setVcpus(const PCpuset::value_type& value_)
	{
		m_vcpus = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_level;
	PCpuset::value_type m_vcpus;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice5117

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Element<Domain::Xml::Cache2, Name::Strict<558> >, Element<Domain::Xml::Monitor, Name::Strict<9363> > > > VChoice5117Impl;
typedef VChoice5117Impl::value_type VChoice5117;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Cachetune

namespace Domain
{
namespace Xml
{
struct Cachetune
{
	const PCpuset::value_type& getVcpus() const
	{
		return m_vcpus;
	}
	void setVcpus(const PCpuset::value_type& value_)
	{
		m_vcpus = value_;
	}
	const boost::optional<PId1::value_type >& getId() const
	{
		return m_id;
	}
	void setId(const boost::optional<PId1::value_type >& value_)
	{
		m_id = value_;
	}
	const QList<VChoice5117 >& getChoice5117List() const
	{
		return m_choice5117List;
	}
	void setChoice5117List(const QList<VChoice5117 >& value_)
	{
		m_choice5117List = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PCpuset::value_type m_vcpus;
	boost::optional<PId1::value_type > m_id;
	QList<VChoice5117 > m_choice5117List;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Node

namespace Domain
{
namespace Xml
{
struct Node
{
	Node();

	PUnsignedInt::value_type getId() const
	{
		return m_id;
	}
	void setId(PUnsignedInt::value_type value_)
	{
		m_id = value_;
	}
	PUnsignedInt::value_type getBandwidth() const
	{
		return m_bandwidth;
	}
	void setBandwidth(PUnsignedInt::value_type value_)
	{
		m_bandwidth = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_id;
	PUnsignedInt::value_type m_bandwidth;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice5120

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Element<Domain::Xml::Node, Name::Strict<609> >, Element<Attribute<Domain::Xml::PCpuset, Name::Strict<343> >, Name::Strict<9363> > > > VChoice5120Impl;
typedef VChoice5120Impl::value_type VChoice5120;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Memorytune

namespace Domain
{
namespace Xml
{
struct Memorytune
{
	const PCpuset::value_type& getVcpus() const
	{
		return m_vcpus;
	}
	void setVcpus(const PCpuset::value_type& value_)
	{
		m_vcpus = value_;
	}
	const QList<VChoice5120 >& getChoice5120List() const
	{
		return m_choice5120List;
	}
	void setChoice5120List(const QList<VChoice5120 >& value_)
	{
		m_choice5120List = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PCpuset::value_type m_vcpus;
	QList<VChoice5120 > m_choice5120List;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Cputune

namespace Domain
{
namespace Xml
{
struct Cputune
{
	const boost::optional<PCpushares::value_type >& getShares() const
	{
		return m_shares;
	}
	void setShares(const boost::optional<PCpushares::value_type >& value_)
	{
		m_shares = value_;
	}
	const boost::optional<PCpuperiod::value_type >& getGlobalPeriod() const
	{
		return m_globalPeriod;
	}
	void setGlobalPeriod(const boost::optional<PCpuperiod::value_type >& value_)
	{
		m_globalPeriod = value_;
	}
	const boost::optional<PCpuquota::value_type >& getGlobalQuota() const
	{
		return m_globalQuota;
	}
	void setGlobalQuota(const boost::optional<PCpuquota::value_type >& value_)
	{
		m_globalQuota = value_;
	}
	const boost::optional<PCpuperiod::value_type >& getPeriod() const
	{
		return m_period;
	}
	void setPeriod(const boost::optional<PCpuperiod::value_type >& value_)
	{
		m_period = value_;
	}
	const boost::optional<PCpuquota::value_type >& getQuota() const
	{
		return m_quota;
	}
	void setQuota(const boost::optional<PCpuquota::value_type >& value_)
	{
		m_quota = value_;
	}
	const boost::optional<PCpuperiod::value_type >& getEmulatorPeriod() const
	{
		return m_emulatorPeriod;
	}
	void setEmulatorPeriod(const boost::optional<PCpuperiod::value_type >& value_)
	{
		m_emulatorPeriod = value_;
	}
	const boost::optional<PCpuquota::value_type >& getEmulatorQuota() const
	{
		return m_emulatorQuota;
	}
	void setEmulatorQuota(const boost::optional<PCpuquota::value_type >& value_)
	{
		m_emulatorQuota = value_;
	}
	const boost::optional<PCpuperiod::value_type >& getIothreadPeriod() const
	{
		return m_iothreadPeriod;
	}
	void setIothreadPeriod(const boost::optional<PCpuperiod::value_type >& value_)
	{
		m_iothreadPeriod = value_;
	}
	const boost::optional<PCpuquota::value_type >& getIothreadQuota() const
	{
		return m_iothreadQuota;
	}
	void setIothreadQuota(const boost::optional<PCpuquota::value_type >& value_)
	{
		m_iothreadQuota = value_;
	}
	const QList<Vcpupin >& getVcpupinList() const
	{
		return m_vcpupinList;
	}
	void setVcpupinList(const QList<Vcpupin >& value_)
	{
		m_vcpupinList = value_;
	}
	const boost::optional<PCpuset::value_type >& getEmulatorpin() const
	{
		return m_emulatorpin;
	}
	void setEmulatorpin(const boost::optional<PCpuset::value_type >& value_)
	{
		m_emulatorpin = value_;
	}
	const QList<Iothreadpin >& getIothreadpinList() const
	{
		return m_iothreadpinList;
	}
	void setIothreadpinList(const QList<Iothreadpin >& value_)
	{
		m_iothreadpinList = value_;
	}
	const QList<Vcpusched >& getVcpuschedList() const
	{
		return m_vcpuschedList;
	}
	void setVcpuschedList(const QList<Vcpusched >& value_)
	{
		m_vcpuschedList = value_;
	}
	const QList<Iothreadsched >& getIothreadschedList() const
	{
		return m_iothreadschedList;
	}
	void setIothreadschedList(const QList<Iothreadsched >& value_)
	{
		m_iothreadschedList = value_;
	}
	const boost::optional<VSchedparam >& getEmulatorsched() const
	{
		return m_emulatorsched;
	}
	void setEmulatorsched(const boost::optional<VSchedparam >& value_)
	{
		m_emulatorsched = value_;
	}
	const QList<Cachetune >& getCachetuneList() const
	{
		return m_cachetuneList;
	}
	void setCachetuneList(const QList<Cachetune >& value_)
	{
		m_cachetuneList = value_;
	}
	const QList<Memorytune >& getMemorytuneList() const
	{
		return m_memorytuneList;
	}
	void setMemorytuneList(const QList<Memorytune >& value_)
	{
		m_memorytuneList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PCpushares::value_type > m_shares;
	boost::optional<PCpuperiod::value_type > m_globalPeriod;
	boost::optional<PCpuquota::value_type > m_globalQuota;
	boost::optional<PCpuperiod::value_type > m_period;
	boost::optional<PCpuquota::value_type > m_quota;
	boost::optional<PCpuperiod::value_type > m_emulatorPeriod;
	boost::optional<PCpuquota::value_type > m_emulatorQuota;
	boost::optional<PCpuperiod::value_type > m_iothreadPeriod;
	boost::optional<PCpuquota::value_type > m_iothreadQuota;
	QList<Vcpupin > m_vcpupinList;
	boost::optional<PCpuset::value_type > m_emulatorpin;
	QList<Iothreadpin > m_iothreadpinList;
	QList<Vcpusched > m_vcpuschedList;
	QList<Iothreadsched > m_iothreadschedList;
	boost::optional<VSchedparam > m_emulatorsched;
	QList<Cachetune > m_cachetuneList;
	QList<Memorytune > m_memorytuneList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Memory2356

namespace Domain
{
namespace Xml
{
struct Memory2356
{
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VMemory

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Ordered<mpl::vector<Optional<Attribute<mpl::int_<238>, Name::Strict<339> > >, Optional<Attribute<Domain::Xml::PCpuset, Name::Strict<335> > > > >, Memory2356 > > VMemoryImpl;
typedef VMemoryImpl::value_type VMemory;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Memory1

namespace Domain
{
namespace Xml
{
struct Memory1
{
	const boost::optional<EMode7 >& getMode() const
	{
		return m_mode;
	}
	void setMode(const boost::optional<EMode7 >& value_)
	{
		m_mode = value_;
	}
	const VMemory& getMemory() const
	{
		return m_memory;
	}
	void setMemory(const VMemory& value_)
	{
		m_memory = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EMode7 > m_mode;
	VMemory m_memory;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Memnode

namespace Domain
{
namespace Xml
{
struct Memnode
{
	Memnode();

	PUnsignedInt::value_type getCellid() const
	{
		return m_cellid;
	}
	void setCellid(PUnsignedInt::value_type value_)
	{
		m_cellid = value_;
	}
	EMode8 getMode() const
	{
		return m_mode;
	}
	void setMode(EMode8 value_)
	{
		m_mode = value_;
	}
	const PCpuset::value_type& getNodeset() const
	{
		return m_nodeset;
	}
	void setNodeset(const PCpuset::value_type& value_)
	{
		m_nodeset = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_cellid;
	EMode8 m_mode;
	PCpuset::value_type m_nodeset;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Numatune

namespace Domain
{
namespace Xml
{
struct Numatune
{
	const boost::optional<Memory1 >& getMemory() const
	{
		return m_memory;
	}
	void setMemory(const boost::optional<Memory1 >& value_)
	{
		m_memory = value_;
	}
	const QList<Memnode >& getMemnodeList() const
	{
		return m_memnodeList;
	}
	void setMemnodeList(const QList<Memnode >& value_)
	{
		m_memnodeList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<Memory1 > m_memory;
	QList<Memnode > m_memnodeList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Resource

namespace Domain
{
namespace Xml
{
struct Resource
{
	const boost::optional<PAbsFilePath::value_type >& getPartition() const
	{
		return m_partition;
	}
	void setPartition(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_partition = value_;
	}
	const boost::optional<PAppid::value_type >& getFibrechannel() const
	{
		return m_fibrechannel;
	}
	void setFibrechannel(const boost::optional<PAppid::value_type >& value_)
	{
		m_fibrechannel = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PAbsFilePath::value_type > m_partition;
	boost::optional<PAppid::value_type > m_fibrechannel;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Apic

namespace Domain
{
namespace Xml
{
struct Apic
{
	const boost::optional<EVirOnOff >& getEoi() const
	{
		return m_eoi;
	}
	void setEoi(const boost::optional<EVirOnOff >& value_)
	{
		m_eoi = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirOnOff > m_eoi;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hap

namespace Domain
{
namespace Xml
{
struct Hap
{
	const boost::optional<EVirOnOff >& getState() const
	{
		return m_state;
	}
	void setState(const boost::optional<EVirOnOff >& value_)
	{
		m_state = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirOnOff > m_state;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Spinlocks

namespace Domain
{
namespace Xml
{
struct Spinlocks
{
	Spinlocks();

	EVirOnOff getState() const
	{
		return m_state;
	}
	void setState(EVirOnOff value_)
	{
		m_state = value_;
	}
	const boost::optional<PRetries::value_type >& getRetries() const
	{
		return m_retries;
	}
	void setRetries(const boost::optional<PRetries::value_type >& value_)
	{
		m_retries = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EVirOnOff m_state;
	boost::optional<PRetries::value_type > m_retries;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Stimer

namespace Domain
{
namespace Xml
{
struct Stimer
{
	const boost::optional<EVirOnOff >& getState() const
	{
		return m_state;
	}
	void setState(const boost::optional<EVirOnOff >& value_)
	{
		m_state = value_;
	}
	const boost::optional<EVirOnOff >& getDirect() const
	{
		return m_direct;
	}
	void setDirect(const boost::optional<EVirOnOff >& value_)
	{
		m_direct = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirOnOff > m_state;
	boost::optional<EVirOnOff > m_direct;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VendorId

namespace Domain
{
namespace Xml
{
struct VendorId
{
	VendorId();

	EVirOnOff getState() const
	{
		return m_state;
	}
	void setState(EVirOnOff value_)
	{
		m_state = value_;
	}
	const boost::optional<PValue::value_type >& getValue() const
	{
		return m_value;
	}
	void setValue(const boost::optional<PValue::value_type >& value_)
	{
		m_value = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EVirOnOff m_state;
	boost::optional<PValue::value_type > m_value;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hyperv

namespace Domain
{
namespace Xml
{
struct Hyperv
{
	const boost::optional<EVirOnOff >& getRelaxed() const
	{
		return m_relaxed;
	}
	void setRelaxed(const boost::optional<EVirOnOff >& value_)
	{
		m_relaxed = value_;
	}
	const boost::optional<EVirOnOff >& getVapic() const
	{
		return m_vapic;
	}
	void setVapic(const boost::optional<EVirOnOff >& value_)
	{
		m_vapic = value_;
	}
	const boost::optional<Spinlocks >& getSpinlocks() const
	{
		return m_spinlocks;
	}
	void setSpinlocks(const boost::optional<Spinlocks >& value_)
	{
		m_spinlocks = value_;
	}
	const boost::optional<EVirOnOff >& getVpindex() const
	{
		return m_vpindex;
	}
	void setVpindex(const boost::optional<EVirOnOff >& value_)
	{
		m_vpindex = value_;
	}
	const boost::optional<EVirOnOff >& getRuntime() const
	{
		return m_runtime;
	}
	void setRuntime(const boost::optional<EVirOnOff >& value_)
	{
		m_runtime = value_;
	}
	const boost::optional<EVirOnOff >& getSynic() const
	{
		return m_synic;
	}
	void setSynic(const boost::optional<EVirOnOff >& value_)
	{
		m_synic = value_;
	}
	const boost::optional<Stimer >& getStimer() const
	{
		return m_stimer;
	}
	void setStimer(const boost::optional<Stimer >& value_)
	{
		m_stimer = value_;
	}
	const boost::optional<EVirOnOff >& getReset() const
	{
		return m_reset;
	}
	void setReset(const boost::optional<EVirOnOff >& value_)
	{
		m_reset = value_;
	}
	const boost::optional<VendorId >& getVendorId() const
	{
		return m_vendorId;
	}
	void setVendorId(const boost::optional<VendorId >& value_)
	{
		m_vendorId = value_;
	}
	const boost::optional<EVirOnOff >& getFrequencies() const
	{
		return m_frequencies;
	}
	void setFrequencies(const boost::optional<EVirOnOff >& value_)
	{
		m_frequencies = value_;
	}
	const boost::optional<EVirOnOff >& getReenlightenment() const
	{
		return m_reenlightenment;
	}
	void setReenlightenment(const boost::optional<EVirOnOff >& value_)
	{
		m_reenlightenment = value_;
	}
	const boost::optional<EVirOnOff >& getTlbflush() const
	{
		return m_tlbflush;
	}
	void setTlbflush(const boost::optional<EVirOnOff >& value_)
	{
		m_tlbflush = value_;
	}
	const boost::optional<EVirOnOff >& getIpi() const
	{
		return m_ipi;
	}
	void setIpi(const boost::optional<EVirOnOff >& value_)
	{
		m_ipi = value_;
	}
	const boost::optional<EVirOnOff >& getEvmcs() const
	{
		return m_evmcs;
	}
	void setEvmcs(const boost::optional<EVirOnOff >& value_)
	{
		m_evmcs = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirOnOff > m_relaxed;
	boost::optional<EVirOnOff > m_vapic;
	boost::optional<Spinlocks > m_spinlocks;
	boost::optional<EVirOnOff > m_vpindex;
	boost::optional<EVirOnOff > m_runtime;
	boost::optional<EVirOnOff > m_synic;
	boost::optional<Stimer > m_stimer;
	boost::optional<EVirOnOff > m_reset;
	boost::optional<VendorId > m_vendorId;
	boost::optional<EVirOnOff > m_frequencies;
	boost::optional<EVirOnOff > m_reenlightenment;
	boost::optional<EVirOnOff > m_tlbflush;
	boost::optional<EVirOnOff > m_ipi;
	boost::optional<EVirOnOff > m_evmcs;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Kvm

namespace Domain
{
namespace Xml
{
struct Kvm
{
	const boost::optional<EVirOnOff >& getHidden() const
	{
		return m_hidden;
	}
	void setHidden(const boost::optional<EVirOnOff >& value_)
	{
		m_hidden = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirOnOff > m_hidden;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Pvspinlock

namespace Domain
{
namespace Xml
{
struct Pvspinlock
{
	const boost::optional<EVirOnOff >& getState() const
	{
		return m_state;
	}
	void setState(const boost::optional<EVirOnOff >& value_)
	{
		m_state = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirOnOff > m_state;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Capabilities

namespace Domain
{
namespace Xml
{
struct Capabilities
{
	Capabilities();

	EPolicy2 getPolicy() const
	{
		return m_policy;
	}
	void setPolicy(EPolicy2 value_)
	{
		m_policy = value_;
	}
	const boost::optional<EVirOnOff >& getAuditControl() const
	{
		return m_auditControl;
	}
	void setAuditControl(const boost::optional<EVirOnOff >& value_)
	{
		m_auditControl = value_;
	}
	const boost::optional<EVirOnOff >& getAuditWrite() const
	{
		return m_auditWrite;
	}
	void setAuditWrite(const boost::optional<EVirOnOff >& value_)
	{
		m_auditWrite = value_;
	}
	const boost::optional<EVirOnOff >& getBlockSuspend() const
	{
		return m_blockSuspend;
	}
	void setBlockSuspend(const boost::optional<EVirOnOff >& value_)
	{
		m_blockSuspend = value_;
	}
	const boost::optional<EVirOnOff >& getChown() const
	{
		return m_chown;
	}
	void setChown(const boost::optional<EVirOnOff >& value_)
	{
		m_chown = value_;
	}
	const boost::optional<EVirOnOff >& getDacOverride() const
	{
		return m_dacOverride;
	}
	void setDacOverride(const boost::optional<EVirOnOff >& value_)
	{
		m_dacOverride = value_;
	}
	const boost::optional<EVirOnOff >& getDacReadSearch() const
	{
		return m_dacReadSearch;
	}
	void setDacReadSearch(const boost::optional<EVirOnOff >& value_)
	{
		m_dacReadSearch = value_;
	}
	const boost::optional<EVirOnOff >& getFowner() const
	{
		return m_fowner;
	}
	void setFowner(const boost::optional<EVirOnOff >& value_)
	{
		m_fowner = value_;
	}
	const boost::optional<EVirOnOff >& getFsetid() const
	{
		return m_fsetid;
	}
	void setFsetid(const boost::optional<EVirOnOff >& value_)
	{
		m_fsetid = value_;
	}
	const boost::optional<EVirOnOff >& getIpcLock() const
	{
		return m_ipcLock;
	}
	void setIpcLock(const boost::optional<EVirOnOff >& value_)
	{
		m_ipcLock = value_;
	}
	const boost::optional<EVirOnOff >& getIpcOwner() const
	{
		return m_ipcOwner;
	}
	void setIpcOwner(const boost::optional<EVirOnOff >& value_)
	{
		m_ipcOwner = value_;
	}
	const boost::optional<EVirOnOff >& getKill() const
	{
		return m_kill;
	}
	void setKill(const boost::optional<EVirOnOff >& value_)
	{
		m_kill = value_;
	}
	const boost::optional<EVirOnOff >& getLease() const
	{
		return m_lease;
	}
	void setLease(const boost::optional<EVirOnOff >& value_)
	{
		m_lease = value_;
	}
	const boost::optional<EVirOnOff >& getLinuxImmutable() const
	{
		return m_linuxImmutable;
	}
	void setLinuxImmutable(const boost::optional<EVirOnOff >& value_)
	{
		m_linuxImmutable = value_;
	}
	const boost::optional<EVirOnOff >& getMacAdmin() const
	{
		return m_macAdmin;
	}
	void setMacAdmin(const boost::optional<EVirOnOff >& value_)
	{
		m_macAdmin = value_;
	}
	const boost::optional<EVirOnOff >& getMacOverride() const
	{
		return m_macOverride;
	}
	void setMacOverride(const boost::optional<EVirOnOff >& value_)
	{
		m_macOverride = value_;
	}
	const boost::optional<EVirOnOff >& getMknod() const
	{
		return m_mknod;
	}
	void setMknod(const boost::optional<EVirOnOff >& value_)
	{
		m_mknod = value_;
	}
	const boost::optional<EVirOnOff >& getNetAdmin() const
	{
		return m_netAdmin;
	}
	void setNetAdmin(const boost::optional<EVirOnOff >& value_)
	{
		m_netAdmin = value_;
	}
	const boost::optional<EVirOnOff >& getNetBindService() const
	{
		return m_netBindService;
	}
	void setNetBindService(const boost::optional<EVirOnOff >& value_)
	{
		m_netBindService = value_;
	}
	const boost::optional<EVirOnOff >& getNetBroadcast() const
	{
		return m_netBroadcast;
	}
	void setNetBroadcast(const boost::optional<EVirOnOff >& value_)
	{
		m_netBroadcast = value_;
	}
	const boost::optional<EVirOnOff >& getNetRaw() const
	{
		return m_netRaw;
	}
	void setNetRaw(const boost::optional<EVirOnOff >& value_)
	{
		m_netRaw = value_;
	}
	const boost::optional<EVirOnOff >& getSetgid() const
	{
		return m_setgid;
	}
	void setSetgid(const boost::optional<EVirOnOff >& value_)
	{
		m_setgid = value_;
	}
	const boost::optional<EVirOnOff >& getSetfcap() const
	{
		return m_setfcap;
	}
	void setSetfcap(const boost::optional<EVirOnOff >& value_)
	{
		m_setfcap = value_;
	}
	const boost::optional<EVirOnOff >& getSetpcap() const
	{
		return m_setpcap;
	}
	void setSetpcap(const boost::optional<EVirOnOff >& value_)
	{
		m_setpcap = value_;
	}
	const boost::optional<EVirOnOff >& getSetuid() const
	{
		return m_setuid;
	}
	void setSetuid(const boost::optional<EVirOnOff >& value_)
	{
		m_setuid = value_;
	}
	const boost::optional<EVirOnOff >& getSysAdmin() const
	{
		return m_sysAdmin;
	}
	void setSysAdmin(const boost::optional<EVirOnOff >& value_)
	{
		m_sysAdmin = value_;
	}
	const boost::optional<EVirOnOff >& getSysBoot() const
	{
		return m_sysBoot;
	}
	void setSysBoot(const boost::optional<EVirOnOff >& value_)
	{
		m_sysBoot = value_;
	}
	const boost::optional<EVirOnOff >& getSysChroot() const
	{
		return m_sysChroot;
	}
	void setSysChroot(const boost::optional<EVirOnOff >& value_)
	{
		m_sysChroot = value_;
	}
	const boost::optional<EVirOnOff >& getSysModule() const
	{
		return m_sysModule;
	}
	void setSysModule(const boost::optional<EVirOnOff >& value_)
	{
		m_sysModule = value_;
	}
	const boost::optional<EVirOnOff >& getSysNice() const
	{
		return m_sysNice;
	}
	void setSysNice(const boost::optional<EVirOnOff >& value_)
	{
		m_sysNice = value_;
	}
	const boost::optional<EVirOnOff >& getSysPacct() const
	{
		return m_sysPacct;
	}
	void setSysPacct(const boost::optional<EVirOnOff >& value_)
	{
		m_sysPacct = value_;
	}
	const boost::optional<EVirOnOff >& getSysPtrace() const
	{
		return m_sysPtrace;
	}
	void setSysPtrace(const boost::optional<EVirOnOff >& value_)
	{
		m_sysPtrace = value_;
	}
	const boost::optional<EVirOnOff >& getSysRawio() const
	{
		return m_sysRawio;
	}
	void setSysRawio(const boost::optional<EVirOnOff >& value_)
	{
		m_sysRawio = value_;
	}
	const boost::optional<EVirOnOff >& getSysResource() const
	{
		return m_sysResource;
	}
	void setSysResource(const boost::optional<EVirOnOff >& value_)
	{
		m_sysResource = value_;
	}
	const boost::optional<EVirOnOff >& getSysTime() const
	{
		return m_sysTime;
	}
	void setSysTime(const boost::optional<EVirOnOff >& value_)
	{
		m_sysTime = value_;
	}
	const boost::optional<EVirOnOff >& getSysTtyConfig() const
	{
		return m_sysTtyConfig;
	}
	void setSysTtyConfig(const boost::optional<EVirOnOff >& value_)
	{
		m_sysTtyConfig = value_;
	}
	const boost::optional<EVirOnOff >& getSyslog() const
	{
		return m_syslog;
	}
	void setSyslog(const boost::optional<EVirOnOff >& value_)
	{
		m_syslog = value_;
	}
	const boost::optional<EVirOnOff >& getWakeAlarm() const
	{
		return m_wakeAlarm;
	}
	void setWakeAlarm(const boost::optional<EVirOnOff >& value_)
	{
		m_wakeAlarm = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EPolicy2 m_policy;
	boost::optional<EVirOnOff > m_auditControl;
	boost::optional<EVirOnOff > m_auditWrite;
	boost::optional<EVirOnOff > m_blockSuspend;
	boost::optional<EVirOnOff > m_chown;
	boost::optional<EVirOnOff > m_dacOverride;
	boost::optional<EVirOnOff > m_dacReadSearch;
	boost::optional<EVirOnOff > m_fowner;
	boost::optional<EVirOnOff > m_fsetid;
	boost::optional<EVirOnOff > m_ipcLock;
	boost::optional<EVirOnOff > m_ipcOwner;
	boost::optional<EVirOnOff > m_kill;
	boost::optional<EVirOnOff > m_lease;
	boost::optional<EVirOnOff > m_linuxImmutable;
	boost::optional<EVirOnOff > m_macAdmin;
	boost::optional<EVirOnOff > m_macOverride;
	boost::optional<EVirOnOff > m_mknod;
	boost::optional<EVirOnOff > m_netAdmin;
	boost::optional<EVirOnOff > m_netBindService;
	boost::optional<EVirOnOff > m_netBroadcast;
	boost::optional<EVirOnOff > m_netRaw;
	boost::optional<EVirOnOff > m_setgid;
	boost::optional<EVirOnOff > m_setfcap;
	boost::optional<EVirOnOff > m_setpcap;
	boost::optional<EVirOnOff > m_setuid;
	boost::optional<EVirOnOff > m_sysAdmin;
	boost::optional<EVirOnOff > m_sysBoot;
	boost::optional<EVirOnOff > m_sysChroot;
	boost::optional<EVirOnOff > m_sysModule;
	boost::optional<EVirOnOff > m_sysNice;
	boost::optional<EVirOnOff > m_sysPacct;
	boost::optional<EVirOnOff > m_sysPtrace;
	boost::optional<EVirOnOff > m_sysRawio;
	boost::optional<EVirOnOff > m_sysResource;
	boost::optional<EVirOnOff > m_sysTime;
	boost::optional<EVirOnOff > m_sysTtyConfig;
	boost::optional<EVirOnOff > m_syslog;
	boost::optional<EVirOnOff > m_wakeAlarm;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Pmu

namespace Domain
{
namespace Xml
{
struct Pmu
{
	const boost::optional<EVirOnOff >& getState() const
	{
		return m_state;
	}
	void setState(const boost::optional<EVirOnOff >& value_)
	{
		m_state = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirOnOff > m_state;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Vmport

namespace Domain
{
namespace Xml
{
struct Vmport
{
	const boost::optional<EVirOnOff >& getState() const
	{
		return m_state;
	}
	void setState(const boost::optional<EVirOnOff >& value_)
	{
		m_state = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirOnOff > m_state;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Gic

namespace Domain
{
namespace Xml
{
struct Gic
{
	const boost::optional<PPositiveInteger::value_type >& getVersion() const
	{
		return m_version;
	}
	void setVersion(const boost::optional<PPositiveInteger::value_type >& value_)
	{
		m_version = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PPositiveInteger::value_type > m_version;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous2357

namespace Domain
{
namespace Xml
{
struct Anonymous2357
{
	Anonymous2357();

	EVirOnOff getState() const
	{
		return m_state;
	}
	void setState(EVirOnOff value_)
	{
		m_state = value_;
	}
	const boost::optional<ScaledInteger >& getTseg() const
	{
		return m_tseg;
	}
	void setTseg(const boost::optional<ScaledInteger >& value_)
	{
		m_tseg = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	EVirOnOff m_state;
	boost::optional<ScaledInteger > m_tseg;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Smm

namespace Domain
{
namespace Xml
{
struct Smm
{
	const boost::optional<Anonymous2357 >& getAnonymous2357() const
	{
		return m_anonymous2357;
	}
	void setAnonymous2357(const boost::optional<Anonymous2357 >& value_)
	{
		m_anonymous2357 = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<Anonymous2357 > m_anonymous2357;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hpt

namespace Domain
{
namespace Xml
{
struct Hpt
{
	const boost::optional<EResizing >& getResizing() const
	{
		return m_resizing;
	}
	void setResizing(const boost::optional<EResizing >& value_)
	{
		m_resizing = value_;
	}
	const boost::optional<ScaledInteger >& getMaxpagesize() const
	{
		return m_maxpagesize;
	}
	void setMaxpagesize(const boost::optional<ScaledInteger >& value_)
	{
		m_maxpagesize = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EResizing > m_resizing;
	boost::optional<ScaledInteger > m_maxpagesize;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Vmcoreinfo

namespace Domain
{
namespace Xml
{
struct Vmcoreinfo
{
	const boost::optional<EVirOnOff >& getState() const
	{
		return m_state;
	}
	void setState(const boost::optional<EVirOnOff >& value_)
	{
		m_state = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirOnOff > m_state;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Tcg

namespace Domain
{
namespace Xml
{
struct Tcg
{
	const boost::optional<ScaledInteger >& getTbCache() const
	{
		return m_tbCache;
	}
	void setTbCache(const boost::optional<ScaledInteger >& value_)
	{
		m_tbCache = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<ScaledInteger > m_tbCache;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Features

namespace Domain
{
namespace Xml
{
struct Features
{
	Features();

	bool getPae() const
	{
		return m_pae;
	}
	void setPae(bool value_)
	{
		m_pae = value_;
	}
	const boost::optional<Apic >& getApic() const
	{
		return m_apic;
	}
	void setApic(const boost::optional<Apic >& value_)
	{
		m_apic = value_;
	}
	bool getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(bool value_)
	{
		m_acpi = value_;
	}
	const boost::optional<Hap >& getHap() const
	{
		return m_hap;
	}
	void setHap(const boost::optional<Hap >& value_)
	{
		m_hap = value_;
	}
	const boost::optional<Hyperv >& getHyperv() const
	{
		return m_hyperv;
	}
	void setHyperv(const boost::optional<Hyperv >& value_)
	{
		m_hyperv = value_;
	}
	bool getViridian() const
	{
		return m_viridian;
	}
	void setViridian(bool value_)
	{
		m_viridian = value_;
	}
	const boost::optional<Kvm >& getKvm() const
	{
		return m_kvm;
	}
	void setKvm(const boost::optional<Kvm >& value_)
	{
		m_kvm = value_;
	}
	bool getPrivnet() const
	{
		return m_privnet;
	}
	void setPrivnet(bool value_)
	{
		m_privnet = value_;
	}
	const boost::optional<Pvspinlock >& getPvspinlock() const
	{
		return m_pvspinlock;
	}
	void setPvspinlock(const boost::optional<Pvspinlock >& value_)
	{
		m_pvspinlock = value_;
	}
	const boost::optional<Capabilities >& getCapabilities() const
	{
		return m_capabilities;
	}
	void setCapabilities(const boost::optional<Capabilities >& value_)
	{
		m_capabilities = value_;
	}
	const boost::optional<Pmu >& getPmu() const
	{
		return m_pmu;
	}
	void setPmu(const boost::optional<Pmu >& value_)
	{
		m_pmu = value_;
	}
	const boost::optional<Vmport >& getVmport() const
	{
		return m_vmport;
	}
	void setVmport(const boost::optional<Vmport >& value_)
	{
		m_vmport = value_;
	}
	const boost::optional<Gic >& getGic() const
	{
		return m_gic;
	}
	void setGic(const boost::optional<Gic >& value_)
	{
		m_gic = value_;
	}
	const boost::optional<Smm >& getSmm() const
	{
		return m_smm;
	}
	void setSmm(const boost::optional<Smm >& value_)
	{
		m_smm = value_;
	}
	const boost::optional<EDriver >& getIoapic() const
	{
		return m_ioapic;
	}
	void setIoapic(const boost::optional<EDriver >& value_)
	{
		m_ioapic = value_;
	}
	const boost::optional<Hpt >& getHpt() const
	{
		return m_hpt;
	}
	void setHpt(const boost::optional<Hpt >& value_)
	{
		m_hpt = value_;
	}
	const boost::optional<Vmcoreinfo >& getVmcoreinfo() const
	{
		return m_vmcoreinfo;
	}
	void setVmcoreinfo(const boost::optional<Vmcoreinfo >& value_)
	{
		m_vmcoreinfo = value_;
	}
	const boost::optional<EVirOnOff >& getHtm() const
	{
		return m_htm;
	}
	void setHtm(const boost::optional<EVirOnOff >& value_)
	{
		m_htm = value_;
	}
	const boost::optional<EVirOnOff >& getNestedHv() const
	{
		return m_nestedHv;
	}
	void setNestedHv(const boost::optional<EVirOnOff >& value_)
	{
		m_nestedHv = value_;
	}
	const boost::optional<EUnknown >& getMsrs() const
	{
		return m_msrs;
	}
	void setMsrs(const boost::optional<EUnknown >& value_)
	{
		m_msrs = value_;
	}
	const boost::optional<EVirOnOff >& getCcfAssist() const
	{
		return m_ccfAssist;
	}
	void setCcfAssist(const boost::optional<EVirOnOff >& value_)
	{
		m_ccfAssist = value_;
	}
	const boost::optional<EValue >& getCfpc() const
	{
		return m_cfpc;
	}
	void setCfpc(const boost::optional<EValue >& value_)
	{
		m_cfpc = value_;
	}
	const boost::optional<EValue1 >& getSbbc() const
	{
		return m_sbbc;
	}
	void setSbbc(const boost::optional<EValue1 >& value_)
	{
		m_sbbc = value_;
	}
	const boost::optional<EValue2 >& getIbs() const
	{
		return m_ibs;
	}
	void setIbs(const boost::optional<EValue2 >& value_)
	{
		m_ibs = value_;
	}
	const boost::optional<Tcg >& getTcg() const
	{
		return m_tcg;
	}
	void setTcg(const boost::optional<Tcg >& value_)
	{
		m_tcg = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	bool m_pae;
	boost::optional<Apic > m_apic;
	bool m_acpi;
	boost::optional<Hap > m_hap;
	boost::optional<Hyperv > m_hyperv;
	bool m_viridian;
	boost::optional<Kvm > m_kvm;
	bool m_privnet;
	boost::optional<Pvspinlock > m_pvspinlock;
	boost::optional<Capabilities > m_capabilities;
	boost::optional<Pmu > m_pmu;
	boost::optional<Vmport > m_vmport;
	boost::optional<Gic > m_gic;
	boost::optional<Smm > m_smm;
	boost::optional<EDriver > m_ioapic;
	boost::optional<Hpt > m_hpt;
	boost::optional<Vmcoreinfo > m_vmcoreinfo;
	boost::optional<EVirOnOff > m_htm;
	boost::optional<EVirOnOff > m_nestedHv;
	boost::optional<EUnknown > m_msrs;
	boost::optional<EVirOnOff > m_ccfAssist;
	boost::optional<EValue > m_cfpc;
	boost::optional<EValue1 > m_sbbc;
	boost::optional<EValue2 > m_ibs;
	boost::optional<Tcg > m_tcg;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VzDns

namespace Domain
{
namespace Xml
{
struct VzDns
{
	const boost::optional<PDnsName::value_type >& getHostname() const
	{
		return m_hostname;
	}
	void setHostname(const boost::optional<PDnsName::value_type >& value_)
	{
		m_hostname = value_;
	}
	const QList<VIpAddr >& getServerList() const
	{
		return m_serverList;
	}
	void setServerList(const QList<VIpAddr >& value_)
	{
		m_serverList = value_;
	}
	const QList<PDnsName::value_type >& getSearchList() const
	{
		return m_searchList;
	}
	void setSearchList(const QList<PDnsName::value_type >& value_)
	{
		m_searchList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PDnsName::value_type > m_hostname;
	QList<VIpAddr > m_serverList;
	QList<PDnsName::value_type > m_searchList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Class

namespace Domain
{
namespace Xml
{
struct Class
{
	Class();

	PUnsignedInt::value_type getId() const
	{
		return m_id;
	}
	void setId(PUnsignedInt::value_type value_)
	{
		m_id = value_;
	}
	PUnsignedLong::value_type getRate() const
	{
		return m_rate;
	}
	void setRate(PUnsignedLong::value_type value_)
	{
		m_rate = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_id;
	PUnsignedLong::value_type m_rate;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VzNetworkRates

namespace Domain
{
namespace Xml
{
struct VzNetworkRates
{
	VzNetworkRates();

	bool getRateBound() const
	{
		return m_rateBound;
	}
	void setRateBound(bool value_)
	{
		m_rateBound = value_;
	}
	const QList<Class >& getClassList() const
	{
		return m_classList;
	}
	void setClassList(const QList<Class >& value_)
	{
		m_classList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	bool m_rateBound;
	QList<Class > m_classList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct SuspendToMem

namespace Domain
{
namespace Xml
{
struct SuspendToMem
{
	const boost::optional<EVirYesNo >& getEnabled() const
	{
		return m_enabled;
	}
	void setEnabled(const boost::optional<EVirYesNo >& value_)
	{
		m_enabled = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirYesNo > m_enabled;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct SuspendToDisk

namespace Domain
{
namespace Xml
{
struct SuspendToDisk
{
	const boost::optional<EVirYesNo >& getEnabled() const
	{
		return m_enabled;
	}
	void setEnabled(const boost::optional<EVirYesNo >& value_)
	{
		m_enabled = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirYesNo > m_enabled;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Pm

namespace Domain
{
namespace Xml
{
struct Pm
{
	const boost::optional<SuspendToMem >& getSuspendToMem() const
	{
		return m_suspendToMem;
	}
	void setSuspendToMem(const boost::optional<SuspendToMem >& value_)
	{
		m_suspendToMem = value_;
	}
	const boost::optional<SuspendToDisk >& getSuspendToDisk() const
	{
		return m_suspendToDisk;
	}
	void setSuspendToDisk(const boost::optional<SuspendToDisk >& value_)
	{
		m_suspendToDisk = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<SuspendToMem > m_suspendToMem;
	boost::optional<SuspendToDisk > m_suspendToDisk;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Event

namespace Domain
{
namespace Xml
{
struct Event
{
	Event();

	EName3 getName() const
	{
		return m_name;
	}
	void setName(EName3 value_)
	{
		m_name = value_;
	}
	EVirYesNo getEnabled() const
	{
		return m_enabled;
	}
	void setEnabled(EVirYesNo value_)
	{
		m_enabled = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EName3 m_name;
	EVirYesNo m_enabled;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Uid

namespace Domain
{
namespace Xml
{
struct Uid
{
	Uid();

	PUnsignedInt::value_type getStart() const
	{
		return m_start;
	}
	void setStart(PUnsignedInt::value_type value_)
	{
		m_start = value_;
	}
	PUnsignedInt::value_type getTarget() const
	{
		return m_target;
	}
	void setTarget(PUnsignedInt::value_type value_)
	{
		m_target = value_;
	}
	PUnsignedInt::value_type getCount() const
	{
		return m_count;
	}
	void setCount(PUnsignedInt::value_type value_)
	{
		m_count = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_start;
	PUnsignedInt::value_type m_target;
	PUnsignedInt::value_type m_count;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Gid

namespace Domain
{
namespace Xml
{
struct Gid
{
	Gid();

	PUnsignedInt::value_type getStart() const
	{
		return m_start;
	}
	void setStart(PUnsignedInt::value_type value_)
	{
		m_start = value_;
	}
	PUnsignedInt::value_type getTarget() const
	{
		return m_target;
	}
	void setTarget(PUnsignedInt::value_type value_)
	{
		m_target = value_;
	}
	PUnsignedInt::value_type getCount() const
	{
		return m_count;
	}
	void setCount(PUnsignedInt::value_type value_)
	{
		m_count = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_start;
	PUnsignedInt::value_type m_target;
	PUnsignedInt::value_type m_count;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Idmap

namespace Domain
{
namespace Xml
{
struct Idmap
{
	const QList<Uid >& getUidList() const
	{
		return m_uidList;
	}
	void setUidList(const QList<Uid >& value_)
	{
		m_uidList = value_;
	}
	const QList<Gid >& getGidList() const
	{
		return m_gidList;
	}
	void setGidList(const QList<Gid >& value_)
	{
		m_gidList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	QList<Uid > m_uidList;
	QList<Gid > m_gidList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Disk7002

namespace Domain
{
namespace Xml
{
struct Disk7002
{
	Disk7002();

	EDevice1 getDevice() const
	{
		return m_device;
	}
	void setDevice(EDevice1 value_)
	{
		m_device = value_;
	}
	const boost::optional<EVirYesNo >& getRawio() const
	{
		return m_rawio;
	}
	void setRawio(const boost::optional<EVirYesNo >& value_)
	{
		m_rawio = value_;
	}
	const boost::optional<ESgio >& getSgio() const
	{
		return m_sgio;
	}
	void setSgio(const boost::optional<ESgio >& value_)
	{
		m_sgio = value_;
	}

private:
	EDevice1 m_device;
	boost::optional<EVirYesNo > m_rawio;
	boost::optional<ESgio > m_sgio;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VDisk

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Optional<Attribute<Domain::Xml::EDevice, Name::Strict<354> > >, Disk7002 > > VDiskImpl;
typedef VDiskImpl::value_type VDisk;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct DriverFormat

namespace Domain
{
namespace Xml
{
struct DriverFormat
{
	const boost::optional<PGenericName::value_type >& getName() const
	{
		return m_name;
	}
	void setName(const boost::optional<PGenericName::value_type >& value_)
	{
		m_name = value_;
	}
	const boost::optional<VType >& getType() const
	{
		return m_type;
	}
	void setType(const boost::optional<VType >& value_)
	{
		m_type = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	boost::optional<PGenericName::value_type > m_name;
	boost::optional<VType > m_type;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VirtioOptions

namespace Domain
{
namespace Xml
{
struct VirtioOptions
{
	const boost::optional<EVirOnOff >& getIommu() const
	{
		return m_iommu;
	}
	void setIommu(const boost::optional<EVirOnOff >& value_)
	{
		m_iommu = value_;
	}
	const boost::optional<EVirOnOff >& getAts() const
	{
		return m_ats;
	}
	void setAts(const boost::optional<EVirOnOff >& value_)
	{
		m_ats = value_;
	}
	const boost::optional<EVirOnOff >& getPacked() const
	{
		return m_packed;
	}
	void setPacked(const boost::optional<EVirOnOff >& value_)
	{
		m_packed = value_;
	}
	const boost::optional<EVirOnOff >& getPagePerVq() const
	{
		return m_pagePerVq;
	}
	void setPagePerVq(const boost::optional<EVirOnOff >& value_)
	{
		m_pagePerVq = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirOnOff > m_iommu;
	boost::optional<EVirOnOff > m_ats;
	boost::optional<EVirOnOff > m_packed;
	boost::optional<EVirOnOff > m_pagePerVq;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct MetadataCache

namespace Domain
{
namespace Xml
{
struct MetadataCache
{
	const boost::optional<ScaledInteger >& getMaxSize() const
	{
		return m_maxSize;
	}
	void setMaxSize(const boost::optional<ScaledInteger >& value_)
	{
		m_maxSize = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<ScaledInteger > m_maxSize;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Driver

namespace Domain
{
namespace Xml
{
struct Driver
{
	const boost::optional<DriverFormat >& getDriverFormat() const
	{
		return m_driverFormat;
	}
	void setDriverFormat(const boost::optional<DriverFormat >& value_)
	{
		m_driverFormat = value_;
	}
	const boost::optional<ECache >& getCache() const
	{
		return m_cache;
	}
	void setCache(const boost::optional<ECache >& value_)
	{
		m_cache = value_;
	}
	const boost::optional<EErrorPolicy >& getErrorPolicy() const
	{
		return m_errorPolicy;
	}
	void setErrorPolicy(const boost::optional<EErrorPolicy >& value_)
	{
		m_errorPolicy = value_;
	}
	const boost::optional<ERerrorPolicy >& getRerrorPolicy() const
	{
		return m_rerrorPolicy;
	}
	void setRerrorPolicy(const boost::optional<ERerrorPolicy >& value_)
	{
		m_rerrorPolicy = value_;
	}
	const boost::optional<EIo >& getIo() const
	{
		return m_io;
	}
	void setIo(const boost::optional<EIo >& value_)
	{
		m_io = value_;
	}
	const boost::optional<EVirOnOff >& getIoeventfd() const
	{
		return m_ioeventfd;
	}
	void setIoeventfd(const boost::optional<EVirOnOff >& value_)
	{
		m_ioeventfd = value_;
	}
	const boost::optional<EVirOnOff >& getEventIdx() const
	{
		return m_eventIdx;
	}
	void setEventIdx(const boost::optional<EVirOnOff >& value_)
	{
		m_eventIdx = value_;
	}
	const boost::optional<EVirOnOff >& getCopyOnRead() const
	{
		return m_copyOnRead;
	}
	void setCopyOnRead(const boost::optional<EVirOnOff >& value_)
	{
		m_copyOnRead = value_;
	}
	const boost::optional<EDiscard >& getDiscard() const
	{
		return m_discard;
	}
	void setDiscard(const boost::optional<EDiscard >& value_)
	{
		m_discard = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getIothread() const
	{
		return m_iothread;
	}
	void setIothread(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_iothread = value_;
	}
	const boost::optional<EDetectZeroes >& getDetectZeroes() const
	{
		return m_detectZeroes;
	}
	void setDetectZeroes(const boost::optional<EDetectZeroes >& value_)
	{
		m_detectZeroes = value_;
	}
	const boost::optional<PPositiveInteger::value_type >& getQueues() const
	{
		return m_queues;
	}
	void setQueues(const boost::optional<PPositiveInteger::value_type >& value_)
	{
		m_queues = value_;
	}
	const boost::optional<PPositiveInteger::value_type >& getQueueSize() const
	{
		return m_queueSize;
	}
	void setQueueSize(const boost::optional<PPositiveInteger::value_type >& value_)
	{
		m_queueSize = value_;
	}
	const VirtioOptions& getVirtioOptions() const
	{
		return m_virtioOptions;
	}
	void setVirtioOptions(const VirtioOptions& value_)
	{
		m_virtioOptions = value_;
	}
	const boost::optional<MetadataCache >& getMetadataCache() const
	{
		return m_metadataCache;
	}
	void setMetadataCache(const boost::optional<MetadataCache >& value_)
	{
		m_metadataCache = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<DriverFormat > m_driverFormat;
	boost::optional<ECache > m_cache;
	boost::optional<EErrorPolicy > m_errorPolicy;
	boost::optional<ERerrorPolicy > m_rerrorPolicy;
	boost::optional<EIo > m_io;
	boost::optional<EVirOnOff > m_ioeventfd;
	boost::optional<EVirOnOff > m_eventIdx;
	boost::optional<EVirOnOff > m_copyOnRead;
	boost::optional<EDiscard > m_discard;
	boost::optional<PUnsignedInt::value_type > m_iothread;
	boost::optional<EDetectZeroes > m_detectZeroes;
	boost::optional<PPositiveInteger::value_type > m_queues;
	boost::optional<PPositiveInteger::value_type > m_queueSize;
	VirtioOptions m_virtioOptions;
	boost::optional<MetadataCache > m_metadataCache;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct MetadataCache1

namespace Domain
{
namespace Xml
{
struct MetadataCache1
{
	const boost::optional<ScaledInteger >& getMaxSize() const
	{
		return m_maxSize;
	}
	void setMaxSize(const boost::optional<ScaledInteger >& value_)
	{
		m_maxSize = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<ScaledInteger > m_maxSize;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Format

namespace Domain
{
namespace Xml
{
struct Format
{
	const VStorageFormat& getType() const
	{
		return m_type;
	}
	void setType(const VStorageFormat& value_)
	{
		m_type = value_;
	}
	const boost::optional<MetadataCache1 >& getMetadataCache() const
	{
		return m_metadataCache;
	}
	void setMetadataCache(const boost::optional<MetadataCache1 >& value_)
	{
		m_metadataCache = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VStorageFormat m_type;
	boost::optional<MetadataCache1 > m_metadataCache;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous2358

namespace Domain
{
namespace Xml
{
struct Anonymous2358
{
	const boost::optional<Source4 >& getSource() const
	{
		return m_source;
	}
	void setSource(const boost::optional<Source4 >& value_)
	{
		m_source = value_;
	}
	const boost::optional<Format >& getFormat() const
	{
		return m_format;
	}
	void setFormat(const boost::optional<Format >& value_)
	{
		m_format = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	boost::optional<Source4 > m_source;
	boost::optional<Format > m_format;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Mirror4765

namespace Domain
{
namespace Xml
{
struct Mirror4765
{
	const PAbsFilePath::value_type& getFile() const
	{
		return m_file;
	}
	void setFile(const PAbsFilePath::value_type& value_)
	{
		m_file = value_;
	}
	const boost::optional<VStorageFormat >& getFormat() const
	{
		return m_format;
	}
	void setFormat(const boost::optional<VStorageFormat >& value_)
	{
		m_format = value_;
	}
	const boost::optional<EJob >& getJob() const
	{
		return m_job;
	}
	void setJob(const boost::optional<EJob >& value_)
	{
		m_job = value_;
	}
	const boost::optional<Anonymous2358 >& getAnonymous2358() const
	{
		return m_anonymous2358;
	}
	void setAnonymous2358(const boost::optional<Anonymous2358 >& value_)
	{
		m_anonymous2358 = value_;
	}

private:
	PAbsFilePath::value_type m_file;
	boost::optional<VStorageFormat > m_format;
	boost::optional<EJob > m_job;
	boost::optional<Anonymous2358 > m_anonymous2358;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Mirror4766

namespace Domain
{
namespace Xml
{
struct Mirror4766
{
	Mirror4766();

	EJob1 getJob() const
	{
		return m_job;
	}
	void setJob(EJob1 value_)
	{
		m_job = value_;
	}
	const VDiskSource& getDiskSource() const
	{
		return m_diskSource;
	}
	void setDiskSource(const VDiskSource& value_)
	{
		m_diskSource = value_;
	}
	const boost::optional<Format >& getFormat() const
	{
		return m_format;
	}
	void setFormat(const boost::optional<Format >& value_)
	{
		m_format = value_;
	}

private:
	EJob1 m_job;
	VDiskSource m_diskSource;
	boost::optional<Format > m_format;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VMirror

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Mirror4765, Mirror4766 > > VMirrorImpl;
typedef VMirrorImpl::value_type VMirror;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Mirror

namespace Domain
{
namespace Xml
{
struct Mirror
{
	const VMirror& getMirror() const
	{
		return m_mirror;
	}
	void setMirror(const VMirror& value_)
	{
		m_mirror = value_;
	}
	const boost::optional<EReady >& getReady() const
	{
		return m_ready;
	}
	void setReady(const boost::optional<EReady >& value_)
	{
		m_ready = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VMirror m_mirror;
	boost::optional<EReady > m_ready;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VSecret1

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Attribute<Domain::Xml::VUUID, Name::Strict<151> >, Attribute<Domain::Xml::PGenericName, Name::Strict<640> > > > VSecret1Impl;
typedef VSecret1Impl::value_type VSecret1;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Secret

namespace Domain
{
namespace Xml
{
struct Secret
{
	Secret();

	EType8 getType() const
	{
		return m_type;
	}
	void setType(EType8 value_)
	{
		m_type = value_;
	}
	const VSecret1& getSecret() const
	{
		return m_secret;
	}
	void setSecret(const VSecret1& value_)
	{
		m_secret = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EType8 m_type;
	VSecret1 m_secret;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Auth

namespace Domain
{
namespace Xml
{
struct Auth
{
	const PGenericName::value_type& getUsername() const
	{
		return m_username;
	}
	void setUsername(const PGenericName::value_type& value_)
	{
		m_username = value_;
	}
	const Secret& getSecret() const
	{
		return m_secret;
	}
	void setSecret(const Secret& value_)
	{
		m_secret = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PGenericName::value_type m_username;
	Secret m_secret;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Target

namespace Domain
{
namespace Xml
{
struct Target
{
	const PDiskTarget::value_type& getDev() const
	{
		return m_dev;
	}
	void setDev(const PDiskTarget::value_type& value_)
	{
		m_dev = value_;
	}
	const boost::optional<EBus >& getBus() const
	{
		return m_bus;
	}
	void setBus(const boost::optional<EBus >& value_)
	{
		m_bus = value_;
	}
	const boost::optional<ETray >& getTray() const
	{
		return m_tray;
	}
	void setTray(const boost::optional<ETray >& value_)
	{
		m_tray = value_;
	}
	const boost::optional<EVirOnOff >& getRemovable() const
	{
		return m_removable;
	}
	void setRemovable(const boost::optional<EVirOnOff >& value_)
	{
		m_removable = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PDiskTarget::value_type m_dev;
	boost::optional<EBus > m_bus;
	boost::optional<ETray > m_tray;
	boost::optional<EVirOnOff > m_removable;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Boot

namespace Domain
{
namespace Xml
{
struct Boot
{
	Boot();

	PPositiveInteger::value_type getOrder() const
	{
		return m_order;
	}
	void setOrder(PPositiveInteger::value_type value_)
	{
		m_order = value_;
	}
	const boost::optional<PLoadparm::value_type >& getLoadparm() const
	{
		return m_loadparm;
	}
	void setLoadparm(const boost::optional<PLoadparm::value_type >& value_)
	{
		m_loadparm = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PPositiveInteger::value_type m_order;
	boost::optional<PLoadparm::value_type > m_loadparm;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Transient

namespace Domain
{
namespace Xml
{
struct Transient
{
	const boost::optional<EVirYesNo >& getShareBacking() const
	{
		return m_shareBacking;
	}
	void setShareBacking(const boost::optional<EVirYesNo >& value_)
	{
		m_shareBacking = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirYesNo > m_shareBacking;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Variant4770

namespace Domain
{
namespace Xml
{
struct Variant4770
{
	const boost::optional<PReadBytesSec::value_type >& getReadBytesSec() const
	{
		return m_readBytesSec;
	}
	void setReadBytesSec(const boost::optional<PReadBytesSec::value_type >& value_)
	{
		m_readBytesSec = value_;
	}
	const boost::optional<PWriteBytesSec::value_type >& getWriteBytesSec() const
	{
		return m_writeBytesSec;
	}
	void setWriteBytesSec(const boost::optional<PWriteBytesSec::value_type >& value_)
	{
		m_writeBytesSec = value_;
	}

private:
	boost::optional<PReadBytesSec::value_type > m_readBytesSec;
	boost::optional<PWriteBytesSec::value_type > m_writeBytesSec;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice4771

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Element<Text<Domain::Xml::PTotalBytesSec >, Name::Strict<1104> >, Variant4770 > > VChoice4771Impl;
typedef VChoice4771Impl::value_type VChoice4771;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Variant4773

namespace Domain
{
namespace Xml
{
struct Variant4773
{
	const boost::optional<PReadIopsSec1::value_type >& getReadIopsSec() const
	{
		return m_readIopsSec;
	}
	void setReadIopsSec(const boost::optional<PReadIopsSec1::value_type >& value_)
	{
		m_readIopsSec = value_;
	}
	const boost::optional<PWriteIopsSec1::value_type >& getWriteIopsSec() const
	{
		return m_writeIopsSec;
	}
	void setWriteIopsSec(const boost::optional<PWriteIopsSec1::value_type >& value_)
	{
		m_writeIopsSec = value_;
	}

private:
	boost::optional<PReadIopsSec1::value_type > m_readIopsSec;
	boost::optional<PWriteIopsSec1::value_type > m_writeIopsSec;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice4774

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Element<Text<Domain::Xml::PTotalIopsSec >, Name::Strict<1108> >, Variant4773 > > VChoice4774Impl;
typedef VChoice4774Impl::value_type VChoice4774;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Iotune

namespace Domain
{
namespace Xml
{
struct Iotune
{
	const VChoice4771& getChoice4771() const
	{
		return m_choice4771;
	}
	void setChoice4771(const VChoice4771& value_)
	{
		m_choice4771 = value_;
	}
	const VChoice4774& getChoice4774() const
	{
		return m_choice4774;
	}
	void setChoice4774(const VChoice4774& value_)
	{
		m_choice4774 = value_;
	}
	const boost::optional<PSizeIopsSec::value_type >& getSizeIopsSec() const
	{
		return m_sizeIopsSec;
	}
	void setSizeIopsSec(const boost::optional<PSizeIopsSec::value_type >& value_)
	{
		m_sizeIopsSec = value_;
	}
	const boost::optional<QString >& getGroupName() const
	{
		return m_groupName;
	}
	void setGroupName(const boost::optional<QString >& value_)
	{
		m_groupName = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VChoice4771 m_choice4771;
	VChoice4774 m_choice4774;
	boost::optional<PSizeIopsSec::value_type > m_sizeIopsSec;
	boost::optional<QString > m_groupName;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Pciaddress

namespace Domain
{
namespace Xml
{
struct Pciaddress
{
	const boost::optional<PPciDomain::value_type >& getDomain() const
	{
		return m_domain;
	}
	void setDomain(const boost::optional<PPciDomain::value_type >& value_)
	{
		m_domain = value_;
	}
	const PPciBus::value_type& getBus() const
	{
		return m_bus;
	}
	void setBus(const PPciBus::value_type& value_)
	{
		m_bus = value_;
	}
	const PPciSlot::value_type& getSlot() const
	{
		return m_slot;
	}
	void setSlot(const PPciSlot::value_type& value_)
	{
		m_slot = value_;
	}
	const PPciFunc::value_type& getFunction() const
	{
		return m_function;
	}
	void setFunction(const PPciFunc::value_type& value_)
	{
		m_function = value_;
	}
	const boost::optional<EVirOnOff >& getMultifunction() const
	{
		return m_multifunction;
	}
	void setMultifunction(const boost::optional<EVirOnOff >& value_)
	{
		m_multifunction = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PPciDomain::value_type > m_domain;
	PPciBus::value_type m_bus;
	PPciSlot::value_type m_slot;
	PPciFunc::value_type m_function;
	boost::optional<EVirOnOff > m_multifunction;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Driveaddress

namespace Domain
{
namespace Xml
{
struct Driveaddress
{
	const boost::optional<PDriveController::value_type >& getController() const
	{
		return m_controller;
	}
	void setController(const boost::optional<PDriveController::value_type >& value_)
	{
		m_controller = value_;
	}
	const boost::optional<PDriveBus::value_type >& getBus() const
	{
		return m_bus;
	}
	void setBus(const boost::optional<PDriveBus::value_type >& value_)
	{
		m_bus = value_;
	}
	const boost::optional<PDriveTarget::value_type >& getTarget() const
	{
		return m_target;
	}
	void setTarget(const boost::optional<PDriveTarget::value_type >& value_)
	{
		m_target = value_;
	}
	const boost::optional<PDriveUnit::value_type >& getUnit() const
	{
		return m_unit;
	}
	void setUnit(const boost::optional<PDriveUnit::value_type >& value_)
	{
		m_unit = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	boost::optional<PDriveController::value_type > m_controller;
	boost::optional<PDriveBus::value_type > m_bus;
	boost::optional<PDriveTarget::value_type > m_target;
	boost::optional<PDriveUnit::value_type > m_unit;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Virtioserialaddress

namespace Domain
{
namespace Xml
{
struct Virtioserialaddress
{
	const PDriveController::value_type& getController() const
	{
		return m_controller;
	}
	void setController(const PDriveController::value_type& value_)
	{
		m_controller = value_;
	}
	const boost::optional<PDriveBus::value_type >& getBus() const
	{
		return m_bus;
	}
	void setBus(const boost::optional<PDriveBus::value_type >& value_)
	{
		m_bus = value_;
	}
	const boost::optional<PDriveUnit::value_type >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<PDriveUnit::value_type >& value_)
	{
		m_port = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	PDriveController::value_type m_controller;
	boost::optional<PDriveBus::value_type > m_bus;
	boost::optional<PDriveUnit::value_type > m_port;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Ccidaddress

namespace Domain
{
namespace Xml
{
struct Ccidaddress
{
	const PDriveController::value_type& getController() const
	{
		return m_controller;
	}
	void setController(const PDriveController::value_type& value_)
	{
		m_controller = value_;
	}
	const boost::optional<PDriveUnit::value_type >& getSlot() const
	{
		return m_slot;
	}
	void setSlot(const boost::optional<PDriveUnit::value_type >& value_)
	{
		m_slot = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	PDriveController::value_type m_controller;
	boost::optional<PDriveUnit::value_type > m_slot;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Usbportaddress

namespace Domain
{
namespace Xml
{
struct Usbportaddress
{
	const PUsbAddr::value_type& getBus() const
	{
		return m_bus;
	}
	void setBus(const PUsbAddr::value_type& value_)
	{
		m_bus = value_;
	}
	const boost::optional<PUsbPort::value_type >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<PUsbPort::value_type >& value_)
	{
		m_port = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	PUsbAddr::value_type m_bus;
	boost::optional<PUsbPort::value_type > m_port;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous9190

namespace Domain
{
namespace Xml
{
struct Anonymous9190
{
	const VCcwCssidRange& getCssid() const
	{
		return m_cssid;
	}
	void setCssid(const VCcwCssidRange& value_)
	{
		m_cssid = value_;
	}
	const PCcwSsidRange::value_type& getSsid() const
	{
		return m_ssid;
	}
	void setSsid(const PCcwSsidRange::value_type& value_)
	{
		m_ssid = value_;
	}
	const VCcwDevnoRange& getDevno() const
	{
		return m_devno;
	}
	void setDevno(const VCcwDevnoRange& value_)
	{
		m_devno = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	VCcwCssidRange m_cssid;
	PCcwSsidRange::value_type m_ssid;
	VCcwDevnoRange m_devno;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Isaaddress

namespace Domain
{
namespace Xml
{
struct Isaaddress
{
	const boost::optional<PIobase::value_type >& getIobase() const
	{
		return m_iobase;
	}
	void setIobase(const boost::optional<PIobase::value_type >& value_)
	{
		m_iobase = value_;
	}
	const boost::optional<PIrq::value_type >& getIrq() const
	{
		return m_irq;
	}
	void setIrq(const boost::optional<PIrq::value_type >& value_)
	{
		m_irq = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	boost::optional<PIobase::value_type > m_iobase;
	boost::optional<PIrq::value_type > m_irq;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Dimmaddress

namespace Domain
{
namespace Xml
{
struct Dimmaddress
{
	const boost::optional<PUnsignedInt::value_type >& getSlot() const
	{
		return m_slot;
	}
	void setSlot(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_slot = value_;
	}
	const boost::optional<PHexuint::value_type >& getBase() const
	{
		return m_base;
	}
	void setBase(const boost::optional<PHexuint::value_type >& value_)
	{
		m_base = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	boost::optional<PUnsignedInt::value_type > m_slot;
	boost::optional<PHexuint::value_type > m_base;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VAddress

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Ordered<mpl::vector<Attribute<mpl::int_<596>, Name::Strict<105> >, Fragment<Pciaddress > > >, Ordered<mpl::vector<Attribute<mpl::int_<1052>, Name::Strict<105> >, Fragment<Driveaddress > > >, Ordered<mpl::vector<Attribute<mpl::int_<622>, Name::Strict<105> >, Fragment<Virtioserialaddress > > >, Ordered<mpl::vector<Attribute<mpl::int_<573>, Name::Strict<105> >, Fragment<Ccidaddress > > >, Ordered<mpl::vector<Attribute<mpl::int_<531>, Name::Strict<105> >, Fragment<Usbportaddress > > >, Ordered<mpl::vector<Attribute<mpl::int_<1057>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::PSpaprvioReg, Name::Strict<947> > > > >, Ordered<mpl::vector<Attribute<mpl::int_<1059>, Name::Strict<105> >, Optional<Fragment<Anonymous9190 > > > >, Ordered<mpl::vector<Attribute<mpl::int_<1061>, Name::Strict<105> >, Fragment<Isaaddress > > >, Ordered<mpl::vector<Attribute<mpl::int_<1063>, Name::Strict<105> >, Fragment<Dimmaddress > > >, Ordered<mpl::vector<Attribute<mpl::int_<1065>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::VUUID, Name::Strict<184> > > > > > > VAddressImpl;
typedef VAddressImpl::value_type VAddress;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Geometry

namespace Domain
{
namespace Xml
{
struct Geometry
{
	Geometry();

	PCyls::value_type getCyls() const
	{
		return m_cyls;
	}
	void setCyls(PCyls::value_type value_)
	{
		m_cyls = value_;
	}
	PHeads::value_type getHeads() const
	{
		return m_heads;
	}
	void setHeads(PHeads::value_type value_)
	{
		m_heads = value_;
	}
	PSecs::value_type getSecs() const
	{
		return m_secs;
	}
	void setSecs(PSecs::value_type value_)
	{
		m_secs = value_;
	}
	const boost::optional<ETrans >& getTrans() const
	{
		return m_trans;
	}
	void setTrans(const boost::optional<ETrans >& value_)
	{
		m_trans = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PCyls::value_type m_cyls;
	PHeads::value_type m_heads;
	PSecs::value_type m_secs;
	boost::optional<ETrans > m_trans;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Blockio

namespace Domain
{
namespace Xml
{
struct Blockio
{
	const boost::optional<PLogicalBlockSize::value_type >& getLogicalBlockSize() const
	{
		return m_logicalBlockSize;
	}
	void setLogicalBlockSize(const boost::optional<PLogicalBlockSize::value_type >& value_)
	{
		m_logicalBlockSize = value_;
	}
	const boost::optional<PPhysicalBlockSize::value_type >& getPhysicalBlockSize() const
	{
		return m_physicalBlockSize;
	}
	void setPhysicalBlockSize(const boost::optional<PPhysicalBlockSize::value_type >& value_)
	{
		m_physicalBlockSize = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PLogicalBlockSize::value_type > m_logicalBlockSize;
	boost::optional<PPhysicalBlockSize::value_type > m_physicalBlockSize;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct BackingStore

namespace Domain
{
namespace Xml
{
struct BackingStore
{
	const boost::optional<PPositiveInteger::value_type >& getIndex() const
	{
		return m_index;
	}
	void setIndex(const boost::optional<PPositiveInteger::value_type >& value_)
	{
		m_index = value_;
	}
	const VDiskSource& getDiskSource() const
	{
		return m_diskSource;
	}
	void setDiskSource(const VDiskSource& value_)
	{
		m_diskSource = value_;
	}
	const VDiskBackingChainBin* getDiskBackingChain() const;
	void setDiskBackingChain(const VDiskBackingChainBin& value_);
	const Format& getFormat() const
	{
		return m_format;
	}
	void setFormat(const Format& value_)
	{
		m_format = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PPositiveInteger::value_type > m_index;
	VDiskSource m_diskSource;
	boost::any m_diskBackingChain;
	Format m_format;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VDiskBackingChain

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Element<Domain::Xml::BackingStore, Name::Strict<487> >, Optional<Element<Empty, Name::Strict<487> > > > > VDiskBackingChainImpl;
typedef VDiskBackingChainImpl::value_type VDiskBackingChain;
struct VDiskBackingChainBin
{
	VDiskBackingChain value;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Disk

namespace Domain
{
namespace Xml
{
struct Disk
{
	Disk();

	const VDisk& getDisk() const
	{
		return m_disk;
	}
	void setDisk(const VDisk& value_)
	{
		m_disk = value_;
	}
	const boost::optional<ESnapshot >& getSnapshot() const
	{
		return m_snapshot;
	}
	void setSnapshot(const boost::optional<ESnapshot >& value_)
	{
		m_snapshot = value_;
	}
	const VDiskSource& getDiskSource() const
	{
		return m_diskSource;
	}
	void setDiskSource(const VDiskSource& value_)
	{
		m_diskSource = value_;
	}
	const boost::optional<Driver >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver >& value_)
	{
		m_driver = value_;
	}
	const boost::optional<Mirror >& getMirror() const
	{
		return m_mirror;
	}
	void setMirror(const boost::optional<Mirror >& value_)
	{
		m_mirror = value_;
	}
	const boost::optional<Auth >& getAuth() const
	{
		return m_auth;
	}
	void setAuth(const boost::optional<Auth >& value_)
	{
		m_auth = value_;
	}
	const Target& getTarget() const
	{
		return m_target;
	}
	void setTarget(const Target& value_)
	{
		m_target = value_;
	}
	const boost::optional<Boot >& getBoot() const
	{
		return m_boot;
	}
	void setBoot(const boost::optional<Boot >& value_)
	{
		m_boot = value_;
	}
	const boost::optional<PObjectNameWithSlash::value_type >& getBackenddomain() const
	{
		return m_backenddomain;
	}
	void setBackenddomain(const boost::optional<PObjectNameWithSlash::value_type >& value_)
	{
		m_backenddomain = value_;
	}
	bool getReadonly() const
	{
		return m_readonly;
	}
	void setReadonly(bool value_)
	{
		m_readonly = value_;
	}
	bool getShareable() const
	{
		return m_shareable;
	}
	void setShareable(bool value_)
	{
		m_shareable = value_;
	}
	const boost::optional<Transient >& getTransient() const
	{
		return m_transient;
	}
	void setTransient(const boost::optional<Transient >& value_)
	{
		m_transient = value_;
	}
	const boost::optional<PDiskSerial::value_type >& getSerial() const
	{
		return m_serial;
	}
	void setSerial(const boost::optional<PDiskSerial::value_type >& value_)
	{
		m_serial = value_;
	}
	const boost::optional<Encryption >& getEncryption() const
	{
		return m_encryption;
	}
	void setEncryption(const boost::optional<Encryption >& value_)
	{
		m_encryption = value_;
	}
	const boost::optional<Iotune >& getIotune() const
	{
		return m_iotune;
	}
	void setIotune(const boost::optional<Iotune >& value_)
	{
		m_iotune = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<Geometry >& getGeometry() const
	{
		return m_geometry;
	}
	void setGeometry(const boost::optional<Geometry >& value_)
	{
		m_geometry = value_;
	}
	const boost::optional<Blockio >& getBlockio() const
	{
		return m_blockio;
	}
	void setBlockio(const boost::optional<Blockio >& value_)
	{
		m_blockio = value_;
	}
	const boost::optional<PWwn::value_type >& getWwn() const
	{
		return m_wwn;
	}
	void setWwn(const boost::optional<PWwn::value_type >& value_)
	{
		m_wwn = value_;
	}
	const boost::optional<PVendor::value_type >& getVendor() const
	{
		return m_vendor;
	}
	void setVendor(const boost::optional<PVendor::value_type >& value_)
	{
		m_vendor = value_;
	}
	const boost::optional<PProduct::value_type >& getProduct() const
	{
		return m_product;
	}
	void setProduct(const boost::optional<PProduct::value_type >& value_)
	{
		m_product = value_;
	}
	const QList<QString >& getXCheckpointList() const
	{
		return m_xCheckpointList;
	}
	void setXCheckpointList(const QList<QString >& value_)
	{
		m_xCheckpointList = value_;
	}
	const VDiskBackingChain& getDiskBackingChain() const
	{
		return m_diskBackingChain;
	}
	void setDiskBackingChain(const VDiskBackingChain& value_)
	{
		m_diskBackingChain = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VDisk m_disk;
	boost::optional<ESnapshot > m_snapshot;
	VDiskSource m_diskSource;
	boost::optional<Driver > m_driver;
	boost::optional<Mirror > m_mirror;
	boost::optional<Auth > m_auth;
	Target m_target;
	boost::optional<Boot > m_boot;
	boost::optional<PObjectNameWithSlash::value_type > m_backenddomain;
	bool m_readonly;
	bool m_shareable;
	boost::optional<Transient > m_transient;
	boost::optional<PDiskSerial::value_type > m_serial;
	boost::optional<Encryption > m_encryption;
	boost::optional<Iotune > m_iotune;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<VAddress > m_address;
	boost::optional<Geometry > m_geometry;
	boost::optional<Blockio > m_blockio;
	boost::optional<PWwn::value_type > m_wwn;
	boost::optional<PVendor::value_type > m_vendor;
	boost::optional<PProduct::value_type > m_product;
	QList<QString > m_xCheckpointList;
	VDiskBackingChain m_diskBackingChain;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Acpi

namespace Domain
{
namespace Xml
{
struct Acpi
{
	const boost::optional<PUnsignedInt::value_type >& getIndex() const
	{
		return m_index;
	}
	void setIndex(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_index = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PUnsignedInt::value_type > m_index;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Variant5121

namespace Domain
{
namespace Xml
{
struct Variant5121
{
	const boost::optional<EModel1 >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<EModel1 >& value_)
	{
		m_model = value_;
	}
	const boost::optional<PUsbPort::value_type >& getMaster() const
	{
		return m_master;
	}
	void setMaster(const boost::optional<PUsbPort::value_type >& value_)
	{
		m_master = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getPorts() const
	{
		return m_ports;
	}
	void setPorts(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_ports = value_;
	}

private:
	boost::optional<EModel1 > m_model;
	boost::optional<PUsbPort::value_type > m_master;
	boost::optional<PUnsignedInt::value_type > m_ports;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Variant7013

namespace Domain
{
namespace Xml
{
struct Variant7013
{
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Target1

namespace Domain
{
namespace Xml
{
struct Target1
{
	const boost::optional<VUint8 >& getChassisNr() const
	{
		return m_chassisNr;
	}
	void setChassisNr(const boost::optional<VUint8 >& value_)
	{
		m_chassisNr = value_;
	}
	const boost::optional<VUint8 >& getChassis() const
	{
		return m_chassis;
	}
	void setChassis(const boost::optional<VUint8 >& value_)
	{
		m_chassis = value_;
	}
	const boost::optional<VUint8 >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<VUint8 >& value_)
	{
		m_port = value_;
	}
	const boost::optional<VUint8 >& getBusNr() const
	{
		return m_busNr;
	}
	void setBusNr(const boost::optional<VUint8 >& value_)
	{
		m_busNr = value_;
	}
	const boost::optional<VUint8 >& getIndex() const
	{
		return m_index;
	}
	void setIndex(const boost::optional<VUint8 >& value_)
	{
		m_index = value_;
	}
	const boost::optional<EVirOnOff >& getHotplug() const
	{
		return m_hotplug;
	}
	void setHotplug(const boost::optional<EVirOnOff >& value_)
	{
		m_hotplug = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getNode() const
	{
		return m_node;
	}
	void setNode(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_node = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<VUint8 > m_chassisNr;
	boost::optional<VUint8 > m_chassis;
	boost::optional<VUint8 > m_port;
	boost::optional<VUint8 > m_busNr;
	boost::optional<VUint8 > m_index;
	boost::optional<EVirOnOff > m_hotplug;
	boost::optional<PUnsignedInt::value_type > m_node;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Variant7014

namespace Domain
{
namespace Xml
{
struct Variant7014
{
	Variant7014();

	EModel3 getModel() const
	{
		return m_model;
	}
	void setModel(EModel3 value_)
	{
		m_model = value_;
	}
	const boost::optional<ScaledInteger >& getPcihole64() const
	{
		return m_pcihole64;
	}
	void setPcihole64(const boost::optional<ScaledInteger >& value_)
	{
		m_pcihole64 = value_;
	}

private:
	EModel3 m_model;
	boost::optional<ScaledInteger > m_pcihole64;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice2355

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Variant7014, Attribute<Domain::Xml::EModel4, Name::Strict<231> > > > VChoice2355Impl;
typedef VChoice2355Impl::value_type VChoice2355;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Variant8014

namespace Domain
{
namespace Xml
{
struct Variant8014
{
	const boost::optional<EName4 >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<EName4 >& value_)
	{
		m_model = value_;
	}
	const boost::optional<Target1 >& getTarget() const
	{
		return m_target;
	}
	void setTarget(const boost::optional<Target1 >& value_)
	{
		m_target = value_;
	}
	const VChoice2355& getChoice2355() const
	{
		return m_choice2355;
	}
	void setChoice2355(const VChoice2355& value_)
	{
		m_choice2355 = value_;
	}

private:
	boost::optional<EName4 > m_model;
	boost::optional<Target1 > m_target;
	VChoice2355 m_choice2355;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Variant9522

namespace Domain
{
namespace Xml
{
struct Variant9522
{
	const boost::optional<EModel5 >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<EModel5 >& value_)
	{
		m_model = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getPorts() const
	{
		return m_ports;
	}
	void setPorts(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_ports = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getVectors() const
	{
		return m_vectors;
	}
	void setVectors(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_vectors = value_;
	}

private:
	boost::optional<EModel5 > m_model;
	boost::optional<PUnsignedInt::value_type > m_ports;
	boost::optional<PUnsignedInt::value_type > m_vectors;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Variant8018

namespace Domain
{
namespace Xml
{
struct Variant8018
{
	const boost::optional<PUnsignedInt::value_type >& getMaxGrantFrames() const
	{
		return m_maxGrantFrames;
	}
	void setMaxGrantFrames(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_maxGrantFrames = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getMaxEventChannels() const
	{
		return m_maxEventChannels;
	}
	void setMaxEventChannels(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_maxEventChannels = value_;
	}

private:
	boost::optional<PUnsignedInt::value_type > m_maxGrantFrames;
	boost::optional<PUnsignedInt::value_type > m_maxEventChannels;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice5123

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Attribute<Domain::Xml::EType9, Name::Strict<105> >, Ordered<mpl::vector<Attribute<mpl::int_<529>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::EModel, Name::Strict<231> > > > >, Variant5121, Ordered<mpl::vector<Attribute<mpl::int_<527>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::EModel2, Name::Strict<231> > > > >, Variant7013, Variant8014, Variant9522, Variant8018 > > VChoice5123Impl;
typedef VChoice5123Impl::value_type VChoice5123;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Driver1

namespace Domain
{
namespace Xml
{
struct Driver1
{
	const boost::optional<PUnsignedInt::value_type >& getQueues() const
	{
		return m_queues;
	}
	void setQueues(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_queues = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getCmdPerLun() const
	{
		return m_cmdPerLun;
	}
	void setCmdPerLun(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_cmdPerLun = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getMaxSectors() const
	{
		return m_maxSectors;
	}
	void setMaxSectors(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_maxSectors = value_;
	}
	const boost::optional<EVirOnOff >& getIoeventfd() const
	{
		return m_ioeventfd;
	}
	void setIoeventfd(const boost::optional<EVirOnOff >& value_)
	{
		m_ioeventfd = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getIothread() const
	{
		return m_iothread;
	}
	void setIothread(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_iothread = value_;
	}
	const VirtioOptions& getVirtioOptions() const
	{
		return m_virtioOptions;
	}
	void setVirtioOptions(const VirtioOptions& value_)
	{
		m_virtioOptions = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PUnsignedInt::value_type > m_queues;
	boost::optional<PUnsignedInt::value_type > m_cmdPerLun;
	boost::optional<PUnsignedInt::value_type > m_maxSectors;
	boost::optional<EVirOnOff > m_ioeventfd;
	boost::optional<PUnsignedInt::value_type > m_iothread;
	VirtioOptions m_virtioOptions;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Controller

namespace Domain
{
namespace Xml
{
struct Controller
{
	const boost::optional<PUnsignedInt::value_type >& getIndex() const
	{
		return m_index;
	}
	void setIndex(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_index = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const VChoice5123& getChoice5123() const
	{
		return m_choice5123;
	}
	void setChoice5123(const VChoice5123& value_)
	{
		m_choice5123 = value_;
	}
	const boost::optional<Driver1 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver1 >& value_)
	{
		m_driver = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PUnsignedInt::value_type > m_index;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
	VChoice5123 m_choice5123;
	boost::optional<Driver1 > m_driver;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Target2

namespace Domain
{
namespace Xml
{
struct Target2
{
	const QString& getPath() const
	{
		return m_path;
	}
	void setPath(const QString& value_)
	{
		m_path = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getOffset() const
	{
		return m_offset;
	}
	void setOffset(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_offset = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	QString m_path;
	boost::optional<PUnsignedInt::value_type > m_offset;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Lease

namespace Domain
{
namespace Xml
{
struct Lease
{
	const QString& getLockspace() const
	{
		return m_lockspace;
	}
	void setLockspace(const QString& value_)
	{
		m_lockspace = value_;
	}
	const QString& getKey() const
	{
		return m_key;
	}
	void setKey(const QString& value_)
	{
		m_key = value_;
	}
	const Target2& getTarget() const
	{
		return m_target;
	}
	void setTarget(const Target2& value_)
	{
		m_target = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	QString m_lockspace;
	QString m_key;
	Target2 m_target;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Driver2

namespace Domain
{
namespace Xml
{
struct Driver2
{
	const boost::optional<EType10 >& getType() const
	{
		return m_type;
	}
	void setType(const boost::optional<EType10 >& value_)
	{
		m_type = value_;
	}
	const boost::optional<VStorageFormat >& getFormat() const
	{
		return m_format;
	}
	void setFormat(const boost::optional<VStorageFormat >& value_)
	{
		m_format = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EType10 > m_type;
	boost::optional<VStorageFormat > m_format;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7016

namespace Domain
{
namespace Xml
{
struct Filesystem7016
{
	const boost::optional<Driver2 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver2 >& value_)
	{
		m_driver = value_;
	}
	const PAbsFilePath::value_type& getSource() const
	{
		return m_source;
	}
	void setSource(const PAbsFilePath::value_type& value_)
	{
		m_source = value_;
	}

private:
	boost::optional<Driver2 > m_driver;
	PAbsFilePath::value_type m_source;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7017

namespace Domain
{
namespace Xml
{
struct Filesystem7017
{
	const boost::optional<Driver2 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver2 >& value_)
	{
		m_driver = value_;
	}
	const PAbsFilePath::value_type& getSource() const
	{
		return m_source;
	}
	void setSource(const PAbsFilePath::value_type& value_)
	{
		m_source = value_;
	}

private:
	boost::optional<Driver2 > m_driver;
	PAbsFilePath::value_type m_source;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7018

namespace Domain
{
namespace Xml
{
struct Filesystem7018
{
	const boost::optional<Driver2 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver2 >& value_)
	{
		m_driver = value_;
	}
	const PAbsDirPath::value_type& getSource() const
	{
		return m_source;
	}
	void setSource(const PAbsDirPath::value_type& value_)
	{
		m_source = value_;
	}

private:
	boost::optional<Driver2 > m_driver;
	PAbsDirPath::value_type m_source;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7019

namespace Domain
{
namespace Xml
{
struct Filesystem7019
{
	const boost::optional<Driver2 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver2 >& value_)
	{
		m_driver = value_;
	}
	const PAbsDirPath::value_type& getSource() const
	{
		return m_source;
	}
	void setSource(const PAbsDirPath::value_type& value_)
	{
		m_source = value_;
	}

private:
	boost::optional<Driver2 > m_driver;
	PAbsDirPath::value_type m_source;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7020

namespace Domain
{
namespace Xml
{
struct Filesystem7020
{
	const boost::optional<Driver2 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver2 >& value_)
	{
		m_driver = value_;
	}
	const PGenericName::value_type& getSource() const
	{
		return m_source;
	}
	void setSource(const PGenericName::value_type& value_)
	{
		m_source = value_;
	}

private:
	boost::optional<Driver2 > m_driver;
	PGenericName::value_type m_source;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source5

namespace Domain
{
namespace Xml
{
struct Source5
{
	Source5();

	PUnsignedLong::value_type getUsage() const
	{
		return m_usage;
	}
	void setUsage(PUnsignedLong::value_type value_)
	{
		m_usage = value_;
	}
	const boost::optional<PUnit::value_type >& getUnits() const
	{
		return m_units;
	}
	void setUnits(const boost::optional<PUnit::value_type >& value_)
	{
		m_units = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedLong::value_type m_usage;
	boost::optional<PUnit::value_type > m_units;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7021

namespace Domain
{
namespace Xml
{
struct Filesystem7021
{
	const boost::optional<Driver2 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver2 >& value_)
	{
		m_driver = value_;
	}
	const Source5& getSource() const
	{
		return m_source;
	}
	void setSource(const Source5& value_)
	{
		m_source = value_;
	}

private:
	boost::optional<Driver2 > m_driver;
	Source5 m_source;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VFilesystem

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Filesystem7016, Filesystem7017, Filesystem7018, Filesystem7019, Filesystem7020, Filesystem7021 > > VFilesystemImpl;
typedef VFilesystemImpl::value_type VFilesystem;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem

namespace Domain
{
namespace Xml
{
struct Filesystem
{
	Filesystem();

	const VFilesystem& getFilesystem() const
	{
		return m_filesystem;
	}
	void setFilesystem(const VFilesystem& value_)
	{
		m_filesystem = value_;
	}
	const PAbsDirPath::value_type& getTarget() const
	{
		return m_target;
	}
	void setTarget(const PAbsDirPath::value_type& value_)
	{
		m_target = value_;
	}
	const boost::optional<EAccessmode >& getAccessmode() const
	{
		return m_accessmode;
	}
	void setAccessmode(const boost::optional<EAccessmode >& value_)
	{
		m_accessmode = value_;
	}
	const boost::optional<EMultidevs >& getMultidevs() const
	{
		return m_multidevs;
	}
	void setMultidevs(const boost::optional<EMultidevs >& value_)
	{
		m_multidevs = value_;
	}
	const boost::optional<PCreateMode::value_type >& getFmode() const
	{
		return m_fmode;
	}
	void setFmode(const boost::optional<PCreateMode::value_type >& value_)
	{
		m_fmode = value_;
	}
	const boost::optional<PCreateMode::value_type >& getDmode() const
	{
		return m_dmode;
	}
	void setDmode(const boost::optional<PCreateMode::value_type >& value_)
	{
		m_dmode = value_;
	}
	bool getReadonly() const
	{
		return m_readonly;
	}
	void setReadonly(bool value_)
	{
		m_readonly = value_;
	}
	const boost::optional<Boot >& getBoot() const
	{
		return m_boot;
	}
	void setBoot(const boost::optional<Boot >& value_)
	{
		m_boot = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<ScaledInteger >& getSpaceHardLimit() const
	{
		return m_spaceHardLimit;
	}
	void setSpaceHardLimit(const boost::optional<ScaledInteger >& value_)
	{
		m_spaceHardLimit = value_;
	}
	const boost::optional<ScaledInteger >& getSpaceSoftLimit() const
	{
		return m_spaceSoftLimit;
	}
	void setSpaceSoftLimit(const boost::optional<ScaledInteger >& value_)
	{
		m_spaceSoftLimit = value_;
	}
	const boost::optional<EModel6 >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<EModel6 >& value_)
	{
		m_model = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VFilesystem m_filesystem;
	PAbsDirPath::value_type m_target;
	boost::optional<EAccessmode > m_accessmode;
	boost::optional<EMultidevs > m_multidevs;
	boost::optional<PCreateMode::value_type > m_fmode;
	boost::optional<PCreateMode::value_type > m_dmode;
	bool m_readonly;
	boost::optional<Boot > m_boot;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
	boost::optional<ScaledInteger > m_spaceHardLimit;
	boost::optional<ScaledInteger > m_spaceSoftLimit;
	boost::optional<EModel6 > m_model;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct InterfaceBridgeAttributes

namespace Domain
{
namespace Xml
{
struct InterfaceBridgeAttributes
{
	const PDeviceName::value_type& getBridge() const
	{
		return m_bridge;
	}
	void setBridge(const PDeviceName::value_type& value_)
	{
		m_bridge = value_;
	}
	const boost::optional<EMacTableManager >& getMacTableManager() const
	{
		return m_macTableManager;
	}
	void setMacTableManager(const boost::optional<EMacTableManager >& value_)
	{
		m_macTableManager = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	PDeviceName::value_type m_bridge;
	boost::optional<EMacTableManager > m_macTableManager;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct InterfaceNetworkAttributes

namespace Domain
{
namespace Xml
{
struct InterfaceNetworkAttributes
{
	const QString& getNetwork() const
	{
		return m_network;
	}
	void setNetwork(const QString& value_)
	{
		m_network = value_;
	}
	const boost::optional<PDeviceName::value_type >& getPortgroup() const
	{
		return m_portgroup;
	}
	void setPortgroup(const boost::optional<PDeviceName::value_type >& value_)
	{
		m_portgroup = value_;
	}
	const boost::optional<VUUID >& getPortid() const
	{
		return m_portid;
	}
	void setPortid(const boost::optional<VUUID >& value_)
	{
		m_portid = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	QString m_network;
	boost::optional<PDeviceName::value_type > m_portgroup;
	boost::optional<VUUID > m_portid;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source6

namespace Domain
{
namespace Xml
{
struct Source6
{
	const InterfaceBridgeAttributes& getInterfaceBridgeAttributes() const
	{
		return m_interfaceBridgeAttributes;
	}
	void setInterfaceBridgeAttributes(const InterfaceBridgeAttributes& value_)
	{
		m_interfaceBridgeAttributes = value_;
	}
	const boost::optional<InterfaceNetworkAttributes >& getInterfaceNetworkAttributes() const
	{
		return m_interfaceNetworkAttributes;
	}
	void setInterfaceNetworkAttributes(const boost::optional<InterfaceNetworkAttributes >& value_)
	{
		m_interfaceNetworkAttributes = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	InterfaceBridgeAttributes m_interfaceBridgeAttributes;
	boost::optional<InterfaceNetworkAttributes > m_interfaceNetworkAttributes;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Parameters

namespace Domain
{
namespace Xml
{
struct Parameters
{
	const boost::optional<VUint8 >& getManagerid() const
	{
		return m_managerid;
	}
	void setManagerid(const boost::optional<VUint8 >& value_)
	{
		m_managerid = value_;
	}
	const boost::optional<VUint24 >& getTypeid() const
	{
		return m_typeid;
	}
	void setTypeid(const boost::optional<VUint24 >& value_)
	{
		m_typeid = value_;
	}
	const boost::optional<VUint8 >& getTypeidversion() const
	{
		return m_typeidversion;
	}
	void setTypeidversion(const boost::optional<VUint8 >& value_)
	{
		m_typeidversion = value_;
	}
	const boost::optional<VUUID >& getInstanceid() const
	{
		return m_instanceid;
	}
	void setInstanceid(const boost::optional<VUUID >& value_)
	{
		m_instanceid = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<VUint8 > m_managerid;
	boost::optional<VUint24 > m_typeid;
	boost::optional<VUint8 > m_typeidversion;
	boost::optional<VUUID > m_instanceid;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Parameters1

namespace Domain
{
namespace Xml
{
struct Parameters1
{
	const boost::optional<PVirtualPortProfileID::value_type >& getProfileid() const
	{
		return m_profileid;
	}
	void setProfileid(const boost::optional<PVirtualPortProfileID::value_type >& value_)
	{
		m_profileid = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PVirtualPortProfileID::value_type > m_profileid;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Parameters2

namespace Domain
{
namespace Xml
{
struct Parameters2
{
	const boost::optional<PVirtualPortProfileID::value_type >& getProfileid() const
	{
		return m_profileid;
	}
	void setProfileid(const boost::optional<PVirtualPortProfileID::value_type >& value_)
	{
		m_profileid = value_;
	}
	const boost::optional<VUUID >& getInterfaceid() const
	{
		return m_interfaceid;
	}
	void setInterfaceid(const boost::optional<VUUID >& value_)
	{
		m_interfaceid = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PVirtualPortProfileID::value_type > m_profileid;
	boost::optional<VUUID > m_interfaceid;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Parameters3

namespace Domain
{
namespace Xml
{
struct Parameters3
{
	const boost::optional<VUint8 >& getManagerid() const
	{
		return m_managerid;
	}
	void setManagerid(const boost::optional<VUint8 >& value_)
	{
		m_managerid = value_;
	}
	const boost::optional<VUint24 >& getTypeid() const
	{
		return m_typeid;
	}
	void setTypeid(const boost::optional<VUint24 >& value_)
	{
		m_typeid = value_;
	}
	const boost::optional<VUint8 >& getTypeidversion() const
	{
		return m_typeidversion;
	}
	void setTypeidversion(const boost::optional<VUint8 >& value_)
	{
		m_typeidversion = value_;
	}
	const boost::optional<VUUID >& getInstanceid() const
	{
		return m_instanceid;
	}
	void setInstanceid(const boost::optional<VUUID >& value_)
	{
		m_instanceid = value_;
	}
	const boost::optional<PVirtualPortProfileID::value_type >& getProfileid() const
	{
		return m_profileid;
	}
	void setProfileid(const boost::optional<PVirtualPortProfileID::value_type >& value_)
	{
		m_profileid = value_;
	}
	const boost::optional<VUUID >& getInterfaceid() const
	{
		return m_interfaceid;
	}
	void setInterfaceid(const boost::optional<VUUID >& value_)
	{
		m_interfaceid = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<VUint8 > m_managerid;
	boost::optional<VUint24 > m_typeid;
	boost::optional<VUint8 > m_typeidversion;
	boost::optional<VUUID > m_instanceid;
	boost::optional<PVirtualPortProfileID::value_type > m_profileid;
	boost::optional<VUUID > m_interfaceid;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Virtualport

namespace Domain
{
namespace Xml
{
struct Virtualport
{
	const boost::optional<Parameters3 >& getParameters() const
	{
		return m_parameters;
	}
	void setParameters(const boost::optional<Parameters3 >& value_)
	{
		m_parameters = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<Parameters3 > m_parameters;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VVirtualPortProfile

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Element<Ordered<mpl::vector<Attribute<mpl::int_<179>, Name::Strict<105> >, Optional<Element<Domain::Xml::Parameters, Name::Strict<180> > > > >, Name::Strict<178> >, Element<Ordered<mpl::vector<Attribute<mpl::int_<186>, Name::Strict<105> >, Optional<Element<Domain::Xml::Parameters1, Name::Strict<180> > > > >, Name::Strict<178> >, Element<Ordered<mpl::vector<Attribute<mpl::int_<189>, Name::Strict<105> >, Optional<Element<Domain::Xml::Parameters2, Name::Strict<180> > > > >, Name::Strict<178> >, Element<Ordered<mpl::vector<Attribute<mpl::int_<5772>, Name::Strict<105> >, Element<Attribute<Domain::Xml::VUUID, Name::Strict<190> >, Name::Strict<180> > > >, Name::Strict<178> >, Element<Domain::Xml::Virtualport, Name::Strict<178> > > > VVirtualPortProfileImpl;
typedef VVirtualPortProfileImpl::value_type VVirtualPortProfile;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Frames

namespace Domain
{
namespace Xml
{
struct Frames
{
	const boost::optional<PUnsignedInt::value_type >& getMax() const
	{
		return m_max;
	}
	void setMax(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_max = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PUnsignedInt::value_type > m_max;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Rx

namespace Domain
{
namespace Xml
{
struct Rx
{
	const boost::optional<Frames >& getFrames() const
	{
		return m_frames;
	}
	void setFrames(const boost::optional<Frames >& value_)
	{
		m_frames = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<Frames > m_frames;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Coalesce

namespace Domain
{
namespace Xml
{
struct Coalesce
{
	const boost::optional<Rx >& getRx() const
	{
		return m_rx;
	}
	void setRx(const boost::optional<Rx >& value_)
	{
		m_rx = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<Rx > m_rx;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VzDhcp

namespace Domain
{
namespace Xml
{
struct VzDhcp
{
	const boost::optional<PAddrFamily::value_type >& getFamily() const
	{
		return m_family;
	}
	void setFamily(const boost::optional<PAddrFamily::value_type >& value_)
	{
		m_family = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PAddrFamily::value_type > m_family;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VzDns1

namespace Domain
{
namespace Xml
{
struct VzDns1
{
	const QList<VIpAddr >& getServerList() const
	{
		return m_serverList;
	}
	void setServerList(const QList<VIpAddr >& value_)
	{
		m_serverList = value_;
	}
	const QList<PDnsName::value_type >& getSearchList() const
	{
		return m_searchList;
	}
	void setSearchList(const QList<PDnsName::value_type >& value_)
	{
		m_searchList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	QList<VIpAddr > m_serverList;
	QList<PDnsName::value_type > m_searchList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Target3

namespace Domain
{
namespace Xml
{
struct Target3
{
	const PDeviceName::value_type& getDev() const
	{
		return m_dev;
	}
	void setDev(const PDeviceName::value_type& value_)
	{
		m_dev = value_;
	}
	const boost::optional<EVirYesNo >& getManaged() const
	{
		return m_managed;
	}
	void setManaged(const boost::optional<EVirYesNo >& value_)
	{
		m_managed = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PDeviceName::value_type m_dev;
	boost::optional<EVirYesNo > m_managed;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Guest

namespace Domain
{
namespace Xml
{
struct Guest
{
	const boost::optional<PDeviceName::value_type >& getDev() const
	{
		return m_dev;
	}
	void setDev(const boost::optional<PDeviceName::value_type >& value_)
	{
		m_dev = value_;
	}
	const boost::optional<PDeviceName::value_type >& getActual() const
	{
		return m_actual;
	}
	void setActual(const boost::optional<PDeviceName::value_type >& value_)
	{
		m_actual = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PDeviceName::value_type > m_dev;
	boost::optional<PDeviceName::value_type > m_actual;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Ip

namespace Domain
{
namespace Xml
{
struct Ip
{
	const VIpAddr& getAddress() const
	{
		return m_address;
	}
	void setAddress(const VIpAddr& value_)
	{
		m_address = value_;
	}
	const boost::optional<PAddrFamily::value_type >& getFamily() const
	{
		return m_family;
	}
	void setFamily(const boost::optional<PAddrFamily::value_type >& value_)
	{
		m_family = value_;
	}
	const boost::optional<VIpPrefix >& getPrefix() const
	{
		return m_prefix;
	}
	void setPrefix(const boost::optional<VIpPrefix >& value_)
	{
		m_prefix = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VIpAddr m_address;
	boost::optional<PAddrFamily::value_type > m_family;
	boost::optional<VIpPrefix > m_prefix;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice7116

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Attribute<Domain::Xml::PIpv4Addr, Name::Strict<1245> >, Attribute<Domain::Xml::VIpPrefix, Name::Strict<691> > > > VChoice7116Impl;
typedef VChoice7116Impl::value_type VChoice7116;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Route

namespace Domain
{
namespace Xml
{
struct Route
{
	const boost::optional<PAddrFamily::value_type >& getFamily() const
	{
		return m_family;
	}
	void setFamily(const boost::optional<PAddrFamily::value_type >& value_)
	{
		m_family = value_;
	}
	const VIpAddr& getAddress() const
	{
		return m_address;
	}
	void setAddress(const VIpAddr& value_)
	{
		m_address = value_;
	}
	const boost::optional<VChoice7116 >& getChoice7116() const
	{
		return m_choice7116;
	}
	void setChoice7116(const boost::optional<VChoice7116 >& value_)
	{
		m_choice7116 = value_;
	}
	const VIpAddr& getGateway() const
	{
		return m_gateway;
	}
	void setGateway(const VIpAddr& value_)
	{
		m_gateway = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getMetric() const
	{
		return m_metric;
	}
	void setMetric(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_metric = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PAddrFamily::value_type > m_family;
	VIpAddr m_address;
	boost::optional<VChoice7116 > m_choice7116;
	VIpAddr m_gateway;
	boost::optional<PUnsignedInt::value_type > m_metric;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Backend

namespace Domain
{
namespace Xml
{
struct Backend
{
	const boost::optional<PAbsFilePath::value_type >& getTap() const
	{
		return m_tap;
	}
	void setTap(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_tap = value_;
	}
	const boost::optional<PAbsFilePath::value_type >& getVhost() const
	{
		return m_vhost;
	}
	void setVhost(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_vhost = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PAbsFilePath::value_type > m_tap;
	boost::optional<PAbsFilePath::value_type > m_vhost;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Driver7037

namespace Domain
{
namespace Xml
{
struct Driver7037
{
	const boost::optional<EName6 >& getName() const
	{
		return m_name;
	}
	void setName(const boost::optional<EName6 >& value_)
	{
		m_name = value_;
	}
	const boost::optional<PPositiveInteger::value_type >& getQueues() const
	{
		return m_queues;
	}
	void setQueues(const boost::optional<PPositiveInteger::value_type >& value_)
	{
		m_queues = value_;
	}
	const boost::optional<PPositiveInteger::value_type >& getRxQueueSize() const
	{
		return m_rxQueueSize;
	}
	void setRxQueueSize(const boost::optional<PPositiveInteger::value_type >& value_)
	{
		m_rxQueueSize = value_;
	}
	const boost::optional<PPositiveInteger::value_type >& getTxQueueSize() const
	{
		return m_txQueueSize;
	}
	void setTxQueueSize(const boost::optional<PPositiveInteger::value_type >& value_)
	{
		m_txQueueSize = value_;
	}
	const boost::optional<ETxmode >& getTxmode() const
	{
		return m_txmode;
	}
	void setTxmode(const boost::optional<ETxmode >& value_)
	{
		m_txmode = value_;
	}
	const boost::optional<EVirOnOff >& getIoeventfd() const
	{
		return m_ioeventfd;
	}
	void setIoeventfd(const boost::optional<EVirOnOff >& value_)
	{
		m_ioeventfd = value_;
	}
	const boost::optional<EVirOnOff >& getEventIdx() const
	{
		return m_eventIdx;
	}
	void setEventIdx(const boost::optional<EVirOnOff >& value_)
	{
		m_eventIdx = value_;
	}

private:
	boost::optional<EName6 > m_name;
	boost::optional<PPositiveInteger::value_type > m_queues;
	boost::optional<PPositiveInteger::value_type > m_rxQueueSize;
	boost::optional<PPositiveInteger::value_type > m_txQueueSize;
	boost::optional<ETxmode > m_txmode;
	boost::optional<EVirOnOff > m_ioeventfd;
	boost::optional<EVirOnOff > m_eventIdx;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VDriver

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Attribute<Domain::Xml::EName5, Name::Strict<107> >, Driver7037 > > VDriverImpl;
typedef VDriverImpl::value_type VDriver;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Host

namespace Domain
{
namespace Xml
{
struct Host
{
	const boost::optional<EVirOnOff >& getCsum() const
	{
		return m_csum;
	}
	void setCsum(const boost::optional<EVirOnOff >& value_)
	{
		m_csum = value_;
	}
	const boost::optional<EVirOnOff >& getGso() const
	{
		return m_gso;
	}
	void setGso(const boost::optional<EVirOnOff >& value_)
	{
		m_gso = value_;
	}
	const boost::optional<EVirOnOff >& getTso4() const
	{
		return m_tso4;
	}
	void setTso4(const boost::optional<EVirOnOff >& value_)
	{
		m_tso4 = value_;
	}
	const boost::optional<EVirOnOff >& getTso6() const
	{
		return m_tso6;
	}
	void setTso6(const boost::optional<EVirOnOff >& value_)
	{
		m_tso6 = value_;
	}
	const boost::optional<EVirOnOff >& getEcn() const
	{
		return m_ecn;
	}
	void setEcn(const boost::optional<EVirOnOff >& value_)
	{
		m_ecn = value_;
	}
	const boost::optional<EVirOnOff >& getUfo() const
	{
		return m_ufo;
	}
	void setUfo(const boost::optional<EVirOnOff >& value_)
	{
		m_ufo = value_;
	}
	const boost::optional<EVirOnOff >& getMrgRxbuf() const
	{
		return m_mrgRxbuf;
	}
	void setMrgRxbuf(const boost::optional<EVirOnOff >& value_)
	{
		m_mrgRxbuf = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirOnOff > m_csum;
	boost::optional<EVirOnOff > m_gso;
	boost::optional<EVirOnOff > m_tso4;
	boost::optional<EVirOnOff > m_tso6;
	boost::optional<EVirOnOff > m_ecn;
	boost::optional<EVirOnOff > m_ufo;
	boost::optional<EVirOnOff > m_mrgRxbuf;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Guest1

namespace Domain
{
namespace Xml
{
struct Guest1
{
	const boost::optional<EVirOnOff >& getCsum() const
	{
		return m_csum;
	}
	void setCsum(const boost::optional<EVirOnOff >& value_)
	{
		m_csum = value_;
	}
	const boost::optional<EVirOnOff >& getTso4() const
	{
		return m_tso4;
	}
	void setTso4(const boost::optional<EVirOnOff >& value_)
	{
		m_tso4 = value_;
	}
	const boost::optional<EVirOnOff >& getTso6() const
	{
		return m_tso6;
	}
	void setTso6(const boost::optional<EVirOnOff >& value_)
	{
		m_tso6 = value_;
	}
	const boost::optional<EVirOnOff >& getEcn() const
	{
		return m_ecn;
	}
	void setEcn(const boost::optional<EVirOnOff >& value_)
	{
		m_ecn = value_;
	}
	const boost::optional<EVirOnOff >& getUfo() const
	{
		return m_ufo;
	}
	void setUfo(const boost::optional<EVirOnOff >& value_)
	{
		m_ufo = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirOnOff > m_csum;
	boost::optional<EVirOnOff > m_tso4;
	boost::optional<EVirOnOff > m_tso6;
	boost::optional<EVirOnOff > m_ecn;
	boost::optional<EVirOnOff > m_ufo;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Driver3

namespace Domain
{
namespace Xml
{
struct Driver3
{
	const VDriver& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const VDriver& value_)
	{
		m_driver = value_;
	}
	const boost::optional<Host >& getHost() const
	{
		return m_host;
	}
	void setHost(const boost::optional<Host >& value_)
	{
		m_host = value_;
	}
	const boost::optional<Guest1 >& getGuest() const
	{
		return m_guest;
	}
	void setGuest(const boost::optional<Guest1 >& value_)
	{
		m_guest = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VDriver m_driver;
	boost::optional<Host > m_host;
	boost::optional<Guest1 > m_guest;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Parameter

namespace Domain
{
namespace Xml
{
struct Parameter
{
	const PFilterParamName::value_type& getName() const
	{
		return m_name;
	}
	void setName(const PFilterParamName::value_type& value_)
	{
		m_name = value_;
	}
	const PFilterParamValue::value_type& getValue() const
	{
		return m_value;
	}
	void setValue(const PFilterParamValue::value_type& value_)
	{
		m_value = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PFilterParamName::value_type m_name;
	PFilterParamValue::value_type m_value;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct FilterrefNodeAttributes

namespace Domain
{
namespace Xml
{
struct FilterrefNodeAttributes
{
	const PFilter::value_type& getFilter() const
	{
		return m_filter;
	}
	void setFilter(const PFilter::value_type& value_)
	{
		m_filter = value_;
	}
	const QList<Parameter >& getParameterList() const
	{
		return m_parameterList;
	}
	void setParameterList(const QList<Parameter >& value_)
	{
		m_parameterList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PFilter::value_type m_filter;
	QList<Parameter > m_parameterList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Tune

namespace Domain
{
namespace Xml
{
struct Tune
{
	const boost::optional<PUnsignedInt::value_type >& getSndbuf() const
	{
		return m_sndbuf;
	}
	void setSndbuf(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_sndbuf = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PUnsignedInt::value_type > m_sndbuf;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Rom

namespace Domain
{
namespace Xml
{
struct Rom
{
	const boost::optional<EVirYesNo >& getEnabled() const
	{
		return m_enabled;
	}
	void setEnabled(const boost::optional<EVirYesNo >& value_)
	{
		m_enabled = value_;
	}
	const boost::optional<EVirOnOff >& getBar() const
	{
		return m_bar;
	}
	void setBar(const boost::optional<EVirOnOff >& value_)
	{
		m_bar = value_;
	}
	const boost::optional<PAbsFilePath::value_type >& getFile() const
	{
		return m_file;
	}
	void setFile(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_file = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirYesNo > m_enabled;
	boost::optional<EVirOnOff > m_bar;
	boost::optional<PAbsFilePath::value_type > m_file;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct BandwidthAttributes

namespace Domain
{
namespace Xml
{
struct BandwidthAttributes
{
	const boost::optional<PSpeed::value_type >& getAverage() const
	{
		return m_average;
	}
	void setAverage(const boost::optional<PSpeed::value_type >& value_)
	{
		m_average = value_;
	}
	const boost::optional<PSpeed::value_type >& getPeak() const
	{
		return m_peak;
	}
	void setPeak(const boost::optional<PSpeed::value_type >& value_)
	{
		m_peak = value_;
	}
	const boost::optional<PSpeed::value_type >& getFloor() const
	{
		return m_floor;
	}
	void setFloor(const boost::optional<PSpeed::value_type >& value_)
	{
		m_floor = value_;
	}
	const boost::optional<PBurstSize::value_type >& getBurst() const
	{
		return m_burst;
	}
	void setBurst(const boost::optional<PBurstSize::value_type >& value_)
	{
		m_burst = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PSpeed::value_type > m_average;
	boost::optional<PSpeed::value_type > m_peak;
	boost::optional<PSpeed::value_type > m_floor;
	boost::optional<PBurstSize::value_type > m_burst;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Bandwidth1

namespace Domain
{
namespace Xml
{
struct Bandwidth1
{
	const boost::optional<PPositiveInteger::value_type >& getClassID() const
	{
		return m_classID;
	}
	void setClassID(const boost::optional<PPositiveInteger::value_type >& value_)
	{
		m_classID = value_;
	}
	const boost::optional<BandwidthAttributes >& getInbound() const
	{
		return m_inbound;
	}
	void setInbound(const boost::optional<BandwidthAttributes >& value_)
	{
		m_inbound = value_;
	}
	const boost::optional<BandwidthAttributes >& getOutbound() const
	{
		return m_outbound;
	}
	void setOutbound(const boost::optional<BandwidthAttributes >& value_)
	{
		m_outbound = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PPositiveInteger::value_type > m_classID;
	boost::optional<BandwidthAttributes > m_inbound;
	boost::optional<BandwidthAttributes > m_outbound;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Tag

namespace Domain
{
namespace Xml
{
struct Tag
{
	Tag();

	PId::value_type getId() const
	{
		return m_id;
	}
	void setId(PId::value_type value_)
	{
		m_id = value_;
	}
	const boost::optional<ENativeMode >& getNativeMode() const
	{
		return m_nativeMode;
	}
	void setNativeMode(const boost::optional<ENativeMode >& value_)
	{
		m_nativeMode = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PId::value_type m_id;
	boost::optional<ENativeMode > m_nativeMode;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Port

namespace Domain
{
namespace Xml
{
struct Port
{
	const boost::optional<EVirYesNo >& getIsolated() const
	{
		return m_isolated;
	}
	void setIsolated(const boost::optional<EVirYesNo >& value_)
	{
		m_isolated = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirYesNo > m_isolated;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Teaming9388

namespace Domain
{
namespace Xml
{
struct Teaming9388
{
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VTeaming

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Teaming9388, Ordered<mpl::vector<Attribute<mpl::int_<452>, Name::Strict<105> >, Attribute<Domain::Xml::PAliasName, Name::Strict<9388> > > > > > VTeamingImpl;
typedef VTeamingImpl::value_type VTeaming;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Interface7022

namespace Domain
{
namespace Xml
{
struct Interface7022
{
	const boost::optional<Source6 >& getSource() const
	{
		return m_source;
	}
	void setSource(const boost::optional<Source6 >& value_)
	{
		m_source = value_;
	}
	const boost::optional<VVirtualPortProfile >& getVirtualPortProfile() const
	{
		return m_virtualPortProfile;
	}
	void setVirtualPortProfile(const boost::optional<VVirtualPortProfile >& value_)
	{
		m_virtualPortProfile = value_;
	}
	const boost::optional<EState >& getLink() const
	{
		return m_link;
	}
	void setLink(const boost::optional<EState >& value_)
	{
		m_link = value_;
	}
	const boost::optional<PUnsignedShort::value_type >& getMtu() const
	{
		return m_mtu;
	}
	void setMtu(const boost::optional<PUnsignedShort::value_type >& value_)
	{
		m_mtu = value_;
	}
	const boost::optional<Coalesce >& getCoalesce() const
	{
		return m_coalesce;
	}
	void setCoalesce(const boost::optional<Coalesce >& value_)
	{
		m_coalesce = value_;
	}
	const boost::optional<QList<VzDhcp > >& getVzDhcpList() const
	{
		return m_vzDhcpList;
	}
	void setVzDhcpList(const boost::optional<QList<VzDhcp > >& value_)
	{
		m_vzDhcpList = value_;
	}
	const boost::optional<VzDns1 >& getVzDns() const
	{
		return m_vzDns;
	}
	void setVzDns(const boost::optional<VzDns1 >& value_)
	{
		m_vzDns = value_;
	}
	const boost::optional<Target3 >& getTarget() const
	{
		return m_target;
	}
	void setTarget(const boost::optional<Target3 >& value_)
	{
		m_target = value_;
	}
	const boost::optional<Guest >& getGuest() const
	{
		return m_guest;
	}
	void setGuest(const boost::optional<Guest >& value_)
	{
		m_guest = value_;
	}
	const boost::optional<PUniMacAddr::value_type >& getMac() const
	{
		return m_mac;
	}
	void setMac(const boost::optional<PUniMacAddr::value_type >& value_)
	{
		m_mac = value_;
	}
	const QList<Ip >& getIpList() const
	{
		return m_ipList;
	}
	void setIpList(const QList<Ip >& value_)
	{
		m_ipList = value_;
	}
	const QList<Route >& getRouteList() const
	{
		return m_routeList;
	}
	void setRouteList(const QList<Route >& value_)
	{
		m_routeList = value_;
	}
	const boost::optional<PFilePath::value_type >& getScript() const
	{
		return m_script;
	}
	void setScript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_script = value_;
	}
	const boost::optional<PFilePath::value_type >& getDownscript() const
	{
		return m_downscript;
	}
	void setDownscript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_downscript = value_;
	}
	const boost::optional<PObjectNameWithSlash::value_type >& getBackenddomain() const
	{
		return m_backenddomain;
	}
	void setBackenddomain(const boost::optional<PObjectNameWithSlash::value_type >& value_)
	{
		m_backenddomain = value_;
	}
	const boost::optional<PType::value_type >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<PType::value_type >& value_)
	{
		m_model = value_;
	}
	const boost::optional<Backend >& getBackend() const
	{
		return m_backend;
	}
	void setBackend(const boost::optional<Backend >& value_)
	{
		m_backend = value_;
	}
	const boost::optional<Driver3 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver3 >& value_)
	{
		m_driver = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<FilterrefNodeAttributes >& getFilterref() const
	{
		return m_filterref;
	}
	void setFilterref(const boost::optional<FilterrefNodeAttributes >& value_)
	{
		m_filterref = value_;
	}
	const boost::optional<Tune >& getTune() const
	{
		return m_tune;
	}
	void setTune(const boost::optional<Tune >& value_)
	{
		m_tune = value_;
	}
	const boost::optional<Boot >& getBoot() const
	{
		return m_boot;
	}
	void setBoot(const boost::optional<Boot >& value_)
	{
		m_boot = value_;
	}
	const boost::optional<Rom >& getRom() const
	{
		return m_rom;
	}
	void setRom(const boost::optional<Rom >& value_)
	{
		m_rom = value_;
	}
	const boost::optional<Bandwidth1 >& getBandwidth() const
	{
		return m_bandwidth;
	}
	void setBandwidth(const boost::optional<Bandwidth1 >& value_)
	{
		m_bandwidth = value_;
	}
	const boost::optional<QList<Tag > >& getVlan() const
	{
		return m_vlan;
	}
	void setVlan(const boost::optional<QList<Tag > >& value_)
	{
		m_vlan = value_;
	}
	const boost::optional<Port >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<Port >& value_)
	{
		m_port = value_;
	}
	const boost::optional<VTeaming >& getTeaming() const
	{
		return m_teaming;
	}
	void setTeaming(const boost::optional<VTeaming >& value_)
	{
		m_teaming = value_;
	}

private:
	boost::optional<Source6 > m_source;
	boost::optional<VVirtualPortProfile > m_virtualPortProfile;
	boost::optional<EState > m_link;
	boost::optional<PUnsignedShort::value_type > m_mtu;
	boost::optional<Coalesce > m_coalesce;
	boost::optional<QList<VzDhcp > > m_vzDhcpList;
	boost::optional<VzDns1 > m_vzDns;
	boost::optional<Target3 > m_target;
	boost::optional<Guest > m_guest;
	boost::optional<PUniMacAddr::value_type > m_mac;
	QList<Ip > m_ipList;
	QList<Route > m_routeList;
	boost::optional<PFilePath::value_type > m_script;
	boost::optional<PFilePath::value_type > m_downscript;
	boost::optional<PObjectNameWithSlash::value_type > m_backenddomain;
	boost::optional<PType::value_type > m_model;
	boost::optional<Backend > m_backend;
	boost::optional<Driver3 > m_driver;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
	boost::optional<FilterrefNodeAttributes > m_filterref;
	boost::optional<Tune > m_tune;
	boost::optional<Boot > m_boot;
	boost::optional<Rom > m_rom;
	boost::optional<Bandwidth1 > m_bandwidth;
	boost::optional<QList<Tag > > m_vlan;
	boost::optional<Port > m_port;
	boost::optional<VTeaming > m_teaming;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Interface7023

namespace Domain
{
namespace Xml
{
struct Interface7023
{
	const boost::optional<PDeviceName::value_type >& getSource() const
	{
		return m_source;
	}
	void setSource(const boost::optional<PDeviceName::value_type >& value_)
	{
		m_source = value_;
	}
	const boost::optional<EState >& getLink() const
	{
		return m_link;
	}
	void setLink(const boost::optional<EState >& value_)
	{
		m_link = value_;
	}
	const boost::optional<PUnsignedShort::value_type >& getMtu() const
	{
		return m_mtu;
	}
	void setMtu(const boost::optional<PUnsignedShort::value_type >& value_)
	{
		m_mtu = value_;
	}
	const boost::optional<Coalesce >& getCoalesce() const
	{
		return m_coalesce;
	}
	void setCoalesce(const boost::optional<Coalesce >& value_)
	{
		m_coalesce = value_;
	}
	const boost::optional<QList<VzDhcp > >& getVzDhcpList() const
	{
		return m_vzDhcpList;
	}
	void setVzDhcpList(const boost::optional<QList<VzDhcp > >& value_)
	{
		m_vzDhcpList = value_;
	}
	const boost::optional<VzDns1 >& getVzDns() const
	{
		return m_vzDns;
	}
	void setVzDns(const boost::optional<VzDns1 >& value_)
	{
		m_vzDns = value_;
	}
	const boost::optional<Target3 >& getTarget() const
	{
		return m_target;
	}
	void setTarget(const boost::optional<Target3 >& value_)
	{
		m_target = value_;
	}
	const boost::optional<Guest >& getGuest() const
	{
		return m_guest;
	}
	void setGuest(const boost::optional<Guest >& value_)
	{
		m_guest = value_;
	}
	const boost::optional<PUniMacAddr::value_type >& getMac() const
	{
		return m_mac;
	}
	void setMac(const boost::optional<PUniMacAddr::value_type >& value_)
	{
		m_mac = value_;
	}
	const QList<Ip >& getIpList() const
	{
		return m_ipList;
	}
	void setIpList(const QList<Ip >& value_)
	{
		m_ipList = value_;
	}
	const QList<Route >& getRouteList() const
	{
		return m_routeList;
	}
	void setRouteList(const QList<Route >& value_)
	{
		m_routeList = value_;
	}
	const boost::optional<PFilePath::value_type >& getScript() const
	{
		return m_script;
	}
	void setScript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_script = value_;
	}
	const boost::optional<PFilePath::value_type >& getDownscript() const
	{
		return m_downscript;
	}
	void setDownscript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_downscript = value_;
	}
	const boost::optional<PObjectNameWithSlash::value_type >& getBackenddomain() const
	{
		return m_backenddomain;
	}
	void setBackenddomain(const boost::optional<PObjectNameWithSlash::value_type >& value_)
	{
		m_backenddomain = value_;
	}
	const boost::optional<PType::value_type >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<PType::value_type >& value_)
	{
		m_model = value_;
	}
	const boost::optional<Backend >& getBackend() const
	{
		return m_backend;
	}
	void setBackend(const boost::optional<Backend >& value_)
	{
		m_backend = value_;
	}
	const boost::optional<Driver3 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver3 >& value_)
	{
		m_driver = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<FilterrefNodeAttributes >& getFilterref() const
	{
		return m_filterref;
	}
	void setFilterref(const boost::optional<FilterrefNodeAttributes >& value_)
	{
		m_filterref = value_;
	}
	const boost::optional<Tune >& getTune() const
	{
		return m_tune;
	}
	void setTune(const boost::optional<Tune >& value_)
	{
		m_tune = value_;
	}
	const boost::optional<Boot >& getBoot() const
	{
		return m_boot;
	}
	void setBoot(const boost::optional<Boot >& value_)
	{
		m_boot = value_;
	}
	const boost::optional<Rom >& getRom() const
	{
		return m_rom;
	}
	void setRom(const boost::optional<Rom >& value_)
	{
		m_rom = value_;
	}
	const boost::optional<Bandwidth1 >& getBandwidth() const
	{
		return m_bandwidth;
	}
	void setBandwidth(const boost::optional<Bandwidth1 >& value_)
	{
		m_bandwidth = value_;
	}
	const boost::optional<QList<Tag > >& getVlan() const
	{
		return m_vlan;
	}
	void setVlan(const boost::optional<QList<Tag > >& value_)
	{
		m_vlan = value_;
	}
	const boost::optional<Port >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<Port >& value_)
	{
		m_port = value_;
	}
	const boost::optional<VTeaming >& getTeaming() const
	{
		return m_teaming;
	}
	void setTeaming(const boost::optional<VTeaming >& value_)
	{
		m_teaming = value_;
	}

private:
	boost::optional<PDeviceName::value_type > m_source;
	boost::optional<EState > m_link;
	boost::optional<PUnsignedShort::value_type > m_mtu;
	boost::optional<Coalesce > m_coalesce;
	boost::optional<QList<VzDhcp > > m_vzDhcpList;
	boost::optional<VzDns1 > m_vzDns;
	boost::optional<Target3 > m_target;
	boost::optional<Guest > m_guest;
	boost::optional<PUniMacAddr::value_type > m_mac;
	QList<Ip > m_ipList;
	QList<Route > m_routeList;
	boost::optional<PFilePath::value_type > m_script;
	boost::optional<PFilePath::value_type > m_downscript;
	boost::optional<PObjectNameWithSlash::value_type > m_backenddomain;
	boost::optional<PType::value_type > m_model;
	boost::optional<Backend > m_backend;
	boost::optional<Driver3 > m_driver;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
	boost::optional<FilterrefNodeAttributes > m_filterref;
	boost::optional<Tune > m_tune;
	boost::optional<Boot > m_boot;
	boost::optional<Rom > m_rom;
	boost::optional<Bandwidth1 > m_bandwidth;
	boost::optional<QList<Tag > > m_vlan;
	boost::optional<Port > m_port;
	boost::optional<VTeaming > m_teaming;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source7

namespace Domain
{
namespace Xml
{
struct Source7
{
	Source7();

	EType11 getType() const
	{
		return m_type;
	}
	void setType(EType11 value_)
	{
		m_type = value_;
	}
	const PAbsFilePath::value_type& getPath() const
	{
		return m_path;
	}
	void setPath(const PAbsFilePath::value_type& value_)
	{
		m_path = value_;
	}
	EMode9 getMode() const
	{
		return m_mode;
	}
	void setMode(EMode9 value_)
	{
		m_mode = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EType11 m_type;
	PAbsFilePath::value_type m_path;
	EMode9 m_mode;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Interface7024

namespace Domain
{
namespace Xml
{
struct Interface7024
{
	const Source7& getSource() const
	{
		return m_source;
	}
	void setSource(const Source7& value_)
	{
		m_source = value_;
	}
	const boost::optional<EState >& getLink() const
	{
		return m_link;
	}
	void setLink(const boost::optional<EState >& value_)
	{
		m_link = value_;
	}
	const boost::optional<PUnsignedShort::value_type >& getMtu() const
	{
		return m_mtu;
	}
	void setMtu(const boost::optional<PUnsignedShort::value_type >& value_)
	{
		m_mtu = value_;
	}
	const boost::optional<Coalesce >& getCoalesce() const
	{
		return m_coalesce;
	}
	void setCoalesce(const boost::optional<Coalesce >& value_)
	{
		m_coalesce = value_;
	}
	const boost::optional<QList<VzDhcp > >& getVzDhcpList() const
	{
		return m_vzDhcpList;
	}
	void setVzDhcpList(const boost::optional<QList<VzDhcp > >& value_)
	{
		m_vzDhcpList = value_;
	}
	const boost::optional<VzDns1 >& getVzDns() const
	{
		return m_vzDns;
	}
	void setVzDns(const boost::optional<VzDns1 >& value_)
	{
		m_vzDns = value_;
	}
	const boost::optional<Target3 >& getTarget() const
	{
		return m_target;
	}
	void setTarget(const boost::optional<Target3 >& value_)
	{
		m_target = value_;
	}
	const boost::optional<Guest >& getGuest() const
	{
		return m_guest;
	}
	void setGuest(const boost::optional<Guest >& value_)
	{
		m_guest = value_;
	}
	const boost::optional<PUniMacAddr::value_type >& getMac() const
	{
		return m_mac;
	}
	void setMac(const boost::optional<PUniMacAddr::value_type >& value_)
	{
		m_mac = value_;
	}
	const QList<Ip >& getIpList() const
	{
		return m_ipList;
	}
	void setIpList(const QList<Ip >& value_)
	{
		m_ipList = value_;
	}
	const QList<Route >& getRouteList() const
	{
		return m_routeList;
	}
	void setRouteList(const QList<Route >& value_)
	{
		m_routeList = value_;
	}
	const boost::optional<PFilePath::value_type >& getScript() const
	{
		return m_script;
	}
	void setScript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_script = value_;
	}
	const boost::optional<PFilePath::value_type >& getDownscript() const
	{
		return m_downscript;
	}
	void setDownscript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_downscript = value_;
	}
	const boost::optional<PObjectNameWithSlash::value_type >& getBackenddomain() const
	{
		return m_backenddomain;
	}
	void setBackenddomain(const boost::optional<PObjectNameWithSlash::value_type >& value_)
	{
		m_backenddomain = value_;
	}
	const boost::optional<PType::value_type >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<PType::value_type >& value_)
	{
		m_model = value_;
	}
	const boost::optional<Backend >& getBackend() const
	{
		return m_backend;
	}
	void setBackend(const boost::optional<Backend >& value_)
	{
		m_backend = value_;
	}
	const boost::optional<Driver3 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver3 >& value_)
	{
		m_driver = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<FilterrefNodeAttributes >& getFilterref() const
	{
		return m_filterref;
	}
	void setFilterref(const boost::optional<FilterrefNodeAttributes >& value_)
	{
		m_filterref = value_;
	}
	const boost::optional<Tune >& getTune() const
	{
		return m_tune;
	}
	void setTune(const boost::optional<Tune >& value_)
	{
		m_tune = value_;
	}
	const boost::optional<Boot >& getBoot() const
	{
		return m_boot;
	}
	void setBoot(const boost::optional<Boot >& value_)
	{
		m_boot = value_;
	}
	const boost::optional<Rom >& getRom() const
	{
		return m_rom;
	}
	void setRom(const boost::optional<Rom >& value_)
	{
		m_rom = value_;
	}
	const boost::optional<Bandwidth1 >& getBandwidth() const
	{
		return m_bandwidth;
	}
	void setBandwidth(const boost::optional<Bandwidth1 >& value_)
	{
		m_bandwidth = value_;
	}
	const boost::optional<QList<Tag > >& getVlan() const
	{
		return m_vlan;
	}
	void setVlan(const boost::optional<QList<Tag > >& value_)
	{
		m_vlan = value_;
	}
	const boost::optional<Port >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<Port >& value_)
	{
		m_port = value_;
	}
	const boost::optional<VTeaming >& getTeaming() const
	{
		return m_teaming;
	}
	void setTeaming(const boost::optional<VTeaming >& value_)
	{
		m_teaming = value_;
	}

private:
	Source7 m_source;
	boost::optional<EState > m_link;
	boost::optional<PUnsignedShort::value_type > m_mtu;
	boost::optional<Coalesce > m_coalesce;
	boost::optional<QList<VzDhcp > > m_vzDhcpList;
	boost::optional<VzDns1 > m_vzDns;
	boost::optional<Target3 > m_target;
	boost::optional<Guest > m_guest;
	boost::optional<PUniMacAddr::value_type > m_mac;
	QList<Ip > m_ipList;
	QList<Route > m_routeList;
	boost::optional<PFilePath::value_type > m_script;
	boost::optional<PFilePath::value_type > m_downscript;
	boost::optional<PObjectNameWithSlash::value_type > m_backenddomain;
	boost::optional<PType::value_type > m_model;
	boost::optional<Backend > m_backend;
	boost::optional<Driver3 > m_driver;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
	boost::optional<FilterrefNodeAttributes > m_filterref;
	boost::optional<Tune > m_tune;
	boost::optional<Boot > m_boot;
	boost::optional<Rom > m_rom;
	boost::optional<Bandwidth1 > m_bandwidth;
	boost::optional<QList<Tag > > m_vlan;
	boost::optional<Port > m_port;
	boost::optional<VTeaming > m_teaming;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source8

namespace Domain
{
namespace Xml
{
struct Source8
{
	const InterfaceNetworkAttributes& getInterfaceNetworkAttributes() const
	{
		return m_interfaceNetworkAttributes;
	}
	void setInterfaceNetworkAttributes(const InterfaceNetworkAttributes& value_)
	{
		m_interfaceNetworkAttributes = value_;
	}
	const boost::optional<InterfaceBridgeAttributes >& getInterfaceBridgeAttributes() const
	{
		return m_interfaceBridgeAttributes;
	}
	void setInterfaceBridgeAttributes(const boost::optional<InterfaceBridgeAttributes >& value_)
	{
		m_interfaceBridgeAttributes = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	InterfaceNetworkAttributes m_interfaceNetworkAttributes;
	boost::optional<InterfaceBridgeAttributes > m_interfaceBridgeAttributes;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Interface7025

namespace Domain
{
namespace Xml
{
struct Interface7025
{
	const Source8& getSource() const
	{
		return m_source;
	}
	void setSource(const Source8& value_)
	{
		m_source = value_;
	}
	const boost::optional<VVirtualPortProfile >& getVirtualPortProfile() const
	{
		return m_virtualPortProfile;
	}
	void setVirtualPortProfile(const boost::optional<VVirtualPortProfile >& value_)
	{
		m_virtualPortProfile = value_;
	}
	const boost::optional<EState >& getLink() const
	{
		return m_link;
	}
	void setLink(const boost::optional<EState >& value_)
	{
		m_link = value_;
	}
	const boost::optional<PUnsignedShort::value_type >& getMtu() const
	{
		return m_mtu;
	}
	void setMtu(const boost::optional<PUnsignedShort::value_type >& value_)
	{
		m_mtu = value_;
	}
	const boost::optional<Coalesce >& getCoalesce() const
	{
		return m_coalesce;
	}
	void setCoalesce(const boost::optional<Coalesce >& value_)
	{
		m_coalesce = value_;
	}
	const boost::optional<QList<VzDhcp > >& getVzDhcpList() const
	{
		return m_vzDhcpList;
	}
	void setVzDhcpList(const boost::optional<QList<VzDhcp > >& value_)
	{
		m_vzDhcpList = value_;
	}
	const boost::optional<VzDns1 >& getVzDns() const
	{
		return m_vzDns;
	}
	void setVzDns(const boost::optional<VzDns1 >& value_)
	{
		m_vzDns = value_;
	}
	const boost::optional<Target3 >& getTarget() const
	{
		return m_target;
	}
	void setTarget(const boost::optional<Target3 >& value_)
	{
		m_target = value_;
	}
	const boost::optional<Guest >& getGuest() const
	{
		return m_guest;
	}
	void setGuest(const boost::optional<Guest >& value_)
	{
		m_guest = value_;
	}
	const boost::optional<PUniMacAddr::value_type >& getMac() const
	{
		return m_mac;
	}
	void setMac(const boost::optional<PUniMacAddr::value_type >& value_)
	{
		m_mac = value_;
	}
	const QList<Ip >& getIpList() const
	{
		return m_ipList;
	}
	void setIpList(const QList<Ip >& value_)
	{
		m_ipList = value_;
	}
	const QList<Route >& getRouteList() const
	{
		return m_routeList;
	}
	void setRouteList(const QList<Route >& value_)
	{
		m_routeList = value_;
	}
	const boost::optional<PFilePath::value_type >& getScript() const
	{
		return m_script;
	}
	void setScript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_script = value_;
	}
	const boost::optional<PFilePath::value_type >& getDownscript() const
	{
		return m_downscript;
	}
	void setDownscript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_downscript = value_;
	}
	const boost::optional<PObjectNameWithSlash::value_type >& getBackenddomain() const
	{
		return m_backenddomain;
	}
	void setBackenddomain(const boost::optional<PObjectNameWithSlash::value_type >& value_)
	{
		m_backenddomain = value_;
	}
	const boost::optional<PType::value_type >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<PType::value_type >& value_)
	{
		m_model = value_;
	}
	const boost::optional<Backend >& getBackend() const
	{
		return m_backend;
	}
	void setBackend(const boost::optional<Backend >& value_)
	{
		m_backend = value_;
	}
	const boost::optional<Driver3 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver3 >& value_)
	{
		m_driver = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<FilterrefNodeAttributes >& getFilterref() const
	{
		return m_filterref;
	}
	void setFilterref(const boost::optional<FilterrefNodeAttributes >& value_)
	{
		m_filterref = value_;
	}
	const boost::optional<Tune >& getTune() const
	{
		return m_tune;
	}
	void setTune(const boost::optional<Tune >& value_)
	{
		m_tune = value_;
	}
	const boost::optional<Boot >& getBoot() const
	{
		return m_boot;
	}
	void setBoot(const boost::optional<Boot >& value_)
	{
		m_boot = value_;
	}
	const boost::optional<Rom >& getRom() const
	{
		return m_rom;
	}
	void setRom(const boost::optional<Rom >& value_)
	{
		m_rom = value_;
	}
	const boost::optional<Bandwidth1 >& getBandwidth() const
	{
		return m_bandwidth;
	}
	void setBandwidth(const boost::optional<Bandwidth1 >& value_)
	{
		m_bandwidth = value_;
	}
	const boost::optional<QList<Tag > >& getVlan() const
	{
		return m_vlan;
	}
	void setVlan(const boost::optional<QList<Tag > >& value_)
	{
		m_vlan = value_;
	}
	const boost::optional<Port >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<Port >& value_)
	{
		m_port = value_;
	}
	const boost::optional<VTeaming >& getTeaming() const
	{
		return m_teaming;
	}
	void setTeaming(const boost::optional<VTeaming >& value_)
	{
		m_teaming = value_;
	}

private:
	Source8 m_source;
	boost::optional<VVirtualPortProfile > m_virtualPortProfile;
	boost::optional<EState > m_link;
	boost::optional<PUnsignedShort::value_type > m_mtu;
	boost::optional<Coalesce > m_coalesce;
	boost::optional<QList<VzDhcp > > m_vzDhcpList;
	boost::optional<VzDns1 > m_vzDns;
	boost::optional<Target3 > m_target;
	boost::optional<Guest > m_guest;
	boost::optional<PUniMacAddr::value_type > m_mac;
	QList<Ip > m_ipList;
	QList<Route > m_routeList;
	boost::optional<PFilePath::value_type > m_script;
	boost::optional<PFilePath::value_type > m_downscript;
	boost::optional<PObjectNameWithSlash::value_type > m_backenddomain;
	boost::optional<PType::value_type > m_model;
	boost::optional<Backend > m_backend;
	boost::optional<Driver3 > m_driver;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
	boost::optional<FilterrefNodeAttributes > m_filterref;
	boost::optional<Tune > m_tune;
	boost::optional<Boot > m_boot;
	boost::optional<Rom > m_rom;
	boost::optional<Bandwidth1 > m_bandwidth;
	boost::optional<QList<Tag > > m_vlan;
	boost::optional<Port > m_port;
	boost::optional<VTeaming > m_teaming;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source9

namespace Domain
{
namespace Xml
{
struct Source9
{
	const PDeviceName::value_type& getDev() const
	{
		return m_dev;
	}
	void setDev(const PDeviceName::value_type& value_)
	{
		m_dev = value_;
	}
	const boost::optional<PBridgeMode::value_type >& getMode() const
	{
		return m_mode;
	}
	void setMode(const boost::optional<PBridgeMode::value_type >& value_)
	{
		m_mode = value_;
	}
	const boost::optional<InterfaceNetworkAttributes >& getInterfaceNetworkAttributes() const
	{
		return m_interfaceNetworkAttributes;
	}
	void setInterfaceNetworkAttributes(const boost::optional<InterfaceNetworkAttributes >& value_)
	{
		m_interfaceNetworkAttributes = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PDeviceName::value_type m_dev;
	boost::optional<PBridgeMode::value_type > m_mode;
	boost::optional<InterfaceNetworkAttributes > m_interfaceNetworkAttributes;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Interface7026

namespace Domain
{
namespace Xml
{
struct Interface7026
{
	const Source9& getSource() const
	{
		return m_source;
	}
	void setSource(const Source9& value_)
	{
		m_source = value_;
	}
	const boost::optional<VVirtualPortProfile >& getVirtualPortProfile() const
	{
		return m_virtualPortProfile;
	}
	void setVirtualPortProfile(const boost::optional<VVirtualPortProfile >& value_)
	{
		m_virtualPortProfile = value_;
	}
	const boost::optional<EState >& getLink() const
	{
		return m_link;
	}
	void setLink(const boost::optional<EState >& value_)
	{
		m_link = value_;
	}
	const boost::optional<PUnsignedShort::value_type >& getMtu() const
	{
		return m_mtu;
	}
	void setMtu(const boost::optional<PUnsignedShort::value_type >& value_)
	{
		m_mtu = value_;
	}
	const boost::optional<Coalesce >& getCoalesce() const
	{
		return m_coalesce;
	}
	void setCoalesce(const boost::optional<Coalesce >& value_)
	{
		m_coalesce = value_;
	}
	const boost::optional<QList<VzDhcp > >& getVzDhcpList() const
	{
		return m_vzDhcpList;
	}
	void setVzDhcpList(const boost::optional<QList<VzDhcp > >& value_)
	{
		m_vzDhcpList = value_;
	}
	const boost::optional<VzDns1 >& getVzDns() const
	{
		return m_vzDns;
	}
	void setVzDns(const boost::optional<VzDns1 >& value_)
	{
		m_vzDns = value_;
	}
	const boost::optional<Target3 >& getTarget() const
	{
		return m_target;
	}
	void setTarget(const boost::optional<Target3 >& value_)
	{
		m_target = value_;
	}
	const boost::optional<Guest >& getGuest() const
	{
		return m_guest;
	}
	void setGuest(const boost::optional<Guest >& value_)
	{
		m_guest = value_;
	}
	const boost::optional<PUniMacAddr::value_type >& getMac() const
	{
		return m_mac;
	}
	void setMac(const boost::optional<PUniMacAddr::value_type >& value_)
	{
		m_mac = value_;
	}
	const QList<Ip >& getIpList() const
	{
		return m_ipList;
	}
	void setIpList(const QList<Ip >& value_)
	{
		m_ipList = value_;
	}
	const QList<Route >& getRouteList() const
	{
		return m_routeList;
	}
	void setRouteList(const QList<Route >& value_)
	{
		m_routeList = value_;
	}
	const boost::optional<PFilePath::value_type >& getScript() const
	{
		return m_script;
	}
	void setScript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_script = value_;
	}
	const boost::optional<PFilePath::value_type >& getDownscript() const
	{
		return m_downscript;
	}
	void setDownscript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_downscript = value_;
	}
	const boost::optional<PObjectNameWithSlash::value_type >& getBackenddomain() const
	{
		return m_backenddomain;
	}
	void setBackenddomain(const boost::optional<PObjectNameWithSlash::value_type >& value_)
	{
		m_backenddomain = value_;
	}
	const boost::optional<PType::value_type >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<PType::value_type >& value_)
	{
		m_model = value_;
	}
	const boost::optional<Backend >& getBackend() const
	{
		return m_backend;
	}
	void setBackend(const boost::optional<Backend >& value_)
	{
		m_backend = value_;
	}
	const boost::optional<Driver3 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver3 >& value_)
	{
		m_driver = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<FilterrefNodeAttributes >& getFilterref() const
	{
		return m_filterref;
	}
	void setFilterref(const boost::optional<FilterrefNodeAttributes >& value_)
	{
		m_filterref = value_;
	}
	const boost::optional<Tune >& getTune() const
	{
		return m_tune;
	}
	void setTune(const boost::optional<Tune >& value_)
	{
		m_tune = value_;
	}
	const boost::optional<Boot >& getBoot() const
	{
		return m_boot;
	}
	void setBoot(const boost::optional<Boot >& value_)
	{
		m_boot = value_;
	}
	const boost::optional<Rom >& getRom() const
	{
		return m_rom;
	}
	void setRom(const boost::optional<Rom >& value_)
	{
		m_rom = value_;
	}
	const boost::optional<Bandwidth1 >& getBandwidth() const
	{
		return m_bandwidth;
	}
	void setBandwidth(const boost::optional<Bandwidth1 >& value_)
	{
		m_bandwidth = value_;
	}
	const boost::optional<QList<Tag > >& getVlan() const
	{
		return m_vlan;
	}
	void setVlan(const boost::optional<QList<Tag > >& value_)
	{
		m_vlan = value_;
	}
	const boost::optional<Port >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<Port >& value_)
	{
		m_port = value_;
	}
	const boost::optional<VTeaming >& getTeaming() const
	{
		return m_teaming;
	}
	void setTeaming(const boost::optional<VTeaming >& value_)
	{
		m_teaming = value_;
	}

private:
	Source9 m_source;
	boost::optional<VVirtualPortProfile > m_virtualPortProfile;
	boost::optional<EState > m_link;
	boost::optional<PUnsignedShort::value_type > m_mtu;
	boost::optional<Coalesce > m_coalesce;
	boost::optional<QList<VzDhcp > > m_vzDhcpList;
	boost::optional<VzDns1 > m_vzDns;
	boost::optional<Target3 > m_target;
	boost::optional<Guest > m_guest;
	boost::optional<PUniMacAddr::value_type > m_mac;
	QList<Ip > m_ipList;
	QList<Route > m_routeList;
	boost::optional<PFilePath::value_type > m_script;
	boost::optional<PFilePath::value_type > m_downscript;
	boost::optional<PObjectNameWithSlash::value_type > m_backenddomain;
	boost::optional<PType::value_type > m_model;
	boost::optional<Backend > m_backend;
	boost::optional<Driver3 > m_driver;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
	boost::optional<FilterrefNodeAttributes > m_filterref;
	boost::optional<Tune > m_tune;
	boost::optional<Boot > m_boot;
	boost::optional<Rom > m_rom;
	boost::optional<Bandwidth1 > m_bandwidth;
	boost::optional<QList<Tag > > m_vlan;
	boost::optional<Port > m_port;
	boost::optional<VTeaming > m_teaming;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct InterfaceOptions

namespace Domain
{
namespace Xml
{
struct InterfaceOptions
{
	const boost::optional<EState >& getLink() const
	{
		return m_link;
	}
	void setLink(const boost::optional<EState >& value_)
	{
		m_link = value_;
	}
	const boost::optional<PUnsignedShort::value_type >& getMtu() const
	{
		return m_mtu;
	}
	void setMtu(const boost::optional<PUnsignedShort::value_type >& value_)
	{
		m_mtu = value_;
	}
	const boost::optional<Coalesce >& getCoalesce() const
	{
		return m_coalesce;
	}
	void setCoalesce(const boost::optional<Coalesce >& value_)
	{
		m_coalesce = value_;
	}
	const boost::optional<QList<VzDhcp > >& getVzDhcpList() const
	{
		return m_vzDhcpList;
	}
	void setVzDhcpList(const boost::optional<QList<VzDhcp > >& value_)
	{
		m_vzDhcpList = value_;
	}
	const boost::optional<VzDns1 >& getVzDns() const
	{
		return m_vzDns;
	}
	void setVzDns(const boost::optional<VzDns1 >& value_)
	{
		m_vzDns = value_;
	}
	const boost::optional<Target3 >& getTarget() const
	{
		return m_target;
	}
	void setTarget(const boost::optional<Target3 >& value_)
	{
		m_target = value_;
	}
	const boost::optional<Guest >& getGuest() const
	{
		return m_guest;
	}
	void setGuest(const boost::optional<Guest >& value_)
	{
		m_guest = value_;
	}
	const boost::optional<PUniMacAddr::value_type >& getMac() const
	{
		return m_mac;
	}
	void setMac(const boost::optional<PUniMacAddr::value_type >& value_)
	{
		m_mac = value_;
	}
	const QList<Ip >& getIpList() const
	{
		return m_ipList;
	}
	void setIpList(const QList<Ip >& value_)
	{
		m_ipList = value_;
	}
	const QList<Route >& getRouteList() const
	{
		return m_routeList;
	}
	void setRouteList(const QList<Route >& value_)
	{
		m_routeList = value_;
	}
	const boost::optional<PFilePath::value_type >& getScript() const
	{
		return m_script;
	}
	void setScript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_script = value_;
	}
	const boost::optional<PFilePath::value_type >& getDownscript() const
	{
		return m_downscript;
	}
	void setDownscript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_downscript = value_;
	}
	const boost::optional<PObjectNameWithSlash::value_type >& getBackenddomain() const
	{
		return m_backenddomain;
	}
	void setBackenddomain(const boost::optional<PObjectNameWithSlash::value_type >& value_)
	{
		m_backenddomain = value_;
	}
	const boost::optional<PType::value_type >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<PType::value_type >& value_)
	{
		m_model = value_;
	}
	const boost::optional<Backend >& getBackend() const
	{
		return m_backend;
	}
	void setBackend(const boost::optional<Backend >& value_)
	{
		m_backend = value_;
	}
	const boost::optional<Driver3 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver3 >& value_)
	{
		m_driver = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<FilterrefNodeAttributes >& getFilterref() const
	{
		return m_filterref;
	}
	void setFilterref(const boost::optional<FilterrefNodeAttributes >& value_)
	{
		m_filterref = value_;
	}
	const boost::optional<Tune >& getTune() const
	{
		return m_tune;
	}
	void setTune(const boost::optional<Tune >& value_)
	{
		m_tune = value_;
	}
	const boost::optional<Boot >& getBoot() const
	{
		return m_boot;
	}
	void setBoot(const boost::optional<Boot >& value_)
	{
		m_boot = value_;
	}
	const boost::optional<Rom >& getRom() const
	{
		return m_rom;
	}
	void setRom(const boost::optional<Rom >& value_)
	{
		m_rom = value_;
	}
	const boost::optional<Bandwidth1 >& getBandwidth() const
	{
		return m_bandwidth;
	}
	void setBandwidth(const boost::optional<Bandwidth1 >& value_)
	{
		m_bandwidth = value_;
	}
	const boost::optional<QList<Tag > >& getVlan() const
	{
		return m_vlan;
	}
	void setVlan(const boost::optional<QList<Tag > >& value_)
	{
		m_vlan = value_;
	}
	const boost::optional<Port >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<Port >& value_)
	{
		m_port = value_;
	}
	const boost::optional<VTeaming >& getTeaming() const
	{
		return m_teaming;
	}
	void setTeaming(const boost::optional<VTeaming >& value_)
	{
		m_teaming = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	boost::optional<EState > m_link;
	boost::optional<PUnsignedShort::value_type > m_mtu;
	boost::optional<Coalesce > m_coalesce;
	boost::optional<QList<VzDhcp > > m_vzDhcpList;
	boost::optional<VzDns1 > m_vzDns;
	boost::optional<Target3 > m_target;
	boost::optional<Guest > m_guest;
	boost::optional<PUniMacAddr::value_type > m_mac;
	QList<Ip > m_ipList;
	QList<Route > m_routeList;
	boost::optional<PFilePath::value_type > m_script;
	boost::optional<PFilePath::value_type > m_downscript;
	boost::optional<PObjectNameWithSlash::value_type > m_backenddomain;
	boost::optional<PType::value_type > m_model;
	boost::optional<Backend > m_backend;
	boost::optional<Driver3 > m_driver;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
	boost::optional<FilterrefNodeAttributes > m_filterref;
	boost::optional<Tune > m_tune;
	boost::optional<Boot > m_boot;
	boost::optional<Rom > m_rom;
	boost::optional<Bandwidth1 > m_bandwidth;
	boost::optional<QList<Tag > > m_vlan;
	boost::optional<Port > m_port;
	boost::optional<VTeaming > m_teaming;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Interface7028

namespace Domain
{
namespace Xml
{
struct Interface7028
{
	const PDeviceName::value_type& getSource() const
	{
		return m_source;
	}
	void setSource(const PDeviceName::value_type& value_)
	{
		m_source = value_;
	}
	const boost::optional<EState >& getLink() const
	{
		return m_link;
	}
	void setLink(const boost::optional<EState >& value_)
	{
		m_link = value_;
	}
	const boost::optional<PUnsignedShort::value_type >& getMtu() const
	{
		return m_mtu;
	}
	void setMtu(const boost::optional<PUnsignedShort::value_type >& value_)
	{
		m_mtu = value_;
	}
	const boost::optional<Coalesce >& getCoalesce() const
	{
		return m_coalesce;
	}
	void setCoalesce(const boost::optional<Coalesce >& value_)
	{
		m_coalesce = value_;
	}
	const boost::optional<QList<VzDhcp > >& getVzDhcpList() const
	{
		return m_vzDhcpList;
	}
	void setVzDhcpList(const boost::optional<QList<VzDhcp > >& value_)
	{
		m_vzDhcpList = value_;
	}
	const boost::optional<VzDns1 >& getVzDns() const
	{
		return m_vzDns;
	}
	void setVzDns(const boost::optional<VzDns1 >& value_)
	{
		m_vzDns = value_;
	}
	const boost::optional<Target3 >& getTarget() const
	{
		return m_target;
	}
	void setTarget(const boost::optional<Target3 >& value_)
	{
		m_target = value_;
	}
	const boost::optional<Guest >& getGuest() const
	{
		return m_guest;
	}
	void setGuest(const boost::optional<Guest >& value_)
	{
		m_guest = value_;
	}
	const boost::optional<PUniMacAddr::value_type >& getMac() const
	{
		return m_mac;
	}
	void setMac(const boost::optional<PUniMacAddr::value_type >& value_)
	{
		m_mac = value_;
	}
	const QList<Ip >& getIpList() const
	{
		return m_ipList;
	}
	void setIpList(const QList<Ip >& value_)
	{
		m_ipList = value_;
	}
	const QList<Route >& getRouteList() const
	{
		return m_routeList;
	}
	void setRouteList(const QList<Route >& value_)
	{
		m_routeList = value_;
	}
	const boost::optional<PFilePath::value_type >& getScript() const
	{
		return m_script;
	}
	void setScript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_script = value_;
	}
	const boost::optional<PFilePath::value_type >& getDownscript() const
	{
		return m_downscript;
	}
	void setDownscript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_downscript = value_;
	}
	const boost::optional<PObjectNameWithSlash::value_type >& getBackenddomain() const
	{
		return m_backenddomain;
	}
	void setBackenddomain(const boost::optional<PObjectNameWithSlash::value_type >& value_)
	{
		m_backenddomain = value_;
	}
	const boost::optional<PType::value_type >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<PType::value_type >& value_)
	{
		m_model = value_;
	}
	const boost::optional<Backend >& getBackend() const
	{
		return m_backend;
	}
	void setBackend(const boost::optional<Backend >& value_)
	{
		m_backend = value_;
	}
	const boost::optional<Driver3 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver3 >& value_)
	{
		m_driver = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<FilterrefNodeAttributes >& getFilterref() const
	{
		return m_filterref;
	}
	void setFilterref(const boost::optional<FilterrefNodeAttributes >& value_)
	{
		m_filterref = value_;
	}
	const boost::optional<Tune >& getTune() const
	{
		return m_tune;
	}
	void setTune(const boost::optional<Tune >& value_)
	{
		m_tune = value_;
	}
	const boost::optional<Boot >& getBoot() const
	{
		return m_boot;
	}
	void setBoot(const boost::optional<Boot >& value_)
	{
		m_boot = value_;
	}
	const boost::optional<Rom >& getRom() const
	{
		return m_rom;
	}
	void setRom(const boost::optional<Rom >& value_)
	{
		m_rom = value_;
	}
	const boost::optional<Bandwidth1 >& getBandwidth() const
	{
		return m_bandwidth;
	}
	void setBandwidth(const boost::optional<Bandwidth1 >& value_)
	{
		m_bandwidth = value_;
	}
	const boost::optional<QList<Tag > >& getVlan() const
	{
		return m_vlan;
	}
	void setVlan(const boost::optional<QList<Tag > >& value_)
	{
		m_vlan = value_;
	}
	const boost::optional<Port >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<Port >& value_)
	{
		m_port = value_;
	}
	const boost::optional<VTeaming >& getTeaming() const
	{
		return m_teaming;
	}
	void setTeaming(const boost::optional<VTeaming >& value_)
	{
		m_teaming = value_;
	}

private:
	PDeviceName::value_type m_source;
	boost::optional<EState > m_link;
	boost::optional<PUnsignedShort::value_type > m_mtu;
	boost::optional<Coalesce > m_coalesce;
	boost::optional<QList<VzDhcp > > m_vzDhcpList;
	boost::optional<VzDns1 > m_vzDns;
	boost::optional<Target3 > m_target;
	boost::optional<Guest > m_guest;
	boost::optional<PUniMacAddr::value_type > m_mac;
	QList<Ip > m_ipList;
	QList<Route > m_routeList;
	boost::optional<PFilePath::value_type > m_script;
	boost::optional<PFilePath::value_type > m_downscript;
	boost::optional<PObjectNameWithSlash::value_type > m_backenddomain;
	boost::optional<PType::value_type > m_model;
	boost::optional<Backend > m_backend;
	boost::optional<Driver3 > m_driver;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
	boost::optional<FilterrefNodeAttributes > m_filterref;
	boost::optional<Tune > m_tune;
	boost::optional<Boot > m_boot;
	boost::optional<Rom > m_rom;
	boost::optional<Bandwidth1 > m_bandwidth;
	boost::optional<QList<Tag > > m_vlan;
	boost::optional<Port > m_port;
	boost::optional<VTeaming > m_teaming;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source10

namespace Domain
{
namespace Xml
{
struct Source10
{
	Source10();

	const PIpv4Addr::value_type& getAddress() const
	{
		return m_address;
	}
	void setAddress(const PIpv4Addr::value_type& value_)
	{
		m_address = value_;
	}
	PPortNumber::value_type getPort() const
	{
		return m_port;
	}
	void setPort(PPortNumber::value_type value_)
	{
		m_port = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PIpv4Addr::value_type m_address;
	PPortNumber::value_type m_port;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Interface7029

namespace Domain
{
namespace Xml
{
struct Interface7029
{
	Interface7029();

	EType12 getType() const
	{
		return m_type;
	}
	void setType(EType12 value_)
	{
		m_type = value_;
	}
	const Source10& getSource() const
	{
		return m_source;
	}
	void setSource(const Source10& value_)
	{
		m_source = value_;
	}
	const boost::optional<PUniMacAddr::value_type >& getMac() const
	{
		return m_mac;
	}
	void setMac(const boost::optional<PUniMacAddr::value_type >& value_)
	{
		m_mac = value_;
	}

private:
	EType12 m_type;
	Source10 m_source;
	boost::optional<PUniMacAddr::value_type > m_mac;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source11

namespace Domain
{
namespace Xml
{
struct Source11
{
	Source11();

	const boost::optional<PIpv4Addr::value_type >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<PIpv4Addr::value_type >& value_)
	{
		m_address = value_;
	}
	PPortNumber::value_type getPort() const
	{
		return m_port;
	}
	void setPort(PPortNumber::value_type value_)
	{
		m_port = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PIpv4Addr::value_type > m_address;
	PPortNumber::value_type m_port;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Interface7030

namespace Domain
{
namespace Xml
{
struct Interface7030
{
	const Source11& getSource() const
	{
		return m_source;
	}
	void setSource(const Source11& value_)
	{
		m_source = value_;
	}
	const boost::optional<PUniMacAddr::value_type >& getMac() const
	{
		return m_mac;
	}
	void setMac(const boost::optional<PUniMacAddr::value_type >& value_)
	{
		m_mac = value_;
	}

private:
	Source11 m_source;
	boost::optional<PUniMacAddr::value_type > m_mac;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Usbproduct

namespace Domain
{
namespace Xml
{
struct Usbproduct
{
	const PUsbId::value_type& getVendor() const
	{
		return m_vendor;
	}
	void setVendor(const PUsbId::value_type& value_)
	{
		m_vendor = value_;
	}
	const PUsbId::value_type& getProduct() const
	{
		return m_product;
	}
	void setProduct(const PUsbId::value_type& value_)
	{
		m_product = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	PUsbId::value_type m_vendor;
	PUsbId::value_type m_product;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Address

namespace Domain
{
namespace Xml
{
struct Address
{
	const PUsbAddr::value_type& getBus() const
	{
		return m_bus;
	}
	void setBus(const PUsbAddr::value_type& value_)
	{
		m_bus = value_;
	}
	const PUsbPort::value_type& getDevice() const
	{
		return m_device;
	}
	void setDevice(const PUsbPort::value_type& value_)
	{
		m_device = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUsbAddr::value_type m_bus;
	PUsbPort::value_type m_device;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source7031

namespace Domain
{
namespace Xml
{
struct Source7031
{
	const Usbproduct& getUsbproduct() const
	{
		return m_usbproduct;
	}
	void setUsbproduct(const Usbproduct& value_)
	{
		m_usbproduct = value_;
	}
	const boost::optional<Address >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<Address >& value_)
	{
		m_address = value_;
	}

private:
	Usbproduct m_usbproduct;
	boost::optional<Address > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Address7033

namespace Domain
{
namespace Xml
{
struct Address7033
{
	const PUsbAddr::value_type& getBus() const
	{
		return m_bus;
	}
	void setBus(const PUsbAddr::value_type& value_)
	{
		m_bus = value_;
	}
	const PUsbPort::value_type& getDevice() const
	{
		return m_device;
	}
	void setDevice(const PUsbPort::value_type& value_)
	{
		m_device = value_;
	}

private:
	PUsbAddr::value_type m_bus;
	PUsbPort::value_type m_device;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VAddress1

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Ordered<mpl::vector<Attribute<mpl::int_<596>, Name::Strict<105> >, Fragment<Pciaddress > > >, Address7033 > > VAddress1Impl;
typedef VAddress1Impl::value_type VAddress1;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VSource

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Source7031, Element<Domain::Xml::VAddress1Impl, Name::Strict<111> > > > VSourceImpl;
typedef VSourceImpl::value_type VSource;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source12

namespace Domain
{
namespace Xml
{
struct Source12
{
	const boost::optional<EVirYesNo >& getMissing() const
	{
		return m_missing;
	}
	void setMissing(const boost::optional<EVirYesNo >& value_)
	{
		m_missing = value_;
	}
	const VSource& getSource() const
	{
		return m_source;
	}
	void setSource(const VSource& value_)
	{
		m_source = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirYesNo > m_missing;
	VSource m_source;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Interface7035

namespace Domain
{
namespace Xml
{
struct Interface7035
{
	const boost::optional<EVirYesNo >& getManaged() const
	{
		return m_managed;
	}
	void setManaged(const boost::optional<EVirYesNo >& value_)
	{
		m_managed = value_;
	}
	const Source12& getSource() const
	{
		return m_source;
	}
	void setSource(const Source12& value_)
	{
		m_source = value_;
	}
	const boost::optional<VVirtualPortProfile >& getVirtualPortProfile() const
	{
		return m_virtualPortProfile;
	}
	void setVirtualPortProfile(const boost::optional<VVirtualPortProfile >& value_)
	{
		m_virtualPortProfile = value_;
	}
	const boost::optional<EState >& getLink() const
	{
		return m_link;
	}
	void setLink(const boost::optional<EState >& value_)
	{
		m_link = value_;
	}
	const boost::optional<PUnsignedShort::value_type >& getMtu() const
	{
		return m_mtu;
	}
	void setMtu(const boost::optional<PUnsignedShort::value_type >& value_)
	{
		m_mtu = value_;
	}
	const boost::optional<Coalesce >& getCoalesce() const
	{
		return m_coalesce;
	}
	void setCoalesce(const boost::optional<Coalesce >& value_)
	{
		m_coalesce = value_;
	}
	const boost::optional<QList<VzDhcp > >& getVzDhcpList() const
	{
		return m_vzDhcpList;
	}
	void setVzDhcpList(const boost::optional<QList<VzDhcp > >& value_)
	{
		m_vzDhcpList = value_;
	}
	const boost::optional<VzDns1 >& getVzDns() const
	{
		return m_vzDns;
	}
	void setVzDns(const boost::optional<VzDns1 >& value_)
	{
		m_vzDns = value_;
	}
	const boost::optional<Target3 >& getTarget() const
	{
		return m_target;
	}
	void setTarget(const boost::optional<Target3 >& value_)
	{
		m_target = value_;
	}
	const boost::optional<Guest >& getGuest() const
	{
		return m_guest;
	}
	void setGuest(const boost::optional<Guest >& value_)
	{
		m_guest = value_;
	}
	const boost::optional<PUniMacAddr::value_type >& getMac() const
	{
		return m_mac;
	}
	void setMac(const boost::optional<PUniMacAddr::value_type >& value_)
	{
		m_mac = value_;
	}
	const QList<Ip >& getIpList() const
	{
		return m_ipList;
	}
	void setIpList(const QList<Ip >& value_)
	{
		m_ipList = value_;
	}
	const QList<Route >& getRouteList() const
	{
		return m_routeList;
	}
	void setRouteList(const QList<Route >& value_)
	{
		m_routeList = value_;
	}
	const boost::optional<PFilePath::value_type >& getScript() const
	{
		return m_script;
	}
	void setScript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_script = value_;
	}
	const boost::optional<PFilePath::value_type >& getDownscript() const
	{
		return m_downscript;
	}
	void setDownscript(const boost::optional<PFilePath::value_type >& value_)
	{
		m_downscript = value_;
	}
	const boost::optional<PObjectNameWithSlash::value_type >& getBackenddomain() const
	{
		return m_backenddomain;
	}
	void setBackenddomain(const boost::optional<PObjectNameWithSlash::value_type >& value_)
	{
		m_backenddomain = value_;
	}
	const boost::optional<PType::value_type >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<PType::value_type >& value_)
	{
		m_model = value_;
	}
	const boost::optional<Backend >& getBackend() const
	{
		return m_backend;
	}
	void setBackend(const boost::optional<Backend >& value_)
	{
		m_backend = value_;
	}
	const boost::optional<Driver3 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver3 >& value_)
	{
		m_driver = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<FilterrefNodeAttributes >& getFilterref() const
	{
		return m_filterref;
	}
	void setFilterref(const boost::optional<FilterrefNodeAttributes >& value_)
	{
		m_filterref = value_;
	}
	const boost::optional<Tune >& getTune() const
	{
		return m_tune;
	}
	void setTune(const boost::optional<Tune >& value_)
	{
		m_tune = value_;
	}
	const boost::optional<Boot >& getBoot() const
	{
		return m_boot;
	}
	void setBoot(const boost::optional<Boot >& value_)
	{
		m_boot = value_;
	}
	const boost::optional<Rom >& getRom() const
	{
		return m_rom;
	}
	void setRom(const boost::optional<Rom >& value_)
	{
		m_rom = value_;
	}
	const boost::optional<Bandwidth1 >& getBandwidth() const
	{
		return m_bandwidth;
	}
	void setBandwidth(const boost::optional<Bandwidth1 >& value_)
	{
		m_bandwidth = value_;
	}
	const boost::optional<QList<Tag > >& getVlan() const
	{
		return m_vlan;
	}
	void setVlan(const boost::optional<QList<Tag > >& value_)
	{
		m_vlan = value_;
	}
	const boost::optional<Port >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<Port >& value_)
	{
		m_port = value_;
	}
	const boost::optional<VTeaming >& getTeaming() const
	{
		return m_teaming;
	}
	void setTeaming(const boost::optional<VTeaming >& value_)
	{
		m_teaming = value_;
	}

private:
	boost::optional<EVirYesNo > m_managed;
	Source12 m_source;
	boost::optional<VVirtualPortProfile > m_virtualPortProfile;
	boost::optional<EState > m_link;
	boost::optional<PUnsignedShort::value_type > m_mtu;
	boost::optional<Coalesce > m_coalesce;
	boost::optional<QList<VzDhcp > > m_vzDhcpList;
	boost::optional<VzDns1 > m_vzDns;
	boost::optional<Target3 > m_target;
	boost::optional<Guest > m_guest;
	boost::optional<PUniMacAddr::value_type > m_mac;
	QList<Ip > m_ipList;
	QList<Route > m_routeList;
	boost::optional<PFilePath::value_type > m_script;
	boost::optional<PFilePath::value_type > m_downscript;
	boost::optional<PObjectNameWithSlash::value_type > m_backenddomain;
	boost::optional<PType::value_type > m_model;
	boost::optional<Backend > m_backend;
	boost::optional<Driver3 > m_driver;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
	boost::optional<FilterrefNodeAttributes > m_filterref;
	boost::optional<Tune > m_tune;
	boost::optional<Boot > m_boot;
	boost::optional<Rom > m_rom;
	boost::optional<Bandwidth1 > m_bandwidth;
	boost::optional<QList<Tag > > m_vlan;
	boost::optional<Port > m_port;
	boost::optional<VTeaming > m_teaming;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VInterface

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Interface7022, Interface7023, Interface7024, Interface7025, Interface7026, Ordered<mpl::vector<Attribute<mpl::int_<669>, Name::Strict<105> >, Fragment<InterfaceOptions > > >, Interface7028, Interface7029, Interface7030, Interface7035 > > VInterfaceImpl;
typedef VInterfaceImpl::value_type VInterface;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Interface

namespace Domain
{
namespace Xml
{
struct Interface
{
	const VInterface& getInterface() const
	{
		return m_interface;
	}
	void setInterface(const VInterface& value_)
	{
		m_interface = value_;
	}
	const boost::optional<EVirYesNo >& getTrustGuestRxFilters() const
	{
		return m_trustGuestRxFilters;
	}
	void setTrustGuestRxFilters(const boost::optional<EVirYesNo >& value_)
	{
		m_trustGuestRxFilters = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VInterface m_interface;
	boost::optional<EVirYesNo > m_trustGuestRxFilters;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous9430

namespace Domain
{
namespace Xml
{
struct Anonymous9430
{
	const boost::optional<EModel7 >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<EModel7 >& value_)
	{
		m_model = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	boost::optional<EModel7 > m_model;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Input

namespace Domain
{
namespace Xml
{
struct Input
{
	Input();

	EType13 getType() const
	{
		return m_type;
	}
	void setType(EType13 value_)
	{
		m_type = value_;
	}
	const boost::optional<EBus1 >& getBus() const
	{
		return m_bus;
	}
	void setBus(const boost::optional<EBus1 >& value_)
	{
		m_bus = value_;
	}
	const boost::optional<Anonymous9430 >& getAnonymous9430() const
	{
		return m_anonymous9430;
	}
	void setAnonymous9430(const boost::optional<Anonymous9430 >& value_)
	{
		m_anonymous9430 = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EType13 m_type;
	boost::optional<EBus1 > m_bus;
	boost::optional<Anonymous9430 > m_anonymous9430;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Sound

namespace Domain
{
namespace Xml
{
struct Sound
{
	Sound();

	EModel8 getModel() const
	{
		return m_model;
	}
	void setModel(EModel8 value_)
	{
		m_model = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<VUint8 >& getAudio() const
	{
		return m_audio;
	}
	void setAudio(const boost::optional<VUint8 >& value_)
	{
		m_audio = value_;
	}
	const QList<EType14 >& getCodecList() const
	{
		return m_codecList;
	}
	void setCodecList(const QList<EType14 >& value_)
	{
		m_codecList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EModel8 m_model;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
	boost::optional<VUint8 > m_audio;
	QList<EType14 > m_codecList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source13

namespace Domain
{
namespace Xml
{
struct Source13
{
	const boost::optional<EStartupPolicy >& getStartupPolicy() const
	{
		return m_startupPolicy;
	}
	void setStartupPolicy(const boost::optional<EStartupPolicy >& value_)
	{
		m_startupPolicy = value_;
	}
	const Pciaddress& getAddress() const
	{
		return m_address;
	}
	void setAddress(const Pciaddress& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EStartupPolicy > m_startupPolicy;
	Pciaddress m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevsubsyspci

namespace Domain
{
namespace Xml
{
struct Hostdevsubsyspci
{
	const boost::optional<EName7 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<EName7 >& value_)
	{
		m_driver = value_;
	}
	const boost::optional<VTeaming >& getTeaming() const
	{
		return m_teaming;
	}
	void setTeaming(const boost::optional<VTeaming >& value_)
	{
		m_teaming = value_;
	}
	const Source13& getSource() const
	{
		return m_source;
	}
	void setSource(const Source13& value_)
	{
		m_source = value_;
	}

private:
	boost::optional<EName7 > m_driver;
	boost::optional<VTeaming > m_teaming;
	Source13 m_source;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source7072

namespace Domain
{
namespace Xml
{
struct Source7072
{
	const Usbproduct& getUsbproduct() const
	{
		return m_usbproduct;
	}
	void setUsbproduct(const Usbproduct& value_)
	{
		m_usbproduct = value_;
	}
	const boost::optional<Address >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<Address >& value_)
	{
		m_address = value_;
	}

private:
	Usbproduct m_usbproduct;
	boost::optional<Address > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VSource1

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Source7072, Element<Domain::Xml::Address, Name::Strict<111> > > > VSource1Impl;
typedef VSource1Impl::value_type VSource1;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source14

namespace Domain
{
namespace Xml
{
struct Source14
{
	const boost::optional<EStartupPolicy >& getStartupPolicy() const
	{
		return m_startupPolicy;
	}
	void setStartupPolicy(const boost::optional<EStartupPolicy >& value_)
	{
		m_startupPolicy = value_;
	}
	const VSource1& getSource() const
	{
		return m_source;
	}
	void setSource(const VSource1& value_)
	{
		m_source = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EStartupPolicy > m_startupPolicy;
	VSource1 m_source;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevsubsysusb

namespace Domain
{
namespace Xml
{
struct Hostdevsubsysusb
{
	const boost::optional<EVirYesNo >& getReplug() const
	{
		return m_replug;
	}
	void setReplug(const boost::optional<EVirYesNo >& value_)
	{
		m_replug = value_;
	}
	const Source14& getSource() const
	{
		return m_source;
	}
	void setSource(const Source14& value_)
	{
		m_source = value_;
	}

private:
	boost::optional<EVirYesNo > m_replug;
	Source14 m_source;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Parentaddr

namespace Domain
{
namespace Xml
{
struct Parentaddr
{
	const boost::optional<PPositiveInteger::value_type >& getUniqueId() const
	{
		return m_uniqueId;
	}
	void setUniqueId(const boost::optional<PPositiveInteger::value_type >& value_)
	{
		m_uniqueId = value_;
	}
	const Pciaddress& getAddress() const
	{
		return m_address;
	}
	void setAddress(const Pciaddress& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PPositiveInteger::value_type > m_uniqueId;
	Pciaddress m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice112

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Attribute<QString, Name::Strict<107> >, Element<Domain::Xml::Parentaddr, Name::Strict<109> > > > VChoice112Impl;
typedef VChoice112Impl::value_type VChoice112;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Adapter118

namespace Domain
{
namespace Xml
{
struct Adapter118
{
	const boost::optional<QString >& getParent() const
	{
		return m_parent;
	}
	void setParent(const boost::optional<QString >& value_)
	{
		m_parent = value_;
	}
	const boost::optional<EVirYesNo >& getManaged() const
	{
		return m_managed;
	}
	void setManaged(const boost::optional<EVirYesNo >& value_)
	{
		m_managed = value_;
	}
	const boost::optional<PWwn::value_type >& getParentWwnn() const
	{
		return m_parentWwnn;
	}
	void setParentWwnn(const boost::optional<PWwn::value_type >& value_)
	{
		m_parentWwnn = value_;
	}
	const boost::optional<PWwn::value_type >& getParentWwpn() const
	{
		return m_parentWwpn;
	}
	void setParentWwpn(const boost::optional<PWwn::value_type >& value_)
	{
		m_parentWwpn = value_;
	}
	const boost::optional<PWwn::value_type >& getParentFabricWwn() const
	{
		return m_parentFabricWwn;
	}
	void setParentFabricWwn(const boost::optional<PWwn::value_type >& value_)
	{
		m_parentFabricWwn = value_;
	}
	const PWwn::value_type& getWwnn() const
	{
		return m_wwnn;
	}
	void setWwnn(const PWwn::value_type& value_)
	{
		m_wwnn = value_;
	}
	const PWwn::value_type& getWwpn() const
	{
		return m_wwpn;
	}
	void setWwpn(const PWwn::value_type& value_)
	{
		m_wwpn = value_;
	}

private:
	boost::optional<QString > m_parent;
	boost::optional<EVirYesNo > m_managed;
	boost::optional<PWwn::value_type > m_parentWwnn;
	boost::optional<PWwn::value_type > m_parentWwpn;
	boost::optional<PWwn::value_type > m_parentFabricWwn;
	PWwn::value_type m_wwnn;
	PWwn::value_type m_wwpn;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VAdapter

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Ordered<mpl::vector<Optional<Attribute<mpl::int_<106>, Name::Strict<105> > >, Domain::Xml::VChoice112Impl > >, Adapter118 > > VAdapterImpl;
typedef VAdapterImpl::value_type VAdapter;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Scsiaddress

namespace Domain
{
namespace Xml
{
struct Scsiaddress
{
	const PDriveBus::value_type& getBus() const
	{
		return m_bus;
	}
	void setBus(const PDriveBus::value_type& value_)
	{
		m_bus = value_;
	}
	const PDriveTarget::value_type& getTarget() const
	{
		return m_target;
	}
	void setTarget(const PDriveTarget::value_type& value_)
	{
		m_target = value_;
	}
	const PDriveUnit::value_type& getUnit() const
	{
		return m_unit;
	}
	void setUnit(const PDriveUnit::value_type& value_)
	{
		m_unit = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PDriveBus::value_type m_bus;
	PDriveTarget::value_type m_target;
	PDriveUnit::value_type m_unit;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source7074

namespace Domain
{
namespace Xml
{
struct Source7074
{
	const boost::optional<EProtocol1 >& getProtocol() const
	{
		return m_protocol;
	}
	void setProtocol(const boost::optional<EProtocol1 >& value_)
	{
		m_protocol = value_;
	}
	const VAdapter& getAdapter() const
	{
		return m_adapter;
	}
	void setAdapter(const VAdapter& value_)
	{
		m_adapter = value_;
	}
	const Scsiaddress& getAddress() const
	{
		return m_address;
	}
	void setAddress(const Scsiaddress& value_)
	{
		m_address = value_;
	}

private:
	boost::optional<EProtocol1 > m_protocol;
	VAdapter m_adapter;
	Scsiaddress m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Host1

namespace Domain
{
namespace Xml
{
struct Host1
{
	const QString& getName() const
	{
		return m_name;
	}
	void setName(const QString& value_)
	{
		m_name = value_;
	}
	const boost::optional<PPortNumber::value_type >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<PPortNumber::value_type >& value_)
	{
		m_port = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	QString m_name;
	boost::optional<PPortNumber::value_type > m_port;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source7075

namespace Domain
{
namespace Xml
{
struct Source7075
{
	Source7075();

	EProtocol2 getProtocol() const
	{
		return m_protocol;
	}
	void setProtocol(EProtocol2 value_)
	{
		m_protocol = value_;
	}
	const QString& getName() const
	{
		return m_name;
	}
	void setName(const QString& value_)
	{
		m_name = value_;
	}
	const QList<Host1 >& getHostList() const
	{
		return m_hostList;
	}
	void setHostList(const QList<Host1 >& value_)
	{
		m_hostList = value_;
	}
	const boost::optional<Auth >& getAuth() const
	{
		return m_auth;
	}
	void setAuth(const boost::optional<Auth >& value_)
	{
		m_auth = value_;
	}
	const boost::optional<QString >& getInitiator() const
	{
		return m_initiator;
	}
	void setInitiator(const boost::optional<QString >& value_)
	{
		m_initiator = value_;
	}

private:
	EProtocol2 m_protocol;
	QString m_name;
	QList<Host1 > m_hostList;
	boost::optional<Auth > m_auth;
	boost::optional<QString > m_initiator;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VSource2

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Source7074, Source7075 > > VSource2Impl;
typedef VSource2Impl::value_type VSource2;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevsubsysscsi

namespace Domain
{
namespace Xml
{
struct Hostdevsubsysscsi
{
	const boost::optional<ESgio1 >& getSgio() const
	{
		return m_sgio;
	}
	void setSgio(const boost::optional<ESgio1 >& value_)
	{
		m_sgio = value_;
	}
	const boost::optional<EVirYesNo >& getRawio() const
	{
		return m_rawio;
	}
	void setRawio(const boost::optional<EVirYesNo >& value_)
	{
		m_rawio = value_;
	}
	const VSource2& getSource() const
	{
		return m_source;
	}
	void setSource(const VSource2& value_)
	{
		m_source = value_;
	}

private:
	boost::optional<ESgio1 > m_sgio;
	boost::optional<EVirYesNo > m_rawio;
	VSource2 m_source;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VHostdevsubsys

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Hostdevsubsyspci, Hostdevsubsysusb, Hostdevsubsysscsi > > VHostdevsubsysImpl;
typedef VHostdevsubsysImpl::value_type VHostdevsubsys;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevsubsys

namespace Domain
{
namespace Xml
{
struct Hostdevsubsys
{
	const boost::optional<EVirYesNo >& getManaged() const
	{
		return m_managed;
	}
	void setManaged(const boost::optional<EVirYesNo >& value_)
	{
		m_managed = value_;
	}
	const VHostdevsubsys& getHostdevsubsys() const
	{
		return m_hostdevsubsys;
	}
	void setHostdevsubsys(const VHostdevsubsys& value_)
	{
		m_hostdevsubsys = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	boost::optional<EVirYesNo > m_managed;
	VHostdevsubsys m_hostdevsubsys;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Ip1

namespace Domain
{
namespace Xml
{
struct Ip1
{
	const VIpAddr& getAddress() const
	{
		return m_address;
	}
	void setAddress(const VIpAddr& value_)
	{
		m_address = value_;
	}
	const boost::optional<PAddrFamily::value_type >& getFamily() const
	{
		return m_family;
	}
	void setFamily(const boost::optional<PAddrFamily::value_type >& value_)
	{
		m_family = value_;
	}
	const boost::optional<VIpPrefix >& getPrefix() const
	{
		return m_prefix;
	}
	void setPrefix(const boost::optional<VIpPrefix >& value_)
	{
		m_prefix = value_;
	}
	const boost::optional<VIpAddr >& getPeer() const
	{
		return m_peer;
	}
	void setPeer(const boost::optional<VIpAddr >& value_)
	{
		m_peer = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VIpAddr m_address;
	boost::optional<PAddrFamily::value_type > m_family;
	boost::optional<VIpPrefix > m_prefix;
	boost::optional<VIpAddr > m_peer;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct InterfaceIpInfo

namespace Domain
{
namespace Xml
{
struct InterfaceIpInfo
{
	const QList<Ip1 >& getIpList() const
	{
		return m_ipList;
	}
	void setIpList(const QList<Ip1 >& value_)
	{
		m_ipList = value_;
	}
	const QList<Route >& getRouteList() const
	{
		return m_routeList;
	}
	void setRouteList(const QList<Route >& value_)
	{
		m_routeList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	QList<Ip1 > m_ipList;
	QList<Route > m_routeList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevcapsnet

namespace Domain
{
namespace Xml
{
struct Hostdevcapsnet
{
	const PDeviceName::value_type& getSource() const
	{
		return m_source;
	}
	void setSource(const PDeviceName::value_type& value_)
	{
		m_source = value_;
	}
	const InterfaceIpInfo& getInterfaceIpInfo() const
	{
		return m_interfaceIpInfo;
	}
	void setInterfaceIpInfo(const InterfaceIpInfo& value_)
	{
		m_interfaceIpInfo = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	PDeviceName::value_type m_source;
	InterfaceIpInfo m_interfaceIpInfo;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VHostdevcaps

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Ordered<mpl::vector<Ordered<mpl::vector<Attribute<mpl::int_<938>, Name::Strict<105> >, Element<Element<Text<Domain::Xml::PAbsFilePath >, Name::Strict<502> >, Name::Strict<501> > > > > >, Ordered<mpl::vector<Ordered<mpl::vector<Attribute<mpl::int_<939>, Name::Strict<105> >, Element<Element<Text<Domain::Xml::PAbsFilePath >, Name::Strict<940> >, Name::Strict<501> > > > > >, Fragment<Hostdevcapsnet > > > VHostdevcapsImpl;
typedef VHostdevcapsImpl::value_type VHostdevcaps;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice7065

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Fragment<Hostdevsubsys >, Ordered<mpl::vector<Ordered<mpl::vector<Attribute<mpl::int_<926>, Name::Strict<379> >, Domain::Xml::VHostdevcapsImpl > > > > > > VChoice7065Impl;
typedef VChoice7065Impl::value_type VChoice7065;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hostdev

namespace Domain
{
namespace Xml
{
struct Hostdev
{
	Hostdev();

	const VChoice7065& getChoice7065() const
	{
		return m_choice7065;
	}
	void setChoice7065(const VChoice7065& value_)
	{
		m_choice7065 = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<Boot >& getBoot() const
	{
		return m_boot;
	}
	void setBoot(const boost::optional<Boot >& value_)
	{
		m_boot = value_;
	}
	const boost::optional<Rom >& getRom() const
	{
		return m_rom;
	}
	void setRom(const boost::optional<Rom >& value_)
	{
		m_rom = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	bool getReadonly() const
	{
		return m_readonly;
	}
	void setReadonly(bool value_)
	{
		m_readonly = value_;
	}
	bool getShareable() const
	{
		return m_shareable;
	}
	void setShareable(bool value_)
	{
		m_shareable = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VChoice7065 m_choice7065;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<Boot > m_boot;
	boost::optional<Rom > m_rom;
	boost::optional<VAddress > m_address;
	bool m_readonly;
	bool m_shareable;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7038

namespace Domain
{
namespace Xml
{
struct Graphics7038
{
	const boost::optional<QString >& getDisplay() const
	{
		return m_display;
	}
	void setDisplay(const boost::optional<QString >& value_)
	{
		m_display = value_;
	}
	const boost::optional<QString >& getXauth() const
	{
		return m_xauth;
	}
	void setXauth(const boost::optional<QString >& value_)
	{
		m_xauth = value_;
	}
	const boost::optional<EVirYesNo >& getFullscreen() const
	{
		return m_fullscreen;
	}
	void setFullscreen(const boost::optional<EVirYesNo >& value_)
	{
		m_fullscreen = value_;
	}
	const boost::optional<EVirYesNo >& getGl() const
	{
		return m_gl;
	}
	void setGl(const boost::optional<EVirYesNo >& value_)
	{
		m_gl = value_;
	}

private:
	boost::optional<QString > m_display;
	boost::optional<QString > m_xauth;
	boost::optional<EVirYesNo > m_fullscreen;
	boost::optional<EVirYesNo > m_gl;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Variant5124

namespace Domain
{
namespace Xml
{
struct Variant5124
{
	const boost::optional<PPortNumber::value_type >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<PPortNumber::value_type >& value_)
	{
		m_port = value_;
	}
	const boost::optional<EVirYesNo >& getAutoport() const
	{
		return m_autoport;
	}
	void setAutoport(const boost::optional<EVirYesNo >& value_)
	{
		m_autoport = value_;
	}
	const boost::optional<PPortNumber::value_type >& getWebsocket() const
	{
		return m_websocket;
	}
	void setWebsocket(const boost::optional<PPortNumber::value_type >& value_)
	{
		m_websocket = value_;
	}
	const boost::optional<PAddrIPorName::value_type >& getListen() const
	{
		return m_listen;
	}
	void setListen(const boost::optional<PAddrIPorName::value_type >& value_)
	{
		m_listen = value_;
	}
	const boost::optional<ESharePolicy >& getSharePolicy() const
	{
		return m_sharePolicy;
	}
	void setSharePolicy(const boost::optional<ESharePolicy >& value_)
	{
		m_sharePolicy = value_;
	}
	const boost::optional<EVirYesNo >& getPowerControl() const
	{
		return m_powerControl;
	}
	void setPowerControl(const boost::optional<EVirYesNo >& value_)
	{
		m_powerControl = value_;
	}

private:
	boost::optional<PPortNumber::value_type > m_port;
	boost::optional<EVirYesNo > m_autoport;
	boost::optional<PPortNumber::value_type > m_websocket;
	boost::optional<PAddrIPorName::value_type > m_listen;
	boost::optional<ESharePolicy > m_sharePolicy;
	boost::optional<EVirYesNo > m_powerControl;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice5126

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Variant5124, Optional<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<521> > > > > VChoice5126Impl;
typedef VChoice5126Impl::value_type VChoice5126;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Listen7044

namespace Domain
{
namespace Xml
{
struct Listen7044
{
	const QString& getNetwork() const
	{
		return m_network;
	}
	void setNetwork(const QString& value_)
	{
		m_network = value_;
	}
	const boost::optional<PAddrIPorName::value_type >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<PAddrIPorName::value_type >& value_)
	{
		m_address = value_;
	}

private:
	QString m_network;
	boost::optional<PAddrIPorName::value_type > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Listen9392

namespace Domain
{
namespace Xml
{
struct Listen9392
{
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VListen

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Ordered<mpl::vector<Attribute<mpl::int_<111>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::PAddrIPorName, Name::Strict<111> > > > >, Listen7044, Ordered<mpl::vector<Attribute<mpl::int_<521>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<521> > > > >, Listen9392 > > VListenImpl;
typedef VListenImpl::value_type VListen;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7039

namespace Domain
{
namespace Xml
{
struct Graphics7039
{
	const VChoice5126& getChoice5126() const
	{
		return m_choice5126;
	}
	void setChoice5126(const VChoice5126& value_)
	{
		m_choice5126 = value_;
	}
	const boost::optional<QString >& getPasswd() const
	{
		return m_passwd;
	}
	void setPasswd(const boost::optional<QString >& value_)
	{
		m_passwd = value_;
	}
	const boost::optional<QString >& getKeymap() const
	{
		return m_keymap;
	}
	void setKeymap(const boost::optional<QString >& value_)
	{
		m_keymap = value_;
	}
	const boost::optional<PPasswdValidTo::value_type >& getPasswdValidTo() const
	{
		return m_passwdValidTo;
	}
	void setPasswdValidTo(const boost::optional<PPasswdValidTo::value_type >& value_)
	{
		m_passwdValidTo = value_;
	}
	const boost::optional<EConnected >& getConnected() const
	{
		return m_connected;
	}
	void setConnected(const boost::optional<EConnected >& value_)
	{
		m_connected = value_;
	}
	const QList<VListen >& getListenList() const
	{
		return m_listenList;
	}
	void setListenList(const QList<VListen >& value_)
	{
		m_listenList = value_;
	}

private:
	VChoice5126 m_choice5126;
	boost::optional<QString > m_passwd;
	boost::optional<QString > m_keymap;
	boost::optional<PPasswdValidTo::value_type > m_passwdValidTo;
	boost::optional<EConnected > m_connected;
	QList<VListen > m_listenList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Channel

namespace Domain
{
namespace Xml
{
struct Channel
{
	Channel();

	EName8 getName() const
	{
		return m_name;
	}
	void setName(EName8 value_)
	{
		m_name = value_;
	}
	EMode10 getMode() const
	{
		return m_mode;
	}
	void setMode(EMode10 value_)
	{
		m_mode = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EName8 m_name;
	EMode10 m_mode;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Gl

namespace Domain
{
namespace Xml
{
struct Gl
{
	Gl();

	EVirYesNo getEnable() const
	{
		return m_enable;
	}
	void setEnable(EVirYesNo value_)
	{
		m_enable = value_;
	}
	const boost::optional<PAbsFilePath::value_type >& getRendernode() const
	{
		return m_rendernode;
	}
	void setRendernode(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_rendernode = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EVirYesNo m_enable;
	boost::optional<PAbsFilePath::value_type > m_rendernode;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7040

namespace Domain
{
namespace Xml
{
struct Graphics7040
{
	const boost::optional<PPortNumber::value_type >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<PPortNumber::value_type >& value_)
	{
		m_port = value_;
	}
	const boost::optional<PPortNumber::value_type >& getTlsPort() const
	{
		return m_tlsPort;
	}
	void setTlsPort(const boost::optional<PPortNumber::value_type >& value_)
	{
		m_tlsPort = value_;
	}
	const boost::optional<EVirYesNo >& getAutoport() const
	{
		return m_autoport;
	}
	void setAutoport(const boost::optional<EVirYesNo >& value_)
	{
		m_autoport = value_;
	}
	const boost::optional<PAddrIPorName::value_type >& getListen() const
	{
		return m_listen;
	}
	void setListen(const boost::optional<PAddrIPorName::value_type >& value_)
	{
		m_listen = value_;
	}
	const boost::optional<QString >& getPasswd() const
	{
		return m_passwd;
	}
	void setPasswd(const boost::optional<QString >& value_)
	{
		m_passwd = value_;
	}
	const boost::optional<QString >& getKeymap() const
	{
		return m_keymap;
	}
	void setKeymap(const boost::optional<QString >& value_)
	{
		m_keymap = value_;
	}
	const boost::optional<PPasswdValidTo::value_type >& getPasswdValidTo() const
	{
		return m_passwdValidTo;
	}
	void setPasswdValidTo(const boost::optional<PPasswdValidTo::value_type >& value_)
	{
		m_passwdValidTo = value_;
	}
	const boost::optional<EConnected1 >& getConnected() const
	{
		return m_connected;
	}
	void setConnected(const boost::optional<EConnected1 >& value_)
	{
		m_connected = value_;
	}
	const boost::optional<EDefaultMode >& getDefaultMode() const
	{
		return m_defaultMode;
	}
	void setDefaultMode(const boost::optional<EDefaultMode >& value_)
	{
		m_defaultMode = value_;
	}
	const QList<VListen >& getListenList() const
	{
		return m_listenList;
	}
	void setListenList(const QList<VListen >& value_)
	{
		m_listenList = value_;
	}
	const QList<Channel >& getChannelList() const
	{
		return m_channelList;
	}
	void setChannelList(const QList<Channel >& value_)
	{
		m_channelList = value_;
	}
	const boost::optional<ECompression >& getImage() const
	{
		return m_image;
	}
	void setImage(const boost::optional<ECompression >& value_)
	{
		m_image = value_;
	}
	const boost::optional<ECompression1 >& getJpeg() const
	{
		return m_jpeg;
	}
	void setJpeg(const boost::optional<ECompression1 >& value_)
	{
		m_jpeg = value_;
	}
	const boost::optional<ECompression2 >& getZlib() const
	{
		return m_zlib;
	}
	void setZlib(const boost::optional<ECompression2 >& value_)
	{
		m_zlib = value_;
	}
	const boost::optional<EVirOnOff >& getPlayback() const
	{
		return m_playback;
	}
	void setPlayback(const boost::optional<EVirOnOff >& value_)
	{
		m_playback = value_;
	}
	const boost::optional<EMode11 >& getStreaming() const
	{
		return m_streaming;
	}
	void setStreaming(const boost::optional<EMode11 >& value_)
	{
		m_streaming = value_;
	}
	const boost::optional<EVirYesNo >& getClipboard() const
	{
		return m_clipboard;
	}
	void setClipboard(const boost::optional<EVirYesNo >& value_)
	{
		m_clipboard = value_;
	}
	const boost::optional<EMode12 >& getMouse() const
	{
		return m_mouse;
	}
	void setMouse(const boost::optional<EMode12 >& value_)
	{
		m_mouse = value_;
	}
	const boost::optional<EVirYesNo >& getFiletransfer() const
	{
		return m_filetransfer;
	}
	void setFiletransfer(const boost::optional<EVirYesNo >& value_)
	{
		m_filetransfer = value_;
	}
	const boost::optional<Gl >& getGl() const
	{
		return m_gl;
	}
	void setGl(const boost::optional<Gl >& value_)
	{
		m_gl = value_;
	}

private:
	boost::optional<PPortNumber::value_type > m_port;
	boost::optional<PPortNumber::value_type > m_tlsPort;
	boost::optional<EVirYesNo > m_autoport;
	boost::optional<PAddrIPorName::value_type > m_listen;
	boost::optional<QString > m_passwd;
	boost::optional<QString > m_keymap;
	boost::optional<PPasswdValidTo::value_type > m_passwdValidTo;
	boost::optional<EConnected1 > m_connected;
	boost::optional<EDefaultMode > m_defaultMode;
	QList<VListen > m_listenList;
	QList<Channel > m_channelList;
	boost::optional<ECompression > m_image;
	boost::optional<ECompression1 > m_jpeg;
	boost::optional<ECompression2 > m_zlib;
	boost::optional<EVirOnOff > m_playback;
	boost::optional<EMode11 > m_streaming;
	boost::optional<EVirYesNo > m_clipboard;
	boost::optional<EMode12 > m_mouse;
	boost::optional<EVirYesNo > m_filetransfer;
	boost::optional<Gl > m_gl;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7041

namespace Domain
{
namespace Xml
{
struct Graphics7041
{
	const boost::optional<PPortNumber::value_type >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<PPortNumber::value_type >& value_)
	{
		m_port = value_;
	}
	const boost::optional<EVirYesNo >& getAutoport() const
	{
		return m_autoport;
	}
	void setAutoport(const boost::optional<EVirYesNo >& value_)
	{
		m_autoport = value_;
	}
	const boost::optional<EVirYesNo >& getReplaceUser() const
	{
		return m_replaceUser;
	}
	void setReplaceUser(const boost::optional<EVirYesNo >& value_)
	{
		m_replaceUser = value_;
	}
	const boost::optional<EVirYesNo >& getMultiUser() const
	{
		return m_multiUser;
	}
	void setMultiUser(const boost::optional<EVirYesNo >& value_)
	{
		m_multiUser = value_;
	}
	const boost::optional<PAddrIPorName::value_type >& getListen() const
	{
		return m_listen;
	}
	void setListen(const boost::optional<PAddrIPorName::value_type >& value_)
	{
		m_listen = value_;
	}
	const QList<VListen >& getListenList() const
	{
		return m_listenList;
	}
	void setListenList(const QList<VListen >& value_)
	{
		m_listenList = value_;
	}

private:
	boost::optional<PPortNumber::value_type > m_port;
	boost::optional<EVirYesNo > m_autoport;
	boost::optional<EVirYesNo > m_replaceUser;
	boost::optional<EVirYesNo > m_multiUser;
	boost::optional<PAddrIPorName::value_type > m_listen;
	QList<VListen > m_listenList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7042

namespace Domain
{
namespace Xml
{
struct Graphics7042
{
	const boost::optional<QString >& getDisplay() const
	{
		return m_display;
	}
	void setDisplay(const boost::optional<QString >& value_)
	{
		m_display = value_;
	}
	const boost::optional<EVirYesNo >& getFullscreen() const
	{
		return m_fullscreen;
	}
	void setFullscreen(const boost::optional<EVirYesNo >& value_)
	{
		m_fullscreen = value_;
	}

private:
	boost::optional<QString > m_display;
	boost::optional<EVirYesNo > m_fullscreen;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Gl1

namespace Domain
{
namespace Xml
{
struct Gl1
{
	const boost::optional<PAbsFilePath::value_type >& getRendernode() const
	{
		return m_rendernode;
	}
	void setRendernode(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_rendernode = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PAbsFilePath::value_type > m_rendernode;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VGraphics

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Graphics7038, Graphics7039, Graphics7040, Graphics7041, Graphics7042, Ordered<mpl::vector<Attribute<mpl::int_<9187>, Name::Strict<105> >, Optional<Element<Domain::Xml::Gl1, Name::Strict<9188> > > > > > > VGraphicsImpl;
typedef VGraphicsImpl::value_type VGraphics;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Driver4

namespace Domain
{
namespace Xml
{
struct Driver4
{
	const boost::optional<VirtioOptions >& getVirtioOptions() const
	{
		return m_virtioOptions;
	}
	void setVirtioOptions(const boost::optional<VirtioOptions >& value_)
	{
		m_virtioOptions = value_;
	}
	const boost::optional<EName9 >& getName() const
	{
		return m_name;
	}
	void setName(const boost::optional<EName9 >& value_)
	{
		m_name = value_;
	}
	const boost::optional<EVgaconf >& getVgaconf() const
	{
		return m_vgaconf;
	}
	void setVgaconf(const boost::optional<EVgaconf >& value_)
	{
		m_vgaconf = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<VirtioOptions > m_virtioOptions;
	boost::optional<EName9 > m_name;
	boost::optional<EVgaconf > m_vgaconf;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Model7046

namespace Domain
{
namespace Xml
{
struct Model7046
{
	const boost::optional<PUnsignedInt::value_type >& getRam() const
	{
		return m_ram;
	}
	void setRam(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_ram = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getVgamem() const
	{
		return m_vgamem;
	}
	void setVgamem(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_vgamem = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getVram64() const
	{
		return m_vram64;
	}
	void setVram64(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_vram64 = value_;
	}

private:
	boost::optional<PUnsignedInt::value_type > m_ram;
	boost::optional<PUnsignedInt::value_type > m_vgamem;
	boost::optional<PUnsignedInt::value_type > m_vram64;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VModel

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Attribute<Domain::Xml::EType15, Name::Strict<105> >, Model7046 > > VModelImpl;
typedef VModelImpl::value_type VModel;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Acceleration

namespace Domain
{
namespace Xml
{
struct Acceleration
{
	const boost::optional<EVirYesNo >& getAccel3d() const
	{
		return m_accel3d;
	}
	void setAccel3d(const boost::optional<EVirYesNo >& value_)
	{
		m_accel3d = value_;
	}
	const boost::optional<EVirYesNo >& getAccel2d() const
	{
		return m_accel2d;
	}
	void setAccel2d(const boost::optional<EVirYesNo >& value_)
	{
		m_accel2d = value_;
	}
	const boost::optional<PAbsFilePath::value_type >& getRendernode() const
	{
		return m_rendernode;
	}
	void setRendernode(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_rendernode = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirYesNo > m_accel3d;
	boost::optional<EVirYesNo > m_accel2d;
	boost::optional<PAbsFilePath::value_type > m_rendernode;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Resolution

namespace Domain
{
namespace Xml
{
struct Resolution
{
	Resolution();

	PUnsignedInt::value_type getX() const
	{
		return m_x;
	}
	void setX(PUnsignedInt::value_type value_)
	{
		m_x = value_;
	}
	PUnsignedInt::value_type getY() const
	{
		return m_y;
	}
	void setY(PUnsignedInt::value_type value_)
	{
		m_y = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PUnsignedInt::value_type m_x;
	PUnsignedInt::value_type m_y;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Model1

namespace Domain
{
namespace Xml
{
struct Model1
{
	const VModel& getModel() const
	{
		return m_model;
	}
	void setModel(const VModel& value_)
	{
		m_model = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getVram() const
	{
		return m_vram;
	}
	void setVram(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_vram = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getHeads() const
	{
		return m_heads;
	}
	void setHeads(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_heads = value_;
	}
	const boost::optional<EVirYesNo >& getPrimary() const
	{
		return m_primary;
	}
	void setPrimary(const boost::optional<EVirYesNo >& value_)
	{
		m_primary = value_;
	}
	const boost::optional<Acceleration >& getAcceleration() const
	{
		return m_acceleration;
	}
	void setAcceleration(const boost::optional<Acceleration >& value_)
	{
		m_acceleration = value_;
	}
	const boost::optional<Resolution >& getResolution() const
	{
		return m_resolution;
	}
	void setResolution(const boost::optional<Resolution >& value_)
	{
		m_resolution = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VModel m_model;
	boost::optional<PUnsignedInt::value_type > m_vram;
	boost::optional<PUnsignedInt::value_type > m_heads;
	boost::optional<EVirYesNo > m_primary;
	boost::optional<Acceleration > m_acceleration;
	boost::optional<Resolution > m_resolution;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Video

namespace Domain
{
namespace Xml
{
struct Video
{
	const boost::optional<Driver4 >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver4 >& value_)
	{
		m_driver = value_;
	}
	const boost::optional<Model1 >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<Model1 >& value_)
	{
		m_model = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<Driver4 > m_driver;
	boost::optional<Model1 > m_model;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source15

namespace Domain
{
namespace Xml
{
struct Source15
{
	const boost::optional<QString >& getMode() const
	{
		return m_mode;
	}
	void setMode(const boost::optional<QString >& value_)
	{
		m_mode = value_;
	}
	const boost::optional<QString >& getPath() const
	{
		return m_path;
	}
	void setPath(const boost::optional<QString >& value_)
	{
		m_path = value_;
	}
	const boost::optional<QString >& getHost() const
	{
		return m_host;
	}
	void setHost(const boost::optional<QString >& value_)
	{
		m_host = value_;
	}
	const boost::optional<QString >& getService() const
	{
		return m_service;
	}
	void setService(const boost::optional<QString >& value_)
	{
		m_service = value_;
	}
	const boost::optional<QString >& getWiremode() const
	{
		return m_wiremode;
	}
	void setWiremode(const boost::optional<QString >& value_)
	{
		m_wiremode = value_;
	}
	const boost::optional<QString >& getChannel() const
	{
		return m_channel;
	}
	void setChannel(const boost::optional<QString >& value_)
	{
		m_channel = value_;
	}
	const boost::optional<QString >& getMaster() const
	{
		return m_master;
	}
	void setMaster(const boost::optional<QString >& value_)
	{
		m_master = value_;
	}
	const boost::optional<QString >& getSlave() const
	{
		return m_slave;
	}
	void setSlave(const boost::optional<QString >& value_)
	{
		m_slave = value_;
	}
	const boost::optional<EVirOnOff >& getAppend() const
	{
		return m_append;
	}
	void setAppend(const boost::optional<EVirOnOff >& value_)
	{
		m_append = value_;
	}
	const boost::optional<Seclabel >& getSeclabel() const
	{
		return m_seclabel;
	}
	void setSeclabel(const boost::optional<Seclabel >& value_)
	{
		m_seclabel = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<QString > m_mode;
	boost::optional<QString > m_path;
	boost::optional<QString > m_host;
	boost::optional<QString > m_service;
	boost::optional<QString > m_wiremode;
	boost::optional<QString > m_channel;
	boost::optional<QString > m_master;
	boost::optional<QString > m_slave;
	boost::optional<EVirOnOff > m_append;
	boost::optional<Seclabel > m_seclabel;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Protocol

namespace Domain
{
namespace Xml
{
struct Protocol
{
	const boost::optional<EType16 >& getType() const
	{
		return m_type;
	}
	void setType(const boost::optional<EType16 >& value_)
	{
		m_type = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EType16 > m_type;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Log

namespace Domain
{
namespace Xml
{
struct Log
{
	const PAbsFilePath::value_type& getFile() const
	{
		return m_file;
	}
	void setFile(const PAbsFilePath::value_type& value_)
	{
		m_file = value_;
	}
	const boost::optional<EVirOnOff >& getAppend() const
	{
		return m_append;
	}
	void setAppend(const boost::optional<EVirOnOff >& value_)
	{
		m_append = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PAbsFilePath::value_type m_file;
	boost::optional<EVirOnOff > m_append;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct QemucdevSrcDef

namespace Domain
{
namespace Xml
{
struct QemucdevSrcDef
{
	const QList<Source15 >& getSourceList() const
	{
		return m_sourceList;
	}
	void setSourceList(const QList<Source15 >& value_)
	{
		m_sourceList = value_;
	}
	const boost::optional<Protocol >& getProtocol() const
	{
		return m_protocol;
	}
	void setProtocol(const boost::optional<Protocol >& value_)
	{
		m_protocol = value_;
	}
	const boost::optional<Log >& getLog() const
	{
		return m_log;
	}
	void setLog(const boost::optional<Log >& value_)
	{
		m_log = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;

private:
	QList<Source15 > m_sourceList;
	boost::optional<Protocol > m_protocol;
	boost::optional<Log > m_log;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice8004

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Optional<Attribute<Domain::Xml::EType17, Name::Strict<105> > >, Optional<Attribute<Domain::Xml::EType18, Name::Strict<105> > > > > VChoice8004Impl;
typedef VChoice8004Impl::value_type VChoice8004;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Target4

namespace Domain
{
namespace Xml
{
struct Target4
{
	const VChoice8004& getChoice8004() const
	{
		return m_choice8004;
	}
	void setChoice8004(const VChoice8004& value_)
	{
		m_choice8004 = value_;
	}
	const boost::optional<QString >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<QString >& value_)
	{
		m_port = value_;
	}
	const boost::optional<EName10 >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<EName10 >& value_)
	{
		m_model = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VChoice8004 m_choice8004;
	boost::optional<QString > m_port;
	boost::optional<EName10 > m_model;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Qemucdev

namespace Domain
{
namespace Xml
{
struct Qemucdev
{
	Qemucdev();

	EQemucdevSrcTypeChoice getType() const
	{
		return m_type;
	}
	void setType(EQemucdevSrcTypeChoice value_)
	{
		m_type = value_;
	}
	const boost::optional<PAbsFilePath::value_type >& getTty() const
	{
		return m_tty;
	}
	void setTty(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_tty = value_;
	}
	const QemucdevSrcDef& getQemucdevSrcDef() const
	{
		return m_qemucdevSrcDef;
	}
	void setQemucdevSrcDef(const QemucdevSrcDef& value_)
	{
		m_qemucdevSrcDef = value_;
	}
	const boost::optional<Target4 >& getTarget() const
	{
		return m_target;
	}
	void setTarget(const boost::optional<Target4 >& value_)
	{
		m_target = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EQemucdevSrcTypeChoice m_type;
	boost::optional<PAbsFilePath::value_type > m_tty;
	QemucdevSrcDef m_qemucdevSrcDef;
	boost::optional<Target4 > m_target;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<VAddress > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VConsole

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Optional<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<811> > >, Qemucdev > > VConsoleImpl;
typedef VConsoleImpl::value_type VConsole;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Target5

namespace Domain
{
namespace Xml
{
struct Target5
{
	const QString& getAddress() const
	{
		return m_address;
	}
	void setAddress(const QString& value_)
	{
		m_address = value_;
	}
	const QString& getPort() const
	{
		return m_port;
	}
	void setPort(const QString& value_)
	{
		m_port = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	QString m_address;
	QString m_port;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Target6

namespace Domain
{
namespace Xml
{
struct Target6
{
	const boost::optional<QString >& getName() const
	{
		return m_name;
	}
	void setName(const boost::optional<QString >& value_)
	{
		m_name = value_;
	}
	const boost::optional<EState1 >& getState() const
	{
		return m_state;
	}
	void setState(const boost::optional<EState1 >& value_)
	{
		m_state = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<QString > m_name;
	boost::optional<EState1 > m_state;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice9400

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Element<Domain::Xml::Target5, Name::Strict<323> >, Element<Domain::Xml::Target6, Name::Strict<323> > > > VChoice9400Impl;
typedef VChoice9400Impl::value_type VChoice9400;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Channel1

namespace Domain
{
namespace Xml
{
struct Channel1
{
	Channel1();

	EQemucdevSrcTypeChoice getType() const
	{
		return m_type;
	}
	void setType(EQemucdevSrcTypeChoice value_)
	{
		m_type = value_;
	}
	const QemucdevSrcDef& getQemucdevSrcDef() const
	{
		return m_qemucdevSrcDef;
	}
	void setQemucdevSrcDef(const QemucdevSrcDef& value_)
	{
		m_qemucdevSrcDef = value_;
	}
	const VChoice9400& getChoice9400() const
	{
		return m_choice9400;
	}
	void setChoice9400(const VChoice9400& value_)
	{
		m_choice9400 = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EQemucdevSrcTypeChoice m_type;
	QemucdevSrcDef m_qemucdevSrcDef;
	VChoice9400 m_choice9400;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Smartcard7059

namespace Domain
{
namespace Xml
{
struct Smartcard7059
{
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Smartcard7060

namespace Domain
{
namespace Xml
{
struct Smartcard7060
{
	const QString& getCertificate() const
	{
		return m_certificate;
	}
	void setCertificate(const QString& value_)
	{
		m_certificate = value_;
	}
	const QString& getCertificate2() const
	{
		return m_certificate2;
	}
	void setCertificate2(const QString& value_)
	{
		m_certificate2 = value_;
	}
	const QString& getCertificate3() const
	{
		return m_certificate3;
	}
	void setCertificate3(const QString& value_)
	{
		m_certificate3 = value_;
	}
	const boost::optional<PAbsDirPath::value_type >& getDatabase() const
	{
		return m_database;
	}
	void setDatabase(const boost::optional<PAbsDirPath::value_type >& value_)
	{
		m_database = value_;
	}

private:
	QString m_certificate;
	QString m_certificate2;
	QString m_certificate3;
	boost::optional<PAbsDirPath::value_type > m_database;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Smartcard7061

namespace Domain
{
namespace Xml
{
struct Smartcard7061
{
	Smartcard7061();

	EQemucdevSrcTypeChoice getType() const
	{
		return m_type;
	}
	void setType(EQemucdevSrcTypeChoice value_)
	{
		m_type = value_;
	}
	const QemucdevSrcDef& getQemucdevSrcDef() const
	{
		return m_qemucdevSrcDef;
	}
	void setQemucdevSrcDef(const QemucdevSrcDef& value_)
	{
		m_qemucdevSrcDef = value_;
	}
	const boost::optional<Target4 >& getTarget() const
	{
		return m_target;
	}
	void setTarget(const boost::optional<Target4 >& value_)
	{
		m_target = value_;
	}

private:
	EQemucdevSrcTypeChoice m_type;
	QemucdevSrcDef m_qemucdevSrcDef;
	boost::optional<Target4 > m_target;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VSmartcard

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Smartcard7059, Smartcard7060, Smartcard7061 > > VSmartcardImpl;
typedef VSmartcardImpl::value_type VSmartcard;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Smartcard

namespace Domain
{
namespace Xml
{
struct Smartcard
{
	const VSmartcard& getSmartcard() const
	{
		return m_smartcard;
	}
	void setSmartcard(const VSmartcard& value_)
	{
		m_smartcard = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VSmartcard m_smartcard;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Hub

namespace Domain
{
namespace Xml
{
struct Hub
{
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Redirdev

namespace Domain
{
namespace Xml
{
struct Redirdev
{
	Redirdev();

	EQemucdevSrcTypeChoice getType() const
	{
		return m_type;
	}
	void setType(EQemucdevSrcTypeChoice value_)
	{
		m_type = value_;
	}
	const QemucdevSrcDef& getQemucdevSrcDef() const
	{
		return m_qemucdevSrcDef;
	}
	void setQemucdevSrcDef(const QemucdevSrcDef& value_)
	{
		m_qemucdevSrcDef = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<Boot >& getBoot() const
	{
		return m_boot;
	}
	void setBoot(const boost::optional<Boot >& value_)
	{
		m_boot = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EQemucdevSrcTypeChoice m_type;
	QemucdevSrcDef m_qemucdevSrcDef;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
	boost::optional<Boot > m_boot;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Usbdev

namespace Domain
{
namespace Xml
{
struct Usbdev
{
	Usbdev();

	EVirYesNo getAllow() const
	{
		return m_allow;
	}
	void setAllow(EVirYesNo value_)
	{
		m_allow = value_;
	}
	const boost::optional<VClass >& getClass() const
	{
		return m_class;
	}
	void setClass(const boost::optional<VClass >& value_)
	{
		m_class = value_;
	}
	const boost::optional<VVendor >& getVendor() const
	{
		return m_vendor;
	}
	void setVendor(const boost::optional<VVendor >& value_)
	{
		m_vendor = value_;
	}
	const boost::optional<VProduct >& getProduct() const
	{
		return m_product;
	}
	void setProduct(const boost::optional<VProduct >& value_)
	{
		m_product = value_;
	}
	const boost::optional<VVersion >& getVersion() const
	{
		return m_version;
	}
	void setVersion(const boost::optional<VVersion >& value_)
	{
		m_version = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EVirYesNo m_allow;
	boost::optional<VClass > m_class;
	boost::optional<VVendor > m_vendor;
	boost::optional<VProduct > m_product;
	boost::optional<VVersion > m_version;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Backend4752

namespace Domain
{
namespace Xml
{
struct Backend4752
{
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Backend4753

namespace Domain
{
namespace Xml
{
struct Backend4753
{
	Backend4753();

	EQemucdevSrcTypeChoice getType() const
	{
		return m_type;
	}
	void setType(EQemucdevSrcTypeChoice value_)
	{
		m_type = value_;
	}
	const QemucdevSrcDef& getQemucdevSrcDef() const
	{
		return m_qemucdevSrcDef;
	}
	void setQemucdevSrcDef(const QemucdevSrcDef& value_)
	{
		m_qemucdevSrcDef = value_;
	}

private:
	EQemucdevSrcTypeChoice m_type;
	QemucdevSrcDef m_qemucdevSrcDef;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Backend4754

namespace Domain
{
namespace Xml
{
struct Backend4754
{
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VBackend

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Backend4752, Backend4753, Backend4754 > > VBackendImpl;
typedef VBackendImpl::value_type VBackend;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Rate

namespace Domain
{
namespace Xml
{
struct Rate
{
	Rate();

	PPositiveInteger::value_type getBytes() const
	{
		return m_bytes;
	}
	void setBytes(PPositiveInteger::value_type value_)
	{
		m_bytes = value_;
	}
	const boost::optional<PPositiveInteger::value_type >& getPeriod() const
	{
		return m_period;
	}
	void setPeriod(const boost::optional<PPositiveInteger::value_type >& value_)
	{
		m_period = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PPositiveInteger::value_type m_bytes;
	boost::optional<PPositiveInteger::value_type > m_period;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Rng

namespace Domain
{
namespace Xml
{
struct Rng
{
	Rng();

	EModel9 getModel() const
	{
		return m_model;
	}
	void setModel(EModel9 value_)
	{
		m_model = value_;
	}
	const VBackend& getBackend() const
	{
		return m_backend;
	}
	void setBackend(const VBackend& value_)
	{
		m_backend = value_;
	}
	const boost::optional<VirtioOptions >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<VirtioOptions >& value_)
	{
		m_driver = value_;
	}
	const boost::optional<Rate >& getRate() const
	{
		return m_rate;
	}
	void setRate(const boost::optional<Rate >& value_)
	{
		m_rate = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EModel9 m_model;
	VBackend m_backend;
	boost::optional<VirtioOptions > m_driver;
	boost::optional<Rate > m_rate;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Device1

namespace Domain
{
namespace Xml
{
struct Device1
{
	const boost::optional<PFilePath::value_type >& getPath() const
	{
		return m_path;
	}
	void setPath(const boost::optional<PFilePath::value_type >& value_)
	{
		m_path = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PFilePath::value_type > m_path;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Backend7062

namespace Domain
{
namespace Xml
{
struct Backend7062
{
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VBackend1

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Ordered<mpl::vector<Attribute<mpl::int_<644>, Name::Strict<105> >, Optional<Element<Domain::Xml::Device1, Name::Strict<354> > > > >, Backend7062 > > VBackend1Impl;
typedef VBackend1Impl::value_type VBackend1;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Backend1

namespace Domain
{
namespace Xml
{
struct Backend1
{
	const VBackend1& getBackend() const
	{
		return m_backend;
	}
	void setBackend(const VBackend1& value_)
	{
		m_backend = value_;
	}
	const boost::optional<EVersion >& getVersion() const
	{
		return m_version;
	}
	void setVersion(const boost::optional<EVersion >& value_)
	{
		m_version = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VBackend1 m_backend;
	boost::optional<EVersion > m_version;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Tpm

namespace Domain
{
namespace Xml
{
struct Tpm
{
	const boost::optional<EModel10 >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<EModel10 >& value_)
	{
		m_model = value_;
	}
	const Backend1& getBackend() const
	{
		return m_backend;
	}
	void setBackend(const Backend1& value_)
	{
		m_backend = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EModel10 > m_model;
	Backend1 m_backend;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Source16

namespace Domain
{
namespace Xml
{
struct Source16
{
	const boost::optional<ScaledInteger >& getPagesize() const
	{
		return m_pagesize;
	}
	void setPagesize(const boost::optional<ScaledInteger >& value_)
	{
		m_pagesize = value_;
	}
	const boost::optional<PCpuset::value_type >& getNodemask() const
	{
		return m_nodemask;
	}
	void setNodemask(const boost::optional<PCpuset::value_type >& value_)
	{
		m_nodemask = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<ScaledInteger > m_pagesize;
	boost::optional<PCpuset::value_type > m_nodemask;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Target7

namespace Domain
{
namespace Xml
{
struct Target7
{
	Target7();

	const ScaledInteger& getSize() const
	{
		return m_size;
	}
	void setSize(const ScaledInteger& value_)
	{
		m_size = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getNode() const
	{
		return m_node;
	}
	void setNode(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_node = value_;
	}
	const boost::optional<ScaledInteger >& getBlock() const
	{
		return m_block;
	}
	void setBlock(const boost::optional<ScaledInteger >& value_)
	{
		m_block = value_;
	}
	const boost::optional<ScaledInteger >& getRequested() const
	{
		return m_requested;
	}
	void setRequested(const boost::optional<ScaledInteger >& value_)
	{
		m_requested = value_;
	}
	const boost::optional<ScaledInteger >& getCurrent() const
	{
		return m_current;
	}
	void setCurrent(const boost::optional<ScaledInteger >& value_)
	{
		m_current = value_;
	}
	const boost::optional<ScaledInteger >& getLabel() const
	{
		return m_label;
	}
	void setLabel(const boost::optional<ScaledInteger >& value_)
	{
		m_label = value_;
	}
	bool getReadonly() const
	{
		return m_readonly;
	}
	void setReadonly(bool value_)
	{
		m_readonly = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	ScaledInteger m_size;
	boost::optional<PUnsignedInt::value_type > m_node;
	boost::optional<ScaledInteger > m_block;
	boost::optional<ScaledInteger > m_requested;
	boost::optional<ScaledInteger > m_current;
	boost::optional<ScaledInteger > m_label;
	bool m_readonly;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Memory2

namespace Domain
{
namespace Xml
{
struct Memory2
{
	Memory2();

	EModel11 getModel() const
	{
		return m_model;
	}
	void setModel(EModel11 value_)
	{
		m_model = value_;
	}
	const boost::optional<EAccess >& getAccess() const
	{
		return m_access;
	}
	void setAccess(const boost::optional<EAccess >& value_)
	{
		m_access = value_;
	}
	const boost::optional<EVirYesNo >& getDiscard() const
	{
		return m_discard;
	}
	void setDiscard(const boost::optional<EVirYesNo >& value_)
	{
		m_discard = value_;
	}
	const boost::optional<VUUID >& getUuid() const
	{
		return m_uuid;
	}
	void setUuid(const boost::optional<VUUID >& value_)
	{
		m_uuid = value_;
	}
	const boost::optional<Source16 >& getSource() const
	{
		return m_source;
	}
	void setSource(const boost::optional<Source16 >& value_)
	{
		m_source = value_;
	}
	const Target7& getTarget() const
	{
		return m_target;
	}
	void setTarget(const Target7& value_)
	{
		m_target = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EModel11 m_model;
	boost::optional<EAccess > m_access;
	boost::optional<EVirYesNo > m_discard;
	boost::optional<VUUID > m_uuid;
	boost::optional<Source16 > m_source;
	Target7 m_target;
	boost::optional<VAddress > m_address;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice7097

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Element<Domain::Xml::Disk, Name::Strict<472> >, Element<Domain::Xml::Controller, Name::Strict<572> >, Element<Domain::Xml::Lease, Name::Strict<465> >, Element<Domain::Xml::Filesystem, Name::Strict<630> >, Element<Domain::Xml::Interface, Name::Strict<657> >, Element<Domain::Xml::Input, Name::Strict<907> >, Element<Domain::Xml::Sound, Name::Strict<872> >, Element<Domain::Xml::Hostdev, Name::Strict<676> >, Element<Domain::Xml::VGraphicsImpl, Name::Strict<712> >, Element<Domain::Xml::Video, Name::Strict<779> >, Element<Domain::Xml::VConsoleImpl, Name::Strict<865> >, Element<Domain::Xml::Qemucdev, Name::Strict<889> >, Element<Domain::Xml::Qemucdev, Name::Strict<453> >, Element<Domain::Xml::Channel1, Name::Strict<744> >, Element<Domain::Xml::Smartcard, Name::Strict<750> >, Element<Domain::Xml::Hub, Name::Strict<911> >, Element<Domain::Xml::Redirdev, Name::Strict<912> >, Element<ZeroOrMore<Element<Domain::Xml::Usbdev, Name::Strict<840> > >, Name::Strict<913> >, Element<Domain::Xml::Rng, Name::Strict<981> >, Element<Domain::Xml::Tpm, Name::Strict<902> >, Element<Domain::Xml::Memory2, Name::Strict<326> > > > VChoice7097Impl;
typedef VChoice7097Impl::value_type VChoice7097;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Watchdog

namespace Domain
{
namespace Xml
{
struct Watchdog
{
	Watchdog();

	EModel12 getModel() const
	{
		return m_model;
	}
	void setModel(EModel12 value_)
	{
		m_model = value_;
	}
	const boost::optional<EAction >& getAction() const
	{
		return m_action;
	}
	void setAction(const boost::optional<EAction >& value_)
	{
		m_action = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EModel12 m_model;
	boost::optional<EAction > m_action;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Memballoon

namespace Domain
{
namespace Xml
{
struct Memballoon
{
	Memballoon();

	EModel13 getModel() const
	{
		return m_model;
	}
	void setModel(EModel13 value_)
	{
		m_model = value_;
	}
	const boost::optional<EVirOnOff >& getAutodeflate() const
	{
		return m_autodeflate;
	}
	void setAutodeflate(const boost::optional<EVirOnOff >& value_)
	{
		m_autodeflate = value_;
	}
	const boost::optional<EVirOnOff >& getFreePageReporting() const
	{
		return m_freePageReporting;
	}
	void setFreePageReporting(const boost::optional<EVirOnOff >& value_)
	{
		m_freePageReporting = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<PPositiveInteger::value_type >& getStats() const
	{
		return m_stats;
	}
	void setStats(const boost::optional<PPositiveInteger::value_type >& value_)
	{
		m_stats = value_;
	}
	const boost::optional<VirtioOptions >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<VirtioOptions >& value_)
	{
		m_driver = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EModel13 m_model;
	boost::optional<EVirOnOff > m_autodeflate;
	boost::optional<EVirOnOff > m_freePageReporting;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VAddress > m_address;
	boost::optional<PPositiveInteger::value_type > m_stats;
	boost::optional<VirtioOptions > m_driver;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Nvram1

namespace Domain
{
namespace Xml
{
struct Nvram1
{
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<VAddress > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Panic

namespace Domain
{
namespace Xml
{
struct Panic
{
	const boost::optional<EModel14 >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<EModel14 >& value_)
	{
		m_model = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EModel14 > m_model;
	boost::optional<VAddress > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Address1

namespace Domain
{
namespace Xml
{
struct Address1
{
	const PAddrIPorName::value_type& getHost() const
	{
		return m_host;
	}
	void setHost(const PAddrIPorName::value_type& value_)
	{
		m_host = value_;
	}
	const boost::optional<PPortNumber::value_type >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<PPortNumber::value_type >& value_)
	{
		m_port = value_;
	}
	const boost::optional<EVirYesNo >& getAutoport() const
	{
		return m_autoport;
	}
	void setAutoport(const boost::optional<EVirYesNo >& value_)
	{
		m_autoport = value_;
	}
	const boost::optional<EVirYesNo >& getTls() const
	{
		return m_tls;
	}
	void setTls(const boost::optional<EVirYesNo >& value_)
	{
		m_tls = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PAddrIPorName::value_type m_host;
	boost::optional<PPortNumber::value_type > m_port;
	boost::optional<EVirYesNo > m_autoport;
	boost::optional<EVirYesNo > m_tls;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VChoice7113

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Attribute<QString, Name::Strict<1180> >, Attribute<Domain::Xml::EVirYesNo, Name::Strict<1182> > > > VChoice7113Impl;
typedef VChoice7113Impl::value_type VChoice7113;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Disk1

namespace Domain
{
namespace Xml
{
struct Disk1
{
	const VName1& getName() const
	{
		return m_name;
	}
	void setName(const VName1& value_)
	{
		m_name = value_;
	}
	const boost::optional<QString >& getExportname() const
	{
		return m_exportname;
	}
	void setExportname(const boost::optional<QString >& value_)
	{
		m_exportname = value_;
	}
	const boost::optional<QString >& getSnapshot() const
	{
		return m_snapshot;
	}
	void setSnapshot(const boost::optional<QString >& value_)
	{
		m_snapshot = value_;
	}
	const boost::optional<VChoice7113 >& getChoice7113() const
	{
		return m_choice7113;
	}
	void setChoice7113(const boost::optional<VChoice7113 >& value_)
	{
		m_choice7113 = value_;
	}
	const boost::optional<EVirYesNo >& getReadonly() const
	{
		return m_readonly;
	}
	void setReadonly(const boost::optional<EVirYesNo >& value_)
	{
		m_readonly = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VName1 m_name;
	boost::optional<QString > m_exportname;
	boost::optional<QString > m_snapshot;
	boost::optional<VChoice7113 > m_choice7113;
	boost::optional<EVirYesNo > m_readonly;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Domainblockexport_

namespace Domain
{
namespace Xml
{
struct Domainblockexport_
{
	const Address1& getAddress() const
	{
		return m_address;
	}
	void setAddress(const Address1& value_)
	{
		m_address = value_;
	}
	const QList<Disk1 >& getDiskList() const
	{
		return m_diskList;
	}
	void setDiskList(const QList<Disk1 >& value_)
	{
		m_diskList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	Address1 m_address;
	QList<Disk1 > m_diskList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Driver5

namespace Domain
{
namespace Xml
{
struct Driver5
{
	const boost::optional<EVirOnOff >& getIntremap() const
	{
		return m_intremap;
	}
	void setIntremap(const boost::optional<EVirOnOff >& value_)
	{
		m_intremap = value_;
	}
	const boost::optional<EVirOnOff >& getCachingMode() const
	{
		return m_cachingMode;
	}
	void setCachingMode(const boost::optional<EVirOnOff >& value_)
	{
		m_cachingMode = value_;
	}
	const boost::optional<EVirOnOff >& getEim() const
	{
		return m_eim;
	}
	void setEim(const boost::optional<EVirOnOff >& value_)
	{
		m_eim = value_;
	}
	const boost::optional<EVirOnOff >& getIotlb() const
	{
		return m_iotlb;
	}
	void setIotlb(const boost::optional<EVirOnOff >& value_)
	{
		m_iotlb = value_;
	}
	const boost::optional<VUint8 >& getAwBits() const
	{
		return m_awBits;
	}
	void setAwBits(const boost::optional<VUint8 >& value_)
	{
		m_awBits = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirOnOff > m_intremap;
	boost::optional<EVirOnOff > m_cachingMode;
	boost::optional<EVirOnOff > m_eim;
	boost::optional<EVirOnOff > m_iotlb;
	boost::optional<VUint8 > m_awBits;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Cid

namespace Domain
{
namespace Xml
{
struct Cid
{
	const boost::optional<EVirYesNo >& getAuto() const
	{
		return m_auto;
	}
	void setAuto(const boost::optional<EVirYesNo >& value_)
	{
		m_auto = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_address = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EVirYesNo > m_auto;
	boost::optional<PUnsignedInt::value_type > m_address;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Vsock

namespace Domain
{
namespace Xml
{
struct Vsock
{
	const boost::optional<Cid >& getCid() const
	{
		return m_cid;
	}
	void setCid(const boost::optional<Cid >& value_)
	{
		m_cid = value_;
	}
	const boost::optional<VAddress >& getAddress() const
	{
		return m_address;
	}
	void setAddress(const boost::optional<VAddress >& value_)
	{
		m_address = value_;
	}
	const boost::optional<PAliasName::value_type >& getAlias() const
	{
		return m_alias;
	}
	void setAlias(const boost::optional<PAliasName::value_type >& value_)
	{
		m_alias = value_;
	}
	const boost::optional<Acpi >& getAcpi() const
	{
		return m_acpi;
	}
	void setAcpi(const boost::optional<Acpi >& value_)
	{
		m_acpi = value_;
	}
	const boost::optional<VirtioOptions >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<VirtioOptions >& value_)
	{
		m_driver = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<Cid > m_cid;
	boost::optional<VAddress > m_address;
	boost::optional<PAliasName::value_type > m_alias;
	boost::optional<Acpi > m_acpi;
	boost::optional<VirtioOptions > m_driver;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Devices

namespace Domain
{
namespace Xml
{
struct Devices
{
	const boost::optional<PAbsFilePath::value_type >& getEmulator() const
	{
		return m_emulator;
	}
	void setEmulator(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_emulator = value_;
	}
	const QList<VChoice7097 >& getChoice7097List() const
	{
		return m_choice7097List;
	}
	void setChoice7097List(const QList<VChoice7097 >& value_)
	{
		m_choice7097List = value_;
	}
	const boost::optional<Watchdog >& getWatchdog() const
	{
		return m_watchdog;
	}
	void setWatchdog(const boost::optional<Watchdog >& value_)
	{
		m_watchdog = value_;
	}
	const boost::optional<Memballoon >& getMemballoon() const
	{
		return m_memballoon;
	}
	void setMemballoon(const boost::optional<Memballoon >& value_)
	{
		m_memballoon = value_;
	}
	const boost::optional<Nvram1 >& getNvram() const
	{
		return m_nvram;
	}
	void setNvram(const boost::optional<Nvram1 >& value_)
	{
		m_nvram = value_;
	}
	const QList<Panic >& getPanicList() const
	{
		return m_panicList;
	}
	void setPanicList(const QList<Panic >& value_)
	{
		m_panicList = value_;
	}
	const boost::optional<Domainblockexport_ >& getXBlockexport() const
	{
		return m_xBlockexport;
	}
	void setXBlockexport(const boost::optional<Domainblockexport_ >& value_)
	{
		m_xBlockexport = value_;
	}
	const boost::optional<Driver5 >& getIommu() const
	{
		return m_iommu;
	}
	void setIommu(const boost::optional<Driver5 >& value_)
	{
		m_iommu = value_;
	}
	const boost::optional<Vsock >& getVsock() const
	{
		return m_vsock;
	}
	void setVsock(const boost::optional<Vsock >& value_)
	{
		m_vsock = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PAbsFilePath::value_type > m_emulator;
	QList<VChoice7097 > m_choice7097List;
	boost::optional<Watchdog > m_watchdog;
	boost::optional<Memballoon > m_memballoon;
	boost::optional<Nvram1 > m_nvram;
	QList<Panic > m_panicList;
	boost::optional<Domainblockexport_ > m_xBlockexport;
	boost::optional<Driver5 > m_iommu;
	boost::optional<Vsock > m_vsock;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6970

namespace Domain
{
namespace Xml
{
struct Seclabel6970
{
	const boost::optional<QString >& getLabel() const
	{
		return m_label;
	}
	void setLabel(const boost::optional<QString >& value_)
	{
		m_label = value_;
	}
	const boost::optional<QString >& getImagelabel() const
	{
		return m_imagelabel;
	}
	void setImagelabel(const boost::optional<QString >& value_)
	{
		m_imagelabel = value_;
	}
	const boost::optional<QString >& getBaselabel() const
	{
		return m_baselabel;
	}
	void setBaselabel(const boost::optional<QString >& value_)
	{
		m_baselabel = value_;
	}

private:
	boost::optional<QString > m_label;
	boost::optional<QString > m_imagelabel;
	boost::optional<QString > m_baselabel;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6971

namespace Domain
{
namespace Xml
{
struct Seclabel6971
{
	const boost::optional<EVirYesNo >& getRelabel() const
	{
		return m_relabel;
	}
	void setRelabel(const boost::optional<EVirYesNo >& value_)
	{
		m_relabel = value_;
	}
	const QString& getLabel() const
	{
		return m_label;
	}
	void setLabel(const QString& value_)
	{
		m_label = value_;
	}
	const boost::optional<QString >& getImagelabel() const
	{
		return m_imagelabel;
	}
	void setImagelabel(const boost::optional<QString >& value_)
	{
		m_imagelabel = value_;
	}

private:
	boost::optional<EVirYesNo > m_relabel;
	QString m_label;
	boost::optional<QString > m_imagelabel;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6972

namespace Domain
{
namespace Xml
{
struct Seclabel6972
{
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct VSeclabel1

namespace Domain
{
namespace Xml
{
typedef Choice<mpl::vector<Seclabel6970, Seclabel6971, Seclabel6972 > > VSeclabel1Impl;
typedef VSeclabel1Impl::value_type VSeclabel1;

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel1

namespace Domain
{
namespace Xml
{
struct Seclabel1
{
	const boost::optional<QString >& getModel() const
	{
		return m_model;
	}
	void setModel(const boost::optional<QString >& value_)
	{
		m_model = value_;
	}
	const VSeclabel1& getSeclabel() const
	{
		return m_seclabel;
	}
	void setSeclabel(const VSeclabel1& value_)
	{
		m_seclabel = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<QString > m_model;
	VSeclabel1 m_seclabel;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Env

namespace Domain
{
namespace Xml
{
struct Env
{
	const PFilterParamName::value_type& getName() const
	{
		return m_name;
	}
	void setName(const PFilterParamName::value_type& value_)
	{
		m_name = value_;
	}
	const boost::optional<QString >& getValue() const
	{
		return m_value;
	}
	void setValue(const boost::optional<QString >& value_)
	{
		m_value = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	PFilterParamName::value_type m_name;
	boost::optional<QString > m_value;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Commandline

namespace Domain
{
namespace Xml
{
struct Commandline
{
	const QList<QString >& getArgList() const
	{
		return m_argList;
	}
	void setArgList(const QList<QString >& value_)
	{
		m_argList = value_;
	}
	const QList<Env >& getEnvList() const
	{
		return m_envList;
	}
	void setEnvList(const QList<Env >& value_)
	{
		m_envList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	QList<QString > m_argList;
	QList<Env > m_envList;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Cipher

namespace Domain
{
namespace Xml
{
struct Cipher
{
	Cipher();

	EName11 getName() const
	{
		return m_name;
	}
	void setName(EName11 value_)
	{
		m_name = value_;
	}
	EVirOnOff getState() const
	{
		return m_state;
	}
	void setState(EVirOnOff value_)
	{
		m_state = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EName11 m_name;
	EVirOnOff m_state;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct LaunchSecurity

namespace Domain
{
namespace Xml
{
struct LaunchSecurity
{
	const boost::optional<PCbitpos::value_type >& getCbitpos() const
	{
		return m_cbitpos;
	}
	void setCbitpos(const boost::optional<PCbitpos::value_type >& value_)
	{
		m_cbitpos = value_;
	}
	const boost::optional<PReducedPhysBits::value_type >& getReducedPhysBits() const
	{
		return m_reducedPhysBits;
	}
	void setReducedPhysBits(const boost::optional<PReducedPhysBits::value_type >& value_)
	{
		m_reducedPhysBits = value_;
	}
	const PHexuint::value_type& getPolicy() const
	{
		return m_policy;
	}
	void setPolicy(const PHexuint::value_type& value_)
	{
		m_policy = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getHandle() const
	{
		return m_handle;
	}
	void setHandle(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_handle = value_;
	}
	const boost::optional<PDhCert::value_type >& getDhCert() const
	{
		return m_dhCert;
	}
	void setDhCert(const boost::optional<PDhCert::value_type >& value_)
	{
		m_dhCert = value_;
	}
	const boost::optional<PSession::value_type >& getSession() const
	{
		return m_session;
	}
	void setSession(const boost::optional<PSession::value_type >& value_)
	{
		m_session = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PCbitpos::value_type > m_cbitpos;
	boost::optional<PReducedPhysBits::value_type > m_reducedPhysBits;
	PHexuint::value_type m_policy;
	boost::optional<PUnsignedInt::value_type > m_handle;
	boost::optional<PDhCert::value_type > m_dhCert;
	boost::optional<PSession::value_type > m_session;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Domain

namespace Domain
{
namespace Xml
{
struct Domain
{
	Domain();

	EType getType() const
	{
		return m_type;
	}
	void setType(EType value_)
	{
		m_type = value_;
	}
	const Ids& getIds() const
	{
		return m_ids;
	}
	void setIds(const Ids& value_)
	{
		m_ids = value_;
	}
	const boost::optional<PObjectNameWithSlash::value_type >& getTitle() const
	{
		return m_title;
	}
	void setTitle(const boost::optional<PObjectNameWithSlash::value_type >& value_)
	{
		m_title = value_;
	}
	const boost::optional<QString >& getDescription() const
	{
		return m_description;
	}
	void setDescription(const boost::optional<QString >& value_)
	{
		m_description = value_;
	}
	const boost::optional<QList<QDomElement > >& getMetadata() const
	{
		return m_metadata;
	}
	void setMetadata(const boost::optional<QList<QDomElement > >& value_)
	{
		m_metadata = value_;
	}
	const boost::optional<Cpu >& getCpu() const
	{
		return m_cpu;
	}
	void setCpu(const boost::optional<Cpu >& value_)
	{
		m_cpu = value_;
	}
	const QList<Sysinfo >& getSysinfoList() const
	{
		return m_sysinfoList;
	}
	void setSysinfoList(const QList<Sysinfo >& value_)
	{
		m_sysinfoList = value_;
	}
	const VOs& getOs() const
	{
		return m_os;
	}
	void setOs(const VOs& value_)
	{
		m_os = value_;
	}
	const boost::optional<Clock >& getClock() const
	{
		return m_clock;
	}
	void setClock(const boost::optional<Clock >& value_)
	{
		m_clock = value_;
	}
	const boost::optional<Memory >& getMemory() const
	{
		return m_memory;
	}
	void setMemory(const boost::optional<Memory >& value_)
	{
		m_memory = value_;
	}
	const boost::optional<MaxMemory >& getMaxMemory() const
	{
		return m_maxMemory;
	}
	void setMaxMemory(const boost::optional<MaxMemory >& value_)
	{
		m_maxMemory = value_;
	}
	const boost::optional<ScaledInteger >& getCurrentMemory() const
	{
		return m_currentMemory;
	}
	void setCurrentMemory(const boost::optional<ScaledInteger >& value_)
	{
		m_currentMemory = value_;
	}
	const boost::optional<MemoryBacking >& getMemoryBacking() const
	{
		return m_memoryBacking;
	}
	void setMemoryBacking(const boost::optional<MemoryBacking >& value_)
	{
		m_memoryBacking = value_;
	}
	const boost::optional<Vcpu >& getVcpu() const
	{
		return m_vcpu;
	}
	void setVcpu(const boost::optional<Vcpu >& value_)
	{
		m_vcpu = value_;
	}
	const boost::optional<QList<Vcpu1 > >& getVcpus() const
	{
		return m_vcpus;
	}
	void setVcpus(const boost::optional<QList<Vcpu1 > >& value_)
	{
		m_vcpus = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getIothreads() const
	{
		return m_iothreads;
	}
	void setIothreads(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_iothreads = value_;
	}
	const boost::optional<QList<PUnsignedInt::value_type > >& getIothreadids() const
	{
		return m_iothreadids;
	}
	void setIothreadids(const boost::optional<QList<PUnsignedInt::value_type > >& value_)
	{
		m_iothreadids = value_;
	}
	const boost::optional<Blkiotune >& getBlkiotune() const
	{
		return m_blkiotune;
	}
	void setBlkiotune(const boost::optional<Blkiotune >& value_)
	{
		m_blkiotune = value_;
	}
	const boost::optional<Memtune >& getMemtune() const
	{
		return m_memtune;
	}
	void setMemtune(const boost::optional<Memtune >& value_)
	{
		m_memtune = value_;
	}
	const boost::optional<Cputune >& getCputune() const
	{
		return m_cputune;
	}
	void setCputune(const boost::optional<Cputune >& value_)
	{
		m_cputune = value_;
	}
	const boost::optional<Numatune >& getNumatune() const
	{
		return m_numatune;
	}
	void setNumatune(const boost::optional<Numatune >& value_)
	{
		m_numatune = value_;
	}
	const boost::optional<Resource >& getResource() const
	{
		return m_resource;
	}
	void setResource(const boost::optional<Resource >& value_)
	{
		m_resource = value_;
	}
	const boost::optional<Features >& getFeatures() const
	{
		return m_features;
	}
	void setFeatures(const boost::optional<Features >& value_)
	{
		m_features = value_;
	}
	const boost::optional<EOffOptions >& getOnReboot() const
	{
		return m_onReboot;
	}
	void setOnReboot(const boost::optional<EOffOptions >& value_)
	{
		m_onReboot = value_;
	}
	const boost::optional<EOffOptions >& getOnPoweroff() const
	{
		return m_onPoweroff;
	}
	void setOnPoweroff(const boost::optional<EOffOptions >& value_)
	{
		m_onPoweroff = value_;
	}
	const boost::optional<ECrashOptions >& getOnCrash() const
	{
		return m_onCrash;
	}
	void setOnCrash(const boost::optional<ECrashOptions >& value_)
	{
		m_onCrash = value_;
	}
	const boost::optional<ELockfailureOptions >& getOnLockfailure() const
	{
		return m_onLockfailure;
	}
	void setOnLockfailure(const boost::optional<ELockfailureOptions >& value_)
	{
		m_onLockfailure = value_;
	}
	const boost::optional<VzDns >& getVzDns() const
	{
		return m_vzDns;
	}
	void setVzDns(const boost::optional<VzDns >& value_)
	{
		m_vzDns = value_;
	}
	const boost::optional<VzNetworkRates >& getVzNetworkRates() const
	{
		return m_vzNetworkRates;
	}
	void setVzNetworkRates(const boost::optional<VzNetworkRates >& value_)
	{
		m_vzNetworkRates = value_;
	}
	const boost::optional<Pm >& getPm() const
	{
		return m_pm;
	}
	void setPm(const boost::optional<Pm >& value_)
	{
		m_pm = value_;
	}
	const boost::optional<QList<Event > >& getPerf() const
	{
		return m_perf;
	}
	void setPerf(const boost::optional<QList<Event > >& value_)
	{
		m_perf = value_;
	}
	const boost::optional<Idmap >& getIdmap() const
	{
		return m_idmap;
	}
	void setIdmap(const boost::optional<Idmap >& value_)
	{
		m_idmap = value_;
	}
	const boost::optional<Devices >& getDevices() const
	{
		return m_devices;
	}
	void setDevices(const boost::optional<Devices >& value_)
	{
		m_devices = value_;
	}
	const QList<Seclabel1 >& getSeclabelList() const
	{
		return m_seclabelList;
	}
	void setSeclabelList(const QList<Seclabel1 >& value_)
	{
		m_seclabelList = value_;
	}
	const boost::optional<Commandline >& getCommandline() const
	{
		return m_commandline;
	}
	void setCommandline(const boost::optional<Commandline >& value_)
	{
		m_commandline = value_;
	}
	const boost::optional<QList<Cipher > >& getKeywrap() const
	{
		return m_keywrap;
	}
	void setKeywrap(const boost::optional<QList<Cipher > >& value_)
	{
		m_keywrap = value_;
	}
	const boost::optional<LaunchSecurity >& getLaunchSecurity() const
	{
		return m_launchSecurity;
	}
	void setLaunchSecurity(const boost::optional<LaunchSecurity >& value_)
	{
		m_launchSecurity = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EType m_type;
	Ids m_ids;
	boost::optional<PObjectNameWithSlash::value_type > m_title;
	boost::optional<QString > m_description;
	boost::optional<QList<QDomElement > > m_metadata;
	boost::optional<Cpu > m_cpu;
	QList<Sysinfo > m_sysinfoList;
	VOs m_os;
	boost::optional<Clock > m_clock;
	boost::optional<Memory > m_memory;
	boost::optional<MaxMemory > m_maxMemory;
	boost::optional<ScaledInteger > m_currentMemory;
	boost::optional<MemoryBacking > m_memoryBacking;
	boost::optional<Vcpu > m_vcpu;
	boost::optional<QList<Vcpu1 > > m_vcpus;
	boost::optional<PUnsignedInt::value_type > m_iothreads;
	boost::optional<QList<PUnsignedInt::value_type > > m_iothreadids;
	boost::optional<Blkiotune > m_blkiotune;
	boost::optional<Memtune > m_memtune;
	boost::optional<Cputune > m_cputune;
	boost::optional<Numatune > m_numatune;
	boost::optional<Resource > m_resource;
	boost::optional<Features > m_features;
	boost::optional<EOffOptions > m_onReboot;
	boost::optional<EOffOptions > m_onPoweroff;
	boost::optional<ECrashOptions > m_onCrash;
	boost::optional<ELockfailureOptions > m_onLockfailure;
	boost::optional<VzDns > m_vzDns;
	boost::optional<VzNetworkRates > m_vzNetworkRates;
	boost::optional<Pm > m_pm;
	boost::optional<QList<Event > > m_perf;
	boost::optional<Idmap > m_idmap;
	boost::optional<Devices > m_devices;
	QList<Seclabel1 > m_seclabelList;
	boost::optional<Commandline > m_commandline;
	boost::optional<QList<Cipher > > m_keywrap;
	boost::optional<LaunchSecurity > m_launchSecurity;
};

} // namespace Xml
} // namespace Domain

///////////////////////////////////////////////////////////////////////////////
// struct Ids traits

template<>
struct Traits<Domain::Xml::Ids>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<208> > >, Unordered<mpl::vector<Element<Text<Domain::Xml::PDomainName >, Name::Strict<107> >, Optional<Element<Text<Domain::Xml::VUUID >, Name::Strict<151> > >, Optional<Element<Text<Domain::Xml::VUUID >, Name::Strict<3563> > >, Optional<Element<Text<Domain::Xml::PGenericName >, Name::Strict<9355> > > > > > > marshal_type;

	static int parse(Domain::Xml::Ids& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Ids& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Model traits

template<>
struct Traits<Domain::Xml::Model>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EFallback, Name::Strict<1018> > >, Optional<Attribute<Domain::Xml::PVendorId, Name::Strict<1020> > >, Text<QString > > > marshal_type;

	static int parse(Domain::Xml::Model& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Model& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Topology traits

template<>
struct Traits<Domain::Xml::Topology>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<1029> >, Optional<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<5780> > >, Attribute<Domain::Xml::PPositiveInteger, Name::Strict<1030> >, Attribute<Domain::Xml::PPositiveInteger, Name::Strict<570> > > > marshal_type;

	static int parse(Domain::Xml::Topology& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Topology& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Feature traits

template<>
struct Traits<Domain::Xml::Feature>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EPolicy, Name::Strict<1023> >, Attribute<Domain::Xml::PFeatureName, Name::Strict<107> > > > marshal_type;

	static int parse(Domain::Xml::Feature& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Feature& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Sibling traits

template<>
struct Traits<Domain::Xml::Sibling>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<208> >, Attribute<Domain::Xml::PNumaDistanceValue, Name::Strict<1086> > > > marshal_type;

	static int parse(Domain::Xml::Sibling& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Sibling& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Size traits

template<>
struct Traits<Domain::Xml::Size>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<1086> >, Attribute<Domain::Xml::PUnit, Name::Strict<66> > > > marshal_type;

	static int parse(Domain::Xml::Size& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Size& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Line traits

template<>
struct Traits<Domain::Xml::Line>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<1086> >, Attribute<Domain::Xml::PUnit, Name::Strict<66> > > > marshal_type;

	static int parse(Domain::Xml::Line& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Line& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Cache traits

template<>
struct Traits<Domain::Xml::Cache>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<1876> >, Attribute<Domain::Xml::EAssociativity, Name::Strict<5786> >, Attribute<Domain::Xml::EPolicy1, Name::Strict<1023> >, Unordered<mpl::vector<Element<Domain::Xml::Size, Name::Strict<334> >, Element<Domain::Xml::Line, Name::Strict<5787> > > > > > marshal_type;

	static int parse(Domain::Xml::Cache& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Cache& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Cell traits

template<>
struct Traits<Domain::Xml::Cell>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<208> > >, Optional<Attribute<Domain::Xml::PCpuset, Name::Strict<1034> > >, Attribute<Domain::Xml::PMemoryKB1, Name::Strict<326> >, Optional<Attribute<Domain::Xml::PUnit, Name::Strict<66> > >, Optional<Attribute<Domain::Xml::EMemAccess, Name::Strict<1036> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<428> > >, Unordered<mpl::vector<Optional<Element<OneOrMore<Element<Domain::Xml::Sibling, Name::Strict<5785> > >, Name::Strict<5782> > >, ZeroOrMore<Element<Domain::Xml::Cache, Name::Strict<558> > > > > > > marshal_type;

	static int parse(Domain::Xml::Cell& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Cell& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Latency traits

template<>
struct Traits<Domain::Xml::Latency>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<5754> >, Attribute<Domain::Xml::PUnsignedInt, Name::Strict<323> >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<558> > >, Attribute<Domain::Xml::EType1, Name::Strict<105> >, Attribute<Domain::Xml::PUnsignedInt, Name::Strict<1086> > > > marshal_type;

	static int parse(Domain::Xml::Latency& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Latency& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Bandwidth traits

template<>
struct Traits<Domain::Xml::Bandwidth>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<5754> >, Attribute<Domain::Xml::PUnsignedInt, Name::Strict<323> >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<558> > >, Attribute<Domain::Xml::EType2, Name::Strict<105> >, Attribute<Domain::Xml::PUnsignedInt, Name::Strict<1086> >, Attribute<Domain::Xml::PUnit, Name::Strict<66> > > > marshal_type;

	static int parse(Domain::Xml::Bandwidth& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Bandwidth& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Interconnects traits

template<>
struct Traits<Domain::Xml::Interconnects>
{
	typedef Unordered<mpl::vector<ZeroOrMore<Element<Domain::Xml::Latency, Name::Strict<5789> > >, ZeroOrMore<Element<Domain::Xml::Bandwidth, Name::Strict<193> > > > > marshal_type;

	static int parse(Domain::Xml::Interconnects& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Interconnects& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Numa traits

template<>
struct Traits<Domain::Xml::Numa>
{
	typedef Unordered<mpl::vector<OneOrMore<Element<Domain::Xml::Cell, Name::Strict<1033> > >, Optional<Element<Domain::Xml::Interconnects, Name::Strict<5788> > > > > marshal_type;

	static int parse(Domain::Xml::Numa& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Numa& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Cache1 traits

template<>
struct Traits<Domain::Xml::Cache1>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::ELevel, Name::Strict<1876> > >, Attribute<Domain::Xml::EMode1, Name::Strict<379> > > > marshal_type;

	static int parse(Domain::Xml::Cache1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Cache1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Cpu traits

template<>
struct Traits<Domain::Xml::Cpu>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EMode, Name::Strict<379> > >, Optional<Attribute<Domain::Xml::EMatch, Name::Strict<1015> > >, Optional<Attribute<Domain::Xml::ECheck, Name::Strict<1871> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<5802> > >, Unordered<mpl::vector<Optional<Element<Domain::Xml::Model, Name::Strict<231> > >, Optional<Element<Text<QString >, Name::Strict<459> > >, Optional<Element<Domain::Xml::Topology, Name::Strict<1028> > >, ZeroOrMore<Element<Domain::Xml::Feature, Name::Strict<1022> > >, Optional<Element<Domain::Xml::Numa, Name::Strict<1031> > >, Optional<Element<Domain::Xml::Cache1, Name::Strict<558> > > > > > > marshal_type;

	static int parse(Domain::Xml::Cpu& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Cpu& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Entry traits

template<>
struct Traits<Domain::Xml::Entry>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::ESysinfoBiosName, Name::Strict<107> >, Text<Domain::Xml::PSysinfoValue > > > marshal_type;

	static int parse(Domain::Xml::Entry& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Entry& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Entry1 traits

template<>
struct Traits<Domain::Xml::Entry1>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::ESysinfoSystemName, Name::Strict<107> >, Text<Domain::Xml::PSysinfoValue > > > marshal_type;

	static int parse(Domain::Xml::Entry1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Entry1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Entry2 traits

template<>
struct Traits<Domain::Xml::Entry2>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::ESysinfoBaseBoardName, Name::Strict<107> >, Text<Domain::Xml::PSysinfoValue > > > marshal_type;

	static int parse(Domain::Xml::Entry2& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Entry2& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Entry3 traits

template<>
struct Traits<Domain::Xml::Entry3>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::ESysinfoChassisName, Name::Strict<107> >, Text<Domain::Xml::PSysinfoValue > > > marshal_type;

	static int parse(Domain::Xml::Entry3& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Entry3& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Sysinfo traits

template<>
struct Traits<Domain::Xml::Sysinfo>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<283>, Name::Strict<105> >, Unordered<mpl::vector<Optional<Element<OneOrMore<Element<Domain::Xml::Entry, Name::Strict<1039> > >, Name::Strict<284> > >, Optional<Element<OneOrMore<Element<Domain::Xml::Entry1, Name::Strict<1039> > >, Name::Strict<1042> > >, ZeroOrMore<Element<OneOrMore<Element<Domain::Xml::Entry2, Name::Strict<1039> > >, Name::Strict<5208> > >, Optional<Element<OneOrMore<Element<Domain::Xml::Entry3, Name::Strict<1039> > >, Name::Strict<607> > >, Optional<Element<OneOrMore<Element<Text<Domain::Xml::PSysinfoValue >, Name::Strict<1039> > >, Name::Strict<5211> > > > > > > marshal_type;

	static int parse(Domain::Xml::Sysinfo& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Sysinfo& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Bootloader traits

template<>
struct Traits<Domain::Xml::Bootloader>
{
	typedef Unordered<mpl::vector<Optional<Element<Text<QString >, Name::Strict<267> > >, Optional<Element<Text<QString >, Name::Strict<436> > > > > marshal_type;

	static int parse(Domain::Xml::Bootloader& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Bootloader& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Type traits

template<>
struct Traits<Domain::Xml::Type>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EArch, Name::Strict<285> > >, Optional<Attribute<Domain::Xml::EMachine, Name::Strict<286> > >, Text<Domain::Xml::EType3 > > > marshal_type;

	static int parse(Domain::Xml::Type& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Type& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Osbootkernel traits

template<>
struct Traits<Domain::Xml::Osbootkernel>
{
	typedef Unordered<mpl::vector<Optional<Element<Text<Domain::Xml::PAbsFilePath >, Name::Strict<214> > >, Optional<Element<Text<Domain::Xml::PAbsFilePath >, Name::Strict<437> > >, Optional<Element<Text<Domain::Xml::PAbsFilePath >, Name::Strict<438> > >, Optional<Element<Text<QString >, Name::Strict<439> > >, Optional<Element<Text<Domain::Xml::PAbsFilePath >, Name::Strict<440> > > > > marshal_type;

	static int parse(Domain::Xml::Osbootkernel& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Osbootkernel& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Os traits

template<>
struct Traits<Domain::Xml::Os>
{
	typedef Ordered<mpl::vector<Element<Domain::Xml::Type, Name::Strict<105> >, Fragment<Domain::Xml::Osbootkernel > > > marshal_type;

	static int parse(Domain::Xml::Os& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Os& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Osxen6979 traits

template<>
struct Traits<Domain::Xml::Osxen6979>
{
	typedef Ordered<mpl::vector<Optional<Fragment<Domain::Xml::Bootloader > >, Element<Domain::Xml::Os, Name::Strict<222> > > > marshal_type;

	static int parse(Domain::Xml::Osxen6979& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Osxen6979& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Os1 traits

template<>
struct Traits<Domain::Xml::Os1>
{
	typedef Ordered<mpl::vector<Element<Domain::Xml::Type, Name::Strict<105> >, Optional<Fragment<Domain::Xml::Osbootkernel > > > > marshal_type;

	static int parse(Domain::Xml::Os1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Os1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Osxen6980 traits

template<>
struct Traits<Domain::Xml::Osxen6980>
{
	typedef Ordered<mpl::vector<Fragment<Domain::Xml::Bootloader >, Optional<Element<Domain::Xml::Os1, Name::Strict<222> > > > > marshal_type;

	static int parse(Domain::Xml::Osxen6980& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Osxen6980& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hvmx86 traits

template<>
struct Traits<Domain::Xml::Hvmx86>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EArch1, Name::Strict<285> > >, Optional<Attribute<Domain::Xml::PMachine, Name::Strict<286> > > > > marshal_type;

	static int parse(Domain::Xml::Hvmx86& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hvmx86& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hvmmips traits

template<>
struct Traits<Domain::Xml::Hvmmips>
{
	typedef Ordered<mpl::vector<Optional<Attribute<mpl::int_<82>, Name::Strict<285> > >, Optional<Attribute<mpl::int_<82>, Name::Strict<286> > > > > marshal_type;

	static int parse(Domain::Xml::Hvmmips& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hvmmips& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hvmsparc traits

template<>
struct Traits<Domain::Xml::Hvmsparc>
{
	typedef Ordered<mpl::vector<Optional<Attribute<mpl::int_<96>, Name::Strict<285> > >, Optional<Attribute<mpl::int_<308>, Name::Strict<286> > > > > marshal_type;

	static int parse(Domain::Xml::Hvmsparc& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hvmsparc& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hvms390 traits

template<>
struct Traits<Domain::Xml::Hvms390>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EArch2, Name::Strict<285> > >, Optional<Attribute<Domain::Xml::EMachine3, Name::Strict<286> > > > > marshal_type;

	static int parse(Domain::Xml::Hvms390& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hvms390& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hvmarm traits

template<>
struct Traits<Domain::Xml::Hvmarm>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EArch3, Name::Strict<285> > >, Optional<Attribute<Domain::Xml::PMachine, Name::Strict<286> > > > > marshal_type;

	static int parse(Domain::Xml::Hvmarm& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hvmarm& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hvmaarch64 traits

template<>
struct Traits<Domain::Xml::Hvmaarch64>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EArch4, Name::Strict<285> > >, Optional<Attribute<Domain::Xml::PMachine, Name::Strict<286> > > > > marshal_type;

	static int parse(Domain::Xml::Hvmaarch64& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hvmaarch64& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Loader traits

template<>
struct Traits<Domain::Xml::Loader>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EReadonly, Name::Strict<274> > >, Optional<Attribute<Domain::Xml::ESecure, Name::Strict<742> > >, Optional<Attribute<Domain::Xml::EType4, Name::Strict<105> > >, Optional<Text<Domain::Xml::PAbsFilePath > > > > marshal_type;

	static int parse(Domain::Xml::Loader& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Loader& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6973 traits

template<>
struct Traits<Domain::Xml::Seclabel6973>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<136>, Name::Strict<233> > > > marshal_type;

	static int parse(Domain::Xml::Seclabel6973& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Seclabel6973& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6974 traits

template<>
struct Traits<Domain::Xml::Seclabel6974>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<135>, Name::Strict<244> > > > marshal_type;

	static int parse(Domain::Xml::Seclabel6974& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Seclabel6974& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel traits

template<>
struct Traits<Domain::Xml::Seclabel>
{
	typedef Ordered<mpl::vector<Optional<Attribute<QString, Name::Strict<231> > >, Domain::Xml::VSeclabelImpl > > marshal_type;

	static int parse(Domain::Xml::Seclabel& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Seclabel& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source traits

template<>
struct Traits<Domain::Xml::Source>
{
	typedef Unordered<mpl::vector<Optional<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<441> > >, Optional<Attribute<Domain::Xml::EStartupPolicy, Name::Strict<468> > >, ZeroOrMore<Element<Domain::Xml::Seclabel, Name::Strict<229> > > > > marshal_type;

	static int parse(Domain::Xml::Source& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous7117 traits

template<>
struct Traits<Domain::Xml::Anonymous7117>
{
	typedef Ordered<mpl::vector<Attribute<QString, Name::Strict<379> >, Attribute<QString, Name::Strict<5769> > > > marshal_type;

	static int parse(Domain::Xml::Anonymous7117& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Anonymous7117& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Keycipher traits

template<>
struct Traits<Domain::Xml::Keycipher>
{
	typedef Ordered<mpl::vector<Attribute<QString, Name::Strict<107> >, Attribute<Domain::Xml::PUnsignedInt, Name::Strict<334> >, Optional<Fragment<Domain::Xml::Anonymous7117 > > > > marshal_type;

	static int parse(Domain::Xml::Keycipher& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Keycipher& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Keyivgen traits

template<>
struct Traits<Domain::Xml::Keyivgen>
{
	typedef Ordered<mpl::vector<Attribute<QString, Name::Strict<107> >, Optional<Attribute<QString, Name::Strict<5769> > > > > marshal_type;

	static int parse(Domain::Xml::Keyivgen& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Keyivgen& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous7118 traits

template<>
struct Traits<Domain::Xml::Anonymous7118>
{
	typedef Ordered<mpl::vector<Element<Domain::Xml::Keycipher, Name::Strict<5049> >, Element<Domain::Xml::Keyivgen, Name::Strict<5751> > > > marshal_type;

	static int parse(Domain::Xml::Anonymous7118& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Anonymous7118& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Encryption traits

template<>
struct Traits<Domain::Xml::Encryption>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EFormat, Name::Strict<146> >, Unordered<mpl::vector<Element<Ordered<mpl::vector<Attribute<mpl::int_<150>, Name::Strict<105> >, Domain::Xml::VSecretImpl > >, Name::Strict<149> >, Optional<Fragment<Domain::Xml::Anonymous7118 > > > > > > marshal_type;

	static int parse(Domain::Xml::Encryption& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Encryption& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source1 traits

template<>
struct Traits<Domain::Xml::Source1>
{
	typedef Unordered<mpl::vector<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<164> >, Optional<Attribute<Domain::Xml::EStartupPolicy, Name::Strict<468> > >, Optional<Element<Domain::Xml::Encryption, Name::Strict<145> > > > > marshal_type;

	static int parse(Domain::Xml::Source1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Host7010 traits

template<>
struct Traits<Domain::Xml::Host7010>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::ETransport, Name::Strict<514> > >, Attribute<Domain::Xml::VName, Name::Strict<107> >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<212> > > > > marshal_type;

	static int parse(Domain::Xml::Host7010& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Host7010& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source2 traits

template<>
struct Traits<Domain::Xml::Source2>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EProtocol, Name::Strict<203> >, Optional<Attribute<QString, Name::Strict<107> > >, ZeroOrMore<Element<Domain::Xml::VHostImpl, Name::Strict<513> > > > > marshal_type;

	static int parse(Domain::Xml::Source2& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source2& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source3 traits

template<>
struct Traits<Domain::Xml::Source3>
{
	typedef Unordered<mpl::vector<Attribute<Domain::Xml::PGenericName, Name::Strict<524> >, Attribute<Domain::Xml::PVolName, Name::Strict<523> >, Optional<Attribute<Domain::Xml::EMode2, Name::Strict<379> > >, Optional<Attribute<Domain::Xml::EStartupPolicy, Name::Strict<468> > >, Optional<Element<Domain::Xml::Encryption, Name::Strict<145> > >, ZeroOrMore<Element<Domain::Xml::Seclabel, Name::Strict<229> > > > > marshal_type;

	static int parse(Domain::Xml::Source3& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source3& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source4 traits

template<>
struct Traits<Domain::Xml::Source4>
{
	typedef Unordered<mpl::vector<Optional<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<500> > >, Optional<Attribute<Domain::Xml::EStartupPolicy, Name::Strict<468> > >, ZeroOrMore<Element<Domain::Xml::Seclabel, Name::Strict<229> > > > > marshal_type;

	static int parse(Domain::Xml::Source4& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source4& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Nvram traits

template<>
struct Traits<Domain::Xml::Nvram>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<278> > >, Optional<Domain::Xml::VDiskSourceImpl >, Optional<Attribute<Domain::Xml::EFormat1, Name::Strict<146> > > > > marshal_type;

	static int parse(Domain::Xml::Nvram& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Nvram& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Bootmenu traits

template<>
struct Traits<Domain::Xml::Bootmenu>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EVirYesNo, Name::Strict<281> >, Optional<Attribute<Domain::Xml::PUnsignedShort, Name::Strict<282> > > > > marshal_type;

	static int parse(Domain::Xml::Bootmenu& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Bootmenu& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Bios traits

template<>
struct Traits<Domain::Xml::Bios>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<1048> > >, Optional<Attribute<Domain::Xml::PRebootTimeoutDelay, Name::Strict<1049> > > > > marshal_type;

	static int parse(Domain::Xml::Bios& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Bios& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Os2 traits

template<>
struct Traits<Domain::Xml::Os2>
{
	typedef Ordered<mpl::vector<Element<Ordered<mpl::vector<Optional<Domain::Xml::VChoice5114Impl >, Text<mpl::int_<307> > > >, Name::Strict<105> >, Unordered<mpl::vector<Optional<Element<Domain::Xml::Loader, Name::Strict<273> > >, Optional<Element<Domain::Xml::Nvram, Name::Strict<277> > >, Optional<Fragment<Domain::Xml::Osbootkernel > >, ZeroOrMore<Element<Attribute<Domain::Xml::EDev, Name::Strict<441> >, Name::Strict<407> > >, Optional<Element<Domain::Xml::Bootmenu, Name::Strict<280> > >, Optional<Element<Attribute<Domain::Xml::EMode3, Name::Strict<379> >, Name::Strict<283> > >, Optional<Element<Domain::Xml::Bios, Name::Strict<284> > >, Optional<Element<ZeroOrMore<Element<Ordered<mpl::vector<Attribute<mpl::int_<5089>, Name::Strict<105> >, Text<Domain::Xml::PAbsFilePath > > >, Name::Strict<5088> > >, Name::Strict<993> > > > > > > marshal_type;

	static int parse(Domain::Xml::Os2& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Os2& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Initenv traits

template<>
struct Traits<Domain::Xml::Initenv>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PName, Name::Strict<107> >, Text<QString > > > marshal_type;

	static int parse(Domain::Xml::Initenv& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Initenv& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Os3 traits

template<>
struct Traits<Domain::Xml::Os3>
{
	typedef Ordered<mpl::vector<Element<Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EArch5, Name::Strict<285> > >, Text<mpl::int_<317> > > >, Name::Strict<105> >, Unordered<mpl::vector<Optional<Element<Text<Domain::Xml::PAbsFilePath >, Name::Strict<318> > >, ZeroOrMore<Element<Text<QString >, Name::Strict<319> > >, ZeroOrMore<Element<Domain::Xml::Initenv, Name::Strict<9348> > >, Optional<Element<Text<Domain::Xml::PAbsFilePath >, Name::Strict<9349> > >, Optional<Element<Text<Domain::Xml::PGenericName >, Name::Strict<9350> > >, Optional<Element<Text<Domain::Xml::PGenericName >, Name::Strict<9351> > > > > > > marshal_type;

	static int parse(Domain::Xml::Os3& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Os3& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Clock6991 traits

template<>
struct Traits<Domain::Xml::Clock6991>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EOffset, Name::Strict<389> >, Optional<Attribute<Domain::Xml::VAdjustment, Name::Strict<392> > > > > marshal_type;

	static int parse(Domain::Xml::Clock6991& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Clock6991& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Clock6993 traits

template<>
struct Traits<Domain::Xml::Clock6993>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<400>, Name::Strict<389> >, Optional<Attribute<Domain::Xml::PTimeDelta, Name::Strict<392> > >, Optional<Attribute<Domain::Xml::EBasis, Name::Strict<401> > > > > marshal_type;

	static int parse(Domain::Xml::Clock6993& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Clock6993& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Catchup traits

template<>
struct Traits<Domain::Xml::Catchup>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<431> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<432> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<433> > > > > marshal_type;

	static int parse(Domain::Xml::Catchup& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Catchup& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Timer6994 traits

template<>
struct Traits<Domain::Xml::Timer6994>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EName, Name::Strict<107> >, Optional<Attribute<Domain::Xml::ETrack, Name::Strict<406> > >, Optional<Domain::Xml::VTickpolicyImpl > > > marshal_type;

	static int parse(Domain::Xml::Timer6994& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Timer6994& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Timer6995 traits

template<>
struct Traits<Domain::Xml::Timer6995>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<412>, Name::Strict<107> >, Optional<Domain::Xml::VTickpolicyImpl >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<413> > >, Optional<Attribute<Domain::Xml::EMode4, Name::Strict<379> > > > > marshal_type;

	static int parse(Domain::Xml::Timer6995& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Timer6995& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Timer6996 traits

template<>
struct Traits<Domain::Xml::Timer6996>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EName1, Name::Strict<107> >, Optional<Domain::Xml::VTickpolicyImpl > > > marshal_type;

	static int parse(Domain::Xml::Timer6996& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Timer6996& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Timer traits

template<>
struct Traits<Domain::Xml::Timer>
{
	typedef Ordered<mpl::vector<Domain::Xml::VTimerImpl, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<425> > > > > marshal_type;

	static int parse(Domain::Xml::Timer& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Timer& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Clock traits

template<>
struct Traits<Domain::Xml::Clock>
{
	typedef Ordered<mpl::vector<Domain::Xml::VClockImpl, ZeroOrMore<Element<Domain::Xml::Timer, Name::Strict<403> > > > > marshal_type;

	static int parse(Domain::Xml::Clock& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Clock& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct ScaledInteger traits

template<>
struct Traits<Domain::Xml::ScaledInteger>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PUnit, Name::Strict<66> > >, Text<Domain::Xml::PUnsignedLong > > > marshal_type;

	static int parse(Domain::Xml::ScaledInteger& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::ScaledInteger& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Memory traits

template<>
struct Traits<Domain::Xml::Memory>
{
	typedef Ordered<mpl::vector<Fragment<Domain::Xml::ScaledInteger >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<327> > > > > marshal_type;

	static int parse(Domain::Xml::Memory& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Memory& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct MaxMemory traits

template<>
struct Traits<Domain::Xml::MaxMemory>
{
	typedef Ordered<mpl::vector<Fragment<Domain::Xml::ScaledInteger >, Attribute<Domain::Xml::PUnsignedInt, Name::Strict<329> > > > marshal_type;

	static int parse(Domain::Xml::MaxMemory& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::MaxMemory& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Page traits

template<>
struct Traits<Domain::Xml::Page>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedLong, Name::Strict<334> >, Optional<Attribute<Domain::Xml::PUnit, Name::Strict<66> > >, Optional<Attribute<Domain::Xml::PCpuset, Name::Strict<335> > > > > marshal_type;

	static int parse(Domain::Xml::Page& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Page& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct MemoryBacking traits

template<>
struct Traits<Domain::Xml::MemoryBacking>
{
	typedef Unordered<mpl::vector<Optional<Element<ZeroOrMore<Element<Domain::Xml::Page, Name::Strict<333> > >, Name::Strict<332> > >, Optional<Element<Empty, Name::Strict<336> > >, Optional<Element<Empty, Name::Strict<337> > >, Optional<Element<Attribute<Domain::Xml::EType5, Name::Strict<105> >, Name::Strict<501> > >, Optional<Element<Attribute<Domain::Xml::EMode5, Name::Strict<379> >, Name::Strict<5790> > >, Optional<Element<Attribute<Domain::Xml::EMode6, Name::Strict<379> >, Name::Strict<9184> > >, Optional<Element<Empty, Name::Strict<428> > > > > marshal_type;

	static int parse(Domain::Xml::MemoryBacking& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::MemoryBacking& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Vcpu traits

template<>
struct Traits<Domain::Xml::Vcpu>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EPlacement, Name::Strict<339> > >, Optional<Attribute<Domain::Xml::PCpuset, Name::Strict<69> > >, Optional<Attribute<Domain::Xml::PCountCPU, Name::Strict<341> > >, Text<Domain::Xml::PCountCPU > > > marshal_type;

	static int parse(Domain::Xml::Vcpu& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Vcpu& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Vcpu1 traits

template<>
struct Traits<Domain::Xml::Vcpu1>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<208> >, Attribute<Domain::Xml::EVirYesNo, Name::Strict<344> >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<345> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<346> > > > > marshal_type;

	static int parse(Domain::Xml::Vcpu1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Vcpu1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Device traits

template<>
struct Traits<Domain::Xml::Device>
{
	typedef Unordered<mpl::vector<Element<Text<Domain::Xml::PAbsFilePath >, Name::Strict<355> >, Optional<Element<Text<Domain::Xml::PWeight >, Name::Strict<353> > >, Optional<Element<Text<Domain::Xml::PReadIopsSec >, Name::Strict<356> > >, Optional<Element<Text<Domain::Xml::PWriteIopsSec >, Name::Strict<357> > >, Optional<Element<Text<Domain::Xml::PReadBytesSec >, Name::Strict<358> > >, Optional<Element<Text<Domain::Xml::PWriteBytesSec >, Name::Strict<359> > > > > marshal_type;

	static int parse(Domain::Xml::Device& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Device& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Blkiotune traits

template<>
struct Traits<Domain::Xml::Blkiotune>
{
	typedef Unordered<mpl::vector<Optional<Element<Text<Domain::Xml::PWeight >, Name::Strict<353> > >, ZeroOrMore<Element<Domain::Xml::Device, Name::Strict<354> > > > > marshal_type;

	static int parse(Domain::Xml::Blkiotune& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Blkiotune& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Memtune traits

template<>
struct Traits<Domain::Xml::Memtune>
{
	typedef Ordered<mpl::vector<Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<360> > >, Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<361> > >, Optional<Element<Domain::Xml::VMinGuaranteeImpl, Name::Strict<362> > >, Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<363> > > > > marshal_type;

	static int parse(Domain::Xml::Memtune& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Memtune& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Vcpupin traits

template<>
struct Traits<Domain::Xml::Vcpupin>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PVcpuid, Name::Strict<338> >, Attribute<Domain::Xml::PCpuset, Name::Strict<69> > > > marshal_type;

	static int parse(Domain::Xml::Vcpupin& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Vcpupin& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Iothreadpin traits

template<>
struct Traits<Domain::Xml::Iothreadpin>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<378> >, Attribute<Domain::Xml::PCpuset, Name::Strict<69> > > > marshal_type;

	static int parse(Domain::Xml::Iothreadpin& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Iothreadpin& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Schedparam9370 traits

template<>
struct Traits<Domain::Xml::Schedparam9370>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EScheduler1, Name::Strict<9365> >, Attribute<Domain::Xml::PUnsignedShort, Name::Strict<1243> > > > marshal_type;

	static int parse(Domain::Xml::Schedparam9370& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Schedparam9370& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Vcpusched traits

template<>
struct Traits<Domain::Xml::Vcpusched>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PCpuset, Name::Strict<343> > >, Domain::Xml::VSchedparamImpl > > marshal_type;

	static int parse(Domain::Xml::Vcpusched& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Vcpusched& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Iothreadsched traits

template<>
struct Traits<Domain::Xml::Iothreadsched>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PCpuset, Name::Strict<347> > >, Domain::Xml::VSchedparamImpl > > marshal_type;

	static int parse(Domain::Xml::Iothreadsched& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Iothreadsched& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Cache2 traits

template<>
struct Traits<Domain::Xml::Cache2>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<208> >, Attribute<Domain::Xml::PUnsignedInt, Name::Strict<1876> >, Attribute<Domain::Xml::EType6, Name::Strict<105> >, Attribute<Domain::Xml::PUnsignedLong, Name::Strict<334> >, Optional<Attribute<Domain::Xml::PUnit, Name::Strict<66> > > > > marshal_type;

	static int parse(Domain::Xml::Cache2& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Cache2& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Monitor traits

template<>
struct Traits<Domain::Xml::Monitor>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<1876> >, Attribute<Domain::Xml::PCpuset, Name::Strict<343> > > > marshal_type;

	static int parse(Domain::Xml::Monitor& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Monitor& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Cachetune traits

template<>
struct Traits<Domain::Xml::Cachetune>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PCpuset, Name::Strict<343> >, Optional<Attribute<Domain::Xml::PId1, Name::Strict<208> > >, OneOrMore<Domain::Xml::VChoice5117Impl > > > marshal_type;

	static int parse(Domain::Xml::Cachetune& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Cachetune& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Node traits

template<>
struct Traits<Domain::Xml::Node>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<208> >, Attribute<Domain::Xml::PUnsignedInt, Name::Strict<193> > > > marshal_type;

	static int parse(Domain::Xml::Node& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Node& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Memorytune traits

template<>
struct Traits<Domain::Xml::Memorytune>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PCpuset, Name::Strict<343> >, OneOrMore<Domain::Xml::VChoice5120Impl > > > marshal_type;

	static int parse(Domain::Xml::Memorytune& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Memorytune& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Cputune traits

template<>
struct Traits<Domain::Xml::Cputune>
{
	typedef Unordered<mpl::vector<Optional<Element<Text<Domain::Xml::PCpushares >, Name::Strict<364> > >, Optional<Element<Text<Domain::Xml::PCpuperiod >, Name::Strict<366> > >, Optional<Element<Text<Domain::Xml::PCpuquota >, Name::Strict<368> > >, Optional<Element<Text<Domain::Xml::PCpuperiod >, Name::Strict<370> > >, Optional<Element<Text<Domain::Xml::PCpuquota >, Name::Strict<371> > >, Optional<Element<Text<Domain::Xml::PCpuperiod >, Name::Strict<372> > >, Optional<Element<Text<Domain::Xml::PCpuquota >, Name::Strict<373> > >, Optional<Element<Text<Domain::Xml::PCpuperiod >, Name::Strict<5078> > >, Optional<Element<Text<Domain::Xml::PCpuquota >, Name::Strict<5079> > >, ZeroOrMore<Element<Domain::Xml::Vcpupin, Name::Strict<374> > >, Optional<Element<Attribute<Domain::Xml::PCpuset, Name::Strict<69> >, Name::Strict<376> > >, ZeroOrMore<Element<Domain::Xml::Iothreadpin, Name::Strict<377> > >, ZeroOrMore<Element<Domain::Xml::Vcpusched, Name::Strict<9356> > >, ZeroOrMore<Element<Domain::Xml::Iothreadsched, Name::Strict<9358> > >, Optional<Element<Domain::Xml::VSchedparamImpl, Name::Strict<9359> > >, ZeroOrMore<Element<Domain::Xml::Cachetune, Name::Strict<9360> > >, ZeroOrMore<Element<Domain::Xml::Memorytune, Name::Strict<9364> > > > > marshal_type;

	static int parse(Domain::Xml::Cputune& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Cputune& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Memory2356 traits

template<>
struct Traits<Domain::Xml::Memory2356>
{
	typedef Attribute<mpl::int_<340>, Name::Strict<339> > marshal_type;

	static int parse(Domain::Xml::Memory2356& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Memory2356& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Memory1 traits

template<>
struct Traits<Domain::Xml::Memory1>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EMode7, Name::Strict<379> > >, Domain::Xml::VMemoryImpl > > marshal_type;

	static int parse(Domain::Xml::Memory1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Memory1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Memnode traits

template<>
struct Traits<Domain::Xml::Memnode>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<386> >, Attribute<Domain::Xml::EMode8, Name::Strict<379> >, Attribute<Domain::Xml::PCpuset, Name::Strict<335> > > > marshal_type;

	static int parse(Domain::Xml::Memnode& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Memnode& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Numatune traits

template<>
struct Traits<Domain::Xml::Numatune>
{
	typedef Unordered<mpl::vector<Optional<Element<Domain::Xml::Memory1, Name::Strict<326> > >, ZeroOrMore<Element<Domain::Xml::Memnode, Name::Strict<385> > > > > marshal_type;

	static int parse(Domain::Xml::Numatune& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Numatune& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Resource traits

template<>
struct Traits<Domain::Xml::Resource>
{
	typedef Ordered<mpl::vector<Optional<Element<Text<Domain::Xml::PAbsFilePath >, Name::Strict<388> > >, Optional<Element<Attribute<Domain::Xml::PAppid, Name::Strict<9353> >, Name::Strict<9352> > > > > marshal_type;

	static int parse(Domain::Xml::Resource& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Resource& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Apic traits

template<>
struct Traits<Domain::Xml::Apic>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<992> > > > > marshal_type;

	static int parse(Domain::Xml::Apic& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Apic& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hap traits

template<>
struct Traits<Domain::Xml::Hap>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> > > > > marshal_type;

	static int parse(Domain::Xml::Hap& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hap& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Spinlocks traits

template<>
struct Traits<Domain::Xml::Spinlocks>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Optional<Attribute<Domain::Xml::PRetries, Name::Strict<1115> > > > > marshal_type;

	static int parse(Domain::Xml::Spinlocks& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Spinlocks& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Stimer traits

template<>
struct Traits<Domain::Xml::Stimer>
{
	typedef Unordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<525> > > > > marshal_type;

	static int parse(Domain::Xml::Stimer& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Stimer& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct VendorId traits

template<>
struct Traits<Domain::Xml::VendorId>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Optional<Attribute<Domain::Xml::PValue, Name::Strict<1086> > > > > marshal_type;

	static int parse(Domain::Xml::VendorId& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::VendorId& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hyperv traits

template<>
struct Traits<Domain::Xml::Hyperv>
{
	typedef Unordered<mpl::vector<Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1112> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1113> > >, Optional<Element<Domain::Xml::Spinlocks, Name::Strict<1114> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1116> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1117> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1118> > >, Optional<Element<Domain::Xml::Stimer, Name::Strict<1119> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<395> > >, Optional<Element<Domain::Xml::VendorId, Name::Strict<1020> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<5687> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<5688> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<5689> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<5690> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<5691> > > > > marshal_type;

	static int parse(Domain::Xml::Hyperv& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hyperv& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Kvm traits

template<>
struct Traits<Domain::Xml::Kvm>
{
	typedef Ordered<mpl::vector<Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1120> > > > > marshal_type;

	static int parse(Domain::Xml::Kvm& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Kvm& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Pvspinlock traits

template<>
struct Traits<Domain::Xml::Pvspinlock>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> > > > > marshal_type;

	static int parse(Domain::Xml::Pvspinlock& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Pvspinlock& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Capabilities traits

template<>
struct Traits<Domain::Xml::Capabilities>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EPolicy2, Name::Strict<1023> >, Unordered<mpl::vector<Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1122> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1123> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1124> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1125> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1126> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1127> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1128> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1129> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1130> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1131> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1132> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<465> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1133> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1134> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1135> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1136> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1137> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1138> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1139> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1140> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1141> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1142> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1143> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1144> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1145> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1146> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1147> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1148> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1149> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1150> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1151> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1152> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1153> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1154> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1155> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1156> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<1157> > > > > > > marshal_type;

	static int parse(Domain::Xml::Capabilities& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Capabilities& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Pmu traits

template<>
struct Traits<Domain::Xml::Pmu>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> > > > > marshal_type;

	static int parse(Domain::Xml::Pmu& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Pmu& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Vmport traits

template<>
struct Traits<Domain::Xml::Vmport>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> > > > > marshal_type;

	static int parse(Domain::Xml::Vmport& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Vmport& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Gic traits

template<>
struct Traits<Domain::Xml::Gic>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<852> > > > > marshal_type;

	static int parse(Domain::Xml::Gic& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Gic& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous2357 traits

template<>
struct Traits<Domain::Xml::Anonymous2357>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<9403> > > > > marshal_type;

	static int parse(Domain::Xml::Anonymous2357& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Anonymous2357& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Smm traits

template<>
struct Traits<Domain::Xml::Smm>
{
	typedef Ordered<mpl::vector<Optional<Fragment<Domain::Xml::Anonymous2357 > > > > marshal_type;

	static int parse(Domain::Xml::Smm& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Smm& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hpt traits

template<>
struct Traits<Domain::Xml::Hpt>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EResizing, Name::Strict<9413> > >, Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<9416> > > > > marshal_type;

	static int parse(Domain::Xml::Hpt& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hpt& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Vmcoreinfo traits

template<>
struct Traits<Domain::Xml::Vmcoreinfo>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> > > > > marshal_type;

	static int parse(Domain::Xml::Vmcoreinfo& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Vmcoreinfo& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Tcg traits

template<>
struct Traits<Domain::Xml::Tcg>
{
	typedef Ordered<mpl::vector<Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<9425> > > > > marshal_type;

	static int parse(Domain::Xml::Tcg& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Tcg& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Features traits

template<>
struct Traits<Domain::Xml::Features>
{
	typedef Unordered<mpl::vector<Optional<Element<Empty, Name::Strict<990> > >, Optional<Element<Domain::Xml::Apic, Name::Strict<991> > >, Optional<Element<Empty, Name::Strict<993> > >, Optional<Element<Domain::Xml::Hap, Name::Strict<994> > >, Optional<Element<Domain::Xml::Hyperv, Name::Strict<256> > >, Optional<Element<Empty, Name::Strict<995> > >, Optional<Element<Domain::Xml::Kvm, Name::Strict<249> > >, Optional<Element<Empty, Name::Strict<996> > >, Optional<Element<Domain::Xml::Pvspinlock, Name::Strict<997> > >, Optional<Element<Domain::Xml::Capabilities, Name::Strict<926> > >, Optional<Element<Domain::Xml::Pmu, Name::Strict<999> > >, Optional<Element<Domain::Xml::Vmport, Name::Strict<1000> > >, Optional<Element<Domain::Xml::Gic, Name::Strict<1001> > >, Optional<Element<Domain::Xml::Smm, Name::Strict<1002> > >, Optional<Element<Attribute<Domain::Xml::EDriver, Name::Strict<546> >, Name::Strict<1003> > >, Optional<Element<Domain::Xml::Hpt, Name::Strict<9404> > >, Optional<Element<Domain::Xml::Vmcoreinfo, Name::Strict<1004> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<9405> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<9406> > >, Optional<Element<Attribute<Domain::Xml::EUnknown, Name::Strict<127> >, Name::Strict<9407> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> >, Name::Strict<9408> > >, Optional<Element<Attribute<Domain::Xml::EValue, Name::Strict<1086> >, Name::Strict<9409> > >, Optional<Element<Attribute<Domain::Xml::EValue1, Name::Strict<1086> >, Name::Strict<9410> > >, Optional<Element<Attribute<Domain::Xml::EValue2, Name::Strict<1086> >, Name::Strict<9411> > >, Optional<Element<Domain::Xml::Tcg, Name::Strict<9424> > > > > marshal_type;

	static int parse(Domain::Xml::Features& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Features& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct VzDns traits

template<>
struct Traits<Domain::Xml::VzDns>
{
	typedef Ordered<mpl::vector<Optional<Element<Text<Domain::Xml::PDnsName >, Name::Strict<1244> > >, ZeroOrMore<Element<Text<Domain::Xml::VIpAddr >, Name::Strict<663> > >, ZeroOrMore<Element<Text<Domain::Xml::PDnsName >, Name::Strict<5707> > > > > marshal_type;

	static int parse(Domain::Xml::VzDns& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::VzDns& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Class traits

template<>
struct Traits<Domain::Xml::Class>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<208> >, Attribute<Domain::Xml::PUnsignedLong, Name::Strict<1081> > > > marshal_type;

	static int parse(Domain::Xml::Class& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Class& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct VzNetworkRates traits

template<>
struct Traits<Domain::Xml::VzNetworkRates>
{
	typedef Ordered<mpl::vector<Optional<Element<Empty, Name::Strict<9003> > >, ZeroOrMore<Element<Domain::Xml::Class, Name::Strict<842> > > > > marshal_type;

	static int parse(Domain::Xml::VzNetworkRates& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::VzNetworkRates& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct SuspendToMem traits

template<>
struct Traits<Domain::Xml::SuspendToMem>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<344> > > > > marshal_type;

	static int parse(Domain::Xml::SuspendToMem& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::SuspendToMem& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct SuspendToDisk traits

template<>
struct Traits<Domain::Xml::SuspendToDisk>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<344> > > > > marshal_type;

	static int parse(Domain::Xml::SuspendToDisk& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::SuspendToDisk& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Pm traits

template<>
struct Traits<Domain::Xml::Pm>
{
	typedef Unordered<mpl::vector<Optional<Element<Domain::Xml::SuspendToMem, Name::Strict<806> > >, Optional<Element<Domain::Xml::SuspendToDisk, Name::Strict<808> > > > > marshal_type;

	static int parse(Domain::Xml::Pm& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Pm& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Event traits

template<>
struct Traits<Domain::Xml::Event>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EName3, Name::Strict<107> >, Attribute<Domain::Xml::EVirYesNo, Name::Strict<344> > > > marshal_type;

	static int parse(Domain::Xml::Event& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Event& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Uid traits

template<>
struct Traits<Domain::Xml::Uid>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<322> >, Attribute<Domain::Xml::PUnsignedInt, Name::Strict<323> >, Attribute<Domain::Xml::PUnsignedInt, Name::Strict<324> > > > marshal_type;

	static int parse(Domain::Xml::Uid& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Uid& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Gid traits

template<>
struct Traits<Domain::Xml::Gid>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<322> >, Attribute<Domain::Xml::PUnsignedInt, Name::Strict<323> >, Attribute<Domain::Xml::PUnsignedInt, Name::Strict<324> > > > marshal_type;

	static int parse(Domain::Xml::Gid& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Gid& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Idmap traits

template<>
struct Traits<Domain::Xml::Idmap>
{
	typedef Unordered<mpl::vector<ZeroOrMore<Element<Domain::Xml::Uid, Name::Strict<321> > >, ZeroOrMore<Element<Domain::Xml::Gid, Name::Strict<325> > > > > marshal_type;

	static int parse(Domain::Xml::Idmap& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Idmap& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Disk7002 traits

template<>
struct Traits<Domain::Xml::Disk7002>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EDevice1, Name::Strict<354> >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<1174> > >, Optional<Attribute<Domain::Xml::ESgio, Name::Strict<477> > > > > marshal_type;

	static int parse(Domain::Xml::Disk7002& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Disk7002& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct DriverFormat traits

template<>
struct Traits<Domain::Xml::DriverFormat>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PGenericName, Name::Strict<107> > >, Optional<Attribute<Domain::Xml::VType, Name::Strict<105> > > > > marshal_type;

	static int parse(Domain::Xml::DriverFormat& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::DriverFormat& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct VirtioOptions traits

template<>
struct Traits<Domain::Xml::VirtioOptions>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<5082> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<8021> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<8022> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<9427> > > > > marshal_type;

	static int parse(Domain::Xml::VirtioOptions& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::VirtioOptions& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct MetadataCache traits

template<>
struct Traits<Domain::Xml::MetadataCache>
{
	typedef Ordered<mpl::vector<Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<6547> > > > > marshal_type;

	static int parse(Domain::Xml::MetadataCache& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::MetadataCache& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Driver traits

template<>
struct Traits<Domain::Xml::Driver>
{
	typedef Ordered<mpl::vector<Optional<Fragment<Domain::Xml::DriverFormat > >, Optional<Attribute<Domain::Xml::ECache, Name::Strict<558> > >, Optional<Attribute<Domain::Xml::EErrorPolicy, Name::Strict<563> > >, Optional<Attribute<Domain::Xml::ERerrorPolicy, Name::Strict<568> > >, Optional<Attribute<Domain::Xml::EIo, Name::Strict<569> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<552> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<553> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<554> > >, Optional<Attribute<Domain::Xml::EDiscard, Name::Strict<428> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<378> > >, Optional<Attribute<Domain::Xml::EDetectZeroes, Name::Strict<9374> > >, Optional<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<627> > >, Optional<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<9375> > >, Fragment<Domain::Xml::VirtioOptions >, Optional<Element<Domain::Xml::MetadataCache, Name::Strict<6546> > > > > marshal_type;

	static int parse(Domain::Xml::Driver& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Driver& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct MetadataCache1 traits

template<>
struct Traits<Domain::Xml::MetadataCache1>
{
	typedef Ordered<mpl::vector<Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<6547> > > > > marshal_type;

	static int parse(Domain::Xml::MetadataCache1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::MetadataCache1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Format traits

template<>
struct Traits<Domain::Xml::Format>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::VStorageFormat, Name::Strict<105> >, Optional<Element<Domain::Xml::MetadataCache1, Name::Strict<6546> > > > > marshal_type;

	static int parse(Domain::Xml::Format& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Format& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous2358 traits

template<>
struct Traits<Domain::Xml::Anonymous2358>
{
	typedef Unordered<mpl::vector<Ordered<mpl::vector<Optional<Attribute<mpl::int_<500>, Name::Strict<105> > >, Optional<Element<Domain::Xml::Source4, Name::Strict<501> > > > >, Optional<Element<Domain::Xml::Format, Name::Strict<146> > > > > marshal_type;

	static int parse(Domain::Xml::Anonymous2358& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Anonymous2358& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Mirror4765 traits

template<>
struct Traits<Domain::Xml::Mirror4765>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<500> >, Optional<Attribute<Domain::Xml::VStorageFormat, Name::Strict<146> > >, Optional<Attribute<Domain::Xml::EJob, Name::Strict<1089> > >, Optional<Fragment<Domain::Xml::Anonymous2358 > > > > marshal_type;

	static int parse(Domain::Xml::Mirror4765& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Mirror4765& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Mirror4766 traits

template<>
struct Traits<Domain::Xml::Mirror4766>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EJob1, Name::Strict<1089> >, Unordered<mpl::vector<Domain::Xml::VDiskSourceImpl, Optional<Element<Domain::Xml::Format, Name::Strict<146> > > > > > > marshal_type;

	static int parse(Domain::Xml::Mirror4766& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Mirror4766& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Mirror traits

template<>
struct Traits<Domain::Xml::Mirror>
{
	typedef Ordered<mpl::vector<Domain::Xml::VMirrorImpl, Optional<Attribute<Domain::Xml::EReady, Name::Strict<1094> > > > > marshal_type;

	static int parse(Domain::Xml::Mirror& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Mirror& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Secret traits

template<>
struct Traits<Domain::Xml::Secret>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EType8, Name::Strict<105> >, Domain::Xml::VSecret1Impl > > marshal_type;

	static int parse(Domain::Xml::Secret& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Secret& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Auth traits

template<>
struct Traits<Domain::Xml::Auth>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PGenericName, Name::Strict<1098> >, Element<Domain::Xml::Secret, Name::Strict<149> > > > marshal_type;

	static int parse(Domain::Xml::Auth& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Auth& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Target traits

template<>
struct Traits<Domain::Xml::Target>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PDiskTarget, Name::Strict<441> >, Optional<Attribute<Domain::Xml::EBus, Name::Strict<29> > >, Optional<Attribute<Domain::Xml::ETray, Name::Strict<534> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<537> > > > > marshal_type;

	static int parse(Domain::Xml::Target& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Target& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Boot traits

template<>
struct Traits<Domain::Xml::Boot>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<346> >, Optional<Attribute<Domain::Xml::PLoadparm, Name::Strict<9428> > > > > marshal_type;

	static int parse(Domain::Xml::Boot& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Boot& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Transient traits

template<>
struct Traits<Domain::Xml::Transient>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<9373> > > > > marshal_type;

	static int parse(Domain::Xml::Transient& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Transient& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Variant4770 traits

template<>
struct Traits<Domain::Xml::Variant4770>
{
	typedef Ordered<mpl::vector<Unordered<mpl::vector<Optional<Element<Text<Domain::Xml::PReadBytesSec >, Name::Strict<358> > >, Optional<Element<Text<Domain::Xml::PWriteBytesSec >, Name::Strict<359> > > > > > > marshal_type;

	static int parse(Domain::Xml::Variant4770& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Variant4770& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Variant4773 traits

template<>
struct Traits<Domain::Xml::Variant4773>
{
	typedef Ordered<mpl::vector<Unordered<mpl::vector<Optional<Element<Text<Domain::Xml::PReadIopsSec1 >, Name::Strict<356> > >, Optional<Element<Text<Domain::Xml::PWriteIopsSec1 >, Name::Strict<357> > > > > > > marshal_type;

	static int parse(Domain::Xml::Variant4773& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Variant4773& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Iotune traits

template<>
struct Traits<Domain::Xml::Iotune>
{
	typedef Unordered<mpl::vector<Domain::Xml::VChoice4771Impl, Domain::Xml::VChoice4774Impl, Optional<Element<Text<Domain::Xml::PSizeIopsSec >, Name::Strict<3554> > >, Optional<Element<Text<QString >, Name::Strict<3555> > > > > marshal_type;

	static int parse(Domain::Xml::Iotune& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Iotune& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Pciaddress traits

template<>
struct Traits<Domain::Xml::Pciaddress>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PPciDomain, Name::Strict<1> > >, Attribute<Domain::Xml::PPciBus, Name::Strict<29> >, Attribute<Domain::Xml::PPciSlot, Name::Strict<31> >, Attribute<Domain::Xml::PPciFunc, Name::Strict<33> >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<35> > > > > marshal_type;

	static int parse(Domain::Xml::Pciaddress& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Pciaddress& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Driveaddress traits

template<>
struct Traits<Domain::Xml::Driveaddress>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PDriveController, Name::Strict<572> > >, Optional<Attribute<Domain::Xml::PDriveBus, Name::Strict<29> > >, Optional<Attribute<Domain::Xml::PDriveTarget, Name::Strict<323> > >, Optional<Attribute<Domain::Xml::PDriveUnit, Name::Strict<66> > > > > marshal_type;

	static int parse(Domain::Xml::Driveaddress& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Driveaddress& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Virtioserialaddress traits

template<>
struct Traits<Domain::Xml::Virtioserialaddress>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PDriveController, Name::Strict<572> >, Optional<Attribute<Domain::Xml::PDriveBus, Name::Strict<29> > >, Optional<Attribute<Domain::Xml::PDriveUnit, Name::Strict<212> > > > > marshal_type;

	static int parse(Domain::Xml::Virtioserialaddress& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Virtioserialaddress& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Ccidaddress traits

template<>
struct Traits<Domain::Xml::Ccidaddress>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PDriveController, Name::Strict<572> >, Optional<Attribute<Domain::Xml::PDriveUnit, Name::Strict<31> > > > > marshal_type;

	static int parse(Domain::Xml::Ccidaddress& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Ccidaddress& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Usbportaddress traits

template<>
struct Traits<Domain::Xml::Usbportaddress>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUsbAddr, Name::Strict<29> >, Optional<Attribute<Domain::Xml::PUsbPort, Name::Strict<212> > > > > marshal_type;

	static int parse(Domain::Xml::Usbportaddress& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Usbportaddress& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous9190 traits

template<>
struct Traits<Domain::Xml::Anonymous9190>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::VCcwCssidRange, Name::Strict<950> >, Attribute<Domain::Xml::PCcwSsidRange, Name::Strict<952> >, Attribute<Domain::Xml::VCcwDevnoRange, Name::Strict<954> > > > marshal_type;

	static int parse(Domain::Xml::Anonymous9190& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Anonymous9190& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Isaaddress traits

template<>
struct Traits<Domain::Xml::Isaaddress>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PIobase, Name::Strict<121> > >, Optional<Attribute<Domain::Xml::PIrq, Name::Strict<122> > > > > marshal_type;

	static int parse(Domain::Xml::Isaaddress& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Isaaddress& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Dimmaddress traits

template<>
struct Traits<Domain::Xml::Dimmaddress>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<31> > >, Optional<Attribute<Domain::Xml::PHexuint, Name::Strict<961> > > > > marshal_type;

	static int parse(Domain::Xml::Dimmaddress& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Dimmaddress& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Geometry traits

template<>
struct Traits<Domain::Xml::Geometry>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PCyls, Name::Strict<538> >, Attribute<Domain::Xml::PHeads, Name::Strict<539> >, Attribute<Domain::Xml::PSecs, Name::Strict<540> >, Optional<Attribute<Domain::Xml::ETrans, Name::Strict<541> > > > > marshal_type;

	static int parse(Domain::Xml::Geometry& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Geometry& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Blockio traits

template<>
struct Traits<Domain::Xml::Blockio>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PLogicalBlockSize, Name::Strict<544> > >, Optional<Attribute<Domain::Xml::PPhysicalBlockSize, Name::Strict<545> > > > > marshal_type;

	static int parse(Domain::Xml::Blockio& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Blockio& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct BackingStore traits

template<>
struct Traits<Domain::Xml::BackingStore>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<488> > >, Unordered<mpl::vector<Domain::Xml::VDiskSourceImpl, Domain::Xml::VDiskBackingChainImpl, Element<Domain::Xml::Format, Name::Strict<146> > > > > > marshal_type;

	static int parse(Domain::Xml::BackingStore& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::BackingStore& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Disk traits

template<>
struct Traits<Domain::Xml::Disk>
{
	typedef Ordered<mpl::vector<Domain::Xml::VDiskImpl, Optional<Attribute<Domain::Xml::ESnapshot, Name::Strict<462> > >, Unordered<mpl::vector<Domain::Xml::VDiskSourceImpl, Optional<Element<Domain::Xml::Driver, Name::Strict<546> > >, Optional<Element<Domain::Xml::Mirror, Name::Strict<1088> > >, Optional<Element<Domain::Xml::Auth, Name::Strict<1097> > >, Element<Domain::Xml::Target, Name::Strict<323> >, Optional<Element<Domain::Xml::Boot, Name::Strict<407> > >, Optional<Element<Attribute<Domain::Xml::PObjectNameWithSlash, Name::Strict<107> >, Name::Strict<9372> > >, Optional<Element<Empty, Name::Strict<274> > >, Optional<Element<Empty, Name::Strict<451> > >, Optional<Element<Domain::Xml::Transient, Name::Strict<452> > >, Optional<Element<Text<Domain::Xml::PDiskSerial >, Name::Strict<453> > >, Optional<Element<Domain::Xml::Encryption, Name::Strict<145> > >, Optional<Element<Domain::Xml::Iotune, Name::Strict<1103> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Domain::Xml::Geometry, Name::Strict<457> > >, Optional<Element<Domain::Xml::Blockio, Name::Strict<543> > >, Optional<Element<Text<Domain::Xml::PWwn >, Name::Strict<68> > >, Optional<Element<Text<Domain::Xml::PVendor >, Name::Strict<459> > >, Optional<Element<Text<Domain::Xml::PProduct >, Name::Strict<460> > >, ZeroOrMore<Element<Attribute<QString, Name::Strict<107> >, Name::Strict<461> > >, Domain::Xml::VDiskBackingChainImpl > > > > marshal_type;

	static int parse(Domain::Xml::Disk& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Disk& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Acpi traits

template<>
struct Traits<Domain::Xml::Acpi>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<488> > > > > marshal_type;

	static int parse(Domain::Xml::Acpi& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Acpi& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Variant5121 traits

template<>
struct Traits<Domain::Xml::Variant5121>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<531>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::EModel1, Name::Strict<231> > >, Optional<Element<Attribute<Domain::Xml::PUsbPort, Name::Strict<1083> >, Name::Strict<858> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<623> > > > > marshal_type;

	static int parse(Domain::Xml::Variant5121& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Variant5121& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Variant7013 traits

template<>
struct Traits<Domain::Xml::Variant7013>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<1061>, Name::Strict<105> > > > marshal_type;

	static int parse(Domain::Xml::Variant7013& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Variant7013& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Target1 traits

template<>
struct Traits<Domain::Xml::Target1>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::VUint8, Name::Strict<606> > >, Optional<Attribute<Domain::Xml::VUint8, Name::Strict<607> > >, Optional<Attribute<Domain::Xml::VUint8, Name::Strict<212> > >, Optional<Attribute<Domain::Xml::VUint8, Name::Strict<608> > >, Optional<Attribute<Domain::Xml::VUint8, Name::Strict<488> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<1347> > >, Optional<Element<Text<Domain::Xml::PUnsignedInt >, Name::Strict<609> > > > > marshal_type;

	static int parse(Domain::Xml::Target1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Target1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Variant7014 traits

template<>
struct Traits<Domain::Xml::Variant7014>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EModel3, Name::Strict<231> >, Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<612> > > > > marshal_type;

	static int parse(Domain::Xml::Variant7014& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Variant7014& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Variant8014 traits

template<>
struct Traits<Domain::Xml::Variant8014>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<596>, Name::Strict<105> >, Optional<Element<Attribute<Domain::Xml::EName4, Name::Strict<107> >, Name::Strict<231> > >, Optional<Element<Domain::Xml::Target1, Name::Strict<323> > >, Domain::Xml::VChoice2355Impl > > marshal_type;

	static int parse(Domain::Xml::Variant8014& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Variant8014& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Variant9522 traits

template<>
struct Traits<Domain::Xml::Variant9522>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<622>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::EModel5, Name::Strict<231> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<623> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<624> > > > > marshal_type;

	static int parse(Domain::Xml::Variant9522& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Variant9522& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Variant8018 traits

template<>
struct Traits<Domain::Xml::Variant8018>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<8016>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<8017> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<8018> > > > > marshal_type;

	static int parse(Domain::Xml::Variant8018& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Variant8018& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Driver1 traits

template<>
struct Traits<Domain::Xml::Driver1>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<627> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<628> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<629> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<552> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<378> > >, Fragment<Domain::Xml::VirtioOptions > > > marshal_type;

	static int parse(Domain::Xml::Driver1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Driver1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Controller traits

template<>
struct Traits<Domain::Xml::Controller>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<488> > >, Unordered<mpl::vector<Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Domain::Xml::VChoice5123Impl, Optional<Element<Domain::Xml::Driver1, Name::Strict<546> > > > > > > marshal_type;

	static int parse(Domain::Xml::Controller& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Controller& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Target2 traits

template<>
struct Traits<Domain::Xml::Target2>
{
	typedef Ordered<mpl::vector<Attribute<QString, Name::Strict<355> >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<389> > > > > marshal_type;

	static int parse(Domain::Xml::Target2& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Target2& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Lease traits

template<>
struct Traits<Domain::Xml::Lease>
{
	typedef Unordered<mpl::vector<Element<Text<QString >, Name::Strict<466> >, Element<Text<QString >, Name::Strict<467> >, Element<Domain::Xml::Target2, Name::Strict<323> > > > marshal_type;

	static int parse(Domain::Xml::Lease& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Lease& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Driver2 traits

template<>
struct Traits<Domain::Xml::Driver2>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EType10, Name::Strict<105> > >, Optional<Attribute<Domain::Xml::VStorageFormat, Name::Strict<146> > >, Optional<Attribute<mpl::int_<652>, Name::Strict<651> > >, Attribute<mpl::int_<9186>, Name::Strict<105> > > > marshal_type;

	static int parse(Domain::Xml::Driver2& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Driver2& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7016 traits

template<>
struct Traits<Domain::Xml::Filesystem7016>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<500>, Name::Strict<105> >, Optional<Element<Domain::Xml::Driver2, Name::Strict<546> > >, Element<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<500> >, Name::Strict<501> > > > marshal_type;

	static int parse(Domain::Xml::Filesystem7016& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Filesystem7016& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7017 traits

template<>
struct Traits<Domain::Xml::Filesystem7017>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<502>, Name::Strict<105> >, Optional<Element<Domain::Xml::Driver2, Name::Strict<546> > >, Element<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<441> >, Name::Strict<501> > > > marshal_type;

	static int parse(Domain::Xml::Filesystem7017& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Filesystem7017& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7018 traits

template<>
struct Traits<Domain::Xml::Filesystem7018>
{
	typedef Ordered<mpl::vector<Optional<Attribute<mpl::int_<634>, Name::Strict<105> > >, Optional<Element<Domain::Xml::Driver2, Name::Strict<546> > >, Element<Attribute<Domain::Xml::PAbsDirPath, Name::Strict<164> >, Name::Strict<501> > > > marshal_type;

	static int parse(Domain::Xml::Filesystem7018& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Filesystem7018& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7019 traits

template<>
struct Traits<Domain::Xml::Filesystem7019>
{
	typedef Ordered<mpl::vector<Optional<Attribute<mpl::int_<636>, Name::Strict<105> > >, Optional<Element<Domain::Xml::Driver2, Name::Strict<546> > >, Element<Attribute<Domain::Xml::PAbsDirPath, Name::Strict<164> >, Name::Strict<501> > > > marshal_type;

	static int parse(Domain::Xml::Filesystem7019& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Filesystem7019& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7020 traits

template<>
struct Traits<Domain::Xml::Filesystem7020>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<278>, Name::Strict<105> >, Optional<Element<Domain::Xml::Driver2, Name::Strict<546> > >, Element<Attribute<Domain::Xml::PGenericName, Name::Strict<107> >, Name::Strict<501> > > > marshal_type;

	static int parse(Domain::Xml::Filesystem7020& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Filesystem7020& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source5 traits

template<>
struct Traits<Domain::Xml::Source5>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedLong, Name::Strict<640> >, Optional<Attribute<Domain::Xml::PUnit, Name::Strict<641> > > > > marshal_type;

	static int parse(Domain::Xml::Source5& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source5& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7021 traits

template<>
struct Traits<Domain::Xml::Filesystem7021>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<639>, Name::Strict<105> >, Optional<Element<Domain::Xml::Driver2, Name::Strict<546> > >, Element<Domain::Xml::Source5, Name::Strict<501> > > > marshal_type;

	static int parse(Domain::Xml::Filesystem7021& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Filesystem7021& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem traits

template<>
struct Traits<Domain::Xml::Filesystem>
{
	typedef Ordered<mpl::vector<Domain::Xml::VFilesystemImpl, Unordered<mpl::vector<Element<Attribute<Domain::Xml::PAbsDirPath, Name::Strict<164> >, Name::Strict<323> >, Optional<Attribute<Domain::Xml::EAccessmode, Name::Strict<643> > >, Optional<Attribute<Domain::Xml::EMultidevs, Name::Strict<9376> > >, Optional<Attribute<Domain::Xml::PCreateMode, Name::Strict<9379> > >, Optional<Attribute<Domain::Xml::PCreateMode, Name::Strict<9380> > >, Optional<Element<Empty, Name::Strict<274> > >, Optional<Element<Domain::Xml::Boot, Name::Strict<407> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > > > >, Unordered<mpl::vector<Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<647> > >, Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<648> > > > >, Optional<Attribute<Domain::Xml::EModel6, Name::Strict<231> > > > > marshal_type;

	static int parse(Domain::Xml::Filesystem& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Filesystem& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct InterfaceBridgeAttributes traits

template<>
struct Traits<Domain::Xml::InterfaceBridgeAttributes>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PDeviceName, Name::Strict<656> >, Optional<Attribute<Domain::Xml::EMacTableManager, Name::Strict<213> > > > > marshal_type;

	static int parse(Domain::Xml::InterfaceBridgeAttributes& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::InterfaceBridgeAttributes& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct InterfaceNetworkAttributes traits

template<>
struct Traits<Domain::Xml::InterfaceNetworkAttributes>
{
	typedef Ordered<mpl::vector<Attribute<QString, Name::Strict<445> >, Optional<Attribute<Domain::Xml::PDeviceName, Name::Strict<654> > >, Optional<Attribute<Domain::Xml::VUUID, Name::Strict<9381> > > > > marshal_type;

	static int parse(Domain::Xml::InterfaceNetworkAttributes& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::InterfaceNetworkAttributes& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source6 traits

template<>
struct Traits<Domain::Xml::Source6>
{
	typedef Ordered<mpl::vector<Fragment<Domain::Xml::InterfaceBridgeAttributes >, Optional<Fragment<Domain::Xml::InterfaceNetworkAttributes > > > > marshal_type;

	static int parse(Domain::Xml::Source6& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source6& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Parameters traits

template<>
struct Traits<Domain::Xml::Parameters>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::VUint8, Name::Strict<181> > >, Optional<Attribute<Domain::Xml::VUint24, Name::Strict<182> > >, Optional<Attribute<Domain::Xml::VUint8, Name::Strict<183> > >, Optional<Attribute<Domain::Xml::VUUID, Name::Strict<184> > > > > marshal_type;

	static int parse(Domain::Xml::Parameters& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Parameters& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Parameters1 traits

template<>
struct Traits<Domain::Xml::Parameters1>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PVirtualPortProfileID, Name::Strict<187> > > > > marshal_type;

	static int parse(Domain::Xml::Parameters1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Parameters1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Parameters2 traits

template<>
struct Traits<Domain::Xml::Parameters2>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PVirtualPortProfileID, Name::Strict<187> > >, Optional<Attribute<Domain::Xml::VUUID, Name::Strict<190> > > > > marshal_type;

	static int parse(Domain::Xml::Parameters2& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Parameters2& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Parameters3 traits

template<>
struct Traits<Domain::Xml::Parameters3>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::VUint8, Name::Strict<181> > >, Optional<Attribute<Domain::Xml::VUint24, Name::Strict<182> > >, Optional<Attribute<Domain::Xml::VUint8, Name::Strict<183> > >, Optional<Attribute<Domain::Xml::VUUID, Name::Strict<184> > >, Optional<Attribute<Domain::Xml::PVirtualPortProfileID, Name::Strict<187> > >, Optional<Attribute<Domain::Xml::VUUID, Name::Strict<190> > > > > marshal_type;

	static int parse(Domain::Xml::Parameters3& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Parameters3& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Virtualport traits

template<>
struct Traits<Domain::Xml::Virtualport>
{
	typedef Ordered<mpl::vector<Optional<Element<Domain::Xml::Parameters3, Name::Strict<180> > > > > marshal_type;

	static int parse(Domain::Xml::Virtualport& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Virtualport& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Frames traits

template<>
struct Traits<Domain::Xml::Frames>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<1880> > > > > marshal_type;

	static int parse(Domain::Xml::Frames& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Frames& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Rx traits

template<>
struct Traits<Domain::Xml::Rx>
{
	typedef Ordered<mpl::vector<Optional<Element<Domain::Xml::Frames, Name::Strict<9430> > > > > marshal_type;

	static int parse(Domain::Xml::Rx& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Rx& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Coalesce traits

template<>
struct Traits<Domain::Xml::Coalesce>
{
	typedef Ordered<mpl::vector<Optional<Element<Domain::Xml::Rx, Name::Strict<9429> > > > > marshal_type;

	static int parse(Domain::Xml::Coalesce& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Coalesce& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct VzDhcp traits

template<>
struct Traits<Domain::Xml::VzDhcp>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PAddrFamily, Name::Strict<690> > > > > marshal_type;

	static int parse(Domain::Xml::VzDhcp& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::VzDhcp& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct VzDns1 traits

template<>
struct Traits<Domain::Xml::VzDns1>
{
	typedef Ordered<mpl::vector<ZeroOrMore<Element<Text<Domain::Xml::VIpAddr >, Name::Strict<663> > >, ZeroOrMore<Element<Text<Domain::Xml::PDnsName >, Name::Strict<5707> > > > > marshal_type;

	static int parse(Domain::Xml::VzDns1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::VzDns1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Target3 traits

template<>
struct Traits<Domain::Xml::Target3>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PDeviceName, Name::Strict<441> >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<677> > > > > marshal_type;

	static int parse(Domain::Xml::Target3& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Target3& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Guest traits

template<>
struct Traits<Domain::Xml::Guest>
{
	typedef Unordered<mpl::vector<Optional<Attribute<Domain::Xml::PDeviceName, Name::Strict<441> > >, Optional<Attribute<Domain::Xml::PDeviceName, Name::Strict<688> > > > > marshal_type;

	static int parse(Domain::Xml::Guest& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Guest& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Ip traits

template<>
struct Traits<Domain::Xml::Ip>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::VIpAddr, Name::Strict<111> >, Optional<Attribute<Domain::Xml::PAddrFamily, Name::Strict<690> > >, Optional<Attribute<Domain::Xml::VIpPrefix, Name::Strict<691> > > > > marshal_type;

	static int parse(Domain::Xml::Ip& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Ip& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Route traits

template<>
struct Traits<Domain::Xml::Route>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PAddrFamily, Name::Strict<690> > >, Attribute<Domain::Xml::VIpAddr, Name::Strict<111> >, Optional<Domain::Xml::VChoice7116Impl >, Attribute<Domain::Xml::VIpAddr, Name::Strict<1260> >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<1261> > > > > marshal_type;

	static int parse(Domain::Xml::Route& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Route& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Backend traits

template<>
struct Traits<Domain::Xml::Backend>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<694> > >, Optional<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<695> > > > > marshal_type;

	static int parse(Domain::Xml::Backend& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Backend& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Driver7037 traits

template<>
struct Traits<Domain::Xml::Driver7037>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EName6, Name::Strict<107> > >, Optional<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<627> > >, Optional<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<5080> > >, Optional<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<5081> > >, Optional<Attribute<Domain::Xml::ETxmode, Name::Strict<698> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<552> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<553> > > > > marshal_type;

	static int parse(Domain::Xml::Driver7037& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Driver7037& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Host traits

template<>
struct Traits<Domain::Xml::Host>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<700> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<701> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<702> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<703> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<704> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<705> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<9384> > > > > marshal_type;

	static int parse(Domain::Xml::Host& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Host& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Guest1 traits

template<>
struct Traits<Domain::Xml::Guest1>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<700> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<702> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<703> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<704> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<705> > > > > marshal_type;

	static int parse(Domain::Xml::Guest1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Guest1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Driver3 traits

template<>
struct Traits<Domain::Xml::Driver3>
{
	typedef Ordered<mpl::vector<Domain::Xml::VDriverImpl, Unordered<mpl::vector<Optional<Element<Domain::Xml::Host, Name::Strict<513> > >, Optional<Element<Domain::Xml::Guest1, Name::Strict<408> > > > > > > marshal_type;

	static int parse(Domain::Xml::Driver3& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Driver3& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Parameter traits

template<>
struct Traits<Domain::Xml::Parameter>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PFilterParamName, Name::Strict<107> >, Attribute<Domain::Xml::PFilterParamValue, Name::Strict<1086> > > > marshal_type;

	static int parse(Domain::Xml::Parameter& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Parameter& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct FilterrefNodeAttributes traits

template<>
struct Traits<Domain::Xml::FilterrefNodeAttributes>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PFilter, Name::Strict<764> >, ZeroOrMore<Element<Domain::Xml::Parameter, Name::Strict<1084> > > > > marshal_type;

	static int parse(Domain::Xml::FilterrefNodeAttributes& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::FilterrefNodeAttributes& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Tune traits

template<>
struct Traits<Domain::Xml::Tune>
{
	typedef Ordered<mpl::vector<Optional<Element<Text<Domain::Xml::PUnsignedInt >, Name::Strict<709> > > > > marshal_type;

	static int parse(Domain::Xml::Tune& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Tune& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Rom traits

template<>
struct Traits<Domain::Xml::Rom>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<344> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<1067> > >, Optional<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<500> > > > > marshal_type;

	static int parse(Domain::Xml::Rom& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Rom& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct BandwidthAttributes traits

template<>
struct Traits<Domain::Xml::BandwidthAttributes>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PSpeed, Name::Strict<197> > >, Optional<Attribute<Domain::Xml::PSpeed, Name::Strict<198> > >, Optional<Attribute<Domain::Xml::PSpeed, Name::Strict<199> > >, Optional<Attribute<Domain::Xml::PBurstSize, Name::Strict<200> > > > > marshal_type;

	static int parse(Domain::Xml::BandwidthAttributes& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::BandwidthAttributes& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Bandwidth1 traits

template<>
struct Traits<Domain::Xml::Bandwidth1>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<5774> > >, Unordered<mpl::vector<Optional<Element<Domain::Xml::BandwidthAttributes, Name::Strict<194> > >, Optional<Element<Domain::Xml::BandwidthAttributes, Name::Strict<196> > > > > > > marshal_type;

	static int parse(Domain::Xml::Bandwidth1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Bandwidth1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Tag traits

template<>
struct Traits<Domain::Xml::Tag>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PId, Name::Strict<208> >, Optional<Attribute<Domain::Xml::ENativeMode, Name::Strict<209> > > > > marshal_type;

	static int parse(Domain::Xml::Tag& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Tag& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Port traits

template<>
struct Traits<Domain::Xml::Port>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<5777> > > > > marshal_type;

	static int parse(Domain::Xml::Port& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Port& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Teaming9388 traits

template<>
struct Traits<Domain::Xml::Teaming9388>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<9388>, Name::Strict<105> > > > marshal_type;

	static int parse(Domain::Xml::Teaming9388& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Teaming9388& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Interface7022 traits

template<>
struct Traits<Domain::Xml::Interface7022>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<656>, Name::Strict<105> >, Unordered<mpl::vector<Optional<Element<Domain::Xml::Source6, Name::Strict<501> > >, Optional<Domain::Xml::VVirtualPortProfileImpl >, Optional<Element<Attribute<Domain::Xml::EState, Name::Strict<126> >, Name::Strict<124> > >, Optional<Element<Attribute<Domain::Xml::PUnsignedShort, Name::Strict<334> >, Name::Strict<1309> > >, Optional<Element<Domain::Xml::Coalesce, Name::Strict<9382> > >, Optional<ZeroOrMore<Element<Domain::Xml::VzDhcp, Name::Strict<5704> > > >, Optional<Element<Domain::Xml::VzDns1, Name::Strict<5706> > >, Optional<Element<Domain::Xml::Target3, Name::Strict<323> > >, Optional<Element<Domain::Xml::Guest, Name::Strict<408> > >, Optional<Element<Attribute<Domain::Xml::PUniMacAddr, Name::Strict<111> >, Name::Strict<673> > >, ZeroOrMore<Element<Domain::Xml::Ip, Name::Strict<689> > >, ZeroOrMore<Element<Domain::Xml::Route, Name::Strict<1230> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<692> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<9383> > >, Optional<Element<Attribute<Domain::Xml::PObjectNameWithSlash, Name::Strict<107> >, Name::Strict<9372> > >, Optional<Element<Attribute<Domain::Xml::PType, Name::Strict<105> >, Name::Strict<231> > >, Optional<Element<Domain::Xml::Backend, Name::Strict<693> > >, Optional<Element<Domain::Xml::Driver3, Name::Strict<546> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Domain::Xml::FilterrefNodeAttributes, Name::Strict<706> > >, Optional<Element<Domain::Xml::Tune, Name::Strict<708> > >, Optional<Element<Domain::Xml::Boot, Name::Strict<407> > >, Optional<Element<Domain::Xml::Rom, Name::Strict<275> > >, Optional<Element<Domain::Xml::Bandwidth1, Name::Strict<193> > >, Optional<Element<Ordered<mpl::vector<Optional<Attribute<mpl::int_<135>, Name::Strict<206> > >, OneOrMore<Element<Domain::Xml::Tag, Name::Strict<207> > > > >, Name::Strict<205> > >, Optional<Element<Domain::Xml::Port, Name::Strict<212> > >, Optional<Element<Domain::Xml::VTeamingImpl, Name::Strict<9385> > > > > > > marshal_type;

	static int parse(Domain::Xml::Interface7022& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Interface7022& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Interface7023 traits

template<>
struct Traits<Domain::Xml::Interface7023>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<660>, Name::Strict<105> >, Unordered<mpl::vector<Optional<Element<Attribute<Domain::Xml::PDeviceName, Name::Strict<441> >, Name::Strict<501> > >, Optional<Element<Attribute<Domain::Xml::EState, Name::Strict<126> >, Name::Strict<124> > >, Optional<Element<Attribute<Domain::Xml::PUnsignedShort, Name::Strict<334> >, Name::Strict<1309> > >, Optional<Element<Domain::Xml::Coalesce, Name::Strict<9382> > >, Optional<ZeroOrMore<Element<Domain::Xml::VzDhcp, Name::Strict<5704> > > >, Optional<Element<Domain::Xml::VzDns1, Name::Strict<5706> > >, Optional<Element<Domain::Xml::Target3, Name::Strict<323> > >, Optional<Element<Domain::Xml::Guest, Name::Strict<408> > >, Optional<Element<Attribute<Domain::Xml::PUniMacAddr, Name::Strict<111> >, Name::Strict<673> > >, ZeroOrMore<Element<Domain::Xml::Ip, Name::Strict<689> > >, ZeroOrMore<Element<Domain::Xml::Route, Name::Strict<1230> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<692> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<9383> > >, Optional<Element<Attribute<Domain::Xml::PObjectNameWithSlash, Name::Strict<107> >, Name::Strict<9372> > >, Optional<Element<Attribute<Domain::Xml::PType, Name::Strict<105> >, Name::Strict<231> > >, Optional<Element<Domain::Xml::Backend, Name::Strict<693> > >, Optional<Element<Domain::Xml::Driver3, Name::Strict<546> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Domain::Xml::FilterrefNodeAttributes, Name::Strict<706> > >, Optional<Element<Domain::Xml::Tune, Name::Strict<708> > >, Optional<Element<Domain::Xml::Boot, Name::Strict<407> > >, Optional<Element<Domain::Xml::Rom, Name::Strict<275> > >, Optional<Element<Domain::Xml::Bandwidth1, Name::Strict<193> > >, Optional<Element<Ordered<mpl::vector<Optional<Attribute<mpl::int_<135>, Name::Strict<206> > >, OneOrMore<Element<Domain::Xml::Tag, Name::Strict<207> > > > >, Name::Strict<205> > >, Optional<Element<Domain::Xml::Port, Name::Strict<212> > >, Optional<Element<Domain::Xml::VTeamingImpl, Name::Strict<9385> > > > > > > marshal_type;

	static int parse(Domain::Xml::Interface7023& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Interface7023& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source7 traits

template<>
struct Traits<Domain::Xml::Source7>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EType11, Name::Strict<105> >, Attribute<Domain::Xml::PAbsFilePath, Name::Strict<355> >, Attribute<Domain::Xml::EMode9, Name::Strict<379> > > > marshal_type;

	static int parse(Domain::Xml::Source7& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source7& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Interface7024 traits

template<>
struct Traits<Domain::Xml::Interface7024>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<662>, Name::Strict<105> >, Unordered<mpl::vector<Element<Domain::Xml::Source7, Name::Strict<501> >, Optional<Element<Attribute<Domain::Xml::EState, Name::Strict<126> >, Name::Strict<124> > >, Optional<Element<Attribute<Domain::Xml::PUnsignedShort, Name::Strict<334> >, Name::Strict<1309> > >, Optional<Element<Domain::Xml::Coalesce, Name::Strict<9382> > >, Optional<ZeroOrMore<Element<Domain::Xml::VzDhcp, Name::Strict<5704> > > >, Optional<Element<Domain::Xml::VzDns1, Name::Strict<5706> > >, Optional<Element<Domain::Xml::Target3, Name::Strict<323> > >, Optional<Element<Domain::Xml::Guest, Name::Strict<408> > >, Optional<Element<Attribute<Domain::Xml::PUniMacAddr, Name::Strict<111> >, Name::Strict<673> > >, ZeroOrMore<Element<Domain::Xml::Ip, Name::Strict<689> > >, ZeroOrMore<Element<Domain::Xml::Route, Name::Strict<1230> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<692> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<9383> > >, Optional<Element<Attribute<Domain::Xml::PObjectNameWithSlash, Name::Strict<107> >, Name::Strict<9372> > >, Optional<Element<Attribute<Domain::Xml::PType, Name::Strict<105> >, Name::Strict<231> > >, Optional<Element<Domain::Xml::Backend, Name::Strict<693> > >, Optional<Element<Domain::Xml::Driver3, Name::Strict<546> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Domain::Xml::FilterrefNodeAttributes, Name::Strict<706> > >, Optional<Element<Domain::Xml::Tune, Name::Strict<708> > >, Optional<Element<Domain::Xml::Boot, Name::Strict<407> > >, Optional<Element<Domain::Xml::Rom, Name::Strict<275> > >, Optional<Element<Domain::Xml::Bandwidth1, Name::Strict<193> > >, Optional<Element<Ordered<mpl::vector<Optional<Attribute<mpl::int_<135>, Name::Strict<206> > >, OneOrMore<Element<Domain::Xml::Tag, Name::Strict<207> > > > >, Name::Strict<205> > >, Optional<Element<Domain::Xml::Port, Name::Strict<212> > >, Optional<Element<Domain::Xml::VTeamingImpl, Name::Strict<9385> > > > > > > marshal_type;

	static int parse(Domain::Xml::Interface7024& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Interface7024& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source8 traits

template<>
struct Traits<Domain::Xml::Source8>
{
	typedef Ordered<mpl::vector<Fragment<Domain::Xml::InterfaceNetworkAttributes >, Optional<Fragment<Domain::Xml::InterfaceBridgeAttributes > > > > marshal_type;

	static int parse(Domain::Xml::Source8& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source8& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Interface7025 traits

template<>
struct Traits<Domain::Xml::Interface7025>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<445>, Name::Strict<105> >, Unordered<mpl::vector<Element<Domain::Xml::Source8, Name::Strict<501> >, Optional<Domain::Xml::VVirtualPortProfileImpl >, Optional<Element<Attribute<Domain::Xml::EState, Name::Strict<126> >, Name::Strict<124> > >, Optional<Element<Attribute<Domain::Xml::PUnsignedShort, Name::Strict<334> >, Name::Strict<1309> > >, Optional<Element<Domain::Xml::Coalesce, Name::Strict<9382> > >, Optional<ZeroOrMore<Element<Domain::Xml::VzDhcp, Name::Strict<5704> > > >, Optional<Element<Domain::Xml::VzDns1, Name::Strict<5706> > >, Optional<Element<Domain::Xml::Target3, Name::Strict<323> > >, Optional<Element<Domain::Xml::Guest, Name::Strict<408> > >, Optional<Element<Attribute<Domain::Xml::PUniMacAddr, Name::Strict<111> >, Name::Strict<673> > >, ZeroOrMore<Element<Domain::Xml::Ip, Name::Strict<689> > >, ZeroOrMore<Element<Domain::Xml::Route, Name::Strict<1230> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<692> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<9383> > >, Optional<Element<Attribute<Domain::Xml::PObjectNameWithSlash, Name::Strict<107> >, Name::Strict<9372> > >, Optional<Element<Attribute<Domain::Xml::PType, Name::Strict<105> >, Name::Strict<231> > >, Optional<Element<Domain::Xml::Backend, Name::Strict<693> > >, Optional<Element<Domain::Xml::Driver3, Name::Strict<546> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Domain::Xml::FilterrefNodeAttributes, Name::Strict<706> > >, Optional<Element<Domain::Xml::Tune, Name::Strict<708> > >, Optional<Element<Domain::Xml::Boot, Name::Strict<407> > >, Optional<Element<Domain::Xml::Rom, Name::Strict<275> > >, Optional<Element<Domain::Xml::Bandwidth1, Name::Strict<193> > >, Optional<Element<Ordered<mpl::vector<Optional<Attribute<mpl::int_<135>, Name::Strict<206> > >, OneOrMore<Element<Domain::Xml::Tag, Name::Strict<207> > > > >, Name::Strict<205> > >, Optional<Element<Domain::Xml::Port, Name::Strict<212> > >, Optional<Element<Domain::Xml::VTeamingImpl, Name::Strict<9385> > > > > > > marshal_type;

	static int parse(Domain::Xml::Interface7025& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Interface7025& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source9 traits

template<>
struct Traits<Domain::Xml::Source9>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PDeviceName, Name::Strict<441> >, Optional<Attribute<Domain::Xml::PBridgeMode, Name::Strict<379> > >, Optional<Fragment<Domain::Xml::InterfaceNetworkAttributes > > > > marshal_type;

	static int parse(Domain::Xml::Source9& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source9& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Interface7026 traits

template<>
struct Traits<Domain::Xml::Interface7026>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<525>, Name::Strict<105> >, Unordered<mpl::vector<Element<Domain::Xml::Source9, Name::Strict<501> >, Optional<Domain::Xml::VVirtualPortProfileImpl >, Optional<Element<Attribute<Domain::Xml::EState, Name::Strict<126> >, Name::Strict<124> > >, Optional<Element<Attribute<Domain::Xml::PUnsignedShort, Name::Strict<334> >, Name::Strict<1309> > >, Optional<Element<Domain::Xml::Coalesce, Name::Strict<9382> > >, Optional<ZeroOrMore<Element<Domain::Xml::VzDhcp, Name::Strict<5704> > > >, Optional<Element<Domain::Xml::VzDns1, Name::Strict<5706> > >, Optional<Element<Domain::Xml::Target3, Name::Strict<323> > >, Optional<Element<Domain::Xml::Guest, Name::Strict<408> > >, Optional<Element<Attribute<Domain::Xml::PUniMacAddr, Name::Strict<111> >, Name::Strict<673> > >, ZeroOrMore<Element<Domain::Xml::Ip, Name::Strict<689> > >, ZeroOrMore<Element<Domain::Xml::Route, Name::Strict<1230> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<692> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<9383> > >, Optional<Element<Attribute<Domain::Xml::PObjectNameWithSlash, Name::Strict<107> >, Name::Strict<9372> > >, Optional<Element<Attribute<Domain::Xml::PType, Name::Strict<105> >, Name::Strict<231> > >, Optional<Element<Domain::Xml::Backend, Name::Strict<693> > >, Optional<Element<Domain::Xml::Driver3, Name::Strict<546> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Domain::Xml::FilterrefNodeAttributes, Name::Strict<706> > >, Optional<Element<Domain::Xml::Tune, Name::Strict<708> > >, Optional<Element<Domain::Xml::Boot, Name::Strict<407> > >, Optional<Element<Domain::Xml::Rom, Name::Strict<275> > >, Optional<Element<Domain::Xml::Bandwidth1, Name::Strict<193> > >, Optional<Element<Ordered<mpl::vector<Optional<Attribute<mpl::int_<135>, Name::Strict<206> > >, OneOrMore<Element<Domain::Xml::Tag, Name::Strict<207> > > > >, Name::Strict<205> > >, Optional<Element<Domain::Xml::Port, Name::Strict<212> > >, Optional<Element<Domain::Xml::VTeamingImpl, Name::Strict<9385> > > > > > > marshal_type;

	static int parse(Domain::Xml::Interface7026& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Interface7026& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct InterfaceOptions traits

template<>
struct Traits<Domain::Xml::InterfaceOptions>
{
	typedef Unordered<mpl::vector<Optional<Element<Attribute<Domain::Xml::EState, Name::Strict<126> >, Name::Strict<124> > >, Optional<Element<Attribute<Domain::Xml::PUnsignedShort, Name::Strict<334> >, Name::Strict<1309> > >, Optional<Element<Domain::Xml::Coalesce, Name::Strict<9382> > >, Optional<ZeroOrMore<Element<Domain::Xml::VzDhcp, Name::Strict<5704> > > >, Optional<Element<Domain::Xml::VzDns1, Name::Strict<5706> > >, Optional<Element<Domain::Xml::Target3, Name::Strict<323> > >, Optional<Element<Domain::Xml::Guest, Name::Strict<408> > >, Optional<Element<Attribute<Domain::Xml::PUniMacAddr, Name::Strict<111> >, Name::Strict<673> > >, ZeroOrMore<Element<Domain::Xml::Ip, Name::Strict<689> > >, ZeroOrMore<Element<Domain::Xml::Route, Name::Strict<1230> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<692> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<9383> > >, Optional<Element<Attribute<Domain::Xml::PObjectNameWithSlash, Name::Strict<107> >, Name::Strict<9372> > >, Optional<Element<Attribute<Domain::Xml::PType, Name::Strict<105> >, Name::Strict<231> > >, Optional<Element<Domain::Xml::Backend, Name::Strict<693> > >, Optional<Element<Domain::Xml::Driver3, Name::Strict<546> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Domain::Xml::FilterrefNodeAttributes, Name::Strict<706> > >, Optional<Element<Domain::Xml::Tune, Name::Strict<708> > >, Optional<Element<Domain::Xml::Boot, Name::Strict<407> > >, Optional<Element<Domain::Xml::Rom, Name::Strict<275> > >, Optional<Element<Domain::Xml::Bandwidth1, Name::Strict<193> > >, Optional<Element<Ordered<mpl::vector<Optional<Attribute<mpl::int_<135>, Name::Strict<206> > >, OneOrMore<Element<Domain::Xml::Tag, Name::Strict<207> > > > >, Name::Strict<205> > >, Optional<Element<Domain::Xml::Port, Name::Strict<212> > >, Optional<Element<Domain::Xml::VTeamingImpl, Name::Strict<9385> > > > > marshal_type;

	static int parse(Domain::Xml::InterfaceOptions& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::InterfaceOptions& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Interface7028 traits

template<>
struct Traits<Domain::Xml::Interface7028>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<463>, Name::Strict<105> >, Unordered<mpl::vector<Element<Attribute<Domain::Xml::PDeviceName, Name::Strict<107> >, Name::Strict<501> >, Optional<Element<Attribute<Domain::Xml::EState, Name::Strict<126> >, Name::Strict<124> > >, Optional<Element<Attribute<Domain::Xml::PUnsignedShort, Name::Strict<334> >, Name::Strict<1309> > >, Optional<Element<Domain::Xml::Coalesce, Name::Strict<9382> > >, Optional<ZeroOrMore<Element<Domain::Xml::VzDhcp, Name::Strict<5704> > > >, Optional<Element<Domain::Xml::VzDns1, Name::Strict<5706> > >, Optional<Element<Domain::Xml::Target3, Name::Strict<323> > >, Optional<Element<Domain::Xml::Guest, Name::Strict<408> > >, Optional<Element<Attribute<Domain::Xml::PUniMacAddr, Name::Strict<111> >, Name::Strict<673> > >, ZeroOrMore<Element<Domain::Xml::Ip, Name::Strict<689> > >, ZeroOrMore<Element<Domain::Xml::Route, Name::Strict<1230> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<692> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<9383> > >, Optional<Element<Attribute<Domain::Xml::PObjectNameWithSlash, Name::Strict<107> >, Name::Strict<9372> > >, Optional<Element<Attribute<Domain::Xml::PType, Name::Strict<105> >, Name::Strict<231> > >, Optional<Element<Domain::Xml::Backend, Name::Strict<693> > >, Optional<Element<Domain::Xml::Driver3, Name::Strict<546> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Domain::Xml::FilterrefNodeAttributes, Name::Strict<706> > >, Optional<Element<Domain::Xml::Tune, Name::Strict<708> > >, Optional<Element<Domain::Xml::Boot, Name::Strict<407> > >, Optional<Element<Domain::Xml::Rom, Name::Strict<275> > >, Optional<Element<Domain::Xml::Bandwidth1, Name::Strict<193> > >, Optional<Element<Ordered<mpl::vector<Optional<Attribute<mpl::int_<135>, Name::Strict<206> > >, OneOrMore<Element<Domain::Xml::Tag, Name::Strict<207> > > > >, Name::Strict<205> > >, Optional<Element<Domain::Xml::Port, Name::Strict<212> > >, Optional<Element<Domain::Xml::VTeamingImpl, Name::Strict<9385> > > > > > > marshal_type;

	static int parse(Domain::Xml::Interface7028& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Interface7028& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source10 traits

template<>
struct Traits<Domain::Xml::Source10>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PIpv4Addr, Name::Strict<111> >, Attribute<Domain::Xml::PPortNumber, Name::Strict<212> > > > marshal_type;

	static int parse(Domain::Xml::Source10& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source10& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Interface7029 traits

template<>
struct Traits<Domain::Xml::Interface7029>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EType12, Name::Strict<105> >, Unordered<mpl::vector<Element<Domain::Xml::Source10, Name::Strict<501> >, Optional<Element<Attribute<Domain::Xml::PUniMacAddr, Name::Strict<111> >, Name::Strict<673> > > > > > > marshal_type;

	static int parse(Domain::Xml::Interface7029& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Interface7029& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source11 traits

template<>
struct Traits<Domain::Xml::Source11>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PIpv4Addr, Name::Strict<111> > >, Attribute<Domain::Xml::PPortNumber, Name::Strict<212> > > > marshal_type;

	static int parse(Domain::Xml::Source11& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source11& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Interface7030 traits

template<>
struct Traits<Domain::Xml::Interface7030>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<663>, Name::Strict<105> >, Unordered<mpl::vector<Element<Domain::Xml::Source11, Name::Strict<501> >, Optional<Element<Attribute<Domain::Xml::PUniMacAddr, Name::Strict<111> >, Name::Strict<673> > > > > > > marshal_type;

	static int parse(Domain::Xml::Interface7030& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Interface7030& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Usbproduct traits

template<>
struct Traits<Domain::Xml::Usbproduct>
{
	typedef Ordered<mpl::vector<Element<Attribute<Domain::Xml::PUsbId, Name::Strict<208> >, Name::Strict<459> >, Element<Attribute<Domain::Xml::PUsbId, Name::Strict<208> >, Name::Strict<460> > > > marshal_type;

	static int parse(Domain::Xml::Usbproduct& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Usbproduct& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Address traits

template<>
struct Traits<Domain::Xml::Address>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUsbAddr, Name::Strict<29> >, Attribute<Domain::Xml::PUsbPort, Name::Strict<354> > > > marshal_type;

	static int parse(Domain::Xml::Address& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Address& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source7031 traits

template<>
struct Traits<Domain::Xml::Source7031>
{
	typedef Ordered<mpl::vector<Fragment<Domain::Xml::Usbproduct >, Optional<Element<Domain::Xml::Address, Name::Strict<111> > > > > marshal_type;

	static int parse(Domain::Xml::Source7031& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source7031& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Address7033 traits

template<>
struct Traits<Domain::Xml::Address7033>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<531>, Name::Strict<105> >, Attribute<Domain::Xml::PUsbAddr, Name::Strict<29> >, Attribute<Domain::Xml::PUsbPort, Name::Strict<354> > > > marshal_type;

	static int parse(Domain::Xml::Address7033& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Address7033& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source12 traits

template<>
struct Traits<Domain::Xml::Source12>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<678> > >, Domain::Xml::VSourceImpl > > marshal_type;

	static int parse(Domain::Xml::Source12& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source12& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Interface7035 traits

template<>
struct Traits<Domain::Xml::Interface7035>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<676>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<677> > >, Unordered<mpl::vector<Element<Domain::Xml::Source12, Name::Strict<501> >, Optional<Domain::Xml::VVirtualPortProfileImpl >, Optional<Element<Attribute<Domain::Xml::EState, Name::Strict<126> >, Name::Strict<124> > >, Optional<Element<Attribute<Domain::Xml::PUnsignedShort, Name::Strict<334> >, Name::Strict<1309> > >, Optional<Element<Domain::Xml::Coalesce, Name::Strict<9382> > >, Optional<ZeroOrMore<Element<Domain::Xml::VzDhcp, Name::Strict<5704> > > >, Optional<Element<Domain::Xml::VzDns1, Name::Strict<5706> > >, Optional<Element<Domain::Xml::Target3, Name::Strict<323> > >, Optional<Element<Domain::Xml::Guest, Name::Strict<408> > >, Optional<Element<Attribute<Domain::Xml::PUniMacAddr, Name::Strict<111> >, Name::Strict<673> > >, ZeroOrMore<Element<Domain::Xml::Ip, Name::Strict<689> > >, ZeroOrMore<Element<Domain::Xml::Route, Name::Strict<1230> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<692> > >, Optional<Element<Attribute<Domain::Xml::PFilePath, Name::Strict<355> >, Name::Strict<9383> > >, Optional<Element<Attribute<Domain::Xml::PObjectNameWithSlash, Name::Strict<107> >, Name::Strict<9372> > >, Optional<Element<Attribute<Domain::Xml::PType, Name::Strict<105> >, Name::Strict<231> > >, Optional<Element<Domain::Xml::Backend, Name::Strict<693> > >, Optional<Element<Domain::Xml::Driver3, Name::Strict<546> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Domain::Xml::FilterrefNodeAttributes, Name::Strict<706> > >, Optional<Element<Domain::Xml::Tune, Name::Strict<708> > >, Optional<Element<Domain::Xml::Boot, Name::Strict<407> > >, Optional<Element<Domain::Xml::Rom, Name::Strict<275> > >, Optional<Element<Domain::Xml::Bandwidth1, Name::Strict<193> > >, Optional<Element<Ordered<mpl::vector<Optional<Attribute<mpl::int_<135>, Name::Strict<206> > >, OneOrMore<Element<Domain::Xml::Tag, Name::Strict<207> > > > >, Name::Strict<205> > >, Optional<Element<Domain::Xml::Port, Name::Strict<212> > >, Optional<Element<Domain::Xml::VTeamingImpl, Name::Strict<9385> > > > > > > marshal_type;

	static int parse(Domain::Xml::Interface7035& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Interface7035& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Interface traits

template<>
struct Traits<Domain::Xml::Interface>
{
	typedef Ordered<mpl::vector<Domain::Xml::VInterfaceImpl, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<5978> > > > > marshal_type;

	static int parse(Domain::Xml::Interface& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Interface& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous9430 traits

template<>
struct Traits<Domain::Xml::Anonymous9430>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EModel7, Name::Strict<231> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > > > > marshal_type;

	static int parse(Domain::Xml::Anonymous9430& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Anonymous9430& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Input traits

template<>
struct Traits<Domain::Xml::Input>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EType13, Name::Strict<105> >, Optional<Attribute<Domain::Xml::EBus1, Name::Strict<29> > >, Optional<Fragment<Domain::Xml::Anonymous9430 > > > > marshal_type;

	static int parse(Domain::Xml::Input& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Input& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Sound traits

template<>
struct Traits<Domain::Xml::Sound>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EModel8, Name::Strict<231> >, Unordered<mpl::vector<Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Attribute<Domain::Xml::VUint8, Name::Strict<208> >, Name::Strict<9397> > >, ZeroOrMore<Element<Attribute<Domain::Xml::EType14, Name::Strict<105> >, Name::Strict<869> > > > > > > marshal_type;

	static int parse(Domain::Xml::Sound& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Sound& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source13 traits

template<>
struct Traits<Domain::Xml::Source13>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EStartupPolicy, Name::Strict<468> > >, Element<Domain::Xml::Pciaddress, Name::Strict<111> > > > marshal_type;

	static int parse(Domain::Xml::Source13& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source13& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevsubsyspci traits

template<>
struct Traits<Domain::Xml::Hostdevsubsyspci>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<596>, Name::Strict<105> >, Unordered<mpl::vector<Optional<Element<Attribute<Domain::Xml::EName7, Name::Strict<107> >, Name::Strict<546> > >, Optional<Element<Domain::Xml::VTeamingImpl, Name::Strict<9385> > >, Element<Domain::Xml::Source13, Name::Strict<501> > > > > > marshal_type;

	static int parse(Domain::Xml::Hostdevsubsyspci& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hostdevsubsyspci& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source7072 traits

template<>
struct Traits<Domain::Xml::Source7072>
{
	typedef Ordered<mpl::vector<Fragment<Domain::Xml::Usbproduct >, Optional<Element<Domain::Xml::Address, Name::Strict<111> > > > > marshal_type;

	static int parse(Domain::Xml::Source7072& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source7072& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source14 traits

template<>
struct Traits<Domain::Xml::Source14>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EStartupPolicy, Name::Strict<468> > >, Domain::Xml::VSource1Impl > > marshal_type;

	static int parse(Domain::Xml::Source14& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source14& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevsubsysusb traits

template<>
struct Traits<Domain::Xml::Hostdevsubsysusb>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<531>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<4929> > >, Element<Domain::Xml::Source14, Name::Strict<501> > > > marshal_type;

	static int parse(Domain::Xml::Hostdevsubsysusb& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hostdevsubsysusb& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Parentaddr traits

template<>
struct Traits<Domain::Xml::Parentaddr>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<110> > >, Element<Domain::Xml::Pciaddress, Name::Strict<111> > > > marshal_type;

	static int parse(Domain::Xml::Parentaddr& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Parentaddr& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Adapter118 traits

template<>
struct Traits<Domain::Xml::Adapter118>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<115>, Name::Strict<105> >, Optional<Attribute<QString, Name::Strict<116> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<677> > >, Optional<Attribute<Domain::Xml::PWwn, Name::Strict<5742> > >, Optional<Attribute<Domain::Xml::PWwn, Name::Strict<5743> > >, Optional<Attribute<Domain::Xml::PWwn, Name::Strict<5744> > >, Attribute<Domain::Xml::PWwn, Name::Strict<117> >, Attribute<Domain::Xml::PWwn, Name::Strict<118> > > > marshal_type;

	static int parse(Domain::Xml::Adapter118& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Adapter118& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Scsiaddress traits

template<>
struct Traits<Domain::Xml::Scsiaddress>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PDriveBus, Name::Strict<29> >, Attribute<Domain::Xml::PDriveTarget, Name::Strict<323> >, Attribute<Domain::Xml::PDriveUnit, Name::Strict<66> > > > marshal_type;

	static int parse(Domain::Xml::Scsiaddress& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Scsiaddress& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source7074 traits

template<>
struct Traits<Domain::Xml::Source7074>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EProtocol1, Name::Strict<203> > >, Unordered<mpl::vector<Element<Domain::Xml::VAdapterImpl, Name::Strict<104> >, Element<Domain::Xml::Scsiaddress, Name::Strict<111> > > > > > marshal_type;

	static int parse(Domain::Xml::Source7074& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source7074& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Host1 traits

template<>
struct Traits<Domain::Xml::Host1>
{
	typedef Ordered<mpl::vector<Attribute<QString, Name::Strict<107> >, Optional<Attribute<Domain::Xml::PPortNumber, Name::Strict<212> > > > > marshal_type;

	static int parse(Domain::Xml::Host1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Host1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source7075 traits

template<>
struct Traits<Domain::Xml::Source7075>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EProtocol2, Name::Strict<203> >, Attribute<QString, Name::Strict<107> >, Unordered<mpl::vector<OneOrMore<Element<Domain::Xml::Host1, Name::Strict<513> > >, Optional<Element<Domain::Xml::Auth, Name::Strict<1097> > >, Optional<Element<Element<Attribute<QString, Name::Strict<107> >, Name::Strict<5755> >, Name::Strict<5754> > > > > > > marshal_type;

	static int parse(Domain::Xml::Source7075& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source7075& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevsubsysscsi traits

template<>
struct Traits<Domain::Xml::Hostdevsubsysscsi>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<529>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::ESgio1, Name::Strict<477> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<1174> > >, Element<Domain::Xml::VSource2Impl, Name::Strict<501> > > > marshal_type;

	static int parse(Domain::Xml::Hostdevsubsysscsi& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hostdevsubsysscsi& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevsubsys traits

template<>
struct Traits<Domain::Xml::Hostdevsubsys>
{
	typedef Ordered<mpl::vector<Optional<Attribute<mpl::int_<919>, Name::Strict<379> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<677> > >, Domain::Xml::VHostdevsubsysImpl > > marshal_type;

	static int parse(Domain::Xml::Hostdevsubsys& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hostdevsubsys& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Ip1 traits

template<>
struct Traits<Domain::Xml::Ip1>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::VIpAddr, Name::Strict<111> >, Optional<Attribute<Domain::Xml::PAddrFamily, Name::Strict<690> > >, Optional<Attribute<Domain::Xml::VIpPrefix, Name::Strict<691> > >, Optional<Attribute<Domain::Xml::VIpAddr, Name::Strict<9387> > > > > marshal_type;

	static int parse(Domain::Xml::Ip1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Ip1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct InterfaceIpInfo traits

template<>
struct Traits<Domain::Xml::InterfaceIpInfo>
{
	typedef Ordered<mpl::vector<ZeroOrMore<Element<Domain::Xml::Ip1, Name::Strict<689> > >, ZeroOrMore<Element<Domain::Xml::Route, Name::Strict<1230> > > > > marshal_type;

	static int parse(Domain::Xml::InterfaceIpInfo& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::InterfaceIpInfo& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevcapsnet traits

template<>
struct Traits<Domain::Xml::Hostdevcapsnet>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<941>, Name::Strict<105> >, Element<Element<Text<Domain::Xml::PDeviceName >, Name::Strict<657> >, Name::Strict<501> >, Fragment<Domain::Xml::InterfaceIpInfo > > > marshal_type;

	static int parse(Domain::Xml::Hostdevcapsnet& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hostdevcapsnet& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hostdev traits

template<>
struct Traits<Domain::Xml::Hostdev>
{
	typedef Unordered<mpl::vector<Domain::Xml::VChoice7065Impl, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::Boot, Name::Strict<407> > >, Optional<Element<Domain::Xml::Rom, Name::Strict<275> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Empty, Name::Strict<274> > >, Optional<Element<Empty, Name::Strict<451> > > > > marshal_type;

	static int parse(Domain::Xml::Hostdev& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hostdev& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7038 traits

template<>
struct Traits<Domain::Xml::Graphics7038>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<713>, Name::Strict<105> >, Optional<Attribute<QString, Name::Strict<714> > >, Optional<Attribute<QString, Name::Strict<715> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<716> > >, Optional<Element<Attribute<Domain::Xml::EVirYesNo, Name::Strict<281> >, Name::Strict<9188> > > > > marshal_type;

	static int parse(Domain::Xml::Graphics7038& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Graphics7038& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Variant5124 traits

template<>
struct Traits<Domain::Xml::Variant5124>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PPortNumber, Name::Strict<212> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<719> > >, Optional<Attribute<Domain::Xml::PPortNumber, Name::Strict<720> > >, Optional<Attribute<Domain::Xml::PAddrIPorName, Name::Strict<721> > >, Optional<Attribute<Domain::Xml::ESharePolicy, Name::Strict<723> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<9391> > > > > marshal_type;

	static int parse(Domain::Xml::Variant5124& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Variant5124& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Listen7044 traits

template<>
struct Traits<Domain::Xml::Listen7044>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<445>, Name::Strict<105> >, Attribute<QString, Name::Strict<445> >, Optional<Attribute<Domain::Xml::PAddrIPorName, Name::Strict<111> > > > > marshal_type;

	static int parse(Domain::Xml::Listen7044& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Listen7044& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Listen9392 traits

template<>
struct Traits<Domain::Xml::Listen9392>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<240>, Name::Strict<105> > > > marshal_type;

	static int parse(Domain::Xml::Listen9392& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Listen9392& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7039 traits

template<>
struct Traits<Domain::Xml::Graphics7039>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<718>, Name::Strict<105> >, Domain::Xml::VChoice5126Impl, Optional<Attribute<QString, Name::Strict<729> > >, Optional<Attribute<QString, Name::Strict<730> > >, Optional<Attribute<Domain::Xml::PPasswdValidTo, Name::Strict<731> > >, Optional<Attribute<Domain::Xml::EConnected, Name::Strict<732> > >, ZeroOrMore<Element<Domain::Xml::VListenImpl, Name::Strict<721> > > > > marshal_type;

	static int parse(Domain::Xml::Graphics7039& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Graphics7039& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Channel traits

template<>
struct Traits<Domain::Xml::Channel>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EName8, Name::Strict<107> >, Attribute<Domain::Xml::EMode10, Name::Strict<379> > > > marshal_type;

	static int parse(Domain::Xml::Channel& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Channel& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Gl traits

template<>
struct Traits<Domain::Xml::Gl>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EVirYesNo, Name::Strict<281> >, Optional<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<8678> > > > > marshal_type;

	static int parse(Domain::Xml::Gl& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Gl& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7040 traits

template<>
struct Traits<Domain::Xml::Graphics7040>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<736>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::PPortNumber, Name::Strict<212> > >, Optional<Attribute<Domain::Xml::PPortNumber, Name::Strict<737> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<719> > >, Optional<Attribute<Domain::Xml::PAddrIPorName, Name::Strict<721> > >, Optional<Attribute<QString, Name::Strict<729> > >, Optional<Attribute<QString, Name::Strict<730> > >, Optional<Attribute<Domain::Xml::PPasswdValidTo, Name::Strict<731> > >, Optional<Attribute<Domain::Xml::EConnected1, Name::Strict<732> > >, Optional<Attribute<Domain::Xml::EDefaultMode, Name::Strict<740> > >, Unordered<mpl::vector<ZeroOrMore<Element<Domain::Xml::VListenImpl, Name::Strict<721> > >, ZeroOrMore<Element<Domain::Xml::Channel, Name::Strict<744> > >, Optional<Element<Attribute<Domain::Xml::ECompression, Name::Strict<753> >, Name::Strict<752> > >, Optional<Element<Attribute<Domain::Xml::ECompression1, Name::Strict<753> >, Name::Strict<759> > >, Optional<Element<Attribute<Domain::Xml::ECompression2, Name::Strict<753> >, Name::Strict<762> > >, Optional<Element<Attribute<Domain::Xml::EVirOnOff, Name::Strict<753> >, Name::Strict<748> > >, Optional<Element<Attribute<Domain::Xml::EMode11, Name::Strict<379> >, Name::Strict<763> > >, Optional<Element<Attribute<Domain::Xml::EVirYesNo, Name::Strict<767> >, Name::Strict<766> > >, Optional<Element<Attribute<Domain::Xml::EMode12, Name::Strict<379> >, Name::Strict<768> > >, Optional<Element<Attribute<Domain::Xml::EVirYesNo, Name::Strict<281> >, Name::Strict<769> > >, Optional<Element<Domain::Xml::Gl, Name::Strict<9188> > > > > > > marshal_type;

	static int parse(Domain::Xml::Graphics7040& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Graphics7040& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7041 traits

template<>
struct Traits<Domain::Xml::Graphics7041>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<771>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::PPortNumber, Name::Strict<212> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<719> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<772> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<773> > >, Optional<Attribute<Domain::Xml::PAddrIPorName, Name::Strict<721> > >, ZeroOrMore<Element<Domain::Xml::VListenImpl, Name::Strict<721> > > > > marshal_type;

	static int parse(Domain::Xml::Graphics7041& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Graphics7041& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7042 traits

template<>
struct Traits<Domain::Xml::Graphics7042>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<775>, Name::Strict<105> >, Optional<Attribute<QString, Name::Strict<714> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<716> > > > > marshal_type;

	static int parse(Domain::Xml::Graphics7042& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Graphics7042& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Gl1 traits

template<>
struct Traits<Domain::Xml::Gl1>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<8678> > > > > marshal_type;

	static int parse(Domain::Xml::Gl1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Gl1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Driver4 traits

template<>
struct Traits<Domain::Xml::Driver4>
{
	typedef Ordered<mpl::vector<Optional<Fragment<Domain::Xml::VirtioOptions > >, Optional<Attribute<Domain::Xml::EName9, Name::Strict<107> > >, Optional<Attribute<Domain::Xml::EVgaconf, Name::Strict<8672> > > > > marshal_type;

	static int parse(Domain::Xml::Driver4& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Driver4& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Model7046 traits

template<>
struct Traits<Domain::Xml::Model7046>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<784>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<639> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<8676> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<8677> > > > > marshal_type;

	static int parse(Domain::Xml::Model7046& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Model7046& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Acceleration traits

template<>
struct Traits<Domain::Xml::Acceleration>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<789> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<790> > >, Optional<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<8678> > > > > marshal_type;

	static int parse(Domain::Xml::Acceleration& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Acceleration& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Resolution traits

template<>
struct Traits<Domain::Xml::Resolution>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<8680> >, Attribute<Domain::Xml::PUnsignedInt, Name::Strict<8681> > > > marshal_type;

	static int parse(Domain::Xml::Resolution& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Resolution& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Model1 traits

template<>
struct Traits<Domain::Xml::Model1>
{
	typedef Ordered<mpl::vector<Domain::Xml::VModelImpl, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<786> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<539> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<787> > >, Optional<Element<Domain::Xml::Acceleration, Name::Strict<788> > >, Optional<Element<Domain::Xml::Resolution, Name::Strict<8679> > > > > marshal_type;

	static int parse(Domain::Xml::Model1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Model1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Video traits

template<>
struct Traits<Domain::Xml::Video>
{
	typedef Unordered<mpl::vector<Optional<Element<Domain::Xml::Driver4, Name::Strict<546> > >, Optional<Element<Domain::Xml::Model1, Name::Strict<231> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > > > > marshal_type;

	static int parse(Domain::Xml::Video& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Video& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source15 traits

template<>
struct Traits<Domain::Xml::Source15>
{
	typedef Ordered<mpl::vector<Optional<Attribute<QString, Name::Strict<379> > >, Optional<Attribute<QString, Name::Strict<355> > >, Optional<Attribute<QString, Name::Strict<513> > >, Optional<Attribute<QString, Name::Strict<856> > >, Optional<Attribute<QString, Name::Strict<857> > >, Optional<Attribute<QString, Name::Strict<744> > >, Optional<Attribute<QString, Name::Strict<858> > >, Optional<Attribute<QString, Name::Strict<859> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<860> > >, Optional<Element<Domain::Xml::Seclabel, Name::Strict<229> > > > > marshal_type;

	static int parse(Domain::Xml::Source15& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source15& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Protocol traits

template<>
struct Traits<Domain::Xml::Protocol>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EType16, Name::Strict<105> > > > > marshal_type;

	static int parse(Domain::Xml::Protocol& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Protocol& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Log traits

template<>
struct Traits<Domain::Xml::Log>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<500> >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<860> > > > > marshal_type;

	static int parse(Domain::Xml::Log& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Log& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct QemucdevSrcDef traits

template<>
struct Traits<Domain::Xml::QemucdevSrcDef>
{
	typedef Ordered<mpl::vector<ZeroOrMore<Element<Domain::Xml::Source15, Name::Strict<501> > >, Optional<Element<Domain::Xml::Protocol, Name::Strict<203> > >, Optional<Element<Domain::Xml::Log, Name::Strict<864> > > > > marshal_type;

	static int parse(Domain::Xml::QemucdevSrcDef& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::QemucdevSrcDef& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Target4 traits

template<>
struct Traits<Domain::Xml::Target4>
{
	typedef Unordered<mpl::vector<Domain::Xml::VChoice8004Impl, Optional<Attribute<QString, Name::Strict<212> > >, Optional<Element<Attribute<Domain::Xml::EName10, Name::Strict<107> >, Name::Strict<231> > > > > marshal_type;

	static int parse(Domain::Xml::Target4& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Target4& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Qemucdev traits

template<>
struct Traits<Domain::Xml::Qemucdev>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EQemucdevSrcTypeChoice, Name::Strict<105> >, Optional<Attribute<Domain::Xml::PAbsFilePath, Name::Strict<811> > >, Fragment<Domain::Xml::QemucdevSrcDef >, Optional<Element<Domain::Xml::Target4, Name::Strict<323> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > > > > marshal_type;

	static int parse(Domain::Xml::Qemucdev& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Qemucdev& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Target5 traits

template<>
struct Traits<Domain::Xml::Target5>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<891>, Name::Strict<105> >, Attribute<QString, Name::Strict<111> >, Attribute<QString, Name::Strict<212> > > > marshal_type;

	static int parse(Domain::Xml::Target5& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Target5& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Target6 traits

template<>
struct Traits<Domain::Xml::Target6>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<530>, Name::Strict<105> >, Optional<Attribute<QString, Name::Strict<107> > >, Optional<Attribute<Domain::Xml::EState1, Name::Strict<126> > > > > marshal_type;

	static int parse(Domain::Xml::Target6& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Target6& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Channel1 traits

template<>
struct Traits<Domain::Xml::Channel1>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EQemucdevSrcTypeChoice, Name::Strict<105> >, Unordered<mpl::vector<Fragment<Domain::Xml::QemucdevSrcDef >, Domain::Xml::VChoice9400Impl, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > > > > > > marshal_type;

	static int parse(Domain::Xml::Channel1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Channel1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Smartcard7059 traits

template<>
struct Traits<Domain::Xml::Smartcard7059>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<513>, Name::Strict<379> > > > marshal_type;

	static int parse(Domain::Xml::Smartcard7059& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Smartcard7059& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Smartcard7060 traits

template<>
struct Traits<Domain::Xml::Smartcard7060>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<897>, Name::Strict<379> >, Element<Text<QString >, Name::Strict<898> >, Element<Text<QString >, Name::Strict<898> >, Element<Text<QString >, Name::Strict<898> >, Optional<Element<Text<Domain::Xml::PAbsDirPath >, Name::Strict<899> > > > > marshal_type;

	static int parse(Domain::Xml::Smartcard7060& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Smartcard7060& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Smartcard7061 traits

template<>
struct Traits<Domain::Xml::Smartcard7061>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<644>, Name::Strict<379> >, Attribute<Domain::Xml::EQemucdevSrcTypeChoice, Name::Strict<105> >, Unordered<mpl::vector<Fragment<Domain::Xml::QemucdevSrcDef >, Optional<Element<Domain::Xml::Target4, Name::Strict<323> > > > > > > marshal_type;

	static int parse(Domain::Xml::Smartcard7061& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Smartcard7061& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Smartcard traits

template<>
struct Traits<Domain::Xml::Smartcard>
{
	typedef Ordered<mpl::vector<Domain::Xml::VSmartcardImpl, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > > > > marshal_type;

	static int parse(Domain::Xml::Smartcard& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Smartcard& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Hub traits

template<>
struct Traits<Domain::Xml::Hub>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<531>, Name::Strict<105> >, Unordered<mpl::vector<Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > > > > > > marshal_type;

	static int parse(Domain::Xml::Hub& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Hub& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Redirdev traits

template<>
struct Traits<Domain::Xml::Redirdev>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<531>, Name::Strict<29> >, Attribute<Domain::Xml::EQemucdevSrcTypeChoice, Name::Strict<105> >, Unordered<mpl::vector<Fragment<Domain::Xml::QemucdevSrcDef >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Domain::Xml::Boot, Name::Strict<407> > > > > > > marshal_type;

	static int parse(Domain::Xml::Redirdev& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Redirdev& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Usbdev traits

template<>
struct Traits<Domain::Xml::Usbdev>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EVirYesNo, Name::Strict<841> >, Optional<Attribute<Domain::Xml::VClass, Name::Strict<842> > >, Optional<Attribute<Domain::Xml::VVendor, Name::Strict<459> > >, Optional<Attribute<Domain::Xml::VProduct, Name::Strict<460> > >, Optional<Attribute<Domain::Xml::VVersion, Name::Strict<852> > > > > marshal_type;

	static int parse(Domain::Xml::Usbdev& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Usbdev& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Backend4752 traits

template<>
struct Traits<Domain::Xml::Backend4752>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<1074>, Name::Strict<231> >, Text<Domain::Xml::PAbsFilePath > > > marshal_type;

	static int parse(Domain::Xml::Backend4752& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Backend4752& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Backend4753 traits

template<>
struct Traits<Domain::Xml::Backend4753>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<1079>, Name::Strict<231> >, Attribute<Domain::Xml::EQemucdevSrcTypeChoice, Name::Strict<105> >, Fragment<Domain::Xml::QemucdevSrcDef > > > marshal_type;

	static int parse(Domain::Xml::Backend4753& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Backend4753& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Backend4754 traits

template<>
struct Traits<Domain::Xml::Backend4754>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<9190>, Name::Strict<231> > > > marshal_type;

	static int parse(Domain::Xml::Backend4754& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Backend4754& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Rate traits

template<>
struct Traits<Domain::Xml::Rate>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<1082> >, Optional<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<370> > > > > marshal_type;

	static int parse(Domain::Xml::Rate& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Rate& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Rng traits

template<>
struct Traits<Domain::Xml::Rng>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EModel9, Name::Strict<231> >, Unordered<mpl::vector<Element<Domain::Xml::VBackendImpl, Name::Strict<693> >, Optional<Element<Domain::Xml::VirtioOptions, Name::Strict<546> > >, Optional<Element<Domain::Xml::Rate, Name::Strict<1081> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > > > > > > marshal_type;

	static int parse(Domain::Xml::Rng& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Rng& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Device1 traits

template<>
struct Traits<Domain::Xml::Device1>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::PFilePath, Name::Strict<355> > > > > marshal_type;

	static int parse(Domain::Xml::Device1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Device1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Backend7062 traits

template<>
struct Traits<Domain::Xml::Backend7062>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<710>, Name::Strict<105> > > > marshal_type;

	static int parse(Domain::Xml::Backend7062& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Backend7062& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Backend1 traits

template<>
struct Traits<Domain::Xml::Backend1>
{
	typedef Ordered<mpl::vector<Domain::Xml::VBackend1Impl, Optional<Attribute<Domain::Xml::EVersion, Name::Strict<852> > > > > marshal_type;

	static int parse(Domain::Xml::Backend1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Backend1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Tpm traits

template<>
struct Traits<Domain::Xml::Tpm>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EModel10, Name::Strict<231> > >, Element<Domain::Xml::Backend1, Name::Strict<693> >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > > > > marshal_type;

	static int parse(Domain::Xml::Tpm& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Tpm& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source16 traits

template<>
struct Traits<Domain::Xml::Source16>
{
	typedef Ordered<mpl::vector<Unordered<mpl::vector<Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<1070> > >, Optional<Element<Text<Domain::Xml::PCpuset >, Name::Strict<1071> > > > > > > marshal_type;

	static int parse(Domain::Xml::Source16& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Source16& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Target7 traits

template<>
struct Traits<Domain::Xml::Target7>
{
	typedef Unordered<mpl::vector<Element<Domain::Xml::ScaledInteger, Name::Strict<334> >, Optional<Element<Text<Domain::Xml::PUnsignedInt >, Name::Strict<609> > >, Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<502> > >, Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<9426> > >, Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<341> > >, Optional<Element<Element<Domain::Xml::ScaledInteger, Name::Strict<334> >, Name::Strict<234> > >, Optional<Element<Empty, Name::Strict<274> > > > > marshal_type;

	static int parse(Domain::Xml::Target7& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Target7& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Memory2 traits

template<>
struct Traits<Domain::Xml::Memory2>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EModel11, Name::Strict<231> >, Optional<Attribute<Domain::Xml::EAccess, Name::Strict<5790> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<428> > >, Unordered<mpl::vector<Optional<Element<Text<Domain::Xml::VUUID >, Name::Strict<151> > >, Optional<Element<Domain::Xml::Source16, Name::Strict<501> > >, Element<Domain::Xml::Target7, Name::Strict<323> >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > > > > > > marshal_type;

	static int parse(Domain::Xml::Memory2& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Memory2& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Watchdog traits

template<>
struct Traits<Domain::Xml::Watchdog>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EModel12, Name::Strict<231> >, Optional<Attribute<Domain::Xml::EAction, Name::Strict<883> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > > > > marshal_type;

	static int parse(Domain::Xml::Watchdog& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Watchdog& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Memballoon traits

template<>
struct Traits<Domain::Xml::Memballoon>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EModel13, Name::Strict<231> >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<887> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<9398> > >, Unordered<mpl::vector<Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Attribute<Domain::Xml::PPositiveInteger, Name::Strict<370> >, Name::Strict<888> > >, Optional<Element<Domain::Xml::VirtioOptions, Name::Strict<546> > > > > > > marshal_type;

	static int parse(Domain::Xml::Memballoon& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Memballoon& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Nvram1 traits

template<>
struct Traits<Domain::Xml::Nvram1>
{
	typedef Ordered<mpl::vector<Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > > > > marshal_type;

	static int parse(Domain::Xml::Nvram1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Nvram1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Panic traits

template<>
struct Traits<Domain::Xml::Panic>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EModel14, Name::Strict<231> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > > > > marshal_type;

	static int parse(Domain::Xml::Panic& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Panic& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Address1 traits

template<>
struct Traits<Domain::Xml::Address1>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<689>, Name::Strict<105> >, Attribute<Domain::Xml::PAddrIPorName, Name::Strict<513> >, Optional<Attribute<Domain::Xml::PPortNumber, Name::Strict<212> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<719> > >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<863> > > > > marshal_type;

	static int parse(Domain::Xml::Address1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Address1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Disk1 traits

template<>
struct Traits<Domain::Xml::Disk1>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::VName1, Name::Strict<107> >, Optional<Attribute<QString, Name::Strict<1179> > >, Optional<Attribute<QString, Name::Strict<462> > >, Optional<Domain::Xml::VChoice7113Impl >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<274> > > > > marshal_type;

	static int parse(Domain::Xml::Disk1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Disk1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Domainblockexport_ traits

template<>
struct Traits<Domain::Xml::Domainblockexport_>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<503>, Name::Strict<105> >, Unordered<mpl::vector<Element<Domain::Xml::Address1, Name::Strict<111> >, OneOrMore<Element<Domain::Xml::Disk1, Name::Strict<472> > > > > > > marshal_type;

	static int parse(Domain::Xml::Domainblockexport_& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Domainblockexport_& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Driver5 traits

template<>
struct Traits<Domain::Xml::Driver5>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<5084> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<5085> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<5086> > >, Optional<Attribute<Domain::Xml::EVirOnOff, Name::Strict<5087> > >, Optional<Attribute<Domain::Xml::VUint8, Name::Strict<9402> > > > > marshal_type;

	static int parse(Domain::Xml::Driver5& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Driver5& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Cid traits

template<>
struct Traits<Domain::Xml::Cid>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<340> > >, Optional<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<111> > > > > marshal_type;

	static int parse(Domain::Xml::Cid& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Cid& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Vsock traits

template<>
struct Traits<Domain::Xml::Vsock>
{
	typedef Ordered<mpl::vector<Optional<Attribute<mpl::int_<530>, Name::Strict<231> > >, Unordered<mpl::vector<Optional<Element<Domain::Xml::Cid, Name::Strict<5043> > >, Optional<Element<Domain::Xml::VAddressImpl, Name::Strict<111> > >, Optional<Element<Attribute<Domain::Xml::PAliasName, Name::Strict<107> >, Name::Strict<456> > >, Optional<Element<Domain::Xml::Acpi, Name::Strict<993> > >, Optional<Element<Domain::Xml::VirtioOptions, Name::Strict<546> > > > > > > marshal_type;

	static int parse(Domain::Xml::Vsock& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Vsock& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Devices traits

template<>
struct Traits<Domain::Xml::Devices>
{
	typedef Unordered<mpl::vector<Optional<Element<Text<Domain::Xml::PAbsFilePath >, Name::Strict<710> > >, ZeroOrMore<Domain::Xml::VChoice7097Impl >, Optional<Element<Domain::Xml::Watchdog, Name::Strict<880> > >, Optional<Element<Domain::Xml::Memballoon, Name::Strict<886> > >, Optional<Element<Domain::Xml::Nvram1, Name::Strict<277> > >, ZeroOrMore<Element<Domain::Xml::Panic, Name::Strict<987> > >, Optional<Element<Domain::Xml::Domainblockexport_, Name::Strict<988> > >, Optional<Element<Ordered<mpl::vector<Attribute<mpl::int_<5083>, Name::Strict<231> >, Optional<Element<Domain::Xml::Driver5, Name::Strict<546> > > > >, Name::Strict<5082> > >, Optional<Element<Domain::Xml::Vsock, Name::Strict<5042> > > > > marshal_type;

	static int parse(Domain::Xml::Devices& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Devices& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6970 traits

template<>
struct Traits<Domain::Xml::Seclabel6970>
{
	typedef Ordered<mpl::vector<Optional<Attribute<mpl::int_<232>, Name::Strict<105> > >, Optional<Attribute<mpl::int_<135>, Name::Strict<233> > >, Unordered<mpl::vector<Optional<Element<Text<QString >, Name::Strict<234> > >, Optional<Element<Text<QString >, Name::Strict<235> > >, Optional<Element<Text<QString >, Name::Strict<236> > > > > > > marshal_type;

	static int parse(Domain::Xml::Seclabel6970& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Seclabel6970& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6971 traits

template<>
struct Traits<Domain::Xml::Seclabel6971>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<238>, Name::Strict<105> >, Optional<Attribute<Domain::Xml::EVirYesNo, Name::Strict<233> > >, Unordered<mpl::vector<Element<Text<QString >, Name::Strict<234> >, Optional<Element<Text<QString >, Name::Strict<235> > > > > > > marshal_type;

	static int parse(Domain::Xml::Seclabel6971& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Seclabel6971& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6972 traits

template<>
struct Traits<Domain::Xml::Seclabel6972>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<240>, Name::Strict<105> >, Optional<Attribute<mpl::int_<136>, Name::Strict<233> > > > > marshal_type;

	static int parse(Domain::Xml::Seclabel6972& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Seclabel6972& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel1 traits

template<>
struct Traits<Domain::Xml::Seclabel1>
{
	typedef Ordered<mpl::vector<Optional<Attribute<QString, Name::Strict<231> > >, Domain::Xml::VSeclabel1Impl > > marshal_type;

	static int parse(Domain::Xml::Seclabel1& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Seclabel1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Env traits

template<>
struct Traits<Domain::Xml::Env>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::PFilterParamName, Name::Strict<107> >, Optional<Attribute<QString, Name::Strict<1086> > > > > marshal_type;

	static int parse(Domain::Xml::Env& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Env& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Commandline traits

template<>
struct Traits<Domain::Xml::Commandline>
{
	typedef Ordered<mpl::vector<ZeroOrMore<Element<Attribute<QString, Name::Strict<1086> >, Name::Strict<1160> > >, ZeroOrMore<Element<Domain::Xml::Env, Name::Strict<1161> > > > > marshal_type;

	static int parse(Domain::Xml::Commandline& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Commandline& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Cipher traits

template<>
struct Traits<Domain::Xml::Cipher>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EName11, Name::Strict<107> >, Attribute<Domain::Xml::EVirOnOff, Name::Strict<126> > > > marshal_type;

	static int parse(Domain::Xml::Cipher& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Cipher& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct LaunchSecurity traits

template<>
struct Traits<Domain::Xml::LaunchSecurity>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<3562>, Name::Strict<105> >, Unordered<mpl::vector<Optional<Element<Text<Domain::Xml::PCbitpos >, Name::Strict<3564> > >, Optional<Element<Text<Domain::Xml::PReducedPhysBits >, Name::Strict<3565> > >, Element<Text<Domain::Xml::PHexuint >, Name::Strict<1023> >, Optional<Element<Text<Domain::Xml::PUnsignedInt >, Name::Strict<649> > >, Optional<Element<Text<Domain::Xml::PDhCert >, Name::Strict<5052> > >, Optional<Element<Text<Domain::Xml::PSession >, Name::Strict<5053> > > > > > > marshal_type;

	static int parse(Domain::Xml::LaunchSecurity& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::LaunchSecurity& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Domain traits

template<>
struct Traits<Domain::Xml::Domain>
{
	typedef Ordered<mpl::vector<Attribute<Domain::Xml::EType, Name::Strict<105> >, Unordered<mpl::vector<Fragment<Domain::Xml::Ids >, Optional<Element<Text<Domain::Xml::PObjectNameWithSlash >, Name::Strict<217> > >, Optional<Element<Text<QString >, Name::Strict<216> > >, Optional<Element<ZeroOrMore<Pod >, Name::Strict<139> > >, Optional<Element<Domain::Xml::Cpu, Name::Strict<220> > >, ZeroOrMore<Element<Domain::Xml::Sysinfo, Name::Strict<221> > >, Domain::Xml::VOsImpl, Optional<Element<Domain::Xml::Clock, Name::Strict<223> > >, Optional<Element<Domain::Xml::Memory, Name::Strict<326> > >, Optional<Element<Domain::Xml::MaxMemory, Name::Strict<328> > >, Optional<Element<Domain::Xml::ScaledInteger, Name::Strict<330> > >, Optional<Element<Domain::Xml::MemoryBacking, Name::Strict<331> > >, Optional<Element<Domain::Xml::Vcpu, Name::Strict<338> > >, Optional<Element<ZeroOrMore<Element<Domain::Xml::Vcpu1, Name::Strict<338> > >, Name::Strict<343> > >, Optional<Element<Text<Domain::Xml::PUnsignedInt >, Name::Strict<347> > >, Optional<Element<ZeroOrMore<Element<Attribute<Domain::Xml::PUnsignedInt, Name::Strict<208> >, Name::Strict<378> > >, Name::Strict<5077> > >, Optional<Element<Domain::Xml::Blkiotune, Name::Strict<348> > >, Optional<Element<Domain::Xml::Memtune, Name::Strict<349> > >, Optional<Element<Domain::Xml::Cputune, Name::Strict<350> > >, Optional<Element<Domain::Xml::Numatune, Name::Strict<351> > >, Optional<Element<Domain::Xml::Resource, Name::Strict<387> > >, Optional<Element<Domain::Xml::Features, Name::Strict<155> > >, Optional<Element<Text<Domain::Xml::EOffOptions >, Name::Strict<791> > >, Optional<Element<Text<Domain::Xml::EOffOptions >, Name::Strict<793> > >, Optional<Element<Text<Domain::Xml::ECrashOptions >, Name::Strict<794> > >, Optional<Element<Text<Domain::Xml::ELockfailureOptions >, Name::Strict<796> > >, Optional<Element<Domain::Xml::VzDns, Name::Strict<5706> > >, Optional<Element<Domain::Xml::VzNetworkRates, Name::Strict<9001> > >, Optional<Element<Domain::Xml::Pm, Name::Strict<226> > >, Optional<Element<OneOrMore<Element<Domain::Xml::Event, Name::Strict<5054> > >, Name::Strict<5045> > >, Optional<Element<Domain::Xml::Idmap, Name::Strict<227> > >, Optional<Element<Domain::Xml::Devices, Name::Strict<228> > >, ZeroOrMore<Element<Domain::Xml::Seclabel1, Name::Strict<229> > >, Optional<Element<Domain::Xml::Commandline, Name::Scoped<1159, 1162> > >, Optional<Element<OneOrMore<Element<Domain::Xml::Cipher, Name::Strict<5049> > >, Name::Strict<5046> > >, Optional<Element<Domain::Xml::LaunchSecurity, Name::Strict<5047> > > > > > > marshal_type;

	static int parse(Domain::Xml::Domain& , QStack<QDomElement>& );
	static int generate(const Domain::Xml::Domain& , QDomElement& );
};

} // namespace Libvirt

#endif // __DOMAIN_TYPE_H__
