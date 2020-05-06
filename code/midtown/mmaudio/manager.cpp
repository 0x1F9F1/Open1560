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
    return stub<thiscall_t<i32, AudManager*, class AudSound*>>(0x4E8E40, this, arg1);
}

i32 AudManager::AddStream(class AudStream* arg1)
{
    return stub<thiscall_t<i32, AudManager*, class AudStream*>>(0x4E8EA0, this, arg1);
}

void AudManager::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, AudManager*, class Bank*>>(0x4E9610, this, arg1);
}

void AudManager::AlwaysEAX(u32 arg1)
{
    return stub<thiscall_t<void, AudManager*, u32>>(0x4E97D0, this, arg1);
}

void AudManager::AssignCDBalance(f32 arg1)
{
    return stub<thiscall_t<void, AudManager*, f32>>(0x4E95B0, this, arg1);
}

void AudManager::AssignCDVolume(f32 arg1)
{
    return stub<thiscall_t<void, AudManager*, f32>>(0x4E9470, this, arg1);
}

void AudManager::AssignWaveBalance(f32 arg1)
{
    return stub<thiscall_t<void, AudManager*, f32>>(0x4E9570, this, arg1);
}

void AudManager::AssignWaveVolume(f32 arg1)
{
    return stub<thiscall_t<void, AudManager*, f32>>(0x4E9430, this, arg1);
}

void AudManager::AttenuateAudSounds(f32 arg1)
{
    return stub<thiscall_t<void, AudManager*, f32>>(0x4E8DD0, this, arg1);
}

void AudManager::AttenuateCDVolume(f32 arg1)
{
    return stub<thiscall_t<void, AudManager*, f32>>(0x4E9530, this, arg1);
}

i32 AudManager::CDIsEnabled()
{
    return stub<thiscall_t<i32, AudManager*>>(0x4E94E0, this);
}

i16 AudManager::CDIsPlaying()
{
    return stub<thiscall_t<i16, AudManager*>>(0x4E93A0, this);
}

u8 AudManager::CheckCDFile(char* arg1)
{
    return stub<thiscall_t<u8, AudManager*, char*>>(0x4E9630, this, arg1);
}

i32 AudManager::CheckPriority(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<i32, AudManager*, i32, i32, i32>>(0x4E8390, this, arg1, arg2, arg3);
}

u32 AudManager::DSound3DEnabled()
{
    return stub<thiscall_t<u32, AudManager*>>(0x4E9810, this);
}

void AudManager::DeallocateADFRecord(i32 arg1)
{
    return stub<thiscall_t<void, AudManager*, i32>>(0x4E82A0, this, arg1);
}

void AudManager::DeallocateCityADF()
{
    return stub<thiscall_t<void, AudManager*>>(0x4E8A80, this);
}

void AudManager::DeallocateDSound(i16 arg1, i16 arg2)
{
    return stub<thiscall_t<void, AudManager*, i16, i16>>(0x4E8A90, this, arg1, arg2);
}

void AudManager::DeallocateUIADF()
{
    return stub<thiscall_t<void, AudManager*>>(0x4E8A70, this);
}

void AudManager::Disable(i16 arg1, i16 arg2)
{
    return stub<thiscall_t<void, AudManager*, i16, i16>>(0x4E9090, this, arg1, arg2);
}

void AudManager::DisableCD()
{
    return stub<thiscall_t<void, AudManager*>>(0x4E93C0, this);
}

u32 AudManager::EAXEnabled()
{
    return stub<thiscall_t<u32, AudManager*>>(0x4E9800, this);
}

void AudManager::Enable(char* arg1, i16 arg2, i16 arg3)
{
    return stub<thiscall_t<void, AudManager*, char*, i16, i16>>(0x4E8FE0, this, arg1, arg2, arg3);
}

i32 AudManager::EnableCD()
{
    return stub<thiscall_t<i32, AudManager*>>(0x4E9400, this);
}

char* AudManager::GetActiveDeviceName()
{
    return stub<thiscall_t<char*, AudManager*>>(0x4E9EA0, this);
}

f32 AudManager::GetCDBalance()
{
    return stub<thiscall_t<f32, AudManager*>>(0x4E95D0, this);
}

u32 AudManager::GetCDPosition(u8* arg1, u8* arg2, u8* arg3, u8* arg4)
{
    return stub<thiscall_t<u32, AudManager*, u8*, u8*, u8*, u8*>>(0x4E9F90, this, arg1, arg2, arg3, arg4);
}

u8 AudManager::GetCDTrackNum()
{
    return stub<thiscall_t<u8, AudManager*>>(0x4E9380, this);
}

f32 AudManager::GetCDVolume()
{
    return stub<thiscall_t<f32, AudManager*>>(0x4E9500, this);
}

class MetaClass* AudManager::GetClass()
{
    return stub<thiscall_t<class MetaClass*, AudManager*>>(0x4EA1E0, this);
}

