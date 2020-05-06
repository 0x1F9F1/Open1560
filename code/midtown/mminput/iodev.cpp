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

define_dummy_symbol(mminput_iodev);

#include "iodev.h"

mmIODev::mmIODev()
{
    unimplemented();
}

mmIODev::~mmIODev()
{
    unimplemented(arg1);
}

i32 mmIODev::operator==(union eqEvent* arg1)
{
    return stub<thiscall_t<i32, mmIODev*, union eqEvent*>>(0x4E5200, this, arg1);
}

void mmIODev::Assign(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmIODev*, i32, i32, i32>>(0x4E50E0, this, arg1, arg2, arg3);
}

class MetaClass* mmIODev::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmIODev*>>(0x4E5A50, this);
}

i32 mmIODev::GetComponentType(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmIODev*, i32, i32>>(0x4E5580, this, arg1, arg2);
}

void mmIODev::GetDescription(char* arg1)
{
    return stub<thiscall_t<void, mmIODev*, char*>>(0x4E52C0, this, arg1);
}

void mmIODev::Init(i32 arg1, i64 arg2)
{
    return stub<thiscall_t<void, mmIODev*, i32, i64>>(0x4E50B0, this, arg1, arg2);
}

void mmIODev::Print(i32 arg1)
{
    return stub<thiscall_t<void, mmIODev*, i32>>(0x4E5670, this, arg1);
}

i32 mmIODev::Read(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmIODev*, class Stream*>>(0x4E57F0, this, arg1);
}

i32 mmIODev::ReadBinary(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmIODev*, class Stream*>>(0x4E5850, this, arg1);
}

i32 mmIODev::SanityCheckioType(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<i32, mmIODev*, i32, i32, i32>>(0x4E55F0, this, arg1, arg2, arg3);
}

i32 mmIODev::Write(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmIODev*, class Stream*>>(0x4E5740, this, arg1);
}

i32 mmIODev::WriteBinary(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmIODev*, class Stream*>>(0x4E57A0, this, arg1);
}

void mmIODev::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4E58A0);
}

i32 ConvertDItoString(i32 arg1, char* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, i32, char*, i32>>(0x4E5260, arg1, arg2, arg3);
}
