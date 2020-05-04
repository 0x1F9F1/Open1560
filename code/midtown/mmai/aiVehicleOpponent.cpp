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

#include "aiVehicleOpponent.h"

aiVehicleOpponent::aiVehicleOpponent()
{
    unimplemented();
}

aiVehicleOpponent::~aiVehicleOpponent()
{
    unimplemented();
}

class MetaClass* aiVehicleOpponent::GetClass()
{
    return stub<thiscall_t<class MetaClass*, aiVehicleOpponent*>>(0x4E670_Offset, this);
}

void aiVehicleOpponent::AddWidget(class Bank* arg1)
{
    return stub<thiscall_t<void, aiVehicleOpponent*, class Bank*>>(0x4E490_Offset, this, arg1);
}

void aiVehicleOpponent::AssignSounds(
    class AudSound* arg1, class AudSound* arg2, class mmOpponentImpactAudio* arg3, class AudSound* arg4)
{
    return stub<thiscall_t<void, aiVehicleOpponent*, class AudSound*, class AudSound*, class mmOpponentImpactAudio*,
        class AudSound*>>(0x4E4B0_Offset, this, arg1, arg2, arg3, arg4);
}

void aiVehicleOpponent::DrawDamage()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x4E2A0_Offset, this);
}

void aiVehicleOpponent::DrawId()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x4E2B0_Offset, this);
}

void aiVehicleOpponent::DrawTargetPt()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x4E130_Offset, this);
}

void aiVehicleOpponent::Dump()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x4E060_Offset, this);
}

class mmOpponentCarAudio* aiVehicleOpponent::GetCarAudioPtr()
{
    return stub<thiscall_t<class mmOpponentCarAudio*, aiVehicleOpponent*>>(0x4E420_Offset, this);
}

f32 aiVehicleOpponent::GetDistanceToPlayer2()
{
    return stub<thiscall_t<f32, aiVehicleOpponent*>>(0x4E3A0_Offset, this);
}

i32 aiVehicleOpponent::GetEngineSoundIndex()
{
    return stub<thiscall_t<i32, aiVehicleOpponent*>>(0x4E120_Offset, this);
}

void aiVehicleOpponent::Init(i32 arg1, class aiRaceData* arg2, char* arg3)
{
    return stub<thiscall_t<void, aiVehicleOpponent*, i32, class aiRaceData*, char*>>(
        0x4DC00_Offset, this, arg1, arg2, arg3);
}

void aiVehicleOpponent::Reset()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x4DE10_Offset, this);
}

void aiVehicleOpponent::SetAudioCloserMinDistMult(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleOpponent*, f32>>(0x4E400_Offset, this, arg1);
}

void aiVehicleOpponent::SetAudioMaxDistance(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleOpponent*, f32>>(0x4E3D0_Offset, this, arg1);
}

void aiVehicleOpponent::SetAudioMinDistance(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleOpponent*, f32>>(0x4E3B0_Offset, this, arg1);
}

i32 aiVehicleOpponent::Type()
{
    return stub<thiscall_t<i32, aiVehicleOpponent*>>(0x4E7D0_Offset, this);
}

void aiVehicleOpponent::UnAssignSounds()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x4E100_Offset, this);
}

void aiVehicleOpponent::Update()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x4DED0_Offset, this);
}

void aiVehicleOpponent::UpdateAudio()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x4E300_Offset, this);
}

void aiVehicleOpponent::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4E4E0_Offset);
}

void aiVehicleOpponent::AddToAiAudMgr()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x4E430_Offset, this);
}

define_dummy_symbol(mmai_aiVehicleOpponent);
