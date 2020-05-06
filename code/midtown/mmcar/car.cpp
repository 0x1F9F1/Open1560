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

define_dummy_symbol(mmcar_car);

#include "car.h"

mmCar::mmCar()
{
    unimplemented();
}

mmCar::~mmCar()
{
    unimplemented(arg1);
}

void mmCar::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmCar*, class Bank*>>(0x4745E0, this, arg1);
}

void mmCar::ClearDamage()
{
    return stub<thiscall_t<void, mmCar*>>(0x473E70, this);
}

void mmCar::EnableDriving(i32 arg1)
{
    return stub<thiscall_t<void, mmCar*, i32>>(0x473D70, this, arg1);
}

class asBound* mmCar::GetBound()
{
    return stub<thiscall_t<class asBound*, mmCar*>>(0x474870, this);
}

class MetaClass* mmCar::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmCar*>>(0x4747C0, this);
}

class asInertialCS* mmCar::GetICS()
{
    return stub<thiscall_t<class asInertialCS*, mmCar*>>(0x474860, this);
}

void mmCar::Impact(class mmIntersection* arg1, class Vector3* arg2, f32 arg3, i32 arg4, class Vector3* arg5)
{
    return stub<thiscall_t<void, mmCar*, class mmIntersection*, class Vector3*, f32, i32, class Vector3*>>(
        0x473EB0, this, arg1, arg2, arg3, arg4, arg5);
}

void mmCar::Init(char* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmCar*, char*, i32, i32>>(0x473530, this, arg1, arg2, arg3);
}

i32 mmCar::IsDrivingDisabled()
{
    return stub<thiscall_t<i32, mmCar*>>(0x473DE0, this);
}

void mmCar::PostUpdate()
{
    return stub<thiscall_t<void, mmCar*>>(0x473C80, this);
}

void mmCar::ReInit(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCar*, char*, i32>>(0x473960, this, arg1, arg2);
}

void mmCar::ReleaseTrailer()
{
    return stub<thiscall_t<void, mmCar*>>(0x473500, this);
}

void mmCar::RemoveVehicleAudio()
{
    return stub<thiscall_t<void, mmCar*>>(0x473E60, this);
}

void mmCar::Reset()
{
    return stub<thiscall_t<void, mmCar*>>(0x473B90, this);
}

void mmCar::StartSiren()
{
    return stub<thiscall_t<void, mmCar*>>(0x473E20, this);
}

void mmCar::StopSiren()
{
    return stub<thiscall_t<void, mmCar*>>(0x473E40, this);
}

void mmCar::ToggleSiren()
{
    return stub<thiscall_t<void, mmCar*>>(0x473DF0, this);
}

void mmCar::TranslateFlags(i32 arg1)
{
    return stub<thiscall_t<void, mmCar*, i32>>(0x4734A0, this, arg1);
}

void mmCar::Update()
{
    return stub<thiscall_t<void, mmCar*>>(0x473C40, this);
}

char* mmCar::VehNameRemap(char* arg1, i32 arg2)
{
    return stub<thiscall_t<char*, mmCar*, char*, i32>>(0x474340, this, arg1, arg2);
}

void mmCar::DeclareFields()
{
    return stub<cdecl_t<void>>(0x474640);
}

i32 EggNameIndex(char* arg1)
{
    return stub<cdecl_t<i32, char*>>(0x4742E0, arg1);
}
