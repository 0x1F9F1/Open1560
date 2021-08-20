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
    mmcity:position

    0x491E00 | public: __thiscall mmPositions::mmPositions(void) | ??0mmPositions@@QAE@XZ
    0x491E10 | public: void __thiscall mmPositions::Init(int) | ?Init@mmPositions@@QAEXH@Z
    0x491E40 | public: int __thiscall mmPositions::Load(char *) | ?Load@mmPositions@@QAEHPAD@Z
    0x492010 | public: int __thiscall mmPositions::GetCount(void) | ?GetCount@mmPositions@@QAEHXZ
    0x492020 | public: class Vector4 & __thiscall mmPositions::GetVector4(int) | ?GetVector4@mmPositions@@QAEAAVVector4@@H@Z
    0x492050 | public: void __thiscall mmPositions::Dump(char *) | ?Dump@mmPositions@@QAEXPAD@Z
    0x4920F0 | public: int __thiscall mmPositions::Recall(int,class Matrix34 *,int *,char *) | ?Recall@mmPositions@@QAEHHPAVMatrix34@@PAHPAD@Z
    0x492180 | public: int __thiscall mmPositions::Register(class Vector4 &,int,int,int,int,char *) | ?Register@mmPositions@@QAEHAAVVector4@@HHHHPAD@Z
*/

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

    // ?Dump@mmPositions@@QAEXPAD@Z | unused
    ARTS_IMPORT void Dump(char* arg1);

    // ?GetCount@mmPositions@@QAEHXZ
    ARTS_IMPORT i32 GetCount();

    // ?GetVector4@mmPositions@@QAEAAVVector4@@H@Z | unused
    ARTS_IMPORT Vector4& GetVector4(i32 arg1);

    // ?Init@mmPositions@@QAEXH@Z
    ARTS_IMPORT void Init(i32 arg1);

    // ?Load@mmPositions@@QAEHPAD@Z
    ARTS_IMPORT i32 Load(char* arg1);

    // ?Recall@mmPositions@@QAEHHPAVMatrix34@@PAHPAD@Z
    ARTS_IMPORT i32 Recall(i32 arg1, Matrix34* arg2, i32* arg3, char* arg4);

    // ?Register@mmPositions@@QAEHAAVVector4@@HHHHPAD@Z
    ARTS_IMPORT i32 Register(Vector4& arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, char* arg6);

    mmPosition** Positions;
    i32 NumPositions;
    i32 MaxPositions;
};

check_size(mmPositions, 0xC);
