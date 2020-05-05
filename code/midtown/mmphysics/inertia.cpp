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
    unimplemented(arg1);
}

void asInertialCS::ApplyPush(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&, class Vector3 const&>>(
        0xDA660_Offset, this, arg1, arg2);
}

void asInertialCS::GetCMatrix(class Matrix34& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, asInertialCS*, class Matrix34&, class Vector3 const&>>(
        0xDAD70_Offset, this, arg1, arg2);
}

void asInertialCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Bank*>>(0xDB190_Offset, this, arg1);
}

void asInertialCS::ApplyAngImpulse(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&>>(0xDA5D0_Offset, this, arg1);
}

void asInertialCS::ApplyForce(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&>>(0xDA200_Offset, this, arg1);
}

void asInertialCS::ApplyForce(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&, class Vector3 const&>>(
        0xDA290_Offset, this, arg1, arg2);
}

void asInertialCS::ApplyImpulse(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&>>(0xDA430_Offset, this, arg1);
}

void asInertialCS::ApplyImpulse(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&, class Vector3 const&>>(
        0xDA4C0_Offset, this, arg1, arg2);
}

void asInertialCS::ApplyPush(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&>>(0xDA7D0_Offset, this, arg1);
}

void asInertialCS::ApplyTorque(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&>>(0xDA3A0_Offset, this, arg1);
}

void asInertialCS::ApplyTurn(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&>>(0xDA940_Offset, this, arg1);
}

void asInertialCS::CalcCMatrix(class Matrix34& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, asInertialCS*, class Matrix34&, class Vector3 const&>>(
        0xDABA0_Offset, this, arg1, arg2);
}

void asInertialCS::DoConstrain()
{
    return stub<thiscall_t<void, asInertialCS*>>(0xDAA20_Offset, this);
}

void asInertialCS::FileIO(class MiniParser* arg1)
{
    return stub<thiscall_t<void, asInertialCS*, class MiniParser*>>(0xDB180_Offset, this, arg1);
}

void asInertialCS::FinishForces()
{
    return stub<thiscall_t<void, asInertialCS*>>(0xD9740_Offset, this);
}

void asInertialCS::FinishUpdate()
{
    return stub<thiscall_t<void, asInertialCS*>>(0xD9B60_Offset, this);
}

class MetaClass* asInertialCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asInertialCS*>>(0xDBAF0_Offset, this);
}

class Vector3 asInertialCS::GetVelocity(class Vector3 const* arg1)
{
    return stub<thiscall_t<class Vector3, asInertialCS*, class Vector3 const*>>(0xDAAD0_Offset, this, arg1);
}

void asInertialCS::MatricesToMomenta(class Matrix34 const& arg1, class Matrix34 const& arg2, f32 arg3)
{
    return stub<thiscall_t<void, asInertialCS*, class Matrix34 const&, class Matrix34 const&, f32>>(
        0xDAEF0_Offset, this, arg1, arg2, arg3);
}

void asInertialCS::MoveICS()
{
    return stub<thiscall_t<void, asInertialCS*>>(0xD9AE0_Offset, this);
}

void asInertialCS::Reset()
{
    return stub<thiscall_t<void, asInertialCS*>>(0xD9630_Offset, this);
}

void asInertialCS::SetDensity(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, asInertialCS*, f32, f32, f32, f32>>(0xD9400_Offset, this, arg1, arg2, arg3, arg4);
}

void asInertialCS::SetMass(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, asInertialCS*, f32, f32, f32, f32>>(0xD92F0_Offset, this, arg1, arg2, arg3, arg4);
}

void asInertialCS::SetZeroDOF(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, asInertialCS*, f32, f32>>(0xD9450_Offset, this, arg1, arg2);
}

void asInertialCS::Update()
{
    return stub<thiscall_t<void, asInertialCS*>>(0xD9680_Offset, this);
}

void asInertialCS::UpdateKids()
{
    return stub<thiscall_t<void, asInertialCS*>>(0xD9650_Offset, this);
}

void asInertialCS::Zero()
{
    return stub<thiscall_t<void, asInertialCS*>>(0xD9510_Offset, this);
}

void asInertialCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0xDB970_Offset);
}

void asInertialCS::DrawForce(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&, class Vector3 const&>>(
        0xDA980_Offset, this, arg1, arg2);
}

void asInertialCS::DrawForce(class Vector3 const& arg1, class Vector3 const& arg2, class Vector3 const& arg3)
{
    return stub<thiscall_t<void, asInertialCS*, class Vector3 const&, class Vector3 const&, class Vector3 const&>>(
        0xDA9D0_Offset, this, arg1, arg2, arg3);
}

f32 InertiaAxis(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<cdecl_t<f32, class Vector3 const&, class Vector3 const&>>(0xDADE0_Offset, arg1, arg2);
}

class Vector3 MatrixToAngVelocity(class Matrix34 const& arg1, f32 arg2)
{
    return stub<cdecl_t<class Vector3, class Matrix34 const&, f32>>(0xDAE20_Offset, arg1, arg2);
}

class Vector3 MatrixToAngVelocity(class Matrix34 const& arg1, class Matrix34 const& arg2, f32 arg3)
{
    return stub<cdecl_t<class Vector3, class Matrix34 const&, class Matrix34 const&, f32>>(
        0xDB120_Offset, arg1, arg2, arg3);
}
