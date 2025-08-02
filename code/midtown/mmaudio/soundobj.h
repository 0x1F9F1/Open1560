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
    mmaudio:soundobj

    0x4F0B20 | public: __thiscall SoundObj::SoundObj(void) | ??0SoundObj@@QAE@XZ
    0x4F0BE0 | public: __thiscall SoundObj::~SoundObj(void) | ??1SoundObj@@QAE@XZ
    0x4F0CA0 | public: void __thiscall SoundObj::DeallocateEffects(void) | ?DeallocateEffects@SoundObj@@QAEXXZ
    0x4F0D70 | public: void __thiscall SoundObj::SetDelayTime(float) | ?SetDelayTime@SoundObj@@QAEXM@Z
    0x4F0E90 | public: short __thiscall SoundObj::SetupOneShotLayerBuffers(short,float,char *) | ?SetupOneShotLayerBuffers@SoundObj@@QAEFFMPAD@Z
    0x4F0F20 | public: void __thiscall SoundObj::FreeOneShotLayerBuffers(void) | ?FreeOneShotLayerBuffers@SoundObj@@QAEXXZ
    0x4F0FA0 | public: int __thiscall SoundObj::DSCreateSoundBuffer(struct IDirectSoundBuffer * *,unsigned char) | ?DSCreateSoundBuffer@SoundObj@@QAEHPAPAUIDirectSoundBuffer@@E@Z
    0x4F1030 | public: struct IDirectSoundBuffer * __thiscall SoundObj::DSLoadSoundBuffer(char const *,unsigned long) | ?DSLoadSoundBuffer@SoundObj@@QAEPAUIDirectSoundBuffer@@PBDK@Z
    0x4F1210 | public: void __thiscall SoundObj::DSLoadSoundBuffer(unsigned short,unsigned long) | ?DSLoadSoundBuffer@SoundObj@@QAEXGK@Z
    0x4F1350 | public: void __thiscall SoundObj::ReadADFRecord(unsigned short) | ?ReadADFRecord@SoundObj@@QAEXG@Z
    0x4F1510 | public: int __thiscall SoundObj::DSGetWaveResource(struct HINSTANCE__ *,char const *,struct tWAVEFORMATEX * *,unsigned char * *,unsigned long *) | ?DSGetWaveResource@SoundObj@@QAEHPAUHINSTANCE__@@PBDPAPAUtWAVEFORMATEX@@PAPAEPAK@Z
    0x4F15F0 | public: void __thiscall SoundObj::ConvertTo8Bit(void) | ?ConvertTo8Bit@SoundObj@@QAEXXZ
    0x4F1750 | public: int __thiscall SoundObj::DSGetWaveFile(struct HINSTANCE__ *,char const *,struct tWAVEFORMATEX * *,unsigned char * *,unsigned long *,void * *) | ?DSGetWaveFile@SoundObj@@QAEHPAUHINSTANCE__@@PBDPAPAUtWAVEFORMATEX@@PAPAEPAKPAPAX@Z
    0x4F1A20 | public: int __thiscall SoundObj::InitDummy(void) | ?InitDummy@SoundObj@@QAEHXZ
    0x4F1BD0 | public: int __thiscall SoundObj::Init(char const *,unsigned long,short) | ?Init@SoundObj@@QAEHPBDKF@Z
    0x4F1C90 | public: int __thiscall SoundObj::Init(unsigned short,unsigned long,short) | ?Init@SoundObj@@QAEHGKF@Z
    0x4F1D40 | public: void __thiscall SoundObj::SetEffect(short,char *) | ?SetEffect@SoundObj@@QAEXFPAD@Z
    0x4F1EC0 | public: void __thiscall SoundObj::SetPlayPosition(unsigned long) | ?SetPlayPosition@SoundObj@@QAEXK@Z
    0x4F1EE0 | public: int __thiscall SoundObj::Play(unsigned long,char *) | ?Play@SoundObj@@QAEHKPAD@Z
    0x4F2120 | public: int __thiscall SoundObj::Stop(void) | ?Stop@SoundObj@@QAEHXZ
    0x4F21B0 | public: void __thiscall SoundObj::StopEchoBuffers(void) | ?StopEchoBuffers@SoundObj@@QAEXXZ
    0x4F21D0 | public: int __thiscall SoundObj::DSFillSoundBuffer(struct IDirectSoundBuffer *) | ?DSFillSoundBuffer@SoundObj@@QAEHPAUIDirectSoundBuffer@@@Z
    0x4F2290 | public: int __thiscall SoundObj::DSParseWaveResource(void *,struct tWAVEFORMATEX * *,unsigned char * *,unsigned long *) | ?DSParseWaveResource@SoundObj@@QAEHPAXPAPAUtWAVEFORMATEX@@PAPAEPAK@Z
    0x4F2390 | public: short __thiscall SoundObj::IsPlaying(short) | ?IsPlaying@SoundObj@@QAEFF@Z
    0x4F2470 | public: short __thiscall SoundObj::ReadyOneShotLayerBuf(void) | ?ReadyOneShotLayerBuf@SoundObj@@QAEFXZ
    0x4F2500 | public: short __thiscall SoundObj::AllOneShotLayersPlaying(void) | ?AllOneShotLayersPlaying@SoundObj@@QAEFXZ
    0x4F25A0 | public: void __thiscall SoundObj::SetPosition(float,float,float) | ?SetPosition@SoundObj@@QAEXMMM@Z
    0x4F25E0 | public: void __thiscall SoundObj::SetVelocity(float,float,float) | ?SetVelocity@SoundObj@@QAEXMMM@Z
    0x4F2620 | public: void __thiscall SoundObj::SetFrequency(float) | ?SetFrequency@SoundObj@@QAEXM@Z
    0x4F2860 | public: void __thiscall SoundObj::SetEchoFrequency(float) | ?SetEchoFrequency@SoundObj@@QAEXM@Z
    0x4F2920 | public: void __thiscall SoundObj::SetVolume(float) | ?SetVolume@SoundObj@@QAEXM@Z
    0x4F2A60 | public: void __thiscall SoundObj::SetPan(float) | ?SetPan@SoundObj@@QAEXM@Z
    0x4F2BA0 | public: void __thiscall SoundObj::SetEchoPan(float) | ?SetEchoPan@SoundObj@@QAEXM@Z
    0x4F2BD0 | public: void __thiscall SoundObj::SetRamp(float,float) | ?SetRamp@SoundObj@@QAEXMM@Z
    0x4F2C00 | public: void __thiscall SoundObj::Set3DMode(unsigned long) | ?Set3DMode@SoundObj@@QAEXK@Z
    0x4F2C20 | public: void __thiscall SoundObj::SetConeOutsideVolume(long) | ?SetConeOutsideVolume@SoundObj@@QAEXJ@Z
    0x4F2C50 | public: void __thiscall SoundObj::SetConeAngles(unsigned long,unsigned long) | ?SetConeAngles@SoundObj@@QAEXKK@Z
    0x4F2C90 | public: void __thiscall SoundObj::SetConeOrientation(class Vector3 *) | ?SetConeOrientation@SoundObj@@QAEXPAVVector3@@@Z
    0x4F2CC0 | public: struct IDirectSoundBuffer * __thiscall SoundObj::SetupDuplicateBuffer(char *) | ?SetupDuplicateBuffer@SoundObj@@QAEPAUIDirectSoundBuffer@@PAD@Z
    0x4F2D70 | public: void __thiscall SoundObj::SetupEchoBuffer(char *) | ?SetupEchoBuffer@SoundObj@@QAEXPAD@Z
    0x4F2E10 | private: struct IDirectSoundBuffer * __thiscall SoundObj::SetupChorusBuffer(char *) | ?SetupChorusBuffer@SoundObj@@AAEPAUIDirectSoundBuffer@@PAD@Z
    0x4F2E90 | public: void __thiscall SoundObj::UpdateSeconds(void) | ?UpdateSeconds@SoundObj@@QAEXXZ
    0x4F2EC0 | public: void __thiscall SoundObj::UpdateEcho(void) | ?UpdateEcho@SoundObj@@QAEXXZ
    0x4F2F30 | public: void __thiscall SoundObj::UpdatePlayEcho(void) | ?UpdatePlayEcho@SoundObj@@QAEXXZ
    0x4F3030 | public: void __thiscall SoundObj::UpdateStopEcho(void) | ?UpdateStopEcho@SoundObj@@QAEXXZ
    0x4F30F0 | public: void __thiscall SoundObj::UpdateVolumeEcho(void) | ?UpdateVolumeEcho@SoundObj@@QAEXXZ
    0x4F31B0 | public: void __thiscall SoundObj::UpdatePitchEcho(void) | ?UpdatePitchEcho@SoundObj@@QAEXXZ
    0x4F3270 | public: void __thiscall SoundObj::DisableEffect(short) | ?DisableEffect@SoundObj@@QAEXF@Z
    0x4F3370 | public: unsigned short __thiscall SoundObj::CreateListenerEAXObj(void) | ?CreateListenerEAXObj@SoundObj@@QAEGXZ
    0x4F3410 | public: unsigned short __thiscall SoundObj::CreateSecondaryEAXObj(void) | ?CreateSecondaryEAXObj@SoundObj@@QAEGXZ
    0x4F34D0 | public: struct tWAVEFORMATEX * __thiscall SoundObj::GetFormat(void) | ?GetFormat@SoundObj@@QAEPAUtWAVEFORMATEX@@XZ
    0x4F3550 | public: void __thiscall SoundObj::Enable3DMode(void) | ?Enable3DMode@SoundObj@@QAEXXZ
    0x4F3580 | public: void __thiscall SoundObj::Disable3DMode(void) | ?Disable3DMode@SoundObj@@QAEXXZ
