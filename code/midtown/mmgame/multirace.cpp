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
    return stub<thiscall_t<void, mmMultiRace*>>(0x420480, this);
}

void mmMultiRace::GameMessage(struct NETGAME_MSG* arg1)
{
    return stub<thiscall_t<void, mmMultiRace*, struct NETGAME_MSG*>>(0x420EE0, this, arg1);
}

class MetaClass* mmMultiRace::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmMultiRace*>>(0x421400, this);
}

class mmWaypoints* mmMultiRace::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmMultiRace*>>(0x4215C0, this);
}

i32 mmMultiRace::Init()
{
    return stub<thiscall_t<i32, mmMultiRace*>>(0x41FA60, this);
}

void mmMultiRace::InitGameObjects()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x41FC70, this);
}

void mmMultiRace::InitHUD()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x41FC10, this);
}

void mmMultiRace::InitMyPlayer()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x41FBA0, this);
}

void mmMultiRace::InitNetworkPlayers()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x41FF40, this);
}

void mmMultiRace::Reset()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x420370, this);
}

void mmMultiRace::SystemMessage(struct NETSYS_MSG* arg1)
{
    return stub<thiscall_t<void, mmMultiRace*, struct NETSYS_MSG*>>(0x420D10, this, arg1);
}

void mmMultiRace::UpdateGame()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x420510, this);
}

void mmMultiRace::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiRace*, i32>>(0x4204D0, this, arg1);
}

void mmMultiRace::DeclareFields()
{
    return stub<cdecl_t<void>>(0x421280);
}

void mmMultiRace::SendPlayerFinish()
{
    return stub<thiscall_t<void, mmMultiRace*>>(0x421240, this);
}
