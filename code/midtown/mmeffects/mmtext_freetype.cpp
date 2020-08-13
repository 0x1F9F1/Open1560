#include "mmtext.h"

#include "agi/bitmap.h"
#include "agi/cmodel.h"
#include "agi/pipeline.h"
#include "agi/surface.h"
#include "data7/hash.h"
#include "localize/localize.h"

#include <ft2build.h>

#include <freetype/freetype.h>

static u32 TwiddleColor(u32 color)
{
    return ((color >> 16) & 0xFF) | (color & 0xFF00) | ((color & 0xFF) << 16);
}

static FT_Library FreeTypeLibrary = nullptr;

void InitFreeType()
{
    if (FreeTypeLibrary != nullptr)
        return;

    if (FT_Init_FreeType(&FreeTypeLibrary))
        Quitf("Can't initialize FreeType");

    std::atexit([] { FT_Done_FreeType(FreeTypeLibrary); });
}

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

#define MM_DT_TOP 0x00000000
#define MM_DT_LEFT 0x00000000
#define MM_DT_CENTER 0x00000001
#define MM_DT_RIGHT 0x00000002
#define MM_DT_VCENTER 0x00000004
#define MM_DT_BOTTOM 0x00000008
#define MM_DT_WORDBREAK 0x00000010
#define MM_DT_SINGLELINE 0x00000020
#define MM_DT_EXPANDTABS 0x00000040
#define MM_DT_TABSTOP 0x00000080
#define MM_DT_NOCLIP 0x00000100
#define MM_DT_EXTERNALLEADING 0x00000200
#define MM_DT_CALCRECT 0x00000400
#define MM_DT_NOPREFIX 0x00000800
#define MM_DT_INTERNAL 0x00001000

static HashTable FontHash {64, "FontHash"};

class mmFont
{
private:
    mmFont(const char* name, FT_Face face)
        : face_(face)
    {
        arts_strcpy(name_, name);
    }

    ~mmFont()
    {
        FT_Done_Face(face_);

        FontHash.Delete(name_);
    }

    i32 ref_count_ {1};
    FT_Face face_ {nullptr};
    char name_[256] {};

public:
    void AddRef()
    {
        ++ref_count_;
    }

    i32 Release()
    {
        u32 const refs = --ref_count_;

        if (refs == 0)
        {
            delete this;
        }

        return refs;
    }

    mmSize GetExtents(const char* text)
    {
        u32 width = 0;
        u32 height = face_->size->metrics.height;

        for (; *text; ++text)
        {
            u32 glyph_index = FT_Get_Char_Index(face_, static_cast<unsigned char>(*text));
            FT_Load_Glyph(face_, glyph_index, FT_LOAD_DEFAULT);
            FT_Render_Glyph(face_->glyph, FT_RENDER_MODE_NORMAL);

            width += face_->glyph->advance.x;
        }

        return {static_cast<i32>((width + 63) >> 6), static_cast<i32>((height + 63) >> 6)};
    }

