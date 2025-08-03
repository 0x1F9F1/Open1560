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

#include <guiddef.h>

#include <eax.h>

class AudHead;
class AudSound;
class AudStream;
class Bank;
class CReverb;
class MixerCTL;
class mmVoiceCommentary;
class SoundObj;

class AudManager final : public asNode
{
public:
    // ??0AudManager@@QAE@XZ
    ARTS_IMPORT AudManager();

    // ??1AudManager@@UAE@XZ
    ARTS_IMPORT ~AudManager() override;

    ARTS_ZEROED;

    // ?AddSound@AudManager@@QAEHPAVAudSound@@@Z
    ARTS_IMPORT i32 AddSound(AudSound* arg1);

    // ?AddStream@AudManager@@QAEHPAVAudStream@@@Z
    ARTS_IMPORT i32 AddStream(AudStream* arg1);

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@AudManager@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AlwaysEAX@AudManager@@QAEXI@Z
    ARTS_IMPORT void AlwaysEAX(u32 arg1);

    // ?AssignCDBalance@AudManager@@QAEXM@Z
    ARTS_IMPORT void AssignCDBalance(f32 arg1);

    // ?AssignCDVolume@AudManager@@QAEXM@Z
    ARTS_IMPORT void AssignCDVolume(f32 arg1);

    // ?AssignWaveBalance@AudManager@@QAEXM@Z
    ARTS_IMPORT void AssignWaveBalance(f32 arg1);

    // ?AssignWaveVolume@AudManager@@QAEXM@Z
    ARTS_IMPORT void AssignWaveVolume(f32 arg1);

    // ?AttenuateCDVolume@AudManager@@QAEXM@Z
    ARTS_IMPORT void AttenuateCDVolume(f32 arg1);

    // ?CDIsEnabled@AudManager@@QAEHXZ
    ARTS_IMPORT i32 CDIsEnabled();

    // ?CDIsPlaying@AudManager@@QAEFXZ
    ARTS_IMPORT i16 CDIsPlaying();

    // ?CheckCDFile@AudManager@@QAEEPAD@Z
    ARTS_IMPORT u8 CheckCDFile(aconst char* arg1);

    // ?CheckPriority@AudManager@@QAEHHHH@Z
    ARTS_IMPORT i32 CheckPriority(i32 arg1, i32 arg2, i32 arg3);

    // ?DSound3DEnabled@AudManager@@QAEIXZ
    ARTS_IMPORT u32 DSound3DEnabled();

    // ?DeallocateDSound@AudManager@@QAEXFF@Z
    ARTS_IMPORT void DeallocateDSound(i16 arg1, i16 arg2);

    // ?DeallocateUIADF@AudManager@@QAEXXZ
    ARTS_IMPORT void DeallocateUIADF();

    // ?Disable@AudManager@@QAEXFF@Z
    ARTS_IMPORT void Disable(i16 sfx_mode, i16 cd_mode);

    // ?EAXEnabled@AudManager@@QAEIXZ
    ARTS_IMPORT u32 EAXEnabled();

    // ?Enable@AudManager@@QAEXPADFF@Z
    ARTS_IMPORT void Enable(char* arg1, i16 arg2, i16 arg3);

    // ?EnableCD@AudManager@@QAEHXZ
    ARTS_IMPORT i32 EnableCD();

    // ?GetActiveDeviceName@AudManager@@QAEPADXZ
    ARTS_IMPORT char* GetActiveDeviceName();

    // ?GetCDPosition@AudManager@@QAEKPAE000@Z
    ARTS_IMPORT u32 GetCDPosition(u8* arg1, u8* arg2, u8* arg3, u8* arg4);

    // ?GetCDTrackNum@AudManager@@QAEEXZ
    ARTS_IMPORT u8 GetCDTrackNum();

    // ?GetClass@AudManager@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetDeviceNames@AudManager@@QAEPAPADXZ
    ARTS_IMPORT char** GetDeviceNames();

    // ?GetMixerPtr@AudManager@@QAEPAVMixerCTL@@XZ
    ARTS_IMPORT MixerCTL* GetMixerPtr();

    // ?GetNum3DHalBufs@AudManager@@QAEKXZ
    ARTS_EXPORT ulong GetNum3DHalBufs();

    // ?GetNumCDTracks@AudManager@@QAEFXZ
    ARTS_IMPORT i16 GetNumCDTracks();

    // ?GetNumDevices@AudManager@@QAEHXZ
    ARTS_IMPORT i32 GetNumDevices();

    // ?GetVoiceCommentaryPtr@AudManager@@QAEPAVmmVoiceCommentary@@XZ
    ARTS_IMPORT mmVoiceCommentary* GetVoiceCommentaryPtr();

    // ?Init@AudManager@@QAEXHIPADFF@Z
    ARTS_IMPORT void Init(i32 arg1, u32 arg2, char* arg3, i16 arg4, i16 arg5);

    // ?IsAlwaysEAX@AudManager@@QAEIXZ
    ARTS_IMPORT u32 IsAlwaysEAX();

    // ?IsStereo@AudManager@@QAEHXZ
    ARTS_IMPORT i32 IsStereo();

    // ?PlayCDTrack@AudManager@@QAEHHH@Z
    ARTS_IMPORT i32 PlayCDTrack(i32 track, b32 restart);

    // ?PlayCDTrack@AudManager@@QAEHHEEEH@Z
    ARTS_IMPORT i32 PlayCDTrack(i32 track, u8 minute, u8 second, u8 frame, b32 restart);

    // ?ReallocateDSound@AudManager@@QAEXPADFF@Z
    ARTS_IMPORT void ReallocateDSound(char* arg1, i16 arg2, i16 arg3);

