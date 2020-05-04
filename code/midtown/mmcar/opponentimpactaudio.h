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
    // 0x47A3B0 | ??0mmOpponentImpactAudio@@QAE@XZ
    mmOpponentImpactAudio();

    // 0x47A570 | ??1mmOpponentImpactAudio@@QAE@XZ
    ~mmOpponentImpactAudio();

    // 0x47A7E0 | ?Disable3DMode@mmOpponentImpactAudio@@QAEXXZ
    void Disable3DMode();

    // 0x47A770 | ?Enable3DMode@mmOpponentImpactAudio@@QAEXPAVVector3@@@Z
    void Enable3DMode(class Vector3* arg1);

    // 0x47A5A0 | ?Play@mmOpponentImpactAudio@@QAEXMFMM@Z
    void Play(f32 arg1, i16 arg2, f32 arg3, f32 arg4);

    // 0x47A710 | ?Update@mmOpponentImpactAudio@@QAEXXZ
    void Update();

    // 0x47A7D0 | ?GetSecondsElapsed@mmOpponentImpactAudio@@SAMXZ
    static f32 GetSecondsElapsed();

    // 0x47A7C0 | ?SetSecondsElapsed@mmOpponentImpactAudio@@SAXM@Z
    static void SetSecondsElapsed(f32 arg1);

private:
    // 0x63C1E8 | ?m_fBareMinimum@mmOpponentImpactAudio@@0MA
    static inline extern_var(0x23C1E8_Offset, f32, m_fBareMinimum);

    // 0x6A7FCC | ?m_fHugeVolumeMultiplier@mmOpponentImpactAudio@@0MA
    static inline extern_var(0x2A7FCC_Offset, f32, m_fHugeVolumeMultiplier);

    // 0x63C208 | ?m_fMaxHugeVolume@mmOpponentImpactAudio@@0MA
    static inline extern_var(0x23C208_Offset, f32, m_fMaxHugeVolume);

    // 0x63C200 | ?m_fMaxMedVolume@mmOpponentImpactAudio@@0MA
    static inline extern_var(0x23C200_Offset, f32, m_fMaxMedVolume);

    // 0x63C1F8 | ?m_fMaxSoftVolume@mmOpponentImpactAudio@@0MA
    static inline extern_var(0x23C1F8_Offset, f32, m_fMaxSoftVolume);

    // 0x6A7FC8 | ?m_fMedVolumeMultiplier@mmOpponentImpactAudio@@0MA
    static inline extern_var(0x2A7FC8_Offset, f32, m_fMedVolumeMultiplier);

    // 0x63C1F0 | ?m_fMedium@mmOpponentImpactAudio@@0MA
    static inline extern_var(0x23C1F0_Offset, f32, m_fMedium);

    // 0x63C204 | ?m_fMinHugeVolume@mmOpponentImpactAudio@@0MA
    static inline extern_var(0x23C204_Offset, f32, m_fMinHugeVolume);

    // 0x63C1FC | ?m_fMinMedVolume@mmOpponentImpactAudio@@0MA
    static inline extern_var(0x23C1FC_Offset, f32, m_fMinMedVolume);

    // 0x63C1F4 | ?m_fMinSoftVolume@mmOpponentImpactAudio@@0MA
    static inline extern_var(0x23C1F4_Offset, f32, m_fMinSoftVolume);

    // 0x63C1EC | ?m_fSoft@mmOpponentImpactAudio@@0MA
    static inline extern_var(0x23C1EC_Offset, f32, m_fSoft);

    // 0x6A7FC4 | ?m_fSoftVolumeMultiplier@mmOpponentImpactAudio@@0MA
    static inline extern_var(0x2A7FC4_Offset, f32, m_fSoftVolumeMultiplier);

    // 0x6A7FC0 | ?s_fSecondsElapsed@mmOpponentImpactAudio@@0MA
    static inline extern_var(0x2A7FC0_Offset, f32, s_fSecondsElapsed);
};

check_size(mmOpponentImpactAudio, 0x0);
