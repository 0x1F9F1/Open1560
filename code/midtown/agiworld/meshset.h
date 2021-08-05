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
    agiworld:meshset

    0x5147D0 | public: __thiscall agiMeshSet::agiMeshSet(void) | ??0agiMeshSet@@QAE@XZ
    0x5147F0 | public: __thiscall agiMeshSet::~agiMeshSet(void) | ??1agiMeshSet@@QAE@XZ
    0x514880 | public: void __thiscall agiMeshSet::Offset(class Vector3) | ?Offset@agiMeshSet@@QAEXVVector3@@@Z
    0x5148D0 | public: void __thiscall agiMeshSet::ComputePlaneEquations(void) | ?ComputePlaneEquations@agiMeshSet@@QAEXXZ
    0x514AF0 | private: static void __cdecl agiMeshSet::PageInCallback(void *) | ?PageInCallback@agiMeshSet@@CAXPAX@Z
    0x514B00 | public: void __thiscall agiMeshSet::PageIn(void) | ?PageIn@agiMeshSet@@QAEXXZ
    0x514B20 | public: int __thiscall agiMeshSet::LockIfResident(void) | ?LockIfResident@agiMeshSet@@QAEHXZ
    0x514B50 | public: void __thiscall agiMeshSet::Unlock(void) | ?Unlock@agiMeshSet@@QAEXXZ
    0x514B70 | public: void __thiscall agiMeshSet::UnlockAndFree(void) | ?UnlockAndFree@agiMeshSet@@QAEXXZ
    0x514B90 | public: void __thiscall agiMeshSet::MakeResident(void) | ?MakeResident@agiMeshSet@@QAEXXZ
    0x514BC0 | public: int __thiscall agiMeshSet::IsFullyResident(int) | ?IsFullyResident@agiMeshSet@@QAEHH@Z
*/

#include "data7/pager.h"
#include "vector7/vector2.h"
#include "vector7/vector3.h"
#include "vector7/vector4.h"

#include <atomic>

// agiMeshSet::Flags
#define AGI_MESH_SET_UV 0x1      // agiMeshSet::TexCoords
#define AGI_MESH_SET_LIT 0x2     // agiMeshSet::Normals
#define AGI_MESH_SET_CPV 0x4     // agiMeshSet::Colors
#define AGI_MESH_SET_OFFSET 0x8  // agiMeshSet::Vertices are offset
#define AGI_MESH_SET_PLANES 0x10 // agiMeshSet::Planes

// GetMeshSet
// mesh->Flags = flags & AGI_MESH_SET_FLAGS_MASK
#define AGI_MESH_SET_FLAGS_MASK \
    (AGI_MESH_SET_UV | AGI_MESH_SET_LIT | AGI_MESH_SET_CPV | AGI_MESH_SET_OFFSET | AGI_MESH_SET_PLANES)

// if (!(flags & 0x100) && (EnablePaging & 2) && FileSystem::PagerInfoAny(bms_path, &pager))
#define AGI_MESH_SET_KEEP_LOADED 0x100 // Overlaps with AGI_MESH_SET_VARIANT_MASK, why?

// if (flags & 0xF00) mesh->Variant = flags >> 8
#define AGI_MESH_SET_VARIANT_MASK 0xF00
#define AGI_MESH_SET_VARIANT_SHIFT 8

// mmInstance::GetMeshSetSet
#define AGI_MESH_SET_SET_NO_BOUND 0x40
#define AGI_MESH_SET_SET_BREAKABLE 0x80 // strcat(bnd_name, "_break")

using agiMeshLighter = void (*)(u8* codes, u32* output, u32* colors, class agiMeshSet* mesh);

#define AGI_MESH_DRAW_CLIP 0x1        // Use agiMeshSet::codes
#define AGI_MESH_DRAW_DYNTEX 0x8      // Do not share vertices between textures
#define AGI_MESH_DRAW_VARIANT_SHIFT 4 // CurrentMeshSetVariant = flags >> 4

#define AGI_MESH_CLIP_NX 0x01     // Clip -X
#define AGI_MESH_CLIP_PX 0x02     // Clip +X
#define AGI_MESH_CLIP_NY 0x04     // Clip -Y
#define AGI_MESH_CLIP_PY 0x08     // Clip +Y
#define AGI_MESH_CLIP_NZ 0x10     // Clip -Z
#define AGI_MESH_CLIP_PZ 0x20     // Clip +Z
#define AGI_MESH_CLIP_ANY 0x3F    // Clip *
#define AGI_MESH_CLIP_SCREEN 0x40 // ToScreen

