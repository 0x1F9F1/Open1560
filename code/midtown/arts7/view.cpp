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

define_dummy_symbol(arts7_view);

#include "view.h"

asViewCS::asViewCS()
{
    unimplemented();
}

asViewCS::~asViewCS()
{
    unimplemented(arg1);
}

void asViewCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asViewCS*, class Bank*>>(0x52C780, this, arg1);
}

void asViewCS::FileIO(class MiniParser* arg1)
{
    return stub<thiscall_t<void, asViewCS*, class MiniParser*>>(0x52C770, this, arg1);
}

class MetaClass* asViewCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asViewCS*>>(0x52CDE0, this);
}

void asViewCS::Reset()
{
    return stub<thiscall_t<void, asViewCS*>>(0x52BD30, this);
}

void asViewCS::SetAzimuth()
{
    return stub<thiscall_t<void, asViewCS*>>(0x52BCD0, this);
}

void asViewCS::Update()
{
    return stub<thiscall_t<void, asViewCS*>>(0x52BF00, this);
}

void asViewCS::UpdateLookAt()
{
    return stub<thiscall_t<void, asViewCS*>>(0x52C220, this);
}

void asViewCS::UpdatePOV()
{
    return stub<thiscall_t<void, asViewCS*>>(0x52C1D0, this);
}

void asViewCS::UpdatePolar()
{
    return stub<thiscall_t<void, asViewCS*>>(0x52BF80, this);
}

void asViewCS::UpdateRoam()
{
    return stub<thiscall_t<void, asViewCS*>>(0x52C0C0, this);
}

void asViewCS::UpdateStereo()
{
    return stub<thiscall_t<void, asViewCS*>>(0x52C640, this);
}

void asViewCS::UpdateTrack()
{
    return stub<thiscall_t<void, asViewCS*>>(0x52C280, this);
}

void asViewCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x52CC70);
}
