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

    if (shader_ != 0)
    {
        glDeleteProgram(shader_);
        shader_ = 0;
    }
}

static void CheckShader(u32 shader)
{
    GLint is_compiled = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &is_compiled);

    if (is_compiled)
        return;

    agiGL->CheckErrors();

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

    agiGL->CheckErrors();

    GLint log_length = 0;
    glGetShaderiv(program, GL_INFO_LOG_LENGTH, &log_length);

    char* log_text = new char[log_length];
    glGetProgramInfoLog(program, log_length, &log_length, log_text);
    Quitf("Failed to link program:\n%s", log_text);
}

static u32 CompileShader(u32 type, i32 glsl_version, const char* src)
{
    u32 shader = glCreateShader(type);

    const auto version_string = arts_formatf<64>("#version %i\n", glsl_version);

    const char* strings[3] {version_string, "", src};

    if (glsl_version >= 130)
    {
        strings[1] = "#define texture2D texture\n";
    }
    else
    {
        switch (type)
        {
            case GL_VERTEX_SHADER:
                strings[1] = "#define in attribute\n"
                             "#define out varying\n";
                break;
            case GL_FRAGMENT_SHADER: strings[1] = "#define in varying\n"; break;
            default: Quitf("Invalid Shader Type %u", type);
        }
    }

    glShaderSource(shader, ARTS_SSIZE(strings), strings, 0);
    glCompileShader(shader);

    CheckShader(shader);

    return shader;
}

agiGLRasterizer::agiGLRasterizer(agiPipeline* pipe)
    : agiRasterizer(pipe)
{}

agiGLRasterizer::~agiGLRasterizer() = default;

enum class agiGLAttribType
{
    Float2,
    Float4,
    Byte4_UNorm,
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
    {0, agiGLAttribType::Float4,      "in_Position", offsetof(agiScreenVtx, x),        sizeof(agiScreenVtx)},
    {1, agiGLAttribType::Byte4_UNorm, "in_Color",    offsetof(agiScreenVtx, color),    sizeof(agiScreenVtx)},
    {2, agiGLAttribType::Byte4_UNorm, "in_Specular", offsetof(agiScreenVtx, specular), sizeof(agiScreenVtx)},
    {3, agiGLAttribType::Float2,      "in_UV",       offsetof(agiScreenVtx, tu),       sizeof(agiScreenVtx)},
};

//static const agiGLVertexAttrib agiScreenVtx2_Attribs[] {
//    {0, agiGLAttribType::Float4,      "in_Position", offsetof(agiScreenVtx2, x),        sizeof(agiScreenVtx2)},
//    {1, agiGLAttribType::Byte4_UNorm, "in_Color",    offsetof(agiScreenVtx2, color),    sizeof(agiScreenVtx2)},
//    {2, agiGLAttribType::Byte4_UNorm, "in_Specular", offsetof(agiScreenVtx2, specular), sizeof(agiScreenVtx2)},
//    {3, agiGLAttribType::Float2,      "in_UV1",      offsetof(agiScreenVtx2, tu1),      sizeof(agiScreenVtx2)},
//    {4, agiGLAttribType::Float2,      "in_UV2",      offsetof(agiScreenVtx2, tu2),      sizeof(agiScreenVtx2)},
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

            case agiGLAttribType::Byte4_UNorm:
                size = 4;
                type = GL_UNSIGNED_BYTE;
                normalized = GL_TRUE;
                break;

            default: Abortf("Invalid Vertex Attrib Type");
        }

        glVertexAttribPointer(attrib.Index, size, type, normalized, static_cast<GLsizei>(attrib.Stride),
            static_cast<const unsigned char*>(pointer) + attrib.Offset);
    }
}

static mem::cmd_param PARAM_ancientgl {"ancientgl"};

