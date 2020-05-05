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

define_dummy_symbol(mmphysics_phys);

#include "phys.h"

mmPhysExec::~mmPhysExec()
{
    unimplemented(arg1);
}

void mmPhysExec::DoUpdateAll()
{
    return stub<thiscall_t<void, mmPhysExec*>>(0xD3DA0_Offset, this);
}

void mmPhysExec::DoUpdatePlayerOnly()
{
    return stub<thiscall_t<void, mmPhysExec*>>(0xD3FF0_Offset, this);
}

void mmPhysExec::Update()
{
    return stub<thiscall_t<void, mmPhysExec*>>(0xD9190_Offset, this);
}

mmPhysicsMGR::mmPhysicsMGR()
{
    unimplemented();
}

mmPhysicsMGR::~mmPhysicsMGR()
{
    unimplemented(arg1);
}

void mmPhysicsMGR::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmPhysicsMGR*, class Bank*>>(0xD8E00_Offset, this, arg1);
}

i32 mmPhysicsMGR::Collide(class mmIntersection* arg1, i32 arg2, i16 arg3, i16 arg4)
{
    return stub<thiscall_t<i32, mmPhysicsMGR*, class mmIntersection*, i32, i16, i16>>(
        0xD6460_Offset, this, arg1, arg2, arg3, arg4);
}

i32 mmPhysicsMGR::CollideLOS(class mmIntersection* arg1, i32 arg2, i16 arg3, i16 arg4)
{
    return stub<thiscall_t<i32, mmPhysicsMGR*, class mmIntersection*, i32, i16, i16>>(
        0xD6580_Offset, this, arg1, arg2, arg3, arg4);
}

void mmPhysicsMGR::Cull()
{
    return stub<thiscall_t<void, mmPhysicsMGR*>>(0xD5390_Offset, this);
}

void mmPhysicsMGR::DeclareMover(class mmInstance* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmPhysicsMGR*, class mmInstance*, i32, i32>>(0xD4540_Offset, this, arg1, arg2, arg3);
}

class MetaClass* mmPhysicsMGR::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPhysicsMGR*>>(0xD9070_Offset, this);
}

void mmPhysicsMGR::IgnoreMover(class mmInstance* arg1)
{
    return stub<thiscall_t<void, mmPhysicsMGR*, class mmInstance*>>(0xD49E0_Offset, this, arg1);
}

void mmPhysicsMGR::Init(class asInertialCS* arg1, class mmViewCS* arg2)
{
    return stub<thiscall_t<void, mmPhysicsMGR*, class asInertialCS*, class mmViewCS*>>(
        0xD4430_Offset, this, arg1, arg2);
}

void mmPhysicsMGR::NewMover(class mmInstance* arg1)
{
    return stub<thiscall_t<void, mmPhysicsMGR*, class mmInstance*>>(0xD4840_Offset, this, arg1);
}

void mmPhysicsMGR::NewMover(class mmInstance* arg1, class mmInstance* arg2)
{
    return stub<thiscall_t<void, mmPhysicsMGR*, class mmInstance*, class mmInstance*>>(
        0xD4740_Offset, this, arg1, arg2);
}

void mmPhysicsMGR::NewMover(class mmInstance* arg1, class mmInstance* arg2, class mmInstance* arg3)
{
    return stub<thiscall_t<void, mmPhysicsMGR*, class mmInstance*, class mmInstance*, class mmInstance*>>(
        0xD48C0_Offset, this, arg1, arg2, arg3);
}

void mmPhysicsMGR::Reset()
{
    return stub<thiscall_t<void, mmPhysicsMGR*>>(0xD44D0_Offset, this);
}

void mmPhysicsMGR::Shutdown()
{
    return stub<thiscall_t<void, mmPhysicsMGR*>>(0xD4520_Offset, this);
}

void mmPhysicsMGR::Update()
{
    return stub<thiscall_t<void, mmPhysicsMGR*>>(0xD4F40_Offset, this);
}

void mmPhysicsMGR::UpdateEverythingButPlayer()
{
    return stub<thiscall_t<void, mmPhysicsMGR*>>(0xD4D00_Offset, this);
}

void mmPhysicsMGR::UpdatePaused()
{
    return stub<thiscall_t<void, mmPhysicsMGR*>>(0xD52F0_Offset, this);
}

void mmPhysicsMGR::DeclareFields()
{
    return stub<cdecl_t<void>>(0xD8EF0_Offset);
}

i32 mmPhysicsMGR::ClosestNeighboringCullRoom(i32 arg1)
{
    return stub<thiscall_t<i32, mmPhysicsMGR*, i32>>(0xD4B50_Offset, this, arg1);
}

