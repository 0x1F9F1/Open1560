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
#include "stream/stream.h"

#include "glcontext.h"
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

static u32 CompileShader(u32 type, i32 glsl_version, const char* src)
{
    u32 shader = glCreateShader(type);

    char version_string[64];
    arts_sprintf(version_string, "#version %i\n", glsl_version);

    const char* strings[3] {version_string, "", src};

    if (glsl_version < 130)
    {
        switch (type)
        {
            case GL_VERTEX_SHADER: strings[1] = "#define in attribute\n#define out varying\n"; break;
            case GL_FRAGMENT_SHADER: strings[1] = "#define in varying\n"; break;
            default: Quitf("Invalid Shader Type %u", type);
        }
    }

    glShaderSource(shader, ARTS_SSIZE(strings), strings, 0);
    glCompileShader(shader);

    CheckShader(shader);

    return shader;
}

agiGLRasterizer::agiGLRasterizer(class agiPipeline* pipe)
    : agiRasterizer(pipe)
{}

agiGLRasterizer::~agiGLRasterizer() = default;

static mem::cmd_param PARAM_glstream {"glstream"};

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

//static const agiGLVertexAttrib agiScreenVtx2_Attribs[] {
//    {0, agiGLAttribType::Float4, "in_Position", offsetof(agiScreenVtx2, x),        sizeof(agiScreenVtx2)},
//    {1, agiGLAttribType::BGRA,   "in_Color",    offsetof(agiScreenVtx2, color),    sizeof(agiScreenVtx2)},
//    {2, agiGLAttribType::BGRA,   "in_Specular", offsetof(agiScreenVtx2, specular), sizeof(agiScreenVtx2)},
//    {3, agiGLAttribType::Float2, "in_UV1",      offsetof(agiScreenVtx2, tu1),      sizeof(agiScreenVtx2)},
//    {4, agiGLAttribType::Float2, "in_UV2",      offsetof(agiScreenVtx2, tu2),      sizeof(agiScreenVtx2)},
//};
// clang-format on

static void EnableVertexAttribs(const agiGLVertexAttrib* attribs, usize count, bool enabled)
{
    for (usize i = 0; i < count; ++i)
    {
        const agiGLVertexAttrib& attrib = attribs[i];

        (enabled ? glEnableVertexAttribArray : glDisableVertexAttribArray)(attrib.Index);
    }
}

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
    }
}

