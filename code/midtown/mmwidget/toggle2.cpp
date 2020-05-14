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

define_dummy_symbol(mmwidget_toggle2);

#include "toggle2.h"

mmToggle2::mmToggle2()
{
    unimplemented();
}

mmToggle2::~mmToggle2()
{
    unimplemented();
}

void mmToggle2::Cull()
{
    return stub<thiscall_t<void, mmToggle2*>>(0x4C00E0, this);
}

class MetaClass* mmToggle2::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmToggle2*>>(0x4C0300, this);
}

void mmToggle2::Init(char* arg1, f32 arg2, f32 arg3, i32* arg4)
{
    return stub<thiscall_t<void, mmToggle2*, char*, f32, f32, i32*>>(0x4BFF90, this, arg1, arg2, arg3, arg4);
}

void mmToggle2::SetPosition(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmToggle2*, f32, f32>>(0x4C0020, this, arg1, arg2);
}

void mmToggle2::Update()
{
    return stub<thiscall_t<void, mmToggle2*>>(0x4C00C0, this);
}

void mmToggle2::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4C01A0);
}

void mmToggle2::LoadBitmap(char* arg1)
{
    return stub<thiscall_t<void, mmToggle2*, char*>>(0x4BFFC0, this, arg1);
}
