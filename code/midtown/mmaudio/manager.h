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

#pragma once

/*
    mmaudio:manager

    0x4E8020 | public: __thiscall AudManager::AudManager(void) | ??0AudManager@@QAE@XZ
    0x4E8160 | public: virtual __thiscall AudManager::~AudManager(void) | ??1AudManager@@UAE@XZ
    0x4E82A0 | public: void __thiscall AudManager::DeallocateADFRecord(int) | ?DeallocateADFRecord@AudManager@@QAEXH@Z
    0x4E82D0 | public: void __thiscall AudManager::SetNumChannels(int) | ?SetNumChannels@AudManager@@QAEXH@Z
    0x4E8390 | public: int __thiscall AudManager::CheckPriority(int,int,int) | ?CheckPriority@AudManager@@QAEHHHH@Z
    0x4E8630 | public: void __thiscall AudManager::RemoveSoundFromPlayList(class AudSound *) | ?RemoveSoundFromPlayList@AudManager@@QAEXPAVAudSound@@@Z
    0x4E8670 | public: void __thiscall AudManager::RemoveSoundFromPlayList(int) | ?RemoveSoundFromPlayList@AudManager@@QAEXH@Z
    0x4E86C0 | public: virtual void __thiscall AudManager::Update(void) | ?Update@AudManager@@UAEXXZ
    0x4E86F0 | public: void __thiscall AudManager::Init(int,unsigned int,char *,short,short) | ?Init@AudManager@@QAEXHIPADFF@Z
    0x4E8820 | public: void __thiscall AudManager::LoadUIADF(void) | ?LoadUIADF@AudManager@@QAEXXZ
    0x4E8880 | public: void __thiscall AudManager::LoadCityADF(int,unsigned long) | ?LoadCityADF@AudManager@@QAEXHK@Z
    0x4E8930 | public: void __thiscall AudManager::InitCityADF(int,unsigned long) | ?InitCityADF@AudManager@@QAEXHK@Z
    0x4E89E0 | public: void __thiscall AudManager::InitUIADF(int,unsigned long) | ?InitUIADF@AudManager@@QAEXHK@Z
    0x4E8A70 | public: void __thiscall AudManager::DeallocateUIADF(void) | ?DeallocateUIADF@AudManager@@QAEXXZ
    0x4E8A80 | public: void __thiscall AudManager::DeallocateCityADF(void) | ?DeallocateCityADF@AudManager@@QAEXXZ
    0x4E8A90 | public: void __thiscall AudManager::DeallocateDSound(short,short) | ?DeallocateDSound@AudManager@@QAEXFF@Z
    0x4E8C10 | public: void __thiscall AudManager::ReallocateDSound(char *,short,short) | ?ReallocateDSound@AudManager@@QAEXPADFF@Z
    0x4E8DA0 | public: void __thiscall AudManager::SetStereo(int) | ?SetStereo@AudManager@@QAEXH@Z
    0x4E8DD0 | public: void __thiscall AudManager::AttenuateAudSounds(float) | ?AttenuateAudSounds@AudManager@@QAEXM@Z
    0x4E8E40 | public: int __thiscall AudManager::AddSound(class AudSound *) | ?AddSound@AudManager@@QAEHPAVAudSound@@@Z
    0x4E8EA0 | public: int __thiscall AudManager::AddStream(class AudStream *) | ?AddStream@AudManager@@QAEHPAVAudStream@@@Z
    0x4E8EF0 | public: void __thiscall AudManager::RemoveSound(class AudSound *,int) | ?RemoveSound@AudManager@@QAEXPAVAudSound@@H@Z
    0x4E8F60 | public: void __thiscall AudManager::RemoveStream(class AudStream *,int) | ?RemoveStream@AudManager@@QAEXPAVAudStream@@H@Z
    0x4E8FD0 | public: virtual void __thiscall AudManager::Reset(void) | ?Reset@AudManager@@UAEXXZ
    0x4E8FE0 | public: void __thiscall AudManager::Enable(char *,short,short) | ?Enable@AudManager@@QAEXPADFF@Z
    0x4E9090 | public: void __thiscall AudManager::Disable(short,short) | ?Disable@AudManager@@QAEXFF@Z
    0x4E9180 | public: void __thiscall AudManager::StopAllSounds(void) | ?StopAllSounds@AudManager@@QAEXXZ
    0x4E9220 | public: void __thiscall AudManager::ZeroVolAllSounds(void) | ?ZeroVolAllSounds@AudManager@@QAEXXZ
    0x4E9230 | public: int __thiscall AudManager::PlayCDTrack(int,int) | ?PlayCDTrack@AudManager@@QAEHHH@Z
    0x4E92B0 | public: int __thiscall AudManager::PlayCDTrack(int,unsigned char,unsigned char,unsigned char,int) | ?PlayCDTrack@AudManager@@QAEHHEEEH@Z
    0x4E9340 | public: int __thiscall AudManager::ResumeCDPlay(void) | ?ResumeCDPlay@AudManager@@QAEHXZ
    0x4E9360 | public: short __thiscall AudManager::GetNumCDTracks(void) | ?GetNumCDTracks@AudManager@@QAEFXZ
    0x4E9380 | public: unsigned char __thiscall AudManager::GetCDTrackNum(void) | ?GetCDTrackNum@AudManager@@QAEEXZ
    0x4E93A0 | public: short __thiscall AudManager::CDIsPlaying(void) | ?CDIsPlaying@AudManager@@QAEFXZ
    0x4E93C0 | public: void __thiscall AudManager::DisableCD(void) | ?DisableCD@AudManager@@QAEXXZ
    0x4E93E0 | public: void __thiscall AudManager::StopCD(void) | ?StopCD@AudManager@@QAEXXZ
    0x4E9400 | public: int __thiscall AudManager::EnableCD(void) | ?EnableCD@AudManager@@QAEHXZ
    0x4E9430 | public: void __thiscall AudManager::AssignWaveVolume(float) | ?AssignWaveVolume@AudManager@@QAEXM@Z
    0x4E9450 | public: float __thiscall AudManager::GetWaveVolume(void) | ?GetWaveVolume@AudManager@@QAEMXZ
    0x4E9470 | public: void __thiscall AudManager::AssignCDVolume(float) | ?AssignCDVolume@AudManager@@QAEXM@Z
    0x4E94B0 | public: void __thiscall AudManager::SetCDPlayMode(unsigned char) | ?SetCDPlayMode@AudManager@@QAEXE@Z
    0x4E94E0 | public: int __thiscall AudManager::CDIsEnabled(void) | ?CDIsEnabled@AudManager@@QAEHXZ
    0x4E9500 | public: float __thiscall AudManager::GetCDVolume(void) | ?GetCDVolume@AudManager@@QAEMXZ
    0x4E9530 | public: void __thiscall AudManager::AttenuateCDVolume(float) | ?AttenuateCDVolume@AudManager@@QAEXM@Z
    0x4E9570 | public: void __thiscall AudManager::AssignWaveBalance(float) | ?AssignWaveBalance@AudManager@@QAEXM@Z
    0x4E9590 | public: float __thiscall AudManager::GetWaveBalance(void) | ?GetWaveBalance@AudManager@@QAEMXZ
    0x4E95B0 | public: void __thiscall AudManager::AssignCDBalance(float) | ?AssignCDBalance@AudManager@@QAEXM@Z
    0x4E95D0 | public: float __thiscall AudManager::GetCDBalance(void) | ?GetCDBalance@AudManager@@QAEMXZ
    0x4E9600 | public: int __thiscall AudManager::IsStereo(void) | ?IsStereo@AudManager@@QAEHXZ
    0x4E9610 | public: virtual void __thiscall AudManager::AddWidgets(class Bank *) | ?AddWidgets@AudManager@@UAEXPAVBank@@@Z
    0x4E9620 | public: short __thiscall AudManager::Supports16Bit(void) | ?Supports16Bit@AudManager@@QAEFXZ
    0x4E9630 | public: unsigned char __thiscall AudManager::CheckCDFile(char *) | ?CheckCDFile@AudManager@@QAEEPAD@Z
    0x4E9650 | private: void __thiscall AudManager::Update3DCDMusic(void) | ?Update3DCDMusic@AudManager@@AAEXXZ
    0x4E97B0 | public: static unsigned int const __cdecl AudManager::GetUsingEAXMask(void) | ?GetUsingEAXMask@AudManager@@SA?BIXZ
    0x4E97C0 | public: unsigned int __thiscall AudManager::IsAlwaysEAX(void) | ?IsAlwaysEAX@AudManager@@QAEIXZ
    0x4E97D0 | public: void __thiscall AudManager::AlwaysEAX(unsigned int) | ?AlwaysEAX@AudManager@@QAEXI@Z
    0x4E9800 | public: unsigned int __thiscall AudManager::EAXEnabled(void) | ?EAXEnabled@AudManager@@QAEIXZ
    0x4E9810 | public: unsigned int __thiscall AudManager::DSound3DEnabled(void) | ?DSound3DEnabled@AudManager@@QAEIXZ
    0x4E9820 | private: unsigned int __thiscall AudManager::CreateListenerSoundObj(void) | ?CreateListenerSoundObj@AudManager@@AAEIXZ
    0x4E9960 | private: class CReverb * __thiscall AudManager::GetListenerEAXObj(void) | ?GetListenerEAXObj@AudManager@@AAEPAVCReverb@@XZ
    0x4E9970 | public: int __thiscall AudManager::SetEAXPreset(unsigned long,float,float,float) | ?SetEAXPreset@AudManager@@QAEHKMMM@Z
    0x4E99F0 | public: int __thiscall AudManager::SetEAXPreset(struct EAX_REVERBPROPERTIES *) | ?SetEAXPreset@AudManager@@QAEHPAUEAX_REVERBPROPERTIES@@@Z
    0x4E9A60 | public: void __thiscall AudManager::GetEAXAll(struct EAX_REVERBPROPERTIES *) | ?GetEAXAll@AudManager@@QAEXPAUEAX_REVERBPROPERTIES@@@Z
    0x4E9AB0 | public: int __thiscall AudManager::SetEAXEnvironmet(unsigned long) | ?SetEAXEnvironmet@AudManager@@QAEHK@Z
    0x4E9B20 | public: unsigned long __thiscall AudManager::GetEAXEnvironmet(void) | ?GetEAXEnvironmet@AudManager@@QAEKXZ
    0x4E9B70 | public: int __thiscall AudManager::SetEAXReverbVolume(float) | ?SetEAXReverbVolume@AudManager@@QAEHM@Z
    0x4E9BE0 | public: float __thiscall AudManager::GetEAXReverbVolume(void) | ?GetEAXReverbVolume@AudManager@@QAEMXZ
    0x4E9C30 | public: int __thiscall AudManager::SetEAXDecayTime(float) | ?SetEAXDecayTime@AudManager@@QAEHM@Z
    0x4E9CA0 | public: float __thiscall AudManager::GetEAXDecayTime(void) | ?GetEAXDecayTime@AudManager@@QAEMXZ
    0x4E9CF0 | public: int __thiscall AudManager::SetEAXDamping(float) | ?SetEAXDamping@AudManager@@QAEHM@Z
    0x4E9D60 | public: float __thiscall AudManager::GetEAXDamping(void) | ?GetEAXDamping@AudManager@@QAEMXZ
    0x4E9DB0 | public: virtual void __thiscall AudManager::UpdatePaused(void) | ?UpdatePaused@AudManager@@UAEXXZ
    0x4E9DD0 | public: void __thiscall AudManager::SetBitDepthAndSampleRate(int,unsigned long) | ?SetBitDepthAndSampleRate@AudManager@@QAEXHK@Z
    0x4E9E60 | public: char * * __thiscall AudManager::GetDeviceNames(void) | ?GetDeviceNames@AudManager@@QAEPAPADXZ
    0x4E9E80 | public: int __thiscall AudManager::GetNumDevices(void) | ?GetNumDevices@AudManager@@QAEHXZ
    0x4E9EA0 | public: char * __thiscall AudManager::GetActiveDeviceName(void) | ?GetActiveDeviceName@AudManager@@QAEPADXZ
    0x4E9EC0 | public: unsigned long __thiscall AudManager::GetNum3DHalBufs(void) | ?GetNum3DHalBufs@AudManager@@QAEKXZ
    0x4E9ED0 | public: static unsigned int const __cdecl AudManager::GetStereoOnMask(void) | ?GetStereoOnMask@AudManager@@SA?BIXZ
    0x4E9EE0 | public: static unsigned int const __cdecl AudManager::GetHiResMask(void) | ?GetHiResMask@AudManager@@SA?BIXZ
    0x4E9EF0 | public: static unsigned int const __cdecl AudManager::GetHiSampleSizeMask(void) | ?GetHiSampleSizeMask@AudManager@@SA?BIXZ
    0x4E9F00 | public: static unsigned int const __cdecl AudManager::GetEchoOnMask(void) | ?GetEchoOnMask@AudManager@@SA?BIXZ
    0x4E9F10 | public: static unsigned int const __cdecl AudManager::GetDSound3DMask(void) | ?GetDSound3DMask@AudManager@@SA?BIXZ
    0x4E9F20 | public: static unsigned int const __cdecl AudManager::GetSoundFXOnMask(void) | ?GetSoundFXOnMask@AudManager@@SA?BIXZ
    0x4E9F30 | public: static unsigned int const __cdecl AudManager::GetCDMusicOnMask(void) | ?GetCDMusicOnMask@AudManager@@SA?BIXZ
    0x4E9F40 | public: static unsigned int const __cdecl AudManager::GetCommentaryOnMask(void) | ?GetCommentaryOnMask@AudManager@@SA?BIXZ
    0x4E9F50 | public: void __thiscall AudManager::SetDeviceName(char *) | ?SetDeviceName@AudManager@@QAEXPAD@Z
    0x4E9F90 | public: unsigned long __thiscall AudManager::GetCDPosition(unsigned char *,unsigned char *,unsigned char *,unsigned char *) | ?GetCDPosition@AudManager@@QAEKPAE000@Z
    0x4E9FD0 | public: class MixerCTL * __thiscall AudManager::GetMixerPtr(void) | ?GetMixerPtr@AudManager@@QAEPAVMixerCTL@@XZ
    0x4E9FE0 | public: class mmVoiceCommentary * __thiscall AudManager::GetVoiceCommentaryPtr(void) | ?GetVoiceCommentaryPtr@AudManager@@QAEPAVmmVoiceCommentary@@XZ
    0x4E9FF0 | public: void __thiscall AudManager::SetVoiceCommentaryPtr(class mmVoiceCommentary *) | ?SetVoiceCommentaryPtr@AudManager@@QAEXPAVmmVoiceCommentary@@@Z
    0x4EA000 | void __cdecl DeactivateApplication(void) | ?DeactivateApplication@@YAXXZ
    0x4EA040 | void __cdecl RestoreApplication(void) | ?RestoreApplication@@YAXXZ
    0x4EA070 | public: static void __cdecl AudManager::DeclareFields(void) | ?DeclareFields@AudManager@@SAXXZ
    0x4EA1E0 | public: virtual class MetaClass * __thiscall AudManager::GetClass(void) | ?GetClass@AudManager@@UAEPAVMetaClass@@XZ
    0x4EA1F0 | public: virtual void * __thiscall AudManager::`vector deleting destructor'(unsigned int) | ??_EAudManager@@UAEPAXI@Z
    0x61FD48 | const AudManager::`vftable' | ??_7AudManager@@6B@
    0x7192F8 | class MetaClass AudManagerMetaClass | ?AudManagerMetaClass@@3VMetaClass@@A
    0x719320 | class AudManager * AUDMGRPTR | ?AUDMGRPTR@@3PAVAudManager@@A
*/

