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

#include "sliderbar.h"

mmSlider::mmSlider()
{
    unimplemented();
}

mmSlider::~mmSlider()
{
    unimplemented();
}

void mmSlider::Cull()
{
    return stub<thiscall_t<void, mmSlider*>>(0xBED40_Offset, this);
}

f32 mmSlider::Dec()
{
    return stub<thiscall_t<f32, mmSlider*>>(0xBEC10_Offset, this);
}

f32 mmSlider::FudgeWidth()
{
    return stub<thiscall_t<f32, mmSlider*>>(0xBEAA0_Offset, this);
}

class MetaClass* mmSlider::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmSlider*>>(0xBF070_Offset, this);
}

f32 mmSlider::GetScreenHeight()
{
    return stub<thiscall_t<f32, mmSlider*>>(0xBEA70_Offset, this);
}

void mmSlider::GetSliderHotSpots(f32& arg1, f32& arg2, f32& arg3, f32& arg4, f32& arg5, f32& arg6)
{
    return stub<thiscall_t<void, mmSlider*, f32&, f32&, f32&, f32&, f32&, f32&>>(
        0xBEAF0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

f32 mmSlider::Inc()
{
    return stub<thiscall_t<f32, mmSlider*>>(0xBEBF0_Offset, this);
}

void mmSlider::Init(char* arg1, class uiWidget* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, f32 arg8,
    f32 arg9, i32 arg10, i32 arg11)
{
    return stub<thiscall_t<void, mmSlider*, char*, class uiWidget*, f32, f32, f32, f32, i32, f32, f32, i32, i32>>(
        0xBE7D0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}

i32 mmSlider::IsReadWrite()
{
    return stub<thiscall_t<i32, mmSlider*>>(0xBEA00_Offset, this);
}

void mmSlider::LoadBitmap(char* arg1)
{
    return stub<thiscall_t<void, mmSlider*, char*>>(0xBE830_Offset, this, arg1);
}

void mmSlider::SetPosition(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmSlider*, f32, f32>>(0xBEAD0_Offset, this, arg1, arg2);
}

void mmSlider::SetRange(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmSlider*, f32, f32>>(0xBECB0_Offset, this, arg1, arg2);
}

void mmSlider::SetReadWrite(i32 arg1)
{
    return stub<thiscall_t<void, mmSlider*, i32>>(0xBE9E0_Offset, this, arg1);
}

void mmSlider::SetStep(f32 arg1)
{
    return stub<thiscall_t<void, mmSlider*, f32>>(0xBEC30_Offset, this, arg1);
}

f32 mmSlider::SetValue(f32 arg1)
{
    return stub<thiscall_t<f32, mmSlider*, f32>>(0xBEA10_Offset, this, arg1);
}

void mmSlider::Update()
{
    return stub<thiscall_t<void, mmSlider*>>(0xBED20_Offset, this);
}

void mmSlider::UpdatePosition()
{
    return stub<thiscall_t<void, mmSlider*>>(0xBEBC0_Offset, this);
}

void mmSlider::DeclareFields()
{
    return stub<cdecl_t<void>>(0xBEF00_Offset);
}

define_dummy_symbol(mmwidget_sliderbar);
