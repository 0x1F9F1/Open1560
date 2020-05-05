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
    return stub<thiscall_t<void, mmMultiCR*>>(0x1D1A0_Offset, this);
}

void mmMultiCR::DropThruCityHandler()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1D810_Offset, this);
}

void mmMultiCR::FondleCarMass(class mmCar* arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmMultiCR*, class mmCar*, f32>>(0x1D180_Offset, this, arg1, arg2);
}

void mmMultiCR::GameMessage(struct NETGAME_MSG* arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, struct NETGAME_MSG*>>(0x1E6E0_Offset, this, arg1);
}

class MetaClass* mmMultiCR::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmMultiCR*>>(0x1F760_Offset, this);
}

class mmWaypoints* mmMultiCR::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmMultiCR*>>(0x1F920_Offset, this);
}

void mmMultiCR::HitWaterHandler()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1D760_Offset, this);
}

void mmMultiCR::ImpactCallback()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1D090_Offset, this);
}

i32 mmMultiCR::Init()
{
    return stub<thiscall_t<i32, mmMultiCR*>>(0x1C140_Offset, this);
}

void mmMultiCR::InitGameObjects()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1C4E0_Offset, this);
}

void mmMultiCR::InitHUD()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1C3A0_Offset, this);
}

void mmMultiCR::InitMyPlayer()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1C2A0_Offset, this);
}

void mmMultiCR::InitNetworkPlayers()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1C940_Offset, this);
}

i32 mmMultiCR::LoadCSV(char* arg1)
{
    return stub<thiscall_t<i32, mmMultiCR*, char*>>(0x1CF40_Offset, this, arg1);
}

i32 mmMultiCR::LoadSets(char* arg1)
{
    return stub<thiscall_t<i32, mmMultiCR*, char*>>(0x1CEA0_Offset, this, arg1);
}

void mmMultiCR::Reset()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1CCC0_Offset, this);
}

void mmMultiCR::ResetPositions(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x1D210_Offset, this, arg1);
}

void mmMultiCR::SystemMessage(struct NETSYS_MSG* arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, struct NETSYS_MSG*>>(0x1E490_Offset, this, arg1);
}

void mmMultiCR::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x1F560_Offset, this, arg1);
}

void mmMultiCR::UpdateGame()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1D380_Offset, this);
}

void mmMultiCR::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x1D340_Offset, this, arg1);
}

void mmMultiCR::DeclareFields()
{
    return stub<cdecl_t<void>>(0x1F5E0_Offset);
}

void mmMultiCR::CycleInterest(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x1F570_Offset, this, arg1);
}

void mmMultiCR::DisplayTimeWarning(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x1F130_Offset, this, arg1);
}

void mmMultiCR::DropGold(class Vector3 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmMultiCR*, class Vector3, i32>>(0x1DA30_Offset, this, arg1, arg2);
}

void mmMultiCR::FillResults()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1E290_Offset, this);
}

void mmMultiCR::FindGround(class Vector3 arg1, class Vector3& arg2)
{
    return stub<thiscall_t<void, mmMultiCR*, class Vector3, class Vector3&>>(0x1D970_Offset, this, arg1, arg2);
}

i32 mmMultiCR::GetRandomIndex()
{
    return stub<thiscall_t<i32, mmMultiCR*>>(0x1D1F0_Offset, this);
}

void mmMultiCR::OppStealGold(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x1D900_Offset, this, arg1);
}

void mmMultiCR::Score(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x1F530_Offset, this, arg1);
}

i32 mmMultiCR::SelectTeams()
{
    return stub<thiscall_t<i32, mmMultiCR*>>(0x1D330_Offset, this);
}

void mmMultiCR::SendChangeSet(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x1F350_Offset, this, arg1);
}

void mmMultiCR::SendGameState(u32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, u32>>(0x1F1C0_Offset, this, arg1);
}

void mmMultiCR::SendGoldAck(u32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, u32>>(0x1F2C0_Offset, this, arg1);
}

void mmMultiCR::SendGoldDeliver()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1F300_Offset, this);
}

void mmMultiCR::SendGoldDrop(class Vector3 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, class Vector3>>(0x1F270_Offset, this, arg1);
}

void mmMultiCR::SendLimitReached(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x1F390_Offset, this, arg1);
}

void mmMultiCR::SendSetup(u32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, u32>>(0x1F260_Offset, this, arg1);
}

void mmMultiCR::SendTimeWarning(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, i32>>(0x1F3D0_Offset, this, arg1);
}

void mmMultiCR::StealGold(class mmCar* arg1)
{
    return stub<thiscall_t<void, mmMultiCR*, class mmCar*>>(0x1D8C0_Offset, this, arg1);
}

void mmMultiCR::UpdateBank()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1DFA0_Offset, this);
}

void mmMultiCR::UpdateGold()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1DC20_Offset, this);
}

void mmMultiCR::UpdateHUD()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1F410_Offset, this);
}

void mmMultiCR::UpdateHideout()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1DE50_Offset, this);
}

void mmMultiCR::UpdateLimit()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1E0F0_Offset, this);
}

void mmMultiCR::UpdateTimeWarning()
{
    return stub<thiscall_t<void, mmMultiCR*>>(0x1EFC0_Offset, this);
}
