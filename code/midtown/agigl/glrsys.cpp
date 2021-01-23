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

static u32 ImmDrawMode = 0;

static agiVtx* ImmVtxBase = nullptr;
static u32 ImmVtxCount = 0;

static u16 ImmIdxBuffer[4096];
static u32 ImmIdxCount = 0;

void agiGLRasterizer::EndGfx()
{
    glDeleteBuffers(1, &vbo_);
    vbo_ = 0;

#ifdef ARTS_GL_USE_INDEX_BUFFER
    glDeleteBuffers(1, &ibo_);
    ibo_ = 0;
#endif

    if (vao_ != 0)
    {
        glDeleteVertexArrays(1, &vao_);
        vao_ = 0;
    }

    glDeleteProgram(shader_);
    shader_ = 0;

    glDeleteTextures(1, &white_texture_);
    white_texture_ = 0;
}

static void CheckShader(u32 shader)
{
    GLint is_compiled = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &is_compiled);

    if (is_compiled)
        return;

    PrintGlErrors();

    GLint log_length = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);

    char* log_text = new char[log_length];
    glGetShaderInfoLog(shader, log_length, &log_length, log_text);
    Quitf("Failed to compile shader:\n%s", log_text);
}

static void CheckProgram(u32 program)
{
    GLint is_compiled = GL_FALSE;
    glGetProgramiv(program, GL_LINK_STATUS, &is_compiled);

    if (is_compiled)
        return;

    PrintGlErrors();

    GLint log_length = 0;
    glGetShaderiv(program, GL_INFO_LOG_LENGTH, &log_length);

    char* log_text = new char[log_length];
    glGetProgramInfoLog(program, log_length, &log_length, log_text);
    Quitf("Failed to link program:\n%s", log_text);
}

static u32 CompileShader(u32 type, const char* src)
{
    u32 shader = glCreateShader(type);

    glShaderSource(shader, 1, &src, 0);
    glCompileShader(shader);

    CheckShader(shader);

    return shader;
}

i32 agiGLRasterizer::BeginGfx()
{
    if (Pipe()->HasExtension("GL_ARB_vertex_array_object"))
    {
        glGenVertexArrays(1, &vao_);
        glBindVertexArray(vao_);
    }
    else
    {
        Displayf("OpenGL VAO not supported");
    }

    glGenBuffers(1, &vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, 0xFFFF * sizeof(agiScreenVtx), nullptr, GL_STREAM_DRAW);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(agiScreenVtx),
        reinterpret_cast<const GLvoid*>(static_cast<GLintptr>(0x0))); // xyzw
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, GL_BGRA, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(agiScreenVtx),
        reinterpret_cast<const GLvoid*>(static_cast<GLintptr>(0x10))); // color
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, GL_BGRA, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(agiScreenVtx),
        reinterpret_cast<const GLvoid*>(static_cast<GLintptr>(0x14))); // specular
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(agiScreenVtx),
        reinterpret_cast<const GLvoid*>(static_cast<GLintptr>(0x18))); // uv
    glEnableVertexAttribArray(3);

#ifdef ARTS_GL_USE_INDEX_BUFFER
    glGenBuffers(1, &ibo_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 0xFFFF * sizeof(u16), nullptr, GL_STREAM_DRAW);
