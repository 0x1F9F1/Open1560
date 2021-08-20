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

define_dummy_symbol(agiworld_meshlight);

#include "meshlight.h"
#include "meshset.h"
#include "packnorm.h"
#include "vector7/vector3.h"

// ?agiInitCones@@YAXAAVMatrix34@@M@Z
ARTS_IMPORT /*static*/ void agiInitCones(Matrix34& arg1, f32 arg2);

#ifdef ARTS_ENABLE_KNI
#    include <xmmintrin.h>
#else
#    include "data7/b2f.h"
#    include "data7/mmx.h"
#    include "mmx.h"

static mmx keyNormal;
static mmx fill1Normal;
static mmx fill2Normal;

// ?mmxTriple@@YAXPAI0HPAEH@Z
static void mmxTriple(
    u32* ARTS_RESTRICT output, u32* ARTS_RESTRICT colors, i32 stride, u8* ARTS_RESTRICT normals, i32 count)
{
    for (i32 i = 0; i < count; ++i, colors += stride)
    {
        // Normals/Colors use 1:1:14 fixed point
        // Each _m_pmulhw shifts the radix point by 2

        __m64 normal = UnpackNormalMMX[normals[i]].mm;

        // intensity = intensity * normal
        __m64 key_intensity = _m_pmulhw(normal, keyNormal.mm);
        __m64 fill1_intensity = _m_pmulhw(normal, fill1Normal.mm);
        __m64 fill2_intensity = _m_pmulhw(normal, fill2Normal.mm);

        // intensity.rgba = intensity.r + intensity.b + intensity.a
        __m64 temp = _m_psrlqi(key_intensity, 0x10);
        key_intensity = _m_paddw(key_intensity, temp);
        key_intensity = _m_paddw(key_intensity, _m_psrlqi(temp, 0x10));
        key_intensity = _m_punpcklwd(key_intensity, key_intensity);
        key_intensity = _m_punpcklwd(key_intensity, key_intensity);

        temp = _m_psrlqi(fill1_intensity, 0x10);
        fill1_intensity = _m_paddw(fill1_intensity, temp);
        fill1_intensity = _m_paddw(fill1_intensity, _m_psrlqi(temp, 0x10));
        fill1_intensity = _m_punpcklwd(fill1_intensity, fill1_intensity);
        fill1_intensity = _m_punpcklwd(fill1_intensity, fill1_intensity);

        temp = _m_psrlqi(fill2_intensity, 0x10);
        fill2_intensity = _m_paddw(fill2_intensity, temp);
        fill2_intensity = _m_paddw(fill2_intensity, _m_psrlqi(temp, 0x10));
        fill2_intensity = _m_punpcklwd(fill2_intensity, fill2_intensity);
        fill2_intensity = _m_punpcklwd(fill2_intensity, fill2_intensity);

        // intensity = max(intensity, 0.0) * color
        key_intensity = _m_pmulhw(_m_pand(key_intensity, _m_pcmpgtw(key_intensity, minus1.mm)), keyColor.mm);
        fill1_intensity = _m_pmulhw(_m_pand(fill1_intensity, _m_pcmpgtw(fill1_intensity, minus1.mm)), fill1Color.mm);
        fill2_intensity = _m_pmulhw(_m_pand(fill2_intensity, _m_pcmpgtw(fill2_intensity, minus1.mm)), fill2Color.mm);

        // intensity = key + fill1 + fill2 + amb
        __m64 intensity = _m_paddw(_m_paddw(_m_paddw(key_intensity, fill1_intensity), fill2_intensity), ambColor.mm);

        // intensity.rgb = min(intensity.rgb, 1.0)
        // intensity.a = 1.0
        intensity = _m_psubw(_m_paddsw(intensity, clampSSS_3_10.mm), unclampSSS_3_10.mm);

        __m64 color_64 = _m_from_int(*colors);
        color_64 = _m_psrlwi(_m_punpcklbw(color_64, color_64), 1);
        color_64 = _m_psrlwi(_m_pmulhw(color_64, intensity), 1);

        output[i] = _m_to_int(_m_packuswb(color_64, color_64));
    }

    _m_empty();
}

// Quantize signed normals using 1:1:14 | [-1.0, +1.0] -> [-0x4000,+0x4000]
static ARTS_FORCEINLINE void PackNormalMMX(mmx& output, const Vector3& input)
{
    output.m16[0] = static_cast<u16>(mem::bit_cast<u32>(input.z + 768.0f));
    output.m16[1] = static_cast<u16>(mem::bit_cast<u32>(input.y + 768.0f));
    output.m16[2] = static_cast<u16>(mem::bit_cast<u32>(input.x + 768.0f));
    output.m16[3] = 0;
}
#endif

