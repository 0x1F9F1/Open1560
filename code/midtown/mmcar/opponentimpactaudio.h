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

class mmOpponentImpactAudio
{
public:
    // ??0mmOpponentImpactAudio@@QAE@XZ
    ARTS_IMPORT mmOpponentImpactAudio();

    // ??1mmOpponentImpactAudio@@QAE@XZ
    ARTS_IMPORT ~mmOpponentImpactAudio();

    // ?Disable3DMode@mmOpponentImpactAudio@@QAEXXZ
    ARTS_IMPORT void Disable3DMode();

    // ?Enable3DMode@mmOpponentImpactAudio@@QAEXPAVVector3@@@Z
    ARTS_IMPORT void Enable3DMode(Vector3* arg1);

    // ?Play@mmOpponentImpactAudio@@QAEXMFMM@Z
    ARTS_IMPORT void Play(f32 arg1, i16 arg2, f32 arg3, f32 arg4);

    // ?Update@mmOpponentImpactAudio@@QAEXXZ
    ARTS_IMPORT void Update();

    // ?GetSecondsElapsed@mmOpponentImpactAudio@@SAMXZ
    ARTS_IMPORT static f32 GetSecondsElapsed();

    // ?SetSecondsElapsed@mmOpponentImpactAudio@@SAXM@Z
    ARTS_IMPORT static void SetSecondsElapsed(f32 arg1);

private:
    // ?m_fBareMinimum@mmOpponentImpactAudio@@0MA
    ARTS_IMPORT static f32 m_fBareMinimum;

    // ?m_fHugeVolumeMultiplier@mmOpponentImpactAudio@@0MA
    ARTS_IMPORT static f32 m_fHugeVolumeMultiplier;

    // ?m_fMaxHugeVolume@mmOpponentImpactAudio@@0MA
    ARTS_IMPORT static f32 m_fMaxHugeVolume;

    // ?m_fMaxMedVolume@mmOpponentImpactAudio@@0MA
    ARTS_IMPORT static f32 m_fMaxMedVolume;

    // ?m_fMaxSoftVolume@mmOpponentImpactAudio@@0MA
    ARTS_IMPORT static f32 m_fMaxSoftVolume;

    // ?m_fMedVolumeMultiplier@mmOpponentImpactAudio@@0MA
    ARTS_IMPORT static f32 m_fMedVolumeMultiplier;

    // ?m_fMedium@mmOpponentImpactAudio@@0MA
    ARTS_IMPORT static f32 m_fMedium;

    // ?m_fMinHugeVolume@mmOpponentImpactAudio@@0MA
    ARTS_IMPORT static f32 m_fMinHugeVolume;

    // ?m_fMinMedVolume@mmOpponentImpactAudio@@0MA
    ARTS_IMPORT static f32 m_fMinMedVolume;

    // ?m_fMinSoftVolume@mmOpponentImpactAudio@@0MA
    ARTS_IMPORT static f32 m_fMinSoftVolume;

    // ?m_fSoft@mmOpponentImpactAudio@@0MA
    ARTS_IMPORT static f32 m_fSoft;

    // ?m_fSoftVolumeMultiplier@mmOpponentImpactAudio@@0MA
    ARTS_IMPORT static f32 m_fSoftVolumeMultiplier;

    // ?s_fSecondsElapsed@mmOpponentImpactAudio@@0MA
    ARTS_IMPORT static f32 s_fSecondsElapsed;

    u8 gap0[0x18];
};

check_size(mmOpponentImpactAudio, 0x18);