    // ?RemoveSound@AudManager@@QAEXPAVAudSound@@H@Z
    ARTS_IMPORT void RemoveSound(AudSound* arg1, i32 arg2);

    // ?RemoveSoundFromPlayList@AudManager@@QAEXPAVAudSound@@@Z
    ARTS_IMPORT void RemoveSoundFromPlayList(AudSound* arg1);

    // ?RemoveSoundFromPlayList@AudManager@@QAEXH@Z
    ARTS_IMPORT void RemoveSoundFromPlayList(i32 arg1);

    // ?RemoveStream@AudManager@@QAEXPAVAudStream@@H@Z
    ARTS_IMPORT void RemoveStream(AudStream* arg1, i32 arg2);

    // ?Reset@AudManager@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?SetBitDepthAndSampleRate@AudManager@@QAEXHK@Z
    ARTS_IMPORT void SetBitDepthAndSampleRate(i32 arg1, ulong arg2);

    // ?SetCDPlayMode@AudManager@@QAEXE@Z
    ARTS_IMPORT void SetCDPlayMode(u8 arg1);

    // ?SetDeviceName@AudManager@@QAEXPAD@Z
    ARTS_IMPORT void SetDeviceName(char* arg1);

    // ?SetEAXPreset@AudManager@@QAEHPAUEAX_REVERBPROPERTIES@@@Z
    ARTS_IMPORT i32 SetEAXPreset(EAX_REVERBPROPERTIES* arg1);

    // ?SetEAXPreset@AudManager@@QAEHKMMM@Z
    ARTS_IMPORT i32 SetEAXPreset(ulong environment, f32 volume, f32 decay_time, f32 damping);

    // ?SetNumChannels@AudManager@@QAEXH@Z
    ARTS_IMPORT void SetNumChannels(i32 arg1);

    // ?SetVoiceCommentaryPtr@AudManager@@QAEXPAVmmVoiceCommentary@@@Z
    ARTS_IMPORT void SetVoiceCommentaryPtr(mmVoiceCommentary* arg1);

    // ?StopAllSounds@AudManager@@QAEXXZ
    ARTS_IMPORT void StopAllSounds();

    // ?StopCD@AudManager@@QAEXXZ
    ARTS_IMPORT void StopCD();

    // ?Supports16Bit@AudManager@@QAEFXZ
    ARTS_IMPORT i16 Supports16Bit();

    // ?Update@AudManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdatePaused@AudManager@@UAEXXZ
    ARTS_IMPORT void UpdatePaused() override;

    // ?ZeroVolAllSounds@AudManager@@QAEXXZ | unused
    void ZeroVolAllSounds();

    // ?DeclareFields@AudManager@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // TODO: Remove const from return type

    ARTS_DIAGNOSTIC_PUSH;
    ARTS_CLANG_DIAGNOSTIC_IGNORED("-Wignored-qualifiers");

    // ?GetCDMusicOnMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static const u32 GetCDMusicOnMask();

    // ?GetCommentaryOnMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static const u32 GetCommentaryOnMask();

    // ?GetDSound3DMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static const u32 GetDSound3DMask();

    // ?GetEchoOnMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static const u32 GetEchoOnMask();

    // ?GetHiResMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static const u32 GetHiResMask();

    // ?GetHiSampleSizeMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static const u32 GetHiSampleSizeMask();

    // ?GetSoundFXOnMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static const u32 GetSoundFXOnMask();

    // ?GetStereoOnMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static const u32 GetStereoOnMask();

    // ?GetUsingEAXMask@AudManager@@SA?BIXZ
    ARTS_IMPORT static const u32 GetUsingEAXMask();

    ARTS_DIAGNOSTIC_POP;

    i32 dword20;
    i32 NumChannels;
    i32 field_28;
    i32 field_2C;
    i32 field_30;
    i32 MaxSounds;
    i32 MaxStreams;
    i32 NumSounds;
    i32 NumStreams;
    i32 dword44;
    i32 HasDSound;
    i32 SteroOn;
    i32 AudFlags;
    i16 word54;
    i16 CDIsPlayer;
    i16 NotDsound3D;
    i16 SfxOn;
    i16 CdMusicOn;
    u8 CDTrack;
    u8 CDMinute;
    u8 CDSecond;
    u8 CDFrame;
    i8 CDPlayMode;
    i32 SampleRate;
    i16 word68;
    Bank* Widgets;
    f32 dword70;
    f32 dword74;
    f32 dword78;
    AudSound** Channels;
    AudSound** Sounds;
    AudSound** Streams;
    SoundObj* Listener;
    AudHead* Head;
    Vector3* dword90;
    mmVoiceCommentary* VoiceCommentary;
    char* DefaultDeviceName;
    EAX_REVERBPROPERTIES* Reverb;

private:
    // ?CreateListenerSoundObj@AudManager@@AAEIXZ
    ARTS_IMPORT u32 CreateListenerSoundObj();

    // ?GetListenerEAXObj@AudManager@@AAEPAVCReverb@@XZ
    ARTS_IMPORT CReverb* GetListenerEAXObj();

    // ?Update3DCDMusic@AudManager@@AAEXXZ
    ARTS_IMPORT void Update3DCDMusic();
};

check_size(AudManager, 0xA0);

// ?DeactivateApplication@@YAXXZ
ARTS_IMPORT void DeactivateApplication();

// ?RestoreApplication@@YAXXZ
ARTS_IMPORT void RestoreApplication();

// ?AUDMGRPTR@@3PAVAudManager@@A
ARTS_IMPORT extern AudManager* AUDMGRPTR;

inline AudManager* AudMgr()
{
    return AUDMGRPTR;
}
