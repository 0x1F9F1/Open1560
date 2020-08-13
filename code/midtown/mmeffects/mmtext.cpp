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

void mmTextNode::Cull()
{
    if (touched_)
    {
        RenderText(text_bitmap_->GetSurface(), lines_.get(), line_count_, enabled_lines_);
        text_bitmap_->EndGfx();
        text_bitmap_->SafeBeginGfx();

        touched_ = false;
    }

    if (!hidden_)
    {
        i32 x = 0;
        i32 y = 0;

        if (x_ < 1.0f || y_ < 1.0f)
        {
            x = static_cast<i32>(Pipe()->GetWidth() * x_ - -0.5f);
            y = static_cast<i32>(Pipe()->GetHeight() * y_ - -0.5f);
        }
        else
        {
            x = static_cast<i32>(x_);
            y = static_cast<i32>(y_);
        }

        Pipe()->CopyBitmap(x, y, text_bitmap_.get(), 0, 0, text_bitmap_->GetWidth(), text_bitmap_->GetHeight());
    }
}