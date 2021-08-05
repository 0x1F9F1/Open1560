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

/*
    agiworld:quality

    0x64ACD8 | struct agiWorldRenderQuality agiRQ | ?agiRQ@@3UagiWorldRenderQuality@@A
*/

#define AGI_QUALITY_LOW 0
#define AGI_QUALITY_MEDIUM 1
#define AGI_QUALITY_HIGH 2
#define AGI_QUALITY_VERY_HIGH 3

struct agiWorldRenderQuality
{
    i32 Shadow;
    b32 EnvMap;
    b32 SphMap;
    b32 TexturedSky;

    i32 LightQuality;

    // Texture Resolution
    i32 TextureQuality;

    // Object Detail
    i32 TerrainQuality;

    f32 FarClip;

    f32 field_20;

    // 0 | Point
    // 1 | Linear
    // 2 | Linear Mip
    i32 TexFilter;
};

check_size(agiWorldRenderQuality, 0x28);

// ?agiRQ@@3UagiWorldRenderQuality@@A
ARTS_IMPORT extern struct agiWorldRenderQuality agiRQ;
