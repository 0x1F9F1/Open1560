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

define_dummy_symbol(mmanim_AnimMgr);

#include "AnimMgr.h"

mmAnimMgr::mmAnimMgr()
{
    unimplemented();
}

mmAnimMgr::~mmAnimMgr()
{
    unimplemented(arg1);
}

void mmAnimMgr::AirlinerSwap()
{
    return stub<thiscall_t<void, mmAnimMgr*>>(0x4C13C0, this);
}

class MetaClass* mmAnimMgr::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmAnimMgr*>>(0x4C15B0, this);
}

i32 mmAnimMgr::Init(char* arg1, class mmInstance* arg2, class mmInstance** arg3, i32 arg4)
{
    return stub<thiscall_t<i32, mmAnimMgr*, char*, class mmInstance*, class mmInstance**, i32>>(
        0x4C11F0, this, arg1, arg2, arg3, arg4);
}

void mmAnimMgr::TestDOFAct(i32 arg1)
{
    return stub<thiscall_t<void, mmAnimMgr*, i32>>(0x4C13B0, this, arg1);
}

void mmAnimMgr::UFOSwap()
{
    return stub<thiscall_t<void, mmAnimMgr*>>(0x4C1400, this);
}

void mmAnimMgr::Update()
{
    return stub<thiscall_t<void, mmAnimMgr*>>(0x4C13A0, this);
}

void mmAnimMgr::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4C1440);
}