void agiMeshLighterTriple(
    [[maybe_unused]] u8* ARTS_RESTRICT codes, u32* ARTS_RESTRICT output, u32* ARTS_RESTRICT colors, agiMeshSet* mesh)
{
    agiMeshSet::InitLocalize();

    Vector3 sun_dir;
    Vector3 fill1_dir;
    Vector3 fill2_dir;

    agiMeshSet::LocalizeDirection(sun_dir, agiMeshLighterSun);
    agiMeshSet::LocalizeDirection(fill1_dir, agiMeshLighterFill1);
    agiMeshSet::LocalizeDirection(fill2_dir, agiMeshLighterFill2);

    i32 stride = 1;

    if (colors == nullptr)
    {
        static u32 color_white[1] {0xFFFFFFFF};
        stride = 0;
        colors = color_white;
    }

    i32 count = mesh->AdjunctCount;

#ifdef ARTS_ENABLE_KNI
    __m128 const dirs_x = _mm_set_ps(0.0f, fill2_dir.x, fill1_dir.x, sun_dir.x);
    __m128 const dirs_y = _mm_set_ps(0.0f, fill2_dir.y, fill1_dir.y, sun_dir.y);
    __m128 const dirs_z = _mm_set_ps(0.0f, fill2_dir.z, fill1_dir.z, sun_dir.z);

    __m128 const sun_color =
        _mm_set_ps(0.0f, agiMeshLighterSunColor.x, agiMeshLighterSunColor.y, agiMeshLighterSunColor.z);
    __m128 const fill1_color =
        _mm_set_ps(0.0f, agiMeshLighterFill1Color.x, agiMeshLighterFill1Color.y, agiMeshLighterFill1Color.z);
    __m128 const fill2_color =
        _mm_set_ps(0.0f, agiMeshLighterFill2Color.x, agiMeshLighterFill2Color.y, agiMeshLighterFill2Color.z);
    __m128 const ambient_color =
        _mm_set_ps(1.0f, agiMeshLighterAmbient.x, agiMeshLighterAmbient.y, agiMeshLighterAmbient.z);

    for (i32 i = 0; i < count; ++i, colors += stride)
    {
        const Vector3& normal = UnpackNormal[mesh->Normals[i]];

        __m128 const color_128 = _mm_cvtepi32_ps(
            _mm_unpacklo_epi16(_mm_unpacklo_epi8(_mm_loadu_si32(colors), _mm_setzero_si128()), _mm_setzero_si128()));

        __m128 const nx = _mm_mul_ps(_mm_load1_ps(&normal.x), dirs_x);
        __m128 const ny = _mm_mul_ps(_mm_load1_ps(&normal.y), dirs_y);
        __m128 const nz = _mm_mul_ps(_mm_load1_ps(&normal.z), dirs_z);
        __m128 const intensity = _mm_max_ps(_mm_add_ps(_mm_add_ps(nx, ny), nz), _mm_set1_ps(0.0f));

        __m128 const sun_colored = _mm_mul_ps(sun_color, _mm_shuffle_ps(intensity, intensity, _MM_SHUFFLE(0, 0, 0, 0)));
        __m128 const fill1_colored =
            _mm_mul_ps(fill1_color, _mm_shuffle_ps(intensity, intensity, _MM_SHUFFLE(1, 1, 1, 1)));
        __m128 const fill2_colored =
            _mm_mul_ps(fill2_color, _mm_shuffle_ps(intensity, intensity, _MM_SHUFFLE(2, 2, 2, 2)));

        __m128 const colored =
            _mm_min_ps(_mm_add_ps(_mm_add_ps(_mm_add_ps(sun_colored, fill1_colored), fill2_colored), ambient_color),
                _mm_set1_ps(1.0f));

        __m128i const shaded = _mm_cvtps_epi32(_mm_mul_ps(color_128, colored));

        output[i] =
            _mm_cvtsi128_si32(_mm_packus_epi16(_mm_packs_epi32(shaded, _mm_setzero_si128()), _mm_setzero_si128()));
    }
#else
    if (UseMMX && count >= 8)
    {
        PackNormalMMX(keyNormal, sun_dir);
        PackNormalMMX(fill1Normal, fill1_dir);
        PackNormalMMX(fill2Normal, fill2_dir);
        mmxTriple(output, colors, stride, mesh->Normals, count);
        return;
    }

    for (i32 i = 0; i < count; ++i, colors += stride)
    {
        if (codes && !(codes[mesh->VertexIndices[i]] & MESH_CLIP_SCREEN))
            continue;

        u32 const color = *colors;
        const Vector3& normal = UnpackNormal[mesh->Normals[i]];

        f32 sun_intensity = normal.x * sun_dir.x + normal.y * sun_dir.y + normal.z * sun_dir.z;
        f32 fill1_intensity = normal.x * fill1_dir.x + normal.y * fill1_dir.y + normal.z * fill1_dir.z;
        f32 fill2_intensity = normal.x * fill2_dir.x + normal.y * fill2_dir.y + normal.z * fill2_dir.z;

        sun_intensity = std::max<f32>(sun_intensity, 0.0f);
        fill1_intensity = std::max<f32>(fill1_intensity, 0.0f);
        fill2_intensity = std::max<f32>(fill2_intensity, 0.0f);

        f32 r_intensity = (agiMeshLighterSunColor.x * sun_intensity) + (agiMeshLighterFill1Color.x * fill1_intensity) +
            (agiMeshLighterFill2Color.x * fill2_intensity) + agiMeshLighterAmbient.x;
        f32 g_intensity = (agiMeshLighterSunColor.y * sun_intensity) + (agiMeshLighterFill1Color.y * fill1_intensity) +
            (agiMeshLighterFill2Color.y * fill2_intensity) + agiMeshLighterAmbient.y;
        f32 b_intensity = (agiMeshLighterSunColor.z * sun_intensity) + (agiMeshLighterFill1Color.z * fill1_intensity) +
            (agiMeshLighterFill2Color.z * fill2_intensity) + agiMeshLighterAmbient.z;

        u32 r = FloatToByte(std::min<f32>(r_intensity, 1.0f) * ByteToFloat((color >> 16) & 0xFF));
        u32 g = FloatToByte(std::min<f32>(g_intensity, 1.0f) * ByteToFloat((color >> 8) & 0xFF));
        u32 b = FloatToByte(std::min<f32>(b_intensity, 1.0f) * ByteToFloat((color >> 0) & 0xFF));

        output[i] = (color & 0xFF000000) | (r << 16) | (g << 8) | (b << 0);
    }
#endif
}
