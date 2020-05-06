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

define_dummy_symbol(mmcar_stuck);

#include "stuck.h"

mmStuck::mmStuck()
{
    unimplemented();
}

mmStuck::~mmStuck()
{
    unimplemented(arg1);
}

void mmStuck::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmStuck*, class Bank*>>(0x47C7D0, this, arg1);
}

void mmStuck::Impact()
{
    return stub<thiscall_t<void, mmStuck*>>(0x47C540, this);
}

void mmStuck::Init(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmStuck*, class mmCarSim*>>(0x47C520, this, arg1);
}

i32 mmStuck::Pegged()
{
    return stub<thiscall_t<i32, mmStuck*>>(0x47C560, this);
}

void mmStuck::Reset()
{
    return stub<thiscall_t<void, mmStuck*>>(0x47C550, this);
}

void mmStuck::Update()
{
    return stub<thiscall_t<void, mmStuck*>>(0x47C5B0, this);
}
