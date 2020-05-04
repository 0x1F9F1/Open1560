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

#include "wphud.h"

mmWPHUD::mmWPHUD()
{
    unimplemented();
}

mmWPHUD::~mmWPHUD()
{
    unimplemented();
}

void mmWPHUD::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmWPHUD*, class Bank*>>(0x24780_Offset, this, arg1);
}

void mmWPHUD::Cull()
{
    return stub<thiscall_t<void, mmWPHUD*>>(0x24770_Offset, this);
}

void mmWPHUD::Init(i32 arg1, i32* arg2, i32* arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmWPHUD*, i32, i32*, i32*, i32>>(0x243F0_Offset, this, arg1, arg2, arg3, arg4);
}

void mmWPHUD::Reset()
{
    return stub<thiscall_t<void, mmWPHUD*>>(0x246E0_Offset, this);
}

void mmWPHUD::SetStandings(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmWPHUD*, i32, i32>>(0x243B0_Offset, this, arg1, arg2);
}

void mmWPHUD::SetWPCleared()
{
    return stub<thiscall_t<void, mmWPHUD*>>(0x24360_Offset, this);
}

void mmWPHUD::Update()
{
    return stub<thiscall_t<void, mmWPHUD*>>(0x24730_Offset, this);
}

mmCircuitHUD::mmCircuitHUD()
{
    unimplemented();
}

mmCircuitHUD::~mmCircuitHUD()
{
    unimplemented();
}

void mmCircuitHUD::Init()
{
    return stub<thiscall_t<void, mmCircuitHUD*>>(0x249A0_Offset, this);
}

void mmCircuitHUD::Reset()
{
    return stub<thiscall_t<void, mmCircuitHUD*>>(0x25090_Offset, this);
}

void mmCircuitHUD::SetLapTime(i32 arg1, f32 arg2, char* arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmCircuitHUD*, i32, f32, char*, i32>>(0x24FB0_Offset, this, arg1, arg2, arg3, arg4);
}

void mmCircuitHUD::SetStandings(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCircuitHUD*, i32, i32>>(0x24F60_Offset, this, arg1, arg2);
}

void mmCircuitHUD::SetWPCleared(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCircuitHUD*, i32, i32>>(0x25050_Offset, this, arg1, arg2);
}

void mmCircuitHUD::Update()
{
    return stub<thiscall_t<void, mmCircuitHUD*>>(0x24F50_Offset, this);
}

mmCRHUD::mmCRHUD()
{
    unimplemented();
}

mmCRHUD::~mmCRHUD()
{
    unimplemented();
}

void mmCRHUD::ActivateGold()
{
    return stub<thiscall_t<void, mmCRHUD*>>(0x26090_Offset, this);
}

void mmCRHUD::ActivateRosterGold(u32 arg1)
{
    return stub<thiscall_t<void, mmCRHUD*, u32>>(0x260B0_Offset, this, arg1);
}

void mmCRHUD::AddPlayer(char* arg1, u32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, mmCRHUD*, char*, u32, i32, u32>>(0x25C50_Offset, this, arg1, arg2, arg3, arg4);
}

void mmCRHUD::DeactivateGold()
{
    return stub<thiscall_t<void, mmCRHUD*>>(0x260A0_Offset, this);
}

void mmCRHUD::DeactivateRosterGold()
{
    return stub<thiscall_t<void, mmCRHUD*>>(0x26100_Offset, this);
}

void mmCRHUD::Init(class asLinearCS* arg1, char* arg2, enum mmCRGameClass arg3)
{
    return stub<thiscall_t<void, mmCRHUD*, class asLinearCS*, char*, enum mmCRGameClass>>(
        0x25410_Offset, this, arg1, arg2, arg3);
}

void mmCRHUD::RemovePlayer(u32 arg1)
{
    return stub<thiscall_t<void, mmCRHUD*, u32>>(0x25F20_Offset, this, arg1);
}

void mmCRHUD::Reset()
{
    return stub<thiscall_t<void, mmCRHUD*>>(0x26180_Offset, this);
}

void mmCRHUD::SetBlueScore(i32 arg1)
{
    return stub<thiscall_t<void, mmCRHUD*, i32>>(0x26190_Offset, this, arg1);
}

void mmCRHUD::SetName(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCRHUD*, char*, i32>>(0x25E30_Offset, this, arg1, arg2);
}

void mmCRHUD::SetRedScore(i32 arg1)
{
    return stub<thiscall_t<void, mmCRHUD*, i32>>(0x261D0_Offset, this, arg1);
}

void mmCRHUD::SetScore(char* arg1)
{
    return stub<thiscall_t<void, mmCRHUD*, char*>>(0x25E10_Offset, this, arg1);
}

void mmCRHUD::SetScore(u32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCRHUD*, u32, i32>>(0x25EB0_Offset, this, arg1, arg2);
}

void mmCRHUD::ToggleScores()
{
    return stub<thiscall_t<void, mmCRHUD*>>(0x25C20_Offset, this);
}

void mmCRHUD::UnPackColor(u32 arg1, class Vector4& arg2)
{
    return stub<thiscall_t<void, mmCRHUD*, u32, class Vector4&>>(0x25D90_Offset, this, arg1, arg2);
}

void mmCRHUD::Update()
{
    return stub<thiscall_t<void, mmCRHUD*>>(0x26160_Offset, this);
}

void mmCRHUD::UpdateGold()
{
    return stub<thiscall_t<void, mmCRHUD*>>(0x26140_Offset, this);
}

define_dummy_symbol(mmgame_wphud);
