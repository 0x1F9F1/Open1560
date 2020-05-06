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
    return stub<thiscall_t<i32, mmIO*, union eqEvent*>>(0x4E4D20, this, arg1);
}

void mmIO::Assign(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmIO*, i32, i32>>(0x4E4CC0, this, arg1, arg2);
}

void mmIO::Clear()
{
    return stub<thiscall_t<void, mmIO*>>(0x4E4B90, this);
}

i32 mmIO::CompareComponent(i32 arg1)
{
    return stub<thiscall_t<i32, mmIO*, i32>>(0x4E4ED0, this, arg1);
}

void mmIO::ForceSettingAcrossConfigs(i32 arg1)
{
    return stub<thiscall_t<void, mmIO*, i32>>(0x4E4FA0, this, arg1);
}

void mmIO::GetDescription(char* arg1)
{
    return stub<thiscall_t<void, mmIO*, char*>>(0x4E4D70, this, arg1);
}

void mmIO::Init(char* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmIO*, char*, i32, i32>>(0x4E4BB0, this, arg1, arg2, arg3);
}

void mmIO::InitDev(i32 arg1, i64 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, mmIO*, i32, i64, i32, i32, i32>>(0x4E4C10, this, arg1, arg2, arg3, arg4, arg5);
}

i32 mmIO::Read(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmIO*, class Stream*>>(0x4E4E00, this, arg1);
}

i32 mmIO::Write(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmIO*, class Stream*>>(0x4E4DC0, this, arg1);
}
