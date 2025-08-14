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

#include "mmtext.h"

#include "agi/bitmap.h"
#include "agi/cmodel.h"
#include "agi/pipeline.h"
#include "agi/rgba.h"
#include "agi/surface.h"
#include "core/utf8.h"
#include "data7/callback.h"
#include "data7/hash.h"
#include "localize/localize.h"
#include "midtown.h"
#include "stream/stream.h"

#include <unordered_map>
#include <vector>

#include <ft2build.h>

#include <freetype/freetype.h>
#include <freetype/ftmodapi.h>

struct mmSize
{
    i32 cx {};
    i32 cy {};
};

struct mmRect
{
    i32 left {};
    i32 top {};
    i32 right {};
    i32 bottom {};
};

struct mmGlyph
{
    u32 GlyphIndex {};

    i32 BitmapTop {};
    i32 BitmapLeft {};

    i32 AdvanceX {};

    u32 Rows {};
    u32 Width {};
    i32 Pitch {};
    Ptr<u8[]> Buffer;

    std::unordered_map<mmGlyph*, i32> Kerning;
};

struct mmLineInfo
{
    const char* Start {};
    const char* End {};
    i32 Left {};
    i32 Right {};
};

static HashTable FontHash {64, "FontHash"};

class mmFont
{
public:
    ~mmFont();

    i32 GetKerning(mmGlyph* glyph, mmGlyph* prev_glyph) const;

    void Draw(agiSurfaceDesc* surface, const char* text, mmRect rect, u32 color, u32 format);

    i32 GetLineHeight() const
    {
        return height_;
    }

    mmSize GetExtents(const char* text)
    {
        i32 right = 0;
        i32 height = 0;

        for (const auto& line : GetLines(text, 0))
        {
            right = std::max(right, line.Right);
            height += GetLineHeight();
        }

        return {right, height};
    }

    std::vector<mmLineInfo> GetLines(const char* text, i32 max_width);

    static mmFont* Create(const char* font_name, i32 height, i32 weight);

private:
    mmFont(const char* name, FT_Face face, i32 height)
        : face_(face)
        , height_(height)
        , ascender_(face_->size->metrics.ascender >> 6)
        , has_kerning_(FT_HAS_KERNING(face))
    {
        FontHash.Insert(name, this);
    }

    FT_Face face_ {};
    i32 height_ {};
    i32 ascender_ {};
    bool has_kerning_ {false};

    std::unordered_map<u32, mmGlyph> glyphs_;

    mmGlyph* LoadChar(u32 char_code);
};

static inline bool StopDecoding(u32 state)
{
    return (state == UTF8_ACCEPT) || (state == UTF8_REJECT);
}

// TODO: Handle encoding of foreign game files
static const u32 ErrorCodepoint = '?';

static inline u32 DecodeUTF8(const char** text)
{
    u32 codepoint = 0;
    u32 state = 0;
    const char* s = *text;

    while (*s)
    {
        if (StopDecoding(DecodeUTF8(&state, &codepoint, static_cast<unsigned char>(*s++))))
            break;
    }

    *text = s;

    if (state != UTF8_ACCEPT)
        codepoint = ErrorCodepoint;

    return codepoint;
}

static inline u32 DecodeUTF8(const char** text, const char* end)
{
    u32 codepoint = 0;
    u32 state = 0;
    const char* s = *text;

    while (s != end)
    {
        if (StopDecoding(DecodeUTF8(&state, &codepoint, static_cast<unsigned char>(*s++))))
            break;
    }

    *text = s;

    if (state != UTF8_ACCEPT)
        codepoint = ErrorCodepoint;

    return codepoint;
}

