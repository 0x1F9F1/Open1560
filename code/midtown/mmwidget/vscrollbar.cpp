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

#include "vscrollbar.h"

UIVScrollBar::UIVScrollBar()
{
    unimplemented();
}

UIVScrollBar::~UIVScrollBar()
{
    unimplemented();
}

void UIVScrollBar::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, UIVScrollBar*, union eqEvent>>(0xBD370_Offset, this, arg1);
}

void UIVScrollBar::Cull()
{
    return stub<thiscall_t<void, UIVScrollBar*>>(0xBD5B0_Offset, this);
}

f32 UIVScrollBar::Dec()
{
    return stub<thiscall_t<f32, UIVScrollBar*>>(0xBD150_Offset, this);
}

void UIVScrollBar::Disable()
{
    return stub<thiscall_t<void, UIVScrollBar*>>(0xBD950_Offset, this);
}

void UIVScrollBar::Enable()
{
    return stub<thiscall_t<void, UIVScrollBar*>>(0xBD930_Offset, this);
}

void UIVScrollBar::EvalMouseXY(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, UIVScrollBar*, f32, f32>>(0xBD430_Offset, this, arg1, arg2);
}

class MetaClass* UIVScrollBar::GetClass()
{
    return stub<thiscall_t<class MetaClass*, UIVScrollBar*>>(0xBD8A0_Offset, this);
}

f32 UIVScrollBar::Inc()
{
    return stub<thiscall_t<f32, UIVScrollBar*>>(0xBD0F0_Offset, this);
}

void UIVScrollBar::Init(
    f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32 arg5, f32 arg6, f32 arg7, i32* arg8, class Callback arg9, i32 arg10)
{
    return stub<thiscall_t<void, UIVScrollBar*, f32, f32, f32, f32, i32, f32, f32, i32*, class Callback, i32>>(
        0xBCE90_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}

void UIVScrollBar::LoadBitmap()
{
    return stub<thiscall_t<void, UIVScrollBar*>>(0xBCF00_Offset, this);
}

void UIVScrollBar::SetHotSpots()
{
    return stub<thiscall_t<void, UIVScrollBar*>>(0xBD030_Offset, this);
}

void UIVScrollBar::SetPosition(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, UIVScrollBar*, f32, f32>>(0xBD910_Offset, this, arg1, arg2);
}

void UIVScrollBar::SetRange(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, UIVScrollBar*, f32, f32>>(0xBD210_Offset, this, arg1, arg2);
}

void UIVScrollBar::SetStep(i32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, UIVScrollBar*, i32, f32>>(0xBD1B0_Offset, this, arg1, arg2);
}

void UIVScrollBar::SetTrough(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, UIVScrollBar*, f32, f32>>(0xBD280_Offset, this, arg1, arg2);
}

void UIVScrollBar::Switch(i32 arg1)
{
    return stub<thiscall_t<void, UIVScrollBar*, i32>>(0xBD320_Offset, this, arg1);
}

void UIVScrollBar::Update()
{
    return stub<thiscall_t<void, UIVScrollBar*>>(0xBD300_Offset, this);
}

void UIVScrollBar::DeclareFields()
{
    return stub<cdecl_t<void>>(0xBD730_Offset);
}

define_dummy_symbol(mmwidget_vscrollbar);
