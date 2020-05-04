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

#include "sound.h"

AudSound::AudSound(u32 arg1, i32 arg2, i16 arg3)
{
    unimplemented();
}

AudSound::~AudSound()
{
    unimplemented();
}

void AudSound::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, AudSound*, class Bank*>>(0xEB6E0_Offset, this, arg1);
}

i32 AudSound::AllOneShotLayersPlaying()
{
    return stub<thiscall_t<i32, AudSound*>>(0xEB9E0_Offset, this);
}

void AudSound::DeallocateSoundObjs()
{
    return stub<thiscall_t<void, AudSound*>>(0xEA690_Offset, this);
}

void AudSound::Disable()
{
    return stub<thiscall_t<void, AudSound*>>(0xEAD40_Offset, this);
}

void AudSound::Disable3DMode()
{
    return stub<thiscall_t<void, AudSound*>>(0xEBC00_Offset, this);
}

void AudSound::DisableEffect(i32 arg1)
{
    return stub<thiscall_t<void, AudSound*, i32>>(0xEBAA0_Offset, this, arg1);
}

u8 AudSound::EchoPending()
{
    return stub<thiscall_t<u8, AudSound*>>(0xEB800_Offset, this);
}

void AudSound::Enable()
{
    return stub<thiscall_t<void, AudSound*>>(0xEAD30_Offset, this);
}

void AudSound::Enable3DMode()
{
    return stub<thiscall_t<void, AudSound*>>(0xEBBC0_Offset, this);
}

void AudSound::EnabledAction()
{
    return stub<thiscall_t<void, AudSound*>>(0xEAD10_Offset, this);
}

class SoundObj* AudSound::GetCurrentSoundObj()
{
    return stub<thiscall_t<class SoundObj*, AudSound*>>(0xEBC40_Offset, this);
}

f32 AudSound::GetEAXReverbMix(i32 arg1)
{
    return stub<thiscall_t<f32, AudSound*, i32>>(0xEB3B0_Offset, this, arg1);
}

i32 AudSound::GetEffect()
{
    return stub<thiscall_t<i32, AudSound*>>(0xEBA10_Offset, this);
}

f32 AudSound::GetFrequency(i32 arg1)
{
    return stub<thiscall_t<f32, AudSound*, i32>>(0xEB290_Offset, this, arg1);
}

f32 AudSound::GetSampleTime()
{
    return stub<thiscall_t<f32, AudSound*>>(0xEB6C0_Offset, this);
}

class CReverbBuffer* AudSound::GetSecondaryEAXObj(i32 arg1)
{
    return stub<thiscall_t<class CReverbBuffer*, AudSound*, i32>>(0xEBB90_Offset, this, arg1);
}

f32 AudSound::GetVolume(i32 arg1)
{
    return stub<thiscall_t<f32, AudSound*, i32>>(0xEBC50_Offset, this, arg1);
}

i32 AudSound::IsPlaying(i32 arg1)
{
    return stub<thiscall_t<i32, AudSound*, i32>>(0xEB690_Offset, this, arg1);
}

i32 AudSound::Load(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, AudSound*, char*, i32>>(0xEA8D0_Offset, this, arg1, arg2);
}

i32 AudSound::Load(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, AudSound*, i32, i32>>(0xEAB20_Offset, this, arg1, arg2);
}

void AudSound::PlayLoop(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, f32>>(0xEB0D0_Offset, this, arg1, arg2);
}

void AudSound::PlayOnce(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, f32>>(0xEAFF0_Offset, this, arg1, arg2);
}

i32 AudSound::ReadyOneShotLayerBuf()
{
    return stub<thiscall_t<i32, AudSound*>>(0xEB9B0_Offset, this);
}

void AudSound::ReallocateSoundObjs()
{
    return stub<thiscall_t<void, AudSound*>>(0xEA6F0_Offset, this);
}

void AudSound::Reset()
{
    return stub<thiscall_t<void, AudSound*>>(0xEAD60_Offset, this);
}

void AudSound::Set3DMode(u32 arg1)
{
    return stub<thiscall_t<void, AudSound*, u32>>(0xEB660_Offset, this, arg1);
}

void AudSound::SetChorusAttenuation(f32 arg1)
{
    return stub<thiscall_t<void, AudSound*, f32>>(0xEB820_Offset, this, arg1);
}

