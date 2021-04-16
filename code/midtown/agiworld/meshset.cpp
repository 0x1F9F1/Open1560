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

define_dummy_symbol(agiworld_meshset);

#include "meshset.h"

#include "agi/texdef.h"
#include "data7/ipc.h"
#include "vector7/geomath.h"
#include "vector7/vector3.h"
#include "vector7/vector4.h"

agiMeshSet::agiMeshSet() = default;

agiMeshSet::~agiMeshSet()
{
    EndGfx();

    if (Textures)
    {
        for (i32 i = 0; i < VariationCount; ++i)
        {
            for (i32 j = 1; j < TextureCount; ++j)
            {
                if (agiTexDef* texture = Textures[i][j])
                    texture->Release();
            }

            delete[] Textures[i];
        }

        delete[] Textures;
    }

    // TODO: Should this free the other fields?
}

void agiMeshSet::ComputePlaneEquations()
{
    if (Planes)
        delete[] Planes;

    Planes = new Vector4[SurfaceCount];

    for (i32 i = 0; i < SurfaceCount; ++i)
    {
        u16* indices = &SurfaceIndices[i * 4];

        Planes[i].CalculatePlane(Vertices[VertexIndices[indices[0]]], Vertices[VertexIndices[indices[1]]],
            Vertices[VertexIndices[indices[2]]]);
    }

    if (VertexCount >= 16)
    {
        if (!BoundingBox)
            BoundingBox = new Vector3[8];

        Vector3 min;
        Vector3 max;
        GetBoundInfo(VertexCount, Vertices, &min, &max, nullptr, nullptr);

        BoundingBox[0] = Vector3(min.x, min.y, min.z);
        BoundingBox[1] = Vector3(max.x, min.y, min.z);
        BoundingBox[2] = Vector3(max.x, min.y, max.z);
        BoundingBox[3] = Vector3(min.x, min.y, max.z);
        BoundingBox[4] = Vector3(min.x, max.y, min.z);
        BoundingBox[5] = Vector3(max.x, max.y, min.z);
        BoundingBox[6] = Vector3(max.x, max.y, max.z);
        BoundingBox[7] = Vector3(min.x, max.y, max.z);
    }

    f32 mag_sqr = 0.0f;

    for (i32 i = 0; i < VertexCount; ++i)
        mag_sqr = std::max(mag_sqr, Vertices[i].Mag2());

    MagnitudeSqr = mag_sqr;
    Magnitude = std::sqrt(mag_sqr);

    GetBoundInfo(VertexCount, Vertices, nullptr, nullptr, nullptr, &BoundingBoxMagnitude);
}

void agiMeshSet::PageIn()
{
    if (!Resident)
    {
        ++Resident;
        PAGER.Send(PageInCallback, this);
    }
}

void agiMeshSet::PageInCallback(void* param)
{
    static_cast<agiMeshSet*>(param)->DoPageIn();
}