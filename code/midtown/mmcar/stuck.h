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
class asInertialCS;

class mmStuck final : public asNode
{
public:
    // ??0mmStuck@@QAE@XZ
    ARTS_IMPORT mmStuck();

    // ??_GmmStuck@@UAEPAXI@Z
    // ??_EmmStuck@@UAEPAXI@Z
    // ??1mmStuck@@UAE@XZ | inline
    ARTS_EXPORT ~mmStuck() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmStuck@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Impact@mmStuck@@QAEXXZ
    ARTS_IMPORT void Impact();

    // ?Init@mmStuck@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void Init(mmCarSim* arg1);

    // ?Pegged@mmStuck@@QAEHXZ
    ARTS_IMPORT i32 Pegged();

    // ?Reset@mmStuck@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@mmStuck@@UAEXXZ
    ARTS_IMPORT void Update() override;

    i32 State;
    b32 Impacted;
    f32 StuckTime;
    Vector3 LastPosition;
    f32 TimeThresh;
    f32 PosThresh;
    f32 MoveThresh;
    f32 PosThreshSqr;
    f32 MoveThreshSqr;
    f32 RotAmount;
    asInertialCS* ICS;
    mmCarSim* CarSim;
};

check_size(mmStuck, 0x58);
