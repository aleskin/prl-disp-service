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

#include "domain_type.h"

namespace Libvirt
{
///////////////////////////////////////////////////////////////////////////////
// struct Ids

namespace Domain
{
namespace Xml
{
bool Ids::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Ids>::parse(*this, k);
}

bool Ids::save(QDomElement& dst_) const
{
	return 0 <= Traits<Ids>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Ids>::parse(Domain::Xml::Ids& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setId(m.get<0>().getValue());
		dst_.setName(m.get<1>().get<0>().getValue());
		dst_.setUuid(m.get<1>().get<1>().getValue());
		dst_.setGenid(m.get<1>().get<2>().getValue());
		dst_.setExtraId(m.get<1>().get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Ids>::generate(const Domain::Xml::Ids& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getId(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getUuid(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGenid(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getExtraId(), m.get<1>().get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Model

namespace Domain
{
namespace Xml
{
bool Model::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Model, Name::Strict<231> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Model::save(QDomElement& dst_) const
{
	Element<Model, Name::Strict<231> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Model::save(QDomDocument& dst_) const
{
	Element<Model, Name::Strict<231> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Model>::parse(Domain::Xml::Model& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setFallback(m.get<0>().getValue());
		dst_.setVendorId(m.get<1>().getValue());
		dst_.setOwnValue(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Model>::generate(const Domain::Xml::Model& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getFallback(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVendorId(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOwnValue(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Topology

namespace Domain
{
namespace Xml
{
Topology::Topology(): m_sockets(), m_cores(), m_threads()
{
}

bool Topology::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Topology, Name::Strict<1028> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Topology::save(QDomElement& dst_) const
{
	Element<Topology, Name::Strict<1028> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Topology::save(QDomDocument& dst_) const
{
	Element<Topology, Name::Strict<1028> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Topology>::parse(Domain::Xml::Topology& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSockets(m.get<0>().getValue());
		dst_.setDies(m.get<1>().getValue());
		dst_.setCores(m.get<2>().getValue());
		dst_.setThreads(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Topology>::generate(const Domain::Xml::Topology& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSockets(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDies(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCores(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getThreads(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Feature

namespace Domain
{
namespace Xml
{
Feature::Feature(): m_policy()
{
}

bool Feature::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Feature, Name::Strict<1022> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Feature::save(QDomElement& dst_) const
{
	Element<Feature, Name::Strict<1022> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Feature::save(QDomDocument& dst_) const
{
	Element<Feature, Name::Strict<1022> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Feature>::parse(Domain::Xml::Feature& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setPolicy(m.get<0>().getValue());
		dst_.setName(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Feature>::generate(const Domain::Xml::Feature& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getPolicy(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Sibling

namespace Domain
{
namespace Xml
{
Sibling::Sibling(): m_id(), m_value()
{
}

bool Sibling::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Sibling, Name::Strict<5785> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Sibling::save(QDomElement& dst_) const
{
	Element<Sibling, Name::Strict<5785> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Sibling::save(QDomDocument& dst_) const
{
	Element<Sibling, Name::Strict<5785> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Sibling>::parse(Domain::Xml::Sibling& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setId(m.get<0>().getValue());
		dst_.setValue(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Sibling>::generate(const Domain::Xml::Sibling& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getId(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getValue(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Size

namespace Domain
{
namespace Xml
{
Size::Size(): m_value()
{
}

bool Size::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Size, Name::Strict<334> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Size::save(QDomElement& dst_) const
{
	Element<Size, Name::Strict<334> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Size::save(QDomDocument& dst_) const
{
	Element<Size, Name::Strict<334> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Size>::parse(Domain::Xml::Size& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setValue(m.get<0>().getValue());
		dst_.setUnit(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Size>::generate(const Domain::Xml::Size& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getValue(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getUnit(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Line

namespace Domain
{
namespace Xml
{
Line::Line(): m_value()
{
}

bool Line::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Line, Name::Strict<5787> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Line::save(QDomElement& dst_) const
{
	Element<Line, Name::Strict<5787> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Line::save(QDomDocument& dst_) const
{
	Element<Line, Name::Strict<5787> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Line>::parse(Domain::Xml::Line& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setValue(m.get<0>().getValue());
		dst_.setUnit(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Line>::generate(const Domain::Xml::Line& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getValue(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getUnit(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Cache

namespace Domain
{
namespace Xml
{
Cache::Cache(): m_level(), m_associativity(), m_policy()
{
}

bool Cache::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Cache, Name::Strict<558> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Cache::save(QDomElement& dst_) const
{
	Element<Cache, Name::Strict<558> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Cache::save(QDomDocument& dst_) const
{
	Element<Cache, Name::Strict<558> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Cache>::parse(Domain::Xml::Cache& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setLevel(m.get<0>().getValue());
		dst_.setAssociativity(m.get<1>().getValue());
		dst_.setPolicy(m.get<2>().getValue());
		dst_.setSize(m.get<3>().get<0>().getValue());
		dst_.setLine(m.get<3>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Cache>::generate(const Domain::Xml::Cache& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getLevel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAssociativity(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPolicy(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSize(), m.get<3>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLine(), m.get<3>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Cell

namespace Domain
{
namespace Xml
{
Cell::Cell(): m_memory()
{
}

bool Cell::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Cell, Name::Strict<1033> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Cell::save(QDomElement& dst_) const
{
	Element<Cell, Name::Strict<1033> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Cell::save(QDomDocument& dst_) const
{
	Element<Cell, Name::Strict<1033> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Cell>::parse(Domain::Xml::Cell& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setId(m.get<0>().getValue());
		dst_.setCpus(m.get<1>().getValue());
		dst_.setMemory(m.get<2>().getValue());
		dst_.setUnit(m.get<3>().getValue());
		dst_.setMemAccess(m.get<4>().getValue());
		dst_.setDiscard(m.get<5>().getValue());
		dst_.setDistances(m.get<6>().get<0>().getValue());
		dst_.setCacheList(m.get<6>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Cell>::generate(const Domain::Xml::Cell& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getId(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCpus(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMemory(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getUnit(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMemAccess(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDiscard(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDistances(), m.get<6>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCacheList(), m.get<6>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Latency

namespace Domain
{
namespace Xml
{
Latency::Latency(): m_initiator(), m_target(), m_type(), m_value()
{
}

bool Latency::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Latency, Name::Strict<5789> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Latency::save(QDomElement& dst_) const
{
	Element<Latency, Name::Strict<5789> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Latency::save(QDomDocument& dst_) const
{
	Element<Latency, Name::Strict<5789> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Latency>::parse(Domain::Xml::Latency& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setInitiator(m.get<0>().getValue());
		dst_.setTarget(m.get<1>().getValue());
		dst_.setCache(m.get<2>().getValue());
		dst_.setType(m.get<3>().getValue());
		dst_.setValue(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Latency>::generate(const Domain::Xml::Latency& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getInitiator(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCache(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getValue(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Bandwidth

namespace Domain
{
namespace Xml
{
Bandwidth::Bandwidth(): m_initiator(), m_target(), m_type(), m_value()
{
}

bool Bandwidth::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Bandwidth, Name::Strict<193> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Bandwidth::save(QDomElement& dst_) const
{
	Element<Bandwidth, Name::Strict<193> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Bandwidth::save(QDomDocument& dst_) const
{
	Element<Bandwidth, Name::Strict<193> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Bandwidth>::parse(Domain::Xml::Bandwidth& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setInitiator(m.get<0>().getValue());
		dst_.setTarget(m.get<1>().getValue());
		dst_.setCache(m.get<2>().getValue());
		dst_.setType(m.get<3>().getValue());
		dst_.setValue(m.get<4>().getValue());
		dst_.setUnit(m.get<5>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Bandwidth>::generate(const Domain::Xml::Bandwidth& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getInitiator(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCache(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getValue(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getUnit(), m.get<5>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Interconnects

namespace Domain
{
namespace Xml
{
bool Interconnects::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Interconnects, Name::Strict<5788> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Interconnects::save(QDomElement& dst_) const
{
	Element<Interconnects, Name::Strict<5788> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Interconnects::save(QDomDocument& dst_) const
{
	Element<Interconnects, Name::Strict<5788> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Interconnects>::parse(Domain::Xml::Interconnects& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setLatencyList(m.get<0>().getValue());
		dst_.setBandwidthList(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Interconnects>::generate(const Domain::Xml::Interconnects& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getLatencyList(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBandwidthList(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Numa

namespace Domain
{
namespace Xml
{
bool Numa::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Numa, Name::Strict<1031> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Numa::save(QDomElement& dst_) const
{
	Element<Numa, Name::Strict<1031> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Numa::save(QDomDocument& dst_) const
{
	Element<Numa, Name::Strict<1031> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Numa>::parse(Domain::Xml::Numa& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setCellList(m.get<0>().getValue());
		dst_.setInterconnects(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Numa>::generate(const Domain::Xml::Numa& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getCellList(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInterconnects(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Cache1

namespace Domain
{
namespace Xml
{
Cache1::Cache1(): m_mode()
{
}

bool Cache1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Cache1, Name::Strict<558> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Cache1::save(QDomElement& dst_) const
{
	Element<Cache1, Name::Strict<558> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Cache1::save(QDomDocument& dst_) const
{
	Element<Cache1, Name::Strict<558> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Cache1>::parse(Domain::Xml::Cache1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setLevel(m.get<0>().getValue());
		dst_.setMode(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Cache1>::generate(const Domain::Xml::Cache1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getLevel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMode(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Cpu

namespace Domain
{
namespace Xml
{
bool Cpu::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Cpu, Name::Strict<220> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Cpu::save(QDomElement& dst_) const
{
	Element<Cpu, Name::Strict<220> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Cpu::save(QDomDocument& dst_) const
{
	Element<Cpu, Name::Strict<220> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Cpu>::parse(Domain::Xml::Cpu& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setMode(m.get<0>().getValue());
		dst_.setMatch(m.get<1>().getValue());
		dst_.setCheck(m.get<2>().getValue());
		dst_.setMigratable(m.get<3>().getValue());
		dst_.setModel(m.get<4>().get<0>().getValue());
		dst_.setVendor(m.get<4>().get<1>().getValue());
		dst_.setTopology(m.get<4>().get<2>().getValue());
		dst_.setFeatureList(m.get<4>().get<3>().getValue());
		dst_.setNuma(m.get<4>().get<4>().getValue());
		dst_.setCache(m.get<4>().get<5>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Cpu>::generate(const Domain::Xml::Cpu& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getMode(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMatch(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCheck(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMigratable(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<4>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVendor(), m.get<4>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTopology(), m.get<4>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFeatureList(), m.get<4>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNuma(), m.get<4>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCache(), m.get<4>().get<5>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Entry

namespace Domain
{
namespace Xml
{
Entry::Entry(): m_name()
{
}

bool Entry::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Entry, Name::Strict<1039> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Entry::save(QDomElement& dst_) const
{
	Element<Entry, Name::Strict<1039> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Entry::save(QDomDocument& dst_) const
{
	Element<Entry, Name::Strict<1039> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Entry>::parse(Domain::Xml::Entry& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setOwnValue(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Entry>::generate(const Domain::Xml::Entry& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOwnValue(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Entry1

namespace Domain
{
namespace Xml
{
Entry1::Entry1(): m_name()
{
}

bool Entry1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Entry1, Name::Strict<1039> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Entry1::save(QDomElement& dst_) const
{
	Element<Entry1, Name::Strict<1039> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Entry1::save(QDomDocument& dst_) const
{
	Element<Entry1, Name::Strict<1039> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Entry1>::parse(Domain::Xml::Entry1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setOwnValue(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Entry1>::generate(const Domain::Xml::Entry1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOwnValue(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Entry2

namespace Domain
{
namespace Xml
{
Entry2::Entry2(): m_name()
{
}

bool Entry2::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Entry2, Name::Strict<1039> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Entry2::save(QDomElement& dst_) const
{
	Element<Entry2, Name::Strict<1039> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Entry2::save(QDomDocument& dst_) const
{
	Element<Entry2, Name::Strict<1039> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Entry2>::parse(Domain::Xml::Entry2& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setOwnValue(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Entry2>::generate(const Domain::Xml::Entry2& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOwnValue(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Entry3

namespace Domain
{
namespace Xml
{
Entry3::Entry3(): m_name()
{
}

bool Entry3::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Entry3, Name::Strict<1039> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Entry3::save(QDomElement& dst_) const
{
	Element<Entry3, Name::Strict<1039> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Entry3::save(QDomDocument& dst_) const
{
	Element<Entry3, Name::Strict<1039> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Entry3>::parse(Domain::Xml::Entry3& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setOwnValue(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Entry3>::generate(const Domain::Xml::Entry3& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOwnValue(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Sysinfo

namespace Domain
{
namespace Xml
{
bool Sysinfo::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Sysinfo, Name::Strict<221> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Sysinfo::save(QDomElement& dst_) const
{
	Element<Sysinfo, Name::Strict<221> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Sysinfo::save(QDomDocument& dst_) const
{
	Element<Sysinfo, Name::Strict<221> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Sysinfo>::parse(Domain::Xml::Sysinfo& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setBios(m.get<1>().get<0>().getValue());
		dst_.setSystem(m.get<1>().get<1>().getValue());
		dst_.setBaseBoardList(m.get<1>().get<2>().getValue());
		dst_.setChassis(m.get<1>().get<3>().getValue());
		dst_.setOemStrings(m.get<1>().get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Sysinfo>::generate(const Domain::Xml::Sysinfo& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getBios(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSystem(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBaseBoardList(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChassis(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOemStrings(), m.get<1>().get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Bootloader

namespace Domain
{
namespace Xml
{
bool Bootloader::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Bootloader>::parse(*this, k);
}

bool Bootloader::save(QDomElement& dst_) const
{
	return 0 <= Traits<Bootloader>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Bootloader>::parse(Domain::Xml::Bootloader& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setBootloader(m.get<0>().getValue());
		dst_.setBootloaderArgs(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Bootloader>::generate(const Domain::Xml::Bootloader& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getBootloader(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBootloaderArgs(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Type

namespace Domain
{
namespace Xml
{
Type::Type(): m_type()
{
}

bool Type::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Type, Name::Strict<105> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Type::save(QDomElement& dst_) const
{
	Element<Type, Name::Strict<105> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Type::save(QDomDocument& dst_) const
{
	Element<Type, Name::Strict<105> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Type>::parse(Domain::Xml::Type& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setArch(m.get<0>().getValue());
		dst_.setMachine(m.get<1>().getValue());
		dst_.setType(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Type>::generate(const Domain::Xml::Type& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getArch(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMachine(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Osbootkernel

namespace Domain
{
namespace Xml
{
bool Osbootkernel::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Osbootkernel>::parse(*this, k);
}

bool Osbootkernel::save(QDomElement& dst_) const
{
	return 0 <= Traits<Osbootkernel>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Osbootkernel>::parse(Domain::Xml::Osbootkernel& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setKernel(m.get<0>().getValue());
		dst_.setInitrd(m.get<1>().getValue());
		dst_.setRoot(m.get<2>().getValue());
		dst_.setCmdline(m.get<3>().getValue());
		dst_.setDtb(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Osbootkernel>::generate(const Domain::Xml::Osbootkernel& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getKernel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInitrd(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRoot(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCmdline(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDtb(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Os

namespace Domain
{
namespace Xml
{
bool Os::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Os, Name::Strict<222> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Os::save(QDomElement& dst_) const
{
	Element<Os, Name::Strict<222> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Os::save(QDomDocument& dst_) const
{
	Element<Os, Name::Strict<222> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Os>::parse(Domain::Xml::Os& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
		dst_.setOsbootkernel(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Os>::generate(const Domain::Xml::Os& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOsbootkernel(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Osxen6979

int Traits<Domain::Xml::Osxen6979>::parse(Domain::Xml::Osxen6979& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setBootloader(m.get<0>().getValue());
		dst_.setOs(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Osxen6979>::generate(const Domain::Xml::Osxen6979& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getBootloader(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOs(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Os1

namespace Domain
{
namespace Xml
{
bool Os1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Os1, Name::Strict<222> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Os1::save(QDomElement& dst_) const
{
	Element<Os1, Name::Strict<222> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Os1::save(QDomDocument& dst_) const
{
	Element<Os1, Name::Strict<222> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Os1>::parse(Domain::Xml::Os1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
		dst_.setOsbootkernel(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Os1>::generate(const Domain::Xml::Os1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOsbootkernel(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Osxen6980

int Traits<Domain::Xml::Osxen6980>::parse(Domain::Xml::Osxen6980& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setBootloader(m.get<0>().getValue());
		dst_.setOs(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Osxen6980>::generate(const Domain::Xml::Osxen6980& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getBootloader(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOs(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hvmx86

int Traits<Domain::Xml::Hvmx86>::parse(Domain::Xml::Hvmx86& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setArch(m.get<0>().getValue());
		dst_.setMachine(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hvmx86>::generate(const Domain::Xml::Hvmx86& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getArch(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMachine(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hvmmips

int Traits<Domain::Xml::Hvmmips>::parse(Domain::Xml::Hvmmips& , QStack<QDomElement>& stack_)
{
	marshal_type m;
	return m.consume(stack_);
}

int Traits<Domain::Xml::Hvmmips>::generate(const Domain::Xml::Hvmmips& , QDomElement& dst_)
{
	marshal_type m;
	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hvmsparc

int Traits<Domain::Xml::Hvmsparc>::parse(Domain::Xml::Hvmsparc& , QStack<QDomElement>& stack_)
{
	marshal_type m;
	return m.consume(stack_);
}

int Traits<Domain::Xml::Hvmsparc>::generate(const Domain::Xml::Hvmsparc& , QDomElement& dst_)
{
	marshal_type m;
	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hvms390

int Traits<Domain::Xml::Hvms390>::parse(Domain::Xml::Hvms390& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setArch(m.get<0>().getValue());
		dst_.setMachine(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hvms390>::generate(const Domain::Xml::Hvms390& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getArch(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMachine(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hvmarm

int Traits<Domain::Xml::Hvmarm>::parse(Domain::Xml::Hvmarm& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setArch(m.get<0>().getValue());
		dst_.setMachine(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hvmarm>::generate(const Domain::Xml::Hvmarm& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getArch(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMachine(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hvmaarch64

int Traits<Domain::Xml::Hvmaarch64>::parse(Domain::Xml::Hvmaarch64& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setArch(m.get<0>().getValue());
		dst_.setMachine(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hvmaarch64>::generate(const Domain::Xml::Hvmaarch64& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getArch(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMachine(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Loader

namespace Domain
{
namespace Xml
{
bool Loader::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Loader, Name::Strict<273> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Loader::save(QDomElement& dst_) const
{
	Element<Loader, Name::Strict<273> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Loader::save(QDomDocument& dst_) const
{
	Element<Loader, Name::Strict<273> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Loader>::parse(Domain::Xml::Loader& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setReadonly(m.get<0>().getValue());
		dst_.setSecure(m.get<1>().getValue());
		dst_.setType(m.get<2>().getValue());
		dst_.setOwnValue(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Loader>::generate(const Domain::Xml::Loader& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getReadonly(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSecure(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOwnValue(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6973

int Traits<Domain::Xml::Seclabel6973>::parse(Domain::Xml::Seclabel6973& , QStack<QDomElement>& stack_)
{
	marshal_type m;
	return m.consume(stack_);
}

int Traits<Domain::Xml::Seclabel6973>::generate(const Domain::Xml::Seclabel6973& , QDomElement& dst_)
{
	marshal_type m;
	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6974

int Traits<Domain::Xml::Seclabel6974>::parse(Domain::Xml::Seclabel6974& , QStack<QDomElement>& stack_)
{
	marshal_type m;
	return m.consume(stack_);
}

int Traits<Domain::Xml::Seclabel6974>::generate(const Domain::Xml::Seclabel6974& , QDomElement& dst_)
{
	marshal_type m;
	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel

namespace Domain
{
namespace Xml
{
bool Seclabel::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Seclabel, Name::Strict<229> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Seclabel::save(QDomElement& dst_) const
{
	Element<Seclabel, Name::Strict<229> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Seclabel::save(QDomDocument& dst_) const
{
	Element<Seclabel, Name::Strict<229> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Seclabel>::parse(Domain::Xml::Seclabel& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<0>().getValue());
		dst_.setSeclabel(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Seclabel>::generate(const Domain::Xml::Seclabel& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSeclabel(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source

namespace Domain
{
namespace Xml
{
bool Source::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source::save(QDomElement& dst_) const
{
	Element<Source, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source::save(QDomDocument& dst_) const
{
	Element<Source, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source>::parse(Domain::Xml::Source& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDev(m.get<0>().getValue());
		dst_.setStartupPolicy(m.get<1>().getValue());
		dst_.setSeclabelList(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source>::generate(const Domain::Xml::Source& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDev(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getStartupPolicy(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSeclabelList(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous7117

namespace Domain
{
namespace Xml
{
bool Anonymous7117::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Anonymous7117>::parse(*this, k);
}

bool Anonymous7117::save(QDomElement& dst_) const
{
	return 0 <= Traits<Anonymous7117>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Anonymous7117>::parse(Domain::Xml::Anonymous7117& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setMode(m.get<0>().getValue());
		dst_.setHash(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Anonymous7117>::generate(const Domain::Xml::Anonymous7117& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getMode(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHash(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Keycipher

namespace Domain
{
namespace Xml
{
Keycipher::Keycipher(): m_size()
{
}

bool Keycipher::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Keycipher, Name::Strict<5049> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Keycipher::save(QDomElement& dst_) const
{
	Element<Keycipher, Name::Strict<5049> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Keycipher::save(QDomDocument& dst_) const
{
	Element<Keycipher, Name::Strict<5049> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Keycipher>::parse(Domain::Xml::Keycipher& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setSize(m.get<1>().getValue());
		dst_.setAnonymous7117(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Keycipher>::generate(const Domain::Xml::Keycipher& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSize(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAnonymous7117(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Keyivgen

namespace Domain
{
namespace Xml
{
bool Keyivgen::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Keyivgen, Name::Strict<5751> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Keyivgen::save(QDomElement& dst_) const
{
	Element<Keyivgen, Name::Strict<5751> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Keyivgen::save(QDomDocument& dst_) const
{
	Element<Keyivgen, Name::Strict<5751> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Keyivgen>::parse(Domain::Xml::Keyivgen& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setHash(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Keyivgen>::generate(const Domain::Xml::Keyivgen& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHash(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous7118

namespace Domain
{
namespace Xml
{
bool Anonymous7118::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Anonymous7118>::parse(*this, k);
}

bool Anonymous7118::save(QDomElement& dst_) const
{
	return 0 <= Traits<Anonymous7118>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Anonymous7118>::parse(Domain::Xml::Anonymous7118& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setCipher(m.get<0>().getValue());
		dst_.setIvgen(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Anonymous7118>::generate(const Domain::Xml::Anonymous7118& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getCipher(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIvgen(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Encryption

namespace Domain
{
namespace Xml
{
Encryption::Encryption(): m_format()
{
}

bool Encryption::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Encryption, Name::Strict<145> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Encryption::save(QDomElement& dst_) const
{
	Element<Encryption, Name::Strict<145> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Encryption::save(QDomDocument& dst_) const
{
	Element<Encryption, Name::Strict<145> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Encryption>::parse(Domain::Xml::Encryption& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setFormat(m.get<0>().getValue());
		dst_.setSecret(m.get<1>().get<0>().getValue());
		dst_.setAnonymous7118(m.get<1>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Encryption>::generate(const Domain::Xml::Encryption& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getFormat(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSecret(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAnonymous7118(), m.get<1>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source1

namespace Domain
{
namespace Xml
{
bool Source1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source1, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source1::save(QDomElement& dst_) const
{
	Element<Source1, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source1::save(QDomDocument& dst_) const
{
	Element<Source1, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source1>::parse(Domain::Xml::Source1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDir(m.get<0>().getValue());
		dst_.setStartupPolicy(m.get<1>().getValue());
		dst_.setEncryption(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source1>::generate(const Domain::Xml::Source1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDir(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getStartupPolicy(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEncryption(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Host7010

int Traits<Domain::Xml::Host7010>::parse(Domain::Xml::Host7010& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setTransport(m.get<0>().getValue());
		dst_.setName(m.get<1>().getValue());
		dst_.setPort(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Host7010>::generate(const Domain::Xml::Host7010& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getTransport(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source2

namespace Domain
{
namespace Xml
{
Source2::Source2(): m_protocol()
{
}

bool Source2::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source2, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source2::save(QDomElement& dst_) const
{
	Element<Source2, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source2::save(QDomDocument& dst_) const
{
	Element<Source2, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source2>::parse(Domain::Xml::Source2& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setProtocol(m.get<0>().getValue());
		dst_.setName(m.get<1>().getValue());
		dst_.setHostList(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source2>::generate(const Domain::Xml::Source2& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getProtocol(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHostList(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source3

namespace Domain
{
namespace Xml
{
bool Source3::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source3, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source3::save(QDomElement& dst_) const
{
	Element<Source3, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source3::save(QDomDocument& dst_) const
{
	Element<Source3, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source3>::parse(Domain::Xml::Source3& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setPool(m.get<0>().getValue());
		dst_.setVolume(m.get<1>().getValue());
		dst_.setMode(m.get<2>().getValue());
		dst_.setStartupPolicy(m.get<3>().getValue());
		dst_.setEncryption(m.get<4>().getValue());
		dst_.setSeclabelList(m.get<5>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source3>::generate(const Domain::Xml::Source3& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getPool(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVolume(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMode(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getStartupPolicy(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEncryption(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSeclabelList(), m.get<5>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source4

namespace Domain
{
namespace Xml
{
bool Source4::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source4, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source4::save(QDomElement& dst_) const
{
	Element<Source4, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source4::save(QDomDocument& dst_) const
{
	Element<Source4, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source4>::parse(Domain::Xml::Source4& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setFile(m.get<0>().getValue());
		dst_.setStartupPolicy(m.get<1>().getValue());
		dst_.setSeclabelList(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source4>::generate(const Domain::Xml::Source4& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getFile(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getStartupPolicy(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSeclabelList(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Nvram

namespace Domain
{
namespace Xml
{
bool Nvram::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Nvram, Name::Strict<277> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Nvram::save(QDomElement& dst_) const
{
	Element<Nvram, Name::Strict<277> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Nvram::save(QDomDocument& dst_) const
{
	Element<Nvram, Name::Strict<277> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Nvram>::parse(Domain::Xml::Nvram& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setTemplate(m.get<0>().getValue());
		dst_.setDiskSource(m.get<1>().getValue());
		dst_.setFormat(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Nvram>::generate(const Domain::Xml::Nvram& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getTemplate(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDiskSource(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFormat(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Bootmenu

namespace Domain
{
namespace Xml
{
Bootmenu::Bootmenu(): m_enable()
{
}

bool Bootmenu::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Bootmenu, Name::Strict<280> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Bootmenu::save(QDomElement& dst_) const
{
	Element<Bootmenu, Name::Strict<280> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Bootmenu::save(QDomDocument& dst_) const
{
	Element<Bootmenu, Name::Strict<280> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Bootmenu>::parse(Domain::Xml::Bootmenu& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setEnable(m.get<0>().getValue());
		dst_.setTimeout(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Bootmenu>::generate(const Domain::Xml::Bootmenu& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getEnable(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTimeout(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Bios

namespace Domain
{
namespace Xml
{
bool Bios::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Bios, Name::Strict<284> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Bios::save(QDomElement& dst_) const
{
	Element<Bios, Name::Strict<284> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Bios::save(QDomDocument& dst_) const
{
	Element<Bios, Name::Strict<284> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Bios>::parse(Domain::Xml::Bios& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setUseserial(m.get<0>().getValue());
		dst_.setRebootTimeout(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Bios>::generate(const Domain::Xml::Bios& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getUseserial(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRebootTimeout(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Os2

namespace Domain
{
namespace Xml
{
bool Os2::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Os2, Name::Strict<222> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Os2::save(QDomElement& dst_) const
{
	Element<Os2, Name::Strict<222> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Os2::save(QDomDocument& dst_) const
{
	Element<Os2, Name::Strict<222> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Os2>::parse(Domain::Xml::Os2& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
		dst_.setLoader(m.get<1>().get<0>().getValue());
		dst_.setNvram(m.get<1>().get<1>().getValue());
		dst_.setOsbootkernel(m.get<1>().get<2>().getValue());
		dst_.setBootList(m.get<1>().get<3>().getValue());
		dst_.setBootmenu(m.get<1>().get<4>().getValue());
		dst_.setSmbios(m.get<1>().get<5>().getValue());
		dst_.setBios(m.get<1>().get<6>().getValue());
		dst_.setAcpi(m.get<1>().get<7>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Os2>::generate(const Domain::Xml::Os2& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLoader(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNvram(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOsbootkernel(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBootList(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBootmenu(), m.get<1>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSmbios(), m.get<1>().get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBios(), m.get<1>().get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<7>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Initenv

namespace Domain
{
namespace Xml
{
bool Initenv::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Initenv, Name::Strict<9348> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Initenv::save(QDomElement& dst_) const
{
	Element<Initenv, Name::Strict<9348> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Initenv::save(QDomDocument& dst_) const
{
	Element<Initenv, Name::Strict<9348> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Initenv>::parse(Domain::Xml::Initenv& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setOwnValue(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Initenv>::generate(const Domain::Xml::Initenv& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOwnValue(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Os3

namespace Domain
{
namespace Xml
{
bool Os3::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Os3, Name::Strict<222> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Os3::save(QDomElement& dst_) const
{
	Element<Os3, Name::Strict<222> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Os3::save(QDomDocument& dst_) const
{
	Element<Os3, Name::Strict<222> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Os3>::parse(Domain::Xml::Os3& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
		dst_.setInit(m.get<1>().get<0>().getValue());
		dst_.setInitargList(m.get<1>().get<1>().getValue());
		dst_.setInitenvList(m.get<1>().get<2>().getValue());
		dst_.setInitdir(m.get<1>().get<3>().getValue());
		dst_.setInituser(m.get<1>().get<4>().getValue());
		dst_.setInitgroup(m.get<1>().get<5>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Os3>::generate(const Domain::Xml::Os3& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInit(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInitargList(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInitenvList(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInitdir(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInituser(), m.get<1>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInitgroup(), m.get<1>().get<5>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Clock6991

namespace Domain
{
namespace Xml
{
Clock6991::Clock6991(): m_offset()
{
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Clock6991>::parse(Domain::Xml::Clock6991& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setOffset(m.get<0>().getValue());
		dst_.setAdjustment(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Clock6991>::generate(const Domain::Xml::Clock6991& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getOffset(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAdjustment(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Clock6993

int Traits<Domain::Xml::Clock6993>::parse(Domain::Xml::Clock6993& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAdjustment(m.get<1>().getValue());
		dst_.setBasis(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Clock6993>::generate(const Domain::Xml::Clock6993& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAdjustment(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBasis(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Catchup

namespace Domain
{
namespace Xml
{
bool Catchup::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Catchup, Name::Strict<430> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Catchup::save(QDomElement& dst_) const
{
	Element<Catchup, Name::Strict<430> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Catchup::save(QDomDocument& dst_) const
{
	Element<Catchup, Name::Strict<430> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Catchup>::parse(Domain::Xml::Catchup& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setThreshold(m.get<0>().getValue());
		dst_.setSlew(m.get<1>().getValue());
		dst_.setLimit(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Catchup>::generate(const Domain::Xml::Catchup& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getThreshold(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSlew(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLimit(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Timer6994

namespace Domain
{
namespace Xml
{
Timer6994::Timer6994(): m_name()
{
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Timer6994>::parse(Domain::Xml::Timer6994& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setTrack(m.get<1>().getValue());
		dst_.setTickpolicy(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Timer6994>::generate(const Domain::Xml::Timer6994& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTrack(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTickpolicy(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Timer6995

int Traits<Domain::Xml::Timer6995>::parse(Domain::Xml::Timer6995& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setTickpolicy(m.get<1>().getValue());
		dst_.setFrequency(m.get<2>().getValue());
		dst_.setMode(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Timer6995>::generate(const Domain::Xml::Timer6995& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getTickpolicy(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFrequency(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMode(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Timer6996

namespace Domain
{
namespace Xml
{
Timer6996::Timer6996(): m_name()
{
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Timer6996>::parse(Domain::Xml::Timer6996& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setTickpolicy(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Timer6996>::generate(const Domain::Xml::Timer6996& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTickpolicy(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Timer

namespace Domain
{
namespace Xml
{
bool Timer::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Timer, Name::Strict<403> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Timer::save(QDomElement& dst_) const
{
	Element<Timer, Name::Strict<403> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Timer::save(QDomDocument& dst_) const
{
	Element<Timer, Name::Strict<403> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Timer>::parse(Domain::Xml::Timer& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setTimer(m.get<0>().getValue());
		dst_.setPresent(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Timer>::generate(const Domain::Xml::Timer& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getTimer(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPresent(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Clock

namespace Domain
{
namespace Xml
{
bool Clock::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Clock, Name::Strict<223> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Clock::save(QDomElement& dst_) const
{
	Element<Clock, Name::Strict<223> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Clock::save(QDomDocument& dst_) const
{
	Element<Clock, Name::Strict<223> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Clock>::parse(Domain::Xml::Clock& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setClock(m.get<0>().getValue());
		dst_.setTimerList(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Clock>::generate(const Domain::Xml::Clock& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getClock(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTimerList(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct ScaledInteger

namespace Domain
{
namespace Xml
{
ScaledInteger::ScaledInteger(): m_ownValue()
{
}

bool ScaledInteger::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<ScaledInteger, Name::Strict<334> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool ScaledInteger::save(QDomElement& dst_) const
{
	Element<ScaledInteger, Name::Strict<334> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool ScaledInteger::save(QDomDocument& dst_) const
{
	Element<ScaledInteger, Name::Strict<334> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::ScaledInteger>::parse(Domain::Xml::ScaledInteger& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setUnit(m.get<0>().getValue());
		dst_.setOwnValue(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::ScaledInteger>::generate(const Domain::Xml::ScaledInteger& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getUnit(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOwnValue(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Memory

namespace Domain
{
namespace Xml
{
bool Memory::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Memory, Name::Strict<326> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Memory::save(QDomElement& dst_) const
{
	Element<Memory, Name::Strict<326> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Memory::save(QDomDocument& dst_) const
{
	Element<Memory, Name::Strict<326> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Memory>::parse(Domain::Xml::Memory& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setScaledInteger(m.get<0>().getValue());
		dst_.setDumpCore(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Memory>::generate(const Domain::Xml::Memory& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getScaledInteger(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDumpCore(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct MaxMemory

namespace Domain
{
namespace Xml
{
MaxMemory::MaxMemory(): m_slots()
{
}

bool MaxMemory::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<MaxMemory, Name::Strict<328> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool MaxMemory::save(QDomElement& dst_) const
{
	Element<MaxMemory, Name::Strict<328> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool MaxMemory::save(QDomDocument& dst_) const
{
	Element<MaxMemory, Name::Strict<328> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::MaxMemory>::parse(Domain::Xml::MaxMemory& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setScaledInteger(m.get<0>().getValue());
		dst_.setSlots(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::MaxMemory>::generate(const Domain::Xml::MaxMemory& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getScaledInteger(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSlots(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Page

namespace Domain
{
namespace Xml
{
Page::Page(): m_size()
{
}

bool Page::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Page, Name::Strict<333> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Page::save(QDomElement& dst_) const
{
	Element<Page, Name::Strict<333> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Page::save(QDomDocument& dst_) const
{
	Element<Page, Name::Strict<333> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Page>::parse(Domain::Xml::Page& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSize(m.get<0>().getValue());
		dst_.setUnit(m.get<1>().getValue());
		dst_.setNodeset(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Page>::generate(const Domain::Xml::Page& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSize(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getUnit(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNodeset(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct MemoryBacking

namespace Domain
{
namespace Xml
{
MemoryBacking::MemoryBacking(): m_nosharepages(), m_locked(), m_discard()
{
}

bool MemoryBacking::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<MemoryBacking, Name::Strict<331> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool MemoryBacking::save(QDomElement& dst_) const
{
	Element<MemoryBacking, Name::Strict<331> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool MemoryBacking::save(QDomDocument& dst_) const
{
	Element<MemoryBacking, Name::Strict<331> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::MemoryBacking>::parse(Domain::Xml::MemoryBacking& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setHugepages(m.get<0>().getValue());
		dst_.setNosharepages(m.get<1>().getValue());
		dst_.setLocked(m.get<2>().getValue());
		dst_.setSource(m.get<3>().getValue());
		dst_.setAccess(m.get<4>().getValue());
		dst_.setAllocation(m.get<5>().getValue());
		dst_.setDiscard(m.get<6>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::MemoryBacking>::generate(const Domain::Xml::MemoryBacking& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getHugepages(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNosharepages(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLocked(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAccess(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAllocation(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDiscard(), m.get<6>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Vcpu

namespace Domain
{
namespace Xml
{
Vcpu::Vcpu(): m_ownValue()
{
}

bool Vcpu::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Vcpu, Name::Strict<338> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Vcpu::save(QDomElement& dst_) const
{
	Element<Vcpu, Name::Strict<338> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Vcpu::save(QDomDocument& dst_) const
{
	Element<Vcpu, Name::Strict<338> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Vcpu>::parse(Domain::Xml::Vcpu& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setPlacement(m.get<0>().getValue());
		dst_.setCpuset(m.get<1>().getValue());
		dst_.setCurrent(m.get<2>().getValue());
		dst_.setOwnValue(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Vcpu>::generate(const Domain::Xml::Vcpu& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getPlacement(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCpuset(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCurrent(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOwnValue(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Vcpu1

namespace Domain
{
namespace Xml
{
Vcpu1::Vcpu1(): m_id(), m_enabled()
{
}

bool Vcpu1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Vcpu1, Name::Strict<338> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Vcpu1::save(QDomElement& dst_) const
{
	Element<Vcpu1, Name::Strict<338> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Vcpu1::save(QDomDocument& dst_) const
{
	Element<Vcpu1, Name::Strict<338> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Vcpu1>::parse(Domain::Xml::Vcpu1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setId(m.get<0>().getValue());
		dst_.setEnabled(m.get<1>().getValue());
		dst_.setHotpluggable(m.get<2>().getValue());
		dst_.setOrder(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Vcpu1>::generate(const Domain::Xml::Vcpu1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getId(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEnabled(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHotpluggable(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOrder(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Device

namespace Domain
{
namespace Xml
{
bool Device::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Device, Name::Strict<354> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Device::save(QDomElement& dst_) const
{
	Element<Device, Name::Strict<354> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Device::save(QDomDocument& dst_) const
{
	Element<Device, Name::Strict<354> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Device>::parse(Domain::Xml::Device& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setPath(m.get<0>().getValue());
		dst_.setWeight(m.get<1>().getValue());
		dst_.setReadIopsSec(m.get<2>().getValue());
		dst_.setWriteIopsSec(m.get<3>().getValue());
		dst_.setReadBytesSec(m.get<4>().getValue());
		dst_.setWriteBytesSec(m.get<5>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Device>::generate(const Domain::Xml::Device& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getPath(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getWeight(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getReadIopsSec(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getWriteIopsSec(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getReadBytesSec(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getWriteBytesSec(), m.get<5>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Blkiotune

namespace Domain
{
namespace Xml
{
bool Blkiotune::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Blkiotune, Name::Strict<348> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Blkiotune::save(QDomElement& dst_) const
{
	Element<Blkiotune, Name::Strict<348> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Blkiotune::save(QDomDocument& dst_) const
{
	Element<Blkiotune, Name::Strict<348> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Blkiotune>::parse(Domain::Xml::Blkiotune& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setWeight(m.get<0>().getValue());
		dst_.setDeviceList(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Blkiotune>::generate(const Domain::Xml::Blkiotune& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getWeight(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDeviceList(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Memtune

namespace Domain
{
namespace Xml
{
bool Memtune::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Memtune, Name::Strict<349> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Memtune::save(QDomElement& dst_) const
{
	Element<Memtune, Name::Strict<349> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Memtune::save(QDomDocument& dst_) const
{
	Element<Memtune, Name::Strict<349> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Memtune>::parse(Domain::Xml::Memtune& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setHardLimit(m.get<0>().getValue());
		dst_.setSoftLimit(m.get<1>().getValue());
		dst_.setMinGuarantee(m.get<2>().getValue());
		dst_.setSwapHardLimit(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Memtune>::generate(const Domain::Xml::Memtune& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getHardLimit(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSoftLimit(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMinGuarantee(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSwapHardLimit(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Vcpupin

namespace Domain
{
namespace Xml
{
Vcpupin::Vcpupin(): m_vcpu()
{
}

bool Vcpupin::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Vcpupin, Name::Strict<374> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Vcpupin::save(QDomElement& dst_) const
{
	Element<Vcpupin, Name::Strict<374> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Vcpupin::save(QDomDocument& dst_) const
{
	Element<Vcpupin, Name::Strict<374> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Vcpupin>::parse(Domain::Xml::Vcpupin& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setVcpu(m.get<0>().getValue());
		dst_.setCpuset(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Vcpupin>::generate(const Domain::Xml::Vcpupin& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getVcpu(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCpuset(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Iothreadpin

namespace Domain
{
namespace Xml
{
Iothreadpin::Iothreadpin(): m_iothread()
{
}

bool Iothreadpin::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Iothreadpin, Name::Strict<377> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Iothreadpin::save(QDomElement& dst_) const
{
	Element<Iothreadpin, Name::Strict<377> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Iothreadpin::save(QDomDocument& dst_) const
{
	Element<Iothreadpin, Name::Strict<377> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Iothreadpin>::parse(Domain::Xml::Iothreadpin& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setIothread(m.get<0>().getValue());
		dst_.setCpuset(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Iothreadpin>::generate(const Domain::Xml::Iothreadpin& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getIothread(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCpuset(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Schedparam9370

namespace Domain
{
namespace Xml
{
Schedparam9370::Schedparam9370(): m_scheduler(), m_priority()
{
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Schedparam9370>::parse(Domain::Xml::Schedparam9370& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setScheduler(m.get<0>().getValue());
		dst_.setPriority(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Schedparam9370>::generate(const Domain::Xml::Schedparam9370& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getScheduler(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPriority(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Vcpusched

namespace Domain
{
namespace Xml
{
bool Vcpusched::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Vcpusched, Name::Strict<9356> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Vcpusched::save(QDomElement& dst_) const
{
	Element<Vcpusched, Name::Strict<9356> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Vcpusched::save(QDomDocument& dst_) const
{
	Element<Vcpusched, Name::Strict<9356> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Vcpusched>::parse(Domain::Xml::Vcpusched& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setVcpus(m.get<0>().getValue());
		dst_.setSchedparam(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Vcpusched>::generate(const Domain::Xml::Vcpusched& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getVcpus(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSchedparam(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Iothreadsched

namespace Domain
{
namespace Xml
{
bool Iothreadsched::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Iothreadsched, Name::Strict<9358> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Iothreadsched::save(QDomElement& dst_) const
{
	Element<Iothreadsched, Name::Strict<9358> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Iothreadsched::save(QDomDocument& dst_) const
{
	Element<Iothreadsched, Name::Strict<9358> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Iothreadsched>::parse(Domain::Xml::Iothreadsched& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setIothreads(m.get<0>().getValue());
		dst_.setSchedparam(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Iothreadsched>::generate(const Domain::Xml::Iothreadsched& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getIothreads(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSchedparam(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Cache2

namespace Domain
{
namespace Xml
{
Cache2::Cache2(): m_id(), m_level(), m_type(), m_size()
{
}

bool Cache2::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Cache2, Name::Strict<558> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Cache2::save(QDomElement& dst_) const
{
	Element<Cache2, Name::Strict<558> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Cache2::save(QDomDocument& dst_) const
{
	Element<Cache2, Name::Strict<558> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Cache2>::parse(Domain::Xml::Cache2& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setId(m.get<0>().getValue());
		dst_.setLevel(m.get<1>().getValue());
		dst_.setType(m.get<2>().getValue());
		dst_.setSize(m.get<3>().getValue());
		dst_.setUnit(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Cache2>::generate(const Domain::Xml::Cache2& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getId(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLevel(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSize(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getUnit(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Monitor

namespace Domain
{
namespace Xml
{
Monitor::Monitor(): m_level()
{
}

bool Monitor::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Monitor, Name::Strict<9363> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Monitor::save(QDomElement& dst_) const
{
	Element<Monitor, Name::Strict<9363> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Monitor::save(QDomDocument& dst_) const
{
	Element<Monitor, Name::Strict<9363> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Monitor>::parse(Domain::Xml::Monitor& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setLevel(m.get<0>().getValue());
		dst_.setVcpus(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Monitor>::generate(const Domain::Xml::Monitor& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getLevel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVcpus(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Cachetune

namespace Domain
{
namespace Xml
{
bool Cachetune::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Cachetune, Name::Strict<9360> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Cachetune::save(QDomElement& dst_) const
{
	Element<Cachetune, Name::Strict<9360> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Cachetune::save(QDomDocument& dst_) const
{
	Element<Cachetune, Name::Strict<9360> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Cachetune>::parse(Domain::Xml::Cachetune& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setVcpus(m.get<0>().getValue());
		dst_.setId(m.get<1>().getValue());
		dst_.setChoice5117List(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Cachetune>::generate(const Domain::Xml::Cachetune& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getVcpus(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getId(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChoice5117List(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Node

namespace Domain
{
namespace Xml
{
Node::Node(): m_id(), m_bandwidth()
{
}

bool Node::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Node, Name::Strict<609> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Node::save(QDomElement& dst_) const
{
	Element<Node, Name::Strict<609> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Node::save(QDomDocument& dst_) const
{
	Element<Node, Name::Strict<609> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Node>::parse(Domain::Xml::Node& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setId(m.get<0>().getValue());
		dst_.setBandwidth(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Node>::generate(const Domain::Xml::Node& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getId(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBandwidth(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Memorytune

namespace Domain
{
namespace Xml
{
bool Memorytune::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Memorytune, Name::Strict<9364> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Memorytune::save(QDomElement& dst_) const
{
	Element<Memorytune, Name::Strict<9364> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Memorytune::save(QDomDocument& dst_) const
{
	Element<Memorytune, Name::Strict<9364> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Memorytune>::parse(Domain::Xml::Memorytune& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setVcpus(m.get<0>().getValue());
		dst_.setChoice5120List(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Memorytune>::generate(const Domain::Xml::Memorytune& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getVcpus(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChoice5120List(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Cputune

namespace Domain
{
namespace Xml
{
bool Cputune::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Cputune, Name::Strict<350> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Cputune::save(QDomElement& dst_) const
{
	Element<Cputune, Name::Strict<350> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Cputune::save(QDomDocument& dst_) const
{
	Element<Cputune, Name::Strict<350> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Cputune>::parse(Domain::Xml::Cputune& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setShares(m.get<0>().getValue());
		dst_.setGlobalPeriod(m.get<1>().getValue());
		dst_.setGlobalQuota(m.get<2>().getValue());
		dst_.setPeriod(m.get<3>().getValue());
		dst_.setQuota(m.get<4>().getValue());
		dst_.setEmulatorPeriod(m.get<5>().getValue());
		dst_.setEmulatorQuota(m.get<6>().getValue());
		dst_.setIothreadPeriod(m.get<7>().getValue());
		dst_.setIothreadQuota(m.get<8>().getValue());
		dst_.setVcpupinList(m.get<9>().getValue());
		dst_.setEmulatorpin(m.get<10>().getValue());
		dst_.setIothreadpinList(m.get<11>().getValue());
		dst_.setVcpuschedList(m.get<12>().getValue());
		dst_.setIothreadschedList(m.get<13>().getValue());
		dst_.setEmulatorsched(m.get<14>().getValue());
		dst_.setCachetuneList(m.get<15>().getValue());
		dst_.setMemorytuneList(m.get<16>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Cputune>::generate(const Domain::Xml::Cputune& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getShares(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGlobalPeriod(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGlobalQuota(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPeriod(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getQuota(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEmulatorPeriod(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEmulatorQuota(), m.get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIothreadPeriod(), m.get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIothreadQuota(), m.get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVcpupinList(), m.get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEmulatorpin(), m.get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIothreadpinList(), m.get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVcpuschedList(), m.get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIothreadschedList(), m.get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEmulatorsched(), m.get<14>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCachetuneList(), m.get<15>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMemorytuneList(), m.get<16>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Memory2356

int Traits<Domain::Xml::Memory2356>::parse(Domain::Xml::Memory2356& , QStack<QDomElement>& stack_)
{
	marshal_type m;
	return m.consume(stack_);
}

int Traits<Domain::Xml::Memory2356>::generate(const Domain::Xml::Memory2356& , QDomElement& dst_)
{
	marshal_type m;
	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Memory1

namespace Domain
{
namespace Xml
{
bool Memory1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Memory1, Name::Strict<326> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Memory1::save(QDomElement& dst_) const
{
	Element<Memory1, Name::Strict<326> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Memory1::save(QDomDocument& dst_) const
{
	Element<Memory1, Name::Strict<326> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Memory1>::parse(Domain::Xml::Memory1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setMode(m.get<0>().getValue());
		dst_.setMemory(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Memory1>::generate(const Domain::Xml::Memory1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getMode(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMemory(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Memnode

namespace Domain
{
namespace Xml
{
Memnode::Memnode(): m_cellid(), m_mode()
{
}

bool Memnode::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Memnode, Name::Strict<385> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Memnode::save(QDomElement& dst_) const
{
	Element<Memnode, Name::Strict<385> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Memnode::save(QDomDocument& dst_) const
{
	Element<Memnode, Name::Strict<385> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Memnode>::parse(Domain::Xml::Memnode& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setCellid(m.get<0>().getValue());
		dst_.setMode(m.get<1>().getValue());
		dst_.setNodeset(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Memnode>::generate(const Domain::Xml::Memnode& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getCellid(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMode(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNodeset(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Numatune

namespace Domain
{
namespace Xml
{
bool Numatune::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Numatune, Name::Strict<351> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Numatune::save(QDomElement& dst_) const
{
	Element<Numatune, Name::Strict<351> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Numatune::save(QDomDocument& dst_) const
{
	Element<Numatune, Name::Strict<351> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Numatune>::parse(Domain::Xml::Numatune& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setMemory(m.get<0>().getValue());
		dst_.setMemnodeList(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Numatune>::generate(const Domain::Xml::Numatune& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getMemory(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMemnodeList(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Resource

namespace Domain
{
namespace Xml
{
bool Resource::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Resource, Name::Strict<387> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Resource::save(QDomElement& dst_) const
{
	Element<Resource, Name::Strict<387> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Resource::save(QDomDocument& dst_) const
{
	Element<Resource, Name::Strict<387> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Resource>::parse(Domain::Xml::Resource& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setPartition(m.get<0>().getValue());
		dst_.setFibrechannel(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Resource>::generate(const Domain::Xml::Resource& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getPartition(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFibrechannel(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Apic

namespace Domain
{
namespace Xml
{
bool Apic::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Apic, Name::Strict<991> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Apic::save(QDomElement& dst_) const
{
	Element<Apic, Name::Strict<991> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Apic::save(QDomDocument& dst_) const
{
	Element<Apic, Name::Strict<991> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Apic>::parse(Domain::Xml::Apic& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setEoi(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Apic>::generate(const Domain::Xml::Apic& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getEoi(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hap

namespace Domain
{
namespace Xml
{
bool Hap::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Hap, Name::Strict<994> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Hap::save(QDomElement& dst_) const
{
	Element<Hap, Name::Strict<994> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Hap::save(QDomDocument& dst_) const
{
	Element<Hap, Name::Strict<994> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Hap>::parse(Domain::Xml::Hap& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setState(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hap>::generate(const Domain::Xml::Hap& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getState(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Spinlocks

namespace Domain
{
namespace Xml
{
Spinlocks::Spinlocks(): m_state()
{
}

bool Spinlocks::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Spinlocks, Name::Strict<1114> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Spinlocks::save(QDomElement& dst_) const
{
	Element<Spinlocks, Name::Strict<1114> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Spinlocks::save(QDomDocument& dst_) const
{
	Element<Spinlocks, Name::Strict<1114> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Spinlocks>::parse(Domain::Xml::Spinlocks& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setState(m.get<0>().getValue());
		dst_.setRetries(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Spinlocks>::generate(const Domain::Xml::Spinlocks& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getState(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRetries(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Stimer

namespace Domain
{
namespace Xml
{
bool Stimer::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Stimer, Name::Strict<1119> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Stimer::save(QDomElement& dst_) const
{
	Element<Stimer, Name::Strict<1119> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Stimer::save(QDomDocument& dst_) const
{
	Element<Stimer, Name::Strict<1119> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Stimer>::parse(Domain::Xml::Stimer& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setState(m.get<0>().getValue());
		dst_.setDirect(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Stimer>::generate(const Domain::Xml::Stimer& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getState(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDirect(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct VendorId

namespace Domain
{
namespace Xml
{
VendorId::VendorId(): m_state()
{
}

bool VendorId::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<VendorId, Name::Strict<1020> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool VendorId::save(QDomElement& dst_) const
{
	Element<VendorId, Name::Strict<1020> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool VendorId::save(QDomDocument& dst_) const
{
	Element<VendorId, Name::Strict<1020> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::VendorId>::parse(Domain::Xml::VendorId& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setState(m.get<0>().getValue());
		dst_.setValue(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::VendorId>::generate(const Domain::Xml::VendorId& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getState(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getValue(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hyperv

namespace Domain
{
namespace Xml
{
bool Hyperv::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Hyperv, Name::Strict<256> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Hyperv::save(QDomElement& dst_) const
{
	Element<Hyperv, Name::Strict<256> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Hyperv::save(QDomDocument& dst_) const
{
	Element<Hyperv, Name::Strict<256> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Hyperv>::parse(Domain::Xml::Hyperv& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setRelaxed(m.get<0>().getValue());
		dst_.setVapic(m.get<1>().getValue());
		dst_.setSpinlocks(m.get<2>().getValue());
		dst_.setVpindex(m.get<3>().getValue());
		dst_.setRuntime(m.get<4>().getValue());
		dst_.setSynic(m.get<5>().getValue());
		dst_.setStimer(m.get<6>().getValue());
		dst_.setReset(m.get<7>().getValue());
		dst_.setVendorId(m.get<8>().getValue());
		dst_.setFrequencies(m.get<9>().getValue());
		dst_.setReenlightenment(m.get<10>().getValue());
		dst_.setTlbflush(m.get<11>().getValue());
		dst_.setIpi(m.get<12>().getValue());
		dst_.setEvmcs(m.get<13>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hyperv>::generate(const Domain::Xml::Hyperv& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getRelaxed(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVapic(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSpinlocks(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVpindex(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRuntime(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSynic(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getStimer(), m.get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getReset(), m.get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVendorId(), m.get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFrequencies(), m.get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getReenlightenment(), m.get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTlbflush(), m.get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIpi(), m.get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEvmcs(), m.get<13>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Kvm

namespace Domain
{
namespace Xml
{
bool Kvm::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Kvm, Name::Strict<249> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Kvm::save(QDomElement& dst_) const
{
	Element<Kvm, Name::Strict<249> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Kvm::save(QDomDocument& dst_) const
{
	Element<Kvm, Name::Strict<249> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Kvm>::parse(Domain::Xml::Kvm& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setHidden(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Kvm>::generate(const Domain::Xml::Kvm& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getHidden(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Pvspinlock

namespace Domain
{
namespace Xml
{
bool Pvspinlock::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Pvspinlock, Name::Strict<997> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Pvspinlock::save(QDomElement& dst_) const
{
	Element<Pvspinlock, Name::Strict<997> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Pvspinlock::save(QDomDocument& dst_) const
{
	Element<Pvspinlock, Name::Strict<997> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Pvspinlock>::parse(Domain::Xml::Pvspinlock& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setState(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Pvspinlock>::generate(const Domain::Xml::Pvspinlock& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getState(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Capabilities

namespace Domain
{
namespace Xml
{
Capabilities::Capabilities(): m_policy()
{
}

bool Capabilities::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Capabilities, Name::Strict<926> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Capabilities::save(QDomElement& dst_) const
{
	Element<Capabilities, Name::Strict<926> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Capabilities::save(QDomDocument& dst_) const
{
	Element<Capabilities, Name::Strict<926> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Capabilities>::parse(Domain::Xml::Capabilities& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setPolicy(m.get<0>().getValue());
		dst_.setAuditControl(m.get<1>().get<0>().getValue());
		dst_.setAuditWrite(m.get<1>().get<1>().getValue());
		dst_.setBlockSuspend(m.get<1>().get<2>().getValue());
		dst_.setChown(m.get<1>().get<3>().getValue());
		dst_.setDacOverride(m.get<1>().get<4>().getValue());
		dst_.setDacReadSearch(m.get<1>().get<5>().getValue());
		dst_.setFowner(m.get<1>().get<6>().getValue());
		dst_.setFsetid(m.get<1>().get<7>().getValue());
		dst_.setIpcLock(m.get<1>().get<8>().getValue());
		dst_.setIpcOwner(m.get<1>().get<9>().getValue());
		dst_.setKill(m.get<1>().get<10>().getValue());
		dst_.setLease(m.get<1>().get<11>().getValue());
		dst_.setLinuxImmutable(m.get<1>().get<12>().getValue());
		dst_.setMacAdmin(m.get<1>().get<13>().getValue());
		dst_.setMacOverride(m.get<1>().get<14>().getValue());
		dst_.setMknod(m.get<1>().get<15>().getValue());
		dst_.setNetAdmin(m.get<1>().get<16>().getValue());
		dst_.setNetBindService(m.get<1>().get<17>().getValue());
		dst_.setNetBroadcast(m.get<1>().get<18>().getValue());
		dst_.setNetRaw(m.get<1>().get<19>().getValue());
		dst_.setSetgid(m.get<1>().get<20>().getValue());
		dst_.setSetfcap(m.get<1>().get<21>().getValue());
		dst_.setSetpcap(m.get<1>().get<22>().getValue());
		dst_.setSetuid(m.get<1>().get<23>().getValue());
		dst_.setSysAdmin(m.get<1>().get<24>().getValue());
		dst_.setSysBoot(m.get<1>().get<25>().getValue());
		dst_.setSysChroot(m.get<1>().get<26>().getValue());
		dst_.setSysModule(m.get<1>().get<27>().getValue());
		dst_.setSysNice(m.get<1>().get<28>().getValue());
		dst_.setSysPacct(m.get<1>().get<29>().getValue());
		dst_.setSysPtrace(m.get<1>().get<30>().getValue());
		dst_.setSysRawio(m.get<1>().get<31>().getValue());
		dst_.setSysResource(m.get<1>().get<32>().getValue());
		dst_.setSysTime(m.get<1>().get<33>().getValue());
		dst_.setSysTtyConfig(m.get<1>().get<34>().getValue());
		dst_.setSyslog(m.get<1>().get<35>().getValue());
		dst_.setWakeAlarm(m.get<1>().get<36>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Capabilities>::generate(const Domain::Xml::Capabilities& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getPolicy(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAuditControl(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAuditWrite(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBlockSuspend(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChown(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDacOverride(), m.get<1>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDacReadSearch(), m.get<1>().get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFowner(), m.get<1>().get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFsetid(), m.get<1>().get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIpcLock(), m.get<1>().get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIpcOwner(), m.get<1>().get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getKill(), m.get<1>().get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLease(), m.get<1>().get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLinuxImmutable(), m.get<1>().get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMacAdmin(), m.get<1>().get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMacOverride(), m.get<1>().get<14>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMknod(), m.get<1>().get<15>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNetAdmin(), m.get<1>().get<16>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNetBindService(), m.get<1>().get<17>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNetBroadcast(), m.get<1>().get<18>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNetRaw(), m.get<1>().get<19>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSetgid(), m.get<1>().get<20>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSetfcap(), m.get<1>().get<21>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSetpcap(), m.get<1>().get<22>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSetuid(), m.get<1>().get<23>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSysAdmin(), m.get<1>().get<24>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSysBoot(), m.get<1>().get<25>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSysChroot(), m.get<1>().get<26>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSysModule(), m.get<1>().get<27>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSysNice(), m.get<1>().get<28>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSysPacct(), m.get<1>().get<29>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSysPtrace(), m.get<1>().get<30>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSysRawio(), m.get<1>().get<31>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSysResource(), m.get<1>().get<32>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSysTime(), m.get<1>().get<33>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSysTtyConfig(), m.get<1>().get<34>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSyslog(), m.get<1>().get<35>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getWakeAlarm(), m.get<1>().get<36>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Pmu

namespace Domain
{
namespace Xml
{
bool Pmu::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Pmu, Name::Strict<999> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Pmu::save(QDomElement& dst_) const
{
	Element<Pmu, Name::Strict<999> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Pmu::save(QDomDocument& dst_) const
{
	Element<Pmu, Name::Strict<999> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Pmu>::parse(Domain::Xml::Pmu& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setState(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Pmu>::generate(const Domain::Xml::Pmu& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getState(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Vmport

namespace Domain
{
namespace Xml
{
bool Vmport::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Vmport, Name::Strict<1000> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Vmport::save(QDomElement& dst_) const
{
	Element<Vmport, Name::Strict<1000> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Vmport::save(QDomDocument& dst_) const
{
	Element<Vmport, Name::Strict<1000> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Vmport>::parse(Domain::Xml::Vmport& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setState(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Vmport>::generate(const Domain::Xml::Vmport& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getState(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Gic

namespace Domain
{
namespace Xml
{
bool Gic::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Gic, Name::Strict<1001> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Gic::save(QDomElement& dst_) const
{
	Element<Gic, Name::Strict<1001> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Gic::save(QDomDocument& dst_) const
{
	Element<Gic, Name::Strict<1001> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Gic>::parse(Domain::Xml::Gic& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setVersion(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Gic>::generate(const Domain::Xml::Gic& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getVersion(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous2357

namespace Domain
{
namespace Xml
{
Anonymous2357::Anonymous2357(): m_state()
{
}

bool Anonymous2357::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Anonymous2357>::parse(*this, k);
}

bool Anonymous2357::save(QDomElement& dst_) const
{
	return 0 <= Traits<Anonymous2357>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Anonymous2357>::parse(Domain::Xml::Anonymous2357& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setState(m.get<0>().getValue());
		dst_.setTseg(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Anonymous2357>::generate(const Domain::Xml::Anonymous2357& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getState(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTseg(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Smm

namespace Domain
{
namespace Xml
{
bool Smm::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Smm, Name::Strict<1002> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Smm::save(QDomElement& dst_) const
{
	Element<Smm, Name::Strict<1002> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Smm::save(QDomDocument& dst_) const
{
	Element<Smm, Name::Strict<1002> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Smm>::parse(Domain::Xml::Smm& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAnonymous2357(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Smm>::generate(const Domain::Xml::Smm& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAnonymous2357(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hpt

namespace Domain
{
namespace Xml
{
bool Hpt::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Hpt, Name::Strict<9404> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Hpt::save(QDomElement& dst_) const
{
	Element<Hpt, Name::Strict<9404> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Hpt::save(QDomDocument& dst_) const
{
	Element<Hpt, Name::Strict<9404> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Hpt>::parse(Domain::Xml::Hpt& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setResizing(m.get<0>().getValue());
		dst_.setMaxpagesize(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hpt>::generate(const Domain::Xml::Hpt& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getResizing(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMaxpagesize(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Vmcoreinfo

namespace Domain
{
namespace Xml
{
bool Vmcoreinfo::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Vmcoreinfo, Name::Strict<1004> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Vmcoreinfo::save(QDomElement& dst_) const
{
	Element<Vmcoreinfo, Name::Strict<1004> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Vmcoreinfo::save(QDomDocument& dst_) const
{
	Element<Vmcoreinfo, Name::Strict<1004> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Vmcoreinfo>::parse(Domain::Xml::Vmcoreinfo& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setState(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Vmcoreinfo>::generate(const Domain::Xml::Vmcoreinfo& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getState(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Tcg

namespace Domain
{
namespace Xml
{
bool Tcg::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Tcg, Name::Strict<9424> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Tcg::save(QDomElement& dst_) const
{
	Element<Tcg, Name::Strict<9424> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Tcg::save(QDomDocument& dst_) const
{
	Element<Tcg, Name::Strict<9424> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Tcg>::parse(Domain::Xml::Tcg& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setTbCache(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Tcg>::generate(const Domain::Xml::Tcg& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getTbCache(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Features

namespace Domain
{
namespace Xml
{
Features::Features(): m_pae(), m_acpi(), m_viridian(), m_privnet()
{
}

bool Features::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Features, Name::Strict<155> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Features::save(QDomElement& dst_) const
{
	Element<Features, Name::Strict<155> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Features::save(QDomDocument& dst_) const
{
	Element<Features, Name::Strict<155> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Features>::parse(Domain::Xml::Features& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setPae(m.get<0>().getValue());
		dst_.setApic(m.get<1>().getValue());
		dst_.setAcpi(m.get<2>().getValue());
		dst_.setHap(m.get<3>().getValue());
		dst_.setHyperv(m.get<4>().getValue());
		dst_.setViridian(m.get<5>().getValue());
		dst_.setKvm(m.get<6>().getValue());
		dst_.setPrivnet(m.get<7>().getValue());
		dst_.setPvspinlock(m.get<8>().getValue());
		dst_.setCapabilities(m.get<9>().getValue());
		dst_.setPmu(m.get<10>().getValue());
		dst_.setVmport(m.get<11>().getValue());
		dst_.setGic(m.get<12>().getValue());
		dst_.setSmm(m.get<13>().getValue());
		dst_.setIoapic(m.get<14>().getValue());
		dst_.setHpt(m.get<15>().getValue());
		dst_.setVmcoreinfo(m.get<16>().getValue());
		dst_.setHtm(m.get<17>().getValue());
		dst_.setNestedHv(m.get<18>().getValue());
		dst_.setMsrs(m.get<19>().getValue());
		dst_.setCcfAssist(m.get<20>().getValue());
		dst_.setCfpc(m.get<21>().getValue());
		dst_.setSbbc(m.get<22>().getValue());
		dst_.setIbs(m.get<23>().getValue());
		dst_.setTcg(m.get<24>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Features>::generate(const Domain::Xml::Features& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getPae(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getApic(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHap(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHyperv(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getViridian(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getKvm(), m.get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPrivnet(), m.get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPvspinlock(), m.get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCapabilities(), m.get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPmu(), m.get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVmport(), m.get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGic(), m.get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSmm(), m.get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIoapic(), m.get<14>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHpt(), m.get<15>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVmcoreinfo(), m.get<16>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHtm(), m.get<17>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNestedHv(), m.get<18>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMsrs(), m.get<19>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCcfAssist(), m.get<20>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCfpc(), m.get<21>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSbbc(), m.get<22>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIbs(), m.get<23>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTcg(), m.get<24>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct VzDns

namespace Domain
{
namespace Xml
{
bool VzDns::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<VzDns, Name::Strict<5706> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool VzDns::save(QDomElement& dst_) const
{
	Element<VzDns, Name::Strict<5706> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool VzDns::save(QDomDocument& dst_) const
{
	Element<VzDns, Name::Strict<5706> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::VzDns>::parse(Domain::Xml::VzDns& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setHostname(m.get<0>().getValue());
		dst_.setServerList(m.get<1>().getValue());
		dst_.setSearchList(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::VzDns>::generate(const Domain::Xml::VzDns& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getHostname(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getServerList(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSearchList(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Class

namespace Domain
{
namespace Xml
{
Class::Class(): m_id(), m_rate()
{
}

bool Class::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Class, Name::Strict<842> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Class::save(QDomElement& dst_) const
{
	Element<Class, Name::Strict<842> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Class::save(QDomDocument& dst_) const
{
	Element<Class, Name::Strict<842> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Class>::parse(Domain::Xml::Class& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setId(m.get<0>().getValue());
		dst_.setRate(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Class>::generate(const Domain::Xml::Class& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getId(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRate(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct VzNetworkRates

namespace Domain
{
namespace Xml
{
VzNetworkRates::VzNetworkRates(): m_rateBound()
{
}

bool VzNetworkRates::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<VzNetworkRates, Name::Strict<9001> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool VzNetworkRates::save(QDomElement& dst_) const
{
	Element<VzNetworkRates, Name::Strict<9001> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool VzNetworkRates::save(QDomDocument& dst_) const
{
	Element<VzNetworkRates, Name::Strict<9001> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::VzNetworkRates>::parse(Domain::Xml::VzNetworkRates& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setRateBound(m.get<0>().getValue());
		dst_.setClassList(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::VzNetworkRates>::generate(const Domain::Xml::VzNetworkRates& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getRateBound(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getClassList(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct SuspendToMem

namespace Domain
{
namespace Xml
{
bool SuspendToMem::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<SuspendToMem, Name::Strict<806> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool SuspendToMem::save(QDomElement& dst_) const
{
	Element<SuspendToMem, Name::Strict<806> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool SuspendToMem::save(QDomDocument& dst_) const
{
	Element<SuspendToMem, Name::Strict<806> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::SuspendToMem>::parse(Domain::Xml::SuspendToMem& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setEnabled(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::SuspendToMem>::generate(const Domain::Xml::SuspendToMem& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getEnabled(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct SuspendToDisk

namespace Domain
{
namespace Xml
{
bool SuspendToDisk::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<SuspendToDisk, Name::Strict<808> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool SuspendToDisk::save(QDomElement& dst_) const
{
	Element<SuspendToDisk, Name::Strict<808> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool SuspendToDisk::save(QDomDocument& dst_) const
{
	Element<SuspendToDisk, Name::Strict<808> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::SuspendToDisk>::parse(Domain::Xml::SuspendToDisk& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setEnabled(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::SuspendToDisk>::generate(const Domain::Xml::SuspendToDisk& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getEnabled(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Pm

namespace Domain
{
namespace Xml
{
bool Pm::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Pm, Name::Strict<226> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Pm::save(QDomElement& dst_) const
{
	Element<Pm, Name::Strict<226> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Pm::save(QDomDocument& dst_) const
{
	Element<Pm, Name::Strict<226> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Pm>::parse(Domain::Xml::Pm& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSuspendToMem(m.get<0>().getValue());
		dst_.setSuspendToDisk(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Pm>::generate(const Domain::Xml::Pm& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSuspendToMem(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSuspendToDisk(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Event

namespace Domain
{
namespace Xml
{
Event::Event(): m_name(), m_enabled()
{
}

bool Event::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Event, Name::Strict<5054> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Event::save(QDomElement& dst_) const
{
	Element<Event, Name::Strict<5054> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Event::save(QDomDocument& dst_) const
{
	Element<Event, Name::Strict<5054> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Event>::parse(Domain::Xml::Event& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setEnabled(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Event>::generate(const Domain::Xml::Event& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEnabled(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Uid

namespace Domain
{
namespace Xml
{
Uid::Uid(): m_start(), m_target(), m_count()
{
}

bool Uid::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Uid, Name::Strict<321> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Uid::save(QDomElement& dst_) const
{
	Element<Uid, Name::Strict<321> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Uid::save(QDomDocument& dst_) const
{
	Element<Uid, Name::Strict<321> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Uid>::parse(Domain::Xml::Uid& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setStart(m.get<0>().getValue());
		dst_.setTarget(m.get<1>().getValue());
		dst_.setCount(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Uid>::generate(const Domain::Xml::Uid& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getStart(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCount(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Gid

namespace Domain
{
namespace Xml
{
Gid::Gid(): m_start(), m_target(), m_count()
{
}

bool Gid::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Gid, Name::Strict<325> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Gid::save(QDomElement& dst_) const
{
	Element<Gid, Name::Strict<325> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Gid::save(QDomDocument& dst_) const
{
	Element<Gid, Name::Strict<325> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Gid>::parse(Domain::Xml::Gid& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setStart(m.get<0>().getValue());
		dst_.setTarget(m.get<1>().getValue());
		dst_.setCount(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Gid>::generate(const Domain::Xml::Gid& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getStart(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCount(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Idmap

namespace Domain
{
namespace Xml
{
bool Idmap::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Idmap, Name::Strict<227> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Idmap::save(QDomElement& dst_) const
{
	Element<Idmap, Name::Strict<227> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Idmap::save(QDomDocument& dst_) const
{
	Element<Idmap, Name::Strict<227> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Idmap>::parse(Domain::Xml::Idmap& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setUidList(m.get<0>().getValue());
		dst_.setGidList(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Idmap>::generate(const Domain::Xml::Idmap& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getUidList(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGidList(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Disk7002

namespace Domain
{
namespace Xml
{
Disk7002::Disk7002(): m_device()
{
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Disk7002>::parse(Domain::Xml::Disk7002& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDevice(m.get<0>().getValue());
		dst_.setRawio(m.get<1>().getValue());
		dst_.setSgio(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Disk7002>::generate(const Domain::Xml::Disk7002& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDevice(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRawio(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSgio(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct DriverFormat

namespace Domain
{
namespace Xml
{
bool DriverFormat::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<DriverFormat>::parse(*this, k);
}

bool DriverFormat::save(QDomElement& dst_) const
{
	return 0 <= Traits<DriverFormat>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::DriverFormat>::parse(Domain::Xml::DriverFormat& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setType(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::DriverFormat>::generate(const Domain::Xml::DriverFormat& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct VirtioOptions

namespace Domain
{
namespace Xml
{
bool VirtioOptions::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<VirtioOptions, Name::Strict<546> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool VirtioOptions::save(QDomElement& dst_) const
{
	Element<VirtioOptions, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool VirtioOptions::save(QDomDocument& dst_) const
{
	Element<VirtioOptions, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::VirtioOptions>::parse(Domain::Xml::VirtioOptions& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setIommu(m.get<0>().getValue());
		dst_.setAts(m.get<1>().getValue());
		dst_.setPacked(m.get<2>().getValue());
		dst_.setPagePerVq(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::VirtioOptions>::generate(const Domain::Xml::VirtioOptions& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getIommu(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAts(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPacked(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPagePerVq(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct MetadataCache

namespace Domain
{
namespace Xml
{
bool MetadataCache::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<MetadataCache, Name::Strict<6546> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool MetadataCache::save(QDomElement& dst_) const
{
	Element<MetadataCache, Name::Strict<6546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool MetadataCache::save(QDomDocument& dst_) const
{
	Element<MetadataCache, Name::Strict<6546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::MetadataCache>::parse(Domain::Xml::MetadataCache& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setMaxSize(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::MetadataCache>::generate(const Domain::Xml::MetadataCache& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getMaxSize(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Driver

namespace Domain
{
namespace Xml
{
bool Driver::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Driver, Name::Strict<546> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Driver::save(QDomElement& dst_) const
{
	Element<Driver, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Driver::save(QDomDocument& dst_) const
{
	Element<Driver, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Driver>::parse(Domain::Xml::Driver& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDriverFormat(m.get<0>().getValue());
		dst_.setCache(m.get<1>().getValue());
		dst_.setErrorPolicy(m.get<2>().getValue());
		dst_.setRerrorPolicy(m.get<3>().getValue());
		dst_.setIo(m.get<4>().getValue());
		dst_.setIoeventfd(m.get<5>().getValue());
		dst_.setEventIdx(m.get<6>().getValue());
		dst_.setCopyOnRead(m.get<7>().getValue());
		dst_.setDiscard(m.get<8>().getValue());
		dst_.setIothread(m.get<9>().getValue());
		dst_.setDetectZeroes(m.get<10>().getValue());
		dst_.setQueues(m.get<11>().getValue());
		dst_.setQueueSize(m.get<12>().getValue());
		dst_.setVirtioOptions(m.get<13>().getValue());
		dst_.setMetadataCache(m.get<14>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Driver>::generate(const Domain::Xml::Driver& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDriverFormat(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCache(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getErrorPolicy(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRerrorPolicy(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIo(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIoeventfd(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEventIdx(), m.get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCopyOnRead(), m.get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDiscard(), m.get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIothread(), m.get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDetectZeroes(), m.get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getQueues(), m.get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getQueueSize(), m.get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVirtioOptions(), m.get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMetadataCache(), m.get<14>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct MetadataCache1

namespace Domain
{
namespace Xml
{
bool MetadataCache1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<MetadataCache1, Name::Strict<6546> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool MetadataCache1::save(QDomElement& dst_) const
{
	Element<MetadataCache1, Name::Strict<6546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool MetadataCache1::save(QDomDocument& dst_) const
{
	Element<MetadataCache1, Name::Strict<6546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::MetadataCache1>::parse(Domain::Xml::MetadataCache1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setMaxSize(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::MetadataCache1>::generate(const Domain::Xml::MetadataCache1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getMaxSize(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Format

namespace Domain
{
namespace Xml
{
bool Format::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Format, Name::Strict<146> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Format::save(QDomElement& dst_) const
{
	Element<Format, Name::Strict<146> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Format::save(QDomDocument& dst_) const
{
	Element<Format, Name::Strict<146> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Format>::parse(Domain::Xml::Format& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
		dst_.setMetadataCache(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Format>::generate(const Domain::Xml::Format& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMetadataCache(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous2358

namespace Domain
{
namespace Xml
{
bool Anonymous2358::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Anonymous2358>::parse(*this, k);
}

bool Anonymous2358::save(QDomElement& dst_) const
{
	return 0 <= Traits<Anonymous2358>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Anonymous2358>::parse(Domain::Xml::Anonymous2358& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSource(m.get<0>().get<1>().getValue());
		dst_.setFormat(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Anonymous2358>::generate(const Domain::Xml::Anonymous2358& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<0>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFormat(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Mirror4765

int Traits<Domain::Xml::Mirror4765>::parse(Domain::Xml::Mirror4765& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setFile(m.get<0>().getValue());
		dst_.setFormat(m.get<1>().getValue());
		dst_.setJob(m.get<2>().getValue());
		dst_.setAnonymous2358(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Mirror4765>::generate(const Domain::Xml::Mirror4765& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getFile(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFormat(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getJob(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAnonymous2358(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Mirror4766

namespace Domain
{
namespace Xml
{
Mirror4766::Mirror4766(): m_job()
{
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Mirror4766>::parse(Domain::Xml::Mirror4766& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setJob(m.get<0>().getValue());
		dst_.setDiskSource(m.get<1>().get<0>().getValue());
		dst_.setFormat(m.get<1>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Mirror4766>::generate(const Domain::Xml::Mirror4766& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getJob(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDiskSource(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFormat(), m.get<1>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Mirror

namespace Domain
{
namespace Xml
{
bool Mirror::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Mirror, Name::Strict<1088> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Mirror::save(QDomElement& dst_) const
{
	Element<Mirror, Name::Strict<1088> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Mirror::save(QDomDocument& dst_) const
{
	Element<Mirror, Name::Strict<1088> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Mirror>::parse(Domain::Xml::Mirror& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setMirror(m.get<0>().getValue());
		dst_.setReady(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Mirror>::generate(const Domain::Xml::Mirror& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getMirror(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getReady(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Secret

namespace Domain
{
namespace Xml
{
Secret::Secret(): m_type()
{
}

bool Secret::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Secret, Name::Strict<149> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Secret::save(QDomElement& dst_) const
{
	Element<Secret, Name::Strict<149> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Secret::save(QDomDocument& dst_) const
{
	Element<Secret, Name::Strict<149> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Secret>::parse(Domain::Xml::Secret& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
		dst_.setSecret(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Secret>::generate(const Domain::Xml::Secret& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSecret(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Auth

namespace Domain
{
namespace Xml
{
bool Auth::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Auth, Name::Strict<1097> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Auth::save(QDomElement& dst_) const
{
	Element<Auth, Name::Strict<1097> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Auth::save(QDomDocument& dst_) const
{
	Element<Auth, Name::Strict<1097> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Auth>::parse(Domain::Xml::Auth& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setUsername(m.get<0>().getValue());
		dst_.setSecret(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Auth>::generate(const Domain::Xml::Auth& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getUsername(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSecret(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Target

namespace Domain
{
namespace Xml
{
bool Target::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Target, Name::Strict<323> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Target::save(QDomElement& dst_) const
{
	Element<Target, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Target::save(QDomDocument& dst_) const
{
	Element<Target, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Target>::parse(Domain::Xml::Target& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDev(m.get<0>().getValue());
		dst_.setBus(m.get<1>().getValue());
		dst_.setTray(m.get<2>().getValue());
		dst_.setRemovable(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Target>::generate(const Domain::Xml::Target& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDev(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBus(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTray(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRemovable(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Boot

namespace Domain
{
namespace Xml
{
Boot::Boot(): m_order()
{
}

bool Boot::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Boot, Name::Strict<407> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Boot::save(QDomElement& dst_) const
{
	Element<Boot, Name::Strict<407> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Boot::save(QDomDocument& dst_) const
{
	Element<Boot, Name::Strict<407> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Boot>::parse(Domain::Xml::Boot& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setOrder(m.get<0>().getValue());
		dst_.setLoadparm(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Boot>::generate(const Domain::Xml::Boot& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getOrder(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLoadparm(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Transient

namespace Domain
{
namespace Xml
{
bool Transient::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Transient, Name::Strict<452> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Transient::save(QDomElement& dst_) const
{
	Element<Transient, Name::Strict<452> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Transient::save(QDomDocument& dst_) const
{
	Element<Transient, Name::Strict<452> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Transient>::parse(Domain::Xml::Transient& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setShareBacking(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Transient>::generate(const Domain::Xml::Transient& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getShareBacking(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Variant4770

int Traits<Domain::Xml::Variant4770>::parse(Domain::Xml::Variant4770& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setReadBytesSec(m.get<0>().get<0>().getValue());
		dst_.setWriteBytesSec(m.get<0>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Variant4770>::generate(const Domain::Xml::Variant4770& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getReadBytesSec(), m.get<0>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getWriteBytesSec(), m.get<0>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Variant4773

int Traits<Domain::Xml::Variant4773>::parse(Domain::Xml::Variant4773& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setReadIopsSec(m.get<0>().get<0>().getValue());
		dst_.setWriteIopsSec(m.get<0>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Variant4773>::generate(const Domain::Xml::Variant4773& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getReadIopsSec(), m.get<0>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getWriteIopsSec(), m.get<0>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Iotune

namespace Domain
{
namespace Xml
{
bool Iotune::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Iotune, Name::Strict<1103> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Iotune::save(QDomElement& dst_) const
{
	Element<Iotune, Name::Strict<1103> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Iotune::save(QDomDocument& dst_) const
{
	Element<Iotune, Name::Strict<1103> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Iotune>::parse(Domain::Xml::Iotune& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setChoice4771(m.get<0>().getValue());
		dst_.setChoice4774(m.get<1>().getValue());
		dst_.setSizeIopsSec(m.get<2>().getValue());
		dst_.setGroupName(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Iotune>::generate(const Domain::Xml::Iotune& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getChoice4771(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChoice4774(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSizeIopsSec(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGroupName(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Pciaddress

namespace Domain
{
namespace Xml
{
bool Pciaddress::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Pciaddress, Name::Strict<111> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Pciaddress::save(QDomElement& dst_) const
{
	Element<Pciaddress, Name::Strict<111> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Pciaddress::save(QDomDocument& dst_) const
{
	Element<Pciaddress, Name::Strict<111> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Pciaddress>::parse(Domain::Xml::Pciaddress& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDomain(m.get<0>().getValue());
		dst_.setBus(m.get<1>().getValue());
		dst_.setSlot(m.get<2>().getValue());
		dst_.setFunction(m.get<3>().getValue());
		dst_.setMultifunction(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Pciaddress>::generate(const Domain::Xml::Pciaddress& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDomain(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBus(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSlot(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFunction(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMultifunction(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Driveaddress

namespace Domain
{
namespace Xml
{
bool Driveaddress::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Driveaddress>::parse(*this, k);
}

bool Driveaddress::save(QDomElement& dst_) const
{
	return 0 <= Traits<Driveaddress>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Driveaddress>::parse(Domain::Xml::Driveaddress& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setController(m.get<0>().getValue());
		dst_.setBus(m.get<1>().getValue());
		dst_.setTarget(m.get<2>().getValue());
		dst_.setUnit(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Driveaddress>::generate(const Domain::Xml::Driveaddress& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getController(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBus(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getUnit(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Virtioserialaddress

namespace Domain
{
namespace Xml
{
bool Virtioserialaddress::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Virtioserialaddress>::parse(*this, k);
}

bool Virtioserialaddress::save(QDomElement& dst_) const
{
	return 0 <= Traits<Virtioserialaddress>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Virtioserialaddress>::parse(Domain::Xml::Virtioserialaddress& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setController(m.get<0>().getValue());
		dst_.setBus(m.get<1>().getValue());
		dst_.setPort(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Virtioserialaddress>::generate(const Domain::Xml::Virtioserialaddress& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getController(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBus(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Ccidaddress

namespace Domain
{
namespace Xml
{
bool Ccidaddress::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Ccidaddress>::parse(*this, k);
}

bool Ccidaddress::save(QDomElement& dst_) const
{
	return 0 <= Traits<Ccidaddress>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Ccidaddress>::parse(Domain::Xml::Ccidaddress& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setController(m.get<0>().getValue());
		dst_.setSlot(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Ccidaddress>::generate(const Domain::Xml::Ccidaddress& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getController(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSlot(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Usbportaddress

namespace Domain
{
namespace Xml
{
bool Usbportaddress::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Usbportaddress>::parse(*this, k);
}

bool Usbportaddress::save(QDomElement& dst_) const
{
	return 0 <= Traits<Usbportaddress>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Usbportaddress>::parse(Domain::Xml::Usbportaddress& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setBus(m.get<0>().getValue());
		dst_.setPort(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Usbportaddress>::generate(const Domain::Xml::Usbportaddress& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getBus(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous9190

namespace Domain
{
namespace Xml
{
bool Anonymous9190::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Anonymous9190>::parse(*this, k);
}

bool Anonymous9190::save(QDomElement& dst_) const
{
	return 0 <= Traits<Anonymous9190>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Anonymous9190>::parse(Domain::Xml::Anonymous9190& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setCssid(m.get<0>().getValue());
		dst_.setSsid(m.get<1>().getValue());
		dst_.setDevno(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Anonymous9190>::generate(const Domain::Xml::Anonymous9190& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getCssid(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSsid(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDevno(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Isaaddress

namespace Domain
{
namespace Xml
{
bool Isaaddress::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Isaaddress>::parse(*this, k);
}

bool Isaaddress::save(QDomElement& dst_) const
{
	return 0 <= Traits<Isaaddress>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Isaaddress>::parse(Domain::Xml::Isaaddress& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setIobase(m.get<0>().getValue());
		dst_.setIrq(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Isaaddress>::generate(const Domain::Xml::Isaaddress& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getIobase(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIrq(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Dimmaddress

namespace Domain
{
namespace Xml
{
bool Dimmaddress::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Dimmaddress>::parse(*this, k);
}

bool Dimmaddress::save(QDomElement& dst_) const
{
	return 0 <= Traits<Dimmaddress>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Dimmaddress>::parse(Domain::Xml::Dimmaddress& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSlot(m.get<0>().getValue());
		dst_.setBase(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Dimmaddress>::generate(const Domain::Xml::Dimmaddress& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSlot(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBase(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Geometry

namespace Domain
{
namespace Xml
{
Geometry::Geometry(): m_cyls(), m_heads(), m_secs()
{
}

bool Geometry::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Geometry, Name::Strict<457> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Geometry::save(QDomElement& dst_) const
{
	Element<Geometry, Name::Strict<457> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Geometry::save(QDomDocument& dst_) const
{
	Element<Geometry, Name::Strict<457> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Geometry>::parse(Domain::Xml::Geometry& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setCyls(m.get<0>().getValue());
		dst_.setHeads(m.get<1>().getValue());
		dst_.setSecs(m.get<2>().getValue());
		dst_.setTrans(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Geometry>::generate(const Domain::Xml::Geometry& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getCyls(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHeads(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSecs(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTrans(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Blockio

namespace Domain
{
namespace Xml
{
bool Blockio::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Blockio, Name::Strict<543> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Blockio::save(QDomElement& dst_) const
{
	Element<Blockio, Name::Strict<543> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Blockio::save(QDomDocument& dst_) const
{
	Element<Blockio, Name::Strict<543> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Blockio>::parse(Domain::Xml::Blockio& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setLogicalBlockSize(m.get<0>().getValue());
		dst_.setPhysicalBlockSize(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Blockio>::generate(const Domain::Xml::Blockio& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getLogicalBlockSize(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPhysicalBlockSize(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct BackingStore

namespace Domain
{
namespace Xml
{

const VDiskBackingChainBin* BackingStore::getDiskBackingChain() const
{
	if (m_diskBackingChain.empty())
		return NULL;

	return boost::any_cast<VDiskBackingChainBin >(&m_diskBackingChain);
}

void BackingStore::setDiskBackingChain(const VDiskBackingChainBin& value_)
{
	m_diskBackingChain = value_;
}

bool BackingStore::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<BackingStore, Name::Strict<487> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool BackingStore::save(QDomElement& dst_) const
{
	Element<BackingStore, Name::Strict<487> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool BackingStore::save(QDomDocument& dst_) const
{
	Element<BackingStore, Name::Strict<487> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::BackingStore>::parse(Domain::Xml::BackingStore& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setIndex(m.get<0>().getValue());
		dst_.setDiskSource(m.get<1>().get<0>().getValue());
		Domain::Xml::VDiskBackingChainBin b;
		b.value = m.get<1>().get<1>().getValue();
		dst_.setDiskBackingChain(b);
		dst_.setFormat(m.get<1>().get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::BackingStore>::generate(const Domain::Xml::BackingStore& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getIndex(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDiskSource(), m.get<1>().get<0>()))
		return -1;
	const Domain::Xml::VDiskBackingChain* d = NULL;
	const Domain::Xml::VDiskBackingChainBin* v = src_.getDiskBackingChain();
	if (NULL != v)
		d = &v->value;
	if (NULL == d)
		return -1;
	if (0 > Details::Marshal::assign(*d, m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFormat(), m.get<1>().get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Disk

namespace Domain
{
namespace Xml
{
Disk::Disk(): m_readonly(), m_shareable()
{
}

bool Disk::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Disk, Name::Strict<472> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Disk::save(QDomElement& dst_) const
{
	Element<Disk, Name::Strict<472> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Disk::save(QDomDocument& dst_) const
{
	Element<Disk, Name::Strict<472> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Disk>::parse(Domain::Xml::Disk& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDisk(m.get<0>().getValue());
		dst_.setSnapshot(m.get<1>().getValue());
		dst_.setDiskSource(m.get<2>().get<0>().getValue());
		dst_.setDriver(m.get<2>().get<1>().getValue());
		dst_.setMirror(m.get<2>().get<2>().getValue());
		dst_.setAuth(m.get<2>().get<3>().getValue());
		dst_.setTarget(m.get<2>().get<4>().getValue());
		dst_.setBoot(m.get<2>().get<5>().getValue());
		dst_.setBackenddomain(m.get<2>().get<6>().getValue());
		dst_.setReadonly(m.get<2>().get<7>().getValue());
		dst_.setShareable(m.get<2>().get<8>().getValue());
		dst_.setTransient(m.get<2>().get<9>().getValue());
		dst_.setSerial(m.get<2>().get<10>().getValue());
		dst_.setEncryption(m.get<2>().get<11>().getValue());
		dst_.setIotune(m.get<2>().get<12>().getValue());
		dst_.setAlias(m.get<2>().get<13>().getValue());
		dst_.setAddress(m.get<2>().get<14>().getValue());
		dst_.setGeometry(m.get<2>().get<15>().getValue());
		dst_.setBlockio(m.get<2>().get<16>().getValue());
		dst_.setWwn(m.get<2>().get<17>().getValue());
		dst_.setVendor(m.get<2>().get<18>().getValue());
		dst_.setProduct(m.get<2>().get<19>().getValue());
		dst_.setXCheckpointList(m.get<2>().get<20>().getValue());
		dst_.setDiskBackingChain(m.get<2>().get<21>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Disk>::generate(const Domain::Xml::Disk& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDisk(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSnapshot(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDiskSource(), m.get<2>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<2>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMirror(), m.get<2>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAuth(), m.get<2>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<2>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBoot(), m.get<2>().get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackenddomain(), m.get<2>().get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getReadonly(), m.get<2>().get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getShareable(), m.get<2>().get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTransient(), m.get<2>().get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSerial(), m.get<2>().get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEncryption(), m.get<2>().get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIotune(), m.get<2>().get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<2>().get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<2>().get<14>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGeometry(), m.get<2>().get<15>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBlockio(), m.get<2>().get<16>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getWwn(), m.get<2>().get<17>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVendor(), m.get<2>().get<18>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getProduct(), m.get<2>().get<19>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getXCheckpointList(), m.get<2>().get<20>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDiskBackingChain(), m.get<2>().get<21>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Acpi

namespace Domain
{
namespace Xml
{
bool Acpi::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Acpi, Name::Strict<993> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Acpi::save(QDomElement& dst_) const
{
	Element<Acpi, Name::Strict<993> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Acpi::save(QDomDocument& dst_) const
{
	Element<Acpi, Name::Strict<993> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Acpi>::parse(Domain::Xml::Acpi& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setIndex(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Acpi>::generate(const Domain::Xml::Acpi& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getIndex(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Variant5121

int Traits<Domain::Xml::Variant5121>::parse(Domain::Xml::Variant5121& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<1>().getValue());
		dst_.setMaster(m.get<2>().getValue());
		dst_.setPorts(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Variant5121>::generate(const Domain::Xml::Variant5121& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMaster(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPorts(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Variant7013

int Traits<Domain::Xml::Variant7013>::parse(Domain::Xml::Variant7013& , QStack<QDomElement>& stack_)
{
	marshal_type m;
	return m.consume(stack_);
}

int Traits<Domain::Xml::Variant7013>::generate(const Domain::Xml::Variant7013& , QDomElement& dst_)
{
	marshal_type m;
	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Target1

namespace Domain
{
namespace Xml
{
bool Target1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Target1, Name::Strict<323> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Target1::save(QDomElement& dst_) const
{
	Element<Target1, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Target1::save(QDomDocument& dst_) const
{
	Element<Target1, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Target1>::parse(Domain::Xml::Target1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setChassisNr(m.get<0>().getValue());
		dst_.setChassis(m.get<1>().getValue());
		dst_.setPort(m.get<2>().getValue());
		dst_.setBusNr(m.get<3>().getValue());
		dst_.setIndex(m.get<4>().getValue());
		dst_.setHotplug(m.get<5>().getValue());
		dst_.setNode(m.get<6>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Target1>::generate(const Domain::Xml::Target1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getChassisNr(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChassis(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBusNr(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIndex(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHotplug(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNode(), m.get<6>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Variant7014

namespace Domain
{
namespace Xml
{
Variant7014::Variant7014(): m_model()
{
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Variant7014>::parse(Domain::Xml::Variant7014& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<0>().getValue());
		dst_.setPcihole64(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Variant7014>::generate(const Domain::Xml::Variant7014& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPcihole64(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Variant8014

int Traits<Domain::Xml::Variant8014>::parse(Domain::Xml::Variant8014& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<1>().getValue());
		dst_.setTarget(m.get<2>().getValue());
		dst_.setChoice2355(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Variant8014>::generate(const Domain::Xml::Variant8014& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChoice2355(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Variant9522

int Traits<Domain::Xml::Variant9522>::parse(Domain::Xml::Variant9522& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<1>().getValue());
		dst_.setPorts(m.get<2>().getValue());
		dst_.setVectors(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Variant9522>::generate(const Domain::Xml::Variant9522& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPorts(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVectors(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Variant8018

int Traits<Domain::Xml::Variant8018>::parse(Domain::Xml::Variant8018& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setMaxGrantFrames(m.get<1>().getValue());
		dst_.setMaxEventChannels(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Variant8018>::generate(const Domain::Xml::Variant8018& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getMaxGrantFrames(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMaxEventChannels(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Driver1

namespace Domain
{
namespace Xml
{
bool Driver1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Driver1, Name::Strict<546> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Driver1::save(QDomElement& dst_) const
{
	Element<Driver1, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Driver1::save(QDomDocument& dst_) const
{
	Element<Driver1, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Driver1>::parse(Domain::Xml::Driver1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setQueues(m.get<0>().getValue());
		dst_.setCmdPerLun(m.get<1>().getValue());
		dst_.setMaxSectors(m.get<2>().getValue());
		dst_.setIoeventfd(m.get<3>().getValue());
		dst_.setIothread(m.get<4>().getValue());
		dst_.setVirtioOptions(m.get<5>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Driver1>::generate(const Domain::Xml::Driver1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getQueues(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCmdPerLun(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMaxSectors(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIoeventfd(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIothread(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVirtioOptions(), m.get<5>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Controller

namespace Domain
{
namespace Xml
{
bool Controller::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Controller, Name::Strict<572> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Controller::save(QDomElement& dst_) const
{
	Element<Controller, Name::Strict<572> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Controller::save(QDomDocument& dst_) const
{
	Element<Controller, Name::Strict<572> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Controller>::parse(Domain::Xml::Controller& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setIndex(m.get<0>().getValue());
		dst_.setAlias(m.get<1>().get<0>().getValue());
		dst_.setAcpi(m.get<1>().get<1>().getValue());
		dst_.setAddress(m.get<1>().get<2>().getValue());
		dst_.setChoice5123(m.get<1>().get<3>().getValue());
		dst_.setDriver(m.get<1>().get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Controller>::generate(const Domain::Xml::Controller& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getIndex(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChoice5123(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>().get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Target2

namespace Domain
{
namespace Xml
{
bool Target2::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Target2, Name::Strict<323> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Target2::save(QDomElement& dst_) const
{
	Element<Target2, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Target2::save(QDomDocument& dst_) const
{
	Element<Target2, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Target2>::parse(Domain::Xml::Target2& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setPath(m.get<0>().getValue());
		dst_.setOffset(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Target2>::generate(const Domain::Xml::Target2& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getPath(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOffset(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Lease

namespace Domain
{
namespace Xml
{
bool Lease::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Lease, Name::Strict<465> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Lease::save(QDomElement& dst_) const
{
	Element<Lease, Name::Strict<465> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Lease::save(QDomDocument& dst_) const
{
	Element<Lease, Name::Strict<465> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Lease>::parse(Domain::Xml::Lease& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setLockspace(m.get<0>().getValue());
		dst_.setKey(m.get<1>().getValue());
		dst_.setTarget(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Lease>::generate(const Domain::Xml::Lease& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getLockspace(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getKey(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Driver2

namespace Domain
{
namespace Xml
{
bool Driver2::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Driver2, Name::Strict<546> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Driver2::save(QDomElement& dst_) const
{
	Element<Driver2, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Driver2::save(QDomDocument& dst_) const
{
	Element<Driver2, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Driver2>::parse(Domain::Xml::Driver2& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
		dst_.setFormat(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Driver2>::generate(const Domain::Xml::Driver2& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFormat(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7016

int Traits<Domain::Xml::Filesystem7016>::parse(Domain::Xml::Filesystem7016& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDriver(m.get<1>().getValue());
		dst_.setSource(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Filesystem7016>::generate(const Domain::Xml::Filesystem7016& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7017

int Traits<Domain::Xml::Filesystem7017>::parse(Domain::Xml::Filesystem7017& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDriver(m.get<1>().getValue());
		dst_.setSource(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Filesystem7017>::generate(const Domain::Xml::Filesystem7017& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7018

int Traits<Domain::Xml::Filesystem7018>::parse(Domain::Xml::Filesystem7018& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDriver(m.get<1>().getValue());
		dst_.setSource(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Filesystem7018>::generate(const Domain::Xml::Filesystem7018& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7019

int Traits<Domain::Xml::Filesystem7019>::parse(Domain::Xml::Filesystem7019& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDriver(m.get<1>().getValue());
		dst_.setSource(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Filesystem7019>::generate(const Domain::Xml::Filesystem7019& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7020

int Traits<Domain::Xml::Filesystem7020>::parse(Domain::Xml::Filesystem7020& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDriver(m.get<1>().getValue());
		dst_.setSource(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Filesystem7020>::generate(const Domain::Xml::Filesystem7020& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source5

namespace Domain
{
namespace Xml
{
Source5::Source5(): m_usage()
{
}

bool Source5::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source5, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source5::save(QDomElement& dst_) const
{
	Element<Source5, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source5::save(QDomDocument& dst_) const
{
	Element<Source5, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source5>::parse(Domain::Xml::Source5& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setUsage(m.get<0>().getValue());
		dst_.setUnits(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source5>::generate(const Domain::Xml::Source5& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getUsage(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getUnits(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem7021

int Traits<Domain::Xml::Filesystem7021>::parse(Domain::Xml::Filesystem7021& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDriver(m.get<1>().getValue());
		dst_.setSource(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Filesystem7021>::generate(const Domain::Xml::Filesystem7021& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Filesystem

namespace Domain
{
namespace Xml
{
Filesystem::Filesystem(): m_readonly()
{
}

bool Filesystem::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Filesystem, Name::Strict<630> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Filesystem::save(QDomElement& dst_) const
{
	Element<Filesystem, Name::Strict<630> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Filesystem::save(QDomDocument& dst_) const
{
	Element<Filesystem, Name::Strict<630> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Filesystem>::parse(Domain::Xml::Filesystem& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setFilesystem(m.get<0>().getValue());
		dst_.setTarget(m.get<1>().get<0>().getValue());
		dst_.setAccessmode(m.get<1>().get<1>().getValue());
		dst_.setMultidevs(m.get<1>().get<2>().getValue());
		dst_.setFmode(m.get<1>().get<3>().getValue());
		dst_.setDmode(m.get<1>().get<4>().getValue());
		dst_.setReadonly(m.get<1>().get<5>().getValue());
		dst_.setBoot(m.get<1>().get<6>().getValue());
		dst_.setAlias(m.get<1>().get<7>().getValue());
		dst_.setAcpi(m.get<1>().get<8>().getValue());
		dst_.setAddress(m.get<1>().get<9>().getValue());
		dst_.setSpaceHardLimit(m.get<2>().get<0>().getValue());
		dst_.setSpaceSoftLimit(m.get<2>().get<1>().getValue());
		dst_.setModel(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Filesystem>::generate(const Domain::Xml::Filesystem& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getFilesystem(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAccessmode(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMultidevs(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFmode(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDmode(), m.get<1>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getReadonly(), m.get<1>().get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBoot(), m.get<1>().get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>().get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSpaceHardLimit(), m.get<2>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSpaceSoftLimit(), m.get<2>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct InterfaceBridgeAttributes

namespace Domain
{
namespace Xml
{
bool InterfaceBridgeAttributes::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<InterfaceBridgeAttributes>::parse(*this, k);
}

bool InterfaceBridgeAttributes::save(QDomElement& dst_) const
{
	return 0 <= Traits<InterfaceBridgeAttributes>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::InterfaceBridgeAttributes>::parse(Domain::Xml::InterfaceBridgeAttributes& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setBridge(m.get<0>().getValue());
		dst_.setMacTableManager(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::InterfaceBridgeAttributes>::generate(const Domain::Xml::InterfaceBridgeAttributes& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getBridge(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMacTableManager(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct InterfaceNetworkAttributes

namespace Domain
{
namespace Xml
{
bool InterfaceNetworkAttributes::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<InterfaceNetworkAttributes>::parse(*this, k);
}

bool InterfaceNetworkAttributes::save(QDomElement& dst_) const
{
	return 0 <= Traits<InterfaceNetworkAttributes>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::InterfaceNetworkAttributes>::parse(Domain::Xml::InterfaceNetworkAttributes& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setNetwork(m.get<0>().getValue());
		dst_.setPortgroup(m.get<1>().getValue());
		dst_.setPortid(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::InterfaceNetworkAttributes>::generate(const Domain::Xml::InterfaceNetworkAttributes& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getNetwork(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPortgroup(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPortid(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source6

namespace Domain
{
namespace Xml
{
bool Source6::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source6, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source6::save(QDomElement& dst_) const
{
	Element<Source6, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source6::save(QDomDocument& dst_) const
{
	Element<Source6, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source6>::parse(Domain::Xml::Source6& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setInterfaceBridgeAttributes(m.get<0>().getValue());
		dst_.setInterfaceNetworkAttributes(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source6>::generate(const Domain::Xml::Source6& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getInterfaceBridgeAttributes(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInterfaceNetworkAttributes(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Parameters

namespace Domain
{
namespace Xml
{
bool Parameters::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Parameters, Name::Strict<180> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Parameters::save(QDomElement& dst_) const
{
	Element<Parameters, Name::Strict<180> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Parameters::save(QDomDocument& dst_) const
{
	Element<Parameters, Name::Strict<180> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Parameters>::parse(Domain::Xml::Parameters& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setManagerid(m.get<0>().getValue());
		dst_.setTypeid(m.get<1>().getValue());
		dst_.setTypeidversion(m.get<2>().getValue());
		dst_.setInstanceid(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Parameters>::generate(const Domain::Xml::Parameters& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getManagerid(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTypeid(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTypeidversion(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInstanceid(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Parameters1

namespace Domain
{
namespace Xml
{
bool Parameters1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Parameters1, Name::Strict<180> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Parameters1::save(QDomElement& dst_) const
{
	Element<Parameters1, Name::Strict<180> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Parameters1::save(QDomDocument& dst_) const
{
	Element<Parameters1, Name::Strict<180> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Parameters1>::parse(Domain::Xml::Parameters1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setProfileid(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Parameters1>::generate(const Domain::Xml::Parameters1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getProfileid(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Parameters2

namespace Domain
{
namespace Xml
{
bool Parameters2::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Parameters2, Name::Strict<180> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Parameters2::save(QDomElement& dst_) const
{
	Element<Parameters2, Name::Strict<180> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Parameters2::save(QDomDocument& dst_) const
{
	Element<Parameters2, Name::Strict<180> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Parameters2>::parse(Domain::Xml::Parameters2& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setProfileid(m.get<0>().getValue());
		dst_.setInterfaceid(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Parameters2>::generate(const Domain::Xml::Parameters2& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getProfileid(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInterfaceid(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Parameters3

namespace Domain
{
namespace Xml
{
bool Parameters3::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Parameters3, Name::Strict<180> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Parameters3::save(QDomElement& dst_) const
{
	Element<Parameters3, Name::Strict<180> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Parameters3::save(QDomDocument& dst_) const
{
	Element<Parameters3, Name::Strict<180> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Parameters3>::parse(Domain::Xml::Parameters3& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setManagerid(m.get<0>().getValue());
		dst_.setTypeid(m.get<1>().getValue());
		dst_.setTypeidversion(m.get<2>().getValue());
		dst_.setInstanceid(m.get<3>().getValue());
		dst_.setProfileid(m.get<4>().getValue());
		dst_.setInterfaceid(m.get<5>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Parameters3>::generate(const Domain::Xml::Parameters3& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getManagerid(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTypeid(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTypeidversion(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInstanceid(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getProfileid(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInterfaceid(), m.get<5>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Virtualport

namespace Domain
{
namespace Xml
{
bool Virtualport::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Virtualport, Name::Strict<178> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Virtualport::save(QDomElement& dst_) const
{
	Element<Virtualport, Name::Strict<178> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Virtualport::save(QDomDocument& dst_) const
{
	Element<Virtualport, Name::Strict<178> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Virtualport>::parse(Domain::Xml::Virtualport& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setParameters(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Virtualport>::generate(const Domain::Xml::Virtualport& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getParameters(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Frames

namespace Domain
{
namespace Xml
{
bool Frames::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Frames, Name::Strict<9430> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Frames::save(QDomElement& dst_) const
{
	Element<Frames, Name::Strict<9430> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Frames::save(QDomDocument& dst_) const
{
	Element<Frames, Name::Strict<9430> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Frames>::parse(Domain::Xml::Frames& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setMax(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Frames>::generate(const Domain::Xml::Frames& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getMax(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Rx

namespace Domain
{
namespace Xml
{
bool Rx::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Rx, Name::Strict<9429> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Rx::save(QDomElement& dst_) const
{
	Element<Rx, Name::Strict<9429> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Rx::save(QDomDocument& dst_) const
{
	Element<Rx, Name::Strict<9429> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Rx>::parse(Domain::Xml::Rx& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setFrames(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Rx>::generate(const Domain::Xml::Rx& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getFrames(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Coalesce

namespace Domain
{
namespace Xml
{
bool Coalesce::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Coalesce, Name::Strict<9382> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Coalesce::save(QDomElement& dst_) const
{
	Element<Coalesce, Name::Strict<9382> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Coalesce::save(QDomDocument& dst_) const
{
	Element<Coalesce, Name::Strict<9382> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Coalesce>::parse(Domain::Xml::Coalesce& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setRx(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Coalesce>::generate(const Domain::Xml::Coalesce& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getRx(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct VzDhcp

namespace Domain
{
namespace Xml
{
bool VzDhcp::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<VzDhcp, Name::Strict<5704> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool VzDhcp::save(QDomElement& dst_) const
{
	Element<VzDhcp, Name::Strict<5704> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool VzDhcp::save(QDomDocument& dst_) const
{
	Element<VzDhcp, Name::Strict<5704> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::VzDhcp>::parse(Domain::Xml::VzDhcp& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setFamily(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::VzDhcp>::generate(const Domain::Xml::VzDhcp& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getFamily(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct VzDns1

namespace Domain
{
namespace Xml
{
bool VzDns1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<VzDns1, Name::Strict<5706> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool VzDns1::save(QDomElement& dst_) const
{
	Element<VzDns1, Name::Strict<5706> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool VzDns1::save(QDomDocument& dst_) const
{
	Element<VzDns1, Name::Strict<5706> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::VzDns1>::parse(Domain::Xml::VzDns1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setServerList(m.get<0>().getValue());
		dst_.setSearchList(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::VzDns1>::generate(const Domain::Xml::VzDns1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getServerList(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSearchList(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Target3

namespace Domain
{
namespace Xml
{
bool Target3::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Target3, Name::Strict<323> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Target3::save(QDomElement& dst_) const
{
	Element<Target3, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Target3::save(QDomDocument& dst_) const
{
	Element<Target3, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Target3>::parse(Domain::Xml::Target3& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDev(m.get<0>().getValue());
		dst_.setManaged(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Target3>::generate(const Domain::Xml::Target3& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDev(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getManaged(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Guest

namespace Domain
{
namespace Xml
{
bool Guest::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Guest, Name::Strict<408> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Guest::save(QDomElement& dst_) const
{
	Element<Guest, Name::Strict<408> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Guest::save(QDomDocument& dst_) const
{
	Element<Guest, Name::Strict<408> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Guest>::parse(Domain::Xml::Guest& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDev(m.get<0>().getValue());
		dst_.setActual(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Guest>::generate(const Domain::Xml::Guest& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDev(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getActual(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Ip

namespace Domain
{
namespace Xml
{
bool Ip::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Ip, Name::Strict<689> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Ip::save(QDomElement& dst_) const
{
	Element<Ip, Name::Strict<689> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Ip::save(QDomDocument& dst_) const
{
	Element<Ip, Name::Strict<689> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Ip>::parse(Domain::Xml::Ip& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAddress(m.get<0>().getValue());
		dst_.setFamily(m.get<1>().getValue());
		dst_.setPrefix(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Ip>::generate(const Domain::Xml::Ip& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFamily(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPrefix(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Route

namespace Domain
{
namespace Xml
{
bool Route::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Route, Name::Strict<1230> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Route::save(QDomElement& dst_) const
{
	Element<Route, Name::Strict<1230> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Route::save(QDomDocument& dst_) const
{
	Element<Route, Name::Strict<1230> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Route>::parse(Domain::Xml::Route& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setFamily(m.get<0>().getValue());
		dst_.setAddress(m.get<1>().getValue());
		dst_.setChoice7116(m.get<2>().getValue());
		dst_.setGateway(m.get<3>().getValue());
		dst_.setMetric(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Route>::generate(const Domain::Xml::Route& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getFamily(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChoice7116(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGateway(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMetric(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Backend

namespace Domain
{
namespace Xml
{
bool Backend::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Backend, Name::Strict<693> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Backend::save(QDomElement& dst_) const
{
	Element<Backend, Name::Strict<693> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Backend::save(QDomDocument& dst_) const
{
	Element<Backend, Name::Strict<693> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Backend>::parse(Domain::Xml::Backend& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setTap(m.get<0>().getValue());
		dst_.setVhost(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Backend>::generate(const Domain::Xml::Backend& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getTap(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVhost(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Driver7037

int Traits<Domain::Xml::Driver7037>::parse(Domain::Xml::Driver7037& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setQueues(m.get<1>().getValue());
		dst_.setRxQueueSize(m.get<2>().getValue());
		dst_.setTxQueueSize(m.get<3>().getValue());
		dst_.setTxmode(m.get<4>().getValue());
		dst_.setIoeventfd(m.get<5>().getValue());
		dst_.setEventIdx(m.get<6>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Driver7037>::generate(const Domain::Xml::Driver7037& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getQueues(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRxQueueSize(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTxQueueSize(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTxmode(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIoeventfd(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEventIdx(), m.get<6>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Host

namespace Domain
{
namespace Xml
{
bool Host::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Host, Name::Strict<513> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Host::save(QDomElement& dst_) const
{
	Element<Host, Name::Strict<513> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Host::save(QDomDocument& dst_) const
{
	Element<Host, Name::Strict<513> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Host>::parse(Domain::Xml::Host& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setCsum(m.get<0>().getValue());
		dst_.setGso(m.get<1>().getValue());
		dst_.setTso4(m.get<2>().getValue());
		dst_.setTso6(m.get<3>().getValue());
		dst_.setEcn(m.get<4>().getValue());
		dst_.setUfo(m.get<5>().getValue());
		dst_.setMrgRxbuf(m.get<6>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Host>::generate(const Domain::Xml::Host& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getCsum(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGso(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTso4(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTso6(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEcn(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getUfo(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMrgRxbuf(), m.get<6>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Guest1

namespace Domain
{
namespace Xml
{
bool Guest1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Guest1, Name::Strict<408> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Guest1::save(QDomElement& dst_) const
{
	Element<Guest1, Name::Strict<408> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Guest1::save(QDomDocument& dst_) const
{
	Element<Guest1, Name::Strict<408> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Guest1>::parse(Domain::Xml::Guest1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setCsum(m.get<0>().getValue());
		dst_.setTso4(m.get<1>().getValue());
		dst_.setTso6(m.get<2>().getValue());
		dst_.setEcn(m.get<3>().getValue());
		dst_.setUfo(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Guest1>::generate(const Domain::Xml::Guest1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getCsum(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTso4(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTso6(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEcn(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getUfo(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Driver3

namespace Domain
{
namespace Xml
{
bool Driver3::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Driver3, Name::Strict<546> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Driver3::save(QDomElement& dst_) const
{
	Element<Driver3, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Driver3::save(QDomDocument& dst_) const
{
	Element<Driver3, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Driver3>::parse(Domain::Xml::Driver3& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDriver(m.get<0>().getValue());
		dst_.setHost(m.get<1>().get<0>().getValue());
		dst_.setGuest(m.get<1>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Driver3>::generate(const Domain::Xml::Driver3& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHost(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGuest(), m.get<1>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Parameter

namespace Domain
{
namespace Xml
{
bool Parameter::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Parameter, Name::Strict<1084> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Parameter::save(QDomElement& dst_) const
{
	Element<Parameter, Name::Strict<1084> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Parameter::save(QDomDocument& dst_) const
{
	Element<Parameter, Name::Strict<1084> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Parameter>::parse(Domain::Xml::Parameter& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setValue(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Parameter>::generate(const Domain::Xml::Parameter& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getValue(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct FilterrefNodeAttributes

namespace Domain
{
namespace Xml
{
bool FilterrefNodeAttributes::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<FilterrefNodeAttributes, Name::Strict<706> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool FilterrefNodeAttributes::save(QDomElement& dst_) const
{
	Element<FilterrefNodeAttributes, Name::Strict<706> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool FilterrefNodeAttributes::save(QDomDocument& dst_) const
{
	Element<FilterrefNodeAttributes, Name::Strict<706> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::FilterrefNodeAttributes>::parse(Domain::Xml::FilterrefNodeAttributes& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setFilter(m.get<0>().getValue());
		dst_.setParameterList(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::FilterrefNodeAttributes>::generate(const Domain::Xml::FilterrefNodeAttributes& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getFilter(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getParameterList(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Tune

namespace Domain
{
namespace Xml
{
bool Tune::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Tune, Name::Strict<708> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Tune::save(QDomElement& dst_) const
{
	Element<Tune, Name::Strict<708> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Tune::save(QDomDocument& dst_) const
{
	Element<Tune, Name::Strict<708> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Tune>::parse(Domain::Xml::Tune& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSndbuf(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Tune>::generate(const Domain::Xml::Tune& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSndbuf(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Rom

namespace Domain
{
namespace Xml
{
bool Rom::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Rom, Name::Strict<275> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Rom::save(QDomElement& dst_) const
{
	Element<Rom, Name::Strict<275> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Rom::save(QDomDocument& dst_) const
{
	Element<Rom, Name::Strict<275> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Rom>::parse(Domain::Xml::Rom& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setEnabled(m.get<0>().getValue());
		dst_.setBar(m.get<1>().getValue());
		dst_.setFile(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Rom>::generate(const Domain::Xml::Rom& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getEnabled(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBar(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFile(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct BandwidthAttributes

namespace Domain
{
namespace Xml
{
bool BandwidthAttributes::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<BandwidthAttributes, Name::Strict<196> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool BandwidthAttributes::save(QDomElement& dst_) const
{
	Element<BandwidthAttributes, Name::Strict<196> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool BandwidthAttributes::save(QDomDocument& dst_) const
{
	Element<BandwidthAttributes, Name::Strict<196> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::BandwidthAttributes>::parse(Domain::Xml::BandwidthAttributes& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAverage(m.get<0>().getValue());
		dst_.setPeak(m.get<1>().getValue());
		dst_.setFloor(m.get<2>().getValue());
		dst_.setBurst(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::BandwidthAttributes>::generate(const Domain::Xml::BandwidthAttributes& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAverage(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPeak(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFloor(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBurst(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Bandwidth1

namespace Domain
{
namespace Xml
{
bool Bandwidth1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Bandwidth1, Name::Strict<193> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Bandwidth1::save(QDomElement& dst_) const
{
	Element<Bandwidth1, Name::Strict<193> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Bandwidth1::save(QDomDocument& dst_) const
{
	Element<Bandwidth1, Name::Strict<193> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Bandwidth1>::parse(Domain::Xml::Bandwidth1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setClassID(m.get<0>().getValue());
		dst_.setInbound(m.get<1>().get<0>().getValue());
		dst_.setOutbound(m.get<1>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Bandwidth1>::generate(const Domain::Xml::Bandwidth1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getClassID(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInbound(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOutbound(), m.get<1>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Tag

namespace Domain
{
namespace Xml
{
Tag::Tag(): m_id()
{
}

bool Tag::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Tag, Name::Strict<207> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Tag::save(QDomElement& dst_) const
{
	Element<Tag, Name::Strict<207> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Tag::save(QDomDocument& dst_) const
{
	Element<Tag, Name::Strict<207> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Tag>::parse(Domain::Xml::Tag& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setId(m.get<0>().getValue());
		dst_.setNativeMode(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Tag>::generate(const Domain::Xml::Tag& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getId(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNativeMode(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Port

namespace Domain
{
namespace Xml
{
bool Port::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Port, Name::Strict<212> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Port::save(QDomElement& dst_) const
{
	Element<Port, Name::Strict<212> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Port::save(QDomDocument& dst_) const
{
	Element<Port, Name::Strict<212> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Port>::parse(Domain::Xml::Port& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setIsolated(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Port>::generate(const Domain::Xml::Port& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getIsolated(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Teaming9388

int Traits<Domain::Xml::Teaming9388>::parse(Domain::Xml::Teaming9388& , QStack<QDomElement>& stack_)
{
	marshal_type m;
	return m.consume(stack_);
}

int Traits<Domain::Xml::Teaming9388>::generate(const Domain::Xml::Teaming9388& , QDomElement& dst_)
{
	marshal_type m;
	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Interface7022

int Traits<Domain::Xml::Interface7022>::parse(Domain::Xml::Interface7022& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSource(m.get<1>().get<0>().getValue());
		dst_.setVirtualPortProfile(m.get<1>().get<1>().getValue());
		dst_.setLink(m.get<1>().get<2>().getValue());
		dst_.setMtu(m.get<1>().get<3>().getValue());
		dst_.setCoalesce(m.get<1>().get<4>().getValue());
		dst_.setVzDhcpList(m.get<1>().get<5>().getValue());
		dst_.setVzDns(m.get<1>().get<6>().getValue());
		dst_.setTarget(m.get<1>().get<7>().getValue());
		dst_.setGuest(m.get<1>().get<8>().getValue());
		dst_.setMac(m.get<1>().get<9>().getValue());
		dst_.setIpList(m.get<1>().get<10>().getValue());
		dst_.setRouteList(m.get<1>().get<11>().getValue());
		dst_.setScript(m.get<1>().get<12>().getValue());
		dst_.setDownscript(m.get<1>().get<13>().getValue());
		dst_.setBackenddomain(m.get<1>().get<14>().getValue());
		dst_.setModel(m.get<1>().get<15>().getValue());
		dst_.setBackend(m.get<1>().get<16>().getValue());
		dst_.setDriver(m.get<1>().get<17>().getValue());
		dst_.setAlias(m.get<1>().get<18>().getValue());
		dst_.setAcpi(m.get<1>().get<19>().getValue());
		dst_.setAddress(m.get<1>().get<20>().getValue());
		dst_.setFilterref(m.get<1>().get<21>().getValue());
		dst_.setTune(m.get<1>().get<22>().getValue());
		dst_.setBoot(m.get<1>().get<23>().getValue());
		dst_.setRom(m.get<1>().get<24>().getValue());
		dst_.setBandwidth(m.get<1>().get<25>().getValue());
		dst_.setVlan(m.get<1>().get<26>().getValue());
		dst_.setPort(m.get<1>().get<27>().getValue());
		dst_.setTeaming(m.get<1>().get<28>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Interface7022>::generate(const Domain::Xml::Interface7022& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVirtualPortProfile(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLink(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMtu(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCoalesce(), m.get<1>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDhcpList(), m.get<1>().get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDns(), m.get<1>().get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<1>().get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGuest(), m.get<1>().get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMac(), m.get<1>().get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIpList(), m.get<1>().get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRouteList(), m.get<1>().get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getScript(), m.get<1>().get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDownscript(), m.get<1>().get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackenddomain(), m.get<1>().get<14>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<1>().get<15>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackend(), m.get<1>().get<16>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>().get<17>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>().get<18>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<19>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<20>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFilterref(), m.get<1>().get<21>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTune(), m.get<1>().get<22>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBoot(), m.get<1>().get<23>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRom(), m.get<1>().get<24>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBandwidth(), m.get<1>().get<25>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVlan(), m.get<1>().get<26>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<1>().get<27>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTeaming(), m.get<1>().get<28>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Interface7023

int Traits<Domain::Xml::Interface7023>::parse(Domain::Xml::Interface7023& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSource(m.get<1>().get<0>().getValue());
		dst_.setLink(m.get<1>().get<1>().getValue());
		dst_.setMtu(m.get<1>().get<2>().getValue());
		dst_.setCoalesce(m.get<1>().get<3>().getValue());
		dst_.setVzDhcpList(m.get<1>().get<4>().getValue());
		dst_.setVzDns(m.get<1>().get<5>().getValue());
		dst_.setTarget(m.get<1>().get<6>().getValue());
		dst_.setGuest(m.get<1>().get<7>().getValue());
		dst_.setMac(m.get<1>().get<8>().getValue());
		dst_.setIpList(m.get<1>().get<9>().getValue());
		dst_.setRouteList(m.get<1>().get<10>().getValue());
		dst_.setScript(m.get<1>().get<11>().getValue());
		dst_.setDownscript(m.get<1>().get<12>().getValue());
		dst_.setBackenddomain(m.get<1>().get<13>().getValue());
		dst_.setModel(m.get<1>().get<14>().getValue());
		dst_.setBackend(m.get<1>().get<15>().getValue());
		dst_.setDriver(m.get<1>().get<16>().getValue());
		dst_.setAlias(m.get<1>().get<17>().getValue());
		dst_.setAcpi(m.get<1>().get<18>().getValue());
		dst_.setAddress(m.get<1>().get<19>().getValue());
		dst_.setFilterref(m.get<1>().get<20>().getValue());
		dst_.setTune(m.get<1>().get<21>().getValue());
		dst_.setBoot(m.get<1>().get<22>().getValue());
		dst_.setRom(m.get<1>().get<23>().getValue());
		dst_.setBandwidth(m.get<1>().get<24>().getValue());
		dst_.setVlan(m.get<1>().get<25>().getValue());
		dst_.setPort(m.get<1>().get<26>().getValue());
		dst_.setTeaming(m.get<1>().get<27>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Interface7023>::generate(const Domain::Xml::Interface7023& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLink(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMtu(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCoalesce(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDhcpList(), m.get<1>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDns(), m.get<1>().get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<1>().get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGuest(), m.get<1>().get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMac(), m.get<1>().get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIpList(), m.get<1>().get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRouteList(), m.get<1>().get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getScript(), m.get<1>().get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDownscript(), m.get<1>().get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackenddomain(), m.get<1>().get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<1>().get<14>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackend(), m.get<1>().get<15>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>().get<16>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>().get<17>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<18>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<19>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFilterref(), m.get<1>().get<20>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTune(), m.get<1>().get<21>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBoot(), m.get<1>().get<22>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRom(), m.get<1>().get<23>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBandwidth(), m.get<1>().get<24>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVlan(), m.get<1>().get<25>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<1>().get<26>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTeaming(), m.get<1>().get<27>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source7

namespace Domain
{
namespace Xml
{
Source7::Source7(): m_type(), m_mode()
{
}

bool Source7::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source7, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source7::save(QDomElement& dst_) const
{
	Element<Source7, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source7::save(QDomDocument& dst_) const
{
	Element<Source7, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source7>::parse(Domain::Xml::Source7& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
		dst_.setPath(m.get<1>().getValue());
		dst_.setMode(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source7>::generate(const Domain::Xml::Source7& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPath(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMode(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Interface7024

int Traits<Domain::Xml::Interface7024>::parse(Domain::Xml::Interface7024& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSource(m.get<1>().get<0>().getValue());
		dst_.setLink(m.get<1>().get<1>().getValue());
		dst_.setMtu(m.get<1>().get<2>().getValue());
		dst_.setCoalesce(m.get<1>().get<3>().getValue());
		dst_.setVzDhcpList(m.get<1>().get<4>().getValue());
		dst_.setVzDns(m.get<1>().get<5>().getValue());
		dst_.setTarget(m.get<1>().get<6>().getValue());
		dst_.setGuest(m.get<1>().get<7>().getValue());
		dst_.setMac(m.get<1>().get<8>().getValue());
		dst_.setIpList(m.get<1>().get<9>().getValue());
		dst_.setRouteList(m.get<1>().get<10>().getValue());
		dst_.setScript(m.get<1>().get<11>().getValue());
		dst_.setDownscript(m.get<1>().get<12>().getValue());
		dst_.setBackenddomain(m.get<1>().get<13>().getValue());
		dst_.setModel(m.get<1>().get<14>().getValue());
		dst_.setBackend(m.get<1>().get<15>().getValue());
		dst_.setDriver(m.get<1>().get<16>().getValue());
		dst_.setAlias(m.get<1>().get<17>().getValue());
		dst_.setAcpi(m.get<1>().get<18>().getValue());
		dst_.setAddress(m.get<1>().get<19>().getValue());
		dst_.setFilterref(m.get<1>().get<20>().getValue());
		dst_.setTune(m.get<1>().get<21>().getValue());
		dst_.setBoot(m.get<1>().get<22>().getValue());
		dst_.setRom(m.get<1>().get<23>().getValue());
		dst_.setBandwidth(m.get<1>().get<24>().getValue());
		dst_.setVlan(m.get<1>().get<25>().getValue());
		dst_.setPort(m.get<1>().get<26>().getValue());
		dst_.setTeaming(m.get<1>().get<27>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Interface7024>::generate(const Domain::Xml::Interface7024& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLink(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMtu(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCoalesce(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDhcpList(), m.get<1>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDns(), m.get<1>().get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<1>().get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGuest(), m.get<1>().get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMac(), m.get<1>().get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIpList(), m.get<1>().get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRouteList(), m.get<1>().get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getScript(), m.get<1>().get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDownscript(), m.get<1>().get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackenddomain(), m.get<1>().get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<1>().get<14>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackend(), m.get<1>().get<15>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>().get<16>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>().get<17>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<18>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<19>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFilterref(), m.get<1>().get<20>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTune(), m.get<1>().get<21>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBoot(), m.get<1>().get<22>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRom(), m.get<1>().get<23>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBandwidth(), m.get<1>().get<24>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVlan(), m.get<1>().get<25>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<1>().get<26>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTeaming(), m.get<1>().get<27>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source8

namespace Domain
{
namespace Xml
{
bool Source8::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source8, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source8::save(QDomElement& dst_) const
{
	Element<Source8, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source8::save(QDomDocument& dst_) const
{
	Element<Source8, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source8>::parse(Domain::Xml::Source8& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setInterfaceNetworkAttributes(m.get<0>().getValue());
		dst_.setInterfaceBridgeAttributes(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source8>::generate(const Domain::Xml::Source8& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getInterfaceNetworkAttributes(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInterfaceBridgeAttributes(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Interface7025

int Traits<Domain::Xml::Interface7025>::parse(Domain::Xml::Interface7025& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSource(m.get<1>().get<0>().getValue());
		dst_.setVirtualPortProfile(m.get<1>().get<1>().getValue());
		dst_.setLink(m.get<1>().get<2>().getValue());
		dst_.setMtu(m.get<1>().get<3>().getValue());
		dst_.setCoalesce(m.get<1>().get<4>().getValue());
		dst_.setVzDhcpList(m.get<1>().get<5>().getValue());
		dst_.setVzDns(m.get<1>().get<6>().getValue());
		dst_.setTarget(m.get<1>().get<7>().getValue());
		dst_.setGuest(m.get<1>().get<8>().getValue());
		dst_.setMac(m.get<1>().get<9>().getValue());
		dst_.setIpList(m.get<1>().get<10>().getValue());
		dst_.setRouteList(m.get<1>().get<11>().getValue());
		dst_.setScript(m.get<1>().get<12>().getValue());
		dst_.setDownscript(m.get<1>().get<13>().getValue());
		dst_.setBackenddomain(m.get<1>().get<14>().getValue());
		dst_.setModel(m.get<1>().get<15>().getValue());
		dst_.setBackend(m.get<1>().get<16>().getValue());
		dst_.setDriver(m.get<1>().get<17>().getValue());
		dst_.setAlias(m.get<1>().get<18>().getValue());
		dst_.setAcpi(m.get<1>().get<19>().getValue());
		dst_.setAddress(m.get<1>().get<20>().getValue());
		dst_.setFilterref(m.get<1>().get<21>().getValue());
		dst_.setTune(m.get<1>().get<22>().getValue());
		dst_.setBoot(m.get<1>().get<23>().getValue());
		dst_.setRom(m.get<1>().get<24>().getValue());
		dst_.setBandwidth(m.get<1>().get<25>().getValue());
		dst_.setVlan(m.get<1>().get<26>().getValue());
		dst_.setPort(m.get<1>().get<27>().getValue());
		dst_.setTeaming(m.get<1>().get<28>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Interface7025>::generate(const Domain::Xml::Interface7025& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVirtualPortProfile(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLink(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMtu(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCoalesce(), m.get<1>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDhcpList(), m.get<1>().get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDns(), m.get<1>().get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<1>().get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGuest(), m.get<1>().get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMac(), m.get<1>().get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIpList(), m.get<1>().get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRouteList(), m.get<1>().get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getScript(), m.get<1>().get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDownscript(), m.get<1>().get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackenddomain(), m.get<1>().get<14>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<1>().get<15>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackend(), m.get<1>().get<16>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>().get<17>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>().get<18>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<19>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<20>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFilterref(), m.get<1>().get<21>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTune(), m.get<1>().get<22>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBoot(), m.get<1>().get<23>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRom(), m.get<1>().get<24>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBandwidth(), m.get<1>().get<25>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVlan(), m.get<1>().get<26>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<1>().get<27>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTeaming(), m.get<1>().get<28>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source9

namespace Domain
{
namespace Xml
{
bool Source9::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source9, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source9::save(QDomElement& dst_) const
{
	Element<Source9, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source9::save(QDomDocument& dst_) const
{
	Element<Source9, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source9>::parse(Domain::Xml::Source9& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDev(m.get<0>().getValue());
		dst_.setMode(m.get<1>().getValue());
		dst_.setInterfaceNetworkAttributes(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source9>::generate(const Domain::Xml::Source9& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDev(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMode(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInterfaceNetworkAttributes(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Interface7026

int Traits<Domain::Xml::Interface7026>::parse(Domain::Xml::Interface7026& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSource(m.get<1>().get<0>().getValue());
		dst_.setVirtualPortProfile(m.get<1>().get<1>().getValue());
		dst_.setLink(m.get<1>().get<2>().getValue());
		dst_.setMtu(m.get<1>().get<3>().getValue());
		dst_.setCoalesce(m.get<1>().get<4>().getValue());
		dst_.setVzDhcpList(m.get<1>().get<5>().getValue());
		dst_.setVzDns(m.get<1>().get<6>().getValue());
		dst_.setTarget(m.get<1>().get<7>().getValue());
		dst_.setGuest(m.get<1>().get<8>().getValue());
		dst_.setMac(m.get<1>().get<9>().getValue());
		dst_.setIpList(m.get<1>().get<10>().getValue());
		dst_.setRouteList(m.get<1>().get<11>().getValue());
		dst_.setScript(m.get<1>().get<12>().getValue());
		dst_.setDownscript(m.get<1>().get<13>().getValue());
		dst_.setBackenddomain(m.get<1>().get<14>().getValue());
		dst_.setModel(m.get<1>().get<15>().getValue());
		dst_.setBackend(m.get<1>().get<16>().getValue());
		dst_.setDriver(m.get<1>().get<17>().getValue());
		dst_.setAlias(m.get<1>().get<18>().getValue());
		dst_.setAcpi(m.get<1>().get<19>().getValue());
		dst_.setAddress(m.get<1>().get<20>().getValue());
		dst_.setFilterref(m.get<1>().get<21>().getValue());
		dst_.setTune(m.get<1>().get<22>().getValue());
		dst_.setBoot(m.get<1>().get<23>().getValue());
		dst_.setRom(m.get<1>().get<24>().getValue());
		dst_.setBandwidth(m.get<1>().get<25>().getValue());
		dst_.setVlan(m.get<1>().get<26>().getValue());
		dst_.setPort(m.get<1>().get<27>().getValue());
		dst_.setTeaming(m.get<1>().get<28>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Interface7026>::generate(const Domain::Xml::Interface7026& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVirtualPortProfile(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLink(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMtu(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCoalesce(), m.get<1>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDhcpList(), m.get<1>().get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDns(), m.get<1>().get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<1>().get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGuest(), m.get<1>().get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMac(), m.get<1>().get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIpList(), m.get<1>().get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRouteList(), m.get<1>().get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getScript(), m.get<1>().get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDownscript(), m.get<1>().get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackenddomain(), m.get<1>().get<14>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<1>().get<15>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackend(), m.get<1>().get<16>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>().get<17>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>().get<18>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<19>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<20>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFilterref(), m.get<1>().get<21>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTune(), m.get<1>().get<22>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBoot(), m.get<1>().get<23>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRom(), m.get<1>().get<24>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBandwidth(), m.get<1>().get<25>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVlan(), m.get<1>().get<26>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<1>().get<27>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTeaming(), m.get<1>().get<28>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct InterfaceOptions

namespace Domain
{
namespace Xml
{
bool InterfaceOptions::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<InterfaceOptions>::parse(*this, k);
}

bool InterfaceOptions::save(QDomElement& dst_) const
{
	return 0 <= Traits<InterfaceOptions>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::InterfaceOptions>::parse(Domain::Xml::InterfaceOptions& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setLink(m.get<0>().getValue());
		dst_.setMtu(m.get<1>().getValue());
		dst_.setCoalesce(m.get<2>().getValue());
		dst_.setVzDhcpList(m.get<3>().getValue());
		dst_.setVzDns(m.get<4>().getValue());
		dst_.setTarget(m.get<5>().getValue());
		dst_.setGuest(m.get<6>().getValue());
		dst_.setMac(m.get<7>().getValue());
		dst_.setIpList(m.get<8>().getValue());
		dst_.setRouteList(m.get<9>().getValue());
		dst_.setScript(m.get<10>().getValue());
		dst_.setDownscript(m.get<11>().getValue());
		dst_.setBackenddomain(m.get<12>().getValue());
		dst_.setModel(m.get<13>().getValue());
		dst_.setBackend(m.get<14>().getValue());
		dst_.setDriver(m.get<15>().getValue());
		dst_.setAlias(m.get<16>().getValue());
		dst_.setAcpi(m.get<17>().getValue());
		dst_.setAddress(m.get<18>().getValue());
		dst_.setFilterref(m.get<19>().getValue());
		dst_.setTune(m.get<20>().getValue());
		dst_.setBoot(m.get<21>().getValue());
		dst_.setRom(m.get<22>().getValue());
		dst_.setBandwidth(m.get<23>().getValue());
		dst_.setVlan(m.get<24>().getValue());
		dst_.setPort(m.get<25>().getValue());
		dst_.setTeaming(m.get<26>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::InterfaceOptions>::generate(const Domain::Xml::InterfaceOptions& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getLink(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMtu(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCoalesce(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDhcpList(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDns(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGuest(), m.get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMac(), m.get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIpList(), m.get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRouteList(), m.get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getScript(), m.get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDownscript(), m.get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackenddomain(), m.get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackend(), m.get<14>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<15>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<16>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<17>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<18>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFilterref(), m.get<19>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTune(), m.get<20>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBoot(), m.get<21>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRom(), m.get<22>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBandwidth(), m.get<23>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVlan(), m.get<24>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<25>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTeaming(), m.get<26>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Interface7028

int Traits<Domain::Xml::Interface7028>::parse(Domain::Xml::Interface7028& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSource(m.get<1>().get<0>().getValue());
		dst_.setLink(m.get<1>().get<1>().getValue());
		dst_.setMtu(m.get<1>().get<2>().getValue());
		dst_.setCoalesce(m.get<1>().get<3>().getValue());
		dst_.setVzDhcpList(m.get<1>().get<4>().getValue());
		dst_.setVzDns(m.get<1>().get<5>().getValue());
		dst_.setTarget(m.get<1>().get<6>().getValue());
		dst_.setGuest(m.get<1>().get<7>().getValue());
		dst_.setMac(m.get<1>().get<8>().getValue());
		dst_.setIpList(m.get<1>().get<9>().getValue());
		dst_.setRouteList(m.get<1>().get<10>().getValue());
		dst_.setScript(m.get<1>().get<11>().getValue());
		dst_.setDownscript(m.get<1>().get<12>().getValue());
		dst_.setBackenddomain(m.get<1>().get<13>().getValue());
		dst_.setModel(m.get<1>().get<14>().getValue());
		dst_.setBackend(m.get<1>().get<15>().getValue());
		dst_.setDriver(m.get<1>().get<16>().getValue());
		dst_.setAlias(m.get<1>().get<17>().getValue());
		dst_.setAcpi(m.get<1>().get<18>().getValue());
		dst_.setAddress(m.get<1>().get<19>().getValue());
		dst_.setFilterref(m.get<1>().get<20>().getValue());
		dst_.setTune(m.get<1>().get<21>().getValue());
		dst_.setBoot(m.get<1>().get<22>().getValue());
		dst_.setRom(m.get<1>().get<23>().getValue());
		dst_.setBandwidth(m.get<1>().get<24>().getValue());
		dst_.setVlan(m.get<1>().get<25>().getValue());
		dst_.setPort(m.get<1>().get<26>().getValue());
		dst_.setTeaming(m.get<1>().get<27>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Interface7028>::generate(const Domain::Xml::Interface7028& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLink(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMtu(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCoalesce(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDhcpList(), m.get<1>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDns(), m.get<1>().get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<1>().get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGuest(), m.get<1>().get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMac(), m.get<1>().get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIpList(), m.get<1>().get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRouteList(), m.get<1>().get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getScript(), m.get<1>().get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDownscript(), m.get<1>().get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackenddomain(), m.get<1>().get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<1>().get<14>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackend(), m.get<1>().get<15>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>().get<16>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>().get<17>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<18>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<19>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFilterref(), m.get<1>().get<20>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTune(), m.get<1>().get<21>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBoot(), m.get<1>().get<22>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRom(), m.get<1>().get<23>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBandwidth(), m.get<1>().get<24>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVlan(), m.get<1>().get<25>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<1>().get<26>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTeaming(), m.get<1>().get<27>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source10

namespace Domain
{
namespace Xml
{
Source10::Source10(): m_port()
{
}

bool Source10::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source10, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source10::save(QDomElement& dst_) const
{
	Element<Source10, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source10::save(QDomDocument& dst_) const
{
	Element<Source10, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source10>::parse(Domain::Xml::Source10& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAddress(m.get<0>().getValue());
		dst_.setPort(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source10>::generate(const Domain::Xml::Source10& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Interface7029

namespace Domain
{
namespace Xml
{
Interface7029::Interface7029(): m_type()
{
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Interface7029>::parse(Domain::Xml::Interface7029& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
		dst_.setSource(m.get<1>().get<0>().getValue());
		dst_.setMac(m.get<1>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Interface7029>::generate(const Domain::Xml::Interface7029& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMac(), m.get<1>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source11

namespace Domain
{
namespace Xml
{
Source11::Source11(): m_port()
{
}

bool Source11::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source11, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source11::save(QDomElement& dst_) const
{
	Element<Source11, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source11::save(QDomDocument& dst_) const
{
	Element<Source11, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source11>::parse(Domain::Xml::Source11& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAddress(m.get<0>().getValue());
		dst_.setPort(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source11>::generate(const Domain::Xml::Source11& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Interface7030

int Traits<Domain::Xml::Interface7030>::parse(Domain::Xml::Interface7030& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSource(m.get<1>().get<0>().getValue());
		dst_.setMac(m.get<1>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Interface7030>::generate(const Domain::Xml::Interface7030& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMac(), m.get<1>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Usbproduct

namespace Domain
{
namespace Xml
{
bool Usbproduct::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Usbproduct>::parse(*this, k);
}

bool Usbproduct::save(QDomElement& dst_) const
{
	return 0 <= Traits<Usbproduct>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Usbproduct>::parse(Domain::Xml::Usbproduct& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setVendor(m.get<0>().getValue());
		dst_.setProduct(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Usbproduct>::generate(const Domain::Xml::Usbproduct& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getVendor(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getProduct(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Address

namespace Domain
{
namespace Xml
{
bool Address::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Address, Name::Strict<111> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Address::save(QDomElement& dst_) const
{
	Element<Address, Name::Strict<111> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Address::save(QDomDocument& dst_) const
{
	Element<Address, Name::Strict<111> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Address>::parse(Domain::Xml::Address& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setBus(m.get<0>().getValue());
		dst_.setDevice(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Address>::generate(const Domain::Xml::Address& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getBus(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDevice(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source7031

int Traits<Domain::Xml::Source7031>::parse(Domain::Xml::Source7031& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setUsbproduct(m.get<0>().getValue());
		dst_.setAddress(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source7031>::generate(const Domain::Xml::Source7031& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getUsbproduct(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Address7033

int Traits<Domain::Xml::Address7033>::parse(Domain::Xml::Address7033& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setBus(m.get<1>().getValue());
		dst_.setDevice(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Address7033>::generate(const Domain::Xml::Address7033& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getBus(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDevice(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source12

namespace Domain
{
namespace Xml
{
bool Source12::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source12, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source12::save(QDomElement& dst_) const
{
	Element<Source12, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source12::save(QDomDocument& dst_) const
{
	Element<Source12, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source12>::parse(Domain::Xml::Source12& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setMissing(m.get<0>().getValue());
		dst_.setSource(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source12>::generate(const Domain::Xml::Source12& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getMissing(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Interface7035

int Traits<Domain::Xml::Interface7035>::parse(Domain::Xml::Interface7035& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setManaged(m.get<1>().getValue());
		dst_.setSource(m.get<2>().get<0>().getValue());
		dst_.setVirtualPortProfile(m.get<2>().get<1>().getValue());
		dst_.setLink(m.get<2>().get<2>().getValue());
		dst_.setMtu(m.get<2>().get<3>().getValue());
		dst_.setCoalesce(m.get<2>().get<4>().getValue());
		dst_.setVzDhcpList(m.get<2>().get<5>().getValue());
		dst_.setVzDns(m.get<2>().get<6>().getValue());
		dst_.setTarget(m.get<2>().get<7>().getValue());
		dst_.setGuest(m.get<2>().get<8>().getValue());
		dst_.setMac(m.get<2>().get<9>().getValue());
		dst_.setIpList(m.get<2>().get<10>().getValue());
		dst_.setRouteList(m.get<2>().get<11>().getValue());
		dst_.setScript(m.get<2>().get<12>().getValue());
		dst_.setDownscript(m.get<2>().get<13>().getValue());
		dst_.setBackenddomain(m.get<2>().get<14>().getValue());
		dst_.setModel(m.get<2>().get<15>().getValue());
		dst_.setBackend(m.get<2>().get<16>().getValue());
		dst_.setDriver(m.get<2>().get<17>().getValue());
		dst_.setAlias(m.get<2>().get<18>().getValue());
		dst_.setAcpi(m.get<2>().get<19>().getValue());
		dst_.setAddress(m.get<2>().get<20>().getValue());
		dst_.setFilterref(m.get<2>().get<21>().getValue());
		dst_.setTune(m.get<2>().get<22>().getValue());
		dst_.setBoot(m.get<2>().get<23>().getValue());
		dst_.setRom(m.get<2>().get<24>().getValue());
		dst_.setBandwidth(m.get<2>().get<25>().getValue());
		dst_.setVlan(m.get<2>().get<26>().getValue());
		dst_.setPort(m.get<2>().get<27>().getValue());
		dst_.setTeaming(m.get<2>().get<28>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Interface7035>::generate(const Domain::Xml::Interface7035& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getManaged(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<2>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVirtualPortProfile(), m.get<2>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLink(), m.get<2>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMtu(), m.get<2>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCoalesce(), m.get<2>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDhcpList(), m.get<2>().get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDns(), m.get<2>().get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<2>().get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGuest(), m.get<2>().get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMac(), m.get<2>().get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIpList(), m.get<2>().get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRouteList(), m.get<2>().get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getScript(), m.get<2>().get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDownscript(), m.get<2>().get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackenddomain(), m.get<2>().get<14>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<2>().get<15>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackend(), m.get<2>().get<16>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<2>().get<17>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<2>().get<18>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<2>().get<19>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<2>().get<20>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFilterref(), m.get<2>().get<21>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTune(), m.get<2>().get<22>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBoot(), m.get<2>().get<23>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRom(), m.get<2>().get<24>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBandwidth(), m.get<2>().get<25>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVlan(), m.get<2>().get<26>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<2>().get<27>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTeaming(), m.get<2>().get<28>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Interface

namespace Domain
{
namespace Xml
{
bool Interface::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Interface, Name::Strict<657> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Interface::save(QDomElement& dst_) const
{
	Element<Interface, Name::Strict<657> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Interface::save(QDomDocument& dst_) const
{
	Element<Interface, Name::Strict<657> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Interface>::parse(Domain::Xml::Interface& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setInterface(m.get<0>().getValue());
		dst_.setTrustGuestRxFilters(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Interface>::generate(const Domain::Xml::Interface& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getInterface(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTrustGuestRxFilters(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Anonymous9430

namespace Domain
{
namespace Xml
{
bool Anonymous9430::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Anonymous9430>::parse(*this, k);
}

bool Anonymous9430::save(QDomElement& dst_) const
{
	return 0 <= Traits<Anonymous9430>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Anonymous9430>::parse(Domain::Xml::Anonymous9430& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<0>().getValue());
		dst_.setAlias(m.get<1>().getValue());
		dst_.setAcpi(m.get<2>().getValue());
		dst_.setAddress(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Anonymous9430>::generate(const Domain::Xml::Anonymous9430& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Input

namespace Domain
{
namespace Xml
{
Input::Input(): m_type()
{
}

bool Input::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Input, Name::Strict<907> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Input::save(QDomElement& dst_) const
{
	Element<Input, Name::Strict<907> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Input::save(QDomDocument& dst_) const
{
	Element<Input, Name::Strict<907> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Input>::parse(Domain::Xml::Input& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
		dst_.setBus(m.get<1>().getValue());
		dst_.setAnonymous9430(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Input>::generate(const Domain::Xml::Input& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBus(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAnonymous9430(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Sound

namespace Domain
{
namespace Xml
{
Sound::Sound(): m_model()
{
}

bool Sound::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Sound, Name::Strict<872> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Sound::save(QDomElement& dst_) const
{
	Element<Sound, Name::Strict<872> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Sound::save(QDomDocument& dst_) const
{
	Element<Sound, Name::Strict<872> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Sound>::parse(Domain::Xml::Sound& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<0>().getValue());
		dst_.setAlias(m.get<1>().get<0>().getValue());
		dst_.setAcpi(m.get<1>().get<1>().getValue());
		dst_.setAddress(m.get<1>().get<2>().getValue());
		dst_.setAudio(m.get<1>().get<3>().getValue());
		dst_.setCodecList(m.get<1>().get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Sound>::generate(const Domain::Xml::Sound& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAudio(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCodecList(), m.get<1>().get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source13

namespace Domain
{
namespace Xml
{
bool Source13::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source13, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source13::save(QDomElement& dst_) const
{
	Element<Source13, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source13::save(QDomDocument& dst_) const
{
	Element<Source13, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source13>::parse(Domain::Xml::Source13& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setStartupPolicy(m.get<0>().getValue());
		dst_.setAddress(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source13>::generate(const Domain::Xml::Source13& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getStartupPolicy(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevsubsyspci

int Traits<Domain::Xml::Hostdevsubsyspci>::parse(Domain::Xml::Hostdevsubsyspci& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDriver(m.get<1>().get<0>().getValue());
		dst_.setTeaming(m.get<1>().get<1>().getValue());
		dst_.setSource(m.get<1>().get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hostdevsubsyspci>::generate(const Domain::Xml::Hostdevsubsyspci& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTeaming(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<1>().get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source7072

int Traits<Domain::Xml::Source7072>::parse(Domain::Xml::Source7072& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setUsbproduct(m.get<0>().getValue());
		dst_.setAddress(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source7072>::generate(const Domain::Xml::Source7072& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getUsbproduct(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source14

namespace Domain
{
namespace Xml
{
bool Source14::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source14, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source14::save(QDomElement& dst_) const
{
	Element<Source14, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source14::save(QDomDocument& dst_) const
{
	Element<Source14, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source14>::parse(Domain::Xml::Source14& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setStartupPolicy(m.get<0>().getValue());
		dst_.setSource(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source14>::generate(const Domain::Xml::Source14& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getStartupPolicy(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevsubsysusb

int Traits<Domain::Xml::Hostdevsubsysusb>::parse(Domain::Xml::Hostdevsubsysusb& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setReplug(m.get<1>().getValue());
		dst_.setSource(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hostdevsubsysusb>::generate(const Domain::Xml::Hostdevsubsysusb& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getReplug(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Parentaddr

namespace Domain
{
namespace Xml
{
bool Parentaddr::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Parentaddr, Name::Strict<109> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Parentaddr::save(QDomElement& dst_) const
{
	Element<Parentaddr, Name::Strict<109> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Parentaddr::save(QDomDocument& dst_) const
{
	Element<Parentaddr, Name::Strict<109> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Parentaddr>::parse(Domain::Xml::Parentaddr& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setUniqueId(m.get<0>().getValue());
		dst_.setAddress(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Parentaddr>::generate(const Domain::Xml::Parentaddr& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getUniqueId(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Adapter118

int Traits<Domain::Xml::Adapter118>::parse(Domain::Xml::Adapter118& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setParent(m.get<1>().getValue());
		dst_.setManaged(m.get<2>().getValue());
		dst_.setParentWwnn(m.get<3>().getValue());
		dst_.setParentWwpn(m.get<4>().getValue());
		dst_.setParentFabricWwn(m.get<5>().getValue());
		dst_.setWwnn(m.get<6>().getValue());
		dst_.setWwpn(m.get<7>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Adapter118>::generate(const Domain::Xml::Adapter118& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getParent(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getManaged(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getParentWwnn(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getParentWwpn(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getParentFabricWwn(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getWwnn(), m.get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getWwpn(), m.get<7>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Scsiaddress

namespace Domain
{
namespace Xml
{
bool Scsiaddress::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Scsiaddress, Name::Strict<111> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Scsiaddress::save(QDomElement& dst_) const
{
	Element<Scsiaddress, Name::Strict<111> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Scsiaddress::save(QDomDocument& dst_) const
{
	Element<Scsiaddress, Name::Strict<111> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Scsiaddress>::parse(Domain::Xml::Scsiaddress& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setBus(m.get<0>().getValue());
		dst_.setTarget(m.get<1>().getValue());
		dst_.setUnit(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Scsiaddress>::generate(const Domain::Xml::Scsiaddress& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getBus(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getUnit(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source7074

int Traits<Domain::Xml::Source7074>::parse(Domain::Xml::Source7074& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setProtocol(m.get<0>().getValue());
		dst_.setAdapter(m.get<1>().get<0>().getValue());
		dst_.setAddress(m.get<1>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source7074>::generate(const Domain::Xml::Source7074& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getProtocol(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAdapter(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Host1

namespace Domain
{
namespace Xml
{
bool Host1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Host1, Name::Strict<513> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Host1::save(QDomElement& dst_) const
{
	Element<Host1, Name::Strict<513> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Host1::save(QDomDocument& dst_) const
{
	Element<Host1, Name::Strict<513> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Host1>::parse(Domain::Xml::Host1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setPort(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Host1>::generate(const Domain::Xml::Host1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source7075

namespace Domain
{
namespace Xml
{
Source7075::Source7075(): m_protocol()
{
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source7075>::parse(Domain::Xml::Source7075& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setProtocol(m.get<0>().getValue());
		dst_.setName(m.get<1>().getValue());
		dst_.setHostList(m.get<2>().get<0>().getValue());
		dst_.setAuth(m.get<2>().get<1>().getValue());
		dst_.setInitiator(m.get<2>().get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source7075>::generate(const Domain::Xml::Source7075& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getProtocol(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHostList(), m.get<2>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAuth(), m.get<2>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInitiator(), m.get<2>().get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevsubsysscsi

int Traits<Domain::Xml::Hostdevsubsysscsi>::parse(Domain::Xml::Hostdevsubsysscsi& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSgio(m.get<1>().getValue());
		dst_.setRawio(m.get<2>().getValue());
		dst_.setSource(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hostdevsubsysscsi>::generate(const Domain::Xml::Hostdevsubsysscsi& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSgio(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRawio(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevsubsys

namespace Domain
{
namespace Xml
{
bool Hostdevsubsys::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Hostdevsubsys>::parse(*this, k);
}

bool Hostdevsubsys::save(QDomElement& dst_) const
{
	return 0 <= Traits<Hostdevsubsys>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Hostdevsubsys>::parse(Domain::Xml::Hostdevsubsys& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setManaged(m.get<1>().getValue());
		dst_.setHostdevsubsys(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hostdevsubsys>::generate(const Domain::Xml::Hostdevsubsys& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getManaged(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHostdevsubsys(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Ip1

namespace Domain
{
namespace Xml
{
bool Ip1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Ip1, Name::Strict<689> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Ip1::save(QDomElement& dst_) const
{
	Element<Ip1, Name::Strict<689> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Ip1::save(QDomDocument& dst_) const
{
	Element<Ip1, Name::Strict<689> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Ip1>::parse(Domain::Xml::Ip1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAddress(m.get<0>().getValue());
		dst_.setFamily(m.get<1>().getValue());
		dst_.setPrefix(m.get<2>().getValue());
		dst_.setPeer(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Ip1>::generate(const Domain::Xml::Ip1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFamily(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPrefix(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPeer(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct InterfaceIpInfo

namespace Domain
{
namespace Xml
{
bool InterfaceIpInfo::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<InterfaceIpInfo>::parse(*this, k);
}

bool InterfaceIpInfo::save(QDomElement& dst_) const
{
	return 0 <= Traits<InterfaceIpInfo>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::InterfaceIpInfo>::parse(Domain::Xml::InterfaceIpInfo& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setIpList(m.get<0>().getValue());
		dst_.setRouteList(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::InterfaceIpInfo>::generate(const Domain::Xml::InterfaceIpInfo& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getIpList(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRouteList(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hostdevcapsnet

namespace Domain
{
namespace Xml
{
bool Hostdevcapsnet::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<Hostdevcapsnet>::parse(*this, k);
}

bool Hostdevcapsnet::save(QDomElement& dst_) const
{
	return 0 <= Traits<Hostdevcapsnet>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Hostdevcapsnet>::parse(Domain::Xml::Hostdevcapsnet& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSource(m.get<1>().getValue());
		dst_.setInterfaceIpInfo(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hostdevcapsnet>::generate(const Domain::Xml::Hostdevcapsnet& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getInterfaceIpInfo(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hostdev

namespace Domain
{
namespace Xml
{
Hostdev::Hostdev(): m_readonly(), m_shareable()
{
}

bool Hostdev::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Hostdev, Name::Strict<676> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Hostdev::save(QDomElement& dst_) const
{
	Element<Hostdev, Name::Strict<676> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Hostdev::save(QDomDocument& dst_) const
{
	Element<Hostdev, Name::Strict<676> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Hostdev>::parse(Domain::Xml::Hostdev& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setChoice7065(m.get<0>().getValue());
		dst_.setAlias(m.get<1>().getValue());
		dst_.setAcpi(m.get<2>().getValue());
		dst_.setBoot(m.get<3>().getValue());
		dst_.setRom(m.get<4>().getValue());
		dst_.setAddress(m.get<5>().getValue());
		dst_.setReadonly(m.get<6>().getValue());
		dst_.setShareable(m.get<7>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hostdev>::generate(const Domain::Xml::Hostdev& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getChoice7065(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBoot(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRom(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getReadonly(), m.get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getShareable(), m.get<7>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7038

int Traits<Domain::Xml::Graphics7038>::parse(Domain::Xml::Graphics7038& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDisplay(m.get<1>().getValue());
		dst_.setXauth(m.get<2>().getValue());
		dst_.setFullscreen(m.get<3>().getValue());
		dst_.setGl(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Graphics7038>::generate(const Domain::Xml::Graphics7038& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDisplay(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getXauth(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFullscreen(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGl(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Variant5124

int Traits<Domain::Xml::Variant5124>::parse(Domain::Xml::Variant5124& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setPort(m.get<0>().getValue());
		dst_.setAutoport(m.get<1>().getValue());
		dst_.setWebsocket(m.get<2>().getValue());
		dst_.setListen(m.get<3>().getValue());
		dst_.setSharePolicy(m.get<4>().getValue());
		dst_.setPowerControl(m.get<5>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Variant5124>::generate(const Domain::Xml::Variant5124& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAutoport(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getWebsocket(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getListen(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSharePolicy(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPowerControl(), m.get<5>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Listen7044

int Traits<Domain::Xml::Listen7044>::parse(Domain::Xml::Listen7044& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setNetwork(m.get<1>().getValue());
		dst_.setAddress(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Listen7044>::generate(const Domain::Xml::Listen7044& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getNetwork(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Listen9392

int Traits<Domain::Xml::Listen9392>::parse(Domain::Xml::Listen9392& , QStack<QDomElement>& stack_)
{
	marshal_type m;
	return m.consume(stack_);
}

int Traits<Domain::Xml::Listen9392>::generate(const Domain::Xml::Listen9392& , QDomElement& dst_)
{
	marshal_type m;
	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7039

int Traits<Domain::Xml::Graphics7039>::parse(Domain::Xml::Graphics7039& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setChoice5126(m.get<1>().getValue());
		dst_.setPasswd(m.get<2>().getValue());
		dst_.setKeymap(m.get<3>().getValue());
		dst_.setPasswdValidTo(m.get<4>().getValue());
		dst_.setConnected(m.get<5>().getValue());
		dst_.setListenList(m.get<6>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Graphics7039>::generate(const Domain::Xml::Graphics7039& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getChoice5126(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPasswd(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getKeymap(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPasswdValidTo(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getConnected(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getListenList(), m.get<6>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Channel

namespace Domain
{
namespace Xml
{
Channel::Channel(): m_name(), m_mode()
{
}

bool Channel::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Channel, Name::Strict<744> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Channel::save(QDomElement& dst_) const
{
	Element<Channel, Name::Strict<744> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Channel::save(QDomDocument& dst_) const
{
	Element<Channel, Name::Strict<744> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Channel>::parse(Domain::Xml::Channel& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setMode(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Channel>::generate(const Domain::Xml::Channel& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMode(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Gl

namespace Domain
{
namespace Xml
{
Gl::Gl(): m_enable()
{
}

bool Gl::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Gl, Name::Strict<9188> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Gl::save(QDomElement& dst_) const
{
	Element<Gl, Name::Strict<9188> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Gl::save(QDomDocument& dst_) const
{
	Element<Gl, Name::Strict<9188> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Gl>::parse(Domain::Xml::Gl& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setEnable(m.get<0>().getValue());
		dst_.setRendernode(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Gl>::generate(const Domain::Xml::Gl& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getEnable(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRendernode(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7040

int Traits<Domain::Xml::Graphics7040>::parse(Domain::Xml::Graphics7040& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setPort(m.get<1>().getValue());
		dst_.setTlsPort(m.get<2>().getValue());
		dst_.setAutoport(m.get<3>().getValue());
		dst_.setListen(m.get<4>().getValue());
		dst_.setPasswd(m.get<5>().getValue());
		dst_.setKeymap(m.get<6>().getValue());
		dst_.setPasswdValidTo(m.get<7>().getValue());
		dst_.setConnected(m.get<8>().getValue());
		dst_.setDefaultMode(m.get<9>().getValue());
		dst_.setListenList(m.get<10>().get<0>().getValue());
		dst_.setChannelList(m.get<10>().get<1>().getValue());
		dst_.setImage(m.get<10>().get<2>().getValue());
		dst_.setJpeg(m.get<10>().get<3>().getValue());
		dst_.setZlib(m.get<10>().get<4>().getValue());
		dst_.setPlayback(m.get<10>().get<5>().getValue());
		dst_.setStreaming(m.get<10>().get<6>().getValue());
		dst_.setClipboard(m.get<10>().get<7>().getValue());
		dst_.setMouse(m.get<10>().get<8>().getValue());
		dst_.setFiletransfer(m.get<10>().get<9>().getValue());
		dst_.setGl(m.get<10>().get<10>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Graphics7040>::generate(const Domain::Xml::Graphics7040& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTlsPort(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAutoport(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getListen(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPasswd(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getKeymap(), m.get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPasswdValidTo(), m.get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getConnected(), m.get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDefaultMode(), m.get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getListenList(), m.get<10>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChannelList(), m.get<10>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getImage(), m.get<10>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getJpeg(), m.get<10>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getZlib(), m.get<10>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPlayback(), m.get<10>().get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getStreaming(), m.get<10>().get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getClipboard(), m.get<10>().get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMouse(), m.get<10>().get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFiletransfer(), m.get<10>().get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getGl(), m.get<10>().get<10>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7041

int Traits<Domain::Xml::Graphics7041>::parse(Domain::Xml::Graphics7041& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setPort(m.get<1>().getValue());
		dst_.setAutoport(m.get<2>().getValue());
		dst_.setReplaceUser(m.get<3>().getValue());
		dst_.setMultiUser(m.get<4>().getValue());
		dst_.setListen(m.get<5>().getValue());
		dst_.setListenList(m.get<6>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Graphics7041>::generate(const Domain::Xml::Graphics7041& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAutoport(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getReplaceUser(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMultiUser(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getListen(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getListenList(), m.get<6>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Graphics7042

int Traits<Domain::Xml::Graphics7042>::parse(Domain::Xml::Graphics7042& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDisplay(m.get<1>().getValue());
		dst_.setFullscreen(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Graphics7042>::generate(const Domain::Xml::Graphics7042& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDisplay(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFullscreen(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Gl1

namespace Domain
{
namespace Xml
{
bool Gl1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Gl1, Name::Strict<9188> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Gl1::save(QDomElement& dst_) const
{
	Element<Gl1, Name::Strict<9188> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Gl1::save(QDomDocument& dst_) const
{
	Element<Gl1, Name::Strict<9188> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Gl1>::parse(Domain::Xml::Gl1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setRendernode(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Gl1>::generate(const Domain::Xml::Gl1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getRendernode(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Driver4

namespace Domain
{
namespace Xml
{
bool Driver4::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Driver4, Name::Strict<546> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Driver4::save(QDomElement& dst_) const
{
	Element<Driver4, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Driver4::save(QDomDocument& dst_) const
{
	Element<Driver4, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Driver4>::parse(Domain::Xml::Driver4& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setVirtioOptions(m.get<0>().getValue());
		dst_.setName(m.get<1>().getValue());
		dst_.setVgaconf(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Driver4>::generate(const Domain::Xml::Driver4& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getVirtioOptions(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVgaconf(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Model7046

int Traits<Domain::Xml::Model7046>::parse(Domain::Xml::Model7046& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setRam(m.get<1>().getValue());
		dst_.setVgamem(m.get<2>().getValue());
		dst_.setVram64(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Model7046>::generate(const Domain::Xml::Model7046& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getRam(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVgamem(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVram64(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Acceleration

namespace Domain
{
namespace Xml
{
bool Acceleration::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Acceleration, Name::Strict<788> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Acceleration::save(QDomElement& dst_) const
{
	Element<Acceleration, Name::Strict<788> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Acceleration::save(QDomDocument& dst_) const
{
	Element<Acceleration, Name::Strict<788> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Acceleration>::parse(Domain::Xml::Acceleration& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAccel3d(m.get<0>().getValue());
		dst_.setAccel2d(m.get<1>().getValue());
		dst_.setRendernode(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Acceleration>::generate(const Domain::Xml::Acceleration& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAccel3d(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAccel2d(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRendernode(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Resolution

namespace Domain
{
namespace Xml
{
Resolution::Resolution(): m_x(), m_y()
{
}

bool Resolution::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Resolution, Name::Strict<8679> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Resolution::save(QDomElement& dst_) const
{
	Element<Resolution, Name::Strict<8679> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Resolution::save(QDomDocument& dst_) const
{
	Element<Resolution, Name::Strict<8679> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Resolution>::parse(Domain::Xml::Resolution& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setX(m.get<0>().getValue());
		dst_.setY(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Resolution>::generate(const Domain::Xml::Resolution& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getX(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getY(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Model1

namespace Domain
{
namespace Xml
{
bool Model1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Model1, Name::Strict<231> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Model1::save(QDomElement& dst_) const
{
	Element<Model1, Name::Strict<231> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Model1::save(QDomDocument& dst_) const
{
	Element<Model1, Name::Strict<231> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Model1>::parse(Domain::Xml::Model1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<0>().getValue());
		dst_.setVram(m.get<1>().getValue());
		dst_.setHeads(m.get<2>().getValue());
		dst_.setPrimary(m.get<3>().getValue());
		dst_.setAcceleration(m.get<4>().getValue());
		dst_.setResolution(m.get<5>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Model1>::generate(const Domain::Xml::Model1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVram(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHeads(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPrimary(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcceleration(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getResolution(), m.get<5>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Video

namespace Domain
{
namespace Xml
{
bool Video::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Video, Name::Strict<779> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Video::save(QDomElement& dst_) const
{
	Element<Video, Name::Strict<779> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Video::save(QDomDocument& dst_) const
{
	Element<Video, Name::Strict<779> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Video>::parse(Domain::Xml::Video& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setDriver(m.get<0>().getValue());
		dst_.setModel(m.get<1>().getValue());
		dst_.setAlias(m.get<2>().getValue());
		dst_.setAcpi(m.get<3>().getValue());
		dst_.setAddress(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Video>::generate(const Domain::Xml::Video& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source15

namespace Domain
{
namespace Xml
{
bool Source15::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source15, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source15::save(QDomElement& dst_) const
{
	Element<Source15, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source15::save(QDomDocument& dst_) const
{
	Element<Source15, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source15>::parse(Domain::Xml::Source15& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setMode(m.get<0>().getValue());
		dst_.setPath(m.get<1>().getValue());
		dst_.setHost(m.get<2>().getValue());
		dst_.setService(m.get<3>().getValue());
		dst_.setWiremode(m.get<4>().getValue());
		dst_.setChannel(m.get<5>().getValue());
		dst_.setMaster(m.get<6>().getValue());
		dst_.setSlave(m.get<7>().getValue());
		dst_.setAppend(m.get<8>().getValue());
		dst_.setSeclabel(m.get<9>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source15>::generate(const Domain::Xml::Source15& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getMode(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPath(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHost(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getService(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getWiremode(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChannel(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMaster(), m.get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSlave(), m.get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAppend(), m.get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSeclabel(), m.get<9>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Protocol

namespace Domain
{
namespace Xml
{
bool Protocol::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Protocol, Name::Strict<203> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Protocol::save(QDomElement& dst_) const
{
	Element<Protocol, Name::Strict<203> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Protocol::save(QDomDocument& dst_) const
{
	Element<Protocol, Name::Strict<203> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Protocol>::parse(Domain::Xml::Protocol& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Protocol>::generate(const Domain::Xml::Protocol& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Log

namespace Domain
{
namespace Xml
{
bool Log::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Log, Name::Strict<864> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Log::save(QDomElement& dst_) const
{
	Element<Log, Name::Strict<864> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Log::save(QDomDocument& dst_) const
{
	Element<Log, Name::Strict<864> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Log>::parse(Domain::Xml::Log& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setFile(m.get<0>().getValue());
		dst_.setAppend(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Log>::generate(const Domain::Xml::Log& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getFile(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAppend(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct QemucdevSrcDef

namespace Domain
{
namespace Xml
{
bool QemucdevSrcDef::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	k.push(src_.firstChildElement());
	return 0 <= Traits<QemucdevSrcDef>::parse(*this, k);
}

bool QemucdevSrcDef::save(QDomElement& dst_) const
{
	return 0 <= Traits<QemucdevSrcDef>::generate(*this, dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::QemucdevSrcDef>::parse(Domain::Xml::QemucdevSrcDef& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSourceList(m.get<0>().getValue());
		dst_.setProtocol(m.get<1>().getValue());
		dst_.setLog(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::QemucdevSrcDef>::generate(const Domain::Xml::QemucdevSrcDef& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSourceList(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getProtocol(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLog(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Target4

namespace Domain
{
namespace Xml
{
bool Target4::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Target4, Name::Strict<323> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Target4::save(QDomElement& dst_) const
{
	Element<Target4, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Target4::save(QDomDocument& dst_) const
{
	Element<Target4, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Target4>::parse(Domain::Xml::Target4& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setChoice8004(m.get<0>().getValue());
		dst_.setPort(m.get<1>().getValue());
		dst_.setModel(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Target4>::generate(const Domain::Xml::Target4& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getChoice8004(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Qemucdev

namespace Domain
{
namespace Xml
{
Qemucdev::Qemucdev(): m_type()
{
}

bool Qemucdev::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Qemucdev, Name::Strict<453> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Qemucdev::save(QDomElement& dst_) const
{
	Element<Qemucdev, Name::Strict<453> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Qemucdev::save(QDomDocument& dst_) const
{
	Element<Qemucdev, Name::Strict<453> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Qemucdev>::parse(Domain::Xml::Qemucdev& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
		dst_.setTty(m.get<1>().getValue());
		dst_.setQemucdevSrcDef(m.get<2>().getValue());
		dst_.setTarget(m.get<3>().getValue());
		dst_.setAlias(m.get<4>().getValue());
		dst_.setAddress(m.get<5>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Qemucdev>::generate(const Domain::Xml::Qemucdev& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTty(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getQemucdevSrcDef(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<5>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Target5

namespace Domain
{
namespace Xml
{
bool Target5::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Target5, Name::Strict<323> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Target5::save(QDomElement& dst_) const
{
	Element<Target5, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Target5::save(QDomDocument& dst_) const
{
	Element<Target5, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Target5>::parse(Domain::Xml::Target5& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAddress(m.get<1>().getValue());
		dst_.setPort(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Target5>::generate(const Domain::Xml::Target5& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Target6

namespace Domain
{
namespace Xml
{
bool Target6::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Target6, Name::Strict<323> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Target6::save(QDomElement& dst_) const
{
	Element<Target6, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Target6::save(QDomDocument& dst_) const
{
	Element<Target6, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Target6>::parse(Domain::Xml::Target6& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<1>().getValue());
		dst_.setState(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Target6>::generate(const Domain::Xml::Target6& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getState(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Channel1

namespace Domain
{
namespace Xml
{
Channel1::Channel1(): m_type()
{
}

bool Channel1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Channel1, Name::Strict<744> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Channel1::save(QDomElement& dst_) const
{
	Element<Channel1, Name::Strict<744> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Channel1::save(QDomDocument& dst_) const
{
	Element<Channel1, Name::Strict<744> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Channel1>::parse(Domain::Xml::Channel1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
		dst_.setQemucdevSrcDef(m.get<1>().get<0>().getValue());
		dst_.setChoice9400(m.get<1>().get<1>().getValue());
		dst_.setAlias(m.get<1>().get<2>().getValue());
		dst_.setAcpi(m.get<1>().get<3>().getValue());
		dst_.setAddress(m.get<1>().get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Channel1>::generate(const Domain::Xml::Channel1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getQemucdevSrcDef(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChoice9400(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Smartcard7059

int Traits<Domain::Xml::Smartcard7059>::parse(Domain::Xml::Smartcard7059& , QStack<QDomElement>& stack_)
{
	marshal_type m;
	return m.consume(stack_);
}

int Traits<Domain::Xml::Smartcard7059>::generate(const Domain::Xml::Smartcard7059& , QDomElement& dst_)
{
	marshal_type m;
	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Smartcard7060

int Traits<Domain::Xml::Smartcard7060>::parse(Domain::Xml::Smartcard7060& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setCertificate(m.get<1>().getValue());
		dst_.setCertificate2(m.get<2>().getValue());
		dst_.setCertificate3(m.get<3>().getValue());
		dst_.setDatabase(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Smartcard7060>::generate(const Domain::Xml::Smartcard7060& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getCertificate(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCertificate2(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCertificate3(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDatabase(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Smartcard7061

namespace Domain
{
namespace Xml
{
Smartcard7061::Smartcard7061(): m_type()
{
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Smartcard7061>::parse(Domain::Xml::Smartcard7061& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<1>().getValue());
		dst_.setQemucdevSrcDef(m.get<2>().get<0>().getValue());
		dst_.setTarget(m.get<2>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Smartcard7061>::generate(const Domain::Xml::Smartcard7061& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getQemucdevSrcDef(), m.get<2>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<2>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Smartcard

namespace Domain
{
namespace Xml
{
bool Smartcard::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Smartcard, Name::Strict<750> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Smartcard::save(QDomElement& dst_) const
{
	Element<Smartcard, Name::Strict<750> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Smartcard::save(QDomDocument& dst_) const
{
	Element<Smartcard, Name::Strict<750> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Smartcard>::parse(Domain::Xml::Smartcard& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSmartcard(m.get<0>().getValue());
		dst_.setAlias(m.get<1>().getValue());
		dst_.setAcpi(m.get<2>().getValue());
		dst_.setAddress(m.get<3>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Smartcard>::generate(const Domain::Xml::Smartcard& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSmartcard(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<3>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Hub

namespace Domain
{
namespace Xml
{
bool Hub::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Hub, Name::Strict<911> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Hub::save(QDomElement& dst_) const
{
	Element<Hub, Name::Strict<911> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Hub::save(QDomDocument& dst_) const
{
	Element<Hub, Name::Strict<911> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Hub>::parse(Domain::Xml::Hub& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAlias(m.get<1>().get<0>().getValue());
		dst_.setAcpi(m.get<1>().get<1>().getValue());
		dst_.setAddress(m.get<1>().get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Hub>::generate(const Domain::Xml::Hub& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Redirdev

namespace Domain
{
namespace Xml
{
Redirdev::Redirdev(): m_type()
{
}

bool Redirdev::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Redirdev, Name::Strict<912> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Redirdev::save(QDomElement& dst_) const
{
	Element<Redirdev, Name::Strict<912> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Redirdev::save(QDomDocument& dst_) const
{
	Element<Redirdev, Name::Strict<912> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Redirdev>::parse(Domain::Xml::Redirdev& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<1>().getValue());
		dst_.setQemucdevSrcDef(m.get<2>().get<0>().getValue());
		dst_.setAlias(m.get<2>().get<1>().getValue());
		dst_.setAcpi(m.get<2>().get<2>().getValue());
		dst_.setAddress(m.get<2>().get<3>().getValue());
		dst_.setBoot(m.get<2>().get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Redirdev>::generate(const Domain::Xml::Redirdev& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getQemucdevSrcDef(), m.get<2>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<2>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<2>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<2>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBoot(), m.get<2>().get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Usbdev

namespace Domain
{
namespace Xml
{
Usbdev::Usbdev(): m_allow()
{
}

bool Usbdev::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Usbdev, Name::Strict<840> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Usbdev::save(QDomElement& dst_) const
{
	Element<Usbdev, Name::Strict<840> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Usbdev::save(QDomDocument& dst_) const
{
	Element<Usbdev, Name::Strict<840> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Usbdev>::parse(Domain::Xml::Usbdev& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAllow(m.get<0>().getValue());
		dst_.setClass(m.get<1>().getValue());
		dst_.setVendor(m.get<2>().getValue());
		dst_.setProduct(m.get<3>().getValue());
		dst_.setVersion(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Usbdev>::generate(const Domain::Xml::Usbdev& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAllow(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getClass(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVendor(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getProduct(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVersion(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Backend4752

int Traits<Domain::Xml::Backend4752>::parse(Domain::Xml::Backend4752& , QStack<QDomElement>& stack_)
{
	marshal_type m;
	return m.consume(stack_);
}

int Traits<Domain::Xml::Backend4752>::generate(const Domain::Xml::Backend4752& , QDomElement& dst_)
{
	marshal_type m;
	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Backend4753

namespace Domain
{
namespace Xml
{
Backend4753::Backend4753(): m_type()
{
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Backend4753>::parse(Domain::Xml::Backend4753& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<1>().getValue());
		dst_.setQemucdevSrcDef(m.get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Backend4753>::generate(const Domain::Xml::Backend4753& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getQemucdevSrcDef(), m.get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Backend4754

int Traits<Domain::Xml::Backend4754>::parse(Domain::Xml::Backend4754& , QStack<QDomElement>& stack_)
{
	marshal_type m;
	return m.consume(stack_);
}

int Traits<Domain::Xml::Backend4754>::generate(const Domain::Xml::Backend4754& , QDomElement& dst_)
{
	marshal_type m;
	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Rate

namespace Domain
{
namespace Xml
{
Rate::Rate(): m_bytes()
{
}

bool Rate::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Rate, Name::Strict<1081> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Rate::save(QDomElement& dst_) const
{
	Element<Rate, Name::Strict<1081> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Rate::save(QDomDocument& dst_) const
{
	Element<Rate, Name::Strict<1081> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Rate>::parse(Domain::Xml::Rate& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setBytes(m.get<0>().getValue());
		dst_.setPeriod(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Rate>::generate(const Domain::Xml::Rate& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getBytes(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPeriod(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Rng

namespace Domain
{
namespace Xml
{
Rng::Rng(): m_model()
{
}

bool Rng::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Rng, Name::Strict<981> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Rng::save(QDomElement& dst_) const
{
	Element<Rng, Name::Strict<981> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Rng::save(QDomDocument& dst_) const
{
	Element<Rng, Name::Strict<981> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Rng>::parse(Domain::Xml::Rng& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<0>().getValue());
		dst_.setBackend(m.get<1>().get<0>().getValue());
		dst_.setDriver(m.get<1>().get<1>().getValue());
		dst_.setRate(m.get<1>().get<2>().getValue());
		dst_.setAlias(m.get<1>().get<3>().getValue());
		dst_.setAcpi(m.get<1>().get<4>().getValue());
		dst_.setAddress(m.get<1>().get<5>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Rng>::generate(const Domain::Xml::Rng& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackend(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRate(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<5>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Device1

namespace Domain
{
namespace Xml
{
bool Device1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Device1, Name::Strict<354> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Device1::save(QDomElement& dst_) const
{
	Element<Device1, Name::Strict<354> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Device1::save(QDomDocument& dst_) const
{
	Element<Device1, Name::Strict<354> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Device1>::parse(Domain::Xml::Device1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setPath(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Device1>::generate(const Domain::Xml::Device1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getPath(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Backend7062

int Traits<Domain::Xml::Backend7062>::parse(Domain::Xml::Backend7062& , QStack<QDomElement>& stack_)
{
	marshal_type m;
	return m.consume(stack_);
}

int Traits<Domain::Xml::Backend7062>::generate(const Domain::Xml::Backend7062& , QDomElement& dst_)
{
	marshal_type m;
	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Backend1

namespace Domain
{
namespace Xml
{
bool Backend1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Backend1, Name::Strict<693> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Backend1::save(QDomElement& dst_) const
{
	Element<Backend1, Name::Strict<693> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Backend1::save(QDomDocument& dst_) const
{
	Element<Backend1, Name::Strict<693> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Backend1>::parse(Domain::Xml::Backend1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setBackend(m.get<0>().getValue());
		dst_.setVersion(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Backend1>::generate(const Domain::Xml::Backend1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getBackend(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVersion(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Tpm

namespace Domain
{
namespace Xml
{
bool Tpm::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Tpm, Name::Strict<902> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Tpm::save(QDomElement& dst_) const
{
	Element<Tpm, Name::Strict<902> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Tpm::save(QDomDocument& dst_) const
{
	Element<Tpm, Name::Strict<902> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Tpm>::parse(Domain::Xml::Tpm& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<0>().getValue());
		dst_.setBackend(m.get<1>().getValue());
		dst_.setAlias(m.get<2>().getValue());
		dst_.setAcpi(m.get<3>().getValue());
		dst_.setAddress(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Tpm>::generate(const Domain::Xml::Tpm& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBackend(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Source16

namespace Domain
{
namespace Xml
{
bool Source16::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Source16, Name::Strict<501> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Source16::save(QDomElement& dst_) const
{
	Element<Source16, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Source16::save(QDomDocument& dst_) const
{
	Element<Source16, Name::Strict<501> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Source16>::parse(Domain::Xml::Source16& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setPagesize(m.get<0>().get<0>().getValue());
		dst_.setNodemask(m.get<0>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Source16>::generate(const Domain::Xml::Source16& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getPagesize(), m.get<0>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNodemask(), m.get<0>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Target7

namespace Domain
{
namespace Xml
{
Target7::Target7(): m_readonly()
{
}

bool Target7::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Target7, Name::Strict<323> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Target7::save(QDomElement& dst_) const
{
	Element<Target7, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Target7::save(QDomDocument& dst_) const
{
	Element<Target7, Name::Strict<323> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Target7>::parse(Domain::Xml::Target7& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setSize(m.get<0>().getValue());
		dst_.setNode(m.get<1>().getValue());
		dst_.setBlock(m.get<2>().getValue());
		dst_.setRequested(m.get<3>().getValue());
		dst_.setCurrent(m.get<4>().getValue());
		dst_.setLabel(m.get<5>().getValue());
		dst_.setReadonly(m.get<6>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Target7>::generate(const Domain::Xml::Target7& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getSize(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNode(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBlock(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getRequested(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCurrent(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLabel(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getReadonly(), m.get<6>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Memory2

namespace Domain
{
namespace Xml
{
Memory2::Memory2(): m_model()
{
}

bool Memory2::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Memory2, Name::Strict<326> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Memory2::save(QDomElement& dst_) const
{
	Element<Memory2, Name::Strict<326> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Memory2::save(QDomDocument& dst_) const
{
	Element<Memory2, Name::Strict<326> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Memory2>::parse(Domain::Xml::Memory2& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<0>().getValue());
		dst_.setAccess(m.get<1>().getValue());
		dst_.setDiscard(m.get<2>().getValue());
		dst_.setUuid(m.get<3>().get<0>().getValue());
		dst_.setSource(m.get<3>().get<1>().getValue());
		dst_.setTarget(m.get<3>().get<2>().getValue());
		dst_.setAddress(m.get<3>().get<3>().getValue());
		dst_.setAlias(m.get<3>().get<4>().getValue());
		dst_.setAcpi(m.get<3>().get<5>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Memory2>::generate(const Domain::Xml::Memory2& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAccess(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDiscard(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getUuid(), m.get<3>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSource(), m.get<3>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTarget(), m.get<3>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<3>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<3>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<3>().get<5>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Watchdog

namespace Domain
{
namespace Xml
{
Watchdog::Watchdog(): m_model()
{
}

bool Watchdog::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Watchdog, Name::Strict<880> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Watchdog::save(QDomElement& dst_) const
{
	Element<Watchdog, Name::Strict<880> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Watchdog::save(QDomDocument& dst_) const
{
	Element<Watchdog, Name::Strict<880> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Watchdog>::parse(Domain::Xml::Watchdog& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<0>().getValue());
		dst_.setAction(m.get<1>().getValue());
		dst_.setAlias(m.get<2>().getValue());
		dst_.setAcpi(m.get<3>().getValue());
		dst_.setAddress(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Watchdog>::generate(const Domain::Xml::Watchdog& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAction(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Memballoon

namespace Domain
{
namespace Xml
{
Memballoon::Memballoon(): m_model()
{
}

bool Memballoon::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Memballoon, Name::Strict<886> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Memballoon::save(QDomElement& dst_) const
{
	Element<Memballoon, Name::Strict<886> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Memballoon::save(QDomDocument& dst_) const
{
	Element<Memballoon, Name::Strict<886> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Memballoon>::parse(Domain::Xml::Memballoon& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<0>().getValue());
		dst_.setAutodeflate(m.get<1>().getValue());
		dst_.setFreePageReporting(m.get<2>().getValue());
		dst_.setAlias(m.get<3>().get<0>().getValue());
		dst_.setAcpi(m.get<3>().get<1>().getValue());
		dst_.setAddress(m.get<3>().get<2>().getValue());
		dst_.setStats(m.get<3>().get<3>().getValue());
		dst_.setDriver(m.get<3>().get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Memballoon>::generate(const Domain::Xml::Memballoon& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAutodeflate(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFreePageReporting(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<3>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<3>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<3>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getStats(), m.get<3>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<3>().get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Nvram1

namespace Domain
{
namespace Xml
{
bool Nvram1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Nvram1, Name::Strict<277> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Nvram1::save(QDomElement& dst_) const
{
	Element<Nvram1, Name::Strict<277> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Nvram1::save(QDomDocument& dst_) const
{
	Element<Nvram1, Name::Strict<277> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Nvram1>::parse(Domain::Xml::Nvram1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAddress(m.get<0>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Nvram1>::generate(const Domain::Xml::Nvram1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<0>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Panic

namespace Domain
{
namespace Xml
{
bool Panic::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Panic, Name::Strict<987> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Panic::save(QDomElement& dst_) const
{
	Element<Panic, Name::Strict<987> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Panic::save(QDomDocument& dst_) const
{
	Element<Panic, Name::Strict<987> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Panic>::parse(Domain::Xml::Panic& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<0>().getValue());
		dst_.setAddress(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Panic>::generate(const Domain::Xml::Panic& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Address1

namespace Domain
{
namespace Xml
{
bool Address1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Address1, Name::Strict<111> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Address1::save(QDomElement& dst_) const
{
	Element<Address1, Name::Strict<111> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Address1::save(QDomDocument& dst_) const
{
	Element<Address1, Name::Strict<111> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Address1>::parse(Domain::Xml::Address1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setHost(m.get<1>().getValue());
		dst_.setPort(m.get<2>().getValue());
		dst_.setAutoport(m.get<3>().getValue());
		dst_.setTls(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Address1>::generate(const Domain::Xml::Address1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getHost(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPort(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAutoport(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTls(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Disk1

namespace Domain
{
namespace Xml
{
bool Disk1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Disk1, Name::Strict<472> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Disk1::save(QDomElement& dst_) const
{
	Element<Disk1, Name::Strict<472> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Disk1::save(QDomDocument& dst_) const
{
	Element<Disk1, Name::Strict<472> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Disk1>::parse(Domain::Xml::Disk1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setExportname(m.get<1>().getValue());
		dst_.setSnapshot(m.get<2>().getValue());
		dst_.setChoice7113(m.get<3>().getValue());
		dst_.setReadonly(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Disk1>::generate(const Domain::Xml::Disk1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getExportname(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSnapshot(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChoice7113(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getReadonly(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Domainblockexport_

namespace Domain
{
namespace Xml
{
bool Domainblockexport_::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Domainblockexport_, Name::Strict<988> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Domainblockexport_::save(QDomElement& dst_) const
{
	Element<Domainblockexport_, Name::Strict<988> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Domainblockexport_::save(QDomDocument& dst_) const
{
	Element<Domainblockexport_, Name::Strict<988> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Domainblockexport_>::parse(Domain::Xml::Domainblockexport_& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAddress(m.get<1>().get<0>().getValue());
		dst_.setDiskList(m.get<1>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Domainblockexport_>::generate(const Domain::Xml::Domainblockexport_& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDiskList(), m.get<1>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Driver5

namespace Domain
{
namespace Xml
{
bool Driver5::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Driver5, Name::Strict<546> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Driver5::save(QDomElement& dst_) const
{
	Element<Driver5, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Driver5::save(QDomDocument& dst_) const
{
	Element<Driver5, Name::Strict<546> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Driver5>::parse(Domain::Xml::Driver5& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setIntremap(m.get<0>().getValue());
		dst_.setCachingMode(m.get<1>().getValue());
		dst_.setEim(m.get<2>().getValue());
		dst_.setIotlb(m.get<3>().getValue());
		dst_.setAwBits(m.get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Driver5>::generate(const Domain::Xml::Driver5& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getIntremap(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCachingMode(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEim(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIotlb(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAwBits(), m.get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Cid

namespace Domain
{
namespace Xml
{
bool Cid::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Cid, Name::Strict<5043> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Cid::save(QDomElement& dst_) const
{
	Element<Cid, Name::Strict<5043> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Cid::save(QDomDocument& dst_) const
{
	Element<Cid, Name::Strict<5043> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Cid>::parse(Domain::Xml::Cid& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setAuto(m.get<0>().getValue());
		dst_.setAddress(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Cid>::generate(const Domain::Xml::Cid& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getAuto(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Vsock

namespace Domain
{
namespace Xml
{
bool Vsock::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Vsock, Name::Strict<5042> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Vsock::save(QDomElement& dst_) const
{
	Element<Vsock, Name::Strict<5042> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Vsock::save(QDomDocument& dst_) const
{
	Element<Vsock, Name::Strict<5042> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Vsock>::parse(Domain::Xml::Vsock& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setCid(m.get<1>().get<0>().getValue());
		dst_.setAddress(m.get<1>().get<1>().getValue());
		dst_.setAlias(m.get<1>().get<2>().getValue());
		dst_.setAcpi(m.get<1>().get<3>().getValue());
		dst_.setDriver(m.get<1>().get<4>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Vsock>::generate(const Domain::Xml::Vsock& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getCid(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAddress(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAlias(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getAcpi(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDriver(), m.get<1>().get<4>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Devices

namespace Domain
{
namespace Xml
{
bool Devices::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Devices, Name::Strict<228> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Devices::save(QDomElement& dst_) const
{
	Element<Devices, Name::Strict<228> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Devices::save(QDomDocument& dst_) const
{
	Element<Devices, Name::Strict<228> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Devices>::parse(Domain::Xml::Devices& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setEmulator(m.get<0>().getValue());
		dst_.setChoice7097List(m.get<1>().getValue());
		dst_.setWatchdog(m.get<2>().getValue());
		dst_.setMemballoon(m.get<3>().getValue());
		dst_.setNvram(m.get<4>().getValue());
		dst_.setPanicList(m.get<5>().getValue());
		dst_.setXBlockexport(m.get<6>().getValue());
		dst_.setIommu(m.get<7>().getValue());
		dst_.setVsock(m.get<8>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Devices>::generate(const Domain::Xml::Devices& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getEmulator(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getChoice7097List(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getWatchdog(), m.get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMemballoon(), m.get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNvram(), m.get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPanicList(), m.get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getXBlockexport(), m.get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIommu(), m.get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVsock(), m.get<8>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6970

int Traits<Domain::Xml::Seclabel6970>::parse(Domain::Xml::Seclabel6970& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setLabel(m.get<2>().get<0>().getValue());
		dst_.setImagelabel(m.get<2>().get<1>().getValue());
		dst_.setBaselabel(m.get<2>().get<2>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Seclabel6970>::generate(const Domain::Xml::Seclabel6970& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getLabel(), m.get<2>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getImagelabel(), m.get<2>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBaselabel(), m.get<2>().get<2>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6971

int Traits<Domain::Xml::Seclabel6971>::parse(Domain::Xml::Seclabel6971& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setRelabel(m.get<1>().getValue());
		dst_.setLabel(m.get<2>().get<0>().getValue());
		dst_.setImagelabel(m.get<2>().get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Seclabel6971>::generate(const Domain::Xml::Seclabel6971& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getRelabel(), m.get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLabel(), m.get<2>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getImagelabel(), m.get<2>().get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel6972

int Traits<Domain::Xml::Seclabel6972>::parse(Domain::Xml::Seclabel6972& , QStack<QDomElement>& stack_)
{
	marshal_type m;
	return m.consume(stack_);
}

int Traits<Domain::Xml::Seclabel6972>::generate(const Domain::Xml::Seclabel6972& , QDomElement& dst_)
{
	marshal_type m;
	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Seclabel1

namespace Domain
{
namespace Xml
{
bool Seclabel1::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Seclabel1, Name::Strict<229> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Seclabel1::save(QDomElement& dst_) const
{
	Element<Seclabel1, Name::Strict<229> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Seclabel1::save(QDomDocument& dst_) const
{
	Element<Seclabel1, Name::Strict<229> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Seclabel1>::parse(Domain::Xml::Seclabel1& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setModel(m.get<0>().getValue());
		dst_.setSeclabel(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Seclabel1>::generate(const Domain::Xml::Seclabel1& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getModel(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSeclabel(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Env

namespace Domain
{
namespace Xml
{
bool Env::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Env, Name::Strict<1161> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Env::save(QDomElement& dst_) const
{
	Element<Env, Name::Strict<1161> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Env::save(QDomDocument& dst_) const
{
	Element<Env, Name::Strict<1161> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Env>::parse(Domain::Xml::Env& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setValue(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Env>::generate(const Domain::Xml::Env& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getValue(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Commandline

namespace Domain
{
namespace Xml
{
bool Commandline::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Commandline, Name::Scoped<1159, 1162> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Commandline::save(QDomElement& dst_) const
{
	Element<Commandline, Name::Scoped<1159, 1162> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Commandline::save(QDomDocument& dst_) const
{
	Element<Commandline, Name::Scoped<1159, 1162> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Commandline>::parse(Domain::Xml::Commandline& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setArgList(m.get<0>().getValue());
		dst_.setEnvList(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Commandline>::generate(const Domain::Xml::Commandline& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getArgList(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getEnvList(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Cipher

namespace Domain
{
namespace Xml
{
Cipher::Cipher(): m_name(), m_state()
{
}

bool Cipher::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Cipher, Name::Strict<5049> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Cipher::save(QDomElement& dst_) const
{
	Element<Cipher, Name::Strict<5049> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Cipher::save(QDomDocument& dst_) const
{
	Element<Cipher, Name::Strict<5049> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Cipher>::parse(Domain::Xml::Cipher& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setName(m.get<0>().getValue());
		dst_.setState(m.get<1>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Cipher>::generate(const Domain::Xml::Cipher& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getName(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getState(), m.get<1>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct LaunchSecurity

namespace Domain
{
namespace Xml
{
bool LaunchSecurity::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<LaunchSecurity, Name::Strict<5047> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool LaunchSecurity::save(QDomElement& dst_) const
{
	Element<LaunchSecurity, Name::Strict<5047> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool LaunchSecurity::save(QDomDocument& dst_) const
{
	Element<LaunchSecurity, Name::Strict<5047> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::LaunchSecurity>::parse(Domain::Xml::LaunchSecurity& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setCbitpos(m.get<1>().get<0>().getValue());
		dst_.setReducedPhysBits(m.get<1>().get<1>().getValue());
		dst_.setPolicy(m.get<1>().get<2>().getValue());
		dst_.setHandle(m.get<1>().get<3>().getValue());
		dst_.setDhCert(m.get<1>().get<4>().getValue());
		dst_.setSession(m.get<1>().get<5>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::LaunchSecurity>::generate(const Domain::Xml::LaunchSecurity& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getCbitpos(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getReducedPhysBits(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPolicy(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getHandle(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDhCert(), m.get<1>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSession(), m.get<1>().get<5>()))
		return -1;

	return m.produce(dst_);
}

///////////////////////////////////////////////////////////////////////////////
// struct Domain

namespace Domain
{
namespace Xml
{
Domain::Domain(): m_type()
{
}

bool Domain::load(const QDomElement& src_)
{
	QStack<QDomElement> k;
	k.push(src_);
	Element<Domain, Name::Strict<1> > m;
	if (0 > m.consume(k))
		return false;
	
	*this = m.getValue();
	return true;
}

bool Domain::save(QDomElement& dst_) const
{
	Element<Domain, Name::Strict<1> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}

bool Domain::save(QDomDocument& dst_) const
{
	Element<Domain, Name::Strict<1> > m;
	m.setValue(*this);
	return 0 <= m.produce(dst_);
}


} // namespace Xml
} // namespace Domain

int Traits<Domain::Xml::Domain>::parse(Domain::Xml::Domain& dst_, QStack<QDomElement>& stack_)
{
	marshal_type m;
	int output = m.consume(stack_);
	if (0 <= output)
	{
		dst_.setType(m.get<0>().getValue());
		dst_.setIds(m.get<1>().get<0>().getValue());
		dst_.setTitle(m.get<1>().get<1>().getValue());
		dst_.setDescription(m.get<1>().get<2>().getValue());
		dst_.setMetadata(m.get<1>().get<3>().getValue());
		dst_.setCpu(m.get<1>().get<4>().getValue());
		dst_.setSysinfoList(m.get<1>().get<5>().getValue());
		dst_.setOs(m.get<1>().get<6>().getValue());
		dst_.setClock(m.get<1>().get<7>().getValue());
		dst_.setMemory(m.get<1>().get<8>().getValue());
		dst_.setMaxMemory(m.get<1>().get<9>().getValue());
		dst_.setCurrentMemory(m.get<1>().get<10>().getValue());
		dst_.setMemoryBacking(m.get<1>().get<11>().getValue());
		dst_.setVcpu(m.get<1>().get<12>().getValue());
		dst_.setVcpus(m.get<1>().get<13>().getValue());
		dst_.setIothreads(m.get<1>().get<14>().getValue());
		dst_.setIothreadids(m.get<1>().get<15>().getValue());
		dst_.setBlkiotune(m.get<1>().get<16>().getValue());
		dst_.setMemtune(m.get<1>().get<17>().getValue());
		dst_.setCputune(m.get<1>().get<18>().getValue());
		dst_.setNumatune(m.get<1>().get<19>().getValue());
		dst_.setResource(m.get<1>().get<20>().getValue());
		dst_.setFeatures(m.get<1>().get<21>().getValue());
		dst_.setOnReboot(m.get<1>().get<22>().getValue());
		dst_.setOnPoweroff(m.get<1>().get<23>().getValue());
		dst_.setOnCrash(m.get<1>().get<24>().getValue());
		dst_.setOnLockfailure(m.get<1>().get<25>().getValue());
		dst_.setVzDns(m.get<1>().get<26>().getValue());
		dst_.setVzNetworkRates(m.get<1>().get<27>().getValue());
		dst_.setPm(m.get<1>().get<28>().getValue());
		dst_.setPerf(m.get<1>().get<29>().getValue());
		dst_.setIdmap(m.get<1>().get<30>().getValue());
		dst_.setDevices(m.get<1>().get<31>().getValue());
		dst_.setSeclabelList(m.get<1>().get<32>().getValue());
		dst_.setCommandline(m.get<1>().get<33>().getValue());
		dst_.setKeywrap(m.get<1>().get<34>().getValue());
		dst_.setLaunchSecurity(m.get<1>().get<35>().getValue());
	}
	return output;
}

int Traits<Domain::Xml::Domain>::generate(const Domain::Xml::Domain& src_, QDomElement& dst_)
{
	marshal_type m;
	if (0 > Details::Marshal::assign(src_.getType(), m.get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIds(), m.get<1>().get<0>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getTitle(), m.get<1>().get<1>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDescription(), m.get<1>().get<2>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMetadata(), m.get<1>().get<3>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCpu(), m.get<1>().get<4>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSysinfoList(), m.get<1>().get<5>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOs(), m.get<1>().get<6>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getClock(), m.get<1>().get<7>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMemory(), m.get<1>().get<8>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMaxMemory(), m.get<1>().get<9>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCurrentMemory(), m.get<1>().get<10>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMemoryBacking(), m.get<1>().get<11>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVcpu(), m.get<1>().get<12>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVcpus(), m.get<1>().get<13>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIothreads(), m.get<1>().get<14>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIothreadids(), m.get<1>().get<15>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getBlkiotune(), m.get<1>().get<16>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getMemtune(), m.get<1>().get<17>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCputune(), m.get<1>().get<18>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getNumatune(), m.get<1>().get<19>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getResource(), m.get<1>().get<20>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getFeatures(), m.get<1>().get<21>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOnReboot(), m.get<1>().get<22>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOnPoweroff(), m.get<1>().get<23>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOnCrash(), m.get<1>().get<24>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getOnLockfailure(), m.get<1>().get<25>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzDns(), m.get<1>().get<26>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getVzNetworkRates(), m.get<1>().get<27>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPm(), m.get<1>().get<28>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getPerf(), m.get<1>().get<29>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getIdmap(), m.get<1>().get<30>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getDevices(), m.get<1>().get<31>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getSeclabelList(), m.get<1>().get<32>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getCommandline(), m.get<1>().get<33>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getKeywrap(), m.get<1>().get<34>()))
		return -1;
	if (0 > Details::Marshal::assign(src_.getLaunchSecurity(), m.get<1>().get<35>()))
		return -1;

	return m.produce(dst_);
}

} // namespace Libvirt
