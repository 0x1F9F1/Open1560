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
    mmai:aiVehiclePolice

    0x444790 | public: __thiscall aiVehiclePolice::aiVehiclePolice(void) | ??0aiVehiclePolice@@QAE@XZ
    0x4447F0 | public: __thiscall aiVehiclePolice::~aiVehiclePolice(void) | ??1aiVehiclePolice@@QAE@XZ
    0x444930 | public: void __thiscall aiVehiclePolice::Init(int,class aiRaceData *) | ?Init@aiVehiclePolice@@QAEXHPAVaiRaceData@@@Z
    0x444B40 | public: virtual void __thiscall aiVehiclePolice::Reset(void) | ?Reset@aiVehiclePolice@@UAEXXZ
    0x4451D0 | public: void __thiscall aiVehiclePolice::ResetPed(void) | ?ResetPed@aiVehiclePolice@@QAEXXZ
    0x4453D0 | public: virtual void __thiscall aiVehiclePolice::Update(void) | ?Update@aiVehiclePolice@@UAEXXZ
    0x4459D0 | public: int __thiscall aiVehiclePolice::InPersuit(void) | ?InPersuit@aiVehiclePolice@@QAEHXZ
    0x445A00 | public: int __thiscall aiVehiclePolice::IsPerpInRange(class mmCar *) | ?IsPerpInRange@aiVehiclePolice@@QAEHPAVmmCar@@@Z
    0x445C70 | private: int __thiscall aiVehiclePolice::FindPerp(int,int,class aiPath *,int,int) | ?FindPerp@aiVehiclePolice@@AAEHHHPAVaiPath@@HH@Z
    0x445DB0 | public: void __thiscall aiVehiclePolice::PerpEscapes(unsigned char) | ?PerpEscapes@aiVehiclePolice@@QAEXE@Z
    0x445E20 | public: void __thiscall aiVehiclePolice::ConfigCar(void) | ?ConfigCar@aiVehiclePolice@@QAEXXZ
    0x445F20 | public: void __thiscall aiVehiclePolice::Backup(void) | ?Backup@aiVehiclePolice@@QAEXXZ
    0x445F40 | public: void __thiscall aiVehiclePolice::DrawTargetPt(void) | ?DrawTargetPt@aiVehiclePolice@@QAEXXZ
    0x4460B0 | public: void __thiscall aiVehiclePolice::DrawDamage(void) | ?DrawDamage@aiVehiclePolice@@QAEXXZ
    0x446100 | public: virtual void __thiscall aiVehiclePolice::DrawId(void) | ?DrawId@aiVehiclePolice@@UAEXXZ
    0x446150 | public: void __thiscall aiVehiclePolice::UnAssignSounds(void) | ?UnAssignSounds@aiVehiclePolice@@QAEXXZ
    0x446170 | public: class mmPoliceCarAudio * __thiscall aiVehiclePolice::GetCarAudioPtr(void) | ?GetCarAudioPtr@aiVehiclePolice@@QAEPAVmmPoliceCarAudio@@XZ
    0x446180 | public: int __thiscall aiVehiclePolice::GetEngineSoundIndex(void) | ?GetEngineSoundIndex@aiVehiclePolice@@QAEHXZ
    0x446190 | public: void __thiscall aiVehiclePolice::SetMainSirenLoop(int) | ?SetMainSirenLoop@aiVehiclePolice@@QAEXH@Z
    0x4461B0 | public: void __thiscall aiVehiclePolice::UpdateAudio(void) | ?UpdateAudio@aiVehiclePolice@@QAEXXZ
    0x446270 | public: float __thiscall aiVehiclePolice::GetDistanceToPlayer2(void) | ?GetDistanceToPlayer2@aiVehiclePolice@@QAEMXZ
    0x446280 | public: void __thiscall aiVehiclePolice::PlayVoice(void) | ?PlayVoice@aiVehiclePolice@@QAEXXZ
    0x446290 | public: void __thiscall aiVehiclePolice::SetAudioMinDistance(float) | ?SetAudioMinDistance@aiVehiclePolice@@QAEXM@Z
    0x4462B0 | public: void __thiscall aiVehiclePolice::SetAudioMaxDistance(float) | ?SetAudioMaxDistance@aiVehiclePolice@@QAEXM@Z
    0x4462E0 | public: void __thiscall aiVehiclePolice::SetAudioCloserMinDistMult(float) | ?SetAudioCloserMinDistMult@aiVehiclePolice@@QAEXM@Z
    0x446300 | private: void __thiscall aiVehiclePolice::AddToAiAudMgr(void) | ?AddToAiAudMgr@aiVehiclePolice@@AAEXXZ
    0x446370 | public: void __thiscall aiVehiclePolice::AssignSounds(class AudSound *,class AudSound *,class AudSound *,class AudSound *,class mmOpponentImpactAudio *,class AudSound *) | ?AssignSounds@aiVehiclePolice@@QAEXPAVAudSound@@000PAVmmOpponentImpactAudio@@0@Z
    0x4463A0 | public: class mmPoliceCarAudio * __thiscall aiVehiclePolice::GetAudioPtr(void) | ?GetAudioPtr@aiVehiclePolice@@QAEPAVmmPoliceCarAudio@@XZ
    0x4463B0 | public: void __thiscall aiVehiclePolice::Dump(void) | ?Dump@aiVehiclePolice@@QAEXXZ
    0x4465E0 | public: virtual class mmOpponentImpactAudio * __thiscall aiVehicleSpline::GetImpactAudioPtr(void) | ?GetImpactAudioPtr@aiVehicleSpline@@UAEPAVmmOpponentImpactAudio@@XZ
    0x4465F0 | public: virtual void __thiscall aiVehicleSpline::PlayHorn(float,float) | ?PlayHorn@aiVehicleSpline@@UAEXMM@Z
    0x446600 | public: virtual void __thiscall aiVehicleSpline::ImpactAudioReaction(float) | ?ImpactAudioReaction@aiVehicleSpline@@UAEXM@Z
    0x446610 | public: virtual void __thiscall aiVehicleSpline::StopVoice(void) | ?StopVoice@aiVehicleSpline@@UAEXXZ
    0x446620 | public: virtual int __thiscall aiVehiclePolice::Type(void) | ?Type@aiVehiclePolice@@UAEHXZ
    0x61B538 | const aiVehiclePolice::`vftable' | ??_7aiVehiclePolice@@6B@
*/

#include "aiVehicleSpline.h"

class aiVehiclePolice : public aiVehicleSpline
{
    // const aiVehiclePolice::`vftable' @ 0x61B538

