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

define_dummy_symbol(mmdyna_bndtmpl);

#include "bndtmpl.h"

#include "vector7/geomath.h"

#include "bndtmpl2.h"
#include "poly.h"

void mmBoundTemplate::ComputeBounds()
{
    GetBoundInfo(NumVerts, Verts, &BBMin, &BBMax, &Center, &Radius);
    RadiusSqr = Radius * Radius;
}

void mmBoundTemplate::ComputeEdges()
{
    i32 total_verts = 0;

    for (i32 i = 0; i < NumPolys; ++i)
    {
        total_verts += Polygons[i].GetNumVerts();
    }

    i32* edge_1s = new i32[4 * total_verts];
    i32* edge_2s = new i32[4 * total_verts];

    i32 num_edges = 0;

    for (i32 j = 0; j < NumPolys; ++j)
    {
        mmPolygon& poly = Polygons[j + 1];

        i32 num_verts = poly.GetNumVerts();

        i32 v1 = poly.MtlIndex + num_verts; // ?
        // Original line: v1 = *((__int16 *)&this->Polygons[j + 1].MtlIndex + num_verts);

        for (i32 k = 0; k < num_verts; ++k)
        {
            i32 v2 = poly.VertIndices[k];

            if (!EdgeInList(v1, v2, num_edges, edge_1s, edge_2s))
            {
                edge_1s[num_edges] = v1;
                edge_2s[num_edges++] = v2;
            }

            v1 = v2;
        }
    }

    if (num_edges)
    {
        EdgeVerts1 = new u32[4 * num_edges];
        EdgeVerts2 = new u32[4 * num_edges];
        HotVerts = Verts;
        NumHotVerts2 = NumVerts;

        for (i32 m = 0; m < num_edges; ++m)
        {
            EdgeVerts1[m] = edge_1s[m];
            EdgeVerts2[m] = edge_2s[m];
        }

        NumEdges = num_edges;
    }

    delete[] edge_1s;
    delete[] edge_2s;
}

#ifdef ARTS_DEV_BUILD
void mmBoundTemplate::DrawGraph()
{}
#endif

i32 mmBoundTemplate::LineSphere(mmIntersection* /*arg1*/)
{
    return 0;
}

void mmBoundTemplate::PlotSpan(i32 /*arg1*/, i32 /*arg2*/, i32 /*arg3*/)
{}
