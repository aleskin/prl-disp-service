/////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2006-2015 Parallels IP Holdings GmbH
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
/// @file
///		AutoHelpers
///
/// @author
///		sergeyt
///
/// @brief
///		Helpers to auto delete vm/ restore settings etc.
///
/// @brief
///		None.
///
/////////////////////////////////////////////////////////////////////////////

#ifndef H__AutoHelpers__H
#define H__AutoHelpers__H

#include "SimpleServerWrapper.h"
#include "Tests/CommonTestsUtils.h"

#include "XmlModel/VmConfig/CVmConfiguration.h"
#include "Libraries/PrlUuid/Uuid.h"
#include "Libraries/Std/SmartPtr.h"
#include "Libraries/Std/PrlAssert.h"
#include "XmlModel/Messaging/CVmEvent.h"
#include "Libraries/HostUtils/HostUtils.h"
#include "Libraries/Std/PrlTime.h"
#include "Libraries/Std/SmartPtr.h"
#include "Libraries/PrlCommonUtils/CAuthHelper.h"
#include "Libraries/PrlCommonUtils/CFileHelper.h"
#include "Libraries/NonQtUtils/CQuestionHelper.h"

#include "Libraries/ProtoSerializer/CProtoSerializer.h"


#include "XmlModel/DispConfig/CDispCommonPreferences.h"

#include <prlsdk/PrlApiDeprecated.h>
#include "Interfaces/ParallelsSdkPrivate.h"


class AutoDirRemover;
class DirCopy;
class AutoRestorer;
class RestoreCommonPrefs;
class AutoRestoreCommonPrefs;
class RestoreLicense;
class AutoRestoreLicense;
class FinalizerBase;
class AutoDeleteVm;
class AutoStopVm;
class AutoRevertCommonPrefsChanges;

/*
		 ================ HEADER of MACROSES =================
		// generated by  $ grep ^#define AutoHelpers.h
		=======================================================

#define QVERIFY_BRES( _bRes, _expression ) \
#define QVERIFY_EXPRESSION( _expression ) \
#define GET_SRV_CONFIG(hServerHandle, hOutSrvConfig ) \
#define SET_DEFAULT_CONFIG_EX( hServerHandle, vmName, out_hVm, os_version, create_devices) \
#define SET_DEFAULT_CONFIG(out_hVm, os_version, create_devices) \
#define EXTRACT_CONFIG_AS_XML_MODEL_OBJECT(hVm, pOutVmConfig)\
#define EXTRACT_HANDLE_AS_XML_MODEL_OBJECT( _hVmInfo, _outXmlObj ) \
#define RECEIVE_USER_PROFILE(hServer, hUserProfile)\
#define FILL_DEFAULT_VM_FOLDER(oldVmRootDir, hUserProfile) \
#define CONVERT_DISPCONF_HANDLE_TO_XML_OBJECT( hDispConfig, refCDispCommonPreferences ) \
#define CONVERT_VMCONF_HANDLE_TO_XML_OBJECT( hVm, refVmConfig ) \
#define TRY_GET_VM_AFTER_GET_VM_LIST( _hJob, _sVmUuid, _hOutVmHandle )\
#define GET_EVENT_PARAM_LIST_BY_NAME( _hEvent, _paramName, _out_lstHandles )    \
#define GET_EVENT_PARAM_BY_NAME( _hEvent, _paramName, _paramValueHandle )       \
#define GET_EVENT_PARAM_BY_NAME_AS_STRING( _hEvent, _paramName, _paramValue ) \

		 ================ END of HEADER of MACROSES defined here =================
*/

// QVERIFY_BRES is deprecated
#define QVERIFY_BRES( _bRes, _expression ) \
{	_bRes = false; (_expression); QVERIFY(_bRes); }

#define GET_SRV_CONFIG(hServerHandle, hOutSrvConfig ) \
{	\
		SdkHandleWrap hJob(PrlSrv_GetSrvConfig(hServerHandle));\
		CHECK_JOB_RET_CODE(hJob)\
		SdkHandleWrap hResult;\
		CHECK_RET_CODE_EXP(PrlJob_GetResult(hJob, hResult.GetHandlePtr()))\
		SdkHandleWrap _hSrvConfig;\
		CHECK_RET_CODE_EXP(PrlResult_GetParam(hResult, _hSrvConfig.GetHandlePtr()))\
		hOutSrvConfig = _hSrvConfig; \
}

