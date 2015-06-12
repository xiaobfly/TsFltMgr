#include <ntifs.h>


#define MAX_PATH 260

#define arraysize(p) (sizeof(p)/sizeof((p)[0]))

//
typedef enum _SYSTEM_INFORMATION_CLASS {
	SystemBasicInformation, // 0 Y N
	SystemProcessorInformation, // 1 Y N
	SystemPerformanceInformation, // 2 Y N
	SystemTimeOfDayInformation, // 3 Y N
	SystemNotImplemented1, // 4 Y N
	SystemProcessesAndThreadsInformation, // 5 Y N
	SystemCallCounts, // 6 Y N
	SystemConfigurationInformation, // 7 Y N
	SystemProcessorTimes, // 8 Y N
	SystemGlobalFlag, // 9 Y Y
	SystemNotImplemented2, // 10 Y N
	SystemModuleInformation, // 11 Y N
	SystemLockInformation, // 12 Y N
	SystemNotImplemented3, // 13 Y N
	SystemNotImplemented4, // 14 Y N
	SystemNotImplemented5, // 15 Y N
	SystemHandleInformation, // 16 Y N
	SystemObjectInformation, // 17 Y N
	SystemPagefileInformation, // 18 Y N
	SystemInstructionEmulationCounts, // 19 Y N
	SystemInvalidInfoClass1, // 20
	SystemCacheInformation, // 21 Y Y
	SystemPoolTagInformation, // 22 Y N
	SystemProcessorStatistics, // 23 Y N
	SystemDpcInformation, // 24 Y Y
	SystemNotImplemented6, // 25 Y N
	SystemLoadImage, // 26 N Y
	SystemUnloadImage, // 27 N Y
	SystemTimeAdjustment, // 28 Y Y
	SystemNotImplemented7, // 29 Y N
	SystemNotImplemented8, // 30 Y N
	SystemNotImplemented9, // 31 Y N
	SystemCrashDumpInformation, // 32 Y N
	SystemExceptionInformation, // 33 Y N
	SystemCrashDumpStateInformation, // 34 Y Y/N
	SystemKernelDebuggerInformation, // 35 Y N
	SystemContextSwitchInformation, // 36 Y N
	SystemRegistryQuotaInformation, // 37 Y Y
	SystemLoadAndCallImage, // 38 N Y
	SystemPrioritySeparation, // 39 N Y
	SystemNotImplemented10, // 40 Y N
	SystemNotImplemented11, // 41 Y N
	SystemInvalidInfoClass2, // 42
	SystemInvalidInfoClass3, // 43
	SystemTimeZoneInformation, // 44 Y N
	SystemLookasideInformation, // 45 Y N
	SystemSetTimeSlipEvent, // 46 N Y
	SystemCreateSession, // 47 N Y
	SystemDeleteSession, // 48 N Y
	SystemInvalidInfoClass4, // 49
	SystemRangeStartInformation, // 50 Y N
	SystemVerifierInformation, // 51 Y Y
	SystemAddVerifier, // 52 N Y
	SystemSessionProcessesInformation // 53 Y N
}SYSTEM_INFORMATION_CLASS;

//---------线程信息结构---------
typedef struct _SYSTEM_THREAD_INFORMATION {
	LARGE_INTEGER KernelTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER CreateTime;
	ULONG WaitTime;
	PVOID StartAddress;
	CLIENT_ID ClientId;
	KPRIORITY Priority;
	KPRIORITY BasePriority;
	ULONG ContextSwitchCount;
	LONG State;
	LONG WaitReason;
} SYSTEM_THREAD_INFORMATION, * PSYSTEM_THREAD_INFORMATION;
//------------------------------

//---------进程信息结构---------
typedef struct _SYSTEM_PROCESS_INFORMATION {
	ULONG NextEntryDelta;
	ULONG ThreadCount;
	ULONG Reserved1[6];
	LARGE_INTEGER CreateTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER KernelTime;
	UNICODE_STRING ProcessName;
	KPRIORITY BasePriority;
	ULONG ProcessId;
	ULONG InheritedFromProcessId;
	ULONG HandleCount;
	ULONG Reserved2[2];
	VM_COUNTERS VmCounters;
	IO_COUNTERS IoCounters;
	SYSTEM_THREAD_INFORMATION Threads[1];
} SYSTEM_PROCESS_INFORMATION, * PSYSTEM_PROCESS_INFORMATION;

