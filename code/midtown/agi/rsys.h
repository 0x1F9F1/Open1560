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
    agi:rsys

    0x557BE0 | public: __thiscall agiRasterizer::agiRasterizer(class agiPipeline *) | ??0agiRasterizer@@QAE@PAVagiPipeline@@@Z
    0x557CE0 | public: void __thiscall agiRendStateStruct::Reset(void) | ?Reset@agiRendStateStruct@@QAEXXZ
    0x557D10 | public: virtual __thiscall agiRasterizer::~agiRasterizer(void) | ??1agiRasterizer@@UAE@XZ
    0x557D20 | public: virtual void __thiscall agiRasterizer::BeginGroup(void) | ?BeginGroup@agiRasterizer@@UAEXXZ
    0x557D30 | public: virtual void __thiscall agiRasterizer::EndGroup(void) | ?EndGroup@agiRasterizer@@UAEXXZ
    0x557D40 | public: virtual void __thiscall agiRasterizer::Quad(int,int,int,int) | ?Quad@agiRasterizer@@UAEXHHHH@Z
    0x557D70 | public: virtual void __thiscall agiRasterizer::Poly(int *,int) | ?Poly@agiRasterizer@@UAEXPAHH@Z
    0x557DB0 | public: virtual void __thiscall agiRasterizer::Mesh2(struct agiScreenVtx2 *,int,unsigned short *,int) | ?Mesh2@agiRasterizer@@UAEXPAUagiScreenVtx2@@HPAGH@Z
    0x557DD0 | public: virtual void __thiscall agiRasterizer::LineList(enum agiVtxType,union agiVtx *,int) | ?LineList@agiRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    0x557E40 | public: virtual void * __thiscall agiRasterizer::`vector deleting destructor'(unsigned int) | ??_EagiRasterizer@@UAEPAXI@Z
    0x557E40 | public: virtual void * __thiscall agiRasterizer::`scalar deleting destructor'(unsigned int) | ??_GagiRasterizer@@UAEPAXI@Z
    0x621660 | const agiRasterizer::`vftable' | ??_7agiRasterizer@@6B@
    0x656BD0 | struct agiRenderOpts ROPTS | ?ROPTS@@3UagiRenderOpts@@A
    0x8FF050 | struct agiRendStateStruct agiLastState | ?agiLastState@@3UagiRendStateStruct@@A
    0x8FF090 | class agiRendState agiCurState | ?agiCurState@@3VagiRendState@@A
    0x8FF0D0 | class agiRasterizer * RAST | ?RAST@@3PAVagiRasterizer@@A
*/

#include "refresh.h"

class agiTexDef;
class agiMtlDef;

enum agiVtxType : i32;
union agiVtx;

class agiRasterizer : public agiRefreshable
{
    // const agiRasterizer::`vftable' @ 0x621660

public:
    // 0x557BE0 | ??0agiRasterizer@@QAE@PAVagiPipeline@@@Z
    ARTS_EXPORT agiRasterizer(class agiPipeline* pipe);

    // 0x557E40 | ??_GagiRasterizer@@UAEPAXI@Z
    // 0x557E40 | ??_EagiRasterizer@@UAEPAXI@Z
    // 0x557D10 | ??1agiRasterizer@@UAE@XZ
    ARTS_EXPORT ~agiRasterizer() override = default;

    // 0x557D20 | ?BeginGroup@agiRasterizer@@UAEXXZ
    ARTS_EXPORT virtual void BeginGroup();

    // 0x557D30 | ?EndGroup@agiRasterizer@@UAEXXZ
    ARTS_EXPORT virtual void EndGroup();

    virtual void Verts(enum agiVtxType type, union agiVtx* vertices, i32 vertex_count) = 0;

    virtual void Points(enum agiVtxType type, union agiVtx* vertices, i32 vertex_count) = 0;

    virtual void SetVertCount(i32 vertex_count) = 0;

    virtual void Triangle(i32 v0, i32 v1, i32 v2) = 0;

    // 0x557D40 | ?Quad@agiRasterizer@@UAEXHHHH@Z
    ARTS_EXPORT virtual void Quad(i32 v0, i32 v1, i32 v2, i32 v3);

    // 0x557D70 | ?Poly@agiRasterizer@@UAEXPAHH@Z
    ARTS_EXPORT virtual void Poly(i32* indices, i32 count);

    virtual void Line(i32 v0, i32 v1) = 0;

    virtual void Card(i32 v0, i32 v1) = 0;

    virtual void Mesh(
        enum agiVtxType type, union agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count) = 0;

    // 0x557DB0 | ?Mesh2@agiRasterizer@@UAEXPAUagiScreenVtx2@@HPAGH@Z
    ARTS_EXPORT virtual void Mesh2(struct agiScreenVtx2* vertices, i32 vertex_count, u16* indices, i32 index_count);

    // 0x557DD0 | ?LineList@agiRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    ARTS_EXPORT virtual void LineList(enum agiVtxType type, union agiVtx* vertices, i32 vertex_count);
};

check_size(agiRasterizer, 0x18);

enum class agiBlendSet : u8
{
    SrcAlpha_InvSrcAlpha = 0,
    SrcAlpha_One = 1,
    Zero_SrcAlpha = 3,
    Zero_SrcColor = 4,
    One_One = 5,
};

