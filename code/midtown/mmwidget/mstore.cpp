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

define_dummy_symbol(mmwidget_mstore);

#include "mstore.h"

MArray::MArray()
{
    unimplemented();
}

MArray::~MArray()
{
    unimplemented();
}

void MArray::AddMenuData(i32 arg1, class Vector4& arg2, char* arg3)
{
    return stub<thiscall_t<void, MArray*, i32, class Vector4&, char*>>(0xABCF0_Offset, this, arg1, arg2, arg3);
}

void MArray::Flush()
{
    return stub<thiscall_t<void, MArray*>>(0xABB20_Offset, this);
}

void MArray::Init(i32 arg1)
{
    return stub<thiscall_t<void, MArray*, i32>>(0xAB7D0_Offset, this, arg1);
}

void MArray::Read(char* arg1)
{
    return stub<thiscall_t<void, MArray*, char*>>(0xABB30_Offset, this, arg1);
}

i32 MArray::RetrieveMenuData(i32 arg1, f32& arg2, f32& arg3, f32& arg4, f32& arg5)
{
    return stub<thiscall_t<i32, MArray*, i32, f32&, f32&, f32&, f32&>>(
        0xABD60_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void MArray::Write(char* arg1)
{
    return stub<thiscall_t<void, MArray*, char*>>(0xAB810_Offset, this, arg1);
}
