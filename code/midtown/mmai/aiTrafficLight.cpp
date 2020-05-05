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

define_dummy_symbol(mmai_aiTrafficLight);

#include "aiTrafficLight.h"

aiTrafficLightSet::aiTrafficLightSet(class aiIntersection* arg1)
{
    unimplemented(arg1);
}

aiTrafficLightSet::~aiTrafficLightSet()
{
    unimplemented(arg1);
}

void aiTrafficLightSet::Reset()
{
    return stub<thiscall_t<void, aiTrafficLightSet*>>(0x441B0_Offset, this);
}

void aiTrafficLightSet::Update()
{
    return stub<thiscall_t<void, aiTrafficLightSet*>>(0x44250_Offset, this);
}

aiTrafficLightInstance::~aiTrafficLightInstance()
{
    unimplemented(arg1);
}

void __fastcall aiTrafficLightInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, aiTrafficLightInstance*, i32>>(0x44530_Offset, this, arg1);
}

i32 aiTrafficLightInstance::Init(char* arg1, class Vector3& arg2, class Vector3& arg3, i32 arg4, char* arg5)
{
    return stub<thiscall_t<i32, aiTrafficLightInstance*, char*, class Vector3&, class Vector3&, i32, char*>>(
        0x44330_Offset, this, arg1, arg2, arg3, arg4, arg5);
}