mmGlyph* mmFont::LoadChar(u32 char_code)
{
    if (auto find = glyphs_.find(char_code); find != glyphs_.end())
    {
        return &find->second;
    }

    FT_UInt glyph_index = FT_Get_Char_Index(face_, char_code);
    FT_Load_Glyph(face_, glyph_index, FT_LOAD_RENDER | FT_LOAD_MONOCHROME | FT_LOAD_TARGET_MONO);

    mmGlyph result {};

    result.GlyphIndex = glyph_index;
    result.BitmapLeft = face_->glyph->bitmap_left;
    result.BitmapTop = face_->glyph->bitmap_top;
    result.AdvanceX = face_->glyph->advance.x >> 6;

    result.Rows = face_->glyph->bitmap.rows;
    result.Width = face_->glyph->bitmap.width;
    result.Pitch = face_->glyph->bitmap.pitch;

    usize buffer_size = result.Rows * result.Pitch;
    result.Buffer = arnewa u8[buffer_size];
    std::memcpy(result.Buffer.get(), face_->glyph->bitmap.buffer, buffer_size);

    auto [iter, _] = glyphs_.emplace(char_code, std::move(result));

    return &iter->second;
}

i32 mmFont::GetKerning(mmGlyph* glyph, mmGlyph* prev_glyph) const
{
    i32 kerning_x = 0;

    if (has_kerning_ && prev_glyph)
    {
        if (auto find = glyph->Kerning.find(prev_glyph); find != glyph->Kerning.end())
        {
            kerning_x = find->second;
        }
        else
        {
            FT_Vector kerning {};
            FT_Get_Kerning(face_, prev_glyph->GlyphIndex, glyph->GlyphIndex, FT_KERNING_DEFAULT, &kerning);
            kerning_x = kerning.x >> 6;

            glyph->Kerning.emplace(prev_glyph, kerning_x);
        }
    }

    return kerning_x;
}

void mmFont::Draw(agiSurfaceDesc* surface, const char* text, mmRect rect, u32 color, u32 format)
{
    Rc<agiColorModel> cmodel = as_rc agiColorModel::FindMatch(surface);
    color = cmodel->GetColor(agiRgba::FromABGR(color | 0xFF000000));

    i32 x = rect.left;
    i32 y = rect.top;

    i32 rect_width = rect.right - rect.left;
    i32 rect_height = rect.bottom - rect.top;

    if (rect_width <= 0 || rect_height <= 0)
        return;

    u32 max_x = std::min<u32>(rect.right, surface->Width);
    u32 max_y = std::min<u32>(rect.bottom, surface->Height);

    std::vector<mmLineInfo> lines = GetLines(text, (format & MM_TEXT_WORDBREAK) ? rect_width : 0);

    if (format & (MM_TEXT_VCENTER | MM_TEXT_BOTTOM))
    {
        i32 text_height = lines.size() * GetLineHeight();

        if (format & MM_TEXT_VCENTER)
            y += (rect_height - text_height) / 2;
        else if (format & MM_TEXT_BOTTOM)
            y += (rect_height - text_height);
    }

    for (const auto& line : lines)
    {
        i32 line_x = x;
        i32 line_y = y;
        y += GetLineHeight();

        if (format & (MM_TEXT_CENTER | MM_TEXT_RIGHT))
        {
            i32 text_width = line.Right - line.Left;

            if (format & MM_TEXT_CENTER)
                line_x += (rect_width - text_width) / 2;
            else if (format & MM_TEXT_RIGHT)
                line_x += (rect_width - text_width);
        }

        line_x += line.Left;
        line_y += ascender_;

        const char* str = line.Start;
        u32 codepoint = 0;
        mmGlyph* prev_glyph = nullptr;

        while ((codepoint = DecodeUTF8(&str, line.End)) != 0)
        {
            mmGlyph* glyph = LoadChar(codepoint);

            line_x += GetKerning(glyph, prev_glyph);

            for (u32 src_y = 0, src_y_off = 0; src_y < glyph->Rows; ++src_y, src_y_off += glyph->Pitch)
            {
                u32 dst_y = line_y + src_y - glyph->BitmapTop;

                if (dst_y >= max_y)
                    continue;

                for (u32 src_x = 0; src_x < glyph->Width; ++src_x)
                {
                    u32 dst_x = line_x + src_x + glyph->BitmapLeft;

                    if (dst_x >= max_x)
                        continue;

                    if (glyph->Buffer[src_y_off + (src_x >> 3)] & (0x80 >> (src_x & 0x7)))
                        cmodel->SetPixel(surface, dst_x, dst_y, color);
                }
            }

            line_x += glyph->AdvanceX;
            prev_glyph = glyph;
        }
    }
}

