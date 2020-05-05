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
    mmcar:opponentcaraudio

    0x47B950 | public: __thiscall mmOpponentCarAudio::mmOpponentCarAudio(class mmCarSim *) | ??0mmOpponentCarAudio@@QAE@PAVmmCarSim@@@Z
    0x47B9C0 | public: virtual __thiscall mmOpponentCarAudio::~mmOpponentCarAudio(void) | ??1mmOpponentCarAudio@@UAE@XZ
    0x47BA30 | public: void __thiscall mmOpponentCarAudio::Init(class mmCarSim *) | ?Init@mmOpponentCarAudio@@QAEXPAVmmCarSim@@@Z
    0x47BB80 | public: void __thiscall mmOpponentCarAudio::PlayReverseBeep(void) | ?PlayReverseBeep@mmOpponentCarAudio@@QAEXXZ
    0x47BBE0 | public: void __thiscall mmOpponentCarAudio::Update(int,float,float) | ?Update@mmOpponentCarAudio@@QAEXHMM@Z
    0x47BC80 | public: void __thiscall mmOpponentCarAudio::CalculateDistToPlayer2(void) | ?CalculateDistToPlayer2@mmOpponentCarAudio@@QAEXXZ
    0x47BD60 | public: void __thiscall mmOpponentCarAudio::CalculatePan(void) | ?CalculatePan@mmOpponentCarAudio@@QAEXXZ
    0x47BDB0 | public: void __thiscall mmOpponentCarAudio::CalculateDoppler(float) | ?CalculateDoppler@mmOpponentCarAudio@@QAEXM@Z
    0x47BDE0 | public: void __thiscall mmOpponentCarAudio::UpdateDoppler(void) | ?UpdateDoppler@mmOpponentCarAudio@@QAEXXZ
    0x47BDF0 | public: void __thiscall mmOpponentCarAudio::UpdateDoppler(float) | ?UpdateDoppler@mmOpponentCarAudio@@QAEXM@Z
    0x47BF00 | public: virtual void __thiscall mmOpponentCarAudio::Reset(void) | ?Reset@mmOpponentCarAudio@@UAEXXZ
    0x47BF20 | public: void __thiscall mmOpponentCarAudio::LoadSucessful(class mmCarSim *) | ?LoadSucessful@mmOpponentCarAudio@@QAEXPAVmmCarSim@@@Z
    0x47BF50 | public: void __thiscall mmOpponentCarAudio::AssignSounds(class AudSound *,class AudSound *,class mmOpponentImpactAudio *,class AudSound *) | ?AssignSounds@mmOpponentCarAudio@@QAEXPAVAudSound@@0PAVmmOpponentImpactAudio@@0@Z
    0x47C020 | public: void __thiscall mmOpponentCarAudio::UnAssignSounds(void) | ?UnAssignSounds@mmOpponentCarAudio@@QAEXXZ
    0x47C0C0 | public: void __thiscall mmOpponentCarAudio::SetMinAmpSpeed(float) | ?SetMinAmpSpeed@mmOpponentCarAudio@@QAEXM@Z
    0x47C0E0 | public: static void __cdecl mmOpponentCarAudio::DeclareFields(void) | ?DeclareFields@mmOpponentCarAudio@@SAXXZ
    0x47C2A0 | public: virtual class MetaClass * __thiscall mmOpponentCarAudio::GetClass(void) | ?GetClass@mmOpponentCarAudio@@UAEPAVMetaClass@@XZ
    0x47C3D0 | public: virtual void * __thiscall mmOpponentCarAudio::`vector deleting destructor'(unsigned int) | ??_EmmOpponentCarAudio@@UAEPAXI@Z
    0x47C430 | public: __thiscall mmOpponentCarAudio::mmOpponentCarAudio(void) | ??0mmOpponentCarAudio@@QAE@XZ
    0x61C500 | const mmOpponentCarAudio::`vftable' | ??_7mmOpponentCarAudio@@6B@
    0x6A7FF8 | class MetaClass mmOpponentCarAudioMetaClass | ?mmOpponentCarAudioMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class mmOpponentCarAudio : public asNode
{
    // const mmOpponentCarAudio::`vftable' @ 0x61C500

public:
    // 0x47C430 | ??0mmOpponentCarAudio@@QAE@XZ
    mmOpponentCarAudio();

    // 0x47B950 | ??0mmOpponentCarAudio@@QAE@PAVmmCarSim@@@Z
    mmOpponentCarAudio(class mmCarSim* arg1);

    // 0x47C3D0 | ??_EmmOpponentCarAudio@@UAEPAXI@Z
    // 0x47B9C0 | ??1mmOpponentCarAudio@@UAE@XZ
    ~mmOpponentCarAudio() override;

    // 0x47BF50 | ?AssignSounds@mmOpponentCarAudio@@QAEXPAVAudSound@@0PAVmmOpponentImpactAudio@@0@Z
    void AssignSounds(
        class AudSound* arg1, class AudSound* arg2, class mmOpponentImpactAudio* arg3, class AudSound* arg4);

    // 0x47BC80 | ?CalculateDistToPlayer2@mmOpponentCarAudio@@QAEXXZ
    void CalculateDistToPlayer2();

    // 0x47BDB0 | ?CalculateDoppler@mmOpponentCarAudio@@QAEXM@Z
    void CalculateDoppler(f32 arg1);

    // 0x47BD60 | ?CalculatePan@mmOpponentCarAudio@@QAEXXZ
    void CalculatePan();

    // 0x47C2A0 | ?GetClass@mmOpponentCarAudio@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x47BA30 | ?Init@mmOpponentCarAudio@@QAEXPAVmmCarSim@@@Z
    void Init(class mmCarSim* arg1);

    // 0x47BF20 | ?LoadSucessful@mmOpponentCarAudio@@QAEXPAVmmCarSim@@@Z
    void LoadSucessful(class mmCarSim* arg1);

    // 0x47BB80 | ?PlayReverseBeep@mmOpponentCarAudio@@QAEXXZ
    void PlayReverseBeep();

    // 0x47BF00 | ?Reset@mmOpponentCarAudio@@UAEXXZ
    void Reset() override;

    // 0x47C0C0 | ?SetMinAmpSpeed@mmOpponentCarAudio@@QAEXM@Z
    void SetMinAmpSpeed(f32 arg1);

    // 0x47C020 | ?UnAssignSounds@mmOpponentCarAudio@@QAEXXZ
    void UnAssignSounds();

    // 0x47BBE0 | ?Update@mmOpponentCarAudio@@QAEXHMM@Z
    void Update(i32 arg1, f32 arg2, f32 arg3);

    // 0x47BDE0 | ?UpdateDoppler@mmOpponentCarAudio@@QAEXXZ
    void UpdateDoppler();

    // 0x47BDF0 | ?UpdateDoppler@mmOpponentCarAudio@@QAEXM@Z
    void UpdateDoppler(f32 arg1);

    // 0x47C0E0 | ?DeclareFields@mmOpponentCarAudio@@SAXXZ
    static void DeclareFields();
};

check_size(mmOpponentCarAudio, 0xE0);

// 0x6A7FF8 | ?mmOpponentCarAudioMetaClass@@3VMetaClass@@A
inline extern_var(0x2A7FF8_Offset, class MetaClass, mmOpponentCarAudioMetaClass);