#define SET_DEFAULT_CONFIG_EX( _hServerHandle, _vmName, out_hVm, _os_version, _create_devices) \
	{	\
		SdkHandleWrap _hSrvConfig; \
		GET_SRV_CONFIG( _hServerHandle, _hSrvConfig ); \
		\
		SdkHandleWrap _hVm;\
		CHECK_RET_CODE_EXP(PrlSrv_CreateVm(_hServerHandle, _hVm.GetHandlePtr()))\
		CHECK_RET_CODE_EXP(PrlVmCfg_SetDefaultConfig(_hVm, _hSrvConfig, _os_version, _create_devices));\
		CHECK_RET_CODE_EXP(PrlVmCfg_SetName(_hVm, QSTR2UTF8(_vmName) ) );\
		out_hVm = _hVm; \
	}

#define SET_DEFAULT_CONFIG(out_hVm, os_version, create_devices) \
	SET_DEFAULT_CONFIG_EX(m_ServerHandle, GEN_VM_NAME_BY_TEST_FUNCTION() \
	, out_hVm, os_version, create_devices );


#define EXTRACT_CONFIG_AS_XML_MODEL_OBJECT(hVm, pOutVmConfig)\
{ \
	PRL_VOID_PTR pVmConfig = 0;\
	QVERIFY(PRL_SUCCEEDED(PrlVm_ToString(hVm, &pVmConfig)));\
	QString sVmConfig = UTF8_2QSTR((const char *)pVmConfig);\
	PrlBuffer_Free(pVmConfig);\
	pOutVmConfig->fromString(sVmConfig);\
	CHECK_RET_CODE_EXP(pOutVmConfig->m_uiRcInit) \
}


#define EXTRACT_HANDLE_AS_XML_MODEL_OBJECT( _hVmInfo, _outXmlObj ) \
{ \
	PRL_VOID_PTR pXml = 0; \
	CHECK_RET_CODE_EXP(PrlHandle_ToString(_hVmInfo, &pXml)); \
	CHECK_RET_CODE_EXP( _outXmlObj.fromString( UTF8_2QSTR((PRL_CONST_STR )pXml) ) ); \
	PrlBuffer_Free(pXml); \
}

#define RECEIVE_USER_PROFILE(hServer, hUserProfile)\
{ \
	SdkHandleWrap hResult; \
	SdkHandleWrap hJob(PrlSrv_GetUserProfile(hServer));\
	CHECK_JOB_RET_CODE(hJob)\
	QVERIFY(PRL_SUCCEEDED(PrlJob_GetResult(hJob, hResult.GetHandlePtr())));\
	QVERIFY(PRL_SUCCEEDED(PrlResult_GetParam(hResult, hUserProfile.GetHandlePtr())));\
	PRL_HANDLE_TYPE _type = PHT_ERROR;\
	QVERIFY(PRL_SUCCEEDED(PrlHandle_GetType(hUserProfile, &_type)));\
	QVERIFY(_type == PHT_USER_PROFILE); \
	\
}

#define FILL_DEFAULT_VM_FOLDER(oldVmRootDir, hUserProfile) \
{ \
	char buff[2048]; \
	PRL_UINT32 szBuff=sizeof(buff); \
	QVERIFY( PRL_SUCCEEDED(PrlUsrCfg_GetDefaultVmFolder( hUserProfile, buff, &szBuff ) ) ); \
	oldVmRootDir = UTF8_2QSTR( buff );	\
}

#define CONVERT_DISPCONF_HANDLE_TO_XML_OBJECT( hDispConfig, refCDispCommonPreferences ) \
{	\
	PRL_VOID_PTR pResString = 0; \
	CHECK_RET_CODE_EXP(PrlDispCfg_ToString(hDispConfig, &pResString)); \
	QString sCommonPrefs = UTF8_2QSTR((const char *)pResString);	\
	PrlBuffer_Free(pResString);	\
	CHECK_RET_CODE_EXP(refCDispCommonPreferences.fromString(sCommonPrefs)); \
}

#define CONVERT_VMCONF_HANDLE_TO_XML_OBJECT( hVm, refVmConfig ) \
{	\
	PRL_VOID_PTR pResString = 0; \
	CHECK_RET_CODE_EXP(PrlVm_ToString(hVm, &pResString)); \
	QString sConf = UTF8_2QSTR((const char *)pResString);	\
	PrlBuffer_Free(pResString);	\
	CHECK_RET_CODE_EXP(refVmConfig.fromString(sConf)); \
}

