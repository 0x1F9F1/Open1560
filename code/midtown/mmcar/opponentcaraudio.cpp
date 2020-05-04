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

#include "opponentcaraudio.h"

mmOpponentCarAudio::mmOpponentCarAudio()
{
    unimplemented();
}

mmOpponentCarAudio::mmOpponentCarAudio(class mmCarSim* arg1)
{
    unimplemented();
}

mmOpponentCarAudio::~mmOpponentCarAudio()
{
    unimplemented();
}

void mmOpponentCarAudio::AssignSounds(
    class AudSound* arg1, class AudSound* arg2, class mmOpponentImpactAudio* arg3, class AudSound* arg4)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, class AudSound*, class AudSound*, class mmOpponentImpactAudio*,
        class AudSound*>>(0x7BF50_Offset, this, arg1, arg2, arg3, arg4);
}

void mmOpponentCarAudio::CalculateDistToPlayer2()
{
    return stub<thiscall_t<void, mmOpponentCarAudio*>>(0x7BC80_Offset, this);
}

void mmOpponentCarAudio::CalculateDoppler(f32 arg1)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, f32>>(0x7BDB0_Offset, this, arg1);
}

void mmOpponentCarAudio::CalculatePan()
{
    return stub<thiscall_t<void, mmOpponentCarAudio*>>(0x7BD60_Offset, this);
}

class MetaClass* mmOpponentCarAudio::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmOpponentCarAudio*>>(0x7C2A0_Offset, this);
}

void mmOpponentCarAudio::Init(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, class mmCarSim*>>(0x7BA30_Offset, this, arg1);
}

void mmOpponentCarAudio::LoadSucessful(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, class mmCarSim*>>(0x7BF20_Offset, this, arg1);
}

void mmOpponentCarAudio::PlayReverseBeep()
{
    return stub<thiscall_t<void, mmOpponentCarAudio*>>(0x7BB80_Offset, this);
}

void mmOpponentCarAudio::Reset()
{
    return stub<thiscall_t<void, mmOpponentCarAudio*>>(0x7BF00_Offset, this);
}

void mmOpponentCarAudio::SetMinAmpSpeed(f32 arg1)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, f32>>(0x7C0C0_Offset, this, arg1);
}

void mmOpponentCarAudio::UnAssignSounds()
{
    return stub<thiscall_t<void, mmOpponentCarAudio*>>(0x7C020_Offset, this);
}

void mmOpponentCarAudio::Update(i32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, i32, f32, f32>>(0x7BBE0_Offset, this, arg1, arg2, arg3);
}

void mmOpponentCarAudio::UpdateDoppler()
{
    return stub<thiscall_t<void, mmOpponentCarAudio*>>(0x7BDE0_Offset, this);
}

void mmOpponentCarAudio::UpdateDoppler(f32 arg1)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, f32>>(0x7BDF0_Offset, this, arg1);
}

void mmOpponentCarAudio::DeclareFields()
{
    return stub<cdecl_t<void>>(0x7C0E0_Offset);
}

define_dummy_symbol(mmcar_opponentcaraudio);
