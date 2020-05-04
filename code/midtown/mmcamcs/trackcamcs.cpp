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

#include "trackcamcs.h"

TrackCamCS::TrackCamCS()
{
    unimplemented();
}

TrackCamCS::~TrackCamCS()
{
    unimplemented();
}

void TrackCamCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, TrackCamCS*, class Bank*>>(0xF6DE0_Offset, this, arg1);
}

void TrackCamCS::AfterLoad()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0xF6D90_Offset, this);
}

class MetaClass* TrackCamCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, TrackCamCS*>>(0xF8F00_Offset, this);
}

void TrackCamCS::MakeActive()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0xF6D50_Offset, this);
}

void TrackCamCS::Reset()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0xF6DA0_Offset, this);
}

void TrackCamCS::SwingToRear()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0xF8A70_Offset, this);
}

void TrackCamCS::Update()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0xF7270_Offset, this);
}

void TrackCamCS::UpdateInput()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0xF7350_Offset, this);
}

void TrackCamCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0xF8BE0_Offset);
}

void TrackCamCS::Collide(class Vector3 arg1)
{
    return stub<thiscall_t<void, TrackCamCS*, class Vector3>>(0xF85D0_Offset, this, arg1);
}

void TrackCamCS::Front(f32 arg1)
{
    return stub<thiscall_t<void, TrackCamCS*, f32>>(0xF8AE0_Offset, this, arg1);
}

void TrackCamCS::MinMax(class Matrix34 arg1)
{
    return stub<thiscall_t<void, TrackCamCS*, class Matrix34>>(0xF8430_Offset, this, arg1);
}

void TrackCamCS::PreApproach()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0xF8230_Offset, this);
}

void TrackCamCS::Rear(f32 arg1)
{
    return stub<thiscall_t<void, TrackCamCS*, f32>>(0xF8B60_Offset, this, arg1);
}

void TrackCamCS::UpdateCar()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0xF7360_Offset, this);
}

void TrackCamCS::UpdateHill()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0xF7500_Offset, this);
}

void TrackCamCS::UpdateSwing()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0xF7E50_Offset, this);
}

void TrackCamCS::UpdateTrack()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0xF7510_Offset, this);
}

define_dummy_symbol(mmcamcs_trackcamcs);
