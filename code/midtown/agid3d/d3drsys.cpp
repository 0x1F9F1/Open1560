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

define_dummy_symbol(agid3d_d3drsys);

#include "d3drsys.h"

#include "agi/pipeline.h"
#include "agi/viewport.h"
#include "d3dtexdef.h"
#include "data7/utimer.h"
#include "dderror.h"
#include "eventq7/winevent.h"
#include "pcpipe.h"

static bool EnableDraw = true;
static agiVtxType VtxType {};
static D3DPRIMITIVETYPE PrimType {};
static i32 VtxCount = 0;
static u16* VtxIndex = nullptr;
static i32 VtxIndexCount = 0;
static u16 VtxIndices[1024] {};

static f32 VtxScreenOffset = 0.0f;
static bool VtxNeedOffset = false;

static mem::cmd_param PARAM_voodooaa {"voodooaa"};

i32 agiD3DRasterizer::BeginGfx()
{
    // // FIXME: This half pixel offset shouldn't be required.
    if (PARAM_voodooaa)
    {
        Displayf("Using half-pixel offset");
        VtxScreenOffset = -0.5f;
    }
    else
    {
        VtxScreenOffset = 0.0f;
    }

    return 0;
}

void agiD3DRasterizer::BeginGroup()
{
    FlushState();
}

void agiD3DRasterizer::Card(i32, i32)
{
    ++STATS.Cards;
}

void agiD3DRasterizer::EndGfx()
{}

void agiD3DRasterizer::EndGroup()
{
    FlushState();
}

void agiD3DRasterizer::Line(i32 i1, i32 i2)
{
    ++STATS.Lines;

    // TODO: Should this be + 2 ?
    if (VtxIndexCount + 4 > ARTS_SSIZE(VtxIndices) || PrimType != D3DPT_LINELIST || agiCurState.IsTouched())
    {
        FlushState();
        PrimType = D3DPT_LINELIST;
    }

    VtxIndex[VtxIndexCount + 0] = static_cast<u16>(i1);
    VtxIndex[VtxIndexCount + 1] = static_cast<u16>(i2);
    VtxIndexCount += 2;
}

void agiD3DRasterizer::Mesh(agiVtxType type, agiVtx* verts, i32 vert_count, u16* indices, i32 index_count)
{
    ArAssert(type == agiVtxType::Screen, "Invalid Vertex Type");

    STATS.Tris += static_cast<i32>(index_count / 3.0f);

    FlushState();

    VtxBase = verts;
    VtxCount = vert_count;
    PrimType = D3DPT_TRIANGLELIST;
    VtxIndex = indices;
    VtxIndexCount = index_count;
    VtxNeedOffset = true;

    FlushState();
}

void agiD3DRasterizer::Mesh2(agiScreenVtx2* verts, i32 vert_count, u16* indices, i32 index_count)
{
    STATS.Tris += static_cast<i32>(index_count / 3.0f);

    FlushState();

    if ((ActiveFlag & 1) && EnableDraw)
    {
        ARTS_UTIMED(agiRasterization);

        DD_TRY(Pipe()->GetD3DDevice()->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,
            (D3DFVF_TLVERTEX | D3DFVF_TEX2) & ~D3DFVF_TEX1, verts, vert_count, indices, index_count,
            D3DDP_DONOTUPDATEEXTENTS | D3DDP_DONOTCLIP));
    }
}

static DWORD GetVertexFlags(agiVtxType type)
{
    switch (type)
    {
        case agiVtxType::VtxType0: return 0;
        case agiVtxType::VtxType1: return D3DDP_DONOTUPDATEEXTENTS;
        case agiVtxType::VtxType2: return D3DDP_DONOTUPDATEEXTENTS;
        case agiVtxType::Screen: return D3DDP_DONOTUPDATEEXTENTS | D3DDP_DONOTCLIP;
    }

    return 0;
}

void agiD3DRasterizer::Points(agiVtxType type, agiVtx* verts, i32 vert_count)
{
    ArAssert(type == agiVtxType::Screen, "Invalid Vertex Type");

    FlushState();

    // TODO: Update stats
    // TODO: Check (ActiveFlag & 1) && EnableDraw

    DD_TRY(Pipe()->GetD3DDevice()->DrawPrimitive(
        D3DPT_POINTLIST, D3DFVF_TLVERTEX, verts, vert_count, GetVertexFlags(type)));
}

