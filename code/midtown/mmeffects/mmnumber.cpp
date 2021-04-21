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
#include "agi/refresh.h"
#include "arts7/cullmgr.h"
#include "data7/metadefine.h"
#include "localize/localize.h"
#include "mmtext.h"

char* NUMBERSTRING = const_cast<char*>("0123456789:,/.");
const usize NUMBERSTRING_LEN = std::strlen(NUMBERSTRING);

mmNumber::mmNumber()
    : text_node_(MakeUnique<mmTextNode>())
{}

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
        if (char* letter = std::strchr(NUMBERSTRING, text_[i]))
        {
            usize index = letter - NUMBERSTRING;

            agiBitmap* bitmap = font_->TextNodes[index].GetBitmap();
            Pipe()->CopyBitmap(x, y, bitmap, 0, 0, bitmap->GetWidth(), bitmap->GetHeight());

            x += font_->CharWidths[index];
        }
    }
}

void mmNumber::AddWidgets(class Bank* /*arg1*/)
{}

void mmNumber::Init(mmNumberFont* font, f32 x, f32 y)
{
    font_ = font;
    text_node_->Init(x, y, font->CharWidth / 640.0f, font->CharHeight / 480.0f, 1, MM_TEXT_VCENTER);
    x_ = x;
    y_ = y;

    if (font_->Font)
        text_node_->AddText(font_->Font, LOC_TEXT("     "), 0, 0.0f, 0.0f);
}

void mmNumber::Printf(char const* format, ...)
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
    CULLMGR->DeclareBitmap(this, font_->TextNodes[0].GetBitmap());
}

META_DEFINE_CHILD("mmNumber", mmNumber, asNode)
{}

mmNumberFont::mmNumberFont()
    : Text(MakeUnique<mmText>())
    , TextNodes(MakeUnique<mmTextNode[]>(NUMBERSTRING_LEN))
    , CharWidths(MakeUnique<i32[]>(NUMBERSTRING_LEN))
{}

mmNumberFont::~mmNumberFont()
{
    mmText::DeleteFont(Font);
}

void mmNumberFont::LoadFont(char* font, i32 height, u32 color)
{
    Font = mmText::CreateFont(font, height);
    Init(height, color);
}

void mmNumberFont::LoadLocFont([[maybe_unused]] char* font, LocString* params, i32 screen_width, u32 color)
{
    Font = mmText::CreateLocFont(params, screen_width);

    mmLocFontInfo loc_font(params);
    Init((screen_width >= 640) ? loc_font.HeightHigh : loc_font.HeightLow, color);
}

void mmNumberFont::Init(i32 height, u32 color)
{
    CharWidth = static_cast<f32>(height);
    CharHeight = CharHeight;

    for (usize i = 0; i < NUMBERSTRING_LEN; ++i)
    {
        mmTextNode& node = TextNodes[i];
        node.Init(0.5f, 0.5f, CharWidth / Pipe()->GetWidth(), CharHeight / Pipe()->GetHeight(), 1, MM_TEXT_VCENTER);

        agiBitmap* bitmap = node.GetBitmap();

        char letter[2] {NUMBERSTRING[i], '\0'};
        Text->Draw2(bitmap->GetSurface(), 0.0f, 0.0f, letter, Font, color);

        bitmap->EndGfx();
        bitmap->SafeBeginGfx();

        f32 letter_width = 0.0f;
        f32 letter_height = 0.0f;
        node.GetTextDimensions(Font, LOC_TEXT(letter), letter_width, letter_height);

        CharWidths[i] = static_cast<i32>((Pipe()->GetWidth() * letter_width) + 2.0f);
    }
}