#define TRY_GET_VM_AFTER_GET_VM_LIST( _hJob, _sVmUuid, _hOutVmHandle )\
{ \
	_hOutVmHandle.reset(); \
	SdkHandleWrap _hResult;\
	CHECK_RET_CODE_EXP(PrlJob_GetResult(_hJob, _hResult.GetHandlePtr()))\
	PRL_UINT32 nParamsCount = 0;\
	CHECK_RET_CODE_EXP(PrlResult_GetParamsCount(_hResult, &nParamsCount))\
	QVERIFY(nParamsCount > 0);\
	for (PRL_UINT32 i = 0; i < nParamsCount; ++i)\
	{\
		SdkHandleWrap _hVm;\
		CHECK_RET_CODE_EXP(PrlResult_GetParamByIndex(_hResult, i, _hVm.GetHandlePtr()))\
		QString _Id; \
		PRL_EXTRACT_STRING_VALUE(_Id, _hVm, PrlVmCfg_GetUuid); \
		if (_Id == _sVmUuid )\
		{\
			_hOutVmHandle = _hVm;\
			break;\
		}\
	}\
}

#define GET_EVENT_PARAM_LIST_BY_NAME( _hEvent, _paramName, _out_lstHandles )	\
{	\
	QList<SdkHandleWrap>& lstHandles = _out_lstHandles;	\
	lstHandles.clear();	\
	\
	uint paramCount = 0;	\
	CHECK_RET_CODE_EXP( PrlEvent_GetParamsCount( _hEvent, &paramCount ) );	\
	for ( uint i = 0; i < paramCount; ++i )	\
	{	\
		SdkHandleWrap hParam;	\
		CHECK_RET_CODE_EXP( PrlEvent_GetParam( _hEvent, i, hParam.GetHandlePtr() ) );	\
		\
		QString name;	\
		PRL_EXTRACT_STRING_VALUE( name, hParam, PrlEvtPrm_GetName );	\
		if ( name == _paramName )	\
			lstHandles << hParam;	\
	}	\
}

#define GET_EVENT_PARAM_BY_NAME( _hEvent, _paramName, _paramValueHandle )	\
{	\
	QList<SdkHandleWrap> _lstHandles;	\
	GET_EVENT_PARAM_LIST_BY_NAME( _hEvent, _paramName, _lstHandles );	\
	QVERIFY( !_lstHandles.isEmpty() );	\
	QVERIFY( _lstHandles.size() == 1 );	\
	_paramValueHandle = _lstHandles[0];	\
}

#define GET_EVENT_PARAM_BY_NAME_AS_STRING( _hEvent, _paramName, _paramValue ) \
{	\
	QString& sValue = _paramValue;	\
	SdkHandleWrap hValue;	\
	GET_EVENT_PARAM_BY_NAME( _hEvent, _paramName, hValue );	\
	PRL_EXTRACT_STRING_VALUE( sValue, hValue, PrlEvtPrm_ToString );	\
}

class DirCopy
{
public:
	static bool copy( const QString& src, const QString& dest )
	{
		if( !QFileInfo(src).isDir() )
		{
			PRL_ASSERT("DirCopy::copy() error." == NULL );
			return false;
		}

		QString cmd;
#ifdef _WIN_
		QString real_dest =  dest;
		// hack because on windows if dest exists xcopy() copy only content of src.
		if( QFileInfo(dest).exists() )
			real_dest = QString("%1/%2").arg(dest).arg( QFileInfo(src).fileName() );
		cmd = QString("xcopy \"%1\" \"%2\" /s /i /e /q").arg(src).arg(real_dest);
#else
		cmd = QString("cp -R \"%1\" \"%2\" ").arg(src).arg(dest);
#endif
		return 0 == system( QSTR2UTF8( cmd ) );
	}
};


//////////////////////////////////////////////////////////////////////////
class AutoDirRemover
{
	QStringList m_lstToDelete;
public:
	~AutoDirRemover();

	bool add( const QString& dirPath );
	bool del( const QString& dirPath );
};
typedef SmartPtr<AutoDirRemover> AutoDirRemoverPtr;

//////////////////////////////////////////////////////////////////////////

typedef void (AutoRestorer::*rollback_call)( SmartPtr<CVmEvent> );

class AutoRestorer
{
public:
	//             method,        parameters
	typedef QPair< rollback_call, SmartPtr<CVmEvent> > RollbackMethod;

	class RollbackOperation
	{	friend class AutoRestorer;
	public:
		virtual ~RollbackOperation() {}
	protected:
		virtual void operation() = 0;
	};

	void addRollback( const RollbackMethod& op)
	{
		m_lstRollbackMeth.append( op );
	}

	void addRollback( SmartPtr<RollbackOperation> op )
	{
		m_lstRollbacks.append( op );
	}

