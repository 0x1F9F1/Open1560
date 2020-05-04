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

#include "game.h"

mmGame::mmGame()
{
    unimplemented();
}

mmGame::~mmGame()
{
    unimplemented();
}

void mmGame::InitGameStrings()
{
    return stub<thiscall_t<void, mmGame*>>(0xFAC0_Offset, this);
}

void mmGame::InitMyPlayer()
{
    return stub<thiscall_t<void, mmGame*>>(0x - 400000_Offset, this);
}

void mmGame::InitOtherPlayers()
{
    return stub<thiscall_t<void, mmGame*>>(0xF8C0_Offset, this);
}

void mmGame::InitGameObjects()
{
    return stub<thiscall_t<void, mmGame*>>(0x - 400000_Offset, this);
}

void mmGame::InitHUD()
{
    return stub<thiscall_t<void, mmGame*>>(0x - 400000_Offset, this);
}

void mmGame::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmGame*, i32>>(0x - 400000_Offset, this, arg1);
}

void mmGame::UpdateDebugInput()
{
    return stub<thiscall_t<void, mmGame*>>(0x104B0_Offset, this);
}

void mmGame::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmGame*, i32>>(0x - 400000_Offset, this, arg1);
}

void mmGame::UpdateGame()
{
    return stub<thiscall_t<void, mmGame*>>(0x - 400000_Offset, this);
}

void mmGame::NextRace()
{
    return stub<thiscall_t<void, mmGame*>>(0x - 400000_Offset, this);
}

void mmGame::HitWaterHandler()
{
    return stub<thiscall_t<void, mmGame*>>(0x104A0_Offset, this);
}

void mmGame::DropThruCityHandler()
{
    return stub<thiscall_t<void, mmGame*>>(0x10490_Offset, this);
}

void mmGame::SendChatMessage(char* arg1)
{
    return stub<thiscall_t<void, mmGame*, char*>>(0x11590_Offset, this, arg1);
}

class mmWaypoints* mmGame::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmGame*>>(0x - 400000_Offset, this);
}

void mmGame::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmGame*, class Bank*>>(0x11E30_Offset, this, arg1);
}

void mmGame::CollideAIOpponents()
{
    return stub<thiscall_t<void, mmGame*>>(0xF9C0_Offset, this);
}

i32 mmGame::GetCDTrack(i16 arg1)
{
    return stub<thiscall_t<i32, mmGame*, i16>>(0x11960_Offset, this, arg1);
}

class MetaClass* mmGame::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmGame*>>(0x11FC0_Offset, this);
}

i32 mmGame::Init()
{
    return stub<thiscall_t<i32, mmGame*>>(0xEA00_Offset, this);
}

i32 mmGame::IsPopupEnabled()
{
    return stub<thiscall_t<i32, mmGame*>>(0x10230_Offset, this);
}

void mmGame::PlayerSetState()
{
    return stub<thiscall_t<void, mmGame*>>(0x11420_Offset, this);
}

void mmGame::Reset()
{
    return stub<thiscall_t<void, mmGame*>>(0x10240_Offset, this);
}

void mmGame::SetIconsState()
{
    return stub<thiscall_t<void, mmGame*>>(0x11400_Offset, this);
}

void mmGame::Stats()
{
    return stub<thiscall_t<void, mmGame*>>(0x10050_Offset, this);
}

void mmGame::Update()
{
    return stub<thiscall_t<void, mmGame*>>(0x102A0_Offset, this);
}

void mmGame::UpdateGameInput()
{
    return stub<thiscall_t<void, mmGame*>>(0x10E90_Offset, this);
}

void mmGame::UpdatePaused()
{
    return stub<thiscall_t<void, mmGame*>>(0x10DA0_Offset, this);
}

void mmGame::UpdateSteeringBrakes()
{
    return stub<thiscall_t<void, mmGame*>>(0x11320_Offset, this);
}

void mmGame::DeclareFields()
{
    return stub<cdecl_t<void>>(0x11F20_Offset);
}

i32 mmGame::CalculateRaceScore(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmGame*, i32, i32>>(0x11520_Offset, this, arg1, arg2);
}

void mmGame::RespawnXYZ(class Vector3& arg1, f32& arg2)
{
    return stub<thiscall_t<void, mmGame*, class Vector3&, f32&>>(0x10130_Offset, this, arg1, arg2);
}

define_dummy_symbol(mmgame_game);
