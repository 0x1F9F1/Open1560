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

define_dummy_symbol(mmwidget_toggle);

#include "toggle.h"

mmToggle::mmToggle()
{
    unimplemented();
}

mmToggle::~mmToggle()
{
    unimplemented(arg1);
}

void mmToggle::Cull()
{
    return stub<thiscall_t<void, mmToggle*>>(0xC05B0_Offset, this);
}

class MetaClass* mmToggle::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmToggle*>>(0xC07A0_Offset, this);
}

void mmToggle::Init(char* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, mmToggle*, char*, f32, f32, f32, f32>>(
        0xC03F0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void mmToggle::Update()
{
    return stub<thiscall_t<void, mmToggle*>>(0xC0590_Offset, this);
}

void mmToggle::DeclareFields()
{
    return stub<cdecl_t<void>>(0xC0630_Offset);
}

void mmToggle::LoadBitmap(char* arg1)
{
    return stub<thiscall_t<void, mmToggle*, char*>>(0xC0490_Offset, this, arg1);
}

void mmToggle::SetSize(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmToggle*, f32, f32>>(0xC04E0_Offset, this, arg1, arg2);
}
