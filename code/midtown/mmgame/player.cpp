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

#include "player.h"

mmPlayer::mmPlayer()
{
    unimplemented();
}

mmPlayer::~mmPlayer()
{
    unimplemented();
}

void mmPlayer::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmPlayer*, class Bank*>>(0x2C590_Offset, this, arg1);
}

void mmPlayer::AfterLoad()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2A380_Offset, this);
}

void mmPlayer::BeforeSave()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2A370_Offset, this);
}

void mmPlayer::EnableRegen(i32 arg1)
{
    return stub<thiscall_t<void, mmPlayer*, i32>>(0x2C4C0_Offset, this, arg1);
}

class MetaClass* mmPlayer::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPlayer*>>(0x2D1B0_Offset, this);
}

void mmPlayer::Init(char* arg1, char* arg2, class mmGame* arg3)
{
    return stub<thiscall_t<void, mmPlayer*, char*, char*, class mmGame*>>(0x2A520_Offset, this, arg1, arg2, arg3);
}

i32 mmPlayer::IsMaxDamaged()
{
    return stub<thiscall_t<i32, mmPlayer*>>(0x2C490_Offset, this);
}

i32 mmPlayer::IsPOV()
{
    return stub<thiscall_t<i32, mmPlayer*>>(0x2AC10_Offset, this);
}

void mmPlayer::ReInit(char* arg1)
{
    return stub<thiscall_t<void, mmPlayer*, char*>>(0x2A390_Offset, this, arg1);
}

void mmPlayer::Reset()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2B440_Offset, this);
}

void mmPlayer::ResetDamage()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2C4E0_Offset, this);
}

void mmPlayer::SetCamInterest(class asInertialCS* arg1)
{
    return stub<thiscall_t<void, mmPlayer*, class asInertialCS*>>(0x2C420_Offset, this, arg1);
}

void mmPlayer::SetMirrorFOV()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2A9A0_Offset, this);
}

void mmPlayer::SetPostRaceCam()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2AAF0_Offset, this);
}

void mmPlayer::SetPreRaceCam()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2A9D0_Offset, this);
}

void mmPlayer::SetSteering(f32 arg1)
{
    return stub<thiscall_t<void, mmPlayer*, f32>>(0x2B5F0_Offset, this, arg1);
}

void mmPlayer::SetWideFOV(i32 arg1)
{
    return stub<thiscall_t<void, mmPlayer*, i32>>(0x2AC60_Offset, this, arg1);
}

void mmPlayer::ToggleCam()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2AE10_Offset, this);
}

void mmPlayer::ToggleDash()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2B0E0_Offset, this);
}

void mmPlayer::ToggleExternalView()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2AF30_Offset, this);
}

void mmPlayer::ToggleWideFOV()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2ADF0_Offset, this);
}

void mmPlayer::Update()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2BBC0_Offset, this);
}

void mmPlayer::UpdateHOG()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2B310_Offset, this);
}

void mmPlayer::UpdateRegen()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x2C4F0_Offset, this);
}

void mmPlayer::DeclareFields()
{
    return stub<cdecl_t<void>>(0x2CD40_Offset);
}

define_dummy_symbol(mmgame_player);
