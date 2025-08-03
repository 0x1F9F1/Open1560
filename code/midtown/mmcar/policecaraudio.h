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

#include "opponentcaraudio.h"

class mmPoliceCarAudio final : public mmOpponentCarAudio
{
public:
    // ??0mmPoliceCarAudio@@QAE@PAVmmCarSim@@M@Z
    ARTS_IMPORT mmPoliceCarAudio(mmCarSim* arg1, f32 arg2);

    // ??1mmPoliceCarAudio@@UAE@XZ
    ARTS_EXPORT ~mmPoliceCarAudio() override = default;

    // ?AssignSounds@mmPoliceCarAudio@@QAEXPAVAudSound@@000PAVmmOpponentImpactAudio@@0@Z
    ARTS_IMPORT void AssignSounds(
        AudSound* arg1, AudSound* arg2, AudSound* arg3, AudSound* arg4, mmOpponentImpactAudio* arg5, AudSound* arg6);

    // ?DamageSiren@mmPoliceCarAudio@@QAEXXZ
    ARTS_IMPORT void DamageSiren();

    // ?ExplosionIsPlaying@mmPoliceCarAudio@@QAEHXZ
    ARTS_IMPORT i32 ExplosionIsPlaying();

    // ?PlayExplosion@mmPoliceCarAudio@@QAEXXZ
    ARTS_IMPORT void PlayExplosion();

    // ?PlayVoice@mmPoliceCarAudio@@QAEXXZ
    ARTS_IMPORT void PlayVoice();

    // ?StartSiren@mmPoliceCarAudio@@QAEXXZ
    ARTS_IMPORT void StartSiren();

    // ?StopSiren@mmPoliceCarAudio@@QAEXXZ
    ARTS_IMPORT void StopSiren();

    // ?UnAssignSounds@mmPoliceCarAudio@@QAEXXZ
    ARTS_IMPORT void UnAssignSounds();

    // ?Update@mmPoliceCarAudio@@QAEXHMM@Z
    ARTS_IMPORT void Update(i32 arg1, f32 arg2, f32 arg3);

    // ?UpdateDoppler@mmPoliceCarAudio@@QAEXXZ
    ARTS_IMPORT void UpdateDoppler();

    // ?UpdateDoppler@mmPoliceCarAudio@@QAEXM@Z
    ARTS_IMPORT void UpdateDoppler(f32 arg1);

private:
    // ?FluctuateFastSiren@mmPoliceCarAudio@@AAEXXZ
    ARTS_IMPORT void FluctuateFastSiren();

    // ?FluctuateSlowSiren@mmPoliceCarAudio@@AAEXXZ
    ARTS_IMPORT void FluctuateSlowSiren();

    // ?s_iPlayingFluctuator@mmPoliceCarAudio@@0FA
    ARTS_IMPORT static i16 s_iPlayingFluctuator;

    u8 gapE0[0x34];
};

check_size(mmPoliceCarAudio, 0x114);
