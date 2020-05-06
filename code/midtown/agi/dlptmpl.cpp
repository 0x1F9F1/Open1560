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

define_dummy_symbol(agi_dlptmpl);

#include "dlptmpl.h"

agiLib<class agiPhysParameters, class agiPhysDef>::agiLib<class agiPhysParameters, class agiPhysDef>()
{
    unimplemented();
}

agiLib<class agiPhysParameters, class agiPhysDef>::~agiLib<class agiPhysParameters, class agiPhysDef>()
{
    unimplemented();
}

i32 agiLib<class agiPhysParameters, class agiPhysDef>::Add(class agiPhysParameters& arg1)
{
    return stub<thiscall_t<i32, agiLib<class agiPhysParameters, class agiPhysDef>*, class agiPhysParameters&>>(
        0x559EF0, this, arg1);
}

void agiLib<class agiPhysParameters, class agiPhysDef>::Init(i32 arg1)
{
    return stub<thiscall_t<void, agiLib<class agiPhysParameters, class agiPhysDef>*, i32>>(0x55A290, this, arg1);
}

void agiLib<class agiPhysParameters, class agiPhysDef>::Kill()
{
    return stub<thiscall_t<void, agiLib<class agiPhysParameters, class agiPhysDef>*>>(0x55A250, this);
}

DLPTemplate::DLPTemplate(char* arg1)
{
    unimplemented(arg1);
}

void DLPTemplate::AddRef()
{
    return stub<thiscall_t<void, DLPTemplate*>>(0x5597C0, this);
}

i32 DLPTemplate::BoundBox(class Vector3& arg1, class Vector3& arg2, char* arg3)
{
    return stub<thiscall_t<i32, DLPTemplate*, class Vector3&, class Vector3&, char*>>(0x559A00, this, arg1, arg2, arg3);
}

i32 DLPTemplate::GetCentroid(class Vector3& arg1, char* arg2)
{
    return stub<thiscall_t<i32, DLPTemplate*, class Vector3&, char*>>(0x559930, this, arg1, arg2);
}

class Vector3* DLPTemplate::GetGroupVertex(char* arg1)
{
    return stub<thiscall_t<class Vector3*, DLPTemplate*, char*>>(0x5599B0, this, arg1);
}

i32 DLPTemplate::GetVertexCentroid(class Vector3& arg1, char* arg2)
{
    return stub<thiscall_t<i32, DLPTemplate*, class Vector3&, char*>>(0x559800, this, arg1, arg2);
}

class DLPGroup* DLPTemplate::GroupExists(char* arg1)
{
    return stub<thiscall_t<class DLPGroup*, DLPTemplate*, char*>>(0x559630, this, arg1);
}

void DLPTemplate::Init(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, DLPTemplate*, i32, i32, i32>>(0x5583D0, this, arg1, arg2, arg3);
}

void DLPTemplate::InitRemap(class agiLib<class agiMtlParameters, class agiMtlDef>& arg1,
    class agiLib<class agiTexParameters, class agiTexDef>& arg2,
    class agiLib<class agiPhysParameters, class agiPhysDef>& arg3)
{
    return stub<thiscall_t<void, DLPTemplate*, class agiLib<class agiMtlParameters, class agiMtlDef>&,
        class agiLib<class agiTexParameters, class agiTexDef>&,
        class agiLib<class agiPhysParameters, class agiPhysDef>&>>(0x558A40, this, arg1, arg2, arg3);
}

i32 DLPTemplate::Load(char* arg1)
{
    return stub<thiscall_t<i32, DLPTemplate*, char*>>(0x558B60, this, arg1);
}

void DLPTemplate::Load(class Stream* arg1)
{
    return stub<thiscall_t<void, DLPTemplate*, class Stream*>>(0x558640, this, arg1);
}

void DLPTemplate::Print(class Stream* arg1)
{
    return stub<thiscall_t<void, DLPTemplate*, class Stream*>>(0x558BA0, this, arg1);
}

i32 DLPTemplate::Release()
{
    return stub<thiscall_t<i32, DLPTemplate*>>(0x5597D0, this);
}

