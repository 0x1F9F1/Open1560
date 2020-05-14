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

define_dummy_symbol(mmaudio_sound);

#include "sound.h"

AudSound::AudSound(u32 arg1, i32 arg2, i16 arg3)
{
    unimplemented(arg1, arg2, arg3);
}

AudSound::~AudSound()
{
    unimplemented();
}

void AudSound::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, AudSound*, class Bank*>>(0x4EB6E0, this, arg1);
}

i32 AudSound::AllOneShotLayersPlaying()
{
    return stub<thiscall_t<i32, AudSound*>>(0x4EB9E0, this);
}

void AudSound::DeallocateSoundObjs()
{
    return stub<thiscall_t<void, AudSound*>>(0x4EA690, this);
}

void AudSound::Disable()
{
    return stub<thiscall_t<void, AudSound*>>(0x4EAD40, this);
}

void AudSound::Disable3DMode()
{
    return stub<thiscall_t<void, AudSound*>>(0x4EBC00, this);
}

void AudSound::DisableEffect(i32 arg1)
{
    return stub<thiscall_t<void, AudSound*, i32>>(0x4EBAA0, this, arg1);
}

u8 AudSound::EchoPending()
{
    return stub<thiscall_t<u8, AudSound*>>(0x4EB800, this);
}

void AudSound::Enable()
{
    return stub<thiscall_t<void, AudSound*>>(0x4EAD30, this);
}

void AudSound::Enable3DMode()
{
    return stub<thiscall_t<void, AudSound*>>(0x4EBBC0, this);
}

void AudSound::EnabledAction()
{
    return stub<thiscall_t<void, AudSound*>>(0x4EAD10, this);
}

class SoundObj* AudSound::GetCurrentSoundObj()
{
    return stub<thiscall_t<class SoundObj*, AudSound*>>(0x4EBC40, this);
}

f32 AudSound::GetEAXReverbMix(i32 arg1)
{
    return stub<thiscall_t<f32, AudSound*, i32>>(0x4EB3B0, this, arg1);
}

i32 AudSound::GetEffect()
{
    return stub<thiscall_t<i32, AudSound*>>(0x4EBA10, this);
}

f32 AudSound::GetFrequency(i32 arg1)
{
    return stub<thiscall_t<f32, AudSound*, i32>>(0x4EB290, this, arg1);
}

f32 AudSound::GetSampleTime()
{
    return stub<thiscall_t<f32, AudSound*>>(0x4EB6C0, this);
}

class CReverbBuffer* AudSound::GetSecondaryEAXObj(i32 arg1)
{
    return stub<thiscall_t<class CReverbBuffer*, AudSound*, i32>>(0x4EBB90, this, arg1);
}

f32 AudSound::GetVolume(i32 arg1)
{
    return stub<thiscall_t<f32, AudSound*, i32>>(0x4EBC50, this, arg1);
}

i32 AudSound::IsPlaying(i32 arg1)
{
    return stub<thiscall_t<i32, AudSound*, i32>>(0x4EB690, this, arg1);
}

i32 AudSound::Load(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, AudSound*, char*, i32>>(0x4EA8D0, this, arg1, arg2);
}

i32 AudSound::Load(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, AudSound*, i32, i32>>(0x4EAB20, this, arg1, arg2);
}

void AudSound::PlayLoop(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, f32>>(0x4EB0D0, this, arg1, arg2);
}

void AudSound::PlayOnce(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, f32>>(0x4EAFF0, this, arg1, arg2);
}

i32 AudSound::ReadyOneShotLayerBuf()
{
    return stub<thiscall_t<i32, AudSound*>>(0x4EB9B0, this);
}

void AudSound::ReallocateSoundObjs()
{
    return stub<thiscall_t<void, AudSound*>>(0x4EA6F0, this);
}

void AudSound::Reset()
{
    return stub<thiscall_t<void, AudSound*>>(0x4EAD60, this);
}

void AudSound::Set3DMode(u32 arg1)
{
    return stub<thiscall_t<void, AudSound*, u32>>(0x4EB660, this, arg1);
}

