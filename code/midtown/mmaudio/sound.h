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

#include "arts7/node.h"
#include "vector7/vector3.h"

class CReverbBuffer;
class SoundObj;

class AudSound final : public asNode
{
public:
    // ??0AudSound@@QAE@KHF@Z
    ARTS_IMPORT AudSound(ulong arg1, i32 arg2, i16 arg3);

    // ??1AudSound@@UAE@XZ
    ARTS_IMPORT ~AudSound() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@AudSound@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AllOneShotLayersPlaying@AudSound@@QAEHXZ
    ARTS_IMPORT i32 AllOneShotLayersPlaying();

    // ?DeallocateSoundObjs@AudSound@@QAEXXZ
    ARTS_IMPORT void DeallocateSoundObjs();

    // ?Disable@AudSound@@QAEXXZ
    ARTS_IMPORT void Disable();

    // ?Disable3DMode@AudSound@@QAEXXZ
    ARTS_IMPORT void Disable3DMode();

    // ?DisableEffect@AudSound@@QAEXH@Z
    ARTS_IMPORT void DisableEffect(i32 arg1);

    // ?Enable@AudSound@@QAEXXZ
    ARTS_IMPORT void Enable();

    // ?Enable3DMode@AudSound@@QAEXXZ
    ARTS_IMPORT void Enable3DMode();

    // ?EnabledAction@AudSound@@QAEXXZ
    ARTS_IMPORT void EnabledAction();

    // ?GetEffect@AudSound@@QAEHXZ
    ARTS_IMPORT i32 GetEffect();

    // ?GetSecondaryEAXObj@AudSound@@QAEPAVCReverbBuffer@@H@Z
    ARTS_IMPORT CReverbBuffer* GetSecondaryEAXObj(i32 arg1);

    // ?GetVolume@AudSound@@QAEMH@Z
    ARTS_IMPORT f32 GetVolume(i32 arg1);

    // ?IsPlaying@AudSound@@QAEHH@Z
    ARTS_IMPORT i32 IsPlaying(i32 arg1);

    // ?Load@AudSound@@QAEHPADH@Z
    ARTS_IMPORT i32 Load(char* arg1, i32 arg2);

    // ?Load@AudSound@@QAEHHH@Z
    ARTS_IMPORT i32 Load(i32 arg1, i32 arg2);

    // ?PlayLoop@AudSound@@QAEXMM@Z
    ARTS_IMPORT void PlayLoop(f32 arg1, f32 arg2);

    // ?PlayOnce@AudSound@@QAEXMM@Z
    ARTS_IMPORT void PlayOnce(f32 arg1, f32 arg2);

    // ?ReadyOneShotLayerBuf@AudSound@@QAEHXZ
    ARTS_IMPORT i32 ReadyOneShotLayerBuf();

    // ?ReallocateSoundObjs@AudSound@@QAEXXZ
    ARTS_IMPORT void ReallocateSoundObjs();

    // ?Reset@AudSound@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetDelayTime@AudSound@@QAEXM@Z
    ARTS_IMPORT void SetDelayTime(f32 arg1);

    // ?SetEAXReverbMix@AudSound@@QAEXMH@Z
    ARTS_IMPORT void SetEAXReverbMix(f32 arg1, i32 arg2);

    // ?SetEchoAttenuation@AudSound@@QAEXM@Z
    ARTS_IMPORT void SetEchoAttenuation(f32 arg1);

    // ?SetEchoFrequency@AudSound@@QAEXMH@Z
    ARTS_IMPORT void SetEchoFrequency(f32 arg1, i32 arg2);

    // ?SetEffect@AudSound@@QAEXH@Z
    ARTS_IMPORT void SetEffect(i32 arg1);

    // ?SetFrequency@AudSound@@QAEXMH@Z
    ARTS_IMPORT void SetFrequency(f32 arg1, i32 arg2);

    // ?SetPan@AudSound@@QAEXMH@Z
    ARTS_IMPORT void SetPan(f32 arg1, i32 arg2);

