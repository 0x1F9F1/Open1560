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

define_dummy_symbol(mmcamcs_povcamcs);

#include "povcamcs.h"

PovCamCS::PovCamCS()
{
    unimplemented();
}

PovCamCS::~PovCamCS()
{
    unimplemented(arg1);
}

void PovCamCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, PovCamCS*, class Bank*>>(0x4F6460, this, arg1);
}

void PovCamCS::AfterLoad()
{
    return stub<thiscall_t<void, PovCamCS*>>(0x4F6410, this);
}

class MetaClass* PovCamCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, PovCamCS*>>(0x4F69B0, this);
}

void PovCamCS::MakeActive()
{
    return stub<thiscall_t<void, PovCamCS*>>(0x4F63C0, this);
}

void PovCamCS::Reset()
{
    return stub<thiscall_t<void, PovCamCS*>>(0x4F6420, this);
}

void PovCamCS::Update()
{
    return stub<thiscall_t<void, PovCamCS*>>(0x4F6530, this);
}

void PovCamCS::UpdateInput()
{
    return stub<thiscall_t<void, PovCamCS*>>(0x4F6550, this);
}

void PovCamCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4F6800);
}

void PovCamCS::UpdatePOV()
{
    return stub<thiscall_t<void, PovCamCS*>>(0x4F6560, this);
}