#include "arts7/node.h"

class AudManager : public asNode
{
    // const AudManager::`vftable' @ 0x61FD48

public:
    // 0x4E8020 | ??0AudManager@@QAE@XZ
    ARTS_IMPORT AudManager();

    // 0x4EA1F0 | ??_EAudManager@@UAEPAXI@Z
    // 0x4E8160 | ??1AudManager@@UAE@XZ
    ARTS_IMPORT ~AudManager() override;

    // 0x4E8E40 | ?AddSound@AudManager@@QAEHPAVAudSound@@@Z
    ARTS_IMPORT i32 AddSound(class AudSound* arg1);

    // 0x4E8EA0 | ?AddStream@AudManager@@QAEHPAVAudStream@@@Z
    ARTS_IMPORT i32 AddStream(class AudStream* arg1);

    // 0x4E9610 | ?AddWidgets@AudManager@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x4E97D0 | ?AlwaysEAX@AudManager@@QAEXI@Z
    ARTS_IMPORT void AlwaysEAX(u32 arg1);

    // 0x4E95B0 | ?AssignCDBalance@AudManager@@QAEXM@Z
    ARTS_IMPORT void AssignCDBalance(f32 arg1);

    // 0x4E9470 | ?AssignCDVolume@AudManager@@QAEXM@Z
    ARTS_IMPORT void AssignCDVolume(f32 arg1);

