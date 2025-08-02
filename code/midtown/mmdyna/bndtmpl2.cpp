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

define_dummy_symbol(mmdyna_bndtmpl2);

#include "bndtmpl2.h"

#include "bndtmpl.h"
#include "poly.h"

#include "data7/ipc.h"
#include "vector7/geomath.h"

void mmBoundTemplate::PageIn()
{
    if (PageState == 0)
    {
        ++PageState;

        PAGER.Send([this] { DoPageIn(); });
    }
}

void mmBoundTemplate::ComputeBounds()
{
    GetBoundInfo(NumVerts, Verts, &BBMin, &BBMax, &Center, &Radius);
    RadiusSqr = Radius * Radius;
}

bool EdgeInList(i32 v1, i32 v2, ilong count, i32* edges1, i32* edges2)
{
    for (i32 i = 0; i < count; ++i)
    {
        i32 edge1 = edges1[i];
        i32 edge2 = edges2[i];

        if ((v1 == edge1 && v2 == edge2) || (v1 == edge2 && v2 == edge1))
        {
            return true;
        }
    }

    return false;
}

void mmBoundTemplate::ComputeEdges()
{
    i32 total_verts = 0;

    for (i32 i = 0; i < NumPolys; ++i)
    {
        total_verts += Polygons[i].GetNumVerts();
    }

    auto edges1 = arnewa i32[total_verts];
    auto edges2 = arnewa i32[total_verts];
    i32 num_edges = 0;

    for (i32 i = 0; i < NumPolys; ++i)
    {
        const mmPolygon& poly = Polygons[i + 1];

        i32 num_verts = poly.GetNumVerts();
        i32 v1 = poly.VertIndices[num_verts - 1];

        for (i32 k = 0; k < num_verts; ++k)
        {
            i32 v2 = poly.VertIndices[k];

            if (!EdgeInList(v1, v2, num_edges, edges1.get(), edges2.get()))
            {
                edges1[num_edges] = v1;
                edges2[num_edges] = v2;
                ++num_edges;
            }

            v1 = v2;
        }
    }

    if (num_edges)
    {
        EdgeVerts1 = new u32[num_edges];
        EdgeVerts2 = new u32[num_edges];
        HotVerts = Verts;
        NumHotVerts2 = NumVerts;

        for (i32 i = 0; i < num_edges; ++i)
        {
            EdgeVerts1[i] = edges1[i];
            EdgeVerts2[i] = edges2[i];
        }

        NumEdges = num_edges;
    }
}

void mmBoundTemplate::PlotSpan(i32 /*arg1*/, i32 /*arg2*/, i32 /*arg3*/)
{}
