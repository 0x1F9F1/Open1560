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
    mmai:aiGoalRandomDrive

    0x45C7E0 | public: __thiscall aiGoalRandomDrive::aiGoalRandomDrive(class aiRailSet *,class aiVehicleSpline *) | ??0aiGoalRandomDrive@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    0x45C8A0 | public: __thiscall aiGoalRandomDrive::~aiGoalRandomDrive(void) | ??1aiGoalRandomDrive@@QAE@XZ
    0x45C8B0 | public: virtual void __thiscall aiGoalRandomDrive::Init(void) | ?Init@aiGoalRandomDrive@@UAEXXZ
    0x45C8D0 | public: virtual void __thiscall aiGoalRandomDrive::Reset(void) | ?Reset@aiGoalRandomDrive@@UAEXXZ
    0x45D320 | public: virtual void __thiscall aiGoalRandomDrive::Update(void) | ?Update@aiGoalRandomDrive@@UAEXXZ
    0x45D440 | public: virtual int __thiscall aiGoalRandomDrive::Context(void) | ?Context@aiGoalRandomDrive@@UAEHXZ
    0x45D460 | public: virtual int __thiscall aiGoalRandomDrive::Priority(void) | ?Priority@aiGoalRandomDrive@@UAEHXZ
    0x45D470 | private: void __thiscall aiGoalRandomDrive::SolveVelocity(void) | ?SolveVelocity@aiGoalRandomDrive@@AAEXXZ
    0x45DC00 | private: int __thiscall aiGoalRandomDrive::OkayToEnterIntersection(void) | ?OkayToEnterIntersection@aiGoalRandomDrive@@AAEHXZ
    0x45DE10 | private: int __thiscall aiGoalRandomDrive::AnyVehiclesComingThisWay(void) | ?AnyVehiclesComingThisWay@aiGoalRandomDrive@@AAEHXZ
    0x45E020 | private: void __thiscall aiGoalRandomDrive::AvoidCollision(class aiVehicleSpline *,float) | ?AvoidCollision@aiGoalRandomDrive@@AAEXPAVaiVehicleSpline@@M@Z
    0x45E250 | public: void __thiscall aiGoalRandomDrive::SolvePosition(class Vector3 &,float) | ?SolvePosition@aiGoalRandomDrive@@QAEXAAVVector3@@M@Z
    0x45E2A0 | private: void __thiscall aiGoalRandomDrive::SolveRailType(void) | ?SolveRailType@aiGoalRandomDrive@@AAEXXZ
    0x45F0B0 | private: void __thiscall aiGoalRandomDrive::SolveLane(void) | ?SolveLane@aiGoalRandomDrive@@AAEXXZ
    0x45F1A0 | private: void __thiscall aiGoalRandomDrive::ChangeLanes(void) | ?ChangeLanes@aiGoalRandomDrive@@AAEXXZ
    0x45F690 | public: void __thiscall aiGoalRandomDrive::Dump(void) | ?Dump@aiGoalRandomDrive@@QAEXXZ
    0x45F6F0 | public: __thiscall aiGoal::~aiGoal(void) | ??1aiGoal@@QAE@XZ
    0x45F700 | public: virtual void __thiscall aiGoal::Update(void) | ?Update@aiGoal@@UAEXXZ
    0x61BAE0 | const aiGoalRandomDrive::`vftable' | ??_7aiGoalRandomDrive@@6B@
    0x61BAF8 | const aiGoal::`vftable' | ??_7aiGoal@@6B@
*/

#include "aiGoal.h"

class aiGoalRandomDrive final : public aiGoal
{
public:
    // ??0aiGoalRandomDrive@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    ARTS_IMPORT aiGoalRandomDrive(aiRailSet* arg1, aiVehicleSpline* arg2);

    // ??1aiGoalRandomDrive@@QAE@XZ
    ARTS_IMPORT ~aiGoalRandomDrive() = default;

    // ?Context@aiGoalRandomDrive@@UAEHXZ
    ARTS_IMPORT b32 Context() override;

    // ?Dump@aiGoalRandomDrive@@QAEXXZ
    ARTS_IMPORT void Dump();

    // ?Init@aiGoalRandomDrive@@UAEXXZ
    ARTS_IMPORT void Init() override;

    // ?Priority@aiGoalRandomDrive@@UAEHXZ
    ARTS_IMPORT i32 Priority() override;

    // ?Reset@aiGoalRandomDrive@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SolvePosition@aiGoalRandomDrive@@QAEXAAVVector3@@M@Z | unused
    ARTS_IMPORT void SolvePosition(Vector3& arg1, f32 arg2);

    // ?Update@aiGoalRandomDrive@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // ?AnyVehiclesComingThisWay@aiGoalRandomDrive@@AAEHXZ
    ARTS_IMPORT i32 AnyVehiclesComingThisWay();

    // ?AvoidCollision@aiGoalRandomDrive@@AAEXPAVaiVehicleSpline@@M@Z
    ARTS_IMPORT void AvoidCollision(aiVehicleSpline* arg1, f32 arg2);

    // ?ChangeLanes@aiGoalRandomDrive@@AAEXXZ
    ARTS_IMPORT void ChangeLanes();

    // ?OkayToEnterIntersection@aiGoalRandomDrive@@AAEHXZ
    ARTS_IMPORT i32 OkayToEnterIntersection();

    // ?SolveLane@aiGoalRandomDrive@@AAEXXZ
    ARTS_IMPORT void SolveLane();

    // ?SolveRailType@aiGoalRandomDrive@@AAEXXZ
    ARTS_IMPORT void SolveRailType();

    // ?SolveVelocity@aiGoalRandomDrive@@AAEXXZ
    ARTS_IMPORT void SolveVelocity();

    u8 gap8[0xC];
};

check_size(aiGoalRandomDrive, 0x14);
