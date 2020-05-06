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

define_dummy_symbol(mmcar_drivetrain);

#include "drivetrain.h"

mmDrivetrain::mmDrivetrain()
{
    unimplemented();
}

mmDrivetrain::~mmDrivetrain()
{
    unimplemented(arg1);
}

i32 mmDrivetrain::AddWheel(class mmWheel* arg1)
{
    return stub<thiscall_t<i32, mmDrivetrain*, class mmWheel*>>(0x47FEF0, this, arg1);
}

void mmDrivetrain::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmDrivetrain*, class Bank*>>(0x4803E0, this, arg1);
}

void mmDrivetrain::Attach()
{
    return stub<thiscall_t<void, mmDrivetrain*>>(0x47FEC0, this);
}

void mmDrivetrain::Detach()
{
    return stub<thiscall_t<void, mmDrivetrain*>>(0x47FEE0, this);
}

class MetaClass* mmDrivetrain::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmDrivetrain*>>(0x4805E0, this);
}

void mmDrivetrain::Init(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmDrivetrain*, class mmCarSim*>>(0x47FE90, this, arg1);
}

void mmDrivetrain::Reset()
{
    return stub<thiscall_t<void, mmDrivetrain*>>(0x480650, this);
}

void mmDrivetrain::Update()
{
    return stub<thiscall_t<void, mmDrivetrain*>>(0x47FF30, this);
}

void mmDrivetrain::DeclareFields()
{
    return stub<cdecl_t<void>>(0x480460);
}
