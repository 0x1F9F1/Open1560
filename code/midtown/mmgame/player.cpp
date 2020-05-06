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

define_dummy_symbol(mmgame_player);

#include "player.h"

mmPlayer::mmPlayer()
{
    unimplemented();
}

mmPlayer::~mmPlayer()
{
    unimplemented(arg1);
}

void mmPlayer::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmPlayer*, class Bank*>>(0x42C590, this, arg1);
}

void mmPlayer::AfterLoad()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42A380, this);
}

void mmPlayer::BeforeSave()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42A370, this);
}

void mmPlayer::EnableRegen(i32 arg1)
{
    return stub<thiscall_t<void, mmPlayer*, i32>>(0x42C4C0, this, arg1);
}

class MetaClass* mmPlayer::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPlayer*>>(0x42D1B0, this);
}

void mmPlayer::Init(char* arg1, char* arg2, class mmGame* arg3)
{
    return stub<thiscall_t<void, mmPlayer*, char*, char*, class mmGame*>>(0x42A520, this, arg1, arg2, arg3);
}

i32 mmPlayer::IsMaxDamaged()
{
    return stub<thiscall_t<i32, mmPlayer*>>(0x42C490, this);
}

i32 mmPlayer::IsPOV()
{
    return stub<thiscall_t<i32, mmPlayer*>>(0x42AC10, this);
}

void mmPlayer::ReInit(char* arg1)
{
    return stub<thiscall_t<void, mmPlayer*, char*>>(0x42A390, this, arg1);
}

void mmPlayer::Reset()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42B440, this);
}

void mmPlayer::ResetDamage()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42C4E0, this);
}

void mmPlayer::SetCamInterest(class asInertialCS* arg1)
{
    return stub<thiscall_t<void, mmPlayer*, class asInertialCS*>>(0x42C420, this, arg1);
}

void mmPlayer::SetMirrorFOV()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42A9A0, this);
}

void mmPlayer::SetPostRaceCam()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42AAF0, this);
}

void mmPlayer::SetPreRaceCam()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42A9D0, this);
}

void mmPlayer::SetSteering(f32 arg1)
{
    return stub<thiscall_t<void, mmPlayer*, f32>>(0x42B5F0, this, arg1);
}

void mmPlayer::SetWideFOV(i32 arg1)
{
    return stub<thiscall_t<void, mmPlayer*, i32>>(0x42AC60, this, arg1);
}

void mmPlayer::ToggleCam()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42AE10, this);
}

void mmPlayer::ToggleDash()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42B0E0, this);
}

void mmPlayer::ToggleExternalView()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42AF30, this);
}

void mmPlayer::ToggleWideFOV()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42ADF0, this);
}

void mmPlayer::Update()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42BBC0, this);
}

void mmPlayer::UpdateHOG()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42B310, this);
}

void mmPlayer::UpdateRegen()
{
    return stub<thiscall_t<void, mmPlayer*>>(0x42C4F0, this);
}

void mmPlayer::DeclareFields()
{
    return stub<cdecl_t<void>>(0x42CD40);
}
