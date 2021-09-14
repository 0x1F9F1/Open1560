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

define_dummy_symbol(mmeffects_mmnumber);

#include "mmnumber.h"
#include "agi/bitmap.h"
#include "agi/pipeline.h"
#include "arts7/cullmgr.h"
#include "data7/metadefine.h"
#include "mmtext.h"

aconst char* NUMBERSTRING = xconst("0123456789:,/.");

mmNumber::mmNumber() = default;
mmNumber::~mmNumber() = default;

void mmNumber::Cull()
{
    i32 x = 0;
    i32 y = 0;

    if (x_ < 1.0f || y_ < 1.0f)
    {
        x = static_cast<i32>(x_ * Pipe()->GetWidth());
        y = static_cast<i32>(y_ * Pipe()->GetHeight());
    }
    else
    {
        x = static_cast<i32>(x_);
        y = static_cast<i32>(y_);
    }

    for (usize i = 0; text_[i]; ++i)
    {
        if (const char* index = std::strchr(font_->Chars, text_[i]))
        {
            agiBitmap* bitmap = font_->Bitmaps[index - font_->Chars];
            Pipe()->CopyBitmap(x, y, bitmap, 0, 0, bitmap->GetWidth(), bitmap->GetHeight());
            x += bitmap->GetWidth();
        }
    }
}

#ifdef ARTS_DEV_BUILD
void mmNumber::AddWidgets(Bank* /*arg1*/)
{}
#endif

void mmNumber::Init(mmNumberFont* font, f32 x, f32 y)
{
    font_ = font;
    x_ = x;
    y_ = y;
}

void mmNumber::Printf(const char* format, ...)
{
    std::va_list va;
    va_start(va, format);
    arts_vsprintf(text_, format, va);
    va_end(va);
}

void mmNumber::SetString(char* text)
{
    arts_strcpy(text_, text);
}

void mmNumber::Update()
{
    CullMgr()->DeclareBitmap(this, font_->Bitmaps[0]);
}

META_DEFINE_CHILD("mmNumber", mmNumber, asNode)
{}

mmNumberFont::mmNumberFont()
    : mmNumberFont("0123456789:,/.")
{}

mmNumberFont::mmNumberFont(const char* chars)
    : Chars(chars)
    , Count(std::strlen(chars))
{}

mmNumberFont::~mmNumberFont()
{
    if (Bitmaps)
    {
        for (usize i = 0; i < Count; ++i)
            Bitmaps[i]->Release();

        delete[] Bitmaps;
    }

    mmText::DeleteFont(Font);
}

void mmNumberFont::LoadFont(char* font, i32 height, u32 color)
{
    Font = mmText::CreateFont(font, height);
    Init(color);
}

void mmNumberFont::LoadLocFont([[maybe_unused]] char* font, LocString* params, i32 screen_width, u32 color)
{
    Font = mmText::CreateLocFont(params, screen_width);
    Init(color);
}

void mmNumberFont::Init(u32 color)
{
    Bitmaps = new agiBitmap* [Count] {};

    for (usize i = 0; i < Count; ++i)
    {
        char letter[2] {Chars[i], '\0'};
        Bitmaps[i] = AsRaw(mmText::CreateFitBitmap(letter, Font, color, -1));
    }
}
