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

class agiPhysParameters;
class mmIntersection;
class mmPolygon;
class asInertialCS;

class asBound final : public asNode
{
public:
    // ??0asBound@@QAE@XZ
    ARTS_IMPORT asBound();

    // ??_GasBound@@UAEPAXI@Z
    // ??_EasBound@@UAEPAXI@Z
    // ??1asBound@@UAE@XZ | inline
    ARTS_EXPORT ~asBound() override = default;

    // ?GetPhysMtl@asBound@@QAEAAVagiPhysParameters@@ABVmmPolygon@@@Z
    ARTS_IMPORT agiPhysParameters& GetPhysMtl(const mmPolygon& arg1);

    // ?Impact@asBound@@QAEHPAVmmIntersection@@PAV1@HHH@Z
    ARTS_IMPORT i32 Impact(mmIntersection* arg1, asBound* arg2, i32 arg3, i32 arg4, i32 arg5);

    f32 field_20;
    f32 field_24;
    f32 field_28;
    asInertialCS* ICS;
    void (*Callback)(void*, asBound*, mmIntersection*, Vector3*, f32, Vector3*);
    void* Param;

    // Set to 9 if INST_FLAG_100 is set (see mmPhysicsMGR::CollideInstances)
    i32 AudioId;
};

check_size(asBound, 0x3C);

#ifdef ARTS_DEV_BUILD
// ?ImpactCallbackCount@@3HA
ARTS_IMPORT extern i32 ImpactCallbackCount;
#endif