#endif

    u32 vs = CompileShader(GL_VERTEX_SHADER, R"(
#version 130

in vec4 in_Position;
in vec4 in_Color;
in vec4 in_Specular;
in vec2 in_UV;

out vec4 frag_Color;
out vec4 frag_Specular;
out vec3 frag_UV;

uniform mat4 u_Transform;

void main()
{
    gl_Position = u_Transform * vec4(in_Position.x, in_Position.y, 1.0 - in_Position.z, 1.0);
    frag_Color = in_Color;
    frag_Specular = in_Specular;
    frag_UV = vec3(in_UV * in_Position.w, in_Position.w);
}
)");

    u32 fs = CompileShader(GL_FRAGMENT_SHADER, R"(
#version 130

in vec4 frag_Color;
in vec4 frag_Specular;
in vec3 frag_UV;

out vec4 out_Color;

uniform sampler2D u_Texture;
uniform float u_AlphaRef;
uniform vec4 u_Fog;

void main()
{
    out_Color = texture(u_Texture, frag_UV.xy / frag_UV.z) * frag_Color;

    if (out_Color.a <= u_AlphaRef)
        discard;

    out_Color.xyz = mix(out_Color.xyz, u_Fog.xyz, (1.0 - frag_Specular.w) * u_Fog.w);
}
)");

    shader_ = glCreateProgram();

    glAttachShader(shader_, vs);
    glAttachShader(shader_, fs);

    glBindAttribLocation(shader_, 0, "in_Position");
    glBindAttribLocation(shader_, 1, "in_Color");
    glBindAttribLocation(shader_, 2, "in_Specular");
    glBindAttribLocation(shader_, 3, "in_UV");

    glLinkProgram(shader_);

    CheckProgram(shader_);

    glDetachShader(shader_, vs);
    glDetachShader(shader_, fs);

    glDeleteShader(vs);
    glDeleteShader(fs);

    glUseProgram(shader_);

    glUniform1i(glGetUniformLocation(shader_, "u_Texture"), 0);

    uniform_alpha_ref_ = glGetUniformLocation(shader_, "u_AlphaRef");
    glUniform1f(uniform_alpha_ref_, 0.0f);

    uniform_fog_ = glGetUniformLocation(shader_, "u_Fog");
    glUniform4f(uniform_fog_, 1.0f, 1.0f, 1.0f, 0.0f);

    f32 left = 0.0f;
    f32 right = static_cast<f32>(Pipe()->GetWidth());

    f32 top = 0.0f;
    f32 bottom = static_cast<f32>(Pipe()->GetHeight());

    f32 z_near = -1.0f;
    f32 z_far = 1.0f;

    GLfloat transform[4][4];

    transform[0][0] = 2.0f / (right - left);
    transform[0][1] = 0.0f;
    transform[0][2] = 0.0f;
    transform[0][3] = 0.0f;

    transform[1][0] = 0.0f;
    transform[1][1] = 2.0f / (top - bottom);
    transform[1][2] = 0.0f;
    transform[1][3] = 0.0f;

    transform[2][0] = 0.0f;
    transform[2][1] = 0.0f;
    transform[2][2] = -2.0f / (z_far - z_near);
    transform[2][3] = 0.0f;

    transform[3][0] = -(right + left) / (right - left);
    transform[3][1] = -(top + bottom) / (top - bottom);
    transform[3][2] = -(z_far + z_near) / (z_far - z_near);
    transform[3][3] = 1.0f;

    glUniformMatrix4fv(glGetUniformLocation(shader_, "u_Transform"), 1, GL_FALSE, (const GLfloat*) &transform);

    glGenTextures(1, &white_texture_);
    glBindTexture(GL_TEXTURE_2D, white_texture_);

    u32 white = 0xFFFFFFFF;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, &white);

    PrintGlErrors();

    return AGI_ERROR_SUCCESS;
}

void agiGLRasterizer::BeginGroup()
{}

void agiGLRasterizer::EndGroup()
{
    ImmDraw();
    ImmVtxBase = nullptr;
    ImmVtxCount = 0;
}

void agiGLRasterizer::Verts(agiVtxType type, agiVtx* vertices, i32 vertex_count)
{
    ArAssert(type == agiVtxType::Screen, "Invalid Vertex Type");

    ImmVtxBase = vertices;
    ImmVtxCount = vertex_count;
}

void agiGLRasterizer::Points(agiVtxType type, agiVtx* vertices, i32 vertex_count)
{
    unimplemented(type, vertices, vertex_count);
}

void agiGLRasterizer::SetVertCount(i32 vertex_count)
{
    ImmVtxCount = vertex_count;
}

void agiGLRasterizer::Triangle(i32 i0, i32 i1, i32 i2)
{
    ++STATS.Tris;

    u16* indices = ImmAddIndices(GL_TRIANGLES, 3);
    indices[0] = static_cast<u16>(i0);
    indices[1] = static_cast<u16>(i1);
    indices[2] = static_cast<u16>(i2);
}

