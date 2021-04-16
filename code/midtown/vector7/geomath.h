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
    vector7:geomath

    0x571730 | class Vector4 __cdecl GetBoundSphere(int,class Vector3 *) | ?GetBoundSphere@@YA?AVVector4@@HPAVVector3@@@Z
    0x571790 | void __cdecl GetBoundInfo(int,class Vector3 *,class Vector3 *,class Vector3 *,class Vector3 *,float *) | ?GetBoundInfo@@YAXHPAVVector3@@000PAM@Z
    0x571D50 | int __cdecl CollideTri(class Vector3 const &,class Vector3 const &,class Vector3 const &,class Vector3 const &,class Vector3 const &,float &,class Vector3 &,class Vector3 &) | ?CollideTri@@YAHABVVector3@@0000AAMAAV1@2@Z
    0x572210 | int __cdecl IsQuadCoplanar(class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &) | ?IsQuadCoplanar@@YAHAAVVector3@@000@Z
    0x572360 | void __cdecl ComputeMirrorMatrix(class Matrix34 &,class Vector4 &) | ?ComputeMirrorMatrix@@YAXAAVMatrix34@@AAVVector4@@@Z
    0x572430 | void __cdecl ComputeShadowMatrix(class Matrix34 &,class Vector4 &) | ?ComputeShadowMatrix@@YAXAAVMatrix34@@AAVVector4@@@Z
    0x5724D0 | public: void __thiscall Vector3::Neg(class Vector3 const &) | ?Neg@Vector3@@QAEXABV1@@Z
    0x5724F0 | public: void __thiscall Vector3::Cross(class Vector3 const &,class Vector3 const &) | ?Cross@Vector3@@QAEXABV1@0@Z
    0x65A4E0 | float QuadCoplanarTolerance | ?QuadCoplanarTolerance@@3MA
*/

// 0x571D50 | ?CollideTri@@YAHABVVector3@@0000AAMAAV1@2@Z | unused
ARTS_IMPORT i32 CollideTri(class Vector3 const& arg1, class Vector3 const& arg2, class Vector3 const& arg3,
    class Vector3 const& arg4, class Vector3 const& arg5, f32& arg6, class Vector3& arg7, class Vector3& arg8);

// 0x572360 | ?ComputeMirrorMatrix@@YAXAAVMatrix34@@AAVVector4@@@Z | unused
ARTS_IMPORT void ComputeMirrorMatrix(class Matrix34& arg1, class Vector4& arg2);

// 0x572430 | ?ComputeShadowMatrix@@YAXAAVMatrix34@@AAVVector4@@@Z
ARTS_IMPORT void ComputeShadowMatrix(class Matrix34& arg1, class Vector4& arg2);

// 0x571790 | ?GetBoundInfo@@YAXHPAVVector3@@000PAM@Z
ARTS_IMPORT void GetBoundInfo(i32 vert_count, class Vector3* vertices, class Vector3* out_min, class Vector3* out_max,
    class Vector3* out_center, f32* out_mag);

// 0x571730 | ?GetBoundSphere@@YA?AVVector4@@HPAVVector3@@@Z | unused
ARTS_IMPORT class Vector4 GetBoundSphere(i32 arg1, class Vector3* arg2);

// 0x572210 | ?IsQuadCoplanar@@YAHAAVVector3@@000@Z
ARTS_IMPORT i32 IsQuadCoplanar(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4);

// 0x65A4E0 | ?QuadCoplanarTolerance@@3MA
ARTS_IMPORT extern f32 QuadCoplanarTolerance;
