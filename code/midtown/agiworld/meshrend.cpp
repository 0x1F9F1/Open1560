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

define_dummy_symbol(agiworld_meshrend);

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
    return stub<thiscall_t<void, agiMeshSet*, class Stream*>>(0x502BD0, this, arg1);
}

void agiMeshSet::BinarySave(class Stream* arg1)
{
    return stub<thiscall_t<void, agiMeshSet*, class Stream*>>(0x516B30, this, arg1);
}

void agiMeshSet::ComputePlaneEquations()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x5148D0, this);
}

i32 agiMeshSet::Draw(u32 arg1)
{
    return stub<thiscall_t<i32, agiMeshSet*, u32>>(0x506ED0, this, arg1);
}

i32 agiMeshSet::DrawColor(u32 arg1, u32 arg2)
{
    return stub<thiscall_t<i32, agiMeshSet*, u32, u32>>(0x506FD0, this, arg1, arg2);
}

i32 agiMeshSet::DrawLit(void (*arg1)(u8*, u32*, u32*, class agiMeshSet*), u32 arg2, u32* arg3)
{
    return stub<thiscall_t<i32, agiMeshSet*, void (*)(u8*, u32*, u32*, class agiMeshSet*), u32, u32*>>(
        0x507040, this, arg1, arg2, arg3);
}

void agiMeshSet::DrawLitEnv(
    void (*arg1)(u8*, u32*, u32*, class agiMeshSet*), class agiTexDef* arg2, class Matrix34& arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiMeshSet*, void (*)(u8*, u32*, u32*, class agiMeshSet*), class agiTexDef*,
        class Matrix34&, u32>>(0x507120, this, arg1, arg2, arg3, arg4);
}

void agiMeshSet::DrawLitSph(void (*arg1)(u8*, u32*, u32*, class agiMeshSet*), class agiTexDef* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, void (*)(u8*, u32*, u32*, class agiMeshSet*), class agiTexDef*, u32>>(
        0x507250, this, arg1, arg2, arg3);
}

void agiMeshSet::DrawNormals(class Vector3& arg1)
{
    return stub<thiscall_t<void, agiMeshSet*, class Vector3&>>(0x50EBC0, this, arg1);
}

void agiMeshSet::DrawShadow(u32 arg1, class Vector4 const& arg2, class Vector3 const& arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32, class Vector4 const&, class Vector3 const&>>(
        0x506F40, this, arg1, arg2, arg3);
}

void agiMeshSet::EnvMap(class Matrix34& arg1, class agiTexDef* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, class Matrix34&, class agiTexDef*, u32>>(
        0x50DB10, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x50D0E0, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_UV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x509FE0, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_UV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x50A780, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_UV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x50AF10, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_UV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x50B4E0, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_noUV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x50BA90, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_noUV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x50C130, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_noUV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x50C7A0, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_HW_noUV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x50CC50, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_UV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x507D30, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_UV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x508330, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_UV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x508910, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_UV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x508D30, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_noUV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x509130, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_noUV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x5095E0, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_noUV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x509A70, this, arg1, arg2, arg3);
}

void agiMeshSet::FirstPass_SW_noUV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, class Vector2*, u32>>(0x509D30, this, arg1, arg2, arg3);
}

i32 agiMeshSet::Geometry(u32 arg1, class Vector3* arg2, class Vector4* arg3)
{
    return stub<thiscall_t<i32, agiMeshSet*, u32, class Vector3*, class Vector4*>>(0x507320, this, arg1, arg2, arg3);
}

i32 agiMeshSet::IsFullyResident(i32 arg1)
{
    return stub<thiscall_t<i32, agiMeshSet*, i32>>(0x514BC0, this, arg1);
}

i32 agiMeshSet::LockIfResident()
{
    return stub<thiscall_t<i32, agiMeshSet*>>(0x514B20, this);
}

void agiMeshSet::MakeResident()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x514B90, this);
}

void agiMeshSet::MultiTexEnvMap(u32* arg1, u32 arg2, class agiTexDef* arg3, class Matrix34& arg4)
{
    return stub<thiscall_t<void, agiMeshSet*, u32*, u32, class agiTexDef*, class Matrix34&>>(
        0x50D170, this, arg1, arg2, arg3, arg4);
}

