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

class asInertialCS;

class asNetObject : public asNode
{
public:
    // ??0asNetObject@@QAE@XZ
    ARTS_IMPORT asNetObject();

    // ??_GasNetObject@@UAEPAXI@Z
    // ??_EasNetObject@@UAEPAXI@Z
    // ??1asNetObject@@UAE@XZ
    ARTS_EXPORT ~asNetObject() override = default;

    virtual void SetLocalData() = 0;

    // ?PositionUpdate@asNetObject@@UAEXPAVMatrix34@@VVector3@@MMM@Z
    ARTS_IMPORT virtual void PositionUpdate(Matrix34* arg1, Vector3 arg2, f32 arg3, f32 arg4, f32 arg5);

    // ?Update@asNetObject@@UAEXXZ
    ARTS_IMPORT void Update() override;

    ulong PlayerID;
    asInertialCS* ICS;
};

check_size(asNetObject, 0x28);
