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

struct aiGoalStop
{
    // const aiGoalStop::`vftable' @ 0x61BB18

public:
    // 0x45F710 | ??0aiGoalStop@@QAE@PAVmmCar@@PAF@Z
    aiGoalStop(class mmCar* arg1, i16* arg2);

    // 0x45F740 | ??1aiGoalStop@@QAE@XZ
    ~aiGoalStop();

    // 0x45F750 | ?Init@aiGoalStop@@UAEXXZ
    virtual void Init();

    // 0x45F760 | ?Reset@aiGoalStop@@UAEXXZ
    virtual void Reset();

    // 0x45F7D0 | ?Context@aiGoalStop@@UAEHXZ
    virtual i32 Context();

    // 0x45F7F0 | ?Priority@aiGoalStop@@UAEHXZ
    virtual i32 Priority();

    // 0x45F770 | ?Update@aiGoalStop@@UAEXXZ
    virtual void Update();
};

check_size(aiGoalStop, 0x10);
