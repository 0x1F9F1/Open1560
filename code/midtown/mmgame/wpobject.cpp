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

define_dummy_symbol(mmgame_wpobject);

#include "wpobject.h"

mmWaypointObject::mmWaypointObject(class Vector4& arg1, char* arg2, i32 arg3, f32 arg4, i32 arg5, f32 arg6)
{
    unimplemented(arg1, arg2, arg3, arg4, arg5, arg6);
}

mmWaypointObject::~mmWaypointObject()
{
    unimplemented();
}

void mmWaypointObject::Activate()
{
    return stub<thiscall_t<void, mmWaypointObject*>>(0x430540, this);
}

void mmWaypointObject::Deactivate()
{
    return stub<thiscall_t<void, mmWaypointObject*>>(0x430550, this);
}

void mmWaypointObject::Move()
{
    return stub<thiscall_t<void, mmWaypointObject*>>(0x4305D0, this);
}

void mmWaypointObject::Reset()
{
    return stub<thiscall_t<void, mmWaypointObject*>>(0x430520, this);
}

void mmWaypointObject::SetHeading(f32 arg1)
{
    return stub<thiscall_t<void, mmWaypointObject*, f32>>(0x430560, this, arg1);
}

void mmWaypointObject::Update()
{
    return stub<thiscall_t<void, mmWaypointObject*>>(0x430530, this);
}
