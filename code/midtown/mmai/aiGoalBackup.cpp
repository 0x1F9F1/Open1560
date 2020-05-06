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

define_dummy_symbol(mmai_aiGoalBackup);

#include "aiGoalBackup.h"

aiGoalBackup::aiGoalBackup(class aiRailSet* arg1, class mmCar* arg2, i16* arg3)
{
    unimplemented(arg1, arg2, arg3);
}

aiGoalBackup::~aiGoalBackup()
{
    unimplemented();
}

void aiGoalBackup::Init()
{
    return stub<thiscall_t<void, aiGoalBackup*>>(0x45F870, this);
}

void aiGoalBackup::Reset()
{
    return stub<thiscall_t<void, aiGoalBackup*>>(0x45F8A0, this);
}

i32 aiGoalBackup::Context()
{
    return stub<thiscall_t<i32, aiGoalBackup*>>(0x45F880, this);
}

i32 aiGoalBackup::Priority()
{
    return stub<thiscall_t<i32, aiGoalBackup*>>(0x45F890, this);
}

void aiGoalBackup::Update()
{
    return stub<thiscall_t<void, aiGoalBackup*>>(0x45F8D0, this);
}

void aiGoalBackup::FinishedBackingUp()
{
    return stub<thiscall_t<void, aiGoalBackup*>>(0x45FC10, this);
}
