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

#include "agi/pipeline.h"
#include "agi/rsys.h"
#include "agi/viewport.h"
#include "agiworld/quality.h"
#include "data7/b2f.h"
#include "data7/utimer.h"
#include "memory/alloca.h"
#include "pcwindis/setupdata.h"
#include "vector7/matrix34.h"
#include "vector7/matrix44.h"

// #ifdef ARTS_ENABLE_KNI
// #    define CLIP_ALL_TO_SCREEN
// #endif

f32 agiMeshSet::DepthOffset = 0.5f;
f32 agiMeshSet::DepthScale = 0.5f;

i32 agiMeshSet::EyePlaneCount = 0;
i32 agiMeshSet::EyePlanesHit = 0;
Vector3 agiMeshSet::EyePos {};

b32 agiMeshSet::FlipX = false;
f32 agiMeshSet::FogValue = 0.0f;
b32 agiMeshSet::MirrorMode = false;
b32 agiMeshSet::AllowEyeBackfacing = false;

Vector3 agiMeshSet::LocPos {};
Matrix34 agiMeshSet::M {};

f32 agiMeshSet::HalfHeight = 0.0f;
f32 agiMeshSet::HalfWidth = 0.0f;
f32 agiMeshSet::MaxX = 0.0f;
f32 agiMeshSet::MaxY = 0.0f;
f32 agiMeshSet::MinX = 0.0f;
f32 agiMeshSet::MinY = 0.0f;
f32 agiMeshSet::OffsX = 0.0f;
f32 agiMeshSet::OffsY = 0.0f;
f32 agiMeshSet::ProjZW = 0.0f;
f32 agiMeshSet::ProjZZ = 0.0f;

u32 agiMeshSet::MtxSerial = 0;
u32 agiMeshSet::ViewSerial = 0;

alignas(64) u8 agiMeshSet::codes[16384];
alignas(64) i16 agiMeshSet::firstFacet[256];
alignas(64) u8 agiMeshSet::fogout[16384];
alignas(64) i16 agiMeshSet::indexCounts[256];
alignas(64) i16 agiMeshSet::nextFacet[16384];
alignas(64) Vector4 agiMeshSet::out[16384];
alignas(64) i16 agiMeshSet::vertCounts[256];

struct CV
{
    Vector4 Pos;
    Vector3 UV;
    u8 Fog;
    u8 Indices[3];
};

check_size(CV, 0x20);

struct CT
{
    u32 Index;
    u32 Count;
    u32 Tri[3];
    CT* Next;
};

check_size(CT, 0x18);

static u32 ClippedVertCount = 0;
static u32 ClippedTriCount = 0;
static extern_var(0x72D390, CV[2048], ClippedVerts);
static extern_var(0x71DE98, CT[512], ClippedTris);
static extern_var(0x719848, CT* [256], ClippedTextures);
static bool OnlyZClip = false;
static extern_var(0x7210E8, Matrix44, ShadowMatrix);

u32 ClipMask = AGI_MESH_CLIP_ANY;

void SetClipMode(b32 mask_only_z)
{
    ClipMask = mask_only_z ? (AGI_MESH_CLIP_NZ | AGI_MESH_CLIP_PZ) : AGI_MESH_CLIP_ANY;
    OnlyZClip = true;
}

// 0x506380 | ?ClipNX@@YIXAAUCV@@0@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL ClipNX(struct CV& arg1, struct CV& arg2);

// 0x506260 | ?ClipNX@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ClipNX(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x5067A0 | ?ClipNY@@YIXAAUCV@@0@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL ClipNY(struct CV& arg1, struct CV& arg2);

// 0x506680 | ?ClipNY@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ClipNY(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x506BB0 | ?ClipNZ@@YIXAAUCV@@0@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL ClipNZ(struct CV& arg1, struct CV& arg2);

// 0x506A90 | ?ClipNZ@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ClipNZ(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x506590 | ?ClipPX@@YIXAAUCV@@0@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL ClipPX(struct CV& arg1, struct CV& arg2);

// 0x506470 | ?ClipPX@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ClipPX(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x5069B0 | ?ClipPY@@YIXAAUCV@@0@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL ClipPY(struct CV& arg1, struct CV& arg2);

// 0x506890 | ?ClipPY@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ClipPY(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x506DC0 | ?ClipPZ@@YIXAAUCV@@0@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL ClipPZ(struct CV& arg1, struct CV& arg2);

