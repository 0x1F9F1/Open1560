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

#include "control.h"

ControlSetup::ControlSetup(i32 arg1)
{
    unimplemented();
}

ControlSetup::~ControlSetup()
{
    unimplemented();
}

void ControlSetup::ActivateDeviceOptions()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA3210_Offset, this);
}

void ControlSetup::BadAssignCB()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA38A0_Offset, this);
}

void ControlSetup::CancelAction()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA3880_Offset, this);
}

void ControlSetup::CancelBadAssignment()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA38E0_Offset, this);
}

void ControlSetup::ClearBadAssignment()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA38D0_Offset, this);
}

void ControlSetup::ControlSelect()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA3530_Offset, this);
}

void ControlSetup::CreateDeviceOptions()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA2EF0_Offset, this);
}

void ControlSetup::DeactivateAllDeviceOptions()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA31B0_Offset, this);
}

void ControlSetup::DoneAction()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA3890_Offset, this);
}

void ControlSetup::InitCustomControls()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA35F0_Offset, this);
}

void ControlSetup::LaunchJoyCpl()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA36F0_Offset, this);
}

void ControlSetup::POVCB()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA3510_Offset, this);
}

void ControlSetup::PreSetup()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA3580_Offset, this);
}

void ControlSetup::ResetDefaultAction()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA36B0_Offset, this);
}

f32 ControlSetup::SetControlPosition(class uiWidget* arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<f32, ControlSetup*, class uiWidget*, f32, f32>>(0xA34F0_Offset, this, arg1, arg2, arg3);
}

void ControlSetup::SetFFPermissions()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA35B0_Offset, this);
}

void ControlSetup::SetSensitivityCB()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA3520_Offset, this);
}

void ControlSetup::StoreCurrentSetup()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA36A0_Offset, this);
}

void ControlSetup::Update()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA3680_Offset, this);
}

void ControlSetup::VerifyBadAssignment()
{
    return stub<thiscall_t<void, ControlSetup*>>(0xA3900_Offset, this);
}

define_dummy_symbol(mmui_control);
