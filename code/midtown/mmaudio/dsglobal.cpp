/*
    Open1560 - An Open Source Re-Implementation of Midtown Madness 1 Beta
    Copyright (C) 2020 Brick

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

define_dummy_symbol(mmaudio_dsglobal);

#include "dsglobal.h"

DSGlobal::DSGlobal()
{
    unimplemented();
}

DSGlobal::~DSGlobal()
{
    unimplemented();
}

u32 DSGlobal::AlwaysEAX(u32 arg1)
{
    return stub<thiscall_t<u32, DSGlobal*, u32>>(0x4F0AD0, this, arg1);
}

u8 DSGlobal::CheckCDFile(char* arg1)
{
    return stub<thiscall_t<u8, DSGlobal*, char*>>(0x4F08E0, this, arg1);
}

void DSGlobal::ClearDSDeviceList()
{
    return stub<thiscall_t<void, DSGlobal*>>(0x4EFDD0, this);
}

void DSGlobal::ConvertTo8Bit(i32 arg1)
{
    return stub<thiscall_t<void, DSGlobal*, i32>>(0x4F0340, this, arg1);
}

u32 DSGlobal::DSound3DEnabled()
{
    return stub<thiscall_t<u32, DSGlobal*>>(0x4F0B00, this);
}

void DSGlobal::DeInit(i16 arg1, i16 arg2)
{
    return stub<thiscall_t<void, DSGlobal*, i16, i16>>(0x4EF400, this, arg1, arg2);
}

void DSGlobal::DeallocateADFRecord(i32 arg1)
{
    return stub<thiscall_t<void, DSGlobal*, i32>>(0x4EF370, this, arg1);
}

void DSGlobal::DeallocateCityADF()
{
    return stub<thiscall_t<void, DSGlobal*>>(0x4EF340, this);
}

void DSGlobal::DeallocateUIADF()
{
    return stub<thiscall_t<void, DSGlobal*>>(0x4EF2E0, this);
}

void DSGlobal::DisableEAXFlag()
{
    return stub<thiscall_t<void, DSGlobal*>>(0x4F0B10, this);
}

u32 DSGlobal::EAXEnabled()
{
    return stub<thiscall_t<u32, DSGlobal*>>(0x4F0AB0, this);
}

i32 DSGlobal::EnumDSDevices()
{
    return stub<thiscall_t<i32, DSGlobal*>>(0x4EFBB0, this);
}

char** DSGlobal::GetDeviceNames()
{
    return stub<thiscall_t<char**, DSGlobal*>>(0x4F09C0, this);
}

u32 DSGlobal::GetNum3DHallBufs()
{
    return stub<thiscall_t<u32, DSGlobal*>>(0x4F09F0, this);
}

i32 DSGlobal::Init(u32 arg1, u8 arg2, u32* arg3, char* arg4, i16 arg5, i16 arg6)
{
    return stub<thiscall_t<i32, DSGlobal*, u32, u8, u32*, char*, i16, i16>>(
        0x4EF550, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

i32 DSGlobal::Init3DListener(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<i32, DSGlobal*, f32, f32, f32, f32, f32>>(0x4EF770, this, arg1, arg2, arg3, arg4, arg5);
}

i32 DSGlobal::InitCityADF(char* arg1, i32 arg2, u32 arg3)
{
    return stub<thiscall_t<i32, DSGlobal*, char*, i32, u32>>(0x4F01C0, this, arg1, arg2, arg3);
}

i32 DSGlobal::InitPrimarySoundBuffer(u32 arg1, u8 arg2, char* arg3)
{
    return stub<thiscall_t<i32, DSGlobal*, u32, u8, char*>>(0x4EFBD0, this, arg1, arg2, arg3);
}

i32 DSGlobal::InitUIADF(char* arg1, i32 arg2, u32 arg3)
{
    return stub<thiscall_t<i32, DSGlobal*, char*, i32, u32>>(0x4F0280, this, arg1, arg2, arg3);
}

u32 DSGlobal::IsAlwaysEAX()
{
    return stub<thiscall_t<u32, DSGlobal*>>(0x4F0AC0, this);
}

i32 DSGlobal::LoadCityADF(char* arg1, i32 arg2, u32 arg3)
{
    return stub<thiscall_t<i32, DSGlobal*, char*, i32, u32>>(0x4EFFB0, this, arg1, arg2, arg3);
}

i32 DSGlobal::LoadUIADF(char* arg1)
{
    return stub<thiscall_t<i32, DSGlobal*, char*>>(0x4EFE10, this, arg1);
}

void DSGlobal::ScanAvailableDSFormats()
{
    return stub<thiscall_t<void, DSGlobal*>>(0x4F0670, this);
}

void DSGlobal::SetBitDepth(i32 arg1)
{
    return stub<thiscall_t<void, DSGlobal*, i32>>(0x4F0990, this, arg1);
}

void DSGlobal::SetDeviceRating(struct tag_dsdevdesc* arg1)
{
    return stub<thiscall_t<void, DSGlobal*, struct tag_dsdevdesc*>>(0x4EFA50, this, arg1);
}

void DSGlobal::SetPrimaryBufferFormat(u32 arg1, u8 arg2)
{
    return stub<thiscall_t<void, DSGlobal*, u32, u8>>(0x4F0580, this, arg1, arg2);
}

char* DSGlobal::TranslateDSError(i32 arg1)
{
    return stub<thiscall_t<char*, DSGlobal*, i32>>(0x4F0730, this, arg1);
}

u32 const DSGlobal::GetCDMusicOnMask()
{
    return stub<cdecl_t<u32 const>>(0x4F0A90);
}

u32 const DSGlobal::GetCommentaryOnMask()
{
    return stub<cdecl_t<u32 const>>(0x4F0A80);
}

u32 const DSGlobal::GetDSound3DMask()
{
    return stub<cdecl_t<u32 const>>(0x4F0A60);
}

u32 const DSGlobal::GetEchoOnMask()
{
    return stub<cdecl_t<u32 const>>(0x4F0A50);
}

u32 const DSGlobal::GetHiResMask()
{
    return stub<cdecl_t<u32 const>>(0x4F0A30);
}

u32 const DSGlobal::GetHiSampleSizeMask()
{
    return stub<cdecl_t<u32 const>>(0x4F0A40);
}

u32 const DSGlobal::GetSoundFXOnMask()
{
    return stub<cdecl_t<u32 const>>(0x4F0A70);
}

u32 const DSGlobal::GetStereoOnMask()
{
    return stub<cdecl_t<u32 const>>(0x4F0A20);
}

u32 const DSGlobal::GetUsingEAXMask()
{
    return stub<cdecl_t<u32 const>>(0x4F0AA0);
}

i32 __stdcall DSEnumProc(struct _GUID* arg1, char* arg2, char* arg3, void* arg4)
{
    return stub<stdcall_t<i32, struct _GUID*, char*, char*, void*>>(0x4EF8B0, arg1, arg2, arg3, arg4);
}

i32 FormatCodeToWFX(u32 arg1, struct tWAVEFORMATEX* arg2)
{
    return stub<cdecl_t<i32, u32, struct tWAVEFORMATEX*>>(0x4F04D0, arg1, arg2);
}

i32 IsDSDeviceInList(struct _GUID* arg1)
{
    return stub<cdecl_t<i32, struct _GUID*>>(0x4EF850, arg1);
}

void UpperCase(char* arg1)
{
    return stub<cdecl_t<void, char*>>(0x4EF800, arg1);
}