// 0x506CA0 | ?ClipPZ@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ClipPZ(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x5061B0 | ?FullClip@@YAHPAUCV@@0H@Z
ARTS_EXPORT /*static*/ i32 FullClip(struct CV* ARTS_RESTRICT output, struct CV* ARTS_RESTRICT input, i32 count)
{
    if (count = ClipNZ(output, input, count); count == 0)
        return 0;

    if (count = ClipNX(input, output, count); count == 0)
        return 0;

    if (count = ClipPX(output, input, count); count == 0)
        return 0;

    if (count = ClipNY(input, output, count); count == 0)
        return 0;

    if (count = ClipPY(output, input, count); count == 0)
        return 0;

    if (count = ClipPZ(input, output, count); count == 0)
        return 0;

    for (i32 i = 0; i < count; ++i)
        output[i] = input[i];

    return count;
}

// 0x506EA0 | ?ZClipOnly@@YAHPAUCV@@0H@Z
ARTS_EXPORT /*static*/ i32 ZClipOnly(struct CV* ARTS_RESTRICT output, struct CV* ARTS_RESTRICT input, i32 count)
{
    if (count = ClipNZ(output, input, count); count == 0)
        return 0;

    if (count = ClipPZ(input, output, count); count == 0)
        return 0;

    // NOTE: Original code did not copy the verts
    // Without the copy, there are artifacts, since the last clip wrote to the input
    for (i32 i = 0; i < count; ++i)
        output[i] = input[i];

    return count;
}

static inline u8 CalculateFog(f32 w, f32 fog)
{
    return ~FloatToByte(std::min<f32>(w * fog, 255.0f));
}

#define ARTS_TRANSFORM_FOG fogout[i] = CalculateFog(output[i].w, FogValue)

#define ARTS_TRANSFORM_CODE                                                            \
    f32 w_abs = std::abs(output[i].w);                                                 \
    u8 clip_code = ClipMask &                                                          \
        ((((w_abs - std::abs(output[i].x)) < 0.0f) << ((output[i].x < 0.0f) + 0)) |    \
            (((w_abs - std::abs(output[i].y)) < 0.0f) << ((output[i].y < 0.0f) + 2)) | \
            (((w_abs - std::abs(output[i].z)) < 0.0f) << ((output[i].z < 0.0f) + 4))); \
    clip_any |= clip_code;                                                             \
    clip_all &= clip_code;                                                             \
    out_codes[i] = clip_code & ClipMask;

#ifndef ARTS_ENABLE_KNI
void agiMeshSet::ToScreen(u8* ARTS_RESTRICT in_codes, Vector4* ARTS_RESTRICT verts, i32 count)
{
    ARTS_UTIMED(agiInvertTimer);

    for (i32 i = 0; i < count; ++i)
    {
        if (in_codes[i] != AGI_MESH_CLIP_SCREEN)
            continue;

        Vector4& vert = verts[i];

        f32 const inv_w = 1.0f / vert.w;

        vert.x = (vert.x * inv_w * HalfWidth) + OffsX;
        vert.y = (vert.y * inv_w * HalfHeight) + OffsY;
        vert.z = (vert.z * inv_w * DepthScale) + DepthOffset;
        vert.w = inv_w;

        ClampToScreen(vert);
    }
}

#    define ARTS_TRANSFORM_DOT                                                                  \
        output[i].x = M.m0.x * input[i].x + M.m1.x * input[i].y + M.m2.x * input[i].z + M.m3.x; \
        output[i].y = M.m0.y * input[i].x + M.m1.y * input[i].y + M.m2.y * input[i].z + M.m3.y; \
        output[i].w = M.m0.z * input[i].x + M.m1.z * input[i].y + M.m2.z * input[i].z + M.m3.z; \
        output[i].z = output[i].w * ProjZZ + ProjZW

void agiMeshSet::Transform(class Vector4* ARTS_RESTRICT output, class Vector3* ARTS_RESTRICT input, i32 count)
{
    STATS.VertsXfrm += count;

    if (FogValue == 0.0f)
    {
        for (i32 i = 0; i < count; ++i)
        {
            ARTS_TRANSFORM_DOT;
        }
    }
    else
    {
        for (i32 i = 0; i < count; ++i)
        {
            ARTS_TRANSFORM_DOT;
            ARTS_TRANSFORM_FOG;
        }
    }
}

