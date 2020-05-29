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

#pragma once

/*
    agiworld:meshrend

    0x504690 | void __cdecl SetClipMode(int) | ?SetClipMode@@YAXH@Z
    0x504730 | protected: static void __fastcall agiMeshSet::InitMtx(class agiViewParameters &,int) | ?InitMtx@agiMeshSet@@KIXAAVagiViewParameters@@H@Z
    0x504A00 | public: static void __cdecl agiMeshSet::InitLocalize(void) | ?InitLocalize@agiMeshSet@@SAXXZ
    0x504AC0 | public: static void __cdecl agiMeshSet::Localize(class Vector3 &,class Vector3 &) | ?Localize@agiMeshSet@@SAXAAVVector3@@0@Z
    0x504B70 | public: static void __cdecl agiMeshSet::LocalizeDirection(class Vector3 &,class Vector3 &) | ?LocalizeDirection@agiMeshSet@@SAXAAVVector3@@0@Z
    0x504C00 | public: static void __fastcall agiMeshSet::Init(int) | ?Init@agiMeshSet@@SIXH@Z
    0x504C80 | protected: static void __fastcall agiMeshSet::ShadowInit(class Vector4 const &,class Vector3 const &) | ?ShadowInit@agiMeshSet@@KIXABVVector4@@ABVVector3@@@Z
    0x504EB0 | protected: static void __fastcall agiMeshSet::InitViewport(class agiViewParameters &) | ?InitViewport@agiMeshSet@@KIXAAVagiViewParameters@@@Z
    0x5050C0 | public: static void __cdecl agiMeshSet::SetFog(float,int) | ?SetFog@agiMeshSet@@SAXMH@Z
    0x5050F0 | protected: static void __fastcall agiMeshSet::Transform(class Vector4 *,class Vector3 *,int) | ?Transform@agiMeshSet@@KIXPAVVector4@@PAVVector3@@H@Z
    0x505360 | protected: static void __fastcall agiMeshSet::ShadowTransform(class Vector4 *,class Vector3 *,int) | ?ShadowTransform@agiMeshSet@@KIXPAVVector4@@PAVVector3@@H@Z
    0x5055E0 | protected: static unsigned int __fastcall agiMeshSet::TransformOutcode(unsigned char *,class Vector4 *,class Vector3 *,int) | ?TransformOutcode@agiMeshSet@@KIIPAEPAVVector4@@PAVVector3@@H@Z
    0x505990 | unsigned int __cdecl EyePlaneOutcode(unsigned char *,unsigned char,class Vector4 &,class Vector3 *,int) | ?EyePlaneOutcode@@YAIPAEEAAVVector4@@PAVVector3@@H@Z
    0x505A30 | protected: static unsigned int __fastcall agiMeshSet::ShadowTransformOutcode(unsigned char *,class Vector4 *,class Vector3 *,int) | ?ShadowTransformOutcode@agiMeshSet@@KIIPAEPAVVector4@@PAVVector3@@H@Z
    0x505E00 | void __fastcall begin_invert(class Vector4 *) | ?begin_invert@@YIXPAVVector4@@@Z
    0x505E10 | void __fastcall end_invert(class Vector4 *) | ?end_invert@@YIXPAVVector4@@@Z
    0x505E20 | private: void __thiscall agiMeshSet::BeginGfx(void) | ?BeginGfx@agiMeshSet@@AAEXXZ
    0x505E30 | private: void __thiscall agiMeshSet::EndGfx(void) | ?EndGfx@agiMeshSet@@AAEXXZ
    0x505E40 | protected: void __thiscall agiMeshSet::ClipTri(int,int,int,int) | ?ClipTri@agiMeshSet@@IAEXHHHH@Z
    0x506ED0 | public: int __thiscall agiMeshSet::Draw(unsigned int) | ?Draw@agiMeshSet@@QAEHI@Z
    0x506F40 | public: void __thiscall agiMeshSet::DrawShadow(unsigned int,class Vector4 const &,class Vector3 const &) | ?DrawShadow@agiMeshSet@@QAEXIABVVector4@@ABVVector3@@@Z
    0x506FD0 | public: int __thiscall agiMeshSet::DrawColor(unsigned int,unsigned int) | ?DrawColor@agiMeshSet@@QAEHII@Z
    0x507040 | public: int __thiscall agiMeshSet::DrawLit(void (__cdecl*)(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *),unsigned int,unsigned int *) | ?DrawLit@agiMeshSet@@QAEHP6AXPAEPAI1PAV1@@ZI1@Z
    0x507120 | public: void __thiscall agiMeshSet::DrawLitEnv(void (__cdecl*)(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *),class agiTexDef *,class Matrix34 &,unsigned int) | ?DrawLitEnv@agiMeshSet@@QAEXP6AXPAEPAI1PAV1@@ZPAVagiTexDef@@AAVMatrix34@@I@Z
    0x507250 | public: void __thiscall agiMeshSet::DrawLitSph(void (__cdecl*)(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *),class agiTexDef *,unsigned int) | ?DrawLitSph@agiMeshSet@@QAEXP6AXPAEPAI1PAV1@@ZPAVagiTexDef@@I@Z
    0x507320 | public: int __thiscall agiMeshSet::Geometry(unsigned int,class Vector3 *,class Vector4 *) | ?Geometry@agiMeshSet@@QAEHIPAVVector3@@PAVVector4@@@Z
    0x507920 | public: int __thiscall agiMeshSet::ShadowGeometry(unsigned int,class Vector3 *,class Vector4 const &,class Vector3 const &) | ?ShadowGeometry@agiMeshSet@@QAEHIPAVVector3@@ABVVector4@@ABV2@@Z
    0x507D30 | public: void __thiscall agiMeshSet::FirstPass_SW_UV_CPV_DYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_SW_UV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x508330 | public: void __thiscall agiMeshSet::FirstPass_SW_UV_CPV_noDYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_SW_UV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x508910 | public: void __thiscall agiMeshSet::FirstPass_SW_UV_noCPV_DYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_SW_UV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x508D30 | public: void __thiscall agiMeshSet::FirstPass_SW_UV_noCPV_noDYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_SW_UV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x509130 | public: void __thiscall agiMeshSet::FirstPass_SW_noUV_CPV_DYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_SW_noUV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x5095E0 | public: void __thiscall agiMeshSet::FirstPass_SW_noUV_CPV_noDYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_SW_noUV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x509A70 | public: void __thiscall agiMeshSet::FirstPass_SW_noUV_noCPV_DYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_SW_noUV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x509D30 | public: void __thiscall agiMeshSet::FirstPass_SW_noUV_noCPV_noDYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_SW_noUV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x509FE0 | public: void __thiscall agiMeshSet::FirstPass_HW_UV_CPV_DYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_HW_UV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x50A780 | public: void __thiscall agiMeshSet::FirstPass_HW_UV_CPV_noDYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_HW_UV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x50AF10 | public: void __thiscall agiMeshSet::FirstPass_HW_UV_noCPV_DYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_HW_UV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x50B4E0 | public: void __thiscall agiMeshSet::FirstPass_HW_UV_noCPV_noDYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_HW_UV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x50BA90 | public: void __thiscall agiMeshSet::FirstPass_HW_noUV_CPV_DYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_HW_noUV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x50C130 | public: void __thiscall agiMeshSet::FirstPass_HW_noUV_CPV_noDYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_HW_noUV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x50C7A0 | public: void __thiscall agiMeshSet::FirstPass_HW_noUV_noCPV_DYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_HW_noUV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x50CC50 | public: void __thiscall agiMeshSet::FirstPass_HW_noUV_noCPV_noDYNTEX(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass_HW_noUV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x50D0E0 | public: void __thiscall agiMeshSet::FirstPass(unsigned int *,class Vector2 *,unsigned int) | ?FirstPass@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    0x50D170 | public: void __thiscall agiMeshSet::MultiTexEnvMap(unsigned int *,unsigned int,class agiTexDef *,class Matrix34 &) | ?MultiTexEnvMap@agiMeshSet@@QAEXPAIIPAVagiTexDef@@AAVMatrix34@@@Z
    0x50DB10 | public: void __thiscall agiMeshSet::EnvMap(class Matrix34 &,class agiTexDef *,unsigned int) | ?EnvMap@agiMeshSet@@QAEXAAVMatrix34@@PAVagiTexDef@@I@Z
    0x50E1D0 | public: void __thiscall agiMeshSet::SphereMap(class agiTexDef *,unsigned int) | ?SphereMap@agiMeshSet@@QAEXPAVagiTexDef@@I@Z
    0x50EBC0 | public: void __thiscall agiMeshSet::DrawNormals(class Vector3 &) | ?DrawNormals@agiMeshSet@@QAEXAAVVector3@@@Z
    0x50EC90 | public: void __thiscall agiMeshCardInfo::Init(int,struct agiMeshCardVertex *,int,int,int) | ?Init@agiMeshCardInfo@@QAEXHPAUagiMeshCardVertex@@HHH@Z
    0x50EE30 | public: static void __cdecl agiMeshSet::InitCards(struct agiMeshCardInfo &) | ?InitCards@agiMeshSet@@SAXAAUagiMeshCardInfo@@@Z
    0x50EE70 | public: static void __cdecl agiMeshSet::DrawCard(class Vector3 &,float,unsigned int,unsigned int,unsigned int) | ?DrawCard@agiMeshSet@@SAXAAVVector3@@MIII@Z
    0x50F9B0 | public: static void __cdecl agiMeshSet::DrawLines(class Vector3 *,class Vector3 *,unsigned int *,int) | ?DrawLines@agiMeshSet@@SAXPAVVector3@@0PAIH@Z
    0x50FE00 | public: static void __cdecl agiMeshSet::DrawWideLines(class Vector3 *,class Vector3 *,float *,unsigned int *,int) | ?DrawWideLines@agiMeshSet@@SAXPAVVector3@@0PAMPAIH@Z
    0x510480 | public: void __thiscall agiPolySet::Triangle(int,int,int) | ?Triangle@agiPolySet@@QAEXHHH@Z
    0x64A6DC | public: static float agiMeshSet::DepthScale | ?DepthScale@agiMeshSet@@2MA
    0x64A6E0 | public: static float agiMeshSet::DepthOffset | ?DepthOffset@agiMeshSet@@2MA
    0x64A6E4 | float ShadowFudge | ?ShadowFudge@@3MA
    0x64A6E8 | unsigned int ShadowColor | ?ShadowColor@@3IA
    0x64A6EC | unsigned int SphMapColor | ?SphMapColor@@3IA
    0x64A730 | public: static struct agiMeshCardVertex * agiMeshSet::DefaultQuad | ?DefaultQuad@agiMeshSet@@2PAUagiMeshCardVertex@@A
    0x64A770 | float MaxCardSize | ?MaxCardSize@@3MA
    0x719C48 | protected: static short * agiMeshSet::indexCounts | ?indexCounts@agiMeshSet@@1PAFA
    0x719E4C | protected: static unsigned int agiMeshSet::MtxSerial | ?MtxSerial@agiMeshSet@@1IA
    0x719E50 | public: static unsigned char * agiMeshSet::codes | ?codes@agiMeshSet@@2PAEA
    0x71DE50 | public: static class Vector3 agiMeshSet::EyePos | ?EyePos@agiMeshSet@@2VVector3@@A
    0x71DE60 | protected: static class Matrix34 agiMeshSet::M | ?M@agiMeshSet@@1VMatrix34@@A
    0x71DE90 | protected: static float agiMeshSet::OffsX | ?OffsX@agiMeshSet@@1MA
    0x720E98 | protected: static float agiMeshSet::MaxY | ?MaxY@agiMeshSet@@1MA
    0x720EB8 | public: static class Vector4 * agiMeshSet::HitEyePlanes | ?HitEyePlanes@agiMeshSet@@2PAVVector4@@A
    0x720ED8 | public: static int agiMeshSet::EyePlaneCount | ?EyePlaneCount@agiMeshSet@@2HA
    0x720EDC | protected: static float agiMeshSet::MaxX | ?MaxX@agiMeshSet@@1MA
    0x720EE0 | protected: static short * agiMeshSet::vertCounts | ?vertCounts@agiMeshSet@@1PAFA
    0x7210E0 | protected: static float agiMeshSet::MinY | ?MinY@agiMeshSet@@1MA
    0x7210E4 | public: static int agiMeshSet::MirrorMode | ?MirrorMode@agiMeshSet@@2HA
    0x721128 | protected: static unsigned char * agiMeshSet::fogout | ?fogout@agiMeshSet@@1PAEA
    0x725128 | protected: static unsigned int agiMeshSet::ViewSerial | ?ViewSerial@agiMeshSet@@1IA
    0x72512C | protected: static float agiMeshSet::ProjZW | ?ProjZW@agiMeshSet@@1MA
    0x725130 | public: static int agiMeshSet::EyePlanesHit | ?EyePlanesHit@agiMeshSet@@2HA
    0x72513C | protected: static float agiMeshSet::HalfWidth | ?HalfWidth@agiMeshSet@@1MA
    0x725140 | protected: static short * agiMeshSet::nextFacet | ?nextFacet@agiMeshSet@@1PAFA
    0x72D140 | protected: static float agiMeshSet::ProjZZ | ?ProjZZ@agiMeshSet@@1MA
    0x72D148 | protected: static class Vector3 agiMeshSet::LocPos | ?LocPos@agiMeshSet@@1VVector3@@A
    0x72D154 | public: static int agiMeshSet::FlipX | ?FlipX@agiMeshSet@@2HA
    0x72D158 | public: static float agiMeshSet::FogValue | ?FogValue@agiMeshSet@@2MA
    0x72D160 | protected: static short * agiMeshSet::firstFacet | ?firstFacet@agiMeshSet@@1PAFA
    0x73D390 | protected: static float agiMeshSet::MinX | ?MinX@agiMeshSet@@1MA
    0x73D398 | public: static class Vector4 * agiMeshSet::EyePlanes | ?EyePlanes@agiMeshSet@@2PAVVector4@@A
    0x73D3B8 | protected: static float agiMeshSet::OffsY | ?OffsY@agiMeshSet@@1MA
    0x73D3BC | protected: static int agiMeshSet::AllowEyeBackfacing | ?AllowEyeBackfacing@agiMeshSet@@1HA
    0x73D3C0 | protected: static float agiMeshSet::HalfHeight | ?HalfHeight@agiMeshSet@@1MA
    0x73D3C4 | float MinCardSize | ?MinCardSize@@3MA
    0x5061B0 | int __cdecl FullClip(struct CV *,struct CV *,int) | ?FullClip@@YAHPAUCV@@0H@Z
    0x506260 | int __cdecl ClipNX(struct CV *,struct CV *,int) | ?ClipNX@@YAHPAUCV@@0H@Z
    0x506380 | void __fastcall ClipNX(struct CV &,struct CV &) | ?ClipNX@@YIXAAUCV@@0@Z
    0x506470 | int __cdecl ClipPX(struct CV *,struct CV *,int) | ?ClipPX@@YAHPAUCV@@0H@Z
    0x506590 | void __fastcall ClipPX(struct CV &,struct CV &) | ?ClipPX@@YIXAAUCV@@0@Z
    0x506680 | int __cdecl ClipNY(struct CV *,struct CV *,int) | ?ClipNY@@YAHPAUCV@@0H@Z
    0x5067A0 | void __fastcall ClipNY(struct CV &,struct CV &) | ?ClipNY@@YIXAAUCV@@0@Z
    0x506890 | int __cdecl ClipPY(struct CV *,struct CV *,int) | ?ClipPY@@YAHPAUCV@@0H@Z
    0x5069B0 | void __fastcall ClipPY(struct CV &,struct CV &) | ?ClipPY@@YIXAAUCV@@0@Z
    0x506A90 | int __cdecl ClipNZ(struct CV *,struct CV *,int) | ?ClipNZ@@YAHPAUCV@@0H@Z
    0x506BB0 | void __fastcall ClipNZ(struct CV &,struct CV &) | ?ClipNZ@@YIXAAUCV@@0@Z
    0x506CA0 | int __cdecl ClipPZ(struct CV *,struct CV *,int) | ?ClipPZ@@YAHPAUCV@@0H@Z
    0x506DC0 | void __fastcall ClipPZ(struct CV &,struct CV &) | ?ClipPZ@@YIXAAUCV@@0@Z
    0x506EA0 | int __cdecl ZClipOnly(struct CV *,struct CV *,int) | ?ZClipOnly@@YAHPAUCV@@0H@Z
*/

