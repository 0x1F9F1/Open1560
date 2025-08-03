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

#include "data7/metadeclare.h"
#include "data7/timer.h"
#include "vector7/vector3.h"

#include "aiGoal.h"
#include "aiStuck.h"

class aiIntersection;
class aiPath;
class aiRailSet;
class aiVehicleOpponent;
class mmCar;

class aiGoalFollowWayPts final : public aiGoal
{
public:
    // ??0aiGoalFollowWayPts@@QAE@XZ
    ARTS_IMPORT aiGoalFollowWayPts();

    // ??0aiGoalFollowWayPts@@QAE@PADPAVaiRailSet@@PAVaiVehicleOpponent@@PAF330M@Z
    ARTS_IMPORT aiGoalFollowWayPts(char* pathfile, aiRailSet* railset, aiVehicleOpponent* vehicle_opponent,
        b16* is_backup, b16* is_finished, b16* is_stopped, aconst char* race_name, f32 max_throttle);

    // ??_EaiGoalFollowWayPts@@QAEPAXI@Z | unused
    // ??1aiGoalFollowWayPts@@QAE@XZ
    ARTS_IMPORT ~aiGoalFollowWayPts();

    // ?GetClass@aiGoalFollowWayPts@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT virtual MetaClass* GetClass();

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@aiGoalFollowWayPts@@QAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1);
#endif

    // ?Context@aiGoalFollowWayPts@@UAEHXZ
    ARTS_EXPORT b32 Context() override;

    // ?Dump@aiGoalFollowWayPts@@QAEXXZ
    ARTS_IMPORT void Dump();

    // ?Init@aiGoalFollowWayPts@@UAEXXZ
    ARTS_IMPORT void Init() override;

    // ?Priority@aiGoalFollowWayPts@@UAEHXZ
    ARTS_IMPORT b32 Priority() override;

    // ?Reset@aiGoalFollowWayPts@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@aiGoalFollowWayPts@@UAEXXZ
    ARTS_EXPORT void Update() override;

    // ?DeclareFields@aiGoalFollowWayPts@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?AddToBlockedRange@aiGoalFollowWayPts@@AAEXMMM@Z
    ARTS_IMPORT void AddToBlockedRange(f32 arg1, f32 arg2, f32 arg3);

    // ?AvoidCollision@aiGoalFollowWayPts@@AAEXH@Z
    ARTS_IMPORT void AvoidCollision(i32 dist_to_side);

    // ?AvoidOpponentCollision@aiGoalFollowWayPts@@AAEXPAVaiVehicleOpponent@@@Z
    ARTS_IMPORT void AvoidOpponentCollision(aiVehicleOpponent* arg1);

    // ?CalcSpeed@aiGoalFollowWayPts@@AAEXXZ
    ARTS_IMPORT void CalcSpeed();

    // ?DetRdSegBetweenInts@aiGoalFollowWayPts@@AAEPAVaiPath@@PAVaiIntersection@@0@Z
    ARTS_IMPORT aiPath* DetRdSegBetweenInts(aiIntersection* arg1, aiIntersection* arg2);

    // ?DetectCollision@aiGoalFollowWayPts@@AAEHPAH@Z
    ARTS_IMPORT i32 DetectCollision(i32* arg1);

    // ?DetectOpponentCollision@aiGoalFollowWayPts@@AAEPAVaiVehicleOpponent@@XZ
    ARTS_IMPORT aiVehicleOpponent* DetectOpponentCollision();

    // ?LocateWayPtFromInt@aiGoalFollowWayPts@@AAEHPAVaiIntersection@@PAPAVaiPath@@@Z
    ARTS_IMPORT i32 LocateWayPtFromInt(aiIntersection* arg1, aiPath** arg2);

    // ?LocateWayPtFromRoad@aiGoalFollowWayPts@@AAEHPAVaiPath@@PAPAV2@1@Z
    ARTS_IMPORT i32 LocateWayPtFromRoad(aiPath* arg1, aiPath** arg2, aiPath** arg3);

    // ?PlanRoute@aiGoalFollowWayPts@@AAEXXZ
    ARTS_IMPORT void PlanRoute();

    // ?SolveTargetPoint@aiGoalFollowWayPts@@AAEXXZ
    ARTS_IMPORT void SolveTargetPoint();

    i32 GetWayPtId(i16 index);

public:
    aiVehicleOpponent* Vehicle;
    aiRailSet* Rail;
    mmCar* Car;
    aiStuck Stuck;
    Timer Time;
    aiPath* StartLink;
    aiPath* LastLink;
    aiPath* NLastLink;
    Vector3 TargetPt;
    i16* WayPtIds;
    b16* BackingUp;
    b16* IsFinished;
    b16* IsStopped;
    i16 NumWayPts;
    i16 WayPtIdx;
    i16 LastMapCompType;
    i16 CurMapCompType;
    i16 CurMapCompIdx;
    i16 CurRdVertIdx;
    i16 CurLap;
    i16 State;
    i16 NumCloseObstacles;
    i16 NumFarObstacles;
    i16 DamageState;
    f32 Brakes;
    f32 Throttle;
    f32 Steering;
    f32 DistToSide;
    f32 Offset;
    f32 TargetPtOffset;
    f32 MaxThrottle;
    f32 NearObstacles[12][2];
    f32 FarObstacles[12][2];
};

check_size(aiGoalFollowWayPts, 0x18C);