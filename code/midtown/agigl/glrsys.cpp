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

static GLenum DrawMode = 0;

static u32 VtxIndexCount = 0;
static u16* VtxIndex = nullptr;
static u16 VtxIndices[1024] {};

void agiGLRasterizer::EndGfx()
{
    glDeleteBuffers(1, &vbo_);
#ifdef ARTS_GL_USE_INDEX_BUFFER
    glDeleteBuffers(1, &ibo_);
#endif

    if (glDeleteVertexArrays)
    {
        glDeleteVertexArrays(1, &vao_);
    }

    glDeleteProgram(shader_);
    glDeleteTextures(1, &white_texture_);
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
    Quitf("Failed to compile shader: %s", log_text);
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
    Quitf("Failed to compile shader: %s", log_text);
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
    glGenBuffers(1, &vbo_);

#ifdef ARTS_GL_USE_INDEX_BUFFER
    glGenBuffers(1, &ibo_);
#endif

    if (glGenVertexArrays)
    {
        glGenVertexArrays(1, &vao_);
        glBindVertexArray(vao_);
    }
    else
    {
        Displayf("OpenGL VAO not supported");
    }

    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, 0xFFFF * sizeof(agiScreenVtx), nullptr, GL_DYNAMIC_DRAW);

#ifdef ARTS_GL_USE_INDEX_BUFFER
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 0xFFFF * sizeof(u16), nullptr, GL_DYNAMIC_DRAW);
#endif

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
    out_Color = texture2D(u_Texture, frag_UV.xy / frag_UV.z) * frag_Color;

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

    f32 transform[4][4];

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

    SetVertices(vertices, vertex_count);

    VtxIndexCount = 0;
    VtxIndex = VtxIndices;
}

void agiGLRasterizer::Points(agiVtxType type, agiVtx* vertices, i32 vertex_count)
{
    unimplemented(type, vertices, vertex_count);
}

void agiGLRasterizer::SetVertCount([[maybe_unused]] i32 vertex_count)
{}

void agiGLRasterizer::Triangle(i32 i0, i32 i1, i32 i2)
{
    ++STATS.Tris;

    if (VtxIndexCount + 3 > std::size(VtxIndices) || (DrawMode != GL_TRIANGLES) || agiCurState.IsTouched())
    {
        FlushState();
        DrawMode = GL_TRIANGLES;
    }

    VtxIndex[VtxIndexCount + 0] = static_cast<u16>(i0);
    VtxIndex[VtxIndexCount + 1] = static_cast<u16>(i1);
    VtxIndex[VtxIndexCount + 2] = static_cast<u16>(i2);

    VtxIndexCount += 3;
}

void agiGLRasterizer::Line(i32 i0, i32 i1)
{
    ++STATS.Lines;

    if (VtxIndexCount + 2 > std::size(VtxIndices) || (DrawMode != GL_LINES) || agiCurState.IsTouched())
    {
        FlushState();
        DrawMode = GL_LINES;
    }

    VtxIndex[VtxIndexCount + 0] = static_cast<u16>(i0);
    VtxIndex[VtxIndexCount + 1] = static_cast<u16>(i1);
    VtxIndexCount += 2;
}

void agiGLRasterizer::Card(i32, i32)
{
    ++STATS.Cards;
}

void agiGLRasterizer::Mesh(agiVtxType type, agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count)
{
    ArAssert(type == agiVtxType::Screen, "Invalid Vertex Type");

    STATS.Tris += static_cast<i32>(index_count / 3.0f);

    agiGLRasterizer::FlushState();

    DrawMode = GL_TRIANGLES;

    SetVertices(vertices, vertex_count);
    Draw(indices, index_count);
}