mmFont::~mmFont()
{
    if (face_)
    {
        FT_Stream stream = face_->stream;
        FT_Done_Face(face_);
        delete stream;
    }
}

static void* mmFont_AllocFunc(FT_Memory, long size)
{
    return arts_malloc(static_cast<std::size_t>(size));
}

static void mmFont_FreeFunc(FT_Memory, void* block)
{
    arts_free(block);
}

static void* mmFont_ReallocFunc(FT_Memory, long, long new_size, void* block)
{
    return arts_realloc(block, static_cast<std::size_t>(new_size));
}

static unsigned long mmFont_IoFunc(FT_Stream stream, unsigned long offset, unsigned char* buffer, unsigned long count)
{
    Stream* file = static_cast<Stream*>(stream->descriptor.pointer);

    if (file->Seek(static_cast<i32>(offset)) != static_cast<i32>(offset))
        return count ? 0 : 1;

    return static_cast<unsigned long>(file->Read(buffer, static_cast<isize>(count)));
}

static void mmFont_CloseFunc(FT_Stream stream)
{
    delete static_cast<Stream*>(stream->descriptor.pointer);
}

static FT_Library mmFont_Library = nullptr;

static void mmFont_Shutdown()
{
    FontHash.Kill(nullptr, [](void*, const char*, void* value) { delete static_cast<mmFont*>(value); });
    FT_Done_Library(mmFont_Library);
    mmFont_Library = nullptr;
}

static FT_MemoryRec_ mmFont_MemoryRec {nullptr, mmFont_AllocFunc, mmFont_FreeFunc, mmFont_ReallocFunc};

std::vector<mmLineInfo> mmFont::GetLines(const char* text, i32 max_width)
{
    std::vector<mmLineInfo> lines;

    mmLineInfo curr_line {};
    mmLineInfo curr_word {};
    mmGlyph* prev_glyph = nullptr;

    const auto new_line = [&](const char* here) {
        curr_line.Start = here;
        curr_line.End = here;
        curr_line.Left = 0;
        curr_line.Right = 0;
        curr_word = curr_line;
        prev_glyph = nullptr;
    };

    const auto flush_line = [&] {
        lines.emplace_back(curr_line);
        new_line(curr_word.Start);
    };

    const auto flush_word = [&](const char* here) {
        curr_line.End = curr_word.End;
        curr_line.Right = curr_word.Right;
        curr_word.Start = here;
        curr_word.End = here;
        curr_word.Left = curr_word.Right;
    };

    new_line(text);

    while (true)
    {
        const char* here = curr_word.End;
        u32 codepoint = DecodeUTF8(&here);

        if ((codepoint == '\0') || IsSpace(codepoint))
        {
            // Word break
            if (max_width && (curr_word.Right >= max_width))
            {
                // If the word spans exactly to the end, or it's the only word on this line,
                // add it to the current line.
                if ((curr_word.Right == max_width) || (curr_word.Start == curr_line.Start))
                {
                    flush_word(here);
                }

                flush_line();

                continue;
            }

            flush_word(here);

            if (codepoint == '\0' || codepoint == '\n')
            {
                flush_line();

                if (codepoint == '\0')
                {
                    return lines;
                }

                continue;
            }
        }

        mmGlyph* glyph = LoadChar(codepoint);

        if (!prev_glyph && (glyph->BitmapLeft < 0))
        {
            curr_word.Left -= glyph->BitmapLeft;
            curr_word.Right = curr_word.Left;
        }

        curr_word.End = here;
        curr_word.Right += GetKerning(glyph, prev_glyph);
        curr_word.Right += glyph->AdvanceX;
        prev_glyph = glyph;
    }
}

