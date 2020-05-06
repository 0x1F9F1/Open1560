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

define_dummy_symbol(mmgame_multicr);

#include "multicr.h"

mmMultiCR::mmMultiCR()
{
    unimplemented();
}

mmMultiCR::~mmMultiCR()
{
    unimplemented(arg1);
}

void mmMultiCR::ChangePlayerData()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41D1A0, this);
}

void mmMultiCR::DropThruCityHandler()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41D810, this);
}

void mmMultiCR::FondleCarMass(class mmCar* arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmMultiCR*, class mmCar*, f32>>(0x41D180, this, arg1, arg2);
}

void mmMultiCR::GameMessage(struct NETGAME_MSG* arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, struct NETGAME_MSG*>>(0x41E6E0, this, arg1);
}

class MetaClass* mmMultiCR::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmMultiCR*>>(0x41F760, this);
}

class mmWaypoints* mmMultiCR::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmMultiCR*>>(0x41F920, this);
}

void mmMultiCR::HitWaterHandler()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41D760, this);
}

void mmMultiCR::ImpactCallback()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41D090, this);
}

i32 mmMultiCR::Init()
{
    return stub<thiscall_t<i32, mmMultiCR*>>(0x41C140, this);
}

void mmMultiCR::InitGameObjects()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41C4E0, this);
}

void mmMultiCR::InitHUD()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41C3A0, this);
}

void mmMultiCR::InitMyPlayer()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41C2A0, this);
}

void mmMultiCR::InitNetworkPlayers()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41C940, this);
}

i32 mmMultiCR::LoadCSV(char* arg1)
{
    return stub<thiscall_t<i32, mmMultiCR*, char*>>(0x41CF40, this, arg1);
}

i32 mmMultiCR::LoadSets(char* arg1)
{
    return stub<thiscall_t<i32, mmMultiCR*, char*>>(0x41CEA0, this, arg1);
}

void mmMultiCR::Reset()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41CCC0, this);
}

void mmMultiCR::ResetPositions(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x41D210, this, arg1);
}

void mmMultiCR::SystemMessage(struct NETSYS_MSG* arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, struct NETSYS_MSG*>>(0x41E490, this, arg1);
}

void mmMultiCR::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x41F560, this, arg1);
}

void mmMultiCR::UpdateGame()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41D380, this);
}

void mmMultiCR::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x41D340, this, arg1);
}

void mmMultiCR::DeclareFields()
{
    return stub<cdecl_t<void>>(0x41F5E0);
}

void mmMultiCR::CycleInterest(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x41F570, this, arg1);
}

void mmMultiCR::DisplayTimeWarning(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x41F130, this, arg1);
}

void mmMultiCR::DropGold(class Vector3 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmMultiCR*, class Vector3, i32>>(0x41DA30, this, arg1, arg2);
}

void mmMultiCR::FillResults()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41E290, this);
}

void mmMultiCR::FindGround(class Vector3 arg1, class Vector3& arg2)
{
    return stub<thiscall_t<void, mmMultiCR*, class Vector3, class Vector3&>>(0x41D970, this, arg1, arg2);
}

i32 mmMultiCR::GetRandomIndex()
{
    return stub<thiscall_t<i32, mmMultiCR*>>(0x41D1F0, this);
}

void mmMultiCR::OppStealGold(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x41D900, this, arg1);
}

void mmMultiCR::Score(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x41F530, this, arg1);
}

i32 mmMultiCR::SelectTeams()
{
    return stub<thiscall_t<i32, mmMultiCR*>>(0x41D330, this);
}

void mmMultiCR::SendChangeSet(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x41F350, this, arg1);
}

void mmMultiCR::SendGameState(u32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, u32>>(0x41F1C0, this, arg1);
}

void mmMultiCR::SendGoldAck(u32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, u32>>(0x41F2C0, this, arg1);
}

void mmMultiCR::SendGoldDeliver()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41F300, this);
}

void mmMultiCR::SendGoldDrop(class Vector3 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, class Vector3>>(0x41F270, this, arg1);
}

void mmMultiCR::SendLimitReached(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x41F390, this, arg1);
}

void mmMultiCR::SendSetup(u32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, u32>>(0x41F260, this, arg1);
}

void mmMultiCR::SendTimeWarning(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x41F3D0, this, arg1);
}

void mmMultiCR::StealGold(class mmCar* arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, class mmCar*>>(0x41D8C0, this, arg1);
}

void mmMultiCR::UpdateBank()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41DFA0, this);
}

void mmMultiCR::UpdateGold()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41DC20, this);
}

void mmMultiCR::UpdateHUD()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41F410, this);
}

void mmMultiCR::UpdateHideout()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41DE50, this);
}

void mmMultiCR::UpdateLimit()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41E0F0, this);
}

void mmMultiCR::UpdateTimeWarning()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x41EFC0, this);
}
