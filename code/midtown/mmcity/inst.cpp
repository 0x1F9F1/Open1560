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

#include "inst.h"

mmInstance::mmInstance()
{
    unimplemented();
}

mmInstance::~mmInstance()
{
    unimplemented();
}

void __fastcall mmInstance::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmInstance*, class Matrix34 const&>>(0x - 400000_Offset, this, arg1);
}

class Matrix34& __fastcall mmInstance::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmInstance*, class Matrix34&>>(0x - 400000_Offset, this, arg1);
}

class Vector3& __fastcall mmInstance::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmInstance*>>(0x - 400000_Offset, this);
}

class mmPhysEntity* mmInstance::GetEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmInstance*>>(0x33DB0_Offset, this);
}

class mmPhysEntity* mmInstance::AttachEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmInstance*>>(0x33DC0_Offset, this);
}

class Vector3 mmInstance::GetVelocity()
{
    return stub<thiscall_t<class Vector3, mmInstance*>>(0x33DD0_Offset, this);
}

void mmInstance::Impact(class mmInstance* arg1, class Vector3* arg2)
{
    return stub<thiscall_t<void, mmInstance*, class mmInstance*, class Vector3*>>(0x33DF0_Offset, this, arg1, arg2);
}

void mmInstance::Detach()
{
    return stub<thiscall_t<void, mmInstance*>>(0x33E00_Offset, this);
}

void __fastcall mmInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmInstance*, i32>>(0x92AA0_Offset, this, arg1);
}

void __fastcall mmInstance::DrawShadow()
{
    return stub<fastcall_t<void, mmInstance*>>(0x92B00_Offset, this);
}

void __fastcall mmInstance::DrawGlow()
{
    return stub<fastcall_t<void, mmInstance*>>(0x92B10_Offset, this);
}

void __fastcall mmInstance::Relight()
{
    return stub<fastcall_t<void, mmInstance*>>(0x92A10_Offset, this);
}

u32 mmInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmInstance*>>(0x93120_Offset, this);
}

void mmInstance::Reset()
{
    return stub<thiscall_t<void, mmInstance*>>(0x93130_Offset, this);
}

void mmInstance::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmInstance*, class Bank*>>(0x - 400000_Offset, this, arg1);
}

i32 mmInstance::Init(char* arg1, class Vector3& arg2, class Vector3& arg3, i32 arg4, char* arg5)
{
    return stub<thiscall_t<i32, mmInstance*, char*, class Vector3&, class Vector3&, i32, char*>>(
        0x92B20_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

f32 __fastcall mmInstance::GetScale()
{
    return stub<fastcall_t<f32, mmInstance*>>(0x92A20_Offset, this);
}

i32 mmInstance::ComputeLod(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, mmInstance*, f32, f32>>(0x92A30_Offset, this, arg1, arg2);
}

void mmInstance::AddMeshes(char* arg1, i32 arg2, char* arg3, class Vector3* arg4)
{
    return stub<thiscall_t<void, mmInstance*, char*, i32, char*, class Vector3*>>(
        0x93290_Offset, this, arg1, arg2, arg3, arg4);
}

void mmInstance::DrawDropShadow(i32 arg1, i32 arg2, class Matrix34 const& arg3)
{
    return stub<thiscall_t<void, mmInstance*, i32, i32, class Matrix34 const&>>(0x946B0_Offset, this, arg1, arg2, arg3);
}

class MetaClass* mmInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmInstance*>>(0x94AB0_Offset, this);
}

class agiMeshSet* mmInstance::GetResidentMeshSet(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<class agiMeshSet*, mmInstance*, i32, i32, i32>>(0x92BE0_Offset, this, arg1, arg2, arg3);
}

void mmInstance::InitMeshes(char* arg1, i32 arg2, char* arg3, class Vector3* arg4)
{
    return stub<thiscall_t<void, mmInstance*, char*, i32, char*, class Vector3*>>(
        0x93250_Offset, this, arg1, arg2, arg3, arg4);
}

void mmInstance::operator delete(void* arg1)
{
    return stub<cdecl_t<void, void*>>(0x30690_Offset, arg1);
}

void mmInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x94A10_Offset);
}

