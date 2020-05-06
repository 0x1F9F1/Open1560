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

define_dummy_symbol(mmcamtour_gamerecord);

#include "gamerecord.h"

mmGameRecord::mmGameRecord(f32 arg1)
{
    unimplemented(arg1);
}

mmGameRecord::~mmGameRecord()
{
    unimplemented();
}

void mmGameRecord::DoScan(class Vector4& arg1)
{
    return stub<thiscall_t<void, mmGameRecord*, class Vector4&>>(0x4FE070, this, arg1);
}

void mmGameRecord::Dump(char* arg1)
{
    return stub<thiscall_t<void, mmGameRecord*, char*>>(0x4FDE90, this, arg1);
}

i32 mmGameRecord::GetCount()
{
    return stub<thiscall_t<i32, mmGameRecord*>>(0x4FDE50, this);
}

class Vector4& mmGameRecord::GetVector4(i32 arg1)
{
    return stub<thiscall_t<class Vector4&, mmGameRecord*, i32>>(0x4FDE60, this, arg1);
}

void mmGameRecord::Init(i32 arg1)
{
    return stub<thiscall_t<void, mmGameRecord*, i32>>(0x4FDDE0, this, arg1);
}

i32 mmGameRecord::Register(
    class Vector4& arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9)
{
    return stub<thiscall_t<i32, mmGameRecord*, class Vector4&, f32, f32, f32, f32, f32, f32, f32, f32>>(
        0x4FDF90, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

void mmGameRecord::Sim()
{
    return stub<thiscall_t<void, mmGameRecord*>>(0x4FE140, this);
}
