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

#include "cd.h"

CDMan::~CDMan()
{
    unimplemented();
}

i32 CDMan::WindowProc(struct HWND__* arg1, u32 arg2, u32 arg3, i32 arg4)
{
    return stub<thiscall_t<i32, CDMan*, struct HWND__*, u32, u32, i32>>(0xF4690_Offset, this, arg1, arg2, arg3, arg4);
}

i16 CDMan::GetNumTracks()
{
    return stub<thiscall_t<i16, CDMan*>>(0xF4700_Offset, this);
}

u32 CDMan::GetPosition(u8* arg1, u8* arg2, u8* arg3, u8* arg4)
{
    return stub<thiscall_t<u32, CDMan*, u8*, u8*, u8*, u8*>>(0xF4610_Offset, this, arg1, arg2, arg3, arg4);
}

u32 CDMan::Init(i16 arg1)
{
    return stub<thiscall_t<u32, CDMan*, i16>>(0xF4280_Offset, this, arg1);
}

u32 CDMan::PlayTrack(u8 arg1, u8 arg2)
{
    return stub<thiscall_t<u32, CDMan*, u8, u8>>(0xF4340_Offset, this, arg1, arg2);
}

u32 CDMan::PlayTrack(u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5)
{
    return stub<thiscall_t<u32, CDMan*, u8, u8, u8, u8, u8>>(0xF4450_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

u32 CDMan::ResumePlay()
{
    return stub<thiscall_t<u32, CDMan*>>(0xF4430_Offset, this);
}

u32 CDMan::SeekTrack(u8 arg1)
{
    return stub<thiscall_t<u32, CDMan*, u8>>(0xF45A0_Offset, this, arg1);
}

u32 CDMan::Stop()
{
    return stub<thiscall_t<u32, CDMan*>>(0xF4560_Offset, this);
}

define_dummy_symbol(mmaudio_cd);
