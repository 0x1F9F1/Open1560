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

define_dummy_symbol(agi_print);

#include "print.h"

#include "pipeline.h"

// 0x557FE0 | ?InitBuiltin@@YAXXZ
ARTS_IMPORT /*static*/ void InitBuiltin();

void agiPrint(i32 x, i32 y, i32 color, char const* text)
{
    agiPipeline::CurrentPipe->Print(x, y, color, text);
}

void agiPrintInit()
{
    agiPipeline::CurrentPipe->PrintInit();
}

i32 agiPrintIs3D()
{
    return agiPipeline::CurrentPipe->PrintIs3D();
}

void agiPrintShutdown()
{
    return agiPipeline::CurrentPipe->PrintShutdown();
}

void agiPrintf(i32 x, i32 y, i32 color, char const* format, ...)
{
    if (y >= 0 && y <= agiPipeline::CurrentPipe->Height - 8)
    {
        char buffer[256];

        std::va_list va;
        va_start(va, format);
        arts_vsprintf(buffer, format, va);
        va_end(va);

        agiPrintf(x, y, color, va);
    }
}