    void Draw(agiSurfaceDesc* surface, const char* text, const mmRect* rect, u32 color, u32 format)
    {
        agiColorModel* cmodel = agiColorModel::FindMatch(surface);

        i32 x = rect->left;
        i32 y = rect->top;

        i32 width = rect->right - rect->left;
        i32 height = rect->bottom - rect->top;

        surface->Clear(x, y, width, height);

        if (format & (MM_DT_CENTER | MM_DT_VCENTER | MM_DT_RIGHT))
        {
            mmSize size = GetExtents(text);

            if (format & MM_DT_CENTER)
                x += (width - size.cx) / 2;
            else if (format & MM_DT_RIGHT)
                x += (width - size.cx);

            if (format & MM_DT_VCENTER)
                y += (height - size.cy) / 2;
            else if (format & MM_DT_BOTTOM)
                y += (height - size.cy);
        }

        x <<= 6;
        y <<= 6;

        y += face_->size->metrics.ascender;

        color = TwiddleColor(color & 0xFFFFFF) | 0xFF000000;

        for (; *text; ++text)
        {
            u32 glyph_index = FT_Get_Char_Index(face_, static_cast<unsigned char>(*text));

            FT_Load_Glyph(face_, glyph_index, FT_LOAD_DEFAULT);

            FT_Render_Glyph(face_->glyph, FT_RENDER_MODE_MONO);

            for (u32 src_y = 0; src_y < face_->glyph->bitmap.rows; ++src_y)
            {
                u32 src_y_off = src_y * face_->glyph->bitmap.pitch;

                u32 dst_y = (y >> 6) + src_y - face_->glyph->bitmap_top;

                if (dst_y >= surface->Height)
                    break;

                for (u32 src_x = 0; src_x < face_->glyph->bitmap.width; ++src_x)
                {
                    u32 dst_x = (x >> 6) + src_x + face_->glyph->bitmap_left;

                    if (dst_x >= surface->Width)
                        break;

                    if (u8 alpha = face_->glyph->bitmap.buffer[src_y_off + (src_x >> 3)] & (0x80 >> (src_x & 0x7)))
                        cmodel->SetPixel(surface, dst_x, dst_y, color);
                }
            }

            x += face_->glyph->advance.x;
        }
    }

    static mmFont* Create(const char* font_name, i32 height, i32 weight)
    {
        InitFreeType();

        // TODO: Support other fonts
        // TODO: Lookup file name for font

        if (weight >= 700)
            font_name = "GILB____.TTF";
        else
            font_name = "GIL_____.TTF";

        char name[256];
        arts_sprintf(name, "%s, %i", font_name, height);

        if (mmFont* font = static_cast<mmFont*>(FontHash.Access(name)))
        {
            font->AddRef();

            return font;
        }

        FT_Face face = nullptr;

        if (FT_New_Face(FreeTypeLibrary, font_name, 0, &face))
        {
            Errorf("Failed to create font %s", font_name);

            return nullptr;
        }

        FT_Set_Char_Size(face, height << 6, height << 6, 72, 72);

        return new mmFont(name, face);
    }
};

void mmText::Draw(agiSurfaceDesc* surface, f32 x, f32 y, char* text, void* font_ptr)
{
    mmFont* font = static_cast<mmFont*>(font_ptr);

    i32 screen_x = static_cast<i32>(Pipe()->GetWidth() * x);
    i32 screen_y = static_cast<i32>(Pipe()->GetHeight() * y);

    mmSize size = font->GetExtents(text);

    // TODO: Should right/bottom be adjusted by screen_x/screen_y?

    mmRect rc {};
    rc.left = screen_x;
    rc.top = screen_y;
    rc.right = size.cx;
    rc.bottom = size.cy;

    font->Draw(surface, text, &rc, 0xFFFFFF, 0);
}

void mmText::Draw2(agiSurfaceDesc* surface, f32 x, f32 y, char* text, void* font_ptr, u32 color)
{
    mmFont* font = static_cast<mmFont*>(font_ptr);

    i32 screen_x = static_cast<i32>(Pipe()->GetWidth() * x);
    i32 screen_y = static_cast<i32>(Pipe()->GetHeight() * y);

    mmSize size = font->GetExtents(text);

    // TODO: Should right/bottom be adjusted by screen_x/screen_y?

    mmRect rc {};
    rc.left = screen_x;
    rc.top = screen_y;
    rc.right = size.cx;
    rc.bottom = size.cy;

    font->Draw(surface, text, &rc, color, MM_DT_RIGHT);
}

