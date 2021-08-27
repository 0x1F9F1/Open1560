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

struct agiMeshCardInfo;
struct agiMeshCardVertex;
class agiTexDef;
class agiViewParameters;

// agiMeshSet::Flags
#define MESH_SET_UV 0x1      // agiMeshSet::TexCoords
#define MESH_SET_NORMAL 0x2  // agiMeshSet::Normals
#define MESH_SET_CPV 0x4     // agiMeshSet::Colors
#define MESH_SET_OFFSET 0x8  // agiMeshSet::Vertices are offset
#define MESH_SET_PLANES 0x10 // agiMeshSet::Planes

// GetMeshSet
// mesh->Flags = flags & MESH_SET_FLAGS_MASK
#define MESH_SET_FLAGS_MASK (MESH_SET_UV | MESH_SET_NORMAL | MESH_SET_CPV | MESH_SET_OFFSET | MESH_SET_PLANES)

// mmInstance::GetMeshSetSet
#define MESH_SET_NO_BOUND 0x40
#define MESH_SET_BREAKABLE 0x80 // strcat(bnd_name, "_break")

// if (!(flags & 0x100) && (EnablePaging & 2) && FileSystem::PagerInfoAny(bms_path, &pager))
#define MESH_SET_KEEP_LOADED 0x100 // FIXME: Overlaps with MESH_SET_VARIANT_MASK

// if (flags & 0xF00) mesh->Variant = flags >> 8
#define MESH_SET_VARIANT_MASK 0xF00
#define MESH_SET_VARIANT_SHIFT 8

#define MESH_DRAW_CLIP 0x1   // Use agiMeshSet::codes
#define MESH_DRAW_DYNTEX 0x8 // Do not share vertices between textures
#define MESH_DRAW_VARIANT(VARIANT) ((VARIANT) << 4)
#define MESH_DRAW_GET_VARIANT(VARIANT) ((VARIANT) >> 4)

#define MESH_CLIP_NX 0x01     // Clip -X
#define MESH_CLIP_PX 0x02     // Clip +X
#define MESH_CLIP_NY 0x04     // Clip -Y
#define MESH_CLIP_PY 0x08     // Clip +Y
#define MESH_CLIP_NZ 0x10     // Clip -Z
#define MESH_CLIP_PZ 0x20     // Clip +Z
#define MESH_CLIP_ANY 0x3F    // Clip *
#define MESH_CLIP_SCREEN 0x40 // ToScreen

class agiMeshSet;
using agiMeshLighter = void (*)(u8* codes, u32* output, u32* colors, agiMeshSet* mesh);

class agiMeshSet
{
public:
    // ??0agiMeshSet@@QAE@XZ
    ARTS_EXPORT agiMeshSet();

    // ??1agiMeshSet@@QAE@XZ
    ARTS_EXPORT ~agiMeshSet();

    // ?BinaryLoad@agiMeshSet@@QAEXPAVStream@@@Z | agiworld:meshload
    ARTS_EXPORT void BinaryLoad(Stream* stream);

    // ?BinarySave@agiMeshSet@@QAEXPAVStream@@@Z | agiworld:meshsave
    ARTS_EXPORT void BinarySave(Stream* stream);

    // ?ComputePlaneEquations@agiMeshSet@@QAEXXZ
    ARTS_EXPORT void ComputePlaneEquations();

    // ?Draw@agiMeshSet@@QAEHI@Z | agiworld:meshrend
    ARTS_EXPORT b32 Draw(u32 flags);

    // ?DrawColor@agiMeshSet@@QAEHII@Z | agiworld:meshrend
    ARTS_EXPORT b32 DrawColor(u32 color, u32 flags);

    // ?DrawLit@agiMeshSet@@QAEHP6AXPAEPAI1PAV1@@ZI1@Z | agiworld:meshrend
    ARTS_EXPORT b32 DrawLit(agiMeshLighter lighter, u32 flags, u32* colors);

    // ?DrawLitEnv@agiMeshSet@@QAEXP6AXPAEPAI1PAV1@@ZPAVagiTexDef@@AAVMatrix34@@I@Z | agiworld:meshrend
    ARTS_EXPORT void DrawLitEnv(agiMeshLighter lighter, agiTexDef* env_map, Matrix34& transform, u32 flags);