void agiGLRasterizer::Line(i32 i0, i32 i1)
{
    ++STATS.Lines;

    u16* indices = ImmAddIndices(GL_LINES, 2);
    indices[0] = static_cast<u16>(i0);
    indices[1] = static_cast<u16>(i1);
}

u16* agiGLRasterizer::ImmAddIndices(u32 draw_mode, u16 count)
{
    if ((draw_mode != ImmDrawMode) || (ImmIdxCount + count > ARTS_SIZE(ImmIdxBuffer)))
    {
        FlushState();

        ImmDrawMode = draw_mode;
    }

    u16* result = &ImmIdxBuffer[ImmIdxCount];
    ImmIdxCount += count;
    return result;
}

void agiGLRasterizer::ImmDraw()
{
    if (ImmVtxCount && ImmIdxCount)
        DrawMesh(ImmDrawMode, ImmVtxBase, ImmVtxCount, ImmIdxBuffer, std::exchange(ImmIdxCount, 0));
}

void agiGLRasterizer::Card(i32, i32)
{
    ++STATS.Cards;
}

void agiGLRasterizer::Mesh(agiVtxType type, agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count)
{
    ArAssert(type == agiVtxType::Screen, "Invalid Vertex Type");

    STATS.Tris += static_cast<i32>(index_count / 3.0f);

    DrawMesh(GL_TRIANGLES, vertices, vertex_count, indices, index_count);
}

void agiGLRasterizer::FlushState()
{
    FlushAgiState();
    FlushGlState();
}

