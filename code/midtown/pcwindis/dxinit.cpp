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

define_dummy_symbol(pcwindis_dxinit);

#include "dxinit.h"

i32 dxiChangeDisplaySettings(i32 /*width*/, i32 /*height*/, i32 /*bpp*/)
{
    export_hook(0x573C60);

    return 0;
}

void dxiDirectDrawCreate()
{
    return stub<cdecl_t<void>>(0x573CC0);
}

void dxiDirectDrawSurfaceCreate()
{
    return stub<cdecl_t<void>>(0x573EC0);
}

void dxiDirectDrawSurfaceDestroy()
{
    return stub<cdecl_t<void>>(0x574190);
}

void dxiDirectInputCreate()
{
    return stub<cdecl_t<void>>(0x574200);
}

void dxiInit(char* arg1, i32 arg2, char** arg3)
{
    return stub<cdecl_t<void, char*, i32, char**>>(0x574550, arg1, arg2, arg3);
}

void* dxiMemoryAllocate(struct IDirectDrawSurface4** arg1, u32 arg2)
{
    return stub<cdecl_t<void*, struct IDirectDrawSurface4**, u32>>(0x5742C0, arg1, arg2);
}

void dxiMemoryFree(struct IDirectDrawSurface4* arg1)
{
    return stub<cdecl_t<void, struct IDirectDrawSurface4*>>(0x5744E0, arg1);
}

void dxiScreenShot(char* arg1)
{
    return stub<cdecl_t<void, char*>>(0x574690, arg1);
}

void dxiSetDisplayMode()
{
    return stub<cdecl_t<void>>(0x573D80);
}

void dxiShutdown()
{
    return stub<cdecl_t<void>>(0x574240);
}

void dxiWindowCreate(char* arg1)
{
    return stub<cdecl_t<void, char*>>(0x573B80, arg1);
}
