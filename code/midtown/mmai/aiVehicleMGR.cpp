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

define_dummy_symbol(mmai_aiVehicleMGR);

#include "aiVehicleMGR.h"

mmPhysEntity::~mmPhysEntity()
{
    unimplemented(arg1);
}

void mmPhysEntity::PostUpdate()
{
    return stub<thiscall_t<void, mmPhysEntity*>>(0x453B00, this);
}

class asBound* mmPhysEntity::GetBound()
{
    return stub<thiscall_t<class asBound*, mmPhysEntity*>>(0x453B10, this);
}

class asInertialCS* mmPhysEntity::GetICS()
{
    return stub<thiscall_t<class asInertialCS*, mmPhysEntity*>>(0x453B20, this);
}

void mmPhysEntity::DetachMe()
{
    return stub<thiscall_t<void, mmPhysEntity*>>(0x453B30, this);
}

void mmPhysEntity::Update()
{
    return stub<thiscall_t<void, mmPhysEntity*>>(0x453AF0, this);
}

void AMBIENTCB(
    class aiVehicleActive* arg1, class asBound* arg2, class mmIntersection* arg3, class Vector3* arg4, f32 arg5)
{
    return stub<cdecl_t<void, class aiVehicleActive*, class asBound*, class mmIntersection*, class Vector3*, f32>>(
        0x451450, arg1, arg2, arg3, arg4, arg5);
}

aiVehicleInstance::~aiVehicleInstance()
{
    unimplemented(arg1);
}

void aiVehicleInstance::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, aiVehicleInstance*, class Bank*>>(0x45C510, this, arg1);
}

class mmPhysEntity* aiVehicleInstance::AttachEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, aiVehicleInstance*>>(0x451F70, this);
}

void aiVehicleInstance::Detach()
{
    return stub<thiscall_t<void, aiVehicleInstance*>>(0x451F40, this);
}

void __fastcall aiVehicleInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, aiVehicleInstance*, i32>>(0x4515E0, this, arg1);
}

void __fastcall aiVehicleInstance::DrawGlow()
{
    return stub<fastcall_t<void, aiVehicleInstance*>>(0x451E20, this);
}

void __fastcall aiVehicleInstance::DrawShadow()
{
    return stub<fastcall_t<void, aiVehicleInstance*>>(0x451E70, this);
}

void __fastcall aiVehicleInstance::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, aiVehicleInstance*, class Matrix34 const&>>(0x452080, this, arg1);
}

class MetaClass* aiVehicleInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, aiVehicleInstance*>>(0x4536B0, this);
}

class aiVehicleData* aiVehicleInstance::GetData()
{
    return stub<thiscall_t<class aiVehicleData*, aiVehicleInstance*>>(0x453020, this);
}

class mmPhysEntity* aiVehicleInstance::GetEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, aiVehicleInstance*>>(0x451F10, this);
}

class Vector3& __fastcall aiVehicleInstance::GetPos()
{
    return stub<fastcall_t<class Vector3&, aiVehicleInstance*>>(0x4520A0, this);
}

class Vector3 aiVehicleInstance::GetVelocity()
{
    return stub<thiscall_t<class Vector3, aiVehicleInstance*>>(0x451FD0, this);
}

class Matrix34& __fastcall aiVehicleInstance::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, aiVehicleInstance*, class Matrix34&>>(0x452090, this, arg1);
}

void aiVehicleInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x453610);
}

aiVehicleActive::aiVehicleActive()
{
    unimplemented();
}

aiVehicleActive::~aiVehicleActive()
{
    unimplemented(arg1);
}

void aiVehicleActive::PostUpdate()
{
    return stub<thiscall_t<void, aiVehicleActive*>>(0x452950, this);
}

class asBound* aiVehicleActive::GetBound()
{
    return stub<thiscall_t<class asBound*, aiVehicleActive*>>(0x453BA0, this);
}

class asInertialCS* aiVehicleActive::GetICS()
{
    return stub<thiscall_t<class asInertialCS*, aiVehicleActive*>>(0x453BB0, this);
}

void aiVehicleActive::DetachMe()
{
    return stub<thiscall_t<void, aiVehicleActive*>>(0x4526F0, this);
}

void aiVehicleActive::Attach(class aiVehicleInstance* arg1)
{
    return stub<thiscall_t<void, aiVehicleActive*, class aiVehicleInstance*>>(0x452540, this, arg1);
}

void aiVehicleActive::Detach()
{
    return stub<thiscall_t<void, aiVehicleActive*>>(0x452710, this);
}

void aiVehicleActive::Init(char* arg1)
{
    return stub<thiscall_t<void, aiVehicleActive*, char*>>(0x4521A0, this, arg1);
}

void aiVehicleActive::Update()
{
    return stub<thiscall_t<void, aiVehicleActive*>>(0x4528E0, this);
}

void aiVehicleActive::UpdateDamage()
{
    return stub<thiscall_t<void, aiVehicleActive*>>(0x4529D0, this);
}

aiVehicleManager::aiVehicleManager()
{
    unimplemented();
}

aiVehicleManager::~aiVehicleManager()
{
    unimplemented(arg1);
}

i32 aiVehicleManager::AddVehicleDataEntry(char* arg1)
{
    return stub<thiscall_t<i32, aiVehicleManager*, char*>>(0x453040, this, arg1);
}

void aiVehicleManager::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, aiVehicleManager*, class Bank*>>(0x453380, this, arg1);
}

class aiVehicleActive* aiVehicleManager::Attach(class aiVehicleInstance* arg1)
{
    return stub<thiscall_t<class aiVehicleActive*, aiVehicleManager*, class aiVehicleInstance*>>(0x452C20, this, arg1);
}

void aiVehicleManager::Detach(class aiVehicleActive* arg1)
{
    return stub<thiscall_t<void, aiVehicleManager*, class aiVehicleActive*>>(0x452CE0, this, arg1);
}

void aiVehicleManager::Init(char* arg1)
{
    return stub<thiscall_t<void, aiVehicleManager*, char*>>(0x452BB0, this, arg1);
}

void aiVehicleManager::Reset()
{
    return stub<thiscall_t<void, aiVehicleManager*>>(0x452BE0, this);
}

void aiVehicleManager::Save()
{
    return stub<thiscall_t<void, aiVehicleManager*>>(0x453350, this);
}

void aiVehicleManager::Update()
{
    return stub<thiscall_t<void, aiVehicleManager*>>(0x452D70, this);
}

aiVehicleData::aiVehicleData()
{
    unimplemented();
}

aiVehicleData::~aiVehicleData()
{
    unimplemented(arg1);
}

void aiVehicleData::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, aiVehicleData*, class Bank*>>(0x453390, this, arg1);
}

class MetaClass* aiVehicleData::GetClass()
{
    return stub<thiscall_t<class MetaClass*, aiVehicleData*>>(0x4539F0, this);
}

i32 aiVehicleData::LoadEntry(char* arg1)
{
    return stub<thiscall_t<i32, aiVehicleData*, char*>>(0x452E60, this, arg1);
}

void aiVehicleData::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4536C0);
}
