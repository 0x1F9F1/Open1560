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

HashTable BitmapHash {64, "BitmapHash"};
aconst char* BitmapSearchPath = "bmp16"_xconst;

agiBitmap::agiBitmap(agiPipeline* pipe)
    : agiRefreshable(pipe)
{}

void agiBitmap::UpdateFlags()
{}

aconst char* agiBitmap::GetName()
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

    if (name && name[0] != '*')
    {
        // NOTE: Orignial used agiPipeline::CurrentPipe for Width and Height
        surface_ = as_ptr agiSurfaceDesc::Load(
            xconst(name), BitmapSearchPath, 0, 0, (sx == 1.0f) ? UI_Width : 0, (sy == 1.0f) ? UI_Height : 0);

        if (surface_ == nullptr)
            return AGI_ERROR_FILE_NOT_FOUND;

        if (sx > 1.0f || sy > 1.0f)
        {
            width_ = std::lround(sx);
            height_ = std::lround(sy);

            width_scale_ = width_ / 640.0f;
            height_scale_ = height_ / 480.0f;
        }
        else
        {
            width_ = sx ? UI_Width : surface_->Width;
            height_ = sy ? UI_Height : surface_->Height;

            width_scale_ = sx;
            height_scale_ = sy;
        }
    }
    else
    {
        ArAssert(sx > 1.0f && sy > 1.0f, "Invalid Scale");

        width_scale_ = 0.0f;
        height_scale_ = 0.0f;

        width_ = std::lround(sx);
        height_ = std::lround(sy);

        surface_ = as_ptr agiSurfaceDesc::Init(width_, height_, Pipe()->GetScreenFormat());
        surface_->Clear();
    }

    return SafeBeginGfx();
}

void agiBitmap::SetTransparency(b32 enabled)
{
    if (enabled)
        flags_ |= BITMAP_TRANSPARENT;
    else
        flags_ &= ~BITMAP_TRANSPARENT;

    UpdateFlags();
}

agiBitmap::~agiBitmap()
{
    if (surface_)
        surface_->Unload();

    // TODO: Should this use width_ and height_ instead of width_scale_ and height_scale_?
    BitmapHash.Delete(arts_formatf<64>(
        "%s.%x.%x.%d", name_.get(), mem::bit_cast<u32>(width_scale_), mem::bit_cast<u32>(height_scale_), flags_));
}
