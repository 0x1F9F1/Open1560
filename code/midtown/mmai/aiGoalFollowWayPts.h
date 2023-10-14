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
    mmai:aiGoalFollowWayPts

    0x4659B0 | public: __thiscall aiGoalFollowWayPts::aiGoalFollowWayPts(void) | ??0aiGoalFollowWayPts@@QAE@XZ
    0x465A10 | public: __thiscall aiGoalFollowWayPts::aiGoalFollowWayPts(char *,class aiRailSet *,class aiVehicleOpponent *,short *,short *,short *,char *,float) | ??0aiGoalFollowWayPts@@QAE@PADPAVaiRailSet@@PAVaiVehicleOpponent@@PAF330M@Z
    0x466420 | public: __thiscall aiGoalFollowWayPts::~aiGoalFollowWayPts(void) | ??1aiGoalFollowWayPts@@QAE@XZ
    0x4664D0 | public: virtual void __thiscall aiGoalFollowWayPts::Init(void) | ?Init@aiGoalFollowWayPts@@UAEXXZ
    0x4668C0 | public: virtual int __thiscall aiGoalFollowWayPts::Context(void) | ?Context@aiGoalFollowWayPts@@UAEHXZ
    0x4669B0 | public: virtual int __thiscall aiGoalFollowWayPts::Priority(void) | ?Priority@aiGoalFollowWayPts@@UAEHXZ
    0x4669C0 | public: virtual void __thiscall aiGoalFollowWayPts::Reset(void) | ?Reset@aiGoalFollowWayPts@@UAEXXZ
    0x466AB0 | public: virtual void __thiscall aiGoalFollowWayPts::Update(void) | ?Update@aiGoalFollowWayPts@@UAEXXZ
    0x466EA0 | private: class aiVehicleOpponent * __thiscall aiGoalFollowWayPts::DetectOpponentCollision(void) | ?DetectOpponentCollision@aiGoalFollowWayPts@@AAEPAVaiVehicleOpponent@@XZ
    0x467040 | private: void __thiscall aiGoalFollowWayPts::AvoidOpponentCollision(class aiVehicleOpponent *) | ?AvoidOpponentCollision@aiGoalFollowWayPts@@AAEXPAVaiVehicleOpponent@@@Z
    0x4674B0 | private: void __thiscall aiGoalFollowWayPts::PlanRoute(void) | ?PlanRoute@aiGoalFollowWayPts@@AAEXXZ
    0x4676E0 | private: int __thiscall aiGoalFollowWayPts::LocateWayPtFromRoad(class aiPath *,class aiPath * *,class aiPath * *) | ?LocateWayPtFromRoad@aiGoalFollowWayPts@@AAEHPAVaiPath@@PAPAV2@1@Z
    0x467D60 | private: int __thiscall aiGoalFollowWayPts::LocateWayPtFromInt(class aiIntersection *,class aiPath * *) | ?LocateWayPtFromInt@aiGoalFollowWayPts@@AAEHPAVaiIntersection@@PAPAVaiPath@@@Z
    0x467E40 | private: class aiPath * __thiscall aiGoalFollowWayPts::DetRdSegBetweenInts(class aiIntersection *,class aiIntersection *) | ?DetRdSegBetweenInts@aiGoalFollowWayPts@@AAEPAVaiPath@@PAVaiIntersection@@0@Z
    0x467ED0 | private: int __thiscall aiGoalFollowWayPts::DetectCollision(int *) | ?DetectCollision@aiGoalFollowWayPts@@AAEHPAH@Z
    0x468B00 | private: void __thiscall aiGoalFollowWayPts::AddToBlockedRange(float,float,float) | ?AddToBlockedRange@aiGoalFollowWayPts@@AAEXMMM@Z
    0x468CA0 | private: void __thiscall aiGoalFollowWayPts::AvoidCollision(int) | ?AvoidCollision@aiGoalFollowWayPts@@AAEXH@Z
    0x469170 | private: void __thiscall aiGoalFollowWayPts::CalcSpeed(void) | ?CalcSpeed@aiGoalFollowWayPts@@AAEXXZ
    0x469E10 | private: void __thiscall aiGoalFollowWayPts::SolveTargetPoint(void) | ?SolveTargetPoint@aiGoalFollowWayPts@@AAEXXZ
    0x469E60 | public: void __thiscall aiGoalFollowWayPts::Dump(void) | ?Dump@aiGoalFollowWayPts@@QAEXXZ
    0x46A0E0 | public: void __thiscall aiGoalFollowWayPts::AddWidgets(class Bank *) | ?AddWidgets@aiGoalFollowWayPts@@QAEXPAVBank@@@Z
    0x46A140 | public: static void __cdecl aiGoalFollowWayPts::DeclareFields(void) | ?DeclareFields@aiGoalFollowWayPts@@SAXXZ
    0x46A2D0 | public: virtual class MetaClass * __thiscall aiGoalFollowWayPts::GetClass(void) | ?GetClass@aiGoalFollowWayPts@@UAEPAVMetaClass@@XZ
    0x46A310 | public: void * __thiscall aiGoalFollowWayPts::`vector deleting destructor'(unsigned int) | ??_EaiGoalFollowWayPts@@QAEPAXI@Z
    0x61BCD0 | const aiGoalFollowWayPts::`vftable' | ??_7aiGoalFollowWayPts@@6B@
    0x6A7C00 | class MetaClass aiGoalFollowWayPtsMetaClass | ?aiGoalFollowWayPtsMetaClass@@3VMetaClass@@A
*/

#include "data7/metadeclare.h"
#include "data7/timer.h"
#include "vector7/vector3.h"

#include "aiGoal.h"
#include "aiStuck.h"

class aiVehicleOpponent;

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
    ARTS_IMPORT i32 Priority() override;

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
    ARTS_IMPORT void AvoidCollision(i32 arg1);

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

    aiVehicleOpponent* Vehicle;
    aiRailSet* Rail;
    mmCar* Car;
    aiStuck Stuck;
    Timer Time;
    aiPath* StartLink;
    aiPath* LastLink;
    aiPath* NLastLink;

public:
    Vector3 TargetPt;

private:
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

public:
    f32 Brakes;
    f32 Throttle;
    f32 Steering;
    f32 DistToSide;

private:
    f32 Offset;
    f32 TargetPtOffset;
    f32 MaxThrottle;
    f32 NearObstacles[12][2];
    f32 FarObstacles[12][2];
};

check_size(aiGoalFollowWayPts, 0x18C);