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
    mmai:aiGoalChase

    0x45FCC0 | public: __thiscall aiGoalChase::aiGoalChase(class aiVehiclePolice *,class aiRailSet *,class mmCar * *,short *,class Vector3 *,short *) | ??0aiGoalChase@@QAE@PAVaiVehiclePolice@@PAVaiRailSet@@PAPAVmmCar@@PAFPAVVector3@@3@Z
    0x45FD70 | public: __thiscall aiGoalChase::~aiGoalChase(void) | ??1aiGoalChase@@QAE@XZ
    0x45FDC0 | public: virtual void __thiscall aiGoalChase::Init(void) | ?Init@aiGoalChase@@UAEXXZ
    0x45FED0 | public: virtual void __thiscall aiGoalChase::Reset(void) | ?Reset@aiGoalChase@@UAEXXZ
    0x460080 | public: virtual int __thiscall aiGoalChase::Context(void) | ?Context@aiGoalChase@@UAEHXZ
    0x460420 | private: int __thiscall aiGoalChase::Fov(class mmCar *) | ?Fov@aiGoalChase@@AAEHPAVmmCar@@@Z
    0x4605B0 | private: int __thiscall aiGoalChase::Speeding(class mmCar *) | ?Speeding@aiGoalChase@@AAEHPAVmmCar@@@Z
    0x460600 | private: int __thiscall aiGoalChase::Collision(class mmCar *) | ?Collision@aiGoalChase@@AAEHPAVmmCar@@@Z
    0x460620 | private: int __thiscall aiGoalChase::HitMe(class mmCar *) | ?HitMe@aiGoalChase@@AAEHPAVmmCar@@@Z
    0x460640 | private: int __thiscall aiGoalChase::Stopped(class mmCar *) | ?Stopped@aiGoalChase@@AAEHPAVmmCar@@@Z
    0x460670 | private: int __thiscall aiGoalChase::IsPerpACop(class mmCar *) | ?IsPerpACop@aiGoalChase@@AAEHPAVmmCar@@@Z
    0x460690 | private: int __thiscall aiGoalChase::OffRoad(class mmCar *) | ?OffRoad@aiGoalChase@@AAEHPAVmmCar@@@Z
    0x460760 | public: virtual int __thiscall aiGoalChase::Priority(void) | ?Priority@aiGoalChase@@UAEHXZ
    0x460770 | public: virtual void __thiscall aiGoalChase::Update(void) | ?Update@aiGoalChase@@UAEXXZ
    0x4613F0 | private: int __thiscall aiGoalChase::PlanRoute(void) | ?PlanRoute@aiGoalChase@@AAEHXZ
    0x461490 | private: int __thiscall aiGoalChase::LocatePerpFromRoad(class aiPath *,class aiPath * *,class aiPath * *) | ?LocatePerpFromRoad@aiGoalChase@@AAEHPAVaiPath@@PAPAV2@1@Z
    0x461B60 | private: int __thiscall aiGoalChase::LocatePerpFromInt(class aiIntersection *,class aiPath * *) | ?LocatePerpFromInt@aiGoalChase@@AAEHPAVaiIntersection@@PAPAVaiPath@@@Z
    0x461DC0 | private: int __thiscall aiGoalChase::FindPerp(int,int,class aiPath *) | ?FindPerp@aiGoalChase@@AAEHHHPAVaiPath@@@Z
    0x461EF0 | private: class aiVehiclePolice * __thiscall aiGoalChase::DetectCopCollision(void) | ?DetectCopCollision@aiGoalChase@@AAEPAVaiVehiclePolice@@XZ
    0x462030 | private: void __thiscall aiGoalChase::AvoidCopCollision(class aiVehiclePolice *) | ?AvoidCopCollision@aiGoalChase@@AAEXPAVaiVehiclePolice@@@Z
    0x462300 | private: void __thiscall aiGoalChase::Follow(void) | ?Follow@aiGoalChase@@AAEXXZ
    0x462430 | private: void __thiscall aiGoalChase::CalcSpeed(float) | ?CalcSpeed@aiGoalChase@@AAEXM@Z
    0x462BB0 | private: void __thiscall aiGoalChase::CloseInRoad(void) | ?CloseInRoad@aiGoalChase@@AAEXXZ
    0x463090 | private: void __thiscall aiGoalChase::CloseInOpenArea(void) | ?CloseInOpenArea@aiGoalChase@@AAEXXZ
    0x463570 | private: void __thiscall aiGoalChase::Barricade(void) | ?Barricade@aiGoalChase@@AAEXXZ
    0x463A00 | private: void __thiscall aiGoalChase::Block(void) | ?Block@aiGoalChase@@AAEXXZ
    0x463E10 | private: void __thiscall aiGoalChase::Push(void) | ?Push@aiGoalChase@@AAEXXZ
    0x464000 | private: int __thiscall aiGoalChase::DetectAmbientCollision(int *) | ?DetectAmbientCollision@aiGoalChase@@AAEHPAH@Z
    0x464F10 | private: void __thiscall aiGoalChase::AddToBlockedRange(float,float,float) | ?AddToBlockedRange@aiGoalChase@@AAEXMMM@Z
    0x4650B0 | private: void __thiscall aiGoalChase::AvoidAmbientCollision(int) | ?AvoidAmbientCollision@aiGoalChase@@AAEXH@Z
    0x465310 | private: void __thiscall aiGoalChase::ProcessCollision(int) | ?ProcessCollision@aiGoalChase@@AAEXH@Z
    0x4655D0 | public: void __thiscall aiGoalChase::Dump(void) | ?Dump@aiGoalChase@@QAEXXZ
    0x4658E0 | public: virtual __thiscall aiStuck::~aiStuck(void) | ??1aiStuck@@UAE@XZ
    0x61BC28 | const aiGoalChase::`vftable' | ??_7aiGoalChase@@6B@
*/

#include "aiGoal.h"

class aiGoalChase final : public aiGoal
{
    // const aiGoalChase::`vftable' @ 0x61BC28

