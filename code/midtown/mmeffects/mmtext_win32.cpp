#include "mmtext.h"

#include "agi/bitmap.h"
#include "agi/surface.h"
#include "agid3d/ddpipe.h"
#include "core/minwin.h"
#include "localize/localize.h"
#include "pcwindis/dxinit.h"

#include <ddraw.h>

#ifdef CreateFont
#    undef CreateFont
#endif

static u32 TwiddleColor(u32 color)
{
    return ((color >> 16) & 0xFF) | (color & 0xFF00) | ((color & 0xFF) << 16);
}

void mmText::Draw(agiSurfaceDesc* surface, f32 x, f32 y, char* text, void* font)
{
    HDC dc = static_cast<HDC>(GetDC(surface));

    if (dc)
    {
        i32 screen_x = static_cast<i32>(Pipe()->GetWidth() * x);
        i32 screen_y = static_cast<i32>(Pipe()->GetHeight() * y);

        HGDIOBJ prev_font = SelectObject(dc, font);

        SetTextColor(dc, 0xFFFFFF);
        SetBkColor(dc, 0);
        TextOutA(dc, screen_x, screen_y, text, std::strlen(text));

        SelectObject(dc, prev_font);

        mmText::ReleaseDC();
    }
}

void mmText::Draw2(agiSurfaceDesc* surface, f32 x, f32 y, char* text, void* font, u32 color)
{
    HDC dc = static_cast<HDC>(GetDC(surface));

    if (dc)
    {
        i32 screen_x = static_cast<i32>(Pipe()->GetWidth() * x);
        i32 screen_y = static_cast<i32>(Pipe()->GetHeight() * y);

        HGDIOBJ prev_font = SelectObject(dc, font);

        SIZE size {};
        GetTextExtentPoint32A(dc, text, std::strlen(text), &size);

        RECT rc {};
        // TODO: Just set rc directly?
        // TODO: Should right/bottom be adjusted by screen_x/screen_y?
        SetRect(&rc, screen_x, screen_y, size.cx, size.cy);

        SetTextColor(dc, color);
        SetBkColor(dc, 0);

        if (!DrawTextA(dc, text, std::strlen(text), &rc, DT_RIGHT | DT_NOPREFIX))
            Displayf("DrawText failed");

        SelectObject(dc, prev_font);

        mmText::ReleaseDC();
    }
}

agiBitmap* mmText::CreateFitBitmap(char* text, void* font, i32 color, i32 bg_color)
{
    SIZE size {};

    {
        HDC wnd_dc = ::GetDC(hwndMain);
        HGDIOBJ prev_font = SelectObject(wnd_dc, font);
        GetTextExtentPoint32A(wnd_dc, text, std::strlen(text), &size);
        size.cx += size.cx & 1;
        SelectObject(wnd_dc, prev_font);
        ::ReleaseDC(hwndMain, wnd_dc);
    }

    agiBitmap* bitmap = Pipe()->CreateBitmap();

    {
        char name[256];
        arts_sprintf(name, "*FitBitmap:%p", bitmap);

        i32 extra = (bg_color != -1) ? 2 : 0;
        bitmap->Init(name, static_cast<f32>(size.cx + extra), static_cast<f32>(size.cy + extra),
            AGI_BITMAP_TRANSPARENT | AGI_BITMAP_OFFSCREEN);
    }

    HDC dc = static_cast<HDC>(GetDC(bitmap->GetSurface()));

    HGDIOBJ prev_font = SelectObject(dc, font);
    i32 prev_mode = SetBkMode(dc, TRANSPARENT);

    if (bg_color != -1)
    {
        SetTextColor(dc, TwiddleColor(bg_color));

        for (i32 i = 0; i <= 2; ++i)
        {
            for (i32 j = 0; j <= 2; ++j)
            {
                RECT rc {};
                rc.left = i;
                rc.top = j;
                rc.right = i + size.cx;
                rc.bottom = j + size.cy;
                DrawTextA(dc, text, std::strlen(text), &rc, DT_NOPREFIX);
            }
        }
    }

    SetTextColor(dc, TwiddleColor(color));

    RECT rc {};
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

    DrawTextA(dc, text, std::strlen(text), &rc, DT_NOPREFIX);

    SetBkMode(dc, prev_mode);
    SelectObject(dc, prev_font);

    mmText::ReleaseDC();

    bitmap->EndGfx();
    bitmap->SafeBeginGfx();

    return bitmap;
}

static i32 GetFontQuality()
{
    return PROOF_QUALITY;
}

void* mmText::CreateFont(char* font_name, i32 height)
{
    // TODO: Use CLEARTYPE_QUALITY ?
    return CreateFontA(height, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, GetFontQuality(), VARIABLE_PITCH, font_name);
}

void* mmText::CreateLocFont(LocString* params, i32 screen_width)
{
    char* split_params = arts_strdup(params->Text);
    char* split_context = nullptr;

    char* font_name = strtok_s(split_params, ",", &split_context);

    i32 height_low = std::atoi(strtok_s(nullptr, ",", &split_context));
    i32 height_high = std::atoi(strtok_s(nullptr, ",", &split_context));

    i32 char_set = std::atoi(strtok_s(nullptr, ",", &split_context));
    i32 weight = std::atoi(strtok_s(nullptr, ",", &split_context));

    void* result = CreateFontA((screen_width >= 640) ? height_high : height_low, 0, 0, 0, weight, FALSE, FALSE, FALSE,
        char_set, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, GetFontQuality(), VARIABLE_PITCH, font_name);

    arts_free(split_params);

    return result;
}

void mmText::DeleteFont(void* font)
{
    DeleteObject(font);
}

