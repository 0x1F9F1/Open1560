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

#include "damage.h"

mmDamage::mmDamage()
{
    unimplemented();
}

mmDamage::~mmDamage()
{
    unimplemented();
}

void mmDamage::Apply(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmDamage*, class Vector3&, f32>>(0x102470_Offset, this, arg1, arg2);
}

void mmDamage::Init(class agiMeshSet* arg1)
{
    return stub<thiscall_t<void, mmDamage*, class agiMeshSet*>>(0x102240_Offset, this, arg1);
}

void mmDamage::Reset(i32 arg1)
{
    return stub<thiscall_t<void, mmDamage*, i32>>(0x102420_Offset, this, arg1);
}

define_dummy_symbol(mmeffects_damage);
