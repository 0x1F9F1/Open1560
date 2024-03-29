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

define_dummy_symbol(agiworld_mrkni);

#include "mrkni.h"

#include "agi/pipeline.h"
#include "agi/viewport.h"
#include "data7/mmx.h"
#include "data7/utimer.h"
#include "vector7/matrix34.h"

#include <xmmintrin.h>

static u32 KniViewSerial = 0xFFFFFFFF;

static __m128 KniOffsX;
static __m128 KniHalfWidth;
static __m128 KniMinX;
static __m128 KniMaxX;

static __m128 KniOffsY;
static __m128 KniHalfHeight;
static __m128 KniMinY;
static __m128 KniMaxY;

static __m128 KniMin;
static __m128 KniMax;

void agiMeshSet::ToScreen(u8* ARTS_RESTRICT in_codes, Vector4* ARTS_RESTRICT verts, i32 count)
{
    static constexpr u32 CLIP_SCREEN_32 = MESH_CLIP_SCREEN * 0x01010101;

    ARTS_UTIMED(agiInvertTimer);

    const __m128 KniMinZ = _mm_set1_ps(0.0f);
    const __m128 KniMaxZ = _mm_set1_ps(1.0f);

    if (KniViewSerial != agiMeshSet::ViewSerial)
    {
        KniViewSerial = agiMeshSet::ViewSerial;

        KniOffsX = _mm_set1_ps(OffsX);
        KniHalfWidth = _mm_set1_ps(HalfWidth);
        KniMinX = _mm_set1_ps(MinX);
        KniMaxX = _mm_set1_ps(MaxX);

        KniOffsY = _mm_set1_ps(OffsY);
        KniHalfHeight = _mm_set1_ps(HalfHeight);
        KniMinY = _mm_set1_ps(MinY);
        KniMaxY = _mm_set1_ps(MaxY);

        KniMin = _mm_movehl_ps(_mm_unpacklo_ps(KniMinY, KniMinX), KniMinZ);
        KniMax = _mm_movehl_ps(_mm_unpacklo_ps(KniMaxY, KniMaxX), KniMaxZ);
    }

    // NOTE: DepthOffset and DepthScale are public can change between ViewSerial's
    const __m128 KniDepthOffset = _mm_set1_ps(DepthOffset);
    const __m128 KniDepthScale = _mm_set1_ps(DepthScale);

    const __m128 KniScale = _mm_movehl_ps(_mm_unpacklo_ps(KniHalfHeight, KniHalfWidth), KniDepthScale);
    const __m128 KniOffset = _mm_movehl_ps(_mm_unpacklo_ps(KniOffsY, KniOffsX), KniDepthOffset);

    while (count >= 4)
    {
        if (*reinterpret_cast<const u32*>(in_codes) & CLIP_SCREEN_32)
        {
            __m128 vert_0 = _mm_load_ps(&verts[0].x);
            __m128 vert_1 = _mm_load_ps(&verts[1].x);
            __m128 vert_2 = _mm_load_ps(&verts[2].x);
            __m128 vert_3 = _mm_load_ps(&verts[3].x);

            _MM_TRANSPOSE4_PS(vert_0, vert_1, vert_2, vert_3);

            // The maximum relative error for this approximation is less than 1.5*2^-12.
            const __m128 inv_w = _mm_rcp_ps(vert_3);

            // Compensate due to loss of precision
            vert_3 = _mm_sub_ps(_mm_add_ps(inv_w, inv_w), _mm_mul_ps(_mm_mul_ps(vert_3, inv_w), inv_w));

            vert_0 = _mm_max_ps(
                _mm_min_ps(_mm_add_ps(_mm_mul_ps(_mm_mul_ps(vert_0, KniHalfWidth), vert_3), KniOffsX), KniMaxX),
                KniMinX);

            vert_1 = _mm_max_ps(
                _mm_min_ps(_mm_add_ps(_mm_mul_ps(_mm_mul_ps(vert_1, KniHalfHeight), vert_3), KniOffsY), KniMaxY),
                KniMinY);

            vert_2 = _mm_max_ps(
                _mm_min_ps(_mm_add_ps(_mm_mul_ps(_mm_mul_ps(vert_2, KniDepthScale), vert_3), KniDepthOffset), KniMaxZ),
                KniMinZ);

            _MM_TRANSPOSE4_PS(vert_0, vert_1, vert_2, vert_3);

            _mm_store_ps(&verts[0].x, vert_0);
            _mm_store_ps(&verts[1].x, vert_1);
            _mm_store_ps(&verts[2].x, vert_2);
            _mm_store_ps(&verts[3].x, vert_3);
        }

        in_codes += 4;
        verts += 4;
        count -= 4;
    }

    while (count)
    {
        if (*in_codes & MESH_CLIP_SCREEN)
        {
            __m128 vert = _mm_load_ps(&verts->x);

            // xyzw -> wzyx
            vert = _mm_shuffle_ps(vert, vert, _MM_SHUFFLE(0, 1, 2, 3));

            // The maximum relative error for this approximation is less than 1.5*2^-12.
            __m128 inv_w = _mm_rcp_ss(vert);

            // Compensate due to loss of precision
            vert = _mm_sub_ss(_mm_add_ss(inv_w, inv_w), _mm_mul_ss(_mm_mul_ss(vert, inv_w), inv_w));

            inv_w = _mm_shuffle_ps(vert, vert, _MM_SHUFFLE(0, 0, 0, 0));

            vert = _mm_mul_ps(vert, KniScale);
            vert = _mm_mul_ps(vert, inv_w);
            vert = _mm_add_ps(vert, KniOffset);
            vert = _mm_max_ps(_mm_min_ps(vert, KniMax), KniMin);
            vert = _mm_move_ss(vert, inv_w);

            // wzyx -> xyzw
            vert = _mm_shuffle_ps(vert, vert, _MM_SHUFFLE(0, 1, 2, 3));

            _mm_store_ps(&verts->x, vert);
        }

        in_codes += 1;
        verts += 1;
        count -= 1;
    }
}

