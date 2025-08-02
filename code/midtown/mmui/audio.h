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
