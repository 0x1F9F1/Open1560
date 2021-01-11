#include "mmtext.h"

#include "agi/bitmap.h"
#include "agi/cmodel.h"
#include "agi/pipeline.h"
#include "agi/rgba.h"
#include "agi/surface.h"
#include "data7/callback.h"
#include "data7/hash.h"
#include "localize/localize.h"
#include "midtown.h"
#include "stream/stream.h"

#include <ft2build.h>

#include <freetype/freetype.h>
#include <freetype/ftmodapi.h>

struct mmSize
{
    i32 cx {0};
    i32 cy {0};
};

struct mmRect
{
    i32 left {0};
    i32 top {0};
    i32 right {0};
    i32 bottom {0};
};

#define MM_DT_CENTER 0x00000001
#define MM_DT_RIGHT 0x00000002
#define MM_DT_VCENTER 0x00000004
#define MM_DT_BOTTOM 0x00000008
#define MM_DT_WORDBREAK 0x00000010
#define MM_DT_SINGLELINE 0x00000020
#define MM_DT_NOPREFIX 0x00000800

static HashTable FontHash {64, "FontHash"};

class mmFont
{
private:
    mmFont(const char* name, FT_Face face, i32 height)
        : face_(face)
        , height_(height)
    {
        arts_strcpy(name_, name);

        FontHash.Insert(name_, this);
    }

    ~mmFont()
    {
        Kill();
    }

    FT_Face face_ {nullptr};
    char name_[256] {};
    i32 height_ {0};

public:
    void Draw(agiSurfaceDesc* surface, const char* text, mmRect rect, u32 color, u32 format);
    void Kill();

    i32 GetWidth(const char* text);

    i32 GetHeight()
    {
        return height_;
    }

    mmSize GetExtents(const char* text)
    {
        return {GetWidth(text), GetHeight()};
    }

    static mmFont* Create(const char* font_name, i32 height, i32 weight);
};

i32 mmFont::GetWidth(const char* text)
{
    i32 width = 0;

    for (usize i = 0; text[i]; ++i)
    {
        u32 glyph_index = FT_Get_Char_Index(face_, static_cast<unsigned char>(text[i]));

        FT_Load_Glyph(face_, glyph_index, FT_LOAD_TARGET_MONO);

        if (i == 0)
            width -= face_->glyph->bitmap_left << 6;

        width += face_->glyph->advance.x;
    }

    return (width + 63) >> 6;
}

void mmFont::Draw(agiSurfaceDesc* surface, const char* text, mmRect rect, u32 color, u32 format)
{
    Rc<agiColorModel> cmodel = AsRc(agiColorModel::FindMatch(surface));

    i32 x = rect.left;
    i32 y = rect.top;

    i32 width = rect.right - rect.left;
    i32 height = rect.bottom - rect.top;

    if (format & (MM_DT_CENTER | MM_DT_RIGHT))
    {
        i32 text_width = GetWidth(text);

        if (format & MM_DT_CENTER)
            x += (width - text_width) / 2;
        else if (format & MM_DT_RIGHT)
            x += (width - text_width);
    }

    if (format & (MM_DT_VCENTER | MM_DT_BOTTOM))
    {
        i32 text_height = GetHeight();

        if (format & MM_DT_VCENTER)
            y += (height - text_height) / 2;
        else if (format & MM_DT_BOTTOM)
            y += (height - text_height);
    }

    x <<= 6;
    y <<= 6;

    y += face_->size->metrics.ascender;

    color = cmodel->GetColor(agiRgba::FromABGR(color | 0xFF000000));

    width = std::min<i32>(rect.right, surface->Width);
    height = std::min<i32>(rect.bottom, surface->Height);

    for (usize i = 0; text[i]; ++i)
    {
        u32 glyph_index = FT_Get_Char_Index(face_, static_cast<unsigned char>(text[i]));

        FT_Load_Glyph(face_, glyph_index, FT_LOAD_RENDER | FT_LOAD_MONOCHROME | FT_LOAD_TARGET_MONO);

        if (i == 0)
            x -= face_->glyph->bitmap_left << 6;

        for (u32 src_y = 0; src_y < face_->glyph->bitmap.rows; ++src_y)
        {
            u32 src_y_off = src_y * face_->glyph->bitmap.pitch;

            u32 dst_y = (y >> 6) + src_y - face_->glyph->bitmap_top;

            if (static_cast<i32>(dst_y) >= height)
                continue;

            for (u32 src_x = 0; src_x < face_->glyph->bitmap.width; ++src_x)
            {
                u32 dst_x = (x >> 6) + src_x + face_->glyph->bitmap_left;

                if (static_cast<i32>(dst_x) >= width)
                    continue;

                if (face_->glyph->bitmap.buffer[src_y_off + (src_x >> 3)] & (0x80 >> (src_x & 0x7)))
                    cmodel->SetPixel(surface, dst_x, dst_y, color);
            }
        }

        x += face_->glyph->advance.x;
    }
}