    // 0x4E9570 | ?AssignWaveBalance@AudManager@@QAEXM@Z
    ARTS_IMPORT void AssignWaveBalance(f32 arg1);

    // 0x4E9430 | ?AssignWaveVolume@AudManager@@QAEXM@Z
    ARTS_IMPORT void AssignWaveVolume(f32 arg1);

    // 0x4E8DD0 | ?AttenuateAudSounds@AudManager@@QAEXM@Z | unused
    ARTS_IMPORT void AttenuateAudSounds(f32 arg1);

    // 0x4E9530 | ?AttenuateCDVolume@AudManager@@QAEXM@Z
    ARTS_IMPORT void AttenuateCDVolume(f32 arg1);

    // 0x4E94E0 | ?CDIsEnabled@AudManager@@QAEHXZ
    ARTS_IMPORT i32 CDIsEnabled();

    // 0x4E93A0 | ?CDIsPlaying@AudManager@@QAEFXZ
    ARTS_IMPORT i16 CDIsPlaying();

    // 0x4E9630 | ?CheckCDFile@AudManager@@QAEEPAD@Z
    ARTS_IMPORT u8 CheckCDFile(char* arg1);

    // 0x4E8390 | ?CheckPriority@AudManager@@QAEHHHH@Z
    ARTS_IMPORT i32 CheckPriority(i32 arg1, i32 arg2, i32 arg3);

