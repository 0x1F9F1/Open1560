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
#include "localize/localize.h"

mmTextNode::mmTextNode() = default;
mmTextNode::~mmTextNode() = default;

void mmTextNode::Init(f32 x, f32 y, f32 width, f32 height, i32 num_lines, i32 flags)
{
    // NOTE: Originally clamped width/height

    x_ = x;
    y_ = y;

    line_count_ = 0;
    max_lines_ = num_lines;
    lines_ = MakeUnique<mmTextData[]>(num_lines);

    text_bitmap_ = as_rc Pipe()->CreateBitmap();
    text_bitmap_->Init(arts_formatf<256>("*TextNode:%p", this), width * Pipe()->GetWidth(),
        height * Pipe()->GetHeight(), flags | BITMAP_UNLOAD_ALWAYS);

    // hl_color_ = 0xFFFFFF00
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
            x = std::lround(x_ * Pipe()->GetWidth());
            y = std::lround(y_ * Pipe()->GetHeight());
        }
        else
        {
            x = std::lround(x_);
            y = std::lround(y_);
        }

        Pipe()->CopyBitmap(x, y, text_bitmap_.get(), 0, 0, text_bitmap_->GetWidth(), text_bitmap_->GetHeight());
    }
}

void mmTextNode::SetString(i32 line, LocString* text)
{
    if (!text)
        return;

    ArAssert(line < max_lines_, "Invalid line index");

    mmTextData& line_data = lines_[line];

    if (char* str = text->Text; (std::strlen(str) < ARTS_SIZE(line_data.Text)) && std::strcmp(str, line_data.Text))
    {
        arts_strcpy(line_data.Text, str);

        touched_ = true;
    }
}

mmLocFontInfo::mmLocFontInfo(LocString* params)
{
    Context = arts_strdup(params->Text);
    char* context = nullptr;

    FontName = arts_strtok(Context, ",", &context);

    HeightLow = std::atoi(arts_strtok(nullptr, ",", &context));
    HeightHigh = std::atoi(arts_strtok(nullptr, ",", &context));

    CharSet = std::atoi(arts_strtok(nullptr, ",", &context));
    Weight = std::atoi(arts_strtok(nullptr, ",", &context));
}

mmLocFontInfo::~mmLocFontInfo()
{
    arts_free(Context);
}
