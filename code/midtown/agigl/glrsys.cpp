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

#include "glrsys.h"

#include "agi/error.h"
#include "agi/pipeline.h"
#include "agi/texdef.h"
#include "data7/utimer.h"
#include "eventq7/winevent.h"
#include "glerror.h"
#include "gltexdef.h"

#include <glad/glad.h>

static u32 CurrentPipeHeight = 0;
static b32 UseTriangles = 1; // PrimType
static agiScreenVtx* VtxBase = nullptr;
static i32 VtxCount = 0;
static i32 VtxIndexCount = 0;
static u16* VtxIndex = nullptr;
static u16 VtxIndices[1024] {};

void agiGLRasterizer::EndGfx()
{}

i32 agiGLRasterizer::BeginGfx()
{
    CurrentPipeHeight = Pipe()->GetHeight();

    return AGI_ERROR_SUCCESS;
}

void agiGLRasterizer::BeginGroup()
{
    FlushState();
}

void agiGLRasterizer::EndGroup()
{
    FlushState();
}

void agiGLRasterizer::Verts(agiVtxType type, agiVtx* vertices, i32 vertex_count)
{
    ArAssert(type == agiVtxType::Screen, "Invalid Vertex Type");

    if (VtxIndexCount || agiCurState.IsTouched())
        FlushState();

    VtxBase = reinterpret_cast<agiScreenVtx*>(vertices);
    VtxCount = vertex_count;
    VtxIndexCount = 0;
    VtxIndex = VtxIndices;
}

void agiGLRasterizer::Points(agiVtxType type, agiVtx* vertices, i32 vertex_count)
{
    unimplemented(type, vertices, vertex_count);
}

void agiGLRasterizer::SetVertCount(i32 vertex_count)
{
    VtxCount = vertex_count;
}

void agiGLRasterizer::Triangle(i32 i0, i32 i1, i32 i2)
{
    ++STATS.Tris;

    if (VtxIndexCount + 3 > static_cast<i32>(std::size(VtxIndices)) || (UseTriangles != 1) || agiCurState.IsTouched())
    {
        FlushState();
        UseTriangles = 1;
    }

    VtxIndex[VtxIndexCount + 0] = static_cast<u16>(i0);
    VtxIndex[VtxIndexCount + 1] = static_cast<u16>(i1);
    VtxIndex[VtxIndexCount + 2] = static_cast<u16>(i2);

    VtxIndexCount += 3;
}

void agiGLRasterizer::Line(i32 i0, i32 i1)
{
    ++STATS.Lines;

    // TODO: Should this be + 2 ?
    if (VtxIndexCount + 2 > static_cast<i32>(std::size(VtxIndices)) || (UseTriangles != 0) || agiCurState.IsTouched())
    {
        FlushState();
        UseTriangles = 0;
    }

    VtxIndex[VtxIndexCount + 0] = static_cast<u16>(i0);
    VtxIndex[VtxIndexCount + 1] = static_cast<u16>(i1);
    VtxIndexCount += 2;
}

void agiGLRasterizer::Card(i32 v0, i32 v1)
{
    unimplemented(v0, v1);
}

void agiGLRasterizer::Mesh(agiVtxType type, agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count)
{
    ArAssert(type == agiVtxType::Screen, "Invalid Vertex Type");

    agiGLRasterizer::FlushState();

    UseTriangles = 1;
    VtxBase = reinterpret_cast<agiScreenVtx*>(vertices);
    VtxCount = vertex_count;
    VtxIndex = indices;
    VtxIndexCount = index_count;

    agiGLRasterizer::FlushState();
}

i32 GetBlendFuncD()
{
    return GL_ONE_MINUS_SRC_ALPHA;
}

i32 GetBlendFuncS()
{
    return GL_SRC_ALPHA;
}

