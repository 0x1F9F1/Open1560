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
#include "data7/b2f.h"
#include "data7/utimer.h"
#include "memory/alloca.h"
#include "vector7/matrix34.h"

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
ARTS_IMPORT /*static*/ i32 FullClip(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x506EA0 | ?ZClipOnly@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ZClipOnly(struct CV* arg1, struct CV* arg2, i32 arg3);

#define ARTS_TRANSFORM_DOT                                                                  \
    output[i].x = M.m0.x * input[i].x + M.m1.x * input[i].y + M.m2.x * input[i].z + M.m3.x; \
    output[i].y = M.m0.y * input[i].x + M.m1.y * input[i].y + M.m2.y * input[i].z + M.m3.y; \
    output[i].w = M.m0.z * input[i].x + M.m1.z * input[i].y + M.m2.z * input[i].z + M.m3.z; \
    output[i].z = output[i].w * ProjZZ + ProjZW

static inline u8 CalculateFog(f32 w, f32 fog)
{
    return ~FloatToByte(std::min<f32>(w * fog, 255.0f));
}

#define ARTS_TRANSFORM_FOG fogout[i] = CalculateFog(output[i].w, FogValue)

#define ARTS_TRANSFORM_CODE                                                            \
    f32 w_abs = std::abs(output[i].w);                                                 \
    out_codes[i] = ClipMask &                                                          \
        ((((w_abs - std::abs(output[i].x)) < 0.0f) << ((output[i].x < 0.0f) + 0)) |    \
            (((w_abs - std::abs(output[i].y)) < 0.0f) << ((output[i].y < 0.0f) + 2)) | \
            (((w_abs - std::abs(output[i].z)) < 0.0f) << ((output[i].z < 0.0f) + 4))); \
    clip_or |= out_codes[i];                                                           \
    clip_and &= out_codes[i];

static extern_var(0x64A6D8, i32, ClipMask);

#ifndef ARTS_ENABLE_KNI
void agiMeshSet::ToScreen(u8* ARTS_RESTRICT in_codes, Vector4* ARTS_RESTRICT verts, i32 count)
{
    ARTS_UTIMED(agiInvertTimer);

    for (i32 i = 0; i < count; ++i)
    {
        if (in_codes[i] != 0x40)
            continue;

        Vector4* vert = &verts[i];

        f32 const inv_w = 1.0f / vert->w;

        vert->x = (vert->x * inv_w * HalfWidth) + OffsX;
        vert->y = (vert->y * inv_w * HalfHeight) + OffsY;
        vert->z = (vert->z * inv_w * DepthScale) + DepthOffset;
        vert->w = inv_w;

        ClampToScreen(vert);
    }
}

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

    u8 clip_or = 0;
    u8 clip_and = 0xFF;

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

    return clip_or | (clip_and << 8);
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

struct CV
{
    Vector4 Pos;
    Vector3 UV;
    u8 Fog;
};

check_size(CV, 0x20);

struct CT
{
    i32 Index;
    i32 Count;
    i32 Tri[3];
    CT* Next;
};

check_size(CT, 0x18);

static extern_var(0x725138, i32, ClippedVertCount);
static extern_var(0x720EB0, i32, ClippedTriCount);
static extern_var(0x72D390, CV[2048], ClippedVerts);
static extern_var(0x71DE98, CT[512], ClippedTris);
static extern_var(0x719848, CT* [256], ClippedTextures);
static extern_var(0x719E48, b32, OnlyZClip);

// TODO: Process all clipped CV's at once, similar to ToScreen

void agiMeshSet::ClipTri(i32 i1, i32 i2, i32 i3, i32 texture)
{
    ARTS_UTIMED(agiClipTimer);

    if (ClippedVertCount > 2032 || ClippedTriCount == 512)
        Quitf("ClipTri: clip buffer overflow");

    // TODO: Understand why there are 16
    CV verts[16];

    verts[0] = {out[VertexIndices[i1]], {1.0f, 0.0f, 0.0f}};
    verts[1] = {out[VertexIndices[i2]], {0.0f, 1.0f, 0.0f}};
    verts[2] = {out[VertexIndices[i3]], {0.0f, 0.0f, 1.0f}};

    i32 count = OnlyZClip ? ZClipOnly(&ClippedVerts[ClippedVertCount], verts, 3)
                          : FullClip(&ClippedVerts[ClippedVertCount], verts, 3);

    if (count)
    {
        for (i32 i = 0; i < count; ++i)
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

            ClampToScreen(&vert->Pos);
        }

        ClippedTris[ClippedTriCount] = {ClippedVertCount, count, {i1, i2, i3}, ClippedTextures[texture]};
        ClippedTextures[texture] = &ClippedTris[ClippedTriCount];
        ++ClippedTriCount;
        ClippedVertCount += count;
    }
}

b32 agiMeshSet::Draw(u32 flags)
{
    if (!this)
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
                agiBlendColors(shaded, colors, AdjunctCount, color);
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
