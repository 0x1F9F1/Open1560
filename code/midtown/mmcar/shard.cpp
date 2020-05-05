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
    unimplemented(arg1);
}

void mmShard::AddShard(class Vector3 arg1, class Vector3 arg2, class Vector3 arg3, f32 arg4)
{
    return stub<thiscall_t<void, mmShard*, class Vector3, class Vector3, class Vector3, f32>>(
        0x785E0_Offset, this, arg1, arg2, arg3, arg4);
}

void __fastcall mmShard::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmShard*, i32>>(0x78730_Offset, this, arg1);
}

class MetaClass* mmShard::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmShard*>>(0x78F80_Offset, this);
}

void mmShard::Init(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmShard*, char*, i32>>(0x785A0_Offset, this, arg1, arg2);
}

void mmShard::Update()
{
    return stub<thiscall_t<void, mmShard*>>(0x78640_Offset, this);
}

void mmShard::DeclareFields()
{
    return stub<cdecl_t<void>>(0x78E00_Offset);
}

mmShardManager::mmShardManager()
{
    unimplemented();
}

mmShardManager::~mmShardManager()
{
    unimplemented(arg1);
}

void mmShardManager::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmShardManager*, class Bank*>>(0x78C90_Offset, this, arg1);
}

void mmShardManager::EmitAllShards(class Vector3 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmShardManager*, class Vector3, f32>>(0x78A60_Offset, this, arg1, arg2);
}

void mmShardManager::EmitShard(class Vector3 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmShardManager*, class Vector3, f32>>(0x78AB0_Offset, this, arg1, arg2);
}

void mmShardManager::EmitShards(class Vector3 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmShardManager*, class Vector3, f32, f32>>(0x789F0_Offset, this, arg1, arg2, arg3);
}

class MetaClass* mmShardManager::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmShardManager*>>(0x79160_Offset, this);
}

void mmShardManager::Init(char* arg1, i32 arg2, class mmCarSim* arg3)
{
    return stub<thiscall_t<void, mmShardManager*, char*, i32, class mmCarSim*>>(0x788F0_Offset, this, arg1, arg2, arg3);
}

void mmShardManager::ReInit(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmShardManager*, class mmCarSim*>>(0x789E0_Offset, this, arg1);
}

void mmShardManager::Update()
{
    return stub<thiscall_t<void, mmShardManager*>>(0x78C60_Offset, this);
}

void mmShardManager::DeclareFields()
{
    return stub<cdecl_t<void>>(0x78F90_Offset);
}

class mmShardManager* mmShardManager::GetInstance(i32 arg1)
{
    return stub<cdecl_t<class mmShardManager*, i32>>(0x788D0_Offset, arg1);
}
