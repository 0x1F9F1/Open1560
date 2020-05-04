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

#include "gameman.h"

mmScreenClearFlunky::~mmScreenClearFlunky()
{
    unimplemented();
}

void mmScreenClearFlunky::Cull()
{
    return stub<thiscall_t<void, mmScreenClearFlunky*>>(0x3D10_Offset, this);
}

void mmScreenClearFlunky::Update()
{
    return stub<thiscall_t<void, mmScreenClearFlunky*>>(0x3CE0_Offset, this);
}

mmGameManager::mmGameManager()
{
    unimplemented();
}

mmGameManager::~mmGameManager()
{
    unimplemented();
}

void mmGameManager::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmGameManager*, class Bank*>>(0x49B0_Offset, this, arg1);
}

void mmGameManager::BeDone()
{
    return stub<thiscall_t<void, mmGameManager*>>(0x44C0_Offset, this);
}

void mmGameManager::Cull()
{
    return stub<thiscall_t<void, mmGameManager*>>(0x4750_Offset, this);
}

f32 mmGameManager::GetBrakes()
{
    return stub<thiscall_t<f32, mmGameManager*>>(0x4920_Offset, this);
}

class MetaClass* mmGameManager::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmGameManager*>>(0x4B30_Offset, this);
}

f32 mmGameManager::GetSteering()
{
    return stub<thiscall_t<f32, mmGameManager*>>(0x4950_Offset, this);
}

f32 mmGameManager::GetThrottle()
{
    return stub<thiscall_t<f32, mmGameManager*>>(0x4980_Offset, this);
}

void mmGameManager::LoadReplay(char* arg1)
{
    return stub<thiscall_t<void, mmGameManager*, char*>>(0x47B0_Offset, this, arg1);
}

void mmGameManager::Reset()
{
    return stub<thiscall_t<void, mmGameManager*>>(0x4910_Offset, this);
}

void mmGameManager::SaveReplay(char* arg1)
{
    return stub<thiscall_t<void, mmGameManager*, char*>>(0x4880_Offset, this, arg1);
}

void mmGameManager::StartReplay()
{
    return stub<thiscall_t<void, mmGameManager*>>(0x4790_Offset, this);
}

void mmGameManager::Update()
{
    return stub<thiscall_t<void, mmGameManager*>>(0x44D0_Offset, this);
}

void mmGameManager::DeclareFields()
{
    return stub<cdecl_t<void>>(0x49C0_Offset);
}

define_dummy_symbol(mmgame_gameman);
