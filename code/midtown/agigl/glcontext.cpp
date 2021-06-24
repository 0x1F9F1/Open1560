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

#include "glcontext.h"

#include <Windows.h>

#include <glad/glad.h>

#include <wglext.h>

PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = NULL;
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;
PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;

agiGLContext::agiGLContext(void* window_dc, void* gl_context, i32 debug_level)
    : window_dc_(window_dc)
    , gl_context_(gl_context)
    , debug_level_(debug_level)
{
    MakeCurrent();

    InitVersioning();
    InitExtensions();
}

agiGLContext::~agiGLContext()
{
    if (wglGetCurrentContext() == gl_context_)
        wglMakeCurrent(NULL, NULL);

    wglDeleteContext(static_cast<HGLRC>(gl_context_));

    if (agiGL == this)
        agiGL = nullptr;
}

void agiGLContext::MakeCurrent()
{
    // wglMakeCurrent causes a flush, which is slow
    if ((wglGetCurrentDC() != window_dc_) || (wglGetCurrentContext() != gl_context_))
        wglMakeCurrent(static_cast<HDC>(window_dc_), static_cast<HGLRC>(gl_context_));

    agiGL = this;
}

void* agiGLContext::GetProc(const char* name)
{
    void* result = wglGetProcAddress(name);

    if (result == nullptr)
        result = GetProcAddress(static_cast<HMODULE>(gl_module_), name);

    return result;
}

static void ParseExtensionString(HashTable& table, const char* extensions, isize category)
{
    char* exts = arts_strdup(extensions);

    if (exts == nullptr)
        return;

    for (char *curr = exts, *next = nullptr; curr; curr = next)
    {
        if (*curr == ' ')
            break;

        if (next = std::strchr(curr, ' '); next)
            *next++ = '\0';

        table.Insert(curr, (void*) category);
    }

    arts_free(exts);
}

void agiGLContext::InitVersioning()
{
    gl_module_ = GetModuleHandleA("opengl32.dll");

    auto agi_glGetString = (PFNGLGETSTRINGPROC) GetProc("glGetString");

    const char* gl_version = (const char*) agi_glGetString(GL_VERSION);

    Displayf("OpenGL Version: %s", gl_version);

    i32 major_version = 0;
    i32 minor_version = 0;

    if (arts_sscanf(gl_version, "%i.%i", &major_version, &minor_version) != 2)
        Quitf("Failed to get OpenGL version");

    gl_version_ = (major_version * 100) + (minor_version * 10);
    context_flags_ = 0;
    profile_mask_ = 0;

    if (HasVersion(300))
    {
        auto agi_glGetIntegerv = (PFNGLGETINTEGERVPROC) GetProc("glGetIntegerv");

        agi_glGetIntegerv(GL_MAJOR_VERSION, &major_version);
        agi_glGetIntegerv(GL_MINOR_VERSION, &minor_version);
        gl_version_ = (major_version * 100) + (minor_version * 10);

        agi_glGetIntegerv(GL_CONTEXT_FLAGS, &context_flags_);

        if (HasVersion(320))
            agi_glGetIntegerv(GL_CONTEXT_PROFILE_MASK, &profile_mask_);

        i32 num_extensions = 0;
        agi_glGetIntegerv(GL_NUM_EXTENSIONS, &num_extensions);

        auto agi_glGetStringi = (PFNGLGETSTRINGIPROC) GetProc("glGetStringi");

        for (i32 i = 0; i < num_extensions; ++i)
        {
            if (const char* ext = (const char*) agi_glGetStringi(GL_EXTENSIONS, i))
                extensions_.Insert(ext, (void*) 2);
        }
    }
    else if (HasVersion(110))
    {
        ParseExtensionString(extensions_, (const char*) agi_glGetString(GL_EXTENSIONS), 1);
    }

    {
        auto agi_wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC) GetProc("wglGetExtensionsStringARB");
        auto agi_wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC) GetProc("wglGetExtensionsStringEXT");

        const char* wgl_exts = nullptr;

        if (agi_wglGetExtensionsStringARB)
            wgl_exts = agi_wglGetExtensionsStringARB(static_cast<HDC>(window_dc_));
        else if (agi_wglGetExtensionsStringEXT)
            wgl_exts = agi_wglGetExtensionsStringEXT();

        if (wgl_exts)
            ParseExtensionString(extensions_, wgl_exts, 3);
    }

    Displayf("OpenGL Extension Count: %i", extensions_.Size());

    shader_version_ = 0;

    if (HasVersion(200))
    {
        const char* glsl_version = (const char*) agi_glGetString(GL_SHADING_LANGUAGE_VERSION);

        if (HasVersion(330))
        {
            shader_version_ = gl_version_;
        }
        else
        {
            i32 glsl_major_version = 0;
            i32 glsl_minor_version = 0;

            if (arts_sscanf(glsl_version, "%i.%i", &glsl_major_version, &glsl_minor_version) != 2)
                Quitf("Failed to get GLSL version");

            shader_version_ = (glsl_major_version * 100) + glsl_minor_version;
        }

        Displayf("OpenGL Shader Version: %i (%s)", shader_version_, glsl_version);
    }
}