void agiGLRasterizer::FlushState()
{
    if (!(ActiveFlag & 0x1))
        return;

    PrintGlErrors();

    if (VtxIndexCount)
    {
        ARTS_TIMED(agiRasterization);

        glBegin(UseTriangles ? GL_TRIANGLES : GL_LINES);

        for (i32 i = 0; i < VtxIndexCount; ++i)
        {
            if (agiCurState.GetDrawMode() == 15)
            {
                glTexCoord4f(VtxBase[VtxIndex[i]].tu * VtxBase[VtxIndex[i]].w,
                    VtxBase[VtxIndex[i]].tv * VtxBase[VtxIndex[i]].w, 0.0, VtxBase[VtxIndex[i]].w);
            }

            // if (agiCurState.GetDrawMode() != 3)
            {
                glColor4ub(static_cast<GLubyte>(VtxBase[VtxIndex[i]].specular >> 16),
                    static_cast<GLubyte>(VtxBase[VtxIndex[i]].specular >> 8),
                    static_cast<GLubyte>(VtxBase[VtxIndex[i]].specular),
                    static_cast<GLubyte>(VtxBase[VtxIndex[i]].specular >> 24));
            }

            glVertex3f(
                VtxBase[VtxIndex[i]].x, CurrentPipeHeight - VtxBase[VtxIndex[i]].y, 1.0f - VtxBase[VtxIndex[i]].z);
        }

        glEnd();

        VtxIndexCount = 0;
    }

    PrintGlErrors();

    if (agiCurState.GetDrawMode() != 15)
        agiCurState.SetTexture(nullptr);

    if (!agiCurState.IsTouched())
        return;

    ARTS_TIMED(agiStateChanges);

    bool texture_changed = false;

    agiGLTexDef* texture = static_cast<agiGLTexDef*>(agiCurState.GetTexture());

    if (texture != agiLastState.Texture)
    {
        if (texture)
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, texture->GetHandle());
        }
        else
        {
            glDisable(GL_TEXTURE_2D);
        }

        agiLastState.Texture = texture;

        texture_changed = true;
    }

    if (bool zwrite = agiCurState.GetZWrite(); zwrite != agiLastState.ZWrite)
    {
        glDepthMask(zwrite);

        agiLastState.ZWrite = zwrite;
    }

    if (bool zenable = agiCurState.GetZEnable(); zenable != agiLastState.ZEnable)
    {
        if (zenable)
        {
            glEnable(GL_DEPTH_TEST);
        }
        else
        {
            glDisable(GL_DEPTH_TEST);
        }

        agiLastState.ZEnable = zenable;
    }

    if (agiCmpFunc zfunc = agiCurState.GetZEnable() ? agiCurState.GetZFunc() : agiCmpFunc::Always;
        zfunc != agiLastState.ZFunc)
    {
        GLenum gl_zfunc = 0;

        switch (zfunc)
        {
            case agiCmpFunc::Never: gl_zfunc = GL_NEVER; break;
            case agiCmpFunc::Less: gl_zfunc = GL_LESS; break;
            case agiCmpFunc::Equal: gl_zfunc = GL_EQUAL; break;
            case agiCmpFunc::LessEqual: gl_zfunc = GL_LEQUAL; break;
            case agiCmpFunc::Greater: gl_zfunc = GL_GREATER; break;
            case agiCmpFunc::Notequal: gl_zfunc = GL_NOTEQUAL; break;
            case agiCmpFunc::GreaterEqual: gl_zfunc = GL_GEQUAL; break;
            case agiCmpFunc::Always: gl_zfunc = GL_ALWAYS; break;
        }

        glDepthFunc(gl_zfunc);

        agiLastState.ZFunc = zfunc;
    }

    if (bool perspective = agiCurState.GetTexturePerspective(); perspective != agiLastState.TexturePerspective)
    {
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, perspective ? GL_NICEST : GL_FASTEST);

        agiLastState.TexturePerspective = perspective;
    }

    agiTexFilter tex_filter = agiCurState.GetTexFilter();

    if (texture && texture->Tex.DisableMipMaps() && tex_filter > agiTexFilter::Bilinear)
        tex_filter = agiTexFilter::Bilinear;

    if (texture_changed || tex_filter != agiLastState.TexFilter)
    {
        GLenum min_filter = GL_NEAREST;
        GLenum mag_filter = GL_NEAREST;

        switch (tex_filter)
        {
            case agiTexFilter::Trilinear: {
                min_filter = GL_LINEAR_MIPMAP_LINEAR;
                mag_filter = GL_LINEAR;

                break;
            }

            case agiTexFilter::Bilinear: {
                min_filter = GL_LINEAR;
                mag_filter = GL_LINEAR;

                break;
            }

            case agiTexFilter::Point: {
                min_filter = GL_NEAREST;
                mag_filter = GL_NEAREST;

                break;
            }
        }

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);

        agiLastState.TexFilter = tex_filter;
    }

    if (bool smooth_shading = agiCurState.GetSmoothShading(); smooth_shading != agiLastState.SmoothShading)
    {
        glShadeModel((smooth_shading || true) ? GL_SMOOTH : GL_FLAT);

        agiLastState.SmoothShading = smooth_shading;
    }

    if (u8 draw_mode = agiCurState.GetDrawMode(); draw_mode != agiLastState.DrawMode)
    {
        GLenum mode = GL_FILL;

        switch (draw_mode & 0x3)
        {
            case 1: mode = GL_POINT; break;
            case 2: mode = GL_LINE; break;
            case 3: mode = GL_FILL; break;
        }

        glPolygonMode(GL_FRONT_AND_BACK, mode);

        agiLastState.DrawMode = draw_mode;
    }

    bool alpha_mode = agiCurState.GetAlphaEnable();

    if (texture)
        alpha_mode |= (texture->Tex.Flags & agiTexParameters::Alpha);

    u8 alpha_ref = agiCurState.GetAlphaRef();

    if (alpha_mode != agiLastState.AlphaEnable || alpha_ref != agiLastState.AlphaRef)
    {
        if (alpha_mode)
        {
            glEnable(GL_ALPHA_TEST);
            glAlphaFunc(GL_GREATER, alpha_ref / 255.0f);
            glEnable(GL_BLEND);
        }
        else
        {
            glDisable(GL_ALPHA_TEST);
            glDisable(GL_BLEND);
        }

        agiLastState.AlphaEnable = alpha_mode;
        agiLastState.AlphaRef = alpha_ref;
    }

    if (agiBlendSet blend_set = agiCurState.GetBlendSet(); blend_set != agiLastState.BlendSet)
    {
        switch (blend_set)
        {
            case agiBlendSet::SrcAlpha_InvSrcAlpha: glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); break;
            case agiBlendSet::SrcAlpha_One: glBlendFunc(GL_SRC_ALPHA, GL_ONE); break;
            case agiBlendSet::Zero_SrcAlpha: glBlendFunc(GL_ZERO, GL_SRC_ALPHA); break;
            case agiBlendSet::Zero_SrcColor: glBlendFunc(GL_ZERO, GL_SRC_COLOR); break;
            case agiBlendSet::One_One: glBlendFunc(GL_ONE, GL_ONE); break;

            default: Quitf("bad blend mode"); break;
        }

        agiLastState.BlendSet = blend_set;
    }

    if (agiCullMode cull_mode = agiCurState.GetCullMode(); cull_mode != agiLastState.CullMode)
    {
        switch (cull_mode)
        {
            case agiCullMode::None: glDisable(GL_CULL_FACE); break;

            case agiCullMode::CW:
                glEnable(GL_CULL_FACE);
                glFrontFace(GL_CCW);
                break;

            case agiCullMode::CCW:
                glEnable(GL_CULL_FACE);
                glFrontFace(GL_CW);
                break;
        }

        agiLastState.CullMode = cull_mode;
    }

    if (agiBlendOp blend_op = agiCurState.GetBlendOp(); blend_op != agiLastState.BlendOp)
    {
        switch (blend_op)
        {
            case agiBlendOp::One: glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); break;
            case agiBlendOp::Modulate: glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); break;
        }

        agiLastState.BlendOp = blend_op;
    }

    // TODO: Fog

    agiCurState.ClearTouched();

    PrintGlErrors();
}