i32 agiGLRasterizer::BeginGfx()
{
    agiGL->CheckErrors();

    if (agiGL->IsCoreProfile() || (agiGL->HasVersion(200) && !PARAM_ancientgl.get_or(false)))
    {
        InitModern();
    }

    // Follow DirectX convention
    // if (agiGL->HasExtension(320, "GL_ARB_provoking_vertex"))
    //     glProvokingVertex(GL_FIRST_VERTEX_CONVENTION);

    // Convert from screen coordinates { [0, Width], [0, Height], [0, 1], RHW } to NDC
    GLfloat proj_mul[4];
    GLfloat proj_add[4];

    // x = 2x / width - 1
    proj_mul[0] = 2.0f / Pipe()->GetWidth();
    proj_add[0] = -1.0f;

    // y = -2y / height + 1
    proj_mul[1] = -2.0f / Pipe()->GetHeight();
    proj_add[1] = 1.0f;

    // z = 2z - 1
    proj_mul[2] = 2.0f;
    proj_add[2] = -1.0f;

    // w = 1
    proj_mul[3] = 0.0f;
    proj_add[3] = 1.0f;

    flip_winding_ = false;

    // Designed for floating point framebuffers
    // https://nlguillemot.wordpress.com/2016/12/07/reversed-z-in-opengl/
    reversed_z_ = false;

    if (agiGL->HasExtension(/*450,*/ "GL_ARB_clip_control"))
    {
        flip_winding_ = true;

        glClipControl(flip_winding_ ? GL_UPPER_LEFT : GL_LOWER_LEFT, GL_ZERO_TO_ONE);

        if (flip_winding_)
        {
            // y = 2y / height - 1
            proj_mul[1] = -proj_mul[1];
            proj_add[1] = -proj_add[1];
        }

        proj_mul[2] = 1.0f;
        proj_add[2] = 0.0f;
    }
    else if (agiGL->HasExtension("GL_NV_depth_buffer_float"))
    {
        glDepthRangedNV(-1.0, 1.0);
    }

    if (reversed_z_)
    {
        proj_add[2] += proj_mul[2];
        proj_mul[2] = -proj_mul[2];
    }

    glClearDepth(reversed_z_ ? 0.0 : 1.0);

    if (shader_)
    {
        glUniform4fv(glGetUniformLocation(shader_, "u_Transform[0]"), 1, proj_mul);
        glUniform4fv(glGetUniformLocation(shader_, "u_Transform[1]"), 1, proj_add);

        u32 buffer = vbo_ ? vbo_->Buffer : 0;
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);

        draw_base_vertex_ = vbo_ && agiGL->HasExtension(320, "GL_ARB_draw_elements_base_vertex");
        last_vtx_offset_ = nullptr;
        BindVertexAttribs(agiScreenVtx_Attribs, ARTS_SIZE(agiScreenVtx_Attribs), nullptr);
        EnableVertexAttribs(agiScreenVtx_Attribs, ARTS_SIZE(agiScreenVtx_Attribs), true);
    }
    else
    {
        glFogi(GL_FOG_MODE, GL_LINEAR);
        glFogi(GL_FOG_COORD_SRC, GL_FOG_COORD);

        glMatrixMode(GL_PROJECTION);

        // clang-format off
        GLfloat projection[16] {
            proj_mul[0],        0.0f,        0.0f, 0.0f,
                   0.0f, proj_mul[1],        0.0f, 0.0f,
                   0.0f,        0.0f, proj_mul[2], 0.0f,
            proj_add[0], proj_add[1], proj_add[2], 1.0f,
        };
        // clang-format on

        glLoadMatrixf(projection);
    }

    agiGL->CheckErrors();

    return AGI_ERROR_SUCCESS;
}

static mem::cmd_param PARAM_glstream {"glstream"};