    // ?DrawLitSph@agiMeshSet@@QAEXP6AXPAEPAI1PAV1@@ZPAVagiTexDef@@I@Z | agiworld:meshrend
    ARTS_IMPORT void DrawLitSph(agiMeshLighter lighter, agiTexDef* sph_map, u32 flags);

    // ?DrawNormals@agiMeshSet@@QAEXAAVVector3@@@Z | agiworld:meshrend
    ARTS_IMPORT void DrawNormals(Vector3& arg1);

    // ?DrawShadow@agiMeshSet@@QAEXIABVVector4@@ABVVector3@@@Z | agiworld:meshrend
    ARTS_EXPORT void DrawShadow(u32 flags, const Vector4& plane, const Vector3& light_dir);

    // ?EnvMap@agiMeshSet@@QAEXAAVMatrix34@@PAVagiTexDef@@I@Z | agiworld:meshrend
    ARTS_IMPORT void EnvMap(Matrix34& arg1, agiTexDef* arg2, u32 arg3);

    // ?FirstPass@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_EXPORT void FirstPass(u32* colors, Vector2* tex_coords, u32 color);

    // ?FirstPass_HW_UV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_UV_CPV_DYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_UV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_UV_CPV_noDYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_UV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_UV_noCPV_DYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_UV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_UV_noCPV_noDYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_noUV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_noUV_CPV_DYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_noUV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_noUV_CPV_noDYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_noUV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_noUV_noCPV_DYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_HW_noUV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_HW_noUV_noCPV_noDYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_UV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_UV_CPV_DYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_UV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_UV_CPV_noDYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_UV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_UV_noCPV_DYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_UV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_UV_noCPV_noDYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_noUV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_noUV_CPV_DYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_noUV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_noUV_CPV_noDYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_noUV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_noUV_noCPV_DYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?FirstPass_SW_noUV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | agiworld:meshrend
    ARTS_IMPORT void FirstPass_SW_noUV_noCPV_noDYNTEX(u32* arg1, Vector2* arg2, u32 arg3);

    // ?Geometry@agiMeshSet@@QAEHIPAVVector3@@PAVVector4@@@Z | agiworld:meshrend
    ARTS_EXPORT i32 Geometry(u32 flags, Vector3* verts, Vector4* planes);

    // ?IsFullyResident@agiMeshSet@@QAEHH@Z
    ARTS_EXPORT b32 IsFullyResident(i32 variant);

    // ?LockIfResident@agiMeshSet@@QAEHXZ
    ARTS_EXPORT b32 LockIfResident();

    // ?MakeResident@agiMeshSet@@QAEXXZ
    ARTS_EXPORT void MakeResident();

    // ?MultiTexEnvMap@agiMeshSet@@QAEXPAIIPAVagiTexDef@@AAVMatrix34@@@Z | agiworld:meshrend
    ARTS_IMPORT void MultiTexEnvMap(u32* arg1, u32 arg2, agiTexDef* arg3, Matrix34& arg4);

    // ?Offset@agiMeshSet@@QAEXVVector3@@@Z
    ARTS_EXPORT void Offset(Vector3 offset);

    // ?PageIn@agiMeshSet@@QAEXXZ
    ARTS_EXPORT void PageIn();

    // ?ShadowGeometry@agiMeshSet@@QAEHIPAVVector3@@ABVVector4@@ABV2@@Z | agiworld:meshrend
    ARTS_EXPORT i32 ShadowGeometry(u32 flags, Vector3* verts, const Vector4& surface_dir, const Vector3& light_dir);

    // ?SphereMap@agiMeshSet@@QAEXPAVagiTexDef@@I@Z | agiworld:meshrend
    ARTS_IMPORT void SphereMap(agiTexDef* arg1, u32 arg2);

    // ?Unlock@agiMeshSet@@QAEXXZ
    ARTS_EXPORT void Unlock();

    // ?UnlockAndFree@agiMeshSet@@QAEXXZ
    ARTS_EXPORT void UnlockAndFree();

    // ?DrawCard@agiMeshSet@@SAXAAVVector3@@MIII@Z | agiworld:meshrend
    ARTS_IMPORT static void DrawCard(Vector3& arg1, f32 arg2, u32 arg3, u32 arg4, u32 arg5);

