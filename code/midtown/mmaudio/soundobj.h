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

class SoundObj
{
public:
    // 0x4F0B20 | ??0SoundObj@@QAE@XZ
    ARTS_IMPORT SoundObj();

    // 0x4F0BE0 | ??1SoundObj@@QAE@XZ
    ARTS_IMPORT ~SoundObj();

    // 0x4F2500 | ?AllOneShotLayersPlaying@SoundObj@@QAEFXZ
    ARTS_IMPORT i16 AllOneShotLayersPlaying();

    // 0x4F15F0 | ?ConvertTo8Bit@SoundObj@@QAEXXZ
    ARTS_IMPORT void ConvertTo8Bit();

    // 0x4F3370 | ?CreateListenerEAXObj@SoundObj@@QAEGXZ
    ARTS_IMPORT u16 CreateListenerEAXObj();

    // 0x4F3410 | ?CreateSecondaryEAXObj@SoundObj@@QAEGXZ
    ARTS_IMPORT u16 CreateSecondaryEAXObj();

    // 0x4F0FA0 | ?DSCreateSoundBuffer@SoundObj@@QAEHPAPAUIDirectSoundBuffer@@E@Z
    ARTS_IMPORT i32 DSCreateSoundBuffer(struct IDirectSoundBuffer** arg1, u8 arg2);

    // 0x4F21D0 | ?DSFillSoundBuffer@SoundObj@@QAEHPAUIDirectSoundBuffer@@@Z
    ARTS_IMPORT i32 DSFillSoundBuffer(struct IDirectSoundBuffer* arg1);

    // 0x4F1750 | ?DSGetWaveFile@SoundObj@@QAEHPAUHINSTANCE__@@PBDPAPAUtWAVEFORMATEX@@PAPAEPAKPAPAX@Z
    ARTS_IMPORT i32 DSGetWaveFile(
        struct HINSTANCE__* arg1, char const* arg2, struct tWAVEFORMATEX** arg3, u8** arg4, u32* arg5, void** arg6);

    // 0x4F1510 | ?DSGetWaveResource@SoundObj@@QAEHPAUHINSTANCE__@@PBDPAPAUtWAVEFORMATEX@@PAPAEPAK@Z
    ARTS_IMPORT i32 DSGetWaveResource(
        struct HINSTANCE__* arg1, char const* arg2, struct tWAVEFORMATEX** arg3, u8** arg4, u32* arg5);

    // 0x4F1030 | ?DSLoadSoundBuffer@SoundObj@@QAEPAUIDirectSoundBuffer@@PBDK@Z
    ARTS_IMPORT struct IDirectSoundBuffer* DSLoadSoundBuffer(char const* arg1, u32 arg2);

    // 0x4F1210 | ?DSLoadSoundBuffer@SoundObj@@QAEXGK@Z
    ARTS_IMPORT void DSLoadSoundBuffer(u16 arg1, u32 arg2);

    // 0x4F2290 | ?DSParseWaveResource@SoundObj@@QAEHPAXPAPAUtWAVEFORMATEX@@PAPAEPAK@Z
    ARTS_IMPORT i32 DSParseWaveResource(void* arg1, struct tWAVEFORMATEX** arg2, u8** arg3, u32* arg4);

    // 0x4F0CA0 | ?DeallocateEffects@SoundObj@@QAEXXZ
    ARTS_IMPORT void DeallocateEffects();

    // 0x4F3580 | ?Disable3DMode@SoundObj@@QAEXXZ
    ARTS_IMPORT void Disable3DMode();

    // 0x4F3270 | ?DisableEffect@SoundObj@@QAEXF@Z
    ARTS_IMPORT void DisableEffect(i16 arg1);

    // 0x4F3550 | ?Enable3DMode@SoundObj@@QAEXXZ
    ARTS_IMPORT void Enable3DMode();

    // 0x4F0F20 | ?FreeOneShotLayerBuffers@SoundObj@@QAEXXZ
    ARTS_IMPORT void FreeOneShotLayerBuffers();

    // 0x4F34D0 | ?GetFormat@SoundObj@@QAEPAUtWAVEFORMATEX@@XZ | unused
    ARTS_IMPORT struct tWAVEFORMATEX* GetFormat();

    // 0x4F1BD0 | ?Init@SoundObj@@QAEHPBDKF@Z
    ARTS_IMPORT i32 Init(char const* arg1, u32 arg2, i16 arg3);

    // 0x4F1C90 | ?Init@SoundObj@@QAEHGKF@Z
    ARTS_IMPORT i32 Init(u16 arg1, u32 arg2, i16 arg3);

    // 0x4F1A20 | ?InitDummy@SoundObj@@QAEHXZ
    ARTS_IMPORT i32 InitDummy();

    // 0x4F2390 | ?IsPlaying@SoundObj@@QAEFF@Z
    ARTS_IMPORT i16 IsPlaying(i16 arg1);

    // 0x4F1EE0 | ?Play@SoundObj@@QAEHKPAD@Z
    ARTS_IMPORT i32 Play(u32 arg1, char* arg2);

    // 0x4F1350 | ?ReadADFRecord@SoundObj@@QAEXG@Z
    ARTS_IMPORT void ReadADFRecord(u16 arg1);

