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

#include "meshrend.h"

#include "vector7/vector3.h"

agiMeshSet::agiMeshSet()
{
    unimplemented();
}

agiMeshSet::~agiMeshSet()
{
    unimplemented();
}

void agiMeshSet::BinaryLoad(class Stream* arg1)
{
    return stub<thiscall_t<void, agiMeshSet*, class Stream*>>(0x102BD0_Offset, this, arg1);
}

void agiMeshSet::BinarySave(class Stream* arg1)
{
    return stub<thiscall_t<void, agiMeshSet*, class Stream*>>(0x116B30_Offset, this, arg1);
}

void agiMeshSet::ComputePlaneEquations()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x1148D0_Offset, this);
}

i32 agiMeshSet::Draw(u32 arg1)
{
    return stub<thiscall_t<i32, agiMeshSet*, u32>>(0x106ED0_Offset, this, arg1);
}

i32 agiMeshSet::DrawColor(u32 arg1, u32 arg2)
{
    return stub<thiscall_t<i32, agiMeshSet*, u32, u32>>(0x106FD0_Offset, this, arg1, arg2);
}

i32 agiMeshSet::DrawLit(void (*arg1)(u8*, u32*, u32*, class agiMeshSet*), u32 arg2, u32* arg3)
{
    return stub<thiscall_t<i32, agiMeshSet*, void (*)(u8*, u32*, u32*, class agiMeshSet*), u32, u32*>>(
        0x107040_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::DrawLitEnv(
    void (*arg1)(u8*, u32*, u32*, class agiMeshSet*), class agiTexDef* arg2, class Matrix34& arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiMeshSet*, void (*)(u8*, u32*, u32*, class agiMeshSet*), class agiTexDef*,
        class Matrix34&, u32>>(0x107120_Offset, this, arg1, arg2, arg3, arg4);
}

void agiMeshSet::DrawLitSph(void (*arg1)(u8*, u32*, u32*, class agiMeshSet*), class agiTexDef* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, void (*)(u8*, u32*, u32*, class agiMeshSet*), class agiTexDef*, u32>>(
        0x107250_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::DrawNormals(class Vector3& arg1)
{
    return stub<thiscall_t<void, agiMeshSet*, class Vector3&>>(0x10EBC0_Offset, this, arg1);
}

void agiMeshSet::DrawShadow(u32 arg1, class Vector4 const& arg2, class Vector3 const& arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32, class Vector4 const&, class Vector3 const&>>(
        0x106F40_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::EnvMap(class Matrix34& arg1, class agiTexDef* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, class Matrix34&, class agiTexDef*, u32>>(
        0x10DB10_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x10D0E0_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_UV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x109FE0_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_UV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x10A780_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_UV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x10AF10_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_UV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x10B4E0_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_noUV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x10BA90_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_noUV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x10C130_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_noUV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x10C7A0_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_noUV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x10CC50_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_UV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x107D30_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_UV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x108330_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_UV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x108910_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_UV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x108D30_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_noUV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x109130_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_noUV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x1095E0_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_noUV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x109A70_Offset, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_noUV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x109D30_Offset, this, arg1, arg2, arg3);
}

i32 agiMeshSet::Geometry(u32 arg1, class Vector3* arg2, class Vector4* arg3)
{
    return stub<thiscall_t<i32, agiMeshSet*, u32, class Vector3*, class Vector4*>>(
        0x107320_Offset, this, arg1, arg2, arg3);
}

i32 agiMeshSet::IsFullyResident(i32 arg1)
{
    return stub<thiscall_t<i32, agiMeshSet*, i32>>(0x114BC0_Offset, this, arg1);
}

i32 agiMeshSet::LockIfResident()
{
    return stub<thiscall_t<i32, agiMeshSet*>>(0x114B20_Offset, this);
}

void agiMeshSet::MakeResident()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x114B90_Offset, this);
}

void agiMeshSet::MultiTexEnvMap(u32* arg1, u32 arg2, class agiTexDef* arg3, class Matrix34& arg4)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, u32, class agiTexDef*, class Matrix34&>>(
        0x10D170_Offset, this, arg1, arg2, arg3, arg4);
}

void agiMeshSet::Offset(class Vector3 arg1)
{
    return stub<thiscall_t<void, agiMeshSet*, class Vector3>>(0x114880_Offset, this, arg1);
}

void agiMeshSet::PageIn()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x114B00_Offset, this);
}

i32 agiMeshSet::ShadowGeometry(u32 arg1, class Vector3* arg2, class Vector4 const& arg3, class Vector3 const& arg4)
{
    return stub<thiscall_t<i32, agiMeshSet*, u32, class Vector3*, class Vector4 const&, class Vector3 const&>>(
        0x107920_Offset, this, arg1, arg2, arg3, arg4);
}

void agiMeshSet::SphereMap(class agiTexDef* arg1, u32 arg2)
{
    return stub<thiscall_t<void, agiMeshSet*, class agiTexDef*, u32>>(0x10E1D0_Offset, this, arg1, arg2);
}

void agiMeshSet::Unlock()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x114B50_Offset, this);
}

void agiMeshSet::UnlockAndFree()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x114B70_Offset, this);
}

void agiMeshSet::DrawCard(class Vector3& arg1, f32 arg2, u32 arg3, u32 arg4, u32 arg5)
{
    return stub<cdecl_t<void, class Vector3&, f32, u32, u32, u32>>(0x10EE70_Offset, arg1, arg2, arg3, arg4, arg5);
}

void agiMeshSet::DrawLines(class Vector3* arg1, class Vector3* arg2, u32* arg3, i32 arg4)
{
    return stub<cdecl_t<void, class Vector3*, class Vector3*, u32*, i32>>(0x10F9B0_Offset, arg1, arg2, arg3, arg4);
}

