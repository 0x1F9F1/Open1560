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

define_dummy_symbol(mmcity_inst);

#include "inst.h"

mmInstance::mmInstance()
{
    unimplemented();
}

mmInstance::~mmInstance()
{
    unimplemented(arg1);
}

class mmPhysEntity* mmInstance::GetEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmInstance*>>(0x433DB0, this);
}

class mmPhysEntity* mmInstance::AttachEntity()
{
    return stub<thiscall_t<class mmPhysEntity*, mmInstance*>>(0x433DC0, this);
}

class Vector3 mmInstance::GetVelocity()
{
    return stub<thiscall_t<class Vector3, mmInstance*>>(0x433DD0, this);
}

void mmInstance::Impact(class mmInstance* arg1, class Vector3* arg2)
{
    return stub<thiscall_t<void, mmInstance*, class mmInstance*, class Vector3*>>(0x433DF0, this, arg1, arg2);
}

void mmInstance::Detach()
{
    return stub<thiscall_t<void, mmInstance*>>(0x433E00, this);
}

void __fastcall mmInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmInstance*, i32>>(0x492AA0, this, arg1);
}

void __fastcall mmInstance::DrawShadow()
{
    return stub<fastcall_t<void, mmInstance*>>(0x492B00, this);
}

void __fastcall mmInstance::DrawGlow()
{
    return stub<fastcall_t<void, mmInstance*>>(0x492B10, this);
}

void __fastcall mmInstance::Relight()
{
    return stub<fastcall_t<void, mmInstance*>>(0x492A10, this);
}

u32 mmInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmInstance*>>(0x493120, this);
}

void mmInstance::Reset()
{
    return stub<thiscall_t<void, mmInstance*>>(0x493130, this);
}

i32 mmInstance::Init(char* arg1, class Vector3& arg2, class Vector3& arg3, i32 arg4, char* arg5)
{
    return stub<thiscall_t<i32, mmInstance*, char*, class Vector3&, class Vector3&, i32, char*>>(
        0x492B20, this, arg1, arg2, arg3, arg4, arg5);
}

f32 __fastcall mmInstance::GetScale()
{
    return stub<fastcall_t<f32, mmInstance*>>(0x492A20, this);
}

i32 mmInstance::ComputeLod(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, mmInstance*, f32, f32>>(0x492A30, this, arg1, arg2);
}

void mmInstance::AddMeshes(char* arg1, i32 arg2, char* arg3, class Vector3* arg4)
{
    return stub<thiscall_t<void, mmInstance*, char*, i32, char*, class Vector3*>>(
        0x493290, this, arg1, arg2, arg3, arg4);
}

void mmInstance::DrawDropShadow(i32 arg1, i32 arg2, class Matrix34 const& arg3)
{
    return stub<thiscall_t<void, mmInstance*, i32, i32, class Matrix34 const&>>(0x4946B0, this, arg1, arg2, arg3);
}

class MetaClass* mmInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmInstance*>>(0x494AB0, this);
}

class agiMeshSet* mmInstance::GetResidentMeshSet(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<class agiMeshSet*, mmInstance*, i32, i32, i32>>(0x492BE0, this, arg1, arg2, arg3);
}

void mmInstance::InitMeshes(char* arg1, i32 arg2, char* arg3, class Vector3* arg4)
{
    return stub<thiscall_t<void, mmInstance*, char*, i32, char*, class Vector3*>>(
        0x493250, this, arg1, arg2, arg3, arg4);
}

void mmInstance::operator delete(void* arg1)
{
    return stub<cdecl_t<void, void*>>(0x430690, arg1);
}

void mmInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x494A10);
}

i32 mmInstance::GetMeshSetSet(char* arg1, i32 arg2, char* arg3, class Vector3* arg4)
{
    return stub<cdecl_t<i32, char*, i32, char*, class Vector3*>>(0x492C70, arg1, arg2, arg3, arg4);
}

void mmInstance::ResetAll()
{
    return stub<cdecl_t<void>>(0x493140);
}

mmShearInstance::mmShearInstance()
{
    unimplemented();
}

mmShearInstance::~mmShearInstance()
{
    unimplemented(arg1);
}

void __fastcall mmShearInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmShearInstance*, i32>>(0x494460, this, arg1);
}

class MetaClass* mmShearInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmShearInstance*>>(0x494E90, this);
}

f32 __fastcall mmShearInstance::GetScale()
{
    return stub<fastcall_t<f32, mmShearInstance*>>(0x494480, this);
}

i32 mmShearInstance::Init(char* arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, i32 arg5, char* arg6)
{
    return stub<thiscall_t<i32, mmShearInstance*, char*, class Vector3&, class Vector3&, f32, i32, char*>>(
        0x4942A0, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

u32 mmShearInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmShearInstance*>>(0x494290, this);
}

void mmShearInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x494D00);
}

mmBuildingInstance::mmBuildingInstance()
{
    unimplemented();
}

mmBuildingInstance::~mmBuildingInstance()
{
    unimplemented(arg1);
}

void __fastcall mmBuildingInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmBuildingInstance*, i32>>(0x4945F0, this, arg1);
}

class MetaClass* mmBuildingInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmBuildingInstance*>>(0x495030, this);
}

f32 __fastcall mmBuildingInstance::GetScale()
{
    return stub<fastcall_t<f32, mmBuildingInstance*>>(0x4945E0, this);
}

i32 mmBuildingInstance::Init(char* arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4)
{
    return stub<thiscall_t<i32, mmBuildingInstance*, char*, class Vector3&, class Vector3&, class Vector3&>>(
        0x4944A0, this, arg1, arg2, arg3, arg4);
}

