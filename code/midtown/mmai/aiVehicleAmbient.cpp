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

define_dummy_symbol(mmai_aiVehicleAmbient);

#include "aiVehicleAmbient.h"

aiVehicleAmbient::aiVehicleAmbient()
{
    unimplemented();
}

aiVehicleAmbient::~aiVehicleAmbient()
{
    unimplemented();
}

void aiVehicleAmbient::AssignSounds(
    class AudSound* arg1, class AudSound* arg2, class AudSound* arg3, class mmOpponentImpactAudio* arg4)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, class AudSound*, class AudSound*, class AudSound*,
        class mmOpponentImpactAudio*>>(0x451000, this, arg1, arg2, arg3, arg4);
}

void aiVehicleAmbient::CalculateAudioPanning()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x44FCF0, this);
}

void aiVehicleAmbient::CalculateDistToPlayer2()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x44FBE0, this);
}

void aiVehicleAmbient::DrawBBox(i16 arg1)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, i16>>(0x44FD90, this, arg1);
}

void aiVehicleAmbient::DrawId()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x44FD80, this);
}

void aiVehicleAmbient::Dump()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x451160, this);
}

class mmOpponentImpactAudio* aiVehicleAmbient::GetImpactAudioPtr()
{
    return stub<thiscall_t<class mmOpponentImpactAudio*, aiVehicleAmbient*>>(0x451360, this);
}

void aiVehicleAmbient::Impact(i32 arg1)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, i32>>(0x44F490, this, arg1);
}

void aiVehicleAmbient::ImpactAudioReaction(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, f32>>(0x450AB0, this, arg1);
}

void aiVehicleAmbient::Init(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, char*, i32>>(0x44EE10, this, arg1, arg2);
}

void aiVehicleAmbient::PlayDoubleHorn(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, f32>>(0x450BF0, this, arg1);
}

void aiVehicleAmbient::PlayHorn()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x450370, this);
}

void aiVehicleAmbient::PlayHorn(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, f32, f32>>(0x4505C0, this, arg1, arg2);
}

void aiVehicleAmbient::PlayTrippleHorn(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, f32>>(0x4506B0, this, arg1);
}

void aiVehicleAmbient::PlayVoice()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x450120, this);
}

void aiVehicleAmbient::Reset()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x44F200, this);
}

void aiVehicleAmbient::StopHorn()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x4500F0, this);
}

void aiVehicleAmbient::StopVoice()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x450A30, this);
}

i32 aiVehicleAmbient::Type()
{
    return stub<thiscall_t<i32, aiVehicleAmbient*>>(0x451350, this);
}

void aiVehicleAmbient::UnAssignSounds()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x44F540, this);
}

void aiVehicleAmbient::Update()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x44F2E0, this);
}

void aiVehicleAmbient::UpdateAudImpactReaction()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x450A70, this);
}

void aiVehicleAmbient::UpdateAudio()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x44F820, this);
}

void aiVehicleAmbient::UpdateHorn()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x450790, this);
}

f32 aiVehicleAmbient::GetSecsSinceImpactReaction()
{
    return stub<cdecl_t<f32>>(0x451150);
}

void aiVehicleAmbient::SetAudioMaxDistance(f32 arg1)
{
    return stub<cdecl_t<void, f32>>(0x450DA0, arg1);
}

void aiVehicleAmbient::AddToAiAudMgr()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x450CC0, this);
}

f32 aiVehicleAmbient::CalculateDoppler(f32 arg1)
{
    return stub<thiscall_t<f32, aiVehicleAmbient*, f32>>(0x44F620, this, arg1);
}

f32 aiVehicleAmbient::CalculateFerrariPitch(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<f32, aiVehicleAmbient*, f32, i32>>(0x44F650, this, arg1, arg2);
}

void aiVehicleAmbient::ImpactAudioReaction()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x450B10, this);
}

void aiVehicleAmbient::UpdateAudio(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, f32>>(0x44F850, this, arg1);
}

void aiVehicleAmbient::UpdateDSound3DAudio()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x450DC0, this);
}
