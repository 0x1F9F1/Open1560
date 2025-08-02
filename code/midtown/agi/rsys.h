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

#include "refresh.h"
#include "vertex.h"

class agiMtlDef;
class agiTexDef;

class agiRasterizer : public agiRefreshable
{
public:
    // ??0agiRasterizer@@QAE@PAVagiPipeline@@@Z
    ARTS_EXPORT agiRasterizer(agiPipeline* pipe);

    // ??_GagiRasterizer@@UAEPAXI@Z
    // ??_EagiRasterizer@@UAEPAXI@Z
    // ??1agiRasterizer@@UAE@XZ
    ARTS_EXPORT ~agiRasterizer() override = default;

    // ?BeginGroup@agiRasterizer@@UAEXXZ
    ARTS_EXPORT virtual void BeginGroup();

    // ?EndGroup@agiRasterizer@@UAEXXZ
    ARTS_EXPORT virtual void EndGroup();

    virtual void Verts(agiVtxType type, agiVtx* vertices, i32 vertex_count) = 0;

    virtual void Points(agiVtxType type, agiVtx* vertices, i32 vertex_count) = 0;

    virtual void SetVertCount(i32 vertex_count) = 0;

    virtual void Triangle(i32 v0, i32 v1, i32 v2) = 0;

    // ?Quad@agiRasterizer@@UAEXHHHH@Z
    ARTS_EXPORT virtual void Quad(i32 v0, i32 v1, i32 v2, i32 v3);

    // ?Poly@agiRasterizer@@UAEXPAHH@Z
    ARTS_EXPORT virtual void Poly(i32* indices, i32 count);

    virtual void Line(i32 v0, i32 v1) = 0;

    virtual void Card(i32 v0, i32 v1) = 0;

    virtual void Mesh(agiVtxType type, agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count) = 0;

    // ?Mesh2@agiRasterizer@@UAEXPAUagiScreenVtx2@@HPAGH@Z
    ARTS_EXPORT virtual void Mesh2(agiScreenVtx2* vertices, i32 vertex_count, u16* indices, i32 index_count);

    // ?LineList@agiRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    ARTS_EXPORT virtual void LineList(agiVtxType type, agiVtx* vertices, i32 vertex_count);
};

check_size(agiRasterizer, 0x18);

enum class agiBlendSet : u8
{
    SrcAlpha_InvSrcAlpha = 0,
    SrcAlpha_One = 1,
    Zero_SrcAlpha = 3,
    Zero_SrcColor = 4,
    One_One = 5, // Additive Blending
};

enum class agiCullMode : u8
{
    None = 1, // Do not cull back faces
    CW = 2,   // Cull back faces with clockwise vertices
    CCW = 3   // Cull back faces with counterclockwise vertices
};

enum class agiCmpFunc : u8 // gfxZFunc
{
    Never = 1,
    Less = 2,
    Equal = 3,
    LessEqual = 4,
    Greater = 5,
    Notequal = 6,
    GreaterEqual = 7,
    Always = 8,
};

enum class agiTexFilter : u8
{
    Point = 0,     // Point
    Bilinear = 1,  // Linear
    Trilinear = 2, // Nicest
};

enum class agiTexEnv : u8
{
    // Color = Texture
    // COLOROP = SELECTARG1, COLORARG1 = TEXTURE, ALPHAOP = SELECTARG1, ALPHAARG1 = TEXTURE
    Replace = 0,

    // Color = Texture * Diffuse
    // COLOROP = MODULATE,   COLORARG1 = TEXTURE, ALPHAOP = MODULATE,   ALPHAARG1 = TEXTURE, COLORARG2 = DIFFUSE
    Modulate = 1,

    // Color = Diffuse
    // COLOROP = DISABLE
    Disable = 2,
};

enum class agiFogMode : u8
{
    None,
    Pixel,
    Vertex,
};

enum class agiFillMode : u8
{
    Point = 0x1,
    Wire = 0x2,
    Solid = 0x3,
};

enum agiDrawMode : u8
{
    agiDrawFillMask = 0x3,

#define X(DRAW, FILL) (DRAW << 2) | static_cast<u8>(agiFillMode::FILL)
    agiDrawWireframe = X(0, Wire),
    agiDrawDepth = X(0, Solid),
    agiDrawColored = X(1, Solid),
    agiDrawSolid = X(2, Solid),
    agiDrawTextured = X(3, Solid),
#undef X
};