    // 0x4E9810 | ?DSound3DEnabled@AudManager@@QAEIXZ
    ARTS_IMPORT u32 DSound3DEnabled();

    // 0x4E82A0 | ?DeallocateADFRecord@AudManager@@QAEXH@Z | unused
    ARTS_IMPORT void DeallocateADFRecord(i32 arg1);

    // 0x4E8A80 | ?DeallocateCityADF@AudManager@@QAEXXZ | unused
    ARTS_IMPORT void DeallocateCityADF();

    // 0x4E8A90 | ?DeallocateDSound@AudManager@@QAEXFF@Z
    ARTS_IMPORT void DeallocateDSound(i16 arg1, i16 arg2);

    // 0x4E8A70 | ?DeallocateUIADF@AudManager@@QAEXXZ
    ARTS_IMPORT void DeallocateUIADF();

    // 0x4E9090 | ?Disable@AudManager@@QAEXFF@Z
    ARTS_IMPORT void Disable(i16 arg1, i16 arg2);

    // 0x4E93C0 | ?DisableCD@AudManager@@QAEXXZ | unused
    ARTS_IMPORT void DisableCD();

    // 0x4E9800 | ?EAXEnabled@AudManager@@QAEIXZ
    ARTS_IMPORT u32 EAXEnabled();

