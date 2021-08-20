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

#include "agi/rgba.h"
#include "agiworld/texsheet.h"
#include "cmodel.h"
#include "texdef.h"

#include <ddraw.h>
#include <emmintrin.h>

struct jpeg_decompress_struct;

// clang-format off
const agiPixelFormat PixelFormat_A8R8G8B8 = {sizeof(agiPixelFormat), AGIPF_RGB | AGIPF_ALPHAPIXELS, 0, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000};
const agiPixelFormat PixelFormat_A8B8G8R8 = {sizeof(agiPixelFormat), AGIPF_RGB | AGIPF_ALPHAPIXELS, 0, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000};
const agiPixelFormat PixelFormat_X8R8G8B8 = {sizeof(agiPixelFormat), AGIPF_RGB,                     0, 32, 0x00FF0000, 0x0000FF00, 0x000000FF};
const agiPixelFormat PixelFormat_X8B8G8R8 = {sizeof(agiPixelFormat), AGIPF_RGB,                     0, 32, 0x000000FF, 0x0000FF00, 0x00FF0000};

const agiPixelFormat PixelFormat_A4R4G4B4 = {sizeof(agiPixelFormat), AGIPF_RGB | AGIPF_ALPHAPIXELS, 0, 16, 0x0F00, 0x00F0, 0x000F, 0xF000};
const agiPixelFormat PixelFormat_A1R5G5B5 = {sizeof(agiPixelFormat), AGIPF_RGB | AGIPF_ALPHAPIXELS, 0, 16, 0x7C00, 0x03E0, 0x001F, 0x8000};
const agiPixelFormat PixelFormat_X1R5G5B5 = {sizeof(agiPixelFormat), AGIPF_RGB,                     0, 16, 0x7C00, 0x03E0, 0x001F, 0x0000};
const agiPixelFormat PixelFormat_R5G6B5   = {sizeof(agiPixelFormat), AGIPF_RGB,                     0, 16, 0xF800, 0x07E0, 0x001F, 0x0000};

const agiPixelFormat PixelFormat_P8 = {sizeof(agiPixelFormat), AGIPF_RGB | AGIPF_PALETTEINDEXED8, 0, 8, 0, 0, 0, 0};
// clang-format on

// ?RescaleJpeg@@YAXIIPAEAAUjpeg_decompress_struct@@@Z
ARTS_IMPORT /*static*/ void RescaleJpeg(u32 arg1, u32 arg2, u8* arg3, jpeg_decompress_struct& arg4);

// ?copyrow4444_to_555@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow4444_to_555(void* dst, void* src, u32 len, u32 step);

// ?copyrow4444_to_5551@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow4444_to_5551(void* dst, void* src, u32 len, u32 step);

// ?copyrow4444_to_565@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow4444_to_565(void* dst, void* src, u32 len, u32 step);

// ?copyrow4444_to_8888@@YAXPAX0II@Z
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

            __m128i dst_hi = _mm_and_si128(dst_lo, mask_hi);
            dst_lo = _mm_and_si128(dst_lo, mask_lo);

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

static void copyrow4444_to_888amul(void* dst, void* src, u32 len, u32 step)
{
    u32* ARTS_RESTRICT dst32 = static_cast<u32*>(dst);
    u16* ARTS_RESTRICT src16 = static_cast<u16*>(src);

    // (x * 0xFF) / (0xF * 0xF) == (x * 0x11) / 0xF == (x * 0x11 * 0x889) >> 15 == (x * 0x9119) >> 15 == (x * 0x1223) >> 12

    if (step == 0x10000 && len >= 4)
    {
        const __m128i mask_alpha = _mm_set1_epi32(0x001E001E);
        const __m128i mask_color = _mm_set1_epi32(0x000F0F0F);
        const __m128i mult_color = _mm_set1_epi32(0x91199119);

        do
        {
            len -= 4;

            __m128i dst_lo = _mm_loadu_si64((const __m128i*) (src16));
            src16 += 4;

            __m128i alphas_16 = _mm_and_si128(_mm_srli_epi16(dst_lo, 11), mask_alpha);
            alphas_16 = _mm_unpacklo_epi16(alphas_16, alphas_16);

            dst_lo = _mm_and_si128(_mm_unpacklo_epi8(dst_lo, _mm_srli_epi16(dst_lo, 4)), mask_color);

            __m128i dst_hi = _mm_unpackhi_epi8(dst_lo, _mm_setzero_si128());
            dst_lo = _mm_unpacklo_epi8(dst_lo, _mm_setzero_si128());

            dst_lo = _mm_mullo_epi16(dst_lo, _mm_unpacklo_epi16(alphas_16, alphas_16));
            dst_hi = _mm_mullo_epi16(dst_hi, _mm_unpackhi_epi16(alphas_16, alphas_16));

            dst_lo = _mm_mulhi_epu16(dst_lo, mult_color);
            dst_hi = _mm_mulhi_epu16(dst_hi, mult_color);

            _mm_storeu_si128((__m128i*) dst32, _mm_packus_epi16(dst_lo, dst_hi));

            dst32 += 4;
        } while (len >= 4);
    }

    for (u32 src_off = 0; len; --len)
    {
        u32 v = src16[src_off >> 16];
        src_off += step;

        u32 amul = (v >> 12) * 0x1223;
        u32 r = ((v & 0x00F) * amul) >> 12;
        u32 g = ((v & 0x0F0) * amul) >> 8;
        u32 b = ((v & 0xF00) * amul) >> 4;
        *dst32++ = r | (g & 0xFF00) | (b & 0xFF0000);
    }
}

