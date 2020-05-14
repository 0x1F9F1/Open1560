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

define_dummy_symbol(mmui_vselect);

#include "vselect.h"

VehicleSelectBase::VehicleSelectBase(i32 arg1)
{
    unimplemented(arg1);
}

VehicleSelectBase::~VehicleSelectBase()
{
    unimplemented();
}

void VehicleSelectBase::AllSetCar(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, VehicleSelectBase*, char*, i32>>(0x49B990, this, arg1, arg2);
}

void VehicleSelectBase::AssignVehicleStats(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, VehicleSelectBase*, i32, f32, f32, f32, f32>>(
        0x49C000, this, arg1, arg2, arg3, arg4, arg5);
}

void VehicleSelectBase::CarMod(i32& arg1)
{
    return stub<thiscall_t<void, VehicleSelectBase*, i32&>>(0x49BC50, this, arg1);
}

void VehicleSelectBase::ColorCB()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49AA70, this);
}

i32 VehicleSelectBase::CurrentVehicleIsLocked()
{
    return stub<thiscall_t<i32, VehicleSelectBase*>>(0x49BBD0, this);
}

void VehicleSelectBase::DecCar()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49C500, this);
}

void VehicleSelectBase::DecColor()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49A9B0, this);
}

void VehicleSelectBase::FillStats()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49C1E0, this);
}

char* VehicleSelectBase::GetCarTitle(i32 arg1, char* arg2, i16 arg3, class string* arg4)
{
    return stub<thiscall_t<char*, VehicleSelectBase*, i32, char*, i16, class string*>>(
        0x49BAA0, this, arg1, arg2, arg3, arg4);
}

void VehicleSelectBase::IncCar()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49C510, this);
}

void VehicleSelectBase::IncColor()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49A8F0, this);
}

void VehicleSelectBase::InitCarSelection(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, VehicleSelectBase*, i32, f32, f32, f32, f32>>(
        0x49AA90, this, arg1, arg2, arg3, arg4, arg5);
}

i32 VehicleSelectBase::LoadStats(char* arg1)
{
    return stub<thiscall_t<i32, VehicleSelectBase*, char*>>(0x49BF60, this, arg1);
}

void VehicleSelectBase::PostSetup()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49B960, this);
}

void VehicleSelectBase::PreSetup()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49B870, this);
}

void VehicleSelectBase::Reset()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49B9F0, this);
}

void VehicleSelectBase::SetLastUnlockedVehicle()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49BBF0, this);
}

void VehicleSelectBase::SetLockedLabel()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49C230, this);
}

void VehicleSelectBase::SetPick(i32 arg1, i16 arg2)
{
    return stub<thiscall_t<void, VehicleSelectBase*, i32, i16>>(0x49BC80, this, arg1, arg2);
}

void VehicleSelectBase::SetShowcaseFlag()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49C520, this);
}

void VehicleSelectBase::TDPickCB()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49B9E0, this);
}

void VehicleSelectBase::Update()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x49BA00, this);
}
