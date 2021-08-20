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
    mmcar:opponentimpactaudio

    0x47A3B0 | public: __thiscall mmOpponentImpactAudio::mmOpponentImpactAudio(void) | ??0mmOpponentImpactAudio@@QAE@XZ
    0x47A570 | public: __thiscall mmOpponentImpactAudio::~mmOpponentImpactAudio(void) | ??1mmOpponentImpactAudio@@QAE@XZ
    0x47A5A0 | public: void __thiscall mmOpponentImpactAudio::Play(float,short,float,float) | ?Play@mmOpponentImpactAudio@@QAEXMFMM@Z
    0x47A710 | public: void __thiscall mmOpponentImpactAudio::Update(void) | ?Update@mmOpponentImpactAudio@@QAEXXZ
    0x47A770 | public: void __thiscall mmOpponentImpactAudio::Enable3DMode(class Vector3 *) | ?Enable3DMode@mmOpponentImpactAudio@@QAEXPAVVector3@@@Z
    0x47A7C0 | public: static void __cdecl mmOpponentImpactAudio::SetSecondsElapsed(float) | ?SetSecondsElapsed@mmOpponentImpactAudio@@SAXM@Z
    0x47A7D0 | public: static float __cdecl mmOpponentImpactAudio::GetSecondsElapsed(void) | ?GetSecondsElapsed@mmOpponentImpactAudio@@SAMXZ
    0x47A7E0 | public: void __thiscall mmOpponentImpactAudio::Disable3DMode(void) | ?Disable3DMode@mmOpponentImpactAudio@@QAEXXZ
    0x63C1E8 | private: static float mmOpponentImpactAudio::m_fBareMinimum | ?m_fBareMinimum@mmOpponentImpactAudio@@0MA
    0x63C1EC | private: static float mmOpponentImpactAudio::m_fSoft | ?m_fSoft@mmOpponentImpactAudio@@0MA
    0x63C1F0 | private: static float mmOpponentImpactAudio::m_fMedium | ?m_fMedium@mmOpponentImpactAudio@@0MA
    0x63C1F4 | private: static float mmOpponentImpactAudio::m_fMinSoftVolume | ?m_fMinSoftVolume@mmOpponentImpactAudio@@0MA
    0x63C1F8 | private: static float mmOpponentImpactAudio::m_fMaxSoftVolume | ?m_fMaxSoftVolume@mmOpponentImpactAudio@@0MA
    0x63C1FC | private: static float mmOpponentImpactAudio::m_fMinMedVolume | ?m_fMinMedVolume@mmOpponentImpactAudio@@0MA
    0x63C200 | private: static float mmOpponentImpactAudio::m_fMaxMedVolume | ?m_fMaxMedVolume@mmOpponentImpactAudio@@0MA
    0x63C204 | private: static float mmOpponentImpactAudio::m_fMinHugeVolume | ?m_fMinHugeVolume@mmOpponentImpactAudio@@0MA
    0x63C208 | private: static float mmOpponentImpactAudio::m_fMaxHugeVolume | ?m_fMaxHugeVolume@mmOpponentImpactAudio@@0MA
    0x6A7FC0 | private: static float mmOpponentImpactAudio::s_fSecondsElapsed | ?s_fSecondsElapsed@mmOpponentImpactAudio@@0MA
    0x6A7FC4 | private: static float mmOpponentImpactAudio::m_fSoftVolumeMultiplier | ?m_fSoftVolumeMultiplier@mmOpponentImpactAudio@@0MA
    0x6A7FC8 | private: static float mmOpponentImpactAudio::m_fMedVolumeMultiplier | ?m_fMedVolumeMultiplier@mmOpponentImpactAudio@@0MA
    0x6A7FCC | private: static float mmOpponentImpactAudio::m_fHugeVolumeMultiplier | ?m_fHugeVolumeMultiplier@mmOpponentImpactAudio@@0MA
*/

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
