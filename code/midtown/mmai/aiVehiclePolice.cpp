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

define_dummy_symbol(mmai_aiVehiclePolice);

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
        class mmOpponentImpactAudio*, class AudSound*>>(0x446370, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void aiVehiclePolice::Backup()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x445F20, this);
}

void aiVehiclePolice::ConfigCar()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x445E20, this);
}

void aiVehiclePolice::DrawDamage()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x4460B0, this);
}

void aiVehiclePolice::DrawId()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x446100, this);
}

void aiVehiclePolice::DrawTargetPt()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x445F40, this);
}

void aiVehiclePolice::Dump()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x4463B0, this);
}

class mmPoliceCarAudio* aiVehiclePolice::GetAudioPtr()
{
    return stub<thiscall_t<class mmPoliceCarAudio*, aiVehiclePolice*>>(0x4463A0, this);
}

class mmPoliceCarAudio* aiVehiclePolice::GetCarAudioPtr()
{
    return stub<thiscall_t<class mmPoliceCarAudio*, aiVehiclePolice*>>(0x446170, this);
}

f32 aiVehiclePolice::GetDistanceToPlayer2()
{
    return stub<thiscall_t<f32, aiVehiclePolice*>>(0x446270, this);
}

i32 aiVehiclePolice::GetEngineSoundIndex()
{
    return stub<thiscall_t<i32, aiVehiclePolice*>>(0x446180, this);
}

i32 aiVehiclePolice::InPersuit()
{
    return stub<thiscall_t<i32, aiVehiclePolice*>>(0x4459D0, this);
}

void aiVehiclePolice::Init(i32 arg1, class aiRaceData* arg2)
{
    return stub<thiscall_t<void, aiVehiclePolice*, i32, class aiRaceData*>>(0x444930, this, arg1, arg2);
}

i32 aiVehiclePolice::IsPerpInRange(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiVehiclePolice*, class mmCar*>>(0x445A00, this, arg1);
}

void aiVehiclePolice::PerpEscapes(u8 arg1)
{
    return stub<thiscall_t<void, aiVehiclePolice*, u8>>(0x445DB0, this, arg1);
}

void aiVehiclePolice::PlayVoice()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x446280, this);
}

void aiVehiclePolice::Reset()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x444B40, this);
}

void aiVehiclePolice::ResetPed()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x4451D0, this);
}

void aiVehiclePolice::SetAudioCloserMinDistMult(f32 arg1)
{
    return stub<thiscall_t<void, aiVehiclePolice*, f32>>(0x4462E0, this, arg1);
}

void aiVehiclePolice::SetAudioMaxDistance(f32 arg1)
{
    return stub<thiscall_t<void, aiVehiclePolice*, f32>>(0x4462B0, this, arg1);
}

void aiVehiclePolice::SetAudioMinDistance(f32 arg1)
{
    return stub<thiscall_t<void, aiVehiclePolice*, f32>>(0x446290, this, arg1);
}

void aiVehiclePolice::SetMainSirenLoop(i32 arg1)
{
    return stub<thiscall_t<void, aiVehiclePolice*, i32>>(0x446190, this, arg1);
}

i32 aiVehiclePolice::Type()
{
    return stub<thiscall_t<i32, aiVehiclePolice*>>(0x446620, this);
}

void aiVehiclePolice::UnAssignSounds()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x446150, this);
}

void aiVehiclePolice::Update()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x4453D0, this);
}

void aiVehiclePolice::UpdateAudio()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x4461B0, this);
}

void aiVehiclePolice::AddToAiAudMgr()
{
    return stub<thiscall_t<void, aiVehiclePolice*>>(0x446300, this);
}

i32 aiVehiclePolice::FindPerp(i32 arg1, i32 arg2, class aiPath* arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<i32, aiVehiclePolice*, i32, i32, class aiPath*, i32, i32>>(
        0x445C70, this, arg1, arg2, arg3, arg4, arg5);
}
