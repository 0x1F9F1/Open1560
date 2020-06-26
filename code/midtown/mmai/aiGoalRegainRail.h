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
    mmai:aiGoalRegainRail

    0x46AA20 | public: __thiscall aiGoalRegainRail::aiGoalRegainRail(class aiRailSet *,class aiVehicleSpline *) | ??0aiGoalRegainRail@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    0x46AA50 | public: __thiscall aiGoalRegainRail::~aiGoalRegainRail(void) | ??1aiGoalRegainRail@@QAE@XZ
    0x46AA60 | public: virtual void __thiscall aiGoalRegainRail::Init(void) | ?Init@aiGoalRegainRail@@UAEXXZ
    0x46AA80 | public: virtual void __thiscall aiGoalRegainRail::Reset(void) | ?Reset@aiGoalRegainRail@@UAEXXZ
    0x46B130 | public: virtual void __thiscall aiGoalRegainRail::Update(void) | ?Update@aiGoalRegainRail@@UAEXXZ
    0x46B240 | public: virtual int __thiscall aiGoalRegainRail::Context(void) | ?Context@aiGoalRegainRail@@UAEHXZ
    0x46B260 | public: virtual int __thiscall aiGoalRegainRail::Priority(void) | ?Priority@aiGoalRegainRail@@UAEHXZ
    0x46B270 | public: void __thiscall aiGoalRegainRail::Dump(void) | ?Dump@aiGoalRegainRail@@QAEXXZ
    0x61BD28 | const aiGoalRegainRail::`vftable' | ??_7aiGoalRegainRail@@6B@
*/

#include "aiGoalRandomDrive.h"

struct aiGoalRegainRail : aiGoal
{
    // const aiGoalRegainRail::`vftable' @ 0x61BD28

public:
    // 0x46AA20 | ??0aiGoalRegainRail@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    ARTS_IMPORT aiGoalRegainRail(class aiRailSet* arg1, class aiVehicleSpline* arg2);

    // 0x46AA50 | ??1aiGoalRegainRail@@QAE@XZ
    ARTS_IMPORT ~aiGoalRegainRail();

    // 0x46B240 | ?Context@aiGoalRegainRail@@UAEHXZ
    ARTS_IMPORT i32 Context() override;

    // 0x46B270 | ?Dump@aiGoalRegainRail@@QAEXXZ
    ARTS_IMPORT void Dump();

    // 0x46AA60 | ?Init@aiGoalRegainRail@@UAEXXZ
    ARTS_IMPORT void Init() override;

    // 0x46B260 | ?Priority@aiGoalRegainRail@@UAEHXZ
    ARTS_IMPORT i32 Priority() override;

    // 0x46AA80 | ?Reset@aiGoalRegainRail@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x46B130 | ?Update@aiGoalRegainRail@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap8[0x20];
};

check_size(aiGoalRegainRail, 0x28);
