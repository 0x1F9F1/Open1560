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

define_dummy_symbol(data7_global);

#include "global.h"

void HexDump(const void* data, i32 length)
{
    const u8* data8 = static_cast<const u8*>(data);

    for (i32 index = 0; index < length; index += 16, data8 += 16)
    {
        i32 count = std::min(length - index, 16);

        std::printf("%08x: ", index);

        for (i32 i = 0; i < count; ++i)
            std::printf("%02x ", data8[i]);

        for (i32 i = count; i < 16; ++i)
            std::printf("   ");

        for (i32 i = 0; i < count; ++i)
        {
            u8 v = data8[i];

            if (v < 0x20 || v >= 0x7F)
                v = '.';

            std::printf("%c", v);
        }

        for (i32 i = count; i < 16; ++i)
            std::printf(" ");

        std::printf("\n");
    }
}
