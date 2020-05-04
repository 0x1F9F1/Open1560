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

#include "singleblitz.h"

foobar::~foobar()
{
    unimplemented();
}

void foobar::Update()
{
    return stub<thiscall_t<void, foobar*>>(0x11EE0_Offset, this);
}

void foobar::UpdatePaused()
{
    return stub<thiscall_t<void, foobar*>>(0x11F10_Offset, this);
}

mmSingleBlitz::mmSingleBlitz()
{
    unimplemented();
}

mmSingleBlitz::~mmSingleBlitz()
{
    unimplemented();
}

class MetaClass* mmSingleBlitz::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmSingleBlitz*>>(0x148B0_Offset, this);
}

class mmWaypoints* mmSingleBlitz::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmSingleBlitz*>>(0x14BE0_Offset, this);
}

void mmSingleBlitz::HitWaterHandler()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x13760_Offset, this);
}

i32 mmSingleBlitz::Init()
{
    return stub<thiscall_t<i32, mmSingleBlitz*>>(0x13060_Offset, this);
}

void mmSingleBlitz::InitGameObjects()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x132D0_Offset, this);
}

void mmSingleBlitz::InitHUD()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x13250_Offset, this);
}

void mmSingleBlitz::InitMyPlayer()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x131E0_Offset, this);
}

void mmSingleBlitz::InitOtherPlayers()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x13540_Offset, this);
}

void mmSingleBlitz::NextRace()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x144F0_Offset, this);
}

void mmSingleBlitz::PlayTimerWarning(f32 arg1)
{
    return stub<thiscall_t<void, mmSingleBlitz*, f32>>(0x14660_Offset, this, arg1);
}

void mmSingleBlitz::Reset()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x13550_Offset, this);
}

void mmSingleBlitz::Update()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x13800_Offset, this);
}

void mmSingleBlitz::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmSingleBlitz*, i32>>(0x14BD0_Offset, this, arg1);
}

void mmSingleBlitz::UpdateGame()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x13860_Offset, this);
}

void mmSingleBlitz::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmSingleBlitz*, i32>>(0x13820_Offset, this, arg1);
}

void mmSingleBlitz::DeclareFields()
{
    return stub<cdecl_t<void>>(0x14740_Offset);
}

void mmSingleBlitz::DisableRacers()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x136F0_Offset, this);
}

void mmSingleBlitz::EnableRacers()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x13660_Offset, this);
}

void mmSingleBlitz::FinishMessage(i32 arg1)
{
    return stub<thiscall_t<void, mmSingleBlitz*, i32>>(0x143F0_Offset, this, arg1);
}

i32 mmSingleBlitz::ProgressCheck(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmSingleBlitz*, i32, i32>>(0x14420_Offset, this, arg1, arg2);
}

i32 mmSingleBlitz::RegisterFinish()
{
    return stub<thiscall_t<i32, mmSingleBlitz*>>(0x140C0_Offset, this);
}

define_dummy_symbol(mmgame_singleblitz);
