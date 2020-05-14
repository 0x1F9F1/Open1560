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

define_dummy_symbol(mmcar_trailer);

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
    return stub<thiscall_t<void, mmTrailer*>>(0x479BB0, this);
}

void mmTrailer::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmTrailer*, class Bank*>>(0x479E40, this, arg1);
}

void mmTrailer::AfterLoad()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x479B40, this);
}

void mmTrailer::BeforeSave()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x479BD0, this);
}

void mmTrailer::Deactivate()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x479BC0, this);
}

class asBound* mmTrailer::GetBound()
{
    return stub<thiscall_t<class asBound*, mmTrailer*>>(0x47A320, this);
}

class MetaClass* mmTrailer::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmTrailer*>>(0x47A130, this);
}

class asInertialCS* mmTrailer::GetICS()
{
    return stub<thiscall_t<class asInertialCS*, mmTrailer*>>(0x47A310, this);
}

void mmTrailer::Init(char* arg1, class mmCarSim* arg2, class Vector3 arg3)
{
    return stub<thiscall_t<void, mmTrailer*, char*, class mmCarSim*, class Vector3>>(0x479480, this, arg1, arg2, arg3);
}

void mmTrailer::PostUpdate()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x479E30, this);
}

void mmTrailer::Reset()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x479C80, this);
}

void mmTrailer::RestoreImpactParams()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x479C30, this);
}

void mmTrailer::SetHackedImpactParams()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x479C60, this);
}

void mmTrailer::Update()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x479D60, this);
}

void mmTrailer::UpdateICSParams()
{
    return stub<thiscall_t<void, mmTrailer*>>(0x479C00, this);
}

void mmTrailer::DeclareFields()
{
    return stub<cdecl_t<void>>(0x479F30);
}

mmTrailerInstance::~mmTrailerInstance()
{
    unimplemented();
}

void mmTrailerInstance::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmTrailerInstance*, class Bank*>>(0x47A300, this, arg1);
}

class mmPhysEntity* mmTrailerInstance::AttachEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmTrailerInstance*>>(0x479730, this);
}

void __fastcall mmTrailerInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmTrailerInstance*, i32>>(0x479910, this, arg1);
}

void __fastcall mmTrailerInstance::DrawShadow()
{
    return stub<fastcall_t<void, mmTrailerInstance*>>(0x479B20, this);
}

void __fastcall mmTrailerInstance::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmTrailerInstance*, class Matrix34 const&>>(0x4796D0, this, arg1);
}

class mmPhysEntity* mmTrailerInstance::GetEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmTrailerInstance*>>(0x479720, this);
}

class Vector3& __fastcall mmTrailerInstance::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmTrailerInstance*>>(0x479710, this);
}

class Vector3 mmTrailerInstance::GetVelocity()
{
    return stub<thiscall_t<class Vector3, mmTrailerInstance*>>(0x479740, this);
}

void mmTrailerInstance::Init(char* arg1, class Vector3* arg2)
{
    return stub<thiscall_t<void, mmTrailerInstance*, char*, class Vector3*>>(0x479770, this, arg1, arg2);
}

class Matrix34& __fastcall mmTrailerInstance::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmTrailerInstance*, class Matrix34&>>(0x4796F0, this, arg1);
}
