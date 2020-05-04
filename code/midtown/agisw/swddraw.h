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
    0x795CB0 | class agiSurfaceDesc swScreenDesc | ?swScreenDesc@@3VagiSurfaceDesc@@A
    0x795D38 | unsigned char * swNibbleLut | ?swNibbleLut@@3PAEA
    0x795F40 | int bRenderToSystem | ?bRenderToSystem@@3HA
*/

// 0x534E30 | ?ddAttach@@YAXHH@Z
void ddAttach(i32 arg1, i32 arg2);

// 0x795F40 | ?bRenderToSystem@@3HA
inline extern_var(0x395F40_Offset, i32, bRenderToSystem);

// 0x795D38 | ?swNibbleLut@@3PAEA
inline extern_var(0x395D38_Offset, u8*, swNibbleLut);

// 0x795CB0 | ?swScreenDesc@@3VagiSurfaceDesc@@A
inline extern_var(0x395CB0_Offset, class agiSurfaceDesc, swScreenDesc);