#define ARTS_KNI_TRANSFORM_INIT                                                                                   \
    const __m128 mdata0 = _mm_loadu_ps((const f32*) (&M) + 0);                                                    \
    const __m128 mdata4 = _mm_loadu_ps((const f32*) (&M) + 4);                                                    \
    const __m128 mdata8 = _mm_loadu_ps((const f32*) (&M) + 8);                                                    \
    const __m128 m0 = _mm_shuffle_ps(mdata0, mdata0, _MM_SHUFFLE(0, 1, 2, 2));                                    \
    const __m128 m1 =                                                                                             \
        _mm_shuffle_ps(mdata4, _mm_shuffle_ps(mdata0, mdata4, _MM_SHUFFLE(0, 0, 0, 3)), _MM_SHUFFLE(0, 2, 1, 1)); \
    const __m128 m2 = _mm_shuffle_ps(mdata8, mdata4, _MM_SHUFFLE(2, 3, 0, 0));                                    \
    const __m128 m3 = _mm_shuffle_ps(mdata8, mdata8, _MM_SHUFFLE(1, 2, 3, 3));                                    \
    const __m128 zz = _mm_load_ss(&ProjZZ);                                                                       \
    const __m128 zw = _mm_load_ss(&ProjZW)

#define ARTS_KNI_TRANSFORM_FOG_INIT            \
    const __m128 fog = _mm_load_ss(&FogValue); \
    const __m128 fog_max = _mm_set_ss(255.0f);

#define ARTS_KNI_TRANSFORM_DOT                                                                                       \
    const __m128 input_low = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i*) &input[i].x));                        \
    const __m128 output_128 = _mm_add_ss(                                                                            \
        _mm_mul_ss(                                                                                                  \
            _mm_add_ps(                                                                                              \
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(input_low, input_low, _MM_SHUFFLE(0, 0, 0, 0)), m0), \
                               _mm_mul_ps(_mm_shuffle_ps(input_low, input_low, _MM_SHUFFLE(1, 1, 1, 1)), m1)),       \
                    _mm_mul_ps(_mm_load1_ps(&input[i].z), m2)),                                                      \
                m3),                                                                                                 \
            zz),                                                                                                     \
        zw);                                                                                                         \
    const __m128 output_real_128 = _mm_shuffle_ps(output_128, output_128, _MM_SHUFFLE(1, 0, 2, 3));                  \
    _mm_store_ps(&output[i].x, output_real_128)

#define ARTS_KNI_TRANSFORM_FOG \
    fogout[i] = ~static_cast<u8>(_mm_cvtt_ss2si(_mm_min_ss(_mm_mul_ss(output_128, fog), fog_max)));

#define ARTS_KNI_TRANSFORM_CODES_INIT const __m128 abs_mask = _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF));

#define ARTS_KNI_TRANSFORM_CODE                                                                                  \
    const __m128 output_abs_128 = _mm_and_ps(abs_mask, output_real_128);                                         \
    u8 is_neg = _mm_movemask_ps(output_real_128) & 0x7;                                                          \
    u8 is_clip = _mm_movemask_ps(_mm_sub_ps(                                                                     \
                     _mm_shuffle_ps(output_abs_128, output_abs_128, _MM_SHUFFLE(3, 3, 3, 3)), output_abs_128)) & \
        0x7;                                                                                                     \
    u8 clip_code = CodesLookup[(is_neg << 3) + is_clip];                                                         \
    clip_any |= clip_code;                                                                                       \
    clip_all &= clip_code;                                                                                       \
    out_codes[i] = clip_code;

void agiMeshSet::Transform(Vector4* ARTS_RESTRICT output, Vector3* ARTS_RESTRICT input, i32 count)
{
    STATS.VertsXfrm += count;

    ARTS_KNI_TRANSFORM_INIT;

    if (FogValue == 0.0f)
    {
        for (i32 i = 0; i < count; ++i)
        {
            ARTS_KNI_TRANSFORM_DOT;
        }
    }
    else
    {
        ARTS_KNI_TRANSFORM_FOG_INIT;

        for (i32 i = 0; i < count; ++i)
        {
            ARTS_KNI_TRANSFORM_DOT;
            ARTS_KNI_TRANSFORM_FOG;
        }
    }
}

