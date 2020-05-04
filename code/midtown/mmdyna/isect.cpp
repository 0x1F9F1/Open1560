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

#include "isect.h"

mmIntersection::mmIntersection()
{
    unimplemented();
}

void mmIntersection::Draw()
{
    return stub<thiscall_t<void, mmIntersection*>>(0x11A5A0_Offset, this);
}

void mmIntersection::InitSegment(
    class Vector3 const& arg1, class Vector3 const& arg2, class mmBoundTemplate* arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, mmIntersection*, class Vector3 const&, class Vector3 const&, class mmBoundTemplate*,
        i32, i32>>(0x11A1C0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void mmIntersection::InitSphere(class Vector3 const& arg1, f32 arg2, class mmBoundTemplate* arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmIntersection*, class Vector3 const&, f32, class mmBoundTemplate*, i32>>(
        0x11A3B0_Offset, this, arg1, arg2, arg3, arg4);
}

void mmIntersection::InitTransformedSegment(
    class Vector3 const& arg1, class Vector3 const& arg2, class mmBoundTemplate* arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, mmIntersection*, class Vector3 const&, class Vector3 const&, class mmBoundTemplate*,
        i32, i32>>(0x11A2D0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void mmIntersection::InitTransformedSphere(class Vector3 const& arg1, f32 arg2, class mmBoundTemplate* arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmIntersection*, class Vector3 const&, f32, class mmBoundTemplate*, i32>>(
        0x11A410_Offset, this, arg1, arg2, arg3, arg4);
}

void mmIntersection::Reset()
{
    return stub<thiscall_t<void, mmIntersection*>>(0x11A470_Offset, this);
}

void mmIntersection::Transform(class Matrix34 const* arg1)
{
    return stub<thiscall_t<void, mmIntersection*, class Matrix34 const*>>(0x11A4D0_Offset, this, arg1);
}

mmEdgeBodyIsect::mmEdgeBodyIsect()
{
    unimplemented();
}

void mmEdgeBodyIsect::Draw()
{
    return stub<thiscall_t<void, mmEdgeBodyIsect*>>(0x11A720_Offset, this);
}

void mmEdgeBodyIsect::InitSegment(
    class Vector3 const& arg1, class Vector3 const& arg2, i32 arg3, i32 arg4, class Vector3 const& arg5, f32 arg6)
{
    return stub<thiscall_t<void, mmEdgeBodyIsect*, class Vector3 const&, class Vector3 const&, i32, i32,
        class Vector3 const&, f32>>(0x11A680_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void mmEdgeBodyIsect::Reset()
{
    return stub<thiscall_t<void, mmEdgeBodyIsect*>>(0x11A660_Offset, this);
}

define_dummy_symbol(mmdyna_isect);
