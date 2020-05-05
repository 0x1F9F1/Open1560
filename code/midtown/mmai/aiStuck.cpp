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

define_dummy_symbol(mmai_aiStuck);

#include "aiStuck.h"

aiStuck::aiStuck()
{
    unimplemented();
}

aiStuck::~aiStuck()
{
    unimplemented(arg1);
}

void aiStuck::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, aiStuck*, class Bank*>>(0x6B770_Offset, this, arg1);
}

void aiStuck::Impact()
{
    return stub<thiscall_t<void, aiStuck*>>(0x6B4C0_Offset, this);
}

void aiStuck::Init(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, aiStuck*, class mmCarSim*>>(0x6B4A0_Offset, this, arg1);
}

i32 aiStuck::Pegged()
{
    return stub<thiscall_t<i32, aiStuck*>>(0x6B4E0_Offset, this);
}

void aiStuck::Reset()
{
    return stub<thiscall_t<void, aiStuck*>>(0x6B4D0_Offset, this);
}

void aiStuck::Update()
{
    return stub<thiscall_t<void, aiStuck*>>(0x6B550_Offset, this);
}