// 0x505990 | ?EyePlaneOutcode@@YAIPAEEAAVVector4@@PAVVector3@@H@Z | unused
u32 EyePlaneOutcode(u8* arg1, u8 arg2, class Vector4& arg3, class Vector3* arg4, i32 arg5);

// 0x504690 | ?SetClipMode@@YAXH@Z | unused
void SetClipMode(i32 arg1);

// 0x505E00 | ?begin_invert@@YIXPAVVector4@@@Z | unused
void __fastcall begin_invert(class Vector4* arg1);

// 0x505E10 | ?end_invert@@YIXPAVVector4@@@Z | unused
void __fastcall end_invert(class Vector4* arg1);

// 0x64A770 | ?MaxCardSize@@3MA
inline extern_var(0x64A770, f32, MaxCardSize);

// 0x73D3C4 | ?MinCardSize@@3MA
inline extern_var(0x73D3C4, f32, MinCardSize);

// 0x64A6E8 | ?ShadowColor@@3IA
inline extern_var(0x64A6E8, u32, ShadowColor);

// 0x64A6E4 | ?ShadowFudge@@3MA
inline extern_var(0x64A6E4, f32, ShadowFudge);

// 0x64A6EC | ?SphMapColor@@3IA
inline extern_var(0x64A6EC, u32, SphMapColor);