typedef struct _SYSTEM_MODULE_INFORMATION_ENTRY
{
	ULONG Unknow1;
	ULONG Unknow2;
	//#ifdef _WIN64
	//	ULONG Unknow3;
	//	ULONG Unknow4:
	//#endif
	PVOID Base;
	ULONG Size;
	ULONG Flags;
	USHORT Index;
	USHORT NameLength;
	USHORT LoadCount;
	USHORT ModuleNameOffset;
	char ImageName[256];
}SYSTEM_MODULE_INFORMATION_ENTRY, *PSYSTEM_MODULE_INFORMATION_ENTRY;

typedef struct _SYSTEM_MODULE_INFORMATION
{
	ULONG Count;//内核中以加载的模块的个数
	SYSTEM_MODULE_INFORMATION_ENTRY Module[1];
}SYSTEM_MODULE_INFORMATION, *PSYSTEM_MODULE_INFORMATION;

typedef struct _SERVICES_DESCRIPTOR_TABLE{
	PVOID ServiceTableBase;									// The Base of SSDT
	PVOID ServiceCounterTableBase;
	ULONG_PTR ServiceCount;									// The Count of SSDT Function 
	PVOID ParamTableBase;
}SERVICES_DESCRIPTOR_TABLE, *PSERVICES_DESCRIPTOR_TABLE;

typedef struct _SERVICE_DESCRIPTOR_TABLE
{
	SERVICES_DESCRIPTOR_TABLE Ntoskrnl;
	SERVICES_DESCRIPTOR_TABLE Win32k;
	SERVICES_DESCRIPTOR_TABLE Reserved[2];
} SERVICE_DESCRIPTOR_TABLE, *PSERVICE_DESCRIPTOR_TABLE;



typedef enum _TsFlt_OS_VERSION
{
	OS_UnKnow,
	OS_Win2000,
	OS_WinXP,
	OS_Win2003,
	OS_WinVista,
	OS_WinVista_SP1,
	OS_WinVista_SP2,
	OS_Win7,
	OS_Win7_SP1,
	OS_Win8,
	OS_Win8_CR,
	OS_Win8_RP,
	OS_Win8_RT1,
	OS_Win8_RT2,
	OS_Win8_RTM,
	OS_Win8_1_RTM,
	OS_Win10_RT1,
	OS_Win10_RT2,
	OS_Max
}TsFlt_OS_VERSION,*PTsFlt_OS_VERSION;

typedef struct _TsFlt_NOTIFY_INFO
{
	ULONG OtherModuleFuncIndex;	//0x00
	ULONG ParameterNumber;		//0x04
	ULONG Parameter[0x0c];		//0x08 - 0x38
	ULONG OtherModuleFuncFlag[0x0a];//0x38 - 0x74
	ULONG FunctionRetValue;		//0x78
	PVOID ProxyFunction;		//0x7c
	ULONG IndexFunction;		//0x80
	ULONG Reserve;				//0x84
	ULONG OtherModuleFunc[0xf];//0x88-0xc4
	ULONG Count;				//0xc8
	ULONG Reserve2;				//0xcc
}TsFlt_NOTIFY_INFO,*PTsFlt_NOTIFY_INFO;

typedef struct _TsFlt_MODULE_INTERFACE
{
	ULONG Type;				//0x00 TSKS类型的字符串标记
	ULONG Reserve1;			//0x04
	ULONG Reserve2;			//0x08
	ULONG Count;			//0x0c
	PKTIMER Timer;			//0x10
	ULONG Reserve3;			//0x14
	ULONG Reserve4[8];		//0x18-0x34
	PVOID FuncAddress;		//0x38
	ULONG Reserve5;			//0x3c-0x40
	//ULONG Reserve4[3];	//0x3c-0x48
}TsFlt_MODULE_INTERFACE,*PTsFlt_MODULE_INTERFACE;

