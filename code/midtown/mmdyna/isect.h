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
    mmdyna:isect

    0x51A1B0 | public: __thiscall mmIntersection::mmIntersection(void) | ??0mmIntersection@@QAE@XZ
    0x51A1C0 | public: void __thiscall mmIntersection::InitSegment(class Vector3 const &,class Vector3 const &,class mmBoundTemplate *,int,int) | ?InitSegment@mmIntersection@@QAEXABVVector3@@0PAVmmBoundTemplate@@HH@Z
    0x51A2D0 | public: void __thiscall mmIntersection::InitTransformedSegment(class Vector3 const &,class Vector3 const &,class mmBoundTemplate *,int,int) | ?InitTransformedSegment@mmIntersection@@QAEXABVVector3@@0PAVmmBoundTemplate@@HH@Z
    0x51A3B0 | public: void __thiscall mmIntersection::InitSphere(class Vector3 const &,float,class mmBoundTemplate *,int) | ?InitSphere@mmIntersection@@QAEXABVVector3@@MPAVmmBoundTemplate@@H@Z
    0x51A410 | public: void __thiscall mmIntersection::InitTransformedSphere(class Vector3 const &,float,class mmBoundTemplate *,int) | ?InitTransformedSphere@mmIntersection@@QAEXABVVector3@@MPAVmmBoundTemplate@@H@Z
    0x51A470 | public: void __thiscall mmIntersection::Reset(void) | ?Reset@mmIntersection@@QAEXXZ
    0x51A4D0 | public: void __thiscall mmIntersection::Transform(class Matrix34 const *) | ?Transform@mmIntersection@@QAEXPBVMatrix34@@@Z
    0x51A5A0 | public: void __thiscall mmIntersection::Draw(void) | ?Draw@mmIntersection@@QAEXXZ
    0x51A650 | public: __thiscall mmEdgeBodyIsect::mmEdgeBodyIsect(void) | ??0mmEdgeBodyIsect@@QAE@XZ
    0x51A660 | public: void __thiscall mmEdgeBodyIsect::Reset(void) | ?Reset@mmEdgeBodyIsect@@QAEXXZ
    0x51A680 | public: void __thiscall mmEdgeBodyIsect::InitSegment(class Vector3 const &,class Vector3 const &,int,int,class Vector3 const &,float) | ?InitSegment@mmEdgeBodyIsect@@QAEXABVVector3@@0HH0M@Z
    0x51A720 | public: void __thiscall mmEdgeBodyIsect::Draw(void) | ?Draw@mmEdgeBodyIsect@@QAEXXZ
*/

class mmIntersection
{
public:
    // 0x51A1B0 | ??0mmIntersection@@QAE@XZ
    ARTS_IMPORT mmIntersection();

#ifdef ARTS_DEV_BUILD
    // 0x51A5A0 | ?Draw@mmIntersection@@QAEXXZ | unused
    ARTS_IMPORT void Draw();
#endif

    // 0x51A1C0 | ?InitSegment@mmIntersection@@QAEXABVVector3@@0PAVmmBoundTemplate@@HH@Z
    ARTS_IMPORT void InitSegment(
        class Vector3 const& arg1, class Vector3 const& arg2, class mmBoundTemplate* arg3, i32 arg4, i32 arg5);

    // 0x51A3B0 | ?InitSphere@mmIntersection@@QAEXABVVector3@@MPAVmmBoundTemplate@@H@Z | unused
    ARTS_IMPORT void InitSphere(class Vector3 const& arg1, f32 arg2, class mmBoundTemplate* arg3, i32 arg4);

    // 0x51A2D0 | ?InitTransformedSegment@mmIntersection@@QAEXABVVector3@@0PAVmmBoundTemplate@@HH@Z
    ARTS_IMPORT void InitTransformedSegment(
        class Vector3 const& arg1, class Vector3 const& arg2, class mmBoundTemplate* arg3, i32 arg4, i32 arg5);

    // 0x51A410 | ?InitTransformedSphere@mmIntersection@@QAEXABVVector3@@MPAVmmBoundTemplate@@H@Z
    ARTS_IMPORT void InitTransformedSphere(class Vector3 const& arg1, f32 arg2, class mmBoundTemplate* arg3, i32 arg4);

    // 0x51A470 | ?Reset@mmIntersection@@QAEXXZ
    ARTS_IMPORT void Reset();

    // 0x51A4D0 | ?Transform@mmIntersection@@QAEXPBVMatrix34@@@Z
    ARTS_IMPORT void Transform(class Matrix34 const* arg1);

    u8 gap0[0xB0];
};

check_size(mmIntersection, 0xB0);

class mmEdgeBodyIsect
{
public:
    // 0x51A650 | ??0mmEdgeBodyIsect@@QAE@XZ
    ARTS_IMPORT mmEdgeBodyIsect();

#ifdef ARTS_DEV_BUILD
    // 0x51A720 | ?Draw@mmEdgeBodyIsect@@QAEXXZ | unused
    ARTS_IMPORT void Draw();
#endif

    // 0x51A680 | ?InitSegment@mmEdgeBodyIsect@@QAEXABVVector3@@0HH0M@Z
    ARTS_IMPORT void InitSegment(
        class Vector3 const& arg1, class Vector3 const& arg2, i32 arg3, i32 arg4, class Vector3 const& arg5, f32 arg6);

    // 0x51A660 | ?Reset@mmEdgeBodyIsect@@QAEXXZ
    ARTS_IMPORT void Reset();

    u8 gap0[0xF4];
};

check_size(mmEdgeBodyIsect, 0xF4);
