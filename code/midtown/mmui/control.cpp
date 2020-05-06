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

define_dummy_symbol(mmui_control);

#include "control.h"

ControlSetup::ControlSetup(i32 arg1)
{
    unimplemented(arg1);
}

ControlSetup::~ControlSetup()
{
    unimplemented(arg1);
}

void ControlSetup::ActivateDeviceOptions()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A3210, this);
}

void ControlSetup::BadAssignCB()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A38A0, this);
}

void ControlSetup::CancelAction()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A3880, this);
}

void ControlSetup::CancelBadAssignment()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A38E0, this);
}

void ControlSetup::ClearBadAssignment()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A38D0, this);
}

void ControlSetup::ControlSelect()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A3530, this);
}

void ControlSetup::CreateDeviceOptions()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A2EF0, this);
}

void ControlSetup::DeactivateAllDeviceOptions()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A31B0, this);
}

void ControlSetup::DoneAction()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A3890, this);
}

void ControlSetup::InitCustomControls()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A35F0, this);
}

void ControlSetup::LaunchJoyCpl()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A36F0, this);
}

void ControlSetup::POVCB()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A3510, this);
}

void ControlSetup::PreSetup()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A3580, this);
}

void ControlSetup::ResetDefaultAction()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A36B0, this);
}

f32 ControlSetup::SetControlPosition(class uiWidget* arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<f32, ControlSetup*, class uiWidget*, f32, f32>>(0x4A34F0, this, arg1, arg2, arg3);
}

void ControlSetup::SetFFPermissions()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A35B0, this);
}

void ControlSetup::SetSensitivityCB()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A3520, this);
}

void ControlSetup::StoreCurrentSetup()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A36A0, this);
}

void ControlSetup::Update()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A3680, this);
}

void ControlSetup::VerifyBadAssignment()
{
    return stub<thiscall_t<void, ControlSetup*>>(0x4A3900, this);
}
