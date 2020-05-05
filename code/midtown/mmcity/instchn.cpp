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

define_dummy_symbol(mmcity_instchn);

#include "instchn.h"

mmInstChain::mmInstChain()
{
    unimplemented();
}

mmInstChain::~mmInstChain()
{
    unimplemented();
}

void mmInstChain::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmInstChain*, class Bank*>>(0x92980_Offset, this, arg1);
}

void mmInstChain::Draw(i16 arg1, i16 arg2, u32 arg3, i32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, mmInstChain*, i16, i16, u32, i32, f32>>(
        0x924C0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void mmInstChain::Init(i32 arg1)
{
    return stub<thiscall_t<void, mmInstChain*, i32>>(0x922B0_Offset, this, arg1);
}

void mmInstChain::Parent(class mmInstance* arg1, i16 arg2)
{
    return stub<thiscall_t<void, mmInstChain*, class mmInstance*, i16>>(0x92310_Offset, this, arg1, arg2);
}

void mmInstChain::Relight(i16 arg1)
{
    return stub<thiscall_t<void, mmInstChain*, i16>>(0x92490_Offset, this, arg1);
}

void mmInstChain::RelightEverything()
{
    return stub<thiscall_t<void, mmInstChain*>>(0x92470_Offset, this);
}

void mmInstChain::Reparent(class mmInstance* arg1, i16 arg2)
{
    return stub<thiscall_t<void, mmInstChain*, class mmInstance*, i16>>(0x92440_Offset, this, arg1, arg2);
}

void mmInstChain::Unparent(class mmInstance* arg1)
{
    return stub<thiscall_t<void, mmInstChain*, class mmInstance*>>(0x923A0_Offset, this, arg1);
}
