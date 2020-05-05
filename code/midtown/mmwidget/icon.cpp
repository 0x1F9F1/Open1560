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

define_dummy_symbol(mmwidget_icon);

#include "icon.h"

UIIcon::UIIcon()
{
    unimplemented();
}

UIIcon::~UIIcon()
{
    unimplemented(arg1);
}

class agiBitmap* UIIcon::CreateDummyBitmap()
{
    return stub<thiscall_t<class agiBitmap*, UIIcon*>>(0xB9A10_Offset, this);
}

void UIIcon::Cull()
{
    return stub<thiscall_t<void, UIIcon*>>(0xB9AF0_Offset, this);
}

void UIIcon::GetHitArea(f32& arg1, f32& arg2)
{
    return stub<thiscall_t<void, UIIcon*, f32&, f32&>>(0xB9A60_Offset, this, arg1, arg2);
}

void UIIcon::Init(char* arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, UIIcon*, char*, f32, f32>>(0xB9960_Offset, this, arg1, arg2, arg3);
}

void UIIcon::LoadBitmap(char* arg1)
{
    return stub<thiscall_t<void, UIIcon*, char*>>(0xB99A0_Offset, this, arg1);
}

void UIIcon::Switch(i32 arg1)
{
    return stub<thiscall_t<void, UIIcon*, i32>>(0xB9A90_Offset, this, arg1);
}

void UIIcon::Update()
{
    return stub<thiscall_t<void, UIIcon*>>(0xB9AD0_Offset, this);
}
