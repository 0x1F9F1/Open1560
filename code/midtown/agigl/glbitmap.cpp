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

#include "glbitmap.h"

#include "agi/error.h"
#include "agi/pipeline.h"

#include <glad/glad.h>

void agiGLBitmap::EndGfx()
{
    if (texture_)
    {
        glDeleteTextures(1, &texture_);
        texture_ = 0;
    }

    state_ = 0;
}

i32 agiGLBitmap::BeginGfx()
{
    if (!Pipe()->HaveGfxStarted())
        return AGI_ERROR_SUCCESS;

    if (state_ != 0)
        return AGI_ERROR_ALREADY_INITIALIZED;

    if (surface_ == nullptr)
        return AGI_ERROR_OBJECT_EMPTY;

    if (width_scale_ == 0.0f || height_scale_ == 0.0f)
    {
        if (name_[0] != '*')
            surface_->Reload(const_cast<char*>(name_.get()), BitmapSearchPath, 0, 0, 0, 0, 0);

        width_ = surface_->Width;
        height_ = surface_->Height;
    }
    else
    {
        width_ = static_cast<i32>(Pipe()->GetWidth() * width_scale_ + 0.5f);
        height_ = static_cast<i32>(Pipe()->GetHeight() * height_scale_ + 0.5f);

        if (name_[0] != '*')
            surface_->Reload(const_cast<char*>(name_.get()), BitmapSearchPath, 0, 0, 0, width_, height_);
    }

    if (surface_->Surface == nullptr)
        return AGI_ERROR_OBJECT_EMPTY;

    glGenTextures(1, &texture_);
    glBindTexture(GL_TEXTURE_2D, texture_);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    if (IsTransparent())
    {
        Ptr<agiSurfaceDesc> gl_surface = AsPtr(agiSurfaceDesc::Init(width_, height_, Pipe()->GetScreenFormat()));

        gl_surface->CopyFrom(surface_.get(), 0);

        ArAssert(gl_surface->PixelFormat.RGBAlphaBitMask == 0xFF000000, "Invalid Surface");

        for (u32 y = 0; y < gl_surface->Height; ++y)
        {
            u32* pixels = reinterpret_cast<u32*>(static_cast<u8*>(gl_surface->Surface) + (y * gl_surface->Pitch));

            for (u32 x = 0; x < gl_surface->Width; ++x)
                pixels[x] |= pixels[x] ? 0xFF000000 : 0;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, gl_surface->Width, gl_surface->Height, 0, GL_BGRA, GL_UNSIGNED_BYTE,
            gl_surface->Surface);

        gl_surface->Unload();
    }
    else
    {
        GLenum format = 0;
        GLenum type = 0;
        GLenum internal = 0;

        switch (surface_->PixelFormat.RBitMask)
        {
            case 0xF800: // 565
                format = GL_RGB;
                type = GL_UNSIGNED_SHORT_5_6_5;
                internal = GL_RGB;
                break;

            case 0xF00: // 4444
                format = GL_BGRA;
                type = GL_UNSIGNED_SHORT_4_4_4_4_REV;
                internal = GL_RGBA;
                break;

            case 0xFF:
                format = surface_->PixelFormat.RGBAlphaBitMask ? GL_RGBA : GL_RGB;
                type = GL_UNSIGNED_BYTE;
                internal = surface_->PixelFormat.RGBAlphaBitMask ? GL_RGBA : GL_RGB;
                break;

            case 0xFF0000:
                format = surface_->PixelFormat.RGBAlphaBitMask ? GL_BGRA : GL_BGR;
                type = GL_UNSIGNED_BYTE;
                internal = surface_->PixelFormat.RGBAlphaBitMask ? GL_RGBA : GL_RGB;
                break;

            default: Quitf("Invalid Format");
        }

        glTexImage2D(GL_TEXTURE_2D, 0, internal, surface_->Width, surface_->Height, 0, format, type, surface_->Surface);
    }

    if (name_[0] != '*' || (flags_ & AGI_BITMAP_UNLOAD_ALWAYS))
        surface_->Unload();

    state_ = 1;

    UpdateFlags();

    glBindTexture(GL_TEXTURE_2D, 0);

    return AGI_ERROR_SUCCESS;
}
