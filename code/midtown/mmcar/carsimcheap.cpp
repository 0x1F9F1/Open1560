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

define_dummy_symbol(mmcar_carsimcheap);

#include "carsimcheap.h"

mmWheelCheap::mmWheelCheap()
{
    unimplemented();
}

mmWheelCheap::~mmWheelCheap()
{
    unimplemented(arg1);
}

void mmWheelCheap::Init(class Vector3* arg1, class aiVehicleData* arg2, class asInertialCS* arg3)
{
    return stub<thiscall_t<void, mmWheelCheap*, class Vector3*, class aiVehicleData*, class asInertialCS*>>(
        0x74950_Offset, this, arg1, arg2, arg3);
}

void mmWheelCheap::Reset()
{
    return stub<thiscall_t<void, mmWheelCheap*>>(0x75180_Offset, this);
}

void mmWheelCheap::Update()
{
    return stub<thiscall_t<void, mmWheelCheap*>>(0x74A20_Offset, this);
}
