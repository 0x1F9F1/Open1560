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

#include "aiRailSet.h"
#include "mmcar/car.h"

class aiGoalBackup;
class aiGoalFollowWayPts;
class aiGoalStop;
class aiRaceData;
class AudSound;
class mmOpponentImpactAudio;

class aiVehicleOpponent final : public aiVehicle
{
public:
    // ??0aiVehicleOpponent@@QAE@XZ
    ARTS_IMPORT aiVehicleOpponent();

    // ??_EaiVehicleOpponent@@QAEPAXI@Z | unused
    // ??1aiVehicleOpponent@@QAE@XZ
    ARTS_IMPORT ~aiVehicleOpponent();

    // ?GetClass@aiVehicleOpponent@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT virtual MetaClass* GetClass();

    // ?AddWidget@aiVehicleOpponent@@QAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidget(Bank* arg1);

    // ?AssignSounds@aiVehicleOpponent@@QAEXPAVAudSound@@0PAVmmOpponentImpactAudio@@0@Z
    ARTS_IMPORT void AssignSounds(AudSound* arg1, AudSound* arg2, mmOpponentImpactAudio* arg3, AudSound* arg4);

    // ?DrawDamage@aiVehicleOpponent@@QAEXXZ | unused
    ARTS_EXPORT void DrawDamage();

    // ?DrawId@aiVehicleOpponent@@UAEXXZ
    ARTS_IMPORT void DrawId() override;

    // ?DrawTargetPt@aiVehicleOpponent@@QAEXXZ
    ARTS_IMPORT void DrawTargetPt();

    // ?Dump@aiVehicleOpponent@@QAEXXZ
    ARTS_IMPORT void Dump();

    // ?GetCarAudioPtr@aiVehicleOpponent@@QAEPAVmmOpponentCarAudio@@XZ
    ARTS_IMPORT mmOpponentCarAudio* GetCarAudioPtr();

    // ?GetDistanceToPlayer2@aiVehicleOpponent@@QAEMXZ
    ARTS_IMPORT f32 GetDistanceToPlayer2();

    // ?GetEngineSoundIndex@aiVehicleOpponent@@QAEHXZ
    ARTS_IMPORT i32 GetEngineSoundIndex();

    // ?Init@aiVehicleOpponent@@QAEXHPAVaiRaceData@@PAD@Z
    ARTS_IMPORT void Init(i32 arg1, aiRaceData* arg2, char* arg3);

    // ?Reset@aiVehicleOpponent@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetAudioCloserMinDistMult@aiVehicleOpponent@@QAEXM@Z
    ARTS_IMPORT void SetAudioCloserMinDistMult(f32 arg1);

    // ?SetAudioMaxDistance@aiVehicleOpponent@@QAEXM@Z
    ARTS_IMPORT void SetAudioMaxDistance(f32 arg1);

    // ?SetAudioMinDistance@aiVehicleOpponent@@QAEXM@Z
    ARTS_IMPORT void SetAudioMinDistance(f32 arg1);

    // ?Type@aiVehicleOpponent@@UAEHXZ | inline
    ARTS_IMPORT i32 Type() override;

    // ?UnAssignSounds@aiVehicleOpponent@@QAEXXZ
    ARTS_IMPORT void UnAssignSounds();

    // ?Update@aiVehicleOpponent@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateAudio@aiVehicleOpponent@@QAEXXZ
    ARTS_IMPORT void UpdateAudio();

    // ?DeclareFields@aiVehicleOpponent@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    mmCar Car;
    aiRailSet RailSet;
    aiGoalFollowWayPts* WayPts;
    aiGoalBackup* BackupGoal;
    aiGoalStop* StopGoal;
    i16 IsFinished;
    i16 IsStopped;
    i16 IsBackup;
    i16 IsSemi;
    i16 AudIndexNumber;
    i16 field_23B6;
    f32 MaxAudDist;

private:
    // ?AddToAiAudMgr@aiVehicleOpponent@@AAEXXZ
    ARTS_IMPORT void AddToAiAudMgr();
};

check_size(aiVehicleOpponent, 0x23BC);
