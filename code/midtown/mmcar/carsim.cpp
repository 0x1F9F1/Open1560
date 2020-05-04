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

#include "carsim.h"

void IMPACTCB(class mmCarSim* arg1, class asBound* arg2, class mmIntersection* arg3, class Vector3* arg4, f32 arg5,
    class Vector3* arg6)
{
    return stub<
        cdecl_t<void, class mmCarSim*, class asBound*, class mmIntersection*, class Vector3*, f32, class Vector3*>>(
        0x6B8F0_Offset, arg1, arg2, arg3, arg4, arg5, arg6);
}

struct MetaType* Struct(class MetaClass* arg1)
{
    return stub<cdecl_t<struct MetaType*, class MetaClass*>>(0x703A0_Offset, arg1);
}

mmCarSim::mmCarSim()
{
    unimplemented();
}

mmCarSim::~mmCarSim()
{
    unimplemented();
}

void mmCarSim::AddPlayerSpecifics()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6C340_Offset, this);
}

void mmCarSim::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmCarSim*, class Bank*>>(0x6E840_Offset, this, arg1);
}

void mmCarSim::AfterLoad()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6D540_Offset, this);
}

void mmCarSim::BeforeSave()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6D600_Offset, this);
}

void mmCarSim::ConfigureDrivetrain()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6D080_Offset, this);
}

void mmCarSim::Explode()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6E080_Offset, this);
}

class MetaClass* mmCarSim::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmCarSim*>>(0x701A0_Offset, this);
}

void mmCarSim::Init(char* arg1, class mmCar* arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmCarSim*, char*, class mmCar*, i32>>(0x6C500_Offset, this, arg1, arg2, arg3);
}

void mmCarSim::InitPtx()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6F5B0_Offset, this);
}

i32 mmCarSim::OnGround()
{
    return stub<thiscall_t<i32, mmCarSim*>>(0x6BFF0_Offset, this);
}

void mmCarSim::PlayHorn()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6C3C0_Offset, this);
}

void mmCarSim::PlayImpactAudio(i16 arg1, class mmIntersection* arg2, class Vector3* arg3)
{
    return stub<thiscall_t<void, mmCarSim*, i16, class mmIntersection*, class Vector3*>>(
        0x6FAA0_Offset, this, arg1, arg2, arg3);
}

void mmCarSim::ReInit(char* arg1)
{
    return stub<thiscall_t<void, mmCarSim*, char*>>(0x6CB20_Offset, this, arg1);
}

void mmCarSim::ReconfigureDrivetrain()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6D060_Offset, this);
}

void mmCarSim::RemoveNetVehicleAudio()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6E830_Offset, this);
}

void mmCarSim::Reset()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6D6B0_Offset, this);
}

void mmCarSim::RestoreImpactParams()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6D020_Offset, this);
}

void mmCarSim::SetHackedImpactParams()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6D040_Offset, this);
}

void mmCarSim::SetResetPos(class Vector3& arg1)
{
    return stub<thiscall_t<void, mmCarSim*, class Vector3&>>(0x6D500_Offset, this, arg1);
}

i32 mmCarSim::ShouldSkid()
{
    return stub<thiscall_t<i32, mmCarSim*>>(0x6E7E0_Offset, this);
}

void mmCarSim::StartSiren()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6C4A0_Offset, this);
}

void mmCarSim::StopHorn()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6C430_Offset, this);
}

void mmCarSim::StopSiren()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6C4D0_Offset, this);
}

void mmCarSim::UnconfigureDrivetrain()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6D300_Offset, this);
}

void mmCarSim::Update()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6D860_Offset, this);
}

void mmCarSim::UpdateDamage()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6E270_Offset, this);
}

void mmCarSim::UpdateExhaust()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6E160_Offset, this);
}

void mmCarSim::UpdateFF()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6E520_Offset, this);
}

void mmCarSim::UpdateICSParams()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x6D680_Offset, this);
}

void mmCarSim::DeclareFields()
{
    return stub<cdecl_t<void>>(0x6FBC0_Offset);
}

void mmCarSim::SetGlobalTuning(f32 arg1, f32 arg2)
{
    return stub<cdecl_t<void, f32, f32>>(0x6C030_Offset, arg1, arg2);
}

define_dummy_symbol(mmcar_carsim);