char** AudManager::GetDeviceNames()
{
    return stub<thiscall_t<char**, AudManager*>>(0x4E9E60, this);
}

void AudManager::GetEAXAll(struct EAX_REVERBPROPERTIES* arg1)
{
    return stub<thiscall_t<void, AudManager*, struct EAX_REVERBPROPERTIES*>>(0x4E9A60, this, arg1);
}

f32 AudManager::GetEAXDamping()
{
    return stub<thiscall_t<f32, AudManager*>>(0x4E9D60, this);
}

f32 AudManager::GetEAXDecayTime()
{
    return stub<thiscall_t<f32, AudManager*>>(0x4E9CA0, this);
}

u32 AudManager::GetEAXEnvironmet()
{
    return stub<thiscall_t<u32, AudManager*>>(0x4E9B20, this);
}

f32 AudManager::GetEAXReverbVolume()
{
    return stub<thiscall_t<f32, AudManager*>>(0x4E9BE0, this);
}

class MixerCTL* AudManager::GetMixerPtr()
{
    return stub<thiscall_t<class MixerCTL*, AudManager*>>(0x4E9FD0, this);
}

u32 AudManager::GetNum3DHalBufs()
{
    return stub<thiscall_t<u32, AudManager*>>(0x4E9EC0, this);
}

i16 AudManager::GetNumCDTracks()
{
    return stub<thiscall_t<i16, AudManager*>>(0x4E9360, this);
}

i32 AudManager::GetNumDevices()
{
    return stub<thiscall_t<i32, AudManager*>>(0x4E9E80, this);
}

class mmVoiceCommentary* AudManager::GetVoiceCommentaryPtr()
{
    return stub<thiscall_t<class mmVoiceCommentary*, AudManager*>>(0x4E9FE0, this);
}

f32 AudManager::GetWaveBalance()
{
    return stub<thiscall_t<f32, AudManager*>>(0x4E9590, this);
}

f32 AudManager::GetWaveVolume()
{
    return stub<thiscall_t<f32, AudManager*>>(0x4E9450, this);
}

void AudManager::Init(i32 arg1, u32 arg2, char* arg3, i16 arg4, i16 arg5)
{
    return stub<thiscall_t<void, AudManager*, i32, u32, char*, i16, i16>>(0x4E86F0, this, arg1, arg2, arg3, arg4, arg5);
}

void AudManager::InitCityADF(i32 arg1, u32 arg2)
{
    return stub<thiscall_t<void, AudManager*, i32, u32>>(0x4E8930, this, arg1, arg2);
}

void AudManager::InitUIADF(i32 arg1, u32 arg2)
{
    return stub<thiscall_t<void, AudManager*, i32, u32>>(0x4E89E0, this, arg1, arg2);
}

u32 AudManager::IsAlwaysEAX()
{
    return stub<thiscall_t<u32, AudManager*>>(0x4E97C0, this);
}

i32 AudManager::IsStereo()
{
    return stub<thiscall_t<i32, AudManager*>>(0x4E9600, this);
}

void AudManager::LoadCityADF(i32 arg1, u32 arg2)
{
    return stub<thiscall_t<void, AudManager*, i32, u32>>(0x4E8880, this, arg1, arg2);
}

void AudManager::LoadUIADF()
{
    return stub<thiscall_t<void, AudManager*>>(0x4E8820, this);
}

i32 AudManager::PlayCDTrack(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, AudManager*, i32, i32>>(0x4E9230, this, arg1, arg2);
}

i32 AudManager::PlayCDTrack(i32 arg1, u8 arg2, u8 arg3, u8 arg4, i32 arg5)
{
    return stub<thiscall_t<i32, AudManager*, i32, u8, u8, u8, i32>>(0x4E92B0, this, arg1, arg2, arg3, arg4, arg5);
}

void AudManager::ReallocateDSound(char* arg1, i16 arg2, i16 arg3)
{
    return stub<thiscall_t<void, AudManager*, char*, i16, i16>>(0x4E8C10, this, arg1, arg2, arg3);
}

void AudManager::RemoveSound(class AudSound* arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudManager*, class AudSound*, i32>>(0x4E8EF0, this, arg1, arg2);
}

void AudManager::RemoveSoundFromPlayList(class AudSound* arg1)
{
    return stub<thiscall_t<void, AudManager*, class AudSound*>>(0x4E8630, this, arg1);
}

void AudManager::RemoveSoundFromPlayList(i32 arg1)
{
    return stub<thiscall_t<void, AudManager*, i32>>(0x4E8670, this, arg1);
}

void AudManager::RemoveStream(class AudStream* arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudManager*, class AudStream*, i32>>(0x4E8F60, this, arg1, arg2);
}

void AudManager::Reset()
{
    return stub<thiscall_t<void, AudManager*>>(0x4E8FD0, this);
}

i32 AudManager::ResumeCDPlay()
{
    return stub<thiscall_t<i32, AudManager*>>(0x4E9340, this);
}