    // ?SetPlayPosition@AudSound@@QAEXK@Z
    ARTS_IMPORT void SetPlayPosition(ulong arg1);

    // ?SetPriority@AudSound@@QAEXH@Z
    ARTS_IMPORT void SetPriority(i32 arg1);

    // ?SetRamp@AudSound@@QAEXMM@Z
    ARTS_IMPORT void SetRamp(f32 arg1, f32 arg2);

    // ?SetVolume@AudSound@@QAEXMH@Z
    ARTS_IMPORT void SetVolume(f32 arg1, i32 arg2);

    // ?SetupOneShotLayerBuffers@AudSound@@QAEXHMH@Z
    ARTS_IMPORT void SetupOneShotLayerBuffers(i32 arg1, f32 arg2, i32 arg3);

    // ?Stop@AudSound@@QAEXXZ
    ARTS_IMPORT void Stop();

    // ?StopEchoBuffers@AudSound@@QAEXXZ
    ARTS_IMPORT void StopEchoBuffers();

    // ?Update@AudSound@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?Update3DSettings@AudSound@@QAEXXZ
    ARTS_IMPORT void Update3DSettings();

    ARTS_DIAGNOSTIC_PUSH;
    ARTS_CLANG_DIAGNOSTIC_IGNORED("-Wignored-qualifiers");

    // ?Get2DFlags@AudSound@@SA?BKXZ
    ARTS_IMPORT static const ulong Get2DFlags();

    // ?Get3DFlags@AudSound@@SA?BKXZ
    ARTS_IMPORT static const ulong Get3DFlags();

    // ?GetFreqChange2DFlags@AudSound@@SA?BKXZ
    ARTS_IMPORT static const ulong GetFreqChange2DFlags();

    // ?GetFreqChange3DFlags@AudSound@@SA?BKXZ
    ARTS_IMPORT static const ulong GetFreqChange3DFlags();

    // ?GetSoft2DFlags@AudSound@@SA?BKXZ
    ARTS_IMPORT static const ulong GetSoft2DFlags();

private:
    // ?s_DWDefault2DCtrlFlags@AudSound@@0KB
    ARTS_IMPORT static const ulong s_DWDefault2DCtrlFlags;

    // ?s_DWDefault3DCtrlFlags@AudSound@@0KB
    ARTS_IMPORT static const ulong s_DWDefault3DCtrlFlags;

    // ?s_DWFreqChange2DCtrlFlags@AudSound@@0KB
    ARTS_IMPORT static const ulong s_DWFreqChange2DCtrlFlags;

    // ?s_DWFreqChange3DCtrlFlags@AudSound@@0KB
    ARTS_IMPORT static const ulong s_DWFreqChange3DCtrlFlags;

    // ?s_DWSoft2DCtrlFlags@AudSound@@0KB
    ARTS_IMPORT static const ulong s_DWSoft2DCtrlFlags;

    // ?s_DWSoftFreqChange2DCtrlFlags@AudSound@@0KB
    ARTS_IMPORT static const ulong s_DWSoftFreqChange2DCtrlFlags;

    ARTS_DIAGNOSTIC_POP;

public:
    i32 field_20;
    i32 Priority;
    i32 field_28;
    i32 SoundIndex;
    i32 Enabled;
    i32 field_34;
    i32 AudMask;
    i32 UpdateFlags;
    i32 field_40;
    i32 field_44;
    i32 ActiveSound;
    i32 NumSoundObjs;
    i32 field_50;
    i32 Position;
    Vector3 LastPosition;
    Vector3 Velocity;
    i32 field_70;
    i32 field_74;
    i32* Volumes;
    i32* Frequencies;
    i32* Pans;
    i32* ReverbMixes;
    i32 field_88;
    i32 field_8C;
    i32 field_90;
    i32 field_94;
    i32 field_98;
    i32 field_9C;
    i32 field_A0;
    i32 field_A4;
    i32 field_A8;
    i32 field_AC;
    i32* SoundNames;
    i32* SoundObjs;
};

check_size(AudSound, 0xB8);
