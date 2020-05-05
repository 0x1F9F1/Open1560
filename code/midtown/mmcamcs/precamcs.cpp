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

define_dummy_symbol(mmcamcs_precamcs);

#include "precamcs.h"

PreCamCS::PreCamCS()
{
    unimplemented();
}

PreCamCS::~PreCamCS()
{
    unimplemented(arg1);
}

void PreCamCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, PreCamCS*, class Bank*>>(0xF9B20_Offset, this, arg1);
}

class MetaClass* PreCamCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, PreCamCS*>>(0xF9D80_Offset, this);
}

void PreCamCS::Init(class mmCar* arg1)
{
    return stub<thiscall_t<void, PreCamCS*, class mmCar*>>(0xF9A30_Offset, this, arg1);
}

void PreCamCS::MakeActive()
{
    return stub<thiscall_t<void, PreCamCS*>>(0xF9A70_Offset, this);
}

void PreCamCS::Reset()
{
    return stub<thiscall_t<void, PreCamCS*>>(0xF9A60_Offset, this);
}

void PreCamCS::Update()
{
    return stub<thiscall_t<void, PreCamCS*>>(0xF9AC0_Offset, this);
}

void PreCamCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0xF9C10_Offset);
}
