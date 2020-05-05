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
    mmcar:policecaraudio

    0x47A800 | public: __thiscall mmPoliceCarAudio::mmPoliceCarAudio(class mmCarSim *,float) | ??0mmPoliceCarAudio@@QAE@PAVmmCarSim@@M@Z
    0x47A8E0 | public: virtual __thiscall mmPoliceCarAudio::~mmPoliceCarAudio(void) | ??1mmPoliceCarAudio@@UAE@XZ
    0x47A8F0 | public: int __thiscall mmPoliceCarAudio::ExplosionIsPlaying(void) | ?ExplosionIsPlaying@mmPoliceCarAudio@@QAEHXZ
    0x47A910 | public: void __thiscall mmPoliceCarAudio::StartSiren(void) | ?StartSiren@mmPoliceCarAudio@@QAEXXZ
    0x47A9C0 | public: void __thiscall mmPoliceCarAudio::StopSiren(void) | ?StopSiren@mmPoliceCarAudio@@QAEXXZ
    0x47AA20 | public: void __thiscall mmPoliceCarAudio::PlayExplosion(void) | ?PlayExplosion@mmPoliceCarAudio@@QAEXXZ
    0x47AAD0 | public: void __thiscall mmPoliceCarAudio::DamageSiren(void) | ?DamageSiren@mmPoliceCarAudio@@QAEXXZ
    0x47AC30 | public: void __thiscall mmPoliceCarAudio::Update(int,float,float) | ?Update@mmPoliceCarAudio@@QAEXHMM@Z
    0x47AD50 | private: void __thiscall mmPoliceCarAudio::FluctuateSlowSiren(void) | ?FluctuateSlowSiren@mmPoliceCarAudio@@AAEXXZ
    0x47AFE0 | private: void __thiscall mmPoliceCarAudio::FluctuateFastSiren(void) | ?FluctuateFastSiren@mmPoliceCarAudio@@AAEXXZ
    0x47B400 | public: void __thiscall mmPoliceCarAudio::UpdateDoppler(void) | ?UpdateDoppler@mmPoliceCarAudio@@QAEXXZ
    0x47B410 | public: void __thiscall mmPoliceCarAudio::UpdateDoppler(float) | ?UpdateDoppler@mmPoliceCarAudio@@QAEXM@Z
    0x47B600 | public: void __thiscall mmPoliceCarAudio::PlayVoice(void) | ?PlayVoice@mmPoliceCarAudio@@QAEXXZ
    0x47B6A0 | public: void __thiscall mmPoliceCarAudio::AssignSounds(class AudSound *,class AudSound *,class AudSound *,class AudSound *,class mmOpponentImpactAudio *,class AudSound *) | ?AssignSounds@mmPoliceCarAudio@@QAEXPAVAudSound@@000PAVmmOpponentImpactAudio@@0@Z
    0x47B770 | public: void __thiscall mmPoliceCarAudio::UnAssignSounds(void) | ?UnAssignSounds@mmPoliceCarAudio@@QAEXXZ
    0x47B920 | public: virtual void * __thiscall mmPoliceCarAudio::`scalar deleting destructor'(unsigned int) | ??_GmmPoliceCarAudio@@UAEPAXI@Z
    0x47B920 | public: virtual void * __thiscall mmPoliceCarAudio::`vector deleting destructor'(unsigned int) | ??_EmmPoliceCarAudio@@UAEPAXI@Z
    0x61C4A0 | const mmPoliceCarAudio::`vftable' | ??_7mmPoliceCarAudio@@6B@
    0x6A7FE8 | private: static short mmPoliceCarAudio::s_iPlayingFluctuator | ?s_iPlayingFluctuator@mmPoliceCarAudio@@0FA
*/

#include "opponentcaraudio.h"

class mmPoliceCarAudio : public mmOpponentCarAudio
{
    // const mmPoliceCarAudio::`vftable' @ 0x61C4A0

public:
    // 0x47A800 | ??0mmPoliceCarAudio@@QAE@PAVmmCarSim@@M@Z
    mmPoliceCarAudio(class mmCarSim* arg1, f32 arg2);

    // 0x47B920 | ??_EmmPoliceCarAudio@@UAEPAXI@Z
    // 0x47A8E0 | ??1mmPoliceCarAudio@@UAE@XZ
    ~mmPoliceCarAudio() override;

    // 0x47B6A0 | ?AssignSounds@mmPoliceCarAudio@@QAEXPAVAudSound@@000PAVmmOpponentImpactAudio@@0@Z
    void AssignSounds(class AudSound* arg1, class AudSound* arg2, class AudSound* arg3, class AudSound* arg4,
        class mmOpponentImpactAudio* arg5, class AudSound* arg6);

    // 0x47AAD0 | ?DamageSiren@mmPoliceCarAudio@@QAEXXZ
    void DamageSiren();

    // 0x47A8F0 | ?ExplosionIsPlaying@mmPoliceCarAudio@@QAEHXZ
    i32 ExplosionIsPlaying();

    // 0x47AA20 | ?PlayExplosion@mmPoliceCarAudio@@QAEXXZ
    void PlayExplosion();

    // 0x47B600 | ?PlayVoice@mmPoliceCarAudio@@QAEXXZ
    void PlayVoice();

    // 0x47A910 | ?StartSiren@mmPoliceCarAudio@@QAEXXZ
    void StartSiren();

    // 0x47A9C0 | ?StopSiren@mmPoliceCarAudio@@QAEXXZ
    void StopSiren();

    // 0x47B770 | ?UnAssignSounds@mmPoliceCarAudio@@QAEXXZ
    void UnAssignSounds();

    // 0x47AC30 | ?Update@mmPoliceCarAudio@@QAEXHMM@Z
    void Update(i32 arg1, f32 arg2, f32 arg3);

    // 0x47B400 | ?UpdateDoppler@mmPoliceCarAudio@@QAEXXZ
    void UpdateDoppler();

    // 0x47B410 | ?UpdateDoppler@mmPoliceCarAudio@@QAEXM@Z
    void UpdateDoppler(f32 arg1);

private:
    // 0x47AFE0 | ?FluctuateFastSiren@mmPoliceCarAudio@@AAEXXZ
    void FluctuateFastSiren();

    // 0x47AD50 | ?FluctuateSlowSiren@mmPoliceCarAudio@@AAEXXZ
    void FluctuateSlowSiren();

    // 0x6A7FE8 | ?s_iPlayingFluctuator@mmPoliceCarAudio@@0FA
    static inline extern_var(0x2A7FE8_Offset, i16, s_iPlayingFluctuator);
};

check_size(mmPoliceCarAudio, 0x114);
