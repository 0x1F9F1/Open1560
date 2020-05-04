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

#include "drivetrain.h"

mmDrivetrain::mmDrivetrain()
{
    unimplemented();
}

mmDrivetrain::~mmDrivetrain()
{
    unimplemented();
}

i32 mmDrivetrain::AddWheel(class mmWheel* arg1)
{
    return stub<thiscall_t<i32, mmDrivetrain*, class mmWheel*>>(0x7FEF0_Offset, this, arg1);
}

void mmDrivetrain::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmDrivetrain*, class Bank*>>(0x803E0_Offset, this, arg1);
}

void mmDrivetrain::Attach()
{
    return stub<thiscall_t<void, mmDrivetrain*>>(0x7FEC0_Offset, this);
}

void mmDrivetrain::Detach()
{
    return stub<thiscall_t<void, mmDrivetrain*>>(0x7FEE0_Offset, this);
}

class MetaClass* mmDrivetrain::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmDrivetrain*>>(0x805E0_Offset, this);
}

void mmDrivetrain::Init(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmDrivetrain*, class mmCarSim*>>(0x7FE90_Offset, this, arg1);
}

void mmDrivetrain::Reset()
{
    return stub<thiscall_t<void, mmDrivetrain*>>(0x80650_Offset, this);
}

void mmDrivetrain::Update()
{
    return stub<thiscall_t<void, mmDrivetrain*>>(0x7FF30_Offset, this);
}

void mmDrivetrain::DeclareFields()
{
    return stub<cdecl_t<void>>(0x80460_Offset);
}

define_dummy_symbol(mmcar_drivetrain);