void agiGLRasterizer::FlushAgiState()
{
    if (agiCurState.GetDrawMode() != 15)
        agiCurState.SetTexture(nullptr);

    if (!agiCurState.IsTouched())
        return;

    agiGLTexDef* texture = static_cast<agiGLTexDef*>(agiCurState.GetTexture());

    if (texture != agiLastState.Texture)
    {
        agiLastState.Texture = texture;

        if (u32 handle = texture ? texture->GetHandle() : white_texture_; handle != state_.Texture)
        {
            state_.Texture = handle;

            ++STATS.TextureChanges;

            if (texture)
                STATS.TxlsXrfd += texture->SurfaceSize;

            if (texture && state_.Texture)
            {
                agiTexFilter tex_filter = agiCurState.GetTexFilter();

                if (texture->Tex.DisableMipMaps() && tex_filter > agiTexFilter::Bilinear)
                    tex_filter = agiTexFilter::Bilinear;

                if (tex_filter != agiLastState.TexFilter)
                {
                    agiLastState.TexFilter = tex_filter;

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

                    state_.MinFilter = min_filter;
                    state_.MagFilter = mag_filter;
                }
            }
        }
    }

#define SET_GL_STATE(NAME, VALUE) state_.Set(state_.NAME, VALUE, state_.Touched_##NAME)

    if (bool zwrite = agiCurState.GetZWrite(); zwrite != agiLastState.ZWrite)
    {
        agiLastState.ZWrite = zwrite;

        SET_GL_STATE(DepthMask, zwrite);
    }

    if (bool zenable = agiCurState.GetZEnable(); zenable != agiLastState.ZEnable)
    {
        agiLastState.ZEnable = zenable;

        SET_GL_STATE(DepthTest, zenable);
    }

    if (agiCmpFunc zfunc = agiCurState.GetZEnable() ? agiCurState.GetZFunc() : agiCmpFunc::Always;
        zfunc != agiLastState.ZFunc)
    {
        agiLastState.ZFunc = zfunc;

        GLenum depth_func = 0;

        switch (zfunc)
        {
            case agiCmpFunc::Never: depth_func = GL_NEVER; break;
            case agiCmpFunc::Less: depth_func = GL_LESS; break;
            case agiCmpFunc::Equal: depth_func = GL_EQUAL; break;
            case agiCmpFunc::LessEqual: depth_func = GL_LEQUAL; break;
            case agiCmpFunc::Greater: depth_func = GL_GREATER; break;
            case agiCmpFunc::Notequal: depth_func = GL_NOTEQUAL; break;
            case agiCmpFunc::GreaterEqual: depth_func = GL_GEQUAL; break;
            case agiCmpFunc::Always: depth_func = GL_ALWAYS; break;
        }

        SET_GL_STATE(DepthFunc, depth_func);
    }

    agiLastState.TexturePerspective = agiCurState.GetTexturePerspective();
    agiLastState.SmoothShading = agiCurState.GetSmoothShading();

    if (u8 draw_mode = agiCurState.GetDrawMode(); draw_mode != agiLastState.DrawMode)
    {
        agiLastState.DrawMode = draw_mode;

        GLenum poly_mode = GL_FILL;

        switch (draw_mode & 0x3)
        {
            case 1: poly_mode = GL_POINT; break;
            case 2: poly_mode = GL_LINE; break;
            case 3: poly_mode = GL_FILL; break;
        }

        SET_GL_STATE(PolygonMode, poly_mode);
    }

    bool alpha_mode = agiCurState.GetAlphaEnable();
    u8 alpha_ref = agiCurState.GetAlphaRef();

#if 1
    alpha_mode = true;
#else
    if (texture)
        alpha_mode |= (texture->Tex.Flags & agiTexParameters::Alpha);
#endif

    if (alpha_mode != agiLastState.AlphaEnable || alpha_ref != agiLastState.AlphaRef)
    {
        agiLastState.AlphaEnable = alpha_mode;
        agiLastState.AlphaRef = alpha_ref;

        SET_GL_STATE(Blend, alpha_mode);
        SET_GL_STATE(AlphaRef, alpha_mode ? (alpha_ref / 255.0f) : 0.0f);
    }

    if (agiBlendSet blend_set = agiCurState.GetBlendSet(); blend_set != agiLastState.BlendSet)
    {
        agiLastState.BlendSet = blend_set;

        u32 blend_s = 0;
        u32 blend_d = 0;

        switch (blend_set)
        {
            case agiBlendSet::SrcAlpha_InvSrcAlpha:
                blend_s = GL_SRC_ALPHA;
                blend_d = GL_ONE_MINUS_SRC_ALPHA;
                break;

            case agiBlendSet::SrcAlpha_One:
                blend_s = GL_SRC_ALPHA;
                blend_d = GL_ONE;
                break;

            case agiBlendSet::Zero_SrcAlpha:
                blend_s = GL_ZERO;
                blend_d = GL_SRC_ALPHA;
                break;

            case agiBlendSet::Zero_SrcColor:
                blend_s = GL_ZERO;
                blend_d = GL_SRC_COLOR;
                break;

            case agiBlendSet::One_One:
                blend_s = GL_ONE;
                blend_d = GL_ONE;
                break;

            default: Quitf("bad blend mode"); break;
        }

        if (blend_s != state_.BlendFuncS || blend_d != state_.BlendFuncD)
        {
            state_.BlendFuncS = blend_s;
            state_.BlendFuncD = blend_d;
            state_.Touched |= State::Touched_BlendFunc;
        }
    }

    if (agiCullMode cull_mode = agiCurState.GetCullMode(); cull_mode != agiLastState.CullMode)
    {
        agiLastState.CullMode = cull_mode;

        u32 front_face = 0;

        switch (cull_mode)
        {
            case agiCullMode::None: front_face = 0; break;
            case agiCullMode::CW: front_face = GL_CCW; break;
            case agiCullMode::CCW: front_face = GL_CW; break;
        }

        SET_GL_STATE(CullFace, front_face != 0);

        if (front_face != 0)
            SET_GL_STATE(FrontFace, front_face);
    }

    if (agiBlendOp blend_op = agiCurState.GetBlendOp(); blend_op != agiLastState.BlendOp)
    {
        agiLastState.BlendOp = blend_op;

        //switch (blend_op)
        //{
        //    case agiBlendOp::One: glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); break;
        //    case agiBlendOp::Modulate: glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); break;
        //}
    }

    // TODO: Support pixel fog?

    agiFogMode fog_mode = agiCurState.GetFogMode();
    u32 fog_color = agiCurState.GetFogColor();

    if (fog_mode != agiLastState.FogMode || fog_color != agiLastState.FogColor)
    {
        agiLastState.FogMode = fog_mode;
        agiLastState.FogColor = fog_color;

        Vector4 fog {
            ((fog_color >> 16) & 0xFF) / 255.0f,
            ((fog_color >> 8) & 0xFF) / 255.0f,
            (fog_color & 0xFF) / 255.0f,
            (fog_mode == agiFogMode::Vertex) ? 1.0f : 0.0f,
        };

        SET_GL_STATE(Fog, fog);
    }

    agiLastState.FogStart = agiCurState.GetFogStart();
    agiLastState.FogEnd = agiCurState.GetFogEnd();
    agiLastState.FogDensity = agiCurState.GetFogDensity();

    agiCurState.ClearTouched();
}

