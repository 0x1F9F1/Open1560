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

define_dummy_symbol(agi_surface);

#include "surface.h"

#include <emmintrin.h>

static void copyrow4444_to_555(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B7E0, arg1, arg2, arg3, arg4);
}

static void copyrow4444_to_5551(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B8E0, arg1, arg2, arg3, arg4);
}

static void copyrow4444_to_565(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B860, arg1, arg2, arg3, arg4);
}

static void copyrow4444_to_8888(void* dst, void* src, u32 len, u32 step)
{
    u32* ARTS_RESTRICT dst32 = static_cast<u32*>(dst);
    u16* ARTS_RESTRICT src16 = static_cast<u16*>(src);

    if (step == 0x10000 && len >= 8)
    {
        const __m128i mask_lo = _mm_set1_epi32(0x0F0F0F0F);
        const __m128i mask_hi = _mm_slli_epi32(mask_lo, 4);

        do
        {
            len -= 8;

            __m128i dst_lo = _mm_loadu_si128((const __m128i*) (src16));
            src16 += 8;

            __m128i dst_hi = dst_lo;

            dst_lo = _mm_and_si128(dst_lo, mask_lo);
            dst_hi = _mm_and_si128(dst_hi, mask_hi);

            dst_lo = _mm_or_si128(dst_lo, _mm_slli_epi16(dst_lo, 4));
            dst_hi = _mm_or_si128(dst_hi, _mm_srli_epi16(dst_hi, 4));

            _mm_storeu_si128((__m128i*) (dst32 + 0), _mm_unpacklo_epi8(dst_lo, dst_hi));
            _mm_storeu_si128((__m128i*) (dst32 + 4), _mm_unpackhi_epi8(dst_lo, dst_hi));

            dst32 += 8;
        } while (len >= 8);
    }

    for (u32 src_off = 0; len; --len)
    {
        u32 v = src16[src_off >> 16];
        src_off += step;
        v = (v & 0x000F) | ((v & 0x00F0) << 4) | ((v & 0x0F00) << 8) | ((v & 0xF000) << 12);
        *dst32++ = v | (v << 4);
    }
}

static void copyrow4444_to_8888rev(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B750, arg1, arg2, arg3, arg4);
}

static void copyrow565_to_555(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B510, arg1, arg2, arg3, arg4);
}

static void copyrow565_to_5551(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B560, arg1, arg2, arg3, arg4);
}

static void copyrow565_to_888(void* dst, void* src, u32 len, u32 step)
{
    u32* ARTS_RESTRICT dst32 = static_cast<u32*>(dst);
    u16* ARTS_RESTRICT src16 = static_cast<u16*>(src);

    if (step == 0x10000 && len >= 8)
    {
        const __m128i mult_0108 = _mm_set1_epi32(0x01080108);
        const __m128i mult_2080 = _mm_set1_epi32(0x20802080);

        const __m128i mask_07E0 = _mm_set1_epi32(0x07E007E0);
        const __m128i mask_F800 = _mm_set1_epi32(0xF800F800);

        do
        {
            len -= 8;

            __m128i dst_lo = _mm_loadu_si128((const __m128i*) (src16));

            src16 += 8;

            __m128i dst_r = _mm_slli_epi16(_mm_mulhi_epu16(_mm_and_si128(dst_lo, mask_F800), mult_0108), 8);
            __m128i dst_b = _mm_mulhi_epu16(_mm_slli_epi16(dst_lo, 11), mult_0108);
            __m128i dst_g = _mm_mulhi_epu16(_mm_and_si128(dst_lo, mask_07E0), mult_2080);

            dst_lo = _mm_or_si128(dst_r, dst_b);

            _mm_storeu_si128((__m128i*) (dst32 + 0), _mm_unpacklo_epi8(dst_lo, dst_g));
            _mm_storeu_si128((__m128i*) (dst32 + 4), _mm_unpackhi_epi8(dst_lo, dst_g));

            dst32 += 8;
        } while (len >= 8);
    }

    for (u32 src_off = 0; len; --len)
    {
        u32 v = src16[src_off >> 16];
        src_off += step;
        *dst32++ =
            ((v & 0xF800) << 8) | ((v & 0x07E0) << 5) | ((v & 0xE01F) << 3) | ((v & 0x0600) >> 1) | ((v & 0x001C) >> 2);
    }
}

static void copyrow565_to_888rev(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B640, arg1, arg2, arg3, arg4);
}