u32 mmBuildingInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmBuildingInstance*>>(0x494490, this);
}

void mmBuildingInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x494EA0);
}

i32 GetPolyInfo(class agiMeshSet* arg1)
{
    return stub<cdecl_t<i32, class agiMeshSet*>>(0x4930E0, arg1);
}

char* formatf(char const* arg1, ...)
{
    unimplemented(arg1);
}

mmYInstance::mmYInstance()
{
    unimplemented();
}

mmYInstance::~mmYInstance()
{
    unimplemented(arg1);
}

void mmYInstance::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmYInstance*, class Bank*>>(0x4933B0, this, arg1);
}

void __fastcall mmYInstance::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmYInstance*, class Matrix34 const&>>(0x4932F0, this, arg1);
}

class MetaClass* mmYInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmYInstance*>>(0x494B60, this);
}

class Vector3& __fastcall mmYInstance::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmYInstance*>>(0x493390, this);
}

u32 mmYInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmYInstance*>>(0x4933A0, this);
}

class Matrix34& __fastcall mmYInstance::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmYInstance*, class Matrix34&>>(0x493340, this, arg1);
}

void mmYInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x494AC0);
}

mmMatrixInstance::mmMatrixInstance()
{
    unimplemented();
}

mmMatrixInstance::~mmMatrixInstance()
{
    unimplemented(arg1);
}

void mmMatrixInstance::Hit(class mmInstance* arg1)
{
    return stub<thiscall_t<void, mmMatrixInstance*, class mmInstance*>>(0x4935B0, this, arg1);
}

void mmMatrixInstance::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmMatrixInstance*, class Bank*>>(0x4935D0, this, arg1);
}

void __fastcall mmMatrixInstance::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmMatrixInstance*, class Matrix34 const&>>(0x493440, this, arg1);
}

class MetaClass* mmMatrixInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmMatrixInstance*>>(0x494CF0, this);
}

class Vector3& __fastcall mmMatrixInstance::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmMatrixInstance*>>(0x493470, this);
}

i32 mmMatrixInstance::Init(
    char* arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4, i32 arg5, char* arg6)
{
    return stub<thiscall_t<i32, mmMatrixInstance*, char*, class Vector3&, class Vector3&, class Vector3&, i32, char*>>(
        0x493480, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

u32 mmMatrixInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmMatrixInstance*>>(0x4935C0, this);
}

class Matrix34& __fastcall mmMatrixInstance::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmMatrixInstance*, class Matrix34&>>(0x493460, this, arg1);
}

void mmMatrixInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x494B70);
}

mmStaticInstance::mmStaticInstance()
{
    unimplemented();
}

mmStaticInstance::~mmStaticInstance()
{
    unimplemented(arg1);
}

void mmStaticInstance::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmStaticInstance*, class Bank*>>(0x494960, this, arg1);
}

void __fastcall mmStaticInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmStaticInstance*, i32>>(0x494230, this, arg1);
}

class MetaClass* mmStaticInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmStaticInstance*>>(0x4951C0, this);
}

i32 mmStaticInstance::Init(char* arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, i32 arg5, char* arg6)
{
    return stub<thiscall_t<i32, mmStaticInstance*, char*, class Vector3&, class Vector3&, f32, i32, char*>>(
        0x493610, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void __fastcall mmStaticInstance::Relight()
{
    return stub<fastcall_t<void, mmStaticInstance*>>(0x494220, this);
}

u32 mmStaticInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmStaticInstance*>>(0x494210, this);
}

void mmStaticInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x495040);
}

mmFacadeInstance::mmFacadeInstance()
{
    unimplemented();
}

mmFacadeInstance::~mmFacadeInstance()
{
    unimplemented(arg1);
}

void __fastcall mmFacadeInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmFacadeInstance*, i32>>(0x494010, this, arg1);
}

class MetaClass* mmFacadeInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmFacadeInstance*>>(0x495350, this);
}

f32 __fastcall mmFacadeInstance::GetScale()
{
    return stub<fastcall_t<f32, mmFacadeInstance*>>(0x493FF0, this);
}

i32 mmFacadeInstance::InitFacade(
    char* arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, i32 arg5, class Vector3 const& arg6)
{
    return stub<
        thiscall_t<i32, mmFacadeInstance*, char*, class Vector3&, class Vector3&, f32, i32, class Vector3 const&>>(
        0x493CC0, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

u32 mmFacadeInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmFacadeInstance*>>(0x494000, this);
}

void mmFacadeInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4951D0);
}

mmFacadeQuad::mmFacadeQuad(class agiMeshSet* arg1, f32 arg2, f32 arg3)
{
    unimplemented(arg1, arg2, arg3);
}

void mmFacadeQuad::DrawLit(void (*arg1)(u8*, u32*, u32*, class agiMeshSet*), class agiMeshSet* arg2)
{
    return stub<thiscall_t<void, mmFacadeQuad*, void (*)(u8*, u32*, u32*, class agiMeshSet*), class agiMeshSet*>>(
        0x493B70, this, arg1, arg2);
}

f32 mmFacadeQuad::DoubleArea(class agiMeshSet* arg1)
{
    return stub<cdecl_t<f32, class agiMeshSet*>>(0x4937C0, arg1);
}

i32 mmFacadeQuad::Valid(class agiMeshSet* arg1)
{
    return stub<cdecl_t<i32, class agiMeshSet*>>(0x493820, arg1);
}
