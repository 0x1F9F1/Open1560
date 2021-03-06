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

#include "aiGoal.h"

class aiGoalFollowWayPts final : public aiGoal
{
    // const aiGoalFollowWayPts::`vftable' @ 0x61BCD0

public:
    // 0x4659B0 | ??0aiGoalFollowWayPts@@QAE@XZ
    ARTS_IMPORT aiGoalFollowWayPts();

    // 0x465A10 | ??0aiGoalFollowWayPts@@QAE@PADPAVaiRailSet@@PAVaiVehicleOpponent@@PAF330M@Z
    ARTS_IMPORT aiGoalFollowWayPts(char* arg1, class aiRailSet* arg2, class aiVehicleOpponent* arg3, i16* arg4,
        i16* arg5, i16* arg6, char* arg7, f32 arg8);

    // 0x46A310 | ??_EaiGoalFollowWayPts@@QAEPAXI@Z | unused
    // 0x466420 | ??1aiGoalFollowWayPts@@QAE@XZ
    ARTS_IMPORT ~aiGoalFollowWayPts();

    // 0x46A2D0 | ?GetClass@aiGoalFollowWayPts@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT virtual class MetaClass* GetClass();

    // 0x46A0E0 | ?AddWidgets@aiGoalFollowWayPts@@QAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1);

    // 0x4668C0 | ?Context@aiGoalFollowWayPts@@UAEHXZ
    ARTS_IMPORT i32 Context() override;

    // 0x469E60 | ?Dump@aiGoalFollowWayPts@@QAEXXZ
    ARTS_IMPORT void Dump();

    // 0x4664D0 | ?Init@aiGoalFollowWayPts@@UAEXXZ
    ARTS_IMPORT void Init() override;

    // 0x4669B0 | ?Priority@aiGoalFollowWayPts@@UAEHXZ
    ARTS_IMPORT i32 Priority() override;

    // 0x4669C0 | ?Reset@aiGoalFollowWayPts@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x466AB0 | ?Update@aiGoalFollowWayPts@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x46A140 | ?DeclareFields@aiGoalFollowWayPts@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // 0x468B00 | ?AddToBlockedRange@aiGoalFollowWayPts@@AAEXMMM@Z
    ARTS_IMPORT void AddToBlockedRange(f32 arg1, f32 arg2, f32 arg3);

    // 0x468CA0 | ?AvoidCollision@aiGoalFollowWayPts@@AAEXH@Z
    ARTS_IMPORT void AvoidCollision(i32 arg1);

    // 0x467040 | ?AvoidOpponentCollision@aiGoalFollowWayPts@@AAEXPAVaiVehicleOpponent@@@Z
    ARTS_IMPORT void AvoidOpponentCollision(class aiVehicleOpponent* arg1);

    // 0x469170 | ?CalcSpeed@aiGoalFollowWayPts@@AAEXXZ
    ARTS_IMPORT void CalcSpeed();

    // 0x467E40 | ?DetRdSegBetweenInts@aiGoalFollowWayPts@@AAEPAVaiPath@@PAVaiIntersection@@0@Z
    ARTS_IMPORT class aiPath* DetRdSegBetweenInts(class aiIntersection* arg1, class aiIntersection* arg2);

    // 0x467ED0 | ?DetectCollision@aiGoalFollowWayPts@@AAEHPAH@Z
    ARTS_IMPORT i32 DetectCollision(i32* arg1);

    // 0x466EA0 | ?DetectOpponentCollision@aiGoalFollowWayPts@@AAEPAVaiVehicleOpponent@@XZ
    ARTS_IMPORT class aiVehicleOpponent* DetectOpponentCollision();

    // 0x467D60 | ?LocateWayPtFromInt@aiGoalFollowWayPts@@AAEHPAVaiIntersection@@PAPAVaiPath@@@Z
    ARTS_IMPORT i32 LocateWayPtFromInt(class aiIntersection* arg1, class aiPath** arg2);

    // 0x4676E0 | ?LocateWayPtFromRoad@aiGoalFollowWayPts@@AAEHPAVaiPath@@PAPAV2@1@Z
    ARTS_IMPORT i32 LocateWayPtFromRoad(class aiPath* arg1, class aiPath** arg2, class aiPath** arg3);

    // 0x4674B0 | ?PlanRoute@aiGoalFollowWayPts@@AAEXXZ
    ARTS_IMPORT void PlanRoute();

    // 0x469E10 | ?SolveTargetPoint@aiGoalFollowWayPts@@AAEXXZ
    ARTS_IMPORT void SolveTargetPoint();

    u8 gap8[0x184];
};

check_size(aiGoalFollowWayPts, 0x18C);

// 0x6A7C00 | ?aiGoalFollowWayPtsMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass aiGoalFollowWayPtsMetaClass;
