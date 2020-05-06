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

define_dummy_symbol(mmdyna_bndtmpl);

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
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32, i32>>(0x519F70, this, arg1, arg2, arg3);
}

void mmBoundTemplate::AddQuad(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32, i32, i32, i32, i32>>(
        0x517370, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void mmBoundTemplate::AddRef()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x51D8F0, this);
}

void mmBoundTemplate::AddTriangle(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32, i32, i32, i32>>(
        0x517280, this, arg1, arg2, arg3, arg4, arg5);
}

i32 mmBoundTemplate::Collide(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x51E550, this, arg1);
}

i32 mmBoundTemplate::Collide(class mmEdgeBodyIsect* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmEdgeBodyIsect*, i32>>(0x51E4F0, this, arg1, arg2);
}

i32 mmBoundTemplate::Collide(class mmBoundTemplate* arg1, class Matrix34& arg2, class Matrix34& arg3,
    class Matrix34& arg4, class mmEdgeBodyIsect* arg5, i32 arg6, i32 arg7, class asInertialCS* arg8,
    class asInertialCS* arg9, class Vector3* arg10, class Vector3* arg11)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmBoundTemplate*, class Matrix34&, class Matrix34&,
        class Matrix34&, class mmEdgeBodyIsect*, i32, i32, class asInertialCS*, class asInertialCS*, class Vector3*,
        class Vector3*>>(0x51DB70, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}

i32 mmBoundTemplate::CollideTerrains(
    class mmBoundTemplate** arg1, class Matrix34& arg2, class mmEdgeBodyIsect* arg3, i32 arg4, i32 arg5)
{
    return stub<
        thiscall_t<i32, mmBoundTemplate*, class mmBoundTemplate**, class Matrix34&, class mmEdgeBodyIsect*, i32, i32>>(
        0x51E240, this, arg1, arg2, arg3, arg4, arg5);
}

void mmBoundTemplate::ComputeBounds()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x5175E0, this);
}

void mmBoundTemplate::ComputeEdgeNormals()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x5193A0, this);
}

void mmBoundTemplate::ComputeEdges()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x517680, this);
}

void mmBoundTemplate::Draw()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x51FCF0, this);
}

void mmBoundTemplate::DrawBox()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x51FD70, this);
}

void mmBoundTemplate::DrawGeometry()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x51FD90, this);
}

void mmBoundTemplate::DrawGraph()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x520000, this);
}

void mmBoundTemplate::DrawSphere()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x51FD30, this);
}

void mmBoundTemplate::DrawTable()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x51FE00, this);
}

void mmBoundTemplate::InitGeometry(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32>>(0x5171D0, this, arg1, arg2);
}

i32 mmBoundTemplate::LineGeometry(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x51F670, this, arg1);
}

i32 mmBoundTemplate::LineGeometry(class mmEdgeBodyIsect* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmEdgeBodyIsect*, i32>>(0x51F120, this, arg1, arg2);
}

i32 mmBoundTemplate::LineSpan(class mmIntersection* arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*, i32, i32, i32>>(
        0x51FB20, this, arg1, arg2, arg3, arg4);
}

i32 mmBoundTemplate::LineSpan(class mmEdgeBodyIsect* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmEdgeBodyIsect*, i32, i32, i32, i32>>(
        0x51F500, this, arg1, arg2, arg3, arg4, arg5);
}

i32 mmBoundTemplate::LineSphere(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x51F110, this, arg1);
}

i32 mmBoundTemplate::LineTable(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x51F7A0, this, arg1);
}

i32 mmBoundTemplate::LineTable(class mmEdgeBodyIsect* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmEdgeBodyIsect*, i32>>(0x51F1E0, this, arg1, arg2);
}

i32 mmBoundTemplate::Load(
    char* arg1, char* arg2, class Vector3* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, i32 arg8, i32 arg9)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, char*, char*, class Vector3*, i32, i32, i32, i32, i32, i32>>(
        0x517850, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

i32 mmBoundTemplate::LockIfResident()
{
    return stub<thiscall_t<i32, mmBoundTemplate*>>(0x519320, this);
}

void mmBoundTemplate::PageIn()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x519300, this);
}

void mmBoundTemplate::PlotLine(class Vector3 arg1, class Vector3 arg2)
{
    return stub<thiscall_t<void, mmBoundTemplate*, class Vector3, class Vector3>>(0x51A090, this, arg1, arg2);
}

void mmBoundTemplate::PlotSpan(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32, i32>>(0x51A1A0, this, arg1, arg2, arg3);
}

i32 mmBoundTemplate::QuickLineBox(class mmEdgeBodyIsect* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmEdgeBodyIsect*>>(0x51EA00, this, arg1);
}

i32 mmBoundTemplate::QuickLineBox(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x51EAF0, this, arg1);
}

i32 mmBoundTemplate::QuickLineSphere(class mmEdgeBodyIsect* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmEdgeBodyIsect*>>(0x51E6C0, this, arg1);
}

i32 mmBoundTemplate::QuickLineSphere(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x51E820, this, arg1);
}

i32 mmBoundTemplate::QuickSphereBox(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x51E940, this, arg1);
}

i32 mmBoundTemplate::QuickSphereSphere(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x51E620, this, arg1);
}

i32 mmBoundTemplate::Release()
{
    return stub<thiscall_t<i32, mmBoundTemplate*>>(0x51D910, this);
}

void mmBoundTemplate::Reset()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x51DB20, this);
}

i32 mmBoundTemplate::SphereGeometry(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x51ED80, this, arg1);
}

i32 mmBoundTemplate::SphereSphere(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x51EBE0, this, arg1);
}

i32 mmBoundTemplate::SphereTable(class mmIntersection* arg1)
{
    return stub<thiscall_t<i32, mmBoundTemplate*, class mmIntersection*>>(0x51EEB0, this, arg1);
}

void mmBoundTemplate::Unlock()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x519380, this);
}

void mmBoundTemplate::ValidatePtr(char* arg1)
{
    return stub<thiscall_t<void, mmBoundTemplate*, char*>>(0x51D940, this, arg1);
}

class mmBoundTemplate* mmBoundTemplate::GetBoundTemplate(
    char* arg1, char* arg2, class Vector3* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, i32 arg8)
{
    return stub<cdecl_t<class mmBoundTemplate*, char*, char*, class Vector3*, i32, i32, i32, i32, i32>>(
        0x51D2E0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

class mmBoundTemplate* mmBoundTemplate::MakeBox(
    char* arg1, char* arg2, i32 arg3, class Vector3* arg4, class Vector3* arg5)
{
    return stub<cdecl_t<class mmBoundTemplate*, char*, char*, i32, class Vector3*, class Vector3*>>(
        0x51D3F0, arg1, arg2, arg3, arg4, arg5);
}

void mmBoundTemplate::DoMakeTable(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32, i32>>(0x519A30, this, arg1, arg2, arg3);
}

void mmBoundTemplate::DoPageIn()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x518E90, this);
}

void mmBoundTemplate::MakeTable(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32, i32>>(0x519830, this, arg1, arg2, arg3);
}

void mmBoundTemplate::PageInCallback(void* arg1)
{
    return stub<cdecl_t<void, void*>>(0x5192F0, arg1);
}

void mmBoundTemplate::PageOutCallback(void* arg1, i32 arg2)
{
    return stub<cdecl_t<void, void*, i32>>(0x518D40, arg1, arg2);
}