class agiMeshSet
{
public:
    // ??0agiMeshSet@@QAE@XZ
    ARTS_EXPORT agiMeshSet();

    // ??1agiMeshSet@@QAE@XZ
    ARTS_EXPORT ~agiMeshSet();

    // ?BinaryLoad@agiMeshSet@@QAEXPAVStream@@@Z | agiworld:meshload
    ARTS_EXPORT void BinaryLoad(class Stream* stream);

    // ?BinarySave@agiMeshSet@@QAEXPAVStream@@@Z | agiworld:meshsave
    ARTS_EXPORT void BinarySave(class Stream* stream);

    // ?ComputePlaneEquations@agiMeshSet@@QAEXXZ
    ARTS_EXPORT void ComputePlaneEquations();

    // ?Draw@agiMeshSet@@QAEHI@Z | agiworld:meshrend
    ARTS_EXPORT b32 Draw(u32 flags);

    // ?DrawColor@agiMeshSet@@QAEHII@Z | agiworld:meshrend
    ARTS_EXPORT b32 DrawColor(u32 color, u32 flags);

    // ?DrawLit@agiMeshSet@@QAEHP6AXPAEPAI1PAV1@@ZI1@Z | agiworld:meshrend
    ARTS_EXPORT b32 DrawLit(agiMeshLighter lighter, u32 flags, u32* colors);

    // ?DrawLitEnv@agiMeshSet@@QAEXP6AXPAEPAI1PAV1@@ZPAVagiTexDef@@AAVMatrix34@@I@Z | agiworld:meshrend
    ARTS_EXPORT void DrawLitEnv(agiMeshLighter lighter, class agiTexDef* env_map, class Matrix34& transform, u32 flags);

    // ?DrawLitSph@agiMeshSet@@QAEXP6AXPAEPAI1PAV1@@ZPAVagiTexDef@@I@Z | agiworld:meshrend
    ARTS_IMPORT void DrawLitSph(agiMeshLighter lighter, class agiTexDef* sph_map, u32 flags);

    // ?DrawNormals@agiMeshSet@@QAEXAAVVector3@@@Z | agiworld:meshrend
    ARTS_IMPORT void DrawNormals(class Vector3& arg1);

    // ?DrawShadow@agiMeshSet@@QAEXIABVVector4@@ABVVector3@@@Z | agiworld:meshrend
    ARTS_EXPORT void DrawShadow(u32 flags, class Vector4 const& plane, class Vector3 const& light_dir);

    // ?EnvMap@agiMeshSet@@QAEXAAVMatrix34@@PAVagiTexDef@@I@Z | agiworld:meshrend
    ARTS_IMPORT void EnvMap(class Matrix34& arg1, class agiTexDef* arg2, u32 arg3);

    // ?FirstPass@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_EXPORT void FirstPass(u32* colors, class Vector2* tex_coords, u32 color);

    // ?FirstPass_HW_UV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_UV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_UV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_UV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_UV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_UV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_UV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_UV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_noUV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_noUV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_noUV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_noUV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_noUV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_noUV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_noUV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_noUV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_UV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_UV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_UV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_UV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_UV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_UV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_UV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_UV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_noUV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_noUV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_noUV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_noUV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_noUV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_noUV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_noUV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_noUV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // ?Geometry@agiMeshSet@@QAEHIPAVVector3@@PAVVector4@@@Z | agiworld:meshrend
    ARTS_EXPORT i32 Geometry(u32 flags, class Vector3* verts, class Vector4* planes);

    // ?IsFullyResident@agiMeshSet@@QAEHH@Z
    ARTS_EXPORT b32 IsFullyResident(i32 variant);

    // ?LockIfResident@agiMeshSet@@QAEHXZ
    ARTS_EXPORT b32 LockIfResident();

    // ?MakeResident@agiMeshSet@@QAEXXZ
    ARTS_EXPORT void MakeResident();

    // ?MultiTexEnvMap@agiMeshSet@@QAEXPAIIPAVagiTexDef@@AAVMatrix34@@@Z | agiworld:meshrend
    ARTS_IMPORT void MultiTexEnvMap(u32* arg1, u32 arg2, class agiTexDef* arg3, class Matrix34& arg4);

