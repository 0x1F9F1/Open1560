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

define_dummy_symbol(mmcamcs_carcamcs);

#include "carcamcs.h"

CarCamCS::CarCamCS()
{
    unimplemented();
}

CarCamCS::~CarCamCS()
{
    unimplemented();
}

void CarCamCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, CarCamCS*, class Bank*>>(0x4FB280, this, arg1);
}

class MetaClass* CarCamCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, CarCamCS*>>(0x4FB400, this);
}

void CarCamCS::Init(class mmCar* arg1, char* arg2)
{
    return stub<thiscall_t<void, CarCamCS*, class mmCar*, char*>>(0x4FB250, this, arg1, arg2);
}

void CarCamCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4FB290);
}
