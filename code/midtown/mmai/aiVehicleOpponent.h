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
    ARTS_EXPORT void Init(i32 opp_id, aiRaceData* race_data, char* race_name);

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
    Ptr<aiGoalFollowWayPts> WayPts;
    Ptr<aiGoalBackup> BackupGoal;
    Ptr<aiGoalStop> StopGoal;
    b16 IsFinished;
    b16 IsStopped;
    b16 IsBackup;
    b16 IsSemi;
    i16 AudIndexNumber;
    i16 field_23B6;
    f32 MaxAudDist;

private:
    // ?AddToAiAudMgr@aiVehicleOpponent@@AAEXXZ
    ARTS_IMPORT void AddToAiAudMgr();
};

check_size(aiVehicleOpponent, 0x23BC);