    // 0x4E8FE0 | ?Enable@AudManager@@QAEXPADFF@Z
    ARTS_IMPORT void Enable(char* arg1, i16 arg2, i16 arg3);

    // 0x4E9400 | ?EnableCD@AudManager@@QAEHXZ
    ARTS_IMPORT i32 EnableCD();

    // 0x4E9EA0 | ?GetActiveDeviceName@AudManager@@QAEPADXZ
    ARTS_IMPORT char* GetActiveDeviceName();

    // 0x4E95D0 | ?GetCDBalance@AudManager@@QAEMXZ | unused
    ARTS_IMPORT f32 GetCDBalance();

    // 0x4E9F90 | ?GetCDPosition@AudManager@@QAEKPAE000@Z
    ARTS_IMPORT u32 GetCDPosition(u8* arg1, u8* arg2, u8* arg3, u8* arg4);

    // 0x4E9380 | ?GetCDTrackNum@AudManager@@QAEEXZ
    ARTS_IMPORT u8 GetCDTrackNum();

    // 0x4E9500 | ?GetCDVolume@AudManager@@QAEMXZ | unused
    ARTS_IMPORT f32 GetCDVolume();

    // 0x4EA1E0 | ?GetClass@AudManager@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4E9E60 | ?GetDeviceNames@AudManager@@QAEPAPADXZ
    ARTS_IMPORT char** GetDeviceNames();

