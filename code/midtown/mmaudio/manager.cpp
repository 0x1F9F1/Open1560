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

define_dummy_symbol(mmaudio_manager);

#include "manager.h"

AudManager::AudManager()
{
    unimplemented();
}

AudManager::~AudManager()
{
    unimplemented(arg1);
}

i32 AudManager::AddSound(class AudSound* arg1)
{
    return stub<thiscall_t<i32, AudManager*, class AudSound*>>(0xE8E40_Offset, this, arg1);
}

i32 AudManager::AddStream(class AudStream* arg1)
{
    return stub<thiscall_t<i32, AudManager*, class AudStream*>>(0xE8EA0_Offset, this, arg1);
}

void AudManager::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, AudManager*, class Bank*>>(0xE9610_Offset, this, arg1);
}

void AudManager::AlwaysEAX(u32 arg1)
{
    return stub<thiscall_t<void, AudManager*, u32>>(0xE97D0_Offset, this, arg1);
}

void AudManager::AssignCDBalance(f32 arg1)
{
    return stub<thiscall_t<void, AudManager*, f32>>(0xE95B0_Offset, this, arg1);
}

void AudManager::AssignCDVolume(f32 arg1)
{
    return stub<thiscall_t<void, AudManager*, f32>>(0xE9470_Offset, this, arg1);
}

void AudManager::AssignWaveBalance(f32 arg1)
{
    return stub<thiscall_t<void, AudManager*, f32>>(0xE9570_Offset, this, arg1);
}

void AudManager::AssignWaveVolume(f32 arg1)
{
    return stub<thiscall_t<void, AudManager*, f32>>(0xE9430_Offset, this, arg1);
}

void AudManager::AttenuateAudSounds(f32 arg1)
{
    return stub<thiscall_t<void, AudManager*, f32>>(0xE8DD0_Offset, this, arg1);
}

void AudManager::AttenuateCDVolume(f32 arg1)
{
    return stub<thiscall_t<void, AudManager*, f32>>(0xE9530_Offset, this, arg1);
}

i32 AudManager::CDIsEnabled()
{
    return stub<thiscall_t<i32, AudManager*>>(0xE94E0_Offset, this);
}

i16 AudManager::CDIsPlaying()
{
    return stub<thiscall_t<i16, AudManager*>>(0xE93A0_Offset, this);
}

u8 AudManager::CheckCDFile(char* arg1)
{
    return stub<thiscall_t<u8, AudManager*, char*>>(0xE9630_Offset, this, arg1);
}

i32 AudManager::CheckPriority(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<i32, AudManager*, i32, i32, i32>>(0xE8390_Offset, this, arg1, arg2, arg3);
}

u32 AudManager::DSound3DEnabled()
{
    return stub<thiscall_t<u32, AudManager*>>(0xE9810_Offset, this);
}

void AudManager::DeallocateADFRecord(i32 arg1)
{
    return stub<thiscall_t<void, AudManager*, i32>>(0xE82A0_Offset, this, arg1);
}

void AudManager::DeallocateCityADF()
{
    return stub<thiscall_t<void, AudManager*>>(0xE8A80_Offset, this);
}

void AudManager::DeallocateDSound(i16 arg1, i16 arg2)
{
    return stub<thiscall_t<void, AudManager*, i16, i16>>(0xE8A90_Offset, this, arg1, arg2);
}

void AudManager::DeallocateUIADF()
{
    return stub<thiscall_t<void, AudManager*>>(0xE8A70_Offset, this);
}

void AudManager::Disable(i16 arg1, i16 arg2)
{
    return stub<thiscall_t<void, AudManager*, i16, i16>>(0xE9090_Offset, this, arg1, arg2);
}

void AudManager::DisableCD()
{
    return stub<thiscall_t<void, AudManager*>>(0xE93C0_Offset, this);
}

u32 AudManager::EAXEnabled()
{
    return stub<thiscall_t<u32, AudManager*>>(0xE9800_Offset, this);
}