i32 agiGLRasterizer::BeginGfx()
{
    PrintGlErrors();

    enum class StreamMode : i32
    {
        // Decent performance, compatible with everything
        BufferData = 0,

        // Decent to abysmal performance, apart from on Mesa
        MapRange = 2,

        // Best performance, if supported
        MapPersistent = 3,
        MapCoherent = 4,
        AmdPinned = 5,

        // Should not be used, but gives a good idea of upload performance when persistent buffers are not available
        MapUnsafe = 6,

        // Great to decent performance, not available in core contexts.
        ClientSide = 7,
    };

    StreamMode stream_mode = StreamMode::ClientSide;

    {
        bool core = agiGL->IsCoreProfile();
        bool async = agiGL->HasExtension("GL_ARB_sync");
        const char* version = (const char*) glGetString(GL_VERSION);

        if (async && agiGL->HasExtension("GL_AMD_pinned_memory"))
        {
            stream_mode = StreamMode::AmdPinned;
        }
        else if (agiGL->HasExtension("GL_ARB_map_buffer_range"))
        {
            if (async && agiGL->HasExtension("GL_ARB_buffer_storage"))
                stream_mode = StreamMode::MapCoherent;
            else if (core && std::strstr(version, "Mesa"))
                stream_mode = StreamMode::MapRange;
        }

        if (i32 mode = 0; PARAM_glstream.get(mode))
            stream_mode = static_cast<StreamMode>(mode);

        if (core && stream_mode == StreamMode::ClientSide)
            stream_mode = StreamMode::BufferData;
    }

    Displayf("OpenGL: Using buffer stream mode %i", stream_mode);

    usize vbo_size = 16 << 20;

    switch (stream_mode)
    {
        case StreamMode::BufferData: {
            // OpenGL 3.3 removes client-side index arrays, but we only try and target 3.2 (or lower) by default
            vbo_ = MakeUnique<agiGLBasicStreamBuffer>();
            ibo_ = false;
            break;
        }

        case StreamMode::MapRange: {
            vbo_ = MakeUnique<agiGLMapRangeStreamBuffer>(vbo_size);
            ibo_ = true;
            break;
        }

        case StreamMode::MapPersistent:
        case StreamMode::MapCoherent: {
            vbo_ = MakeUnique<agiGLPersistentStreamBuffer>(vbo_size, stream_mode == StreamMode::MapCoherent);
            ibo_ = true;
            break;
        }

        case StreamMode::AmdPinned: {
            vbo_ = MakeUnique<agiGLAMDPinnedStreamBuffer>(vbo_size);
            ibo_ = true;
            break;
        }

        case StreamMode::MapUnsafe: {
            vbo_ = MakeUnique<agiGLMapUnsafeStreamBuffer>(vbo_size);
            ibo_ = true;
            break;
        }

        case StreamMode::ClientSide: {
            vbo_ = nullptr;
            ibo_ = false;
            break;
        }

        default: Quitf("Invalid Stream Mode");
    }

    PrintGlErrors();

    if (vbo_)
    {
        if (agiGL->HasExtension("GL_ARB_vertex_array_object"))
        {
            glGenVertexArrays(1, &vao_);
            glBindVertexArray(vao_);
        }
        else
        {
            Displayf("OpenGL VAO not supported");
        }
    }

    i32 glsl_version = std::min(agiGL->GetShaderVersion(), 130);

    Displayf("OpenGL: Using shader version %i", glsl_version);

    u32 vs = CompileShader(GL_VERTEX_SHADER, glsl_version, R"(
in vec4 in_Position;
in vec4 in_Color;
in vec4 in_Specular;
in vec2 in_UV;

out vec4 frag_Color;
out vec4 frag_Fog;
out vec2 frag_UV;

uniform mat4 u_Transform;
uniform vec4 u_FogMode;
uniform vec3 u_FogColor;

void main()
{
    gl_Position = u_Transform * vec4(in_Position.xyz, 1.0);
    gl_Position.w = 1.0 / in_Position.w;
    gl_Position.xyz *= gl_Position.w;
    frag_Color = in_Color;

    if (u_FogMode.x != 0.0)
    {
        float fog;

        if (u_FogMode.x == 2.0) // Vertex
        {
            fog = in_Specular.w;
        }
        else // Pixel
        {
            float depth = in_Position.z * gl_Position.w;
            fog = clamp((u_FogMode.y - depth) * u_FogMode.z, 0.0, 1.0);
        }

        frag_Fog = vec4(u_FogColor * (1.0 - fog), fog);
    }
    else // None
    {
        frag_Fog = vec4(0.0, 0.0, 0.0, 1.0);
    }

    frag_UV = in_UV;
}
)");

    u32 fs = CompileShader(GL_FRAGMENT_SHADER, glsl_version, R"(
in vec4 frag_Color;
in vec4 frag_Fog;
in vec2 frag_UV;

#if __VERSION__  >= 130
out vec4 out_Color;
#define texture2D texture
#else
#define out_Color gl_FragColor
#endif

uniform sampler2D u_Texture;
uniform float u_AlphaRef;

void main()
{
    out_Color = texture2D(u_Texture, frag_UV) * frag_Color;

    // Ignored by software renderer, only used by mmDashView, only ever 0
    if (out_Color.w <= u_AlphaRef)
        discard;

    out_Color.xyz = out_Color.xyz * frag_Fog.w + frag_Fog.xyz;
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

#if 0
    if (Pipe()->HasExtension("GL_ARB_get_program_binary"))
    {
        GLint buffer_size = 0;
        glGetProgramiv(shader_, GL_PROGRAM_BINARY_LENGTH, &buffer_size);
        u8* buffer = new u8[buffer_size];

        GLsizei length = 0;
        GLenum binary_format = 0;
        glGetProgramBinary(shader_, buffer_size, &length, &binary_format, buffer);

        if (Ptr<Stream> output {arts_fopen("shader.bin", "w")})
        {
            output->Write(&binary_format, sizeof(binary_format));
            output->Write(buffer, buffer_size);
        }
    }
#endif

    PrintGlErrors();

    glUniform1i(glGetUniformLocation(shader_, "u_Texture"), 0);

    uniform_alpha_ref_ = glGetUniformLocation(shader_, "u_AlphaRef");
    alpha_ref_ = 0.0f;
    glUniform1f(uniform_alpha_ref_, alpha_ref_);

    uniform_fog_mode_ = glGetUniformLocation(shader_, "u_FogMode");
    fog_mode_ = {0.0f, 0.0f, 0.0f, 0.0f};
    glUniform4f(uniform_fog_mode_, fog_mode_.x, fog_mode_.y, fog_mode_.z, fog_mode_.w);

    uniform_fog_color_ = glGetUniformLocation(shader_, "u_FogColor");
    fog_color_ = {0.0f, 0.0f, 0.0f};
    glUniform3f(uniform_fog_color_, fog_color_.x, fog_color_.y, fog_color_.z);

    // Converts from screen coordinates ([0, Width], [0, Height], [0, 1]) to NDC
    GLfloat transform[16] {};

    // x = 2x / width - 1
    transform[0] = 2.0f / Pipe()->GetWidth();
    transform[12] = -1.0f;

    // y = -2y / height + 1
    transform[5] = -2.0f / Pipe()->GetHeight();
    transform[13] = 1.0f;

    // z = 2z - 1
    transform[10] = 2.0f;
    transform[14] = -1.0f;

    // w = 1
    transform[15] = 1.0f;

    flip_winding_ = false;

    // Designed for floating point framebuffers
    // Broken on some old OpenGL2 drivers
    // https://nlguillemot.wordpress.com/2016/12/07/reversed-z-in-opengl/
    reversed_z_ = false;

    if (agiGL->HasExtension("GL_ARB_clip_control"))
    {
        flip_winding_ = true;

        glClipControl(flip_winding_ ? GL_UPPER_LEFT : GL_LOWER_LEFT, GL_ZERO_TO_ONE);

        if (flip_winding_)
        {
            // y = 2y / height - 1
            transform[5] = -transform[5];
            transform[13] = -transform[13];
        }

        transform[10] = 1.0f;
        transform[14] = 0.0f;
    }
    else if (agiGL->HasExtension("GL_NV_depth_buffer_float"))
    {
        glDepthRangedNV(-1.0, 1.0);
    }

    if (reversed_z_)
    {
        transform[14] += transform[10];
        transform[10] = -transform[10];
    }

    glClearDepth(reversed_z_ ? 0.0 : 1.0);

    glUniformMatrix4fv(glGetUniformLocation(shader_, "u_Transform"), 1, GL_FALSE, transform);

    glGenTextures(1, &white_texture_);
    glBindTexture(GL_TEXTURE_2D, white_texture_);

    u32 white = 0xFFFFFFFF;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, &white);

    glBindBuffer(GL_ARRAY_BUFFER, vbo_ ? vbo_->Buffer : 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_ ? vbo_->Buffer : 0);

    draw_base_vertex_ = vbo_ && agiGL->HasExtension("GL_ARB_draw_elements_base_vertex");
    last_vtx_offset_ = nullptr;
    BindVertexAttribs(agiScreenVtx_Attribs, ARTS_SIZE(agiScreenVtx_Attribs), nullptr);
    EnableVertexAttribs(agiScreenVtx_Attribs, ARTS_SIZE(agiScreenVtx_Attribs), true);

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

void agiGLRasterizer::Points(
    [[maybe_unused]] agiVtxType type, [[maybe_unused]] agiVtx* vertices, [[maybe_unused]] i32 vertex_count)
{}

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
    if (agiCurState.GetDrawMode() != 15)
        agiCurState.SetTexture(nullptr);

    if (!agiCurState.IsTouched())
        return;

    ARTS_UTIMED(agiStateChanges);
    ++STATS.StateChanges;

    agiGLTexDef* texture = static_cast<agiGLTexDef*>(agiCurState.GetTexture());
    agiTexFilter tex_filter = agiCurState.GetTexFilter();

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
                if (texture->Tex.DisableMipMaps() && tex_filter > agiTexFilter::Bilinear)
                    tex_filter = agiTexFilter::Bilinear;

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

                texture->SetFilters(min_filter, mag_filter);
            }
        }
    }

    if (tex_filter != agiLastState.TexFilter)
    {
        agiLastState.TexFilter = tex_filter;
    }

    if (bool zwrite = agiCurState.GetZWrite(); zwrite != agiLastState.ZWrite)
    {
        agiLastState.ZWrite = zwrite;

        agiGL->DepthMask(zwrite);
        ++STATS.StateChangeCalls;
    }

    if (bool zenable = agiCurState.GetZEnable(); zenable != agiLastState.ZEnable)
    {
        agiLastState.ZEnable = zenable;
        agiGL->EnableDisable(GL_DEPTH_TEST, zenable);
        ++STATS.StateChangeCalls;
    }

    if (agiCmpFunc zfunc = agiCurState.GetZFunc(); zfunc != agiLastState.ZFunc)
    {
        agiLastState.ZFunc = zfunc;

        GLenum depth_func = 0;

        switch (zfunc)
        {
            case agiCmpFunc::Never: depth_func = GL_NEVER; break;
            case agiCmpFunc::Less: depth_func = reversed_z_ ? GL_GREATER : GL_LESS; break;
            case agiCmpFunc::Equal: depth_func = GL_EQUAL; break;
            case agiCmpFunc::LessEqual: depth_func = reversed_z_ ? GL_GEQUAL : GL_LEQUAL; break;
            case agiCmpFunc::Greater: depth_func = reversed_z_ ? GL_LESS : GL_GREATER; break;
            case agiCmpFunc::Notequal: depth_func = GL_NOTEQUAL; break;
            case agiCmpFunc::GreaterEqual: depth_func = reversed_z_ ? GL_LEQUAL : GL_GEQUAL; break;
            case agiCmpFunc::Always: depth_func = GL_ALWAYS; break;
        }

        agiGL->DepthFunc(depth_func);
        ++STATS.StateChangeCalls;
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

        agiGL->PolygonMode(poly_mode);
        ++STATS.StateChangeCalls;
    }

    bool alpha_enable =
        agiCurState.GetAlphaEnable() || GetRendererInfo().AdditiveBlending || (texture && texture->Tex.HasAlpha());

    u8 alpha_ref = agiCurState.GetAlphaRef();

    if (alpha_enable != agiLastState.AlphaEnable || alpha_ref != agiLastState.AlphaRef)
    {
        agiLastState.AlphaEnable = alpha_enable;
        agiLastState.AlphaRef = alpha_ref;

        agiGL->EnableDisable(GL_BLEND, alpha_enable);
        ++STATS.StateChangeCalls;

        f32 falpha_ref = alpha_enable ? (alpha_ref / 255.0f) : 0.0f;

        if (alpha_ref_ != falpha_ref)
        {
            alpha_ref_ = falpha_ref;
            glUniform1f(uniform_alpha_ref_, falpha_ref);
            ++STATS.StateChangeCalls;
        }
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

        agiGL->BlendFunc(blend_s, blend_d);
        ++STATS.StateChangeCalls;
    }

    if (agiCullMode cull_mode = agiCurState.GetCullMode(); cull_mode != agiLastState.CullMode)
    {
        agiLastState.CullMode = cull_mode;

        u32 front_face = 0;

        // DirectX CullMode specifies which triangles are NOT drawn
        // OpenGL glFrontFace specifies which triangles ARE drawn
        switch (cull_mode)
        {
            case agiCullMode::None: front_face = 0; break;
            case agiCullMode::CW: front_face = flip_winding_ ? GL_CW : GL_CCW; break;
            case agiCullMode::CCW: front_face = flip_winding_ ? GL_CCW : GL_CW; break;
        }

        agiGL->EnableDisable(GL_CULL_FACE, front_face != 0);
        ++STATS.StateChangeCalls;

        if (front_face != 0)
        {
            agiGL->FrontFace(front_face);
            ++STATS.StateChangeCalls;
        }
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

    agiFogMode fog_mode = agiCurState.GetFogMode();
    f32 fog_start = agiCurState.GetFogStart();
    f32 fog_end = agiCurState.GetFogEnd();
    f32 fog_density = agiCurState.GetFogDensity();

    if (fog_mode != agiLastState.FogMode || fog_start != agiLastState.FogStart || fog_end != agiLastState.FogEnd ||
        fog_density != agiLastState.FogDensity)
    {
        agiLastState.FogMode = fog_mode;
        agiLastState.FogStart = fog_start;
        agiLastState.FogEnd = fog_end;
        agiLastState.FogDensity = fog_density;

        Vector4 mode {
            static_cast<f32>(fog_mode),
            fog_end,
            (fog_start == fog_end) ? 0.0f : (1.0f / (fog_end - fog_start)),
            fog_density,
        };

        if (fog_mode_ != mode)
        {
            fog_mode_ = mode;
            glUniform4f(uniform_fog_mode_, mode.x, mode.y, mode.z, mode.w);
            ++STATS.StateChangeCalls;
        }
    }

    if (u32 fog_color = agiCurState.GetFogColor(); fog_color != agiLastState.FogColor)
    {
        agiLastState.FogColor = fog_color;

        Vector3 color {
            ((fog_color >> 16) & 0xFF) / 255.0f,
            ((fog_color >> 8) & 0xFF) / 255.0f,
            (fog_color & 0xFF) / 255.0f,
        };

        if (fog_color_ != color)
        {
            fog_color_ = color;
            glUniform3f(uniform_fog_color_, color.x, color.y, color.z);
            ++STATS.StateChangeCalls;
        }
    }

    agiCurState.ClearTouched();
}

