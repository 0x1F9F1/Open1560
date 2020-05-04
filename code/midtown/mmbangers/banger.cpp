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

#include "banger.h"

mmBangerInstance::mmBangerInstance()
{
    unimplemented();
}

mmBangerInstance::~mmBangerInstance()
{
    unimplemented();
}

void mmBangerInstance::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmBangerInstance*, class Bank*>>(0x44710_Offset, this, arg1);
}

class mmPhysEntity* mmBangerInstance::AttachEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmBangerInstance*>>(0xCA490_Offset, this);
}

i32 mmBangerInstance::ComputeLod(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, mmBangerInstance*, f32, f32>>(0xC9C30_Offset, this, arg1, arg2);
}

void __fastcall mmBangerInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmBangerInstance*, i32>>(0xC9C50_Offset, this, arg1);
}

void __fastcall mmBangerInstance::DrawGlow()
{
    return stub<fastcall_t<void, mmBangerInstance*>>(0xC9E50_Offset, this);
}

void __fastcall mmBangerInstance::DrawShadow()
{
    return stub<fastcall_t<void, mmBangerInstance*>>(0xCA110_Offset, this);
}

class mmBangerData* mmBangerInstance::GetData()
{
    return stub<thiscall_t<class mmBangerData*, mmBangerInstance*>>(0xCA460_Offset, this);
}

class mmPhysEntity* mmBangerInstance::GetEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmBangerInstance*>>(0xCA480_Offset, this);
}

class Vector3 mmBangerInstance::GetVelocity()
{
    return stub<thiscall_t<class Vector3, mmBangerInstance*>>(0xCA4D0_Offset, this);
}

mmUnhitBangerInstance::mmUnhitBangerInstance()
{
    unimplemented();
}

mmUnhitBangerInstance::~mmUnhitBangerInstance()
{
    unimplemented();
}

void __fastcall mmUnhitBangerInstance::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmUnhitBangerInstance*, class Matrix34 const&>>(0xCA810_Offset, this, arg1);
}

class Vector3& __fastcall mmUnhitBangerInstance::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmUnhitBangerInstance*>>(0xCA8D0_Offset, this);
}

void mmUnhitBangerInstance::Impact(class mmInstance* arg1, class Vector3* arg2)
{
    return stub<thiscall_t<void, mmUnhitBangerInstance*, class mmInstance*, class Vector3*>>(
        0xCA8E0_Offset, this, arg1, arg2);
}

i32 mmUnhitBangerInstance::Init(char* arg1, class Vector3& arg2, class Vector3& arg3, i32 arg4, char* arg5)
{
    return stub<thiscall_t<i32, mmUnhitBangerInstance*, char*, class Vector3&, class Vector3&, i32, char*>>(
        0xCA5F0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void mmUnhitBangerInstance::InitBreakables(char* arg1, char* arg2, class mmBangerData* arg3)
{
    return stub<thiscall_t<void, mmUnhitBangerInstance*, char*, char*, class mmBangerData*>>(
        0xCA560_Offset, this, arg1, arg2, arg3);
}

void mmUnhitBangerInstance::Reset()
{
    return stub<thiscall_t<void, mmUnhitBangerInstance*>>(0xCA830_Offset, this);
}

u32 mmUnhitBangerInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmUnhitBangerInstance*>>(0x44750_Offset, this);
}

class Matrix34& __fastcall mmUnhitBangerInstance::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmUnhitBangerInstance*, class Matrix34&>>(0xCA880_Offset, this, arg1);
}

mmHitBangerInstance::mmHitBangerInstance()
{
    unimplemented();
}

mmHitBangerInstance::~mmHitBangerInstance()
{
    unimplemented();
}

void mmHitBangerInstance::Detach()
{
    return stub<thiscall_t<void, mmHitBangerInstance*>>(0xCAC40_Offset, this);
}

void __fastcall mmHitBangerInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmHitBangerInstance*, i32>>(0xC9F20_Offset, this, arg1);
}

void __fastcall mmHitBangerInstance::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmHitBangerInstance*, class Matrix34 const&>>(0xCA520_Offset, this, arg1);
}

class Vector3& __fastcall mmHitBangerInstance::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmHitBangerInstance*>>(0xCA550_Offset, this);
}

u32 mmHitBangerInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmHitBangerInstance*>>(0xCAEC0_Offset, this);
}

class Matrix34& __fastcall mmHitBangerInstance::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmHitBangerInstance*, class Matrix34&>>(0xCA540_Offset, this, arg1);
}

define_dummy_symbol(mmbangers_banger);
