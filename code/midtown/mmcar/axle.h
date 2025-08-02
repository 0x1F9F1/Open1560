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

#include "arts7/linear.h"

class mmWheel;

class mmAxle final : public asLinearCS
{
public:
    // ??0mmAxle@@QAE@XZ
    ARTS_EXPORT mmAxle() = default;

    // ??_EmmAxle@@UAEPAXI@Z
    // ??1mmAxle@@UAE@XZ | inline
    ARTS_EXPORT ~mmAxle() override = default;

    // ?Init@mmAxle@@QAEXPAD0PAVmmWheel@@1@Z
    ARTS_EXPORT void Init(char* veh_name, char* axle_name, mmWheel* left_wheel, mmWheel* right_wheel);

    // ?Update@mmAxle@@UAEXXZ
    ARTS_EXPORT void Update() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmAxle@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* bank) override;
#endif

    VIRTUAL_META_DECLARE;

    Vector3 Center {};
    mmWheel* WheelL {};
    mmWheel* WheelR {};
};

check_size(mmAxle, 0x9C);