/*
    Converts clip mask from:
        (sign(abs(w) - abs(x)) << 0) |
        (sign(abs(w) - abs(y)) << 1) |
        (sign(abs(w) - abs(z)) << 2) |
        (sign(x) << 3) |
        (sign(y) << 4) |
        (sign(z) << 5);
    To:
        (sign(abs(w) - abs(x)) << (sign(x) + 0)) |
        (sign(abs(w) - abs(y)) << (sign(x) + 2)) |
        (sign(abs(w) - abs(z)) << (sign(x) + 4));
*/
alignas(64) static const u8 CodesLookup[64] {
    // clang-format off
    0x00, 0x01, 0x04, 0x05, 0x10, 0x11, 0x14, 0x15,
    0x00, 0x02, 0x04, 0x06, 0x10, 0x12, 0x14, 0x16,
    0x00, 0x01, 0x08, 0x09, 0x10, 0x11, 0x18, 0x19,
    0x00, 0x02, 0x08, 0x0A, 0x10, 0x12, 0x18, 0x1A,
    0x00, 0x01, 0x04, 0x05, 0x20, 0x21, 0x24, 0x25,
    0x00, 0x02, 0x04, 0x06, 0x20, 0x22, 0x24, 0x26,
    0x00, 0x01, 0x08, 0x09, 0x20, 0x21, 0x28, 0x29,
    0x00, 0x02, 0x08, 0x0A, 0x20, 0x22, 0x28, 0x2A,
    // clang-format on
};

u32 agiMeshSet::TransformOutcode(
    u8* ARTS_RESTRICT out_codes, Vector4* ARTS_RESTRICT output, Vector3* ARTS_RESTRICT input, i32 count)
{
    STATS.VertsOut += count;
    STATS.VertsXfrm += count;

    u8 clip_any = 0;
    u8 clip_all = 0xFF;

    ARTS_KNI_TRANSFORM_INIT;
    ARTS_KNI_TRANSFORM_CODES_INIT;

    if (FogValue == 0.0f)
    {
        for (i32 i = 0; i < count; ++i)
        {
            ARTS_KNI_TRANSFORM_DOT;
            ARTS_KNI_TRANSFORM_CODE;
        }
    }
    else
    {
        ARTS_KNI_TRANSFORM_FOG_INIT;

        for (i32 i = 0; i < count; ++i)
        {
            ARTS_KNI_TRANSFORM_DOT;
            ARTS_KNI_TRANSFORM_FOG;
            ARTS_KNI_TRANSFORM_CODE;
        }
    }

    return clip_any | (clip_all << 8);
}

void agiBlendColors(u32* ARTS_RESTRICT shaded, u32* ARTS_RESTRICT colors, i32 count, u32 color)
{
    if (count >= 4)
    {
        const __m128i color16 = _mm_unpacklo_epi8(_mm_set1_epi32(color), _mm_setzero_si128());

        do
        {
            __m128i colors16 = _mm_loadu_si128((const __m128i*) (colors));

            __m128i colors_lo = _mm_unpacklo_epi8(colors16, _mm_setzero_si128());
            __m128i colors_hi = _mm_unpackhi_epi8(colors16, _mm_setzero_si128());

            colors_lo = _mm_mullo_epi16(colors_lo, color16);
            colors_hi = _mm_mullo_epi16(colors_hi, color16);

            colors_lo = _mm_mulhi_epu16(colors_lo, _mm_set1_epi16(-0x7F7F));
            colors_hi = _mm_mulhi_epu16(colors_hi, _mm_set1_epi16(-0x7F7F));

            colors_lo = _mm_srli_epi16(colors_lo, 7);
            colors_hi = _mm_srli_epi16(colors_hi, 7);

            _mm_storeu_si128((__m128i*) shaded, _mm_packus_epi16(colors_lo, colors_hi));

            shaded += 4;
            colors += 4;
            count -= 4;
        } while (count >= 4);
    }

    if (count)
    {
        const u32 mul_b = (color & 0xFF) * 0x8081;
        const u32 mul_g = ((color >> 8) & 0xFF) * 0x8081;
        const u32 mul_r = ((color >> 16) & 0xFF) * 0x8081;
        const u32 mul_a = (color >> 24) * 0x8081;

        for (i32 i = 0; i < count; ++i)
        {
            const u32 input = colors[i];

            const u8 b = static_cast<u8>((mul_b * (input & 0xFF)) >> 23);
            const u8 g = static_cast<u8>((mul_g * ((input >> 8) & 0xFF)) >> 23);
            const u8 r = static_cast<u8>((mul_r * ((input >> 16) & 0xFF)) >> 23);
            const u8 a = static_cast<u8>((mul_a * (input >> 24)) >> 23);

            shaded[i] = (a << 24) | (r << 16) | (g << 8) | b;
        }
    }
}
