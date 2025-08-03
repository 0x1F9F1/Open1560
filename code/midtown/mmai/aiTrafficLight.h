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
#include "mmbangers/banger.h"

class aiIntersection;

class aiTrafficLightSet final : public asNode
{
public:
    // ??0aiTrafficLightSet@@QAE@PAVaiIntersection@@@Z
    ARTS_IMPORT aiTrafficLightSet(aiIntersection* arg1);

    // ??1aiTrafficLightSet@@UAE@XZ
    ARTS_IMPORT ~aiTrafficLightSet() override;

    // ?Reset@aiTrafficLightSet@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@aiTrafficLightSet@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // ?ObjCount@aiTrafficLightSet@@0FA
    ARTS_IMPORT static i16 ObjCount;

    u8 gap20[0x18];
};

check_size(aiTrafficLightSet, 0x38);

class aiTrafficLightInstance final : public mmUnhitBangerInstance
{
public:
    // ??1aiTrafficLightInstance@@UAE@XZ | inline
    ARTS_EXPORT ~aiTrafficLightInstance() override = default;

    // ?Draw@aiTrafficLightInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?Init@aiTrafficLightInstance@@UAEHPADAAVVector3@@1H0@Z
    ARTS_IMPORT b32 Init(aconst char* name, Vector3& pos1, Vector3& pos2, i32 init_flags, aconst char* part) override;

    u8 gap30[0x4];
};

check_size(aiTrafficLightInstance, 0x34);