void agiSurfaceDesc::CopyFrom(class agiSurfaceDesc* src, i32 lod)
{
    export_hook(0x55B180);

    u32 dst_width = dwWidth;
    u32 dst_height = dwHeight;
    u32 dst_pixel_size = (ddpfPixelFormat.dwRGBBitCount + 7) >> 3;
    u32 dst_pitch = lPitch; // Pitch may be larger than dst_pixel_size * dst->dwWidth
    u8* dst_surface = static_cast<u8*>(lpSurface);

    if (usize dst_min_pitch = dst_pixel_size * dst_width; dst_pitch < dst_min_pitch)
    {
        // In 32-bit color mode the pitch of some mipmaps is too small (half of what it should be).
        // Unsure if this is a bug in MM1 or dgVoodoo, but just use -nomip to avoid it for now.
        Displayf("Invalid Pitch: %u < %u", dst_pitch, dst_min_pitch);
        std::memset(dst_surface, 0xFF, dst_pitch * dst_height);
        return;
    }

    u32 src_width = src->dwWidth;
    u32 src_height = src->dwHeight;
    u32 src_pixel_size = (src->ddpfPixelFormat.dwRGBBitCount + 7) >> 3;
    u32 src_pitch = src_pixel_size * src->dwWidth;
    u8* src_surface = static_cast<u8*>(src->lpSurface);

    for (; lod; --lod)
    {
        src_surface += src_pitch * src_height;
        src_width >>= 1;
        src_height >>= 1;
        src_pitch >>= 1;
    }

    u32 src_x_step = (src_width << 16) / dst_width;
    u32 src_y_step = (src_height << 16) / dst_height;

    if (!std::memcmp(&ddpfPixelFormat, &src->ddpfPixelFormat, sizeof(ddpfPixelFormat)))
    {
        if (src_width != dst_width || src_height != dst_height || src_pitch != dst_pitch)
        {
            switch (src_pixel_size)
            {
#define X(TYPE)                                                                           \
    case sizeof(TYPE):                                                                    \
        for (u32 i = 0, j = 0; i < dst_height; ++i, j += src_y_step)                      \
        {                                                                                 \
            TYPE* dst_row = reinterpret_cast<TYPE*>(dst_surface + dst_pitch * i);         \
            TYPE* src_row = reinterpret_cast<TYPE*>(src_surface + src_pitch * (j >> 16)); \
                                                                                          \
            for (u32 k = 0, l = 0; k < dst_width; ++k, l += src_x_step)                   \
            {                                                                             \
                dst_row[k] = src_row[l >> 16];                                            \
            }                                                                             \
        }                                                                                 \
        break

                X(u8);
                X(u16);
                X(u32);

#undef X

                default: Quitf("Invalid Pixel Format");
            }
        }
        else
        {
            std::memcpy(dst_surface, src_surface, dst_pitch * dst_height);
        }

        return;
    }

    void (*copy_row)(void*, void*, u32, u32) = nullptr;

    switch (src->ddpfPixelFormat.dwRBitMask)
    {
        case 0xF800: // 565
            switch (ddpfPixelFormat.dwRBitMask)
            {
                case 0xFF0000u: copy_row = copyrow565_to_888; break;
                case 0xFFu: copy_row = copyrow565_to_888rev; break;

                case 0x7C00u:
                    if (ddpfPixelFormat.dwRGBAlphaBitMask == 0x8000)
                    {
                        copy_row = copyrow565_to_5551;
                    }
                    else
                    {
                        copy_row = copyrow565_to_555;
                    }
                    break;
            }
            break;

        case 0xF00: // 4444
            switch (ddpfPixelFormat.dwRBitMask)
            {
                case 0xFF0000u: copy_row = copyrow4444_to_8888; break;
                case 0xFFu: copy_row = copyrow4444_to_8888rev; break;

                case 0xF800u: copy_row = copyrow4444_to_565; break;
                case 0x7C00u:
                    if (ddpfPixelFormat.dwRGBAlphaBitMask == 0x8000)
                    {
                        copy_row = copyrow4444_to_5551;
                    }
                    else
                    {
                        copy_row = copyrow4444_to_555;
                    }
                    break;
            }
            break;
    }

    if (!copy_row)
    {
        Quitf("Tell Dave to implement (%x,%x,%x,%x)-->(%x,%x,%x,%x) copyrow function.", src->ddpfPixelFormat.dwRBitMask,
            src->ddpfPixelFormat.dwGBitMask, src->ddpfPixelFormat.dwBBitMask, src->ddpfPixelFormat.dwRGBAlphaBitMask,
            ddpfPixelFormat.dwRBitMask, ddpfPixelFormat.dwGBitMask, ddpfPixelFormat.dwBBitMask,
            ddpfPixelFormat.dwRGBAlphaBitMask);
    }

    for (u32 dst_y = 0, src_y = 0; dst_y < dst_height; ++dst_y, src_y += src_y_step)
    {
        copy_row(dst_surface + (dst_pitch * dst_y), src_surface + (src_pitch * (src_y >> 16)), dst_width, src_x_step);
    }
}

void agiSurfaceDesc::Reload(char* arg1, char* arg2, i32 arg3, i32 arg4, class Stream* arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, agiSurfaceDesc*, char*, char*, i32, i32, class Stream*, i32, i32>>(
        0x55ADE0, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void agiSurfaceDesc::Unload()
{
    export_hook(0x55B160);

    if (lpSurface)
    {
        delete[] static_cast<u8*>(lpSurface);
        lpSurface = nullptr;
    }
}

class agiSurfaceDesc* agiSurfaceDesc::Init(i32 width, i32 height, class agiSurfaceDesc& desc)
{
    export_hook(0x55A720);

    u32 pixel_size = (desc.ddpfPixelFormat.dwRGBBitCount + 7) / 8;

    agiSurfaceDesc* result = new agiSurfaceDesc(desc);

    result->dwFlags = AGISD_WIDTH | AGISD_HEIGHT;
    result->dwWidth = width;
    result->dwHeight = height;
    result->lPitch = width * pixel_size;

    u32 surface_size = width * height * pixel_size;

    result->lpSurface = new u8[surface_size];
    std::memset(result->lpSurface, 0, surface_size);

    return result;
}

class agiSurfaceDesc* agiSurfaceDesc::Load(char* arg1, char* arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6)
{
    return stub<cdecl_t<class agiSurfaceDesc*, char*, char*, i32, i32, i32, i32>>(
        0x55A7A0, arg1, arg2, arg3, arg4, arg5, arg6);
}

static void RescaleJpeg(u32 arg1, u32 arg2, u8* arg3, struct jpeg_decompress_struct& arg4)
{
    return stub<cdecl_t<void, u32, u32, u8*, struct jpeg_decompress_struct&>>(0x55AAE0, arg1, arg2, arg3, arg4);
}