void agiGLRasterizer::FlushState()
{
    if (!(ActiveFlag & 0x1))
        return;

    if (VtxIndexCount)
    {
        Draw(VtxIndex, VtxIndexCount);

        VtxIndexCount = 0;
    }

    if (agiCurState.GetDrawMode() != 15)
        agiCurState.SetTexture(nullptr);

    if (!agiCurState.IsTouched())
        return;

    ARTS_TIMED(agiStateChanges);
    ++STATS.StateChanges;

    bool texture_changed = false;

    agiGLTexDef* texture = static_cast<agiGLTexDef*>(agiCurState.GetTexture());

    if (texture != agiLastState.Texture)
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture ? texture->GetHandle() : white_texture_);

        agiLastState.Texture = texture;

        ++STATS.TextureChanges;

        if (texture)
            STATS.TxlsXrfd += texture->SurfaceSize;

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
        // glHint(GL_PERSPECTIVE_CORRECTION_HINT, perspective ? GL_NICEST : GL_FASTEST);

        agiLastState.TexturePerspective = perspective;
    }

    if (texture)
    {
        agiTexFilter tex_filter = agiCurState.GetTexFilter();

        if (texture->Tex.DisableMipMaps() && tex_filter > agiTexFilter::Bilinear)
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
    }

    if (bool smooth_shading = agiCurState.GetSmoothShading(); smooth_shading != agiLastState.SmoothShading)
    {
        // glShadeModel((smooth_shading || true) ? GL_SMOOTH : GL_FLAT);

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
    u8 alpha_ref = agiCurState.GetAlphaRef();

    if (texture)
        alpha_mode |= (texture->Tex.Flags & agiTexParameters::Alpha);

    if (alpha_mode != agiLastState.AlphaEnable || alpha_ref != agiLastState.AlphaRef)
    {
        if (alpha_mode)
        {
            glUniform1f(uniform_alpha_ref_, alpha_ref / 255.0f);
            glEnable(GL_BLEND);
        }
        else
        {
            glUniform1f(uniform_alpha_ref_, -1.0f);
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
        //switch (blend_op)
        //{
        //    case agiBlendOp::One: glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); break;
        //    case agiBlendOp::Modulate: glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); break;
        //}

        agiLastState.BlendOp = blend_op;
    }

    // TODO: Support pixel fog?

    agiFogMode fog_mode = agiCurState.GetFogMode();
    u32 fog_color = agiCurState.GetFogColor();

    if (fog_mode != agiLastState.FogMode || fog_color != agiLastState.FogColor)
    {
        glUniform4f(uniform_fog_, ((fog_color >> 16) & 0xFF) / 255.0f, ((fog_color >> 8) & 0xFF) / 255.0f,
            (fog_color & 0xFF) / 255.0f, (fog_mode == agiFogMode::Vertex) ? 1.0f : 0.0f);

        agiLastState.FogMode = fog_mode;
        agiLastState.FogColor = fog_color;
    }

    agiLastState.FogStart = agiCurState.GetFogStart();
    agiLastState.FogEnd = agiCurState.GetFogEnd();
    agiLastState.FogDensity = agiCurState.GetFogDensity();

    agiCurState.ClearTouched();
}

void agiGLRasterizer::SetVertices(agiVtx* vertices, i32 vertex_count)
{
    ARTS_TIMED(agiRasterization);

    glBufferSubData(GL_ARRAY_BUFFER, 0, vertex_count * sizeof(agiScreenVtx), vertices);

#ifdef ARTS_GL_USE_DRAW_RANGE
    vertex_count_ = vertex_count;
#endif
}

void agiGLRasterizer::Draw(u16* indices, i32 index_count)
{
    ARTS_TIMED(agiRasterization);

    ++STATS.GeomCalls;

#ifdef ARTS_GL_USE_INDEX_BUFFER
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, index_count * sizeof(u16), indices);
#endif

#ifdef ARTS_GL_USE_DRAW_RANGE
    glDrawRangeElements
#else
    glDrawElements
#endif
        (DrawMode,
#ifdef ARTS_GL_USE_DRAW_RANGE
            0, vertex_count_,
#endif
            index_count, GL_UNSIGNED_SHORT,
#ifdef ARTS_GL_USE_INDEX_BUFFER
            0
#else
            indices
#endif
        );
}
