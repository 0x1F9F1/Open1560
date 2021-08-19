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
    mmui:audio

    0x49C5A0 | public: __thiscall AudioOptions::AudioOptions(int) | ??0AudioOptions@@QAE@H@Z
    0x49CE60 | public: virtual __thiscall AudioOptions::~AudioOptions(void) | ??1AudioOptions@@UAE@XZ
    0x49CEF0 | public: virtual void __thiscall AudioOptions::PreSetup(void) | ?PreSetup@AudioOptions@@UAEXXZ
    0x49CF00 | public: void __thiscall AudioOptions::SetWaveVolume(void) | ?SetWaveVolume@AudioOptions@@QAEXXZ
    0x49CF20 | public: void __thiscall AudioOptions::SetCDVolume(void) | ?SetCDVolume@AudioOptions@@QAEXXZ
    0x49CF40 | public: void __thiscall AudioOptions::SetBalance(void) | ?SetBalance@AudioOptions@@QAEXXZ
    0x49CF70 | public: void __thiscall AudioOptions::SetQuality(void) | ?SetQuality@AudioOptions@@QAEXXZ
    0x49D040 | public: void __thiscall AudioOptions::SetStereoFX(void) | ?SetStereoFX@AudioOptions@@QAEXXZ
    0x49D0C0 | public: virtual void __thiscall AudioOptions::StoreCurrentSetup(void) | ?StoreCurrentSetup@AudioOptions@@UAEXXZ
    0x49D0D0 | public: virtual void __thiscall AudioOptions::ResetDefaultAction(void) | ?ResetDefaultAction@AudioOptions@@UAEXXZ
    0x49D150 | public: virtual void __thiscall AudioOptions::CancelAction(void) | ?CancelAction@AudioOptions@@UAEXXZ
    0x49D1D0 | public: virtual void __thiscall AudioOptions::DoneAction(void) | ?DoneAction@AudioOptions@@UAEXXZ
    0x49D1E0 | public: void __thiscall AudioOptions::SetAudioState(void) | ?SetAudioState@AudioOptions@@QAEXXZ
    0x49D3F0 | public: void __thiscall AudioOptions::SetCDMusic(void) | ?SetCDMusic@AudioOptions@@QAEXXZ
    0x49D420 | public: void __thiscall AudioOptions::SetSoundFX(void) | ?SetSoundFX@AudioOptions@@QAEXXZ
    0x49D450 | public: void __thiscall AudioOptions::SetCommentary(void) | ?SetCommentary@AudioOptions@@QAEXXZ
    0x49D480 | public: int __thiscall AudioOptions::FindDevice(char *) | ?FindDevice@AudioOptions@@QAEHPAD@Z
    0x49D510 | public: char * __thiscall AudioOptions::GetCurrentDeviceName(void) | ?GetCurrentDeviceName@AudioOptions@@QAEPADXZ
    0x49D530 | public: void __thiscall AudioOptions::ResetStereo(void) | ?ResetStereo@AudioOptions@@QAEXXZ
    0x49D560 | public: void __thiscall AudioOptions::ResetSoundFX(void) | ?ResetSoundFX@AudioOptions@@QAEXXZ
    0x49D590 | public: void __thiscall AudioOptions::ResetCDMusic(void) | ?ResetCDMusic@AudioOptions@@QAEXXZ
    0x49D5C0 | public: void __thiscall AudioOptions::ResetSoundQuality(void) | ?ResetSoundQuality@AudioOptions@@QAEXXZ
    0x49D620 | public: void __thiscall AudioOptions::ResetCommentary(void) | ?ResetCommentary@AudioOptions@@QAEXXZ
    0x49D650 | public: void __thiscall AudioOptions::SetDevice(int) | ?SetDevice@AudioOptions@@QAEXH@Z
    0x49D700 | public: virtual void * __thiscall AudioOptions::`vector deleting destructor'(unsigned int) | ??_EAudioOptions@@UAEPAXI@Z
    0x49D700 | public: virtual void * __thiscall AudioOptions::`scalar deleting destructor'(unsigned int) | ??_GAudioOptions@@UAEPAXI@Z
    0x61D488 | const AudioOptions::`vftable' | ??_7AudioOptions@@6B@
*/

#include "optionsbase.h"

class AudioOptions final : public OptionsBase
{
public:
    // ??0AudioOptions@@QAE@H@Z
    ARTS_IMPORT AudioOptions(i32 arg1);

    // ??_GAudioOptions@@UAEPAXI@Z
    // ??_EAudioOptions@@UAEPAXI@Z
    // ??1AudioOptions@@UAE@XZ
    ARTS_IMPORT ~AudioOptions() override;

    // ?CancelAction@AudioOptions@@UAEXXZ
    ARTS_IMPORT void CancelAction() override;

    // ?DoneAction@AudioOptions@@UAEXXZ
    ARTS_IMPORT void DoneAction() override;

    // ?FindDevice@AudioOptions@@QAEHPAD@Z
    ARTS_IMPORT i32 FindDevice(char* arg1);

    // ?GetCurrentDeviceName@AudioOptions@@QAEPADXZ
    ARTS_IMPORT char* GetCurrentDeviceName();

    // ?PreSetup@AudioOptions@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // ?ResetCDMusic@AudioOptions@@QAEXXZ
    ARTS_IMPORT void ResetCDMusic();

    // ?ResetCommentary@AudioOptions@@QAEXXZ
    ARTS_IMPORT void ResetCommentary();

    // ?ResetDefaultAction@AudioOptions@@UAEXXZ
    ARTS_IMPORT void ResetDefaultAction() override;

    // ?ResetSoundFX@AudioOptions@@QAEXXZ
    ARTS_IMPORT void ResetSoundFX();

    // ?ResetSoundQuality@AudioOptions@@QAEXXZ
    ARTS_IMPORT void ResetSoundQuality();

    // ?ResetStereo@AudioOptions@@QAEXXZ
    ARTS_IMPORT void ResetStereo();

    // ?SetAudioState@AudioOptions@@QAEXXZ
    ARTS_IMPORT void SetAudioState();

    // ?SetBalance@AudioOptions@@QAEXXZ
    ARTS_IMPORT void SetBalance();

    // ?SetCDMusic@AudioOptions@@QAEXXZ
    ARTS_IMPORT void SetCDMusic();

    // ?SetCDVolume@AudioOptions@@QAEXXZ
    ARTS_IMPORT void SetCDVolume();

    // ?SetCommentary@AudioOptions@@QAEXXZ
    ARTS_IMPORT void SetCommentary();

    // ?SetDevice@AudioOptions@@QAEXH@Z
    ARTS_IMPORT void SetDevice(i32 arg1);

    // ?SetQuality@AudioOptions@@QAEXXZ
    ARTS_IMPORT void SetQuality();

    // ?SetSoundFX@AudioOptions@@QAEXXZ
    ARTS_IMPORT void SetSoundFX();

    // ?SetStereoFX@AudioOptions@@QAEXXZ
    ARTS_IMPORT void SetStereoFX();

    // ?SetWaveVolume@AudioOptions@@QAEXXZ
    ARTS_IMPORT void SetWaveVolume();

    // ?StoreCurrentSetup@AudioOptions@@UAEXXZ
    ARTS_IMPORT void StoreCurrentSetup() override;

    u8 gap6EC8[0x38];
};

check_size(AudioOptions, 0x6F00);