i32 mmPhysicsMGR::CollideInstances(class mmInstance* arg1, class mmInstance* arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<i32, mmPhysicsMGR*, class mmInstance*, class mmInstance*, i32, i32>>(
        0xD5950_Offset, this, arg1, arg2, arg3, arg4);
}

i32 mmPhysicsMGR::CollideProbe(i16 arg1, class mmIntersection* arg2, i32 arg3)
{
    return stub<thiscall_t<i32, mmPhysicsMGR*, i16, class mmIntersection*, i32>>(
        0xD62D0_Offset, this, arg1, arg2, arg3);
}

void mmPhysicsMGR::CollideTerrain(class mmInstance* arg1)
{
    return stub<thiscall_t<void, mmPhysicsMGR*, class mmInstance*>>(0xD5DF0_Offset, this, arg1);
}

void mmPhysicsMGR::DeclareBound(class mmBoundTemplate* arg1)
{
    return stub<thiscall_t<void, mmPhysicsMGR*, class mmBoundTemplate*>>(0xD5320_Offset, this, arg1);
}

void mmPhysicsMGR::GatherCollidables(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmPhysicsMGR*, i32, i32>>(0xD4CA0_Offset, this, arg1, arg2);
}

void mmPhysicsMGR::GatherRoomCollidables(i32 arg1, i16 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmPhysicsMGR*, i32, i16, i32>>(0xD4A30_Offset, this, arg1, arg2, arg3);
}

void mmPhysicsMGR::Stats()
{
    return stub<thiscall_t<void, mmPhysicsMGR*>>(0xD5520_Offset, this);
}

i32 mmPhysicsMGR::TrivialCollideInstances(class mmInstance* arg1, class mmInstance* arg2)
{
    return stub<thiscall_t<i32, mmPhysicsMGR*, class mmInstance*, class mmInstance*>>(0xD5730_Offset, this, arg1, arg2);
}

void DoEdgeEdge(class mmEdgeBodyIsect* arg1, class mmIntersection** arg2, i32* arg3, i32 arg4)
{
    return stub<cdecl_t<void, class mmEdgeBodyIsect*, class mmIntersection**, i32*, i32>>(
        0xD8130_Offset, arg1, arg2, arg3, arg4);
}

void DoEndPtSearch(i32 arg1, class Vector3 const& arg2, class mmEdgeBodyIsect* arg3, i32 arg4,
    class mmIntersection** arg5, i32* arg6, i32 arg7)
{
    return stub<
        cdecl_t<void, i32, class Vector3 const&, class mmEdgeBodyIsect*, i32, class mmIntersection**, i32*, i32>>(
        0xD7B10_Offset, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

i32 FindIntersections(class mmIntersection* arg1, i32 arg2, class asBound* arg3, class asBound* arg4,
    class mmBoundTemplate* arg5, class mmBoundTemplate* arg6, class mmEdgeBodyIsect* arg7, i32 arg8,
    class mmEdgeBodyIsect* arg9, i32 arg10)
{
    return stub<cdecl_t<i32, class mmIntersection*, i32, class asBound*, class asBound*, class mmBoundTemplate*,
        class mmBoundTemplate*, class mmEdgeBodyIsect*, i32, class mmEdgeBodyIsect*, i32>>(
        0xD66E0_Offset, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}

i32 GetCollidePolyEdge(class Vector3 const& arg1, class mmPolygon* arg2, class mmBoundTemplate* arg3,
    class asInertialCS* arg4, class Vector3 const& arg5, f32 arg6, class Vector3 const& arg7, class Vector3 const& arg8,
    class Vector3 const& arg9, class Vector3 const& arg10, class Vector3* arg11, class Vector3* arg12, f32* arg13,
    i32* arg14, i32* arg15)
{
    return stub<cdecl_t<i32, class Vector3 const&, class mmPolygon*, class mmBoundTemplate*, class asInertialCS*,
        class Vector3 const&, f32, class Vector3 const&, class Vector3 const&, class Vector3 const&,
        class Vector3 const&, class Vector3*, class Vector3*, f32*, i32*, i32*>>(
        0xD8730_Offset, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15);
}

void SegSegDistNorm(class Vector3 const& arg1, class Vector3 const& arg2, class Vector3 const& arg3,
    class Vector3 const& arg4, class Vector3 const& arg5, class Vector3 const& arg6, class Vector3* arg7,
    class Vector3* arg8, class Vector3* arg9, f32* arg10, i32* arg11)
{
    return stub<cdecl_t<void, class Vector3 const&, class Vector3 const&, class Vector3 const&, class Vector3 const&,
        class Vector3 const&, class Vector3 const&, class Vector3*, class Vector3*, class Vector3*, f32*, i32*>>(
        0xD8210_Offset, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}

i32 testNoOverlap(f32 arg1, f32 arg2)
{
    return stub<cdecl_t<i32, f32, f32>>(0xD90C0_Offset, arg1, arg2);
}