void mmFont::Kill()
{
    if (face_)
    {
        FT_Stream stream = face_->stream;
        FT_Done_Face(face_);
        delete stream;

        FontHash.Delete(name_);

        face_ = nullptr;
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

    return file->Read(buffer, static_cast<i32>(count));
};

static void mmFont_CloseFunc(FT_Stream stream)
{
    delete static_cast<Stream*>(stream->descriptor.pointer);
};

static FT_Library mmFont_Library = nullptr;

static void mmFont_Shutdown()
{
    FontHash.Kill(nullptr, [](void*, const char* key, void*) { Displayf("Font '%s' Leaked", key); });

    FT_Done_Library(mmFont_Library);

    mmFont_Library = nullptr;
}

static FT_MemoryRec_ mmFont_MemoryRec {nullptr, mmFont_AllocFunc, mmFont_FreeFunc, mmFont_ReallocFunc};

mmFont* mmFont::Create(const char* font_name, i32 height, i32 weight)
{
    if (mmFont_Library == nullptr)
    {
        if (FT_New_Library(&mmFont_MemoryRec, &mmFont_Library))
            Quitf("Can't initialize FreeType");

        FT_Add_Default_Modules(mmFont_Library);

        GameResetCallbacks.Append(CFA(mmFont_Shutdown));
    }

    char name[256];
    arts_sprintf(name, "%s, %i, %i", font_name, height, weight);

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
    else // Gill Sans MT
    {
        if (weight >= 700)
            font_path.append("GILB____.TTF");
        else
            font_path.append("GIL_____.TTF");
    }

    Stream* file = arts_fopen(font_path, "r");

    if (file == nullptr)
    {
        Errorf("Failed to open font %s", font_name);

        return nullptr;
    }

    FT_StreamRec* stream = new FT_StreamRec {};
    stream->descriptor.pointer = file;
    stream->size = file->Size();
    stream->read = mmFont_IoFunc;
    stream->close = mmFont_CloseFunc;

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
    mmFont* font = static_cast<mmFont*>(font_ptr);

    i32 screen_x = static_cast<i32>(Pipe()->GetWidth() * x);
    i32 screen_y = static_cast<i32>(Pipe()->GetHeight() * y);

    mmSize size = font->GetExtents(text);

    mmRect rc {};

    rc.left = screen_x;
    rc.top = screen_y;
    rc.right = screen_x + size.cx;
    rc.bottom = screen_y + size.cy;

    surface->Clear();

    font->Draw(surface, text, rc, 0xFFFFFF, 0);
}

void mmText::Draw2(agiSurfaceDesc* surface, f32 x, f32 y, char* text, void* font_ptr, u32 color)
{
    mmFont* font = static_cast<mmFont*>(font_ptr);

    i32 screen_x = static_cast<i32>(Pipe()->GetWidth() * x);
    i32 screen_y = static_cast<i32>(Pipe()->GetHeight() * y);

    mmSize size = font->GetExtents(text);

    mmRect rc {};

    rc.left = screen_x;
    rc.top = screen_y;
    rc.right = screen_x + size.cx;
    rc.bottom = screen_y + size.cy;

    surface->Clear();

    font->Draw(surface, text, rc, color, MM_DT_RIGHT);
}

RcOwner<agiBitmap> mmText::CreateFitBitmap(char* text, void* font_ptr, i32 color, i32 bg_color)
{
    Rc<agiBitmap> bitmap = AsRc(Pipe()->CreateBitmap());

    mmFont* font = static_cast<mmFont*>(font_ptr);

    mmSize size = font->GetExtents(text);
    size.cx += size.cx & 1;

    {
        char name[256];
        arts_sprintf(name, "*FitBitmap:%p", bitmap.get());

        i32 extra = (bg_color != -1) ? 2 : 0;

        bitmap->Init(name, static_cast<f32>(size.cx + extra), static_cast<f32>(size.cy + extra),
            AGI_BITMAP_TRANSPARENT | AGI_BITMAP_OFFSCREEN);
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

                font->Draw(bitmap->GetSurface(), text, rc, bg_color, MM_DT_NOPREFIX);
            }
        }
    }

    mmRect rc {};

    rc.top = 0;
    rc.left = 0;
    rc.right = size.cx;
    rc.bottom = size.cy;

    if (bg_color != -1)
    {
        rc.top += 1;
        rc.left += 1;
        rc.right += 1;
        rc.bottom += 1;
    }

    font->Draw(bitmap->GetSurface(), text, rc, color, MM_DT_NOPREFIX);

    bitmap->EndGfx();
    bitmap->SafeBeginGfx();

    return AsOwner(bitmap);
}

