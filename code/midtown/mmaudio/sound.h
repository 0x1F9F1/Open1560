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
    mmaudio:sound

    0x4EA250 | public: __thiscall AudSound::AudSound(unsigned long,int,short) | ??0AudSound@@QAE@KHF@Z
    0x4EA530 | public: virtual __thiscall AudSound::~AudSound(void) | ??1AudSound@@UAE@XZ
    0x4EA670 | public: void __thiscall AudSound::SetPriority(int) | ?SetPriority@AudSound@@QAEXH@Z
    0x4EA690 | public: void __thiscall AudSound::DeallocateSoundObjs(void) | ?DeallocateSoundObjs@AudSound@@QAEXXZ
    0x4EA6F0 | public: void __thiscall AudSound::ReallocateSoundObjs(void) | ?ReallocateSoundObjs@AudSound@@QAEXXZ
    0x4EA8D0 | public: int __thiscall AudSound::Load(char *,int) | ?Load@AudSound@@QAEHPADH@Z
    0x4EAB20 | public: int __thiscall AudSound::Load(int,int) | ?Load@AudSound@@QAEHHH@Z
    0x4EAD10 | public: void __thiscall AudSound::EnabledAction(void) | ?EnabledAction@AudSound@@QAEXXZ
    0x4EAD30 | public: void __thiscall AudSound::Enable(void) | ?Enable@AudSound@@QAEXXZ
    0x4EAD40 | public: void __thiscall AudSound::Disable(void) | ?Disable@AudSound@@QAEXXZ
    0x4EAD60 | public: virtual void __thiscall AudSound::Reset(void) | ?Reset@AudSound@@UAEXXZ
    0x4EAD70 | public: virtual void __thiscall AudSound::Update(void) | ?Update@AudSound@@UAEXXZ
    0x4EAE00 | public: void __thiscall AudSound::Update3DSettings(void) | ?Update3DSettings@AudSound@@QAEXXZ
    0x4EAFC0 | public: void __thiscall AudSound::SetPlayPosition(unsigned long) | ?SetPlayPosition@AudSound@@QAEXK@Z
    0x4EAFF0 | public: void __thiscall AudSound::PlayOnce(float,float) | ?PlayOnce@AudSound@@QAEXMM@Z
    0x4EB0D0 | public: void __thiscall AudSound::PlayLoop(float,float) | ?PlayLoop@AudSound@@QAEXMM@Z
    0x4EB1B0 | public: void __thiscall AudSound::Stop(void) | ?Stop@AudSound@@QAEXXZ
    0x4EB1F0 | public: void __thiscall AudSound::StopEchoBuffers(void) | ?StopEchoBuffers@AudSound@@QAEXXZ
    0x4EB210 | public: void __thiscall AudSound::SetFrequency(float,int) | ?SetFrequency@AudSound@@QAEXMH@Z
    0x4EB290 | public: float __thiscall AudSound::GetFrequency(int) | ?GetFrequency@AudSound@@QAEMH@Z
    0x4EB2D0 | public: void __thiscall AudSound::SetVolume(float,int) | ?SetVolume@AudSound@@QAEXMH@Z
    0x4EB350 | public: void __thiscall AudSound::SetEAXReverbMix(float,int) | ?SetEAXReverbMix@AudSound@@QAEXMH@Z
    0x4EB3B0 | public: float __thiscall AudSound::GetEAXReverbMix(int) | ?GetEAXReverbMix@AudSound@@QAEMH@Z
    0x4EB410 | public: void __thiscall AudSound::SetPan(float,int) | ?SetPan@AudSound@@QAEXMH@Z
    0x4EB4B0 | public: void __thiscall AudSound::SetEchoPan(float) | ?SetEchoPan@AudSound@@QAEXM@Z
    0x4EB510 | public: void __thiscall AudSound::SetEchoFrequency(float,int) | ?SetEchoFrequency@AudSound@@QAEXMH@Z
    0x4EB580 | public: void __thiscall AudSound::SetRamp(float,float) | ?SetRamp@AudSound@@QAEXMM@Z
    0x4EB660 | public: void __thiscall AudSound::Set3DMode(unsigned long) | ?Set3DMode@AudSound@@QAEXK@Z
    0x4EB690 | public: int __thiscall AudSound::IsPlaying(int) | ?IsPlaying@AudSound@@QAEHH@Z
    0x4EB6C0 | public: float __thiscall AudSound::GetSampleTime(void) | ?GetSampleTime@AudSound@@QAEMXZ
    0x4EB6E0 | public: virtual void __thiscall AudSound::AddWidgets(class Bank *) | ?AddWidgets@AudSound@@UAEXPAVBank@@@Z
    0x4EB730 | public: void __thiscall AudSound::SetConeAngles(unsigned long,unsigned long) | ?SetConeAngles@AudSound@@QAEXKK@Z
    0x4EB760 | public: void __thiscall AudSound::SetConeOutsideVolume(long) | ?SetConeOutsideVolume@AudSound@@QAEXJ@Z
    0x4EB790 | public: void __thiscall AudSound::SetConeOrientation(class Vector3 *) | ?SetConeOrientation@AudSound@@QAEXPAVVector3@@@Z
    0x4EB7C0 | public: void __thiscall AudSound::SetEchoAttenuation(float) | ?SetEchoAttenuation@AudSound@@QAEXM@Z
    0x4EB800 | public: unsigned char __thiscall AudSound::EchoPending(void) | ?EchoPending@AudSound@@QAEEXZ
    0x4EB820 | public: void __thiscall AudSound::SetChorusAttenuation(float) | ?SetChorusAttenuation@AudSound@@QAEXM@Z
    0x4EB860 | public: void __thiscall AudSound::SetChorusPitchMult(float) | ?SetChorusPitchMult@AudSound@@QAEXM@Z
    0x4EB8A0 | public: void __thiscall AudSound::SetChorusPitchMult(float,float) | ?SetChorusPitchMult@AudSound@@QAEXMM@Z
    0x4EB8F0 | public: void __thiscall AudSound::SetDelayTime(float) | ?SetDelayTime@AudSound@@QAEXM@Z
    0x4EB940 | public: void __thiscall AudSound::SetupOneShotLayerBuffers(int,float,int) | ?SetupOneShotLayerBuffers@AudSound@@QAEXHMH@Z
    0x4EB9B0 | public: int __thiscall AudSound::ReadyOneShotLayerBuf(void) | ?ReadyOneShotLayerBuf@AudSound@@QAEHXZ
    0x4EB9E0 | public: int __thiscall AudSound::AllOneShotLayersPlaying(void) | ?AllOneShotLayersPlaying@AudSound@@QAEHXZ
    0x4EBA10 | public: int __thiscall AudSound::GetEffect(void) | ?GetEffect@AudSound@@QAEHXZ
    0x4EBA30 | public: void __thiscall AudSound::SetEffect(int) | ?SetEffect@AudSound@@QAEXH@Z
    0x4EBAA0 | public: void __thiscall AudSound::DisableEffect(int) | ?DisableEffect@AudSound@@QAEXH@Z
    0x4EBAF0 | public: static unsigned long const __cdecl AudSound::Get2DFlags(void) | ?Get2DFlags@AudSound@@SA?BKXZ
    0x4EBB10 | public: static unsigned long const __cdecl AudSound::GetSoft2DFlags(void) | ?GetSoft2DFlags@AudSound@@SA?BKXZ
    0x4EBB30 | public: static unsigned long const __cdecl AudSound::GetFreqChange2DFlags(void) | ?GetFreqChange2DFlags@AudSound@@SA?BKXZ
    0x4EBB50 | public: static unsigned long const __cdecl AudSound::GetSoftFreqChange2DFlags(void) | ?GetSoftFreqChange2DFlags@AudSound@@SA?BKXZ
    0x4EBB70 | public: static unsigned long const __cdecl AudSound::Get3DFlags(void) | ?Get3DFlags@AudSound@@SA?BKXZ
    0x4EBB80 | public: static unsigned long const __cdecl AudSound::GetFreqChange3DFlags(void) | ?GetFreqChange3DFlags@AudSound@@SA?BKXZ
    0x4EBB90 | public: class CReverbBuffer * __thiscall AudSound::GetSecondaryEAXObj(int) | ?GetSecondaryEAXObj@AudSound@@QAEPAVCReverbBuffer@@H@Z
    0x4EBBC0 | public: void __thiscall AudSound::Enable3DMode(void) | ?Enable3DMode@AudSound@@QAEXXZ
    0x4EBC00 | public: void __thiscall AudSound::Disable3DMode(void) | ?Disable3DMode@AudSound@@QAEXXZ
    0x4EBC40 | public: class SoundObj * __thiscall AudSound::GetCurrentSoundObj(void) | ?GetCurrentSoundObj@AudSound@@QAEPAVSoundObj@@XZ
    0x4EBC50 | public: float __thiscall AudSound::GetVolume(int) | ?GetVolume@AudSound@@QAEMH@Z
    0x4EBC80 | public: virtual void * __thiscall AudSound::`vector deleting destructor'(unsigned int) | ??_EAudSound@@UAEPAXI@Z
    0x4EBC80 | public: virtual void * __thiscall AudSound::`scalar deleting destructor'(unsigned int) | ??_GAudSound@@UAEPAXI@Z
    0x61FD98 | private: static unsigned long const AudSound::s_DWDefault3DCtrlFlags | ?s_DWDefault3DCtrlFlags@AudSound@@0KB
    0x61FD9C | private: static unsigned long const AudSound::s_DWDefault2DCtrlFlags | ?s_DWDefault2DCtrlFlags@AudSound@@0KB
    0x61FDA0 | private: static unsigned long const AudSound::s_DWFreqChange3DCtrlFlags | ?s_DWFreqChange3DCtrlFlags@AudSound@@0KB
    0x61FDA4 | private: static unsigned long const AudSound::s_DWFreqChange2DCtrlFlags | ?s_DWFreqChange2DCtrlFlags@AudSound@@0KB
    0x61FDA8 | private: static unsigned long const AudSound::s_DWSoft2DCtrlFlags | ?s_DWSoft2DCtrlFlags@AudSound@@0KB
    0x61FDAC | private: static unsigned long const AudSound::s_DWSoftFreqChange2DCtrlFlags | ?s_DWSoftFreqChange2DCtrlFlags@AudSound@@0KB
    0x61FDC8 | const AudSound::`vftable' | ??_7AudSound@@6B@
*/

#include "arts7/node.h"

class AudSound final : public asNode
{
    // const AudSound::`vftable' @ 0x61FDC8