void agiMeshSet::Offset(class Vector3 arg1)
{
    return stub<thiscall_t<void, agiMeshSet*, class Vector3>>(0x514880, this, arg1);
}

void agiMeshSet::PageIn()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x514B00, this);
}

i32 agiMeshSet::ShadowGeometry(u32 arg1, class Vector3* arg2, class Vector4 const& arg3, class Vector3 const& arg4)
{
    return stub<thiscall_t<i32, agiMeshSet*, u32, class Vector3*, class Vector4 const&, class Vector3 const&>>(
        0x507920, this, arg1, arg2, arg3, arg4);
}

void agiMeshSet::SphereMap(class agiTexDef* arg1, u32 arg2)
{
    return stub<thiscall_t<void, agiMeshSet*, class agiTexDef*, u32>>(0x50E1D0, this, arg1, arg2);
}

void agiMeshSet::Unlock()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x514B50, this);
}

void agiMeshSet::UnlockAndFree()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x514B70, this);
}

void agiMeshSet::DrawCard(class Vector3& arg1, f32 arg2, u32 arg3, u32 arg4, u32 arg5)
{
    return stub<cdecl_t<void, class Vector3&, f32, u32, u32, u32>>(0x50EE70, arg1, arg2, arg3, arg4, arg5);
}

void agiMeshSet::DrawLines(class Vector3* arg1, class Vector3* arg2, u32* arg3, i32 arg4)
{
    return stub<cdecl_t<void, class Vector3*, class Vector3*, u32*, i32>>(0x50F9B0, arg1, arg2, arg3, arg4);
}

void agiMeshSet::DrawWideLines(class Vector3* arg1, class Vector3* arg2, f32* arg3, u32* arg4, i32 arg5)
{
    return stub<cdecl_t<void, class Vector3*, class Vector3*, f32*, u32*, i32>>(0x50FE00, arg1, arg2, arg3, arg4, arg5);
}

void __fastcall agiMeshSet::Init(i32 arg1)
{
    return stub<fastcall_t<void, i32>>(0x504C00, arg1);
}

void agiMeshSet::InitCards(struct agiMeshCardInfo& arg1)
{
    return stub<cdecl_t<void, struct agiMeshCardInfo&>>(0x50EE30, arg1);
}

void agiMeshSet::InitLocalize()
{
    return stub<cdecl_t<void>>(0x504A00);
}

void agiMeshSet::Localize(class Vector3& arg1, class Vector3& arg2)
{
    return stub<cdecl_t<void, class Vector3&, class Vector3&>>(0x504AC0, arg1, arg2);
}

void agiMeshSet::LocalizeDirection(class Vector3& arg1, class Vector3& arg2)
{
    return stub<cdecl_t<void, class Vector3&, class Vector3&>>(0x504B70, arg1, arg2);
}

void agiMeshSet::SetFog(f32 arg1, i32 arg2)
{
    return stub<cdecl_t<void, f32, i32>>(0x5050C0, arg1, arg2);
}

void agiMeshSet::ClipTri(i32 arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, agiMeshSet*, i32, i32, i32, i32>>(0x505E40, this, arg1, arg2, arg3, arg4);
}

void __fastcall agiMeshSet::InitMtx(class agiViewParameters& arg1, i32 arg2)
{
    return stub<fastcall_t<void, class agiViewParameters&, i32>>(0x504730, arg1, arg2);
}

void __fastcall agiMeshSet::InitViewport(class agiViewParameters& arg1)
{
    return stub<fastcall_t<void, class agiViewParameters&>>(0x504EB0, arg1);
}

void __fastcall agiMeshSet::ShadowInit(class Vector4 const& arg1, class Vector3 const& arg2)
{
    return stub<fastcall_t<void, class Vector4 const&, class Vector3 const&>>(0x504C80, arg1, arg2);
}

void __fastcall agiMeshSet::ShadowTransform(class Vector4* arg1, class Vector3* arg2, i32 arg3)
{
    return stub<fastcall_t<void, class Vector4*, class Vector3*, i32>>(0x505360, arg1, arg2, arg3);
}

u32 __fastcall agiMeshSet::ShadowTransformOutcode(u8* arg1, class Vector4* arg2, class Vector3* arg3, i32 arg4)
{
    return stub<fastcall_t<u32, u8*, class Vector4*, class Vector3*, i32>>(0x505A30, arg1, arg2, arg3, arg4);
}

