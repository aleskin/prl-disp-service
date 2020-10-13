/////////////////////////////////////////////////////////////////////////////
///
/// Copyright (c) 2020 Virtuozzo International GmbH, All rights reserved.
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
/// @file
///		CTransponsterNwfilterTest.cpp
///
/// @author
///		alexander.alekseev
///
/// @brief
///		Tests fixture class for testing DspCmdDirVmClone dispatcher API command functionality.
///
/////////////////////////////////////////////////////////////////////////////
#include "CTransponsterNwfilterTest.h"

#include <QtTest/QtTest>

#include "Tests/CommonTestsUtils.h"
#include "Libraries/Transponster/Reverse.h"
#include "Libraries/Transponster/Reverse_p.h"

const QString CTransponsterNwfilterTest::S_UUID = "{1ca7dd05-07b3-48f3-b8d3-ebe0edc7b4ed}";

void CTransponsterNwfilterTest::init()
{
	static const QString S_FIXTURE_PATH = "./TransponsterNwfilterTestFixtures/%1.xml";
	static const QString S_FILTER_FORMAT = "./TransponsterNwfilterTestFixtures/%1_filter.xml";
	static const QString S_FILTERREF_PATH = "./TransponsterNwfilterTestFixtures/filterref.xml";
	
	m_FixtureNames.append("fw_disabled");
	m_FixtureNames.append("fw_tcp_ipv4_in_only");
	m_FixtureNames.append("fw_tcp_ipv4_out_only");
	m_FixtureNames.append("fw_tcp_ipv6");
	m_FixtureNames.append("fw_tcp_ipv6_ports");
	m_FixtureNames.append("fw_tcp_ipv6_whitelist");
	m_FixtureNames.append("fw_tcp_ipv6_with_pktfilters");

	foreach(const QString& fixture, m_FixtureNames)
	{
		// Loading adapter fixtures
		QFile adapter_file(S_FIXTURE_PATH.arg(fixture));
		QVERIFY(adapter_file.open(QIODevice::ReadOnly));
		m_pAdapters.append(SmartPtr<CVmGenericNetworkAdapter>(
						new CVmGenericNetworkAdapter(&adapter_file)));

		// Loading expected nwfilters
		QFile filter_file(S_FILTER_FORMAT.arg(fixture));
		QVERIFY(filter_file.open(QIODevice::ReadOnly));
		m_Filters.append(filter_file.readAll());
	}

	// Loading expected filterref
	QFile filterref_file(S_FILTERREF_PATH);
	QVERIFY(filterref_file.open(QIODevice::ReadOnly));
	m_Filterref = filterref_file.readAll();
}

void CTransponsterNwfilterTest::cleanup()
{

}

void CTransponsterNwfilterTest::TestFilterref()
{
	for (int i = 0; i < m_FixtureNames.size(); ++i)
		TestSingleFixtureFilterref(i);
}

void CTransponsterNwfilterTest::TestFilter()
{
	for (int i = 0; i < m_FixtureNames.size(); ++i)
		TestSingleFixtureFilter(i);
}

void CTransponsterNwfilterTest::TestSingleFixtureFilter(uint id)
{
	Transponster::Filter::Reverse u(*m_pAdapters[id], S_UUID);
	QCOMPARE(u.getResult().toUtf8(), m_Filters[id]);
}

using Libvirt::Domain::Xml::FilterrefNodeAttributes;

void CTransponsterNwfilterTest::TestSingleFixtureFilterref(uint id)
{
	boost::optional<FilterrefNodeAttributes> filter =
		Transponster::Device::Network::View(*m_pAdapters[id], S_UUID).getFilterref();

	QByteArray filter_xml;
	if (filter)
	{
		QDomDocument result;
		filter->save(result);
		filter_xml = result.toByteArray();
	}
	QCOMPARE(filter_xml, m_Filterref);
}
