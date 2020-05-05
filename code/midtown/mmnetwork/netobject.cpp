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

define_dummy_symbol(mmnetwork_netobject);

#include "netobject.h"

asNetObject::asNetObject()
{
    unimplemented();
}

asNetObject::~asNetObject()
{
    unimplemented(arg1);
}

void asNetObject::SetLocalData()
{
    return stub<thiscall_t<void, asNetObject*>>(0x - 400000_Offset, this);
}

void asNetObject::PositionUpdate(class Matrix34* arg1, class Vector3 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, asNetObject*, class Matrix34*, class Vector3, f32, f32, f32>>(
        0x8B4D0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void asNetObject::Update()
{
    return stub<thiscall_t<void, asNetObject*>>(0x8B4F0_Offset, this);
}