void agiGLRasterizer::DrawMesh(u32 prim_type, agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count)
{
    if (!IsAppActive() || (vertex_count == 0) || (index_count == 0))
        return;

    FlushState();

    if (current_texture_ == 0)
        return;

    ARTS_UTIMED(agiRasterization);
    ++STATS.GeomCalls;

    agiGL->BindTextureUnit(GL_TEXTURE_2D, current_texture_, 0);

    const void* offsets[2] {vertices, indices};

    if (vbo_)
    {
        const usize lengths[2] {vertex_count * sizeof(agiScreenVtx), index_count * sizeof(u16)};
        const usize aligns[2] {sizeof(agiScreenVtx), sizeof(u16)};
        vbo_->Upload(offsets, lengths, aligns, ibo_ ? 2 : 1);
    }

    const auto [vtx_offset, idx_offset] = offsets;

    if (draw_base_vertex_ && vtx_offset)
    {
        glDrawRangeElementsBaseVertex(prim_type, 0, vertex_count, index_count, GL_UNSIGNED_SHORT, idx_offset,
            reinterpret_cast<usize>(vtx_offset) / sizeof(agiScreenVtx));
    }
    else
    {
        if (vtx_offset != last_vtx_offset_)
        {
            BindVertexAttribs(agiScreenVtx_Attribs, ARTS_SIZE(agiScreenVtx_Attribs), vtx_offset);
            last_vtx_offset_ = vtx_offset;
        }

        glDrawRangeElements(prim_type, 0, vertex_count, index_count, GL_UNSIGNED_SHORT, idx_offset);
    }

    if (vbo_)
        vbo_->Discard();
}
