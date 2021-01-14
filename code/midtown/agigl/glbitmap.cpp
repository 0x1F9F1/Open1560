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
    if (tex_def_)
    {
        tex_def_->Surface->Surface = nullptr;
        tex_def_->EndGfx();
        tex_def_ = nullptr;
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
            surface_->Reload(name_.get(), BitmapSearchPath, 0, 0, 0, 0, 0);

        width_ = surface_->Width;
        height_ = surface_->Height;
    }
    else
    {
        width_ = static_cast<i32>(UI_Width * width_scale_ + 0.5f);
        height_ = static_cast<i32>(UI_Height * height_scale_ + 0.5f);

        if (name_[0] != '*')
            surface_->Reload(name_.get(), BitmapSearchPath, 0, 0, 0, width_, height_);
    }

    if (surface_->Surface == nullptr)
        return AGI_ERROR_OBJECT_EMPTY;

    tex_def_ = AsRc(Pipe()->CreateTexDef());

    Ptr<agiSurfaceDesc> surface = MakeUnique<agiSurfaceDesc>(*surface_);

    agiTexParameters params {};
    arts_strcpy(params.Name, "*");
    arts_strcat(params.Name, name_.get());
    params.Flags |= agiTexParameters::NoMipMaps | agiTexParameters::KeepLoaded;

    if (IsTransparent())
    {
        surface->Flags |= AGISD_CKSRCBLT;
        params.Flags |= agiTexParameters::Chromakey;
    }

    if (tex_def_->Init(params, std::move(surface)) != AGI_ERROR_SUCCESS)
    {
        return AGI_ERROR_UNSUPPORTED;
    }

    if (name_[0] != '*' || (flags_ & AGI_BITMAP_UNLOAD_ALWAYS))
    {
        tex_def_->Surface->Surface = nullptr;

        surface_->Unload();
    }

    state_ = 1;

    UpdateFlags();

    return AGI_ERROR_SUCCESS;
}
