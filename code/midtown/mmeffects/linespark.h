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

#include "vector7/vector3.h"

// ?SLH@@3VHashTable@@A
ARTS_IMPORT extern HashTable SLH;

class asSparkLut
{
public:
    // ?Init@asSparkLut@@QAEXPAD@Z
    ARTS_IMPORT void Init(char* path);

    u32* Colors {};
    i32 RowShift {};
    i32 Height {};

private:
    // ?BuiltinClut@asSparkLut@@0PAIA
    ARTS_IMPORT static u32 BuiltinClut[32];
};

// ?GetSparkLut@@YAPAVasSparkLut@@PAD@Z
ARTS_IMPORT asSparkLut* GetSparkLut(aconst char* path);

check_size(asSparkLut, 0xC);

struct asLineSparks
{
public:
#ifdef ARTS_DEV_BUILD
#endif

    // ?Draw@asLineSparks@@QAEXXZ
    ARTS_EXPORT void Draw();

    // ?Init@asLineSparks@@QAEXHPAVasSparkLut@@@Z
    void Init(i32 num_sparks, asSparkLut* lut);

    // ?RadialBlast@asLineSparks@@QAEXHAAVVector3@@0@Z
    ARTS_IMPORT void RadialBlast(i32 arg1, Vector3& arg2, Vector3& arg3);

    // ?Update@asLineSparks@@QAEXXZ
    ARTS_EXPORT void Update();

    // ?Update@asLineSparks@@QAEXM@Z
    void Update(f32 delta);

    i32 field_0 {};
    asSparkLut* Lut {};
    Ptr<Vector3[]> SparkStarts;
    Ptr<Vector3[]> SparkEnds;
    Ptr<Vector3[]> SparkVelocities;
    Vector3 PosVary {};
    Ptr<u8[]> SparkRows;
    Ptr<u8[]> SparkColumns;
    Ptr<u32[]> SparkColors;
    i32 NumSparks {};
    i32 NumActive {};
    f32 GroundY {};
    f32 Gravity {};
    f32 VelXZMin {};
    f32 VelXZMax {};
    f32 VelYMin {};
    f32 VelYMax {};
    f32 TrailLength {};
    f32 FadeFraction {};
    f32 SampleRate {};
    f32 FadeRate {};
};

check_size(asLineSparks, 0x5C);
