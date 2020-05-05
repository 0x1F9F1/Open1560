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

define_dummy_symbol(mmgame_gamemulti);

#include "gamemulti.h"

mmGameMulti::mmGameMulti()
{
    unimplemented();
}

mmGameMulti::~mmGameMulti()
{
    unimplemented(arg1);
}

void mmGameMulti::InitNetworkPlayers()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x - 400000_Offset, this);
}

void mmGameMulti::InitRoster()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x31960_Offset, this);
}

void mmGameMulti::SystemMessage(struct NETSYS_MSG* arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, struct NETSYS_MSG*>>(0x - 400000_Offset, this, arg1);
}

void mmGameMulti::GameMessage(struct NETGAME_MSG* arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, struct NETGAME_MSG*>>(0x - 400000_Offset, this, arg1);
}

void mmGameMulti::ActivateMapNetObject(i32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, i32>>(0x32030_Offset, this, arg1);
}

void mmGameMulti::BootPlayerCB(void* arg1, void* arg2)
{
    return stub<thiscall_t<void, mmGameMulti*, void*, void*>>(0x32410_Offset, this, arg1, arg2);
}

void mmGameMulti::BootStrapCars()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x31480_Offset, this);
}

void mmGameMulti::ClearNetObjects()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x316A0_Offset, this);
}

void mmGameMulti::DeactivateMapNetObject(i32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, i32>>(0x32000_Offset, this, arg1);
}

void mmGameMulti::DropThruCityHandler()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x30A90_Offset, this);
}

void mmGameMulti::FinishMessage(i32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, i32>>(0x32350_Offset, this, arg1);
}

void mmGameMulti::GameMessageCB(void* arg1, void* arg2)
{
    return stub<thiscall_t<void, mmGameMulti*, void*, void*>>(0x31100_Offset, this, arg1, arg2);
}

class MetaClass* mmGameMulti::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmGameMulti*>>(0x325B0_Offset, this);
}

void mmGameMulti::HitWaterHandler()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x309A0_Offset, this);
}

i32 mmGameMulti::Init()
{
    return stub<thiscall_t<i32, mmGameMulti*>>(0x30870_Offset, this);
}

void mmGameMulti::InitGameStrings()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x30AA0_Offset, this);
}

void mmGameMulti::InitOtherPlayers()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x316E0_Offset, this);
}

void mmGameMulti::NextRace()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x1A890_Offset, this);
}

i32 mmGameMulti::ParseChatMessage(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmGameMulti*, char*, i32>>(0x32160_Offset, this, arg1, arg2);
}

void mmGameMulti::QuitNetwork()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x32140_Offset, this);
}

void mmGameMulti::RegisterMapNetObjects(i32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, i32>>(0x31EE0_Offset, this, arg1);
}

void mmGameMulti::Reset()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x31620_Offset, this);
}

void mmGameMulti::SendBootMsg(u32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, u32>>(0x324D0_Offset, this, arg1);
}

void mmGameMulti::SendChatMessage(char* arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, char*>>(0x321D0_Offset, this, arg1);
}

void mmGameMulti::SendMsg(i32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, i32>>(0x324A0_Offset, this, arg1);
}

void mmGameMulti::SendToChatMessage(char* arg1, u32 arg2)
{
    return stub<thiscall_t<void, mmGameMulti*, char*, u32>>(0x32290_Offset, this, arg1, arg2);
}

void mmGameMulti::SystemMessageCB(void* arg1, void* arg2)
{
    return stub<thiscall_t<void, mmGameMulti*, void*, void*>>(0x30EF0_Offset, this, arg1, arg2);
}

void mmGameMulti::Update()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x319F0_Offset, this);
}

void mmGameMulti::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, i32>>(0x31ED0_Offset, this, arg1);
}

void mmGameMulti::UpdateGame()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x31A10_Offset, this);
}

void mmGameMulti::UpdateNetWorkAudio()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x32450_Offset, this);
}

void mmGameMulti::UpdateScore()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x31AA0_Offset, this);
}

void mmGameMulti::DeclareFields()
{
    return stub<cdecl_t<void>>(0x32510_Offset);
}

void mmGameMulti::DisableRacers()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x320F0_Offset, this);
}

void mmGameMulti::EnableRacers()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x32070_Offset, this);
}

void mmGameMulti::StartXYZ(i32 arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, mmGameMulti*, i32, class Vector3&, class Vector3&, f32, f32>>(
        0x30CC0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}