void AudSound::SetChorusAttenuation(f32 arg1)
{
    return stub<thiscall_t<void, AudSound*, f32>>(0x4EB820, this, arg1);
}

void AudSound::SetChorusPitchMult(f32 arg1)
{
    return stub<thiscall_t<void, AudSound*, f32>>(0x4EB860, this, arg1);
}

void AudSound::SetChorusPitchMult(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, f32>>(0x4EB8A0, this, arg1, arg2);
}

void AudSound::SetConeAngles(u32 arg1, u32 arg2)
{
    return stub<thiscall_t<void, AudSound*, u32, u32>>(0x4EB730, this, arg1, arg2);
}

void AudSound::SetConeOrientation(class Vector3* arg1)
{
    return stub<thiscall_t<void, AudSound*, class Vector3*>>(0x4EB790, this, arg1);
}

void AudSound::SetConeOutsideVolume(i32 arg1)
{
    return stub<thiscall_t<void, AudSound*, i32>>(0x4EB760, this, arg1);
}

void AudSound::SetDelayTime(f32 arg1)
{
    return stub<thiscall_t<void, AudSound*, f32>>(0x4EB8F0, this, arg1);
}

void AudSound::SetEAXReverbMix(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, i32>>(0x4EB350, this, arg1, arg2);
}

void AudSound::SetEchoAttenuation(f32 arg1)
{
    return stub<thiscall_t<void, AudSound*, f32>>(0x4EB7C0, this, arg1);
}

void AudSound::SetEchoFrequency(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, i32>>(0x4EB510, this, arg1, arg2);
}

void AudSound::SetEchoPan(f32 arg1)
{
    return stub<thiscall_t<void, AudSound*, f32>>(0x4EB4B0, this, arg1);
}

void AudSound::SetEffect(i32 arg1)
{
    return stub<thiscall_t<void, AudSound*, i32>>(0x4EBA30, this, arg1);
}

void AudSound::SetFrequency(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, i32>>(0x4EB210, this, arg1, arg2);
}

void AudSound::SetPan(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, i32>>(0x4EB410, this, arg1, arg2);
}

void AudSound::SetPlayPosition(u32 arg1)
{
    return stub<thiscall_t<void, AudSound*, u32>>(0x4EAFC0, this, arg1);
}

void AudSound::SetPriority(i32 arg1)
{
    return stub<thiscall_t<void, AudSound*, i32>>(0x4EA670, this, arg1);
}

void AudSound::SetRamp(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, f32>>(0x4EB580, this, arg1, arg2);
}

void AudSound::SetVolume(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudSound*, f32, i32>>(0x4EB2D0, this, arg1, arg2);
}

void AudSound::SetupOneShotLayerBuffers(i32 arg1, f32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, AudSound*, i32, f32, i32>>(0x4EB940, this, arg1, arg2, arg3);
}

void AudSound::Stop()
{
    return stub<thiscall_t<void, AudSound*>>(0x4EB1B0, this);
}

void AudSound::StopEchoBuffers()
{
    return stub<thiscall_t<void, AudSound*>>(0x4EB1F0, this);
}

void AudSound::Update()
{
    return stub<thiscall_t<void, AudSound*>>(0x4EAD70, this);
}

void AudSound::Update3DSettings()
{
    return stub<thiscall_t<void, AudSound*>>(0x4EAE00, this);
}

u32 const AudSound::Get2DFlags()
{
    return stub<cdecl_t<u32 const>>(0x4EBAF0);
}

u32 const AudSound::Get3DFlags()
{
    return stub<cdecl_t<u32 const>>(0x4EBB70);
}

u32 const AudSound::GetFreqChange2DFlags()
{
    return stub<cdecl_t<u32 const>>(0x4EBB30);
}

u32 const AudSound::GetFreqChange3DFlags()
{
    return stub<cdecl_t<u32 const>>(0x4EBB80);
}

u32 const AudSound::GetSoft2DFlags()
{
    return stub<cdecl_t<u32 const>>(0x4EBB10);
}

u32 const AudSound::GetSoftFreqChange2DFlags()
{
    return stub<cdecl_t<u32 const>>(0x4EBB50);
}