    // ?Offset@agiMeshSet@@QAEXVVector3@@@Z
    ARTS_EXPORT void Offset(class Vector3 offset);

    // ?PageIn@agiMeshSet@@QAEXXZ
    ARTS_EXPORT void PageIn();

    // ?ShadowGeometry@agiMeshSet@@QAEHIPAVVector3@@ABVVector4@@ABV2@@Z | agiworld:meshrend
    ARTS_EXPORT i32 ShadowGeometry(
        u32 flags, class Vector3* verts, class Vector4 const& surface_dir, class Vector3 const& light_dir);

    // ?SphereMap@agiMeshSet@@QAEXPAVagiTexDef@@I@Z | agiworld:meshrend
    ARTS_IMPORT void SphereMap(class agiTexDef* arg1, u32 arg2);

    // ?Unlock@agiMeshSet@@QAEXXZ
    ARTS_EXPORT void Unlock();

    // ?UnlockAndFree@agiMeshSet@@QAEXXZ
    ARTS_EXPORT void UnlockAndFree();

    // ?DrawCard@agiMeshSet@@SAXAAVVector3@@MIII@Z | agiworld:meshrend
    ARTS_IMPORT static void DrawCard(class Vector3& arg1, f32 arg2, u32 arg3, u32 arg4, u32 arg5);

    // ?DrawLines@agiMeshSet@@SAXPAVVector3@@0PAIH@Z | agiworld:meshrend
    ARTS_EXPORT static void DrawLines(class Vector3* starts, class Vector3* ends, u32* colors, i32 count);

    // ?DrawWideLines@agiMeshSet@@SAXPAVVector3@@0PAMPAIH@Z | agiworld:meshrend
    ARTS_EXPORT static void DrawWideLines(
        class Vector3* starts, class Vector3* ends, f32* widths, u32* colors, i32 count);

    // ?Init@agiMeshSet@@SIXH@Z | agiworld:meshrend
    ARTS_IMPORT static void ARTS_FASTCALL Init(i32 arg1);

    // ?InitCards@agiMeshSet@@SAXAAUagiMeshCardInfo@@@Z | agiworld:meshrend
    ARTS_IMPORT static void InitCards(struct agiMeshCardInfo& arg1);

    // ?InitLocalize@agiMeshSet@@SAXXZ | agiworld:meshrend
    ARTS_IMPORT static void InitLocalize();

    // ?Localize@agiMeshSet@@SAXAAVVector3@@0@Z | agiworld:meshrend | unused
    ARTS_IMPORT static void Localize(class Vector3& arg1, class Vector3& arg2);

    // ?LocalizeDirection@agiMeshSet@@SAXAAVVector3@@0@Z | agiworld:meshrend
    ARTS_IMPORT static void LocalizeDirection(class Vector3& arg1, class Vector3& arg2);

    // ?SetFog@agiMeshSet@@SAXMH@Z | agiworld:meshrend
    ARTS_EXPORT static void SetFog(f32 fog, i32 arg2);

    // ?DefaultQuad@agiMeshSet@@2PAUagiMeshCardVertex@@A | agiworld:meshrend
    ARTS_IMPORT static struct agiMeshCardVertex DefaultQuad[4];

    // ?DepthOffset@agiMeshSet@@2MA | agiworld:meshrend
    ARTS_EXPORT static f32 DepthOffset;

    // ?DepthScale@agiMeshSet@@2MA | agiworld:meshrend
    ARTS_EXPORT static f32 DepthScale;

    // ?EyePlaneCount@agiMeshSet@@2HA | agiworld:meshrend
    ARTS_EXPORT static i32 EyePlaneCount;

    // ?EyePlanes@agiMeshSet@@2PAVVector4@@A | agiworld:meshrend
    ARTS_IMPORT static class Vector4 EyePlanes[2];

    // ?EyePlanesHit@agiMeshSet@@2HA | agiworld:meshrend
    ARTS_EXPORT static i32 EyePlanesHit;

    // ?EyePos@agiMeshSet@@2VVector3@@A | agiworld:meshrend
    ARTS_EXPORT static class Vector3 EyePos;

    // ?FlipX@agiMeshSet@@2HA | agiworld:meshrend
    ARTS_EXPORT static b32 FlipX;

    // ?FogValue@agiMeshSet@@2MA | agiworld:meshrend
    ARTS_EXPORT static f32 FogValue;

    // ?HitEyePlanes@agiMeshSet@@2PAVVector4@@A | agiworld:meshrend
    ARTS_IMPORT static class Vector4 HitEyePlanes[2];

