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
    agi:print

    0x557E70 | void __cdecl agiPrint(int,int,int,char const *) | ?agiPrint@@YAXHHHPBD@Z
    0x557E90 | void __cdecl agiPrintf(int,int,int,char const *,...) | ?agiPrintf@@YAXHHHPBDZZ
    0x557EF0 | int __cdecl agiPrintIs3D(void) | ?agiPrintIs3D@@YAHXZ
    0x557F00 | void __cdecl agiPrintInit(void) | ?agiPrintInit@@YAXXZ
    0x557F10 | void __cdecl agiPrintShutdown(void) | ?agiPrintShutdown@@YAXXZ
    0x557F20 | public: virtual void __thiscall agiPipeline::Print(int,int,int,char const *) | ?Print@agiPipeline@@UAEXHHHPBD@Z
    0x557FE0 | void __cdecl InitBuiltin(void) | ?InitBuiltin@@YAXXZ
    0x558110 | public: virtual int __thiscall agiPipeline::PrintIs3D(void) | ?PrintIs3D@agiPipeline@@UAEHXZ
    0x558130 | public: virtual void __thiscall agiPipeline::PrintInit(void) | ?PrintInit@agiPipeline@@UAEXXZ
    0x558140 | public: virtual void __thiscall agiPipeline::PrintShutdown(void) | ?PrintShutdown@agiPipeline@@UAEXXZ
    0x656C30 | unsigned char * CharSet | ?CharSet@@3PAEA
*/

// TODO: Allow larger sizes
constexpr i32 agiPrintSize = 8;

// 0x557E70 | ?agiPrint@@YAXHHHPBD@Z
ARTS_EXPORT void agiPrint(i32 x, i32 y, i32 color, char const* text);

// 0x557F00 | ?agiPrintInit@@YAXXZ
ARTS_EXPORT void agiPrintInit();

// 0x557EF0 | ?agiPrintIs3D@@YAHXZ
ARTS_EXPORT i32 agiPrintIs3D();

// 0x557F10 | ?agiPrintShutdown@@YAXXZ
ARTS_EXPORT void agiPrintShutdown();

// 0x557E90 | ?agiPrintf@@YAXHHHPBDZZ
ARTS_EXPORT void agiPrintf(i32 x, i32 y, i32 color, char const* format, ...);

// 0x656C30 | ?CharSet@@3PAEA
ARTS_IMPORT extern u8 CharSet[768];
