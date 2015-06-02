///////////////////////////////////////////////////////////////////////////////
///
/// @file Task_ExecCt.h
///
/// @author igor
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
/////////////////////////////////////////////////////////////////////////////////

#ifndef __Task_ExecCt_H__
#define __Task_ExecCt_H__

#include "CDspService.h"
#include "CDspVzHelper.h"
#include "CDspTaskHelper.h"
#include "XmlModel/VmDirectory/CVmDirectory.h"
#include "Libraries/ProtoSerializer/CProtoCommands.h"

using namespace Parallels;

class Task_ExecCt;
class Task_ResponseProcessor : public CDspTaskHelper
{
	Q_OBJECT

public:
	Task_ResponseProcessor(const SmartPtr<CDspClient>& pClient,
			const SmartPtr<IOPackage>& p, Task_ExecCt *pExec);
	virtual ~Task_ResponseProcessor();
	void waitForStart();

private:
	virtual PRL_RESULT prepareTask();
	virtual PRL_RESULT run_body();
	virtual void cancelOperation(SmartPtr<CDspClient>, const SmartPtr<IOPackage> &);

public slots:
	void slotProcessStdin(const SmartPtr<IOPackage>& p);
	void slotProcessFin();

private:
	bool m_bStarted;
	QString m_sSessionUuid;
	QString m_sGuestSessionUuid;
	Task_ExecCt *m_pExec;
	QMutex m_mutex;
	QWaitCondition m_cond;
};

class Task_ExecCt : public CDspTaskHelper
{
public:
	Task_ExecCt(const SmartPtr<CDspClient>& pClient,
			const SmartPtr<IOPackage>& p);
	virtual ~Task_ExecCt();

	int sendEvent(int type);
	void processStdin(const SmartPtr<IOPackage>& p);
	void wakeUp();
	const QString &getSessionUuid() const  { return m_sSessionUuid; }
	const QString &getGuestSessionUuid() const  { return m_sGuestSessionUuid; }

private:
	CProtoCommandDspWsResponse *getResponseCmd();
private:
	virtual PRL_RESULT prepareTask();
	virtual PRL_RESULT run_body();
	virtual void finalizeTask();
	virtual void cancelOperation(SmartPtr<CDspClient>, const SmartPtr<IOPackage> &);
	virtual QString getVmUuid() { return m_sVmUuid; }
	int getStdEvtTypeByFd(int fd);
	int sendStdData(int &fd);
	int sendToClient(int type, const char *data, int size);
	PRL_RESULT startResponseProcessor();
	PRL_RESULT processStd();
	PRL_RESULT execCmd();

private:
	unsigned int m_nFlags;
	unsigned int m_nTimeout;
	QMutex m_mutex;
	QWaitCondition m_cond;
	CProtoCommandPtr m_pResponseCmd;
	SmartPtr<CDspClient> m_ioClient;
	CVzExecHelper m_exec;
	CDspTaskFuture<Task_ResponseProcessor> m_pResponseProcessor;
	QString m_sVmUuid;
	QString m_sSessionUuid;
	QString m_sGuestSessionUuid;
	int m_stdinfd[2];
	int m_stdoutfd[2];
	int m_stderrfd[2];
	bool m_bCancelled;
	bool m_bFinProcessed;
};

#endif	// __Task_ExecCt_H__

