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

define_dummy_symbol(mmwidget_sliderbar);

#include "sliderbar.h"

mmSlider::mmSlider()
{
    unimplemented();
}

mmSlider::~mmSlider()
{
    unimplemented(arg1);
}

void mmSlider::Cull()
{
    return stub<thiscall_t<void, mmSlider*>>(0x4BED40, this);
}

f32 mmSlider::Dec()
{
    return stub<thiscall_t<f32, mmSlider*>>(0x4BEC10, this);
}

f32 mmSlider::FudgeWidth()
{
    return stub<thiscall_t<f32, mmSlider*>>(0x4BEAA0, this);
}

class MetaClass* mmSlider::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmSlider*>>(0x4BF070, this);
}

f32 mmSlider::GetScreenHeight()
{
    return stub<thiscall_t<f32, mmSlider*>>(0x4BEA70, this);
}

void mmSlider::GetSliderHotSpots(f32& arg1, f32& arg2, f32& arg3, f32& arg4, f32& arg5, f32& arg6)
{
    return stub<thiscall_t<void, mmSlider*, f32&, f32&, f32&, f32&, f32&, f32&>>(
        0x4BEAF0, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

f32 mmSlider::Inc()
{
    return stub<thiscall_t<f32, mmSlider*>>(0x4BEBF0, this);
}

void mmSlider::Init(char* arg1, class uiWidget* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, f32 arg8,
    f32 arg9, i32 arg10, i32 arg11)
{
    return stub<thiscall_t<void, mmSlider*, char*, class uiWidget*, f32, f32, f32, f32, i32, f32, f32, i32, i32>>(
        0x4BE7D0, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}

i32 mmSlider::IsReadWrite()
{
    return stub<thiscall_t<i32, mmSlider*>>(0x4BEA00, this);
}

void mmSlider::LoadBitmap(char* arg1)
{
    return stub<thiscall_t<void, mmSlider*, char*>>(0x4BE830, this, arg1);
}

void mmSlider::SetPosition(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmSlider*, f32, f32>>(0x4BEAD0, this, arg1, arg2);
}

void mmSlider::SetRange(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmSlider*, f32, f32>>(0x4BECB0, this, arg1, arg2);
}

void mmSlider::SetReadWrite(i32 arg1)
{
    return stub<thiscall_t<void, mmSlider*, i32>>(0x4BE9E0, this, arg1);
}

void mmSlider::SetStep(f32 arg1)
{
    return stub<thiscall_t<void, mmSlider*, f32>>(0x4BEC30, this, arg1);
}

f32 mmSlider::SetValue(f32 arg1)
{
    return stub<thiscall_t<f32, mmSlider*, f32>>(0x4BEA10, this, arg1);
}

void mmSlider::Update()
{
    return stub<thiscall_t<void, mmSlider*>>(0x4BED20, this);
}

void mmSlider::UpdatePosition()
{
    return stub<thiscall_t<void, mmSlider*>>(0x4BEBC0, this);
}

void mmSlider::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4BEF00);
}
