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

define_dummy_symbol(mmwidget_bm_label);

#include "bm_label.h"

UIBMLabel::UIBMLabel()
{
    unimplemented();
}

UIBMLabel::~UIBMLabel()
{
    unimplemented(arg1);
}

class agiBitmap* UIBMLabel::CreateDummyBitmap()
{
    return stub<thiscall_t<class agiBitmap*, UIBMLabel*>>(0x4B45C0, this);
}

void UIBMLabel::Cull()
{
    return stub<thiscall_t<void, UIBMLabel*>>(0x4B4640, this);
}

class MetaClass* UIBMLabel::GetClass()
{
    return stub<thiscall_t<class MetaClass*, UIBMLabel*>>(0x4B47F0, this);
}

void UIBMLabel::Init(class string* arg1, f32 arg2, f32 arg3, i32* arg4)
{
    return stub<thiscall_t<void, UIBMLabel*, class string*, f32, f32, i32*>>(0x4B4360, this, arg1, arg2, arg3, arg4);
}

void UIBMLabel::SetBitmapName(class string* arg1)
{
    return stub<thiscall_t<void, UIBMLabel*, class string*>>(0x4B4440, this, arg1);
}

void UIBMLabel::Update()
{
    return stub<thiscall_t<void, UIBMLabel*>>(0x4B4610, this);
}

void UIBMLabel::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4B4680);
}

void UIBMLabel::LoadBitmap()
{
    return stub<thiscall_t<void, UIBMLabel*>>(0x4B44E0, this);
}
