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

define_dummy_symbol(mmgame_multiblitz);

#include "multiblitz.h"

mmMultiBlitz::mmMultiBlitz()
{
    unimplemented();
}

mmMultiBlitz::~mmMultiBlitz()
{
    unimplemented();
}

void mmMultiBlitz::GameMessage(struct NETGAME_MSG* arg1)
{
    return stub<thiscall_t<void, mmMultiBlitz*, struct NETGAME_MSG*>>(0x41A1C0, this, arg1);
}

class MetaClass* mmMultiBlitz::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmMultiBlitz*>>(0x41A6D0, this);
}

class mmWaypoints* mmMultiBlitz::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmMultiBlitz*>>(0x41A8A0, this);
}

i32 mmMultiBlitz::Init()
{
    return stub<thiscall_t<i32, mmMultiBlitz*>>(0x419010, this);
}

void mmMultiBlitz::InitGameObjects()
{
    return stub<thiscall_t<void, mmMultiBlitz*>>(0x419230, this);
}

void mmMultiBlitz::InitHUD()
{
    return stub<thiscall_t<void, mmMultiBlitz*>>(0x4191B0, this);
}

void mmMultiBlitz::InitMyPlayer()
{
    return stub<thiscall_t<void, mmMultiBlitz*>>(0x419140, this);
}

void mmMultiBlitz::InitNetworkPlayers()
{
    return stub<thiscall_t<void, mmMultiBlitz*>>(0x4194C0, this);
}

void mmMultiBlitz::PlayTimerWarning(f32 arg1)
{
    return stub<thiscall_t<void, mmMultiBlitz*, f32>>(0x41A470, this, arg1);
}

void mmMultiBlitz::Reset()
{
    return stub<thiscall_t<void, mmMultiBlitz*>>(0x419820, this);
}

void mmMultiBlitz::SystemMessage(struct NETSYS_MSG* arg1)
{
    return stub<thiscall_t<void, mmMultiBlitz*, struct NETSYS_MSG*>>(0x41A030, this, arg1);
}

void mmMultiBlitz::UpdateGame()
{
    return stub<thiscall_t<void, mmMultiBlitz*>>(0x419910, this);
}

void mmMultiBlitz::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmMultiBlitz*, i32>>(0x4198D0, this, arg1);
}

void mmMultiBlitz::DeclareFields()
{
    return stub<cdecl_t<void>>(0x41A550);
}

void mmMultiBlitz::SendPlayerFinish()
{
    return stub<thiscall_t<void, mmMultiBlitz*>>(0x41A420, this);
}
