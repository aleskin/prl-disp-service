/////////////////////////////////////////////////////////////////////////////
///
/// Copyright (c) 2006-2017, Parallels International GmbH
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
/// Our contact details: Parallels International GmbH, Vordergasse 59, 8200
/// Schaffhausen, Switzerland.
///
/// @file
///		CommonTestsUtils.h
///
/// @author
///		sergeyt, aleksandera
///
/// @brief
///		Common utils using at all dispatcher API tests suites classes.
///
/// @brief
///		None.
///
/////////////////////////////////////////////////////////////////////////////
#ifndef CommonTestsUtils_H
#define CommonTestsUtils_H

#include <prlcommon/Interfaces/ParallelsNamespace.h>
#include <prlcommon/Interfaces/ParallelsNamespaceTests.h>
#include <prlsdk/PrlEnums.h>

#include <QList>
#include <QString>
#include <QtTest/QtTest>
#include <prlcommon/Logging/Logging.h>
#include <prlcommon/PrlCommonUtilsBase/PrlStringifyConsts.h>
#include <prlsdk/helpers/SdkWrap/SdkHandleWrap.h>

#define PRL_JOB_WAIT_TIMEOUT 18000
#define STR_BUF_LENGTH 32768

/*
		 ================ HEADER of MACROSES defined here =================
		 // generated by  $ grep ^#define CommonTestsUtils.h
		=====================================================================

#define GEN_VM_NAME_BY_TEST_FUNCTION() \
#define CHECK_RET_CODE_EXP(expression)\
#define CHECK_CONCRETE_EXPRESSION_RET_CODE(expression, retcode)\
#define CHECK_JOB_RET_CODE(_hJobOperation)\
#define GET_JOB_RET_CODE_EX(_hJobOperation, _nRetCode )\
#define GET_JOB_RET_CODE(_hJob)\
#define HANDLE_TO_STRING(handle)\
#define HANDLE_TO_STRING_EX( handle, outStr ) \
#define CHECK_HANDLE_TYPE(handle, expected_type)\
#define EXECUTE_TESTS_SUITE(TESTS_SUITE_CLASS_NAME)\
#define OUTPUT_HANDLES_NUM_FOR_TYPE(handle_type)\
#define CHECK_ASYNC_OP_FAILED(operation, expectedErrCode)\
#define CHECK_ASYNC_OP_SUCCEEDED(operation)\
#define CHECK_RET_CODE(_ret_code)\
#define CALL_CMD(cmd, expecting_response_code)\
#define TEST_BEHAVIOR_ON_NULL_BUF_SIZE(handle, sdk_call)\
#define PRL_EXTRACT_STRING_VALUE(result_string, handle, sdk_method)\
#define PRL_EXTRACT_STRING_VALUE_BY_INDEX(result_string, handle, index, sdk_method)\
#define CHECK_EVENT_PARAMETER(pEvent, param_name, param_type, param_value)\
#define PRL_CHECK_STRINGS_LIST(handle, extract_list_method, expected_list_values)\
#define DELETE_VM(hVm)\
#define PRL_CHECK_PERMISSION(hVm, perm_id, perm_allowed)\
#define PRL_SHARE_VM(hVm, sharing_mode)\
#define WAIT_ANY_QUESTION(hQuestion, _nTotalWaitTime)\
#define WAIT_FOR_VM_STATE(hVm, state)\
#define VM_CONFIG_INIT \
#define VM_CONFIG_TO_XML_OBJECT \
#define VM_CONFIG_FROM_XML_OBJECT \
#define CHECK_PARAMS_COUNT(hResult, expected_count)\
#define SKIP_IF_EXTERNAL_BUILD \
#define GET_RESULT_AFTER_ASYNC_CALL_WITH_COPY(SDK_CALL, _hConvertedResult, _hConvertedResultCopy ) \
#define GET_RESULT_AFTER_ASYNC_CALL(SDK_CALL, _hConvertedResult ) \
#define SET_LICENCE_USER_AND_COMPANY(hServer, username, company) \
#define GET_LICENSE_INFO \
#define VERIFY_WITH_BOOL_RETURN(statement) \
#define CHECK_RET_CODE_EXP_WITH_BOOL_RETURN(expression) \
#define WAIT_AND_ANSWER_SERVER_QUESTION( hServer, question, answer, timeoutMsec ) \

		 ================ END of HEADER of MACROSES defined here =================
*/

