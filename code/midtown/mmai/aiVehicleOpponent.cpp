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

define_dummy_symbol(mmai_aiVehicleOpponent);

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
    return stub<thiscall_t<class MetaClass*, aiVehicleOpponent*>>(0x44E670, this);
}

void aiVehicleOpponent::AddWidget(class Bank* arg1)
{
    return stub<thiscall_t<void, aiVehicleOpponent*, class Bank*>>(0x44E490, this, arg1);
}

void aiVehicleOpponent::AssignSounds(
    class AudSound* arg1, class AudSound* arg2, class mmOpponentImpactAudio* arg3, class AudSound* arg4)
{
    return stub<thiscall_t<void, aiVehicleOpponent*, class AudSound*, class AudSound*, class mmOpponentImpactAudio*,
        class AudSound*>>(0x44E4B0, this, arg1, arg2, arg3, arg4);
}

void aiVehicleOpponent::DrawDamage()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x44E2A0, this);
}

void aiVehicleOpponent::DrawId()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x44E2B0, this);
}

void aiVehicleOpponent::DrawTargetPt()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x44E130, this);
}

void aiVehicleOpponent::Dump()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x44E060, this);
}

class mmOpponentCarAudio* aiVehicleOpponent::GetCarAudioPtr()
{
    return stub<thiscall_t<class mmOpponentCarAudio*, aiVehicleOpponent*>>(0x44E420, this);
}

f32 aiVehicleOpponent::GetDistanceToPlayer2()
{
    return stub<thiscall_t<f32, aiVehicleOpponent*>>(0x44E3A0, this);
}

i32 aiVehicleOpponent::GetEngineSoundIndex()
{
    return stub<thiscall_t<i32, aiVehicleOpponent*>>(0x44E120, this);
}

void aiVehicleOpponent::Init(i32 arg1, class aiRaceData* arg2, char* arg3)
{
    return stub<thiscall_t<void, aiVehicleOpponent*, i32, class aiRaceData*, char*>>(0x44DC00, this, arg1, arg2, arg3);
}

void aiVehicleOpponent::Reset()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x44DE10, this);
}

void aiVehicleOpponent::SetAudioCloserMinDistMult(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleOpponent*, f32>>(0x44E400, this, arg1);
}

void aiVehicleOpponent::SetAudioMaxDistance(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleOpponent*, f32>>(0x44E3D0, this, arg1);
}

void aiVehicleOpponent::SetAudioMinDistance(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleOpponent*, f32>>(0x44E3B0, this, arg1);
}

i32 aiVehicleOpponent::Type()
{
    return stub<thiscall_t<i32, aiVehicleOpponent*>>(0x44E7D0, this);
}

void aiVehicleOpponent::UnAssignSounds()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x44E100, this);
}

void aiVehicleOpponent::Update()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x44DED0, this);
}

void aiVehicleOpponent::UpdateAudio()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x44E300, this);
}

void aiVehicleOpponent::DeclareFields()
{
    return stub<cdecl_t<void>>(0x44E4E0);
}

void aiVehicleOpponent::AddToAiAudMgr()
{
    return stub<thiscall_t<void, aiVehicleOpponent*>>(0x44E430, this);
}
