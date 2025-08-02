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