void agiGLContext::InitExtensions()
{
    if (HasExtension("WGL_ARB_pixel_format"))
    {
        wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC) GetProc("wglChoosePixelFormatARB");
    }

    if (HasExtension("WGL_ARB_create_context"))
    {
        wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC) GetProc("wglCreateContextAttribsARB");
    }

    if (HasExtension("WGL_EXT_swap_control"))
    {
        wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC) GetProc("wglSwapIntervalEXT");
    }
}

static void APIENTRY GlDebugMessageCallback([[maybe_unused]] GLenum source, GLenum type, [[maybe_unused]] GLuint id,
    GLenum severity, [[maybe_unused]] GLsizei length, const GLchar* message, [[maybe_unused]] const void* userParam)
{
    i32 print_level = 2;
    const char* level = "Unknown";
    const char* type_name = "Unknown";

    switch (severity)
    {
        case GL_DEBUG_SEVERITY_HIGH:
            level = "High";
            print_level = 2;
            break;
        case GL_DEBUG_SEVERITY_MEDIUM:
            level = "Medium";
            print_level = 1;
            break;
        case GL_DEBUG_SEVERITY_LOW:
            level = "Low";
            print_level = 0;
            break;
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            level = "Notification";
            print_level = 0;
            break;
    }

    switch (type)
    {
        case GL_DEBUG_TYPE_ERROR: type_name = "Error"; break;
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: type_name = "Deprecated Behaviour"; break;
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: type_name = "Undefined Behaviour"; break;
        case GL_DEBUG_TYPE_PORTABILITY: type_name = "Portability"; break;
        case GL_DEBUG_TYPE_PERFORMANCE: type_name = "Performance"; break;
        case GL_DEBUG_TYPE_OTHER: type_name = "Other"; break;
        case GL_DEBUG_TYPE_MARKER: type_name = "Marker"; break;
        case GL_DEBUG_TYPE_PUSH_GROUP: type_name = "Push Group"; break;
        case GL_DEBUG_TYPE_POP_GROUP: type_name = "Pop Group"; break;
    }

    Printerf(print_level, "OpenGL: %s (%s): %s", type_name, level, message);
}

static mem::cmd_param PARAM_afilter {"afilter"};

void agiGLContext::Init()
{
    if (debug_level_ > 1)
    {
        Displayf("OpenGL Extensions:");

        for (HashIterator i(extensions_); i.Next();)
            Displayf("    %s", i->Key.get());

        Displayf("");
    }

    if ((debug_level_ < 0) || (context_flags_ & GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR))
        error_count_ = -1;
    else if (debug_level_ > 0)
        error_count_ = 1;
    else
        error_count_ = 0;

    if ((context_flags_ & GL_CONTEXT_FLAG_DEBUG_BIT) && HasExtension(/*430,*/ "GL_KHR_debug"))
    {
        Displayf("Using glDebugMessageCallback");

        glDebugMessageCallback(GlDebugMessageCallback, nullptr);

#define X(SEVERITY, LEVEL) glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, SEVERITY, 0, NULL, debug_level_ >= LEVEL)
        X(GL_DEBUG_SEVERITY_HIGH, 0);
        X(GL_DEBUG_SEVERITY_MEDIUM, 1);
        X(GL_DEBUG_SEVERITY_LOW, 3);
        X(GL_DEBUG_SEVERITY_NOTIFICATION, 4);
#undef X

        if (debug_level_ >= 2)
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

        glEnable(GL_DEBUG_OUTPUT);
    }

    direct_state_access_ = IsCoreProfile() && HasExtension(/*450,*/ "GL_ARB_direct_state_access");
    max_anisotropy_ = 0;

    if (HasExtension("GL_EXT_texture_filter_anisotropic"))
    {
        glGetIntegerv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &max_anisotropy_);
        max_anisotropy_ = (std::min) (max_anisotropy_, PARAM_afilter.get_or(16));
        Displayf("Max Anisotropy = %i", max_anisotropy_);
    }

    // Set defaults
    depth_mask_ = true;
    polygon_mode_ = GL_FILL;
    depth_func_ = GL_LESS;
    front_face_ = GL_CCW;
    blend_func_s_ = GL_ONE;
    blend_func_d_ = GL_ZERO;
}