    // ?DrawLines@agiMeshSet@@SAXPAVVector3@@0PAIH@Z | agiworld:meshrend
    ARTS_EXPORT static void DrawLines(Vector3* starts, Vector3* ends, u32* colors, i32 count);

    // ?DrawWideLines@agiMeshSet@@SAXPAVVector3@@0PAMPAIH@Z | agiworld:meshrend
    ARTS_EXPORT static void DrawWideLines(Vector3* starts, Vector3* ends, f32* widths, u32* colors, i32 count);

    // ?Init@agiMeshSet@@SIXH@Z | agiworld:meshrend
    ARTS_IMPORT static void ARTS_FASTCALL Init(i32 arg1);

    // ?InitCards@agiMeshSet@@SAXAAUagiMeshCardInfo@@@Z | agiworld:meshrend
    ARTS_IMPORT static void InitCards(agiMeshCardInfo& arg1);

    // ?InitLocalize@agiMeshSet@@SAXXZ | agiworld:meshrend
    ARTS_IMPORT static void InitLocalize();

    // ?Localize@agiMeshSet@@SAXAAVVector3@@0@Z | agiworld:meshrend | unused
    ARTS_IMPORT static void Localize(Vector3& arg1, Vector3& arg2);

    // ?LocalizeDirection@agiMeshSet@@SAXAAVVector3@@0@Z | agiworld:meshrend
    ARTS_IMPORT static void LocalizeDirection(Vector3& arg1, Vector3& arg2);

    // ?SetFog@agiMeshSet@@SAXMH@Z | agiworld:meshrend
    ARTS_EXPORT static void SetFog(f32 fog, i32 arg2);

    // ?DefaultQuad@agiMeshSet@@2PAUagiMeshCardVertex@@A | agiworld:meshrend
    ARTS_IMPORT static agiMeshCardVertex DefaultQuad[4];

    // ?DepthOffset@agiMeshSet@@2MA | agiworld:meshrend
    ARTS_EXPORT static f32 DepthOffset;

    // ?DepthScale@agiMeshSet@@2MA | agiworld:meshrend
    ARTS_EXPORT static f32 DepthScale;

    // ?EyePlaneCount@agiMeshSet@@2HA | agiworld:meshrend
    ARTS_EXPORT static i32 EyePlaneCount;

    // ?EyePlanes@agiMeshSet@@2PAVVector4@@A | agiworld:meshrend
    ARTS_IMPORT static Vector4 EyePlanes[2];

    // ?EyePlanesHit@agiMeshSet@@2HA | agiworld:meshrend
    ARTS_EXPORT static i32 EyePlanesHit;

    // ?EyePos@agiMeshSet@@2VVector3@@A | agiworld:meshrend
    ARTS_EXPORT static Vector3 EyePos;

    // ?FlipX@agiMeshSet@@2HA | agiworld:meshrend
    ARTS_EXPORT static b32 FlipX;

    // ?FogValue@agiMeshSet@@2MA | agiworld:meshrend
    ARTS_EXPORT static f32 FogValue;

    // ?HitEyePlanes@agiMeshSet@@2PAVVector4@@A | agiworld:meshrend
    ARTS_IMPORT static Vector4 HitEyePlanes[2];

    // ?MirrorMode@agiMeshSet@@2HA | agiworld:meshrend
    ARTS_EXPORT static b32 MirrorMode;

    // MESH_CLIP_*
    // ?codes@agiMeshSet@@2PAEA | agiworld:meshrend
    ARTS_EXPORT static u8 codes[16384];

protected:
    // ?ClipTri@agiMeshSet@@IAEXHHHH@Z | agiworld:meshrend
    ARTS_EXPORT void ClipTri(i32 i1, i32 i2, i32 i3, i32 texture);

    template <typename T>
    static void ARTS_FASTCALL ClampToScreen(T& vert);

    // ?InitMtx@agiMeshSet@@KIXAAVagiViewParameters@@H@Z | agiworld:meshrend
    ARTS_IMPORT static void ARTS_FASTCALL InitMtx(agiViewParameters& arg1, i32 arg2);

    // ?InitViewport@agiMeshSet@@KIXAAVagiViewParameters@@@Z | agiworld:meshrend
    ARTS_EXPORT static void ARTS_FASTCALL InitViewport(agiViewParameters& params);

