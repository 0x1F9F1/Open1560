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
    pcwindis:dxinit

    0x573B80 | void __cdecl dxiWindowCreate(char *) | ?dxiWindowCreate@@YAXPAD@Z
    0x573C60 | int __cdecl dxiChangeDisplaySettings(int,int,int) | ?dxiChangeDisplaySettings@@YAHHHH@Z
    0x573CC0 | void __cdecl dxiDirectDrawCreate(void) | ?dxiDirectDrawCreate@@YAXXZ
    0x573D80 | void __cdecl dxiSetDisplayMode(void) | ?dxiSetDisplayMode@@YAXXZ
    0x573EC0 | void __cdecl dxiDirectDrawSurfaceCreate(void) | ?dxiDirectDrawSurfaceCreate@@YAXXZ
    0x574190 | void __cdecl dxiDirectDrawSurfaceDestroy(void) | ?dxiDirectDrawSurfaceDestroy@@YAXXZ
    0x574200 | void __cdecl dxiDirectInputCreate(void) | ?dxiDirectInputCreate@@YAXXZ
    0x574240 | void __cdecl dxiShutdown(void) | ?dxiShutdown@@YAXXZ
    0x5742C0 | void * __cdecl dxiMemoryAllocate(struct IDirectDrawSurface4 * *,unsigned int) | ?dxiMemoryAllocate@@YAPAXPAPAUIDirectDrawSurface4@@I@Z
    0x5744E0 | void __cdecl dxiMemoryFree(struct IDirectDrawSurface4 *) | ?dxiMemoryFree@@YAXPAUIDirectDrawSurface4@@@Z
    0x574550 | void __cdecl dxiInit(char *,int,char * *) | ?dxiInit@@YAXPADHPAPAD@Z
    0x574690 | void __cdecl dxiScreenShot(char *) | ?dxiScreenShot@@YAXPAD@Z
    0x5748D0 | void __cdecl translate565(unsigned char *,unsigned short *,unsigned int) | ?translate565@@YAXPAEPAGI@Z
    0x574940 | void __cdecl translate555(unsigned char *,unsigned short *,unsigned int) | ?translate555@@YAXPAEPAGI@Z
    0x660F10 | int dxiWidth | ?dxiWidth@@3HA
    0x660F14 | int dxiHeight | ?dxiHeight@@3HA
    0x660F18 | int dxiDepth | ?dxiDepth@@3HA
    0x660F1C | int dxiFlags | ?dxiFlags@@3HA
    0x909650 | int dxiIcon | ?dxiIcon@@3HA
    0x909658 | struct IDirectDrawSurface4 * lpdsBack2 | ?lpdsBack2@@3PAUIDirectDrawSurface4@@A
    0x90965C | struct IDirectInputA * lpDI | ?lpDI@@3PAUIDirectInputA@@A
    0x909660 | struct IDirectDraw4 * lpDD4 | ?lpDD4@@3PAUIDirectDraw4@@A
    0x909664 | struct IDirectDrawSurface4 * lpdsFront | ?lpdsFront@@3PAUIDirectDrawSurface4@@A
    0x909668 | struct HWND__ * hwndMain | ?hwndMain@@3PAUHWND__@@A
    0x909670 | struct IDirectDrawSurface4 * lpdsBack | ?lpdsBack@@3PAUIDirectDrawSurface4@@A
    0x909674 | struct IDirectDrawClipper * lpClip | ?lpClip@@3PAUIDirectDrawClipper@@A
    0x909678 | struct IDirectDrawSurface4 * lpdsRend | ?lpdsRend@@3PAUIDirectDrawSurface4@@A
*/

#include "setupdata.h"

// ?dxiChangeDisplaySettings@@YAHHHH@Z
ARTS_EXPORT i32 dxiChangeDisplaySettings(i32 width, i32 height, i32 bpp);

// ?dxiDirectDrawCreate@@YAXXZ
ARTS_EXPORT void dxiDirectDrawCreate();

// ?dxiDirectDrawSurfaceCreate@@YAXXZ
ARTS_IMPORT void dxiDirectDrawSurfaceCreate();

// ?dxiDirectDrawSurfaceDestroy@@YAXXZ
ARTS_EXPORT void dxiDirectDrawSurfaceDestroy();

// ?dxiDirectInputCreate@@YAXXZ
ARTS_EXPORT void dxiDirectInputCreate();

// ?dxiInit@@YAXPADHPAPAD@Z
ARTS_EXPORT void dxiInit(char* title, i32 argc, char** argv);

// ?dxiMemoryAllocate@@YAPAXPAPAUIDirectDrawSurface4@@I@Z | unused
ARTS_IMPORT void* dxiMemoryAllocate(struct IDirectDrawSurface4** arg1, u32 arg2);

// ?dxiMemoryFree@@YAXPAUIDirectDrawSurface4@@@Z | unused
ARTS_IMPORT void dxiMemoryFree(struct IDirectDrawSurface4* arg1);

// ?dxiScreenShot@@YAXPAD@Z
ARTS_EXPORT void dxiScreenShot(char* file_name);

// ?dxiSetDisplayMode@@YAXXZ
ARTS_EXPORT void dxiSetDisplayMode();

// ?dxiShutdown@@YAXXZ
ARTS_EXPORT void dxiShutdown();

// ?dxiWindowCreate@@YAXPAD@Z
// This should only be in LockScreen
ARTS_EXPORT void dxiWindowCreate(const char* title);

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
ARTS_IMPORT extern struct HWND__* hwndMain;

// ?lpClip@@3PAUIDirectDrawClipper@@A
ARTS_IMPORT extern struct IDirectDrawClipper* lpClip;

// ?lpDD4@@3PAUIDirectDraw4@@A
ARTS_IMPORT extern struct IDirectDraw4* lpDD4;

// ?lpDI@@3PAUIDirectInputA@@A
ARTS_IMPORT extern struct IDirectInputA* lpDI;

// ?lpdsBack@@3PAUIDirectDrawSurface4@@A
ARTS_IMPORT extern struct IDirectDrawSurface4* lpdsBack;

// ?lpdsBack2@@3PAUIDirectDrawSurface4@@A
ARTS_IMPORT extern struct IDirectDrawSurface4* lpdsBack2;

// ?lpdsFront@@3PAUIDirectDrawSurface4@@A
ARTS_IMPORT extern struct IDirectDrawSurface4* lpdsFront;

// ?lpdsRend@@3PAUIDirectDrawSurface4@@A
ARTS_IMPORT extern struct IDirectDrawSurface4* lpdsRend;

typedef struct SDL_Window SDL_Window;

extern SDL_Window* g_MainWindow;
