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
    mmai:aiVehicleOpponent

    0x44DA70 | public: __thiscall aiVehicleOpponent::aiVehicleOpponent(void) | ??0aiVehicleOpponent@@QAE@XZ
    0x44DAD0 | public: __thiscall aiVehicleOpponent::~aiVehicleOpponent(void) | ??1aiVehicleOpponent@@QAE@XZ
    0x44DC00 | public: void __thiscall aiVehicleOpponent::Init(int,class aiRaceData *,char *) | ?Init@aiVehicleOpponent@@QAEXHPAVaiRaceData@@PAD@Z
    0x44DE10 | public: virtual void __thiscall aiVehicleOpponent::Reset(void) | ?Reset@aiVehicleOpponent@@UAEXXZ
    0x44DED0 | public: virtual void __thiscall aiVehicleOpponent::Update(void) | ?Update@aiVehicleOpponent@@UAEXXZ
    0x44E060 | public: void __thiscall aiVehicleOpponent::Dump(void) | ?Dump@aiVehicleOpponent@@QAEXXZ
    0x44E100 | public: void __thiscall aiVehicleOpponent::UnAssignSounds(void) | ?UnAssignSounds@aiVehicleOpponent@@QAEXXZ
    0x44E120 | public: int __thiscall aiVehicleOpponent::GetEngineSoundIndex(void) | ?GetEngineSoundIndex@aiVehicleOpponent@@QAEHXZ
    0x44E130 | public: void __thiscall aiVehicleOpponent::DrawTargetPt(void) | ?DrawTargetPt@aiVehicleOpponent@@QAEXXZ
    0x44E2A0 | public: void __thiscall aiVehicleOpponent::DrawDamage(void) | ?DrawDamage@aiVehicleOpponent@@QAEXXZ
    0x44E2B0 | public: virtual void __thiscall aiVehicleOpponent::DrawId(void) | ?DrawId@aiVehicleOpponent@@UAEXXZ
    0x44E300 | public: void __thiscall aiVehicleOpponent::UpdateAudio(void) | ?UpdateAudio@aiVehicleOpponent@@QAEXXZ
    0x44E3A0 | public: float __thiscall aiVehicleOpponent::GetDistanceToPlayer2(void) | ?GetDistanceToPlayer2@aiVehicleOpponent@@QAEMXZ
    0x44E3B0 | public: void __thiscall aiVehicleOpponent::SetAudioMinDistance(float) | ?SetAudioMinDistance@aiVehicleOpponent@@QAEXM@Z
    0x44E3D0 | public: void __thiscall aiVehicleOpponent::SetAudioMaxDistance(float) | ?SetAudioMaxDistance@aiVehicleOpponent@@QAEXM@Z
    0x44E400 | public: void __thiscall aiVehicleOpponent::SetAudioCloserMinDistMult(float) | ?SetAudioCloserMinDistMult@aiVehicleOpponent@@QAEXM@Z
    0x44E420 | public: class mmOpponentCarAudio * __thiscall aiVehicleOpponent::GetCarAudioPtr(void) | ?GetCarAudioPtr@aiVehicleOpponent@@QAEPAVmmOpponentCarAudio@@XZ
    0x44E430 | private: void __thiscall aiVehicleOpponent::AddToAiAudMgr(void) | ?AddToAiAudMgr@aiVehicleOpponent@@AAEXXZ
    0x44E490 | public: void __thiscall aiVehicleOpponent::AddWidget(class Bank *) | ?AddWidget@aiVehicleOpponent@@QAEXPAVBank@@@Z
    0x44E4B0 | public: void __thiscall aiVehicleOpponent::AssignSounds(class AudSound *,class AudSound *,class mmOpponentImpactAudio *,class AudSound *) | ?AssignSounds@aiVehicleOpponent@@QAEXPAVAudSound@@0PAVmmOpponentImpactAudio@@0@Z
    0x44E4E0 | public: static void __cdecl aiVehicleOpponent::DeclareFields(void) | ?DeclareFields@aiVehicleOpponent@@SAXXZ
    0x44E670 | public: virtual class MetaClass * __thiscall aiVehicleOpponent::GetClass(void) | ?GetClass@aiVehicleOpponent@@UAEPAVMetaClass@@XZ
    0x44E7D0 | public: virtual int __thiscall aiVehicleOpponent::Type(void) | ?Type@aiVehicleOpponent@@UAEHXZ
    0x61B6F8 | const aiVehicleOpponent::`vftable' | ??_7aiVehicleOpponent@@6B@
    0x6A7A58 | class MetaClass aiVehicleOpponentMetaClass | ?aiVehicleOpponentMetaClass@@3VMetaClass@@A
*/

#include "aiVehicle.h"

class aiVehicleOpponent : public aiVehicle
{
    // const aiVehicleOpponent::`vftable' @ 0x61B6F8

