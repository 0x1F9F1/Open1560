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

define_dummy_symbol(mmwidget_dropdown);

#include "dropdown.h"

mmDropDown::mmDropDown()
{
    unimplemented();
}

mmDropDown::~mmDropDown()
{
    unimplemented(arg1);
}

i32 mmDropDown::FindFirstEnabled()
{
    return stub<thiscall_t<i32, mmDropDown*>>(0x4C0E30, this);
}

class MetaClass* mmDropDown::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmDropDown*>>(0x4C10A0, this);
}

void mmDropDown::GetCurrentString(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmDropDown*, char*, i32>>(0x4C0D60, this, arg1, arg2);
}

i32 mmDropDown::GetHit(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, mmDropDown*, f32, f32>>(0x4C0EC0, this, arg1, arg2);
}

void mmDropDown::Init(
    class asCamera* arg1, void* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, class string arg7, i32 arg8)
{
    return stub<thiscall_t<void, mmDropDown*, class asCamera*, void*, f32, f32, f32, f32, class string, i32>>(
        0x4C08F0, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

void mmDropDown::InitString(class string arg1)
{
    return stub<thiscall_t<void, mmDropDown*, class string>>(0x4C09F0, this, arg1);
}

void mmDropDown::SetDisabledColors()
{
    return stub<thiscall_t<void, mmDropDown*>>(0x4C0DB0, this);
}

void mmDropDown::SetHighlight(i32 arg1)
{
    return stub<thiscall_t<void, mmDropDown*, i32>>(0x4C0E60, this, arg1);
}

void mmDropDown::Update()
{
    return stub<thiscall_t<void, mmDropDown*>>(0x4C0F20, this);
}

void mmDropDown::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4C0F30);
}

void mmDropDown::SetString(class string arg1)
{
    return stub<thiscall_t<void, mmDropDown*, class string>>(0x4C0C70, this, arg1);
}
