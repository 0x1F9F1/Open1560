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

#include "arts7/node.h"
#include "vector7/vector3.h"

class mmCarSim;

class aiStuck final : public asNode
{
public:
    // ??0aiStuck@@QAE@XZ
    ARTS_IMPORT aiStuck();

    // ??_GaiStuck@@UAEPAXI@Z
    // ??_EaiStuck@@UAEPAXI@Z
    // ??1aiStuck@@UAE@XZ | inline
    ARTS_EXPORT ~aiStuck() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@aiStuck@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Init@aiStuck@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void Init(mmCarSim* arg1);

    // ?Pegged@aiStuck@@QAEHXZ
    ARTS_IMPORT i32 Pegged();

    // ?Reset@aiStuck@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@aiStuck@@UAEXXZ
    ARTS_IMPORT void Update() override;

    i32 State;
    i32 Impacted;
    i32 field_28;
    Vector3 field_2C;
    i32 TimeThresh;
    i32 PosThresh;
    i32 MoveThresh;
    i32 PosThreshSqr;
    i32 MoveThreshSqr;
    i32 RotAmount;
    i32* ICS;
    mmCarSim* CarSim;
};

check_size(aiStuck, 0x58);
