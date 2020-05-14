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

define_dummy_symbol(mmcamcs_polarcamcs);

#include "polarcamcs.h"

PolarCamCS::PolarCamCS()
{
    unimplemented();
}

PolarCamCS::~PolarCamCS()
{
    unimplemented();
}

class MetaClass* PolarCamCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, PolarCamCS*>>(0x4FB180, this);
}

void PolarCamCS::Init(class mmCar* arg1)
{
    return stub<thiscall_t<void, PolarCamCS*, class mmCar*>>(0x4FABB0, this, arg1);
}

void PolarCamCS::MakeActive()
{
    return stub<thiscall_t<void, PolarCamCS*>>(0x4FABF0, this);
}

void PolarCamCS::Reset()
{
    return stub<thiscall_t<void, PolarCamCS*>>(0x4FABE0, this);
}

void PolarCamCS::Update()
{
    return stub<thiscall_t<void, PolarCamCS*>>(0x4FAC20, this);
}

void PolarCamCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4FB010);
}
