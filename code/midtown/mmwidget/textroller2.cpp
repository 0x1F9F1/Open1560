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

#include "textroller2.h"

UITextRoller2::UITextRoller2()
{
    unimplemented();
}

UITextRoller2::~UITextRoller2()
{
    unimplemented();
}

void UITextRoller2::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, UITextRoller2*, union eqEvent>>(0xBB4C0_Offset, this, arg1);
}

void UITextRoller2::Cull()
{
    return stub<thiscall_t<void, UITextRoller2*>>(0xBB980_Offset, this);
}

i32 UITextRoller2::Dec()
{
    return stub<thiscall_t<i32, UITextRoller2*>>(0xBB950_Offset, this);
}

void UITextRoller2::EvalMouseXY(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, UITextRoller2*, f32, f32>>(0xBB5A0_Offset, this, arg1, arg2);
}

i32 UITextRoller2::Inc()
{
    return stub<thiscall_t<i32, UITextRoller2*>>(0xBB920_Offset, this);
}

void UITextRoller2::Init(struct LocString* arg1, i32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, class string arg7,
    i32 arg8, i32 arg9, i32 arg10, i32 arg11, class Callback arg12, class UIMenu* arg13)
{
    return stub<thiscall_t<void, UITextRoller2*, struct LocString*, i32*, f32, f32, f32, f32, class string, i32, i32,
        i32, i32, class Callback, class UIMenu*>>(
        0xBACD0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
}

void UITextRoller2::SetData(i32* arg1)
{
    return stub<thiscall_t<void, UITextRoller2*, i32*>>(0xBB890_Offset, this, arg1);
}

void UITextRoller2::SetString(class string arg1)
{
    return stub<thiscall_t<void, UITextRoller2*, class string>>(0xBB7C0_Offset, this, arg1);
}

void UITextRoller2::SetText()
{
    return stub<thiscall_t<void, UITextRoller2*>>(0xBB8B0_Offset, this);
}

i32 UITextRoller2::SetValue(i32 arg1)
{
    return stub<thiscall_t<i32, UITextRoller2*, i32>>(0xBB710_Offset, this, arg1);
}

void UITextRoller2::Switch(i32 arg1)
{
    return stub<thiscall_t<void, UITextRoller2*, i32>>(0xBB420_Offset, this, arg1);
}

void UITextRoller2::Update()
{
    return stub<thiscall_t<void, UITextRoller2*>>(0xBB3C0_Offset, this);
}

define_dummy_symbol(mmwidget_textroller2);
