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
    unimplemented(arg1);
}

void mmSingleCircuit::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmSingleCircuit*, class Bank*>>(0x167A0_Offset, this, arg1);
}

class MetaClass* mmSingleCircuit::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmSingleCircuit*>>(0x16AB0_Offset, this);
}

class mmWaypoints* mmSingleCircuit::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmSingleCircuit*>>(0x16C80_Offset, this);
}

void mmSingleCircuit::HitWaterHandler()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x152E0_Offset, this);
}

i32 mmSingleCircuit::Init()
{
    return stub<thiscall_t<i32, mmSingleCircuit*>>(0x14D50_Offset, this);
}

void mmSingleCircuit::InitGameObjects()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x14F90_Offset, this);
}

void mmSingleCircuit::InitHUD()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x14F40_Offset, this);
}

void mmSingleCircuit::InitMyPlayer()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x14ED0_Offset, this);
}

void mmSingleCircuit::InitOtherPlayers()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x15200_Offset, this);
}

void mmSingleCircuit::NextRace()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x16620_Offset, this);
}

void mmSingleCircuit::Reset()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x15210_Offset, this);
}

void mmSingleCircuit::Update()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x15490_Offset, this);
}

void mmSingleCircuit::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmSingleCircuit*, i32>>(0x16C70_Offset, this, arg1);
}

void mmSingleCircuit::UpdateGame()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x15850_Offset, this);
}

void mmSingleCircuit::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmSingleCircuit*, i32>>(0x154B0_Offset, this, arg1);
}

void mmSingleCircuit::UpdateScore()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x154C0_Offset, this);
}

void mmSingleCircuit::DeclareFields()
{
    return stub<cdecl_t<void>>(0x16940_Offset);
}

void mmSingleCircuit::DisableRacers()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x15420_Offset, this);
}

void mmSingleCircuit::EnableRacers()
{
    return stub<thiscall_t<void, mmSingleCircuit*>>(0x15390_Offset, this);
}

void mmSingleCircuit::FinishMessage(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmSingleCircuit*, i32, i32>>(0x15FE0_Offset, this, arg1, arg2);
}

i32 mmSingleCircuit::ProgressCheck(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmSingleCircuit*, i32, i32>>(0x165F0_Offset, this, arg1, arg2);
}

i32 mmSingleCircuit::RegisterFinish()
{
    return stub<thiscall_t<i32, mmSingleCircuit*>>(0x161D0_Offset, this);
}

i32 mmSingleCircuit::RegisterLap()
{
    return stub<thiscall_t<i32, mmSingleCircuit*>>(0x16170_Offset, this);
}
