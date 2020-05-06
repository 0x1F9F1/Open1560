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

define_dummy_symbol(mmwidget_textroller);

#include "textroller.h"

UITextRoller::UITextRoller()
{
    unimplemented();
}

UITextRoller::~UITextRoller()
{
    unimplemented(arg1);
}

void UITextRoller::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, UITextRoller*, union eqEvent>>(0x4BA640, this, arg1);
}

void UITextRoller::Cull()
{
    return stub<thiscall_t<void, UITextRoller*>>(0x4BAAD0, this);
}

i32 UITextRoller::Dec()
{
    return stub<thiscall_t<i32, UITextRoller*>>(0x4BAAB0, this);
}

void UITextRoller::EvalMouseXY(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, UITextRoller*, f32, f32>>(0x4BA720, this, arg1, arg2);
}

i32 UITextRoller::Inc()
{
    return stub<thiscall_t<i32, UITextRoller*>>(0x4BAA90, this);
}

void UITextRoller::Init(struct LocString* arg1, i32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, class string arg7,
    i32 arg8, i32 arg9, i32 arg10, i32 arg11, class Callback arg12, class UIMenu* arg13)
{
    return stub<thiscall_t<void, UITextRoller*, struct LocString*, i32*, f32, f32, f32, f32, class string, i32, i32,
        i32, i32, class Callback, class UIMenu*>>(
        0x4BA0E0, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
}

void UITextRoller::SetString(class string arg1)
{
    return stub<thiscall_t<void, UITextRoller*, class string>>(0x4BA950, this, arg1);
}

void UITextRoller::SetText()
{
    return stub<thiscall_t<void, UITextRoller*>>(0x4BAA20, this);
}

i32 UITextRoller::SetValue(i32 arg1)
{
    return stub<thiscall_t<i32, UITextRoller*, i32>>(0x4BA8B0, this, arg1);
}

void UITextRoller::Switch(i32 arg1)
{
    return stub<thiscall_t<void, UITextRoller*, i32>>(0x4BA610, this, arg1);
}

void UITextRoller::Update()
{
    return stub<thiscall_t<void, UITextRoller*>>(0x4BA5B0, this);
}
