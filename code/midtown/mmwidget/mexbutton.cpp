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

define_dummy_symbol(mmwidget_mexbutton);

#include "mexbutton.h"

UIMexButton::UIMexButton()
{
    unimplemented();
}

UIMexButton::~UIMexButton()
{
    unimplemented(arg1);
}

void UIMexButton::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, UIMexButton*, union eqEvent>>(0x4BCCC0, this, arg1);
}

void UIMexButton::DoToggle()
{
    return stub<thiscall_t<void, UIMexButton*>>(0x4BCCA0, this);
}

void UIMexButton::Init(struct LocString* arg1, i32* arg2, i32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, i32 arg8,
    i32 arg9, class Callback arg10)
{
    return stub<
        thiscall_t<void, UIMexButton*, struct LocString*, i32*, i32, f32, f32, f32, f32, i32, i32, class Callback>>(
        0x4BCB40, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}

void UIMexButton::Update()
{
    return stub<thiscall_t<void, UIMexButton*>>(0x4BCC10, this);
}

void UIMexButton::DrawOff()
{
    return stub<thiscall_t<void, UIMexButton*>>(0x4BCC60, this);
}

void UIMexButton::DrawOn()
{
    return stub<thiscall_t<void, UIMexButton*>>(0x4BCC70, this);
}
