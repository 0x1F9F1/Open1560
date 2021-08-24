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

#include "pipeline.h"

#include "data7/ipc.h"

#include <miniz.h>

#include "core/minwin.h"

static ConstString ScreenShotName;
static std::atomic<i32> ScreenShotStage = 0;

void agiPipeline::RequestScreenShot(ConstString file_name)
{
    if (ScreenShotStage != 0)
    {
        Errorf("RequestScreenShot: Previous request not yet complete");

        return;
    }

    ScreenShotName = std::move(file_name);
    ScreenShotStage = 1;
}

bool agiPipeline::ScreenShotRequested()
{
    return ScreenShotStage == 1;
}

static void SaveScreenShotWorker(void* ctx)
{
    agiSurfaceDesc* surface = static_cast<agiSurfaceDesc*>(ctx);
    ArAssert(surface->PixelFormat.RGBBitCount == 24, "Invalid Screenshot Format");

    i32 width = surface->Width;
    i32 height = surface->Height;
    i32 pitch = surface->Pitch;
    u8* pixels = static_cast<u8*>(surface->Surface);

    if (OpenClipboard(NULL))
    {
        if (EmptyClipboard())
        {
            i32 dst_pitch = ((width * 3) + 3) & ~3;

            BITMAPINFOHEADER info_header {};
            info_header.biSize = sizeof(info_header);
            info_header.biWidth = width;
            info_header.biHeight = height;
            info_header.biPlanes = 1;
            info_header.biBitCount = 24;
            info_header.biCompression = BI_RGB;
            info_header.biSizeImage = 0;
            info_header.biXPelsPerMeter = width;
            info_header.biYPelsPerMeter = height;
            info_header.biClrUsed = 0;
            info_header.biClrImportant = 0;

            if (HGLOBAL clip_handle =
                    GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT, sizeof(info_header) + dst_pitch * height))
            {
                if (u8* clip_data = static_cast<u8*>(GlobalLock(clip_handle)))
                {
                    std::memcpy(clip_data, &info_header, sizeof(info_header));
                    clip_data += sizeof(info_header);

                    for (i32 i = 0; i < height; ++i)
                        std::memcpy(&clip_data[i * dst_pitch], &pixels[i * pitch], dst_pitch);

                    GlobalUnlock(clip_handle);
                }

                SetClipboardData(CF_DIB, clip_handle);
            }
        }

        CloseClipboard();
    }

    char name_buffer[64];
    const char* file_name = ScreenShotName.get();

    if (file_name == nullptr)
    {
        i32 shot_num = 0;
        WIN32_FIND_DATAA find_data;

        if (HANDLE find_handle = FindFirstFileA("screen/SHOT*.PNG", &find_data); find_handle != INVALID_HANDLE_VALUE)
        {
            do
            {
                if (!arts_strnicmp(find_data.cFileName, "SHOT", 4))
                    shot_num = std::max<i32>(shot_num, std::atoi(find_data.cFileName + 4));
            } while (FindNextFileA(find_handle, &find_data));

            FindClose(find_handle);
        }

        CreateDirectoryA("screen", NULL);

        arts_sprintf(name_buffer, "screen/SHOT%04d.PNG", shot_num + 1);
        file_name = name_buffer;
    }

    // BGR -> RGB + Ensure Packing
    for (i32 i = 0; i < height; ++i)
    {
        u8* src = pixels + (i * pitch);
        u8* dst = pixels + (i * width * 3);

        for (i32 j = 0; j < width; ++j, src += 3, dst += 3)
        {
            u8 tmp = src[0];
            dst[0] = src[2];
            dst[1] = src[1];
            dst[2] = tmp;
        }
    }

    size_t png_size = 0;
    if (void* png_data = tdefl_write_image_to_png_file_in_memory_ex(pixels, width, height, 3, &png_size, 10, true);
        png_data)
    {
        if (HANDLE file = CreateFileA(file_name, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
            file != INVALID_HANDLE_VALUE)
        {
            DWORD written = 0;
            WriteFile(file, png_data, png_size, &written, NULL);
            CloseHandle(file);
        }

        mz_free(png_data);
    }

    surface->Unload();
    delete surface;

    ScreenShotName = nullptr;
    ScreenShotStage = 0;
}

void agiPipeline::SaveScreenShot(Ptr<agiSurfaceDesc> surface)
{
    if (surface == nullptr)
    {
        ScreenShotStage = 0;
        return;
    }

    ScreenShotStage = 2;
    GFXPAGER.Send(SaveScreenShotWorker, surface.release());
}
