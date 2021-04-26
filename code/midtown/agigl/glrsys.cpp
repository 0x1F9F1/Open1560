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
#include "pcwindis/setupdata.h"

#include "glerror.h"
#include "glstream.h"
#include "gltexdef.h"

#include <glad/glad.h>

static u32 ImmPrimType = 0;

static agiVtx* ImmVtxBase = nullptr;
static u32 ImmVtxCount = 0;

alignas(16) static u16 ImmIdxBuffer[4096];
static u32 ImmIdxCount = 0;

void agiGLRasterizer::EndGfx()
{
    vbo_ = nullptr;
    ibo_ = nullptr;

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

agiGLRasterizer::agiGLRasterizer(class agiPipeline* pipe)
    : agiRasterizer(pipe)
{}

agiGLRasterizer::~agiGLRasterizer() = default;

static mem::cmd_param PARAM_glstream {"glstream"};
static mem::cmd_param PARAM_gllinewidth {"gllinewidth"};

enum class agiGLAttribType
{
    Float2,
    Float4,
    BGRA,
};

struct agiGLVertexAttrib
{
    u32 Index;
    agiGLAttribType Type;
    const char* Name;
    usize Offset;
    usize Stride;
};

// clang-format off
static const agiGLVertexAttrib agiScreenVtx_Attribs[] {
    {0, agiGLAttribType::Float4, "in_Position", offsetof(agiScreenVtx, x),        sizeof(agiScreenVtx)},
    {1, agiGLAttribType::BGRA,   "in_Color",    offsetof(agiScreenVtx, color),    sizeof(agiScreenVtx)},
    {2, agiGLAttribType::BGRA,   "in_Specular", offsetof(agiScreenVtx, specular), sizeof(agiScreenVtx)},
    {3, agiGLAttribType::Float2, "in_UV",       offsetof(agiScreenVtx, tu),       sizeof(agiScreenVtx)},
};

static const agiGLVertexAttrib agiScreenVtx2_Attribs[] {
    {0, agiGLAttribType::Float4, "in_Position", offsetof(agiScreenVtx2, x),        sizeof(agiScreenVtx2)},
    {1, agiGLAttribType::BGRA,   "in_Color",    offsetof(agiScreenVtx2, color),    sizeof(agiScreenVtx2)},
    {2, agiGLAttribType::BGRA,   "in_Specular", offsetof(agiScreenVtx2, specular), sizeof(agiScreenVtx2)},
    {3, agiGLAttribType::Float2, "in_UV1",      offsetof(agiScreenVtx2, tu1),      sizeof(agiScreenVtx2)},
    {4, agiGLAttribType::Float2, "in_UV2",      offsetof(agiScreenVtx2, tu2),      sizeof(agiScreenVtx2)},
};
// clang-format on

static void BindVertexAttribs(const agiGLVertexAttrib* attribs, usize count, const void* pointer)
{
    for (usize i = 0; i < count; ++i)
    {
        const agiGLVertexAttrib& attrib = attribs[i];

        GLint size = 0;
        GLenum type = 0;
        GLboolean normalized = GL_FALSE;

        switch (attrib.Type)
        {
            case agiGLAttribType::Float2:
                size = 2;
                type = GL_FLOAT;
                break;

            case agiGLAttribType::Float4:
                size = 4;
                type = GL_FLOAT;
                break;

            case agiGLAttribType::BGRA:
                size = GL_BGRA;
                type = GL_UNSIGNED_BYTE;
                normalized = GL_TRUE;
                break;

            default: Abortf("Invalid Vertex Attrib Type");
        }

        glVertexAttribPointer(attrib.Index, size, type, normalized, static_cast<GLsizei>(attrib.Stride),
            static_cast<const unsigned char*>(pointer) + attrib.Offset);
        glEnableVertexAttribArray(attrib.Index);
    }
}

i32 agiGLRasterizer::BeginGfx()
{
    PrintGlErrors();

    enum class DrawMode : i32
    {
        DrawRange = 0,     // glDrawRangeElements
        DrawRangeBase = 1, // glDrawRangeElementsBaseVertex

        // DrawIndirect = 2,      // glDrawElementsInstancedBaseVertexBaseInstance
        // MultiDrawIndirect = 3, // glMultiDrawElementsIndirect
    };

    enum class StreamMode : i32
    {
        BufferData = 0,
        BufferSubData = 1,

        MapRange = 2,

        MapPersistent = 3,
        MapCoherent = 4,

        AmdPinned = 5,

        MapUnsafe = 6,

        ClientSide = 7,
    };

    DrawMode draw_mode = DrawMode::DrawRange;
    StreamMode stream_mode = StreamMode::BufferData;

    if (Pipe()->HasExtension("GL_ARB_draw_elements_base_vertex"))
    {
        draw_mode = DrawMode::DrawRangeBase;
    }

    if ((draw_mode != DrawMode::DrawRange) && Pipe()->HasExtension("GL_ARB_sync"))
    {
        if (Pipe()->HasExtension("GL_AMD_pinned_memory"))
        {
            stream_mode = StreamMode::AmdPinned;
        }
        else if (Pipe()->HasExtension("GL_ARB_map_buffer_range"))
        {
            stream_mode =
                Pipe()->HasExtension("GL_ARB_buffer_storage") ? StreamMode::MapCoherent : StreamMode::MapRange;
        }
    }

    const char* gl_version = (const char*) glGetString(GL_VERSION);

    if (i32 mode = 0; PARAM_glstream.get(mode))
        stream_mode = static_cast<StreamMode>(mode);
    else if ((stream_mode == StreamMode::MapRange) && !std::strstr(gl_version, "Mesa"))
        stream_mode =
            StreamMode::BufferSubData; // Mesa seems to get a mid-large perf boost, others seem slightly slower

    Displayf("OpenGL: Using buffer stream mode %i", stream_mode);

    u32 stream_vertex_count = 0x40000;

    switch (stream_mode)
    {
        case StreamMode::BufferData:
        case StreamMode::BufferSubData: {
            // OpenGL 3.3 removes client-side vertex/index arrays, but we only try and target 3.2 (or lower) by default
            const u32 vertex_count = 0x2000; // Capacity is not important, just to try and pre-allocate some space
            const bool orphan = stream_mode == StreamMode::BufferSubData;
            vbo_ = MakeUnique<agiGLBasicStreamBuffer>(GL_ARRAY_BUFFER, vertex_count * sizeof(agiScreenVtx), orphan);
            ibo_ = nullptr;
            break;
        }

        case StreamMode::MapRange: {
            // Capacity is fixed
            vbo_ = MakeUnique<agiGLAsyncStreamBuffer>(GL_ARRAY_BUFFER, stream_vertex_count * sizeof(agiScreenVtx));
            ibo_ = MakeUnique<agiGLAsyncStreamBuffer>(GL_ELEMENT_ARRAY_BUFFER, stream_vertex_count * 3 * sizeof(u16));
            break;
        }

        case StreamMode::MapPersistent:
        case StreamMode::MapCoherent: {
            const bool coherent = stream_mode == StreamMode::MapCoherent;

            vbo_ = MakeUnique<agiGLPersistentStreamBuffer>(
                GL_ARRAY_BUFFER, stream_vertex_count * sizeof(agiScreenVtx), coherent);
            ibo_ = MakeUnique<agiGLPersistentStreamBuffer>(
                GL_ELEMENT_ARRAY_BUFFER, stream_vertex_count * 3 * sizeof(u16), coherent);
            break;
        }

        case StreamMode::AmdPinned: {
            vbo_ = MakeUnique<agiGLPinnedStreamBuffer>(GL_ARRAY_BUFFER, stream_vertex_count * sizeof(agiScreenVtx));
            ibo_ = MakeUnique<agiGLPinnedStreamBuffer>(GL_ELEMENT_ARRAY_BUFFER, stream_vertex_count * 3 * sizeof(u16));
            break;
        }

        case StreamMode::MapUnsafe: {
            vbo_ = MakeUnique<agiGLRiskyAsyncStreamBuffer>(GL_ARRAY_BUFFER, stream_vertex_count * sizeof(agiScreenVtx));
            ibo_ =
                MakeUnique<agiGLRiskyAsyncStreamBuffer>(GL_ELEMENT_ARRAY_BUFFER, stream_vertex_count * 3 * sizeof(u16));
            break;
        }

        case StreamMode::ClientSide: {
            vbo_ = nullptr;
            ibo_ = nullptr;
            break;
        }

        default: Quitf("Invalid Stream Mode");
    }

    PrintGlErrors();

    if (vbo_)
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

        vbo_->Bind();

        BindVertexAttribs(agiScreenVtx_Attribs, ARTS_SIZE(agiScreenVtx_Attribs), nullptr);
    }

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

    if (out_Color.w <= u_AlphaRef)
        discard;

    out_Color.xyz = mix(out_Color.xyz, u_Fog.xyz, (1.0 - frag_Specular.w) * u_Fog.w);
}
)");

    shader_ = glCreateProgram();

    glAttachShader(shader_, vs);
    glAttachShader(shader_, fs);

    for (const auto& attrib : agiScreenVtx_Attribs)
        glBindAttribLocation(shader_, attrib.Index, attrib.Name);

    glLinkProgram(shader_);

    CheckProgram(shader_);

    glDetachShader(shader_, vs);
    glDetachShader(shader_, fs);

    glDeleteShader(vs);
    glDeleteShader(fs);

    glUseProgram(shader_);

    PrintGlErrors();

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

    const GLfloat transform[16] {
        2.0f / (right - left),
        0.0f,
        0.0f,
        0.0f,

        0.0f,
        2.0f / (top - bottom),
        0.0f,
        0.0f,

        0.0f,
        0.0f,
        -2.0f / (z_far - z_near),
        0.0f,

        -(right + left) / (right - left),
        -(top + bottom) / (top - bottom),
        -(z_far + z_near) / (z_far - z_near),
        1.0f,
    };

    glUniformMatrix4fv(glGetUniformLocation(shader_, "u_Transform"), 1, GL_FALSE, transform);

    glGenTextures(1, &white_texture_);
    glBindTexture(GL_TEXTURE_2D, white_texture_);

    u32 white = 0xFFFFFFFF;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, &white);

    GLfloat line_width_range[2];
    glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, line_width_range);

    f32 line_width = std::clamp(PARAM_gllinewidth.get_or(1.0f), line_width_range[0], line_width_range[1]);

    glLineWidth(line_width);

    if (vbo_)
        vbo_->Bind();

    if (ibo_)
        ibo_->Bind();

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

