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

define_dummy_symbol(mmdyna_bndtmpl2);

#include "bndtmpl2.h"

#include "bndtmpl.h"

bool EdgeInList(i32 arg1, i32 arg2, i32 arg3, i32* arg4, i32* arg5)
{
    return stub<cdecl_t<bool, i32, i32, i32, i32*, i32*>>(0x517620, arg1, arg2, arg3, arg4, arg5);
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

void mmBoundTemplate::AddTriangle(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32, i32, i32, i32>>(
        0x517280, this, arg1, arg2, arg3, arg4, arg5);
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

void mmBoundTemplate::InitGeometry(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmBoundTemplate*, i32, i32>>(0x5171D0, this, arg1, arg2);
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

void mmBoundTemplate::Unlock()
{
    return stub<thiscall_t<void, mmBoundTemplate*>>(0x519380, this);
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
