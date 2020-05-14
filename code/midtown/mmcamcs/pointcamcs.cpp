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

define_dummy_symbol(mmcamcs_pointcamcs);

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
    return stub<thiscall_t<class MetaClass*, PointCamCS*>>(0x4FA3F0, this);
}

class Vector3 PointCamCS::GetPos()
{
    return stub<thiscall_t<class Vector3, PointCamCS*>>(0x4F9F70, this);
}

void PointCamCS::Init(class mmCar* arg1)
{
    return stub<thiscall_t<void, PointCamCS*, class mmCar*>>(0x4F9E50, this, arg1);
}

void PointCamCS::MakeActive()
{
    return stub<thiscall_t<void, PointCamCS*>>(0x4F9E90, this);
}

void PointCamCS::Reset()
{
    return stub<thiscall_t<void, PointCamCS*>>(0x4F9E80, this);
}

void PointCamCS::SetAppRate(f32 arg1)
{
    return stub<thiscall_t<void, PointCamCS*, f32>>(0x4F9F40, this, arg1);
}

void PointCamCS::SetMaxDist(f32 arg1)
{
    return stub<thiscall_t<void, PointCamCS*, f32>>(0x4F9F00, this, arg1);
}

void PointCamCS::SetMinDist(f32 arg1)
{
    return stub<thiscall_t<void, PointCamCS*, f32>>(0x4F9F20, this, arg1);
}

void PointCamCS::SetPos(class Vector3& arg1)
{
    return stub<thiscall_t<void, PointCamCS*, class Vector3&>>(0x4F9EC0, this, arg1);
}

void PointCamCS::SetVel(class Vector3& arg1)
{
    return stub<thiscall_t<void, PointCamCS*, class Vector3&>>(0x4F9F50, this, arg1);
}

void PointCamCS::Update()
{
    return stub<thiscall_t<void, PointCamCS*>>(0x4F9FA0, this);
}

void PointCamCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4FA280);
}
