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
    mmai:aiGoalCollision

    0x46B2F0 | public: __thiscall aiGoalCollision::aiGoalCollision(class aiRailSet *,class aiVehicleSpline *) | ??0aiGoalCollision@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    0x46B320 | public: __thiscall aiGoalCollision::~aiGoalCollision(void) | ??1aiGoalCollision@@QAE@XZ
    0x46B330 | public: virtual void __thiscall aiGoalCollision::Init(void) | ?Init@aiGoalCollision@@UAEXXZ
    0x46B340 | public: virtual void __thiscall aiGoalCollision::Reset(void) | ?Reset@aiGoalCollision@@UAEXXZ
    0x46B350 | public: virtual void __thiscall aiGoalCollision::Update(void) | ?Update@aiGoalCollision@@UAEXXZ
    0x46B3D0 | public: virtual int __thiscall aiGoalCollision::Context(void) | ?Context@aiGoalCollision@@UAEHXZ
    0x46B3F0 | public: virtual int __thiscall aiGoalCollision::Priority(void) | ?Priority@aiGoalCollision@@UAEHXZ
    0x61BD48 | const aiGoalCollision::`vftable' | ??_7aiGoalCollision@@6B@
*/

#include "aiGoal.h"

class aiGoalCollision final : public aiGoal
{
    // const aiGoalCollision::`vftable' @ 0x61BD48

public:
    // 0x46B2F0 | ??0aiGoalCollision@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    ARTS_IMPORT aiGoalCollision(class aiRailSet* arg1, class aiVehicleSpline* arg2);

    // 0x46B320 | ??1aiGoalCollision@@QAE@XZ
    ARTS_IMPORT ~aiGoalCollision() = default;

    // 0x46B3D0 | ?Context@aiGoalCollision@@UAEHXZ
    ARTS_IMPORT i32 Context() override;

    // 0x46B330 | ?Init@aiGoalCollision@@UAEXXZ
    ARTS_IMPORT void Init() override;

    // 0x46B3F0 | ?Priority@aiGoalCollision@@UAEHXZ
    ARTS_IMPORT i32 Priority() override;

    // 0x46B340 | ?Reset@aiGoalCollision@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x46B350 | ?Update@aiGoalCollision@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap8[0x8];
};

check_size(aiGoalCollision, 0x10);