u32 agiMeshSet::TransformOutcode(
    u8* ARTS_RESTRICT out_codes, class Vector4* ARTS_RESTRICT output, class Vector3* ARTS_RESTRICT input, i32 count)
{
    STATS.VertsOut += count;
    STATS.VertsXfrm += count;

    u8 clip_any = 0;
    u8 clip_all = 0xFF;

    if (FogValue == 0.0f)
    {
        for (i32 i = 0; i < count; ++i)
        {
            ARTS_TRANSFORM_DOT;
            ARTS_TRANSFORM_CODE;
        }
    }
    else
    {
        for (i32 i = 0; i < count; ++i)
        {
            ARTS_TRANSFORM_DOT;
            ARTS_TRANSFORM_FOG;
            ARTS_TRANSFORM_CODE;
        }
    }

    return clip_any | (clip_all << 8);
}

void agiBlendColors(u32* ARTS_RESTRICT shaded, u32* ARTS_RESTRICT colors, i32 count, u32 color)
{
    if (color == 0xFFFFFFFF)
    {
        std::memcpy(shaded, colors, count * sizeof(u32));

        return;
    }

    if (count)
    {
        u32 const mul_b = (color & 0xFF) * 0x8081;
        u32 const mul_g = ((color >> 8) & 0xFF) * 0x8081;
        u32 const mul_r = ((color >> 16) & 0xFF) * 0x8081;
        u32 const mul_a = (color >> 24) * 0x8081;

        for (i32 i = 0; i < count; ++i)
        {
            u32 const input = colors[i];

            u8 const b = static_cast<u8>((mul_b * (input & 0xFF)) >> 23);
            u8 const g = static_cast<u8>((mul_g * ((input >> 8) & 0xFF)) >> 23);
            u8 const r = static_cast<u8>((mul_r * ((input >> 16) & 0xFF)) >> 23);
            u8 const a = static_cast<u8>((mul_a * (input >> 24)) >> 23);

            shaded[i] = (a << 24) | (r << 16) | (g << 8) | b;
        }
    }
}
#endif

#define ARTS_SHADOW_TRANSFORM_DOT                                                                                    \
    output[i].x = ShadowMatrix.m0.x * input[i].x + ShadowMatrix.m1.x * input[i].y + ShadowMatrix.m2.x * input[i].z + \
        ShadowMatrix.m3.x;                                                                                           \
    output[i].y = ShadowMatrix.m0.y * input[i].x + ShadowMatrix.m1.y * input[i].y + ShadowMatrix.m2.y * input[i].z + \
        ShadowMatrix.m3.y;                                                                                           \
    output[i].z = ShadowMatrix.m0.z * input[i].x + ShadowMatrix.m1.z * input[i].y + ShadowMatrix.m2.z * input[i].z + \
        ShadowMatrix.m3.z;                                                                                           \
    output[i].w = ShadowMatrix.m0.w * input[i].x + ShadowMatrix.m1.w * input[i].y + ShadowMatrix.m2.w * input[i].z + \
        ShadowMatrix.m3.w;

void agiMeshSet::ShadowTransform(Vector4* ARTS_RESTRICT output, Vector3* ARTS_RESTRICT input, i32 count)
{
    STATS.VertsXfrm += count;

    if (FogValue == 0.0f)
    {
        for (i32 i = 0; i < count; ++i)
        {
            ARTS_SHADOW_TRANSFORM_DOT;
        }
    }
    else
    {
        for (i32 i = 0; i < count; ++i)
        {
            ARTS_SHADOW_TRANSFORM_DOT;
            ARTS_TRANSFORM_FOG;
        }
    }
}

u32 agiMeshSet::ShadowTransformOutcode(
    u8* ARTS_RESTRICT out_codes, Vector4* ARTS_RESTRICT output, Vector3* ARTS_RESTRICT input, i32 count)
{
    STATS.VertsOut += count;
    STATS.VertsXfrm += count;

    u8 clip_any = 0;
    u8 clip_all = 0xFF;

    if (FogValue == 0.0f)
    {
        for (i32 i = 0; i < count; ++i)
        {
            ARTS_SHADOW_TRANSFORM_DOT;
            ARTS_TRANSFORM_CODE;
        }
    }
    else
    {
        for (i32 i = 0; i < count; ++i)
        {
            ARTS_SHADOW_TRANSFORM_DOT;
            ARTS_TRANSFORM_FOG;
            ARTS_TRANSFORM_CODE;
        }
    }

    return clip_any | (clip_all << 8);
}

void agiMeshSet::SetFog(f32 fog, i32 /*arg2*/)
{
    FogValue = fog ? (255.0f / fog) : 0.0f;
}

// A simple wrapper to avoid default constructing elements
template <typename T, std::size_t N>
struct PodArray
{
    static_assert(std::is_trivially_copy_assignable_v<T>);

    alignas(T) unsigned char Data[N][sizeof(T)];

    operator T*()
    {
        return reinterpret_cast<T*>(Data);
    }