*/

struct HINSTANCE__;
struct IDirectSoundBuffer;
struct tWAVEFORMATEX;

class SoundObj
{
public:
    // ??0SoundObj@@QAE@XZ
    ARTS_IMPORT SoundObj();

    // ??1SoundObj@@QAE@XZ
    ARTS_IMPORT ~SoundObj();

    // ?AllOneShotLayersPlaying@SoundObj@@QAEFXZ
    ARTS_IMPORT i16 AllOneShotLayersPlaying();

    // ?ConvertTo8Bit@SoundObj@@QAEXXZ
    ARTS_IMPORT void ConvertTo8Bit();

    // ?CreateListenerEAXObj@SoundObj@@QAEGXZ
    ARTS_IMPORT u16 CreateListenerEAXObj();

    // ?CreateSecondaryEAXObj@SoundObj@@QAEGXZ
    ARTS_IMPORT u16 CreateSecondaryEAXObj();

    // ?DSCreateSoundBuffer@SoundObj@@QAEHPAPAUIDirectSoundBuffer@@E@Z
    ARTS_IMPORT i32 DSCreateSoundBuffer(IDirectSoundBuffer** arg1, u8 arg2);

    // ?DSFillSoundBuffer@SoundObj@@QAEHPAUIDirectSoundBuffer@@@Z
    ARTS_IMPORT i32 DSFillSoundBuffer(IDirectSoundBuffer* arg1);

