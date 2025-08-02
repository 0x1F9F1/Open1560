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

#include "aiVehicleSpline.h"

#include "mmcar/car.h"

class aiGoalBackup;
class aiGoalChase;
class aiGoalRandomDrive;
class aiGoalStop;
class aiPath;
class aiRaceData;
class AudSound;
class mmPed;

class aiVehiclePolice final : public aiVehicleSpline
{
public:
    // ??0aiVehiclePolice@@QAE@XZ
    ARTS_IMPORT aiVehiclePolice();

    // ??_EaiVehiclePolice@@QAEPAXI@Z | unused
    // ??1aiVehiclePolice@@QAE@XZ
    ARTS_IMPORT ~aiVehiclePolice();

    // ?AssignSounds@aiVehiclePolice@@QAEXPAVAudSound@@000PAVmmOpponentImpactAudio@@0@Z
    ARTS_IMPORT void AssignSounds(
        AudSound* arg1, AudSound* arg2, AudSound* arg3, AudSound* arg4, mmOpponentImpactAudio* arg5, AudSound* arg6);

    // ?ConfigCar@aiVehiclePolice@@QAEXXZ
    ARTS_IMPORT void ConfigCar();

    // ?DrawId@aiVehiclePolice@@UAEXXZ
    ARTS_IMPORT void DrawId() override;

    // ?DrawTargetPt@aiVehiclePolice@@QAEXXZ
    ARTS_IMPORT void DrawTargetPt();

    // ?Dump@aiVehiclePolice@@QAEXXZ
    ARTS_IMPORT void Dump();

    // ?GetAudioPtr@aiVehiclePolice@@QAEPAVmmPoliceCarAudio@@XZ
    ARTS_IMPORT mmPoliceCarAudio* GetAudioPtr();

    // ?GetCarAudioPtr@aiVehiclePolice@@QAEPAVmmPoliceCarAudio@@XZ
    ARTS_IMPORT mmPoliceCarAudio* GetCarAudioPtr();

    // ?GetDistanceToPlayer2@aiVehiclePolice@@QAEMXZ
    ARTS_IMPORT f32 GetDistanceToPlayer2();

    // ?GetEngineSoundIndex@aiVehiclePolice@@QAEHXZ
    ARTS_IMPORT i32 GetEngineSoundIndex();

    // ?InPersuit@aiVehiclePolice@@QAEHXZ
    ARTS_IMPORT i32 InPersuit();

    // ?Init@aiVehiclePolice@@QAEXHPAVaiRaceData@@@Z
    ARTS_IMPORT void Init(i32 arg1, aiRaceData* arg2);

    // ?PerpEscapes@aiVehiclePolice@@QAEXE@Z
    ARTS_IMPORT void PerpEscapes(u8 arg1);

    // ?PlayVoice@aiVehiclePolice@@QAEXXZ
    ARTS_IMPORT void PlayVoice();

    // ?Reset@aiVehiclePolice@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?ResetPed@aiVehiclePolice@@QAEXXZ
    ARTS_IMPORT void ResetPed();

    // ?SetAudioCloserMinDistMult@aiVehiclePolice@@QAEXM@Z
    ARTS_IMPORT void SetAudioCloserMinDistMult(f32 arg1);

    // ?SetAudioMaxDistance@aiVehiclePolice@@QAEXM@Z
    ARTS_IMPORT void SetAudioMaxDistance(f32 arg1);

    // ?SetAudioMinDistance@aiVehiclePolice@@QAEXM@Z
    ARTS_IMPORT void SetAudioMinDistance(f32 arg1);

    // ?SetMainSirenLoop@aiVehiclePolice@@QAEXH@Z
    ARTS_IMPORT void SetMainSirenLoop(i32 arg1);

    // ?Type@aiVehiclePolice@@UAEHXZ | inline
    ARTS_IMPORT i32 Type() override;

    // ?UnAssignSounds@aiVehiclePolice@@QAEXXZ
    ARTS_IMPORT void UnAssignSounds();

    // ?Update@aiVehiclePolice@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateAudio@aiVehiclePolice@@QAEXXZ
    ARTS_IMPORT void UpdateAudio();

    mmCar Car;
    mmCar* TargetCar;
    aiRaceData* RaceData;
    aiGoalChase* ChaseGoal;
    aiGoalBackup* BackupGoal;
    aiGoalStop* StopGoal;
    aiGoalRandomDrive* RandomDriveGoal;
    mmPed* Ped;
    Vector3 TargetPt;
    i16 StopId;
    i16 BackupId;
    i16 PoliceType;
    i16 field_2412;
    i32 AudioIndexNumber;
    f32 AudioMaxDist;

private:
    // ?AddToAiAudMgr@aiVehiclePolice@@AAEXXZ
    ARTS_IMPORT void AddToAiAudMgr();

    // ?FindPerp@aiVehiclePolice@@AAEHHHPAVaiPath@@HH@Z
    ARTS_IMPORT i32 FindPerp(i32 arg1, i32 arg2, aiPath* arg3, i32 arg4, i32 arg5);
};

check_size(aiVehiclePolice, 0x241C);
