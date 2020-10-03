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
    agisw:swddraw

    0x534E30 | void __cdecl ddAttach(int,int) | ?ddAttach@@YAXHH@Z
    0x534EA0 | void __cdecl ddStart(void) | ?ddStart@@YAXXZ
    0x534FA0 | void __cdecl ddEnd(void) | ?ddEnd@@YAXXZ
    0x534FC0 | void __cdecl ddStartFrame(void) | ?ddStartFrame@@YAXXZ
    0x534FD0 | void __cdecl ddStartScene(void) | ?ddStartScene@@YAXXZ
    0x535030 | void __cdecl ddEndScene(void) | ?ddEndScene@@YAXXZ
    0x535070 | void __cdecl ddEndFrame(void) | ?ddEndFrame@@YAXXZ
    0x795CB0 | class agiSurfaceDesc swScreenDesc | ?swScreenDesc@@3VagiSurfaceDesc@@A
    0x795D38 | unsigned char * swNibbleLut | ?swNibbleLut@@3PAEA
    0x795F40 | int bRenderToSystem | ?bRenderToSystem@@3HA
*/

// 0x534E30 | ?ddAttach@@YAXHH@Z
ARTS_EXPORT void ddAttach(i32 flags, i32 bit_depth);

// 0x795F40 | ?bRenderToSystem@@3HA
ARTS_IMPORT extern i32 bRenderToSystem;

// 0x795D38 | ?swNibbleLut@@3PAEA
ARTS_IMPORT extern u8 swNibbleLut[256];

// 0x795CB0 | ?swScreenDesc@@3VagiSurfaceDesc@@A
ARTS_IMPORT extern class agiSurfaceDesc swScreenDesc;