void AudManager::SetBitDepthAndSampleRate(i32 arg1, u32 arg2)
{
    return stub<thiscall_t<void, AudManager*, i32, u32>>(0x4E9DD0, this, arg1, arg2);
}

void AudManager::SetCDPlayMode(u8 arg1)
{
    return stub<thiscall_t<void, AudManager*, u8>>(0x4E94B0, this, arg1);
}

void AudManager::SetDeviceName(char* arg1)
{
    return stub<thiscall_t<void, AudManager*, char*>>(0x4E9F50, this, arg1);
}

i32 AudManager::SetEAXDamping(f32 arg1)
{
    return stub<thiscall_t<i32, AudManager*, f32>>(0x4E9CF0, this, arg1);
}

i32 AudManager::SetEAXDecayTime(f32 arg1)
{
    return stub<thiscall_t<i32, AudManager*, f32>>(0x4E9C30, this, arg1);
}

i32 AudManager::SetEAXEnvironmet(u32 arg1)
{
    return stub<thiscall_t<i32, AudManager*, u32>>(0x4E9AB0, this, arg1);
}

i32 AudManager::SetEAXPreset(struct EAX_REVERBPROPERTIES* arg1)
{
    return stub<thiscall_t<i32, AudManager*, struct EAX_REVERBPROPERTIES*>>(0x4E99F0, this, arg1);
}

i32 AudManager::SetEAXPreset(u32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<i32, AudManager*, u32, f32, f32, f32>>(0x4E9970, this, arg1, arg2, arg3, arg4);
}

i32 AudManager::SetEAXReverbVolume(f32 arg1)
{
    return stub<thiscall_t<i32, AudManager*, f32>>(0x4E9B70, this, arg1);
}

void AudManager::SetNumChannels(i32 arg1)
{
    return stub<thiscall_t<void, AudManager*, i32>>(0x4E82D0, this, arg1);
}

void AudManager::SetStereo(i32 arg1)
{
    return stub<thiscall_t<void, AudManager*, i32>>(0x4E8DA0, this, arg1);
}

void AudManager::SetVoiceCommentaryPtr(class mmVoiceCommentary* arg1)
{
    return stub<thiscall_t<void, AudManager*, class mmVoiceCommentary*>>(0x4E9FF0, this, arg1);
}

void AudManager::StopAllSounds()
{
    return stub<thiscall_t<void, AudManager*>>(0x4E9180, this);
}

void AudManager::StopCD()
{
    return stub<thiscall_t<void, AudManager*>>(0x4E93E0, this);
}

i16 AudManager::Supports16Bit()
{
    return stub<thiscall_t<i16, AudManager*>>(0x4E9620, this);
}

void AudManager::Update()
{
    return stub<thiscall_t<void, AudManager*>>(0x4E86C0, this);
}

void AudManager::UpdatePaused()
{
    return stub<thiscall_t<void, AudManager*>>(0x4E9DB0, this);
}

void AudManager::ZeroVolAllSounds()
{
    return stub<thiscall_t<void, AudManager*>>(0x4E9220, this);
}

void AudManager::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4EA070);
}

u32 const AudManager::GetCDMusicOnMask()
{
    return stub<cdecl_t<u32 const>>(0x4E9F30);
}

u32 const AudManager::GetCommentaryOnMask()
{
    return stub<cdecl_t<u32 const>>(0x4E9F40);
}

u32 const AudManager::GetDSound3DMask()
{
    return stub<cdecl_t<u32 const>>(0x4E9F10);
}

u32 const AudManager::GetEchoOnMask()
{
    return stub<cdecl_t<u32 const>>(0x4E9F00);
}

u32 const AudManager::GetHiResMask()
{
    return stub<cdecl_t<u32 const>>(0x4E9EE0);
}

u32 const AudManager::GetHiSampleSizeMask()
{
    return stub<cdecl_t<u32 const>>(0x4E9EF0);
}

u32 const AudManager::GetSoundFXOnMask()
{
    return stub<cdecl_t<u32 const>>(0x4E9F20);
}

u32 const AudManager::GetStereoOnMask()
{
    return stub<cdecl_t<u32 const>>(0x4E9ED0);
}

u32 const AudManager::GetUsingEAXMask()
{
    return stub<cdecl_t<u32 const>>(0x4E97B0);
}

u32 AudManager::CreateListenerSoundObj()
{
    return stub<thiscall_t<u32, AudManager*>>(0x4E9820, this);
}

class CReverb* AudManager::GetListenerEAXObj()
{
    return stub<thiscall_t<class CReverb*, AudManager*>>(0x4E9960, this);
}

void AudManager::Update3DCDMusic()
{
    return stub<thiscall_t<void, AudManager*>>(0x4E9650, this);
}

void DeactivateApplication()
{
    return stub<cdecl_t<void>>(0x4EA000);
}

void RestoreApplication()
{
    return stub<cdecl_t<void>>(0x4EA040);
}