enum class agiShadeMode : u8
{
    Flat = 0,
    Smooth = 1,
};

enum class agiCullMode : u8
{
    None = 1, // Do not cull back faces
    CW = 2,   // Cull back faces with clockwise vertices
    CCW = 3   // Cull back faces with counterclockwise vertices
};

enum class agiCmpFunc : u8
{
    Never = 1,
    Less = 2,
    Equal = 3,
    LessEqual = 4,
    Greater = 5,
    Notequal = 6,
    GreateRequal = 7,
    Always = 8,
};

enum class agiTexAddress : u8
{
    Wrap = 1,
    Mirror = 2,
    Clamp = 3,
    Border = 4,
};

enum class agiTexFilter : u8
{
    Point = 0,
    Bilinear = 1,
    Trilinear = 2,
};

enum class agiBlendOp : u8
{
    // COLOROP = SELECTARG1, COLORARG1 = TEXTURE, ALPHAOP = SELECTARG1, ALPHAARG1 = TEXTURE
    One = 0,

    // COLOROP = MODULATE,   COLORARG1 = TEXTURE, ALPHAOP = MODULATE,   ALPHAARG1 = TEXTURE, COLORARG2 = DIFFUSE
    Modulate = 1,

    // COLOROP = DISABLE
    Ignore = 2,
};

struct agiRendStateStruct
{
public:
    // 0x557CE0 | ?Reset@agiRendStateStruct@@QAEXXZ
    ARTS_EXPORT void Reset();

    agiMtlDef* Mtl {nullptr};
    agiTexDef* Texture {nullptr};
    agiTexDef* Texture2 {nullptr};

    agiBlendSet BlendSet {};

    // 0: FLAT
    // 1: GOURAUD
    agiShadeMode ShadeMode {};

    // DrawMode & 3 = FillMode
    // 0x0: None
    // 0x1: Point
    // 0x2: Line (Wireframe)
    // 0x3: Fill (Depth)

    // if (DrawMode == 3): DepthTest=0, ZWriteEnable=0, AlphaEnable=1, BlendMode=5, specular=0xFF202020
    // if (DrawMode == 15): TexCoord
    // if (DrawMode != 3) Color

    // 0x4: Enable Textures?
    // 0xB: Solid, No EnvMap,SphereMap
    // 0xF: Tex
    u8 DrawMode {0};

    agiTexFilter TexFilter {};

    agiBlendOp BlendOp {};

    agiCullMode CullMode {};

    agiCmpFunc ZFunc {};

    bool FogEnable {false};
    bool TexturePerspective {false};
    bool AlphaEnable {false};

    agiTexAddress AddressU {};
    agiTexAddress AddressV {};

    bool ZEnable {false};
    bool ZWrite {false};
    u32 FogColor {0};
    f32 FogStart {0.0f};
    f32 FogEnd {0.0f};
    f32 FogDensity {0.0f};
    bool Dither {false};
    u8 byte2D {0};
    bool SoftwareRendering {0};
    bool SpecularEnable {0};
    u8 byte30 {0};
    i8 MaxTextures {0};
    bool StippledAlpha {0};
    u8 AlphaRef {0};
    f32 LodBias {0.0f};
    u32 Specular {0};
};

check_size(agiRendStateStruct, 0x3C);

class agiRendState
{
public:
    b32 Touched {false};
    agiRendStateStruct State {};

    template <typename T>
    T Set(T& value, T new_value)
    {
        T old_value = value;

        if (old_value != new_value)
        {
            value = new_value;
            Touched = true;
        }

        return old_value;
    }

#define AGI_RSTATE_MEMBER(NAME)                \
    auto Get##NAME() const                     \
    {                                          \
        return State.NAME;                     \
    }                                          \
                                               \
    auto Set##NAME(decltype(State.NAME) value) \
    {                                          \
        return Set(State.NAME, value);         \
    }

    AGI_RSTATE_MEMBER(Mtl)
    AGI_RSTATE_MEMBER(Texture)
    AGI_RSTATE_MEMBER(Texture2)
    AGI_RSTATE_MEMBER(BlendSet)
    AGI_RSTATE_MEMBER(ShadeMode)
    AGI_RSTATE_MEMBER(DrawMode)
    AGI_RSTATE_MEMBER(TexFilter)
    AGI_RSTATE_MEMBER(BlendOp)
    AGI_RSTATE_MEMBER(CullMode)
    AGI_RSTATE_MEMBER(ZFunc)
    AGI_RSTATE_MEMBER(FogEnable)
    AGI_RSTATE_MEMBER(TexturePerspective)
    AGI_RSTATE_MEMBER(AlphaEnable)
    AGI_RSTATE_MEMBER(AddressU)
    AGI_RSTATE_MEMBER(AddressV)
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

// 0x8FF0D0 | ?RAST@@3PAVagiRasterizer@@A
ARTS_IMPORT extern class agiRasterizer* RAST;

// 0x656BD0 | ?ROPTS@@3UagiRenderOpts@@A
ARTS_IMPORT extern struct agiRenderOpts ROPTS;

// 0x8FF090 | ?agiCurState@@3VagiRendState@@A
ARTS_IMPORT extern class agiRendState agiCurState;

// 0x8FF050 | ?agiLastState@@3UagiRendStateStruct@@A
ARTS_IMPORT extern struct agiRendStateStruct agiLastState;
