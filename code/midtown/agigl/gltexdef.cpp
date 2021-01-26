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

#include "gltexdef.h"

#include "agi/error.h"
#include "agiworld/texsheet.h"
#include "glerror.h"
#include "pcwindis/setupdata.h"
#include "vector7/vector2.h"

#include <glad/glad.h>

// clang-format off
static constexpr const u32 MultiplyDeBruijnBitPosition[32] = {
    0,  9,  1, 10, 13, 21,  2, 29, 11, 14, 16, 18, 22, 25, 3, 30,
    8, 12, 20, 28, 15, 17, 24,  7, 19, 27, 23,  6, 26,  5, 4, 31
};
// clang-format on

static u32 ilog2(u32 value)
{
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;

    return MultiplyDeBruijnBitPosition[static_cast<u32>(value * 0x07C4ACDD) >> 27];
}

static u32 CaluclateMipMapLevels(u32 width, u32 height)
{
    return 1 + ilog2(std::max(width, height));
}

i32 agiGLTexDef::BeginGfx()
{
    if (Surface == nullptr)
    {
        Errorf("Missing SurfaceDesc for '%s' in BeginGfx - trouble is brewing!", Tex.Name);
        return AGI_ERROR_FILE_NOT_FOUND;
    }

    if (Tex.Name[0] != '*' && page_state_ == 0 && cache_handle_ == 0)
    {
        Surface->Reload(Tex.Name, TexSearchPath, Tex.LOD, PackShift, 0, 0, 0); // TODO: Should this be PackShift & 0xF ?

        // FIXME: Surfaces with a PackShift don't have their pitch updated. This should really be corrected in agiSurfaceDesc::[Load/Reload]
        Surface->Pitch = Surface->Width * Surface->GetPixelSize();
    }

    // TODO: Fix thread safety/set context during PAGER startup
    if (wglGetCurrentContext() == NULL)
    {
        return AGI_ERROR_SUCCESS;
    }

    if (Tex.Props & agiTexProp::AlphaGlow && GetRendererInfo().AdditiveBlending)
        Tex.Flags &= ~agiTexParameters::Alpha;

    SurfaceSize = 0;

    agiSurfaceDesc* surface = Surface.get();

    bool color_key = (Tex.Flags & agiTexParameters::Chromakey) || (Surface->Flags & AGISD_CKSRCBLT);
    bool alpha_glow = (Tex.Props & agiTexProp::AlphaGlow);
    bool mip_maps = !(Tex.Flags & agiTexParameters::NoMipMaps) && (surface->Flags & AGISD_MIPMAPCOUNT);

    if (color_key || alpha_glow)
    {
        Ptr<agiSurfaceDesc> temp_surface =
            AsPtr(agiSurfaceDesc::Init(surface->Width, surface->Height, Pipe()->GetScreenFormat()));

        temp_surface->CopyFrom(Surface.get(), 0, &Tex);

        if (color_key)
        {
            ArAssert(temp_surface->PixelFormat.RGBAlphaBitMask == 0xFF000000, "Invalid Surface");

            for (u32 y = 0; y < temp_surface->Height; ++y)
            {
                u32* pixels =
                    reinterpret_cast<u32*>(static_cast<u8*>(temp_surface->Surface) + (y * temp_surface->Pitch));

                for (u32 x = 0; x < temp_surface->Width; ++x)
                    pixels[x] |= (pixels[x] & 0xFFFFFF) ? 0xFF000000 : 0;
            }

            Tex.Flags &= ~agiTexParameters::Chromakey;
            Tex.Flags |= agiTexParameters::Alpha;
        }

        surface = temp_surface.release();
        mip_maps = false;
    }

    GLenum format = 0;
    GLenum type = 0;

    switch (surface->PixelFormat.RBitMask)
    {
        case 0xF800: // 565
            format = GL_RGB;
            type = GL_UNSIGNED_SHORT_5_6_5;
            break;

        case 0xF00: // 4444
            format = GL_BGRA;
            type = GL_UNSIGNED_SHORT_4_4_4_4_REV;
            break;

        case 0xFF:
            format = surface->PixelFormat.RGBAlphaBitMask ? GL_RGBA : GL_RGB;
            type = GL_UNSIGNED_BYTE;
            break;

        case 0xFF0000:
            format = surface->PixelFormat.RGBAlphaBitMask ? GL_BGRA : GL_BGR;
            type = GL_UNSIGNED_BYTE;
            break;

        default: Quitf("Invalid Format");
    }

    i32 prev_texture = 0;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &prev_texture);

    glGenTextures(1, &texture_);
    glBindTexture(GL_TEXTURE_2D, texture_);

    // FIXME: Calculate alignment from pointer
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    GLenum internal = (Tex.Flags & agiTexParameters::Alpha) ? GL_RGBA8 : GL_RGB8;
    SurfaceSize = 0;

    i32 num_levels =
        mip_maps ? std::clamp<i32>(surface->MipMapCount, 1, CaluclateMipMapLevels(surface->Width, surface->Height)) : 1;

    if (Pipe()->HasExtension("GL_ARB_texture_storage"))
    {
        glTexStorage2D(GL_TEXTURE_2D, num_levels, internal, surface->Width, surface->Height);
    }
    else
    {
        for (i32 i = 0; i < num_levels; ++i)
        {
            i32 width = (std::max<i32>) (surface->Width >> i, 1);
            i32 height = (std::max<i32>) (surface->Height >> i, 1);

            glTexImage2D(GL_TEXTURE_2D, i, internal, width, height, 0, format, type, NULL);
        }
    }

    for (i32 i = 0; i < num_levels; ++i)
    {
        i32 width = (std::max<i32>) (surface->Width >> i, 1);
        i32 height = (std::max<i32>) (surface->Height >> i, 1);

        glTexSubImage2D(
            GL_TEXTURE_2D, i, 0, 0, width, height, format, type, static_cast<u8*>(surface->Surface) + SurfaceSize);

        SurfaceSize += (surface->Pitch >> i) * height;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, num_levels - 1);

    glTexParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (Tex.Flags & agiTexParameters::WrapU) ? GL_REPEAT : GL_CLAMP_TO_EDGE);
    glTexParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (Tex.Flags & agiTexParameters::WrapV) ? GL_REPEAT : GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (num_levels != 1)
    {
        if (u32 max_af = Pipe()->GetMaxAnisotropy(); max_af > 0)
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, static_cast<f32>(max_af));
    }
    else
    {
        Tex.Flags |= agiTexParameters::NoMipMaps;
    }

    if (surface != Surface.get())
    {
        surface->Unload();

        delete surface;
    }

    if (Tex.Name[0] != '*' && cache_handle_ == 0 && !(Tex.Flags & agiTexParameters::KeepLoaded))
        Surface->Unload();

    if ((EnablePaging & ARTS_PAGE_TEXTURES) && !(Tex.Flags & agiTexParameters::KeepLoaded) &&
        Pipe()->HasExtension("GL_ARB_sync"))
    {
        fence_ = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
    }

    // NOTE: Textures created by the pager NEED to be synchronied.
    //       This requires a glFlush (slow-ish) or glFenceSync (GL 3.2+).
    // glFlush();

    glBindTexture(GL_TEXTURE_2D, prev_texture);

    page_state_ = 0;
    state_ = 2;

    return AGI_ERROR_SUCCESS;
}

