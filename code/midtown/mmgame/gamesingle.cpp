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

define_dummy_symbol(mmgame_gamesingle);

#include "gamesingle.h"

u32 __stdcall ThreadFunc(void* arg1)
{
    return stub<stdcall_t<u32, void*>>(0x416C90, arg1);
}

mmGameSingle::mmGameSingle()
{
    unimplemented();
}

mmGameSingle::~mmGameSingle()
{
    unimplemented();
}

void mmGameSingle::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmGameSingle*, class Bank*>>(0x4189E0, this, arg1);
}

class MetaClass* mmGameSingle::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmGameSingle*>>(0x418D00, this);
}

class mmWaypoints* mmGameSingle::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmGameSingle*>>(0x418ED0, this);
}

void mmGameSingle::HitWaterHandler()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x4175A0, this);
}

i32 mmGameSingle::Init()
{
    return stub<thiscall_t<i32, mmGameSingle*>>(0x416DF0, this);
}

void mmGameSingle::InitGameObjects()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x417040, this);
}

void mmGameSingle::InitHUD()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x416FE0, this);
}

void mmGameSingle::InitMyPlayer()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x416F70, this);
}

void mmGameSingle::InitOtherPlayers()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x417340, this);
}

void mmGameSingle::NextRace()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x418840, this);
}

void mmGameSingle::Reset()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x4173A0, this);
}

void mmGameSingle::Update()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x417640, this);
}

void mmGameSingle::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmGameSingle*, i32>>(0x418EC0, this, arg1);
}

void mmGameSingle::UpdateGame()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x4176A0, this);
}

void mmGameSingle::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmGameSingle*, i32>>(0x417660, this, arg1);
}

void mmGameSingle::UpdateScore()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x417EF0, this);
}

void mmGameSingle::DeclareFields()
{
    return stub<cdecl_t<void>>(0x418B90);
}

void mmGameSingle::DisableRacers()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x417530, this);
}

void mmGameSingle::EnableRacers()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x4174A0, this);
}

void mmGameSingle::FinishMessage(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmGameSingle*, i32, i32>>(0x418270, this, arg1, arg2);
}

i32 mmGameSingle::ProgressCheck(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmGameSingle*, i32, i32>>(0x4187F0, this, arg1, arg2);
}

i32 mmGameSingle::RegisterFinish()
{
    return stub<thiscall_t<i32, mmGameSingle*>>(0x4183F0, this);
}
