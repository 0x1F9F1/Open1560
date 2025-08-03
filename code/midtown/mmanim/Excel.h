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

class mmAnimExcel final
{
public:
    // ??0mmAnimExcel@@QAE@XZ
    ARTS_IMPORT mmAnimExcel();

    // ??1mmAnimExcel@@UAE@XZ
    ARTS_IMPORT virtual ~mmAnimExcel();

    // ?AddFile@mmAnimExcel@@QAEXPAD0@Z
    ARTS_IMPORT void AddFile(char* arg1, char* arg2);

    // ?GetName@mmAnimExcel@@QAEPADH@Z
    ARTS_IMPORT char* GetName(i32 arg1);

    // ?Init@mmAnimExcel@@QAEHPAD0@Z
    ARTS_IMPORT i32 Init(char* arg1, char* arg2);

    u8 gap4[0xC];
};

check_size(mmAnimExcel, 0x10);
