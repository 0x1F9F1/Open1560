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

#include "vselect.h"

VehicleSelectBase::VehicleSelectBase(i32 arg1)
{
    unimplemented();
}

VehicleSelectBase::~VehicleSelectBase()
{
    unimplemented();
}

void VehicleSelectBase::AllSetCar(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, VehicleSelectBase*, char*, i32>>(0x9B990_Offset, this, arg1, arg2);
}

void VehicleSelectBase::AssignVehicleStats(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, VehicleSelectBase*, i32, f32, f32, f32, f32>>(
        0x9C000_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void VehicleSelectBase::CarMod(i32& arg1)
{
    return stub<thiscall_t<void, VehicleSelectBase*, i32&>>(0x9BC50_Offset, this, arg1);
}

void VehicleSelectBase::ColorCB()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9AA70_Offset, this);
}

i32 VehicleSelectBase::CurrentVehicleIsLocked()
{
    return stub<thiscall_t<i32, VehicleSelectBase*>>(0x9BBD0_Offset, this);
}

void VehicleSelectBase::DecCar()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9C500_Offset, this);
}

void VehicleSelectBase::DecColor()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9A9B0_Offset, this);
}

void VehicleSelectBase::FillStats()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9C1E0_Offset, this);
}

char* VehicleSelectBase::GetCarTitle(i32 arg1, char* arg2, i16 arg3, class string* arg4)
{
    return stub<thiscall_t<char*, VehicleSelectBase*, i32, char*, i16, class string*>>(
        0x9BAA0_Offset, this, arg1, arg2, arg3, arg4);
}

void VehicleSelectBase::IncCar()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9C510_Offset, this);
}

void VehicleSelectBase::IncColor()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9A8F0_Offset, this);
}

void VehicleSelectBase::InitCarSelection(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, VehicleSelectBase*, i32, f32, f32, f32, f32>>(
        0x9AA90_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

i32 VehicleSelectBase::LoadStats(char* arg1)
{
    return stub<thiscall_t<i32, VehicleSelectBase*, char*>>(0x9BF60_Offset, this, arg1);
}

void VehicleSelectBase::PostSetup()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9B960_Offset, this);
}

void VehicleSelectBase::PreSetup()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9B870_Offset, this);
}

void VehicleSelectBase::Reset()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9B9F0_Offset, this);
}

void VehicleSelectBase::SetLastUnlockedVehicle()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9BBF0_Offset, this);
}

void VehicleSelectBase::SetLockedLabel()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9C230_Offset, this);
}

void VehicleSelectBase::SetPick(i32 arg1, i16 arg2)
{
    return stub<thiscall_t<void, VehicleSelectBase*, i32, i16>>(0x9BC80_Offset, this, arg1, arg2);
}

void VehicleSelectBase::SetShowcaseFlag()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9C520_Offset, this);
}

void VehicleSelectBase::TDPickCB()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9B9E0_Offset, this);
}

void VehicleSelectBase::Update()
{
    return stub<thiscall_t<void, VehicleSelectBase*>>(0x9BA00_Offset, this);
}

define_dummy_symbol(mmui_vselect);
