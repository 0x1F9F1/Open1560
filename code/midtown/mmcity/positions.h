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

// ?DumpPositions@@YAXPAD@Z
ARTS_IMPORT void DumpPositions(aconst char* arg1);

// ?GetPositionCount@@YAHXZ
ARTS_IMPORT i32 GetPositionCount();

// ?GetPositionVector4@@YAAAVVector4@@H@Z
ARTS_IMPORT Vector4& GetPositionVector4(i32 arg1);

// ?InitPositions@@YAXXZ
ARTS_IMPORT void InitPositions();

// ?LoadPositions@@YAXPAD@Z
ARTS_IMPORT void LoadPositions(aconst char* arg1);

// ?RecallPosition@@YAHHPAVMatrix34@@PAHPAD@Z
ARTS_IMPORT i32 RecallPosition(i32 arg1, Matrix34* arg2, i32* arg3, char* arg4);

// ?RegisterPosition@@YAHAAVVector4@@HHHHPAD@Z
ARTS_IMPORT i32 RegisterPosition(Vector4& arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, char* arg6);

// ?DontClearPositions@@3HA
ARTS_IMPORT extern b32 DontClearPositions;

struct position_t
{
public:
    // ??1position_t@@QAE@XZ | inline
    ARTS_IMPORT ~position_t();

    u8 gap0[0x24];
};

check_size(position_t, 0x24);
