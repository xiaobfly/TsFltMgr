#include "stdafx.h"
#include "TsFltMgr.h"

extern "C"
{

	NTSTATUS	NTAPI	ZwQuerySystemInformation(ULONG SystemInfoClass,PVOID SystemInfoBuffer,ULONG SystemInfoBufferSize,PULONG BytesReturned OPTIONAL);

	void __sidt(void*);
	void __cdecl _disable(void);
	void __cdecl _enable(void);
}

TsFlt_FUNCTION_LIST g_ZwCreateKey_25B4C[] = 
{
	{ 0x0,0x0,L"ZwCreateKey",&xx_ZwCreateKey_12580,{0x3ff,0x23,0x29,0x2b,0x40,0x40,0x40,0x46,0x46,0x15b,0x15f,0x15f,0x15e,0x15e,0x15e,0x162,0x163,0x163,0x0} }
};

TsFlt_FUNCTION_LIST g_FunctionArray_25B4C[] = 
{
	{ 0x0,0x0,L"ZwTerminateProcess",&xx_ZwTerminateProcess_12810,{0x3ff,0xe0,0x101,0x10a,0x152,0x14e,0x14e,0x172,0x172,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x24,0x24} },
	{ 0x1,0x0,L"ZwSetInformationFile",&xx_ZwSetInformationFile_12960,{0x3ff,0xc2,0xe0,0xe9,0x131,0x12d,0x12d,0x149,0x149,0x4e,0x4f,0x4f,0x4e,0x4e,0x4e,0x51,0x52,0x52} },
	/*{ 0x2,0x0,L"ZwWriteFile",xx_ZwWriteFile_12BD0,{0x3ff,0xed,0x112,0x11c,0x167,0x163,0x163,0x18c,0x18c,0x4,0x5,0x5,0x5,0x5,0x5,0x6,0x7,0x7} },
	{ 0x3,0x0,L"ZwSetValueKey",xx_ZwSetValueKey_12EA0,{0x3ff,0xd7,0xf7,0x100,0x148,0x144,0x144,0x166,0x166,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x32,0x32} },
	{ 0x4,0x0,L"ZwWriteVirtualMemory",xx_ZwWriteVirtualMemory_13120,{0x3ff,0xf0,0x115,0x11f,0x16a,0x166,0x166,0x18f,0x18f,0x1,0x2,0x2,0x2,0x2,0x2,0x3,0x4,0x4} },
	{ 0x5,0x0,L"ZwCreateFile",xx_ZwCreateFile_13390,{0x3ff,0x20,0x25,0x27,0x3c,0x3c,0x3c,0x42,0x42,0x15f,0x164,0x164,0x163,0x163,0x163,0x168,0x169,0x169} },
	{ 0x6,0x0,L"ZwOpenProcess",xx_ZwOpenProcess_13690,{0x3ff,0x6a,0x7a,0x80,0xc2,0xc2,0xc2,0xbe,0xbe,0xdc,0xde,0xde,0xdd,0xdd,0xdd,0xe0,0xe1,0xe1} },
	{ 0x7,0x0,L"ZwDeleteKey",xx_ZwDeleteKey_138E0,{0x3ff,0x35,0x3f,0x42,0x7b,0x7b,0x7b,0x67,0x67,0x136,0x13a,0x13a,0x139,0x139,0x139,0x13d,0x13e,0x13e} },
	{ 0x8,0x0,L"ZwDeleteValueKey",xx_ZwDeleteValueKey_13AF0,{0x3ff,0x37,0x41,0x44,0x7e,0x7e,0x7e,0x6a,0x6a,0x133,0x137,0x137,0x136,0x136,0x136,0x13a,0x13b,0x13b} },
	{ 0x9,0x0,L"ZwRequestWaitReplyPort",xx_ZwRequestWaitReplyPort_13D20,{0x3ff,0xb0,0xc8,0xd0,0x113,0x114,0x114,0x12b,0x12b,0x6c,0x6e,0x6e,0x6d,0x6d,0x6d,0x70,0x71,0x71} },
	{ 0xa,0x0,L"ZwQueryValueKey",xx_ZwQueryValueKey_13F60,{0x3ff,0x9b,0xb1,0xb9,0xfc,0xfc,0xfc,0x10a,0x10a,0x8f,0x91,0x91,0x90,0x90,0x90,0x93,0x94,0x94} },
	{ 0xb,0x0,L"ZwEnumerateValueKey",xx_ZwEnumerateValueKey_141E0,{0x3ff,0x3d,0x49,0x4d,0x88,0x88,0x88,0x77,0x77,0x124,0x128,0x128,0x127,0x127,0x127,0x12b,0x12c,0x12c} },
	{ 0xc,0x0,L"ZwCreateThread",xx_ZwCreateThread_14460,{0x3ff,0x2e,0x35,0x37,0x4e,0x4e,0x4e,0x57,0x57,0x14a,0x14e,0x14e,0x14d,0x14d,0x14d,0x151,0x152,0x152} },
	{ 0xd,0x0,L"ZwDuplicateObject",xx_ZwDuplicateObject_14710,{0x3ff,0x3a,0x44,0x47,0x81,0x81,0x81,0x6f,0x6f,0x12c,0x130,0x130,0x12f,0x12f,0x12f,0x133,0x134,0x134} },
	{ 0xe,0x0,L"ZwLoadDriver",xx_ZwLoadDriver_149B0,{0x3ff,0x55,0x61,0x65,0xa5,0xa5,0xa5,0x9b,0x9b,0xff,0x101,0x101,0x100,0x100,0x100,0x103,0x104,0x104} },
	{ 0xf,0x0,L"ZwDeviceIoControlFile",xx_ZwDeviceIoControlFile_14BC0,{0x3ff,0x38,0x42,0x45,0x7f,0x7f,0x7f,0x6b,0x6b,0x130,0x134,0x134,0x133,0x133,0x133,0x137,0x138,0x138} },
	{ 0x10,0x0,L"ZwAlpcSendWaitReceivePort",xx_ZwAlpcSendWaitReceivePort_14EA0,{0x3ff,0x3ff,0x3ff,0x3ff,0x26,0x26,0x26,0x27,0x27,0x17d,0x182,0x182,0x181,0x181,0x181,0x186,0x187,0x187} },
	{ 0x11,0x0,L"ZwSetSystemInformation",xx_ZwSetSystemInformation_15150,{0x3ff,0xd0,0xf0,0xf9,0x141,0x13d,0x13d,0x15e,0x15e,0x38,0x38,0x38,0x38,0x38,0x38,0x39,0x3a,0x3a} },
	{ 0x12,0x0,L"ZwDeleteFile",xx_ZwDeleteFile_15390,{0x3ff,0x34,0x3e,0x41,0x7a,0x7a,0x7a,0x66,0x66,0x137,0x13b,0x13b,0x13a,0x13a,0x13a,0x13e,0x13f,0x13f} },
	{ 0x13,0x0,L"ZwOpenSection",xx_ZwOpenSection_155A0,{0x3ff,0x6c,0x7d,0x83,0xc5,0xc5,0xc5,0xc2,0xc2,0xd8,0xda,0xda,0xd9,0xd9,0xd9,0xdc,0xdd,0xdd} },
	{ 0x14,0x0,L"ZwCreateSection",xx_ZwCreateSection_157E0,{0x3ff,0x2b,0x32,0x34,0x4b,0x4b,0x4b,0x54,0x54,0x14d,0x151,0x151,0x150,0x150,0x150,0x154,0x155,0x155} },
	{ 0x15,0x0,L"ZwSuspendThread",xx_ZwSuspendThread_15A80,{0x3ff,0xdd,0xfe,0x107,0x14f,0x14b,0x14b,0x16f,0x16f,0x26,0x26,0x26,0x26,0x26,0x26,0x26,0x27,0x27} },
	{ 0x16,0x0,L"ZwTerminateThread",xx_ZwTerminateThread_15CB0,{0x3ff,0xe1,0x102,0x10b,0x153,0x14f,0x14f,0x173,0x173,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x23,0x23} },
	{ 0x17,0x0,L"ZwSystemDebugControl",xx_ZwSystemDebugControl_15E00,{0x3ff,0xde,0xff,0x108,0x150,0x14c,0x14c,0x170,0x170,0x25,0x25,0x25,0x25,0x25,0x25,0x25,0x26,0x26} },
	{ 0x18,0x0,L"ZwProtectVirtualMemory",xx_ZwProtectVirtualMemory_16080,{0x3ff,0x3ff,0x89,0x8f,0xd2,0xd2,0xd2,0xd7,0xd7,0xc2,0xc4,0xc4,0xc3,0xc3,0xc3,0xc6,0xc7,0xc7} },
	{ 0x26,0x0,L"ZwCreateSymbolicLinkObject",xx_ZwCreateSymbolicLinkObject_162F0,{0x3ff,0x2d,0x34,0x36,0x4d,0x4d,0x4d,0x56,0x56,0x14b,0x14f,0x14f,0x14e,0x14e,0x14e,0x152,0x153,0x153} },
	{ 0x27,0x0,L"ZwSetContextThread",xx_ZwSetContextThread_16540,{0x3ff,0x3ff,0xd5,0xdd,0x125,0x121,0x121,0x13c,0x13c,0x5b,0x5c,0x5c,0x5b,0x5b,0x5b,0x5e,0x5f,0x5f} },
	{ 0x28,0x0,L"ZwRenameKey",xx_ZwRenameKey_16770,{0x3ff,0x3ff,0xc0,0xc8,0x10b,0x10b,0x10b,0x122,0x122,0x75,0x77,0x77,0x76,0x76,0x76,0x79,0x7a,0x7a} },
	{ 0x29,0x0,L"ZwOpenThread",xx_ZwOpenThread_16E20,{0x3ff,0x6f,0x80,0x86,0xc9,0xc9,0xc9,0xc6,0xc6,0xd6,0xd6,0xd6,0xd5,0xd5,0xd5,0xd8,0xd9,0xd9} },
	{ 0x2a,0x0,L"ZwGetNextThread",xx_ZwGetNextThread_17070,{0x3ff,0x3ff,0x3ff,0x3ff,0x174,0x170,0x170,0x8c,0x8c,0x10f,0x10f,0x10f,0x10e,0x10e,0x10e,0x111,0x112,0x112} },
	{ 0x2b,0x0,L"ZwCreateThreadEx",xx_ZwCreateThreadEx_172F0,{0x3ff,0x3ff,0x3ff,0x3ff,0x184,0x17e,0x17e,0x58,0x58,0x14d,0x14d,0x14d,0x14c,0x14c,0x14c,0x150,0x151,0x151} },
	{ 0x2c,0x0,L"ZwRestoreKey",xx_ZwRestoreKey_169A0,{0x3ff,0x3ff,0xcc,0xd4,0x117,0x118,0x118,0x12e,0x12e,0x69,0x6b,0x6b,0x6a,0x6a,0x6a,0x6d,0x6e,0x6e} },
	{ 0x37,0x0,L"ZwReplaceKey",xx_ZwReplaceKey_16BE0,{0x3ff,0x3ff,0xc1,0xc9,0x10c,0x10c,0x10c,0x124,0x124,0x73,0x75,0x75,0x74,0x74,0x74,0x77,0x78,0x78} },
	{ 0x38,0x0,L"ZwGetNextProcess",xx_ZwGetNextProcess_175F0,{0x3ff,0x3ff,0x3ff,0x3ff,0x173,0x16f,0x16f,0x8b,0x8b,0x10e,0x110,0x110,0x10f,0x10f,0x10f,0x112,0x113,0x113} },
	{ 0x2d,0x0,L"ZwUnmapViewOfSection",xx_ZwUnmapViewOfSection_17860,{0x3ff,0xe7,0x10b,0x115,0x160,0x15c,0x15c,0x181,0x181,0x13,0x13,0x13,0x13,0x13,0x13,0x13,0x14,0x14} },
	{ 0x2e,0x0,L"ZwAssignProcessToJobObject",xx_ZwAssignProcessToJobObject_17A90,{0x3ff,0x12,0x13,0x15,0x2a,0x2a,0x2a,0x2b,0x2b,0x179,0x17e,0x17e,0x17d,0x17d,0x17d,0x182,0x183,0x183} },
	{ 0x2f,0x0,L"ZwAllocateVirtualMemory",xx_ZwAllocateVirtualMemory_17CC0,{0x3ff,0x10,0x11,0x12,0x12,0x12,0x12,0x13,0x13,0x193,0x197,0x197,0x196,0x196,0x196,0x19b,0x19c,0x19c} },
	{ 0x39,0x0,L"ZwFreeVirtualMemory",xx_ZwFreeVirtualMemory_17F40,{0x3ff,0x47,0x53,0x57,0x93,0x93,0x93,0x83,0x83,0x116,0x119,0x119,0x118,0x118,0x118,0x11c,0x11d,0x11d} },
	{ 0x3a,0x1,L"NtUserFindWindowEx",xx_NtUserFindWindowEx_186A0,{0x3ff,0x170,0x17a,0x179,0x187,0x187,0x187,0x18c,0x18c,0x1c7,0x1c9,0x1ca,0x1cb,0x1cc,0x1cb,0x1cc,0x1ce,0x1d2} },
	{ 0x19,0x1,L"NtUserBuildHwndList",xx_NtUserBuildHwndList_18910,{0x3ff,0x12e,0x138,0x137,0x142,0x142,0x142,0x143,0x143,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x1a,0x1,L"NtUserQueryWindow",xx_NtUserQueryWindow_18BB0,{0x3ff,0x1d2,0x1e3,0x1e1,0x1f8,0x1f8,0x1f8,0x203,0x203,0x1de,0x1e0,0x1e1,0x1e2,0x1e3,0x1e2,0x1e3,0x1e5,0x1e9} },
	{ 0x1b,0x1,L"NtUserGetForegroundWindow",xx_NtUserGetForegroundWindow_18DE0,{0x3ff,0x189,0x194,0x193,0x1a2,0x1a2,0x1a2,0x1a7,0x1a7,0x1aa,0x1ac,0x1ad,0x1ae,0x1ae,0x1ad,0x1ae,0x1af,0x1b3} },
	{ 0x1c,0x1,L"NtUserWindowFromPoint",xx_NtUserWindowFromPoint_18FD0,{0x3ff,0x238,0x250,0x24c,0x269,0x269,0x269,0x275,0x275,0x280,0x283,0x286,0x288,0x28a,0x289,0x28c,0x292,0x298} },
	{ 0x1d,0x1,L"NtUserSetParent",xx_NtUserSetParent_19200,{0x3ff,0x1fe,0x211,0x20e,0x226,0x226,0x226,0x230,0x230,0x246,0x249,0x24b,0x24d,0x24f,0x24e,0x251,0x253,0x259} },
	{ 0x1e,0x1,L"NtUserSetWindowLong",xx_NtUserSetWindowLong_19430,{0x3ff,0x20d,0x220,0x21c,0x236,0x236,0x236,0x242,0x242,0x230,0x232,0x234,0x236,0x237,0x236,0x239,0x23b,0x23f} },
	{ 0x1f,0x1,L"NtUserMoveWindow",xx_NtUserMoveWindow_19680,{0x3ff,0x1c1,0x1d1,0x1d0,0x1e4,0x1e4,0x1e4,0x1ef,0x1ef,0x1f3,0x1f5,0x1f6,0x1f7,0x1f8,0x1f7,0x1f9,0x1fb,0x1ff} },
	{ 0x20,0x1,L"NtUserSetWindowPos",xx_NtUserSetWindowPos_19900,{0x3ff,0x20f,0x222,0x21e,0x238,0x238,0x238,0x244,0x244,0x22e,0x230,0x232,0x234,0x235,0x234,0x237,0x239,0x23d} },
	{ 0x21,0x1,L"NtUserSetWindowPlacement",xx_NtUserSetWindowPlacement_19BA0,{0x3ff,0x20e,0x221,0x21d,0x237,0x237,0x237,0x243,0x243,0x22f,0x231,0x233,0x235,0x236,0x235,0x238,0x23a,0x23e} },
	{ 0x22,0x1,L"NtUserShowWindow",xx_NtUserShowWindow_19DD0,{0x3ff,0x218,0x22b,0x227,0x243,0x243,0x243,0x24f,0x24f,0x223,0x225,0x227,0x229,0x22a,0x229,0x22c,0x22e,0x232} },
	{ 0x23,0x1,L"NtUserShowWindowAsync",xx_NtUserShowWindowAsync_1A000,{0x3ff,0x219,0x22c,0x228,0x244,0x244,0x244,0x250,0x250,0x222,0x224,0x226,0x228,0x229,0x228,0x22b,0x22d,0x231} },
	{ 0x24,0x1,L"NtUserSendInput",xx_NtUserSendInput_1A230,{0x3ff,0x1e1,0x1f6,0x1f4,0x20d,0x20d,0x20d,0x218,0x218,0x25e,0x261,0x263,0x265,0x267,0x266,0x269,0x26b,0x271} },
	{ 0x25,0x1,L"NtUserSetWinEventHook",xx_NtUserSetWinEventHook_1A680,{0x3ff,0x215,0x228,0x224,0x240,0x240,0x240,0x24c,0x24c,0x226,0x228,0x22a,0x22c,0x22d,0x22c,0x22f,0x231,0x235} },
	{ 0x31,0x1,L"NtUserClipCursor",xx_NtUserClipCursor_1A470,{0x3ff,0x0,0x14a,0x149,0x157,0x157,0x157,0x15c,0x15c,0x14d,0x14e,0x14f,0x14f,0x14f,0x14f,0x151,0x152,0x156} },
	{ 0x30,0x1,L"NtUserSetWindowsHookEx",xx_NtUserSetWindowsHookEx_1A930,{0x3ff,0x212,0x225,0x221,0x23d,0x23d,0x23d,0x249,0x249,0x229,0x22b,0x22d,0x22f,0x230,0x22f,0x232,0x234,0x238} },
	{ 0x32,0x0,L"ZwMakeTemporaryObject",xx_ZwMakeTemporaryObject_18190,{0x3ff,0x3ff,0x69,0x6e,0xae,0xae,0xae,0xa4,0xa4,0xf6,0xf8,0xf8,0xf7,0xf7,0xf7,0xfa,0xfb,0xfb} },
	{ 0x3b,0x0,L"ZwCreateUserProcess",xx_ZwCreateUserProcess_183A0,{0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x17f,0x17f,0x5d,0x5d,0x142,0x146,0x146,0x145,0x145,0x145,0x149,0x14a,0x14a} },
	{ 0x3c,0x1,L"NtUserMessageCall",xx_NtUserMessageCall_1ABB0,{0x3ff,0x1bc,0x1cc,0x1cb,0x1df,0x1df,0x1df,0x1ea,0x1ea,0x1f8,0x1fa,0x1fb,0x1fc,0x1fd,0x1fc,0x1fe,0x200,0x204} },
	{ 0x3d,0x1,L"NtUserPostMessage",xx_NtUserPostMessage_1AE50,{0x3ff,0x1cb,0x1db,0x1da,0x1f1,0x1f1,0x1f1,0x1fc,0x1fc,0x1e6,0x1e8,0x1e9,0x1ea,0x1eb,0x1ea,0x1ec,0x1ee,0x1f2} },
	{ 0x3e,0x1,L"NtUserPostThreadMessage",xx_NtUserPostThreadMessage_1B0A0,{0x3ff,0x1cc,0x1dc,0x1db,0x1f2,0x1f2,0x1f2,0x1fd,0x1fd,0x1e5,0x1e7,0x1e8,0x1e9,0x1ea,0x1e9,0x1eb,0x1ed,0x1f1} },
	{ 0x3f,0x1,L"NtUserBuildHwndList_WIN8",xx_NtUserBuildHwndList_WIN8_1B2F0,{0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x166,0x167,0x168,0x168,0x168,0x168,0x16a,0x16b,0x16f} },
	{ 0x40,0x0,L"ZwFsControlFile",xx_ZwFsControlFile_1B5A0,{0x3ff,0x3ff,0x54,0x3ff,0x96,0x96,0x96,0x86,0x86,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x41,0x1,L"NtUserSetImeInfoEx",xx_NtUserSetImeInfoEx_1B880,{0x3ff,0x3ff,0x205,0x3ff,0x3ff,0x3ff,0x3ff,0x226,0x226,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x258,0x25b,0x25d,0x263} },
	{ 0x42,0x0,L"ZwCreateProcessEx",xx_ZwCreateProcessEx_1BA90,{0x3ff,0x3ff,0x30,0x32,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x48,0x1,L"NtUserGetRawInputData",xx_NtUserGetRawInputData_1BD60,{0x3ff,0x3ff,0x1ac,0x3ff,0x3ff,0x3ff,0x3ff,0x1c0,0x1c0,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x43,0x1,L"NtUserGetRawInputBuffer",xx_NtUserGetRawInputBuffer_1BFD0,{0x3ff,0x3ff,0x1ab,0x3ff,0x3ff,0x3ff,0x3ff,0x1bf,0x1bf,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x44,0x1,L"NtUserGetAsyncKeyState",xx_NtUserGetAsyncKeyState_1C210,{0x3ff,0x3ff,0x17f,0x3ff,0x3ff,0x3ff,0x3ff,0x192,0x192,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x45,0x1,L"NtUserGetKeyState",xx_NtUserGetKeyState_1C420,{0x3ff,0x3ff,0x1a0,0x3ff,0x3ff,0x3ff,0x3ff,0x1b4,0x1b4,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x46,0x1,L"NtUserGetKeyboardState",xx_NtUserGetKeyboardState_1C630,{0x3ff,0x3ff,0x19e,0x3ff,0x3ff,0x3ff,0x3ff,0x1b2,0x1b2,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x47,0x0,L"ZwQueueApcThread",xx_ZwQueueApcThread_1C840,{0x3ff,0x3ff,0xb4,0x3ff,0x3ff,0x3ff,0x3ff,0x10d,0x10d,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x8b,0x8e,0x8f,0x8f} },
	{ 0x4a,0x0,L"ZwSetSecurityObject",xx_ZwSetSecurityObject_1CAB0,{0x3ff,0x3ff,0xed,0x3ff,0x3ff,0x3ff,0x3ff,0x15b,0x15b,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3b,0x3c,0x3d,0x3d} },
	{ 0x4b,0x0,L"ZwOpenFile",xx_ZwOpenFile_1CCF0,{0x3ff,0x3ff,0x74,0x3ff,0x3ff,0x3ff,0x3ff,0xb3,0xb3,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0xe8,0xeb,0xec,0xec} },
	{ 0x4c,0x0,L"ZwQueueApcThreadEx",xx_ZwQueueApcThreadEx_1CF70,{0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x10e,0x10e,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x8a,0x8d,0x8e,0x8e} },
	{ 0x4d,0x0,L"ZwCreateMutant",xx_ZwCreateMutant_1D1F0,{0x3ff,0x3ff,0x2b,0x2d,0x43,0x43,0x43,0x4a,0x4a,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x15a,0x15e,0x15f,0x15f} },
	{ 0x4e,0x0,L"ZwQuerySystemInformation",xx_ZwQuerySystemInformation_1D440,{0x3ff,0x3ff,0xad,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x4f,0x0,L"ZwQueryIntervalProfile",xx_ZwQueryIntervalProfile_1D690,{0x3ff,0x3ff,0x9e,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x50,0x0,L"ZwSetInformationProcess",xx_ZwSetInformationProcess_1D8C0,{0x3ff,0x3ff,0xe4,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x51,0x1,L"NtGdiAddFontMemResourceEx",xx_NtGdiAddFontMemResourceEx_1DB10,{0x3ff,0x3ff,0x4,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x52,0x0,L"ZwReplyWaitReceivePortEx",xx_ZwReplyWaitReceivePortEx_1DD80,{0x3ff,0x3ff,0xc4,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x53,0x3,L"KeUserModeCallback",xx_KeUserModeCallback_1DFF0,{0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x33,0x0,L"ZwOpenKey",xx_ZwOpenKey_1E260,{0x3ff,0x3ff,0x77,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x54,0x0,L"ZwMapViewOfSection",xx_ZwMapViewOfSection_1E4A0,{0x3ff,0x3ff,0x6c,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x55,0x0,L"ZwSetIntervalProfile",xx_ZwSetIntervalProfile_1E780,{0x3ff,0x3ff,0xe7,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x56,0x1,L"NtGdiAddFontResourceW",xx_NtGdiAddFontResourceW_1E9B0,{0x3ff,0x3ff,0x2,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x57,0x1,L"NtGdiAddRemoteFontToDC",xx_NtGdiAddRemoteFontToDC_1EC30,{0x3ff,0x3ff,0x3,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x58,0x0,L"ZwQueryInformationProcess",xx_ZwQueryInformationProcess_1EE80,{0x3ff,0x3ff,0x9a,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x59,0x0,L"ZwQueryInformationThread",xx_ZwQueryInformationThread_1F0F0,{0x3ff,0x3ff,0x9b,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x5a,0x0,L"ZwCreateProfile",xx_ZwCreateProfile_1F360,{0x3ff,0x3ff,0x31,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x5b,0x0,L"ZwVdmControl",xx_ZwVdmControl_1F630,{0x3ff,0x3ff,0x10c,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x5c,0x0,L"ZwCreateProcess",xx_ZwCreateProcess_1F860,{0x3ff,0x3ff,0x2f,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x5d,0x1,L"NtGdiAddEmbFontToDC",xx_NtGdiAddEmbFontToDC_1FB10,{0x3ff,0x3ff,0xd6,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x5e,0x0,L"NtDebugActiveProcess",xx_NtDebugActiveProcess_1FD40,{0x3ff,0x3ff,0x39,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x5f,0x0,L"NtAlpcCreatePort",xx_NtAlpcCreatePort_1FF70,{0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x17,0x17,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x191,0x196,0x197,0x197} },
	{ 0x60,0x0,L"NtCreatePort",xx_NtCreatePort_201B0,{0x3ff,0x3ff,0x2e,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff} },
	{ 0x61,0x2,NULL,{0xffffffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0} },
	{ 0x62,0x0,NULL,{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0} }
	*/
};