struct agiRendStateStruct
{
public:
    // ?Reset@agiRendStateStruct@@QAEXXZ
    ARTS_EXPORT void Reset();

    agiMtlDef* Mtl {};
    agiTexDef* Texture {};
    agiTexDef* Texture2 {};

    agiBlendSet BlendSet {};

    // false: Flat (Provoking Vertex)
    // true : Interpolate
    bool SmoothShading {};

    agiDrawMode DrawMode {};

    agiTexFilter TexFilter {};

    agiTexEnv TexEnv {};

    agiCullMode CullMode {};

    agiCmpFunc ZFunc {};

    agiFogMode FogMode {};
    bool TexturePerspective {};
    bool AlphaEnable {};

    bool WrapU {};
    bool WrapV {};

    bool ZEnable {};
    bool ZWrite {};

    u32 FogColor {};
    f32 FogStart {};
    f32 FogEnd {};
    f32 FogDensity {};

    bool Dither {};
    u8 byte2D {};
    bool SoftwareRendering {};
    bool SpecularEnable {};
    u8 byte30 {};
    i8 MaxTextures {};
    bool StippledAlpha {};
    u8 AlphaRef {};
    f32 LodBias {};
    u32 Specular {};
};

check_size(agiRendStateStruct, 0x3C);

class agiRendState
{
private:
    b32 touched_ {};
    agiRendStateStruct state_ {};

public:
    bool IsTouched()
    {
        return touched_;
    }

    void ClearTouched()
    {
        touched_ = false;
    }

    template <typename T>
    inline T Set(T& value, T new_value)
    {
        T old_value = value;

        if (old_value != new_value)
        {
            value = new_value;
            touched_ = true;
        }

        return old_value;
    }

#define AGI_RSTATE_MEMBER(NAME)                        \
    inline auto Get##NAME() const                      \
    {                                                  \
        return state_.NAME;                            \
    }                                                  \
                                                       \
    inline auto Set##NAME(decltype(state_.NAME) value) \
    {                                                  \
        return Set(state_.NAME, value);                \
    }

    AGI_RSTATE_MEMBER(Mtl)
    AGI_RSTATE_MEMBER(Texture)
    AGI_RSTATE_MEMBER(Texture2)
    AGI_RSTATE_MEMBER(BlendSet)
    AGI_RSTATE_MEMBER(SmoothShading)
    AGI_RSTATE_MEMBER(DrawMode)
    AGI_RSTATE_MEMBER(TexFilter)
    AGI_RSTATE_MEMBER(TexEnv)
    AGI_RSTATE_MEMBER(CullMode)
    AGI_RSTATE_MEMBER(ZFunc)
    AGI_RSTATE_MEMBER(FogMode)
    AGI_RSTATE_MEMBER(TexturePerspective)
    AGI_RSTATE_MEMBER(AlphaEnable)
    AGI_RSTATE_MEMBER(WrapU)
    AGI_RSTATE_MEMBER(WrapV)
    AGI_RSTATE_MEMBER(ZEnable)
    AGI_RSTATE_MEMBER(ZWrite)
    AGI_RSTATE_MEMBER(FogColor)
    AGI_RSTATE_MEMBER(FogStart)
    AGI_RSTATE_MEMBER(FogEnd)
    AGI_RSTATE_MEMBER(FogDensity)
    AGI_RSTATE_MEMBER(Dither)
    AGI_RSTATE_MEMBER(byte2D)
    AGI_RSTATE_MEMBER(SoftwareRendering)
    AGI_RSTATE_MEMBER(SpecularEnable)
    AGI_RSTATE_MEMBER(byte30)
    AGI_RSTATE_MEMBER(MaxTextures)
    AGI_RSTATE_MEMBER(StippledAlpha)
    AGI_RSTATE_MEMBER(AlphaRef)
    AGI_RSTATE_MEMBER(LodBias)
    AGI_RSTATE_MEMBER(Specular)

#undef AGI_RSTATE_MEMBER
};

check_size(agiRendState, 0x40);

// ?RAST@@3PAVagiRasterizer@@A
ARTS_EXPORT extern agiRasterizer* RAST;

// Unused
struct agiRenderOpts
{};

// ?ROPTS@@3UagiRenderOpts@@A
ARTS_EXPORT extern agiRenderOpts ROPTS;

// ?agiCurState@@3VagiRendState@@A
ARTS_EXPORT extern agiRendState agiCurState;

// ?agiLastState@@3UagiRendStateStruct@@A
ARTS_EXPORT extern agiRendStateStruct agiLastState;
