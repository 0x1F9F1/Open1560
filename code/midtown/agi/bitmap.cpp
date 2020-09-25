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

define_dummy_symbol(agi_bitmap);

#include "bitmap.h"

#include "data7/hash.h"
#include "error.h"
#include "pipeline.h"
#include "surface.h"

agiBitmap::agiBitmap(agiPipeline* pipe)
    : agiRefreshable(pipe)
{}

void agiBitmap::UpdateFlags()
{}

/*const*/ char* agiBitmap::GetName()
{
    static char buffer[64]; // FIXME: Static buffer
    arts_sprintf(buffer, "Bitmap '%s'", name_.get());
    return buffer;
}

i32 agiBitmap::Init(const char* name, f32 sx, f32 sy, i32 flags)
{
    EndGfx();

    name_ = name;
    flags_ = flags;

    if (name && *name != '*')
    {
        // NOTE: Orignial used agiPipeline::CurrentPipe for Width and Height
        surface_ = AsPtr(agiSurfaceDesc::Load(const_cast<char*>(name), BitmapSearchPath, 0, 0,
            (sx == 1.0f) ? Pipe()->GetWidth() : 0, (sy == 1.0f) ? Pipe()->GetHeight() : 0));

        if (surface_ == nullptr)
            return AGI_ERROR_FILE_NOT_FOUND;

        if (sx > 1.0f || sy > 1.0f)
        {
            width_scale_ = sx / 640.0f;
            height_scale_ = sy / 480.0f;

            width_ = static_cast<i32>(sx);
            height_ = static_cast<i32>(sy);
        }
        else
        {
            width_ = sx ? static_cast<i32>(Pipe()->GetWidth() * sx) : surface_->Width;
            height_ = sy ? static_cast<i32>(Pipe()->GetHeight() * sy) : surface_->Height;

            width_scale_ = sx;
            height_scale_ = sy;
        }
    }
    else
    {
        ArAssert(sx > 1.0f && sy > 1.0f, "Invalid Scale");

        width_scale_ = 0.0f;
        height_scale_ = 0.0f;

        width_ = static_cast<i32>(sx);
        height_ = static_cast<i32>(sy);

        surface_ = AsPtr(agiSurfaceDesc::Init(width_, height_, Pipe()->GetScreenFormat()));
    }

    return SafeBeginGfx();
}

void agiBitmap::SetTransparency(b32 enabled)
{
    if (enabled)
        flags_ |= AGI_BITMAP_TRANSPARENT;
    else
        flags_ &= ~AGI_BITMAP_TRANSPARENT;

    UpdateFlags();
}

agiBitmap::~agiBitmap()
{
    if (surface_)
        surface_->Unload();

    // TODO: Should this use width_ and height_ instead of width_scale_ and height_scale_?
    char buffer[64];
    arts_sprintf(buffer, "%s.%x.%x.%d", name_.get(), mem::bit_cast<u32>(width_scale_),
        mem::bit_cast<u32>(height_scale_), flags_);
    BitmapHash.Delete(buffer);
}
