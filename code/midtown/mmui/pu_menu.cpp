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

#include "pu_menu.h"

PUMenuBase::PUMenuBase(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6)
{
    unimplemented();
}

PUMenuBase::~PUMenuBase()
{
    unimplemented();
}

f32 PUMenuBase::AddExit(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<f32, PUMenuBase*, f32, f32, f32, f32>>(0xAB390_Offset, this, arg1, arg2, arg3, arg4);
}

void PUMenuBase::AddOKCancel(class Callback arg1, class Callback arg2)
{
    return stub<thiscall_t<void, PUMenuBase*, class Callback, class Callback>>(0xAB2F0_Offset, this, arg1, arg2);
}

f32 PUMenuBase::AddPrevious(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<f32, PUMenuBase*, f32, f32, f32, f32>>(0xAB280_Offset, this, arg1, arg2, arg3, arg4);
}

class agiBitmap* PUMenuBase::CreateDummyBitmap()
{
    return stub<thiscall_t<class agiBitmap*, PUMenuBase*>>(0xAB210_Offset, this);
}

f32 PUMenuBase::CreateTitle()
{
    return stub<thiscall_t<f32, PUMenuBase*>>(0xAB270_Offset, this);
}

void PUMenuBase::Cull()
{
    return stub<thiscall_t<void, PUMenuBase*>>(0xAB430_Offset, this);
}

void PUMenuBase::DisableExit()
{
    return stub<thiscall_t<void, PUMenuBase*>>(0xAB470_Offset, this);
}

void PUMenuBase::EnableExit()
{
    return stub<thiscall_t<void, PUMenuBase*>>(0xAB480_Offset, this);
}

void PUMenuBase::Update()
{
    return stub<thiscall_t<void, PUMenuBase*>>(0xAB400_Offset, this);
}

define_dummy_symbol(mmui_pu_menu);