public:
    // 0x444790 | ??0aiVehiclePolice@@QAE@XZ
    aiVehiclePolice();

    // 0x43BF50 | ??_EaiVehiclePolice@@QAEPAXI@Z
    // 0x4447F0 | ??1aiVehiclePolice@@QAE@XZ
    ~aiVehiclePolice();

    // 0x446370 | ?AssignSounds@aiVehiclePolice@@QAEXPAVAudSound@@000PAVmmOpponentImpactAudio@@0@Z
    void AssignSounds(class AudSound* arg1, class AudSound* arg2, class AudSound* arg3, class AudSound* arg4,
        class mmOpponentImpactAudio* arg5, class AudSound* arg6);

    // 0x445F20 | ?Backup@aiVehiclePolice@@QAEXXZ | unused
    void Backup();

    // 0x445E20 | ?ConfigCar@aiVehiclePolice@@QAEXXZ
    void ConfigCar();

    // 0x4460B0 | ?DrawDamage@aiVehiclePolice@@QAEXXZ | unused
    void DrawDamage();

    // 0x446100 | ?DrawId@aiVehiclePolice@@UAEXXZ
    void DrawId() override;

    // 0x445F40 | ?DrawTargetPt@aiVehiclePolice@@QAEXXZ
    void DrawTargetPt();

    // 0x4463B0 | ?Dump@aiVehiclePolice@@QAEXXZ
    void Dump();

    // 0x4463A0 | ?GetAudioPtr@aiVehiclePolice@@QAEPAVmmPoliceCarAudio@@XZ
    class mmPoliceCarAudio* GetAudioPtr();

    // 0x446170 | ?GetCarAudioPtr@aiVehiclePolice@@QAEPAVmmPoliceCarAudio@@XZ
    class mmPoliceCarAudio* GetCarAudioPtr();

    // 0x446270 | ?GetDistanceToPlayer2@aiVehiclePolice@@QAEMXZ
    f32 GetDistanceToPlayer2();

    // 0x446180 | ?GetEngineSoundIndex@aiVehiclePolice@@QAEHXZ
    i32 GetEngineSoundIndex();

    // 0x4459D0 | ?InPersuit@aiVehiclePolice@@QAEHXZ
    i32 InPersuit();

    // 0x444930 | ?Init@aiVehiclePolice@@QAEXHPAVaiRaceData@@@Z
    void Init(i32 arg1, class aiRaceData* arg2);

    // 0x445A00 | ?IsPerpInRange@aiVehiclePolice@@QAEHPAVmmCar@@@Z | unused
    i32 IsPerpInRange(class mmCar* arg1);

    // 0x445DB0 | ?PerpEscapes@aiVehiclePolice@@QAEXE@Z
    void PerpEscapes(u8 arg1);

    // 0x446280 | ?PlayVoice@aiVehiclePolice@@QAEXXZ
    void PlayVoice();

    // 0x444B40 | ?Reset@aiVehiclePolice@@UAEXXZ
    void Reset() override;

    // 0x4451D0 | ?ResetPed@aiVehiclePolice@@QAEXXZ
    void ResetPed();

    // 0x4462E0 | ?SetAudioCloserMinDistMult@aiVehiclePolice@@QAEXM@Z
    void SetAudioCloserMinDistMult(f32 arg1);

    // 0x4462B0 | ?SetAudioMaxDistance@aiVehiclePolice@@QAEXM@Z
    void SetAudioMaxDistance(f32 arg1);

    // 0x446290 | ?SetAudioMinDistance@aiVehiclePolice@@QAEXM@Z
    void SetAudioMinDistance(f32 arg1);

    // 0x446190 | ?SetMainSirenLoop@aiVehiclePolice@@QAEXH@Z
    void SetMainSirenLoop(i32 arg1);

    // 0x446620 | ?Type@aiVehiclePolice@@UAEHXZ
    i32 Type() override;

    // 0x446150 | ?UnAssignSounds@aiVehiclePolice@@QAEXXZ
    void UnAssignSounds();

    // 0x4453D0 | ?Update@aiVehiclePolice@@UAEXXZ
    void Update() override;

    // 0x4461B0 | ?UpdateAudio@aiVehiclePolice@@QAEXXZ
    void UpdateAudio();

private:
    // 0x446300 | ?AddToAiAudMgr@aiVehiclePolice@@AAEXXZ
    void AddToAiAudMgr();

    // 0x445C70 | ?FindPerp@aiVehiclePolice@@AAEHHHPAVaiPath@@HH@Z
    i32 FindPerp(i32 arg1, i32 arg2, class aiPath* arg3, i32 arg4, i32 arg5);
};

check_size(aiVehiclePolice, 0x241C);
