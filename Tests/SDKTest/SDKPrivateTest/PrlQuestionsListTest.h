/////////////////////////////////////////////////////////////////////////////
///
///	@file PrlQuestionsListTest.h
///
///	This file is the part of parallels public SDK library private tests suite.
///	Tests fixture class for testing internal SDK questions list object.
///
///	@author sandro
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
/////////////////////////////////////////////////////////////////////////////
#ifndef PrlQuestionsListTest_H
#define PrlQuestionsListTest_H

#include <QtTest/QtTest>
#include "SDK/Handles/Disp/PrlQuestionsList.h"
#include "SDK/Wrappers/SdkWrap/SdkHandleWrap.h"

class PrlQuestionsListTest : public QObject
{

Q_OBJECT

private slots:
	void cleanup();
	void testRegisterQuestionObject();
	void testUnregisterQuestionObject();
	void testGetQuestionsByIssuerId();

private:
	QList<SdkHandleWrap> m_lstEventsHandles;
};

#endif
