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

#include "aiGoalStop.h"

aiGoalStop::aiGoalStop(class mmCar* arg1, i16* arg2)
{
    unimplemented();
}

aiGoalStop::~aiGoalStop()
{
    unimplemented();
}

void aiGoalStop::Init()
{
    return stub<thiscall_t<void, aiGoalStop*>>(0x5F750_Offset, this);
}

void aiGoalStop::Reset()
{
    return stub<thiscall_t<void, aiGoalStop*>>(0x5F760_Offset, this);
}

i32 aiGoalStop::Context()
{
    return stub<thiscall_t<i32, aiGoalStop*>>(0x5F7D0_Offset, this);
}

i32 aiGoalStop::Priority()
{
    return stub<thiscall_t<i32, aiGoalStop*>>(0x5F7F0_Offset, this);
}

void aiGoalStop::Update()
{
    return stub<thiscall_t<void, aiGoalStop*>>(0x5F770_Offset, this);
}

define_dummy_symbol(mmai_aiGoalStop);
