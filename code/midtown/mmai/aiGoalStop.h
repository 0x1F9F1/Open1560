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
    mmai:aiGoalStop

    0x45F710 | public: __thiscall aiGoalStop::aiGoalStop(class mmCar *,short *) | ??0aiGoalStop@@QAE@PAVmmCar@@PAF@Z
    0x45F740 | public: __thiscall aiGoalStop::~aiGoalStop(void) | ??1aiGoalStop@@QAE@XZ
    0x45F750 | public: virtual void __thiscall aiGoalStop::Init(void) | ?Init@aiGoalStop@@UAEXXZ
    0x45F760 | public: virtual void __thiscall aiGoalStop::Reset(void) | ?Reset@aiGoalStop@@UAEXXZ
    0x45F770 | public: virtual void __thiscall aiGoalStop::Update(void) | ?Update@aiGoalStop@@UAEXXZ
    0x45F7D0 | public: virtual int __thiscall aiGoalStop::Context(void) | ?Context@aiGoalStop@@UAEHXZ
    0x45F7F0 | public: virtual int __thiscall aiGoalStop::Priority(void) | ?Priority@aiGoalStop@@UAEHXZ
    0x61BB18 | const aiGoalStop::`vftable' | ??_7aiGoalStop@@6B@
*/

#include "aiGoal.h"

class aiGoalStop final : public aiGoal
{
public:
    // ??0aiGoalStop@@QAE@PAVmmCar@@PAF@Z
    ARTS_IMPORT aiGoalStop(mmCar* arg1, i16* arg2);

    // ??1aiGoalStop@@QAE@XZ
    ARTS_IMPORT ~aiGoalStop() = default;

    // ?Context@aiGoalStop@@UAEHXZ
    ARTS_IMPORT b32 Context() override;

    // ?Init@aiGoalStop@@UAEXXZ
    ARTS_IMPORT void Init() override;

    // ?Priority@aiGoalStop@@UAEHXZ
    ARTS_IMPORT i32 Priority() override;

    // ?Reset@aiGoalStop@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?Update@aiGoalStop@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap8[0x8];
};

check_size(aiGoalStop, 0x10);