// ?copyrow4444_to_8888rev@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow4444_to_8888rev(void* dst, void* src, u32 len, u32 step);

// ?copyrow565_to_555@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow565_to_555(void* dst, void* src, u32 len, u32 step);

// ?copyrow565_to_5551@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow565_to_5551(void* dst, void* src, u32 len, u32 step);

// ?copyrow565_to_888@@YAXPAX0II@Z
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

// ?copyrow565_to_888rev@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow565_to_888rev(void* dst, void* src, u32 len, u32 step);

template <typename T>
static void copyrow_basic(void* dst, void* src, u32 len, u32 step)
{
    T* ARTS_RESTRICT dstT = static_cast<T*>(dst);
    T* ARTS_RESTRICT srcT = static_cast<T*>(src);

    if (step == 0x10000)
    {
        std::memcpy(dstT, srcT, len * sizeof(T));
        return;
    }

    for (u32 src_off = 0; len; --len)
    {
        *dstT++ = srcT[src_off >> 16];
        src_off += step;
    }
}

void agiSurfaceDesc::CopyFrom(agiSurfaceDesc* src, i32 src_lod)
{
    CopyFrom(src, src_lod, nullptr);
}

void agiSurfaceDesc::CopyFrom(agiSurfaceDesc* src, i32 src_lod, agiTexParameters* params)
{
    const u32 dst_width = Width;
    const u32 dst_height = Height;
    const i32 dst_pitch = Pitch;
    u8* const dst_surface = static_cast<u8*>(Surface);

    // FIXME: Surfaces with a PackShift don't have their pitch updated. This should really be corrected in agiSurfaceDesc::Load.
    src->FixPitch();

    u32 src_width = src->Width;
    u32 src_height = src->Height;
    i32 src_pitch = src->Pitch;
    u8* src_surface = static_cast<u8*>(src->Surface);

    for (; src_lod; --src_lod)
    {
        src_surface += src_pitch * src_height;
        src_width >>= 1;
        src_height >>= 1;
        src_pitch >>= 1;
    }

    void (*copy_row)(void*, void*, u32, u32) = nullptr;

    if (!std::memcmp(&PixelFormat, &src->PixelFormat, sizeof(PixelFormat)))
    {
        if (src_width == dst_width && src_height == dst_height && src_pitch == dst_pitch)
        {
            std::memcpy(dst_surface, src_surface, dst_pitch * dst_height);

            return;
        }

        switch (GetPixelSize())
        {
            case sizeof(u8): copy_row = copyrow_basic<u8>; break;
            case sizeof(u16): copy_row = copyrow_basic<u16>; break;
            case sizeof(u32): copy_row = copyrow_basic<u32>; break;

            default: Quitf("Invalid Pixel Format");
        }
    }
    else
    {
        switch (src->PixelFormat.RBitMask)
        {
            case 0xF800: // 565
                switch (PixelFormat.RBitMask)
                {
                    case 0xFF0000u: copy_row = copyrow565_to_888; break;
                    case 0xFFu: copy_row = copyrow565_to_888rev; break;

                    case 0x7C00u:
                        if (PixelFormat.RGBAlphaBitMask == 0x8000)
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
                // 4444_to_565, 4444_to_5551, 4444_to_555 do alpha multiplication, but 4444_to_8888 and 4444_to_8888rev do not.
                // Therefore, 4444_to_888amul was added to do the alpha multiplication when needed

                switch (PixelFormat.RBitMask)
                {
                    case 0xFF0000u:
                        copy_row = (params && (params->Props & agiTexProp::AlphaGlow) &&
                                       !(params->Flags & agiTexParameters::Alpha))
                            ? copyrow4444_to_888amul
                            : copyrow4444_to_8888;
                        break;
                    case 0xFFu: copy_row = copyrow4444_to_8888rev; break;

                    case 0xF800u: copy_row = copyrow4444_to_565; break;
                    case 0x7C00u:
                        if (PixelFormat.RGBAlphaBitMask == 0x8000)
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
    }

    if (!copy_row)
    {
        Quitf("Tell Dave to implement (%x,%x,%x,%x)-->(%x,%x,%x,%x) copyrow function.", src->PixelFormat.RBitMask,
            src->PixelFormat.GBitMask, src->PixelFormat.BBitMask, src->PixelFormat.RGBAlphaBitMask,
            PixelFormat.RBitMask, PixelFormat.GBitMask, PixelFormat.BBitMask, PixelFormat.RGBAlphaBitMask);
    }

    // 16:16 fixed point arithmetic
    // Avoids costly div instructions inside the for loop
    const u32 src_x_step = (src_width << 16) / dst_width;
    const u32 src_y_step = (src_height << 16) / dst_height;

    for (u32 dst_y = 0, src_y = 0; dst_y < dst_height; ++dst_y, src_y += src_y_step)
    {
        copy_row(dst_surface + (dst_pitch * dst_y), src_surface + (src_pitch * (src_y >> 16)), dst_width, src_x_step);
    }
}

void agiSurfaceDesc::Unload()
{
    if (Surface)
    {
        delete[] static_cast<u8*>(Surface);
        Surface = nullptr;
    }
}

void agiSurfaceDesc::Init(i32 width, i32 height)
{
    Flags = AGISD_WIDTH | AGISD_HEIGHT | AGISD_PITCH | AGISD_PIXELFORMAT;
    Width = width;
    Height = height;
    Pitch = (width * GetPixelSize() + 3) & ~3;
    Surface = nullptr;
    MipMapCount = 0;
    SCaps.Caps = 0;

    Load();
    Clear();
}

[[nodiscard]] Owner<agiSurfaceDesc> agiSurfaceDesc::Init(i32 width, i32 height, const agiSurfaceDesc& desc)
{
    Ptr<agiSurfaceDesc> result = MakeUnique<agiSurfaceDesc>(desc);
    result->Init(width, height);
    return AsOwner(result);
}

void agiSurfaceDesc::Load()
{
    if (Surface == nullptr)
        Surface = new u8[Pitch * Height];
}

void agiSurfaceDesc::Clear()
{
    std::memset(Surface, 0, Pitch * Height);
}

void agiSurfaceDesc::Clear(i32 x, i32 y, i32 width, i32 height)
{
    if (x + width > static_cast<i32>(Width) || y + height > static_cast<i32>(Height))
        return;

    i32 pixel_size = GetPixelSize();

    for (; height; ++y, --height)
        std::memset(static_cast<u8*>(Surface) + (y * Pitch) + (x * pixel_size), 0, width * pixel_size);
}

void agiSurfaceDesc::Fill(i32 x, i32 y, i32 width, i32 height, u32 color)
{
    if (x + width > static_cast<i32>(Width) || y + height > static_cast<i32>(Height))
        return;

    Rc<agiColorModel> cmodel = AsRc(agiColorModel::FindMatch(this));

    color = cmodel->GetColor(agiRgba::FromARGB(color));

    u32 byte_count = cmodel->PixelSize;

    for (; height; ++y, --height)
    {
        void* row = static_cast<u8*>(Surface) + (y * Pitch) + (x * byte_count);

        switch (byte_count)
        {
            case 2:
                for (i32 i = 0; i < width; ++i)
                    static_cast<u16*>(row)[i] = static_cast<u16>(color);
                break;

            case 4:
                for (i32 i = 0; i < width; ++i)
                    static_cast<u32*>(row)[i] = color;
                break;
        }
    }
}

void agiSurfaceDesc::FixPitch()
{
    if (Pitch < 0)
        return;

    // Some RV3 textures have linear size instead of pitch
    if (Flags & AGISD_LINEARSIZE)
    {
        Pitch /= Height;
        Flags &= ~AGISD_LINEARSIZE;
        Flags |= AGISD_PITCH;
    }

    i32 pitch = Width * GetPixelSize();

    if (!(Flags & AGISD_PITCH) || (pitch > Pitch) || ((std::max) ((pitch + 3) & ~3, pitch * 2) <= Pitch))
    {
        Pitch = pitch;
        Flags |= AGISD_PITCH;
    }
}

agiSurfaceDesc agiSurfaceDesc::FromFormat(const agiPixelFormat& format)
{
    agiSurfaceDesc result {sizeof(result)};
    result.Flags = AGISD_PIXELFORMAT;
    result.PixelFormat = format;
    return result;
}

DDPIXELFORMAT agiPixelFormat::ToDD()
{
    return mem::bit_cast<DDPIXELFORMAT>(*this);
}

agiPixelFormat agiPixelFormat::FromDD(const DDPIXELFORMAT& sd)
{
    return mem::bit_cast<agiPixelFormat>(sd);
}

DDSURFACEDESC2 agiSurfaceDesc::ToDD()
{
    return mem::bit_cast<DDSURFACEDESC2>(*this); // FIXME: 64-bit incompatible
}

agiSurfaceDesc agiSurfaceDesc::FromDD(const DDSURFACEDESC2& sd)
{
    return mem::bit_cast<agiSurfaceDesc>(sd); // FIXME: 64-bit incompatible
}
