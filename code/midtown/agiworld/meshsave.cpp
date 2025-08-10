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

define_dummy_symbol(agiworld_meshsave);

#include "meshsave.h"

#include "agi/texdef.h"
#include "meshset.h"
#include "stream/stream.h"
#include "vector7/vector2.h"
#include "vector7/vector3.h"
#include "vector7/vector4.h"

void agiMeshSet::BinarySave(Stream* stream)
{
    stream->Write(&VertexCount, sizeof(VertexCount));
    stream->Write(&AdjunctCount, sizeof(AdjunctCount));
    stream->Write(&SurfaceCount, sizeof(SurfaceCount));
    stream->Write(&IndicesCount, sizeof(IndicesCount));
    stream->Write(&Radius, sizeof(Radius));
    stream->Write(&RadiusSqr, sizeof(RadiusSqr));
    stream->Write(&BoundingBoxRadius, sizeof(BoundingBoxRadius));
    stream->Write(&TextureCount, sizeof(TextureCount));
    stream->Write(&Flags, sizeof(Flags));

    u16 padding = 0;
    stream->Write(&padding, sizeof(padding));

    u32 cache_size = GetBaseCacheSize();
    stream->Write(&cache_size, sizeof(cache_size));

    for (u8 i = 1; i <= TextureCount; ++i)
    {
        agiTexParameters params {};

        if (agiTexDef* texture = Textures[0][i])
            params = texture->Tex;

        stream->Write(&params, sizeof(params));
    }

    stream->Write(Vertices, VertexCount * sizeof(*Vertices));

    if (VertexCount >= 16)
        stream->Write(BoundingBox, 8 * sizeof(*BoundingBox));

    if (Flags & MESH_SET_NORMAL)
        stream->Write(Normals, AdjunctCount * sizeof(*Normals));

    if (Flags & MESH_SET_UV)
        stream->Write(TexCoords, AdjunctCount * sizeof(*TexCoords));

    if (Flags & MESH_SET_CPV)
        stream->Write(Colors, AdjunctCount * sizeof(*Colors));

    stream->Write(VertexIndices, AdjunctCount * sizeof(*VertexIndices));

    if (Flags & MESH_SET_PLANES)
        stream->Write(Planes, SurfaceCount * sizeof(*Planes));

    stream->Write(TextureIndices, SurfaceCount * sizeof(*TextureIndices));
    stream->Write(SurfaceIndices, IndicesCount * sizeof(*SurfaceIndices));
}
