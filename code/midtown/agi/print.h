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

extern i32 agiFontWidth;
extern i32 agiFontHeight;

// ?agiPrint@@YAXHHHPBD@Z
ARTS_EXPORT void agiPrint(i32 x, i32 y, i32 color, const char* text);

// ?agiPrintInit@@YAXXZ
void agiPrintInit();

// ?agiPrintIs3D@@YAHXZ
b32 agiPrintIs3D();

// ?agiPrintShutdown@@YAXXZ
void agiPrintShutdown();

// ?agiPrintf@@YAXHHHPBDZZ
void agiPrintf(i32 x, i32 y, i32 color, ARTS_FORMAT_STRING const char* format, ...);

// ?CharSet@@3PAEA
extern const u8 CharSet[768];