#define GEN_VM_NAME_BY_TEST_FUNCTION() \
	QString("%1_%2").arg(QTest::currentTestFunction()).arg( qrand() )

#define QVERIFY_EXPRESSION( _expression ) \
{	(_expression); QVERIFY( ! QTest::currentTestFailed() ); }

#define CHECK_RET_CODE_EXP(expression)\
	{\
		PRL_RESULT nExprRetCode = (expression);\
		if (PRL_FAILED(nExprRetCode))\
			WRITE_TRACE(DBG_FATAL, "Expression: '%s' nRetCode=%.8X '%s'", #expression, nExprRetCode, PRL_RESULT_TO_STRING(nExprRetCode));\
		QCOMPARE(nExprRetCode, PRL_ERR_SUCCESS);\
	}

#define CHECK_CONCRETE_EXPRESSION_RET_CODE(expression, retcode)\
	{\
		PRL_RESULT nRetCode = (expression);\
		if (nRetCode != retcode)\
			WRITE_TRACE(DBG_FATAL, "Expression: '%s' expected %.8X '%s' but %.8X '%s' was received", #expression,\
					retcode, PRL_RESULT_TO_STRING(retcode), nRetCode, PRL_RESULT_TO_STRING(nRetCode));\
		QVERIFY(nRetCode == retcode);\
	}

#define CHECK_JOB_RET_CODE_TM(_hJobOperation, nTimeout)\
	{\
		SdkHandleWrap _hJob(_hJobOperation); \
		QVERIFY(PRL_INVALID_HANDLE != _hJob); \
		PRL_HANDLE_TYPE nJobType = PHT_ERROR; \
		CHECK_RET_CODE_EXP(PrlHandle_GetType(_hJob, &nJobType)); \
		QCOMPARE(nJobType, PHT_JOB); \
		PRL_RESULT nJobWaitRetCode = PrlJob_Wait(_hJob, nTimeout);\
		if (nJobWaitRetCode == PRL_ERR_TIMEOUT)\
			CHECK_RET_CODE_EXP(PrlJob_Wait(_hJob, 10*nTimeout))\
		else\
			CHECK_RET_CODE_EXP(nJobWaitRetCode)\
		PRL_RESULT _ret_code = PRL_ERR_UNINITIALIZED;\
		CHECK_RET_CODE_EXP(PrlJob_GetRetCode(_hJob, &_ret_code))\
		if (PRL_FAILED(_ret_code))\
			WRITE_TRACE(DBG_FATAL, "_ret_code=%.8X '%s'", _ret_code, PRL_RESULT_TO_STRING(_ret_code));\
		QCOMPARE(_ret_code, PRL_ERR_SUCCESS);\
	}

#define CHECK_JOB_RET_CODE(_hJobOperation) \
		CHECK_JOB_RET_CODE_TM(_hJobOperation, PRL_JOB_WAIT_TIMEOUT)


#define GET_JOB_RET_CODE_EX(_hJobOperation, _nRetCode )\
	{\
	SdkHandleWrap _hJob(_hJobOperation); \
	PRL_RESULT nJobWaitRetCode = PrlJob_Wait(_hJob, PRL_JOB_WAIT_TIMEOUT);\
	if (nJobWaitRetCode == PRL_ERR_TIMEOUT)\
	CHECK_RET_CODE_EXP(PrlJob_Wait(_hJob, 10*PRL_JOB_WAIT_TIMEOUT))\
		else\
		CHECK_RET_CODE_EXP(nJobWaitRetCode)\
		_nRetCode = PRL_ERR_UNINITIALIZED;\
		CHECK_RET_CODE_EXP(PrlJob_GetRetCode(_hJob, &_nRetCode))\
		if (PRL_FAILED(_nRetCode))\
		WRITE_TRACE(DBG_FATAL, "nRetCode=%.8X '%s'", _nRetCode, PRL_RESULT_TO_STRING(_nRetCode));\
	}

#define GET_JOB_RET_CODE(_hJob)\
	PRL_RESULT nRetCode = PRL_ERR_UNINITIALIZED;\
	GET_JOB_RET_CODE_EX(_hJob, nRetCode );

#define HANDLE_TO_STRING(handle)\
	PRL_VOID_PTR pData = 0;\
	CHECK_RET_CODE_EXP(PrlHandle_ToString(handle, &pData));\
	QString _str_object = UTF8_2QSTR((const char *)pData);\
	PrlBuffer_Free(pData);

#define HANDLE_TO_STRING_EX( handle, outStr ) \
{ \
	HANDLE_TO_STRING( handle );	\
	outStr = _str_object;	\
}

#define CHECK_HANDLE_TYPE(handle, expected_type)\
	{\
		PRL_HANDLE_TYPE _type = PHT_ERROR;\
		CHECK_RET_CODE_EXP(PrlHandle_GetType(handle, &_type))\
		if (_type != expected_type)\
			WRITE_TRACE(DBG_FATAL, "Expected %d '%s' type but %d '%s' received",\
				expected_type, PRL_HANDLE_TYPE_TO_STRING(expected_type),\
				_type, PRL_HANDLE_TYPE_TO_STRING(_type));\
		QVERIFY(_type == expected_type);\
	}

#define EXECUTE_TESTS_SUITE(TESTS_SUITE_CLASS_NAME)\
	{\
		QStringList argList;\
		if (checkArguments(argc, argv, #TESTS_SUITE_CLASS_NAME ,argList))\
		{\
			TESTS_SUITE_CLASS_NAME _tests_suite;\
			nRet += QTest::qExec(&_tests_suite, argList);\
		}\
	}

#define OUTPUT_HANDLES_NUM_FOR_TYPE(handle_type)\
	{\
		PRL_UINT32 nHandlesNum = 0;\
		PrlDbg_GetHandlesNum(&nHandlesNum, handle_type);\
		if (nHandlesNum != 0)\
			WRITE_TRACE(DBG_FATAL, "WARNING Not all handles were freed. Handles instances of type '%s': %d",\
							PRL_HANDLE_TYPE_TO_STRING(handle_type), nHandlesNum);\
	}

#define CHECK_ASYNC_OP_FAILED(operation, expectedErrCode)\
	{\
		SdkHandleWrap _hJob(operation);\
		QVERIFY(_hJob != PRL_INVALID_HANDLE);\
		CHECK_RET_CODE_EXP(PrlJob_Wait(_hJob, PRL_JOB_WAIT_TIMEOUT*10))\
		PRL_RESULT _ret_code = PRL_ERR_SUCCESS;\
		CHECK_RET_CODE_EXP(PrlJob_GetRetCode(_hJob, &_ret_code))\
		if (_ret_code != expectedErrCode)\
			WRITE_TRACE(DBG_FATAL, "Expecting %.8X '%s' code but received %.8X '%s'", expectedErrCode, PRL_RESULT_TO_STRING(expectedErrCode), _ret_code, PRL_RESULT_TO_STRING(_ret_code));\
		QVERIFY(_ret_code == expectedErrCode);\
	}
#define CHECK_ASYNC_OP_SUCCEEDED(operation)\
	CHECK_ASYNC_OP_FAILED(operation, PRL_ERR_SUCCESS)

#define CHECK_RET_CODE(_ret_code)\
	if (PRL_FAILED(_ret_code))\
	{\
		WRITE_TRACE(DBG_FATAL, "Return code: %.8X '%s'", _ret_code, PRL_RESULT_TO_STRING(_ret_code));\
		QFAIL("Return code not successful!");\
	}

#define CALL_CMD(cmd, expecting_response_code)\
	{\
		m_pHandler->Clear();\
		QString sReqId = cmd;\
		const quint32 nStepInterval = 100;\
		m_pPveControl->WaitForRequestComplete(sReqId, PRL_JOB_WAIT_TIMEOUT);\
		quint32 nWaitTimeout = PRL_JOB_WAIT_TIMEOUT;\
		while (m_pHandler->GetResult().getOpCode() != expecting_response_code && nWaitTimeout)\
		{\
			QCoreApplication::processEvents(QEventLoop::AllEvents);\
			if (nWaitTimeout < nStepInterval)\
				nWaitTimeout = 0;\
			else\
				nWaitTimeout -= nStepInterval;\
		}\
	}

#define TEST_BEHAVIOR_ON_NULL_BUF_SIZE(handle, sdk_call)\
	{\
		PRL_UINT32 nBufSize = 0;\
		CHECK_RET_CODE_EXP(sdk_call(handle, 0, &nBufSize));\
	}

#define PRL_EXTRACT_STRING_VALUE(result_string, handle, sdk_method)\
	{\
		QByteArray _string_value_extracting_buf;\
		PRL_UINT32 nStringValueExtractingBufSize = 0;\
		CHECK_RET_CODE_EXP(sdk_method(handle, 0, &nStringValueExtractingBufSize))\
		QVERIFY(nStringValueExtractingBufSize != 0);\
		_string_value_extracting_buf.resize(nStringValueExtractingBufSize);\
		CHECK_RET_CODE_EXP(sdk_method(handle, _string_value_extracting_buf.data(), &nStringValueExtractingBufSize))\
		result_string = UTF8_2QSTR(_string_value_extracting_buf);\
	}

#define PRL_EXTRACT_STRING_VALUE_BY_INDEX(result_string, handle, index, sdk_method)\
	{\
		QByteArray _string_value_extracting_buf;\
		PRL_UINT32 nStringValueExtractingBufSize = 0;\
		CHECK_RET_CODE_EXP(sdk_method(handle, index, 0, &nStringValueExtractingBufSize))\
		QVERIFY(nStringValueExtractingBufSize != 0);\
		_string_value_extracting_buf.resize(nStringValueExtractingBufSize);\
		CHECK_RET_CODE_EXP(sdk_method(handle, index, _string_value_extracting_buf.data(), &nStringValueExtractingBufSize))\
		result_string = UTF8_2QSTR(_string_value_extracting_buf);\
	}

#define CHECK_EVENT_PARAMETER(pEvent, param_name, param_type, param_value)\
	{\
		CVmEventParameter *pParam = pEvent->getEventParameter(param_name);\
		QVERIFY(pParam != NULL);\
		QVERIFY(pParam->getParamType() == param_type);\
		QCOMPARE(param_value, pParam->getParamValue());\
	}

#define PRL_CHECK_STRINGS_LIST(handle, extract_list_method, expected_list_values)\
	{\
		SdkHandleWrap hStringsList;\
		CHECK_RET_CODE_EXP(extract_list_method(handle, hStringsList.GetHandlePtr()))\
		CHECK_HANDLE_TYPE(hStringsList, PHT_STRINGS_LIST)\
		PRL_UINT32 nItemsCount = 0;\
		CHECK_RET_CODE_EXP(PrlStrList_GetItemsCount(hStringsList, &nItemsCount))\
		QCOMPARE(quint32(nItemsCount), quint32(expected_list_values.size()));\
		for (PRL_UINT32 i = 0; i < nItemsCount; ++i)\
		{\
			QString sItem;\
			PRL_EXTRACT_STRING_VALUE_BY_INDEX(sItem, hStringsList, i, PrlStrList_GetItem)\
			QCOMPARE(sItem, expected_list_values.at(i));\
		}\
	}

#define DELETE_VM(hVm)\
	{\
		PRL_RESULT nRetCode = PRL_ERR_UNINITIALIZED;\
		quint32 nCommonDeletionWaitTime = 100000;\
		const quint32 nTimeout = 1000;\
		while (PRL_FAILED(nRetCode) && nCommonDeletionWaitTime)\
		{\
			SdkHandleWrap hJob;\
			if (PRL_ERR_VM_CONFIG_DOESNT_EXIST == nRetCode)\
				hJob.reset(PrlVm_Unreg(hVm));\
			else\
				hJob.reset(PrlVm_Delete(hVm, PRL_INVALID_HANDLE));\
			PrlJob_Wait(hJob, PRL_JOB_WAIT_TIMEOUT);\
			PrlJob_GetRetCode(hJob, &nRetCode);\
			if (PRL_SUCCEEDED(nRetCode) || PRL_ERR_VM_UUID_NOT_FOUND == nRetCode ||\
				PRL_ERR_NOT_CONNECTED_TO_DISPATCHER == nRetCode || PRL_ERR_UNIMPLEMENTED == nRetCode)\
				break;\
			else\
				WRITE_TRACE(DBG_FATAL, "VM deletion failed with error code: %.8X '%s'", nRetCode, PRL_RESULT_TO_STRING(nRetCode));\
			QTest::qSleep(nTimeout);\
			nCommonDeletionWaitTime -= nTimeout;\
		}\
	}

#define PRL_CHECK_PERMISSION(hVm, perm_id, perm_allowed)\
	{\
		SdkHandleWrap hJob(PrlVm_RefreshConfig(hVm));\
		CHECK_JOB_RET_CODE(hJob)\
		SdkHandleWrap hAccessRights;\
		CHECK_RET_CODE_EXP(PrlVmCfg_GetAccessRights(hVm, hAccessRights.GetHandlePtr()))\
		PRL_BOOL bIsAllowed = PRL_FALSE;\
		CHECK_RET_CODE_EXP(PrlAcl_IsAllowed(hAccessRights, perm_id, &bIsAllowed))\
		QVERIFY(bIsAllowed == perm_allowed);\
	}

#define PRL_SHARE_VM(hVm, sharing_mode)\
	{\
		SdkHandleWrap hJob(PrlVm_RefreshConfig(hVm));\
		CHECK_JOB_RET_CODE(hJob)\
		SdkHandleWrap hAccessRights;\
		CHECK_RET_CODE_EXP(PrlVmCfg_GetAccessRights(hVm, hAccessRights.GetHandlePtr()))\
		CHECK_RET_CODE_EXP(PrlAcl_SetAccessForOthers(hAccessRights, sharing_mode))\
		hJob.reset(PrlVm_UpdateSecurity(hVm, hAccessRights));\
		CHECK_JOB_RET_CODE(hJob)\
	}

#define WAIT_ANY_QUESTION(hQuestion, _nTotalWaitTime)\
{	\
	const unsigned int nTotalWaitTime = (_nTotalWaitTime);\
	const unsigned int nSingleShotWaitTime = 500;\
	SdkHandleWrap& _hQuestion = hQuestion;\
	bool bQuestionFound = false;\
	for (unsigned int i = 0; i < nTotalWaitTime/nSingleShotWaitTime; ++i)\
	{\
		SdkHandleWrap hQuestionsList;\
		CHECK_RET_CODE_EXP(PrlSrv_GetQuestions(m_ServerHandle, hQuestionsList.GetHandlePtr()))\
		PRL_UINT32 nQuestionsCount = 0;\
		CHECK_RET_CODE_EXP(PrlHndlList_GetItemsCount(hQuestionsList, &nQuestionsCount))\
		for (PRL_UINT32 j = 0; j < nQuestionsCount; ++j)\
		{\
			CHECK_RET_CODE_EXP(PrlHndlList_GetItem(hQuestionsList, j, _hQuestion.GetHandlePtr()))\
			CHECK_HANDLE_TYPE(_hQuestion, PHT_EVENT)\
			bQuestionFound = true;\
			break;\
		}\
		if (bQuestionFound)\
			break;\
		HostUtils::Sleep(nSingleShotWaitTime);\
	} \
}

#define WAIT_FOR_VM_STATE(hVm, state)\
{\
	VIRTUAL_MACHINE_STATE nVmState;\
	for(int i = 0; i < 60; i++)\
	{\
		SdkHandleWrap hJob(PrlVm_GetState(hVm));\
		CHECK_JOB_RET_CODE(hJob);\
		SdkHandleWrap hResult;\
		CHECK_RET_CODE_EXP(PrlJob_GetResult(hJob, hResult.GetHandlePtr()));\
		SdkHandleWrap hVmInfo;\
		CHECK_RET_CODE_EXP(PrlResult_GetParam(hResult, hVmInfo.GetHandlePtr()));\
		CHECK_RET_CODE_EXP(PrlVmInfo_GetState(hVmInfo, &nVmState));\
		if ( nVmState == state )\
			break;\
		HostUtils::Sleep(1000);\
	}\
	QCOMPARE( nVmState, state );\
}

#define VM_CONFIG_INIT \
	CVmConfiguration _vm_conf; \
	CHECK_RET_CODE_EXP(PrlSrv_CreateVm(m_ServerHandle, m_VmHandle.GetHandlePtr()))

#define VM_CONFIG_TO_XML_OBJECT \
{ \
	PRL_VOID_PTR pXml = 0; \
	CHECK_RET_CODE_EXP(PrlHandle_ToString(m_VmHandle, &pXml)); \
	_vm_conf.fromString( UTF8_2QSTR((PRL_CONST_STR )pXml) ); \
	PrlBuffer_Free(pXml); \
}

#define VM_CONFIG_FROM_XML_OBJECT \
	CHECK_RET_CODE_EXP(PrlHandle_FromString( m_VmHandle, QSTR2UTF8(_vm_conf.toString()) ));

#define CHECK_PARAMS_COUNT(hResult, expected_count)\
	{\
		PRL_UINT32 nCheckParamsCount = 0;\
		CHECK_RET_CODE_EXP(PrlResult_GetParamsCount((hResult), &nCheckParamsCount))\
		QCOMPARE(quint32(nCheckParamsCount), quint32(expected_count));\
	}

#define SKIP_IF_EXTERNAL_BUILD \
	if ( TestConfig::isExternalBuild() ) \
		QSKIP("Test skipping due functionality not supported at external build", SkipAll);

#define GET_RESULT_AFTER_ASYNC_CALL_WITH_COPY(SDK_CALL, _hConvertedResult, _hConvertedResultCopy ) \
{ \
	SdkHandleWrap _local_hJob; \
	SdkHandleWrap _local_hResult; \
	\
	_local_hJob.reset(SDK_CALL); \
	CHECK_JOB_RET_CODE(_local_hJob); \
	CHECK_RET_CODE_EXP(PrlJob_GetResult(_local_hJob, _local_hResult.GetHandlePtr())); \
	CHECK_RET_CODE_EXP(PrlResult_GetParam(_local_hResult, _hConvertedResult.GetHandlePtr())); \
	CHECK_RET_CODE_EXP(PrlResult_GetParam(_local_hResult, _hConvertedResultCopy.GetHandlePtr())); \
}

#define GET_RESULT_AFTER_ASYNC_CALL(SDK_CALL, _hConvertedResult ) \
{ \
	SdkHandleWrap _hFake; \
	GET_RESULT_AFTER_ASYNC_CALL_WITH_COPY(SDK_CALL, _hConvertedResult, _hFake) \
}

#define SET_LICENSE_USER_AND_COMPANY(hServer, username, company) \
{ \
	SdkHandleWrap hJob(PrlSrv_StoreValueByKey(hServer, PRL_KEY_TO_GET_LICENSE_KEY, "", 0)); \
	\
	if ( TestConfig::isExternalBuild() ) { \
		CHECK_ASYNC_OP_FAILED(hJob, PRL_ERR_UNIMPLEMENTED) \
	} \
	else \
	{ \
		CHECK_JOB_RET_CODE(hJob) \
		SdkHandleWrap hResult; \
		CHECK_RET_CODE_EXP(PrlJob_GetResult(hJob, hResult.GetHandlePtr())) \
		QString origLicenseKey; \
		PRL_EXTRACT_STRING_VALUE(origLicenseKey, hResult, PrlResult_GetParamAsString) \
		\
		hJob.reset(PrlSrv_UpdateLicense(hServer, origLicenseKey.toUtf8().constData(), \
						username.toUtf8().constData(), company.toUtf8().constData())); \
		CHECK_JOB_RET_CODE(hJob) \
	} \
}

#define GET_LICENSE_INFO \
	SdkHandleWrap hJob(PrlSrv_GetLicenseInfo(m_ServerHandle)); \
	CHECK_JOB_RET_CODE(hJob) \
	SdkHandleWrap hResult; \
	CHECK_RET_CODE_EXP(PrlJob_GetResult(hJob, hResult.GetHandlePtr())) \
	SdkHandleWrap hLicense; \
	CHECK_RET_CODE_EXP(PrlResult_GetParam(hResult, hLicense.GetHandlePtr())) \
	CHECK_HANDLE_TYPE(hLicense, PHT_LICENSE)

extern const int CONNECTION_TIMEOUT;

namespace QTest {

template<>
char *toString ( const PVE::IDispatcherCommands &value);

}//namespace QTest

class TestConfig
{
public:
   static char* getUserLogin();
   static char* getUserLogin2();
   static char* getUserPassword();
   static char* getRemoteHostName();
   static char* getLocalHostName();

   static QString getPathToDispatcherConfig();

	static bool isExternalBuild();
	static void readTestParameters();
	static PRL_APPLICATION_MODE getApplicationMode();
	static PRL_UINT32	getSdkInitFlags();
	static bool isCtMode() { return g_CtMode; }

public:
	class InitRandom
	{
	public:
		InitRandom();
	};
public:
	static bool g_CtMode;

private:
	static PRL_APPLICATION_MODE g_executeMode;
};

bool CheckElementPresentsInList(const QList<QString> &_list, const QString &_elem);
void InitializeTooLongString();
void CleanupTooLongString();
char *GetTooLongString();

bool checkArguments(int argc, char **argv, const QString testName, QStringList &testArgsList);

struct stop_vm_on_exit {
        SdkHandleWrap _vm ;
        stop_vm_on_exit(SdkHandleWrap vm):_vm(vm) {}
        ~stop_vm_on_exit() {
            SdkHandleWrap hJob(PrlVm_Stop(_vm, PRL_FALSE));
			PRL_RESULT nJobWaitRetCode = PrlJob_Wait(hJob, PRL_JOB_WAIT_TIMEOUT);
			if (nJobWaitRetCode == PRL_ERR_TIMEOUT)
				nJobWaitRetCode = PrlJob_Wait(hJob, 10*PRL_JOB_WAIT_TIMEOUT);
			if (PRL_SUCCEEDED(nJobWaitRetCode))
			{
				PRL_RESULT _ret_code = PRL_ERR_UNINITIALIZED;
				PrlJob_GetRetCode(hJob, &_ret_code);
				if (PRL_FAILED(_ret_code))
					WRITE_TRACE(DBG_FATAL, "_ret_code=%.8X '%s'", _ret_code, PRL_RESULT_TO_STRING(_ret_code));
			}
        }
};

#define VERIFY_WITH_BOOL_RETURN(statement) \
	do {\
		if (!(statement)){ \
			WRITE_TRACE( DBG_FATAL, "'%s' FAILED", #statement );\
			return false; \
		}\
	} while (0)

#define CHECK_RET_CODE_EXP_WITH_BOOL_RETURN(expression) \
{\
	PRL_RESULT nExprRetCode = (expression);\
	if (PRL_FAILED(nExprRetCode))\
		WRITE_TRACE(DBG_FATAL, "Expression: '%s' nRetCode=%.8X '%s'", #expression, nExprRetCode, PRL_RESULT_TO_STRING(nExprRetCode));\
	VERIFY_WITH_BOOL_RETURN(PRL_SUCCEEDED(nExprRetCode));\
}

template<class T>bool CompareTwoOpTypeLists( SdkHandleWrap hList1, SdkHandleWrap hList2, T fakeParam )
{
	Q_UNUSED( fakeParam );
	// check size
	PRL_UINT32 nSize1, nSize2;
	CHECK_RET_CODE_EXP_WITH_BOOL_RETURN(PrlOpTypeList_GetItemsCount(hList1, &nSize1));
	CHECK_RET_CODE_EXP_WITH_BOOL_RETURN(PrlOpTypeList_GetItemsCount(hList2, &nSize2));
	VERIFY_WITH_BOOL_RETURN( nSize1 == nSize2 );

	// check type
	PRL_SIZE nType1, nType2;
	CHECK_RET_CODE_EXP_WITH_BOOL_RETURN(PrlOpTypeList_GetTypeSize(hList1, &nType1));
	CHECK_RET_CODE_EXP_WITH_BOOL_RETURN(PrlOpTypeList_GetTypeSize(hList2, &nType2));
	VERIFY_WITH_BOOL_RETURN( nType1 == nType2 );
	VERIFY_WITH_BOOL_RETURN( nType1 == sizeof(T) );
	// compare every element
	for( PRL_UINT32 i=0; i< nSize1; i++ )
	{
		T val1, val2;
		CHECK_RET_CODE_EXP_WITH_BOOL_RETURN(PrlOpTypeList_GetItem(hList1, i, &val1));
		CHECK_RET_CODE_EXP_WITH_BOOL_RETURN(PrlOpTypeList_GetItem(hList2, i, &val2));
		VERIFY_WITH_BOOL_RETURN( val1 == val2 );
	}
	return true;
}

#define WAIT_AND_ANSWER_SERVER_QUESTION( hServer, question, answer, timeoutMsec ) \
{\
	const unsigned int nTotalWaitTime = timeoutMsec;\
	const unsigned int nSingleShotWaitTime = 1000;\
	SdkHandleWrap hQuestion;\
	bool bQuestionFound = false;\
	for (unsigned int i = 0; i < nTotalWaitTime/nSingleShotWaitTime; ++i)\
	{\
		SdkHandleWrap hQuestionsList;\
		CHECK_RET_CODE_EXP(PrlSrv_GetQuestions(hServer, hQuestionsList.GetHandlePtr()))\
		PRL_UINT32 nQuestionsCount = 0;\
		CHECK_RET_CODE_EXP(PrlHndlList_GetItemsCount(hQuestionsList, &nQuestionsCount))\
		for (PRL_UINT32 j = 0; j < nQuestionsCount; ++j)\
		{\
			CHECK_RET_CODE_EXP(PrlHndlList_GetItem(hQuestionsList, j, hQuestion.GetHandlePtr()))\
			CHECK_HANDLE_TYPE(hQuestion, PHT_EVENT)\
			PRL_RESULT nQuestionId = PRL_ERR_UNINITIALIZED;\
			CHECK_RET_CODE_EXP(PrlEvent_GetErrCode(hQuestion, &nQuestionId))\
			if (question == nQuestionId)\
			{\
				bQuestionFound = true;\
				SdkHandleWrap hAnswer;\
				CHECK_RET_CODE_EXP(PrlEvent_CreateAnswerEvent(hQuestion, hAnswer.GetHandlePtr(), answer));\
				SdkHandleWrap hAnswerJob(PrlSrv_SendAnswer(hServer, hAnswer));\
				CHECK_JOB_RET_CODE(hAnswerJob);\
				break;\
			}\
		}\
		if (bQuestionFound)\
			break;\
		HostUtils::Sleep(nSingleShotWaitTime);\
	}\
	QVERIFY(bQuestionFound);\
}

#define CLEAR_QDATETIME_MSECS( _dateTime ) \
{	\
	QTime t = _dateTime.time(); \
	_dateTime.setTime( QTime( t.hour(), t.minute(), t.second() ) ); \
}

#endif