void agiD3DRasterizer::SetVertCount(i32 vert_count)
{
    VtxCount = vert_count;
}

void agiD3DRasterizer::Triangle(i32 i1, i32 i2, i32 i3)
{
    ++STATS.Tris;

    // TODO: Should this be + 3 ?
    if (VtxIndexCount + 4 > ARTS_SSIZE(VtxIndices) || PrimType != D3DPT_TRIANGLELIST || agiCurState.IsTouched())
    {
        FlushState();
        PrimType = D3DPT_TRIANGLELIST;
    }

    VtxIndex[VtxIndexCount + 0] = static_cast<u16>(i1);
    VtxIndex[VtxIndexCount + 1] = static_cast<u16>(i2);
    VtxIndex[VtxIndexCount + 2] = static_cast<u16>(i3);
    VtxIndexCount += 3;
}

void agiD3DRasterizer::Verts(agiVtxType type, agiVtx* verts, i32 vert_count)
{
    if (VtxIndexCount || agiCurState.IsTouched())
        FlushState();

    VtxType = type;
    VtxBase = verts;
    VtxCount = vert_count;
    VtxIndex = VtxIndices;
    VtxNeedOffset = true;
}

// TODO: Store data in agiD3DRasterizer

static DWORD RenderStates[64] {};
static DWORD TextureStageStates[2][23] {};
static i32 CurrentTextureStage = 0;

void d3d_state_init()
{
    for (i32 i = 1; i < 64; ++i)
        d3ddev->GetRenderState(static_cast<D3DRENDERSTATETYPE>(i), &RenderStates[i]);

    for (i32 i = 0; i < 2; ++i)
    {
        for (i32 j = 1; j < 23; ++j)
            d3ddev->GetTextureStageState(i, static_cast<D3DTEXTURESTAGESTATETYPE>(j), &TextureStageStates[i][j]);
    }
}

static void d3d_set_texture_stage_state(i32 stage, D3DTEXTURESTAGESTATETYPE type, DWORD state)
{
    ArDebugAssert(stage < 2, "Invalid Stage");
    ArDebugAssert(static_cast<i32>(type) < 23, "Invalid Type");

    if (TextureStageStates[stage][type] != state)
    {
        TextureStageStates[stage][type] = state;

        d3ddev->SetTextureStageState(stage, type, state);
    }
}

static void d3d_set_render_state(D3DRENDERSTATETYPE type, DWORD state)
{
    ArDebugAssert(static_cast<i32>(type) < 64, "Invalid Type");

    if (RenderStates[type] != state)
    {
        RenderStates[type] = state;
        ++STATS.StateChangeCalls;
        d3ddev->SetRenderState(type, state);
    }
}