public:
    // 0x45FCC0 | ??0aiGoalChase@@QAE@PAVaiVehiclePolice@@PAVaiRailSet@@PAPAVmmCar@@PAFPAVVector3@@3@Z
    ARTS_IMPORT aiGoalChase(class aiVehiclePolice* arg1, class aiRailSet* arg2, class mmCar** arg3, i16* arg4,
        class Vector3* arg5, i16* arg6);

    // 0x45FD70 | ??1aiGoalChase@@QAE@XZ
    ARTS_IMPORT ~aiGoalChase();

    // 0x460080 | ?Context@aiGoalChase@@UAEHXZ
    ARTS_IMPORT i32 Context() override;

    // 0x4655D0 | ?Dump@aiGoalChase@@QAEXXZ
    ARTS_IMPORT void Dump();

    // 0x45FDC0 | ?Init@aiGoalChase@@UAEXXZ
    ARTS_IMPORT void Init() override;

    // 0x460760 | ?Priority@aiGoalChase@@UAEHXZ
    ARTS_IMPORT i32 Priority() override;

    // 0x45FED0 | ?Reset@aiGoalChase@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x460770 | ?Update@aiGoalChase@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // 0x464F10 | ?AddToBlockedRange@aiGoalChase@@AAEXMMM@Z
    ARTS_IMPORT void AddToBlockedRange(f32 arg1, f32 arg2, f32 arg3);

    // 0x4650B0 | ?AvoidAmbientCollision@aiGoalChase@@AAEXH@Z
    ARTS_IMPORT void AvoidAmbientCollision(i32 arg1);

    // 0x462030 | ?AvoidCopCollision@aiGoalChase@@AAEXPAVaiVehiclePolice@@@Z
    ARTS_IMPORT void AvoidCopCollision(class aiVehiclePolice* arg1);

    // 0x463570 | ?Barricade@aiGoalChase@@AAEXXZ
    ARTS_IMPORT void Barricade();

    // 0x463A00 | ?Block@aiGoalChase@@AAEXXZ
    ARTS_IMPORT void Block();

    // 0x462430 | ?CalcSpeed@aiGoalChase@@AAEXM@Z
    ARTS_IMPORT void CalcSpeed(f32 arg1);

    // 0x463090 | ?CloseInOpenArea@aiGoalChase@@AAEXXZ
    ARTS_IMPORT void CloseInOpenArea();

    // 0x462BB0 | ?CloseInRoad@aiGoalChase@@AAEXXZ
    ARTS_IMPORT void CloseInRoad();

    // 0x460600 | ?Collision@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 Collision(class mmCar* arg1);

    // 0x464000 | ?DetectAmbientCollision@aiGoalChase@@AAEHPAH@Z
    ARTS_IMPORT i32 DetectAmbientCollision(i32* arg1);

    // 0x461EF0 | ?DetectCopCollision@aiGoalChase@@AAEPAVaiVehiclePolice@@XZ
    ARTS_IMPORT class aiVehiclePolice* DetectCopCollision();

    // 0x461DC0 | ?FindPerp@aiGoalChase@@AAEHHHPAVaiPath@@@Z
    ARTS_IMPORT i32 FindPerp(i32 arg1, i32 arg2, class aiPath* arg3);

    // 0x462300 | ?Follow@aiGoalChase@@AAEXXZ
    ARTS_IMPORT void Follow();

    // 0x460420 | ?Fov@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 Fov(class mmCar* arg1);

    // 0x460620 | ?HitMe@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 HitMe(class mmCar* arg1);

    // 0x460670 | ?IsPerpACop@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 IsPerpACop(class mmCar* arg1);

    // 0x461B60 | ?LocatePerpFromInt@aiGoalChase@@AAEHPAVaiIntersection@@PAPAVaiPath@@@Z
    ARTS_IMPORT i32 LocatePerpFromInt(class aiIntersection* arg1, class aiPath** arg2);

    // 0x461490 | ?LocatePerpFromRoad@aiGoalChase@@AAEHPAVaiPath@@PAPAV2@1@Z
    ARTS_IMPORT i32 LocatePerpFromRoad(class aiPath* arg1, class aiPath** arg2, class aiPath** arg3);

    // 0x460690 | ?OffRoad@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 OffRoad(class mmCar* arg1);

    // 0x4613F0 | ?PlanRoute@aiGoalChase@@AAEHXZ
    ARTS_IMPORT i32 PlanRoute();

    // 0x465310 | ?ProcessCollision@aiGoalChase@@AAEXH@Z
    ARTS_IMPORT void ProcessCollision(i32 arg1);

    // 0x463E10 | ?Push@aiGoalChase@@AAEXXZ
    ARTS_IMPORT void Push();

    // 0x4605B0 | ?Speeding@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 Speeding(class mmCar* arg1);

    // 0x460640 | ?Stopped@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 Stopped(class mmCar* arg1);

    u8 gap8[0x1A4];
};

check_size(aiGoalChase, 0x1AC);
