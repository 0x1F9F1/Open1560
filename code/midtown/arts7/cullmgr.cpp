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

define_dummy_symbol(arts7_cullmgr);

#include "cullmgr.h"

asCullManager::asCullManager(i32 arg1, i32 arg2)
{
    unimplemented(arg1, arg2);
}

asCullManager::~asCullManager()
{
    unimplemented(arg1);
}

void asCullManager::DeclareCamera(class asCamera* arg1)
{
    return stub<thiscall_t<void, asCullManager*, class asCamera*>>(0x125440_Offset, this, arg1);
}

void asCullManager::DeclareCullable(class asCullable* arg1)
{
    return stub<thiscall_t<void, asCullManager*, class asCullable*>>(0x1254A0_Offset, this, arg1);
}

void asCullManager::DeclareCullable2D(class asCullable* arg1)
{
    return stub<thiscall_t<void, asCullManager*, class asCullable*>>(0x125550_Offset, this, arg1);
}

void asCullManager::AddPage(class Callback arg1)
{
    return stub<thiscall_t<void, asCullManager*, class Callback>>(0x125400_Offset, this, arg1);
}

void asCullManager::DeclareBitmap(class asCullable* arg1, class agiBitmap* arg2)
{
    return stub<thiscall_t<void, asCullManager*, class asCullable*, class agiBitmap*>>(
        0x1255F0_Offset, this, arg1, arg2);
}

void asCullManager::DeclarePrint(class asCullable* arg1)
{
    return stub<thiscall_t<void, asCullManager*, class asCullable*>>(0x125660_Offset, this, arg1);
}

class MetaClass* asCullManager::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asCullManager*>>(0x125840_Offset, this);
}

void asCullManager::Reset()
{
    return stub<thiscall_t<void, asCullManager*>>(0x124DF0_Offset, this);
}

void asCullManager::Update()
{
    return stub<thiscall_t<void, asCullManager*>>(0x125090_Offset, this);
}

void asCullManager::DeclareFields()
{
    return stub<cdecl_t<void>>(0x1256D0_Offset);
}

void asCullManager::DisplayVersionString()
{
    return stub<thiscall_t<void, asCullManager*>>(0x124E50_Offset, this);
}

void asCullManager::PrintMiniStats()
{
    return stub<thiscall_t<void, asCullManager*>>(0x124F00_Offset, this);
}

void asCullManager::PrintStats()
{
    return stub<thiscall_t<void, asCullManager*>>(0x124F90_Offset, this);
}

void Statsf(char const* arg1, ...)
{
    unimplemented(arg1);
}