agiBitmap* mmText::CreateFitBitmap(char* text, void* font_ptr, i32 color, i32 bg_color)
{
    agiBitmap* bitmap = Pipe()->CreateBitmap();

    mmFont* font = static_cast<mmFont*>(font_ptr);

    mmSize size = font->GetExtents(text);
    size.cx += size.cy & 1;

    {
        char name[256];
        arts_sprintf(name, "*FitBitmap:%p", bitmap);

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

                font->Draw(bitmap->GetSurface(), text, &rc, bg_color, MM_DT_NOPREFIX);
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

    font->Draw(bitmap->GetSurface(), text, &rc, color, MM_DT_NOPREFIX);

    bitmap->EndGfx();
    bitmap->SafeBeginGfx();

    return bitmap;
}

void* mmText::CreateFont(char* font_name, i32 height)
{
    return mmFont::Create(font_name, height, 400);
}

void* mmText::CreateLocFont(LocString* params, i32 screen_width)
{
    char* split_params = arts_strdup(params->Text);
    char* split_context = nullptr;

    char* font_name = strtok_s(split_params, ",", &split_context);

    i32 height_low = std::atoi(strtok_s(nullptr, ",", &split_context));
    i32 height_high = std::atoi(strtok_s(nullptr, ",", &split_context));

    // FIXME: Use this param
    [[maybe_unused]] i32 char_set = std::atoi(strtok_s(nullptr, ",", &split_context));

    i32 weight = std::atoi(strtok_s(nullptr, ",", &split_context));

    Displayf("%s, weight %i", font_name, weight);

    mmFont* result = mmFont::Create(font_name, (screen_width >= 640) ? height_high : height_low, weight);

    arts_free(split_params);

    return result;
}

void mmText::DeleteFont(void* font)
{
    static_cast<mmFont*>(font)->Release();
}

void* mmText::GetDC(agiSurfaceDesc*)
{
    return nullptr;
}

void mmText::ReleaseDC()
{}

void mmTextNode::GetTextDimensions(void* font_ptr, LocString* text, f32& width, f32& height)
{
    if (font_ptr == nullptr)
    {
        // Called by MenuManager::InitCommonStuff with a null font.

        width = (16.0f * std::strlen(text->Text)) / Pipe()->GetWidth();
        height = 16.0f / Pipe()->GetHeight();

        return;
    }

    mmFont* font = static_cast<mmFont*>(font_ptr);
    mmSize size = font->GetExtents(text->Text);

    width = static_cast<f32>(size.cx) / Pipe()->GetWidth();
    height = static_cast<f32>(size.cy) / Pipe()->GetHeight();
}

void mmTextNode::RenderText(
    agiSurfaceDesc* surface, mmTextData* lines, [[maybe_unused]] i32 num_lines, u32 enabled_lines)
{
    format_ = MM_DT_NOPREFIX;
    hidden_ = true;

    for (i32 i = 0; i < num_lines; ++i)
    {
        if (!((1 << i) & enabled_lines))
            continue;

        mmTextData& line = lines[i];

        if ((std::strlen(line.Text) == 0) && !(line.Effects & 0x40))
            continue;

        hidden_ = false;

        mmFont* font = static_cast<mmFont*>(line.Font);

        u32 format = MM_DT_NOPREFIX;

        mmRect rc {};

        rc.left = line.X;
        rc.top = line.Y;
        rc.right = surface->Width;
        rc.bottom = surface->Height;

        mmRect text_rc = rc;

        if (line.Effects)
        {
            if (line.Effects & 0x2)
                format_ |= MM_DT_CENTER;

            if (line.Effects & 0x1)
                format_ |= MM_DT_VCENTER | MM_DT_SINGLELINE;

            if (line.Effects & 0x20)
                format_ |= MM_DT_WORDBREAK;

            if (line.Effects & 0x10)
                text_rc.left += 2;

            format = format_;
        }

        font->Draw(surface, line.Text, &text_rc, fg_color_, format);

        if (line.Effects & 0x4)
        {
            u32 fill_color = 0xFFFFFF;

            surface->Fill(rc.left, rc.top, rc.right - rc.left, 1, fill_color);
            surface->Fill(rc.left, rc.bottom - 1, rc.right - rc.left, 1, fill_color);

            surface->Fill(rc.left, rc.top, 1, rc.bottom - rc.top, fill_color);
            surface->Fill(rc.right - 1, rc.top, 1, rc.bottom - rc.top, fill_color);
        }
    }
}
