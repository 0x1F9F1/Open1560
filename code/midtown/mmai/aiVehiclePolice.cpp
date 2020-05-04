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

#include "aiVehiclePolice.h"

aiVehiclePolice::aiVehiclePolice()
{
    unimplemented();
}

aiVehiclePolice::~aiVehiclePolice()
{
    unimplemented();
}

void aiVehiclePolice::AssignSounds(class AudSound* arg1, class AudSound* arg2, class AudSound* arg3,
    class AudSound* arg4, class mmOpponentImpactAudio* arg5, class AudSound* arg6)
{
    return stub<thiscall_t<void, aiVehiclePolice*, class AudSound*, class AudSound*, class AudSound*, class AudSound*,
        class mmOpponentImpactAudio*, class AudSound*>>(0x46370_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void aiVehiclePolice::Backup()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x45F20_Offset, this);
}

void aiVehiclePolice::ConfigCar()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x45E20_Offset, this);
}

void aiVehiclePolice::DrawDamage()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x460B0_Offset, this);
}

void aiVehiclePolice::DrawId()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x46100_Offset, this);
}

void aiVehiclePolice::DrawTargetPt()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x45F40_Offset, this);
}

void aiVehiclePolice::Dump()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x463B0_Offset, this);
}

class mmPoliceCarAudio* aiVehiclePolice::GetAudioPtr()
{
    return stub<thiscall_t<class mmPoliceCarAudio*, aiVehiclePolice*>>(0x463A0_Offset, this);
}

class mmPoliceCarAudio* aiVehiclePolice::GetCarAudioPtr()
{
    return stub<thiscall_t<class mmPoliceCarAudio*, aiVehiclePolice*>>(0x46170_Offset, this);
}

f32 aiVehiclePolice::GetDistanceToPlayer2()
{
    return stub<thiscall_t<f32, aiVehiclePolice*>>(0x46270_Offset, this);
}

i32 aiVehiclePolice::GetEngineSoundIndex()
{
    return stub<thiscall_t<i32, aiVehiclePolice*>>(0x46180_Offset, this);
}

i32 aiVehiclePolice::InPersuit()
{
    return stub<thiscall_t<i32, aiVehiclePolice*>>(0x459D0_Offset, this);
}

void aiVehiclePolice::Init(i32 arg1, class aiRaceData* arg2)
{
    return stub<thiscall_t<void, aiVehiclePolice*, i32, class aiRaceData*>>(0x44930_Offset, this, arg1, arg2);
}

i32 aiVehiclePolice::IsPerpInRange(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiVehiclePolice*, class mmCar*>>(0x45A00_Offset, this, arg1);
}

void aiVehiclePolice::PerpEscapes(u8 arg1)
{
    return stub<thiscall_t<void, aiVehiclePolice*, u8>>(0x45DB0_Offset, this, arg1);
}

void aiVehiclePolice::PlayVoice()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x46280_Offset, this);
}

void aiVehiclePolice::Reset()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x44B40_Offset, this);
}

void aiVehiclePolice::ResetPed()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x451D0_Offset, this);
}

void aiVehiclePolice::SetAudioCloserMinDistMult(f32 arg1)
{
    return stub<thiscall_t<void, aiVehiclePolice*, f32>>(0x462E0_Offset, this, arg1);
}

void aiVehiclePolice::SetAudioMaxDistance(f32 arg1)
{
    return stub<thiscall_t<void, aiVehiclePolice*, f32>>(0x462B0_Offset, this, arg1);
}

void aiVehiclePolice::SetAudioMinDistance(f32 arg1)
{
    return stub<thiscall_t<void, aiVehiclePolice*, f32>>(0x46290_Offset, this, arg1);
}

void aiVehiclePolice::SetMainSirenLoop(i32 arg1)
{
    return stub<thiscall_t<void, aiVehiclePolice*, i32>>(0x46190_Offset, this, arg1);
}

i32 aiVehiclePolice::Type()
{
    return stub<thiscall_t<i32, aiVehiclePolice*>>(0x46620_Offset, this);
}

void aiVehiclePolice::UnAssignSounds()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x46150_Offset, this);
}

void aiVehiclePolice::Update()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x453D0_Offset, this);
}

void aiVehiclePolice::UpdateAudio()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x461B0_Offset, this);
}

void aiVehiclePolice::AddToAiAudMgr()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x46300_Offset, this);
}

i32 aiVehiclePolice::FindPerp(i32 arg1, i32 arg2, class aiPath* arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<i32, aiVehiclePolice*, i32, i32, class aiPath*, i32, i32>>(
        0x45C70_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

define_dummy_symbol(mmai_aiVehiclePolice);
