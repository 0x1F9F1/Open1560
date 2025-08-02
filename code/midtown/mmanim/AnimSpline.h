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

class mmAnimSpline final : public asNode
{
public:
    // ??0mmAnimSpline@@QAE@XZ
    ARTS_IMPORT mmAnimSpline();

    // ??_EmmAnimSpline@@UAEPAXI@Z
    // ??_GmmAnimSpline@@UAEPAXI@Z | unused
    // ??1mmAnimSpline@@UAE@XZ
    ARTS_IMPORT ~mmAnimSpline() override;

    // ?AddVector@mmAnimSpline@@QAEXAAVVector3@@@Z
    ARTS_IMPORT void AddVector(Vector3& arg1);

    // ?AirlinerSwap@mmAnimSpline@@QAEXXZ
    ARTS_IMPORT void AirlinerSwap();

    // ?ClearVectors@mmAnimSpline@@QAEXXZ
    ARTS_IMPORT void ClearVectors();

    // ?Init@mmAnimSpline@@QAEHPADH@Z
    ARTS_IMPORT i32 Init(char* arg1, i32 arg2);

    // ?InitBoat@mmAnimSpline@@QAEHXZ
    ARTS_EXPORT i32 InitBoat();

    // ?InitPlane@mmAnimSpline@@QAEHXZ
    ARTS_IMPORT i32 InitPlane();

    // ?InitTrain@mmAnimSpline@@QAEHXZ
    ARTS_IMPORT i32 InitTrain();

    // ?LoadFile@mmAnimSpline@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadFile(char* arg1);

    // ?Reset@mmAnimSpline@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?UFOSwap@mmAnimSpline@@QAEXXZ
    ARTS_IMPORT void UFOSwap();

    // ?Update@mmAnimSpline@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x14];
};

check_size(mmAnimSpline, 0x34);