public:
    // 0x44DA70 | ??0aiVehicleOpponent@@QAE@XZ
    ARTS_IMPORT aiVehicleOpponent();

    // 0x43BFB0 | ??_EaiVehicleOpponent@@QAEPAXI@Z | unused
    // 0x44DAD0 | ??1aiVehicleOpponent@@QAE@XZ
    ARTS_IMPORT ~aiVehicleOpponent();

    // 0x44E670 | ?GetClass@aiVehicleOpponent@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT virtual class MetaClass* GetClass();

    // 0x44E490 | ?AddWidget@aiVehicleOpponent@@QAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidget(class Bank* arg1);

    // 0x44E4B0 | ?AssignSounds@aiVehicleOpponent@@QAEXPAVAudSound@@0PAVmmOpponentImpactAudio@@0@Z
    ARTS_IMPORT void AssignSounds(
        class AudSound* arg1, class AudSound* arg2, class mmOpponentImpactAudio* arg3, class AudSound* arg4);

    // 0x44E2A0 | ?DrawDamage@aiVehicleOpponent@@QAEXXZ | unused
    ARTS_IMPORT void DrawDamage();

    // 0x44E2B0 | ?DrawId@aiVehicleOpponent@@UAEXXZ
    ARTS_IMPORT void DrawId() override;

    // 0x44E130 | ?DrawTargetPt@aiVehicleOpponent@@QAEXXZ
    ARTS_IMPORT void DrawTargetPt();

    // 0x44E060 | ?Dump@aiVehicleOpponent@@QAEXXZ
    ARTS_IMPORT void Dump();

    // 0x44E420 | ?GetCarAudioPtr@aiVehicleOpponent@@QAEPAVmmOpponentCarAudio@@XZ
    ARTS_IMPORT class mmOpponentCarAudio* GetCarAudioPtr();

    // 0x44E3A0 | ?GetDistanceToPlayer2@aiVehicleOpponent@@QAEMXZ
    ARTS_IMPORT f32 GetDistanceToPlayer2();

    // 0x44E120 | ?GetEngineSoundIndex@aiVehicleOpponent@@QAEHXZ
    ARTS_IMPORT i32 GetEngineSoundIndex();

    // 0x44DC00 | ?Init@aiVehicleOpponent@@QAEXHPAVaiRaceData@@PAD@Z
    ARTS_IMPORT void Init(i32 arg1, class aiRaceData* arg2, char* arg3);

    // 0x44DE10 | ?Reset@aiVehicleOpponent@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x44E400 | ?SetAudioCloserMinDistMult@aiVehicleOpponent@@QAEXM@Z
    ARTS_IMPORT void SetAudioCloserMinDistMult(f32 arg1);

    // 0x44E3D0 | ?SetAudioMaxDistance@aiVehicleOpponent@@QAEXM@Z
    ARTS_IMPORT void SetAudioMaxDistance(f32 arg1);

    // 0x44E3B0 | ?SetAudioMinDistance@aiVehicleOpponent@@QAEXM@Z
    ARTS_IMPORT void SetAudioMinDistance(f32 arg1);

    // 0x44E7D0 | ?Type@aiVehicleOpponent@@UAEHXZ | inline
    ARTS_IMPORT i32 Type() override;

    // 0x44E100 | ?UnAssignSounds@aiVehicleOpponent@@QAEXXZ
    ARTS_IMPORT void UnAssignSounds();

    // 0x44DED0 | ?Update@aiVehicleOpponent@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x44E300 | ?UpdateAudio@aiVehicleOpponent@@QAEXXZ
    ARTS_IMPORT void UpdateAudio();

    // 0x44E4E0 | ?DeclareFields@aiVehicleOpponent@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // 0x44E430 | ?AddToAiAudMgr@aiVehicleOpponent@@AAEXXZ
    ARTS_IMPORT void AddToAiAudMgr();
};

check_size(aiVehicleOpponent, 0x23BC);

// 0x6A7A58 | ?aiVehicleOpponentMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass aiVehicleOpponentMetaClass;