#define TS_MAX_OTHER_MODULE_FUNC 0x10
typedef struct _TsFlt_FILTER
{
	ULONG Type;				//0x0
	LONG FuncIndex;			//0x4
	PWCHAR FuncName;		//0x8
	ULONG CurTsFltIndex;	//0xc
	ULONG IsHook;			//0x10
	LONG Lock1;				//0x14
	LONG Lock2;				//0x18
	ULONG Reserve1;			//0x1c
	PVOID SaveFunc;			//0x20
	PVOID ProxyFunc;		//0x24
	ULONG Reserve2;			//0x28
	ULONG Reserve3;			//0x2c
	ULONG Reserve4;			//0x30
	ULONG Reserve5;			//0x34
	ULONG Reserve6;			//0x38
	ULONG Reserve7;			//0x3c
	ULONG Flag1;			//0x40
	ULONG Reserve8;			//0x44
	ULONG Flag2;			//0x48
	KEVENT Kevent;			//0x4c
	ULONG Reserve9[0x27];	//0x50-0xec
	struct
	{
		ULONG OtherModuleFuncReserve;	//0xf0
		ULONG OtherModuleFuncCount;		//0xf4
		TsFlt_MODULE_INTERFACE	ModuleInterface[TS_MAX_OTHER_MODULE_FUNC];			
	};
}TsFlt_FILTER,*PTsFlt_FILTER;

typedef struct _TsFlt_PERESOURCE
{
	ERESOURCE Eresouce;
	NTSTATUS Status;
}TsFlt_PERESOURCE,*PTsFlt_PERESOURCE;

typedef struct _TsFlt_WRITE_FILE_BUFFER
{
	ULONG Length;
	PVOID pBuffer;
}TsFlt_WRITE_FILE_BUFFER,*PTsFlt_WRITE_FILE_BUFFER;

typedef struct _TsFlt_PNPAGED_LOOKASIDE_LIST
{
	ULONG Reserve[0x1a];
}TsFlt_PNPAGED_LOOKASIDE_LIST,*PTsFlt_PNPAGED_LOOKASIDE_LIST;

typedef struct _TsFlt_DPC
{
	PULONG pFlag;
	PKSPIN_LOCK pSpinLock;
}TsFlt_DPC,*PTsFlt_DPC;

typedef struct _TsFlt_HOOK_INFO
{
	PVOID HookAddress;
	PVOID TargetAddress;
	PVOID MdlHookAddress;
}TsFlt_HOOK_INFO,*PTsFlt_HOOK_INFO;

typedef struct _TsFlt_DEVICE_EXTENSION
{
	ULONG Type;
	ULONG Reserve1;
	ULONG Reserve2;
	ULONG Reserve3;
	ULONG Reserve4;
	ULONG Reserve5;
	PVOID FunctionPoint;
}TsFlt_DEVICE_EXTENSION,*PTsFlt_DEVICE_EXTENSION;

typedef struct _TsFlt_FUNCTION_LIST
{
	ULONG Number;
	ULONG Type;
	PWCHAR FuncName;
	PVOID FuncAddress;
	ULONG Index[OS_Max + 1];
}TsFlt_FUNCTION_LIST,*PTsFlt_FUNCTION_LIST;

extern "C" ULONG InitSafeBootMode;

NPAGED_LOOKASIDE_LIST g_Lookaside = {0};

PTsFlt_PNPAGED_LOOKASIDE_LIST g_pTsFltPnpagedLoolasideList_28180 = 0;
PTsFlt_PERESOURCE g_pInitResourceLiteInfo_dword_2A398 = NULL;
BOOL g_IsExInitializeResourceLiteSuccess_byte_2A39C = FALSE;

ULONG g_MmUserProbeAddress_dword_28188 = 0;
ULONG g_HookLen8_dword_281E0 = 0;
ULONG g_SsdtType_dword_281DC = 0;
ULONG g_FilterFlag_dword_281D4 = 0;
ULONG g_SystemVersion_dword_281E8;
BOOL g_IsSetThm_byte_2A390 = FALSE;
ULONG g_HookKiSystemFastCallFlag_dword_281E4 = 0;

PVOID g_NtBase_dword_281C0 = NULL;
ULONG g_NtSize_dword_281C4 = 0;

ULONG g_HookLen6_dword_2A384 = 0;
PVOID g_JmpBackAddress_dword_281A0 = 0;

