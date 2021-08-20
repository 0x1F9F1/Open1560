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
    mmphysics:bound

    0x4DF0D0 | public: __thiscall asBound::asBound(void) | ??0asBound@@QAE@XZ
    0x4DF110 | public: int __thiscall asBound::Impact(class mmIntersection *,class asBound *,int,int,int) | ?Impact@asBound@@QAEHPAVmmIntersection@@PAV1@HHH@Z
    0x4DFAF0 | public: class agiPhysParameters & __thiscall asBound::GetPhysMtl(class mmPolygon const &) | ?GetPhysMtl@asBound@@QAEAAVagiPhysParameters@@ABVmmPolygon@@@Z
    0x4DFBE0 | public: virtual void * __thiscall asBound::`vector deleting destructor'(unsigned int) | ??_EasBound@@UAEPAXI@Z
    0x4DFBE0 | public: virtual void * __thiscall asBound::`scalar deleting destructor'(unsigned int) | ??_GasBound@@UAEPAXI@Z
    0x61FBB8 | const asBound::`vftable' | ??_7asBound@@6B@
    0x719194 | int ImpactCallbackCount | ?ImpactCallbackCount@@3HA
*/

#include "arts7/node.h"

class agiPhysParameters;
class mmIntersection;
class mmPolygon;

class asBound final : public asNode
{
public:
    // ??0asBound@@QAE@XZ
    ARTS_IMPORT asBound();

    // ??_GasBound@@UAEPAXI@Z
    // ??_EasBound@@UAEPAXI@Z
    // ??1asBound@@UAE@XZ | inline
    ARTS_IMPORT ~asBound() override = default;

    // ?GetPhysMtl@asBound@@QAEAAVagiPhysParameters@@ABVmmPolygon@@@Z
    ARTS_IMPORT agiPhysParameters& GetPhysMtl(const mmPolygon& arg1);

    // ?Impact@asBound@@QAEHPAVmmIntersection@@PAV1@HHH@Z
    ARTS_IMPORT i32 Impact(mmIntersection* arg1, asBound* arg2, i32 arg3, i32 arg4, i32 arg5);

    u8 gap20[0x1C];
};

check_size(asBound, 0x3C);

#ifdef ARTS_DEV_BUILD
// ?ImpactCallbackCount@@3HA
ARTS_IMPORT extern i32 ImpactCallbackCount;
#endif
