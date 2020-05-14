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

define_dummy_symbol(mmcar_shard);

#include "shard.h"

mmShard::mmShard()
{
    unimplemented();
}

mmShard::~mmShard()
{
    unimplemented();
}

void mmShard::AddShard(class Vector3 arg1, class Vector3 arg2, class Vector3 arg3, f32 arg4)
{
    return stub<thiscall_t<void, mmShard*, class Vector3, class Vector3, class Vector3, f32>>(
        0x4785E0, this, arg1, arg2, arg3, arg4);
}

void __fastcall mmShard::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmShard*, i32>>(0x478730, this, arg1);
}

class MetaClass* mmShard::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmShard*>>(0x478F80, this);
}

void mmShard::Init(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmShard*, char*, i32>>(0x4785A0, this, arg1, arg2);
}

void mmShard::Update()
{
    return stub<thiscall_t<void, mmShard*>>(0x478640, this);
}

void mmShard::DeclareFields()
{
    return stub<cdecl_t<void>>(0x478E00);
}

mmShardManager::mmShardManager()
{
    unimplemented();
}

mmShardManager::~mmShardManager()
{
    unimplemented();
}

void mmShardManager::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmShardManager*, class Bank*>>(0x478C90, this, arg1);
}

void mmShardManager::EmitAllShards(class Vector3 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmShardManager*, class Vector3, f32>>(0x478A60, this, arg1, arg2);
}

void mmShardManager::EmitShard(class Vector3 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmShardManager*, class Vector3, f32>>(0x478AB0, this, arg1, arg2);
}

void mmShardManager::EmitShards(class Vector3 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmShardManager*, class Vector3, f32, f32>>(0x4789F0, this, arg1, arg2, arg3);
}

class MetaClass* mmShardManager::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmShardManager*>>(0x479160, this);
}

void mmShardManager::Init(char* arg1, i32 arg2, class mmCarSim* arg3)
{
    return stub<thiscall_t<void, mmShardManager*, char*, i32, class mmCarSim*>>(0x4788F0, this, arg1, arg2, arg3);
}

void mmShardManager::ReInit(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmShardManager*, class mmCarSim*>>(0x4789E0, this, arg1);
}

void mmShardManager::Update()
{
    return stub<thiscall_t<void, mmShardManager*>>(0x478C60, this);
}

void mmShardManager::DeclareFields()
{
    return stub<cdecl_t<void>>(0x478F90);
}

class mmShardManager* mmShardManager::GetInstance(i32 arg1)
{
    return stub<cdecl_t<class mmShardManager*, i32>>(0x4788D0, arg1);
}
