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

struct aiGoalRandomDrive : aiGoal
{
    // const aiGoalRandomDrive::`vftable' @ 0x61BAE0

public:
    // 0x45C7E0 | ??0aiGoalRandomDrive@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    aiGoalRandomDrive(class aiRailSet* arg1, class aiVehicleSpline* arg2);

    // 0x45C8A0 | ??1aiGoalRandomDrive@@QAE@XZ
    ~aiGoalRandomDrive();

    // 0x45D440 | ?Context@aiGoalRandomDrive@@UAEHXZ
    i32 Context() override;

    // 0x45F690 | ?Dump@aiGoalRandomDrive@@QAEXXZ
    void Dump();

    // 0x45C8B0 | ?Init@aiGoalRandomDrive@@UAEXXZ
    void Init() override;

    // 0x45D460 | ?Priority@aiGoalRandomDrive@@UAEHXZ
    i32 Priority() override;

    // 0x45C8D0 | ?Reset@aiGoalRandomDrive@@UAEXXZ
    void Reset() override;

    // 0x45E250 | ?SolvePosition@aiGoalRandomDrive@@QAEXAAVVector3@@M@Z | unused
    void SolvePosition(class Vector3& arg1, f32 arg2);

    // 0x45D320 | ?Update@aiGoalRandomDrive@@UAEXXZ
    void Update() override;

private:
    // 0x45DE10 | ?AnyVehiclesComingThisWay@aiGoalRandomDrive@@AAEHXZ
    i32 AnyVehiclesComingThisWay();

    // 0x45E020 | ?AvoidCollision@aiGoalRandomDrive@@AAEXPAVaiVehicleSpline@@M@Z
    void AvoidCollision(class aiVehicleSpline* arg1, f32 arg2);

    // 0x45F1A0 | ?ChangeLanes@aiGoalRandomDrive@@AAEXXZ
    void ChangeLanes();

    // 0x45DC00 | ?OkayToEnterIntersection@aiGoalRandomDrive@@AAEHXZ
    i32 OkayToEnterIntersection();

    // 0x45F0B0 | ?SolveLane@aiGoalRandomDrive@@AAEXXZ
    void SolveLane();

    // 0x45E2A0 | ?SolveRailType@aiGoalRandomDrive@@AAEXXZ
    void SolveRailType();

    // 0x45D470 | ?SolveVelocity@aiGoalRandomDrive@@AAEXXZ
    void SolveVelocity();
};

check_size(aiGoalRandomDrive, 0x14);

class aiGoal
{
    // const aiGoal::`vftable' @ 0x61BAF8

public:
    // 0x45F6F0 | ??1aiGoal@@QAE@XZ
    ~aiGoal();

    virtual void Init() = 0;

    virtual void Reset() = 0;

    virtual i32 Context() = 0;

    virtual i32 Priority() = 0;

    // 0x45F700 | ?Update@aiGoal@@UAEXXZ
    virtual void Update();
};

check_size(aiGoal, 0x0);