    // ?MirrorMode@agiMeshSet@@2HA | agiworld:meshrend
    ARTS_EXPORT static b32 MirrorMode;

    // AGI_MESH_CLIP_*
    // ?codes@agiMeshSet@@2PAEA | agiworld:meshrend
    ARTS_EXPORT static u8 codes[16384];

protected:
    // ?ClipTri@agiMeshSet@@IAEXHHHH@Z | agiworld:meshrend
    ARTS_EXPORT void ClipTri(i32 i1, i32 i2, i32 i3, i32 texture);

    template <typename T>
    static void ARTS_FASTCALL ClampToScreen(T& vert);

    // ?InitMtx@agiMeshSet@@KIXAAVagiViewParameters@@H@Z | agiworld:meshrend
    ARTS_IMPORT static void ARTS_FASTCALL InitMtx(class agiViewParameters& arg1, i32 arg2);

    // ?InitViewport@agiMeshSet@@KIXAAVagiViewParameters@@@Z | agiworld:meshrend
    ARTS_EXPORT static void ARTS_FASTCALL InitViewport(class agiViewParameters& params);

    // ?ShadowInit@agiMeshSet@@KIXABVVector4@@ABVVector3@@@Z | agiworld:meshrend
    ARTS_IMPORT static void ARTS_FASTCALL ShadowInit(class Vector4 const& arg1, class Vector3 const& arg2);

    // ?ShadowTransform@agiMeshSet@@KIXPAVVector4@@PAVVector3@@H@Z | agiworld:meshrend
    ARTS_EXPORT static void ARTS_FASTCALL ShadowTransform(
        class Vector4* ARTS_RESTRICT output, class Vector3* ARTS_RESTRICT input, i32 count);

    // ?ShadowTransformOutcode@agiMeshSet@@KIIPAEPAVVector4@@PAVVector3@@H@Z | agiworld:meshrend
    ARTS_EXPORT static u32 ARTS_FASTCALL ShadowTransformOutcode(u8* ARTS_RESTRICT out_codes,
        class Vector4* ARTS_RESTRICT output, class Vector3* ARTS_RESTRICT input, i32 count);

    // ?ToScreen@agiMeshSet@@KIXPAEPAVVector4@@H@Z | agiworld:mrkni
    ARTS_EXPORT static void ARTS_FASTCALL ToScreen(
        u8* ARTS_RESTRICT in_codes, class Vector4* ARTS_RESTRICT verts, i32 count);

    // ?Transform@agiMeshSet@@KIXPAVVector4@@PAVVector3@@H@Z | agiworld:meshrend
    ARTS_EXPORT static void ARTS_FASTCALL Transform(
        class Vector4* ARTS_RESTRICT output, class Vector3* ARTS_RESTRICT input, i32 count);

    // ?TransformOutcode@agiMeshSet@@KIIPAEPAVVector4@@PAVVector3@@H@Z | agiworld:meshrend
    ARTS_EXPORT static u32 ARTS_FASTCALL TransformOutcode(u8* ARTS_RESTRICT out_codes,
        class Vector4* ARTS_RESTRICT output, class Vector3* ARTS_RESTRICT input, i32 count);

    // ?AllowEyeBackfacing@agiMeshSet@@1HA | agiworld:meshrend
    ARTS_EXPORT static b32 AllowEyeBackfacing;

    // ?HalfHeight@agiMeshSet@@1MA | agiworld:meshrend
    ARTS_EXPORT static f32 HalfHeight;

    // ?HalfWidth@agiMeshSet@@1MA | agiworld:meshrend
    ARTS_EXPORT static f32 HalfWidth;

    // ?LocPos@agiMeshSet@@1VVector3@@A | agiworld:meshrend
    ARTS_EXPORT static class Vector3 LocPos;

    // ?M@agiMeshSet@@1VMatrix34@@A | agiworld:meshrend
    ARTS_EXPORT static class Matrix34 M;

    // ?MaxX@agiMeshSet@@1MA | agiworld:meshrend
    ARTS_EXPORT static f32 MaxX;

    // ?MaxY@agiMeshSet@@1MA | agiworld:meshrend
    ARTS_EXPORT static f32 MaxY;

    // ?MinX@agiMeshSet@@1MA | agiworld:meshrend
    ARTS_EXPORT static f32 MinX;

