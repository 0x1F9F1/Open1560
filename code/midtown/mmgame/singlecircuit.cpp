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

define_dummy_symbol(mmgame_singlecircuit);

#include "singlecircuit.h"

mmSingleCircuit::mmSingleCircuit()
{
    unimplemented();
}

mmSingleCircuit::~mmSingleCircuit()
{
    unimplemented();
}

void mmSingleCircuit::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmSingleCircuit*, class Bank*>>(0x4167A0, this, arg1);
}

class MetaClass* mmSingleCircuit::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmSingleCircuit*>>(0x416AB0, this);
}

class mmWaypoints* mmSingleCircuit::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmSingleCircuit*>>(0x416C80, this);
}

void mmSingleCircuit::HitWaterHandler()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x4152E0, this);
}

i32 mmSingleCircuit::Init()
{
    return stub<thiscall_t<i32, mmSingleCircuit*>>(0x414D50, this);
}

void mmSingleCircuit::InitGameObjects()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x414F90, this);
}

void mmSingleCircuit::InitHUD()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x414F40, this);
}

void mmSingleCircuit::InitMyPlayer()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x414ED0, this);
}

void mmSingleCircuit::InitOtherPlayers()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x415200, this);
}

void mmSingleCircuit::NextRace()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x416620, this);
}

void mmSingleCircuit::Reset()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x415210, this);
}

void mmSingleCircuit::Update()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x415490, this);
}

void mmSingleCircuit::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmSingleCircuit*, i32>>(0x416C70, this, arg1);
}

void mmSingleCircuit::UpdateGame()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x415850, this);
}

void mmSingleCircuit::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmSingleCircuit*, i32>>(0x4154B0, this, arg1);
}

void mmSingleCircuit::UpdateScore()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x4154C0, this);
}

void mmSingleCircuit::DeclareFields()
{
    return stub<cdecl_t<void>>(0x416940);
}

void mmSingleCircuit::DisableRacers()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x415420, this);
}

void mmSingleCircuit::EnableRacers()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x415390, this);
}

void mmSingleCircuit::FinishMessage(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmSingleCircuit*, i32, i32>>(0x415FE0, this, arg1, arg2);
}

i32 mmSingleCircuit::ProgressCheck(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmSingleCircuit*, i32, i32>>(0x4165F0, this, arg1, arg2);
}

i32 mmSingleCircuit::RegisterFinish()
{
    return stub<thiscall_t<i32, mmSingleCircuit*>>(0x4161D0, this);
}

i32 mmSingleCircuit::RegisterLap()
{
    return stub<thiscall_t<i32, mmSingleCircuit*>>(0x416170, this);
}
