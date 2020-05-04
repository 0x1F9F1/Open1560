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

#include "pointcamcs.h"

PointCamCS::PointCamCS()
{
    unimplemented();
}

PointCamCS::~PointCamCS()
{
    unimplemented();
}

class MetaClass* PointCamCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, PointCamCS*>>(0xFA3F0_Offset, this);
}

class Vector3 PointCamCS::GetPos()
{
    return stub<thiscall_t<class Vector3, PointCamCS*>>(0xF9F70_Offset, this);
}

void PointCamCS::Init(class mmCar* arg1)
{
    return stub<thiscall_t<void, PointCamCS*, class mmCar*>>(0xF9E50_Offset, this, arg1);
}

void PointCamCS::MakeActive()
{
    return stub<thiscall_t<void, PointCamCS*>>(0xF9E90_Offset, this);
}

void PointCamCS::Reset()
{
    return stub<thiscall_t<void, PointCamCS*>>(0xF9E80_Offset, this);
}

void PointCamCS::SetAppRate(f32 arg1)
{
    return stub<thiscall_t<void, PointCamCS*, f32>>(0xF9F40_Offset, this, arg1);
}

void PointCamCS::SetMaxDist(f32 arg1)
{
    return stub<thiscall_t<void, PointCamCS*, f32>>(0xF9F00_Offset, this, arg1);
}

void PointCamCS::SetMinDist(f32 arg1)
{
    return stub<thiscall_t<void, PointCamCS*, f32>>(0xF9F20_Offset, this, arg1);
}

void PointCamCS::SetPos(class Vector3& arg1)
{
    return stub<thiscall_t<void, PointCamCS*, class Vector3&>>(0xF9EC0_Offset, this, arg1);
}

void PointCamCS::SetVel(class Vector3& arg1)
{
    return stub<thiscall_t<void, PointCamCS*, class Vector3&>>(0xF9F50_Offset, this, arg1);
}

void PointCamCS::Update()
{
    return stub<thiscall_t<void, PointCamCS*>>(0xF9FA0_Offset, this);
}

void PointCamCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0xFA280_Offset);
}

define_dummy_symbol(mmcamcs_pointcamcs);
