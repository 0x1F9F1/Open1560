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

define_dummy_symbol(mmgame_singleblitz);

#include "singleblitz.h"

foobar::~foobar()
{
    unimplemented(arg1);
}

void foobar::Update()
{
    return stub<thiscall_t<void, foobar*>>(0x411EE0, this);
}

void foobar::UpdatePaused()
{
    return stub<thiscall_t<void, foobar*>>(0x411F10, this);
}

mmSingleBlitz::mmSingleBlitz()
{
    unimplemented();
}

mmSingleBlitz::~mmSingleBlitz()
{
    unimplemented(arg1);
}

class MetaClass* mmSingleBlitz::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmSingleBlitz*>>(0x4148B0, this);
}

class mmWaypoints* mmSingleBlitz::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmSingleBlitz*>>(0x414BE0, this);
}

void mmSingleBlitz::HitWaterHandler()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x413760, this);
}

i32 mmSingleBlitz::Init()
{
    return stub<thiscall_t<i32, mmSingleBlitz*>>(0x413060, this);
}

void mmSingleBlitz::InitGameObjects()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x4132D0, this);
}

void mmSingleBlitz::InitHUD()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x413250, this);
}

void mmSingleBlitz::InitMyPlayer()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x4131E0, this);
}

void mmSingleBlitz::InitOtherPlayers()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x413540, this);
}

void mmSingleBlitz::NextRace()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x4144F0, this);
}

void mmSingleBlitz::PlayTimerWarning(f32 arg1)
{
    return stub<thiscall_t<void, mmSingleBlitz*, f32>>(0x414660, this, arg1);
}

void mmSingleBlitz::Reset()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x413550, this);
}

void mmSingleBlitz::Update()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x413800, this);
}

void mmSingleBlitz::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmSingleBlitz*, i32>>(0x414BD0, this, arg1);
}

void mmSingleBlitz::UpdateGame()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x413860, this);
}

void mmSingleBlitz::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmSingleBlitz*, i32>>(0x413820, this, arg1);
}

void mmSingleBlitz::DeclareFields()
{
    return stub<cdecl_t<void>>(0x414740);
}

void mmSingleBlitz::DisableRacers()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x4136F0, this);
}

void mmSingleBlitz::EnableRacers()
{
    return stub<thiscall_t<void, mmSingleBlitz*>>(0x413660, this);
}

void mmSingleBlitz::FinishMessage(i32 arg1)
{
    return stub<thiscall_t<void, mmSingleBlitz*, i32>>(0x4143F0, this, arg1);
}

i32 mmSingleBlitz::ProgressCheck(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmSingleBlitz*, i32, i32>>(0x414420, this, arg1, arg2);
}

i32 mmSingleBlitz::RegisterFinish()
{
    return stub<thiscall_t<i32, mmSingleBlitz*>>(0x4140C0, this);
}
