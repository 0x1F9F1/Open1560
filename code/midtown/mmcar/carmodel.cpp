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

define_dummy_symbol(mmcar_carmodel);

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
    return stub<thiscall_t<void, mmCarModel*>>(0x4730A0, this);
}

void mmCarModel::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmCarModel*, class Bank*>>(0x4730E0, this, arg1);
}

void mmCarModel::ApplyDamage(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmCarModel*, class Vector3&, f32>>(0x472D90, this, arg1, arg2);
}

class mmPhysEntity* mmCarModel::AttachEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmCarModel*>>(0x473330, this);
}

void mmCarModel::ClearDamage(i32 arg1)
{
    return stub<thiscall_t<void, mmCarModel*, i32>>(0x472CA0, this, arg1);
}

void mmCarModel::DashActivated()
{
    return stub<thiscall_t<void, mmCarModel*>>(0x473080, this);
}

void mmCarModel::DashDeactivated()
{
    return stub<thiscall_t<void, mmCarModel*>>(0x473090, this);
}

void mmCarModel::Deactivate()
{
    return stub<thiscall_t<void, mmCarModel*>>(0x4730B0, this);
}

void __fastcall mmCarModel::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmCarModel*, i32>>(0x471B70, this, arg1);
}

void __fastcall mmCarModel::DrawGlow()
{
    return stub<fastcall_t<void, mmCarModel*>>(0x472B00, this);
}

void __fastcall mmCarModel::DrawShadow()
{
    return stub<fastcall_t<void, mmCarModel*>>(0x472B90, this);
}

void mmCarModel::EjectPart(class mmWheel* arg1, i16 arg2, i16 arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmCarModel*, class mmWheel*, i16, i16, i32>>(0x4718D0, this, arg1, arg2, arg3, arg4);
}

void mmCarModel::EjectWheels(i32 arg1)
{
    return stub<thiscall_t<void, mmCarModel*, i32>>(0x471780, this, arg1);
}

void __fastcall mmCarModel::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmCarModel*, class Matrix34 const&>>(0x4715A0, this, arg1);
}

i32 mmCarModel::GetCarFlags(char* arg1)
{
    return stub<thiscall_t<i32, mmCarModel*, char*>>(0x472BE0, this, arg1);
}

class MetaClass* mmCarModel::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmCarModel*>>(0x473280, this);
}

class mmPhysEntity* mmCarModel::GetEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmCarModel*>>(0x473320, this);
}

class mmHitBangerInstance* mmCarModel::GetPart(i32 arg1)
{
    return stub<thiscall_t<class mmHitBangerInstance*, mmCarModel*, i32>>(0x472C50, this, arg1);
}

class Vector3& __fastcall mmCarModel::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmCarModel*>>(0x4715D0, this);
}

class Vector3 mmCarModel::GetVelocity()
{
    return stub<thiscall_t<class Vector3, mmCarModel*>>(0x473340, this);
}

void mmCarModel::Impact(class Vector3* arg1)
{
    return stub<thiscall_t<void, mmCarModel*, class Vector3*>>(0x471640, this, arg1);
}

void mmCarModel::Init(char* arg1, class mmCar* arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmCarModel*, char*, class mmCar*, i32>>(0x472DC0, this, arg1, arg2, arg3);
}

void mmCarModel::InitDamage()
{
    return stub<thiscall_t<void, mmCarModel*>>(0x472BF0, this);
}

void mmCarModel::Kill()
{
    return stub<thiscall_t<void, mmCarModel*>>(0x4730D0, this);
}

void mmCarModel::Reset()
{
    return stub<thiscall_t<void, mmCarModel*>>(0x473370, this);
}

class Matrix34& __fastcall mmCarModel::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmCarModel*, class Matrix34&>>(0x4715C0, this, arg1);
}

void mmCarModel::DeclareFields()
{
    return stub<cdecl_t<void>>(0x473100);
}
