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

class mmBoundTemplate;
class mmPolygon;

class mmIntersection
{
public:
    // ??0mmIntersection@@QAE@XZ
    ARTS_IMPORT mmIntersection();

#ifdef ARTS_DEV_BUILD
#endif

    // ?InitSegment@mmIntersection@@QAEXABVVector3@@0PAVmmBoundTemplate@@HH@Z
    ARTS_IMPORT void InitSegment(const Vector3& arg1, const Vector3& arg2, mmBoundTemplate* arg3, i32 arg4, i32 arg5);

    // ?InitTransformedSegment@mmIntersection@@QAEXABVVector3@@0PAVmmBoundTemplate@@HH@Z
    ARTS_IMPORT void InitTransformedSegment(
        const Vector3& arg1, const Vector3& arg2, mmBoundTemplate* arg3, i32 arg4, i32 arg5);

    // ?InitTransformedSphere@mmIntersection@@QAEXABVVector3@@MPAVmmBoundTemplate@@H@Z
    ARTS_IMPORT void InitTransformedSphere(const Vector3& arg1, f32 arg2, mmBoundTemplate* arg3, i32 arg4);

    // ?Reset@mmIntersection@@QAEXXZ
    ARTS_IMPORT void Reset();

    // ?Transform@mmIntersection@@QAEXPBVMatrix34@@@Z
    ARTS_IMPORT void Transform(const Matrix34* arg1);

    i32 Type;
    i32 field_4;
    mmBoundTemplate* BoundTemplate;
    Vector3 Center;
    Vector3 LocalCenter;
    f32 Radius;
    f32 RadiusSqr;
    Vector3 Min;
    Vector3 Max;
    Vector3 LocalMin;
    Vector3 LocalMax;
    Vector3 Size;
    f32 MagnitudeSqr;
    f32 field_6C;
    i32 field_70;
    f32 field_74;
    f32 field_78;
    f32 field_7C;
    Vector3 Position;
    Vector3 Normal;
    i32 field_98;
    i32 field_9C;
    i32 field_A0;
    mmPolygon* HitPoly;
    i32 field_A8;
    u8* field_AC;
};

check_size(mmIntersection, 0xB0);

class mmEdgeBodyIsect
{
public:
    // ??0mmEdgeBodyIsect@@QAE@XZ
    ARTS_IMPORT mmEdgeBodyIsect();

#ifdef ARTS_DEV_BUILD
#endif

    // ?InitSegment@mmEdgeBodyIsect@@QAEXABVVector3@@0HH0M@Z
    ARTS_IMPORT void InitSegment(
        const Vector3& arg1, const Vector3& arg2, i32 arg3, i32 arg4, const Vector3& arg5, f32 arg6);

    // ?Reset@mmEdgeBodyIsect@@QAEXXZ
    ARTS_IMPORT void Reset();

    u8 gap0[0xF4];
};

check_size(mmEdgeBodyIsect, 0xF4);