    operator const T*() const
    {
        return reinterpret_cast<const T*>(Data);
    }
};

// TODO: Process all clipped CV's at once, similar to ToScreen
void agiMeshSet::ClipTri(i32 i1, i32 i2, i32 i3, i32 texture)
{
    ARTS_UTIMED(agiClipTimer);

    if ((ClippedVertCount + 16) > ARTS_SIZE(ClippedVerts) || ClippedTriCount == ARTS_SIZE(ClippedTris))
        Quitf("ClipTri: clip buffer overflow");

    PodArray<CV, 16> verts;

    verts[0] = {out[VertexIndices[i1]], {1.0f, 0.0f, 0.0f}};
    verts[1] = {out[VertexIndices[i2]], {0.0f, 1.0f, 0.0f}};
    verts[2] = {out[VertexIndices[i3]], {0.0f, 0.0f, 1.0f}};

    u32 count = OnlyZClip ? ZClipOnly(&ClippedVerts[ClippedVertCount], verts, 3)
                          : FullClip(&ClippedVerts[ClippedVertCount], verts, 3);

    if (count)
    {
        for (u32 i = 0; i < count; ++i)
        {
            CV* vert = &ClippedVerts[ClippedVertCount + i];

            f32 inv_w = 1.0f / vert->Pos.w;
            f32 x = vert->Pos.x * inv_w * HalfWidth + OffsX;
            f32 y = vert->Pos.y * inv_w * HalfHeight + OffsY;
            f32 z = vert->Pos.z * inv_w * DepthScale + DepthOffset;

            vert->Fog = CalculateFog(vert->Pos.w, FogValue);
            vert->Pos.x = x;
            vert->Pos.y = y;
            vert->Pos.z = z;
            vert->Pos.w = inv_w;

            ClampToScreen(vert->Pos);
        }

        ClippedTris[ClippedTriCount] = {ClippedVertCount, count,
            {static_cast<u32>(i1), static_cast<u32>(i2), static_cast<u32>(i3)}, ClippedTextures[texture]};
        ClippedTextures[texture] = &ClippedTris[ClippedTriCount];
        ++ClippedTriCount;
        ClippedVertCount += count;
    }
}

void agiMeshSet::InitViewport(agiViewParameters& params)
{
    f32 width = static_cast<f32>(Pipe()->GetWidth());
    f32 height = static_cast<f32>(Pipe()->GetHeight());

    HalfWidth = std::floor(width * params.Width * 0.5f);
    HalfHeight = -std::floor(height * params.Height * 0.5f);

    OffsX = width * params.X + HalfWidth;
    OffsY = height * (1.0f - params.Y) + HalfHeight;

    if (GetRendererInfo().SpecialFlags & 0x8)
        HalfHeight *= 1.01f;

    MinX = OffsX - HalfWidth;
    MaxX = OffsX + HalfWidth;
    MinY = OffsY + HalfHeight;
    MaxY = OffsY - HalfHeight;

    if (GetRendererInfo().SpecialFlags & 0x20)
    {
        // TODO: Use viewport scissor region
        // TODO: Allow custom [Min/Max]Z
        if (MinX <= 0.0f && MaxX >= width && MinY <= 0.0f && MaxY >= height)
        {
            MinX = -INFINITY;
            MaxX = +INFINITY;
            MinY = -INFINITY;
            MaxY = +INFINITY;
            OnlyZClip = true;
            ClipMask = AGI_MESH_CLIP_NZ | AGI_MESH_CLIP_PZ;
        }
        else
        {
            OnlyZClip = false;
            ClipMask = AGI_MESH_CLIP_ANY;
        }
    }
    else
    {
        MinX = std::max(MinX, std::floor(params.X * width));
        MaxX = std::min(MaxX, std::ceil((params.X + params.Width) * width));
        MinY = std::max(MinY, std::floor((1.0f - (params.Y + params.Height)) * height));
        MaxY = std::min(MaxY, std::ceil((1.0f - params.Y) * height));

        MinX = std::max(MinX, 0.0f);
        MaxX = std::min(MaxX, width);
        MinY = std::max(MinY, 0.0f);
        MaxY = std::min(MaxY, height);
    }

    if (FlipX)
        HalfWidth = -HalfWidth;
}

b32 agiMeshSet::Draw(u32 flags)
{
    // FIXME: Avoid this check
    if (agiMeshSet* volatile this_ptr = this; !this_ptr)
        return false;

    bool drawn = false;

    if (LockIfResident())
    {
        if (Geometry(flags, Vertices, Planes) <= 0xFF)
        {
            FirstPass(Colors, TexCoords, 0xFFFFFFFF);
            drawn = true;
        }

        Unlock();
    }
    else
    {
        PageIn();
    }

    return drawn;
}

