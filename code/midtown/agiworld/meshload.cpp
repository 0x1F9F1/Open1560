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

define_dummy_symbol(agiworld_meshload);

#include "meshload.h"

#include "agi/texdef.h"
#include "getmesh.h"
#include "memory/alloca.h"
#include "meshset.h"
#include "stream/stream.h"
#include "texsheet.h"
#include "texsort.h"
#include "vector7/vector2.h"
#include "vector7/vector3.h"
#include "vector7/vector4.h"

void agiMeshSet::BinaryLoad(Stream* stream)
{
    stream->Read(&VertexCount, sizeof(VertexCount));
    stream->Read(&AdjunctCount, sizeof(AdjunctCount));
    stream->Read(&SurfaceCount, sizeof(SurfaceCount));
    stream->Read(&IndicesCount, sizeof(IndicesCount));
    stream->Read(&Magnitude, sizeof(Magnitude));
    stream->Read(&MagnitudeSqr, sizeof(MagnitudeSqr));
    stream->Read(&BoundingBoxMagnitude, sizeof(BoundingBoxMagnitude));
    stream->Read(&TextureCount, sizeof(TextureCount));
    stream->Read(&Flags, sizeof(Flags));

    u16 always_zero;
    stream->Read(&always_zero, sizeof(always_zero));

    u32 cache_size;
    stream->Read(&cache_size, sizeof(cache_size));

    agiTexParameters* textures = ARTS_ALLOCA(agiTexParameters, TextureCount + 1);

    for (u8 i = 1; i <= TextureCount; ++i)
        stream->Read(&textures[i], sizeof(textures[i]));

    VariationCount = 1;

    for (u8 i = 1; i <= TextureCount; ++i)
    {
        if (i32 variations = TEXSHEET.GetVariationCount(textures[i].Name); variations > VariationCount)
            VariationCount = static_cast<u8>(variations);
    }

    Textures = new agiTexDef**[VariationCount];

    for (u8 i = 0; i < VariationCount; ++i)
    {
        Textures[i] = new agiTexDef*[TextureCount + 2]; // FIXME: Should be + 1 (see below)
        Textures[i][0] = nullptr;                       // First texture is always empty
        Textures[i][1] = nullptr; // FIXME: Some code (mmShardManager::Init) assumes texture 1 is always valid

        for (u8 j = 1; j <= TextureCount; ++j)
        {
            if (textures[j].Name[0])
            {
                Textures[i][j] = GetPackedTexture(textures[j].Name, i);

                if (!Textures[i][j])
                    Errorf("MESH %s: Texture '%s' not found.", MeshCurrentObject, textures[j].Name);
            }
            else
            {
                Textures[i][j] = nullptr;
            }
        }
    }

    Vertices = stream->ReadMapped<Vector3>(VertexCount);

    if (VertexCount >= 16)
        BoundingBox = stream->ReadMapped<Vector3>(8);

    if (Flags & AGI_MESH_SET_LIT)
        Normals = stream->ReadMapped<u8>(AdjunctCount);

    if (Flags & AGI_MESH_SET_DYNTEX)
        TexCoords = stream->ReadMapped<Vector2>(AdjunctCount);

    if (Flags & AGI_MESH_SET_CPV)
        Colors = stream->ReadMapped<u32>(AdjunctCount);

    VertexIndices = stream->ReadMapped<u16>(AdjunctCount);

    if (Flags & AGI_MESH_SET_PLANES)
        Planes = stream->ReadMapped<Vector4>(SurfaceCount);

    TextureIndices = stream->ReadMapped<u8>(SurfaceCount);
    SurfaceIndices = stream->ReadMapped<u16>(IndicesCount);
}