static const char* GetGLErrorName(u32 error)
{
    switch (error)
    {
        case GL_INVALID_ENUM: return "Invalid Enum";
        case GL_INVALID_VALUE: return "Invalid Value";
        case GL_INVALID_OPERATION: return "Invalid Operation";
        case GL_INVALID_FRAMEBUFFER_OPERATION: return "Invalid Framebuffer Operation";
        case GL_OUT_OF_MEMORY: return "Out Of Memory";
        case GL_STACK_UNDERFLOW: return "Stack Underflow";
        case GL_STACK_OVERFLOW: return "Stack Overflow";
        default: return "Unknown";
    }
}

void agiGLContext::CheckErrors(bool lazy)
{
    if (error_count_ < (lazy ? 1 : 0))
        return;

    if (error_count_ >= 100)
        return;

    for (u32 error; (error = glGetError()) != GL_NO_ERROR;)
    {
        Errorf("GL Error: %s (%08X)", GetGLErrorName(error), error);

        if (++error_count_ >= 100)
        {
            Errorf("GL: Too many errors!");

            break;
        }
    }
}

void agiGLContext::ActiveTexture(u32 unit)
{
    if (unit != active_texture_unit_)
    {
        active_texture_unit_ = unit;

        glActiveTexture(GL_TEXTURE0 + unit);
    }
}

void agiGLContext::BindTextureUnit(u32 target, u32 texture, u32 unit)
{
    if (direct_state_access_)
    {
        glBindTextureUnit(unit, texture);
    }
    else
    {
        ActiveTexture(unit);
        glBindTexture(target, texture);
    }
}

static u32 GetCapabilityIndex(u32 cap)
{
    switch (cap)
    {
        case GL_BLEND: return 0;
        case GL_CULL_FACE: return 1;
        case GL_DEPTH_TEST: return 2;
        case GL_SCISSOR_TEST: return 3;
        case GL_ALPHA_TEST: return 4;
        case GL_FOG: return 5;

        default: Quitf("Invalid Capability %X", cap);
    }
}

void agiGLContext::EnableDisable(u32 cap, bool enable)
{
    bool& enabled = capabilities_[GetCapabilityIndex(cap)];

    if (enabled != enable)
    {
        enabled = enable;
        (enable ? glEnable : glDisable)(cap);
    }
}

void agiGLContext::DepthMask(bool enable)
{
    if (depth_mask_ != enable)
    {
        depth_mask_ = enable;
        glDepthMask(enable);
    }
}

void agiGLContext::PolygonMode(u32 mode)
{
    if (polygon_mode_ != mode)
    {
        polygon_mode_ = mode;
        glPolygonMode(GL_FRONT_AND_BACK, mode);
    }
}

void agiGLContext::DepthFunc(u32 func)
{
    if (depth_func_ != func)
    {
        depth_func_ = func;
        glDepthFunc(func);
    }
}

void agiGLContext::FrontFace(u32 face)
{
    if (front_face_ != face)
    {
        front_face_ = face;
        glFrontFace(face);
    }
}

void agiGLContext::BlendFunc(u32 sfactor, u32 dfactor)
{
    if (blend_func_s_ != sfactor || blend_func_d_ != dfactor)
    {
        blend_func_s_ = sfactor;
        blend_func_d_ = dfactor;
        glBlendFunc(blend_func_s_, blend_func_d_);
    }
}
