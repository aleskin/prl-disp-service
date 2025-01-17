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

#include "snapshot_data.h"
#include <QRegExp>

namespace Libvirt
{
///////////////////////////////////////////////////////////////////////////////
// struct PUnsignedInt

bool Traits<Snapshot::Xml::PUnsignedInt>::parse(const QString& src_, Snapshot::Xml::PUnsignedInt::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PUnsignedInt>::generate(Snapshot::Xml::PUnsignedInt::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PUnsignedLong

bool Traits<Snapshot::Xml::PUnsignedLong>::parse(const QString& src_, Snapshot::Xml::PUnsignedLong::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PUnsignedLong>::generate(Snapshot::Xml::PUnsignedLong::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PHexuint

bool Validatable<Snapshot::Xml::PHexuint>::validate(const Snapshot::Xml::PHexuint::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-f]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPositiveInteger

bool Traits<Snapshot::Xml::PPositiveInteger>::parse(const QString& src_, Snapshot::Xml::PPositiveInteger::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PPositiveInteger>::generate(Snapshot::Xml::PPositiveInteger::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct POctalMode

bool Traits<Snapshot::Xml::POctalMode>::parse(const QString& src_, Snapshot::Xml::POctalMode::value_type& dst_)
{
	QRegExp q("[0-7]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::POctalMode>::generate(Snapshot::Xml::POctalMode::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7161

bool Validatable<Snapshot::Xml::PData7161>::validate(const Snapshot::Xml::PData7161::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData5569

bool Traits<Snapshot::Xml::PData5569>::parse(const QString& src_, Snapshot::Xml::PData5569::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData5569>::generate(Snapshot::Xml::PData5569::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData5569>::validate(Snapshot::Xml::PData5569::value_type value_)
{
	if (0 > value_)
		return false;

	if (255 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData5571

bool Validatable<Snapshot::Xml::PData5571>::validate(const Snapshot::Xml::PData5571::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData5573

bool Traits<Snapshot::Xml::PData5573>::parse(const QString& src_, Snapshot::Xml::PData5573::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData5573>::generate(Snapshot::Xml::PData5573::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData5573>::validate(Snapshot::Xml::PData5573::value_type value_)
{
	if (0 > value_)
		return false;

	if (255 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData5575

bool Validatable<Snapshot::Xml::PData5575>::validate(const Snapshot::Xml::PData5575::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7163

bool Traits<Snapshot::Xml::PData7163>::parse(const QString& src_, Snapshot::Xml::PData7163::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7163>::generate(Snapshot::Xml::PData7163::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData7163>::validate(Snapshot::Xml::PData7163::value_type value_)
{
	if (0 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7165

bool Validatable<Snapshot::Xml::PData7165>::validate(const Snapshot::Xml::PData7165::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,6}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData5577

bool Traits<Snapshot::Xml::PData5577>::parse(const QString& src_, Snapshot::Xml::PData5577::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData5577>::generate(Snapshot::Xml::PData5577::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData5577>::validate(Snapshot::Xml::PData5577::value_type value_)
{
	if (0 > value_)
		return false;

	if (16777215 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData5579

bool Validatable<Snapshot::Xml::PData5579>::validate(const Snapshot::Xml::PData5579::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,6}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7167

bool Traits<Snapshot::Xml::PData7167>::parse(const QString& src_, Snapshot::Xml::PData7167::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7167>::generate(Snapshot::Xml::PData7167::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData7167>::validate(Snapshot::Xml::PData7167::value_type value_)
{
	if (0 > value_)
		return false;

	if (16777215 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7169

bool Validatable<Snapshot::Xml::PData7169>::validate(const Snapshot::Xml::PData7169::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,8}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7171

bool Traits<Snapshot::Xml::PData7171>::parse(const QString& src_, Snapshot::Xml::PData7171::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7171>::generate(Snapshot::Xml::PData7171::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7173

bool Validatable<Snapshot::Xml::PData7173>::validate(const Snapshot::Xml::PData7173::value_type& value_)
{
	QRegExp q("[a-fA-F0-9]{32}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData5581

bool Validatable<Snapshot::Xml::PData5581>::validate(const Snapshot::Xml::PData5581::value_type& value_)
{
	QRegExp q("[a-fA-F0-9]{8}\\-([a-fA-F0-9]{4}\\-){3}[a-fA-F0-9]{12}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PNumaDistanceValue

bool Traits<Snapshot::Xml::PNumaDistanceValue>::parse(const QString& src_, Snapshot::Xml::PNumaDistanceValue::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PNumaDistanceValue>::generate(Snapshot::Xml::PNumaDistanceValue::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PNumaDistanceValue>::validate(Snapshot::Xml::PNumaDistanceValue::value_type value_)
{
	if (10 > value_)
		return false;

	if (255 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUniMacAddr

bool Validatable<Snapshot::Xml::PUniMacAddr>::validate(const Snapshot::Xml::PUniMacAddr::value_type& value_)
{
	QRegExp q("[a-fA-F0-9][02468aAcCeE](:[a-fA-F0-9]{2}){5}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMultiMacAddr

bool Validatable<Snapshot::Xml::PMultiMacAddr>::validate(const Snapshot::Xml::PMultiMacAddr::value_type& value_)
{
	QRegExp q("[a-fA-F0-9][13579bBdDfF](:[a-fA-F0-9]{2}){5}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMacAddr

bool Validatable<Snapshot::Xml::PMacAddr>::validate(const Snapshot::Xml::PMacAddr::value_type& value_)
{
	QRegExp q("[a-fA-F0-9]{2}(:[a-fA-F0-9]{2}){5}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDuidLLT

bool Validatable<Snapshot::Xml::PDuidLLT>::validate(const Snapshot::Xml::PDuidLLT::value_type& value_)
{
	QRegExp q("[0]{1,2}:[0]{0,1}[1]:[0]{1,2}:[0]{0,1}[a-fA-F1-9](:[a-fA-F0-9]{1,2}){4}(:[a-fA-F0-9]{1,2}){6,8}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDuidEN

bool Validatable<Snapshot::Xml::PDuidEN>::validate(const Snapshot::Xml::PDuidEN::value_type& value_)
{
	QRegExp q("[0]{1,2}:[0]{0,1}[2](:[a-fA-F0-9]{1,2}){4}(:[a-fA-F0-9]{1,2}){1,124}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDuidLL

bool Validatable<Snapshot::Xml::PDuidLL>::validate(const Snapshot::Xml::PDuidLL::value_type& value_)
{
	QRegExp q("[0]{1,2}:[0]{0,1}[3]:[0]{1,2}:[0]{0,1}[a-fA-F1-9](:[a-fA-F0-9]{1,2}){6,8}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDuidUUID

bool Validatable<Snapshot::Xml::PDuidUUID>::validate(const Snapshot::Xml::PDuidUUID::value_type& value_)
{
	QRegExp q("[0]{1,2}:[0]{0,1}[4](:[a-fA-F0-9]{1,2}){16}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIpv4Addr

bool Validatable<Snapshot::Xml::PIpv4Addr>::validate(const Snapshot::Xml::PIpv4Addr::value_type& value_)
{
	QRegExp q("(((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIpv6Addr

bool Validatable<Snapshot::Xml::PIpv6Addr>::validate(const Snapshot::Xml::PIpv6Addr::value_type& value_)
{
	QRegExp q("(([0-9A-Fa-f]{1,4}:){7}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){6}:[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){5}:([0-9A-Fa-f]{1,4}:)?[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){4}:([0-9A-Fa-f]{1,4}:){0,2}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){3}:([0-9A-Fa-f]{1,4}:){0,3}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){2}:([0-9A-Fa-f]{1,4}:){0,4}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){6}(((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9])))|(([0-9A-Fa-f]{1,4}:){0,5}:(((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9])))|(::([0-9A-Fa-f]{1,4}:){0,5}(((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9])))|([0-9A-Fa-f]{1,4}::([0-9A-Fa-f]{1,4}:){0,5}[0-9A-Fa-f]{1,4})|(::([0-9A-Fa-f]{1,4}:){0,6}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){1,7}:)|(::)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIpv4Prefix

bool Traits<Snapshot::Xml::PIpv4Prefix>::parse(const QString& src_, Snapshot::Xml::PIpv4Prefix::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PIpv4Prefix>::generate(Snapshot::Xml::PIpv4Prefix::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PIpv4Prefix>::validate(Snapshot::Xml::PIpv4Prefix::value_type value_)
{
	if (32 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIpv6Prefix

bool Traits<Snapshot::Xml::PIpv6Prefix>::parse(const QString& src_, Snapshot::Xml::PIpv6Prefix::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PIpv6Prefix>::generate(Snapshot::Xml::PIpv6Prefix::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PIpv6Prefix>::validate(Snapshot::Xml::PIpv6Prefix::value_type value_)
{
	if (128 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PObjectNameWithSlash

bool Validatable<Snapshot::Xml::PObjectNameWithSlash>::validate(const Snapshot::Xml::PObjectNameWithSlash::value_type& value_)
{
	QRegExp q("[^\\n]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PObjectName

bool Validatable<Snapshot::Xml::PObjectName>::validate(const Snapshot::Xml::PObjectName::value_type& value_)
{
	QRegExp q("[^/\\n]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PGenericName

bool Validatable<Snapshot::Xml::PGenericName>::validate(const Snapshot::Xml::PGenericName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\+\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDnsName

bool Validatable<Snapshot::Xml::PDnsName>::validate(const Snapshot::Xml::PDnsName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9\\.\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDeviceName

bool Validatable<Snapshot::Xml::PDeviceName>::validate(const Snapshot::Xml::PDeviceName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\-\\\\:/]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PZoneName

bool Validatable<Snapshot::Xml::PZoneName>::validate(const Snapshot::Xml::PZoneName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PFilePath

bool Validatable<Snapshot::Xml::PFilePath>::validate(const Snapshot::Xml::PFilePath::value_type& value_)
{
	QRegExp q(".+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDirPath

bool Validatable<Snapshot::Xml::PDirPath>::validate(const Snapshot::Xml::PDirPath::value_type& value_)
{
	QRegExp q(".+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAbsFilePath

bool Validatable<Snapshot::Xml::PAbsFilePath>::validate(const Snapshot::Xml::PAbsFilePath::value_type& value_)
{
	QRegExp q("(/|[a-zA-Z]:\\\\).+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PVmwarePath

bool Validatable<Snapshot::Xml::PVmwarePath>::validate(const Snapshot::Xml::PVmwarePath::value_type& value_)
{
	QRegExp q("\\[[^\\]]+\\] .+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAbsDirPath

bool Validatable<Snapshot::Xml::PAbsDirPath>::validate(const Snapshot::Xml::PAbsDirPath::value_type& value_)
{
	QRegExp q("/.*");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUnit

bool Validatable<Snapshot::Xml::PUnit>::validate(const Snapshot::Xml::PUnit::value_type& value_)
{
	QRegExp q("([bB]([yY][tT][eE][sS]?)?)|([kKmMgGtTpPeE]([iI]?[bB])?)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPciDomain

bool Validatable<Snapshot::Xml::PPciDomain>::validate(const Snapshot::Xml::PPciDomain::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPciBus

bool Validatable<Snapshot::Xml::PPciBus>::validate(const Snapshot::Xml::PPciBus::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPciSlot

bool Validatable<Snapshot::Xml::PPciSlot>::validate(const Snapshot::Xml::PPciSlot::value_type& value_)
{
	QRegExp q("(0x)?[0-1]?[0-9a-fA-F]");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPciFunc

bool Validatable<Snapshot::Xml::PPciFunc>::validate(const Snapshot::Xml::PPciFunc::value_type& value_)
{
	QRegExp q("(0x)?[0-7]");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PWwn

bool Validatable<Snapshot::Xml::PWwn>::validate(const Snapshot::Xml::PWwn::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{16}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData5591

bool Validatable<Snapshot::Xml::PData5591>::validate(const Snapshot::Xml::PData5591::value_type& value_)
{
	QRegExp q("0x[0-9a-eA-E][0-9a-fA-F]?");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData5593

bool Validatable<Snapshot::Xml::PData5593>::validate(const Snapshot::Xml::PData5593::value_type& value_)
{
	QRegExp q("0x[fF][0-9a-eA-E]?");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData5595

bool Traits<Snapshot::Xml::PData5595>::parse(const QString& src_, Snapshot::Xml::PData5595::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData5595>::generate(Snapshot::Xml::PData5595::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData5595>::validate(Snapshot::Xml::PData5595::value_type value_)
{
	if (0 > value_)
		return false;

	if (254 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCcwSsidRange

bool Validatable<Snapshot::Xml::PCcwSsidRange>::validate(const Snapshot::Xml::PCcwSsidRange::value_type& value_)
{
	QRegExp q("(0x)?[0-3]");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData5597

bool Validatable<Snapshot::Xml::PData5597>::validate(const Snapshot::Xml::PData5597::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData5599

bool Traits<Snapshot::Xml::PData5599>::parse(const QString& src_, Snapshot::Xml::PData5599::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData5599>::generate(Snapshot::Xml::PData5599::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData5599>::validate(Snapshot::Xml::PData5599::value_type value_)
{
	if (0 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCpuset

bool Validatable<Snapshot::Xml::PCpuset>::validate(const Snapshot::Xml::PCpuset::value_type& value_)
{
	QRegExp q("([0-9]+(-[0-9]+)?|\\^[0-9]+)(,([0-9]+(-[0-9]+)?|\\^[0-9]+))*");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PVolName

bool Validatable<Snapshot::Xml::PVolName>::validate(const Snapshot::Xml::PVolName::value_type& value_)
{
	if ("\n        " == value_)
		return false;

	QRegExp q("[^/]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPortNumber

bool Traits<Snapshot::Xml::PPortNumber>::parse(const QString& src_, Snapshot::Xml::PPortNumber::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PPortNumber>::generate(Snapshot::Xml::PPortNumber::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PPortNumber>::validate(Snapshot::Xml::PPortNumber::value_type value_)
{
	if (-1 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIobase

bool Validatable<Snapshot::Xml::PIobase>::validate(const Snapshot::Xml::PIobase::value_type& value_)
{
	QRegExp q("0x[a-fA-F0-9]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIrq

bool Validatable<Snapshot::Xml::PIrq>::validate(const Snapshot::Xml::PIrq::value_type& value_)
{
	QRegExp q("0x[a-fA-F0-9]");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCompat

bool Validatable<Snapshot::Xml::PCompat>::validate(const Snapshot::Xml::PCompat::value_type& value_)
{
	QRegExp q("[0-9]+\\.[0-9]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PVirtualPortProfileID

bool Validatable<Snapshot::Xml::PVirtualPortProfileID>::validate(const Snapshot::Xml::PVirtualPortProfileID::value_type& value_)
{
	if (39 < value_.length())
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PSpeed

bool Traits<Snapshot::Xml::PSpeed>::parse(const QString& src_, Snapshot::Xml::PSpeed::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PSpeed>::generate(Snapshot::Xml::PSpeed::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PSpeed>::validate(Snapshot::Xml::PSpeed::value_type value_)
{
	if (1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PBurstSize

bool Traits<Snapshot::Xml::PBurstSize>::parse(const QString& src_, Snapshot::Xml::PBurstSize::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PBurstSize>::generate(Snapshot::Xml::PBurstSize::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PBurstSize>::validate(Snapshot::Xml::PBurstSize::value_type value_)
{
	if (1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUnsignedShort

bool Traits<Snapshot::Xml::PUnsignedShort>::parse(const QString& src_, Snapshot::Xml::PUnsignedShort::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PUnsignedShort>::generate(Snapshot::Xml::PUnsignedShort::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PUnsignedShort>::validate(Snapshot::Xml::PUnsignedShort::value_type value_)
{
	if (0 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PProtocol

bool Validatable<Snapshot::Xml::PProtocol>::validate(const Snapshot::Xml::PProtocol::value_type& value_)
{
	QRegExp q("(tcp)|(udp)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAddrFamily

bool Validatable<Snapshot::Xml::PAddrFamily>::validate(const Snapshot::Xml::PAddrFamily::value_type& value_)
{
	QRegExp q("(ipv4)|(ipv6)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PId

bool Traits<Snapshot::Xml::PId>::parse(const QString& src_, Snapshot::Xml::PId::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PId>::generate(Snapshot::Xml::PId::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PId>::validate(Snapshot::Xml::PId::value_type value_)
{
	if (4095 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPort

bool Traits<Snapshot::Xml::PPort>::parse(const QString& src_, Snapshot::Xml::PPort::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PPort>::generate(Snapshot::Xml::PPort::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PPort>::validate(Snapshot::Xml::PPort::value_type value_)
{
	if (1 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PVendorId

bool Validatable<Snapshot::Xml::PVendorId>::validate(const Snapshot::Xml::PVendorId::value_type& value_)
{
	QRegExp q("[^,]{12}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMemoryKB

bool Traits<Snapshot::Xml::PMemoryKB>::parse(const QString& src_, Snapshot::Xml::PMemoryKB::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PMemoryKB>::generate(Snapshot::Xml::PMemoryKB::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PFeatureName

bool Validatable<Snapshot::Xml::PFeatureName>::validate(const Snapshot::Xml::PFeatureName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9\\-_\\.]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PName

bool Validatable<Snapshot::Xml::PName>::validate(const Snapshot::Xml::PName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9\\-_]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PFilterParamName

bool Validatable<Snapshot::Xml::PFilterParamName>::validate(const Snapshot::Xml::PFilterParamName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PFilterParamValue

bool Validatable<Snapshot::Xml::PFilterParamValue>::validate(const Snapshot::Xml::PFilterParamValue::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.:]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCreateMode

bool Traits<Snapshot::Xml::PCreateMode>::parse(const QString& src_, Snapshot::Xml::PCreateMode::value_type& dst_)
{
	QRegExp q("0[0-7]{3}|[0-7]{1,3}");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCreateMode>::generate(Snapshot::Xml::PCreateMode::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PMachine

bool Validatable<Snapshot::Xml::PMachine>::validate(const Snapshot::Xml::PMachine::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCbitpos

bool Traits<Snapshot::Xml::PCbitpos>::parse(const QString& src_, Snapshot::Xml::PCbitpos::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCbitpos>::generate(Snapshot::Xml::PCbitpos::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PReducedPhysBits

bool Traits<Snapshot::Xml::PReducedPhysBits>::parse(const QString& src_, Snapshot::Xml::PReducedPhysBits::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PReducedPhysBits>::generate(Snapshot::Xml::PReducedPhysBits::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PAppid

bool Validatable<Snapshot::Xml::PAppid>::validate(const Snapshot::Xml::PAppid::value_type& value_)
{
	QRegExp q("[ -~]{1,128}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PReadIopsSec

bool Traits<Snapshot::Xml::PReadIopsSec>::parse(const QString& src_, Snapshot::Xml::PReadIopsSec::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PReadIopsSec>::generate(Snapshot::Xml::PReadIopsSec::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PWriteIopsSec

bool Traits<Snapshot::Xml::PWriteIopsSec>::parse(const QString& src_, Snapshot::Xml::PWriteIopsSec::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWriteIopsSec>::generate(Snapshot::Xml::PWriteIopsSec::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PReadBytesSec

bool Traits<Snapshot::Xml::PReadBytesSec>::parse(const QString& src_, Snapshot::Xml::PReadBytesSec::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PReadBytesSec>::generate(Snapshot::Xml::PReadBytesSec::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PWriteBytesSec

bool Traits<Snapshot::Xml::PWriteBytesSec>::parse(const QString& src_, Snapshot::Xml::PWriteBytesSec::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWriteBytesSec>::generate(Snapshot::Xml::PWriteBytesSec::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PVzRelative

bool Traits<Snapshot::Xml::PVzRelative>::parse(const QString& src_, Snapshot::Xml::PVzRelative::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toDouble(&output);
	return output;
}

QString Traits<Snapshot::Xml::PVzRelative>::generate(Snapshot::Xml::PVzRelative::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PVzRelative>::validate(Snapshot::Xml::PVzRelative::value_type value_)
{
	if (1 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PVendor

bool Validatable<Snapshot::Xml::PVendor>::validate(const Snapshot::Xml::PVendor::value_type& value_)
{
	QRegExp q("[\\x20-\\x7E]{0,8}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PProduct

bool Validatable<Snapshot::Xml::PProduct>::validate(const Snapshot::Xml::PProduct::value_type& value_)
{
	QRegExp q("[\\x20-\\x7E]{0,16}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDiskTarget

bool Validatable<Snapshot::Xml::PDiskTarget>::validate(const Snapshot::Xml::PDiskTarget::value_type& value_)
{
	QRegExp q("(ioemu:)?(fd|hd|sd|vd|xvd|ubd)[a-zA-Z0-9_]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCyls

bool Traits<Snapshot::Xml::PCyls>::parse(const QString& src_, Snapshot::Xml::PCyls::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCyls>::generate(Snapshot::Xml::PCyls::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PHeads

bool Traits<Snapshot::Xml::PHeads>::parse(const QString& src_, Snapshot::Xml::PHeads::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PHeads>::generate(Snapshot::Xml::PHeads::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PSecs

bool Traits<Snapshot::Xml::PSecs>::parse(const QString& src_, Snapshot::Xml::PSecs::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PSecs>::generate(Snapshot::Xml::PSecs::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PLogicalBlockSize

bool Traits<Snapshot::Xml::PLogicalBlockSize>::parse(const QString& src_, Snapshot::Xml::PLogicalBlockSize::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PLogicalBlockSize>::generate(Snapshot::Xml::PLogicalBlockSize::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PPhysicalBlockSize

bool Traits<Snapshot::Xml::PPhysicalBlockSize>::parse(const QString& src_, Snapshot::Xml::PPhysicalBlockSize::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PPhysicalBlockSize>::generate(Snapshot::Xml::PPhysicalBlockSize::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PType

bool Validatable<Snapshot::Xml::PType>::validate(const Snapshot::Xml::PType::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9\\-_]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPasswdValidTo

bool Traits<Snapshot::Xml::PPasswdValidTo>::parse(const QString& src_, Snapshot::Xml::PPasswdValidTo::value_type& dst_)
{
	dst_ = QDateTime::fromString(src_);
	return !dst_.isNull();
}

QString Traits<Snapshot::Xml::PPasswdValidTo>::generate(const Snapshot::Xml::PPasswdValidTo::value_type& src_)
{
	return src_.toString();
}

///////////////////////////////////////////////////////////////////////////////
// struct PSysinfoValue

bool Validatable<Snapshot::Xml::PSysinfoValue>::validate(const Snapshot::Xml::PSysinfoValue::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9/\\-_\\. \\(\\)]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PLoadparm

bool Validatable<Snapshot::Xml::PLoadparm>::validate(const Snapshot::Xml::PLoadparm::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9.\\s]{1,8}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PTotalBytesSec

bool Traits<Snapshot::Xml::PTotalBytesSec>::parse(const QString& src_, Snapshot::Xml::PTotalBytesSec::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PTotalBytesSec>::generate(Snapshot::Xml::PTotalBytesSec::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PTotalIopsSec

bool Traits<Snapshot::Xml::PTotalIopsSec>::parse(const QString& src_, Snapshot::Xml::PTotalIopsSec::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PTotalIopsSec>::generate(Snapshot::Xml::PTotalIopsSec::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PReadIopsSec1

bool Traits<Snapshot::Xml::PReadIopsSec1>::parse(const QString& src_, Snapshot::Xml::PReadIopsSec1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PReadIopsSec1>::generate(Snapshot::Xml::PReadIopsSec1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PWriteIopsSec1

bool Traits<Snapshot::Xml::PWriteIopsSec1>::parse(const QString& src_, Snapshot::Xml::PWriteIopsSec1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWriteIopsSec1>::generate(Snapshot::Xml::PWriteIopsSec1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PSizeIopsSec

bool Traits<Snapshot::Xml::PSizeIopsSec>::parse(const QString& src_, Snapshot::Xml::PSizeIopsSec::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PSizeIopsSec>::generate(Snapshot::Xml::PSizeIopsSec::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PRetries

bool Traits<Snapshot::Xml::PRetries>::parse(const QString& src_, Snapshot::Xml::PRetries::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PRetries>::generate(Snapshot::Xml::PRetries::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PValue

bool Validatable<Snapshot::Xml::PValue>::validate(const Snapshot::Xml::PValue::value_type& value_)
{
	QRegExp q("[^,]{0,12}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCountCPU

bool Traits<Snapshot::Xml::PCountCPU>::parse(const QString& src_, Snapshot::Xml::PCountCPU::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUShort(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCountCPU>::generate(Snapshot::Xml::PCountCPU::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PCountCPU>::validate(Snapshot::Xml::PCountCPU::value_type value_)
{
	if (1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PVcpuid

bool Traits<Snapshot::Xml::PVcpuid>::parse(const QString& src_, Snapshot::Xml::PVcpuid::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUShort(&output);
	return output;
}

QString Traits<Snapshot::Xml::PVcpuid>::generate(Snapshot::Xml::PVcpuid::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PCpushares

bool Traits<Snapshot::Xml::PCpushares>::parse(const QString& src_, Snapshot::Xml::PCpushares::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCpushares>::generate(Snapshot::Xml::PCpushares::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PCpuperiod

bool Traits<Snapshot::Xml::PCpuperiod>::parse(const QString& src_, Snapshot::Xml::PCpuperiod::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCpuperiod>::generate(Snapshot::Xml::PCpuperiod::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PCpuperiod>::validate(Snapshot::Xml::PCpuperiod::value_type value_)
{
	if (1000 > value_)
		return false;

	if (1000000 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCpuquota

bool Traits<Snapshot::Xml::PCpuquota>::parse(const QString& src_, Snapshot::Xml::PCpuquota::value_type& dst_)
{
	QRegExp q("-?[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toLong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCpuquota>::generate(Snapshot::Xml::PCpuquota::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PCpuquota>::validate(Snapshot::Xml::PCpuquota::value_type value_)
{
	if (-1 > value_)
		return false;

	if (18446744073709551 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PRebootTimeoutDelay

bool Traits<Snapshot::Xml::PRebootTimeoutDelay>::parse(const QString& src_, Snapshot::Xml::PRebootTimeoutDelay::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toShort(&output);
	return output;
}

QString Traits<Snapshot::Xml::PRebootTimeoutDelay>::generate(Snapshot::Xml::PRebootTimeoutDelay::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PRebootTimeoutDelay>::validate(Snapshot::Xml::PRebootTimeoutDelay::value_type value_)
{
	if (-1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PWeight

bool Traits<Snapshot::Xml::PWeight>::parse(const QString& src_, Snapshot::Xml::PWeight::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWeight>::generate(Snapshot::Xml::PWeight::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PWeight>::validate(Snapshot::Xml::PWeight::value_type value_)
{
	if (100 > value_)
		return false;

	if (1000 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMemoryKB1

bool Traits<Snapshot::Xml::PMemoryKB1>::parse(const QString& src_, Snapshot::Xml::PMemoryKB1::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PMemoryKB1>::generate(Snapshot::Xml::PMemoryKB1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PDomainName

bool Validatable<Snapshot::Xml::PDomainName>::validate(const Snapshot::Xml::PDomainName::value_type& value_)
{
	QRegExp q("[^\n]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDiskSerial

bool Validatable<Snapshot::Xml::PDiskSerial>::validate(const Snapshot::Xml::PDiskSerial::value_type& value_)
{
	QRegExp q("[A-Za-z0-9_\\.\\+\\-]*");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PBridgeMode

bool Validatable<Snapshot::Xml::PBridgeMode>::validate(const Snapshot::Xml::PBridgeMode::value_type& value_)
{
	QRegExp q("(vepa|bridge|private|passthrough)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAddrIPorName

bool Validatable<Snapshot::Xml::PAddrIPorName>::validate(const Snapshot::Xml::PAddrIPorName::value_type& value_)
{
	QRegExp q("(([0-2]?[0-9]?[0-9]\\.){3}[0-2]?[0-9]?[0-9])|(([0-9a-fA-F]+|:)+[0-9a-fA-F]+)|([a-zA-Z0-9_\\.\\+\\-]*)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbIdDefault

bool Validatable<Snapshot::Xml::PUsbIdDefault>::validate(const Snapshot::Xml::PUsbIdDefault::value_type& value_)
{
	QRegExp q("-1");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbId

bool Validatable<Snapshot::Xml::PUsbId>::validate(const Snapshot::Xml::PUsbId::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbVersion

bool Validatable<Snapshot::Xml::PUsbVersion>::validate(const Snapshot::Xml::PUsbVersion::value_type& value_)
{
	QRegExp q("[0-9]{1,2}.[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbAddr

bool Validatable<Snapshot::Xml::PUsbAddr>::validate(const Snapshot::Xml::PUsbAddr::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,3}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbClass

bool Validatable<Snapshot::Xml::PUsbClass>::validate(const Snapshot::Xml::PUsbClass::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbPort

bool Validatable<Snapshot::Xml::PUsbPort>::validate(const Snapshot::Xml::PUsbPort::value_type& value_)
{
	QRegExp q("((0x)?[0-9a-fA-F]{1,3}\\.){0,3}(0x)?[0-9a-fA-F]{1,3}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDriveController

bool Validatable<Snapshot::Xml::PDriveController>::validate(const Snapshot::Xml::PDriveController::value_type& value_)
{
	QRegExp q("[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDriveBus

bool Validatable<Snapshot::Xml::PDriveBus>::validate(const Snapshot::Xml::PDriveBus::value_type& value_)
{
	QRegExp q("[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDriveTarget

bool Validatable<Snapshot::Xml::PDriveTarget>::validate(const Snapshot::Xml::PDriveTarget::value_type& value_)
{
	QRegExp q("[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDriveUnit

bool Validatable<Snapshot::Xml::PDriveUnit>::validate(const Snapshot::Xml::PDriveUnit::value_type& value_)
{
	QRegExp q("[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PTimeDelta

bool Validatable<Snapshot::Xml::PTimeDelta>::validate(const Snapshot::Xml::PTimeDelta::value_type& value_)
{
	QRegExp q("(-|\\+)?[0-9]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PTimeZone

bool Validatable<Snapshot::Xml::PTimeZone>::validate(const Snapshot::Xml::PTimeZone::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\+\\-/]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PSpaprvioReg

bool Validatable<Snapshot::Xml::PSpaprvioReg>::validate(const Snapshot::Xml::PSpaprvioReg::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,16}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAliasName

bool Validatable<Snapshot::Xml::PAliasName>::validate(const Snapshot::Xml::PAliasName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\-.]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData5604

bool Validatable<Snapshot::Xml::PData5604>::validate(const Snapshot::Xml::PData5604::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7205

bool Traits<Snapshot::Xml::PData7205>::parse(const QString& src_, Snapshot::Xml::PData7205::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7205>::generate(Snapshot::Xml::PData7205::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData7205>::validate(Snapshot::Xml::PData7205::value_type value_)
{
	if (0 > value_)
		return false;

	if (255 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7207

bool Validatable<Snapshot::Xml::PData7207>::validate(const Snapshot::Xml::PData7207::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7209

bool Traits<Snapshot::Xml::PData7209>::parse(const QString& src_, Snapshot::Xml::PData7209::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7209>::generate(Snapshot::Xml::PData7209::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData7209>::validate(Snapshot::Xml::PData7209::value_type value_)
{
	if (0 > value_)
		return false;

	if (255 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7211

bool Validatable<Snapshot::Xml::PData7211>::validate(const Snapshot::Xml::PData7211::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7213

bool Traits<Snapshot::Xml::PData7213>::parse(const QString& src_, Snapshot::Xml::PData7213::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7213>::generate(Snapshot::Xml::PData7213::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData7213>::validate(Snapshot::Xml::PData7213::value_type value_)
{
	if (0 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7215

bool Validatable<Snapshot::Xml::PData7215>::validate(const Snapshot::Xml::PData7215::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,6}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7217

bool Traits<Snapshot::Xml::PData7217>::parse(const QString& src_, Snapshot::Xml::PData7217::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7217>::generate(Snapshot::Xml::PData7217::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData7217>::validate(Snapshot::Xml::PData7217::value_type value_)
{
	if (0 > value_)
		return false;

	if (16777215 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7219

bool Validatable<Snapshot::Xml::PData7219>::validate(const Snapshot::Xml::PData7219::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,6}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7221

bool Traits<Snapshot::Xml::PData7221>::parse(const QString& src_, Snapshot::Xml::PData7221::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7221>::generate(Snapshot::Xml::PData7221::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData7221>::validate(Snapshot::Xml::PData7221::value_type value_)
{
	if (0 > value_)
		return false;

	if (16777215 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7223

bool Validatable<Snapshot::Xml::PData7223>::validate(const Snapshot::Xml::PData7223::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,8}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7225

bool Traits<Snapshot::Xml::PData7225>::parse(const QString& src_, Snapshot::Xml::PData7225::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7225>::generate(Snapshot::Xml::PData7225::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7227

bool Validatable<Snapshot::Xml::PData7227>::validate(const Snapshot::Xml::PData7227::value_type& value_)
{
	QRegExp q("[a-fA-F0-9]{32}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7229

bool Validatable<Snapshot::Xml::PData7229>::validate(const Snapshot::Xml::PData7229::value_type& value_)
{
	QRegExp q("[a-fA-F0-9]{8}\\-([a-fA-F0-9]{4}\\-){3}[a-fA-F0-9]{12}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7239

bool Validatable<Snapshot::Xml::PData7239>::validate(const Snapshot::Xml::PData7239::value_type& value_)
{
	QRegExp q("0x[0-9a-eA-E][0-9a-fA-F]?");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7241

bool Validatable<Snapshot::Xml::PData7241>::validate(const Snapshot::Xml::PData7241::value_type& value_)
{
	QRegExp q("0x[fF][0-9a-eA-E]?");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7243

bool Traits<Snapshot::Xml::PData7243>::parse(const QString& src_, Snapshot::Xml::PData7243::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7243>::generate(Snapshot::Xml::PData7243::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData7243>::validate(Snapshot::Xml::PData7243::value_type value_)
{
	if (0 > value_)
		return false;

	if (254 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7245

bool Validatable<Snapshot::Xml::PData7245>::validate(const Snapshot::Xml::PData7245::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7247

bool Traits<Snapshot::Xml::PData7247>::parse(const QString& src_, Snapshot::Xml::PData7247::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7247>::generate(Snapshot::Xml::PData7247::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData7247>::validate(Snapshot::Xml::PData7247::value_type value_)
{
	if (0 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7296

bool Validatable<Snapshot::Xml::PData7296>::validate(const Snapshot::Xml::PData7296::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData4296

bool Traits<Snapshot::Xml::PData4296>::parse(const QString& src_, Snapshot::Xml::PData4296::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData4296>::generate(Snapshot::Xml::PData4296::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData4296>::validate(Snapshot::Xml::PData4296::value_type value_)
{
	if (0 > value_)
		return false;

	if (255 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData4298

bool Validatable<Snapshot::Xml::PData4298>::validate(const Snapshot::Xml::PData4298::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData4300

bool Traits<Snapshot::Xml::PData4300>::parse(const QString& src_, Snapshot::Xml::PData4300::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData4300>::generate(Snapshot::Xml::PData4300::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData4300>::validate(Snapshot::Xml::PData4300::value_type value_)
{
	if (0 > value_)
		return false;

	if (255 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData4302

bool Validatable<Snapshot::Xml::PData4302>::validate(const Snapshot::Xml::PData4302::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7298

bool Traits<Snapshot::Xml::PData7298>::parse(const QString& src_, Snapshot::Xml::PData7298::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7298>::generate(Snapshot::Xml::PData7298::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData7298>::validate(Snapshot::Xml::PData7298::value_type value_)
{
	if (0 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7300

bool Validatable<Snapshot::Xml::PData7300>::validate(const Snapshot::Xml::PData7300::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,6}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData4304

bool Traits<Snapshot::Xml::PData4304>::parse(const QString& src_, Snapshot::Xml::PData4304::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData4304>::generate(Snapshot::Xml::PData4304::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData4304>::validate(Snapshot::Xml::PData4304::value_type value_)
{
	if (0 > value_)
		return false;

	if (16777215 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData4306

bool Validatable<Snapshot::Xml::PData4306>::validate(const Snapshot::Xml::PData4306::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,6}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7302

bool Traits<Snapshot::Xml::PData7302>::parse(const QString& src_, Snapshot::Xml::PData7302::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7302>::generate(Snapshot::Xml::PData7302::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData7302>::validate(Snapshot::Xml::PData7302::value_type value_)
{
	if (0 > value_)
		return false;

	if (16777215 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7304

bool Validatable<Snapshot::Xml::PData7304>::validate(const Snapshot::Xml::PData7304::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,8}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7306

bool Traits<Snapshot::Xml::PData7306>::parse(const QString& src_, Snapshot::Xml::PData7306::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData7306>::generate(Snapshot::Xml::PData7306::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PData7308

bool Validatable<Snapshot::Xml::PData7308>::validate(const Snapshot::Xml::PData7308::value_type& value_)
{
	QRegExp q("[a-fA-F0-9]{32}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData4308

bool Validatable<Snapshot::Xml::PData4308>::validate(const Snapshot::Xml::PData4308::value_type& value_)
{
	QRegExp q("[a-fA-F0-9]{8}\\-([a-fA-F0-9]{4}\\-){3}[a-fA-F0-9]{12}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData4318

bool Validatable<Snapshot::Xml::PData4318>::validate(const Snapshot::Xml::PData4318::value_type& value_)
{
	QRegExp q("0x[0-9a-eA-E][0-9a-fA-F]?");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData4320

bool Validatable<Snapshot::Xml::PData4320>::validate(const Snapshot::Xml::PData4320::value_type& value_)
{
	QRegExp q("0x[fF][0-9a-eA-E]?");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData4322

bool Traits<Snapshot::Xml::PData4322>::parse(const QString& src_, Snapshot::Xml::PData4322::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData4322>::generate(Snapshot::Xml::PData4322::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData4322>::validate(Snapshot::Xml::PData4322::value_type value_)
{
	if (0 > value_)
		return false;

	if (254 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData4324

bool Validatable<Snapshot::Xml::PData4324>::validate(const Snapshot::Xml::PData4324::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData4326

bool Traits<Snapshot::Xml::PData4326>::parse(const QString& src_, Snapshot::Xml::PData4326::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData4326>::generate(Snapshot::Xml::PData4326::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData4326>::validate(Snapshot::Xml::PData4326::value_type value_)
{
	if (0 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct VName

bool Traits<Snapshot::Xml::VName>::parse(const QString& src_, Snapshot::Xml::VName& dst_)
{
	int x;
	mpl::at_c<Snapshot::Xml::VName::types, 0>::type a0;
	x = Marshal<Snapshot::Xml::PDiskTarget>::setString(src_, a0);
	if (0 < x)
	{
		dst_ = a0;
		return true;
	}
	mpl::at_c<Snapshot::Xml::VName::types, 1>::type a1;
	x = Marshal<Snapshot::Xml::PAbsFilePath>::setString(src_, a1);
	if (0 < x)
	{
		dst_ = a1;
		return true;
	}

	return false;
}

QString Traits<Snapshot::Xml::VName>::generate(const Snapshot::Xml::VName& src_)
{
	switch (src_.which())
	{
	case 0:
		return Marshal<Snapshot::Xml::PDiskTarget>::getString(boost::get<mpl::at_c<Snapshot::Xml::VName::types, 0>::type>(src_));
	case 1:
		return Marshal<Snapshot::Xml::PAbsFilePath>::getString(boost::get<mpl::at_c<Snapshot::Xml::VName::types, 1>::type>(src_));
	}
	return QString();
}

///////////////////////////////////////////////////////////////////////////////
// struct VUUID

bool Traits<Snapshot::Xml::VUUID>::parse(const QString& src_, Snapshot::Xml::VUUID& dst_)
{
	int x;
	mpl::at_c<Snapshot::Xml::VUUID::types, 0>::type a0;
	x = Marshal<Snapshot::Xml::PData7308>::setString(src_, a0);
	if (0 < x)
	{
		dst_ = a0;
		return true;
	}
	mpl::at_c<Snapshot::Xml::VUUID::types, 1>::type a1;
	x = Marshal<Snapshot::Xml::PData4308>::setString(src_, a1);
	if (0 < x)
	{
		dst_ = a1;
		return true;
	}

	return false;
}

QString Traits<Snapshot::Xml::VUUID>::generate(const Snapshot::Xml::VUUID& src_)
{
	switch (src_.which())
	{
	case 0:
		return Marshal<Snapshot::Xml::PData7308>::getString(boost::get<mpl::at_c<Snapshot::Xml::VUUID::types, 0>::type>(src_));
	case 1:
		return Marshal<Snapshot::Xml::PData4308>::getString(boost::get<mpl::at_c<Snapshot::Xml::VUUID::types, 1>::type>(src_));
	}
	return QString();
}

///////////////////////////////////////////////////////////////////////////////
// struct VIpAddr

bool Traits<Snapshot::Xml::VIpAddr>::parse(const QString& src_, Snapshot::Xml::VIpAddr& dst_)
{
	int x;
	mpl::at_c<Snapshot::Xml::VIpAddr::types, 0>::type a0;
	x = Marshal<Snapshot::Xml::PIpv4Addr>::setString(src_, a0);
	if (0 < x)
	{
		dst_ = a0;
		return true;
	}
	mpl::at_c<Snapshot::Xml::VIpAddr::types, 1>::type a1;
	x = Marshal<Snapshot::Xml::PIpv6Addr>::setString(src_, a1);
	if (0 < x)
	{
		dst_ = a1;
		return true;
	}

	return false;
}

QString Traits<Snapshot::Xml::VIpAddr>::generate(const Snapshot::Xml::VIpAddr& src_)
{
	switch (src_.which())
	{
	case 0:
		return Marshal<Snapshot::Xml::PIpv4Addr>::getString(boost::get<mpl::at_c<Snapshot::Xml::VIpAddr::types, 0>::type>(src_));
	case 1:
		return Marshal<Snapshot::Xml::PIpv6Addr>::getString(boost::get<mpl::at_c<Snapshot::Xml::VIpAddr::types, 1>::type>(src_));
	}
	return QString();
}

///////////////////////////////////////////////////////////////////////////////
// struct VName1

bool Traits<Snapshot::Xml::VName1>::parse(const QString& src_, Snapshot::Xml::VName1& dst_)
{
	int x;
	mpl::at_c<Snapshot::Xml::VName1::types, 0>::type a0;
	x = Marshal<Snapshot::Xml::PDnsName>::setString(src_, a0);
	if (0 < x)
	{
		dst_ = a0;
		return true;
	}
	mpl::at_c<Snapshot::Xml::VName1::types, 1>::type a1;
	x = Marshal<Snapshot::Xml::VIpAddr>::setString(src_, a1);
	if (0 < x)
	{
		dst_ = a1;
		return true;
	}

	return false;
}

QString Traits<Snapshot::Xml::VName1>::generate(const Snapshot::Xml::VName1& src_)
{
	switch (src_.which())
	{
	case 0:
		return Marshal<Snapshot::Xml::PDnsName>::getString(boost::get<mpl::at_c<Snapshot::Xml::VName1::types, 0>::type>(src_));
	case 1:
		return Marshal<Snapshot::Xml::VIpAddr>::getString(boost::get<mpl::at_c<Snapshot::Xml::VName1::types, 1>::type>(src_));
	}
	return QString();
}

} // namespace Libvirt
