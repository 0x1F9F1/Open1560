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

define_dummy_symbol(mmcar_impactaudio);

#include "impactaudio.h"

mmImpactAudio::mmImpactAudio(class mmCarSim* arg1, class Vector3* arg2)
{
    unimplemented(arg1, arg2);
}

mmImpactAudio::~mmImpactAudio()
{
    unimplemented();
}

void mmImpactAudio::EchoOff(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmImpactAudio*, class mmCarSim*>>(0x84E70_Offset, this, arg1);
}

void mmImpactAudio::EchoOn(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmImpactAudio*, class mmCarSim*>>(0x84E60_Offset, this, arg1);
}

void mmImpactAudio::GetBangerPtrs(i16 arg1, class AudSound** arg2, class AudSound** arg3)
{
    return stub<thiscall_t<void, mmImpactAudio*, i16, class AudSound**, class AudSound**>>(
        0x85020_Offset, this, arg1, arg2, arg3);
}

void mmImpactAudio::Play(f32 arg1, i16 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, mmImpactAudio*, f32, i16, f32, f32>>(0x84E80_Offset, this, arg1, arg2, arg3, arg4);
}

void mmImpactAudio::PlayBanger(f32 arg1, i16 arg2)
{
    return stub<thiscall_t<void, mmImpactAudio*, f32, i16>>(0x852A0_Offset, this, arg1, arg2);
}

void mmImpactAudio::PlayCar(f32 arg1)
{
    return stub<thiscall_t<void, mmImpactAudio*, f32>>(0x85010_Offset, this, arg1);
}

void mmImpactAudio::PlayWall(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmImpactAudio*, f32, f32, f32>>(0x84F10_Offset, this, arg1, arg2, arg3);
}

void mmImpactAudio::SetBangerVolumeRange(f32 arg1, f32 arg2, f32 arg3, i16 arg4)
{
    return stub<thiscall_t<void, mmImpactAudio*, f32, f32, f32, i16>>(0x854A0_Offset, this, arg1, arg2, arg3, arg4);
}

void mmImpactAudio::SetWallHugeVolumeMultiplier(f32 arg1)
{
    return stub<thiscall_t<void, mmImpactAudio*, f32>>(0x85480_Offset, this, arg1);
}

void mmImpactAudio::SetWallHugeVolumeRange(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmImpactAudio*, f32, f32>>(0x85460_Offset, this, arg1, arg2);
}

void mmImpactAudio::SetWallMedVolumeMultiplier(f32 arg1)
{
    return stub<thiscall_t<void, mmImpactAudio*, f32>>(0x85440_Offset, this, arg1);
}

void mmImpactAudio::SetWallMedVolumeRange(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmImpactAudio*, f32, f32>>(0x85420_Offset, this, arg1, arg2);
}

void mmImpactAudio::SetWallSoftVolumeMultiplier(f32 arg1)
{
    return stub<thiscall_t<void, mmImpactAudio*, f32>>(0x85400_Offset, this, arg1);
}

void mmImpactAudio::SetWallSoftVolumeRange(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmImpactAudio*, f32, f32>>(0x853E0_Offset, this, arg1, arg2);
}

void mmImpactAudio::Update()
{
    return stub<thiscall_t<void, mmImpactAudio*>>(0x85530_Offset, this);
}