u16* agiGLRasterizer::ImmAddIndices(u32 prim_type, u16 count)
{
    if ((prim_type != ImmPrimType) || (ImmIdxCount + count > ARTS_SIZE(ImmIdxBuffer)))
    {
        ImmDraw();
        ImmPrimType = prim_type;
    }

    u16* result = &ImmIdxBuffer[ImmIdxCount];
    ImmIdxCount += count;
    return result;
}

void agiGLRasterizer::ImmDraw()
{
    if (ImmVtxCount && ImmIdxCount)
        DrawMesh(ImmPrimType, ImmVtxBase, ImmVtxCount, ImmIdxBuffer, std::exchange(ImmIdxCount, 0));
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

        if (u32 handle = texture ? texture->GetHandle() : white_texture_; handle != current_texture_)
        {
            current_texture_ = handle;

            ++STATS.TextureChanges;

            if (texture)
                STATS.TxlsXrfd += texture->SurfaceSize;

            if (texture && current_texture_)
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

                    current_min_filter_ = min_filter;
                    current_mag_filter_ = mag_filter;
                }
            }
        }
    }

#define SET_GL_STATE(NAME, VALUE) SetState(&State::NAME, VALUE, Touched_##NAME)

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

    bool alpha_mode =
        agiCurState.GetAlphaEnable() || GetRendererInfo().AdditiveBlending || (texture && texture->Tex.HasAlpha());

    u8 alpha_ref = agiCurState.GetAlphaRef();

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

        SET_GL_STATE(BlendFuncS, blend_s);
        SET_GL_STATE(BlendFuncD, blend_d);
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
    if (touched_ == 0)
        return;

    ARTS_UTIMED(agiStateChanges);
    ++STATS.StateChanges;

    if (touched_ & Touched_DepthMask)
    {
        glDepthMask(state_.DepthMask);
        ++STATS.StateChangeCalls;
    }

    if (touched_ & Touched_DepthTest)
    {
        (state_.DepthTest ? glEnable : glDisable)(GL_DEPTH_TEST);
        ++STATS.StateChangeCalls;
    }

    if (touched_ & Touched_DepthFunc)
    {
        glDepthFunc(state_.DepthFunc);
        ++STATS.StateChangeCalls;
    }

    if (touched_ & Touched_PolygonMode)
    {
        glPolygonMode(GL_FRONT_AND_BACK, state_.PolygonMode);
        ++STATS.StateChangeCalls;
    }

    if (touched_ & Touched_Fog)
    {
        glUniform4f(uniform_fog_, state_.Fog.x, state_.Fog.y, state_.Fog.z, state_.Fog.w);
        ++STATS.StateChangeCalls;
    }

    if (touched_ & Touched_Blend)
    {
        (state_.Blend ? glEnable : glDisable)(GL_BLEND);
        ++STATS.StateChangeCalls;
    }

    if (touched_ & Touched_AlphaRef)
    {
        glUniform1f(uniform_alpha_ref_, state_.AlphaRef);
        ++STATS.StateChangeCalls;
    }

    if (touched_ & (Touched_BlendFuncS | Touched_BlendFuncD))
    {
        glBlendFunc(state_.BlendFuncS, state_.BlendFuncD);
        ++STATS.StateChangeCalls;
    }

    if (touched_ & Touched_CullFace)
    {
        (state_.CullFace ? glEnable : glDisable)(GL_CULL_FACE);
        ++STATS.StateChangeCalls;
    }

    if (touched_ & Touched_FrontFace)
    {
        glFrontFace(state_.FrontFace);
        ++STATS.StateChangeCalls;
    }

    touched_ = 0;
    real_state_ = state_;
}

