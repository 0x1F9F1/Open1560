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

#include "multicircuit.h"

mmMultiCircuit::mmMultiCircuit()
{
    unimplemented();
}

mmMultiCircuit::~mmMultiCircuit()
{
    unimplemented();
}

void mmMultiCircuit::GameMessage(struct NETGAME_MSG* arg1)
{
    return stub<thiscall_t<void, mmMultiCircuit*, struct NETGAME_MSG*>>(0x1B9C0_Offset, this, arg1);
}

class MetaClass* mmMultiCircuit::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmMultiCircuit*>>(0x1BDE0_Offset, this);
}

class mmWaypoints* mmMultiCircuit::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmMultiCircuit*>>(0x1BFA0_Offset, this);
}

i32 mmMultiCircuit::Init()
{
    return stub<thiscall_t<i32, mmMultiCircuit*>>(0x1A9E0_Offset, this);
}

void mmMultiCircuit::InitGameObjects()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x1ABC0_Offset, this);
}

void mmMultiCircuit::InitHUD()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x1AB70_Offset, this);
}

void mmMultiCircuit::InitMyPlayer()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x1AB00_Offset, this);
}

void mmMultiCircuit::InitNetworkPlayers()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x1AE30_Offset, this);
}

void mmMultiCircuit::Reset()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x1B190_Offset, this);
}

void mmMultiCircuit::SystemMessage(struct NETSYS_MSG* arg1)
{
    return stub<thiscall_t<void, mmMultiCircuit*, struct NETSYS_MSG*>>(0x1B830_Offset, this, arg1);
}

void mmMultiCircuit::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCircuit*, i32>>(0x1B820_Offset, this, arg1);
}

void mmMultiCircuit::UpdateGame()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x1B270_Offset, this);
}

void mmMultiCircuit::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCircuit*, i32>>(0x1B230_Offset, this, arg1);
}

void mmMultiCircuit::DeclareFields()
{
    return stub<cdecl_t<void>>(0x1BC60_Offset);
}

void mmMultiCircuit::SendPlayerFinish()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x1BC20_Offset, this);
}

define_dummy_symbol(mmgame_multicircuit);