b32 agiMeshSet::DrawColor(u32 color, u32 flags)
{
    bool drawn = false;

    if (LockIfResident())
    {
        if (Geometry(flags, Vertices, Planes) <= 0xFF)
        {
            u32* colors = Colors;

            if (colors)
            {
                u32* shaded = ARTS_ALLOCA(u32, AdjunctCount);

                {
                    ARTS_UTIMED(agiLightTimer);
                    agiBlendColors(shaded, colors, AdjunctCount, color);
                }

                colors = shaded;
                color = 0xFFFFFFFF;
            }

            FirstPass(colors, TexCoords, color);

            drawn = true;
        }

        Unlock();
    }
    else
    {
        PageIn();
    }

    return drawn;
}

b32 agiMeshSet::DrawLit(agiMeshLighter lighter, u32 flags, u32* colors)
{
    if (!lighter)
        return Draw(flags);

    bool drawn = false;

    if (LockIfResident())
    {
        if (Geometry(flags, Vertices, Planes) <= 0xFF)
        {
            u32* shaded = ARTS_ALLOCA(u32, AdjunctCount);

            {
                ARTS_UTIMED(agiLightTimer);
                lighter(codes, shaded, colors ? colors : Colors, this);
            }

            FirstPass(shaded, TexCoords, 0);
            drawn = true;
        }

        Unlock();
    }
    else
    {
        PageIn();
    }

    return drawn;
}

void agiMeshSet::DrawLitEnv(agiMeshLighter lighter, agiTexDef* env_map, Matrix34& transform, u32 flags)
{
    if (LockIfResident())
    {
        if (agiCurState.GetMaxTextures() > 1 && agiRQ.EnvMap)
        {
            if (Geometry(flags, Vertices, Planes) <= 0xFF)
            {
                u32* colors = Colors;

                if (lighter)
                {
                    u32* shaded = ARTS_ALLOCA(u32, AdjunctCount);

                    {
                        ARTS_UTIMED(agiLightTimer);
                        lighter(codes, shaded, colors, this);
                    }

                    colors = shaded;
                }

                MultiTexEnvMap(colors, 0xFFFFFFFF, env_map, transform);
            }
        }
        else if (DrawLit(lighter, flags, nullptr) && env_map)
        {
            EnvMap(transform, env_map, 0xFFFFFFFF);
        }

        Unlock();
    }
    else
    {
        PageIn();
    }
}

static void (agiMeshSet::*const FirstPassFunctions[2][2][2][2])(u32* colors, Vector2* tex_coords, u32 color) {
    {
        {
            {&agiMeshSet::FirstPass_HW_UV_CPV_noDYNTEX, &agiMeshSet::FirstPass_HW_UV_CPV_DYNTEX},
            {&agiMeshSet::FirstPass_HW_UV_noCPV_noDYNTEX, &agiMeshSet::FirstPass_HW_UV_noCPV_DYNTEX},
        },
        {
            {&agiMeshSet::FirstPass_HW_noUV_CPV_noDYNTEX, &agiMeshSet::FirstPass_HW_noUV_CPV_DYNTEX},
            {&agiMeshSet::FirstPass_HW_noUV_noCPV_noDYNTEX, &agiMeshSet::FirstPass_HW_noUV_noCPV_DYNTEX},
        },
    },
    {
        {
            {&agiMeshSet::FirstPass_SW_UV_CPV_noDYNTEX, &agiMeshSet::FirstPass_SW_UV_CPV_DYNTEX},
            {&agiMeshSet::FirstPass_SW_UV_noCPV_noDYNTEX, &agiMeshSet::FirstPass_SW_UV_noCPV_DYNTEX},
        },
        {
            {&agiMeshSet::FirstPass_SW_noUV_CPV_noDYNTEX, &agiMeshSet::FirstPass_SW_noUV_CPV_DYNTEX},
            {&agiMeshSet::FirstPass_SW_noUV_noCPV_noDYNTEX, &agiMeshSet::FirstPass_SW_noUV_noCPV_DYNTEX},
        },
    },
};

static extern_var(0x725134, i32, DynTexFlag); // mmCarModel::Draw, mmVehicleForm::Cull

