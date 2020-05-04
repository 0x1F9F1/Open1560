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

#include "bm_button.h"

UIBMButton::UIBMButton()
{
    unimplemented();
}

UIBMButton::~UIBMButton()
{
    unimplemented();
}

void UIBMButton::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, UIBMButton*, union eqEvent>>(0xB69A0_Offset, this, arg1);
}

class agiBitmap* UIBMButton::CreateDummyBitmap()
{
    return stub<thiscall_t<class agiBitmap*, UIBMButton*>>(0xB64F0_Offset, this);
}

void UIBMButton::Cull()
{
    return stub<thiscall_t<void, UIBMButton*>>(0xB6D20_Offset, this);
}

void UIBMButton::Disable()
{
    return stub<thiscall_t<void, UIBMButton*>>(0xB7290_Offset, this);
}

void UIBMButton::DoToggle()
{
    return stub<thiscall_t<void, UIBMButton*>>(0xB6750_Offset, this);
}

void UIBMButton::Enable()
{
    return stub<thiscall_t<void, UIBMButton*>>(0xB7270_Offset, this);
}

class MetaClass* UIBMButton::GetClass()
{
    return stub<thiscall_t<class MetaClass*, UIBMButton*>>(0xB7260_Offset, this);
}

i32 UIBMButton::GetDiv()
{
    return stub<thiscall_t<i32, UIBMButton*>>(0xB64C0_Offset, this);
}

void UIBMButton::GetHitArea(f32& arg1, f32& arg2)
{
    return stub<thiscall_t<void, UIBMButton*, f32&, f32&>>(0xB66F0_Offset, this, arg1, arg2);
}

f32 UIBMButton::GetScreenHeight()
{
    return stub<thiscall_t<f32, UIBMButton*>>(0xB6D10_Offset, this);
}

void UIBMButton::Init(char* arg1, f32 arg2, f32 arg3, i32 arg4, i32 arg5, i32* arg6, i32 arg7, i32 arg8,
    struct LocString* arg9, class Callback arg10, class Callback arg11)
{
    return stub<thiscall_t<void, UIBMButton*, char*, f32, f32, i32, i32, i32*, i32, i32, struct LocString*,
        class Callback, class Callback>>(
        0xB61C0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}

void UIBMButton::Kill()
{
    return stub<thiscall_t<void, UIBMButton*>>(0xB6810_Offset, this);
}

void UIBMButton::LoadBitmap(char* arg1)
{
    return stub<thiscall_t<void, UIBMButton*, char*>>(0xB6450_Offset, this, arg1);
}

void UIBMButton::MexOff()
{
    return stub<thiscall_t<void, UIBMButton*>>(0xB6A50_Offset, this);
}

void UIBMButton::MexOn()
{
    return stub<thiscall_t<void, UIBMButton*>>(0xB6A60_Offset, this);
}

void UIBMButton::MexToggle()
{
    return stub<thiscall_t<void, UIBMButton*>>(0xB6AA0_Offset, this);
}

char* UIBMButton::ReturnDescription()
{
    return stub<thiscall_t<char*, UIBMButton*>>(0xB6C60_Offset, this);
}

void UIBMButton::SetPosition(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, UIBMButton*, f32, f32>>(0xB6580_Offset, this, arg1, arg2);
}

void UIBMButton::Switch(i32 arg1)
{
    return stub<thiscall_t<void, UIBMButton*, i32>>(0xB6870_Offset, this, arg1);
}

void UIBMButton::Unkill()
{
    return stub<thiscall_t<void, UIBMButton*>>(0xB6830_Offset, this);
}

void UIBMButton::Update()
{
    return stub<thiscall_t<void, UIBMButton*>>(0xB6AD0_Offset, this);
}

void UIBMButton::DeclareFields()
{
    return stub<cdecl_t<void>>(0xB70F0_Offset);
}

void UIBMButton::GetSize()
{
    return stub<thiscall_t<void, UIBMButton*>>(0xB6550_Offset, this);
}

void UIBMButton::PlaySound()
{
    return stub<thiscall_t<void, UIBMButton*>>(0xB70C0_Offset, this);
}

void UIBMButton::AllocateSounds()
{
    return stub<cdecl_t<void>>(0xB6ED0_Offset);
}

define_dummy_symbol(mmwidget_bm_button);
