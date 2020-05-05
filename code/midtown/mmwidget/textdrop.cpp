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

define_dummy_symbol(mmwidget_textdrop);

#include "textdrop.h"

UITextDropdown::UITextDropdown()
{
    unimplemented();
}

UITextDropdown::~UITextDropdown()
{
    unimplemented(arg1);
}

void UITextDropdown::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, UITextDropdown*, union eqEvent>>(0xB3680_Offset, this, arg1);
}

i32 UITextDropdown::AnyEnabled()
{
    return stub<thiscall_t<i32, UITextDropdown*>>(0xB3910_Offset, this);
}

void UITextDropdown::AssignString(class string arg1)
{
    return stub<thiscall_t<void, UITextDropdown*, class string>>(0xB33B0_Offset, this, arg1);
}

void UITextDropdown::CaptureAction(union eqEvent arg1)
{
    return stub<thiscall_t<void, UITextDropdown*, union eqEvent>>(0xB3510_Offset, this, arg1);
}

void UITextDropdown::Cull()
{
    return stub<thiscall_t<void, UITextDropdown*>>(0xB3920_Offset, this);
}

f32 UITextDropdown::GetScreenHeight()
{
    return stub<thiscall_t<f32, UITextDropdown*>>(0xB3390_Offset, this);
}

i32 UITextDropdown::GetValue()
{
    return stub<thiscall_t<i32, UITextDropdown*>>(0xB38B0_Offset, this);
}

void UITextDropdown::Init(struct LocString* arg1, i32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, class string arg7,
    i32 arg8, i32 arg9, i32 arg10, class Callback arg11, char* arg12)
{
    return stub<thiscall_t<void, UITextDropdown*, struct LocString*, i32*, f32, f32, f32, f32, class string, i32, i32,
        i32, class Callback, char*>>(
        0xB2FD0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}

void UITextDropdown::SetData(i32* arg1)
{
    return stub<thiscall_t<void, UITextDropdown*, i32*>>(0xB3460_Offset, this, arg1);
}

void UITextDropdown::SetDisabledMask(i32 arg1)
{
    return stub<thiscall_t<void, UITextDropdown*, i32>>(0xB38F0_Offset, this, arg1);
}

void UITextDropdown::SetPos(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, UITextDropdown*, f32, f32>>(0xB33A0_Offset, this, arg1, arg2);
}

void UITextDropdown::SetSliderFocus(i32 arg1)
{
    return stub<thiscall_t<void, UITextDropdown*, i32>>(0xB3830_Offset, this, arg1);
}

void UITextDropdown::SetText(struct LocString* arg1)
{
    return stub<thiscall_t<void, UITextDropdown*, struct LocString*>>(0xB3500_Offset, this, arg1);
}

i32 UITextDropdown::SetValue(i32 arg1)
{
    return stub<thiscall_t<i32, UITextDropdown*, i32>>(0xB38C0_Offset, this, arg1);
}

void UITextDropdown::Switch(i32 arg1)
{
    return stub<thiscall_t<void, UITextDropdown*, i32>>(0xB37B0_Offset, this, arg1);
}

void UITextDropdown::Update()
{
    return stub<thiscall_t<void, UITextDropdown*>>(0xB3490_Offset, this);
}
