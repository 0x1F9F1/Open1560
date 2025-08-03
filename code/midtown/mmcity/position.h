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

#include "vector7/vector4.h"

struct mmPosition
{
    ConstString Message;
    Vector4 Position;
    i32 PolyCount;
    i32 FrameCount;
    i32 StateChanges;
    i32 TextureChanges;
};

class mmPositions
{
public:
    // ??0mmPositions@@QAE@XZ
    ARTS_IMPORT mmPositions();

    // ?GetCount@mmPositions@@QAEHXZ
    i32 GetCount()
    {
        return NumPositions;
    }

    // ?Init@mmPositions@@QAEXH@Z
    ARTS_IMPORT void Init(i32 arg1);

    // ?Load@mmPositions@@QAEHPAD@Z
    ARTS_IMPORT i32 Load(aconst char* arg1);

    // ?Recall@mmPositions@@QAEHHPAVMatrix34@@PAHPAD@Z
    ARTS_IMPORT i32 Recall(i32 arg1, Matrix34* arg2, i32* arg3, char* arg4);

    // ?Register@mmPositions@@QAEHAAVVector4@@HHHHPAD@Z
    ARTS_IMPORT i32 Register(
        Vector4& arg1, i32 arg2 = 0, i32 arg3 = 0, i32 arg4 = 0, i32 arg5 = 0, char* arg6 = nullptr);

    mmPosition** Positions;
    i32 NumPositions;
    i32 MaxPositions;
};

check_size(mmPositions, 0xC);