void agiD3DRasterizer::FlushState()
{
    if (!(ActiveFlag & 0x1))
        return;

    if (VtxIndexCount)
    {
        ARTS_UTIMED(agiRasterization);

        ++STATS.GeomCalls;

        if (EnableDraw)
        {
            // FIXME: This may end up offsetting verts more than once if they are re-used.
            if (VtxNeedOffset)
            {
                if (f32 offset = VtxScreenOffset; offset != 0.0f)
                {
                    agiScreenVtx* verts = static_cast<agiScreenVtx*>(VtxBase);
                    i32 count = VtxCount;

                    for (i32 i = 0; i < count; ++i)
                    {
                        verts[i].x += offset;
                        verts[i].y += offset;
                    }
                }

                VtxNeedOffset = false;
            }

            DD_TRY(Pipe()->GetD3DDevice()->DrawIndexedPrimitive(
                PrimType, D3DFVF_TLVERTEX, VtxBase, VtxCount, VtxIndex, VtxIndexCount, GetVertexFlags(VtxType)));
        }

        VtxIndexCount = 0;
    }

    if (agiCurState.GetDrawMode() != 15)
        agiCurState.SetTexture(nullptr);

    if (!agiCurState.IsTouched())
        return;

    ARTS_UTIMED(agiStateChanges);
    ++STATS.StateChanges;

    IDirect3DDevice3* dev = Pipe()->GetD3DDevice();

    agiTexFilter tex_filter = agiCurState.GetTexFilter();
    bool alpha_enable = agiCurState.GetAlphaEnable();
    agiBlendOp blend_op = agiCurState.GetBlendOp();

    agiD3DTexDef* texture = static_cast<agiD3DTexDef*>(agiCurState.GetTexture());
    agiD3DTexDef* texture2 = static_cast<agiD3DTexDef*>(agiCurState.GetTexture2());

    i32 base_stage = (texture && texture2) ? texture->GetStage() : 0;
    i32 second_stage = texture2 ? (1 - base_stage) : -1;

    bool stage_changed = base_stage != CurrentTextureStage;
    CurrentTextureStage = base_stage;

    d3d_set_texture_stage_state(base_stage, D3DTSS_TEXCOORDINDEX, 0);

    if (second_stage >= 0)
        d3d_set_texture_stage_state(second_stage, D3DTSS_TEXCOORDINDEX, 1);

    if (stage_changed || agiCurState.GetMtl() != agiLastState.Mtl || texture != agiLastState.Texture ||
        texture2 != agiLastState.Texture2)
    {
        if (stage_changed || texture2 != agiLastState.Texture2)
        {
            if (texture2)
            {
                ArAssert(texture2->Tex.Flags & agiTexParameters::Second, "Invalid Texture");

                if (IDirect3DTexture2* th = texture2->GetHandle(second_stage))
                {
                    DD_TRY(dev->SetTexture(second_stage, th));

                    d3d_set_texture_stage_state(second_stage, D3DTSS_ADDRESSU,
                        texture2->Tex.ShouldWrapU() ? D3DTADDRESS_WRAP : D3DTADDRESS_CLAMP);

                    d3d_set_texture_stage_state(second_stage, D3DTSS_ADDRESSV,
                        texture2->Tex.ShouldWrapV() ? D3DTADDRESS_WRAP : D3DTADDRESS_CLAMP);
                }

                d3d_set_texture_stage_state(1, D3DTSS_COLOROP,
                    (agiCurState.GetBlendSet() == agiBlendSet::One_One) ? D3DTOP_ADD : D3DTOP_MODULATE);

                d3d_set_texture_stage_state(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
                d3d_set_texture_stage_state(1, D3DTSS_COLORARG2, D3DTA_CURRENT);
            }
            else if (agiCurState.GetMaxTextures() > 1)
            {
                d3d_set_texture_stage_state(1, D3DTSS_COLOROP, D3DTOP_DISABLE);

                DD_TRY(dev->SetTexture(1, nullptr));
            }

            agiLastState.Texture2 = texture2;
        }

        if (texture)
        {
            if (i32 scene_index = Pipe()->GetSceneIndex(); scene_index != texture->SceneIndex)
            {
                texture->SceneIndex = scene_index;

                STATS.TxlsXrfd += texture->SurfaceSize;
            }

            ++STATS.TextureChanges;

            if (IDirect3DTexture2* th = texture->GetHandle(0))
            {
                DD_TRY(dev->SetTexture(base_stage, th));

                EnableDraw = true;
            }
            else
            {
                EnableDraw = false;
            }

            agiCurState.SetWrapU(texture->Tex.ShouldWrapU());
            agiCurState.SetWrapV(texture->Tex.ShouldWrapV());

            d3d_set_render_state(D3DRENDERSTATE_COLORKEYENABLE, texture->Tex.UseChromakey());

            alpha_enable |= texture->Tex.HasAlpha();

            if (texture->Tex.DisableMipMaps() && tex_filter > agiTexFilter::Bilinear)
                tex_filter = agiTexFilter::Bilinear;
        }
        else
        {
            blend_op = agiBlendOp::Disable;
            EnableDraw = true;
        }

        agiLastState.Mtl = agiCurState.GetMtl();
        agiLastState.Texture = texture;
    }

    if (texture && Pipe()->SupportsAlpha())
        alpha_enable |= texture->Tex.HasAlpha();

    if (texture2)
    {
        alpha_enable = false;
        blend_op = agiBlendOp::One;
    }

    if (!agiEnableZBuffer)
    {
        agiCurState.SetZWrite(false);
        agiCurState.SetZEnable(false);
    }

    if (bool zwrite = agiCurState.GetZWrite(); zwrite != agiLastState.ZWrite)
    {
        d3d_set_render_state(D3DRENDERSTATE_ZWRITEENABLE, zwrite);

        agiLastState.ZWrite = zwrite;
    }

    if (agiCmpFunc zfunc = agiCurState.GetZEnable() ? agiCurState.GetZFunc() : agiCmpFunc::Always;
        zfunc != agiLastState.ZFunc)
    {
        DWORD d3d_zfunc = 0;

        switch (zfunc)
        {
            case agiCmpFunc::Never: d3d_zfunc = D3DCMP_NEVER; break;
            case agiCmpFunc::Less: d3d_zfunc = D3DCMP_LESS; break;
            case agiCmpFunc::Equal: d3d_zfunc = D3DCMP_EQUAL; break;
            case agiCmpFunc::LessEqual: d3d_zfunc = D3DCMP_LESSEQUAL; break;
            case agiCmpFunc::Greater: d3d_zfunc = D3DCMP_GREATER; break;
            case agiCmpFunc::Notequal: d3d_zfunc = D3DCMP_NOTEQUAL; break;
            case agiCmpFunc::GreaterEqual: d3d_zfunc = D3DCMP_GREATEREQUAL; break;
            case agiCmpFunc::Always: d3d_zfunc = D3DCMP_ALWAYS; break;
        }

        d3d_set_render_state(D3DRENDERSTATE_ZFUNC, d3d_zfunc);

        agiLastState.ZFunc = zfunc;
    }

    if (bool perspective = agiCurState.GetTexturePerspective(); perspective != agiLastState.TexturePerspective)
    {
        d3d_set_render_state(D3DRENDERSTATE_TEXTUREPERSPECTIVE, perspective);

        agiLastState.TexturePerspective = perspective;
    }

    if (bool specular = agiCurState.GetSpecularEnable(); specular != agiLastState.SpecularEnable)
    {
        d3d_set_render_state(D3DRENDERSTATE_SPECULARENABLE, specular);

        agiLastState.SpecularEnable = specular;
    }

    if (agiCullMode cull_mode = agiCurState.GetCullMode(); cull_mode != agiLastState.CullMode)
    {
        DWORD d3d_cull = 0;

        switch (cull_mode)
        {
            case agiCullMode::None: d3d_cull = D3DCULL_NONE; break;
            case agiCullMode::CW: d3d_cull = D3DCULL_CW; break;
            case agiCullMode::CCW: d3d_cull = D3DCULL_CCW; break;
        }

        d3d_set_render_state(D3DRENDERSTATE_CULLMODE, d3d_cull);

        agiLastState.CullMode = cull_mode;
    }

    if (tex_filter != agiLastState.TexFilter)
    {
        DWORD mag_filter = D3DTFG_LINEAR;
        DWORD min_filter = D3DTFN_LINEAR;
        DWORD mip_filter = D3DTFP_NONE;
        DWORD anisotropy = 0;

        if (tex_filter == agiTexFilter::Point)
        {
            mag_filter = D3DTFG_POINT;
            min_filter = D3DTFN_POINT;
        }
        else if (Pipe()->GetTextureFilter() & 0x4)
        {
            mag_filter = D3DTFG_ANISOTROPIC;
            min_filter = D3DTFN_ANISOTROPIC;
            anisotropy = 16;
        }
        else
        {
            mag_filter = D3DTFG_LINEAR;
            min_filter = D3DTFN_LINEAR;
        }

        if (tex_filter == agiTexFilter::Trilinear)
        {
            if (agiCurState.GetMaxTextures() == 1 && Pipe()->GetTextureFilter() & 0x2)
            {
                mip_filter = D3DTFP_LINEAR;
            }
            else if (Pipe()->GetTextureFilter() & 1)
            {
                mip_filter = D3DTFP_POINT;
            }
        }

        d3d_set_texture_stage_state(0, D3DTSS_MAGFILTER, mag_filter);
        d3d_set_texture_stage_state(0, D3DTSS_MINFILTER, min_filter);
        d3d_set_texture_stage_state(0, D3DTSS_MIPFILTER, mip_filter);
        d3d_set_texture_stage_state(0, D3DTSS_MAXANISOTROPY, anisotropy);

        if (agiCurState.GetMaxTextures() > 1)
        {
            d3d_set_texture_stage_state(1, D3DTSS_MAGFILTER, mag_filter);
            d3d_set_texture_stage_state(1, D3DTSS_MINFILTER, min_filter);
            d3d_set_texture_stage_state(1, D3DTSS_MIPFILTER, mip_filter);
            d3d_set_texture_stage_state(1, D3DTSS_MAXANISOTROPY, anisotropy);
        }

        agiLastState.TexFilter = tex_filter;
    }

    if (bool smooth_shading = agiCurState.GetSmoothShading(); smooth_shading != agiLastState.SmoothShading)
    {
        d3d_set_render_state(D3DRENDERSTATE_SHADEMODE, smooth_shading ? D3DSHADE_GOURAUD : D3DSHADE_FLAT);

        agiLastState.SmoothShading = smooth_shading;
    }

    if (u8 draw_mode = agiCurState.GetDrawMode(); draw_mode != agiLastState.DrawMode)
    {
        DWORD fill_mode = 0;

        switch (draw_mode & 0x3)
        {
            case 1: fill_mode = D3DFILL_POINT; break;
            case 2: fill_mode = D3DFILL_WIREFRAME; break;
            case 3: fill_mode = D3DFILL_SOLID; break;
        }

        d3d_set_render_state(D3DRENDERSTATE_FILLMODE, fill_mode);

        agiLastState.DrawMode = draw_mode;
    }

    if (u8 alpha_ref = agiCurState.GetAlphaRef(); alpha_ref != agiLastState.AlphaRef)
    {
        d3d_set_render_state(D3DRENDERSTATE_ALPHAREF, alpha_ref);

        agiLastState.AlphaRef = alpha_ref;
    }

    if (stage_changed || blend_op != agiLastState.BlendOp)
    {
        switch (blend_op)
        {
            case agiBlendOp::One: {
                d3d_set_texture_stage_state(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
                d3d_set_texture_stage_state(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
                d3d_set_texture_stage_state(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
                d3d_set_texture_stage_state(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);

                break;
            }

            case agiBlendOp::Modulate: {
                d3d_set_texture_stage_state(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
                d3d_set_texture_stage_state(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
                d3d_set_texture_stage_state(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
                d3d_set_texture_stage_state(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
                d3d_set_texture_stage_state(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
                d3d_set_texture_stage_state(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

                break;
            }

            case agiBlendOp::Disable: {
                d3d_set_texture_stage_state(0, D3DTSS_COLOROP, D3DTOP_DISABLE);

                DD_TRY(dev->SetTexture(0, nullptr));

                break;
            }
        }

        agiLastState.BlendOp = blend_op;
    }

    bool wrap_u = agiCurState.GetWrapU();
    bool wrap_v = agiCurState.GetWrapV();

    if (bool address = wrap_u && wrap_v; stage_changed || address != (agiLastState.WrapU && agiLastState.WrapV))
    {
        d3d_set_texture_stage_state(base_stage, D3DTSS_ADDRESS, address ? D3DTADDRESS_WRAP : D3DTADDRESS_CLAMP);
    }

    if (stage_changed || wrap_u != agiLastState.WrapU)
    {
        d3d_set_texture_stage_state(base_stage, D3DTSS_ADDRESSU, wrap_u ? D3DTADDRESS_WRAP : D3DTADDRESS_CLAMP);

        agiLastState.WrapU = wrap_u;
    }

    if (stage_changed || wrap_v != agiLastState.WrapV)
    {
        d3d_set_texture_stage_state(base_stage, D3DTSS_ADDRESSV, wrap_v ? D3DTADDRESS_WRAP : D3DTADDRESS_CLAMP);

        agiLastState.WrapV = wrap_v;
    }

    if (bool dither = agiCurState.GetDither(); dither != agiLastState.Dither)
    {
        d3d_set_render_state(D3DRENDERSTATE_DITHERENABLE, dither);

        agiLastState.Dither = dither;
    }

    if (f32 lod_bias = agiCurState.GetLodBias(); lod_bias != agiLastState.LodBias)
    {
        d3d_set_texture_stage_state(base_stage, D3DTSS_MIPMAPLODBIAS, mem::bit_cast<DWORD>(-lod_bias));

        agiLastState.LodBias = lod_bias;
    }

    if (alpha_enable != agiLastState.AlphaEnable)
    {
        d3d_set_render_state(D3DRENDERSTATE_ALPHATESTENABLE, alpha_enable);
        d3d_set_render_state(D3DRENDERSTATE_ALPHABLENDENABLE, alpha_enable);

        agiLastState.AlphaEnable = alpha_enable;
    }

    if (bool stippled_alpha = agiCurState.GetStippledAlpha(); stippled_alpha != agiLastState.StippledAlpha)
    {
        d3d_set_render_state(D3DRENDERSTATE_STIPPLEDALPHA, stippled_alpha);

        agiLastState.StippledAlpha = stippled_alpha;
    }

    if (agiBlendSet blend_set = agiCurState.GetBlendSet(); blend_set != agiLastState.BlendSet)
    {
        switch (blend_set)
        {
            case agiBlendSet::SrcAlpha_InvSrcAlpha: {
                d3d_set_render_state(D3DRENDERSTATE_SRCBLEND, D3DBLEND_SRCALPHA);
                d3d_set_render_state(D3DRENDERSTATE_DESTBLEND, D3DBLEND_INVSRCALPHA);

                break;
            }

            case agiBlendSet::SrcAlpha_One: {
                d3d_set_render_state(D3DRENDERSTATE_SRCBLEND, D3DBLEND_SRCALPHA);
                d3d_set_render_state(D3DRENDERSTATE_DESTBLEND, D3DBLEND_ONE);

                break;
            }

            case agiBlendSet::Zero_SrcAlpha: {
                d3d_set_render_state(D3DRENDERSTATE_SRCBLEND, D3DBLEND_ZERO);
                d3d_set_render_state(D3DRENDERSTATE_DESTBLEND, D3DBLEND_SRCALPHA);

                break;
            }

            case agiBlendSet::Zero_SrcColor: {
                d3d_set_render_state(D3DRENDERSTATE_SRCBLEND, D3DBLEND_ZERO);
                d3d_set_render_state(D3DRENDERSTATE_DESTBLEND, D3DBLEND_SRCCOLOR);

                break;
            }

            case agiBlendSet::One_One: {
                d3d_set_render_state(D3DRENDERSTATE_SRCBLEND, D3DBLEND_ONE);
                d3d_set_render_state(D3DRENDERSTATE_DESTBLEND, D3DBLEND_ONE);

                break;
            }
        }

        agiLastState.BlendSet = blend_set;
    }

    agiFogMode fog_mode = agiCurState.GetFogMode();
    f32 fog_start = agiCurState.GetFogStart();
    f32 fog_end = agiCurState.GetFogEnd();
    f32 fog_density = agiCurState.GetFogDensity();
    u32 fog_color = agiCurState.GetFogColor();

    if (fog_mode != agiLastState.FogMode || fog_start != agiLastState.FogStart || fog_end != agiLastState.FogEnd ||
        fog_density != agiLastState.FogDensity || fog_color != agiLastState.FogColor)
    {
        d3d_set_render_state(D3DRENDERSTATE_FOGENABLE, fog_mode != agiFogMode::None);
        d3d_set_render_state(
            D3DRENDERSTATE_FOGTABLEMODE, (fog_mode == agiFogMode::Pixel) ? D3DFOG_LINEAR : D3DFOG_NONE);
        agiLastState.FogMode = fog_mode;

        if (fog_mode == agiFogMode::Pixel)
        {
            const agiViewParameters& vp = GetActiveViewport()->GetParams();

            agiLastState.FogStart = fog_start;

            if (NormalizedFog)
                fog_start = (-fog_start * vp.ProjZZ + vp.ProjZW) / fog_start * 0.5f + 0.5f;

            d3d_set_render_state(D3DRENDERSTATE_FOGTABLESTART, mem::bit_cast<DWORD>(fog_start));

            agiLastState.FogEnd = fog_end;

            if (NormalizedFog)
                fog_end = (-fog_end * vp.ProjZZ + vp.ProjZW) / fog_end * 0.5f + 0.5f;

            d3d_set_render_state(D3DRENDERSTATE_FOGTABLEEND, mem::bit_cast<DWORD>(fog_end));

            agiLastState.FogDensity = fog_density;
            d3d_set_render_state(D3DRENDERSTATE_FOGTABLEDENSITY, mem::bit_cast<DWORD>(fog_density));
        }

        d3d_set_render_state(D3DRENDERSTATE_FOGCOLOR, fog_color);
        agiLastState.FogColor = fog_color;
    }

    agiCurState.ClearTouched();
}