void AudManager::Enable(char* arg1, i16 arg2, i16 arg3)
{
    return stub<thiscall_t<void, AudManager*, char*, i16, i16>>(0xE8FE0_Offset, this, arg1, arg2, arg3);
}

i32 AudManager::EnableCD()
{
    return stub<thiscall_t<i32, AudManager*>>(0xE9400_Offset, this);
}

char* AudManager::GetActiveDeviceName()
{
    return stub<thiscall_t<char*, AudManager*>>(0xE9EA0_Offset, this);
}

f32 AudManager::GetCDBalance()
{
    return stub<thiscall_t<f32, AudManager*>>(0xE95D0_Offset, this);
}

u32 AudManager::GetCDPosition(u8* arg1, u8* arg2, u8* arg3, u8* arg4)
{
    return stub<thiscall_t<u32, AudManager*, u8*, u8*, u8*, u8*>>(0xE9F90_Offset, this, arg1, arg2, arg3, arg4);
}

u8 AudManager::GetCDTrackNum()
{
    return stub<thiscall_t<u8, AudManager*>>(0xE9380_Offset, this);
}

f32 AudManager::GetCDVolume()
{
    return stub<thiscall_t<f32, AudManager*>>(0xE9500_Offset, this);
}

class MetaClass* AudManager::GetClass()
{
    return stub<thiscall_t<class MetaClass*, AudManager*>>(0xEA1E0_Offset, this);
}

char** AudManager::GetDeviceNames()
{
    return stub<thiscall_t<char**, AudManager*>>(0xE9E60_Offset, this);
}

void AudManager::GetEAXAll(struct EAX_REVERBPROPERTIES* arg1)
{
    return stub<thiscall_t<void, AudManager*, struct EAX_REVERBPROPERTIES*>>(0xE9A60_Offset, this, arg1);
}

f32 AudManager::GetEAXDamping()
{
    return stub<thiscall_t<f32, AudManager*>>(0xE9D60_Offset, this);
}

f32 AudManager::GetEAXDecayTime()
{
    return stub<thiscall_t<f32, AudManager*>>(0xE9CA0_Offset, this);
}

u32 AudManager::GetEAXEnvironmet()
{
    return stub<thiscall_t<u32, AudManager*>>(0xE9B20_Offset, this);
}

f32 AudManager::GetEAXReverbVolume()
{
    return stub<thiscall_t<f32, AudManager*>>(0xE9BE0_Offset, this);
}

class MixerCTL* AudManager::GetMixerPtr()
{
    return stub<thiscall_t<class MixerCTL*, AudManager*>>(0xE9FD0_Offset, this);
}

u32 AudManager::GetNum3DHalBufs()
{
    return stub<thiscall_t<u32, AudManager*>>(0xE9EC0_Offset, this);
}

i16 AudManager::GetNumCDTracks()
{
    return stub<thiscall_t<i16, AudManager*>>(0xE9360_Offset, this);
}

i32 AudManager::GetNumDevices()
{
    return stub<thiscall_t<i32, AudManager*>>(0xE9E80_Offset, this);
}

class mmVoiceCommentary* AudManager::GetVoiceCommentaryPtr()
{
    return stub<thiscall_t<class mmVoiceCommentary*, AudManager*>>(0xE9FE0_Offset, this);
}

f32 AudManager::GetWaveBalance()
{
    return stub<thiscall_t<f32, AudManager*>>(0xE9590_Offset, this);
}

f32 AudManager::GetWaveVolume()
{
    return stub<thiscall_t<f32, AudManager*>>(0xE9450_Offset, this);
}

