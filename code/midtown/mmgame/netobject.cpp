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

#include "netobject.h"

mmNetObject::mmNetObject()
{
    unimplemented();
}

mmNetObject::~mmNetObject()
{
    unimplemented();
}

void mmNetObject::Activate()
{
    return stub<thiscall_t<void, mmNetObject*>>(0x32850_Offset, this);
}

void mmNetObject::Clear()
{
    return stub<thiscall_t<void, mmNetObject*>>(0x32800_Offset, this);
}

void mmNetObject::Deactivate()
{
    return stub<thiscall_t<void, mmNetObject*>>(0x328A0_Offset, this);
}

void mmNetObject::Init(class mmCar* arg1, char* arg2, i32 arg3, u32 arg4, char* arg5)
{
    return stub<thiscall_t<void, mmNetObject*, class mmCar*, char*, i32, u32, char*>>(
        0x32900_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void mmNetObject::PositionUpdate(struct NETGAME_MSG* arg1)
{
    return stub<thiscall_t<void, mmNetObject*, struct NETGAME_MSG*>>(0x32BD0_Offset, this, arg1);
}

void mmNetObject::Predict()
{
    return stub<thiscall_t<void, mmNetObject*>>(0x32F80_Offset, this);
}

void mmNetObject::ReInit(class mmCar* arg1, char* arg2, i32 arg3, u32 arg4, char* arg5)
{
    return stub<thiscall_t<void, mmNetObject*, class mmCar*, char*, i32, u32, char*>>(
        0x32980_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void mmNetObject::SetActive(i32 arg1)
{
    return stub<thiscall_t<void, mmNetObject*, i32>>(0x32A50_Offset, this, arg1);
}

void mmNetObject::SetCar(class mmCar* arg1)
{
    return stub<thiscall_t<void, mmNetObject*, class mmCar*>>(0x32A40_Offset, this, arg1);
}

void mmNetObject::SetLocalData()
{
    return stub<thiscall_t<void, mmNetObject*>>(0x32A80_Offset, this);
}

void mmNetObject::SetScore(i32 arg1)
{
    return stub<thiscall_t<void, mmNetObject*, i32>>(0x32A70_Offset, this, arg1);
}

void mmNetObject::Update()
{
    return stub<thiscall_t<void, mmNetObject*>>(0x33130_Offset, this);
}

define_dummy_symbol(mmgame_netobject);
