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

struct agiRgba;

class agiPalette
{
public:
    // ??0agiPalette@@QAE@XZ
    ARTS_IMPORT agiPalette();

    // ?FindColor@agiPalette@@QAEIUagiRgba@@@Z
    ARTS_IMPORT u32 FindColor(agiRgba arg1);

    // ?GetColor@agiPalette@@QAEIUagiRgba@@@Z
    ARTS_IMPORT u32 GetColor(agiRgba arg1);

    // ?Kill@agiPalette@@QAEXXZ
    ARTS_IMPORT void Kill();

    u32 Colors[256] {};
    i32 field_400 {}; // StartIndex ?
    i32 field_404 {}; // EndIndex ?
    i32 ColorCount {};
    i32 ChangeCount {};
};

check_size(agiPalette, 0x410);

// ?agiPal@@3VagiPalette@@A
ARTS_IMPORT extern agiPalette agiPal;
