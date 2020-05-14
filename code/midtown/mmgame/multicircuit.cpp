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

define_dummy_symbol(mmgame_multicircuit);

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
    return stub<thiscall_t<void, mmMultiCircuit*, struct NETGAME_MSG*>>(0x41B9C0, this, arg1);
}

class MetaClass* mmMultiCircuit::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmMultiCircuit*>>(0x41BDE0, this);
}

class mmWaypoints* mmMultiCircuit::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmMultiCircuit*>>(0x41BFA0, this);
}

i32 mmMultiCircuit::Init()
{
    return stub<thiscall_t<i32, mmMultiCircuit*>>(0x41A9E0, this);
}

void mmMultiCircuit::InitGameObjects()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x41ABC0, this);
}

void mmMultiCircuit::InitHUD()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x41AB70, this);
}

void mmMultiCircuit::InitMyPlayer()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x41AB00, this);
}

void mmMultiCircuit::InitNetworkPlayers()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x41AE30, this);
}

void mmMultiCircuit::Reset()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x41B190, this);
}

void mmMultiCircuit::SystemMessage(struct NETSYS_MSG* arg1)
{
    return stub<thiscall_t<void, mmMultiCircuit*, struct NETSYS_MSG*>>(0x41B830, this, arg1);
}

void mmMultiCircuit::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCircuit*, i32>>(0x41B820, this, arg1);
}

void mmMultiCircuit::UpdateGame()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x41B270, this);
}

void mmMultiCircuit::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiCircuit*, i32>>(0x41B230, this, arg1);
}

void mmMultiCircuit::DeclareFields()
{
    return stub<cdecl_t<void>>(0x41BC60);
}

void mmMultiCircuit::SendPlayerFinish()
{
    return stub<thiscall_t<void, mmMultiCircuit*>>(0x41BC20, this);
}
