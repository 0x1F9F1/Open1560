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

define_dummy_symbol(mminput_io);

#include "io.h"

mmIO::mmIO()
{
    unimplemented();
}

mmIO::~mmIO()
{
    unimplemented();
}

i32 mmIO::operator==(union eqEvent* arg1)
{
    return stub<thiscall_t<i32, mmIO*, union eqEvent*>>(0xE4D20_Offset, this, arg1);
}

void mmIO::Assign(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmIO*, i32, i32>>(0xE4CC0_Offset, this, arg1, arg2);
}

void mmIO::Clear()
{
    return stub<thiscall_t<void, mmIO*>>(0xE4B90_Offset, this);
}

i32 mmIO::CompareComponent(i32 arg1)
{
    return stub<thiscall_t<i32, mmIO*, i32>>(0xE4ED0_Offset, this, arg1);
}

void mmIO::ForceSettingAcrossConfigs(i32 arg1)
{
    return stub<thiscall_t<void, mmIO*, i32>>(0xE4FA0_Offset, this, arg1);
}

void mmIO::GetDescription(char* arg1)
{
    return stub<thiscall_t<void, mmIO*, char*>>(0xE4D70_Offset, this, arg1);
}

void mmIO::Init(char* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmIO*, char*, i32, i32>>(0xE4BB0_Offset, this, arg1, arg2, arg3);
}

void mmIO::InitDev(i32 arg1, i64 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, mmIO*, i32, i64, i32, i32, i32>>(0xE4C10_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

i32 mmIO::Read(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmIO*, class Stream*>>(0xE4E00_Offset, this, arg1);
}

i32 mmIO::Write(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmIO*, class Stream*>>(0xE4DC0_Offset, this, arg1);
}
