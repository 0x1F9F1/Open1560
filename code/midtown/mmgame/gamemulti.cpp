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
    unimplemented();
}

void mmGameMulti::InitRoster()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x431960, this);
}

void mmGameMulti::ActivateMapNetObject(i32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, i32>>(0x432030, this, arg1);
}

void mmGameMulti::BootPlayerCB(void* arg1, void* arg2)
{
    return stub<thiscall_t<void, mmGameMulti*, void*, void*>>(0x432410, this, arg1, arg2);
}

void mmGameMulti::BootStrapCars()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x431480, this);
}

void mmGameMulti::ClearNetObjects()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x4316A0, this);
}

void mmGameMulti::DeactivateMapNetObject(i32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, i32>>(0x432000, this, arg1);
}

void mmGameMulti::DropThruCityHandler()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x430A90, this);
}

void mmGameMulti::FinishMessage(i32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, i32>>(0x432350, this, arg1);
}

void mmGameMulti::GameMessageCB(void* arg1, void* arg2)
{
    return stub<thiscall_t<void, mmGameMulti*, void*, void*>>(0x431100, this, arg1, arg2);
}

class MetaClass* mmGameMulti::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmGameMulti*>>(0x4325B0, this);
}

void mmGameMulti::HitWaterHandler()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x4309A0, this);
}

i32 mmGameMulti::Init()
{
    return stub<thiscall_t<i32, mmGameMulti*>>(0x430870, this);
}

void mmGameMulti::InitGameStrings()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x430AA0, this);
}

void mmGameMulti::InitOtherPlayers()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x4316E0, this);
}

void mmGameMulti::NextRace()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x41A890, this);
}

i32 mmGameMulti::ParseChatMessage(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmGameMulti*, char*, i32>>(0x432160, this, arg1, arg2);
}

void mmGameMulti::QuitNetwork()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x432140, this);
}

void mmGameMulti::RegisterMapNetObjects(i32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, i32>>(0x431EE0, this, arg1);
}

void mmGameMulti::Reset()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x431620, this);
}

void mmGameMulti::SendBootMsg(u32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, u32>>(0x4324D0, this, arg1);
}

void mmGameMulti::SendChatMessage(char* arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, char*>>(0x4321D0, this, arg1);
}

void mmGameMulti::SendMsg(i32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, i32>>(0x4324A0, this, arg1);
}

void mmGameMulti::SendToChatMessage(char* arg1, u32 arg2)
{
    return stub<thiscall_t<void, mmGameMulti*, char*, u32>>(0x432290, this, arg1, arg2);
}

void mmGameMulti::SystemMessageCB(void* arg1, void* arg2)
{
    return stub<thiscall_t<void, mmGameMulti*, void*, void*>>(0x430EF0, this, arg1, arg2);
}

void mmGameMulti::Update()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x4319F0, this);
}

void mmGameMulti::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmGameMulti*, i32>>(0x431ED0, this, arg1);
}

void mmGameMulti::UpdateGame()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x431A10, this);
}

void mmGameMulti::UpdateNetWorkAudio()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x432450, this);
}

void mmGameMulti::UpdateScore()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x431AA0, this);
}

void mmGameMulti::DeclareFields()
{
    return stub<cdecl_t<void>>(0x432510);
}

void mmGameMulti::DisableRacers()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x4320F0, this);
}

void mmGameMulti::EnableRacers()
{
    return stub<thiscall_t<void, mmGameMulti*>>(0x432070, this);
}

void mmGameMulti::StartXYZ(i32 arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, mmGameMulti*, i32, class Vector3&, class Vector3&, f32, f32>>(
        0x430CC0, this, arg1, arg2, arg3, arg4, arg5);
}
