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

#pragma once

#include "agi/vertex.h"

class agiPolySet;
class agiTexDef;

class agiTexSorter
{
public:
    // ??0agiTexSorter@@QAE@XZ
    ARTS_EXPORT agiTexSorter();

    // ??1agiTexSorter@@QAE@XZ
    ARTS_EXPORT ~agiTexSorter();

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@agiTexSorter@@QAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* bank);
#endif

    // ?Cull@agiTexSorter@@QAEXH@Z
    ARTS_EXPORT void Cull(b32 alpha);

    // ?BeginVerts@agiTexSorter@@SAPAVagiPolySet@@PAVagiTexDef@@HH@Z
    ARTS_EXPORT static agiPolySet* BeginVerts(agiTexDef* texture, i32 vert_count, i32 index_count);

    // ?BeginVerts2@agiTexSorter@@SAPAVagiPolySet@@PAVagiTexDef@@0HH@Z
    ARTS_IMPORT static agiPolySet* BeginVerts2(
        agiTexDef* texture1, agiTexDef* texture2, i32 vert_count, i32 index_count);

    // ?DoTexture@agiTexSorter@@SAXPAVagiPolySet@@@Z
    ARTS_IMPORT static void DoTexture(agiPolySet* arg1);

    // ?EndVerts@agiTexSorter@@SAXXZ
    ARTS_EXPORT static void EndVerts();

    // ?EndVerts2@agiTexSorter@@SAXXZ
    ARTS_IMPORT static void EndVerts2();

    // ?GetEnv@agiTexSorter@@SAPAVagiPolySet@@PAVagiTexDef@@HH@Z
    ARTS_EXPORT static agiPolySet* GetEnv(agiTexDef* texture, i32 vert_count, i32 index_count);

    // ?AlphaPolySets@agiTexSorter@@2PAPAVagiPolySet@@A
    ARTS_EXPORT static agiPolySet* AlphaPolySets[32];

    // ?AlphaSetCount@agiTexSorter@@2HA
    ARTS_IMPORT static i32 AlphaSetCount;

    // ?BigPoolFlushes@agiTexSorter@@2HA
    ARTS_IMPORT static i32 BigPoolFlushes;

    // ?EnvPolySet@agiTexSorter@@2VagiPolySet@@A
    ARTS_IMPORT static agiPolySet EnvPolySet;

    // ?GeometryCalls@agiTexSorter@@2HA
    ARTS_IMPORT static i32 GeometryCalls;

    // ?InitialZMode@agiTexSorter@@2HA
    ARTS_IMPORT static i32 InitialZMode;

    // ?MaxAlphaSetCount@agiTexSorter@@2HA
    ARTS_IMPORT static i32 MaxAlphaSetCount;

    // ?MaxIndicesPerSet@agiTexSorter@@2HA
    ARTS_IMPORT static i32 MaxIndicesPerSet;

    // ?MaxOpaqueSetCount@agiTexSorter@@2HA
    ARTS_IMPORT static i32 MaxOpaqueSetCount;

    // ?MaxVertsPerSet@agiTexSorter@@2HA
    ARTS_IMPORT static i32 MaxVertsPerSet;

    // ?OpaquePolySets@agiTexSorter@@2PAPAVagiPolySet@@A
    ARTS_EXPORT static agiPolySet* OpaquePolySets[128];

    // ?OpaqueSetCount@agiTexSorter@@2HA
    ARTS_IMPORT static i32 OpaqueSetCount;

    // ?OutOfPoolFlushes@agiTexSorter@@2HA
    ARTS_IMPORT static i32 OutOfPoolFlushes;

    // ?OverflowFlushes@agiTexSorter@@2HA
    ARTS_IMPORT static i32 OverflowFlushes;

    // ?TotalTris@agiTexSorter@@2HA
    ARTS_IMPORT static i32 TotalTris;

private:
    friend agiTexSorter* TexSorter();

    // ?Instance@agiTexSorter@@0PAV1@A
    ARTS_IMPORT static agiTexSorter* Instance;
};

check_size(agiTexSorter, 0x1);

inline agiTexSorter* TexSorter()
{
    return agiTexSorter::Instance;
}

// ?GetPackedTexture@@YAPAVagiTexDef@@PADH@Z
ARTS_EXPORT RcOwner<agiTexDef> GetPackedTexture(aconst char* name, i32 variation);

// ?DisableFogOnAlphaGlow@@3HA
ARTS_IMPORT extern i32 DisableFogOnAlphaGlow;

// ?EnableTexSorting@@3HA
ARTS_IMPORT extern i32 EnableTexSorting;

// ?EnvMapFlushes@@3HA
ARTS_IMPORT extern i32 EnvMapFlushes;

// ?TextureSuffix@@3PADA
ARTS_IMPORT extern aconst char* TextureSuffix;

class agiPolySet
{
public:
    constexpr agiPolySet() = default;

    agiPolySet(i32 verts, i32 indices);
    ~agiPolySet();

    // ?Triangle@agiPolySet@@QAEXHHH@Z | inline
    ARTS_EXPORT void Triangle(i32 i1, i32 i2, i32 i3)
    {
        if (IndexCount + 3 > MaxIndices)
            Quitf("Index pool overrun.");

        Indices[IndexCount] = static_cast<u16>(BaseIndex + i1);
        Indices[IndexCount + 1] = static_cast<u16>(BaseIndex + i2);
        Indices[IndexCount + 2] = static_cast<u16>(BaseIndex + i3);

        IndexCount += 3;

        ++TriCount;
    }

    void Quad(i32 i1, i32 i2, i32 i3, i32 i4)
    {
        // 2-1
        // | |
        // 3-4

        Triangle(i1, i2, i3);
        Triangle(i1, i3, i4);
    }

    agiScreenVtx& Vert()
    {
        ArAssert(!MultiTex, "PolySet is MultiTex");

        if (VertCount == MaxVerts)
            Quitf("Vertex pool overrun.");

        return Verts[VertCount++];
    }

    agiScreenVtx2& Vert2()
    {
        ArAssert(MultiTex, "PolySet is not MultiTex");

        if (VertCount == MaxVerts)
            Quitf("Vertex pool overrun.");

        return Verts2[VertCount++];
    }

    void Init(i32 verts, i32 indices);
    void Kill();

    u16* Indices {};
    agiScreenVtx* Verts {};
    agiScreenVtx2* Verts2 {};
    agiTexDef* Textures[2] {};
    i32 VertCount {};
    i32 IndexCount {};
    i32 BaseIndex {};
    i32 MaxVerts {};
    i32 MaxIndices {};
    i32 MultiTex {};

    // ?TriCount@agiPolySet@@2HA
    ARTS_IMPORT static i32 TriCount;
};

check_size(agiPolySet, 0x2C);