void* mmText::CreateFont(const char* font_name, i32 height)
{
    return mmFont::Create(font_name, height, 400);
}

void* mmText::CreateLocFont(LocString* params, i32 screen_width)
{
    char* split_params = arts_strdup(params->Text);
    char* split_context = nullptr;

    char* font_name = arts_strtok(split_params, ",", &split_context);

    i32 height_low = std::atoi(arts_strtok(nullptr, ",", &split_context));
    i32 height_high = std::atoi(arts_strtok(nullptr, ",", &split_context));

    // FIXME: Use this param
    [[maybe_unused]] i32 char_set = std::atoi(arts_strtok(nullptr, ",", &split_context));

    i32 weight = std::atoi(arts_strtok(nullptr, ",", &split_context));

    mmFont* result = mmFont::Create(font_name, (screen_width >= 640) ? height_high : height_low, weight);

    arts_free(split_params);

    return result;
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

        format_ = MM_DT_NOPREFIX;
        empty_ = false;

        mmFont* font = static_cast<mmFont*>(line.Font);

        mmRect rc {};

        rc.left = line.X;
        rc.top = line.Y;
        rc.right = surface->Width;
        rc.bottom = surface->Height;

        if (line.Effects)
        {
            if (line.Effects & MM_TEXT_CENTER)
                format_ |= MM_DT_CENTER;

            if (line.Effects & MM_TEXT_VCENTER)
                format_ |= MM_DT_VCENTER | MM_DT_SINGLELINE;

            if (line.Effects & MM_TEXT_WORDBREAK)
                format_ |= MM_DT_WORDBREAK;

            if (line.Effects & MM_TEXT_BORDER)
            {
                u32 fill_color = 0xFFFFFF;

                surface->Fill(rc.left, rc.top, rc.right - rc.left, 1, fill_color);
                surface->Fill(rc.left, rc.bottom - 1, rc.right - rc.left, 1, fill_color);

                surface->Fill(rc.left, rc.top, 1, rc.bottom - rc.top, fill_color);
                surface->Fill(rc.right - 1, rc.top, 1, rc.bottom - rc.top, fill_color);
            }

            if (line.Effects & MM_TEXT_PADDING)
            {
                rc.left += 2;
                rc.right -= 2;
            }
        }

        font->Draw(surface, line.Text, rc, fg_color_, format_);
    }
}
