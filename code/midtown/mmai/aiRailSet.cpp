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

define_dummy_symbol(mmai_aiRailSet);

#include "aiRailSet.h"

aiRailSet::aiRailSet()
{
    unimplemented();
}

aiRailSet::~aiRailSet()
{
    unimplemented();
}

i32 aiRailSet::CalcCopRailPosition(class Vector3& arg1, class Vector3& arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<i32, aiRailSet*, class Vector3&, class Vector3&, f32, f32>>(
        0x454710, this, arg1, arg2, arg3, arg4);
}

f32 aiRailSet::CalcRailLength()
{
    return stub<thiscall_t<f32, aiRailSet*>>(0x457170, this);
}

void aiRailSet::CalcRailPosOrient(class Vector3& arg1, class Vector3& arg2, f32 arg3)
{
    return stub<thiscall_t<void, aiRailSet*, class Vector3&, class Vector3&, f32>>(0x458850, this, arg1, arg2, arg3);
}

void aiRailSet::CalcRailPosition(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiRailSet*, class Vector3&, f32>>(0x453D00, this, arg1, arg2);
}

i32 aiRailSet::CalcRailState(f32 arg1)
{
    return stub<thiscall_t<i32, aiRailSet*, f32>>(0x456B60, this, arg1);
}

void aiRailSet::CalcTurnIntersection(class Vector3& arg1, i32 arg2, class aiPath* arg3, class aiPath* arg4)
{
    return stub<thiscall_t<void, aiRailSet*, class Vector3&, i32, class aiPath*, class aiPath*>>(
        0x457660, this, arg1, arg2, arg3, arg4);
}

void aiRailSet::CalcXZDirection(
    class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4, class Vector3& arg5, f32 arg6)
{
    return stub<thiscall_t<void, aiRailSet*, class Vector3&, class Vector3&, class Vector3&, class Vector3&,
        class Vector3&, f32>>(0x459740, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void aiRailSet::CalcXZPosOrient(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4,
    class Vector3& arg5, class Vector3& arg6, f32 arg7)
{
    return stub<thiscall_t<void, aiRailSet*, class Vector3&, class Vector3&, class Vector3&, class Vector3&,
        class Vector3&, class Vector3&, f32>>(0x459860, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void aiRailSet::CalcXZPosition(
    class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4, class Vector3& arg5, f32 arg6)
{
    return stub<thiscall_t<void, aiRailSet*, class Vector3&, class Vector3&, class Vector3&, class Vector3&,
        class Vector3&, f32>>(0x459630, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void aiRailSet::ComputeXZCurve(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4)
{
    return stub<thiscall_t<void, aiRailSet*, class Vector3&, class Vector3&, class Vector3&, class Vector3&>>(
        0x4599A0, this, arg1, arg2, arg3, arg4);
}

void aiRailSet::ComputeXZCurve(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4,
    class Vector4& arg5, class Vector4& arg6)
{
    return stub<thiscall_t<void, aiRailSet*, class Vector3&, class Vector3&, class Vector3&, class Vector3&,
        class Vector4&, class Vector4&>>(0x459A50, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void aiRailSet::DrawTurn(f32 arg1)
{
    return stub<thiscall_t<void, aiRailSet*, f32>>(0x457A70, this, arg1);
}

void aiRailSet::Dump()
{
    return stub<thiscall_t<void, aiRailSet*>>(0x459BC0, this);
}

void aiRailSet::SolveNextLane()
{
    return stub<thiscall_t<void, aiRailSet*>>(0x4593F0, this);
}

i32 aiRailSet::SolveTurnType(class aiPath* arg1, class aiPath* arg2)
{
    return stub<thiscall_t<i32, aiRailSet*, class aiPath*, class aiPath*>>(0x459470, this, arg1, arg2);
}

void aiRailSet::SolveXZCurve(class Vector3& arg1, class Vector3& arg2, f32 arg3)
{
    return stub<thiscall_t<void, aiRailSet*, class Vector3&, class Vector3&, f32>>(0x459AF0, this, arg1, arg2, arg3);
}

void aiRailSet::SolveXZPosition(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiRailSet*, class Vector3&, f32>>(0x459B80, this, arg1, arg2);
}

class Vector3 operator*(f32 arg1, class Vector3 const& arg2)
{
    return stub<cdecl_t<class Vector3, f32, class Vector3 const&>>(0x459E00, arg1, arg2);
}
