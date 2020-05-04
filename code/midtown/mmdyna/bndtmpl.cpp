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

#include "bndtmpl.h"

mmBoundTemplate::mmBoundTemplate()
{
    unimplemented();
}

mmBoundTemplate::~mmBoundTemplate()
{
    unimplemented();
}

void mmBoundTemplate::AddIndex(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32, i32>>(0x119F70_Offset, this, arg1, arg2, arg3);
}

void mmBoundTemplate::AddQuad(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32, i32, i32, i32, i32>>(
        0x117370_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void mmBoundTemplate::AddRef()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x11D8F0_Offset, this);
}

void mmBoundTemplate::AddTriangle(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32, i32, i32, i32>>(
        0x117280_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

i32 mmBoundTemplate::Collide(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x11E550_Offset, this, arg1);
}

i32 mmBoundTemplate::Collide(class mmEdgeBodyIsect* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmEdgeBodyIsect*, i32>>(0x11E4F0_Offset, this, arg1, arg2);
}

i32 mmBoundTemplate::Collide(class mmBoundTemplate* arg1, class Matrix34& arg2, class Matrix34& arg3,
    class Matrix34& arg4, class mmEdgeBodyIsect* arg5, i32 arg6, i32 arg7, class asInertialCS* arg8,
    class asInertialCS* arg9, class Vector3* arg10, class Vector3* arg11)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmBoundTemplate*, class Matrix34&, class Matrix34&,
        class Matrix34&, class mmEdgeBodyIsect*, i32, i32, class asInertialCS*, class asInertialCS*, class Vector3*,
        class Vector3*>>(0x11DB70_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}

i32 mmBoundTemplate::CollideTerrains(
    class mmBoundTemplate** arg1, class Matrix34& arg2, class mmEdgeBodyIsect* arg3, i32 arg4, i32 arg5)
{
    return stub<
        thiscall_t<i32, mmBoundTemplate*, class mmBoundTemplate**, class Matrix34&, class mmEdgeBodyIsect*, i32, i32>>(
        0x11E240_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void mmBoundTemplate::ComputeBounds()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x1175E0_Offset, this);
}

void mmBoundTemplate::ComputeEdgeNormals()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x1193A0_Offset, this);
}

void mmBoundTemplate::ComputeEdges()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x117680_Offset, this);
}

void mmBoundTemplate::Draw()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x11FCF0_Offset, this);
}

void mmBoundTemplate::DrawBox()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x11FD70_Offset, this);
}

void mmBoundTemplate::DrawGeometry()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x11FD90_Offset, this);
}

void mmBoundTemplate::DrawGraph()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x120000_Offset, this);
}

void mmBoundTemplate::DrawSphere()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x11FD30_Offset, this);
}

void mmBoundTemplate::DrawTable()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x11FE00_Offset, this);
}

void mmBoundTemplate::InitGeometry(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32>>(0x1171D0_Offset, this, arg1, arg2);
}

i32 mmBoundTemplate::LineGeometry(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x11F670_Offset, this, arg1);
}

i32 mmBoundTemplate::LineGeometry(class mmEdgeBodyIsect* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmEdgeBodyIsect*, i32>>(0x11F120_Offset, this, arg1, arg2);
}

i32 mmBoundTemplate::LineSpan(class mmIntersection* arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*, i32, i32, i32>>(
        0x11FB20_Offset, this, arg1, arg2, arg3, arg4);
}

i32 mmBoundTemplate::LineSpan(class mmEdgeBodyIsect* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmEdgeBodyIsect*, i32, i32, i32, i32>>(
        0x11F500_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

i32 mmBoundTemplate::LineSphere(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x11F110_Offset, this, arg1);
}

i32 mmBoundTemplate::LineTable(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x11F7A0_Offset, this, arg1);
}

i32 mmBoundTemplate::LineTable(class mmEdgeBodyIsect* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmEdgeBodyIsect*, i32>>(0x11F1E0_Offset, this, arg1, arg2);
}