    // 0x4E9A60 | ?GetEAXAll@AudManager@@QAEXPAUEAX_REVERBPROPERTIES@@@Z | unused
    ARTS_IMPORT void GetEAXAll(struct EAX_REVERBPROPERTIES* arg1);

    // 0x4E9D60 | ?GetEAXDamping@AudManager@@QAEMXZ | unused
    ARTS_IMPORT f32 GetEAXDamping();

    // 0x4E9CA0 | ?GetEAXDecayTime@AudManager@@QAEMXZ | unused
    ARTS_IMPORT f32 GetEAXDecayTime();

    // 0x4E9B20 | ?GetEAXEnvironmet@AudManager@@QAEKXZ | unused
    ARTS_IMPORT u32 GetEAXEnvironmet();

    // 0x4E9BE0 | ?GetEAXReverbVolume@AudManager@@QAEMXZ | unused
    ARTS_IMPORT f32 GetEAXReverbVolume();

    // 0x4E9FD0 | ?GetMixerPtr@AudManager@@QAEPAVMixerCTL@@XZ
    ARTS_IMPORT class MixerCTL* GetMixerPtr();

    // 0x4E9EC0 | ?GetNum3DHalBufs@AudManager@@QAEKXZ
    ARTS_EXPORT u32 GetNum3DHalBufs();

    // 0x4E9360 | ?GetNumCDTracks@AudManager@@QAEFXZ
    ARTS_IMPORT i16 GetNumCDTracks();

    // 0x4E9E80 | ?GetNumDevices@AudManager@@QAEHXZ
    ARTS_IMPORT i32 GetNumDevices();

    // 0x4E9FE0 | ?GetVoiceCommentaryPtr@AudManager@@QAEPAVmmVoiceCommentary@@XZ
    ARTS_IMPORT class mmVoiceCommentary* GetVoiceCommentaryPtr();

    // 0x4E9590 | ?GetWaveBalance@AudManager@@QAEMXZ | unused
    ARTS_IMPORT f32 GetWaveBalance();

    // 0x4E9450 | ?GetWaveVolume@AudManager@@QAEMXZ | unused
    ARTS_IMPORT f32 GetWaveVolume();

    // 0x4E86F0 | ?Init@AudManager@@QAEXHIPADFF@Z
    ARTS_IMPORT void Init(i32 arg1, u32 arg2, char* arg3, i16 arg4, i16 arg5);

