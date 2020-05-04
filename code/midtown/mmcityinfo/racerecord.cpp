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

#include "racerecord.h"

mmRecord::mmRecord()
{
    unimplemented();
}

mmRecord::~mmRecord()
{
    unimplemented();
}

void mmRecord::operator=(class mmRecord& arg1)
{
    return stub<thiscall_t<void, mmRecord*, class mmRecord&>>(0xD1780_Offset, this, arg1);
}

u32 mmRecord::ComputeCRC()
{
    return stub<thiscall_t<u32, mmRecord*>>(0xD1910_Offset, this);
}

char* mmRecord::GetCarName()
{
    return stub<thiscall_t<char*, mmRecord*>>(0xD16A0_Offset, this);
}

class MetaClass* mmRecord::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmRecord*>>(0xD1B50_Offset, this);
}

char* mmRecord::GetName()
{
    return stub<thiscall_t<char*, mmRecord*>>(0xD16B0_Offset, this);
}

i32 mmRecord::GetPassed()
{
    return stub<thiscall_t<i32, mmRecord*>>(0xD16C0_Offset, this);
}

i32 mmRecord::GetScore()
{
    return stub<thiscall_t<i32, mmRecord*>>(0xD16D0_Offset, this);
}

f32 mmRecord::GetTime()
{
    return stub<thiscall_t<f32, mmRecord*>>(0xD1690_Offset, this);
}

i32 mmRecord::LoadBinary(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmRecord*, class Stream*>>(0xD1890_Offset, this, arg1);
}

i32 mmRecord::SaveBinary(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmRecord*, class Stream*>>(0xD1810_Offset, this, arg1);
}

void mmRecord::SetCarName(char* arg1)
{
    return stub<thiscall_t<void, mmRecord*, char*>>(0xD16F0_Offset, this, arg1);
}

void mmRecord::SetName(char* arg1)
{
    return stub<thiscall_t<void, mmRecord*, char*>>(0xD1710_Offset, this, arg1);
}

void mmRecord::SetPassed(i32 arg1)
{
    return stub<thiscall_t<void, mmRecord*, i32>>(0xD1750_Offset, this, arg1);
}

void mmRecord::SetScore(i32 arg1)
{
    return stub<thiscall_t<void, mmRecord*, i32>>(0xD1770_Offset, this, arg1);
}

void mmRecord::SetTime(f32 arg1)
{
    return stub<thiscall_t<void, mmRecord*, f32>>(0xD16E0_Offset, this, arg1);
}

void mmRecord::DeclareFields()
{
    return stub<cdecl_t<void>>(0xD1970_Offset);
}

define_dummy_symbol(mmcityinfo_racerecord);