void AudSound::SetChorusPitchMult(f32 arg1)
{
    return stub<thiscall_t<void, AudSound*, f32>>(0xEB860_Offset, this, arg1);
}

void AudSound::SetChorusPitchMult(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, f32>>(0xEB8A0_Offset, this, arg1, arg2);
}

void AudSound::SetConeAngles(u32 arg1, u32 arg2)
{
    return stub<thiscall_t<void, AudSound*, u32, u32>>(0xEB730_Offset, this, arg1, arg2);
}

void AudSound::SetConeOrientation(class Vector3* arg1)
{
    return stub<thiscall_t<void, AudSound*, class Vector3*>>(0xEB790_Offset, this, arg1);
}

void AudSound::SetConeOutsideVolume(i32 arg1)
{
    return stub<thiscall_t<void, AudSound*, i32>>(0xEB760_Offset, this, arg1);
}

void AudSound::SetDelayTime(f32 arg1)
{
    return stub<thiscall_t<void, AudSound*, f32>>(0xEB8F0_Offset, this, arg1);
}

void AudSound::SetEAXReverbMix(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, i32>>(0xEB350_Offset, this, arg1, arg2);
}

void AudSound::SetEchoAttenuation(f32 arg1)
{
    return stub<thiscall_t<void, AudSound*, f32>>(0xEB7C0_Offset, this, arg1);
}

void AudSound::SetEchoFrequency(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, i32>>(0xEB510_Offset, this, arg1, arg2);
}

void AudSound::SetEchoPan(f32 arg1)
{
    return stub<thiscall_t<void, AudSound*, f32>>(0xEB4B0_Offset, this, arg1);
}

void AudSound::SetEffect(i32 arg1)
{
    return stub<thiscall_t<void, AudSound*, i32>>(0xEBA30_Offset, this, arg1);
}

void AudSound::SetFrequency(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, i32>>(0xEB210_Offset, this, arg1, arg2);
}

void AudSound::SetPan(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, i32>>(0xEB410_Offset, this, arg1, arg2);
}

void AudSound::SetPlayPosition(u32 arg1)
{
    return stub<thiscall_t<void, AudSound*, u32>>(0xEAFC0_Offset, this, arg1);
}

void AudSound::SetPriority(i32 arg1)
{
    return stub<thiscall_t<void, AudSound*, i32>>(0xEA670_Offset, this, arg1);
}

void AudSound::SetRamp(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, f32>>(0xEB580_Offset, this, arg1, arg2);
}

void AudSound::SetVolume(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, i32>>(0xEB2D0_Offset, this, arg1, arg2);
}

void AudSound::SetupOneShotLayerBuffers(i32 arg1, f32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, AudSound*, i32, f32, i32>>(0xEB940_Offset, this, arg1, arg2, arg3);
}

void AudSound::Stop()
{
    return stub<thiscall_t<void, AudSound*>>(0xEB1B0_Offset, this);
}

void AudSound::StopEchoBuffers()
{
    return stub<thiscall_t<void, AudSound*>>(0xEB1F0_Offset, this);
}

void AudSound::Update()
{
    return stub<thiscall_t<void, AudSound*>>(0xEAD70_Offset, this);
}

void AudSound::Update3DSettings()
{
    return stub<thiscall_t<void, AudSound*>>(0xEAE00_Offset, this);
}

u32 const AudSound::Get2DFlags()
{
    return stub<cdecl_t<u32 const>>(0xEBAF0_Offset);
}

u32 const AudSound::Get3DFlags()
{
    return stub<cdecl_t<u32 const>>(0xEBB70_Offset);
}

u32 const AudSound::GetFreqChange2DFlags()
{
    return stub<cdecl_t<u32 const>>(0xEBB30_Offset);
}

u32 const AudSound::GetFreqChange3DFlags()
{
    return stub<cdecl_t<u32 const>>(0xEBB80_Offset);
}

u32 const AudSound::GetSoft2DFlags()
{
    return stub<cdecl_t<u32 const>>(0xEBB10_Offset);
}

u32 const AudSound::GetSoftFreqChange2DFlags()
{
    return stub<cdecl_t<u32 const>>(0xEBB50_Offset);
}

define_dummy_symbol(mmaudio_sound);