    // 0x4E8930 | ?InitCityADF@AudManager@@QAEXHK@Z | unused
    ARTS_IMPORT void InitCityADF(i32 arg1, u32 arg2);

    // 0x4E89E0 | ?InitUIADF@AudManager@@QAEXHK@Z | unused
    ARTS_IMPORT void InitUIADF(i32 arg1, u32 arg2);

    // 0x4E97C0 | ?IsAlwaysEAX@AudManager@@QAEIXZ
    ARTS_IMPORT u32 IsAlwaysEAX();

    // 0x4E9600 | ?IsStereo@AudManager@@QAEHXZ
    ARTS_IMPORT i32 IsStereo();

    // 0x4E8880 | ?LoadCityADF@AudManager@@QAEXHK@Z | unused
    ARTS_IMPORT void LoadCityADF(i32 arg1, u32 arg2);

    // 0x4E8820 | ?LoadUIADF@AudManager@@QAEXXZ | unused
    ARTS_IMPORT void LoadUIADF();

    // 0x4E9230 | ?PlayCDTrack@AudManager@@QAEHHH@Z
    ARTS_IMPORT i32 PlayCDTrack(i32 arg1, i32 arg2);

    // 0x4E92B0 | ?PlayCDTrack@AudManager@@QAEHHEEEH@Z
    ARTS_IMPORT i32 PlayCDTrack(i32 arg1, u8 arg2, u8 arg3, u8 arg4, i32 arg5);

    // 0x4E8C10 | ?ReallocateDSound@AudManager@@QAEXPADFF@Z
    ARTS_IMPORT void ReallocateDSound(char* arg1, i16 arg2, i16 arg3);

    // 0x4E8EF0 | ?RemoveSound@AudManager@@QAEXPAVAudSound@@H@Z
    ARTS_IMPORT void RemoveSound(class AudSound* arg1, i32 arg2);

    // 0x4E8630 | ?RemoveSoundFromPlayList@AudManager@@QAEXPAVAudSound@@@Z
    ARTS_IMPORT void RemoveSoundFromPlayList(class AudSound* arg1);

    // 0x4E8670 | ?RemoveSoundFromPlayList@AudManager@@QAEXH@Z
    ARTS_IMPORT void RemoveSoundFromPlayList(i32 arg1);

    // 0x4E8F60 | ?RemoveStream@AudManager@@QAEXPAVAudStream@@H@Z
    ARTS_IMPORT void RemoveStream(class AudStream* arg1, i32 arg2);

    // 0x4E8FD0 | ?Reset@AudManager@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // 0x4E9340 | ?ResumeCDPlay@AudManager@@QAEHXZ | unused
    ARTS_IMPORT i32 ResumeCDPlay();

    // 0x4E9DD0 | ?SetBitDepthAndSampleRate@AudManager@@QAEXHK@Z
    ARTS_IMPORT void SetBitDepthAndSampleRate(i32 arg1, u32 arg2);

    // 0x4E94B0 | ?SetCDPlayMode@AudManager@@QAEXE@Z
    ARTS_IMPORT void SetCDPlayMode(u8 arg1);

    // 0x4E9F50 | ?SetDeviceName@AudManager@@QAEXPAD@Z
    ARTS_IMPORT void SetDeviceName(char* arg1);

    // 0x4E9CF0 | ?SetEAXDamping@AudManager@@QAEHM@Z | unused
    ARTS_IMPORT i32 SetEAXDamping(f32 arg1);

    // 0x4E9C30 | ?SetEAXDecayTime@AudManager@@QAEHM@Z | unused
    ARTS_IMPORT i32 SetEAXDecayTime(f32 arg1);

    // 0x4E9AB0 | ?SetEAXEnvironmet@AudManager@@QAEHK@Z | unused
    ARTS_IMPORT i32 SetEAXEnvironmet(u32 arg1);

