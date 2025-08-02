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
    mmeffects:linespark

    0x501700 | class asSparkLut * __cdecl GetSparkLut(char *) | ?GetSparkLut@@YAPAVasSparkLut@@PAD@Z
    0x501740 | public: void __thiscall asSparkLut::Init(char *) | ?Init@asSparkLut@@QAEXPAD@Z
    0x501920 | public: void __thiscall asLineSparks::Init(int,class asSparkLut *) | ?Init@asLineSparks@@QAEXHPAVasSparkLut@@@Z
    0x501A10 | public: void __thiscall asLineSparks::AddWidgets(class Bank *) | ?AddWidgets@asLineSparks@@QAEXPAVBank@@@Z
    0x501C40 | public: void __thiscall asLineSparks::RadialBlast(int,class Vector3 &,class Vector3 &) | ?RadialBlast@asLineSparks@@QAEXHAAVVector3@@0@Z
    0x501F80 | public: void __thiscall asLineSparks::Update(void) | ?Update@asLineSparks@@QAEXXZ
    0x501FC0 | public: void __thiscall asLineSparks::Update(float) | ?Update@asLineSparks@@QAEXM@Z
    0x502190 | public: void __thiscall asLineSparks::Draw(void) | ?Draw@asLineSparks@@QAEXXZ
    0x64A0D8 | private: static unsigned int * asSparkLut::BuiltinClut | ?BuiltinClut@asSparkLut@@0PAIA
    0x719600 | class HashTable SLH | ?SLH@@3VHashTable@@A
*/

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
    ARTS_EXPORT void Init(i32 num_sparks, asSparkLut* lut);

    // ?RadialBlast@asLineSparks@@QAEXHAAVVector3@@0@Z
    ARTS_IMPORT void RadialBlast(i32 arg1, Vector3& arg2, Vector3& arg3);

    // ?Update@asLineSparks@@QAEXXZ
    ARTS_EXPORT void Update();

    // ?Update@asLineSparks@@QAEXM@Z
    ARTS_EXPORT void Update(f32 delta);

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
