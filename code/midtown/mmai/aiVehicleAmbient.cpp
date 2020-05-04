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
        class mmOpponentImpactAudio*>>(0x51000_Offset, this, arg1, arg2, arg3, arg4);
}

void aiVehicleAmbient::CalculateAudioPanning()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x4FCF0_Offset, this);
}

void aiVehicleAmbient::CalculateDistToPlayer2()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x4FBE0_Offset, this);
}

void aiVehicleAmbient::DrawBBox(i16 arg1)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, i16>>(0x4FD90_Offset, this, arg1);
}

void aiVehicleAmbient::DrawId()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x4FD80_Offset, this);
}

void aiVehicleAmbient::Dump()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x51160_Offset, this);
}

class mmOpponentImpactAudio* aiVehicleAmbient::GetImpactAudioPtr()
{
    return stub<thiscall_t<class mmOpponentImpactAudio*, aiVehicleAmbient*>>(0x51360_Offset, this);
}

void aiVehicleAmbient::Impact(i32 arg1)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, i32>>(0x4F490_Offset, this, arg1);
}

void aiVehicleAmbient::ImpactAudioReaction(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, f32>>(0x50AB0_Offset, this, arg1);
}

void aiVehicleAmbient::Init(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, char*, i32>>(0x4EE10_Offset, this, arg1, arg2);
}

void aiVehicleAmbient::PlayDoubleHorn(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, f32>>(0x50BF0_Offset, this, arg1);
}

void aiVehicleAmbient::PlayHorn()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x50370_Offset, this);
}

void aiVehicleAmbient::PlayHorn(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, f32, f32>>(0x505C0_Offset, this, arg1, arg2);
}

void aiVehicleAmbient::PlayTrippleHorn(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, f32>>(0x506B0_Offset, this, arg1);
}

void aiVehicleAmbient::PlayVoice()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x50120_Offset, this);
}

void aiVehicleAmbient::Reset()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x4F200_Offset, this);
}

void aiVehicleAmbient::StopHorn()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x500F0_Offset, this);
}

void aiVehicleAmbient::StopVoice()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x50A30_Offset, this);
}

i32 aiVehicleAmbient::Type()
{
    return stub<thiscall_t<i32, aiVehicleAmbient*>>(0x51350_Offset, this);
}

void aiVehicleAmbient::UnAssignSounds()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x4F540_Offset, this);
}

void aiVehicleAmbient::Update()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x4F2E0_Offset, this);
}

void aiVehicleAmbient::UpdateAudImpactReaction()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x50A70_Offset, this);
}

void aiVehicleAmbient::UpdateAudio()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x4F820_Offset, this);
}

void aiVehicleAmbient::UpdateHorn()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x50790_Offset, this);
}

f32 aiVehicleAmbient::GetSecsSinceImpactReaction()
{
    return stub<cdecl_t<f32>>(0x51150_Offset);
}

void aiVehicleAmbient::SetAudioMaxDistance(f32 arg1)
{
    return stub<cdecl_t<void, f32>>(0x50DA0_Offset, arg1);
}

void aiVehicleAmbient::AddToAiAudMgr()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x50CC0_Offset, this);
}

f32 aiVehicleAmbient::CalculateDoppler(f32 arg1)
{
    return stub<thiscall_t<f32, aiVehicleAmbient*, f32>>(0x4F620_Offset, this, arg1);
}

f32 aiVehicleAmbient::CalculateFerrariPitch(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<f32, aiVehicleAmbient*, f32, i32>>(0x4F650_Offset, this, arg1, arg2);
}

void aiVehicleAmbient::ImpactAudioReaction()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x50B10_Offset, this);
}

void aiVehicleAmbient::UpdateAudio(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleAmbient*, f32>>(0x4F850_Offset, this, arg1);
}

void aiVehicleAmbient::UpdateDSound3DAudio()
{
    return stub<thiscall_t<void, aiVehicleAmbient*>>(0x50DC0_Offset, this);
}

define_dummy_symbol(mmai_aiVehicleAmbient);