ULONG g_SaveSsdt_dword_28380[0x2000] = {0};
PSERVICES_DESCRIPTOR_TABLE g_KeServiceDescriptorTable_dword_281BC = NULL;
PVOID g_KiSystemServiceHookAddress_dword_2819C = NULL;
PVOID g_FindCodeHookAddress_dword_2A380 = NULL;

PULONG g_SsdtTableBase = NULL;
DWORD g_SsdtCount_dword_28190 = 0;
HANDLE g_CsrssPid_dword_281D0 = 0;

PVOID g_Target = NULL;
DWORD g_Win32kSize_dword_281CC = 0;

PULONG g_W32pServiceTable_dword_28194 = NULL;
DWORD g_W32pServiceLimit_dword_28198 = 0;

DWORD g_MmUserProbeAddress_dword_25B1C = 0;

UCHAR g_FindHookCode_unk_25B18[11] = {"\x8b\xfc\x3b\x35\xd4\x99\x55\x80\x0f\x83"};
UCHAR g_FindCode_unk_25B24[0x16u] = {0};

PTsFlt_FILTER g_FuncFilterInfo_dword_281F0[0x62] = {0};
PTsFlt_FILTER g_SsdtFilterInfo_dword_28380[1000] = {0};

ULONG g_dword_281F4[0x62] = {0};

KDPC g_Dpc[32] = {0};
KSPIN_LOCK g_SpinLock = 0;

ULONG g_HookAddressOldCode1_dword_281A4 = 0;
ULONG g_HookAddressOldCode2_dword_281A8 = 0;//这里其实也是MmUserProbeAddress的地址

ULONG g_DpcFlag_dword_2816C = 1;
ULONG g_FlagBak_dword_28174 = 0;

TsFlt_DPC g_TsFltDpcInfo = {0};

int g_Flag_dword_281EC = 0;
HANDLE g_KeyHandle = NULL;

typedef NTSTATUS (*pfnPsSetCreateProcessNotifyRoutineEx)(PCREATE_PROCESS_NOTIFY_ROUTINE_EX NotifyRoutine,BOOLEAN Remove);
PVOID g_pfnPsSetCreateProcessNotifyRoutineEx_dword_2A394 = NULL;

PVOID g_PsGetProcessImageFileName_dword_28178 = NULL;

PTsFlt_FILTER g_PsSetCreateProcessNotifyRoutineEx_dword_28314 = NULL;
PTsFlt_FILTER g_ProcessNotifyInfo_dword_282C0 = NULL;
PTsFlt_FILTER g_ThreadNotifyInfo_dword_282C4 = NULL;
PTsFlt_FILTER g_ImageNotifyInfo_dword_282C8 = NULL;
PTsFlt_FILTER g_KeUserModeCallbackInfo = NULL;
PTsFlt_FILTER g_EatHookKeAddSystemServiceTable_dword_28238 = NULL;

PVOID g_KeAddSystemServiceTable_dword_28184 = NULL;

ULONG g_BuildNumber = 0;

NTSTATUS xx_Printf_20F90(PTsFlt_NOTIFY_INFO pBufferInfo_a1, PTsFlt_FILTER pProcessNotifyInfo_a2);
NTSTATUS __stdcall xx_TsLockInfo_21110(PTsFlt_NOTIFY_INFO pTsFltFilterNotify_a1);
NTSTATUS __stdcall xx_ZwCreateKey_12580(ULONG KeyHandle_a1, ULONG DesiredAccess_a2, ULONG ObjectAttributes_a3, ULONG TitleIndex_a4, ULONG Class_a5, ULONG CreateOptions_a6, ULONG Disposition_a7);