mmFont* mmFont::Create(const char* font_name, i32 height, i32 weight)
{
    if (mmFont_Library == nullptr)
    {
        if (FT_New_Library(&mmFont_MemoryRec, &mmFont_Library))
            Quitf("Can't initialize FreeType");

        FT_Add_Default_Modules(mmFont_Library);

        OnGameReset.Append(mmFont_Shutdown);
    }

    const auto name = arts_formatf<256>("%s, %i, %i", font_name, height, weight);

    if (mmFont* font = static_cast<mmFont*>(FontHash.Access(name)))
    {
        return font;
    }

    // TODO: Support other fonts (Broadway, used by mmCDPlayer via mmHUD mmNumberFont)
    // TODO: Lookup file name for font

    CStringBuffer<256> font_path;
    font_path.append("FONT/");

    if (!std::strcmp(font_name, "Broadway"))
    {
        font_path.append("BROADW.TTF");
    }
    else if (!std::strcmp(font_name, "Gill Sans MT"))
    {
        if (weight >= 700)
            font_path.append("GILB____.TTF");
        else
            font_path.append("GIL_____.TTF");
    }
    else
    {
        // Unknown font (hope for the best)
        font_path.assign("C:\\WINDOWS\\FONTS\\VERDANA.TTF");
    }

    Ptr<Stream> file = as_ptr arts_fopen(font_path, "r");

    if (file == nullptr)
    {
        Errorf("Failed to open font %s", font_name);

        return nullptr;
    }

    FT_StreamRec* stream = new FT_StreamRec {};
    stream->size = file->Size();
    stream->read = mmFont_IoFunc;
    stream->close = mmFont_CloseFunc;
    stream->descriptor.pointer = file.release();

    FT_Open_Args args {};
    args.flags = FT_OPEN_STREAM;
    args.stream = stream;

    FT_Face face = nullptr;

    if (FT_Open_Face(mmFont_Library, &args, 0, &face))
    {
        Errorf("Failed to create font %s", font_name);
        delete stream;
        return nullptr;
    }

    FT_Set_Char_Size(face, 0, height << 6, 0, 54);

    return new mmFont(name, face, height);
}

void mmText::Draw(agiSurfaceDesc* surface, f32 x, f32 y, char* text, void* font_ptr)
{
    return Draw2(surface, x, y, text, font_ptr, 0xFFFFFF);
}

void mmText::Draw2(agiSurfaceDesc* surface, f32 x, f32 y, char* text, void* font_ptr, u32 color)
{
    mmFont* font = static_cast<mmFont*>(font_ptr);

    // NOTE: x and y are always 0
    mmRect rc {
        static_cast<i32>(Pipe()->GetWidth() * x),
        static_cast<i32>(Pipe()->GetHeight() * y),
        static_cast<i32>(surface->Width),
        static_cast<i32>(surface->Height),
    };

    surface->Load();
    surface->Clear();

    font->Draw(surface, text, rc, color, 0);
}