	virtual ~AutoRestorer()
	{
		// TODO: need change to RollbackOperation.
		foreach( RollbackMethod meth, m_lstRollbackMeth )
		{
			rollback_call call = meth.first;
			(this->*call)( meth.second );
		}
		foreach( SmartPtr<RollbackOperation> op, m_lstRollbacks )
		{
			op->operation();
		}

	}

private:
	QList< RollbackMethod > m_lstRollbackMeth;

	typedef SmartPtr<RollbackOperation> RollbackOperationPtr;
	QList< RollbackOperationPtr > m_lstRollbacks;

public:
	//////////////////////////////////////////////////////////////////////////
	// Rollbacks
	//
	void restoreUserVmFolder( SmartPtr<CVmEvent> params);

	void renameDirBack( SmartPtr<CVmEvent> params);
};
typedef AutoRestorer::RollbackOperation RollbackOperation;


class RestoreCommonPrefs:
	public AutoRestorer::RollbackOperation
{
public:
	RestoreCommonPrefs( SdkHandleWrap hServerHandle, SdkHandleWrap hDispConfig)
		:m_hServerHandle(hServerHandle), m_hDispConfig(hDispConfig)
	{}
private:
	virtual void operation();
private:
	SdkHandleWrap m_hServerHandle;
	SdkHandleWrap m_hDispConfig;
};

class AutoRestoreCommonPrefs
{
public:
	AutoRestoreCommonPrefs( SdkHandleWrap hServerHandle );
private:
	AutoRestorer m_autoRestorer;
};

class RestoreLicenseCreds:
	public AutoRestorer::RollbackOperation
{
public:
	RestoreLicenseCreds( SdkHandleWrap hServerHandle );
private:
	virtual void operation();
private:
	SdkHandleWrap m_hServerHandle;
	QString username;
	QString company;
};

class AutoRestoreLicenseCreds
{
public:
	AutoRestoreLicenseCreds( SdkHandleWrap hServerHandle );
private:
	AutoRestorer m_autoRestorer;
};

class FinalizerBase
{
protected:
	virtual void finalize() = 0;
	virtual ~FinalizerBase() { }
};

class AutoDeleteVm: public FinalizerBase
{
public:
	AutoDeleteVm( SdkHandleWrap vmHandle ):m_vmHandle( vmHandle ){}
	~AutoDeleteVm() {finalize();}
protected:
	virtual void finalize()
	{
		WRITE_TRACE( DBG_DEBUG, "AutoDeleteVm" );

#if 0
		char sHomePath[2048];
		PRL_UINT32 uiLen = sizeof(sHomePath);
		CHECK_RET_CODE_EXP( PrlVmCfg_GetHomePath( m_vmHandle, sHomePath, &uiLen) );
		WRITE_TRACE( DBG_FATAL, "DEBUG: AutoDeleteVm: START INFINITY WAIT BEFORE DELETE VM. path = %s"
			, sHomePath );
		HostUtils::Sleep(24*60*60*1000);
#endif

		if( ! m_vmHandle.valid() )
			return;

		DELETE_VM(m_vmHandle)
	}
private:
	SdkHandleWrap m_vmHandle;
};

class AutoStopVm: public FinalizerBase
{
public:
	AutoStopVm( SdkHandleWrap vmHandle ):m_vmHandle( vmHandle ){}
	~AutoStopVm() {finalize();}
protected:
	virtual void finalize();

private:
	SdkHandleWrap m_vmHandle;
};

class AutoRevertCommonPrefsChanges: public FinalizerBase
{
public:
	AutoRevertCommonPrefsChanges(
		SdkHandleWrap hServerHandle,
		SdkHandleWrap hCommonPrefs,
		const CDispCommonPreferences& backup)
		:m_ServerHandle(hServerHandle)
		, m_hCommonPrefs(hCommonPrefs)
		, m_CommonPrefs( backup )
	{}
	~AutoRevertCommonPrefsChanges() {finalize();}
protected:
	virtual void finalize()
	{
		WRITE_TRACE( DBG_INFO, "AutoRevertCommonPrefsChanges" );
		SdkHandleWrap hJob(PrlSrv_CommonPrefsBeginEdit(m_ServerHandle));
		CHECK_JOB_RET_CODE(hJob);

		CHECK_RET_CODE_EXP(PrlDispCfg_FromString(m_hCommonPrefs, m_CommonPrefs.toString().toUtf8().data()));
		hJob.reset(PrlSrv_CommonPrefsCommit(m_ServerHandle, m_hCommonPrefs));
		CHECK_JOB_RET_CODE(hJob);
	}
private:
	SdkHandleWrap m_ServerHandle;
	SdkHandleWrap m_hCommonPrefs;
	CDispCommonPreferences m_CommonPrefs;
};

#endif // H__AutoHelpers__H