typedef NTSTATUS (__stdcall *pfnZwCreateKey)(ULONG, ULONG, ULONG, ULONG, ULONG, ULONG, ULONG);
NTSTATUS __stdcall xx_ZwCreateKey_12580(ULONG KeyHandle_a1, ULONG DesiredAccess_a2, ULONG ObjectAttributes_a3, ULONG TitleIndex_a4, ULONG Class_a5, ULONG CreateOptions_a6, ULONG Disposition_a7)
{
	PTsFlt_FILTER pFunInfo_v7 = NULL;
	PTsFlt_NOTIFY_INFO pLockEntryListInfo_v8 = NULL; 
	pfnZwCreateKey pfn_v10 = NULL;
	NTSTATUS status_v16 = STATUS_ACCESS_DENIED;
	
	ULONGLONG FastMutex = 0;

	pFunInfo_v7 = g_FuncFilterInfo_dword_281F0[0];
	pLockEntryListInfo_v8 = (PTsFlt_NOTIFY_INFO)ExAllocateFromNPagedLookasideList(&g_Lookaside);
	if (pLockEntryListInfo_v8)
	{
		memset((void *)pLockEntryListInfo_v8, 0, 0xCCu);
	}

	if ( g_FilterFlag_dword_281D4 == 1 )
	{
		FastMutex = KeQueryInterruptTime();
	}
	
	if ( pLockEntryListInfo_v8 )
	{
		pLockEntryListInfo_v8->Parameter[0] = (ULONG)KeyHandle_a1;
		pLockEntryListInfo_v8->Parameter[1] = (ULONG)DesiredAccess_a2;
		pLockEntryListInfo_v8->Parameter[2] = (ULONG)ObjectAttributes_a3;
		pLockEntryListInfo_v8->Parameter[3] = (ULONG)TitleIndex_a4;
		pLockEntryListInfo_v8->Parameter[4] = (ULONG)Class_a5;
		pLockEntryListInfo_v8->Parameter[5] = (ULONG)CreateOptions_a6;
		pLockEntryListInfo_v8->Parameter[6] = (ULONG)Disposition_a7;
		pLockEntryListInfo_v8->ParameterNumber = 7;
		pLockEntryListInfo_v8->ProxyFunction = pFunInfo_v7->SaveFunc;
		pLockEntryListInfo_v8->IndexFunction = 0;

		InterlockedIncrement(&pFunInfo_v7->Lock1);
		status_v16 = xx_Printf_20F90(pLockEntryListInfo_v8, pFunInfo_v7);
		InterlockedDecrement(&pFunInfo_v7->Lock1);

		if ( status_v16 != 0xEEEE0004 )
		{
			if ( status_v16 == 0xEEEE0005 )
			{
				status_v16 = pLockEntryListInfo_v8->FunctionRetValue;
			}
			else
			{
				pfn_v10 = (pfnZwCreateKey)(pFunInfo_v7->SaveFunc);
				if ( pfn_v10 )
				{
					pLockEntryListInfo_v8->FunctionRetValue = pfn_v10(
						pLockEntryListInfo_v8->Parameter[0],
						pLockEntryListInfo_v8->Parameter[1],
						pLockEntryListInfo_v8->Parameter[2],
						pLockEntryListInfo_v8->Parameter[3],
						pLockEntryListInfo_v8->Parameter[4],
						pLockEntryListInfo_v8->Parameter[5],
						pLockEntryListInfo_v8->Parameter[6]
						);

					InterlockedIncrement(&pFunInfo_v7->Lock2);
					status_v16 = xx_TsLockInfo_21110(pLockEntryListInfo_v8);
					InterlockedDecrement(&pFunInfo_v7->Lock2);
					if ( status_v16 == 0xEEEE0005 )
					{
						status_v16 = pLockEntryListInfo_v8->FunctionRetValue;
					}
				}
			}
		}
	}
	if ( pFunInfo_v7->IsHook && FastMutex )
	{
		if ( g_FilterFlag_dword_281D4 )
		{
			//sub_11810(&pFunInfo_v7->Reserve4, (PFAST_MUTEX)FastMutex, HIDWORD(FastMutex));
		}
	}
	if ( pLockEntryListInfo_v8 )
	{
		ExFreeToNPagedLookasideList(&g_Lookaside, pLockEntryListInfo_v8);
		return status_v16;
	}
	pfn_v10 = (pfnZwCreateKey)(pFunInfo_v7->SaveFunc);
	if ( !pfn_v10 )
		return status_v16;

	return pfn_v10(
		KeyHandle_a1,
		DesiredAccess_a2,
		ObjectAttributes_a3,
		TitleIndex_a4,
		Class_a5,
		CreateOptions_a6,
		Disposition_a7);
}

