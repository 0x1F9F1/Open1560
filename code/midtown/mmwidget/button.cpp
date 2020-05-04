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

#include "button.h"

UIButton::UIButton()
{
    unimplemented();
}

UIButton::~UIButton()
{
    unimplemented();
}

void UIButton::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, UIButton*, union eqEvent>>(0xB9DB0_Offset, this, arg1);
}

void UIButton::Disable()
{
    return stub<thiscall_t<void, UIButton*>>(0xB9F80_Offset, this);
}

void UIButton::Enable()
{
    return stub<thiscall_t<void, UIButton*>>(0xB9F60_Offset, this);
}

void UIButton::Init(
    struct LocString* arg1, i32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, class Callback arg8)
{
    return stub<thiscall_t<void, UIButton*, struct LocString*, i32, f32, f32, f32, f32, i32, class Callback>>(
        0xB9C50_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

void UIButton::SetReadOnly(i32 arg1)
{
    return stub<thiscall_t<void, UIButton*, i32>>(0xB9E00_Offset, this, arg1);
}

void UIButton::SetString(struct LocString* arg1)
{
    return stub<thiscall_t<void, UIButton*, struct LocString*>>(0xB9D30_Offset, this, arg1);
}

void UIButton::SetType(i32 arg1)
{
    return stub<thiscall_t<void, UIButton*, i32>>(0xB9ED0_Offset, this, arg1);
}

void UIButton::Switch(i32 arg1)
{
    return stub<thiscall_t<void, UIButton*, i32>>(0xB9E50_Offset, this, arg1);
}

i32 UIButton::TestHit(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, UIButton*, f32, f32>>(0xB9F20_Offset, this, arg1, arg2);
}

void UIButton::Update()
{
    return stub<thiscall_t<void, UIButton*>>(0xB9D20_Offset, this);
}

void UIButton::DrawOff()
{
    return stub<thiscall_t<void, UIButton*>>(0xB9D50_Offset, this);
}

void UIButton::DrawOn()
{
    return stub<thiscall_t<void, UIButton*>>(0xB9D80_Offset, this);
}

define_dummy_symbol(mmwidget_button);
