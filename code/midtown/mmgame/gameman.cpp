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

define_dummy_symbol(mmgame_gameman);

#include "gameman.h"

mmScreenClearFlunky::~mmScreenClearFlunky()
{
    unimplemented();
}

void mmScreenClearFlunky::Cull()
{
    return stub<thiscall_t<void, mmScreenClearFlunky*>>(0x403D10, this);
}

void mmScreenClearFlunky::Update()
{
    return stub<thiscall_t<void, mmScreenClearFlunky*>>(0x403CE0, this);
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
    return stub<thiscall_t<void, mmGameManager*, class Bank*>>(0x4049B0, this, arg1);
}

void mmGameManager::BeDone()
{
    return stub<thiscall_t<void, mmGameManager*>>(0x4044C0, this);
}

void mmGameManager::Cull()
{
    return stub<thiscall_t<void, mmGameManager*>>(0x404750, this);
}

f32 mmGameManager::GetBrakes()
{
    return stub<thiscall_t<f32, mmGameManager*>>(0x404920, this);
}

class MetaClass* mmGameManager::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmGameManager*>>(0x404B30, this);
}

f32 mmGameManager::GetSteering()
{
    return stub<thiscall_t<f32, mmGameManager*>>(0x404950, this);
}

f32 mmGameManager::GetThrottle()
{
    return stub<thiscall_t<f32, mmGameManager*>>(0x404980, this);
}

void mmGameManager::LoadReplay(char* arg1)
{
    return stub<thiscall_t<void, mmGameManager*, char*>>(0x4047B0, this, arg1);
}

void mmGameManager::Reset()
{
    return stub<thiscall_t<void, mmGameManager*>>(0x404910, this);
}

void mmGameManager::SaveReplay(char* arg1)
{
    return stub<thiscall_t<void, mmGameManager*, char*>>(0x404880, this, arg1);
}

void mmGameManager::StartReplay()
{
    return stub<thiscall_t<void, mmGameManager*>>(0x404790, this);
}

void mmGameManager::Update()
{
    return stub<thiscall_t<void, mmGameManager*>>(0x4044D0, this);
}

void mmGameManager::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4049C0);
}

static void DoScan(void* arg1)
{
    return stub<cdecl_t<void, void*>>(0x4046D0, arg1);
}

static void randcall()
{
    return stub<cdecl_t<void>>(0x404390);
}
