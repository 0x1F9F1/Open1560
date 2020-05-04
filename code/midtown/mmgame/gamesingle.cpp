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

#include "gamesingle.h"

u32 __stdcall ThreadFunc(void* arg1)
{
    return stub<stdcall_t<u32, void*>>(0x16C90_Offset, arg1);
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
    return stub<thiscall_t<void, mmGameSingle*, class Bank*>>(0x189E0_Offset, this, arg1);
}

class MetaClass* mmGameSingle::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmGameSingle*>>(0x18D00_Offset, this);
}

class mmWaypoints* mmGameSingle::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmGameSingle*>>(0x18ED0_Offset, this);
}

void mmGameSingle::HitWaterHandler()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x175A0_Offset, this);
}

i32 mmGameSingle::Init()
{
    return stub<thiscall_t<i32, mmGameSingle*>>(0x16DF0_Offset, this);
}

void mmGameSingle::InitGameObjects()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x17040_Offset, this);
}

void mmGameSingle::InitHUD()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x16FE0_Offset, this);
}

void mmGameSingle::InitMyPlayer()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x16F70_Offset, this);
}

void mmGameSingle::InitOtherPlayers()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x17340_Offset, this);
}

void mmGameSingle::NextRace()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x18840_Offset, this);
}

void mmGameSingle::Reset()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x173A0_Offset, this);
}

void mmGameSingle::Update()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x17640_Offset, this);
}

void mmGameSingle::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmGameSingle*, i32>>(0x18EC0_Offset, this, arg1);
}

void mmGameSingle::UpdateGame()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x176A0_Offset, this);
}

void mmGameSingle::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmGameSingle*, i32>>(0x17660_Offset, this, arg1);
}

void mmGameSingle::UpdateScore()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x17EF0_Offset, this);
}

void mmGameSingle::DeclareFields()
{
    return stub<cdecl_t<void>>(0x18B90_Offset);
}

void mmGameSingle::DisableRacers()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x17530_Offset, this);
}

void mmGameSingle::EnableRacers()
{
    return stub<thiscall_t<void, mmGameSingle*>>(0x174A0_Offset, this);
}

void mmGameSingle::FinishMessage(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmGameSingle*, i32, i32>>(0x18270_Offset, this, arg1, arg2);
}

i32 mmGameSingle::ProgressCheck(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmGameSingle*, i32, i32>>(0x187F0_Offset, this, arg1, arg2);
}

i32 mmGameSingle::RegisterFinish()
{
    return stub<thiscall_t<i32, mmGameSingle*>>(0x183F0_Offset, this);
}

define_dummy_symbol(mmgame_gamesingle);