typedef NTSTATUS (*pfnZwTerminateProcess)(ULONG ProcessHandle,ULONG ExitStatus);
NTSTATUS xx_ZwTerminateProcess_12810(ULONG ProcessHandle,ULONG ExitStatus)
{
	PTsFlt_FILTER pFunInfo_v7 = NULL;
	PTsFlt_NOTIFY_INFO pLockEntryListInfo_v8 = NULL; 
	pfnZwTerminateProcess pfn_v10 = NULL;
	NTSTATUS status_v16 = STATUS_ACCESS_DENIED;

	ULONGLONG FastMutex = 0;

	pFunInfo_v7 = g_FuncFilterInfo_dword_281F0[0];
	pLockEntryListInfo_v8 = (PTsFlt_NOTIFY_INFO)ExAllocateFromNPagedLookasideList(&g_Lookaside);
	if (pLockEntryListInfo_v8)
	{
		memset((void *)pLockEntryListInfo_v8, 0, 0xCCu);
	}

	if ( g_FilterFlag_dword_281D4 == 1 )
	{
		FastMutex = KeQueryInterruptTime();
	}

	if ( pLockEntryListInfo_v8 )
	{
		pLockEntryListInfo_v8->Parameter[0] = (ULONG)ProcessHandle;
		pLockEntryListInfo_v8->Parameter[1] = (ULONG)ExitStatus;
		pLockEntryListInfo_v8->ParameterNumber = 2;
		pLockEntryListInfo_v8->ProxyFunction = pFunInfo_v7->SaveFunc;
		pLockEntryListInfo_v8->IndexFunction = 0;

		InterlockedIncrement(&pFunInfo_v7->Lock1);
		status_v16 = xx_Printf_20F90(pLockEntryListInfo_v8, pFunInfo_v7);
		InterlockedDecrement(&pFunInfo_v7->Lock1);

		if ( status_v16 != 0xEEEE0004 )
		{
			if ( status_v16 == 0xEEEE0005 )
			{
				status_v16 = pLockEntryListInfo_v8->FunctionRetValue;
			}
			else
			{
				pfn_v10 = (pfnZwTerminateProcess)(pFunInfo_v7->SaveFunc);
				if ( pfn_v10 )
				{
					pLockEntryListInfo_v8->FunctionRetValue = pfn_v10(
						pLockEntryListInfo_v8->Parameter[0],
						pLockEntryListInfo_v8->Parameter[1]
					);

					InterlockedIncrement(&pFunInfo_v7->Lock2);
					status_v16 = xx_TsLockInfo_21110(pLockEntryListInfo_v8);
					InterlockedDecrement(&pFunInfo_v7->Lock2);
					if ( status_v16 == 0xEEEE0005 )
					{
						status_v16 = pLockEntryListInfo_v8->FunctionRetValue;
					}
				}
			}
		}
	}
	if ( pFunInfo_v7->IsHook && FastMutex )
	{
		if ( g_FilterFlag_dword_281D4 )
		{
			//sub_11810(&pFunInfo_v7->Reserve4, (PFAST_MUTEX)FastMutex, HIDWORD(FastMutex));
		}
	}
	if ( pLockEntryListInfo_v8 )
	{
		ExFreeToNPagedLookasideList(&g_Lookaside, pLockEntryListInfo_v8);
		return status_v16;
	}
	pfn_v10 = (pfnZwTerminateProcess)(pFunInfo_v7->SaveFunc);
	if ( !pfn_v10 )
		return status_v16;

	return pfn_v10(ProcessHandle, ExitStatus);
}

typedef NTSTATUS (*pfnZwSetInformationFile)(
										ULONG					FileHandle,
										ULONG					IoStatusBlock,
										ULONG					FileInformation,
										ULONG					Length,
										ULONG					FileInformationClass
									   );
