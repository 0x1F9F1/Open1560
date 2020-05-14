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

define_dummy_symbol(mmeffects_vehform);

#include "vehform.h"

mmVehicleForm::mmVehicleForm()
{
    unimplemented();
}

mmVehicleForm::~mmVehicleForm()
{
    unimplemented();
}

void mmVehicleForm::Cull()
{
    return stub<thiscall_t<void, mmVehicleForm*>>(0x5027A0, this);
}

void mmVehicleForm::SetShape(char* arg1, char* arg2, char* arg3, class Vector3* arg4)
{
    return stub<thiscall_t<void, mmVehicleForm*, char*, char*, char*, class Vector3*>>(
        0x502710, this, arg1, arg2, arg3, arg4);
}

void mmVehicleForm::Update()
{
    return stub<thiscall_t<void, mmVehicleForm*>>(0x502780, this);
}
