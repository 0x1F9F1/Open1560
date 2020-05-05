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

define_dummy_symbol(mmcar_gyro);

#include "gyro.h"

VehGyro::VehGyro()
{
    unimplemented();
}

VehGyro::~VehGyro()
{
    unimplemented(arg1);
}

void VehGyro::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, VehGyro*, class Bank*>>(0x80930_Offset, this, arg1);
}

class MetaClass* VehGyro::GetClass()
{
    return stub<thiscall_t<class MetaClass*, VehGyro*>>(0x80B70_Offset, this);
}

void VehGyro::Load(class Stream* arg1)
{
    return stub<thiscall_t<void, VehGyro*, class Stream*>>(0x80690_Offset, this, arg1);
}

void VehGyro::Save(class Stream* arg1)
{
    return stub<thiscall_t<void, VehGyro*, class Stream*>>(0x80700_Offset, this, arg1);
}

void VehGyro::Update()
{
    return stub<thiscall_t<void, VehGyro*>>(0x80780_Offset, this);
}

void VehGyro::DeclareFields()
{
    return stub<cdecl_t<void>>(0x809E0_Offset);
}
