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
    return stub<thiscall_t<u32, DSGlobal*, u32>>(0xF0AD0_Offset, this, arg1);
}

u8 DSGlobal::CheckCDFile(char* arg1)
{
    return stub<thiscall_t<u8, DSGlobal*, char*>>(0xF08E0_Offset, this, arg1);
}

void DSGlobal::ClearDSDeviceList()
{
    return stub<thiscall_t<void, DSGlobal*>>(0xEFDD0_Offset, this);
}

void DSGlobal::ConvertTo8Bit(i32 arg1)
{
    return stub<thiscall_t<void, DSGlobal*, i32>>(0xF0340_Offset, this, arg1);
}

u32 DSGlobal::DSound3DEnabled()
{
    return stub<thiscall_t<u32, DSGlobal*>>(0xF0B00_Offset, this);
}

void DSGlobal::DeInit(i16 arg1, i16 arg2)
{
    return stub<thiscall_t<void, DSGlobal*, i16, i16>>(0xEF400_Offset, this, arg1, arg2);
}

void DSGlobal::DeallocateADFRecord(i32 arg1)
{
    return stub<thiscall_t<void, DSGlobal*, i32>>(0xEF370_Offset, this, arg1);
}

void DSGlobal::DeallocateCityADF()
{
    return stub<thiscall_t<void, DSGlobal*>>(0xEF340_Offset, this);
}

void DSGlobal::DeallocateUIADF()
{
    return stub<thiscall_t<void, DSGlobal*>>(0xEF2E0_Offset, this);
}

void DSGlobal::DisableEAXFlag()
{
    return stub<thiscall_t<void, DSGlobal*>>(0xF0B10_Offset, this);
}

u32 DSGlobal::EAXEnabled()
{
    return stub<thiscall_t<u32, DSGlobal*>>(0xF0AB0_Offset, this);
}

i32 DSGlobal::EnumDSDevices()
{
    return stub<thiscall_t<i32, DSGlobal*>>(0xEFBB0_Offset, this);
}

char** DSGlobal::GetDeviceNames()
{
    return stub<thiscall_t<char**, DSGlobal*>>(0xF09C0_Offset, this);
}

u32 DSGlobal::GetNum3DHallBufs()
{
    return stub<thiscall_t<u32, DSGlobal*>>(0xF09F0_Offset, this);
}

i32 DSGlobal::Init(u32 arg1, u8 arg2, u32* arg3, char* arg4, i16 arg5, i16 arg6)
{
    return stub<thiscall_t<i32, DSGlobal*, u32, u8, u32*, char*, i16, i16>>(
        0xEF550_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

i32 DSGlobal::Init3DListener(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<i32, DSGlobal*, f32, f32, f32, f32, f32>>(
        0xEF770_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

i32 DSGlobal::InitCityADF(char* arg1, i32 arg2, u32 arg3)
{
    return stub<thiscall_t<i32, DSGlobal*, char*, i32, u32>>(0xF01C0_Offset, this, arg1, arg2, arg3);
}

i32 DSGlobal::InitPrimarySoundBuffer(u32 arg1, u8 arg2, char* arg3)
{
    return stub<thiscall_t<i32, DSGlobal*, u32, u8, char*>>(0xEFBD0_Offset, this, arg1, arg2, arg3);
}

i32 DSGlobal::InitUIADF(char* arg1, i32 arg2, u32 arg3)
{
    return stub<thiscall_t<i32, DSGlobal*, char*, i32, u32>>(0xF0280_Offset, this, arg1, arg2, arg3);
}

u32 DSGlobal::IsAlwaysEAX()
{
    return stub<thiscall_t<u32, DSGlobal*>>(0xF0AC0_Offset, this);
}

i32 DSGlobal::LoadCityADF(char* arg1, i32 arg2, u32 arg3)
{
    return stub<thiscall_t<i32, DSGlobal*, char*, i32, u32>>(0xEFFB0_Offset, this, arg1, arg2, arg3);
}

i32 DSGlobal::LoadUIADF(char* arg1)
{
    return stub<thiscall_t<i32, DSGlobal*, char*>>(0xEFE10_Offset, this, arg1);
}

void DSGlobal::ScanAvailableDSFormats()
{
    return stub<thiscall_t<void, DSGlobal*>>(0xF0670_Offset, this);
}

void DSGlobal::SetBitDepth(i32 arg1)
{
    return stub<thiscall_t<void, DSGlobal*, i32>>(0xF0990_Offset, this, arg1);
}

void DSGlobal::SetDeviceRating(struct tag_dsdevdesc* arg1)
{
    return stub<thiscall_t<void, DSGlobal*, struct tag_dsdevdesc*>>(0xEFA50_Offset, this, arg1);
}

void DSGlobal::SetPrimaryBufferFormat(u32 arg1, u8 arg2)
{
    return stub<thiscall_t<void, DSGlobal*, u32, u8>>(0xF0580_Offset, this, arg1, arg2);
}

char* DSGlobal::TranslateDSError(i32 arg1)
{
    return stub<thiscall_t<char*, DSGlobal*, i32>>(0xF0730_Offset, this, arg1);
}

u32 const DSGlobal::GetCDMusicOnMask()
{
    return stub<cdecl_t<u32 const>>(0xF0A90_Offset);
}

u32 const DSGlobal::GetCommentaryOnMask()
{
    return stub<cdecl_t<u32 const>>(0xF0A80_Offset);
}

u32 const DSGlobal::GetDSound3DMask()
{
    return stub<cdecl_t<u32 const>>(0xF0A60_Offset);
}

u32 const DSGlobal::GetEchoOnMask()
{
    return stub<cdecl_t<u32 const>>(0xF0A50_Offset);
}

u32 const DSGlobal::GetHiResMask()
{
    return stub<cdecl_t<u32 const>>(0xF0A30_Offset);
}

u32 const DSGlobal::GetHiSampleSizeMask()
{
    return stub<cdecl_t<u32 const>>(0xF0A40_Offset);
}

u32 const DSGlobal::GetSoundFXOnMask()
{
    return stub<cdecl_t<u32 const>>(0xF0A70_Offset);
}

u32 const DSGlobal::GetStereoOnMask()
{
    return stub<cdecl_t<u32 const>>(0xF0A20_Offset);
}

u32 const DSGlobal::GetUsingEAXMask()
{
    return stub<cdecl_t<u32 const>>(0xF0AA0_Offset);
}

i32 __stdcall DSEnumProc(struct _GUID* arg1, char* arg2, char* arg3, void* arg4)
{
    return stub<stdcall_t<i32, struct _GUID*, char*, char*, void*>>(0xEF8B0_Offset, arg1, arg2, arg3, arg4);
}

i32 FormatCodeToWFX(u32 arg1, struct tWAVEFORMATEX* arg2)
{
    return stub<cdecl_t<i32, u32, struct tWAVEFORMATEX*>>(0xF04D0_Offset, arg1, arg2);
}

i32 IsDSDeviceInList(struct _GUID* arg1)
{
    return stub<cdecl_t<i32, struct _GUID*>>(0xEF850_Offset, arg1);
}

void UpperCase(char* arg1)
{
    return stub<cdecl_t<void, char*>>(0xEF800_Offset, arg1);
}
