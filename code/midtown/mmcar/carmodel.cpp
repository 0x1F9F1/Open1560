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

#include "carmodel.h"

mmCarModel::mmCarModel()
{
    unimplemented();
}

mmCarModel::~mmCarModel()
{
    unimplemented();
}

void mmCarModel::Activate()
{
    return stub<thiscall_t<void, mmCarModel*>>(0x730A0_Offset, this);
}

void mmCarModel::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmCarModel*, class Bank*>>(0x730E0_Offset, this, arg1);
}

void mmCarModel::ApplyDamage(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmCarModel*, class Vector3&, f32>>(0x72D90_Offset, this, arg1, arg2);
}

class mmPhysEntity* mmCarModel::AttachEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmCarModel*>>(0x73330_Offset, this);
}

void mmCarModel::ClearDamage(i32 arg1)
{
    return stub<thiscall_t<void, mmCarModel*, i32>>(0x72CA0_Offset, this, arg1);
}

void mmCarModel::DashActivated()
{
    return stub<thiscall_t<void, mmCarModel*>>(0x73080_Offset, this);
}

void mmCarModel::DashDeactivated()
{
    return stub<thiscall_t<void, mmCarModel*>>(0x73090_Offset, this);
}

void mmCarModel::Deactivate()
{
    return stub<thiscall_t<void, mmCarModel*>>(0x730B0_Offset, this);
}

void __fastcall mmCarModel::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmCarModel*, i32>>(0x71B70_Offset, this, arg1);
}

void __fastcall mmCarModel::DrawGlow()
{
    return stub<fastcall_t<void, mmCarModel*>>(0x72B00_Offset, this);
}

void __fastcall mmCarModel::DrawShadow()
{
    return stub<fastcall_t<void, mmCarModel*>>(0x72B90_Offset, this);
}

void mmCarModel::EjectPart(class mmWheel* arg1, i16 arg2, i16 arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmCarModel*, class mmWheel*, i16, i16, i32>>(
        0x718D0_Offset, this, arg1, arg2, arg3, arg4);
}

void mmCarModel::EjectWheels(i32 arg1)
{
    return stub<thiscall_t<void, mmCarModel*, i32>>(0x71780_Offset, this, arg1);
}

void __fastcall mmCarModel::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmCarModel*, class Matrix34 const&>>(0x715A0_Offset, this, arg1);
}

i32 mmCarModel::GetCarFlags(char* arg1)
{
    return stub<thiscall_t<i32, mmCarModel*, char*>>(0x72BE0_Offset, this, arg1);
}

class MetaClass* mmCarModel::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmCarModel*>>(0x73280_Offset, this);
}

class mmPhysEntity* mmCarModel::GetEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmCarModel*>>(0x73320_Offset, this);
}

class mmHitBangerInstance* mmCarModel::GetPart(i32 arg1)
{
    return stub<thiscall_t<class mmHitBangerInstance*, mmCarModel*, i32>>(0x72C50_Offset, this, arg1);
}

class Vector3& __fastcall mmCarModel::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmCarModel*>>(0x715D0_Offset, this);
}

class Vector3 mmCarModel::GetVelocity()
{
    return stub<thiscall_t<class Vector3, mmCarModel*>>(0x73340_Offset, this);
}

void mmCarModel::Impact(class Vector3* arg1)
{
    return stub<thiscall_t<void, mmCarModel*, class Vector3*>>(0x71640_Offset, this, arg1);
}

void mmCarModel::Init(char* arg1, class mmCar* arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmCarModel*, char*, class mmCar*, i32>>(0x72DC0_Offset, this, arg1, arg2, arg3);
}

void mmCarModel::InitDamage()
{
    return stub<thiscall_t<void, mmCarModel*>>(0x72BF0_Offset, this);
}

void mmCarModel::Kill()
{
    return stub<thiscall_t<void, mmCarModel*>>(0x730D0_Offset, this);
}

void mmCarModel::Reset()
{
    return stub<thiscall_t<void, mmCarModel*>>(0x73370_Offset, this);
}

class Matrix34& __fastcall mmCarModel::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmCarModel*, class Matrix34&>>(0x715C0_Offset, this, arg1);
}

void mmCarModel::DeclareFields()
{
    return stub<cdecl_t<void>>(0x73100_Offset);
}

define_dummy_symbol(mmcar_carmodel);