public:
    // 0x4EA250 | ??0AudSound@@QAE@KHF@Z
    ARTS_IMPORT AudSound(ulong arg1, i32 arg2, i16 arg3);

    // 0x4EBC80 | ??_GAudSound@@UAEPAXI@Z
    // 0x4EBC80 | ??_EAudSound@@UAEPAXI@Z
    // 0x4EA530 | ??1AudSound@@UAE@XZ
    ARTS_IMPORT ~AudSound() override;

    // 0x4EB6E0 | ?AddWidgets@AudSound@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x4EB9E0 | ?AllOneShotLayersPlaying@AudSound@@QAEHXZ
    ARTS_IMPORT i32 AllOneShotLayersPlaying();

    // 0x4EA690 | ?DeallocateSoundObjs@AudSound@@QAEXXZ
    ARTS_IMPORT void DeallocateSoundObjs();

    // 0x4EAD40 | ?Disable@AudSound@@QAEXXZ
    ARTS_IMPORT void Disable();

    // 0x4EBC00 | ?Disable3DMode@AudSound@@QAEXXZ
    ARTS_IMPORT void Disable3DMode();

    // 0x4EBAA0 | ?DisableEffect@AudSound@@QAEXH@Z
    ARTS_IMPORT void DisableEffect(i32 arg1);

    // 0x4EB800 | ?EchoPending@AudSound@@QAEEXZ | unused
    ARTS_IMPORT u8 EchoPending();

    // 0x4EAD30 | ?Enable@AudSound@@QAEXXZ
    ARTS_IMPORT void Enable();

    // 0x4EBBC0 | ?Enable3DMode@AudSound@@QAEXXZ
    ARTS_IMPORT void Enable3DMode();

    // 0x4EAD10 | ?EnabledAction@AudSound@@QAEXXZ
    ARTS_IMPORT void EnabledAction();

    // 0x4EBC40 | ?GetCurrentSoundObj@AudSound@@QAEPAVSoundObj@@XZ | unused
    ARTS_IMPORT class SoundObj* GetCurrentSoundObj();

    // 0x4EB3B0 | ?GetEAXReverbMix@AudSound@@QAEMH@Z | unused
    ARTS_IMPORT f32 GetEAXReverbMix(i32 arg1);

    // 0x4EBA10 | ?GetEffect@AudSound@@QAEHXZ
    ARTS_IMPORT i32 GetEffect();

    // 0x4EB290 | ?GetFrequency@AudSound@@QAEMH@Z | unused
    ARTS_IMPORT f32 GetFrequency(i32 arg1);

    // 0x4EB6C0 | ?GetSampleTime@AudSound@@QAEMXZ | unused
    ARTS_IMPORT f32 GetSampleTime();

    // 0x4EBB90 | ?GetSecondaryEAXObj@AudSound@@QAEPAVCReverbBuffer@@H@Z
    ARTS_IMPORT class CReverbBuffer* GetSecondaryEAXObj(i32 arg1);

    // 0x4EBC50 | ?GetVolume@AudSound@@QAEMH@Z
    ARTS_IMPORT f32 GetVolume(i32 arg1);

    // 0x4EB690 | ?IsPlaying@AudSound@@QAEHH@Z
    ARTS_IMPORT i32 IsPlaying(i32 arg1);

    // 0x4EA8D0 | ?Load@AudSound@@QAEHPADH@Z
    ARTS_IMPORT i32 Load(char* arg1, i32 arg2);

    // 0x4EAB20 | ?Load@AudSound@@QAEHHH@Z
    ARTS_IMPORT i32 Load(i32 arg1, i32 arg2);

    // 0x4EB0D0 | ?PlayLoop@AudSound@@QAEXMM@Z
    ARTS_IMPORT void PlayLoop(f32 arg1, f32 arg2);

    // 0x4EAFF0 | ?PlayOnce@AudSound@@QAEXMM@Z
    ARTS_IMPORT void PlayOnce(f32 arg1, f32 arg2);

    // 0x4EB9B0 | ?ReadyOneShotLayerBuf@AudSound@@QAEHXZ
    ARTS_IMPORT i32 ReadyOneShotLayerBuf();

    // 0x4EA6F0 | ?ReallocateSoundObjs@AudSound@@QAEXXZ
    ARTS_IMPORT void ReallocateSoundObjs();

    // 0x4EAD60 | ?Reset@AudSound@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4EB660 | ?Set3DMode@AudSound@@QAEXK@Z | unused
    ARTS_IMPORT void Set3DMode(ulong arg1);

    // 0x4EB820 | ?SetChorusAttenuation@AudSound@@QAEXM@Z | unused
    ARTS_IMPORT void SetChorusAttenuation(f32 arg1);

    // 0x4EB860 | ?SetChorusPitchMult@AudSound@@QAEXM@Z | unused
    ARTS_IMPORT void SetChorusPitchMult(f32 arg1);

    // 0x4EB8A0 | ?SetChorusPitchMult@AudSound@@QAEXMM@Z | unused
    ARTS_IMPORT void SetChorusPitchMult(f32 arg1, f32 arg2);

    // 0x4EB730 | ?SetConeAngles@AudSound@@QAEXKK@Z | unused
    ARTS_IMPORT void SetConeAngles(ulong arg1, ulong arg2);

    // 0x4EB790 | ?SetConeOrientation@AudSound@@QAEXPAVVector3@@@Z | unused
    ARTS_IMPORT void SetConeOrientation(class Vector3* arg1);

    // 0x4EB760 | ?SetConeOutsideVolume@AudSound@@QAEXJ@Z | unused
    ARTS_IMPORT void SetConeOutsideVolume(ilong arg1);

    // 0x4EB8F0 | ?SetDelayTime@AudSound@@QAEXM@Z
    ARTS_IMPORT void SetDelayTime(f32 arg1);

    // 0x4EB350 | ?SetEAXReverbMix@AudSound@@QAEXMH@Z
    ARTS_IMPORT void SetEAXReverbMix(f32 arg1, i32 arg2);

    // 0x4EB7C0 | ?SetEchoAttenuation@AudSound@@QAEXM@Z
    ARTS_IMPORT void SetEchoAttenuation(f32 arg1);

    // 0x4EB510 | ?SetEchoFrequency@AudSound@@QAEXMH@Z
    ARTS_IMPORT void SetEchoFrequency(f32 arg1, i32 arg2);

    // 0x4EB4B0 | ?SetEchoPan@AudSound@@QAEXM@Z | unused
    ARTS_IMPORT void SetEchoPan(f32 arg1);

    // 0x4EBA30 | ?SetEffect@AudSound@@QAEXH@Z
    ARTS_IMPORT void SetEffect(i32 arg1);

    // 0x4EB210 | ?SetFrequency@AudSound@@QAEXMH@Z
    ARTS_IMPORT void SetFrequency(f32 arg1, i32 arg2);

    // 0x4EB410 | ?SetPan@AudSound@@QAEXMH@Z
    ARTS_IMPORT void SetPan(f32 arg1, i32 arg2);

    // 0x4EAFC0 | ?SetPlayPosition@AudSound@@QAEXK@Z
    ARTS_IMPORT void SetPlayPosition(ulong arg1);

    // 0x4EA670 | ?SetPriority@AudSound@@QAEXH@Z
    ARTS_IMPORT void SetPriority(i32 arg1);

    // 0x4EB580 | ?SetRamp@AudSound@@QAEXMM@Z
    ARTS_IMPORT void SetRamp(f32 arg1, f32 arg2);

    // 0x4EB2D0 | ?SetVolume@AudSound@@QAEXMH@Z
    ARTS_IMPORT void SetVolume(f32 arg1, i32 arg2);

    // 0x4EB940 | ?SetupOneShotLayerBuffers@AudSound@@QAEXHMH@Z
    ARTS_IMPORT void SetupOneShotLayerBuffers(i32 arg1, f32 arg2, i32 arg3);

    // 0x4EB1B0 | ?Stop@AudSound@@QAEXXZ
    ARTS_IMPORT void Stop();

    // 0x4EB1F0 | ?StopEchoBuffers@AudSound@@QAEXXZ
    ARTS_IMPORT void StopEchoBuffers();

    // 0x4EAD70 | ?Update@AudSound@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4EAE00 | ?Update3DSettings@AudSound@@QAEXXZ
    ARTS_IMPORT void Update3DSettings();

    // 0x4EBAF0 | ?Get2DFlags@AudSound@@SA?BKXZ
    ARTS_IMPORT static ulong const Get2DFlags();

    // 0x4EBB70 | ?Get3DFlags@AudSound@@SA?BKXZ
    ARTS_IMPORT static ulong const Get3DFlags();

    // 0x4EBB30 | ?GetFreqChange2DFlags@AudSound@@SA?BKXZ
    ARTS_IMPORT static ulong const GetFreqChange2DFlags();

    // 0x4EBB80 | ?GetFreqChange3DFlags@AudSound@@SA?BKXZ
    ARTS_IMPORT static ulong const GetFreqChange3DFlags();

    // 0x4EBB10 | ?GetSoft2DFlags@AudSound@@SA?BKXZ
    ARTS_IMPORT static ulong const GetSoft2DFlags();

    // 0x4EBB50 | ?GetSoftFreqChange2DFlags@AudSound@@SA?BKXZ | unused
    ARTS_IMPORT static ulong const GetSoftFreqChange2DFlags();

private:
    // 0x61FD9C | ?s_DWDefault2DCtrlFlags@AudSound@@0KB
    ARTS_IMPORT static ulong const s_DWDefault2DCtrlFlags;

    // 0x61FD98 | ?s_DWDefault3DCtrlFlags@AudSound@@0KB
    ARTS_IMPORT static ulong const s_DWDefault3DCtrlFlags;

    // 0x61FDA4 | ?s_DWFreqChange2DCtrlFlags@AudSound@@0KB
    ARTS_IMPORT static ulong const s_DWFreqChange2DCtrlFlags;

    // 0x61FDA0 | ?s_DWFreqChange3DCtrlFlags@AudSound@@0KB
    ARTS_IMPORT static ulong const s_DWFreqChange3DCtrlFlags;

    // 0x61FDA8 | ?s_DWSoft2DCtrlFlags@AudSound@@0KB
    ARTS_IMPORT static ulong const s_DWSoft2DCtrlFlags;

    // 0x61FDAC | ?s_DWSoftFreqChange2DCtrlFlags@AudSound@@0KB
    ARTS_IMPORT static ulong const s_DWSoftFreqChange2DCtrlFlags;

    u8 gap20[0x98];
};

check_size(AudSound, 0xB8);
