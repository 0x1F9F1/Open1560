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

#include "bm_label.h"

UIBMLabel::UIBMLabel()
{
    unimplemented();
}

UIBMLabel::~UIBMLabel()
{
    unimplemented();
}

class agiBitmap* UIBMLabel::CreateDummyBitmap()
{
    return stub<thiscall_t<class agiBitmap*, UIBMLabel*>>(0xB45C0_Offset, this);
}

void UIBMLabel::Cull()
{
    return stub<thiscall_t<void, UIBMLabel*>>(0xB4640_Offset, this);
}

class MetaClass* UIBMLabel::GetClass()
{
    return stub<thiscall_t<class MetaClass*, UIBMLabel*>>(0xB47F0_Offset, this);
}

void UIBMLabel::Init(class string* arg1, f32 arg2, f32 arg3, i32* arg4)
{
    return stub<thiscall_t<void, UIBMLabel*, class string*, f32, f32, i32*>>(
        0xB4360_Offset, this, arg1, arg2, arg3, arg4);
}

void UIBMLabel::SetBitmapName(class string* arg1)
{
    return stub<thiscall_t<void, UIBMLabel*, class string*>>(0xB4440_Offset, this, arg1);
}

void UIBMLabel::Update()
{
    return stub<thiscall_t<void, UIBMLabel*>>(0xB4610_Offset, this);
}

void UIBMLabel::DeclareFields()
{
    return stub<cdecl_t<void>>(0xB4680_Offset);
}

void UIBMLabel::LoadBitmap()
{
    return stub<thiscall_t<void, UIBMLabel*>>(0xB44E0_Offset, this);
}

define_dummy_symbol(mmwidget_bm_label);
