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

#include "trailer.h"

mmTrailer::mmTrailer()
{
    unimplemented();
}

mmTrailer::~mmTrailer()
{
    unimplemented();
}

void mmTrailer::Activate()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x79BB0_Offset, this);
}

void mmTrailer::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmTrailer*, class Bank*>>(0x79E40_Offset, this, arg1);
}

void mmTrailer::AfterLoad()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x79B40_Offset, this);
}

void mmTrailer::BeforeSave()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x79BD0_Offset, this);
}

void mmTrailer::Deactivate()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x79BC0_Offset, this);
}

class asBound* mmTrailer::GetBound()
{
    return stub<thiscall_t<class asBound*, mmTrailer*>>(0x7A320_Offset, this);
}

class MetaClass* mmTrailer::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmTrailer*>>(0x7A130_Offset, this);
}

class asInertialCS* mmTrailer::GetICS()
{
    return stub<thiscall_t<class asInertialCS*, mmTrailer*>>(0x7A310_Offset, this);
}

void mmTrailer::Init(char* arg1, class mmCarSim* arg2, class Vector3 arg3)
{
    return stub<thiscall_t<void, mmTrailer*, char*, class mmCarSim*, class Vector3>>(
        0x79480_Offset, this, arg1, arg2, arg3);
}

void mmTrailer::PostUpdate()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x79E30_Offset, this);
}

void mmTrailer::Reset()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x79C80_Offset, this);
}

void mmTrailer::RestoreImpactParams()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x79C30_Offset, this);
}

void mmTrailer::SetHackedImpactParams()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x79C60_Offset, this);
}

void mmTrailer::Update()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x79D60_Offset, this);
}

void mmTrailer::UpdateICSParams()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x79C00_Offset, this);
}

void mmTrailer::DeclareFields()
{
    return stub<cdecl_t<void>>(0x79F30_Offset);
}

mmTrailerInstance::~mmTrailerInstance()
{
    unimplemented();
}

void mmTrailerInstance::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmTrailerInstance*, class Bank*>>(0x7A300_Offset, this, arg1);
}

class mmPhysEntity* mmTrailerInstance::AttachEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmTrailerInstance*>>(0x79730_Offset, this);
}

void __fastcall mmTrailerInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmTrailerInstance*, i32>>(0x79910_Offset, this, arg1);
}

void __fastcall mmTrailerInstance::DrawShadow()
{
    return stub<fastcall_t<void, mmTrailerInstance*>>(0x79B20_Offset, this);
}

void __fastcall mmTrailerInstance::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmTrailerInstance*, class Matrix34 const&>>(0x796D0_Offset, this, arg1);
}

class mmPhysEntity* mmTrailerInstance::GetEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmTrailerInstance*>>(0x79720_Offset, this);
}

class Vector3& __fastcall mmTrailerInstance::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmTrailerInstance*>>(0x79710_Offset, this);
}

class Vector3 mmTrailerInstance::GetVelocity()
{
    return stub<thiscall_t<class Vector3, mmTrailerInstance*>>(0x79740_Offset, this);
}

void mmTrailerInstance::Init(char* arg1, class Vector3* arg2)
{
    return stub<thiscall_t<void, mmTrailerInstance*, char*, class Vector3*>>(0x79770_Offset, this, arg1, arg2);
}

class Matrix34& __fastcall mmTrailerInstance::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmTrailerInstance*, class Matrix34&>>(0x796F0_Offset, this, arg1);
}

define_dummy_symbol(mmcar_trailer);