    // ?ShadowInit@agiMeshSet@@KIXABVVector4@@ABVVector3@@@Z | agiworld:meshrend
    ARTS_IMPORT static void ARTS_FASTCALL ShadowInit(const Vector4& arg1, const Vector3& arg2);

    // ?ShadowTransform@agiMeshSet@@KIXPAVVector4@@PAVVector3@@H@Z | agiworld:meshrend
    ARTS_EXPORT static void ARTS_FASTCALL ShadowTransform(
        Vector4* ARTS_RESTRICT output, Vector3* ARTS_RESTRICT input, i32 count);

    // ?ShadowTransformOutcode@agiMeshSet@@KIIPAEPAVVector4@@PAVVector3@@H@Z | agiworld:meshrend
    ARTS_EXPORT static u32 ARTS_FASTCALL ShadowTransformOutcode(
        u8* ARTS_RESTRICT out_codes, Vector4* ARTS_RESTRICT output, Vector3* ARTS_RESTRICT input, i32 count);

    // ?ToScreen@agiMeshSet@@KIXPAEPAVVector4@@H@Z | agiworld:mrkni
    ARTS_EXPORT static void ARTS_FASTCALL ToScreen(u8* ARTS_RESTRICT in_codes, Vector4* ARTS_RESTRICT verts, i32 count);

    // ?Transform@agiMeshSet@@KIXPAVVector4@@PAVVector3@@H@Z | agiworld:meshrend
    ARTS_EXPORT static void ARTS_FASTCALL Transform(
        Vector4* ARTS_RESTRICT output, Vector3* ARTS_RESTRICT input, i32 count);

    // ?TransformOutcode@agiMeshSet@@KIIPAEPAVVector4@@PAVVector3@@H@Z | agiworld:meshrend
    ARTS_EXPORT static u32 ARTS_FASTCALL TransformOutcode(
        u8* ARTS_RESTRICT out_codes, Vector4* ARTS_RESTRICT output, Vector3* ARTS_RESTRICT input, i32 count);

    // ?AllowEyeBackfacing@agiMeshSet@@1HA | agiworld:meshrend
    ARTS_EXPORT static b32 AllowEyeBackfacing;

    // ?HalfHeight@agiMeshSet@@1MA | agiworld:meshrend
    ARTS_EXPORT static f32 HalfHeight;

    // ?HalfWidth@agiMeshSet@@1MA | agiworld:meshrend
    ARTS_EXPORT static f32 HalfWidth;

    // ?LocPos@agiMeshSet@@1VVector3@@A | agiworld:meshrend
    ARTS_EXPORT static Vector3 LocPos;

    // ?M@agiMeshSet@@1VMatrix34@@A | agiworld:meshrend
    ARTS_EXPORT static Matrix34 M;

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
    ARTS_EXPORT static Vector4 out[16384];

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
    Vector3* Vertices {};
    u8* Normals {};

    // Vector3[8]
    // min.x, min.y, min.z
    // max.x, min.y, min.z
    // max.x, min.y, max.z
    // min.x, min.y, max.z
    // min.x, max.y, min.z
    // max.x, max.y, min.z
    // max.x, max.y, max.z
    // min.x, max.y, max.z
    Vector3* BoundingBox {};

    Vector2* TexCoords {};
    u32* Colors {};
    Vector4* Planes {};

    // CacheHandle must be stored directly after Pager
    PagerInfo_t Pager {};
    i32 CacheHandle {};

    u16* VertexIndices {};
    u16* SurfaceIndices {};
    u8* TextureIndices {};
    f32 Radius {};
    f32 RadiusSqr {};
    f32 BoundingBoxRadius {};
    u32 VertexCount {};
    u32 AdjunctCount {};
    u32 SurfaceCount {};
    u32 IndicesCount {};
    u8 TextureCount {};
    u8 VariationCount {};

    // MESH_SET_*
    u8 Flags {};

    // 0 | Unloaded
    // 1 | Requested
    // 2 | Loaded
    std::atomic<u8> Resident {};

    u32 Variant {};
    agiTexDef*** Textures {};

private:
    u32 ref_count_ {1};
};

check_size(agiMeshSet, 0x64);
