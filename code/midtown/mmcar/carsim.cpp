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

define_dummy_symbol(mmcar_carsim);

#include "carsim.h"

void IMPACTCB(class mmCarSim* arg1, class asBound* arg2, class mmIntersection* arg3, class Vector3* arg4, f32 arg5,
    class Vector3* arg6)
{
    return stub<
        cdecl_t<void, class mmCarSim*, class asBound*, class mmIntersection*, class Vector3*, f32, class Vector3*>>(
        0x46B8F0, arg1, arg2, arg3, arg4, arg5, arg6);
}

struct MetaType* Struct(class MetaClass* arg1)
{
    return stub<cdecl_t<struct MetaType*, class MetaClass*>>(0x4703A0, arg1);
}

mmCarSim::mmCarSim()
{
    unimplemented();
}

mmCarSim::~mmCarSim()
{
    unimplemented(arg1);
}

void mmCarSim::AddPlayerSpecifics()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46C340, this);
}

void mmCarSim::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmCarSim*, class Bank*>>(0x46E840, this, arg1);
}

void mmCarSim::AfterLoad()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46D540, this);
}

void mmCarSim::BeforeSave()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46D600, this);
}

void mmCarSim::ConfigureDrivetrain()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46D080, this);
}

void mmCarSim::Explode()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46E080, this);
}

class MetaClass* mmCarSim::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmCarSim*>>(0x4701A0, this);
}

void mmCarSim::Init(char* arg1, class mmCar* arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmCarSim*, char*, class mmCar*, i32>>(0x46C500, this, arg1, arg2, arg3);
}

void mmCarSim::InitPtx()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46F5B0, this);
}

i32 mmCarSim::OnGround()
{
    return stub<thiscall_t<i32, mmCarSim*>>(0x46BFF0, this);
}

void mmCarSim::PlayHorn()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46C3C0, this);
}

void mmCarSim::PlayImpactAudio(i16 arg1, class mmIntersection* arg2, class Vector3* arg3)
{
    return stub<thiscall_t<void, mmCarSim*, i16, class mmIntersection*, class Vector3*>>(
        0x46FAA0, this, arg1, arg2, arg3);
}

void mmCarSim::ReInit(char* arg1)
{
    return stub<thiscall_t<void, mmCarSim*, char*>>(0x46CB20, this, arg1);
}

void mmCarSim::ReconfigureDrivetrain()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46D060, this);
}

void mmCarSim::RemoveNetVehicleAudio()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46E830, this);
}

void mmCarSim::Reset()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46D6B0, this);
}

void mmCarSim::RestoreImpactParams()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46D020, this);
}

void mmCarSim::SetHackedImpactParams()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46D040, this);
}

void mmCarSim::SetResetPos(class Vector3& arg1)
{
    return stub<thiscall_t<void, mmCarSim*, class Vector3&>>(0x46D500, this, arg1);
}

i32 mmCarSim::ShouldSkid()
{
    return stub<thiscall_t<i32, mmCarSim*>>(0x46E7E0, this);
}

void mmCarSim::StartSiren()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46C4A0, this);
}

void mmCarSim::StopHorn()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46C430, this);
}

void mmCarSim::StopSiren()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46C4D0, this);
}

void mmCarSim::UnconfigureDrivetrain()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46D300, this);
}

void mmCarSim::Update()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46D860, this);
}

void mmCarSim::UpdateDamage()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46E270, this);
}

void mmCarSim::UpdateExhaust()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46E160, this);
}

void mmCarSim::UpdateFF()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46E520, this);
}

void mmCarSim::UpdateICSParams()
{
    return stub<thiscall_t<void, mmCarSim*>>(0x46D680, this);
}

void mmCarSim::DeclareFields()
{
    return stub<cdecl_t<void>>(0x46FBC0);
}

void mmCarSim::SetGlobalTuning(f32 arg1, f32 arg2)
{
    return stub<cdecl_t<void, f32, f32>>(0x46C030, arg1, arg2);
}
