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

class mmGameRecord
{
public:
    // ??0mmGameRecord@@QAE@M@Z
    ARTS_IMPORT mmGameRecord(f32 arg1);

    // ??1mmGameRecord@@QAE@XZ
    ARTS_IMPORT ~mmGameRecord();

    // ?DoScan@mmGameRecord@@QAEXAAVVector4@@@Z
    ARTS_IMPORT void DoScan(Vector4& arg1);

    // ?Dump@mmGameRecord@@QAEXPAD@Z
    ARTS_IMPORT void Dump(char* arg1);

    // ?Init@mmGameRecord@@QAEXH@Z
    ARTS_IMPORT void Init(i32 arg1);

    // ?Register@mmGameRecord@@QAEHAAVVector4@@MMMMMMMM@Z
    ARTS_IMPORT i32 Register(
        Vector4& arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);

    // ?Sim@mmGameRecord@@QAEXXZ
    ARTS_IMPORT void Sim();

    u8 gap0[0x20];
};

check_size(mmGameRecord, 0x20);