void AudManager::Init(i32 arg1, u32 arg2, char* arg3, i16 arg4, i16 arg5)
{
    return stub<thiscall_t<void, AudManager*, i32, u32, char*, i16, i16>>(
        0xE86F0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void AudManager::InitCityADF(i32 arg1, u32 arg2)
{
    return stub<thiscall_t<void, AudManager*, i32, u32>>(0xE8930_Offset, this, arg1, arg2);
}

void AudManager::InitUIADF(i32 arg1, u32 arg2)
{
    return stub<thiscall_t<void, AudManager*, i32, u32>>(0xE89E0_Offset, this, arg1, arg2);
}

u32 AudManager::IsAlwaysEAX()
{
    return stub<thiscall_t<u32, AudManager*>>(0xE97C0_Offset, this);
}

i32 AudManager::IsStereo()
{
    return stub<thiscall_t<i32, AudManager*>>(0xE9600_Offset, this);
}

void AudManager::LoadCityADF(i32 arg1, u32 arg2)
{
    return stub<thiscall_t<void, AudManager*, i32, u32>>(0xE8880_Offset, this, arg1, arg2);
}

void AudManager::LoadUIADF()
{
    return stub<thiscall_t<void, AudManager*>>(0xE8820_Offset, this);
}

i32 AudManager::PlayCDTrack(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, AudManager*, i32, i32>>(0xE9230_Offset, this, arg1, arg2);
}

i32 AudManager::PlayCDTrack(i32 arg1, u8 arg2, u8 arg3, u8 arg4, i32 arg5)
{
    return stub<thiscall_t<i32, AudManager*, i32, u8, u8, u8, i32>>(0xE92B0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void AudManager::ReallocateDSound(char* arg1, i16 arg2, i16 arg3)
{
    return stub<thiscall_t<void, AudManager*, char*, i16, i16>>(0xE8C10_Offset, this, arg1, arg2, arg3);
}

void AudManager::RemoveSound(class AudSound* arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudManager*, class AudSound*, i32>>(0xE8EF0_Offset, this, arg1, arg2);
}

void AudManager::RemoveSoundFromPlayList(class AudSound* arg1)
{
    return stub<thiscall_t<void, AudManager*, class AudSound*>>(0xE8630_Offset, this, arg1);
}

void AudManager::RemoveSoundFromPlayList(i32 arg1)
{
    return stub<thiscall_t<void, AudManager*, i32>>(0xE8670_Offset, this, arg1);
}

void AudManager::RemoveStream(class AudStream* arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudManager*, class AudStream*, i32>>(0xE8F60_Offset, this, arg1, arg2);
}

void AudManager::Reset()
{
    return stub<thiscall_t<void, AudManager*>>(0xE8FD0_Offset, this);
}

i32 AudManager::ResumeCDPlay()
{
    return stub<thiscall_t<i32, AudManager*>>(0xE9340_Offset, this);
}

void AudManager::SetBitDepthAndSampleRate(i32 arg1, u32 arg2)
{
    return stub<thiscall_t<void, AudManager*, i32, u32>>(0xE9DD0_Offset, this, arg1, arg2);
}

void AudManager::SetCDPlayMode(u8 arg1)
{
    return stub<thiscall_t<void, AudManager*, u8>>(0xE94B0_Offset, this, arg1);
}

void AudManager::SetDeviceName(char* arg1)
{
    return stub<thiscall_t<void, AudManager*, char*>>(0xE9F50_Offset, this, arg1);
}

i32 AudManager::SetEAXDamping(f32 arg1)
{
    return stub<thiscall_t<i32, AudManager*, f32>>(0xE9CF0_Offset, this, arg1);
}

i32 AudManager::SetEAXDecayTime(f32 arg1)
{
    return stub<thiscall_t<i32, AudManager*, f32>>(0xE9C30_Offset, this, arg1);
}

i32 AudManager::SetEAXEnvironmet(u32 arg1)
{
    return stub<thiscall_t<i32, AudManager*, u32>>(0xE9AB0_Offset, this, arg1);
}

i32 AudManager::SetEAXPreset(struct EAX_REVERBPROPERTIES* arg1)
{
    return stub<thiscall_t<i32, AudManager*, struct EAX_REVERBPROPERTIES*>>(0xE99F0_Offset, this, arg1);
}

i32 AudManager::SetEAXPreset(u32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<i32, AudManager*, u32, f32, f32, f32>>(0xE9970_Offset, this, arg1, arg2, arg3, arg4);
}

i32 AudManager::SetEAXReverbVolume(f32 arg1)
{
    return stub<thiscall_t<i32, AudManager*, f32>>(0xE9B70_Offset, this, arg1);
}

void AudManager::SetNumChannels(i32 arg1)
{
    return stub<thiscall_t<void, AudManager*, i32>>(0xE82D0_Offset, this, arg1);
}

void AudManager::SetStereo(i32 arg1)
{
    return stub<thiscall_t<void, AudManager*, i32>>(0xE8DA0_Offset, this, arg1);
}

void AudManager::SetVoiceCommentaryPtr(class mmVoiceCommentary* arg1)
{
    return stub<thiscall_t<void, AudManager*, class mmVoiceCommentary*>>(0xE9FF0_Offset, this, arg1);
}

void AudManager::StopAllSounds()
{
    return stub<thiscall_t<void, AudManager*>>(0xE9180_Offset, this);
}

void AudManager::StopCD()
{
    return stub<thiscall_t<void, AudManager*>>(0xE93E0_Offset, this);
}

i16 AudManager::Supports16Bit()
{
    return stub<thiscall_t<i16, AudManager*>>(0xE9620_Offset, this);
}

void AudManager::Update()
{
    return stub<thiscall_t<void, AudManager*>>(0xE86C0_Offset, this);
}

void AudManager::UpdatePaused()
{
    return stub<thiscall_t<void, AudManager*>>(0xE9DB0_Offset, this);
}

void AudManager::ZeroVolAllSounds()
{
    return stub<thiscall_t<void, AudManager*>>(0xE9220_Offset, this);
}

void AudManager::DeclareFields()
{
    return stub<cdecl_t<void>>(0xEA070_Offset);
}

u32 const AudManager::GetCDMusicOnMask()
{
    return stub<cdecl_t<u32 const>>(0xE9F30_Offset);
}

u32 const AudManager::GetCommentaryOnMask()
{
    return stub<cdecl_t<u32 const>>(0xE9F40_Offset);
}

u32 const AudManager::GetDSound3DMask()
{
    return stub<cdecl_t<u32 const>>(0xE9F10_Offset);
}

u32 const AudManager::GetEchoOnMask()
{
    return stub<cdecl_t<u32 const>>(0xE9F00_Offset);
}

u32 const AudManager::GetHiResMask()
{
    return stub<cdecl_t<u32 const>>(0xE9EE0_Offset);
}

u32 const AudManager::GetHiSampleSizeMask()
{
    return stub<cdecl_t<u32 const>>(0xE9EF0_Offset);
}

u32 const AudManager::GetSoundFXOnMask()
{
    return stub<cdecl_t<u32 const>>(0xE9F20_Offset);
}

u32 const AudManager::GetStereoOnMask()
{
    return stub<cdecl_t<u32 const>>(0xE9ED0_Offset);
}

u32 const AudManager::GetUsingEAXMask()
{
    return stub<cdecl_t<u32 const>>(0xE97B0_Offset);
}

u32 AudManager::CreateListenerSoundObj()
{
    return stub<thiscall_t<u32, AudManager*>>(0xE9820_Offset, this);
}

class CReverb* AudManager::GetListenerEAXObj()
{
    return stub<thiscall_t<class CReverb*, AudManager*>>(0xE9960_Offset, this);
}

void AudManager::Update3DCDMusic()
{
    return stub<thiscall_t<void, AudManager*>>(0xE9650_Offset, this);
}

void DeactivateApplication()
{
    return stub<cdecl_t<void>>(0xEA000_Offset);
}

void RestoreApplication()
{
    return stub<cdecl_t<void>>(0xEA040_Offset);
}