RcOwner<agiBitmap> mmText::CreateFitBitmap(char* text, void* font_ptr, i32 color, i32 bg_color)
{
    Rc<agiBitmap> bitmap = as_rc Pipe()->CreateBitmap();

    mmFont* font = static_cast<mmFont*>(font_ptr);

    mmSize size = font->GetExtents(text);
    size.cx += size.cx & 1;

    {
        i32 extra = (bg_color != -1) ? 2 : 0;

        bitmap->Init(arts_formatf<256>("*FitBitmap:%p", bitmap.get()), static_cast<f32>(size.cx + extra),
            static_cast<f32>(size.cy + extra), BITMAP_TRANSPARENT | BITMAP_OFFSCREEN);
    }

    if (bg_color != -1)
    {
        for (i32 i = 0; i <= 2; ++i)
        {
            for (i32 j = 0; j <= 2; ++j)
            {
                mmRect rc {};

                rc.left = i;
                rc.top = j;
                rc.right = i + size.cx;
                rc.bottom = j + size.cy;

                font->Draw(bitmap->GetSurface(), text, rc, TwiddleColor(bg_color), 0);
            }
        }
    }

    mmRect rc {0, 0, size.cx, size.cy};

    if (bg_color != -1)
    {
        rc.top += 1;
        rc.left += 1;
        rc.right += 1;
        rc.bottom += 1;
    }

    font->Draw(bitmap->GetSurface(), text, rc, TwiddleColor(color), 0);

    bitmap->EndGfx();
    bitmap->SafeBeginGfx();

    return as_owner bitmap;
}

void* mmText::CreateFont(const char* font_name, i32 height)
{
    return mmFont::Create(font_name, height, 400);
}

void* mmText::CreateLocFont(LocString* params, i32 screen_width)
{
    mmLocFontInfo loc_font(params);

    return mmFont::Create(
        loc_font.FontName, (screen_width >= 640) ? loc_font.HeightHigh : loc_font.HeightLow, loc_font.Weight);
}

void mmText::DeleteFont([[maybe_unused]] void* font)
{
    // static_cast<mmFont*>(font)->Release();
}

void* mmText::GetDC(agiSurfaceDesc*)
{
    return nullptr;
}

void mmText::ReleaseDC()
{}

void mmTextNode::GetTextDimensions(void* font_ptr, LocString* text, f32& width, f32& height)
{
    bool temp_font = false;

    if (font_ptr == nullptr)
    {
        // Called by MenuManager::InitCommonStuff with a null font.
        font_ptr = mmText::CreateFont("Gill Sans MT", 16);
        temp_font = true;
    }

    mmFont* font = static_cast<mmFont*>(font_ptr);
    mmSize size = font->GetExtents(text->Text);

    width = static_cast<f32>(size.cx) / Pipe()->GetWidth();
    height = static_cast<f32>(size.cy) / Pipe()->GetHeight();

    if (temp_font)
        mmText::DeleteFont(font_ptr);
}

void mmTextNode::RenderText(
    agiSurfaceDesc* surface, mmTextData* lines, [[maybe_unused]] i32 num_lines, u32 enabled_lines)
{
    surface->Clear();

    empty_ = true;

    for (i32 i = 0; i < num_lines; ++i)
    {
        if (!((1 << i) & enabled_lines))
            continue;

        mmTextData& line = lines[i];

        if ((std::strlen(line.Text) == 0) && !(line.Effects & MM_TEXT_REQUIRED))
            continue;

        empty_ = false;

        mmFont* font = static_cast<mmFont*>(line.Font);

        mmRect rc;
        rc.left = line.X;
        rc.top = line.Y;
        rc.right = surface->Width;
        rc.bottom = surface->Height;

        if (line.Effects & MM_TEXT_BORDER)
        {
            u32 border_color = 0xFFFFFF;

            surface->Fill(rc.left, rc.top, rc.right - rc.left, 1, border_color);
            surface->Fill(rc.left, rc.bottom - 1, rc.right - rc.left, 1, border_color);

            surface->Fill(rc.left, rc.top, 1, rc.bottom - rc.top, border_color);
            surface->Fill(rc.right - 1, rc.top, 1, rc.bottom - rc.top, border_color);
        }

        if ((line.Effects & MM_TEXT_PADDING) && (rc.right - rc.left) > 4)
        {
            rc.left += 3;
            rc.right -= 1;
        }

        i32 hl_color = 0x00FFFF;

        font->Draw(surface, line.Text, rc, (line.Effects & MM_TEXT_HIGHLIGHT) ? hl_color : fg_color_, line.Effects);
    }
}
