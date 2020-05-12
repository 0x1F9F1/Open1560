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

void agiSurfaceDesc::CopyFrom(class agiSurfaceDesc* arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSurfaceDesc*, class agiSurfaceDesc*, i32>>(0x55B180, this, arg1, arg2);
}

void agiSurfaceDesc::Reload(char* arg1, char* arg2, i32 arg3, i32 arg4, class Stream* arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, agiSurfaceDesc*, char*, char*, i32, i32, class Stream*, i32, i32>>(
        0x55ADE0, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void agiSurfaceDesc::Unload()
{
    return stub<thiscall_t<void, agiSurfaceDesc*>>(0x55B160, this);
}

class agiSurfaceDesc* agiSurfaceDesc::Init(i32 arg1, i32 arg2, class agiSurfaceDesc& arg3)
{
    return stub<cdecl_t<class agiSurfaceDesc*, i32, i32, class agiSurfaceDesc&>>(0x55A720, arg1, arg2, arg3);
}

class agiSurfaceDesc* agiSurfaceDesc::Load(char* arg1, char* arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6)
{
    return stub<cdecl_t<class agiSurfaceDesc*, char*, char*, i32, i32, i32, i32>>(
        0x55A7A0, arg1, arg2, arg3, arg4, arg5, arg6);
}

static void RescaleJpeg(u32 arg1, u32 arg2, u8* arg3, struct jpeg_decompress_struct& arg4)
{
    return stub<cdecl_t<void, u32, u32, u8*, struct jpeg_decompress_struct&>>(0x55AAE0, arg1, arg2, arg3, arg4);
}

static void copyrow4444_to_555(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B7E0, arg1, arg2, arg3, arg4);
}

static void copyrow4444_to_5551(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B8E0, arg1, arg2, arg3, arg4);
}

static void copyrow4444_to_565(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B860, arg1, arg2, arg3, arg4);
}

static void copyrow4444_to_8888(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B6C0, arg1, arg2, arg3, arg4);
}

static void copyrow4444_to_8888rev(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B750, arg1, arg2, arg3, arg4);
}

static void copyrow565_to_555(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B510, arg1, arg2, arg3, arg4);
}

static void copyrow565_to_5551(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B560, arg1, arg2, arg3, arg4);
}

static void copyrow565_to_888(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B5C0, arg1, arg2, arg3, arg4);
}

static void copyrow565_to_888rev(void* arg1, void* arg2, u32 arg3, u32 arg4)
{
    return stub<cdecl_t<void, void*, void*, u32, u32>>(0x55B640, arg1, arg2, arg3, arg4);
}