struct agiMeshCardInfo
{
public:
    // 0x50EC90 | ?Init@agiMeshCardInfo@@QAEXHPAUagiMeshCardVertex@@HHH@Z
    void Init(i32 arg1, struct agiMeshCardVertex* arg2, i32 arg3, i32 arg4, i32 arg5);

    i32 VertCount {0};
    i32 PointCount {0};
    class Vector2* Points {nullptr};
    class Vector2* Points2 {nullptr};
};

check_size(agiMeshCardInfo, 0x10);

class agiPolySet
{
public:
    // 0x510480 | ?Triangle@agiPolySet@@QAEXHHH@Z
    void Triangle(i32 arg1, i32 arg2, i32 arg3);

    u16* Indices {nullptr};
    struct agiScreenVtx* Verts {nullptr};
    struct agiScreenVtx2* Verts2 {nullptr};
    class agiTexDef* Textures[2] {};
    i32 VertCount {0};
    i32 IndexCount {0};
    i32 BaseIndex {0};
    i32 MaxVerts {0};
    i32 MaxIndices {0};
    i32 MultiTex {0};

    // 0x719738 | ?TriCount@agiPolySet@@2HA
    static inline extern_var(0x719738, i32, TriCount);
};

check_size(agiPolySet, 0x2C);
