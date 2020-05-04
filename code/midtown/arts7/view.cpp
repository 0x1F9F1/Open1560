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

#include "view.h"

asViewCS::asViewCS()
{
    unimplemented();
}

asViewCS::~asViewCS()
{
    unimplemented();
}

void asViewCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asViewCS*, class Bank*>>(0x12C780_Offset, this, arg1);
}

void asViewCS::FileIO(class MiniParser* arg1)
{
    return stub<thiscall_t<void, asViewCS*, class MiniParser*>>(0x12C770_Offset, this, arg1);
}

class MetaClass* asViewCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asViewCS*>>(0x12CDE0_Offset, this);
}

void asViewCS::Reset()
{
    return stub<thiscall_t<void, asViewCS*>>(0x12BD30_Offset, this);
}

void asViewCS::SetAzimuth()
{
    return stub<thiscall_t<void, asViewCS*>>(0x12BCD0_Offset, this);
}

void asViewCS::Update()
{
    return stub<thiscall_t<void, asViewCS*>>(0x12BF00_Offset, this);
}

void asViewCS::UpdateLookAt()
{
    return stub<thiscall_t<void, asViewCS*>>(0x12C220_Offset, this);
}

void asViewCS::UpdatePOV()
{
    return stub<thiscall_t<void, asViewCS*>>(0x12C1D0_Offset, this);
}

void asViewCS::UpdatePolar()
{
    return stub<thiscall_t<void, asViewCS*>>(0x12BF80_Offset, this);
}

void asViewCS::UpdateRoam()
{
    return stub<thiscall_t<void, asViewCS*>>(0x12C0C0_Offset, this);
}

void asViewCS::UpdateStereo()
{
    return stub<thiscall_t<void, asViewCS*>>(0x12C640_Offset, this);
}

void asViewCS::UpdateTrack()
{
    return stub<thiscall_t<void, asViewCS*>>(0x12C280_Offset, this);
}

void asViewCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x12CC70_Offset);
}

define_dummy_symbol(arts7_view);
