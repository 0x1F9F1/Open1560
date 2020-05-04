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

#include "car.h"

mmCar::mmCar()
{
    unimplemented();
}

mmCar::~mmCar()
{
    unimplemented();
}

void mmCar::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmCar*, class Bank*>>(0x745E0_Offset, this, arg1);
}

void mmCar::ClearDamage()
{
    return stub<thiscall_t<void, mmCar*>>(0x73E70_Offset, this);
}

void mmCar::EnableDriving(i32 arg1)
{
    return stub<thiscall_t<void, mmCar*, i32>>(0x73D70_Offset, this, arg1);
}

class asBound* mmCar::GetBound()
{
    return stub<thiscall_t<class asBound*, mmCar*>>(0x74870_Offset, this);
}

class MetaClass* mmCar::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmCar*>>(0x747C0_Offset, this);
}

class asInertialCS* mmCar::GetICS()
{
    return stub<thiscall_t<class asInertialCS*, mmCar*>>(0x74860_Offset, this);
}

void mmCar::Impact(class mmIntersection* arg1, class Vector3* arg2, f32 arg3, i32 arg4, class Vector3* arg5)
{
    return stub<thiscall_t<void, mmCar*, class mmIntersection*, class Vector3*, f32, i32, class Vector3*>>(
        0x73EB0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void mmCar::Init(char* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmCar*, char*, i32, i32>>(0x73530_Offset, this, arg1, arg2, arg3);
}

i32 mmCar::IsDrivingDisabled()
{
    return stub<thiscall_t<i32, mmCar*>>(0x73DE0_Offset, this);
}

void mmCar::PostUpdate()
{
    return stub<thiscall_t<void, mmCar*>>(0x73C80_Offset, this);
}

void mmCar::ReInit(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCar*, char*, i32>>(0x73960_Offset, this, arg1, arg2);
}

void mmCar::ReleaseTrailer()
{
    return stub<thiscall_t<void, mmCar*>>(0x73500_Offset, this);
}

void mmCar::RemoveVehicleAudio()
{
    return stub<thiscall_t<void, mmCar*>>(0x73E60_Offset, this);
}

void mmCar::Reset()
{
    return stub<thiscall_t<void, mmCar*>>(0x73B90_Offset, this);
}

void mmCar::StartSiren()
{
    return stub<thiscall_t<void, mmCar*>>(0x73E20_Offset, this);
}

void mmCar::StopSiren()
{
    return stub<thiscall_t<void, mmCar*>>(0x73E40_Offset, this);
}

void mmCar::ToggleSiren()
{
    return stub<thiscall_t<void, mmCar*>>(0x73DF0_Offset, this);
}

void mmCar::TranslateFlags(i32 arg1)
{
    return stub<thiscall_t<void, mmCar*, i32>>(0x734A0_Offset, this, arg1);
}

void mmCar::Update()
{
    return stub<thiscall_t<void, mmCar*>>(0x73C40_Offset, this);
}

char* mmCar::VehNameRemap(char* arg1, i32 arg2)
{
    return stub<thiscall_t<char*, mmCar*, char*, i32>>(0x74340_Offset, this, arg1, arg2);
}

void mmCar::DeclareFields()
{
    return stub<cdecl_t<void>>(0x74640_Offset);
}

i32 EggNameIndex(char* arg1)
{
    return stub<cdecl_t<i32, char*>>(0x742E0_Offset, arg1);
}

define_dummy_symbol(mmcar_car);
