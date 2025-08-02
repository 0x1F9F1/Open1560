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

#include "data7/timer.h"

class mmCar;

class aiPoliceForce final
{
public:
    // ??0aiPoliceForce@@QAE@XZ
    ARTS_EXPORT aiPoliceForce();

    // ??1aiPoliceForce@@QAE@XZ
    ARTS_EXPORT ~aiPoliceForce();

    // ?Find@aiPoliceForce@@QAEHPAVmmCar@@0@Z
    ARTS_EXPORT i32 Find(mmCar* cop, mmCar* perp);

    // ?RegisterPerp@aiPoliceForce@@QAEHPAVmmCar@@0@Z
    ARTS_EXPORT b32 RegisterPerp(mmCar* cop, mmCar* perp);

    // ?Reset@aiPoliceForce@@QAEXXZ
    ARTS_EXPORT void Reset();

    // ?State@aiPoliceForce@@QAEHPAVmmCar@@0M@Z
    ARTS_EXPORT i32 State(mmCar* cop, mmCar* perp, f32 dist);

    // ?UnRegisterCop@aiPoliceForce@@QAEHPAVmmCar@@0@Z
    ARTS_EXPORT b32 UnRegisterCop(mmCar* cop, mmCar* perp);

    // ?Update@aiPoliceForce@@QAEXXZ
    ARTS_EXPORT void Update();

private:
    static constexpr usize MaxPerps = 3;
    static constexpr usize MaxCops = 16;

    Timer last_register_;
    u16 num_perps_ {};
    u16 num_cops_[MaxPerps] {};
    mmCar* perps_[MaxPerps] {};
    mmCar* cops_[MaxPerps][MaxCops] {};
    u16 max_cops_ {};

    i32 FindPerp(mmCar* perp);
    i32 FindCop(i32 index, mmCar* cop);
};

check_size(aiPoliceForce, 0xDC);

inline aiPoliceForce::~aiPoliceForce() = default;