    // ?DSGetWaveFile@SoundObj@@QAEHPAUHINSTANCE__@@PBDPAPAUtWAVEFORMATEX@@PAPAEPAKPAPAX@Z
    ARTS_IMPORT i32 DSGetWaveFile(
        HINSTANCE__* arg1, const char* arg2, tWAVEFORMATEX** arg3, u8** arg4, ulong* arg5, void** arg6);

    // ?DSGetWaveResource@SoundObj@@QAEHPAUHINSTANCE__@@PBDPAPAUtWAVEFORMATEX@@PAPAEPAK@Z
    ARTS_IMPORT i32 DSGetWaveResource(
        HINSTANCE__* arg1, const char* arg2, tWAVEFORMATEX** arg3, u8** arg4, ulong* arg5);

    // ?DSLoadSoundBuffer@SoundObj@@QAEPAUIDirectSoundBuffer@@PBDK@Z
    ARTS_IMPORT IDirectSoundBuffer* DSLoadSoundBuffer(const char* arg1, ulong arg2);

    // ?DSLoadSoundBuffer@SoundObj@@QAEXGK@Z
    ARTS_IMPORT void DSLoadSoundBuffer(u16 arg1, ulong arg2);

    // ?DSParseWaveResource@SoundObj@@QAEHPAXPAPAUtWAVEFORMATEX@@PAPAEPAK@Z
    ARTS_IMPORT i32 DSParseWaveResource(void* arg1, tWAVEFORMATEX** arg2, u8** arg3, ulong* arg4);

    // ?DeallocateEffects@SoundObj@@QAEXXZ
    ARTS_IMPORT void DeallocateEffects();

    // ?Disable3DMode@SoundObj@@QAEXXZ
    ARTS_IMPORT void Disable3DMode();

    // ?DisableEffect@SoundObj@@QAEXF@Z
    ARTS_IMPORT void DisableEffect(i16 arg1);

    // ?Enable3DMode@SoundObj@@QAEXXZ
    ARTS_IMPORT void Enable3DMode();

    // ?FreeOneShotLayerBuffers@SoundObj@@QAEXXZ
    ARTS_IMPORT void FreeOneShotLayerBuffers();

    // ?Init@SoundObj@@QAEHPBDKF@Z
    ARTS_IMPORT i32 Init(const char* arg1, ulong arg2, i16 arg3);

    // ?Init@SoundObj@@QAEHGKF@Z
    ARTS_IMPORT i32 Init(u16 arg1, ulong arg2, i16 arg3);

