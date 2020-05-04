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

struct aiGoalRegainRail
{
    // const aiGoalRegainRail::`vftable' @ 0x61BD28

public:
    // 0x46AA20 | ??0aiGoalRegainRail@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    aiGoalRegainRail(class aiRailSet* arg1, class aiVehicleSpline* arg2);

    // 0x46AA50 | ??1aiGoalRegainRail@@QAE@XZ
    ~aiGoalRegainRail();

    // 0x46AA60 | ?Init@aiGoalRegainRail@@UAEXXZ
    virtual void Init();

    // 0x46AA80 | ?Reset@aiGoalRegainRail@@UAEXXZ
    virtual void Reset();

    // 0x46B240 | ?Context@aiGoalRegainRail@@UAEHXZ
    virtual i32 Context();

    // 0x46B260 | ?Priority@aiGoalRegainRail@@UAEHXZ
    virtual i32 Priority();

    // 0x46B130 | ?Update@aiGoalRegainRail@@UAEXXZ
    virtual void Update();

    // 0x46B270 | ?Dump@aiGoalRegainRail@@QAEXXZ
    void Dump();
};

check_size(aiGoalRegainRail, 0x28);