i32 mmInstance::GetMeshSetSet(char* arg1, i32 arg2, char* arg3, class Vector3* arg4)
{
    return stub<cdecl_t<i32, char*, i32, char*, class Vector3*>>(0x92C70_Offset, arg1, arg2, arg3, arg4);
}

void mmInstance::ResetAll()
{
    return stub<cdecl_t<void>>(0x93140_Offset);
}

mmShearInstance::mmShearInstance()
{
    unimplemented();
}

mmShearInstance::~mmShearInstance()
{
    unimplemented();
}

void __fastcall mmShearInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmShearInstance*, i32>>(0x94460_Offset, this, arg1);
}

class MetaClass* mmShearInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmShearInstance*>>(0x94E90_Offset, this);
}

f32 __fastcall mmShearInstance::GetScale()
{
    return stub<fastcall_t<f32, mmShearInstance*>>(0x94480_Offset, this);
}

i32 mmShearInstance::Init(char* arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, i32 arg5, char* arg6)
{
    return stub<thiscall_t<i32, mmShearInstance*, char*, class Vector3&, class Vector3&, f32, i32, char*>>(
        0x942A0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

u32 mmShearInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmShearInstance*>>(0x94290_Offset, this);
}

void mmShearInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x94D00_Offset);
}

mmBuildingInstance::mmBuildingInstance()
{
    unimplemented();
}

mmBuildingInstance::~mmBuildingInstance()
{
    unimplemented();
}

void __fastcall mmBuildingInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmBuildingInstance*, i32>>(0x945F0_Offset, this, arg1);
}

class MetaClass* mmBuildingInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmBuildingInstance*>>(0x95030_Offset, this);
}

f32 __fastcall mmBuildingInstance::GetScale()
{
    return stub<fastcall_t<f32, mmBuildingInstance*>>(0x945E0_Offset, this);
}

i32 mmBuildingInstance::Init(char* arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4)
{
    return stub<thiscall_t<i32, mmBuildingInstance*, char*, class Vector3&, class Vector3&, class Vector3&>>(
        0x944A0_Offset, this, arg1, arg2, arg3, arg4);
}

u32 mmBuildingInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmBuildingInstance*>>(0x94490_Offset, this);
}

void mmBuildingInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x94EA0_Offset);
}

i32 GetPolyInfo(class agiMeshSet* arg1)
{
    return stub<cdecl_t<i32, class agiMeshSet*>>(0x930E0_Offset, arg1);
}

char* formatf(char const* arg1, ...)
{
    unimplemented();
}

mmYInstance::mmYInstance()
{
    unimplemented();
}

mmYInstance::~mmYInstance()
{
    unimplemented();
}

void mmYInstance::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmYInstance*, class Bank*>>(0x933B0_Offset, this, arg1);
}

void __fastcall mmYInstance::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmYInstance*, class Matrix34 const&>>(0x932F0_Offset, this, arg1);
}

class MetaClass* mmYInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmYInstance*>>(0x94B60_Offset, this);
}

class Vector3& __fastcall mmYInstance::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmYInstance*>>(0x93390_Offset, this);
}

u32 mmYInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmYInstance*>>(0x933A0_Offset, this);
}

class Matrix34& __fastcall mmYInstance::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmYInstance*, class Matrix34&>>(0x93340_Offset, this, arg1);
}

void mmYInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x94AC0_Offset);
}

mmMatrixInstance::mmMatrixInstance()
{
    unimplemented();
}

mmMatrixInstance::~mmMatrixInstance()
{
    unimplemented();
}

void mmMatrixInstance::Hit(class mmInstance* arg1)
{
    return stub<thiscall_t<void, mmMatrixInstance*, class mmInstance*>>(0x935B0_Offset, this, arg1);
}

void mmMatrixInstance::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmMatrixInstance*, class Bank*>>(0x935D0_Offset, this, arg1);
}

