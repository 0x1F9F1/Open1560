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
#include "data7/b2f.h"
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

void agiMeshSet::ToScreen(u8* in_codes, Vector4* verts, i32 count)
{
    ARTS_TIMED(agiInvertTimer);

    if (count >= 8 && UseKNI)
    {
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

        do
        {
            // NOTE: This is undefined behaviour. A safer version would use std::bit_cast/equivalent
            if (*reinterpret_cast<const u32*>(in_codes) == 0x40404040)
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
                    _mm_min_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_mul_ps(vert_2, KniDepthScale), vert_3), KniDepthOffset), KniMaxZ),
                    KniMinZ);

                _MM_TRANSPOSE4_PS(vert_0, vert_1, vert_2, vert_3);

                _mm_store_ps(&verts[0].x, vert_0);
                _mm_store_ps(&verts[1].x, vert_1);
                _mm_store_ps(&verts[2].x, vert_2);
                _mm_store_ps(&verts[3].x, vert_3);
            }
            else
            {
                for (i32 i = 0; i < 4; ++i)
                {
                    if (in_codes[i] != 0x40)
                        continue;

                    __m128 vert = _mm_load_ps(&verts[i].x);

                    // xyzw -> wzxy
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

                    // wzxy -> xyzw
                    vert = _mm_shuffle_ps(vert, vert, _MM_SHUFFLE(0, 1, 2, 3));

                    _mm_store_ps(&verts[i].x, vert);
                }
            }

            in_codes += 4;
            verts += 4;
            count -= 4;
        } while (count >= 4);
    }

    for (i32 i = 0; i < count; ++i)
    {
        if (in_codes[i] != 0x40)
            continue;

        Vector4* vert = &verts[i];

        f32 const inv_w = 1.0f / vert->w;

        vert->x = (vert->x * inv_w * HalfWidth) + OffsX;
        vert->y = (vert->y * inv_w * HalfHeight) + OffsY;
        vert->z = (vert->z * inv_w * DepthScale) + DepthOffset;
        vert->w = inv_w;

        ClampToScreen(vert);
    }
}