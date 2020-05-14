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

define_dummy_symbol(mmphysics_inertia);

#include "inertia.h"

asInertialCS::asInertialCS()
{
    unimplemented();
}

asInertialCS::~asInertialCS()
{
    unimplemented();
}

void asInertialCS::ApplyPush(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&, class Vector3 const&>>(
        0x4DA660, this, arg1, arg2);
}

void asInertialCS::GetCMatrix(class Matrix34& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, asInertialCS*, class Matrix34&, class Vector3 const&>>(0x4DAD70, this, arg1, arg2);
}

void asInertialCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Bank*>>(0x4DB190, this, arg1);
}

void asInertialCS::ApplyAngImpulse(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&>>(0x4DA5D0, this, arg1);
}

void asInertialCS::ApplyForce(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&>>(0x4DA200, this, arg1);
}

void asInertialCS::ApplyForce(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&, class Vector3 const&>>(
        0x4DA290, this, arg1, arg2);
}

void asInertialCS::ApplyImpulse(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&>>(0x4DA430, this, arg1);
}

void asInertialCS::ApplyImpulse(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&, class Vector3 const&>>(
        0x4DA4C0, this, arg1, arg2);
}

void asInertialCS::ApplyPush(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&>>(0x4DA7D0, this, arg1);
}

void asInertialCS::ApplyTorque(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&>>(0x4DA3A0, this, arg1);
}

void asInertialCS::ApplyTurn(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&>>(0x4DA940, this, arg1);
}

void asInertialCS::CalcCMatrix(class Matrix34& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, asInertialCS*, class Matrix34&, class Vector3 const&>>(0x4DABA0, this, arg1, arg2);
}

void asInertialCS::DoConstrain()
{
    return stub<thiscall_t<void, asInertialCS*>>(0x4DAA20, this);
}

void asInertialCS::FileIO(class MiniParser* arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class MiniParser*>>(0x4DB180, this, arg1);
}

void asInertialCS::FinishForces()
{
    return stub<thiscall_t<void, asInertialCS*>>(0x4D9740, this);
}

void asInertialCS::FinishUpdate()
{
    return stub<thiscall_t<void, asInertialCS*>>(0x4D9B60, this);
}

class MetaClass* asInertialCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asInertialCS*>>(0x4DBAF0, this);
}

class Vector3 asInertialCS::GetVelocity(class Vector3 const* arg1)
{
    return stub<thiscall_t<class Vector3, asInertialCS*, class Vector3 const*>>(0x4DAAD0, this, arg1);
}

void asInertialCS::MatricesToMomenta(class Matrix34 const& arg1, class Matrix34 const& arg2, f32 arg3)
{
    return stub<thiscall_t<void, asInertialCS*, class Matrix34 const&, class Matrix34 const&, f32>>(
        0x4DAEF0, this, arg1, arg2, arg3);
}

void asInertialCS::MoveICS()
{
    return stub<thiscall_t<void, asInertialCS*>>(0x4D9AE0, this);
}

void asInertialCS::Reset()
{
    return stub<thiscall_t<void, asInertialCS*>>(0x4D9630, this);
}

void asInertialCS::SetDensity(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, asInertialCS*, f32, f32, f32, f32>>(0x4D9400, this, arg1, arg2, arg3, arg4);
}

void asInertialCS::SetMass(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, asInertialCS*, f32, f32, f32, f32>>(0x4D92F0, this, arg1, arg2, arg3, arg4);
}

void asInertialCS::SetZeroDOF(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, asInertialCS*, f32, f32>>(0x4D9450, this, arg1, arg2);
}

void asInertialCS::Update()
{
    return stub<thiscall_t<void, asInertialCS*>>(0x4D9680, this);
}

void asInertialCS::UpdateKids()
{
    return stub<thiscall_t<void, asInertialCS*>>(0x4D9650, this);
}

void asInertialCS::Zero()
{
    return stub<thiscall_t<void, asInertialCS*>>(0x4D9510, this);
}

void asInertialCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4DB970);
}

void asInertialCS::DrawForce(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&, class Vector3 const&>>(
        0x4DA980, this, arg1, arg2);
}

void asInertialCS::DrawForce(class Vector3 const& arg1, class Vector3 const& arg2, class Vector3 const& arg3)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&, class Vector3 const&, class Vector3 const&>>(
        0x4DA9D0, this, arg1, arg2, arg3);
}

f32 InertiaAxis(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<cdecl_t<f32, class Vector3 const&, class Vector3 const&>>(0x4DADE0, arg1, arg2);
}

class Vector3 MatrixToAngVelocity(class Matrix34 const& arg1, f32 arg2)
{
    return stub<cdecl_t<class Vector3, class Matrix34 const&, f32>>(0x4DAE20, arg1, arg2);
}

class Vector3 MatrixToAngVelocity(class Matrix34 const& arg1, class Matrix34 const& arg2, f32 arg3)
{
    return stub<cdecl_t<class Vector3, class Matrix34 const&, class Matrix34 const&, f32>>(0x4DB120, arg1, arg2, arg3);
}
