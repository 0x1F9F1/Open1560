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

define_dummy_symbol(mmai_aiPath);

#include "aiPath.h"

#include "aiIntersection.h"

Vector3* aiPath::CenterVertice(i32 index)
{
    if (index >= 0 && index < VertexCount)
        return &CenterVerts[index];

    Warningf("Returning a NULL CenterVertice vector.");
    Warningf("Bad Idx: %d, Path Id: %d", index, Id);
    return 0;
}

void aiPath::Dump()
{
    Displayf("Path %d, Vertex Count = %d, Num Lanes = %d", Id, VertexCount, NumLanes);

    Displayf("\tOncoming Path = %d, Intersections = %d %d", OncomingPath->Id, Sink->Id, Source->Id);

    Displayf("\tBlocked = %d, PedBlocked = %d, HasBridge = %d", IsBlocked, IsPedBlocked, HasBridge);
    Displayf("\tDivided = %d, Flat       = %d, Alley     = %d", IsDivided, IsFlat, IsAlley);

    for (i32 i = 0; i < NumLanes; ++i)
    {
        Displayf("\tLane: %d", i);

        i32 vertex_per_lane = VertexCount;

        Vector3& start = LaneVertices[i * vertex_per_lane + 1];
        Vector3& end = LaneVertices[i * vertex_per_lane + VertexCount - 2];

        Displayf("\t\tStart = %.2f, %.2f, %.2f", start.x, start.y, start.z);
        Displayf("\t\tEnd   = %.2f, %.2f, %.2f", end.x, end.y, end.z);
    }
}

Vector3* aiPath::VertXDir(i32 index)
{
    if (index >= 0 && index < VertexCount)
        return &VertXDirs[index];

    Warningf("Returning a NULL VertXDir vector.");
    Warningf("Bad Idx: %d, Path Id: %d", index, Id);
    return 0;
}

Vector3* aiPath::VertZDir(i32 index)
{
    if (index >= 0 && index < VertexCount)
        return &VertZDirs[index];

    Warningf("Returning a NULL VertZDir vector.");
    Warningf("Bad Idx: %d, Path Id: %d", index, Id);
    return 0;
}