void agiGLRasterizer::InitModern()
{
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
        bool async = agiGL->HasExtension(320, "GL_ARB_sync");

        if (async && agiGL->HasExtension("GL_AMD_pinned_memory"))
        {
            stream_mode = StreamMode::AmdPinned;
        }
        else if (agiGL->HasExtension(300, "GL_ARB_map_buffer_range"))
        {
            if (async && agiGL->HasExtension(/*440,*/ "GL_ARB_buffer_storage"))
                stream_mode = StreamMode::MapCoherent;
            // else
            //     stream_mode = StreamMode::MapRange;
        }

        if (i32 mode = 0; PARAM_glstream.get(mode))
            stream_mode = static_cast<StreamMode>(mode);

        if (agiGL->IsCoreProfile() && stream_mode == StreamMode::ClientSide)
            stream_mode = StreamMode::BufferData;
    }

    Displayf("OpenGL: Using buffer stream mode %i", stream_mode);

    usize vbo_size = 16 << 20;

    switch (stream_mode)
    {
        case StreamMode::BufferData: {
            vbo_ = MakeUnique<agiGLBasicStreamBuffer>();
            break;
        }

        case StreamMode::MapRange: {
            vbo_ = MakeUnique<agiGLMapRangeStreamBuffer>(vbo_size);
            break;
        }

        case StreamMode::MapPersistent:
        case StreamMode::MapCoherent: {
            vbo_ = MakeUnique<agiGLPersistentStreamBuffer>(vbo_size, stream_mode == StreamMode::MapCoherent);
            break;
        }

        case StreamMode::AmdPinned: {
            vbo_ = MakeUnique<agiGLAMDPinnedStreamBuffer>(vbo_size);
            break;
        }

        case StreamMode::MapUnsafe: {
            vbo_ = MakeUnique<agiGLMapUnsafeStreamBuffer>(vbo_size);
            break;
        }

        case StreamMode::ClientSide: {
            vbo_ = nullptr;
            break;
        }

        default: Quitf("Invalid Stream Mode");
    }

    agiGL->CheckErrors();

    if (vbo_)
    {
        if (agiGL->HasExtension(300, "GL_ARB_vertex_array_object"))
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

uniform vec4 u_Transform[2];
uniform vec4 u_FogMode;
uniform vec3 u_FogColor;
uniform bvec2 u_TexEnv;

void main()
{
    gl_Position = in_Position * u_Transform[0] + u_Transform[1];
    gl_Position /= in_Position.w;
    frag_Color = u_TexEnv[0] ? in_Color.bgra : vec4(1.0);

    frag_Fog = vec4(0.0);
    frag_UV = in_UV;

    if (u_FogMode[0] != 0.0)
    {
        float fog;

        if (u_FogMode[0] == 1.0) // Pixel
        {
            float depth = in_Position.z * gl_Position.w;
            // clamping in the vertex shader assumes assumes Z is pre-clipped
            fog = clamp(depth * u_FogMode[1] + u_FogMode[2], 0.0, 1.0);
        }
        else // Vertex
        {
            fog = in_Specular.a;
        }

        frag_Fog.rgb = u_FogColor * (1.0 - fog);
        frag_Color.rgb *= fog;
    }
}
)");

    u32 fs = CompileShader(GL_FRAGMENT_SHADER, glsl_version, R"(
in vec4 frag_Color;
in vec4 frag_Fog;
in vec2 frag_UV;

#if __VERSION__ >= 130
out vec4 out_Color;
#else
#define out_Color gl_FragColor
#endif

uniform sampler2D u_Texture;
uniform float u_AlphaRef;
uniform bvec2 u_TexEnv;

void main()
{
    out_Color = frag_Color;

    if (u_TexEnv[1])
        out_Color *= texture2D(u_Texture, frag_UV);

    out_Color += frag_Fog;

    // Ignored by software renderer, only used by mmDashView, only ever 0
    if (out_Color.a <= u_AlphaRef)
        discard;
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
    if (agiGL->HasExtension("GL_ARB_get_program_binary"))
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

    agiGL->CheckErrors();

    agiGL->BindTextureUnit(GL_TEXTURE_2D, 0, 0);
    current_texture_ = 0;
    glUniform1i(glGetUniformLocation(shader_, "u_Texture"), 0);

    uniform_alpha_ref_ = glGetUniformLocation(shader_, "u_AlphaRef");
    alpha_ref_ = 0.0f;
    glUniform1f(uniform_alpha_ref_, alpha_ref_);

    uniform_tex_env_ = glGetUniformLocation(shader_, "u_TexEnv");
    tex_env_ = agiTexEnv::Disable;
    glUniform2i(uniform_tex_env_, tex_env_ != agiTexEnv::Replace, tex_env_ != agiTexEnv::Disable);

    uniform_fog_mode_ = glGetUniformLocation(shader_, "u_FogMode");
    fog_mode_ = {0.0f, 0.0f, 0.0f, 0.0f};
    glUniform4f(uniform_fog_mode_, fog_mode_.x, fog_mode_.y, fog_mode_.z, fog_mode_.w);

    uniform_fog_color_ = glGetUniformLocation(shader_, "u_FogColor");
    fog_color_ = {0.0f, 0.0f, 0.0f};
    glUniform3f(uniform_fog_color_, fog_color_.x, fog_color_.y, fog_color_.z);

    agiGL->CheckErrors();
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

    STATS.Tris += index_count / 3;

    DrawMesh(GL_TRIANGLES, vertices, vertex_count, indices, index_count);
}

void agiGLRasterizer::FlushState()
{
    if (!agiCurState.IsTouched())
        return;

    ARTS_UTIMED(agiStateChanges);
    ++STATS.StateChanges;

    agiGLTexDef* texture =
        (agiCurState.GetDrawMode() == agiDrawTextured) ? static_cast<agiGLTexDef*>(agiCurState.GetTexture()) : nullptr;

    agiTexFilter tex_filter = agiCurState.GetTexFilter();

    if (texture != agiLastState.Texture)
    {
        agiLastState.Texture = texture;

        if (texture)
        {
            if (u32 handle = texture->GetHandle(); handle != current_texture_)
            {
                current_texture_ = handle;

                ++STATS.TextureChanges;
                STATS.TxlsXrfd += texture->SurfaceSize;

                if (current_texture_)
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
        else
        {
            current_texture_ = 0;
        }
    }

    if (tex_filter != agiLastState.TexFilter)
    {
        agiLastState.TexFilter = tex_filter;
    }

    bool zenable = agiEnableZBuffer && agiCurState.GetZEnable();

    if (zenable != agiLastState.ZEnable)
    {
        agiLastState.ZEnable = zenable;
        agiGL->EnableDisable(GL_DEPTH_TEST, zenable);
        ++STATS.StateChangeCalls;
    }

    if (zenable)
    {
        if (bool zwrite = agiCurState.GetZWrite(); zwrite != agiLastState.ZWrite)
        {
            agiLastState.ZWrite = zwrite;

            agiGL->DepthMask(zwrite);
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
    }

    if (bool texture_perspective = agiCurState.GetTexturePerspective();
        texture_perspective != agiLastState.TexturePerspective)
    {
        agiLastState.TexturePerspective = texture_perspective;

        if (shader_ == 0)
            glHint(GL_PERSPECTIVE_CORRECTION_HINT, texture_perspective ? GL_NICEST : GL_FASTEST);
    }

    if (bool smooth_shading = agiCurState.GetSmoothShading(); smooth_shading != agiLastState.SmoothShading)
    {
        agiLastState.SmoothShading = smooth_shading;

        if (shader_ == 0)
            glShadeModel(smooth_shading ? GL_SMOOTH : GL_FLAT);
    }

    if (agiDrawMode draw_mode = agiCurState.GetDrawMode(); draw_mode != agiLastState.DrawMode)
    {
        agiLastState.DrawMode = draw_mode;

        GLenum poly_mode = GL_FILL;

        switch (static_cast<agiFillMode>(draw_mode & agiDrawFillMask))
        {
            case agiFillMode::Point: poly_mode = GL_POINT; break;
            case agiFillMode::Wire: poly_mode = GL_LINE; break;
            case agiFillMode::Solid: poly_mode = GL_FILL; break;
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

        if (shader_)
        {
            f32 falpha_ref = alpha_enable ? (alpha_ref / 255.0f) : 0.0f;

            if (alpha_ref_ != falpha_ref)
            {
                alpha_ref_ = falpha_ref;
                glUniform1f(uniform_alpha_ref_, falpha_ref);
                ++STATS.StateChangeCalls;
            }
        }
        else
        {
            agiGL->EnableDisable(GL_ALPHA_TEST, alpha_enable);
            ++STATS.StateChangeCalls;

            if (alpha_enable)
            {
                glAlphaFunc(GL_GREATER, alpha_ref / 255.0f);
                ++STATS.StateChangeCalls;
            }
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

    if (agiTexEnv tex_env = texture ? agiCurState.GetTexEnv() : agiTexEnv::Disable; tex_env != agiLastState.TexEnv)
    {
        agiLastState.TexEnv = tex_env;

        if (tex_env != tex_env_)
        {
            tex_env_ = tex_env;

            if (shader_)
            {
                glUniform2i(uniform_tex_env_, tex_env_ != agiTexEnv::Replace, tex_env_ != agiTexEnv::Disable);
            }
            else
            {
                switch (tex_env)
                {
                    case agiTexEnv::Replace: glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); break;
                    case agiTexEnv::Modulate: glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); break;
                }
            }

            ++STATS.StateChangeCalls;
        }
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

        if (shader_)
        {
            // (end - c) / (end - start) == (end - c) * inv_fog_range == (c * -inv_fog_range) + (end * inv_fog_range)
            f32 inv_fog_range = (fog_start == fog_end) ? 0.0f : (1.0f / (fog_end - fog_start));

            Vector4 mode {
                static_cast<f32>(fog_mode),
                -inv_fog_range,
                fog_end * inv_fog_range,
                fog_density,
            };

            if (fog_mode_ != mode)
            {
                fog_mode_ = mode;
                glUniform4f(uniform_fog_mode_, mode.x, mode.y, mode.z, mode.w);
                ++STATS.StateChangeCalls;
            }
        }
        else
        {
            agiGL->EnableDisable(GL_FOG, fog_mode != agiFogMode::None);

            if (fog_mode != agiFogMode::None)
            {
                if (fog_mode == agiFogMode::Pixel)
                {
                    glFogf(GL_FOG_START, fog_start);
                    glFogf(GL_FOG_END, fog_end);
                }
                else
                {
                    glFogf(GL_FOG_START, 255.0f);
                    glFogf(GL_FOG_END, 0.0f);
                }
            }
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

        if (shader_)
        {
            if (fog_color_ != color)
            {
                fog_color_ = color;
                glUniform3f(uniform_fog_color_, color.x, color.y, color.z);
                ++STATS.StateChangeCalls;
            }
        }
        else
        {
            f32 gl_fog_color[4] {color.x, color.y, color.z, 1.0f};
            glFogfv(GL_FOG_COLOR, gl_fog_color);
        }
    }

    agiCurState.ClearTouched();
}

static void DrawMeshImm(u32 draw_mode, agiVtx* vertices, u16* indices, i32 index_count)
{
    glBegin(draw_mode);

    for (i32 i = 0; i < index_count; ++i)
    {
        agiScreenVtx vert = vertices[indices[i]].Screen;

#ifdef ARTS_ENABLE_KNI
        __m128 pos = _mm_load_ps(&vert.x);
        __m128 w = _mm_shuffle_ps(pos, pos, _MM_SHUFFLE(3, 3, 3, 3));
        pos = _mm_shuffle_ps(
            pos, _mm_shuffle_ps(_mm_set_ss(1.0f), pos, _MM_SHUFFLE(3, 2, 1, 0)), _MM_SHUFFLE(0, 2, 1, 0));
        __m128 rhw = _mm_rcp_ps(w);
        rhw = _mm_sub_ps(_mm_add_ps(rhw, rhw), _mm_mul_ps(_mm_mul_ps(rhw, rhw), w));
        pos = _mm_mul_ps(pos, rhw);
        _mm_store_ps(&vert.x, pos);
#else
        f32 w = 1.0f / vert.w;
        vert.w = 1.0f;
        vert.x *= w;
        vert.y *= w;
        vert.z *= w;
        vert.w *= w;
#endif

        if (agiLastState.TexEnv != agiTexEnv::Disable)
            glTexCoord2fv(&vert.tu);

        glColor4ub(
            (vert.color >> 16) & 0xFF, (vert.color >> 8) & 0xFF, (vert.color >> 0) & 0xFF, (vert.color >> 24) & 0xFF);

        switch (agiLastState.FogMode)
        {
            case agiFogMode::Pixel: glFogCoordf(vert.z); break;
            case agiFogMode::Vertex: glFogCoordf(static_cast<f32>(vert.specular >> 24)); break;
        }

        glVertex4fv(&vert.x);
    }

    glEnd();
}

void agiGLRasterizer::DrawMesh(u32 draw_mode, agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count)
{
    if (!IsAppActive() || (vertex_count == 0) || (index_count == 0))
        return;

    FlushState();

    if ((current_texture_ == 0) && (tex_env_ != agiTexEnv::Disable))
        return;

    ARTS_UTIMED(agiRasterization);
    ++STATS.GeomCalls;

    if (current_texture_ != 0)
    {
        agiGL->BindTextureUnit(GL_TEXTURE_2D, current_texture_, 0);
    }

    if (shader_ == 0)
    {
        agiGL->EnableDisable(GL_TEXTURE_2D, current_texture_ != 0);

        return DrawMeshImm(draw_mode, vertices, indices, index_count);
    }

    const void* offsets[2] {vertices, indices};

    if (vbo_)
    {
        const usize lengths[2] {vertex_count * sizeof(agiScreenVtx), index_count * sizeof(u16)};
        const usize aligns[2] {sizeof(agiScreenVtx), sizeof(u16)};
        vbo_->Upload(offsets, lengths, aligns, 2);
    }

    const auto [vtx_offset, idx_offset] = offsets;

    if (draw_base_vertex_)
    {
        glDrawRangeElementsBaseVertex(draw_mode, 0, vertex_count, index_count, GL_UNSIGNED_SHORT, idx_offset,
            reinterpret_cast<usize>(vtx_offset) / sizeof(agiScreenVtx));
    }
    else
    {
        if (vtx_offset != last_vtx_offset_)
        {
            BindVertexAttribs(agiScreenVtx_Attribs, ARTS_SIZE(agiScreenVtx_Attribs), vtx_offset);
            last_vtx_offset_ = vtx_offset;
        }

        glDrawRangeElements(draw_mode, 0, vertex_count, index_count, GL_UNSIGNED_SHORT, idx_offset);
    }

    if (vbo_)
        vbo_->Discard();
}