    // ?InitDummy@SoundObj@@QAEHXZ
    ARTS_IMPORT i32 InitDummy();

    // ?IsPlaying@SoundObj@@QAEFF@Z
    ARTS_IMPORT i16 IsPlaying(i16 arg1);

    // ?Play@SoundObj@@QAEHKPAD@Z
    ARTS_IMPORT i32 Play(ulong arg1, char* arg2);

    // ?ReadADFRecord@SoundObj@@QAEXG@Z
    ARTS_IMPORT void ReadADFRecord(u16 arg1);

    // ?ReadyOneShotLayerBuf@SoundObj@@QAEFXZ
    ARTS_IMPORT i16 ReadyOneShotLayerBuf();

    // ?Set3DMode@SoundObj@@QAEXK@Z
    ARTS_IMPORT void Set3DMode(ulong arg1);

    // ?SetConeAngles@SoundObj@@QAEXKK@Z
    ARTS_IMPORT void SetConeAngles(ulong arg1, ulong arg2);

    // ?SetConeOrientation@SoundObj@@QAEXPAVVector3@@@Z
    ARTS_IMPORT void SetConeOrientation(Vector3* arg1);

    // ?SetConeOutsideVolume@SoundObj@@QAEXJ@Z
    ARTS_IMPORT void SetConeOutsideVolume(ilong arg1);

    // ?SetDelayTime@SoundObj@@QAEXM@Z
    ARTS_IMPORT void SetDelayTime(f32 arg1);

    // ?SetEchoFrequency@SoundObj@@QAEXM@Z
    ARTS_IMPORT void SetEchoFrequency(f32 arg1);

    // ?SetEchoPan@SoundObj@@QAEXM@Z
    ARTS_IMPORT void SetEchoPan(f32 arg1);

    // ?SetEffect@SoundObj@@QAEXFPAD@Z
    ARTS_IMPORT void SetEffect(i16 arg1, char* arg2);

    // ?SetFrequency@SoundObj@@QAEXM@Z
    ARTS_IMPORT void SetFrequency(f32 arg1);

    // ?SetPan@SoundObj@@QAEXM@Z
    ARTS_IMPORT void SetPan(f32 arg1);

    // ?SetPlayPosition@SoundObj@@QAEXK@Z
    ARTS_IMPORT void SetPlayPosition(ulong arg1);

    // ?SetPosition@SoundObj@@QAEXMMM@Z
    ARTS_IMPORT void SetPosition(f32 arg1, f32 arg2, f32 arg3);

    // ?SetRamp@SoundObj@@QAEXMM@Z
    ARTS_IMPORT void SetRamp(f32 arg1, f32 arg2);

    // ?SetVelocity@SoundObj@@QAEXMMM@Z
    ARTS_IMPORT void SetVelocity(f32 arg1, f32 arg2, f32 arg3);

    // ?SetVolume@SoundObj@@QAEXM@Z
    ARTS_IMPORT void SetVolume(f32 arg1);

    // ?SetupEchoBuffer@SoundObj@@QAEXPAD@Z
    ARTS_IMPORT void SetupEchoBuffer(char* arg1);

    // ?SetupOneShotLayerBuffers@SoundObj@@QAEFFMPAD@Z
    ARTS_IMPORT i16 SetupOneShotLayerBuffers(i16 arg1, f32 arg2, char* arg3);

    // ?Stop@SoundObj@@QAEHXZ
    ARTS_IMPORT i32 Stop();

    // ?StopEchoBuffers@SoundObj@@QAEXXZ
    ARTS_IMPORT void StopEchoBuffers();

    // ?UpdateEcho@SoundObj@@QAEXXZ
    ARTS_IMPORT void UpdateEcho();

    // ?UpdatePitchEcho@SoundObj@@QAEXXZ
    ARTS_IMPORT void UpdatePitchEcho();

    // ?UpdatePlayEcho@SoundObj@@QAEXXZ
    ARTS_IMPORT void UpdatePlayEcho();

    // ?UpdateSeconds@SoundObj@@QAEXXZ
    ARTS_IMPORT void UpdateSeconds();

    // ?UpdateStopEcho@SoundObj@@QAEXXZ
    ARTS_IMPORT void UpdateStopEcho();

    // ?UpdateVolumeEcho@SoundObj@@QAEXXZ
    ARTS_IMPORT void UpdateVolumeEcho();

private:
    // ?SetupChorusBuffer@SoundObj@@AAEPAUIDirectSoundBuffer@@PAD@Z
    ARTS_IMPORT IDirectSoundBuffer* SetupChorusBuffer(char* arg1);

    u8 gap0[0x88];
};

check_size(SoundObj, 0x88);