    // 0x4F2470 | ?ReadyOneShotLayerBuf@SoundObj@@QAEFXZ
    ARTS_IMPORT i16 ReadyOneShotLayerBuf();

    // 0x4F2C00 | ?Set3DMode@SoundObj@@QAEXK@Z
    ARTS_IMPORT void Set3DMode(u32 arg1);

    // 0x4F2C50 | ?SetConeAngles@SoundObj@@QAEXKK@Z
    ARTS_IMPORT void SetConeAngles(u32 arg1, u32 arg2);

    // 0x4F2C90 | ?SetConeOrientation@SoundObj@@QAEXPAVVector3@@@Z
    ARTS_IMPORT void SetConeOrientation(class Vector3* arg1);

    // 0x4F2C20 | ?SetConeOutsideVolume@SoundObj@@QAEXJ@Z
    ARTS_IMPORT void SetConeOutsideVolume(i32 arg1);

    // 0x4F0D70 | ?SetDelayTime@SoundObj@@QAEXM@Z
    ARTS_IMPORT void SetDelayTime(f32 arg1);

    // 0x4F2860 | ?SetEchoFrequency@SoundObj@@QAEXM@Z
    ARTS_IMPORT void SetEchoFrequency(f32 arg1);

    // 0x4F2BA0 | ?SetEchoPan@SoundObj@@QAEXM@Z
    ARTS_IMPORT void SetEchoPan(f32 arg1);

    // 0x4F1D40 | ?SetEffect@SoundObj@@QAEXFPAD@Z
    ARTS_IMPORT void SetEffect(i16 arg1, char* arg2);

    // 0x4F2620 | ?SetFrequency@SoundObj@@QAEXM@Z
    ARTS_IMPORT void SetFrequency(f32 arg1);

    // 0x4F2A60 | ?SetPan@SoundObj@@QAEXM@Z
    ARTS_IMPORT void SetPan(f32 arg1);

    // 0x4F1EC0 | ?SetPlayPosition@SoundObj@@QAEXK@Z
    ARTS_IMPORT void SetPlayPosition(u32 arg1);

    // 0x4F25A0 | ?SetPosition@SoundObj@@QAEXMMM@Z
    ARTS_IMPORT void SetPosition(f32 arg1, f32 arg2, f32 arg3);

    // 0x4F2BD0 | ?SetRamp@SoundObj@@QAEXMM@Z
    ARTS_IMPORT void SetRamp(f32 arg1, f32 arg2);

    // 0x4F25E0 | ?SetVelocity@SoundObj@@QAEXMMM@Z
    ARTS_IMPORT void SetVelocity(f32 arg1, f32 arg2, f32 arg3);

    // 0x4F2920 | ?SetVolume@SoundObj@@QAEXM@Z
    ARTS_IMPORT void SetVolume(f32 arg1);

    // 0x4F2CC0 | ?SetupDuplicateBuffer@SoundObj@@QAEPAUIDirectSoundBuffer@@PAD@Z | unused
    ARTS_IMPORT struct IDirectSoundBuffer* SetupDuplicateBuffer(char* arg1);

    // 0x4F2D70 | ?SetupEchoBuffer@SoundObj@@QAEXPAD@Z
    ARTS_IMPORT void SetupEchoBuffer(char* arg1);

    // 0x4F0E90 | ?SetupOneShotLayerBuffers@SoundObj@@QAEFFMPAD@Z
    ARTS_IMPORT i16 SetupOneShotLayerBuffers(i16 arg1, f32 arg2, char* arg3);

    // 0x4F2120 | ?Stop@SoundObj@@QAEHXZ
    ARTS_IMPORT i32 Stop();

    // 0x4F21B0 | ?StopEchoBuffers@SoundObj@@QAEXXZ
    ARTS_IMPORT void StopEchoBuffers();

    // 0x4F2EC0 | ?UpdateEcho@SoundObj@@QAEXXZ
    ARTS_IMPORT void UpdateEcho();

    // 0x4F31B0 | ?UpdatePitchEcho@SoundObj@@QAEXXZ
    ARTS_IMPORT void UpdatePitchEcho();

    // 0x4F2F30 | ?UpdatePlayEcho@SoundObj@@QAEXXZ
    ARTS_IMPORT void UpdatePlayEcho();

    // 0x4F2E90 | ?UpdateSeconds@SoundObj@@QAEXXZ
    ARTS_IMPORT void UpdateSeconds();

    // 0x4F3030 | ?UpdateStopEcho@SoundObj@@QAEXXZ
    ARTS_IMPORT void UpdateStopEcho();

    // 0x4F30F0 | ?UpdateVolumeEcho@SoundObj@@QAEXXZ
    ARTS_IMPORT void UpdateVolumeEcho();

private:
    // 0x4F2E10 | ?SetupChorusBuffer@SoundObj@@AAEPAUIDirectSoundBuffer@@PAD@Z
    ARTS_IMPORT struct IDirectSoundBuffer* SetupChorusBuffer(char* arg1);

    u8 gap0[0x88];
};

check_size(SoundObj, 0x88);