static agiSurfaceDesc* TextSurfaceAGI = nullptr;
static IDirectDrawSurface4* TextSurfaceDD = nullptr;
static HDC TextSurfaceDC = nullptr;

void* mmText::GetDC(agiSurfaceDesc* surface)
{
    TextSurfaceAGI = surface;

    DDSURFACEDESC2 sd {sizeof(sd)};
    sd.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
    sd.dwWidth = surface->Width;
    sd.dwHeight = surface->Height;
    sd.ddsCaps.dwCaps = DDSCAPS_SYSTEMMEMORY;

    if (lpDD4->CreateSurface(&sd, &TextSurfaceDD, nullptr))
    {
        return nullptr;
    }

    if (TextSurfaceDD->GetDC(&TextSurfaceDC))
    {
        TextSurfaceDD->Release();
        return nullptr;
    }

    return TextSurfaceDC;
}

void mmText::ReleaseDC()
{
    if (TextSurfaceDD->ReleaseDC(TextSurfaceDC))
    {
        TextSurfaceDD->Release();
        return;
    }

    // Assume only querying size if surface == nullptr
    if (TextSurfaceAGI->Surface != nullptr)
    {
        DDSURFACEDESC2 sd {sizeof(sd)};

        if (TextSurfaceDD->Lock(nullptr, &sd, 0, nullptr))
        {
            TextSurfaceDD->Release();
            return;
        }

        agiSurfaceDesc agi_sd = ConvertSurfaceDesc(sd);
        TextSurfaceAGI->CopyFrom(&agi_sd, 0);

        TextSurfaceDD->Unlock(nullptr);
    }

    if (TextSurfaceDD->Release())
        Errorf("mmText::ReleaseDC problem!");

    TextSurfaceDD = nullptr;
}

void mmTextNode::GetTextDimensions(void* font, LocString* text, f32& width, f32& height)
{
    bool created_bitmap = false;

    if (text_bitmap_ == nullptr)
    {
        char name[256];
        arts_sprintf(name, "*TextNode:%ptemp", this);

        text_bitmap_.reset(Pipe()->CreateBitmap());

        text_bitmap_->Init(name, Pipe()->GetWidth() * width, Pipe()->GetHeight() * height, 0);

        created_bitmap = true;
    }

    HDC dc = static_cast<HDC>(mmText::GetDC(text_bitmap_->GetSurface()));

    if (dc)
    {
        SIZE size {};

        if (text)
        {
            HGDIOBJ prev_font = SelectObject(dc, font);
            GetTextExtentPoint32A(dc, text->Text, std::strlen(text->Text), &size);
            SelectObject(dc, prev_font);
        }
        else
        {
            // TODO: Shouldn't this also set the font?
            // TODO: Shouldn't this pass the length of the text, not the max size?
            GetTextExtentPoint32A(dc, lines_[0].Text, std::size(lines_[0].Text), &size);
        }

        mmText::ReleaseDC();

        width = static_cast<f32>(size.cx) / Pipe()->GetWidth();
        height = static_cast<f32>(size.cy) / Pipe()->GetHeight();

        // TODO: Shouldn't this be done outside of the if (dc) check?
        if (created_bitmap)
            text_bitmap_.reset();
    }
}

void mmTextNode::RenderText(
    agiSurfaceDesc* surface, mmTextData* lines, [[maybe_unused]] i32 num_lines, u32 enabled_lines)
{
    HDC dc = static_cast<HDC>(mmText::GetDC(surface));

    if (dc)
    {
        SetTextColor(dc, fg_color_);
        SetBkMode(dc, TRANSPARENT);

        if (SetBkColor(dc, bg_color_) == -1)
            Errorf("SetBkColor failed");

        HGDIOBJ prev_brush = SelectObject(dc, GetStockObject(NULL_BRUSH));
        HGDIOBJ prev_pen = SelectObject(dc, GetStockObject(WHITE_PEN));

        format_ = DT_NOPREFIX;
        hidden_ = true;

        // TODO: Should this use num_lines ?
        for (i32 i = 0; i < line_count_; ++i)
        {
            mmTextData& line = lines[i];

            if (!((1 << i) & enabled_lines))
                continue;

            if ((std::strlen(line.Text) == 0) && !(line.Effects & 0x40))
                continue;

            hidden_ = false;

            HGDIOBJ prev_font = SelectObject(dc, line.Font);

            DWORD format = DT_NOPREFIX;
            RECT rc {};
            SetRect(&rc, line.X, line.Y, text_bitmap_->GetWidth(), text_bitmap_->GetHeight());

            if (line.Effects)
            {
                SIZE size {};
                GetTextExtentPoint32A(dc, line.Text, std::strlen(line.Text), &size);

                // TODO: Should this use the size from GetTextExtentPoint32A ?
                SetRect(&rc, line.X, line.Y, text_bitmap_->GetWidth(), text_bitmap_->GetHeight());

                if (line.Effects & 0x2)
                    format_ |= DT_CENTER;

                if (line.Effects & 0x1)
                    format_ |= DT_VCENTER | DT_SINGLELINE;

                if (line.Effects & 0x20)
                    format_ |= DT_WORDBREAK;

                if (line.Effects & 0x4)
                    Rectangle(dc, rc.left, rc.top, rc.right, rc.bottom);

                if (line.Effects & 0x10)
                    rc.left += 2;

                format = format_;
            }

            DrawTextA(dc, line.Text, std::strlen(line.Text), &rc, format);
            SelectObject(dc, prev_font);
        }

        SelectObject(dc, prev_pen);
        SelectObject(dc, prev_brush);

        mmText::ReleaseDC();
    }
}