i32 DLPTemplate::Restrict(char* arg1)
{
    return stub<thiscall_t<i32, DLPTemplate*, char*>>(0x5596B0, this, arg1);
}

void DLPTemplate::Save(class Stream* arg1)
{
    return stub<thiscall_t<void, DLPTemplate*, class Stream*>>(0x558500, this, arg1);
}

DLPTemplate::~DLPTemplate()
{
    unimplemented();
}

DLPPatch::DLPPatch()
{
    unimplemented();
}

DLPPatch::~DLPPatch()
{
    unimplemented();
}

char* DLPPatch::GetProp(char* arg1)
{
    return stub<thiscall_t<char*, DLPPatch*, char*>>(0x558990, this, arg1);
}

void DLPPatch::Load(class Stream* arg1)
{
    return stub<thiscall_t<void, DLPPatch*, class Stream*>>(0x559080, this, arg1);
}

void DLPPatch::Print(class Stream* arg1)
{
    return stub<thiscall_t<void, DLPPatch*, class Stream*>>(0x559250, this, arg1);
}

void DLPPatch::Save(class Stream* arg1)
{
    return stub<thiscall_t<void, DLPPatch*, class Stream*>>(0x559180, this, arg1);
}

DLPGroup::DLPGroup()
{
    unimplemented();
}

DLPGroup::DLPGroup(class DLPTemplate* arg1, class DLPGroup* arg2)
{
    unimplemented(arg1, arg2);
}

DLPGroup::~DLPGroup()
{
    unimplemented();
}

void DLPGroup::Init(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, DLPGroup*, i32, i32>>(0x559040, this, arg1, arg2);
}

void DLPGroup::Load(class Stream* arg1)
{
    return stub<thiscall_t<void, DLPGroup*, class Stream*>>(0x558EC0, this, arg1);
}

void DLPGroup::Print(class Stream* arg1)
{
    return stub<thiscall_t<void, DLPGroup*, class Stream*>>(0x558FC0, this, arg1);
}

void DLPGroup::Save(class Stream* arg1)
{
    return stub<thiscall_t<void, DLPGroup*, class Stream*>>(0x558F40, this, arg1);
}

u32 PackAngle(f32 arg1)
{
    return stub<cdecl_t<u32, f32>>(0x5593A0, arg1);
}

void PackNormal(u16& arg1, class Vector3& arg2)
{
    return stub<cdecl_t<void, u16&, class Vector3&>>(0x559400, arg1, arg2);
}

f32 UnpackAngle(u8 arg1)
{
    return stub<cdecl_t<f32, u8>>(0x559310, arg1);
}

void UnpackNormal(class Vector3& arg1, u16& arg2)
{
    return stub<cdecl_t<void, class Vector3&, u16&>>(0x559340, arg1, arg2);
}

void DLPVertex::Load(class Stream* arg1)
{
    return stub<thiscall_t<void, DLPVertex*, class Stream*>>(0x5594D0, this, arg1);
}

void DLPVertex::Save(class Stream* arg1)
{
    return stub<thiscall_t<void, DLPVertex*, class Stream*>>(0x5595A0, this, arg1);
}

agiLib<class agiMtlParameters, class agiMtlDef>::agiLib<class agiMtlParameters, class agiMtlDef>()
{
    unimplemented();
}

agiLib<class agiMtlParameters, class agiMtlDef>::~agiLib<class agiMtlParameters, class agiMtlDef>()
{
    unimplemented();
}

i32 agiLib<class agiMtlParameters, class agiMtlDef>::Add(class agiMtlParameters& arg1)
{
    return stub<thiscall_t<i32, agiLib<class agiMtlParameters, class agiMtlDef>*, class agiMtlParameters&>>(
        0x559D90, this, arg1);
}

void agiLib<class agiMtlParameters, class agiMtlDef>::Init(i32 arg1)
{
    return stub<thiscall_t<void, agiLib<class agiMtlParameters, class agiMtlDef>*, i32>>(0x55A080, this, arg1);
}

void agiLib<class agiMtlParameters, class agiMtlDef>::Kill()
{
    return stub<thiscall_t<void, agiLib<class agiMtlParameters, class agiMtlDef>*>>(0x55A030, this);
}
