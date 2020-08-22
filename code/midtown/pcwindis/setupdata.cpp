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

define_dummy_symbol(pcwindis_setupdata);

#include "setupdata.h"

// 0x575090 | ?guidtostr@@YAXPADPAU_GUID@@@Z
ARTS_IMPORT /*static*/ void guidtostr(char* arg1, struct _GUID* arg2);

// 0x574DF0 | ?strtoguid@@YAXPAU_GUID@@PAD@Z
ARTS_IMPORT /*static*/ void strtoguid(struct _GUID* arg1, char* arg2);

i32 dxiResGetRecommended(i32 renderer, [[maybe_unused]] i32 cpu_speed)
{
    dxiRendererInfo_t& info = dxiInfo[renderer];

    if (info.Type == 0)
        return dxiResClosestMatch(renderer, 640, 480);

    i32 best = 0;
    i32 largest = 0;

    for (i32 i = 0; i < info.ResCount; ++i)
    {
        dxiResolution& res = info.Resolutions[i];

        if (i32 size = res.uWidth * res.uHeight; size > largest)
        {
            best = i;
            largest = size;
        }
    }

    return best;
}