    // 0x4E99F0 | ?SetEAXPreset@AudManager@@QAEHPAUEAX_REVERBPROPERTIES@@@Z
    ARTS_IMPORT i32 SetEAXPreset(struct EAX_REVERBPROPERTIES* arg1);

    // 0x4E9970 | ?SetEAXPreset@AudManager@@QAEHKMMM@Z
    ARTS_IMPORT i32 SetEAXPreset(u32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x4E9B70 | ?SetEAXReverbVolume@AudManager@@QAEHM@Z | unused
    ARTS_IMPORT i32 SetEAXReverbVolume(f32 arg1);

    // 0x4E82D0 | ?SetNumChannels@AudManager@@QAEXH@Z
    ARTS_IMPORT void SetNumChannels(i32 arg1);

    // 0x4E8DA0 | ?SetStereo@AudManager@@QAEXH@Z | unused
    ARTS_IMPORT void SetStereo(i32 arg1);

    // 0x4E9FF0 | ?SetVoiceCommentaryPtr@AudManager@@QAEXPAVmmVoiceCommentary@@@Z
    ARTS_IMPORT void SetVoiceCommentaryPtr(class mmVoiceCommentary* arg1);

    // 0x4E9180 | ?StopAllSounds@AudManager@@QAEXXZ
    ARTS_IMPORT void StopAllSounds();

    // 0x4E93E0 | ?StopCD@AudManager@@QAEXXZ
    ARTS_IMPORT void StopCD();

    // 0x4E9620 | ?Supports16Bit@AudManager@@QAEFXZ
    ARTS_IMPORT i16 Supports16Bit();

    // 0x4E86C0 | ?Update@AudManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4E9DB0 | ?UpdatePaused@AudManager@@UAEXXZ
    ARTS_IMPORT void UpdatePaused() override;

    // 0x4E9220 | ?ZeroVolAllSounds@AudManager@@QAEXXZ | unused
    ARTS_EXPORT void ZeroVolAllSounds();

    // 0x4EA070 | ?DeclareFields@AudManager@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // 0x4E9F30 | ?GetCDMusicOnMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static u32 const GetCDMusicOnMask();

    // 0x4E9F40 | ?GetCommentaryOnMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static u32 const GetCommentaryOnMask();

    // 0x4E9F10 | ?GetDSound3DMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static u32 const GetDSound3DMask();

    // 0x4E9F00 | ?GetEchoOnMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static u32 const GetEchoOnMask();

    // 0x4E9EE0 | ?GetHiResMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static u32 const GetHiResMask();

    // 0x4E9EF0 | ?GetHiSampleSizeMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static u32 const GetHiSampleSizeMask();

    // 0x4E9F20 | ?GetSoundFXOnMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static u32 const GetSoundFXOnMask();

    // 0x4E9ED0 | ?GetStereoOnMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static u32 const GetStereoOnMask();

    // 0x4E97B0 | ?GetUsingEAXMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static u32 const GetUsingEAXMask();

private:
    // 0x4E9820 | ?CreateListenerSoundObj@AudManager@@AAEIXZ
    ARTS_IMPORT u32 CreateListenerSoundObj();

    // 0x4E9960 | ?GetListenerEAXObj@AudManager@@AAEPAVCReverb@@XZ
    ARTS_IMPORT class CReverb* GetListenerEAXObj();

    // 0x4E9650 | ?Update3DCDMusic@AudManager@@AAEXXZ
    ARTS_IMPORT void Update3DCDMusic();

    u8 gap20[0x80];
};

check_size(AudManager, 0xA0);

// 0x4EA000 | ?DeactivateApplication@@YAXXZ
ARTS_IMPORT void DeactivateApplication();

// 0x4EA040 | ?RestoreApplication@@YAXXZ
ARTS_IMPORT void RestoreApplication();

// 0x719320 | ?AUDMGRPTR@@3PAVAudManager@@A
ARTS_IMPORT extern class AudManager* AUDMGRPTR;

// 0x7192F8 | ?AudManagerMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass AudManagerMetaClass;