void agiGLRasterizer::FlushGlState()
{
    if (state_.Touched == 0)
        return;

    ARTS_TIMED(agiStateChanges);
    ++STATS.StateChanges;

    if (state_.Touched & (State::Touched_DepthMask | State::Touched_DepthTest | State::Touched_DepthFunc))
    {
        if (state_.Touched & State::Touched_DepthMask)
            glDepthMask(state_.DepthMask);

        if (state_.Touched & State::Touched_DepthTest)
            (state_.DepthTest ? glEnable : glDisable)(GL_DEPTH_TEST);

        if (state_.Touched & State::Touched_DepthFunc)
            glDepthFunc(state_.DepthFunc);
    }

    if (state_.Touched & State::Touched_PolygonMode)
        glPolygonMode(GL_FRONT_AND_BACK, state_.PolygonMode);

    if (state_.Touched & State::Touched_Fog)
        glUniform4f(uniform_fog_, state_.Fog.x, state_.Fog.y, state_.Fog.z, state_.Fog.w);

    if (state_.Touched & (State::Touched_Blend | State::Touched_AlphaRef | State::Touched_BlendFunc))
    {
        if (state_.Touched & State::Touched_Blend)
            (state_.Blend ? glEnable : glDisable)(GL_BLEND);

        if (state_.Touched & State::Touched_AlphaRef)
            glUniform1f(uniform_alpha_ref_, state_.AlphaRef);

        if (state_.Touched & State::Touched_BlendFunc)
            glBlendFunc(state_.BlendFuncS, state_.BlendFuncD);
    }

    if (state_.Touched & (State::Touched_CullFace | State::Touched_FrontFace))
    {
        if (state_.Touched & State::Touched_CullFace)
            (state_.CullFace ? glEnable : glDisable)(GL_CULL_FACE);

        if (state_.Touched & State::Touched_FrontFace)
            glFrontFace(state_.FrontFace);
    }

    state_.Touched = 0;
}

void agiGLRasterizer::DrawMesh(u32 draw_mode, agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count)
{
    if (!(ActiveFlag & 0x1) || (vertex_count == 0) || (index_count == 0))
        return;

    FlushState();

    if (state_.Texture == 0)
        return;

    ARTS_TIMED(agiRasterization);
    ++STATS.GeomCalls;

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, state_.Texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, state_.MinFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, state_.MagFilter);

    glBufferData(GL_ARRAY_BUFFER, vertex_count * sizeof(agiScreenVtx), vertices, GL_STREAM_DRAW);

#ifdef ARTS_GL_USE_INDEX_BUFFER
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_count * sizeof(u16), indices, GL_STREAM_DRAW);
#endif

#ifdef ARTS_GL_USE_DRAW_RANGE
    glDrawRangeElements
#else
    glDrawElements
#endif
        (draw_mode,
#ifdef ARTS_GL_USE_DRAW_RANGE
            0, vertex_count,
#endif
            index_count, GL_UNSIGNED_SHORT,
#ifdef ARTS_GL_USE_INDEX_BUFFER
            0
#else
            indices
#endif
        );
}