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
    mmcar:surfaceaudioinfo

    0x470D50 | void __cdecl SetClearSurfaceAudioInfos(void) | ?SetClearSurfaceAudioInfos@@YAXXZ
    0x470FB0 | void __cdecl SetRainSurfaceAudioInfos(void) | ?SetRainSurfaceAudioInfos@@YAXXZ
    0x471210 | void __cdecl SetSnowSurfaceAudioInfos(void) | ?SetSnowSurfaceAudioInfos@@YAXXZ
    0x6A7CE0 | struct tagSurfaceAudioInfo * SURFACEAUDIOINFO | ?SURFACEAUDIOINFO@@3PAUtagSurfaceAudioInfo@@A
*/

// 0x470D50 | ?SetClearSurfaceAudioInfos@@YAXXZ
void SetClearSurfaceAudioInfos();

// 0x470FB0 | ?SetRainSurfaceAudioInfos@@YAXXZ
void SetRainSurfaceAudioInfos();

// 0x471210 | ?SetSnowSurfaceAudioInfos@@YAXXZ
void SetSnowSurfaceAudioInfos();

// 0x6A7CE0 | ?SURFACEAUDIOINFO@@3PAUtagSurfaceAudioInfo@@A
inline extern_var(0x6A7CE0, struct tagSurfaceAudioInfo[6], SURFACEAUDIOINFO);