void __fastcall agiMeshSet::ToScreen(u8* arg1, class Vector4* arg2, i32 arg3)
{
    return stub<fastcall_t<void, u8*, class Vector4*, i32>>(0x516620, arg1, arg2, arg3);
}

void __fastcall agiMeshSet::Transform(class Vector4* arg1, class Vector3* arg2, i32 arg3)
{
    return stub<fastcall_t<void, class Vector4*, class Vector3*, i32>>(0x5050F0, arg1, arg2, arg3);
}

u32 __fastcall agiMeshSet::TransformOutcode(u8* arg1, class Vector4* arg2, class Vector3* arg3, i32 arg4)
{
    return stub<fastcall_t<u32, u8*, class Vector4*, class Vector3*, i32>>(0x5055E0, arg1, arg2, arg3, arg4);
}

void agiMeshSet::BeginGfx()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x505E20, this);
}

void agiMeshSet::DoPageIn()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x5032A0, this);
}

void agiMeshSet::EndGfx()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x505E30, this);
}

void agiMeshSet::PageInCallback(void* arg1)
{
    return stub<cdecl_t<void, void*>>(0x514AF0, arg1);
}

void agiMeshSet::PageOutCallback(void* arg1, i32 arg2)
{
    return stub<cdecl_t<void, void*, i32>>(0x503180, arg1, arg2);
}

u32 EyePlaneOutcode(u8* arg1, u8 arg2, class Vector4& arg3, class Vector3* arg4, i32 arg5)
{
    return stub<cdecl_t<u32, u8*, u8, class Vector4&, class Vector3*, i32>>(0x505990, arg1, arg2, arg3, arg4, arg5);
}

void SetClipMode(i32 arg1)
{
    return stub<cdecl_t<void, i32>>(0x504690, arg1);
}

void __fastcall begin_invert(class Vector4* arg1)
{
    return stub<fastcall_t<void, class Vector4*>>(0x505E00, arg1);
}

void __fastcall end_invert(class Vector4* arg1)
{
    return stub<fastcall_t<void, class Vector4*>>(0x505E10, arg1);
}

static void __fastcall ClipNX(struct CV& arg1, struct CV& arg2)
{
    return stub<fastcall_t<void, struct CV&, struct CV&>>(0x506380, arg1, arg2);
}

static i32 ClipNX(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506260, arg1, arg2, arg3);
}

static void __fastcall ClipNY(struct CV& arg1, struct CV& arg2)
{
    return stub<fastcall_t<void, struct CV&, struct CV&>>(0x5067A0, arg1, arg2);
}

static i32 ClipNY(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506680, arg1, arg2, arg3);
}

static void __fastcall ClipNZ(struct CV& arg1, struct CV& arg2)
{
    return stub<fastcall_t<void, struct CV&, struct CV&>>(0x506BB0, arg1, arg2);
}

static i32 ClipNZ(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506A90, arg1, arg2, arg3);
}

static void __fastcall ClipPX(struct CV& arg1, struct CV& arg2)
{
    return stub<fastcall_t<void, struct CV&, struct CV&>>(0x506590, arg1, arg2);
}

static i32 ClipPX(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506470, arg1, arg2, arg3);
}

static void __fastcall ClipPY(struct CV& arg1, struct CV& arg2)
{
    return stub<fastcall_t<void, struct CV&, struct CV&>>(0x5069B0, arg1, arg2);
}

static i32 ClipPY(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506890, arg1, arg2, arg3);
}

static void __fastcall ClipPZ(struct CV& arg1, struct CV& arg2)
{
    return stub<fastcall_t<void, struct CV&, struct CV&>>(0x506DC0, arg1, arg2);
}

static i32 ClipPZ(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506CA0, arg1, arg2, arg3);
}

static i32 FullClip(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x5061B0, arg1, arg2, arg3);
}

static i32 ZClipOnly(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506EA0, arg1, arg2, arg3);
}

void agiMeshCardInfo::Init(i32 arg1, struct agiMeshCardVertex* arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, agiMeshCardInfo*, i32, struct agiMeshCardVertex*, i32, i32, i32>>(
        0x50EC90, this, arg1, arg2, arg3, arg4, arg5);
}

void agiPolySet::Triangle(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiPolySet*, i32, i32, i32>>(0x510480, this, arg1, arg2, arg3);
}
