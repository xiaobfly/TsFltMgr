#include "FilterFunction.h"

//typedef struct _TsFlt_NOTIFY_INFO
//{
//	PSLIST_HEADER OtherModuleFuncIndex;		//0x00
//	ULONG ParameterNumber;		//0x04
//	ULONG Parameter1;			//0x08
//	ULONG Parameter2;			//0x0c
//	ULONG Parameter3;			//0x10
//	ULONG Parameter4;			//0x14
//	ULONG Parameter5;			//0x18
//	ULONG Parameter6;			//0x1c
//	ULONG Parameter7;			//0x20
//	ULONG Parameter8;			//0x24
//	ULONG Parameter9;			//0x28
//	ULONG Parameter10;			//0x2c
//	ULONG Parameter11;			//0x30
//	ULONG Parameter12;			//0x34
//	ULONG Parameter13;			//0x38
//	ULONG Parameter14;			//0x3c
//	ULONG Parameter15;			//0x40
//	ULONG Reserve1[0x0e];		//0x44 - 0x74
//	ULONG FunctionRetValue;		//0x78
//	PVOID ProxyFunction;		//0x7c
//	PVOID IndexFunction;		//0x80
//
//}TsFlt_NOTIFY_INFO,*PTsFlt_NOTIFY_INFO;
//
//typedef struct _TsFlt_FILTER
//{
//	ULONG Type;				//0x0
//	LONG FuncIndex;		//0x4
//	PWCHAR FuncName;		//0x8
//	ULONG CurTsFltIndex;	//0xc
//	ULONG IsHook;			//0x10
//	LONG Lock1;				//0x14
//	LONG Lock2;				//0x18
//	ULONG Reserve1;			//0x1c
//	PVOID SaveFunc;			//0x20
//	PVOID ProxyFunc;		//0x24
//	ULONG Reserve2;			//0x28
//	ULONG Reserve3;			//0x2c
//	ULONG Reserve4;			//0x30
//	ULONG Reserve5;			//0x34
//	ULONG Reserve6;			//0x38
//	ULONG Reserve7;			//0x3c
//	ULONG Flag1;			//0x40
//	ULONG Reserve8;			//0x44
//	ULONG Flag2;			//0x48
//	KEVENT Kevent;			//0x4c
//}TsFlt_FILTER,*PTsFlt_FILTER;

int __stdcall xx_FilterNtOpenFile_1CCF0(int a1, int a2, int a3, int a4, int a5, int a6)
{
	PTsFlt_FILTER pFilterInfo_v6; // esi@1
	PTsFlt_NOTIFY_INFO pFilterNotifyInfo_v7; // edi@1
	unsigned int status_v8; // edi@7
	int (__stdcall *pfnFunc_v9)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD); // eax@10
	int nFunctionRetValue_v10; // eax@11
	unsigned int status_v11; // ST2C_4@11
	int (__stdcall *pfnFunc_v13)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD); // esi@23
	int v14; // [sp+18h] [bp-14h]@4
	signed int nFunctionRetValue; // [sp+1Ch] [bp-10h]@4
	ULONGLONG FastMutex; // [sp+24h] [bp-8h]@4

	pFilterInfo_v6 = dword_28320;
	
	pFilterNotifyInfo_v7 = (PTsFlt_NOTIFY_INFO)ExAllocateFromNPagedLookasideList(&g_Lookaside);
	memset((void *)pFilterNotifyInfo_v7, 0, 0xCCu);

	v14 = pFilterNotifyInfo_v7;
	nFunctionRetValue = 0xC0000022;
	FastMutex = 0i64;
	if ( g_FilterFlag_dword_281D4 == 1 )
		FastMutex = KeQueryInterruptTime();
	if ( pFilterNotifyInfo_v7 )
	{
		pFilterNotifyInfo_v7->ParameterNumber = 6;
		pFilterNotifyInfo_v7->Parameter1 = a1;
		pFilterNotifyInfo_v7->Parameter2 = a2;
		pFilterNotifyInfo_v7->Parameter3 = a3;
		pFilterNotifyInfo_v7->Parameter4 = a4;
		pFilterNotifyInfo_v7->Parameter5 = a5;
		pFilterNotifyInfo_v7->Parameter6 = a6;
		pFilterNotifyInfo_v7->ProxyFunction = pFilterInfo_v6->SaveFunc;
		pFilterNotifyInfo_v7->IndexFunction = 76;
		//*(DWORD *)(pFilterNotifyInfo_v7 + 8) = a1;
		//*(DWORD *)(pFilterNotifyInfo_v7 + 0xC) = a2;
		//*(DWORD *)(pFilterNotifyInfo_v7 + 0x10) = a3;
		//*(DWORD *)(pFilterNotifyInfo_v7 + 0x14) = a4;
		//*(DWORD *)(pFilterNotifyInfo_v7 + 0x18) = a5;
		//*(DWORD *)(pFilterNotifyInfo_v7 + 0x1C) = a6;
		//*(DWORD *)(pFilterNotifyInfo_v7 + 4) = 6;
		//*(DWORD *)(pFilterNotifyInfo_v7 + 0x7C) = *(DWORD *)(pFilterInfo_v6 + 0x20);
		//*(DWORD *)(pFilterNotifyInfo_v7 + 0x80) = 76;
		InterlockedIncrement(&pFilterInfo_v6->Lock1);
		status_v8 = xx_Printf_20F90(pFilterNotifyInfo_v7, pFilterInfo_v6);
		InterlockedDecrement(&pFilterInfo_v6->Lock1);
		if ( status_v8 != 0xEEEE0004 )
		{
			if ( status_v8 == 0xEEEE0005 )
			{
				nFunctionRetValue = pFilterNotifyInfo_v7->FunctionRetValue;
			}
			else
			{
				pfnFunc_v9 = (int (__stdcall **)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD))(pFilterInfo_v6->SaveFunc);
				if ( pfnFunc_v9 )
				{
					nFunctionRetValue_v10 = pfnFunc_v9(
						pFilterNotifyInfo_v7->Parameter1,
						pFilterNotifyInfo_v7->Parameter2,
						pFilterNotifyInfo_v7->Parameter3,
						pFilterNotifyInfo_v7->Parameter4,
						pFilterNotifyInfo_v7->Parameter5,
						pFilterNotifyInfo_v7->Parameter6);
					pFilterNotifyInfo_v7->FunctionRetValue = nFunctionRetValue_v10;
					nFunctionRetValue = nFunctionRetValue_v10;
					InterlockedIncrement(&pFilterInfo_v6->Lock2);
					status_v11 = xx_TsLockInfo_21110(pFilterNotifyInfo_v7);
					InterlockedDecrement(&pFilterInfo_v6->Lock2);
					if ( status_v11 == 0xEEEE0005 )
						nFunctionRetValue = pFilterNotifyInfo_v7->FunctionRetValue;
				}
			}
		}
	}
	if ( pFilterInfo_v6->IsHook && FastMutex )
	{
		if ( g_FilterFlag_dword_281D4 )
			sub_11810(&pFilterInfo_v6->Reserve4, (PFAST_MUTEX)FastMutex, SHIDWORD(FastMutex));
	}
	if ( v14 )
	{
		ExFreeToNPagedLookasideList(&g_Lookaside, pFilterNotifyInfo_v7);
		return nFunctionRetValue;
	}
	pfnFunc_v13 = (int (__stdcall **)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD))(pFilterInfo_v6->SaveFunc);
	if ( !pfnFunc_v13 )
		return nFunctionRetValue;
	return pfnFunc_v13(a1, a2, a3, a4, a5, a6);
}