void __fastcall mmMatrixInstance::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmMatrixInstance*, class Matrix34 const&>>(0x93440_Offset, this, arg1);
}

class MetaClass* mmMatrixInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmMatrixInstance*>>(0x94CF0_Offset, this);
}

class Vector3& __fastcall mmMatrixInstance::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmMatrixInstance*>>(0x93470_Offset, this);
}

i32 mmMatrixInstance::Init(
    char* arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4, i32 arg5, char* arg6)
{
    return stub<thiscall_t<i32, mmMatrixInstance*, char*, class Vector3&, class Vector3&, class Vector3&, i32, char*>>(
        0x93480_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

u32 mmMatrixInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmMatrixInstance*>>(0x935C0_Offset, this);
}

class Matrix34& __fastcall mmMatrixInstance::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmMatrixInstance*, class Matrix34&>>(0x93460_Offset, this, arg1);
}

void mmMatrixInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x94B70_Offset);
}

mmStaticInstance::mmStaticInstance()
{
    unimplemented();
}

mmStaticInstance::~mmStaticInstance()
{
    unimplemented();
}

void mmStaticInstance::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmStaticInstance*, class Bank*>>(0x94960_Offset, this, arg1);
}

void __fastcall mmStaticInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmStaticInstance*, i32>>(0x94230_Offset, this, arg1);
}

class MetaClass* mmStaticInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmStaticInstance*>>(0x951C0_Offset, this);
}

i32 mmStaticInstance::Init(char* arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, i32 arg5, char* arg6)
{
    return stub<thiscall_t<i32, mmStaticInstance*, char*, class Vector3&, class Vector3&, f32, i32, char*>>(
        0x93610_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void __fastcall mmStaticInstance::Relight()
{
    return stub<fastcall_t<void, mmStaticInstance*>>(0x94220_Offset, this);
}

u32 mmStaticInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmStaticInstance*>>(0x94210_Offset, this);
}

void mmStaticInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x95040_Offset);
}

mmFacadeInstance::mmFacadeInstance()
{
    unimplemented();
}

mmFacadeInstance::~mmFacadeInstance()
{
    unimplemented();
}

void __fastcall mmFacadeInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmFacadeInstance*, i32>>(0x94010_Offset, this, arg1);
}

class MetaClass* mmFacadeInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmFacadeInstance*>>(0x95350_Offset, this);
}

f32 __fastcall mmFacadeInstance::GetScale()
{
    return stub<fastcall_t<f32, mmFacadeInstance*>>(0x93FF0_Offset, this);
}

i32 mmFacadeInstance::InitFacade(
    char* arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, i32 arg5, class Vector3 const& arg6)
{
    return stub<
        thiscall_t<i32, mmFacadeInstance*, char*, class Vector3&, class Vector3&, f32, i32, class Vector3 const&>>(
        0x93CC0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

u32 mmFacadeInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmFacadeInstance*>>(0x94000_Offset, this);
}

void mmFacadeInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x951D0_Offset);
}

mmFacadeQuad::mmFacadeQuad(class agiMeshSet* arg1, f32 arg2, f32 arg3)
{
    unimplemented();
}

void mmFacadeQuad::DrawLit(void (*arg1)(u8*, u32*, u32*, class agiMeshSet*), class agiMeshSet* arg2)
{
    return stub<thiscall_t<void, mmFacadeQuad*, void (*)(u8*, u32*, u32*, class agiMeshSet*), class agiMeshSet*>>(
        0x93B70_Offset, this, arg1, arg2);
}

f32 mmFacadeQuad::DoubleArea(class agiMeshSet* arg1)
{
    return stub<cdecl_t<f32, class agiMeshSet*>>(0x937C0_Offset, arg1);
}

i32 mmFacadeQuad::Valid(class agiMeshSet* arg1)
{
    return stub<cdecl_t<i32, class agiMeshSet*>>(0x93820_Offset, arg1);
}

define_dummy_symbol(mmcity_inst);
