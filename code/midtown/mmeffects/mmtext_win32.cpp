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
#include "agi/pipeline.h"
#include "agi/surface.h"
#include "core/minwin.h"
#include "localize/localize.h"
#include "pcwindis/dxinit.h"

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
    return NONANTIALIASED_QUALITY;
}

void* mmText::CreateFont(const char* font_name, i32 height)
{
    return CreateFontA(height, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, GetFontQuality(), VARIABLE_PITCH, font_name);
}

void* mmText::CreateLocFont(LocString* params, i32 screen_width)
{
    char* split_params = arts_strdup(params->Text);
    char* split_context = nullptr;

    char* font_name = arts_strtok(split_params, ",", &split_context);

    i32 height_low = std::atoi(arts_strtok(nullptr, ",", &split_context));
    i32 height_high = std::atoi(arts_strtok(nullptr, ",", &split_context));

    i32 char_set = std::atoi(arts_strtok(nullptr, ",", &split_context));
    i32 weight = std::atoi(arts_strtok(nullptr, ",", &split_context));

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
static HDC TextSurfaceDC = nullptr;
static HBITMAP TextSurfaceDIB = nullptr;
static void* TextSurfacePixels = nullptr;

void* mmText::GetDC(agiSurfaceDesc* surface)
{
    TextSurfaceAGI = surface;
    TextSurfaceDC = CreateCompatibleDC(NULL);

    struct BITMAPINFORGB
    {
        BITMAPINFOHEADER bmiHeader;
        DWORD dwBitMasks[3];
    };

    BITMAPINFORGB bmi {};
    bmi.bmiHeader.biSize = sizeof(bmi);
    bmi.bmiHeader.biWidth = surface->Width;
    bmi.bmiHeader.biHeight = surface->Height;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = (WORD) PixelFormat_0565.RGBBitCount;
    bmi.bmiHeader.biCompression = BI_BITFIELDS;
    bmi.dwBitMasks[0] = PixelFormat_0565.RBitMask;
    bmi.dwBitMasks[1] = PixelFormat_0565.GBitMask;
    bmi.dwBitMasks[2] = PixelFormat_0565.BBitMask;

    TextSurfaceDIB = CreateDIBSection(TextSurfaceDC, (const BITMAPINFO*) &bmi, 0, &TextSurfacePixels, NULL, 0);
    SelectObject(TextSurfaceDC, TextSurfaceDIB);

    return TextSurfaceDC;
}

void mmText::ReleaseDC()
{
    // Assume only querying size if surface == nullptr
    if (TextSurfaceAGI->Surface != nullptr)
    {
        agiSurfaceDesc sd {sizeof(sd)};
        sd.Flags = AGISD_WIDTH | AGISD_HEIGHT | AGISD_PITCH | AGISD_PIXELFORMAT;
        sd.Width = TextSurfaceAGI->Width;
        sd.Height = TextSurfaceAGI->Height;
        sd.PixelFormat = PixelFormat_0565;

        // Windows bitmaps are DWORD aligned and upside down
        sd.Pitch = TextSurfaceAGI->Width * 2;
        sd.Pitch = (sd.Pitch + 3) & ~3;

        sd.Surface = static_cast<u8*>(TextSurfacePixels) + (sd.Pitch * (sd.Height - 1));
        sd.Pitch = -sd.Pitch;

        TextSurfaceAGI->CopyFrom(&sd, 0);
    }

    DeleteObject(TextSurfaceDIB);
    DeleteDC(TextSurfaceDC);

    TextSurfaceAGI = nullptr;
    TextSurfaceDC = nullptr;
    TextSurfaceDIB = nullptr;
    TextSurfacePixels = nullptr;
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
            GetTextExtentPoint32A(dc, lines_[0].Text, std::strlen(lines_[0].Text), &size);
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
        SetBkMode(dc, TRANSPARENT);

        if (SetBkColor(dc, bg_color_) == -1)
            Errorf("SetBkColor failed");

        HGDIOBJ prev_brush = SelectObject(dc, GetStockObject(NULL_BRUSH));
        HGDIOBJ prev_pen = SelectObject(dc, GetStockObject(WHITE_PEN));

        empty_ = true;

        // TODO: Should this use num_lines ?
        for (i32 i = 0; i < line_count_; ++i)
        {
            mmTextData& line = lines[i];

            if (!((1 << i) & enabled_lines))
                continue;

            if ((std::strlen(line.Text) == 0) && !(line.Effects & MM_TEXT_REQUIRED))
                continue;

            empty_ = false;

            HGDIOBJ prev_font = SelectObject(dc, line.Font);

            DWORD format = DT_NOPREFIX;
            RECT rc {};
            SetRect(&rc, line.X, line.Y, text_bitmap_->GetWidth(), text_bitmap_->GetHeight());

            if (line.Effects)
            {
                // SIZE size {};
                // GetTextExtentPoint32A(dc, line.Text, std::strlen(line.Text), &size);
                // TODO: Should this use the size from GetTextExtentPoint32A ?
                // SetRect(&rc, line.X, line.Y, text_bitmap_->GetWidth(), text_bitmap_->GetHeight());

                if (line.Effects & MM_TEXT_CENTER)
                    format |= DT_CENTER;

                if (line.Effects & MM_TEXT_VCENTER)
                    format |= DT_VCENTER | DT_SINGLELINE;

                if (line.Effects & MM_TEXT_WORDBREAK)
                    format |= DT_WORDBREAK;

                if (line.Effects & MM_TEXT_BORDER)
                    Rectangle(dc, rc.left, rc.top, rc.right, rc.bottom);

                if ((line.Effects & MM_TEXT_PADDING) && (rc.right - rc.left) > 4)
                {
                    rc.left += 2;
                    rc.right -= 2;
                }
            }

            COLORREF hl_color = 0x00FFFF;
            SetTextColor(dc, (line.Effects & MM_TEXT_HIGHLIGHT) ? hl_color : fg_color_);

            DrawTextA(dc, line.Text, std::strlen(line.Text), &rc, format);
            SelectObject(dc, prev_font);
        }

        SelectObject(dc, prev_pen);
        SelectObject(dc, prev_brush);

        mmText::ReleaseDC();
    }
}
