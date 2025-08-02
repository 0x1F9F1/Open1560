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

#pragma once

#include "meshset.h"

#include "vector7/vector4.h"

// ?SetClipMode@@YAXH@Z | unused
ARTS_EXPORT void SetClipMode(b32 mask_only_z);

// ?MaxCardSize@@3MA
ARTS_IMPORT extern f32 MaxCardSize;

// ?MinCardSize@@3MA
ARTS_IMPORT extern f32 MinCardSize;

// ?ShadowColor@@3IA
ARTS_IMPORT extern u32 ShadowColor;

// ?ShadowFudge@@3MA
ARTS_IMPORT extern f32 ShadowFudge;

// ?SphMapColor@@3IA
ARTS_IMPORT extern u32 SphMapColor;

struct agiMeshCardVertex
{
    f32 x, y;
    f32 tu, tv;
};

check_size(agiMeshCardVertex, 0x10);

struct agiMeshCardInfo
{
public:
    // ?Init@agiMeshCardInfo@@QAEXHPAUagiMeshCardVertex@@HHH@Z
    ARTS_IMPORT void Init(i32 arg1, agiMeshCardVertex* arg2, i32 arg3, i32 arg4, i32 arg5);

    i32 VertCount {};
    i32 PointCount {};
    Vector2* Rotations {};
    Vector2* Frames {};
};

check_size(agiMeshCardInfo, 0x10);

template <typename T>
inline void agiMeshSet::ClampToScreen(T& vert)
{
    vert.x = std::min<f32>(vert.x, MaxX);
    vert.y = std::min<f32>(vert.y, MaxY);
    vert.z = std::min<f32>(vert.z, 1.0f);

    vert.x = std::max<f32>(vert.x, MinX);
    vert.y = std::max<f32>(vert.y, MinY);
    vert.z = std::max<f32>(vert.z, 0.0f);
}

void agiBlendColors(u32* ARTS_RESTRICT shaded, u32* ARTS_RESTRICT colors, i32 count, u32 color);
