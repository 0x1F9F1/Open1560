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

define_dummy_symbol(mmcamcs_trackcamcs);

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
    return stub<thiscall_t<void, TrackCamCS*, class Bank*>>(0x4F6DE0, this, arg1);
}

void TrackCamCS::AfterLoad()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0x4F6D90, this);
}

class MetaClass* TrackCamCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, TrackCamCS*>>(0x4F8F00, this);
}

void TrackCamCS::MakeActive()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0x4F6D50, this);
}

void TrackCamCS::Reset()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0x4F6DA0, this);
}

void TrackCamCS::SwingToRear()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0x4F8A70, this);
}

void TrackCamCS::Update()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0x4F7270, this);
}

void TrackCamCS::UpdateInput()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0x4F7350, this);
}

void TrackCamCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4F8BE0);
}

void TrackCamCS::Collide(class Vector3 arg1)
{
    return stub<thiscall_t<void, TrackCamCS*, class Vector3>>(0x4F85D0, this, arg1);
}

void TrackCamCS::Front(f32 arg1)
{
    return stub<thiscall_t<void, TrackCamCS*, f32>>(0x4F8AE0, this, arg1);
}

void TrackCamCS::MinMax(class Matrix34 arg1)
{
    return stub<thiscall_t<void, TrackCamCS*, class Matrix34>>(0x4F8430, this, arg1);
}

void TrackCamCS::PreApproach()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0x4F8230, this);
}

void TrackCamCS::Rear(f32 arg1)
{
    return stub<thiscall_t<void, TrackCamCS*, f32>>(0x4F8B60, this, arg1);
}

void TrackCamCS::UpdateCar()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0x4F7360, this);
}

void TrackCamCS::UpdateHill()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0x4F7500, this);
}

void TrackCamCS::UpdateSwing()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0x4F7E50, this);
}

void TrackCamCS::UpdateTrack()
{
    return stub<thiscall_t<void, TrackCamCS*>>(0x4F7510, this);
}
