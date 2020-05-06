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

define_dummy_symbol(mmwidget_togglebutton);

#include "togglebutton.h"

UIToggleButton::UIToggleButton()
{
    unimplemented();
}

UIToggleButton::~UIToggleButton()
{
    unimplemented(arg1);
}

void UIToggleButton::DoToggle()
{
    return stub<thiscall_t<void, UIToggleButton*>>(0x4BC660, this);
}

void UIToggleButton::DrawOff()
{
    return stub<thiscall_t<void, UIToggleButton*>>(0x4BC620, this);
}

void UIToggleButton::DrawOn()
{
    return stub<thiscall_t<void, UIToggleButton*>>(0x4BC640, this);
}

void UIToggleButton::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, UIToggleButton*, union eqEvent>>(0x4BC680, this, arg1);
}

void UIToggleButton::Init(
    struct LocString* arg1, i32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, i32 arg8, class Callback arg9)
{
    return stub<
        thiscall_t<void, UIToggleButton*, struct LocString*, i32*, f32, f32, f32, f32, i32, i32, class Callback>>(
        0x4BC580, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

void UIToggleButton::Update()
{
    return stub<thiscall_t<void, UIToggleButton*>>(0x4BC720, this);
}