NTSTATUS TsFltMgrDeviceControl(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);
NTSTATUS TsFltMgrDefaultHandler(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);
NTSTATUS TsFltMgrShutdownControl(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);

NTSTATUS xx_DeviceExtension_11D50(int IoctlCode_a1, PULONG pFuncAddress_a2);
void DriverReinitializationRoutine(struct _DRIVER_OBJECT *DriverObject, PVOID Context, ULONG Count);
UINT xx_Init_10630();
PVOID xx_GetProAddress_11630(int a1, ULONG_PTR pBase_a2, char *strFuncName_a3);
BOOLEAN xx_GetSysModuleInfo_10720(char *pNeedModuleName_a1, void *pSysModuleInfo_a2);

#ifdef __cplusplus
extern "C" NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING  RegistryPath);
#endif

NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING  RegistryPath)
{
	PTsFlt_DEVICE_EXTENSION pDeviceExtension;
	UNICODE_STRING DeviceName,Win32Device;
	PDEVICE_OBJECT DeviceObject = NULL;
	NTSTATUS status;
	ULONG i;

	RtlInitUnicodeString(&DeviceName,L"\\Device\\TsFltMgr");
	status = IoCreateDevice(DriverObject,
		0x18,
		&DeviceName,
		0x8000,
		0,
		TRUE,
		&DeviceObject);
	if (!NT_SUCCESS(status))
		return status;
	if (!DeviceObject)
		return STATUS_UNEXPECTED_IO_ERROR;
	
	IoRegisterShutdownNotification(DeviceObject);

	pDeviceExtension = (PTsFlt_DEVICE_EXTENSION)DeviceObject->DeviceExtension;
	if ( pDeviceExtension )
	{
		pDeviceExtension->Type = 'TSFL';
		pDeviceExtension->FunctionPoint = xx_DeviceExtension_11D50;
	}

	RtlInitUnicodeString(&Win32Device,L"\\DosDevices\\TsFltMgr");
	status = IoCreateSymbolicLink(&Win32Device, &DeviceName);
	if (!NT_SUCCESS(status))
	{
		ExDeleteNPagedLookasideList(&g_Lookaside);
		if ( DeviceObject )
			IoDeleteDevice(DeviceObject);
		return status;
	}

	DriverObject->MajorFunction[IRP_MJ_CREATE] = TsFltMgrDefaultHandler;
	DriverObject->MajorFunction[IRP_MJ_CLOSE] = TsFltMgrDefaultHandler;
	DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = TsFltMgrDeviceControl;
	DriverObject->MajorFunction[IRP_MJ_SHUTDOWN] = TsFltMgrShutdownControl;

	IoRegisterBootDriverReinitialization(DriverObject, DriverReinitializationRoutine, 0);
	ExInitializeNPagedLookasideList(&g_Lookaside, 0, 0, 0, sizeof(NPAGED_LOOKASIDE_LIST)/*0xCCu*/, 'SRVP', 0);
	xx_Init_10630();

	return STATUS_SUCCESS;
}

