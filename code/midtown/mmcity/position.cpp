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

define_dummy_symbol(mmcity_position);

#include "position.h"

mmPositions::mmPositions()
{
    unimplemented();
}

void mmPositions::Dump(char* arg1)
{
    return stub<thiscall_t<void, mmPositions*, char*>>(0x492050, this, arg1);
}

i32 mmPositions::GetCount()
{
    return stub<thiscall_t<i32, mmPositions*>>(0x492010, this);
}

class Vector4& mmPositions::GetVector4(i32 arg1)
{
    return stub<thiscall_t<class Vector4&, mmPositions*, i32>>(0x492020, this, arg1);
}

void mmPositions::Init(i32 arg1)
{
    return stub<thiscall_t<void, mmPositions*, i32>>(0x491E10, this, arg1);
}

i32 mmPositions::Load(char* arg1)
{
    return stub<thiscall_t<i32, mmPositions*, char*>>(0x491E40, this, arg1);
}

i32 mmPositions::Recall(i32 arg1, class Matrix34* arg2, i32* arg3, char* arg4)
{
    return stub<thiscall_t<i32, mmPositions*, i32, class Matrix34*, i32*, char*>>(
        0x4920F0, this, arg1, arg2, arg3, arg4);
}

i32 mmPositions::Register(class Vector4& arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, char* arg6)
{
    return stub<thiscall_t<i32, mmPositions*, class Vector4&, i32, i32, i32, i32, char*>>(
        0x492180, this, arg1, arg2, arg3, arg4, arg5, arg6);
}