    // ?MinY@agiMeshSet@@1MA | agiworld:meshrend
    ARTS_EXPORT static f32 MinY;

    // ?MtxSerial@agiMeshSet@@1IA | agiworld:meshrend
    ARTS_EXPORT static u32 MtxSerial;

    // ?OffsX@agiMeshSet@@1MA | agiworld:meshrend
    ARTS_EXPORT static f32 OffsX;

    // ?OffsY@agiMeshSet@@1MA | agiworld:meshrend
    ARTS_EXPORT static f32 OffsY;

    // ?ProjZW@agiMeshSet@@1MA | agiworld:meshrend
    ARTS_EXPORT static f32 ProjZW;

    // ?ProjZZ@agiMeshSet@@1MA | agiworld:meshrend
    ARTS_EXPORT static f32 ProjZZ;

    // ?ViewSerial@agiMeshSet@@1IA | agiworld:meshrend
    ARTS_EXPORT static u32 ViewSerial;

    // ?firstFacet@agiMeshSet@@1PAFA | agiworld:meshrend
    ARTS_EXPORT static i16 firstFacet[256];

    // ?fogout@agiMeshSet@@1PAEA | agiworld:meshrend
    ARTS_EXPORT static u8 fogout[16384];

    // ?indexCounts@agiMeshSet@@1PAFA | agiworld:meshrend
    ARTS_EXPORT static i16 indexCounts[256];

    // ?nextFacet@agiMeshSet@@1PAFA | agiworld:meshrend
    ARTS_EXPORT static i16 nextFacet[16384];

    // Must be 16-byte aligned
    // ?out@agiMeshSet@@1PAVVector4@@A | agiworld:mrkni
    ARTS_EXPORT static class Vector4 out[16384];

    // ?vertCounts@agiMeshSet@@1PAFA | agiworld:meshrend
    ARTS_EXPORT static i16 vertCounts[256];

private:
    // ?BeginGfx@agiMeshSet@@AAEXXZ | agiworld:meshrend | unused
    ARTS_IMPORT void BeginGfx();

    // ?DoPageIn@agiMeshSet@@AAEXXZ | agiworld:meshload
    ARTS_EXPORT void DoPageIn();

    // ?EndGfx@agiMeshSet@@AAEXXZ | agiworld:meshrend
    ARTS_IMPORT void EndGfx();

    // ?PageInCallback@agiMeshSet@@CAXPAX@Z
    ARTS_EXPORT static void PageInCallback(void* param);

    // ?PageOutCallback@agiMeshSet@@CAXPAXH@Z | agiworld:meshload
    ARTS_EXPORT static void PageOutCallback(void* param, isize delta);

    static inline bool IsBackfacing(const Vector4& plane)
    {
        return AllowEyeBackfacing &&
            MirrorMode != (plane.x * EyePos.x + plane.y * EyePos.y + plane.z * EyePos.z + plane.w < 0.0f);
    }

public:
    Vector3* Vertices {nullptr};
    u8* Normals {nullptr};

    // Vector3[8]
    // min.x, min.y, min.z
    // max.x, min.y, min.z
    // max.x, min.y, max.z
    // min.x, min.y, max.z
    // min.x, max.y, min.z
    // max.x, max.y, min.z
    // max.x, max.y, max.z
    // min.x, max.y, max.z
    Vector3* BoundingBox {nullptr};

    Vector2* TexCoords {nullptr};
    u32* Colors {nullptr};
    Vector4* Planes {nullptr};

    // CacheHandle must be stored directly after Pager
    PagerInfo_t Pager {};
    i32 CacheHandle {0};

    u16* VertexIndices {nullptr};
    u16* SurfaceIndices {nullptr};
    u8* TextureIndices {nullptr};
    f32 Magnitude {0.0f};
    f32 MagnitudeSqr {0.0f};
    f32 BoundingBoxMagnitude {0.0f};
    u32 VertexCount {0};
    u32 AdjunctCount {0};
    u32 SurfaceCount {0};
    u32 IndicesCount {0};
    u8 TextureCount {0};
    u8 VariationCount {0};

    // AGI_MESH_SET_*
    u8 Flags {0};

    // 0 | Unloaded
    // 1 | Requested
    // 2 | Loaded
    std::atomic<u8> Resident {0};

    u32 Variant {0};
    agiTexDef*** Textures {nullptr};

private:
    u32 ref_count_ {1};
};

check_size(agiMeshSet, 0x64);