void agiMeshSet::DrawWideLines(class Vector3* arg1, class Vector3* arg2, f32* arg3, u32* arg4, i32 arg5)
{
    return stub<cdecl_t<void, class Vector3*, class Vector3*, f32*, u32*, i32>>(
        0x10FE00_Offset, arg1, arg2, arg3, arg4, arg5);
}

void __fastcall agiMeshSet::Init(i32 arg1)
{
    return stub<fastcall_t<void, i32>>(0x104C00_Offset, arg1);
}

void agiMeshSet::InitCards(struct agiMeshCardInfo& arg1)
{
    return stub<cdecl_t<void, struct agiMeshCardInfo&>>(0x10EE30_Offset, arg1);
}

void agiMeshSet::InitLocalize()
{
    return stub<cdecl_t<void>>(0x104A00_Offset);
}

void agiMeshSet::Localize(class Vector3& arg1, class Vector3& arg2)
{
    return stub<cdecl_t<void, class Vector3&, class Vector3&>>(0x104AC0_Offset, arg1, arg2);
}

void agiMeshSet::LocalizeDirection(class Vector3& arg1, class Vector3& arg2)
{
    return stub<cdecl_t<void, class Vector3&, class Vector3&>>(0x104B70_Offset, arg1, arg2);
}

void agiMeshSet::SetFog(f32 arg1, i32 arg2)
{
    return stub<cdecl_t<void, f32, i32>>(0x1050C0_Offset, arg1, arg2);
}

void agiMeshSet::ClipTri(i32 arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, agiMeshSet*, i32, i32, i32, i32>>(0x105E40_Offset, this, arg1, arg2, arg3, arg4);
}

void __fastcall agiMeshSet::InitMtx(class agiViewParameters& arg1, i32 arg2)
{
    return stub<fastcall_t<void, class agiViewParameters&, i32>>(0x104730_Offset, arg1, arg2);
}

void __fastcall agiMeshSet::InitViewport(class agiViewParameters& arg1)
{
    return stub<fastcall_t<void, class agiViewParameters&>>(0x104EB0_Offset, arg1);
}

void __fastcall agiMeshSet::ShadowInit(class Vector4 const& arg1, class Vector3 const& arg2)
{
    return stub<fastcall_t<void, class Vector4 const&, class Vector3 const&>>(0x104C80_Offset, arg1, arg2);
}

void __fastcall agiMeshSet::ShadowTransform(class Vector4* arg1, class Vector3* arg2, i32 arg3)
{
    return stub<fastcall_t<void, class Vector4*, class Vector3*, i32>>(0x105360_Offset, arg1, arg2, arg3);
}

u32 __fastcall agiMeshSet::ShadowTransformOutcode(u8* arg1, class Vector4* arg2, class Vector3* arg3, i32 arg4)
{
    return stub<fastcall_t<u32, u8*, class Vector4*, class Vector3*, i32>>(0x105A30_Offset, arg1, arg2, arg3, arg4);
}

void __fastcall agiMeshSet::ToScreen(u8* arg1, class Vector4* arg2, i32 arg3)
{
    return stub<fastcall_t<void, u8*, class Vector4*, i32>>(0x116620_Offset, arg1, arg2, arg3);
}

void __fastcall agiMeshSet::Transform(class Vector4* arg1, class Vector3* arg2, i32 arg3)
{
    return stub<fastcall_t<void, class Vector4*, class Vector3*, i32>>(0x1050F0_Offset, arg1, arg2, arg3);
}

u32 __fastcall agiMeshSet::TransformOutcode(u8* arg1, class Vector4* arg2, class Vector3* arg3, i32 arg4)
{
    return stub<fastcall_t<u32, u8*, class Vector4*, class Vector3*, i32>>(0x1055E0_Offset, arg1, arg2, arg3, arg4);
}

void agiMeshSet::BeginGfx()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x105E20_Offset, this);
}

void agiMeshSet::DoPageIn()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x1032A0_Offset, this);
}

void agiMeshSet::EndGfx()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x105E30_Offset, this);
}

void agiMeshSet::PageInCallback(void* arg1)
{
    return stub<cdecl_t<void, void*>>(0x114AF0_Offset, arg1);
}

void agiMeshSet::PageOutCallback(void* arg1, i32 arg2)
{
    return stub<cdecl_t<void, void*, i32>>(0x103180_Offset, arg1, arg2);
}

u32 EyePlaneOutcode(u8* arg1, u8 arg2, class Vector4& arg3, class Vector3* arg4, i32 arg5)
{
    return stub<cdecl_t<u32, u8*, u8, class Vector4&, class Vector3*, i32>>(
        0x105990_Offset, arg1, arg2, arg3, arg4, arg5);
}

void SetClipMode(i32 arg1)
{
    return stub<cdecl_t<void, i32>>(0x104690_Offset, arg1);
}

void __fastcall begin_invert(class Vector4* arg1)
{
    return stub<fastcall_t<void, class Vector4*>>(0x105E00_Offset, arg1);
}

void __fastcall end_invert(class Vector4* arg1)
{
    return stub<fastcall_t<void, class Vector4*>>(0x105E10_Offset, arg1);
}

void agiMeshCardInfo::Init(i32 arg1, struct agiMeshCardVertex* arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, agiMeshCardInfo*, i32, struct agiMeshCardVertex*, i32, i32, i32>>(
        0x10EC90_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void agiPolySet::Triangle(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiPolySet*, i32, i32, i32>>(0x110480_Offset, this, arg1, arg2, arg3);
}

define_dummy_symbol(agiworld_meshrend);