void agiMeshSet::FirstPass(u32* colors, Vector2* tex_coords, u32 color)
{
    if (agiCurState.GetDrawMode() == 3)
    {
        colors = nullptr;
        color = 0xFF202020;
    }

    ARTS_UTIMED(agiFirstPass);

    (this->*FirstPassFunctions[agiCurState.GetSoftwareRendering()][tex_coords == nullptr][colors == nullptr][(DynTexFlag & AGI_MESH_DRAW_DYNTEX) != 0])(
        colors, tex_coords, color);
}

static extern_var(0x719840, i32, CurrentMeshSetVariant);

template <typename T>
static inline void fill_bytes(T* dst, usize len, u8 value)
{
    std::memset(dst, value, len * sizeof(T));
}

i32 agiMeshSet::Geometry(u32 flags, Vector3* verts, Vector4* planes)
{
    ArAssert(Resident == 2, "Mesh not loaded");

    ClippedVertCount = 0;
    ClippedTriCount = 0;
    fill_bytes(ClippedTextures, TextureCount + 1, 0);

    Init(planes && (SurfaceCount > 1));

    u32 clip_mask = (flags & AGI_MESH_DRAW_CLIP) ? AGI_MESH_CLIP_ANY : 0; // clip_any | (clip_all << 8)

    {
        ARTS_UTIMED(agiTransformTimer);

        // If available, transform the bounding box, checking how visible it is
        if (clip_mask && BoundingBox)
        {
            clip_mask = TransformOutcode(codes, out, BoundingBox, 8);

            if (clip_mask > 0xFF) // All verts are clipped (not visible)
                return clip_mask;
        }

        if (clip_mask & ClipMask)
        {
            clip_mask = TransformOutcode(codes, out, verts, VertexCount);

            if (clip_mask > 0xFF) // All verts are clipped (not visible)
                return clip_mask;
        }
        else // Assume nothing needs clipping
        {
            Transform(out, verts, VertexCount);
        }
    }

    {
        ARTS_UTIMED(agiTraverseTimer);

        fill_bytes(firstFacet, TextureCount + 1, 0xFF);
        fill_bytes(vertCounts, TextureCount + 1, 0);
        fill_bytes(indexCounts, TextureCount + 1, 0);

        DynTexFlag = flags & AGI_MESH_DRAW_DYNTEX;
        CurrentMeshSetVariant = std::min<i32>(flags >> AGI_MESH_DRAW_VARIANT_SHIFT, VariationCount - 1);

        if (clip_mask & ClipMask)
        {
            for (u32 i = 0; i < SurfaceCount; ++i)
            {
                const u16* ARTS_RESTRICT surface = &SurfaceIndices[i * 4];

                u8 clip_any = codes[VertexIndices[surface[0]]] | codes[VertexIndices[surface[1]]] |
                    codes[VertexIndices[surface[2]]];

                u8 clip_all = codes[VertexIndices[surface[0]]] & codes[VertexIndices[surface[1]]] &
                    codes[VertexIndices[surface[2]]];

                i16 num_verts;
                i16 num_index;

                if (surface[3])
                {
                    clip_any |= codes[VertexIndices[surface[3]]];
                    clip_all &= codes[VertexIndices[surface[3]]];
                    num_verts = 4;
                    num_index = 6;
                }
                else
                {
                    num_verts = 3;
                    num_index = 3;
                }

                if (!(clip_all & AGI_MESH_CLIP_ANY) && (!planes || !IsBackfacing(planes[i])))
                {
                    u8 texture = TextureIndices[i];

                    if (clip_any & AGI_MESH_CLIP_ANY)
                    {
                        if (surface[3])
                        {
                            ClipTri(surface[1], surface[2], surface[3], texture);
                            ClipTri(surface[1], surface[3], surface[0], texture);
                        }
                        else
                        {
                            ClipTri(surface[0], surface[1], surface[2], texture);
                        }
                    }
                    else
                    {
                        vertCounts[texture] += num_verts;
                        indexCounts[texture] += num_index;
                        nextFacet[i] = firstFacet[texture];
                        firstFacet[texture] = static_cast<i16>(i);
                    }

                    codes[VertexIndices[surface[0]]] |= AGI_MESH_CLIP_SCREEN;
                    codes[VertexIndices[surface[1]]] |= AGI_MESH_CLIP_SCREEN;
                    codes[VertexIndices[surface[2]]] |= AGI_MESH_CLIP_SCREEN;

                    if (surface[3])
                        codes[VertexIndices[surface[3]]] |= AGI_MESH_CLIP_SCREEN;
                }
            }
        }
        else
        {
            // Either we didn't use TransformOutcode, or we don't care about the clipping it returned. Either way, initialize codes
            fill_bytes(codes, VertexCount,
#ifdef CLIP_ALL_TO_SCREEN
                AGI_MESH_CLIP_SCREEN
#else
                0
#endif
            );

            for (u32 i = 0; i < SurfaceCount; ++i)
            {
                if (!planes || !IsBackfacing(planes[i]))
                {
                    u8 texture = TextureIndices[i];
                    const u16* ARTS_RESTRICT surface = &SurfaceIndices[i * 4];

                    if (surface[3])
                    {
                        vertCounts[texture] += 4;
                        indexCounts[texture] += 6;

#ifndef CLIP_ALL_TO_SCREEN
                        codes[VertexIndices[surface[3]]] |= AGI_MESH_CLIP_SCREEN;
#endif
                    }
                    else
                    {
                        vertCounts[texture] += 3;
                        indexCounts[texture] += 3;
                    }

#ifndef CLIP_ALL_TO_SCREEN
                    codes[VertexIndices[surface[0]]] |= AGI_MESH_CLIP_SCREEN;
                    codes[VertexIndices[surface[1]]] |= AGI_MESH_CLIP_SCREEN;
                    codes[VertexIndices[surface[2]]] |= AGI_MESH_CLIP_SCREEN;
#endif

                    nextFacet[i] = firstFacet[texture];
                    firstFacet[texture] = static_cast<i16>(i);
                }
            }
        }
    }

    ToScreen(codes, out, VertexCount);

    return clip_mask;
}

