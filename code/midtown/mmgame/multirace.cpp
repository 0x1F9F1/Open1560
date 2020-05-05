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

define_dummy_symbol(mmgame_multirace);

#include "multirace.h"

mmMultiRace::mmMultiRace()
{
    unimplemented();
}

mmMultiRace::~mmMultiRace()
{
    unimplemented(arg1);
}

void mmMultiRace::ChangePlayerData()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x20480_Offset, this);
}

void mmMultiRace::GameMessage(struct NETGAME_MSG* arg1)
{
    return stub<thiscall_t<void, mmMultiRace*, struct NETGAME_MSG*>>(0x20EE0_Offset, this, arg1);
}

class MetaClass* mmMultiRace::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmMultiRace*>>(0x21400_Offset, this);
}

class mmWaypoints* mmMultiRace::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmMultiRace*>>(0x215C0_Offset, this);
}

i32 mmMultiRace::Init()
{
    return stub<thiscall_t<i32, mmMultiRace*>>(0x1FA60_Offset, this);
}

void mmMultiRace::InitGameObjects()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x1FC70_Offset, this);
}

void mmMultiRace::InitHUD()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x1FC10_Offset, this);
}

void mmMultiRace::InitMyPlayer()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x1FBA0_Offset, this);
}

void mmMultiRace::InitNetworkPlayers()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x1FF40_Offset, this);
}

void mmMultiRace::Reset()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x20370_Offset, this);
}

void mmMultiRace::SystemMessage(struct NETSYS_MSG* arg1)
{
    return stub<thiscall_t<void, mmMultiRace*, struct NETSYS_MSG*>>(0x20D10_Offset, this, arg1);
}

void mmMultiRace::UpdateGame()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x20510_Offset, this);
}

void mmMultiRace::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiRace*, i32>>(0x204D0_Offset, this, arg1);
}

void mmMultiRace::DeclareFields()
{
    return stub<cdecl_t<void>>(0x21280_Offset);
}

void mmMultiRace::SendPlayerFinish()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x21240_Offset, this);
}
