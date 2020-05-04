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

#include "stuck.h"

mmStuck::mmStuck()
{
    unimplemented();
}

mmStuck::~mmStuck()
{
    unimplemented();
}

void mmStuck::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmStuck*, class Bank*>>(0x7C7D0_Offset, this, arg1);
}

void mmStuck::Impact()
{
    return stub<thiscall_t<void, mmStuck*>>(0x7C540_Offset, this);
}

void mmStuck::Init(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmStuck*, class mmCarSim*>>(0x7C520_Offset, this, arg1);
}

i32 mmStuck::Pegged()
{
    return stub<thiscall_t<i32, mmStuck*>>(0x7C560_Offset, this);
}

void mmStuck::Reset()
{
    return stub<thiscall_t<void, mmStuck*>>(0x7C550_Offset, this);
}

void mmStuck::Update()
{
    return stub<thiscall_t<void, mmStuck*>>(0x7C5B0_Offset, this);
}

define_dummy_symbol(mmcar_stuck);
