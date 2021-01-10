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

define_dummy_symbol(mmeffects_mmtext);

#include "mmtext.h"

#include "agi/bitmap.h"
#include "agi/pipeline.h"

mmTextNode::mmTextNode() = default;
mmTextNode::~mmTextNode() = default;

void mmTextNode::Init(f32 x, f32 y, f32 width, f32 height, i32 num_lines, i32 flags)
{
    // NOTE: Originally assigned x_ and y_ after clamping width/height

    // line_count_ = 0;

    x_ = x;
    y_ = y;

    if (x < 1.0f)
    {
        if (width > 0.0f)
            width = std::min(width, 1.0f - x_);
        else
            width = 0.0f;
    }

    if (y < 1.0f)
    {
        if (height > 0.0f)
            height = std::min(height, 1.0f - y_);
        else
            height = 0.0f;
    }

    max_lines_ = num_lines;
    lines_ = MakeUnique<mmTextData[]>(num_lines);

    char name[256];
    arts_sprintf(name, "*TextNode:%p", this);

    text_bitmap_ = AsRc(Pipe()->CreateBitmap());

    // NOTE: This won't work with agiSWBitmap. agiSWBitmap::BeginGfx doesn't set its state, and is missing the added check whether the surface is null
    // FIXME: mmNumberFont::Load[Loc]Font uses mmText::Draw2 instead of mmTextNode::Cull, so it doesn't load the surface before drawing.
    if (Pipe()->IsHardware() && !(num_lines == 1 && x_ == 0.5f && y_ == 0.5f))
        flags |= AGI_BITMAP_UNLOAD_ALWAYS;

    text_bitmap_->Init(name, width * Pipe()->GetWidth(), height * Pipe()->GetHeight(), flags);

    // bg_color_ = 0xFFFFFF00
}

void mmTextNode::Cull()
{
    if (touched_ || text_bitmap_->NeedsReload())
    {
        agiSurfaceDesc* surface = text_bitmap_->GetSurface();
        surface->Load();

        RenderText(surface, lines_.get(), line_count_, enabled_lines_);
        text_bitmap_->EndGfx();
        text_bitmap_->SafeBeginGfx();

        touched_ = false;
    }

    if (!empty_)
    {
        i32 x = 0;
        i32 y = 0;

        if (x_ < 1.0f || y_ < 1.0f)
        {
            x = static_cast<i32>(Pipe()->GetWidth() * x_ + 0.5f);
            y = static_cast<i32>(Pipe()->GetHeight() * y_ + 0.5f);
        }
        else
        {
            x = static_cast<i32>(x_);
            y = static_cast<i32>(y_);
        }

        Pipe()->CopyBitmap(x, y, text_bitmap_.get(), 0, 0, text_bitmap_->GetWidth(), text_bitmap_->GetHeight());
    }
}

run_once([] {
    create_patch("", "", 0x4C0BF3, "\x51", 1);
    create_patch("", "", 0x4C0E8F, "\x51", 1);
    create_patch("", "", 0x4C0EA8, "\x55", 1);
});