void agiGLTexDef::EndGfx()
{
    if (fence_)
    {
        glDeleteSync(static_cast<GLsync>(fence_));
        fence_ = nullptr;
    }

    if (texture_)
    {
        glDeleteTextures(1, &texture_);
        texture_ = 0;
    }

    if (temp_surface_)
    {
        temp_surface_->Unload();
        temp_surface_ = nullptr;
    }

    state_ = 0;
}

void agiGLTexDef::Set(Vector2& arg1, Vector2& arg2)
{
    arg1 = arg2;
}

b32 agiGLTexDef::Lock(agiTexLock& lock)
{
    if (!Surface || !Surface->Surface || !texture_)
        return false;

    if (temp_surface_ == nullptr)
    {
        temp_surface_ = AsPtr(agiSurfaceDesc::Init(Surface->Width, Surface->Height, *Surface));

        temp_surface_->CopyFrom(Surface.get(), 0);
    }

    lock.ColorModel = AsRaw(agiColorModel::FindMatch(temp_surface_.get()));
    lock.Width = temp_surface_->Width;
    lock.Height = temp_surface_->Height;
    lock.Pitch = temp_surface_->Pitch;
    lock.Surface = temp_surface_->Surface;

    return true;
}

void agiGLTexDef::Unlock(agiTexLock& lock)
{
    GLenum format = 0;
    GLenum type = 0;

    switch (lock.ColorModel->GetMaskR())
    {
        case 0xF800: // 565
            format = GL_RGB;
            type = GL_UNSIGNED_SHORT_5_6_5;
            break;

        case 0xF00: // 4444
            format = GL_BGRA;
            type = GL_UNSIGNED_SHORT_4_4_4_4_REV;
            break;

        case 0xFF:
            format = lock.ColorModel->BitCountA ? GL_RGBA : GL_RGB;
            type = GL_UNSIGNED_BYTE;
            break;

        case 0xFF0000:
            format = lock.ColorModel->BitCountA ? GL_BGRA : GL_BGR;
            type = GL_UNSIGNED_BYTE;
            break;

        default: Quitf("Invalid Format");
    }

    i32 prev_texture = 0;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &prev_texture);

    glBindTexture(GL_TEXTURE_2D, texture_);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, lock.Width, lock.Height, format, type, lock.Surface);

    lock.ColorModel->Release();
    lock = {};

    glBindTexture(GL_TEXTURE_2D, prev_texture);
}

b32 agiGLTexDef::IsAvailable()
{
    return state_ == 2;
}

void agiGLTexDef::Request()
{
    GetHandle();
}

u32 agiGLTexDef::GetHandle()
{
    if (state_ != 2)
    {
        if (!LockSurfaceIfResident())
        {
            PageInSurface();

            return 0;
        }
        if (BeginGfx() == AGI_ERROR_SUCCESS)
        {
            UnlockAndFreeSurface();
        }
        else
        {
            Warningf("agiGLTexDef::Request - Texture '%s' didn't init properly", Tex.Name);
        }
    }

    return CheckFence() ? texture_ : 0;
}

bool agiGLTexDef::CheckFence()
{
    if (fence_ == NULL)
        return true;

    GLenum status =
        glClientWaitSync(static_cast<GLsync>(fence_), 0, (Tex.Flags & agiTexParameters::KeepLoaded) ? 100000000 : 0);

    if (status == GL_TIMEOUT_EXPIRED)
        return false;

    glDeleteSync(static_cast<GLsync>(fence_));
    fence_ = nullptr;

    return true;
}