NTSTATUS TsFltMgrDefaultHandler(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp)
{
	Irp->IoStatus.Status = STATUS_SUCCESS;
	Irp->IoStatus.Information = 0;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

NTSTATUS TsFltMgrDeviceControl(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp)
{
	Irp->IoStatus.Status = STATUS_NOT_SUPPORTED;
	Irp->IoStatus.Information = 0;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return Irp->IoStatus.Status;
}

NTSTATUS TsFltMgrShutdownControl(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp)
{
	Irp->IoStatus.Status = STATUS_NOT_SUPPORTED;
	Irp->IoStatus.Information = 0;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return Irp->IoStatus.Status;
}

int __stdcall xx_SetDwordGolbal_11BD0(BOOLEAN a1)
{
	int result; // eax@1

	result = a1;
	g_FilterFlag_dword_281D4 = a1;
	return result;
}

unsigned int __stdcall xx_GetFunInfoIndexFromList_11BE0(ULONG index_a1, char a2)
{
	PTsFlt_FILTER pTsFltFilter; // eax@1

	if ( index_a1 < arraysize(g_FuncFilterInfo_dword_281F0) )
	{
		pTsFltFilter = g_FuncFilterInfo_dword_281F0[index_a1];
		if ( pTsFltFilter )
		{
			pTsFltFilter->OtherModuleFuncReserve = a2;
		}
		
	}
	return index_a1;
}

BOOLEAN xx_StartTimer_21250(ULONG index_a1, int pInfo_a2)
{
	PTsFlt_MODULE_INTERFACE pTsFltModuleInterface_v3;
	BOOLEAN isSuccess = FALSE;
	PKTIMER pKtimer_v4;
	LARGE_INTEGER Time = {0};
	Time.QuadPart = 1000000;

	if ( pInfo_a2 && index_a1 < TS_MAX_OTHER_MODULE_FUNC )
	{
		pTsFltModuleInterface_v3 = (PTsFlt_MODULE_INTERFACE)(pInfo_a2 + 8);
		pKtimer_v4 = pTsFltModuleInterface_v3[index_a1].Timer;
		KeInitializeTimer(pKtimer_v4);
		while ( pTsFltModuleInterface_v3->Reserve2 )
		{ 
			KeSetTimer(pKtimer_v4, Time, 0);
			KeWaitForSingleObject(pKtimer_v4, Executive, 0, 0, 0);
		}
		isSuccess = KeCancelTimer(pKtimer_v4);
	}
	return isSuccess;
}

NTSTATUS __fastcall xx_StartTimerByFuncInfoList_212B0(unsigned int index_a1, PVOID pFunction_a2)
{
	NTSTATUS result; 
	PTsFlt_FILTER pFunInfo_v3; 
	ULONG index_v4; 
	PTsFlt_MODULE_INTERFACE pTsFltModuleInterface_v5; 
	PCHAR v6;

	result = STATUS_UNSUCCESSFUL;
	if ( pFunction_a2 )
	{
		if ( index_a1 < arraysize(g_FuncFilterInfo_dword_281F0) )
		{
			pFunInfo_v3 = g_FuncFilterInfo_dword_281F0[index_a1];
			if ( pFunInfo_v3 )
			{
				if ( pFunInfo_v3->IsHook == TRUE )
				{
					index_v4 = 0;
					pTsFltModuleInterface_v5 = (PTsFlt_MODULE_INTERFACE)(PCHAR)&pFunInfo_v3->ModuleInterface[0];
					while ( !pTsFltModuleInterface_v5 || pTsFltModuleInterface_v5->FuncAddress != pFunction_a2 )
					{
						++index_v4;
						pTsFltModuleInterface_v5 = (PTsFlt_MODULE_INTERFACE)((PCHAR)pTsFltModuleInterface_v5 + sizeof(TsFlt_MODULE_INTERFACE));
						if ( index_v4 >= TS_MAX_OTHER_MODULE_FUNC )
						{
							return result;
						}
					}
					v6 = (PCHAR)&pFunInfo_v3->OtherModuleFuncReserve;
					pTsFltModuleInterface_v5->Count = 0;
					InterlockedIncrement((volatile LONG *)(&pTsFltModuleInterface_v5->Count));
					xx_StartTimer_21250(index_v4, (int)v6);
					InterlockedExchange((volatile LONG *)(&pTsFltModuleInterface_v5->FuncAddress), 0);

					InterlockedDecrement((volatile LONG *)(&pFunInfo_v3->OtherModuleFuncCount));
					xx_StartTimer_21250(index_v4, (int)v6);
					InterlockedDecrement((volatile LONG *)(&pTsFltModuleInterface_v5->Count));

					result = STATUS_SUCCESS;
				}
			}
		}
	}
	return result;
}

NTSTATUS __stdcall xx_StartTimerByFuncInfoList_11CA0(unsigned int a1, PVOID a2)
{
	return xx_StartTimerByFuncInfoList_212B0(a1, a2);
}

NTSTATUS __stdcall xx_GetGlobalFlag_11CD0(PULONG a1, PULONG a2, PULONG a3, PULONG a4)
{
	if ( g_SystemVersion_dword_281E8 && !g_SsdtType_dword_281DC && g_Flag_dword_281EC == -1 )
	{
		if ( a1 )
			*(DWORD *)a1 = 0;
		if ( a2 )
			*(DWORD *)a2 = g_HookKiSystemFastCallFlag_dword_281E4;
		if ( a3 )
			*(DWORD *)a3 = g_SystemVersion_dword_281E8;
		if ( a4 )
			*(DWORD *)a4 = g_Flag_dword_281EC;
	}
	return STATUS_UNSUCCESSFUL;
}

ULONG xx_GetFuncInfoList_11D40()
{
	return (ULONG)g_FuncFilterInfo_dword_281F0;
}

PVOID __stdcall xx_SetOtherModuleFunctionIntoNotifyInfo_11C10(PTsFlt_NOTIFY_INFO pTsFltNotifyInfo_a1, PVOID pFunc_a2, PVOID pFunc_a3)
{
	if ( pTsFltNotifyInfo_a1 )
	{
		pTsFltNotifyInfo_a1->OtherModuleFuncFlag[pTsFltNotifyInfo_a1->OtherModuleFuncIndex] = (ULONG)pFunc_a3;
		pTsFltNotifyInfo_a1->OtherModuleFunc[pTsFltNotifyInfo_a1->OtherModuleFuncIndex] = (ULONG)pFunc_a2;
		++pTsFltNotifyInfo_a1->Count;
	}
	return pTsFltNotifyInfo_a1;
}

//这里精妙之处
NTSTATUS xx_CallNotifyInfoFunction_11C40(PULONG pParameter_a1, PVOID pParameter_a2, PTsFlt_NOTIFY_INFO pTsFltNotifyInfo_a3)
{
	int ParameterNumber_v4 = 0;
	ULONG Parameter_v5 = 0;
	NTSTATUS result = STATUS_UNSUCCESSFUL;

	if ( pTsFltNotifyInfo_a3 && pTsFltNotifyInfo_a3->ProxyFunction )
	{
		ParameterNumber_v4 = pTsFltNotifyInfo_a3->ParameterNumber;
		if ( ParameterNumber_v4 )
		{
			ParameterNumber_v4 = ParameterNumber_v4 - 1;
			do
			{
				Parameter_v5 = pTsFltNotifyInfo_a3->Parameter[ParameterNumber_v4];
				*pParameter_a1 = Parameter_v5;
				--ParameterNumber_v4;

				__asm push Parameter_v5
			}
			while ( ParameterNumber_v4 >= 0 );

			Parameter_v5 = (ULONG)pTsFltNotifyInfo_a3->ProxyFunction;

			__asm mov eax,Parameter_v5
			__asm call eax
			__asm mov result,eax
		}
	}
	else
	{
		result = STATUS_INVALID_PARAMETER;
	}
	return result;
}

NTSTATUS xx_SetOtherModuleFunctionIntoFilterInfoEx_21360(PVOID pFunc_a1, ULONG index_a2, PULONG pRet_a3, ULONG Type_a4, ULONG indexOfArray_a5)
{
	NTSTATUS result;
	PTsFlt_FILTER pTsFltFilter_v6;
	ULONG count_v7;

	result = STATUS_UNSUCCESSFUL;
	if ( pFunc_a1 )
	{
		if ( index_a2 < arraysize(g_FuncFilterInfo_dword_281F0) && indexOfArray_a5 < TS_MAX_OTHER_MODULE_FUNC )
		{
			pTsFltFilter_v6 = g_FuncFilterInfo_dword_281F0[index_a2];
			if ( pTsFltFilter_v6 )
			{
				if ( pTsFltFilter_v6->IsHook == TRUE )
				{
					if (pTsFltFilter_v6->ModuleInterface[indexOfArray_a5].FuncAddress)//if ( *(DWORD *)((indexOfArray_a5 << 6) + pTsFltFilter_v6 + 0x130) )
					{
						for (count_v7 = 0; pTsFltFilter_v6->ModuleInterface[count_v7].FuncAddress; count_v7++)
						{
							if ( count_v7 >= TS_MAX_OTHER_MODULE_FUNC )
								return result;
						}
						
						pTsFltFilter_v6->ModuleInterface[count_v7].Type = Type_a4; //*(DWORD *)((count_v7 << 6) + pTsFltFilter_v6 + 0xF8) = Type_a4;
						InterlockedExchange((PLONG)&pTsFltFilter_v6->ModuleInterface[count_v7].FuncAddress, (LONG)pFunc_a1);//InterlockedExchange((volatile LONG *)((count_v7 << 6) + pTsFltFilter_v6 + 0x130), pFunc_a1);
						InterlockedIncrement((PLONG)&pTsFltFilter_v6->OtherModuleFuncCount);
						result = 0;
						if ( pRet_a3 )
						{
							*pRet_a3 = count_v7;
						}
					}
					else
					{
						pTsFltFilter_v6->ModuleInterface[indexOfArray_a5].Type = Type_a4;//*(DWORD *)((indexOfArray_a5 << 6) + pTsFltFilter_v6 + 0xF8) = Type_a4;
						InterlockedExchange((PLONG)&pTsFltFilter_v6->ModuleInterface[indexOfArray_a5].FuncAddress, (LONG)pFunc_a1);//InterlockedExchange((volatile LONG *)((indexOfArray_a5 << 6) + pTsFltFilter_v6 + 0x130), pFunc_a1);
						InterlockedIncrement((PLONG)&pTsFltFilter_v6->OtherModuleFuncCount);//InterlockedIncrement((volatile LONG *)(pTsFltFilter_v6 + 0xF4));
						result = 0;
						if ( pRet_a3 )
						{
							*pRet_a3 = indexOfArray_a5;
						}
					}
				}
			}
		}
	}
	return result;
}

NTSTATUS __stdcall xx_SetOtherModuleFunctionIntoFilterInfo_11CB0(ULONG Index_a1, PVOID pFunc_a2, ULONG Type_a3, ULONG indexOfArray_a4, PULONG pRet_a5)
{
	return xx_SetOtherModuleFunctionIntoFilterInfoEx_21360(pFunc_a2, Index_a1, pRet_a5, Type_a3, indexOfArray_a4);
}

NTSTATUS xx_DeviceExtension_11D50(int IoctlCode_a1, PULONG pFuncAddress_a2)
{
	NTSTATUS result = 0;

	if ( pFuncAddress_a2 )
	{
		result = 0;
		switch ( IoctlCode_a1 )
		{
		case 0:
			*(DWORD *)pFuncAddress_a2 = (DWORD)xx_SetDwordGolbal_11BD0;
			break;
		case 1:
			*(DWORD *)pFuncAddress_a2 = (DWORD)xx_GetFunInfoIndexFromList_11BE0;
			break;
		case 2:
			*(DWORD *)pFuncAddress_a2 = (DWORD)xx_SetOtherModuleFunctionIntoNotifyInfo_11C10;
			break;
		case 3:
			*(DWORD *)pFuncAddress_a2 = (DWORD)xx_CallNotifyInfoFunction_11C40;
			break;
		case 4:
			*(DWORD *)pFuncAddress_a2 = (DWORD)xx_SetOtherModuleFunctionIntoFilterInfo_11CB0;
			break;
		case 5:
			*(DWORD *)pFuncAddress_a2 = (DWORD)xx_StartTimerByFuncInfoList_11CA0;
			break;
		case 6:
			*(DWORD *)pFuncAddress_a2 = (DWORD)xx_GetGlobalFlag_11CD0;
			break;
		case 7:
			*(DWORD *)pFuncAddress_a2 = (DWORD)xx_GetFuncInfoList_11D40;
			break;
		default:
			*(DWORD *)pFuncAddress_a2 = 0;
			result = STATUS_UNSUCCESSFUL;
		}
	}
	else
	{
		result = STATUS_UNSUCCESSFUL;
	}
	return result;
}

PCHAR xx_GetProcessName_111E0(PEPROCESS pEprocess_a1)
{
	PVOID PsGetProcessImageFileName_v1;
	PCHAR result;
	UNICODE_STRING DestinationString;

	if ( !g_BuildNumber )
	{
		PsGetVersion(0, 0, &g_BuildNumber, 0);
	}

	PsGetProcessImageFileName_v1 = g_PsGetProcessImageFileName_dword_28178;
	if ( g_PsGetProcessImageFileName_dword_28178 || g_BuildNumber != 2195)
	{
		RtlInitUnicodeString(&DestinationString, L"PsGetProcessImageFileName");
		PsGetProcessImageFileName_v1 = MmGetSystemRoutineAddress(&DestinationString);
		g_PsGetProcessImageFileName_dword_28178 = (PVOID)PsGetProcessImageFileName_v1;
		if (g_PsGetProcessImageFileName_dword_28178)
		{
			result = ((PCHAR (__stdcall *)(PEPROCESS))PsGetProcessImageFileName_v1)(pEprocess_a1);
		}
	}
	else
	{
		result = (PCHAR)"OS_2000";
	}
	return result;
}


NTSTATUS xx_QueryValueKey_10E70(PCWSTR RegSourceString, PCWSTR ValueSourceStringa, void *pData_a3, int pDataLen_a4, int pRet_a5)
{
	PVOID pBuffer_v5 = 0;
	NTSTATUS status_v6;
	PVOID pBuffer_v7;
	NTSTATUS result;
	HANDLE KeyHandle = NULL;
	ULONG ResultLength = 0;
	LSA_UNICODE_STRING DestinationString;
	LSA_UNICODE_STRING ValueName;
	OBJECT_ATTRIBUTES ObjectAttributes = {0};

	if ( RegSourceString && ValueSourceStringa )
	{
		RtlInitUnicodeString(&DestinationString, RegSourceString);
		InitializeObjectAttributes(&ObjectAttributes,&DestinationString, 576, 0, 0)
		status_v6 = ZwOpenKey(&KeyHandle, (ACCESS_MASK)0x00020019, &ObjectAttributes);
		if ( status_v6 >= 0 )
		{
			pBuffer_v5 = ExAllocatePoolWithTag(NonPagedPool, 0x218u, ' kdD');
			if ( pBuffer_v5 )
			{
				memset(pBuffer_v5, 0, 0x218u);
				RtlInitUnicodeString(&ValueName, ValueSourceStringa);
				status_v6 = ZwQueryValueKey(
					KeyHandle,
					&ValueName,
					KeyValuePartialInformation,
					pBuffer_v5,
					0x218u,
					&ResultLength);
				if ( status_v6 >= 0 )
				{
					if ( pRet_a5 )
						*(DWORD *)pRet_a5 = *((DWORD *)pBuffer_v5 + 1);
					if ( pData_a3 )
					{
						if ( (unsigned int)pDataLen_a4 < *((DWORD *)pBuffer_v5 + 2) )
							memcpy(pData_a3, (char *)pBuffer_v5 + 12, pDataLen_a4);
						else
							memcpy(pData_a3, (char *)pBuffer_v5 + 12, *((DWORD *)pBuffer_v5 + 2));
					}
				}
			}
		}
		if ( KeyHandle )
			ZwClose(KeyHandle);
		if ( pBuffer_v5 )
			ExFreePool(pBuffer_v5);
		result = status_v6;
	}
	else
	{
		result = STATUS_INVALID_PARAMETER;
	}
	return result;
}

NTSTATUS __stdcall xx_OpenKeyTsFltMgr_10D80(PHANDLE pHandle)
{
	NTSTATUS status_v1 = STATUS_UNSUCCESSFUL;
	HANDLE Handle = NULL;
	HANDLE KeyHandle = NULL;
	UNICODE_STRING DestinationString = {0};
	UNICODE_STRING DestinationString_v6 = {0};
	OBJECT_ATTRIBUTES ObjectAttributes = {0};
	OBJECT_ATTRIBUTES ObjectAttributes_v8 = {0};

	RtlInitUnicodeString(&DestinationString, L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Services\\TsFltMgr");
	InitializeObjectAttributes(&ObjectAttributes, &DestinationString, 512, 0, 0);
	status_v1 = ZwOpenKey(&KeyHandle, 0xF003Fu, &ObjectAttributes);
	if ( NT_SUCCESS(status_v1) )
	{
		RtlInitUnicodeString(&DestinationString_v6, L"TsFltInfo");
		InitializeObjectAttributes(&ObjectAttributes_v8, &DestinationString_v6, 512, KeyHandle, 0);
		status_v1 = ZwCreateKey(&Handle, 0xF003Fu, &ObjectAttributes_v8, 0, 0, 0, 0);
		if ( NT_SUCCESS(status_v1))
		{
			if ( pHandle )
			{
				*(HANDLE *)pHandle = Handle;
			}
			else
			{
				ZwClose(Handle);
			}
		}
	}
	if ( KeyHandle )
	{
		ZwClose(KeyHandle);
	}
	return status_v1;
}

NTSTATUS xx_InitializeResourceLite_223F0()
{
	NTSTATUS result;
	PTsFlt_PERESOURCE pTemp = NULL;

	if ( g_pInitResourceLiteInfo_dword_2A398 )
	{
		result = STATUS_SUCCESS;
	}
	else
	{
		pTemp = (PTsFlt_PERESOURCE)ExAllocatePoolWithTag(NonPagedPool, sizeof(TsFlt_PERESOURCE)/*0x240u*/, 'KPOT');
		g_pInitResourceLiteInfo_dword_2A398 = pTemp;
		if ( pTemp )
		{
			memset(pTemp, 0, sizeof(TsFlt_PERESOURCE)/*0x240u*/);
			result = ExInitializeResourceLite((PERESOURCE)&pTemp->Eresouce);
			g_pInitResourceLiteInfo_dword_2A398->Status = result;
			g_IsExInitializeResourceLiteSuccess_byte_2A39C = TRUE;
		}
		else
		{
			result = STATUS_UNSUCCESSFUL;
		}
	}
	return result;
}

PVOID xx_GetFunctionClassPoint_22FF0()
{
	PVOID result; // eax@1
	PVOID pBuffer_v1; // esi@2

	result = 0;
	if ( g_IsExInitializeResourceLiteSuccess_byte_2A39C )
	{
		result = ExAllocatePoolWithTag(NonPagedPool, 0x48u, 'KPOT');
		pBuffer_v1 = result;
		if ( result )
		{
			/*memset(result, 0, 0x48u);
			*((DWORD *)pBuffer_v1 + 0) = xx_CreateMsgPort_22CF0;
			*((DWORD *)pBuffer_v1 + 1) = sub_22E50;
			*((DWORD *)pBuffer_v1 + 2) = sub_22F20;
			*((DWORD *)pBuffer_v1 + 3) = sub_22F80;
			*((DWORD *)pBuffer_v1 + 4) = sub_22960;
			*((DWORD *)pBuffer_v1 + 5) = sub_228F0;
			*((DWORD *)pBuffer_v1 + 6) = sub_226D0;
			*((DWORD *)pBuffer_v1 + 7) = xx_InsertIntoList_22800;
			*((DWORD *)pBuffer_v1 + 8) = xx_GetResourceSharedLiteInfo_22460;
			*((DWORD *)pBuffer_v1 + 9) = xx_InterlockedDecrement_224F0;*/
			result = pBuffer_v1;
		}
	}
	return result;
}

NTSTATUS xx_ZwWriteFile_220B0(PTsFlt_WRITE_FILE_BUFFER pWriteFileBufferInfo_a1, HANDLE FileHandle)
{
	ULONG Len_v2; // ST18_4@1
	void *pBuffer_v3; // ST14_4@1
	LARGE_INTEGER ByteOffset = {0}; // [sp+0h] [bp-14h]@1
	IO_STATUS_BLOCK IoStatusBlock; // [sp+8h] [bp-Ch]@1

	Len_v2 = pWriteFileBufferInfo_a1->Length;
	pBuffer_v3 = pWriteFileBufferInfo_a1->pBuffer;
	return ZwWriteFile(FileHandle, 0, 0, 0, &IoStatusBlock, pBuffer_v3, Len_v2, &ByteOffset, 0);
}

int xx_WriteFile_220F0(int a1, int a2, int a3)
{
	PVOID pFuncClassPoint_v3; // esi@1
	NTSTATUS result; // eax@1

	pFuncClassPoint_v3 = xx_GetFunctionClassPoint_22FF0();
	result = STATUS_UNSUCCESSFUL;
	if ( a1 && pFuncClassPoint_v3 && a3 )
	{
		result = (*(NTSTATUS (__stdcall **)(char *, int, NTSTATUS (__stdcall *)(int, HANDLE), int))pFuncClassPoint_v3)(
			(char *)pFuncClassPoint_v3 + 0x40,
			a1,
			(NTSTATUS (__stdcall *)(int,HANDLE))xx_ZwWriteFile_220B0,
			a2);
		if ( result >= 0 )
		{
			result = (*(int (__stdcall **)(DWORD, DWORD, char *))((int (__stdcall **)(DWORD, DWORD, DWORD))pFuncClassPoint_v3
				+ 8))(
				*((DWORD *)pFuncClassPoint_v3 + 0x10),
				*((DWORD *)pFuncClassPoint_v3 + 17),
				(char *)pFuncClassPoint_v3 + 40);
			*(PVOID *)a3 = pFuncClassPoint_v3;
		}
	}
	return result;
}

NTSTATUS xx_CreateFile_22030(PUNICODE_STRING pFileName_a1, PHANDLE pFileHandle_a2)
{
	NTSTATUS result; // eax@3
	HANDLE FileHandle; // [sp+4h] [bp-28h]@1
	IO_STATUS_BLOCK IoStatusBlock; // [sp+8h] [bp-24h]@3
	OBJECT_ATTRIBUTES ObjectAttributes; // [sp+10h] [bp-1Ch]@3

	FileHandle = 0;
	if ( pFileName_a1 && pFileHandle_a2 )
	{
		*(HANDLE *)pFileHandle_a2 = NULL;
		InitializeObjectAttributes(&ObjectAttributes, pFileName_a1, 576, 0, 0);
		result = ZwCreateFile(&FileHandle, 4u, &ObjectAttributes, &IoStatusBlock, 0, 0x80u, 3u, 5u, 0, 0, 0);
		if ( result >= 0 )
		{
			*(HANDLE *)pFileHandle_a2 = FileHandle;
		}
	}
	else
	{
		result = 0xC000000D;
	}
	return result;
}

unsigned int xx_WriteLog_22140(const WCHAR *pwstrFileName_a1)
{
	const WCHAR *wstrFileName_v1; // esi@1
	PTsFlt_PNPAGED_LOOKASIDE_LIST pBuffer_v2; // eax@2
	NTSTATUS status_v5 = STATUS_UNSUCCESSFUL; // eax@4
	HANDLE handle_v6 = NULL; // esi@4
	int v9; // [sp+14h] [bp-Ch]@1
	LSA_UNICODE_STRING DestinationString; // [sp+18h] [bp-8h]@4

	wstrFileName_v1 = pwstrFileName_a1;
	v9 = 0;
	if ( !pwstrFileName_a1 )
		return STATUS_INVALID_PARAMETER;

	pBuffer_v2 = (PTsFlt_PNPAGED_LOOKASIDE_LIST)ExAllocatePoolWithTag(NonPagedPool, 0x68u, 'KLog');
	if ( pBuffer_v2 )
	{
		memset(pBuffer_v2, 0, 0x68u);
		RtlInitUnicodeString(&DestinationString, wstrFileName_v1);
		status_v5 = xx_CreateFile_22030(&DestinationString, &handle_v6);
		if ( status_v5 >= 0 )
		{
			status_v5 = xx_WriteFile_220F0((int)&DestinationString, (int)handle_v6, (int)&v9);
			if ( status_v5 >= 0 )
			{
				ExInitializeNPagedLookasideList((PNPAGED_LOOKASIDE_LIST)(pBuffer_v2 + 24), 0, 0, 0, 0x200u, 'KLOG', 0);
				*(DWORD *)(pBuffer_v2 + 4) = v9;
				*(DWORD *)pBuffer_v2 = (DWORD)handle_v6;
				g_pTsFltPnpagedLoolasideList_28180 = pBuffer_v2;
				return status_v5;
			}
		}
		if ( handle_v6 )
			ZwClose(handle_v6);
		if ( status_v5 >= 0 )
			return status_v5;
	}
	else
	{
		status_v5 = STATUS_NO_MEMORY;
	}
	if ( pBuffer_v2 )
		ExFreePoolWithTag((PVOID)pBuffer_v2, 'Klog');
	return status_v5;
}

void xx_WriteTsDbgLog_112A0(char a1, PVOID P)
{
	int nRet = 4;
	char strBuf_v3[260];

	memset(strBuf_v3, 0, sizeof(strBuf_v3) - 1);
	
	if ( (xx_QueryValueKey_10E70(
		L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Services\\TsFltMgr",
		L"TsDbgLog",
		&strBuf_v3,
		sizeof(strBuf_v3),
		(int)&nRet) & 0x80000000) == 0
		&& nRet == 1
		&& xx_InitializeResourceLite_223F0() >= 0 )
	{
		xx_WriteLog_22140((const WCHAR *)&strBuf_v3);
		//xx_DbgPrint_22270(g_pTsFltPnpagedLoolasideList_28180, (int)"TS TsFltMgr DbgHelper", a1);
	}
	if (P)
	{
		ExFreePool(P);
	}
}

void DriverReinitializationRoutine(struct _DRIVER_OBJECT *DriverObject, PVOID Context, ULONG Count)
{
	PWORK_QUEUE_ITEM pWorkQueueItem = NULL; // eax@2

	if ( !g_pTsFltPnpagedLoolasideList_28180)
	{
		pWorkQueueItem = (PWORK_QUEUE_ITEM)ExAllocatePoolWithTag(NonPagedPool, sizeof(WORK_QUEUE_ITEM), 'TSFL');
		if ( pWorkQueueItem )
		{
			ExInitializeWorkItem(pWorkQueueItem, (PWORKER_THREAD_ROUTINE)xx_WriteTsDbgLog_112A0, pWorkQueueItem);
			ExQueueWorkItem((PWORK_QUEUE_ITEM)pWorkQueueItem, (WORK_QUEUE_TYPE)0);
		}
	}
}

NTSTATUS xx_wGetStrLen_233A4(PWCHAR wstrDes_a1, int nDesMaxLen_a2, int* pRealLen_a3)
{
	int wDesLen_v3;
	NTSTATUS result;
	PWCHAR wstr_v5;

	wstr_v5 = wstrDes_a1;
	wDesLen_v3 = nDesMaxLen_a2;
	result = STATUS_SUCCESS;

	if ( !nDesMaxLen_a2 )
	{
		return STATUS_INVALID_PARAMETER;
	}

	while (*wstr_v5 && wDesLen_v3--)
	{
		wstr_v5++;
	}

	if ( wDesLen_v3 && pRealLen_a3 )
	{
		*(int *)pRealLen_a3 = nDesMaxLen_a2 - wDesLen_v3;
	}
	else
	{
		result = STATUS_INVALID_PARAMETER;
	}
	return result;
}

NTSTATUS __stdcall xx_StrCpy_232DC(PUCHAR pret_a1, int len_a2, PUCHAR pName_a3)
{
	NTSTATUS result; // eax@1
	PUCHAR pRetBuffer_v4; // edx@3
	PUCHAR pInputBuffer_v5; // esi@3

	result = 0;
	if ( len_a2 )
	{
		pRetBuffer_v4 = pret_a1;
		pInputBuffer_v5 = pName_a3;

		while ( *pInputBuffer_v5 && len_a2--)
		{
			*pRetBuffer_v4++ = *pInputBuffer_v5++;
		}

		if ( !len_a2 )
		{
			--pRetBuffer_v4;
			result = 0x80000005;
		}
		*pRetBuffer_v4 = 0;
	}
	else
	{
		result = 0xC000000D;
	}
	return result;
}

NTSTATUS __stdcall xx_StrCpy_233DA(PUCHAR str_a1, int len_a2, PUCHAR pName_a3)
{
	NTSTATUS result; // eax@2

	if ( len_a2 <= 0x7FFFFFFF )
		result = xx_StrCpy_232DC(str_a1, len_a2, pName_a3);
	else
		result = 0xC000000D;
	return result;
}

NTSTATUS xx_wStrCat_23318(PWCHAR wstrDes_a1, int nDesMaxLen_a2, PWCHAR wstrSrc_a3)
{
	NTSTATUS result; // eax@1
	PWCHAR wstrDes_v4; // edx@3
	PWCHAR wstrSrc_v5; // esi@3

	result = STATUS_SUCCESS;
	if ( nDesMaxLen_a2 )
	{
		wstrDes_v4 = wstrDes_a1;
		wstrSrc_v5 = wstrSrc_a3;

		while ( *wstrSrc_v5 && nDesMaxLen_a2--)
		{
			*wstrDes_v4++ = *wstrSrc_v5++;
		}

		//假如空间不够
		if ( !nDesMaxLen_a2 )
		{
			wstrDes_v4--;
			result = 0x80000005;
		}
		*wstrDes_v4 = 0;
	}
	else
	{
		result = STATUS_INVALID_PARAMETER;
	}
	return result;
}

int xx_wStrCmp_2347F(PWCHAR wstrDes_a1, PWCHAR wstrSrc_a2)
{
	WCHAR *wstrDes_v2; // edx@1
	WCHAR *wstrSrc_v3; // esi@1
	WCHAR wDes_v5; // cx@3
	WCHAR wSrc_v6; // ax@5

	wstrDes_v2 = wstrDes_a1;
	wstrSrc_v3 = wstrSrc_a2;
	do
	{
		wDes_v5 = *wstrDes_v2 + 32;
		if ( *wstrDes_v2 < 0x41u || *wstrDes_v2 > 0x5Au)
		{
			wDes_v5 = *wstrDes_v2;
		}

		
		wSrc_v6 = *wstrSrc_v3 + 32;
		if ( *wstrSrc_v3 < 0x41u || *wstrSrc_v3 > 0x5Au )
		{
			wSrc_v6 = *wstrSrc_v3;	
		}

		++wstrDes_v2;
		++wstrSrc_v3;
	}
	while ( wDes_v5 && wDes_v5 == wSrc_v6 );

	return wDes_v5 - wSrc_v6;
}

NTSTATUS xx_MyWStrCat_23436(PWCHAR wstrDes_a1, int wDesMaxLen_a2, PWCHAR wstrSrc_a3)
{
	int Len_v3; // esi@1
	unsigned int result; // eax@1

	Len_v3 = wDesMaxLen_a2;
	result = xx_wGetStrLen_233A4(wstrDes_a1, wDesMaxLen_a2, &wDesMaxLen_a2);
	if ( (result & 0x80000000) == 0 )
	{
		result = xx_wStrCat_23318(&wstrDes_a1[wDesMaxLen_a2], Len_v3 - wDesMaxLen_a2, wstrSrc_a3);
	}
	return result;
}

NTSTATUS xx_MyWStrCat_23468(PWCHAR wstrDes_a1, unsigned int nDesMaxLen_a2, PWCHAR wstrSrc_a3)
{
	NTSTATUS result = STATUS_INVALID_PARAMETER;

	if ( nDesMaxLen_a2 <= 0x7FFFFFFF )
	{
		result = xx_MyWStrCat_23436(wstrDes_a1, nDesMaxLen_a2, wstrSrc_a3);
	}
	return result;
}

BOOLEAN xx_InitTsFltMgrRegistry_10540()
{
	BOOLEAN isSuccess_v0 = FALSE;
	ULONG Data = 0; 
	HANDLE KeyHandle = NULL;
	UNICODE_STRING DestinationString;
	WCHAR SourceString[260] = {0};

	memcpy(&SourceString, 
		L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Services\\TsFltMgr", 
		wcslen(L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Services\\TsFltMgr")*sizeof(WCHAR));
	
	xx_MyWStrCat_23468(SourceString, sizeof(SourceString), L"\\");
	xx_MyWStrCat_23468(SourceString, sizeof(SourceString), L"TsFltInfo");

	if ( (xx_QueryValueKey_10E70(SourceString, L"IsBsod", &Data, sizeof(Data), 0) & 0x80000000) == STATUS_SUCCESS )
	{
		if ( Data )
		{
			isSuccess_v0 = TRUE;
			if ( xx_OpenKeyTsFltMgr_10D80(&KeyHandle) >= 0 )
			{
				RtlInitUnicodeString(&DestinationString, L"IsBsod");
				Data = 1;
				ZwSetValueKey(KeyHandle, &DestinationString, 0, 4u, &Data, 4u);
				ZwClose(KeyHandle);
			}
		}
	}
	return isSuccess_v0;
}

TsFlt_OS_VERSION xx_GetVersion_113C0()
{
	TsFlt_OS_VERSION result = OS_UnKnow;
	ULONG BuildNumber = 0;
	ULONG MinorVersion = 0;
	ULONG MajorVersion = 0;

	PsGetVersion(&MajorVersion, &MinorVersion, &BuildNumber, 0);
	if ( BuildNumber <= 8250 )
	{
		if ( BuildNumber == 8250 )
			return OS_Win8_CR;

		if ( BuildNumber > 6001 )
		{
			if ( BuildNumber > 7601 )
			{
				if ( BuildNumber == 8102 )
					return OS_Win8;
			}
			else
			{
				if ( BuildNumber == 7601 )
					return OS_Win7_SP1;
				if ( BuildNumber == 6002 )
					return OS_WinVista_SP2;
				if ( BuildNumber == 7600 )
					return OS_Win7;
			}
		}
		else
		{
			if ( BuildNumber == 6001 )
				return OS_WinVista_SP1;
			if ( BuildNumber > 3790 )
			{
				if ( BuildNumber == 6000 )
					return OS_WinVista;
			}
			else
			{
				if ( BuildNumber == 3790 )
					return OS_Win2003;
				if ( BuildNumber == 2195 )
					return OS_Win2000;
				if ( BuildNumber == 2600 )
					return OS_WinXP;
			}
		}
		return result;
	}
	if ( BuildNumber > 9200 )
	{
		if ( BuildNumber == 9600 )
		{
			result = OS_Win8_1_RTM;
		}
		else
		{
			if ( BuildNumber == 9841 )
				return OS_Win10_RT1;
			if ( BuildNumber == 9860 )
				return OS_Win10_RT2;
		}
		return result;
	}
	if ( BuildNumber == 9200 )
	{
		result = OS_Win8_RTM;
	}
	else
	{
		switch ( BuildNumber )
		{
		case 8400:
			result = OS_Win8_RP;
			break;
		case 8432:
		case 8441:
			result = OS_Win8_RT1;
			break;
		case 8520:
			result = OS_Win8_RT2;
			break;
		default:
			return result;
		}
	}
	return result;
}

BOOLEAN xx_CheckTsFltMgrDws_11260()
{
	BOOLEAN result = TRUE;
	ULONG Data = 0;

	NTSTATUS status = xx_QueryValueKey_10E70(L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Services\\TsFltMgr", L"dws", &Data, sizeof(Data), 0);
	if (!NT_SUCCESS(status) || (Data != 1))
	{
		result = FALSE;
	}
	return result;
}

ULONG __stdcall xx_IsProcessRun_230A8(WCHAR* strName_a1)
{
	SIZE_T pBufferLen_v1 = 0;
	PVOID pBuffer_v2 = NULL;
	NTSTATUS status_v3 = STATUS_UNSUCCESSFUL; 
	PSYSTEM_PROCESS_INFORMATION pSystemProAndThreadInfo_v4 = NULL;
	BOOLEAN i = FALSE;
	ULONG IsSuccess_v7 = FALSE; 
	ULONG ReturnLength = 0;

	while ( TRUE )
	{
		if ( pBuffer_v2 )
		{
			ExFreePool(pBuffer_v2);
		}

		pBufferLen_v1 += 0x1000;
		pBuffer_v2 = ExAllocatePoolWithTag(NonPagedPool, pBufferLen_v1, 'QMDS');
		if ( !pBuffer_v2 )
		{
			return IsSuccess_v7;
		}

		memset(pBuffer_v2, 0, pBufferLen_v1);
		status_v3 = ZwQuerySystemInformation(SystemProcessesAndThreadsInformation, pBuffer_v2, pBufferLen_v1, &ReturnLength);
		if ( status_v3 != STATUS_INFO_LENGTH_MISMATCH)
		{
			if (NT_SUCCESS(status_v3))
			{
				pSystemProAndThreadInfo_v4 = (PSYSTEM_PROCESS_INFORMATION)pBuffer_v2;
				for ( i = MmIsAddressValid(pBuffer_v2); i; i = MmIsAddressValid(pSystemProAndThreadInfo_v4) )
				{
					if ( MmIsAddressValid(((PVOID *)pSystemProAndThreadInfo_v4->ProcessName.Buffer))
						&& !xx_wStrCmp_2347F((WCHAR*)strName_a1, pSystemProAndThreadInfo_v4->ProcessName.Buffer) )
					{
						IsSuccess_v7 = 1;
						break;
					}
					if ( !pSystemProAndThreadInfo_v4->NextEntryDelta )
						break;

					pSystemProAndThreadInfo_v4 = (PSYSTEM_PROCESS_INFORMATION)((char *)pSystemProAndThreadInfo_v4 + pSystemProAndThreadInfo_v4->NextEntryDelta);
				}
			}
			ExFreePool(pBuffer_v2);
			return IsSuccess_v7;
		}
	}
}

BOOL __stdcall xx_QueryRegeditValue_2315D(PCWSTR RegSourceString, PCWSTR ValueName_a2, PVOID pData_a3, ULONG nDateLen_a4, PULONG pRet_a5)
{
	PVOID pBuffer_v5 = NULL;
	ULONG DaLen_v6 = 0;
	OBJECT_ATTRIBUTES ObjectAttributes = {0};
	UNICODE_STRING ValueName = {0};
	UNICODE_STRING DestinationString = {0};
	ULONG ResultLength = 0;
	BOOL IsSuccess_v12 = FALSE;
	HANDLE KeyHandle = NULL;

#define REG_SIZE 0x218u

	if ( RegSourceString && ValueName_a2 )
	{
		RtlInitUnicodeString(&DestinationString, RegSourceString);
		InitializeObjectAttributes(&ObjectAttributes, &DestinationString, 576, 0, 0);

		if ( ZwOpenKey(&KeyHandle, (ACCESS_MASK)0x00020019, &ObjectAttributes) >= 0 )
		{
			pBuffer_v5 = ExAllocatePoolWithTag(NonPagedPool, 0x218u, 'QMDS');
			if ( pBuffer_v5 )
			{
				memset(pBuffer_v5, 0, REG_SIZE);
				RtlInitUnicodeString(&ValueName, ValueName_a2);
				if ( ZwQueryValueKey(KeyHandle, &ValueName, KeyValuePartialInformation, pBuffer_v5, REG_SIZE, &ResultLength) >= 0 )
				{
					DaLen_v6 = *((ULONG *)pBuffer_v5 + 2);
					if ( nDateLen_a4 >= DaLen_v6 )
					{
						memcpy((void *)pData_a3, (char *)pBuffer_v5 + 12, *((ULONG *)pBuffer_v5 + 2));
						IsSuccess_v12 = TRUE;
					}
					else if ( pRet_a5 )
					{
						*(ULONG *)pRet_a5 = DaLen_v6;
					}
				}
				ExFreePool(pBuffer_v5);
			}
		}
		if ( KeyHandle )
			ZwClose(KeyHandle);
	}
	return IsSuccess_v12;
}

WCHAR* g_ProNameArray_off_25AC0[] = 
{
	L"Winlogon.exe",
	L"Explorer.exe"
};

BOOLEAN __stdcall xx_CheckSysMonDwsBak_23285(ULONG IsSet_a1)
{
	BOOLEAN isSuccess_v1 = FALSE;
	ULONG Value_v3 = 0;

	if ( IsSet_a1 < 0x81
		&& !xx_IsProcessRun_230A8(g_ProNameArray_off_25AC0[0])// Winlogon.exe
		&& xx_QueryRegeditValue_2315D(
			L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\services\\QQSysMon\\DWS",
			L"DwsBak",
			&Value_v3,
			sizeof(Value_v3),
			0)
		&& (IsSet_a1 & Value_v3) )
	{
		isSuccess_v1 = TRUE;
	}
	return isSuccess_v1;
}

NTSTATUS xx_InitTsFltMgr_209E0()
{
	NTSTATUS result = STATUS_UNSUCCESSFUL; 
	HANDLE handle_v1 = NULL; 
	ULONG Data = 0;
	HANDLE KeyHandle = NULL;
	UNICODE_STRING DestinationString = {0};

	result = xx_OpenKeyTsFltMgr_10D80(&KeyHandle);
	if ( NT_SUCCESS(result) )
	{
		handle_v1 = KeyHandle;
		g_KeyHandle = KeyHandle;
		Data = 0;
		RtlInitUnicodeString(&DestinationString, L"LastErrorCode");
		ZwSetValueKey(handle_v1, &DestinationString, 0, REG_DWORD, &Data, sizeof(Data));

		Data = 0;
		RtlInitUnicodeString(&DestinationString, L"InitState");
		ZwSetValueKey(handle_v1, &DestinationString, 0, REG_DWORD, &Data, sizeof(Data));

		Data = 0;
		RtlInitUnicodeString(&DestinationString, L"serHookType");
		ZwSetValueKey(handle_v1, &DestinationString, 0, REG_DWORD, &Data, sizeof(Data));

		Data = 0;
		RtlInitUnicodeString(&DestinationString, L"OsVer");
		ZwSetValueKey(handle_v1, &DestinationString, 0, REG_DWORD, &Data, sizeof(Data));

		Data = 0;
		RtlInitUnicodeString(&DestinationString, L"HookErrorIndex");
		ZwSetValueKey(handle_v1, &DestinationString, 0, REG_DWORD, &Data, sizeof(Data));

		Data = 0;
		RtlInitUnicodeString(&DestinationString, L"IsBsod");
		result = ZwSetValueKey(handle_v1, &DestinationString, 0, REG_DWORD, &Data, sizeof(Data));
	}
	return result;
}

PVOID xx_GetSysInfo_106C0()
{
	PVOID result = NULL;
	ULONG SystemInformation = 0 ;

	ZwQuerySystemInformation(SystemModuleInformation, &SystemInformation, 0, &SystemInformation);
	result = ExAllocatePoolWithTag(PagedPool, SystemInformation, ' kdD');
	if ( result )
	{
		if ( ZwQuerySystemInformation(SystemModuleInformation, result, SystemInformation, 0) != STATUS_SUCCESS)
		{
			ExFreePool(result);
			result = NULL;	
		}
	}
	return result;
}

PIMAGE_NT_HEADERS __fastcall xx_GetNtHeader_115E0(int a1, PIMAGE_DOS_HEADER pBase_a2)
{
	PIMAGE_NT_HEADERS result = NULL;
	PIMAGE_NT_HEADERS pBase_v3 = NULL;

	if ( pBase_a2 )
	{
		if ( pBase_a2 != (PIMAGE_DOS_HEADER)-1 )
		{
			pBase_v3 = (PIMAGE_NT_HEADERS)((char*)pBase_a2 + pBase_a2->e_lfanew);
			if ( ((ULONG_PTR)pBase_a2 >= (ULONG_PTR)MmHighestUserAddress
				|| (ULONG_PTR)pBase_v3 < (ULONG_PTR)MmHighestUserAddress 
				&& (ULONG_PTR)((char*)pBase_v3 + sizeof(IMAGE_NT_HEADERS)) < (ULONG_PTR)MmHighestUserAddress)
				&& *(DWORD *)pBase_v3 == 0x4550 )// 判断pe标志

				result = (PIMAGE_NT_HEADERS)((char*)pBase_a2 + pBase_a2->e_lfanew);
		}
	}
	return result;
}

PVOID xx_GetProAddress_11630(int a1, ULONG_PTR pBase_a2, char *strFuncName_a3)
{
	PIMAGE_NT_HEADERS pNtHeader_v3 = NULL;
	USHORT Magic_v4 = 0;
	PIMAGE_EXPORT_DIRECTORY pExportDirectoryVirtualAddress_v5 = 0;
	ULONG uExportDirectoryVirtualAddress_v6 = 0;
	ULONG uExportDirectorySize_v7 = 0;
	ULONG Index_v8 = 0;
	PULONG pAddressOfNames_v9 = 0;
	PULONG pAddressOfFunctions = 0;
	const char *pFuncNameAddr_v10 = 0;
	PVOID result = 0;
	ULONG uExportDirectorySize_v12 = 0;
	PUSHORT pAddressOfNameOrdinals_v13 = 0;

	pNtHeader_v3 = xx_GetNtHeader_115E0(a1, (PIMAGE_DOS_HEADER)pBase_a2);
	if ( !pNtHeader_v3 )
		return 0;

	do 
	{
		Magic_v4 = pNtHeader_v3->OptionalHeader.Magic;
		if ( Magic_v4 == IMAGE_NT_OPTIONAL_HDR32_MAGIC )                      // 32位程序0x010B
		{
			if ( pNtHeader_v3->OptionalHeader.NumberOfRvaAndSizes <= 0u )
			{
				pExportDirectoryVirtualAddress_v5 = 0;
				break;
			}

			uExportDirectoryVirtualAddress_v6 = pNtHeader_v3->OptionalHeader.DataDirectory[0].VirtualAddress;
			if ( !uExportDirectoryVirtualAddress_v6 )
			{
				pExportDirectoryVirtualAddress_v5 = 0;
				break;
			}
			if ( (pBase_a2 < (unsigned int)MmHighestUserAddress) && (uExportDirectoryVirtualAddress_v6 + pBase_a2 >= (unsigned int)MmHighestUserAddress) )
			{
				pExportDirectoryVirtualAddress_v5 = 0;
				break;
			}
			uExportDirectorySize_v7 = pNtHeader_v3->OptionalHeader.DataDirectory[0].Size;
		}
		else
		{
			if ( Magic_v4 != IMAGE_NT_OPTIONAL_HDR64_MAGIC )                    // 64位程序
				return 0;

			if ( pNtHeader_v3->OptionalHeader.NumberOfRvaAndSizes <= 0u )
			{
				pExportDirectoryVirtualAddress_v5 = 0;
				break;
			}
			uExportDirectoryVirtualAddress_v6 = pNtHeader_v3->OptionalHeader.DataDirectory[0].VirtualAddress;
			if ( !uExportDirectoryVirtualAddress_v6 )
			{
				pExportDirectoryVirtualAddress_v5 = 0;
				break;
			}
			if ( pBase_a2 < (unsigned int)MmHighestUserAddress && uExportDirectoryVirtualAddress_v6 + pBase_a2 >= (unsigned int)MmHighestUserAddress )
			{
				pExportDirectoryVirtualAddress_v5 = 0;
				break;
			}
			uExportDirectorySize_v7 = pNtHeader_v3->OptionalHeader.DataDirectory[0].Size;
		}
		pExportDirectoryVirtualAddress_v5 = (PIMAGE_EXPORT_DIRECTORY)((PCHAR)pBase_a2 + uExportDirectoryVirtualAddress_v6);
		uExportDirectorySize_v12 = uExportDirectorySize_v7;

	} while (FALSE);

	if ( !pExportDirectoryVirtualAddress_v5 )
		return 0;

	Index_v8 = 0;
	pAddressOfFunctions = (PULONG)((PCHAR)pBase_a2 + pExportDirectoryVirtualAddress_v5->AddressOfFunctions);
	pAddressOfNames_v9 = (PULONG)((PCHAR)pBase_a2 + pExportDirectoryVirtualAddress_v5->AddressOfNames);//v9 = pBase_a2 + *(DWORD *)(pExportDirectoryVirtualAddress_v5 + 0x20);
	pAddressOfNameOrdinals_v13 = (PUSHORT)((PCHAR)pBase_a2 + pExportDirectoryVirtualAddress_v5->AddressOfNameOrdinals);//v13 = pBase_a2 + *(DWORD *)(pExportDirectoryVirtualAddress_v5 + 0x24);
	if ( pExportDirectoryVirtualAddress_v5->NumberOfNames )
	{
		while ( TRUE )
		{
			pFuncNameAddr_v10 = (const char *)((PCHAR)pBase_a2 + pAddressOfNames_v9[Index_v8]);
			if ( *strFuncName_a3 == *pFuncNameAddr_v10 && !_stricmp(strFuncName_a3, pFuncNameAddr_v10) )
				break;

			++Index_v8;

			if ( Index_v8 >= pExportDirectoryVirtualAddress_v5->NumberOfNames )
			{
				return 0;
			}
		}

		result = (PVOID)((PCHAR)pBase_a2 + pAddressOfFunctions[pAddressOfNameOrdinals_v13[Index_v8]]);
		if ( result > pExportDirectoryVirtualAddress_v5 && result < pExportDirectoryVirtualAddress_v5 + uExportDirectorySize_v12 )
		{
			result = 0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

ULONG xx_GetProcessIdByProcessName_10B40(const WCHAR *wstr_a1)
{
	ULONG nBufferLen_v1 = 512;
	PVOID pBuffer_v3 = NULL; 
	NTSTATUS status_v4 = STATUS_UNSUCCESSFUL; 
	PSYSTEM_PROCESS_INFORMATION pSysProcInfo_v5 = NULL;
	ULONG pid_v7 = 0; 
	UNICODE_STRING DestinationString = {0};

	RtlInitUnicodeString(&DestinationString, wstr_a1);
	while ( TRUE )
	{
		pBuffer_v3 = ExAllocatePoolWithTag(PagedPool, nBufferLen_v1, ' kdD');
		if ( !pBuffer_v3 )
			return 0;

		status_v4 = ZwQuerySystemInformation(SystemProcessesAndThreadsInformation, pBuffer_v3, nBufferLen_v1, 0);
		if ( status_v4 != STATUS_INFO_LENGTH_MISMATCH)
			break;

		ExFreePool(pBuffer_v3);
		nBufferLen_v1 *= 2;
	}

	if ( status_v4 < 0 )
		ExFreePool(pBuffer_v3);

	pSysProcInfo_v5 = (PSYSTEM_PROCESS_INFORMATION)pBuffer_v3;
	while ( pSysProcInfo_v5->NextEntryDelta )
	{
		pSysProcInfo_v5 = (PSYSTEM_PROCESS_INFORMATION)((char *)pSysProcInfo_v5 + pSysProcInfo_v5->NextEntryDelta);
		if ( RtlEqualUnicodeString(&DestinationString, (PCUNICODE_STRING)pSysProcInfo_v5->ProcessName.Buffer, TRUE) == TRUE )// 对比进程名
			pid_v7 = pSysProcInfo_v5->ProcessId;
	}

	ExFreePool(pBuffer_v3);
	return pid_v7;
}

BOOLEAN __stdcall xx_GetSysModuleInfo_10720(char *pNeedModuleName_a1, PSYSTEM_MODULE_INFORMATION_ENTRY pSysModuleInfo_a2)
{
	PSYSTEM_MODULE_INFORMATION pSysModuleInfo_v2 = NULL; 
	ULONG Index_v4 = 0;
	BOOLEAN isSuccess_v8 = FALSE;

	pSysModuleInfo_v2 = (PSYSTEM_MODULE_INFORMATION)xx_GetSysInfo_106C0();
	if ( pSysModuleInfo_v2 )
	{
		Index_v4 = 0;
		if ( pSysModuleInfo_v2->Count )
		{
			while (0 != _stricmp((const char *)&pSysModuleInfo_v2->Module[Index_v4].ImageName[pSysModuleInfo_v2->Module[Index_v4].ModuleNameOffset], pNeedModuleName_a1) )
			{
				++Index_v4;
				if ( Index_v4 >= pSysModuleInfo_v2->Count )
				{
					ExFreePool(pSysModuleInfo_v2);
					return 0;
				}
			}
			memcpy(pSysModuleInfo_a2, (char *)&pSysModuleInfo_v2->Module[Index_v4], sizeof(SYSTEM_MODULE_INFORMATION_ENTRY));
			isSuccess_v8 = TRUE;
		}
		ExFreePool(pSysModuleInfo_v2);
	}
	return isSuccess_v8;
}

NTSTATUS xx_GetShadowSsdtByKeAddSystemServiceTable_207D0()
{
	int v0 = 0; 
	PVOID KeAddSystemServiceTable_v2 = NULL; 
	PMDL pMdl_v3 = NULL;
	PVOID KeAddSystemServiceTableStart_v4 = NULL;
	ULONG KeAddSystemServiceTableEnd_v5 = 0;
	PSERVICE_DESCRIPTOR_TABLE pServiceDescriptorTable = 0;
	PVOID KeAddSystemServiceTable_v7 = NULL;
	PVOID KeAddSystemServiceTable_v9 = NULL;
	ULONG Version_v12 = 0;
	ULONG isLock_v13 = 0;
	NTSTATUS status_v15 = STATUS_UNSUCCESSFUL;
	PVOID W32pServiceTable_v16 = NULL;

	Version_v12 = xx_GetVersion_113C0();
	KeAddSystemServiceTable_v2 = xx_GetProAddress_11630(v0, (ULONG)g_NtBase_dword_281C0, "KeAddSystemServiceTable");
	if ( KeAddSystemServiceTable_v2 )
	{
		if ( !MmIsAddressValid((PVOID)KeAddSystemServiceTable_v2) )
		{
			pMdl_v3 = MmCreateMdl(0, KeAddSystemServiceTable_v2, 0x1000u);
			if ( pMdl_v3 )
			{
				MmProbeAndLockPages(pMdl_v3, 0, (LOCK_OPERATION)0);
				isLock_v13 = 1;
			}
		}
	}

	if ( !KeAddSystemServiceTable_v2 || !MmIsAddressValid(KeAddSystemServiceTable_v2) )
	{
		g_SsdtType_dword_281DC |= 4u;
		goto _END;
	}

	KeAddSystemServiceTableStart_v4 = KeAddSystemServiceTable_v2;
	KeAddSystemServiceTableEnd_v5 = (int)((char *)KeAddSystemServiceTable_v2 + 0x100);

	if ( (char *)KeAddSystemServiceTable_v2 < (char *)KeAddSystemServiceTable_v2 + 0x100 )
	{
		do
		{
			if ( MmIsAddressValid(KeAddSystemServiceTableStart_v4) && *(WORD *)KeAddSystemServiceTableStart_v4 == 0x888Du )
			{
				pServiceDescriptorTable = (PSERVICE_DESCRIPTOR_TABLE)(*(ULONG_PTR *)((char *)KeAddSystemServiceTableStart_v4 + 2));
				g_W32pServiceTable_dword_28194 = (PULONG)pServiceDescriptorTable->Win32k.ServiceTableBase;
				g_W32pServiceLimit_dword_28198 = pServiceDescriptorTable->Win32k.ServiceCount;
				W32pServiceTable_v16 = g_W32pServiceTable_dword_28194;
				status_v15 = STATUS_SUCCESS;
			}
			KeAddSystemServiceTableStart_v4 = (char *)KeAddSystemServiceTableStart_v4 + 1;
		}
		while ( (unsigned int)KeAddSystemServiceTableStart_v4 < KeAddSystemServiceTableEnd_v5 );
	}

	if ( Version_v12 == 9 || Version_v12 == 10 || Version_v12 == 14 || Version_v12 == 15 )
	{
		KeAddSystemServiceTable_v9 = KeAddSystemServiceTable_v2;
		if ( (unsigned int)KeAddSystemServiceTable_v2 >= KeAddSystemServiceTableEnd_v5 )
		{
			goto LABEL_33;
		}

		while ( !MmIsAddressValid(KeAddSystemServiceTable_v9)
			|| *(WORD *)KeAddSystemServiceTable_v9 != 0xB983u
			|| (DWORD)g_KeServiceDescriptorTable_dword_281BC == *(DWORD *)((char *)KeAddSystemServiceTable_v9 + 2) )
		{
			KeAddSystemServiceTable_v9 = (char *)KeAddSystemServiceTable_v9 + 1;
			if ( (unsigned int)KeAddSystemServiceTable_v9 >= KeAddSystemServiceTableEnd_v5 )
			{
				goto LABEL_33;
			}
		}

		pServiceDescriptorTable = (PSERVICE_DESCRIPTOR_TABLE)(*(ULONG_PTR *)((char *)KeAddSystemServiceTable_v9 + 2));
		g_W32pServiceTable_dword_28194 = (PULONG)pServiceDescriptorTable->Win32k.ServiceTableBase;
		g_W32pServiceLimit_dword_28198 = pServiceDescriptorTable->Win32k.ServiceCount;
		W32pServiceTable_v16 = g_W32pServiceTable_dword_28194;
		status_v15 = STATUS_SUCCESS;
	}

	if ( Version_v12 == 16 || Version_v12 == 17 )
	{
		KeAddSystemServiceTable_v7 = KeAddSystemServiceTable_v2;
		if ( (unsigned int)KeAddSystemServiceTable_v2 < KeAddSystemServiceTableEnd_v5 )
		{
			while ( !MmIsAddressValid(KeAddSystemServiceTable_v7)
				|| *(WORD *)KeAddSystemServiceTable_v7 != 0x3D83
				|| (DWORD)g_KeServiceDescriptorTable_dword_281BC == *(DWORD *)((char *)KeAddSystemServiceTable_v7 + 2) - 16 )
			{
				KeAddSystemServiceTable_v7 = (char *)KeAddSystemServiceTable_v7 + 1;
				if ( (unsigned int)KeAddSystemServiceTable_v7 >= KeAddSystemServiceTableEnd_v5 )
				{
					goto LABEL_33;
				}
			}
			pServiceDescriptorTable = (PSERVICE_DESCRIPTOR_TABLE)(*(DWORD *)((char *)KeAddSystemServiceTable_v7 + 2) - 16);
			g_W32pServiceTable_dword_28194 = (PULONG)pServiceDescriptorTable->Win32k.ServiceTableBase;
			g_W32pServiceLimit_dword_28198 = pServiceDescriptorTable->Win32k.ServiceCount;
			W32pServiceTable_v16 = g_W32pServiceTable_dword_28194;
			status_v15 = STATUS_SUCCESS;
		}
	}

LABEL_33:
	if ( !W32pServiceTable_v16 )
	{
		g_SsdtType_dword_281DC |= 8u;
	}

_END:
	if ( isLock_v13 )
	{
		MmUnlockPages(pMdl_v3);
	}
	if ( pMdl_v3 )
	{
		IoFreeMdl(pMdl_v3);
	}
	return status_v15;
}


#pragma pack(2)
typedef struct _IDTR{
	USHORT numberofidt;
	ULONG highaddress;
}IDTR ,*PIDTR;
#pragma pack()

PVOID xx_GetKiSystemServiceAddress_10830()
{
	PVOID pAddr_v0 = NULL;
	PVOID result = NULL;
	IDTR idt = {0};

	__asm sidt idt

	if ( idt.highaddress )
	{
		pAddr_v0 = (PVOID)(idt.highaddress + 368);
		if ( MmIsAddressValid((PVOID)(pAddr_v0)))
		{
			result = (PVOID)(*(WORD *)pAddr_v0 | (*(WORD *)((PCHAR)pAddr_v0 + 6) << 16));
		}
		else
		{
			result = 0;
		}
	}
	return result;
}

ULONG xx_GetHookPointAddress_20750()
{
	int Index_v1 = 1024; 
	ULONG result; 
	PUCHAR pKiSystemServiceAddress_v0; 

	if ( g_MmUserProbeAddress_dword_28188 )
	{
		pKiSystemServiceAddress_v0 = (PUCHAR)xx_GetKiSystemServiceAddress_10830();
		if ( pKiSystemServiceAddress_v0 < (PUCHAR)g_NtBase_dword_281C0
			|| pKiSystemServiceAddress_v0 > (PUCHAR)g_NtBase_dword_281C0 + g_NtSize_dword_281C4 )
		{
			result = 0;
		}
		else
		{
			while ( TRUE )
			{
				++pKiSystemServiceAddress_v0;
				--Index_v1;
				if ( RtlCompareMemory((const void *)pKiSystemServiceAddress_v0, &g_FindHookCode_unk_25B18, 10) == 10 )
					break;
				if ( !Index_v1 )
					return 0;
			}
			result = (ULONG)pKiSystemServiceAddress_v0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

ULONG xx_GetHookPointAddress_206D0()
{
	int Index_v1 = 0x400;
	PUCHAR KiSystemServiceAddress_v0; 
	ULONG result; 

	if ( g_MmUserProbeAddress_dword_28188 )
	{
		KiSystemServiceAddress_v0 = (PUCHAR)xx_GetKiSystemServiceAddress_10830();
		if ( KiSystemServiceAddress_v0 < (PUCHAR)g_NtBase_dword_281C0
			|| KiSystemServiceAddress_v0 > (PUCHAR)g_NtBase_dword_281C0 + g_NtSize_dword_281C4 )
		{
			result = 0;
		}
		else
		{
			while ( TRUE )
			{
				++KiSystemServiceAddress_v0;
				--Index_v1;
				if ( RtlCompareMemory((const void *)KiSystemServiceAddress_v0, &g_FindCode_unk_25B24, 22) == 22 )
					break;
				if ( !Index_v1 )
					return 0;
			}
			result = (ULONG)KiSystemServiceAddress_v0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

NTSTATUS xx_InitKiSystemServiceHookAddress_20B00()
{
	NTSTATUS status_v0 = STATUS_UNSUCCESSFUL; 
	BOOLEAN isSet_v1 = FALSE;
	PSYSTEM_MODULE_INFORMATION pSysInfo_v2 = NULL;
	int v3 = 0; 
	PSERVICES_DESCRIPTOR_TABLE KeServiceDescriptorTable_v4 = 0;
	int SsdtCount_v6 = 0; 
	PVOID MmUserProbeAddress_v7 = NULL;
	unsigned int pKiSystemServiceHookAddress_v8 = 0;
	unsigned int pFindCodeHookAddress_v9 = 0;
	unsigned int result = 0;
	int pData_v10 = 0;
	UNICODE_STRING DestinationString = {0};
	SYSTEM_MODULE_INFORMATION_ENTRY pSysModuleInfo_v13 = {0};
	volatile LONG *v15 = NULL; 
	int v16 = 0; 
	SYSTEM_MODULE_INFORMATION_ENTRY pSysInfo_v17 = {0};

	g_HookLen8_dword_281E0 = 0;
	g_SsdtType_dword_281DC = 0;
	g_FilterFlag_dword_281D4 = 0;

	//char v14[0x118u] = {0};
	//memset(&v14, 0, sizeof(v14));

	g_SystemVersion_dword_281E8 = xx_GetVersion_113C0();
	xx_InitTsFltMgr_209E0();

	if ( (xx_QueryValueKey_10E70(
								L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Services\\TsFltMgr", 
								L"thm",
								&pData_v10,
								sizeof(pData_v10),
								0) & 0x80000000) == 0)
	{
		if (pData_v10 == 1 )
		{
			isSet_v1 = TRUE;
		}
	}

	g_IsSetThm_byte_2A390 = isSet_v1;
	if ( isSet_v1 )
	{
		g_HookKiSystemFastCallFlag_dword_281E4 = 2;
	}

	pSysInfo_v2 = (PSYSTEM_MODULE_INFORMATION)xx_GetSysInfo_106C0();
	if ( pSysInfo_v2 )
	{
		memcpy(&pSysInfo_v17, &pSysInfo_v2->Module[0], sizeof(SYSTEM_MODULE_INFORMATION_ENTRY));
		ExFreePool(pSysInfo_v2);

		g_HookLen8_dword_281E0 |= 1u;
		g_NtBase_dword_281C0 = pSysInfo_v17.Base;
		g_NtSize_dword_281C4 = pSysInfo_v17.Size;

		KeServiceDescriptorTable_v4 = (PSERVICES_DESCRIPTOR_TABLE)xx_GetProAddress_11630(v3, (ULONG_PTR)g_NtBase_dword_281C0, "KeServiceDescriptorTable");
		if ( KeServiceDescriptorTable_v4 && MmIsAddressValid((PVOID)KeServiceDescriptorTable_v4) )
		{
			g_KeServiceDescriptorTable_dword_281BC = (PSERVICES_DESCRIPTOR_TABLE)KeServiceDescriptorTable_v4;
			g_SsdtTableBase = (PULONG)KeServiceDescriptorTable_v4->ServiceTableBase;
			SsdtCount_v6 = KeServiceDescriptorTable_v4->ServiceCount;

			g_HookLen8_dword_281E0 |= 2u;
			g_SsdtCount_dword_28190 = SsdtCount_v6;

			g_CsrssPid_dword_281D0 = (HANDLE)xx_GetProcessIdByProcessName_10B40(L"csrss.exe");
			if ( xx_GetSysModuleInfo_10720("WIN32K.SYS", &pSysModuleInfo_v13) == TRUE )
			{
				g_Target = (PVOID)v15;
				g_Win32kSize_dword_281CC = v16;
				status_v0 = xx_GetShadowSsdtByKeAddSystemServiceTable_207D0();
				if ( (status_v0 & 0x80000000) == 0 )
				{
					g_HookLen8_dword_281E0 |= 4u;
				}
			}

			RtlInitUnicodeString(&DestinationString, L"MmUserProbeAddress");
			MmUserProbeAddress_v7 = MmGetSystemRoutineAddress(&DestinationString);
			g_MmUserProbeAddress_dword_28188 = (ULONG)MmUserProbeAddress_v7;
			if ( MmUserProbeAddress_v7 && MmIsAddressValid(MmUserProbeAddress_v7) )
			{
				pKiSystemServiceHookAddress_v8 = xx_GetHookPointAddress_20750();
				g_KiSystemServiceHookAddress_dword_2819C = (PVOID)pKiSystemServiceHookAddress_v8;
				if ( pKiSystemServiceHookAddress_v8 )
				{
					pFindCodeHookAddress_v9 = (ULONG)g_FindCodeHookAddress_dword_2A380;
				}
				else
				{
					pFindCodeHookAddress_v9 = xx_GetHookPointAddress_206D0();
					pKiSystemServiceHookAddress_v8 = (ULONG)g_KiSystemServiceHookAddress_dword_2819C;
					g_FindCodeHookAddress_dword_2A380 = (PVOID)pFindCodeHookAddress_v9;
					if ( !g_KiSystemServiceHookAddress_dword_2819C && !pFindCodeHookAddress_v9 )
					{
						g_SsdtType_dword_281DC |= 0x20u;
						return status_v0;
					}
				}                                       // 
				// nt!KiFastCallEntry+0xe6:
				// 8053e626 8bfc            mov     edi,esp   //1
				// 8053e628 3b35d4995580    cmp     esi,dword ptr [nt!MmUserProbeAddress (805599d4)]  //2.这里是hook点
				// 8053e62e 0f83a8010000    jae     nt!KiSystemCallExit2+0x9f (8053e7dc) //这里是返回地址
				// 8053e634 f3a5            rep movs dword ptr es:[edi],dword ptr [esi]
				// 8053e636 ffd3            call    ebx
				// 8053e638 8be5            mov     esp,ebp
				// 8053e63a 8b0d24f1dfff    mov     ecx,dword ptr ds:[0FFDFF124h]
				// 8053e640 8b553c          mov     edx,dword ptr [ebp+3Ch]
				// 
				g_HookLen8_dword_281E0 |= 8u;
				g_HookLen6_dword_2A384 = (ULONG)(int (__fastcall *)(DWORD, DWORD))((PCHAR)pFindCodeHookAddress_v9 + 6);
				g_JmpBackAddress_dword_281A0 = (int (__fastcall *)(DWORD, DWORD))((PCHAR)pKiSystemServiceHookAddress_v8 + 8);
				g_MmUserProbeAddress_dword_28188 = *(DWORD *)g_MmUserProbeAddress_dword_28188;// 7fff0000 xp下是这个数值，Useraddress
				result = 0;
			}
			else
			{
				g_SsdtType_dword_281DC |= 0x10u;
				result = status_v0;
			}
		}
		else
		{
			g_SsdtType_dword_281DC |= 2u;
			result = STATUS_UNSUCCESSFUL;
		}
	}
	else
	{
		g_SsdtType_dword_281DC |= 1u;
		result = STATUS_UNSUCCESSFUL;
	}
	return result;
}

ULONG xx_GetSsdtFunctionIndex_107C0(char *strFuncName_a1)
{
	ULONG Index_v1 = -1;
	int v2 = 0;
	PVOID pfnFuncAddress_v3;
	__int64 v4;
	SYSTEM_MODULE_INFORMATION_ENTRY SystemModuleInfo_v6 = {0};
	ULONG ntBase_v8 = (ULONG)g_NtBase_dword_281C0; 

	if ( xx_GetSysModuleInfo_10720("ntdll.dll", &SystemModuleInfo_v6) == TRUE )
	{
		Index_v1 = -1;
		if ( ntBase_v8 )
		{
			if ( strFuncName_a1 )
			{
				pfnFuncAddress_v3 = xx_GetProAddress_11630(v2, ntBase_v8, strFuncName_a1);
				if ( pfnFuncAddress_v3 )
				{
					//LODWORD(v4) = *(DWORD *)pfnFuncAddress_v3;
					//BYTE4(v4) = *(BYTE *)(pfnFuncAddress_v3 + 4);
					v4 = (__int64)pfnFuncAddress_v3;
					Index_v1 = *(DWORD *)((char *)v4 + 1);// 获取Nt函数index
				}
			}
		}
	}
	return Index_v1;
}

BOOLEAN xx_InitGlobalFunctionValue_20420()
{
	TsFlt_OS_VERSION Version_v0; // ebp@1
	PTsFlt_FUNCTION_LIST pArrayIndex_v4; // eax@3
	ULONG v6 = 0; // ecx@8
	PVOID pfnZwCreateKey_v7; // eax@10
	ULONG v8; // edx@11
	char v9; // al@11
	ULONG Type_v10; // eax@12
	ULONG NtBase_v12; // edi@19
	char *pFuncOffset_v13; // ebp@20
	ULONG Type_v14; // eax@22
	ULONG v15 = 0; // ecx@26
	ULONG pfnFuncAddress_v16; // esi@27
	ULONG nFuncOffset_v17; // esi@28
	STRING AnsiString; // [sp+10h] [bp-134h]@11
	LSA_UNICODE_STRING DestinationString; // [sp+18h] [bp-12Ch]@15
	SYSTEM_MODULE_INFORMATION_ENTRY pNtdllInfo_v20 = {0}; // [sp+20h] [bp-124h]@8
	char v21; // [sp+24h] [bp-120h]@8
	ULONG ntBase_v22; // [sp+28h] [bp-11Ch]@9
	ULONG Index_v1 = 0;
	ULONG Index_v3 = 0;

	Version_v0 = xx_GetVersion_113C0();
	if ( Version_v0 )
	{
		for (int n = 0; n < arraysize(g_FunctionArray_25B4C); n++)
		{
			pArrayIndex_v4 = &g_FunctionArray_25B4C[n];
			for (int i = 0; i < OS_Max; i++)
			{
				if (!pArrayIndex_v4->Index[i])
				{
					pArrayIndex_v4->Index[i] = 0x3FF;
				}
			}
		}

		memset(&v21, 0, 0x118u);
		if ( xx_GetSysModuleInfo_10720("ntdll.dll", &pNtdllInfo_v20) == TRUE)
		{
			ntBase_v22 = (ULONG)pNtdllInfo_v20.Base;
			if (ntBase_v22)
			{
				pfnZwCreateKey_v7 = xx_GetProAddress_11630(v6, ntBase_v22, "ZwCreateKey");
				v8 = *(DWORD *)pfnZwCreateKey_v7;
				v9 = *(BYTE *)((PCHAR)pfnZwCreateKey_v7 + 4);
				*(DWORD *)&AnsiString.Length = v8;
				//LOBYTE(AnsiString.Buffer) = v9;
				if (*(DWORD *)((char *)&AnsiString.Length + 1) != -1)
				{
					while ( TRUE )
					{
						Type_v10 = g_FunctionArray_25B4C[Index_v1].Type;
						if ( Type_v10 == 2 )
							break;

						if ( !Type_v10 && g_FunctionArray_25B4C[Index_v1].FuncName )
						{
							RtlInitUnicodeString(&DestinationString, g_FunctionArray_25B4C[Index_v1].FuncName);
							if ( RtlUnicodeStringToAnsiString(&AnsiString, &DestinationString, TRUE) >= 0 )
							{
								xx_GetSsdtFunctionIndex_107C0(AnsiString.Buffer);
								RtlFreeAnsiString(&AnsiString);
							}
						}
						Index_v3 += 1;
						if ( Index_v3 >= arraysize(g_FunctionArray_25B4C) )
							return TRUE;
					}
				}
			}
		}
		else
		{
			NtBase_v12 = (ULONG)g_NtBase_dword_281C0;
			if ( g_NtBase_dword_281C0 )
			{
				while ( TRUE )
				{
					pFuncOffset_v13 = (char *)&g_FunctionArray_25B4C[Index_v1].Index[Version_v0];
					Type_v14 = g_FunctionArray_25B4C[Index_v1].Type;
					if ( Type_v14 == 2 )
						break;

					if ( !Type_v14 )
					{
						if ( g_FunctionArray_25B4C[Index_v1].FuncName )
						{
							if ( NtBase_v12 )
							{
								RtlInitUnicodeString(&DestinationString, g_FunctionArray_25B4C[Index_v1].FuncName);
								if ( RtlUnicodeStringToAnsiString(&AnsiString, &DestinationString, TRUE) >= 0 )
								{
									pfnFuncAddress_v16 = (ULONG)xx_GetProAddress_11630(v15, NtBase_v12, AnsiString.Buffer);
									RtlFreeAnsiString(&AnsiString);
									if ( pfnFuncAddress_v16 )
									{
										nFuncOffset_v17 = *(DWORD *)(pfnFuncAddress_v16 + 1);
										if ( *(DWORD *)pFuncOffset_v13 != nFuncOffset_v17 && *(DWORD *)pFuncOffset_v13 != 0x3FF )
										{
											*(DWORD *)pFuncOffset_v13 = nFuncOffset_v17;
										}
									}
								}
							}
						}
					}
					Index_v1 += 1;
					if ( Index_v1 >= arraysize(g_FunctionArray_25B4C) )
						break;
				}
			}
		}
	}
	return TRUE;
}

// 将函数加入到全局函数列表中，返回申请的结构
PTsFlt_FILTER xx_InsertFuncIntoList_211D0(PWCHAR strName_a1, ULONG Index_a2, PVOID NewFuncAddress_a3)
{
	PTsFlt_FILTER pResult = NULL;

	if ( strName_a1 && NewFuncAddress_a3 && Index_a2 < arraysize(g_FunctionArray_25B4C) )
	{
		pResult = (PTsFlt_FILTER)ExAllocatePoolWithTag(NonPagedPool, 0x4F8u, 'THOP');
		if ( pResult )
		{
			memset(pResult, 0, 0x4F8u);
			pResult->FuncIndex = -1;					//*(DWORD *)(pResult + 0x04) = -1;
			pResult->FuncName = strName_a1;				//*(DWORD *)(pResult + 0x08) = strName_a1; // FuncName
			pResult->CurTsFltIndex = Index_a2;			//*(DWORD *)(pResult + 0x0C) = Index_a2; // Index
			pResult->IsHook = FALSE;					//*(DWORD *)(pResult + 0x10) = 0;
			pResult->ProxyFunc = NewFuncAddress_a3;		//*(DWORD *)(pResult + 0x24) = NewFuncAddress_a3;// NewFunAddress
			pResult->Flag1 = 1;							//*(DWORD *)(pResult + 0x40) = 1;
			pResult->Flag2 = 1;							//*(DWORD *)(pResult + 0x48) = 0;
			KeInitializeEvent((PRKEVENT)&(pResult->Kevent), SynchronizationEvent, 0);
			g_FuncFilterInfo_dword_281F0[Index_a2] = pResult;
		}
	}
	return pResult;
}

//返回失败的个数
ULONG xx_InitFunctionFilter_20600()
{
	int Type_v5 = 0;
	int nCount_v7 = 0;
	int result = 0;
	char *pFuncIndex_v3 = NULL; 
	ULONG index_v0 = 0;
	ULONG nFuncIndex_v6 = 0;
	PTsFlt_FILTER pFilterFunInfo_v4 = NULL;
	TsFlt_OS_VERSION Version_v1 = OS_UnKnow;
	
	Version_v1 = xx_GetVersion_113C0();
	if ( Version_v1 && xx_InitGlobalFunctionValue_20420() )
	{
		while ( g_FunctionArray_25B4C[index_v0].Type != 2 )
		{
			pFuncIndex_v3 = (char *)&g_FunctionArray_25B4C[index_v0].Index[Version_v1];
			if ( (unsigned int)(Version_v1 - 0xF) > 2 || *(DWORD *)pFuncIndex_v3 != 0x3FF )
			{
				pFilterFunInfo_v4 = (PTsFlt_FILTER)xx_InsertFuncIntoList_211D0(g_FunctionArray_25B4C[index_v0].FuncName, g_FunctionArray_25B4C[index_v0].Number, g_FunctionArray_25B4C[index_v0].FuncAddress);
				if ( pFilterFunInfo_v4 )
				{
					Type_v5 = g_FunctionArray_25B4C[index_v0].Type;
					nFuncIndex_v6 = *(DWORD *)pFuncIndex_v3;
					if ( (unsigned int)Type_v5 >= 2 || nFuncIndex_v6 == -1 || nFuncIndex_v6 >= 0x400 )
					{
						++nCount_v7;
					}
					else
					{
						g_SsdtFilterInfo_dword_28380[nFuncIndex_v6 + (Type_v5 << 10)] = pFilterFunInfo_v4;
						pFilterFunInfo_v4->Type = Type_v5;
						pFilterFunInfo_v4->FuncIndex = nFuncIndex_v6;
					}
				}
			}
			index_v0 += 1;
			if ( index_v0 >= arraysize(g_FunctionArray_25B4C) )
				break;
		}
		result = nCount_v7;
	}
	else
	{
		result = arraysize(g_FunctionArray_25B4C);
	}
	return result;
}

PMDL xx_LockMemory_10A50(PVOID VirtualAddress, ULONG Length, PVOID* ppRetAddress_a3)
{
	PMDL Mdl_v3;
	PVOID LockAddress_v5;

	Mdl_v3 = IoAllocateMdl(VirtualAddress, Length, 0, 1u, 0);
	if ( Mdl_v3 )
	{
		MmProbeAndLockPages(Mdl_v3, 0, IoWriteAccess);
		if ( Mdl_v3 )
		{
			if ( Mdl_v3->MdlFlags & 5 )
			{
				LockAddress_v5 = Mdl_v3->MappedSystemVa;
			}
			else
			{
				LockAddress_v5 = MmMapLockedPagesSpecifyCache(Mdl_v3, 0, MmCached, 0, 0, NormalPagePriority);
			}
			if ( !LockAddress_v5 )
			{
				MmUnlockPages(Mdl_v3);
				IoFreeMdl(Mdl_v3);
				Mdl_v3 = 0;
			}
			if ( ppRetAddress_a3 )
			{
				*ppRetAddress_a3 = LockAddress_v5;
			}
		}
	}
	return Mdl_v3;
}

void xx_UnLockMemory_10B20(PMDL pMdl_a1)
{
	if ( pMdl_a1 )
	{
		MmUnlockPages(pMdl_a1);
		IoFreeMdl(pMdl_a1);
	}
}


void __stdcall DeferredRoutine(struct _KDPC *Dpc, PVOID DeferredContext, PVOID SystemArgument1, PVOID SystemArgument2)
{
	KIRQL OldIrql; // bl@1
	PTsFlt_DPC pTsFltDpcInfo = (PTsFlt_DPC)DeferredContext;

	_disable();
	OldIrql = KfRaiseIrql(DISPATCH_LEVEL);
	InterlockedIncrement((LONG *)*pTsFltDpcInfo->pFlag);
	KefAcquireSpinLockAtDpcLevel(pTsFltDpcInfo->pSpinLock);
	KefReleaseSpinLockFromDpcLevel(pTsFltDpcInfo->pSpinLock);
	KfLowerIrql(OldIrql);
	_enable();
}

NTSTATUS __stdcall xx_Hook_108C0(PTsFlt_HOOK_INFO pHookInfo_a1, NTSTATUS (__stdcall *hook_a2)(PTsFlt_HOOK_INFO))
{
	int nCurCpu_v2;
	NTSTATUS status;
	int NumberOfCpu_v4;
	int i_v6; 
	KIRQL oldIrql_v7;
	PKDPC pDpc_v9;
	int i_v10;
	PKDPC pDpc_v11;
	int nTryTimes_v12;
	int nLoopTimes_v13;
	KIRQL NewIrql; 
	KAFFINITY ActiveProcessors_v16;
	int nCount_v17; 
	int nCurCpu_v18;

	nCurCpu_v2 = 0;
	status = STATUS_UNSUCCESSFUL;
	NumberOfCpu_v4 = 0;

	nCount_v17 = 0;
	if ( (PCHAR)hook_a2 )
	{
		ActiveProcessors_v16 = KeQueryActiveProcessors();
		for (i_v6 = 0; i_v6 < 32; ++i_v6) 
		{
			if ( (ActiveProcessors_v16 >> i_v6) & 1 )
			{
				++NumberOfCpu_v4;
			}
		}

		if ( NumberOfCpu_v4 == 1 )                  // 如果是单核
		{
			_disable();
			oldIrql_v7 = KfRaiseIrql(DISPATCH_LEVEL);
			status = ((NTSTATUS (__stdcall *)(PTsFlt_HOOK_INFO))hook_a2)(pHookInfo_a1);
			KfLowerIrql(oldIrql_v7);
			_enable();
		}
		else
		{
			g_TsFltDpcInfo.pSpinLock = &g_SpinLock;
			g_TsFltDpcInfo.pFlag = &g_DpcFlag_dword_2816C;
			KeInitializeSpinLock(&g_SpinLock);
			for (int i = 0; i < 32; i++)
			{
				pDpc_v9 = &g_Dpc[i];
				KeInitializeDpc(pDpc_v9, DeferredRoutine, &g_TsFltDpcInfo);
			}
			g_DpcFlag_dword_2816C = 0;

			_disable();
			NewIrql = KfAcquireSpinLock(&g_SpinLock);

			__asm mov eax,fs:[0x51]
			__asm mov nCurCpu_v18, eax

			for (i_v10 = 0; i_v10 < 32; i_v10++)
			{
				pDpc_v11 = &g_Dpc[i_v10];
				if ( (ActiveProcessors_v16 & 1) == 1 )
				{
					++nCount_v17;
					if ( i_v10 != nCurCpu_v18 )
					{
						KeSetTargetProcessorDpc(pDpc_v11, (CCHAR)i_v10);
						KeSetImportanceDpc(pDpc_v11, HighImportance);
						KeInsertQueueDpc(pDpc_v11, 0, 0);
					}
				}
				ActiveProcessors_v16 >>= 1;
			}

			nTryTimes_v12 = 0;
			while ( TRUE )
			{
				//这里什么鬼。。。
				nLoopTimes_v13 = 1000000;
				while ( --nLoopTimes_v13 );

				if ( g_DpcFlag_dword_2816C == nCount_v17 - 1 )
					break;

				++nTryTimes_v12;
				if ( nTryTimes_v12 >= 15 )
				{
					KfReleaseSpinLock(&g_SpinLock, NewIrql);
					_enable();
					return STATUS_UNSUCCESSFUL;
				}
			}
			status = hook_a2(pHookInfo_a1);
			KfReleaseSpinLock(&g_SpinLock, NewIrql);
			_enable();
		}
	}
	return status;
}

int __stdcall xx_InterlockedCompareExchange64_12270(LONGLONG  *a1, LONGLONG  a2)
{
	return (int)_InterlockedCompareExchange64(a1, a2, *a1);
}

// 这里的HookPoint其实是一个数组
// HookPoint[0]=hook address
// HookPoint[1]=target address
NTSTATUS __stdcall xx_HookInternal_122A0(PTsFlt_HOOK_INFO pHookPoint_a1)
{
	NTSTATUS result; // eax@2
	PVOID HookAddress_v2; // ecx@3
	LARGE_INTEGER nJmpFar_v3 = {0}; // ST04_8@3

	if ( pHookPoint_a1 )
	{
		HookAddress_v2 = pHookPoint_a1->HookAddress;
		g_HookAddressOldCode1_dword_281A4 = *(DWORD *)HookAddress_v2;// 保存KiSystemFastCall里面的8个字节
		g_HookAddressOldCode2_dword_281A8 = *(DWORD *)((PCHAR)HookAddress_v2 + 4);
		nJmpFar_v3.HighPart = (PCHAR)pHookPoint_a1->TargetAddress - (PCHAR)HookAddress_v2 - 8;// 获取跳板函数相对于hook点的偏移
		nJmpFar_v3.LowPart= 0xE9909090;                   // 将8字节的内容code准备好，通过interlock64这个原子性直接写入hook address
		xx_InterlockedCompareExchange64_12270((LONGLONG*)pHookPoint_a1->MdlHookAddress, nJmpFar_v3.QuadPart);
		result = STATUS_SUCCESS;
	}
	else
	{
		result = STATUS_UNSUCCESSFUL;
	}
	return result;
}
int xx_HookKiSystemFastCall_12300(PVOID pOldAddress_a1, PVOID pNewAddress_a2)
{
	PVOID pOldAddress_v2 = pOldAddress_a1;
	PMDL Mdl_v3 = NULL; 
	NTSTATUS result = STATUS_UNSUCCESSFUL; 
	PVOID pRetAddress_v6 = NULL; 
	TsFlt_HOOK_INFO pHookPointInfo = {0};

	if ( pOldAddress_a1 && pNewAddress_a2 )
	{
		Mdl_v3 = xx_LockMemory_10A50(pOldAddress_a1, 0x10u, &pRetAddress_v6);
		if ( Mdl_v3 )
		{
			pHookPointInfo.HookAddress = pOldAddress_v2;
			pHookPointInfo.TargetAddress = pNewAddress_a2;
			pHookPointInfo.MdlHookAddress = pRetAddress_v6;
			result = xx_Hook_108C0(&pHookPointInfo, (NTSTATUS (__stdcall *)(PTsFlt_HOOK_INFO))xx_HookInternal_122A0);
			MmUnlockPages(Mdl_v3);
			IoFreeMdl(Mdl_v3);
		}
	}
	return result;
}

PVOID __stdcall xx_Filter_12170(ULONG index_a1, PVOID Address_a2, PVOID Base_a3)
{
	PVOID result; // eax@1
	int IsShadowSsdtTable_v4; // ecx@6
	PCHAR pFunc_v5; // ecx@11
	PCHAR v6; // edx@12

	result = Address_a2;
	if ( index_a1 >= 0x400 )
		return result;

	if ( Base_a3 != g_SsdtTableBase || index_a1 > g_SsdtCount_dword_28190 )
	{
		if ( Base_a3 == g_W32pServiceTable_dword_28194 && index_a1 <= g_W32pServiceLimit_dword_28198 )
		{
			IsShadowSsdtTable_v4 = TRUE;
			goto LABEL_11;
		}
		if ( !g_KeServiceDescriptorTable_dword_281BC
			|| g_KeServiceDescriptorTable_dword_281BC->ServiceTableBase != Base_a3
			|| index_a1 > g_SsdtCount_dword_28190 )
			return result;
	}
	IsShadowSsdtTable_v4 = FALSE;

LABEL_11:
	pFunc_v5 = (PCHAR)g_SaveSsdt_dword_28380[index_a1 + (IsShadowSsdtTable_v4 << 10)];
	if ( pFunc_v5 )
	{
		v6 = (PCHAR)*(DWORD *)(pFunc_v5 + 0x24);
		if ( v6 )
		{
			*(DWORD *)(pFunc_v5 + 0x20) = (DWORD)Address_a2;
			result = v6;
		}
	}
	return result;
}

__declspec(naked) xx_HookTargetFunctionAfterVista_12210()
{
	__asm
	{
		pushfd
		pushad
		push    edi             ; DWORD
		push    edx             ; DWORD
		push    eax             ; DWORD
		call    xx_Filter_12170
		mov     [esp + 14h], eax
		popad
		popfd
		mov     edi, esp
		cmp     esi, g_MmUserProbeAddress_dword_28188
		push    g_JmpBackAddress_dword_281A0
		retn
	}
}

__declspec(naked) xx_HookTargetFunctionBeforeVista_121F0()
{
	__asm
	{
		pushfd
		pushad
		push    edi             ; DWORD
		push    ebx             ; DWORD
		push    eax             ; DWORD
		call    xx_Filter_12170
		mov     [esp + 10h], eax
		popad
		popfd
		mov     edi, esp
		cmp     esi, g_MmUserProbeAddress_dword_28188
		push    g_JmpBackAddress_dword_281A0
		retn
	}
}

NTSTATUS __stdcall xx_TargetFunc_123A0(int a1)
{
	NTSTATUS result; // eax@1
	int v2; // eax@2
	signed __int64 v3 = 0; // ST0C_8@2

	result = STATUS_UNSUCCESSFUL;
	if ( a1 )
	{
		v2 = *(DWORD *)a1;
		//dword_2A388 = **(DWORD **)a1;
		//dword_2A38C = *(DWORD *)(v2 + 4);
		//WORD3(v3) = 0x675;
		//*(DWORD *)((char *)&v3 + 2) = *(DWORD *)(a1 + 4) - *(DWORD *)a1 - 6;
		//LOWORD(v3) = 0xE990u;
		xx_InterlockedCompareExchange64_12270(*(LONGLONG **)(a1 + 8), v3);
		result = STATUS_SUCCESS;
	}
	return result;
}

NTSTATUS xx_TsHookFunction_12400(PVOID pOldAddress_a1, PVOID pNewAddress_a2)
{
	PVOID pOldAddress_v2 = NULL;
	PMDL pMdl_v3 = NULL;
	NTSTATUS status = STATUS_UNSUCCESSFUL; 
	PVOID ppRetAddress_v6 = NULL; 
	TsFlt_HOOK_INFO TsFltHookInfo_v7 = {0};

	pOldAddress_v2 = pOldAddress_a1;
	if ( pOldAddress_a1 && pNewAddress_a2 )
	{
		pMdl_v3 = xx_LockMemory_10A50(pOldAddress_a1, 0x10u, &ppRetAddress_v6);
		if ( pMdl_v3 )
		{
			TsFltHookInfo_v7.HookAddress = pOldAddress_v2;
			TsFltHookInfo_v7.TargetAddress = pNewAddress_a2;
			TsFltHookInfo_v7.MdlHookAddress = ppRetAddress_v6;
			status = xx_Hook_108C0(&TsFltHookInfo_v7, (NTSTATUS (__stdcall *)(PTsFlt_HOOK_INFO))xx_TargetFunc_123A0);
			MmUnlockPages(pMdl_v3);
			IoFreeMdl(pMdl_v3);
		}
	}
	return status;
}

__declspec(naked) xx_FilterFunctionBeforVista_12230()
{
	__asm
	{
		pushfd
		pushad
		push    edi             ; DWORD
		push    ebx             ; DWORD
		push    eax             ; DWORD
		call    xx_Filter_12170
		mov     [esp+10h], eax
		popad
		popfd
		mov     edi, esp
		test    byte ptr [ebp+72h], 2
		push    g_HookLen6_dword_2A384
		retn
	}
}

__declspec(naked) xx_FilterFunctionAfterVista_12250()
{
	__asm
	{
		pushfd
		pushad
		push    edi             ; DWORD
		push    edx             ; DWORD
		push    eax             ; DWORD
		call    xx_Filter_12170
		mov     [esp+14h], eax
		popad
		popfd
		mov     edi, esp
		test    byte ptr [ebp+72h], 2
		push    g_HookLen6_dword_2A384
		retn
	}
}

NTSTATUS xx_InitKiSystemFastCall_124A0()
{
	NTSTATUS status; // eax@1
	ULONG Index_v1; // esi@16
	PTsFlt_FILTER pFilterInfo_v2; // ecx@17
	int v3; // ecx@21

	status = STATUS_UNSUCCESSFUL;
	if ( g_HookKiSystemFastCallFlag_dword_281E4 == 2 || !(g_HookLen8_dword_281E0 & 8) )
	{
		return status;
	}

	if ( g_KiSystemServiceHookAddress_dword_2819C )
	{
		if (xx_GetVersion_113C0() >= OS_WinVista )
		{
			status = xx_HookKiSystemFastCall_12300((void *)g_KiSystemServiceHookAddress_dword_2819C,xx_HookTargetFunctionAfterVista_12210);
		}
		else
		{
			status = xx_HookKiSystemFastCall_12300((void *)g_KiSystemServiceHookAddress_dword_2819C,xx_HookTargetFunctionBeforeVista_121F0);
		}
		if ( NT_SUCCESS(status) )
		{
			g_HookKiSystemFastCallFlag_dword_281E4 = 1;
		}
	}

	if ( g_FindCodeHookAddress_dword_2A380 )
	{
		if ( xx_GetVersion_113C0() >= OS_WinVista )           // Vista之后
		{
			status = xx_TsHookFunction_12400((void *)g_FindCodeHookAddress_dword_2A380, xx_FilterFunctionAfterVista_12250);
		}
		else
		{
			status = xx_TsHookFunction_12400((void *)g_FindCodeHookAddress_dword_2A380, xx_FilterFunctionBeforVista_12230);
		}
		if ( !NT_SUCCESS(status))
		{
			return status;
		}
		g_HookKiSystemFastCallFlag_dword_281E4 = 3;
	}

	if ( NT_SUCCESS(status) )
	{
		Index_v1 = 0;
		do
		{
			pFilterInfo_v2 = g_FuncFilterInfo_dword_281F0[Index_v1];
			if ( pFilterInfo_v2 && (!pFilterInfo_v2->Type || pFilterInfo_v2->Type == 1) )
			{
				pFilterInfo_v2->IsHook = TRUE;
			}

			pFilterInfo_v2 = g_FuncFilterInfo_dword_281F0[Index_v1 + 1];
			if ( pFilterInfo_v2 && (!pFilterInfo_v2->Type || pFilterInfo_v2->Type == 1) )
			{
				pFilterInfo_v2->IsHook = TRUE;
			}
			Index_v1 += 2;
		}
		while ( Index_v1 < arraysize(g_FuncFilterInfo_dword_281F0) );
	}
	return status;
}

PRKAPC_STATE xx_TsAttachProcessByPid_10BF0(HANDLE Pid_a1)
{
	PRKAPC_STATE pApcState = NULL;
	PEPROCESS Object = NULL;

	if ( Pid_a1 == PsGetCurrentProcessId() )
		return (PRKAPC_STATE)0xEEEEDDDD;

	if ( Pid_a1 && PsLookupProcessByProcessId(Pid_a1, &Object) >= 0 )
	{
		pApcState = (PRKAPC_STATE)ExAllocatePoolWithTag(PagedPool, sizeof(KAPC_STATE), 'THOP');
		if ( !pApcState )
		{
			ObfDereferenceObject(Object);
			return pApcState;
		}
		pApcState->Process = Object;
		KeStackAttachProcess(Object, pApcState);
	}
	return pApcState;
}

void xx_TsDeatchProcess_10C60(PRKAPC_STATE pApcState)
{
	if ( pApcState )
	{
		if ( *(DWORD*)pApcState != 0xEEEEDDDD )
		{
			KeUnstackDetachProcess(pApcState);
			ObfDereferenceObject(pApcState->Process);
			ExFreePool((PVOID)pApcState);
		}
	}
}

// 参数1为返回旧函数
// 参数2为index下标
// 参数3为hook的新函数
int xx_HookSsdtFunctionByIndex_20D50(PVOID pOldAddress_a1, int index_a2, PVOID pNewFunction_a3)
{
	int index_v2 = -1;
	PULONG LockMemory_v3 = NULL;
	PMDL pMdl_v4 = NULL;

	if ( index_a2 == -1 || index_a2 == 0x3FF || !pOldAddress_a1 || !pNewFunction_a3 || !g_SsdtTableBase )
		return index_v2;

	pMdl_v4 = xx_LockMemory_10A50(g_SsdtTableBase, 4 * g_SsdtCount_dword_28190, (PVOID*)&LockMemory_v3);
	if ( pMdl_v4 )
	{
		*(DWORD *)pOldAddress_a1 = g_SsdtTableBase[index_a2];
		LockMemory_v3[index_a2] = (ULONG)pNewFunction_a3;
		xx_UnLockMemory_10B20(pMdl_v4);
		index_v2 = index_a2;
	}
	return index_v2;
}

int xx_HookShadowSsdtFunctionByIndex_20DD0(int index_a1, PVOID pNewFunction_a2, PVOID pOldFunction_a3)
{
	int index_v3 = -1;
	HANDLE pCurPid_v4 = NULL;
	HANDLE pSmssPid_v5 = NULL;
	PRKAPC_STATE pApcState_v6 = NULL;
	PMDL pMdl_v6 = NULL;
	PMDL pMdl_v8 = NULL;
	PULONG LockMemory_v9 = NULL;

	if ( index_a1 == -1 || index_a1 == 0x3FF || !pOldFunction_a3 || !pNewFunction_a2 || !g_W32pServiceTable_dword_28194 )
		return index_v3;

	pCurPid_v4 = PsGetCurrentProcessId();
	pSmssPid_v5 = (HANDLE)xx_GetProcessIdByProcessName_10B40(L"smss.exe");
	if ( !g_CsrssPid_dword_281D0 )
	{
		if ( pCurPid_v4 == pSmssPid_v5 )
		{
			pMdl_v8 = xx_LockMemory_10A50(g_W32pServiceTable_dword_28194, sizeof(ULONG) * g_W32pServiceLimit_dword_28198, (PVOID*)&LockMemory_v9);
			if ( pMdl_v8 )
			{
				*(DWORD *)pOldFunction_a3 = g_W32pServiceTable_dword_28194[index_a1];
				LockMemory_v9[index_a1] = (ULONG)pNewFunction_a2;
				index_v3 = index_a1;
				xx_UnLockMemory_10B20(pMdl_v8);
			}
		}
		return index_v3;
	}

	pApcState_v6 = xx_TsAttachProcessByPid_10BF0((void *)g_CsrssPid_dword_281D0);
	if ( !pApcState_v6 )
		return index_v3;

	pMdl_v6 = xx_LockMemory_10A50(g_W32pServiceTable_dword_28194, sizeof(ULONG) * g_W32pServiceLimit_dword_28198, (PVOID*)&LockMemory_v9);
	if ( pMdl_v6 )
	{
		*(DWORD *)pOldFunction_a3 = g_W32pServiceTable_dword_28194[index_a1];
		LockMemory_v9[index_a1] = (ULONG)pNewFunction_a2;
		index_v3 = index_a1;
		xx_UnLockMemory_10B20(pMdl_v6);
	}
	xx_TsDeatchProcess_10C60(pApcState_v6);
	return index_v3;
}

NTSTATUS xx_HookSsdtAndShadowSsdt_20EF0()
{
	PTsFlt_FILTER pHookInfo_v1; // esi@4
	ULONG index_v2; // edi@5
	ULONG index_v3; // eax@9

	if ( g_HookKiSystemFastCallFlag_dword_281E4 != 1 && g_HookKiSystemFastCallFlag_dword_281E4 != 3 )
	{
		g_HookKiSystemFastCallFlag_dword_281E4 = 2;
		for (int i = 0; i < arraysize(g_FuncFilterInfo_dword_281F0); i++)
		{
			pHookInfo_v1 = g_FuncFilterInfo_dword_281F0[i];
			if (pHookInfo_v1)
			{
				index_v2 = pHookInfo_v1->FuncIndex; // 下标
				if ( index_v2 == -1 )
				{
					if (pHookInfo_v1->Type)
					{
						//shadow ssdt
						if (!pHookInfo_v1->IsHook)
						{
							index_v3 = xx_HookShadowSsdtFunctionByIndex_20DD0(index_v2, pHookInfo_v1->ProxyFunc, &pHookInfo_v1->SaveFunc);
							if ( index_v3 != -1 )
							{
								pHookInfo_v1->IsHook = TRUE;// isHook标志
							}
						}
					}
					else
					{
						//ssdt
						if (!pHookInfo_v1->IsHook)
						{
							index_v3 = xx_HookSsdtFunctionByIndex_20D50(&pHookInfo_v1->SaveFunc, index_v2, pHookInfo_v1->ProxyFunc);
							if ( index_v3 != -1 )
							{
								pHookInfo_v1->IsHook = TRUE;// isHook标志
							}
						}
					}
				}
			}
		}
	}
	return STATUS_UNSUCCESSFUL;
}

NTSTATUS xx_Printf_20F90(PTsFlt_NOTIFY_INFO pBufferInfo_a1, PTsFlt_FILTER pProcessNotifyInfo_a2)
{
	NTSTATUS result = STATUS_SUCCESS;
//	unsigned int v2; // ebp@5
//	PTsFlt_TSKSP pTsFltTSkspInfo_v3; // esi@5
//	int (__stdcall *pTsKspFunc_v4)(DWORD); // ebx@7
//	int pEprocess_v5; // eax@12
//	int v7; // eax@19
//	unsigned int status_v8; // [sp+10h] [bp-8h]@1
//	int v9; // [sp+14h] [bp-4h]@8
//
//	status_v8 = 0xEEEE0000;
//	if ( pProcessNotifyInfo_a2
//		&& pBufferInfo_a1
//		&& pProcessNotifyInfo_a2->Flag3 != 1
//		&& pProcessNotifyInfo_a2->Flag4 )
//	{
//		v2 = 0;
//		pTsFltTSkspInfo_v3 = &pProcessNotifyInfo_a2->TsFltTSksp;
//		do
//		{
//			if ( pTsFltTSkspInfo_v3->Type != 1 )
//			{
//				pTsKspFunc_v4 = (int (__stdcall **)(DWORD))(pTsFltTSkspInfo_v3->Function);// TSKsp+0x4065:
//				if ( pTsKspFunc_v4 )
//				{
//					InterlockedIncrement((volatile LONG *)&pTsFltTSkspInfo_v3->Lock);
//					pBufferInfo_a1->pList = v2;
//					v9 = pTsKspFunc_v4(pBufferInfo_a1);
//					InterlockedDecrement((volatile LONG *)&pTsFltTSkspInfo_v3->Lock);
//
//					if ( pBufferInfo_a1->Flag & 0x10
//						&& dword_28180
//						&& (pBufferInfo_a1->IndexFunction != 3 || pBufferInfo_a1->Parameter1 == *(DWORD *)dword_28180) )
//					{
//						PsGetCurrentProcessId();
//						pEprocess_v5 = (int)IoGetCurrentProcess();
//						xx_GetProcessName_111E0(pEprocess_v5);
//						xx_DbgPrint_22270(
//							dword_28180,
//							(int)"[Sysnap DbgLog] Modify--> TableIndex %d, Process %s[%d] ",
//							*(DWORD *)(pProcessNotifyInfo_a2 + 12));
//					}
//					switch ( v9 )
//					{
//					case 0xEEEE0004:
//						if ( dword_28180
//							&& (*(DWORD *)(pBufferInfo_a1 + 0x80) != 3 || *(DWORD *)(pBufferInfo_a1 + 8) == *(DWORD *)dword_28180) )
//						{
//							PsGetCurrentProcessId();
//							v7 = (int)IoGetCurrentProcess();
//							xx_GetProcessName_111E0(v7);
//							xx_DbgPrint_22270(
//								dword_28180,
//								(int)"[Sysnap DbgLog] Block--> TableIndex %d, Process %s[%d] ",
//								*(DWORD *)(pProcessNotifyInfo_a2 + 12));
//						}
//						return 0xEEEE0004;
//					case 0xEEEE0005:
//						status_v8 = 0xEEEE0005;
//						goto LABEL_22;
//					case 0xEEEE0002:
//					case 0xEEEE0003:
//						goto LABEL_22;
//					default:
//						break;
//					}
//				}
//			}
//			++v2;
//			pTsFltTSkspInfo_v3 += 64;
//		}
//		while ( v2 < 0x10 );
//		result = 0xEEEE0000;
//	}
//	else
//	{
//LABEL_22:
//		result = status_v8;
//	}
	return result;
}

NTSTATUS __stdcall xx_TsLockInfo_21110(PTsFlt_NOTIFY_INFO pTsFltFilterNotify_a1)
{
	NTSTATUS result = STATUS_SUCCESS;
//	PTsFlt_NOTIFY_INFO pTsFltFilterNotify_v1; // ebx@1
//	ULONG Index_v2; // edi@2
//	int v3; // ebp@2
//	int v4; // esi@2
//	int v5; // ebx@6
//	NTSTATUS result; // eax@9
//	NTSTATUS status_v7; // [sp+4h] [bp-4h]@1
//
//	pTsFltFilterNotify_v1 = pTsFltFilterNotify_a1;
//	status_v7 = 0xEEEE0000;
//	if ( pTsFltFilterNotify_a1 )
//	{
//		Index_v2 = 0;
//		v3 = pTsFltFilterNotify_a1 + 0x88;
//		v4 = (PCHAR)g_FuncFilterInfo_dword_281F0[pTsFltFilterNotify_a1->IndexFunction] + 0x100;
//		do
//		{
//			if ( *(DWORD *)(v4 + 4) != 1 && *(DWORD *)(v4 + 48) && *(DWORD *)v3 )
//			{
//				InterlockedIncrement((volatile LONG *)v4);
//				pTsFltFilterNotify_v1->Type = Index_v2;
//				v5 = (*(int (__stdcall **)(int))v3)((int)pTsFltFilterNotify_v1);
//				InterlockedDecrement((volatile LONG *)v4);
//				switch ( v5 )
//				{
//				case 0xEEEE0005:
//					status_v7 = 0xEEEE0005;
//					goto LABEL_11;
//				case 0xEEEE0002:
//				case 0xEEEE0003:
//				case 0xEEEE0004:
//					goto LABEL_11;
//				default:
//					pTsFltFilterNotify_v1 = pTsFltFilterNotify_a1;
//					break;
//				}
//			}
//			++Index_v2;
//			v3 += 4;
//			v4 += 64;
//		}
//		while ( Index_v2 < 0x10 );
//		result = 0xEEEE0000;
//	}
//	else
//	{
//LABEL_11:
//		result = status_v7;
//	}
	return result;
}

void __stdcall xx_CreateProcessNotifyRoutine(HANDLE ParentId, HANDLE ProcessId, int Create)
{
	PTsFlt_FILTER pProcessNotifyInfo_v3; // esi@1
	unsigned int v5; // edi@7
	int v6; // ST20_4@9
	int (__stdcall *pfnFunc_v7)(DWORD, DWORD, DWORD); // eax@10
	unsigned int status_v8; // ebx@11
	int v9; // ST20_4@12
	void (__stdcall *pfnFunc_v10)(DWORD, DWORD, DWORD); // esi@23
	PTsFlt_NOTIFY_INFO pSlistEntry_v11; // [sp+1Ch] [bp-10h]@4
	ULONGLONG FastMutex; // [sp+24h] [bp-8h]@4

	pProcessNotifyInfo_v3 = g_ProcessNotifyInfo_dword_282C0;
	pSlistEntry_v11 = (PTsFlt_NOTIFY_INFO)ExAllocateFromNPagedLookasideList(&g_Lookaside);
	memset((void *)pSlistEntry_v11, 0, 0xCCu);

	FastMutex = 0i64;
	status_v8 = 0xC000022;
	if ( g_FilterFlag_dword_281D4 == 1 )
		FastMutex = KeQueryInterruptTime();

	if ( pSlistEntry_v11 )
	{
		pSlistEntry_v11->Parameter[0] = (DWORD)ParentId;
		pSlistEntry_v11->Parameter[1] = (DWORD)ProcessId;
		pSlistEntry_v11->Parameter[2] = (DWORD)Create;
		pSlistEntry_v11->ParameterNumber = 3;
		pSlistEntry_v11->ProxyFunction = pProcessNotifyInfo_v3->SaveFunc;
		pSlistEntry_v11->IndexFunction = 0x34;
		/*
		*(DWORD *)(pBufferInfo_v4 + 8) = ParentId;
		*(DWORD *)(pBufferInfo_v4 + 0xC) = ProcessId;
		*(DWORD *)(pBufferInfo_v4 + 0x10) = Create;
		*(DWORD *)(pBufferInfo_v4 + 4) = 3;
		*(DWORD *)(pBufferInfo_v4 + 0x7C) = pProcessNotifyInfo_v3->SaveFunc;
		*(DWORD *)(pBufferInfo_v4 + 0x80) = 52;
		*/
		InterlockedIncrement(&pProcessNotifyInfo_v3->Lock1);
		v5 = xx_Printf_20F90(pSlistEntry_v11, pProcessNotifyInfo_v3);
		InterlockedDecrement(&pProcessNotifyInfo_v3->Lock1);
		if ( v5 != 0xEEEE0004 )
		{
			if ( v5 == 0xEEEE0005 )
			{
				v6 = pSlistEntry_v11->FunctionRetValue;
			}
			else
			{
				pfnFunc_v7 = (int (__stdcall *)(DWORD, DWORD, DWORD))(pProcessNotifyInfo_v3->SaveFunc);
				if ( pfnFunc_v7 )
				{
					pSlistEntry_v11->FunctionRetValue = pfnFunc_v7(pSlistEntry_v11->Parameter[0], pSlistEntry_v11->Parameter[1], pSlistEntry_v11->Parameter[2]);
					InterlockedIncrement(&pProcessNotifyInfo_v3->Lock2);
					status_v8 = xx_TsLockInfo_21110(pSlistEntry_v11);
					InterlockedDecrement(&pProcessNotifyInfo_v3->Lock2);
					if ( status_v8 == 0xEEEE0005 )
					{
						v9 = pSlistEntry_v11->FunctionRetValue;
					}
				}
			}
		}
	}
	if ( g_ProcessNotifyInfo_dword_282C0->IsHook && FastMutex && g_FilterFlag_dword_281D4 )
	{
		//sub_11810(&g_ProcessNotifyInfo_dword_282C0->Reserve8, (PFAST_MUTEX)FastMutex, SHIDWORD(FastMutex));
	}
	if ( pSlistEntry_v11 )
	{
		ExFreeToNPagedLookasideList(&g_Lookaside, pSlistEntry_v11);
	}
	else
	{
		pfnFunc_v10 = (void (__stdcall *)(DWORD, DWORD, DWORD))(pProcessNotifyInfo_v3->SaveFunc);
		if ( pfnFunc_v10 )
		{
			pfnFunc_v10((DWORD)ParentId, (DWORD)ProcessId, (DWORD)Create);
		}
	}
}

int __stdcall xx_CreateProcessNotifyEx_21B80(int Process_a1, int ProcessId_a2, int CreateInfo_a3)
{
	return 0;
	//int v3; // esi@1
	//int v4; // edi@1
	//unsigned int v5; // edi@7
	//int (__stdcall *v6)(DWORD, DWORD, DWORD); // eax@10
	//int v7; // eax@11
	//unsigned int v8; // ebx@11
	//int (__stdcall *pfnFunc_v10)(DWORD, DWORD, DWORD); // esi@23
	//int v11; // [sp+1Ch] [bp-10h]@4
	//unsigned int v12; // [sp+20h] [bp-Ch]@4
	//ULONGLONG FastMutex; // [sp+24h] [bp-8h]@4

	//v3 = g_PsSetCreateProcessNotifyRoutineEx_dword_28314;
	//v4 = ExAllocateFromNPagedLookasideList(&g_Lookaside);
	//if (v4)
	//{
	//	memset((void *)v4, 0, 0xCCu);
	//}
	//v11 = v4;
	//v12 = 0xC0000022;
	//FastMutex = 0i64;
	//if ( g_FilterFlag_dword_281D4 == 1 )
	//	FastMutex = KeQueryInterruptTime();
	//if ( v4 )
	//{
	//	*(DWORD *)(v4 + 8) = Process_a1;
	//	*(DWORD *)(v4 + 12) = ProcessId_a2;
	//	*(DWORD *)(v4 + 16) = CreateInfo_a3;
	//	*(DWORD *)(v4 + 4) = 3;
	//	*(DWORD *)(v4 + 124) = *(DWORD *)(v3 + 32);
	//	*(DWORD *)(v4 + 128) = 73;
	//	InterlockedIncrement((volatile LONG *)(v3 + 20));
	//	v5 = xx_Printf_20F90(v4, v3);
	//	InterlockedDecrement((volatile LONG *)(v3 + 20));
	//	if ( v5 != -286392316 )
	//	{
	//		if ( v5 == -286392315 )
	//		{
	//			v12 = *(DWORD *)(v11 + 120);
	//		}
	//		else
	//		{
	//			v6 = *(int (__stdcall **)(DWORD, DWORD, DWORD))(v3 + 32);
	//			if ( v6 )
	//			{
	//				v7 = v6(*(DWORD *)(v11 + 8), *(DWORD *)(v11 + 12), *(DWORD *)(v11 + 16));
	//				*(DWORD *)(v11 + 120) = v7;
	//				v12 = v7;
	//				InterlockedIncrement((volatile LONG *)(v3 + 24));
	//				v8 = xx_TsLockInfo_21110(v11);
	//				InterlockedDecrement((volatile LONG *)(v3 + 24));
	//				if ( v8 == -286392315 )
	//					v12 = *(DWORD *)(v11 + 120);
	//			}
	//		}
	//	}
	//}
	//if ( g_PsSetCreateProcessNotifyRoutineEx_dword_28314->IsHook && FastMutex )
	//{
	//	if ( g_FilterFlag_dword_281D4 )
	//	{
	//		//sub_11810(g_PsSetCreateProcessNotifyRoutineEx_dword_28314 + 48, (PFAST_MUTEX)FastMutex, SHIDWORD(FastMutex));
	//	}
	//}
	//if ( v11 )
	//{
	//	if ( v11 )
	//	{
	//		ExFreeToNPagedLookasideList(&g_Lookaside, v11);
	//	}
	//	return v12;
	//}
	//pfnFunc_v10 = *(int (__stdcall **)(DWORD, DWORD, DWORD))(v3 + 32);
	//if ( !pfnFunc_v10 )
	//	return v12;
	//return pfnFunc_v10(Process_a1, ProcessId_a2, CreateInfo_a3);
}

void __stdcall xx_CreateThreadNotifyRoutine_21700(HANDLE ProcessId, HANDLE ThreadId, int Create)
{

	//int v3; // esi@1
	//int v4; // edi@1
	//unsigned int v5; // edi@7
	//int v6; // ST20_4@9
	//int (__stdcall *pfnFunc_v7)(DWORD, DWORD, DWORD); // eax@10
	//unsigned int v8; // ebx@11
	//int v9; // ST20_4@12
	//void (__stdcall *pfnFunc_v10)(DWORD, DWORD, DWORD); // esi@23
	//int v11; // [sp+1Ch] [bp-10h]@4
	//ULONGLONG FastMutex; // [sp+24h] [bp-8h]@4

	//v3 = g_ThreadNotifyInfo_dword_282C4;
	//v4 = ExAllocateFromNPagedLookasideList(&g_Lookaside);
	//if (v4)
	//{
	//	memset((void *)v4, 0, 0xCCu);
	//}

	//v11 = v4;
	//FastMutex = 0i64;
	//if ( g_FilterFlag_dword_281D4 == 1 )
	//	FastMutex = KeQueryInterruptTime();
	//if ( v4 )
	//{
	//	*(DWORD *)(v4 + 8) = ProcessId;
	//	*(DWORD *)(v4 + 12) = ThreadId;
	//	*(DWORD *)(v4 + 16) = Create;
	//	*(DWORD *)(v4 + 4) = 3;
	//	*(DWORD *)(v4 + 124) = *(DWORD *)(v3 + 32);
	//	*(DWORD *)(v4 + 128) = 53;
	//	InterlockedIncrement((volatile LONG *)(v3 + 20));
	//	v5 = xx_Printf_20F90(v4, v3);
	//	InterlockedDecrement((volatile LONG *)(v3 + 20));
	//	if ( v5 != -286392316 )
	//	{
	//		if ( v5 == -286392315 )
	//		{
	//			v6 = *(DWORD *)(v11 + 120);
	//		}
	//		else
	//		{
	//			pfnFunc_v7 = *(int (__stdcall **)(DWORD, DWORD, DWORD))(v3 + 32);
	//			if ( pfnFunc_v7 )
	//			{
	//				*(DWORD *)(v11 + 120) = pfnFunc_v7(*(DWORD *)(v11 + 8), *(DWORD *)(v11 + 12), *(DWORD *)(v11 + 16));
	//				InterlockedIncrement((volatile LONG *)(v3 + 24));
	//				v8 = xx_TsLockInfo_21110(v11);
	//				InterlockedDecrement((volatile LONG *)(v3 + 24));
	//				if ( v8 == -286392315 )
	//					v9 = *(DWORD *)(v11 + 120);
	//			}
	//		}
	//	}
	//}
	//if ( *(DWORD *)(g_ThreadNotifyInfo_dword_282C4 + 16) && FastMutex && g_FilterFlag_dword_281D4 )
	//{
	//	//sub_11810(g_ThreadNotifyInfo_dword_282C4 + 48, (PFAST_MUTEX)FastMutex, SHIDWORD(FastMutex));
	//}
	//if ( v11 )
	//{
	//	if ( v11 )
	//	{
	//		ExFreeToNPagedLookasideList(&g_Lookaside, v11);
	//	}
	//}
	//else
	//{
	//	pfnFunc_v10 = *(void (__stdcall **)(DWORD, DWORD, DWORD))(v3 + 32);
	//	if ( pfnFunc_v10 )
	//		pfnFunc_v10(ProcessId, ThreadId, Create);
	//}
}

void __stdcall xx_LoadImageNotify_21940(PUNICODE_STRING FullImageName, HANDLE ProcessId, PIMAGE_INFO ImageInfo)
{
	//PTsFlt_FILTER  pLoadImageTsFltFilter_v3; // esi@1
	//int v4; // edi@1
	//unsigned int v5; // edi@7
	//int v6; // ST20_4@9
	//int (__stdcall *pfnFunc_v7)(DWORD, DWORD, DWORD); // eax@10
	//unsigned int v8; // ebx@11
	//int v9; // ST20_4@12
	//void (__stdcall *pfnFunc_v10)(DWORD, DWORD, DWORD); // esi@23
	//int v11; // [sp+1Ch] [bp-10h]@4
	//ULONGLONG FastMutex; // [sp+24h] [bp-8h]@4

	//pLoadImageTsFltFilter_v3 = g_ImageNotifyInfo_dword_282C8;
	//v4 = ExAllocateFromNPagedLookasideList(&g_Lookaside);
	//if (v4)
	//{
	//	memset((void *)v4, 0, 0xCCu);
	//}
	//v11 = v4;
	//FastMutex = 0i64;
	//if ( g_FilterFlag_dword_281D4 == 1 )
	//{
	//	FastMutex = KeQueryInterruptTime();
	//}
	//if ( v4 )
	//{
	//	*(DWORD *)(v4 + 8) = FullImageName;
	//	*(DWORD *)(v4 + 12) = ProcessId;
	//	*(DWORD *)(v4 + 16) = ImageInfo;
	//	*(DWORD *)(v4 + 4) = 3;
	//	*(DWORD *)(v4 + 124) = *(DWORD *)(pLoadImageTsFltFilter_v3 + 32);
	//	*(DWORD *)(v4 + 128) = 54;
	//	InterlockedIncrement((volatile LONG *)(pLoadImageTsFltFilter_v3 + 20));
	//	v5 = xx_Printf_20F90(v4, pLoadImageTsFltFilter_v3);
	//	InterlockedDecrement((volatile LONG *)(pLoadImageTsFltFilter_v3 + 20));
	//	if ( v5 != -286392316 )
	//	{
	//		if ( v5 == -286392315 )
	//		{
	//			v6 = *(DWORD *)(v11 + 120);
	//		}
	//		else
	//		{
	//			pfnFunc_v7 = *(int (__stdcall **)(DWORD, DWORD, DWORD))(pLoadImageTsFltFilter_v3 + 32);
	//			if ( pfnFunc_v7 )
	//			{
	//				*(DWORD *)(v11 + 120) = pfnFunc_v7(*(DWORD *)(v11 + 8), *(DWORD *)(v11 + 12), *(DWORD *)(v11 + 16));
	//				InterlockedIncrement((volatile LONG *)(pLoadImageTsFltFilter_v3 + 24));
	//				v8 = xx_TsLockInfo_21110(v11);
	//				InterlockedDecrement((volatile LONG *)(pLoadImageTsFltFilter_v3 + 24));
	//				if ( v8 == -286392315 )
	//					v9 = *(DWORD *)(v11 + 120);
	//			}
	//		}
	//	}
	//}
	//if ( *(DWORD *)(g_ImageNotifyInfo_dword_282C8 + 16) && FastMutex && g_FilterFlag_dword_281D4 )
	//{	
	//	//sub_11810(g_ImageNotifyInfo_dword_282C8 + 48, (PFAST_MUTEX)FastMutex, SHIDWORD(FastMutex));
	//}
	//if ( v11 )
	//{
	//	if ( v11 )
	//	{
	//		ExFreeToNPagedLookasideList(&g_Lookaside, v11);
	//	}
	//}
	//else
	//{
	//	pfnFunc_v10 = *(void (__stdcall **)(DWORD, DWORD, DWORD))(pLoadImageTsFltFilter_v3 + 32);
	//	if ( pfnFunc_v10 )
	//	{
	//		pfnFunc_v10((DWORD)FullImageName, (DWORD)ProcessId, (DWORD)ImageInfo);
	//	}
	//}
}

NTSTATUS xx_InitNotifyRoutine_21DC0()
{
	PTsFlt_FILTER pProcessTsFltFilter = NULL; 
	PTsFlt_FILTER pProcessExTsFltFilter = NULL;
	PTsFlt_FILTER pThreadTsFltFilter = NULL; 
	PTsFlt_FILTER pLoadImageTsFltFilter = NULL;
	NTSTATUS status_v9 = STATUS_SUCCESS; 
	UNICODE_STRING DestinationString = {0}; 

	pProcessTsFltFilter = g_ProcessNotifyInfo_dword_282C0;
	if ( g_ProcessNotifyInfo_dword_282C0 )
	{
		if ( !pProcessTsFltFilter->IsHook )
		{
			pProcessTsFltFilter->Type = 3;
			status_v9 = PsSetCreateProcessNotifyRoutine((PCREATE_PROCESS_NOTIFY_ROUTINE)xx_CreateProcessNotifyRoutine, FALSE);
			if ( NT_SUCCESS(status_v9) )
			{
				pProcessTsFltFilter->IsHook = TRUE;
			}
		}
	}
	else if ( (PCHAR)xx_CreateProcessNotifyRoutine )
	{
		pProcessTsFltFilter = (PTsFlt_FILTER)ExAllocatePoolWithTag(NonPagedPool, 0x4F8u, 'THOP');
		if ( pProcessTsFltFilter )
		{
			memset(pProcessTsFltFilter, 0, 0x4F8u);
			pProcessTsFltFilter->FuncName = L"ProcessNotify";
			pProcessTsFltFilter->CurTsFltIndex = 0x34;
			pProcessTsFltFilter->ProxyFunc = xx_CreateProcessNotifyRoutine;
			pProcessTsFltFilter->FuncIndex = -1;
			pProcessTsFltFilter->IsHook = FALSE;
			pProcessTsFltFilter->Flag1 = 1;
			pProcessTsFltFilter->Flag2 = 0;
			KeInitializeEvent((PRKEVENT)(&pProcessTsFltFilter->Kevent), SynchronizationEvent, 0);
			g_ProcessNotifyInfo_dword_282C0 = pProcessTsFltFilter;

			pProcessTsFltFilter->Type = 3;
			status_v9 = PsSetCreateProcessNotifyRoutine((PCREATE_PROCESS_NOTIFY_ROUTINE)xx_CreateProcessNotifyRoutine, FALSE);
			if ( NT_SUCCESS(status_v9) )
			{
				pProcessTsFltFilter->IsHook = TRUE;
			}
		}
	}

	if ( !g_PsSetCreateProcessNotifyRoutineEx_dword_28314 )
	{
		RtlInitUnicodeString(&DestinationString, L"PsSetCreateProcessNotifyRoutineEx");
		g_pfnPsSetCreateProcessNotifyRoutineEx_dword_2A394 = (pfnPsSetCreateProcessNotifyRoutineEx)MmGetSystemRoutineAddress(&DestinationString);
		if ( g_pfnPsSetCreateProcessNotifyRoutineEx_dword_2A394 )
		{
			pProcessExTsFltFilter = xx_InsertFuncIntoList_211D0(L"ProcessNotifyEx", 0x49u, xx_CreateProcessNotifyEx_21B80);
			if ( pProcessExTsFltFilter )
			{
				if ( !pProcessExTsFltFilter->FuncIndex )
				{
					pProcessExTsFltFilter->Type = 3;
					status_v9 = ((pfnPsSetCreateProcessNotifyRoutineEx)g_pfnPsSetCreateProcessNotifyRoutineEx_dword_2A394)((PCREATE_PROCESS_NOTIFY_ROUTINE_EX)xx_CreateProcessNotifyEx_21B80, FALSE);
					if ( status_v9 >= 0 )
					{
						pProcessExTsFltFilter->FuncIndex = 1;
					}
				}
			}
		}
	}

	pThreadTsFltFilter = g_ThreadNotifyInfo_dword_282C4;
	if ( g_ThreadNotifyInfo_dword_282C4 )
	{
		if ( !pThreadTsFltFilter->IsHook )
		{
			pThreadTsFltFilter->Type = 3;
			status_v9 = PsSetCreateThreadNotifyRoutine((PCREATE_THREAD_NOTIFY_ROUTINE)xx_CreateThreadNotifyRoutine_21700);
			if ( !status_v9 )
			{
				pThreadTsFltFilter->IsHook = TRUE;
			}
		}
	}
	else if ( (PCHAR)xx_CreateThreadNotifyRoutine_21700 )
	{
		pThreadTsFltFilter = (PTsFlt_FILTER)ExAllocatePoolWithTag(NonPagedPool, 0x4F8u, 'THOP');
		if ( pThreadTsFltFilter )
		{
			memset(pThreadTsFltFilter, 0, 0x4F8u);
			pThreadTsFltFilter->FuncName = L"ThreadNotify";
			pThreadTsFltFilter->CurTsFltIndex = 0x35;
			pThreadTsFltFilter->ProxyFunc = xx_CreateThreadNotifyRoutine_21700;
			pThreadTsFltFilter->FuncIndex = -1;
			pThreadTsFltFilter->IsHook = FALSE;
			pThreadTsFltFilter->Flag1 = 1;
			pThreadTsFltFilter->Flag2 = 0;
			KeInitializeEvent((PRKEVENT)(&pThreadTsFltFilter->Kevent), SynchronizationEvent, 0);
			g_ThreadNotifyInfo_dword_282C4 = pThreadTsFltFilter;

			pThreadTsFltFilter->Type = 3;
			status_v9 = PsSetCreateThreadNotifyRoutine((PCREATE_THREAD_NOTIFY_ROUTINE)xx_CreateThreadNotifyRoutine_21700);
			if ( !status_v9 )
			{
				pThreadTsFltFilter->IsHook = TRUE;
			}
		}
	}

	pLoadImageTsFltFilter = g_ImageNotifyInfo_dword_282C8;
	if ( g_ImageNotifyInfo_dword_282C8 )
	{
		if ( !pLoadImageTsFltFilter->IsHook )
		{
			pLoadImageTsFltFilter->Type = 3;
			status_v9 = PsSetLoadImageNotifyRoutine(xx_LoadImageNotify_21940);
			if ( !status_v9 )
			{
				pLoadImageTsFltFilter->IsHook = TRUE;
			}
		}
	}
	else if ( (PCHAR)xx_LoadImageNotify_21940 )
	{
		pLoadImageTsFltFilter = (PTsFlt_FILTER)ExAllocatePoolWithTag(NonPagedPool, 0x4F8u, 'THOP');
		if ( pLoadImageTsFltFilter )
		{
			memset(pLoadImageTsFltFilter, 0, 0x4F8u);
			pLoadImageTsFltFilter->FuncName = L"ImageNotify";
			pLoadImageTsFltFilter->CurTsFltIndex = 54;
			pLoadImageTsFltFilter->ProxyFunc = xx_LoadImageNotify_21940;
			pLoadImageTsFltFilter->FuncIndex = -1;
			pLoadImageTsFltFilter->IsHook = FALSE;
			pLoadImageTsFltFilter->Flag1 = 1;
			pLoadImageTsFltFilter->Flag2 = 0;
			KeInitializeEvent((PRKEVENT)(&pLoadImageTsFltFilter->Kevent), SynchronizationEvent, 0);
			g_ImageNotifyInfo_dword_282C8 = pLoadImageTsFltFilter;

			pLoadImageTsFltFilter->Type = 3;
			status_v9 = PsSetLoadImageNotifyRoutine(xx_LoadImageNotify_21940);
			if ( !status_v9 )
			{
				pLoadImageTsFltFilter->IsHook = TRUE;
			}
		}
	}

	return status_v9;
}

ULONG xx_EatHookKeAddSystemServiceTable_11960(int a1, unsigned int NtBase_a2, int NewFunctionAddress_a3)
{
	int index_v3 = 0;
	PIMAGE_NT_HEADERS pNtHeader_v4 = NULL;
	USHORT MagicFlag_v5 = 0; 
	PIMAGE_EXPORT_DIRECTORY pExportTable_v6 = NULL;
	int nAddressOfExport_v7 = 0; 
	PULONG pAddressOfNames_v10 = NULL;
	PUSHORT pAddressOfNameOrdinals_v11 = NULL;
	int Number_v12 = 0;
	int index_v13 = 0;
	int ret_v14 = 0;
	USHORT IndexOfAddressOfFunction_v16 = 0;
	PULONG pAddressOfFunctions_v17 = NULL;
	ULONG nFuncAddressOffset_v18 = 0;
	PVOID ppFunctionAddress_v19 = NULL;
	ULONG pFunctionAddress_v20 = 0;
	PMDL pMdl_v21 = NULL;
	ULONG nSizeOfExport_v23 = 0;
	ULONG nOldFunction_v24 = 0;
	PVOID pMdlRetAddress = NULL;

	pNtHeader_v4 = xx_GetNtHeader_115E0(a1, (PIMAGE_DOS_HEADER)NtBase_a2);
	if ( !pNtHeader_v4 )
	{
		return nOldFunction_v24;
	}

	MagicFlag_v5 = pNtHeader_v4->OptionalHeader.Magic;
	if ( MagicFlag_v5 == IMAGE_NT_OPTIONAL_HDR32_MAGIC )
	{
		if ( pNtHeader_v4->OptionalHeader.NumberOfRvaAndSizes > 0u )
		{
			nAddressOfExport_v7 = pNtHeader_v4->OptionalHeader.DataDirectory[0].VirtualAddress;
			if ( nAddressOfExport_v7 )
			{
				if ( NtBase_a2 >= (unsigned int)MmHighestUserAddress
					|| nAddressOfExport_v7 + NtBase_a2 < (unsigned int)MmHighestUserAddress )
				{
					pExportTable_v6 = (PIMAGE_EXPORT_DIRECTORY)(NtBase_a2 + nAddressOfExport_v7);
					nSizeOfExport_v23 = pNtHeader_v4->OptionalHeader.DataDirectory[0].Size;
				}
			}
		}
	}
	else
	{
		if ( MagicFlag_v5 != IMAGE_NT_OPTIONAL_HDR64_MAGIC )
		{
			return nOldFunction_v24;
		}

		if ( pNtHeader_v4->OptionalHeader.NumberOfRvaAndSizes > 0u )
		{
			nAddressOfExport_v7 = pNtHeader_v4->OptionalHeader.DataDirectory[0].VirtualAddress;
			if ( nAddressOfExport_v7 )
			{
				if ( NtBase_a2 >= (unsigned int)MmHighestUserAddress || nAddressOfExport_v7 + NtBase_a2 < (unsigned int)MmHighestUserAddress )
				{
					nSizeOfExport_v23 = pNtHeader_v4->OptionalHeader.DataDirectory[0].Size;
					pExportTable_v6 = (PIMAGE_EXPORT_DIRECTORY)(nAddressOfExport_v7 + NtBase_a2);
				}
			}
		}
	}

	if ( !pExportTable_v6 )
	{
		return nOldFunction_v24;
	}

	pAddressOfNames_v10			= (PULONG)(NtBase_a2 + pExportTable_v6->AddressOfNames);
	pAddressOfNameOrdinals_v11	= (PUSHORT)(NtBase_a2 + pExportTable_v6->AddressOfNameOrdinals);
	Number_v12					= pExportTable_v6->NumberOfNames - 1;
	if ( Number_v12 < 0 )
	{
		return nOldFunction_v24;
	}

	while ( TRUE )
	{
		index_v13 = (Number_v12 + index_v3) >> 1;// 二分法查找
		ret_v14 = _stricmp("KeAddSystemServiceTable", (const char *)(NtBase_a2 + pAddressOfNames_v10[index_v13]));
		if ( ret_v14 < 0 )                          
		{
			Number_v12 = index_v13 - 1;
		}
		else if ( ret_v14 == 0 )                         // 这里其实是等于0
		{
			break;
		}
		else
		{
			index_v3 = index_v13 + 1;
		}

		if ( Number_v12 < index_v3 )
		{
			return nOldFunction_v24;
		}
	}

	if ( Number_v12 < index_v3 )
	{
		return nOldFunction_v24;
	}

	IndexOfAddressOfFunction_v16	= pAddressOfNameOrdinals_v11[index_v13];
	pAddressOfFunctions_v17			= (PULONG)(NtBase_a2 + pExportTable_v6->AddressOfFunctions);
	nFuncAddressOffset_v18			= pAddressOfFunctions_v17[IndexOfAddressOfFunction_v16];
	ppFunctionAddress_v19			= (void *)(&pAddressOfFunctions_v17[IndexOfAddressOfFunction_v16]);
	pFunctionAddress_v20			= NtBase_a2 + nFuncAddressOffset_v18;
	nOldFunction_v24				= pFunctionAddress_v20;

	if ( pFunctionAddress_v20 <= (ULONG)pExportTable_v6 || pFunctionAddress_v20 >= (ULONG)pExportTable_v6 + nSizeOfExport_v23 )
	{
		nSizeOfExport_v23 = 0;
		pMdl_v21 = xx_LockMemory_10A50(ppFunctionAddress_v19, sizeof(PVOID), &pMdlRetAddress);
		if ( pMdl_v21 )
		{
			*(DWORD *)pMdlRetAddress = NewFunctionAddress_a3 - NtBase_a2;
			MmUnlockPages(pMdl_v21);
			IoFreeMdl(pMdl_v21);
			return nOldFunction_v24;
		}
	}
	return 0;
}

int xx_KeAddSystemServiceTable_11B10(ULONG W32pServiceTable_a1, ULONG W32pServiceTableNull_a2, ULONG W32pServiceLimit_a3, ULONG a4, ULONG a5)
{
	SYSTEM_MODULE_INFORMATION_ENTRY Win32SysInfo_v6 = {0};

	if ( !g_W32pServiceTable_dword_28194
		&& xx_GetSysModuleInfo_10720("win32k.sys", &Win32SysInfo_v6) == TRUE
		&& W32pServiceTable_a1 >= (ULONG)Win32SysInfo_v6.Base
		&& W32pServiceTable_a1 <= Win32SysInfo_v6.Size + (ULONG)Win32SysInfo_v6.Base )
	{
		g_Target = g_NtBase_dword_281C0;
		g_W32pServiceTable_dword_28194 = (PULONG)W32pServiceTable_a1;
		g_W32pServiceLimit_dword_28198 = W32pServiceLimit_a3;
		g_Win32kSize_dword_281CC = Win32SysInfo_v6.Size;
		xx_EatHookKeAddSystemServiceTable_11960(Win32SysInfo_v6.Size, (DWORD)g_NtBase_dword_281C0, (int)g_KeAddSystemServiceTable_dword_28184);
	}
	return ((int (__stdcall *)(DWORD, DWORD, DWORD, DWORD, DWORD))g_KeAddSystemServiceTable_dword_28184)(
		W32pServiceTable_a1,
		W32pServiceTableNull_a2,
		W32pServiceLimit_a3,
		a4,
		a5);
}

unsigned int __stdcall xx_HookSsdt_10300(PTsFlt_NOTIFY_INFO pTsFltNotifyInfo_a1)
{
	if ( pTsFltNotifyInfo_a1->OtherModuleFuncFlag[pTsFltNotifyInfo_a1->OtherModuleFuncIndex] == 0xABCDEEEE
		&& g_HookKiSystemFastCallFlag_dword_281E4 != 1
		&& g_HookKiSystemFastCallFlag_dword_281E4 != 3 )
	{
		xx_HookSsdtAndShadowSsdt_20EF0();
	}
	return 0xEEEE0001;
}

NTSTATUS xx_TsFltEatHookKeAddSystemServiceTable_10330(int temp, PTsFlt_NOTIFY_INFO pTsFltNotifyInfo_a1)
{
	if ( !g_W32pServiceTable_dword_28194 && pTsFltNotifyInfo_a1->Parameter[0] == 0x26/**(DWORD *)(pTsFltNotifyInfo_a1 + 8) == 0x26*/ && !g_KeAddSystemServiceTable_dword_28184 )
	{
		g_KeAddSystemServiceTable_dword_28184 = (int (__stdcall *)(DWORD, DWORD, DWORD))xx_EatHookKeAddSystemServiceTable_11960(temp, (DWORD)g_NtBase_dword_281C0, (int)&xx_KeAddSystemServiceTable_11B10);
		if ( g_KeAddSystemServiceTable_dword_28184 )
		{
			pTsFltNotifyInfo_a1->OtherModuleFuncFlag[pTsFltNotifyInfo_a1->OtherModuleFuncIndex] = 0xABCDEEEE;// 这是一个标志
			pTsFltNotifyInfo_a1->OtherModuleFunc[pTsFltNotifyInfo_a1->OtherModuleFuncIndex] = (ULONG)&xx_HookSsdt_10300;
			++pTsFltNotifyInfo_a1->Count;
		}
	}
	return 0xEEEE0001;
}

NTSTATUS xx_InitKeAddSystemServiceTable_21430()
{
	NTSTATUS status;
	PTsFlt_FILTER pTsFltFilter_v1;
	PVOID pFunction_v2;
	ULONG i_v3; 

	status = STATUS_UNSUCCESSFUL;
	if ( (PCHAR)xx_TsFltEatHookKeAddSystemServiceTable_10330 )
	{
		pTsFltFilter_v1 = g_EatHookKeAddSystemServiceTable_dword_28238;
		if ( g_EatHookKeAddSystemServiceTable_dword_28238 )
		{
			if ( g_EatHookKeAddSystemServiceTable_dword_28238->IsHook == TRUE )
			{
				pFunction_v2 = g_EatHookKeAddSystemServiceTable_dword_28238->ModuleInterface[0].FuncAddress;//v2 = g_EatHookKeAddSystemServiceTable_dword_28238 + 0x130;
				if ( pFunction_v2 )
				{
					i_v3 = 0;
					while ( pFunction_v2 )
					{
						++i_v3;
						pFunction_v2 = (PVOID)((PCHAR)pFunction_v2 + sizeof(TsFlt_MODULE_INTERFACE));
						if ( i_v3 >= TS_MAX_OTHER_MODULE_FUNC )
						{
							return status;
						}
					}
					g_EatHookKeAddSystemServiceTable_dword_28238->ModuleInterface[i_v3].Type = 0;//*(DWORD *)(v4 + g_EatHookKeAddSystemServiceTable_dword_28238 + 0xF8) = 0;
					pFunction_v2 = g_EatHookKeAddSystemServiceTable_dword_28238->ModuleInterface[i_v3].FuncAddress;//pFunction_v2 = v4 + pTsFltFilter_v1 + 0x130;
				}
				else
				{
					g_EatHookKeAddSystemServiceTable_dword_28238->ModuleInterface[0].Type = 0;//*(DWORD *)(g_EatHookKeAddSystemServiceTable_dword_28238 + 0xF8) = 0;
				}
				InterlockedExchange((volatile LONG *)pFunction_v2, (LONG)xx_TsFltEatHookKeAddSystemServiceTable_10330);
				InterlockedIncrement((volatile LONG *)(&pTsFltFilter_v1->OtherModuleFuncCount));

				status = 0;
			}
		}
	}
	return status;
}

NTSTATUS xx_InitSetRegitryValue_10390()
{
	int Index_v0 = 0;
	PTsFlt_FILTER pTsFltFilter_v2;
	PTsFlt_FILTER pTsFltFilter_v3;
	int Data;
	UNICODE_STRING DestinationString;

	do
	{
		pTsFltFilter_v2 = g_FuncFilterInfo_dword_281F0[Index_v0];
		if ( pTsFltFilter_v2 && pTsFltFilter_v2->Type )
		{
			g_Flag_dword_281EC = -1;
			if ( pTsFltFilter_v2->IsHook != TRUE )
				g_Flag_dword_281EC = -1;
		}

		pTsFltFilter_v3 = g_FuncFilterInfo_dword_281F0[Index_v0 + 1];
		if ( pTsFltFilter_v3 && pTsFltFilter_v3->Type )
		{
			g_Flag_dword_281EC = -1;
			if ( pTsFltFilter_v3->IsHook != TRUE )
				g_Flag_dword_281EC = -1;
		}
		Index_v0 += 2;
	}
	while ( (unsigned int)Index_v0 < arraysize(g_FuncFilterInfo_dword_281F0) );

	Data = 2;
	RtlInitUnicodeString(&DestinationString, L"LastErrorCode");
	ZwSetValueKey(g_KeyHandle, &DestinationString, 0, 4u, &g_SsdtType_dword_281DC, sizeof(g_SsdtType_dword_281DC));
	RtlInitUnicodeString(&DestinationString, L"InitState");
	ZwSetValueKey(g_KeyHandle, &DestinationString, 0, 4u, &g_HookLen8_dword_281E0, sizeof(g_HookLen8_dword_281E0));
	RtlInitUnicodeString(&DestinationString, L"serHookType");
	ZwSetValueKey(g_KeyHandle, &DestinationString, 0, 4u, &g_HookKiSystemFastCallFlag_dword_281E4, sizeof(g_HookKiSystemFastCallFlag_dword_281E4));
	RtlInitUnicodeString(&DestinationString, L"OsVer");
	ZwSetValueKey(g_KeyHandle, &DestinationString, 0, 4u, &g_SystemVersion_dword_281E8, sizeof(g_SystemVersion_dword_281E8));
	RtlInitUnicodeString(&DestinationString, L"HookErrorIndex");
	ZwSetValueKey(g_KeyHandle, &DestinationString, 0, 4u, &g_Flag_dword_281EC, sizeof(g_Flag_dword_281EC));
	RtlInitUnicodeString(&DestinationString, L"IsBsod");
	return ZwSetValueKey(g_KeyHandle, &DestinationString, 0, 4u, &Data, sizeof(Data));
}

NTSTATUS xx_AddRoutineIntoWorkItem_11330()
{
	NTSTATUS result = STATUS_SUCCESS;
	PWORK_QUEUE_ITEM pWorkQueueItem = NULL;

	if ( !g_pTsFltPnpagedLoolasideList_28180)
	{
		pWorkQueueItem = (PWORK_QUEUE_ITEM)ExAllocatePoolWithTag(NonPagedPool, sizeof(WORK_QUEUE_ITEM), 'TSFL');
		if ( pWorkQueueItem )
		{
			ExInitializeWorkItem(pWorkQueueItem, (PWORKER_THREAD_ROUTINE)xx_WriteTsDbgLog_112A0, pWorkQueueItem);
			ExQueueWorkItem((PWORK_QUEUE_ITEM)pWorkQueueItem, (WORK_QUEUE_TYPE)0);
		}
		result = STATUS_UNSUCCESSFUL;
	}
	return result;
}

NTSTATUS __stdcall xx_KeUserModeCallback_1DFF0(int a1, int a2, int a3, int a4, int a5)
{
	PTsFlt_FILTER  pTsFltFilter_v5 = NULL; 
	PTsFlt_NOTIFY_INFO pTsFltNotifyInfo_v6 = NULL;
	typedef int (__stdcall *pfn_v8)(DWORD, DWORD, DWORD, DWORD, DWORD);
	
	NTSTATUS status_v13 = STATUS_ACCESS_DENIED;
	ULONGLONG FastMutex = 0;

	pTsFltFilter_v5 = g_KeUserModeCallbackInfo;
	pTsFltNotifyInfo_v6 = (PTsFlt_NOTIFY_INFO)ExAllocateFromNPagedLookasideList(&g_Lookaside);
	if (pTsFltNotifyInfo_v6)
	{
		memset((void *)pTsFltNotifyInfo_v6, 0, 0xCCu);
	}

	if ( g_FilterFlag_dword_281D4 == 1 )
	{
		FastMutex = KeQueryInterruptTime();
	}
	if ( pTsFltNotifyInfo_v6 )
	{
		pTsFltNotifyInfo_v6->Parameter[0] = a1;
		pTsFltNotifyInfo_v6->Parameter[1] = a2;
		pTsFltNotifyInfo_v6->Parameter[2] = a3;
		pTsFltNotifyInfo_v6->Parameter[3] = a4;
		pTsFltNotifyInfo_v6->Parameter[4] = a5;
		pTsFltNotifyInfo_v6->ParameterNumber = 5;
		pTsFltNotifyInfo_v6->ProxyFunction = pTsFltFilter_v5->SaveFunc;
		pTsFltNotifyInfo_v6->IndexFunction = 51;
		InterlockedIncrement((volatile LONG *)(&pTsFltFilter_v5->Lock1));
		status_v13 = xx_Printf_20F90(pTsFltNotifyInfo_v6, pTsFltFilter_v5);
		InterlockedDecrement((volatile LONG *)(&pTsFltFilter_v5->Lock1));
		if ( status_v13 != 0xEEEE0004 )
		{
			if ( status_v13 == 0xEEEE0005 )
			{
				status_v13 = pTsFltNotifyInfo_v6->FunctionRetValue;
			}
			else
			{
				if ( pTsFltFilter_v5->SaveFunc )
				{
					status_v13 = ((pfn_v8)pTsFltFilter_v5->SaveFunc)(
						pTsFltNotifyInfo_v6->Parameter[0],
						pTsFltNotifyInfo_v6->Parameter[1],
						pTsFltNotifyInfo_v6->Parameter[2],
						pTsFltNotifyInfo_v6->Parameter[3],
						pTsFltNotifyInfo_v6->Parameter[4]);

					pTsFltNotifyInfo_v6->FunctionRetValue = status_v13;

					InterlockedIncrement((volatile LONG *)(&pTsFltFilter_v5->Lock2));
					status_v13 = xx_TsLockInfo_21110(pTsFltNotifyInfo_v6);
					InterlockedDecrement((volatile LONG *)(&pTsFltFilter_v5->Lock2));
					if ( status_v13 == 0xEEEE0005 )
					{
						status_v13 = pTsFltNotifyInfo_v6->FunctionRetValue;
					}
				}
			}
		}
	}
	if ( g_KeUserModeCallbackInfo->IsHook && FastMutex )
	{
		if ( g_FilterFlag_dword_281D4 )
		{
			//这里没逆。
			//sub_11810(&g_KeUserModeCallbackInfo->Reserve4, (PFAST_MUTEX)FastMutex, HIDWORD(FastMutex));
		}
	}

	if ( pTsFltNotifyInfo_v6 )
	{
		ExFreeToNPagedLookasideList(&g_Lookaside, pTsFltNotifyInfo_v6);
		return status_v13;
	}

	if ( !pTsFltFilter_v5->SaveFunc )
		return status_v13;

	return ((pfn_v8)pTsFltFilter_v5->SaveFunc)(a1, a2, a3, a4, a5);
}

PVOID xx_ReloadModuleByName_10C90(PUNICODE_STRING pFileName_a1)
{
	PVOID BaseAddress;
	HANDLE SectionHandle;
	HANDLE FileHandle;
	ULONG_PTR ViewSize;
	IO_STATUS_BLOCK IoStatusBlock; 
	OBJECT_ATTRIBUTES ObjectAttributes;

	ViewSize = 0;
	SectionHandle = 0;
	FileHandle = 0;
	BaseAddress = (PVOID)0x5000000;

	InitializeObjectAttributes(&ObjectAttributes, pFileName_a1, 576, 0, 0);
	if ( ZwOpenFile(&FileHandle, GENERIC_READ, &ObjectAttributes, &IoStatusBlock, FILE_SHARE_READ, FILE_SYNCHRONOUS_IO_NONALERT) >= 0 )
	{
		ObjectAttributes.ObjectName = NULL;
		if ( ZwCreateSection(&SectionHandle, SECTION_MAP_EXECUTE, &ObjectAttributes, 0, PAGE_EXECUTE, 0x1000000/*SEC_IMAGE*/, FileHandle) >= 0 )
		{
			if (ZwMapViewOfSection(SectionHandle, (HANDLE)(-1)/*NtCurrentProcess*/, &BaseAddress, 0, 0, 0, &ViewSize, ViewUnmap, 0, PAGE_EXECUTE) < 0)
			{
				BaseAddress = 0;
				ZwMapViewOfSection(SectionHandle, (HANDLE)(-1)/*NtCurrentProcess*/, &BaseAddress, 0, 0, 0, &ViewSize, ViewUnmap, 0, PAGE_EXECUTE);
			}
		}
	}
	if ( SectionHandle )
	{
		ZwClose(SectionHandle);
	}
	if ( FileHandle )
	{
		ZwClose(FileHandle);
	}
	return BaseAddress;
}

PVOID __stdcall xx_GetKeUserModeCallback_11DE0(ULONG pBase_a1)
{
	ULONG pBase_a2; // ebp@1
	PVOID result; // eax@2
	int v3 = 0; // ecx@3
	PIMAGE_NT_HEADERS pNtHeader_v3; // eax@3
	__int16 Magic_v4; // cx@4
	PIMAGE_IMPORT_DESCRIPTOR pImportDirectoryVirtualAddress_v5; // eax@6
	ULONG uImportDirectoryVirtualAddress_v6 = 0;
	ULONG uExportDirectorySize_v7 = 0;
	ULONG uExportDirectorySize_v12 = 0;
	PVOID pMmHighestUserAddress_v7; // ecx@8
	int pName_v9; // eax@19
	int uFirstThunk_v10; // esi@23
	int uFunction_v11; // eax@23
	PIMAGE_THUNK_DATA pFirstThunk_v12; // esi@23
	int Index_v13; // edi@23
	bool i; // sf@23
	bool v15; // zf@25
	const char *v16; // eax@25
	PVOID KeUserModeCallback_v17; // [sp+14h] [bp-14h]@3
	UNICODE_STRING SystemRoutineName; // [sp+18h] [bp-10h]@1
	STRING DestinationString; // [sp+20h] [bp-8h]@1
	int pBase_a1a; // [sp+2Ch] [bp+4h]@1

	pBase_a2 = pBase_a1;
	pBase_a1a = 0;
	RtlInitAnsiString(&DestinationString, "KeUserModeCallback");
	if ( RtlAnsiStringToUnicodeString(&SystemRoutineName, &DestinationString, TRUE) )
		return 0;

	KeUserModeCallback_v17 = MmGetSystemRoutineAddress(&SystemRoutineName);
	RtlFreeUnicodeString(&SystemRoutineName);

	pNtHeader_v3 = xx_GetNtHeader_115E0(v3, (PIMAGE_DOS_HEADER)pBase_a2);
	if ( !pNtHeader_v3 )
		goto LABEL_33;

	Magic_v4 = pNtHeader_v3->OptionalHeader.Magic;
	if ( Magic_v4 == IMAGE_NT_OPTIONAL_HDR32_MAGIC )                            // 32bit程序
	{
		if ( pNtHeader_v3->OptionalHeader.NumberOfRvaAndSizes <= 1 )
		{
			pImportDirectoryVirtualAddress_v5 = 0;
			goto LABEL_18;
		}
		uImportDirectoryVirtualAddress_v6 = pNtHeader_v3->OptionalHeader.DataDirectory[1].VirtualAddress;
		if ( !uImportDirectoryVirtualAddress_v6 )
			goto LABEL_18;

		pMmHighestUserAddress_v7 = MmHighestUserAddress;
	}
	else                                          // 64bit程序
	{
		if ( Magic_v4 != IMAGE_NT_OPTIONAL_HDR64_MAGIC )
			goto LABEL_33;
		if ( pNtHeader_v3->OptionalHeader.NumberOfRvaAndSizes <= 1 )
		{
			pImportDirectoryVirtualAddress_v5 = 0;
			goto LABEL_18;
		}
		uImportDirectoryVirtualAddress_v6 = pNtHeader_v3->OptionalHeader.DataDirectory[1].VirtualAddress;
		if ( !uImportDirectoryVirtualAddress_v6 )
			goto LABEL_18;

		pMmHighestUserAddress_v7 = MmHighestUserAddress;
	}

	if ( pBase_a2 >= (unsigned int)pMmHighestUserAddress_v7 || pBase_a2 + uImportDirectoryVirtualAddress_v6 < (unsigned int)pMmHighestUserAddress_v7 )
	{
		pImportDirectoryVirtualAddress_v5 = (PIMAGE_IMPORT_DESCRIPTOR)(pBase_a2 + uImportDirectoryVirtualAddress_v6);
	}
	else
	{
		pImportDirectoryVirtualAddress_v5 = NULL;
	}

LABEL_18:
	if ( pImportDirectoryVirtualAddress_v5 )
	{
		/*pName_v9 = pImportDirectoryVirtualAddress_v5->Name;
		if ( pName_v9)
		{
			do
			{
				if ( !pImportDirectoryVirtualAddress_v5->FirstThunk )
					goto LABEL_33;

				if ( !stricmp("ntoskrnl.exe", (const char *)(pBase_a2 + pName_v9)) )
				{
					if ( pImportDirectoryVirtualAddress_v5->OriginalFirstThunk )
					{
						pFirstThunk_v12 = (PIMAGE_THUNK_DATA)(pBase_a2 + pImportDirectoryVirtualAddress_v5->FirstThunk);
						uFunction_v11 = pFirstThunk_v12->u1.Function;
						Index_v13 = 0;
						for ( i = (signed int)uFunction_v11 < 0; uFunction_v11; i = (signed int)uFunction_v11 < 0 )
						{
							if ( i )
							{
								if ( (ULONG)KeUserModeCallback_v17 == uFunction_v11 )
								{
									pBase_a1a = pFirstThunk_v12->u1.AddressOfData[Index_v13];
									goto LABEL_33;
								}
							}
							else
							{
								v15 = *((BYTE *)uFunction_v11 + pBase_a2 + 2) == 0x4B;
								v16 = (char *)uFunction_v11 + pBase_a2 + 2;
								if ( v15 && !stricmp(v16, "KeUserModeCallback") )
									return (PVOID)*(DWORD *)(pImportDirectoryVirtualAddress_v5 + 16) + 4 * Index_v13;
							}
							uFunction_v11 = *(void **)(pFirstThunk_v12 + 4);
							pFirstThunk_v12 += 4;
							++Index_v13;
						}
					}
				}
				pImportDirectoryVirtualAddress_v5 = (PIMAGE_IMPORT_DESCRIPTOR)((PCHAR)pImportDirectoryVirtualAddress_v5 + sizeof(pImportDirectoryVirtualAddress_v5));
				pName_v9 = pImportDirectoryVirtualAddress_v5->Name;
			}
			while (pImportDirectoryVirtualAddress_v5->Name );
			result = 0;
		}*/
	}
	else
	{
LABEL_33:
		result = (PVOID)pBase_a1a;
	}
	return result;
}

LONG xx_IatHookKeUserModeCallback_11F80(PVOID pNtBase_a1, PVOID Target, PVOID pNewFunc)
{
	LONG *pTargetFunc_v3 = NULL;
	LONG oldAddr_v4 = 0; 
	PVOID pKeUserModeCallback_v5 = NULL;
	HANDLE CurPid_v6 = NULL;
	HANDLE smssId_v7= NULL;
	PRKAPC_STATE pApcState_v8 = NULL;
	PMDL pMdl_v9 = NULL;

	pTargetFunc_v3 = (LONG*)Target;
	oldAddr_v4 = 0;
	Target = 0;
	
	CurPid_v6 = PsGetCurrentProcessId();
	smssId_v7 = (HANDLE)xx_GetProcessIdByProcessName_10B40(L"smss.exe");

	pKeUserModeCallback_v5 = xx_GetKeUserModeCallback_11DE0((ULONG)pNtBase_a1);
	if ( !pKeUserModeCallback_v5 )
	{
		return oldAddr_v4;
	}

	if ( g_CsrssPid_dword_281D0 )
	{                                             // 下面的IAT hook KeUserModeCallback
		pApcState_v8 = xx_TsAttachProcessByPid_10BF0((void *)g_CsrssPid_dword_281D0);
		if ( pApcState_v8 )
		{
			pMdl_v9 = xx_LockMemory_10A50((char *)pTargetFunc_v3 + (ULONG)pKeUserModeCallback_v5, 0x10u, &Target);
			if ( pMdl_v9 )
			{
				oldAddr_v4 = InterlockedExchange((LONG*)&Target, (LONG)pNewFunc);
				MmUnlockPages(pMdl_v9);
				IoFreeMdl(pMdl_v9);
			}

			if ( pApcState_v8 != (PVOID)0xEEEEDDDD )
			{
				KeUnstackDetachProcess(pApcState_v8);
				ObfDereferenceObject(pApcState_v8->Process);
				ExFreePool(pApcState_v8);
			}
		}
		return oldAddr_v4;
	}

	if ( smssId_v7 != CurPid_v6 )
	{
		return oldAddr_v4;
	}

	// 当前进程是smss的话。直接开始iat hook，这是在上面失败的方案之下的第二个方案
	pMdl_v9 = xx_LockMemory_10A50((char *)pTargetFunc_v3 + (ULONG)pKeUserModeCallback_v5, 0x10u, &Target);
	if ( !pMdl_v9 )
		return oldAddr_v4;

	oldAddr_v4 = InterlockedExchange((LONG*)&Target, (LONG)pNewFunc);
	MmUnlockPages(pMdl_v9);
	IoFreeMdl(pMdl_v9);
	return oldAddr_v4;
}

NTSTATUS xx_HookKeUserModeCallback_12060()
{
	NTSTATUS status_v0 = STATUS_UNSUCCESSFUL;
	PTsFlt_FILTER pTsFltFilter_v1 = NULL; 
	PTsFlt_FILTER pBuffer_v2 = NULL; 
	PVOID pWin32_v3; 
	PVOID pOldAddress_v5;
	UNICODE_STRING DestinationString; 

	if ( g_Target )
	{
		pTsFltFilter_v1 = g_KeUserModeCallbackInfo;
		if ( g_KeUserModeCallbackInfo == NULL )
		{
			if ( (PCHAR)xx_KeUserModeCallback_1DFF0 )
			{
				pBuffer_v2 = (PTsFlt_FILTER)ExAllocatePoolWithTag(NonPagedPool, sizeof(TsFlt_FILTER), 'THOP');// NonPagedPool
				pTsFltFilter_v1 = (PTsFlt_FILTER)pBuffer_v2;
				if ( !pBuffer_v2 )
					return status_v0;

				memset(pBuffer_v2, 0, sizeof(TsFlt_FILTER));
				pTsFltFilter_v1->FuncName = L"KeUserModeCallback";
				pTsFltFilter_v1->CurTsFltIndex = 0x33;
				pTsFltFilter_v1->ProxyFunc = xx_KeUserModeCallback_1DFF0;
				pTsFltFilter_v1->FuncIndex = -1;
				pTsFltFilter_v1->IsHook = FALSE;
				pTsFltFilter_v1->Flag1 = 1;
				pTsFltFilter_v1->Flag2 = 0;
				KeInitializeEvent((PRKEVENT)(&pTsFltFilter_v1->Kevent), SynchronizationEvent, 0);
				g_KeUserModeCallbackInfo = pTsFltFilter_v1;
			}
			if ( pTsFltFilter_v1 == NULL )
				return status_v0;

			pTsFltFilter_v1->Type = 3;
		}

		RtlInitUnicodeString(&DestinationString, L"\\SystemRoot\\System32\\Win32k.sys");
		pWin32_v3 = xx_ReloadModuleByName_10C90(&DestinationString);
		if ( pWin32_v3 )
		{
			if ( !pTsFltFilter_v1->IsHook )
			{
				pTsFltFilter_v1->SaveFunc = NULL;
				pOldAddress_v5 = (PVOID)xx_IatHookKeUserModeCallback_11F80(pWin32_v3, g_Target, xx_KeUserModeCallback_1DFF0);
				pTsFltFilter_v1->SaveFunc = (PVOID)pOldAddress_v5;

				if ( pOldAddress_v5 )
				{
					pTsFltFilter_v1->IsHook = TRUE;
					status_v0 = STATUS_SUCCESS;
				}
			}
			ZwUnmapViewOfSection(NtCurrentProcess(), pWin32_v3);
		}
	}
	return status_v0;
}

UINT xx_Init_10630()
{
	int Flag_v0;
	TsFlt_OS_VERSION Version_v1;
	BOOLEAN isTrue = FALSE;

	Flag_v0 = 0;
	xx_InitTsFltMgrRegistry_10540();
	Version_v1 = xx_GetVersion_113C0();
	if ( Version_v1 )
	{
		if ( (unsigned int)*(PULONG)InitSafeBootMode <= 0 )
		{
			isTrue = xx_CheckTsFltMgrDws_11260();// 查询注册表检测是否开启dws，
			if ( !(BYTE)isTrue  )// 开启的话就启动dws
			{
				isTrue = xx_CheckSysMonDwsBak_23285(1);// 启动dws
				if ( !(BYTE)isTrue  )
				{
					xx_InitKiSystemServiceHookAddress_20B00();
					xx_InitFunctionFilter_20600();

					if ( xx_InitKiSystemFastCall_124A0() )
					{
						xx_HookSsdtAndShadowSsdt_20EF0();   // 假如hook KiSystemFastCall失败，那么就去hook ssdt表
					}

					xx_InitNotifyRoutine_21DC0();
					if ( g_CsrssPid_dword_281D0 )
						Flag_v0 = 1;

					if ( g_Target )
						++Flag_v0;

					if ( Flag_v0 == 2 )
					{
						xx_AddRoutineIntoWorkItem_11330();
						xx_HookKeUserModeCallback_12060();
						xx_InitSetRegitryValue_10390();
					}
					else
					{
						if ( !Flag_v0 )
						{
							xx_InitKeAddSystemServiceTable_21430();
						}
						xx_InitSetRegitryValue_10390();
					}
				}
			}
		}
	}
	return Version_v1;
}