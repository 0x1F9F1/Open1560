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
    pcwindis:setupdata

    0x5749B0 | int __cdecl dxiResClosestMatch(int,int,int) | ?dxiResClosestMatch@@YAHHHH@Z
    0x574A60 | int __cdecl dxiResGetRecommended(int,int) | ?dxiResGetRecommended@@YAHHH@Z
    0x574B00 | int __cdecl dxiReadConfigFile(void) | ?dxiReadConfigFile@@YAHXZ
    0x574E90 | void __cdecl dxiWriteConfigFile(void) | ?dxiWriteConfigFile@@YAXXZ
    0x661380 | int dxiRendererChoice | ?dxiRendererChoice@@3HA
    0x909680 | struct dxiRendererInfo_t * dxiInfo | ?dxiInfo@@3PAUdxiRendererInfo_t@@A
    0x90A350 | int dxiRendererCount | ?dxiRendererCount@@3HA
*/

// 0x574B00 | ?dxiReadConfigFile@@YAHXZ
i32 dxiReadConfigFile();

// 0x5749B0 | ?dxiResClosestMatch@@YAHHHH@Z
i32 dxiResClosestMatch(i32 arg1, i32 arg2, i32 arg3);

// 0x574A60 | ?dxiResGetRecommended@@YAHHH@Z
i32 dxiResGetRecommended(i32 arg1, i32 arg2);

// 0x574E90 | ?dxiWriteConfigFile@@YAXXZ
void dxiWriteConfigFile();

// 0x909680 | ?dxiInfo@@3PAUdxiRendererInfo_t@@A
inline extern_var(0x509680_Offset, struct dxiRendererInfo_t*, dxiInfo);

// 0x661380 | ?dxiRendererChoice@@3HA
inline extern_var(0x261380_Offset, i32, dxiRendererChoice);

// 0x90A350 | ?dxiRendererCount@@3HA
inline extern_var(0x50A350_Offset, i32, dxiRendererCount);
