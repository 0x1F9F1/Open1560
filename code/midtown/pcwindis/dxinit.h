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

#include "setupdata.h"

struct HWND__;
struct IDirectInputA;
class agiSurfaceDesc;

// ?dxiDirectInputCreate@@YAXXZ
ARTS_EXPORT void dxiDirectInputCreate();

// ?dxiInit@@YAXPADHPAPAD@Z
ARTS_EXPORT void dxiInit(char* title, i32 argc, char** argv);

// ?dxiScreenShot@@YAXPAD@Z
ARTS_EXPORT void dxiScreenShot(char* file_name);

// ?dxiShutdown@@YAXXZ
ARTS_EXPORT void dxiShutdown();

void dxiWindowCreate(const char* title, dxiRendererType type);

void dxiWindowDestroy();

// ?dxiDepth@@3HA
ARTS_IMPORT extern i32 dxiDepth;

#define DXI_FLAG_FULL_SCREEN 0x1
#define DXI_FLAG_SYSTEM_MEMORY 0x2
#define DXI_FLAG_DOUBLE_BUFFER 0x4
#define DXI_FLAG_TRIPLE_BUFFER 0x8

// ?dxiFlags@@3HA
ARTS_IMPORT extern i32 dxiFlags;

inline bool dxiIsFullScreen()
{
    return dxiFlags & DXI_FLAG_FULL_SCREEN;
}

inline bool dxiUseSystemMemory()
{
    return dxiFlags & DXI_FLAG_SYSTEM_MEMORY;
}

inline bool dxiDoubleBuffer()
{
    return dxiFlags & DXI_FLAG_DOUBLE_BUFFER;
}

inline bool dxiTripleBuffer()
{
    return dxiFlags & DXI_FLAG_TRIPLE_BUFFER;
}

// ?dxiHeight@@3HA
ARTS_IMPORT extern i32 dxiHeight;

// ?dxiIcon@@3HA
ARTS_IMPORT extern i32 dxiIcon;

// ?dxiWidth@@3HA
ARTS_IMPORT extern i32 dxiWidth;

// ?hwndMain@@3PAUHWND__@@A
ARTS_IMPORT extern HWND__* hwndMain;

// ?lpDI@@3PAUIDirectInputA@@A
ARTS_IMPORT extern IDirectInputA* lpDI;

typedef struct SDL_Window SDL_Window;

extern SDL_Window* g_MainWindow;