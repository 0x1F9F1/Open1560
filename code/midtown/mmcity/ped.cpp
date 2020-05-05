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

define_dummy_symbol(mmcity_ped);

#include "ped.h"

mmPed::mmPed()
{
    unimplemented();
}

mmPed::~mmPed()
{
    unimplemented(arg1);
}

void __fastcall mmPed::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmPed*, i32>>(0x978E0_Offset, this, arg1);
}

class MetaClass* mmPed::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPed*>>(0x97C10_Offset, this);
}

void mmPed::Init(char* arg1, class Vector3& arg2)
{
    return stub<thiscall_t<void, mmPed*, char*, class Vector3&>>(0x97820_Offset, this, arg1, arg2);
}

class Matrix34& __fastcall mmPed::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmPed*, class Matrix34&>>(0x97930_Offset, this, arg1);
}

void mmPed::Update()
{
    return stub<thiscall_t<void, mmPed*>>(0x978C0_Offset, this);
}

void mmPed::DeclareFields()
{
    return stub<cdecl_t<void>>(0x97A90_Offset);
}

mmPedManager::mmPedManager()
{
    unimplemented();
}

mmPedManager::~mmPedManager()
{
    unimplemented(arg1);
}

class MetaClass* mmPedManager::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPedManager*>>(0x97D80_Offset, this);
}

void mmPedManager::Init(i32 arg1)
{
    return stub<thiscall_t<void, mmPedManager*, i32>>(0x979B0_Offset, this, arg1);
}

void mmPedManager::Update()
{
    return stub<thiscall_t<void, mmPedManager*>>(0x97A60_Offset, this);
}

void mmPedManager::DeclareFields()
{
    return stub<cdecl_t<void>>(0x97C20_Offset);
}
