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

define_dummy_symbol(mmgame_wphud);

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
    return stub<thiscall_t<void, mmWPHUD*, class Bank*>>(0x424780, this, arg1);
}

void mmWPHUD::Cull()
{
    return stub<thiscall_t<void, mmWPHUD*>>(0x424770, this);
}

void mmWPHUD::Init(i32 arg1, i32* arg2, i32* arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmWPHUD*, i32, i32*, i32*, i32>>(0x4243F0, this, arg1, arg2, arg3, arg4);
}

void mmWPHUD::Reset()
{
    return stub<thiscall_t<void, mmWPHUD*>>(0x4246E0, this);
}

void mmWPHUD::SetStandings(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmWPHUD*, i32, i32>>(0x4243B0, this, arg1, arg2);
}

void mmWPHUD::SetWPCleared()
{
    return stub<thiscall_t<void, mmWPHUD*>>(0x424360, this);
}

void mmWPHUD::Update()
{
    return stub<thiscall_t<void, mmWPHUD*>>(0x424730, this);
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
    return stub<thiscall_t<void, mmCircuitHUD*>>(0x4249A0, this);
}

void mmCircuitHUD::Reset()
{
    return stub<thiscall_t<void, mmCircuitHUD*>>(0x425090, this);
}

void mmCircuitHUD::SetLapTime(i32 arg1, f32 arg2, char* arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmCircuitHUD*, i32, f32, char*, i32>>(0x424FB0, this, arg1, arg2, arg3, arg4);
}

void mmCircuitHUD::SetStandings(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCircuitHUD*, i32, i32>>(0x424F60, this, arg1, arg2);
}

void mmCircuitHUD::SetWPCleared(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCircuitHUD*, i32, i32>>(0x425050, this, arg1, arg2);
}

void mmCircuitHUD::Update()
{
    return stub<thiscall_t<void, mmCircuitHUD*>>(0x424F50, this);
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
    return stub<thiscall_t<void, mmCRHUD*>>(0x426090, this);
}

void mmCRHUD::ActivateRosterGold(u32 arg1)
{
    return stub<thiscall_t<void, mmCRHUD*, u32>>(0x4260B0, this, arg1);
}

void mmCRHUD::AddPlayer(char* arg1, u32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, mmCRHUD*, char*, u32, i32, u32>>(0x425C50, this, arg1, arg2, arg3, arg4);
}

void mmCRHUD::DeactivateGold()
{
    return stub<thiscall_t<void, mmCRHUD*>>(0x4260A0, this);
}

void mmCRHUD::DeactivateRosterGold()
{
    return stub<thiscall_t<void, mmCRHUD*>>(0x426100, this);
}

void mmCRHUD::Init(class asLinearCS* arg1, char* arg2, enum mmCRGameClass arg3)
{
    return stub<thiscall_t<void, mmCRHUD*, class asLinearCS*, char*, enum mmCRGameClass>>(
        0x425410, this, arg1, arg2, arg3);
}

void mmCRHUD::RemovePlayer(u32 arg1)
{
    return stub<thiscall_t<void, mmCRHUD*, u32>>(0x425F20, this, arg1);
}

void mmCRHUD::Reset()
{
    return stub<thiscall_t<void, mmCRHUD*>>(0x426180, this);
}

void mmCRHUD::SetBlueScore(i32 arg1)
{
    return stub<thiscall_t<void, mmCRHUD*, i32>>(0x426190, this, arg1);
}

void mmCRHUD::SetName(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCRHUD*, char*, i32>>(0x425E30, this, arg1, arg2);
}

void mmCRHUD::SetRedScore(i32 arg1)
{
    return stub<thiscall_t<void, mmCRHUD*, i32>>(0x4261D0, this, arg1);
}

void mmCRHUD::SetScore(char* arg1)
{
    return stub<thiscall_t<void, mmCRHUD*, char*>>(0x425E10, this, arg1);
}

void mmCRHUD::SetScore(u32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCRHUD*, u32, i32>>(0x425EB0, this, arg1, arg2);
}

void mmCRHUD::ToggleScores()
{
    return stub<thiscall_t<void, mmCRHUD*>>(0x425C20, this);
}

void mmCRHUD::UnPackColor(u32 arg1, class Vector4& arg2)
{
    return stub<thiscall_t<void, mmCRHUD*, u32, class Vector4&>>(0x425D90, this, arg1, arg2);
}

void mmCRHUD::Update()
{
    return stub<thiscall_t<void, mmCRHUD*>>(0x426160, this);
}

void mmCRHUD::UpdateGold()
{
    return stub<thiscall_t<void, mmCRHUD*>>(0x426140, this);
}
