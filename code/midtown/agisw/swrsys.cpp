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

define_dummy_symbol(agisw_swrsys);

#include "swrsys.h"

#include "agi/pipeline.h"
#include "swrend.h"

ARTS_IMPORT extern agiScreenVtx* swVtxBase;

i32 agiSWRasterizer::BeginGfx()
{
    return 0;
}

void agiSWRasterizer::BeginGroup()
{}

void agiSWRasterizer::EndGfx()
{}

void agiSWRasterizer::EndGroup()
{}

void agiSWRasterizer::Line(i32 i1, i32 i2)
{
    ++STATS.Lines;

    swLine(&swVtxBase[i1], &swVtxBase[i2]);
}

void agiSWRasterizer::Mesh([[maybe_unused]] agiVtxType type, agiVtx* vertices, [[maybe_unused]] i32 vertex_count,
    u16* indices, i32 index_count)
{
    while (index_count > 0)
    {
        // FIXME: Potentially reading out of bounds

        if (*indices == indices[3] && indices[2] == indices[4])
        {
            swQuad(&vertices[*indices].Screen, &vertices[indices[1]].Screen, &vertices[indices[2]].Screen,
                &vertices[indices[5]].Screen);
            index_count -= 6;
            indices += 6;
        }
        else
        {
            swTri(&vertices[*indices].Screen, &vertices[indices[1]].Screen, &vertices[indices[2]].Screen);
            index_count -= 3;
            indices += 3;
        }
    }
}

void agiSWRasterizer::Points(agiVtxType /*arg1*/, agiVtx* /*arg2*/, i32 /*arg3*/)
{}

void agiSWRasterizer::SetVertCount(i32 /*arg1*/)
{}
