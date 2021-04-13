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
    data7:global

    0x5790A0 | void __cdecl HexDump(void *,int) | ?HexDump@@YAXPAXH@Z
    0x6622CC | int DevelopmentMode | ?DevelopmentMode@@3HA
*/

// 0x5790A0 | ?HexDump@@YAXPAXH@Z
ARTS_EXPORT void HexDump(const void* data, i32 length);

// 0x6622CC | ?DevelopmentMode@@3HA
ARTS_IMPORT extern b32 DevelopmentMode;