i32 agiMeshSet::ShadowGeometry(u32 flags, Vector3* verts, Vector4 const& surface_dir, Vector3 const& light_dir)
{
    ClippedVertCount = 0;
    ClippedTriCount = 0;
    ClippedTextures[0] = 0;
    ShadowInit(surface_dir, light_dir);

    u32 clip_mask = (flags & AGI_MESH_DRAW_CLIP) ? AGI_MESH_CLIP_ANY : 0; // clip_any | (clip_all << 8)

    {
        ARTS_UTIMED(agiTransformTimer);

        // If available, transform the bounding box, checking how visible it is
        if (clip_mask && BoundingBox)
        {
            clip_mask = ShadowTransformOutcode(codes, out, BoundingBox, 8);

            if (clip_mask > 0xFF) // All verts are clipped (not visible)
                return clip_mask;
        }

        if (clip_mask & ClipMask)
        {
            clip_mask = ShadowTransformOutcode(codes, out, verts, VertexCount);

            if (clip_mask > 0xFF) // All verts are clipped (not visible)
                return clip_mask;
        }
        else // Assume nothing needs clipping
        {
            ShadowTransform(out, verts, VertexCount);
        }
    }

    {
        ARTS_UTIMED(agiTraverseTimer);

        firstFacet[0] = -1;
        vertCounts[0] = 0;
        indexCounts[0] = 0;

        if (clip_mask & ClipMask)
        {
            for (u32 i = 0; i < SurfaceCount; ++i)
            {
                const u16* ARTS_RESTRICT surface = &SurfaceIndices[i * 4];

                u8 clip_any = codes[VertexIndices[surface[0]]] | codes[VertexIndices[surface[1]]] |
                    codes[VertexIndices[surface[2]]];

                u8 clip_all = codes[VertexIndices[surface[0]]] & codes[VertexIndices[surface[1]]] &
                    codes[VertexIndices[surface[2]]];

                i16 num_verts;
                i16 num_index;

                if (surface[3])
                {
                    clip_any |= codes[VertexIndices[surface[3]]];
                    clip_all &= codes[VertexIndices[surface[3]]];
                    num_verts = 4;
                    num_index = 6;
                }
                else
                {
                    num_verts = 3;
                    num_index = 3;
                }

                if (!(clip_all & AGI_MESH_CLIP_ANY))
                {
                    if (clip_any & AGI_MESH_CLIP_ANY)
                    {
                        if (surface[3])
                        {
                            ClipTri(surface[1], surface[2], surface[3], 0);
                            ClipTri(surface[1], surface[3], surface[0], 0);
                        }
                        else
                        {
                            ClipTri(surface[0], surface[1], surface[2], 0);
                        }
                    }
                    else
                    {
                        vertCounts[0] += num_verts;
                        indexCounts[0] += num_index;
                        nextFacet[i] = firstFacet[0];
                        firstFacet[0] = static_cast<i16>(i);
                    }

                    codes[VertexIndices[surface[0]]] |= AGI_MESH_CLIP_SCREEN;
                    codes[VertexIndices[surface[1]]] |= AGI_MESH_CLIP_SCREEN;
                    codes[VertexIndices[surface[2]]] |= AGI_MESH_CLIP_SCREEN;

                    if (surface[3])
                        codes[VertexIndices[surface[3]]] |= AGI_MESH_CLIP_SCREEN;
                }
            }
        }
        else
        {
            // Either we didn't use TransformOutcode, or we don't care about the clipping it returned. Either way, initialize codes
            fill_bytes(codes, VertexCount,
#ifdef CLIP_ALL_TO_SCREEN
                AGI_MESH_CLIP_SCREEN
#else
                0
#endif
            );

            for (u32 i = 0; i < SurfaceCount; ++i)
            {
                const u16* ARTS_RESTRICT surface = &SurfaceIndices[i * 4];

                if (surface[3])
                {
                    vertCounts[0] += 4;
                    indexCounts[0] += 6;

#ifndef CLIP_ALL_TO_SCREEN
                    codes[VertexIndices[surface[3]]] |= AGI_MESH_CLIP_SCREEN;
#endif
                }
                else
                {
                    vertCounts[0] += 3;
                    indexCounts[0] += 3;
                }

#ifndef CLIP_ALL_TO_SCREEN
                codes[VertexIndices[surface[0]]] |= AGI_MESH_CLIP_SCREEN;
                codes[VertexIndices[surface[1]]] |= AGI_MESH_CLIP_SCREEN;
                codes[VertexIndices[surface[2]]] |= AGI_MESH_CLIP_SCREEN;
#endif

                nextFacet[i] = firstFacet[0];
                firstFacet[0] = static_cast<i16>(i);
            }
        }
    }

    ToScreen(codes, out, VertexCount);

    return clip_mask;
}

