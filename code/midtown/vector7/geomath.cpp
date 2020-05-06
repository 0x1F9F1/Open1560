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

define_dummy_symbol(vector7_geomath);

#include "geomath.h"

i32 CollideTri(class Vector3 const& arg1, class Vector3 const& arg2, class Vector3 const& arg3,
    class Vector3 const& arg4, class Vector3 const& arg5, f32& arg6, class Vector3& arg7, class Vector3& arg8)
{
    return stub<cdecl_t<i32, class Vector3 const&, class Vector3 const&, class Vector3 const&, class Vector3 const&,
        class Vector3 const&, f32&, class Vector3&, class Vector3&>>(
        0x571D50, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

void ComputeMirrorMatrix(class Matrix34& arg1, class Vector4& arg2)
{
    return stub<cdecl_t<void, class Matrix34&, class Vector4&>>(0x572360, arg1, arg2);
}

void ComputeShadowMatrix(class Matrix34& arg1, class Vector4& arg2)
{
    return stub<cdecl_t<void, class Matrix34&, class Vector4&>>(0x572430, arg1, arg2);
}

void GetBoundInfo(
    i32 arg1, class Vector3* arg2, class Vector3* arg3, class Vector3* arg4, class Vector3* arg5, f32* arg6)
{
    return stub<cdecl_t<void, i32, class Vector3*, class Vector3*, class Vector3*, class Vector3*, f32*>>(
        0x571790, arg1, arg2, arg3, arg4, arg5, arg6);
}

class Vector4 GetBoundSphere(i32 arg1, class Vector3* arg2)
{
    return stub<cdecl_t<class Vector4, i32, class Vector3*>>(0x571730, arg1, arg2);
}

i32 IsQuadCoplanar(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4)
{
    return stub<cdecl_t<i32, class Vector3&, class Vector3&, class Vector3&, class Vector3&>>(
        0x572210, arg1, arg2, arg3, arg4);
}
