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

define_dummy_symbol(mmwidget_tdwidget);

#include "tdwidget.h"

TextDropWidget::TextDropWidget()
{
    unimplemented();
}

TextDropWidget::~TextDropWidget()
{
    unimplemented(arg1);
}

i32 TextDropWidget::Capture(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, TextDropWidget*, f32, f32>>(0x4BE400, this, arg1, arg2);
}

i32 TextDropWidget::Dec()
{
    return stub<thiscall_t<i32, TextDropWidget*>>(0x4BE390, this);
}

i32 TextDropWidget::DecDrop()
{
    return stub<thiscall_t<i32, TextDropWidget*>>(0x4BE3D0, this);
}

class MetaClass* TextDropWidget::GetClass()
{
    return stub<thiscall_t<class MetaClass*, TextDropWidget*>>(0x4BE630, this);
}

i32 TextDropWidget::GetCount()
{
    return stub<thiscall_t<i32, TextDropWidget*>>(0x4BE1A0, this);
}

i32 TextDropWidget::GetDisabledMask()
{
    return stub<thiscall_t<i32, TextDropWidget*>>(0x4BE4B0, this);
}

i32 TextDropWidget::Inc()
{
    return stub<thiscall_t<i32, TextDropWidget*>>(0x4BE380, this);
}

i32 TextDropWidget::IncDrop()
{
    return stub<thiscall_t<i32, TextDropWidget*>>(0x4BE3A0, this);
}

void TextDropWidget::Init(
    class asCamera* arg1, void* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, class string arg8, i32 arg9)
{
    return stub<thiscall_t<void, TextDropWidget*, class asCamera*, void*, f32, f32, f32, f32, f32, class string, i32>>(
        0x4BE0B0, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

i32 TextDropWidget::IsActive()
{
    return stub<thiscall_t<i32, TextDropWidget*>>(0x4BE470, this);
}

void TextDropWidget::SetActive(i32 arg1)
{
    return stub<thiscall_t<void, TextDropWidget*, i32>>(0x4BE480, this, arg1);
}

void TextDropWidget::SetDisabledMask(i32 arg1)
{
    return stub<thiscall_t<void, TextDropWidget*, i32>>(0x4BE490, this, arg1);
}

i32 TextDropWidget::SetHighlight(i32 arg1)
{
    return stub<thiscall_t<i32, TextDropWidget*, i32>>(0x4BE310, this, arg1);
}

void TextDropWidget::SetString(class string arg1)
{
    return stub<thiscall_t<void, TextDropWidget*, class string>>(0x4BE1B0, this, arg1);
}

i32 TextDropWidget::SetValue(i32 arg1)
{
    return stub<thiscall_t<i32, TextDropWidget*, i32>>(0x4BE270, this, arg1);
}

void TextDropWidget::Switch(i32 arg1, class Vector4& arg2)
{
    return stub<thiscall_t<void, TextDropWidget*, i32, class Vector4&>>(0x4BE440, this, arg1, arg2);
}

void TextDropWidget::Update()
{
    return stub<thiscall_t<void, TextDropWidget*>>(0x4BE460, this);
}

void TextDropWidget::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4BE4C0);
}