NTSTATUS xx_ZwSetInformationFile_12960(
									     ULONG					FileHandle,
										 ULONG					IoStatusBlock,
									     ULONG					FileInformation,
									     ULONG					Length,
									     ULONG					FileInformationClass
									   )
{
	PTsFlt_FILTER pFunInfo_v7 = NULL;
	PTsFlt_NOTIFY_INFO pLockEntryListInfo_v8 = NULL; 
	pfnZwSetInformationFile pfn_v10 = NULL;
	NTSTATUS status_v16 = STATUS_ACCESS_DENIED;

	ULONGLONG FastMutex = 0;

	pFunInfo_v7 = g_FuncFilterInfo_dword_281F0[0];
	pLockEntryListInfo_v8 = (PTsFlt_NOTIFY_INFO)ExAllocateFromNPagedLookasideList(&g_Lookaside);
	if (pLockEntryListInfo_v8)
	{
		memset((void *)pLockEntryListInfo_v8, 0, 0xCCu);
	}

	if ( g_FilterFlag_dword_281D4 == 1 )
	{
		FastMutex = KeQueryInterruptTime();
	}

	if ( pLockEntryListInfo_v8 )
	{
		pLockEntryListInfo_v8->Parameter[0] = (ULONG)FileHandle;
		pLockEntryListInfo_v8->Parameter[1] = (ULONG)IoStatusBlock;
		pLockEntryListInfo_v8->Parameter[2] = (ULONG)FileInformation;
		pLockEntryListInfo_v8->Parameter[3] = (ULONG)Length;
		pLockEntryListInfo_v8->Parameter[4] = (ULONG)FileInformationClass;
		pLockEntryListInfo_v8->ParameterNumber = 5;
		pLockEntryListInfo_v8->ProxyFunction = pFunInfo_v7->SaveFunc;
		pLockEntryListInfo_v8->IndexFunction = 0;

		InterlockedIncrement(&pFunInfo_v7->Lock1);
		status_v16 = xx_Printf_20F90(pLockEntryListInfo_v8, pFunInfo_v7);
		InterlockedDecrement(&pFunInfo_v7->Lock1);

		if ( status_v16 != 0xEEEE0004 )
		{
			if ( status_v16 == 0xEEEE0005 )
			{
				status_v16 = pLockEntryListInfo_v8->FunctionRetValue;
			}
			else
			{
				pfn_v10 = (pfnZwSetInformationFile)(pFunInfo_v7->SaveFunc);
				if ( pfn_v10 )
				{
					pLockEntryListInfo_v8->FunctionRetValue = pfn_v10(
						(ULONG)pLockEntryListInfo_v8->Parameter[0],
						(ULONG)pLockEntryListInfo_v8->Parameter[1],
						(ULONG)pLockEntryListInfo_v8->Parameter[2],
						(ULONG)pLockEntryListInfo_v8->Parameter[3],
						(ULONG)pLockEntryListInfo_v8->Parameter[4]
					);

					InterlockedIncrement(&pFunInfo_v7->Lock2);
					status_v16 = xx_TsLockInfo_21110(pLockEntryListInfo_v8);
					InterlockedDecrement(&pFunInfo_v7->Lock2);
					if ( status_v16 == 0xEEEE0005 )
					{
						status_v16 = pLockEntryListInfo_v8->FunctionRetValue;
					}
				}
			}
		}
	}
	if ( pFunInfo_v7->IsHook && FastMutex )
	{
		if ( g_FilterFlag_dword_281D4 )
		{
			//sub_11810(&pFunInfo_v7->Reserve4, (PFAST_MUTEX)FastMutex, HIDWORD(FastMutex));
		}
	}
	if ( pLockEntryListInfo_v8 )
	{
		ExFreeToNPagedLookasideList(&g_Lookaside, pLockEntryListInfo_v8);
		return status_v16;
	}
	pfn_v10 = (pfnZwSetInformationFile)(pFunInfo_v7->SaveFunc);
	if ( !pfn_v10 )
		return status_v16;

	return pfn_v10(FileHandle,IoStatusBlock, FileInformation, Length, FileInformationClass);
}

NTSTATUS xx_ZwWriteFile_12BD0(
							       HANDLE           FileHandle,
							   HANDLE           Event,
							   PIO_APC_ROUTINE  ApcRoutine,
							   PVOID            ApcContext,
							      PIO_STATUS_BLOCK IoStatusBlock,
							       PVOID            Buffer,
							       ULONG            Length,
							   PLARGE_INTEGER   ByteOffset,
							   PULONG           Key
							  );