void agiGLRasterizer::DrawMesh(u32 prim_type, agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count)
{
    if (!IsAppActive() || (vertex_count == 0) || (index_count == 0))
        return;

    FlushAgiState();

    if (current_texture_ == 0)
        return;

    FlushGlState();

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, current_texture_);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, current_min_filter_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, current_mag_filter_);

    usize vtx_offset = 0;

    if (vbo_)
    {
        vtx_offset = vbo_->Upload(vertices, vertex_count * sizeof(agiScreenVtx)) / sizeof(agiScreenVtx);
    }
    else
    {
        BindVertexAttribs(agiScreenVtx_Attribs, ARTS_SIZE(agiScreenVtx_Attribs), vertices);
    }

    const void* idx_offset =
        ibo_ ? reinterpret_cast<const void*>(ibo_->Upload(indices, index_count * sizeof(u16))) : indices;

    ARTS_UTIMED(agiRasterization);
    ++STATS.GeomCalls;

    if (vtx_offset)
    {
        glDrawRangeElementsBaseVertex(
            prim_type, 0, vertex_count, index_count, GL_UNSIGNED_SHORT, idx_offset, static_cast<GLint>(vtx_offset));
    }
    else
    {
        glDrawRangeElements(prim_type, 0, vertex_count, index_count, GL_UNSIGNED_SHORT, idx_offset);
    }

    if (vbo_)
        vbo_->SetFences();

    if (ibo_)
        ibo_->SetFences();
}