i32 mmBoundTemplate::Load(
    char* arg1, char* arg2, class Vector3* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, i32 arg8, i32 arg9)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, char*, char*, class Vector3*, i32, i32, i32, i32, i32, i32>>(
        0x117850_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

i32 mmBoundTemplate::LockIfResident()
{
    return stub<thiscall_t<i32, mmBoundTemplate*>>(0x119320_Offset, this);
}

void mmBoundTemplate::PageIn()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x119300_Offset, this);
}

void mmBoundTemplate::PlotLine(class Vector3 arg1, class Vector3 arg2)
{
    return stub<thiscall_t<void, mmBoundTemplate*, class Vector3, class Vector3>>(0x11A090_Offset, this, arg1, arg2);
}

void mmBoundTemplate::PlotSpan(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32, i32>>(0x11A1A0_Offset, this, arg1, arg2, arg3);
}

i32 mmBoundTemplate::QuickLineBox(class mmEdgeBodyIsect* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmEdgeBodyIsect*>>(0x11EA00_Offset, this, arg1);
}

i32 mmBoundTemplate::QuickLineBox(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x11EAF0_Offset, this, arg1);
}

i32 mmBoundTemplate::QuickLineSphere(class mmEdgeBodyIsect* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmEdgeBodyIsect*>>(0x11E6C0_Offset, this, arg1);
}

i32 mmBoundTemplate::QuickLineSphere(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x11E820_Offset, this, arg1);
}

i32 mmBoundTemplate::QuickSphereBox(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x11E940_Offset, this, arg1);
}

i32 mmBoundTemplate::QuickSphereSphere(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x11E620_Offset, this, arg1);
}

i32 mmBoundTemplate::Release()
{
    return stub<thiscall_t<i32, mmBoundTemplate*>>(0x11D910_Offset, this);
}

void mmBoundTemplate::Reset()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x11DB20_Offset, this);
}

i32 mmBoundTemplate::SphereGeometry(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x11ED80_Offset, this, arg1);
}

i32 mmBoundTemplate::SphereSphere(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x11EBE0_Offset, this, arg1);
}

i32 mmBoundTemplate::SphereTable(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x11EEB0_Offset, this, arg1);
}

void mmBoundTemplate::Unlock()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x119380_Offset, this);
}

void mmBoundTemplate::ValidatePtr(char* arg1)
{
    return stub<thiscall_t<void, mmBoundTemplate*, char*>>(0x11D940_Offset, this, arg1);
}

class mmBoundTemplate* mmBoundTemplate::GetBoundTemplate(
    char* arg1, char* arg2, class Vector3* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, i32 arg8)
{
    return stub<cdecl_t<class mmBoundTemplate*, char*, char*, class Vector3*, i32, i32, i32, i32, i32>>(
        0x11D2E0_Offset, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

class mmBoundTemplate* mmBoundTemplate::MakeBox(
    char* arg1, char* arg2, i32 arg3, class Vector3* arg4, class Vector3* arg5)
{
    return stub<cdecl_t<class mmBoundTemplate*, char*, char*, i32, class Vector3*, class Vector3*>>(
        0x11D3F0_Offset, arg1, arg2, arg3, arg4, arg5);
}

void mmBoundTemplate::DoMakeTable(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32, i32>>(0x119A30_Offset, this, arg1, arg2, arg3);
}

void mmBoundTemplate::DoPageIn()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x118E90_Offset, this);
}

void mmBoundTemplate::MakeTable(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32, i32>>(0x119830_Offset, this, arg1, arg2, arg3);
}

void mmBoundTemplate::PageInCallback(void* arg1)
{
    return stub<cdecl_t<void, void*>>(0x1192F0_Offset, arg1);
}

void mmBoundTemplate::PageOutCallback(void* arg1, i32 arg2)
{
    return stub<cdecl_t<void, void*, i32>>(0x118D40_Offset, arg1, arg2);
}

define_dummy_symbol(mmdyna_bndtmpl);