void agiMeshSet::DrawLines(Vector3* starts, Vector3* ends, u32* colors, i32 count)
{
    agiMeshSet::Init(false);

    agiScreenVtx* ARTS_RESTRICT verts = ARTS_ALLOCA(agiScreenVtx, count * 2);
    i32 stored = 0;

    for (i32 i = 0; i < count; ++i)
    {
        Vector3 start = starts[i];
        Vector3 end = ends[i];
        u32 color = colors[i];

        f32 start_w = M.m0.z * start.x + M.m1.z * start.y + M.m2.z * start.z + M.m3.z;
        f32 start_z = start_w * ProjZZ + ProjZW;

        if (-start_w > start_z || start_z > start_w)
            continue;

        f32 end_w = M.m0.z * end.x + M.m1.z * end.y + M.m2.z * end.z + M.m3.z;
        f32 end_z = end_w * ProjZZ + ProjZW;

        if (-end_w > end_z || end_z > end_w)
            continue;

        f32 start_x = M.m0.x * start.x + M.m1.x * start.y + M.m2.x * start.z + M.m3.x;
        f32 start_y = M.m0.y * start.x + M.m1.y * start.y + M.m2.y * start.z + M.m3.y;

        if (-start_w > start_x || start_x > start_w || -start_w > start_y || start_y > start_w)
            continue;

        f32 end_x = M.m0.x * end.x + M.m1.x * end.y + M.m2.x * end.z + M.m3.x;
        f32 end_y = M.m0.y * end.x + M.m1.y * end.y + M.m2.y * end.z + M.m3.y;

        if (-end_w > end_x || end_x > end_w || -end_w > end_y || end_y > end_w)
            continue;

        f32 start_rhw = 1.0f / start_w;
        f32 end_rhw = 1.0f / end_w;

        verts[stored].x = start_x * start_rhw * HalfWidth + OffsX;
        verts[stored].y = start_y * start_rhw * HalfHeight + OffsY;
        verts[stored].z = start_z * start_rhw * DepthScale + DepthOffset;
        verts[stored].w = start_rhw;
        verts[stored].color = color;
        verts[stored].specular = 0xFF000000;
        verts[stored].tv = 0.0f;
        verts[stored].tu = 0.0f;
        ClampToScreen(verts[stored]);
        ++stored;

        verts[stored].x = end_x * end_rhw * HalfWidth + OffsX;
        verts[stored].y = end_y * end_rhw * HalfHeight + OffsY;
        verts[stored].z = end_z * end_rhw * DepthScale + DepthOffset;
        verts[stored].w = end_rhw;
        verts[stored].color = color;
        verts[stored].specular = 0xFF000000;
        verts[stored].tv = 0.0f;
        verts[stored].tu = 0.0f;
        ClampToScreen(verts[stored]);
        ++stored;
    }

    if (stored)
    {
        ArAssert((stored & 1) == 0, "Invalid Vertex Count");

        RAST->LineList(agiVtxType::Screen, (agiVtx*) verts, stored);
    }
}
