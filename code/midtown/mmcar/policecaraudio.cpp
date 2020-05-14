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

define_dummy_symbol(mmcar_policecaraudio);

#include "policecaraudio.h"

mmPoliceCarAudio::mmPoliceCarAudio(class mmCarSim* arg1, f32 arg2)
{
    unimplemented(arg1, arg2);
}

mmPoliceCarAudio::~mmPoliceCarAudio()
{
    unimplemented();
}

void mmPoliceCarAudio::AssignSounds(class AudSound* arg1, class AudSound* arg2, class AudSound* arg3,
    class AudSound* arg4, class mmOpponentImpactAudio* arg5, class AudSound* arg6)
{
    return stub<thiscall_t<void, mmPoliceCarAudio*, class AudSound*, class AudSound*, class AudSound*, class AudSound*,
        class mmOpponentImpactAudio*, class AudSound*>>(0x47B6A0, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void mmPoliceCarAudio::DamageSiren()
{
    return stub<thiscall_t<void, mmPoliceCarAudio*>>(0x47AAD0, this);
}

i32 mmPoliceCarAudio::ExplosionIsPlaying()
{
    return stub<thiscall_t<i32, mmPoliceCarAudio*>>(0x47A8F0, this);
}

void mmPoliceCarAudio::PlayExplosion()
{
    return stub<thiscall_t<void, mmPoliceCarAudio*>>(0x47AA20, this);
}

void mmPoliceCarAudio::PlayVoice()
{
    return stub<thiscall_t<void, mmPoliceCarAudio*>>(0x47B600, this);
}

void mmPoliceCarAudio::StartSiren()
{
    return stub<thiscall_t<void, mmPoliceCarAudio*>>(0x47A910, this);
}

void mmPoliceCarAudio::StopSiren()
{
    return stub<thiscall_t<void, mmPoliceCarAudio*>>(0x47A9C0, this);
}

void mmPoliceCarAudio::UnAssignSounds()
{
    return stub<thiscall_t<void, mmPoliceCarAudio*>>(0x47B770, this);
}

void mmPoliceCarAudio::Update(i32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmPoliceCarAudio*, i32, f32, f32>>(0x47AC30, this, arg1, arg2, arg3);
}

void mmPoliceCarAudio::UpdateDoppler()
{
    return stub<thiscall_t<void, mmPoliceCarAudio*>>(0x47B400, this);
}

void mmPoliceCarAudio::UpdateDoppler(f32 arg1)
{
    return stub<thiscall_t<void, mmPoliceCarAudio*, f32>>(0x47B410, this, arg1);
}

void mmPoliceCarAudio::FluctuateFastSiren()
{
    return stub<thiscall_t<void, mmPoliceCarAudio*>>(0x47AFE0, this);
}

void mmPoliceCarAudio::FluctuateSlowSiren()
{
    return stub<thiscall_t<void, mmPoliceCarAudio*>>(0x47AD50, this);
}
