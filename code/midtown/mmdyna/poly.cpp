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

#include "poly.h"

mmPolygon::mmPolygon()
{
    unimplemented();
}

f32 mmPolygon::CheckCellXSide(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<f32, mmPolygon*, f32, f32, f32>>(0x11D080_Offset, this, arg1, arg2, arg3);
}

f32 mmPolygon::CheckCellZSide(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<f32, mmPolygon*, f32, f32, f32>>(0x11D170_Offset, this, arg1, arg2, arg3);
}

f32 mmPolygon::CheckCorner(f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5)
{
    return stub<thiscall_t<f32, mmPolygon*, f32, f32, f32*, f32*, f32*>>(
        0x11CFD0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

f32 mmPolygon::CornersHeight(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<f32, mmPolygon*, f32, f32, f32, f32>>(0x11CDB0_Offset, this, arg1, arg2, arg3, arg4);
}

void mmPolygon::Draw()
{
    return stub<thiscall_t<void, mmPolygon*>>(0x11C2A0_Offset, this);
}

i32 mmPolygon::FullSegment(class mmEdgeBodyIsect* arg1)
{
    return stub<thiscall_t<i32, mmPolygon*, class mmEdgeBodyIsect*>>(0x11AEB0_Offset, this, arg1);
}

i32 mmPolygon::FullSegment(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmPolygon*, class mmIntersection*>>(0x11B440_Offset, this, arg1);
}

i32 mmPolygon::FullSphere(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmPolygon*, class mmIntersection*>>(0x11BC80_Offset, this, arg1);
}

i32 mmPolygon::GetCorner(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4,
    class Vector3& arg5, class Vector3& arg6, f32& arg7)
{
    return stub<thiscall_t<i32, mmPolygon*, class Vector3&, class Vector3&, class Vector3&, class Vector3&,
        class Vector3&, class Vector3&, f32&>>(0x11B990_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void mmPolygon::GetST(class Vector3* arg1, class Vector3* arg2, class mmBoundTemplate* arg3)
{
    return stub<thiscall_t<void, mmPolygon*, class Vector3*, class Vector3*, class mmBoundTemplate*>>(
        0x11ADA0_Offset, this, arg1, arg2, arg3);
}

void mmPolygon::Init()
{
    return stub<thiscall_t<void, mmPolygon*>>(0x11A820_Offset, this);
}

f32 mmPolygon::MaxY(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<f32, mmPolygon*, f32, f32, f32, f32>>(0x11CC60_Offset, this, arg1, arg2, arg3, arg4);
}

void mmPolygon::Plot(class mmBoundTemplate* arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmPolygon*, class mmBoundTemplate*, i32>>(0x11C320_Offset, this, arg1, arg2);
}

void mmPolygon::PlotScan(i32 arg1, i32 arg2, i32 arg3, class mmBoundTemplate* arg4, i32 arg5)
{
    return stub<thiscall_t<void, mmPolygon*, i32, i32, i32, class mmBoundTemplate*, i32>>(
        0x11CBD0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void mmPolygon::PlotTriangle(i32 arg1, i32 arg2, i32 arg3, class mmBoundTemplate* arg4, i32 arg5)
{
    return stub<thiscall_t<void, mmPolygon*, i32, i32, i32, class mmBoundTemplate*, i32>>(
        0x11C380_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

define_dummy_symbol(mmdyna_poly);
