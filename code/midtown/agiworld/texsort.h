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

/*
    agiworld:texsort

    0x503830 | public: __thiscall agiTexSorter::agiTexSorter(void) | ??0agiTexSorter@@QAE@XZ
    0x503A50 | public: __thiscall agiTexSorter::~agiTexSorter(void) | ??1agiTexSorter@@QAE@XZ
    0x503A60 | public: static class agiPolySet * __cdecl agiTexSorter::GetEnv(class agiTexDef *,int,int) | ?GetEnv@agiTexSorter@@SAPAVagiPolySet@@PAVagiTexDef@@HH@Z
    0x503B20 | public: static class agiPolySet * __cdecl agiTexSorter::BeginVerts(class agiTexDef *,int,int) | ?BeginVerts@agiTexSorter@@SAPAVagiPolySet@@PAVagiTexDef@@HH@Z
    0x503D70 | public: static class agiPolySet * __cdecl agiTexSorter::BeginVerts2(class agiTexDef *,class agiTexDef *,int,int) | ?BeginVerts2@agiTexSorter@@SAPAVagiPolySet@@PAVagiTexDef@@0HH@Z
    0x503FF0 | public: static void __cdecl agiTexSorter::EndVerts(void) | ?EndVerts@agiTexSorter@@SAXXZ
    0x504040 | public: static void __cdecl agiTexSorter::EndVerts2(void) | ?EndVerts2@agiTexSorter@@SAXXZ
    0x504090 | public: void __thiscall agiTexSorter::Cull(int) | ?Cull@agiTexSorter@@QAEXH@Z
    0x504150 | public: static void __cdecl agiTexSorter::DoTexture(class agiPolySet *) | ?DoTexture@agiTexSorter@@SAXPAVagiPolySet@@@Z
    0x5043E0 | class agiTexDef * __cdecl GetPackedTexture(char *,int) | ?GetPackedTexture@@YAPAVagiTexDef@@PADH@Z
    0x504620 | public: void __thiscall agiTexSorter::AddWidgets(class Bank *) | ?AddWidgets@agiTexSorter@@QAEXPAVBank@@@Z
    0x64A3E0 | public: static int agiTexSorter::MaxOpaqueSetCount | ?MaxOpaqueSetCount@agiTexSorter@@2HA
    0x64A3E4 | public: static int agiTexSorter::MaxAlphaSetCount | ?MaxAlphaSetCount@agiTexSorter@@2HA
    0x64A3E8 | public: static int agiTexSorter::MaxVertsPerSet | ?MaxVertsPerSet@agiTexSorter@@2HA
    0x64A3EC | public: static int agiTexSorter::MaxIndicesPerSet | ?MaxIndicesPerSet@agiTexSorter@@2HA
    0x64A3F0 | int EnableTexSorting | ?EnableTexSorting@@3HA
    0x64A3F4 | public: static int agiTexSorter::InitialZMode | ?InitialZMode@agiTexSorter@@2HA
    0x719620 | public: static int agiTexSorter::GeometryCalls | ?GeometryCalls@agiTexSorter@@2HA
    0x719624 | private: static class agiTexSorter * agiTexSorter::Instance | ?Instance@agiTexSorter@@0PAV1@A
    0x719628 | char * TextureSuffix | ?TextureSuffix@@3PADA
    0x71962C | int EnvMapFlushes | ?EnvMapFlushes@@3HA
    0x719630 | public: static class agiPolySet * * agiTexSorter::OpaquePolySets | ?OpaquePolySets@agiTexSorter@@2PAPAVagiPolySet@@A
    0x719730 | public: static int agiTexSorter::OutOfPoolFlushes | ?OutOfPoolFlushes@agiTexSorter@@2HA
    0x719734 | public: static int agiTexSorter::BigPoolFlushes | ?BigPoolFlushes@agiTexSorter@@2HA
    0x719738 | public: static int agiPolySet::TriCount | ?TriCount@agiPolySet@@2HA
    0x71973C | public: static int agiTexSorter::OverflowFlushes | ?OverflowFlushes@agiTexSorter@@2HA
    0x719744 | public: static int agiTexSorter::OpaqueSetCount | ?OpaqueSetCount@agiTexSorter@@2HA
    0x719750 | public: static class agiPolySet agiTexSorter::EnvPolySet | ?EnvPolySet@agiTexSorter@@2VagiPolySet@@A
    0x71977C | public: static int agiTexSorter::TotalTris | ?TotalTris@agiTexSorter@@2HA
    0x719780 | public: static int agiTexSorter::AlphaSetCount | ?AlphaSetCount@agiTexSorter@@2HA
    0x719788 | public: static class agiPolySet * * agiTexSorter::AlphaPolySets | ?AlphaPolySets@agiTexSorter@@2PAPAVagiPolySet@@A
    0x719838 | int DisableFogOnAlphaGlow | ?DisableFogOnAlphaGlow@@3HA
*/

#include "agi/vertex.h"

class agiTexDef;

class agiTexSorter
{
public:
    // 0x503830 | ??0agiTexSorter@@QAE@XZ
    ARTS_EXPORT agiTexSorter();

    // 0x503A50 | ??1agiTexSorter@@QAE@XZ
    ARTS_EXPORT ~agiTexSorter();

    // 0x504620 | ?AddWidgets@agiTexSorter@@QAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(class Bank* bank);

    // 0x504090 | ?Cull@agiTexSorter@@QAEXH@Z
    ARTS_EXPORT void Cull(b32 alpha);

    // 0x503B20 | ?BeginVerts@agiTexSorter@@SAPAVagiPolySet@@PAVagiTexDef@@HH@Z
    ARTS_EXPORT static class agiPolySet* BeginVerts(class agiTexDef* texture, i32 vert_count, i32 index_count);

    // 0x503D70 | ?BeginVerts2@agiTexSorter@@SAPAVagiPolySet@@PAVagiTexDef@@0HH@Z
    ARTS_IMPORT static class agiPolySet* BeginVerts2(
        class agiTexDef* texture1, class agiTexDef* texture2, i32 vert_count, i32 index_count);

    // 0x504150 | ?DoTexture@agiTexSorter@@SAXPAVagiPolySet@@@Z
    ARTS_IMPORT static void DoTexture(class agiPolySet* arg1);

    // 0x503FF0 | ?EndVerts@agiTexSorter@@SAXXZ
    ARTS_EXPORT static void EndVerts();

    // 0x504040 | ?EndVerts2@agiTexSorter@@SAXXZ
    ARTS_IMPORT static void EndVerts2();

    // 0x503A60 | ?GetEnv@agiTexSorter@@SAPAVagiPolySet@@PAVagiTexDef@@HH@Z
    ARTS_EXPORT static class agiPolySet* GetEnv(class agiTexDef* texture, i32 vert_count, i32 index_count);

    // 0x719788 | ?AlphaPolySets@agiTexSorter@@2PAPAVagiPolySet@@A
    ARTS_EXPORT static class agiPolySet* AlphaPolySets[32];

    // 0x719780 | ?AlphaSetCount@agiTexSorter@@2HA
    ARTS_IMPORT static i32 AlphaSetCount;

    // 0x719734 | ?BigPoolFlushes@agiTexSorter@@2HA
    ARTS_IMPORT static i32 BigPoolFlushes;

    // 0x719750 | ?EnvPolySet@agiTexSorter@@2VagiPolySet@@A
    ARTS_IMPORT static class agiPolySet EnvPolySet;

    // 0x719620 | ?GeometryCalls@agiTexSorter@@2HA
    ARTS_IMPORT static i32 GeometryCalls;

    // 0x64A3F4 | ?InitialZMode@agiTexSorter@@2HA
    ARTS_IMPORT static i32 InitialZMode;

    // 0x64A3E4 | ?MaxAlphaSetCount@agiTexSorter@@2HA
    ARTS_IMPORT static i32 MaxAlphaSetCount;

    // 0x64A3EC | ?MaxIndicesPerSet@agiTexSorter@@2HA
    ARTS_IMPORT static i32 MaxIndicesPerSet;

    // 0x64A3E0 | ?MaxOpaqueSetCount@agiTexSorter@@2HA
    ARTS_IMPORT static i32 MaxOpaqueSetCount;

    // 0x64A3E8 | ?MaxVertsPerSet@agiTexSorter@@2HA
    ARTS_IMPORT static i32 MaxVertsPerSet;

    // 0x719630 | ?OpaquePolySets@agiTexSorter@@2PAPAVagiPolySet@@A
    ARTS_EXPORT static class agiPolySet* OpaquePolySets[128];

    // 0x719744 | ?OpaqueSetCount@agiTexSorter@@2HA
    ARTS_IMPORT static i32 OpaqueSetCount;

    // 0x719730 | ?OutOfPoolFlushes@agiTexSorter@@2HA
    ARTS_IMPORT static i32 OutOfPoolFlushes;

    // 0x71973C | ?OverflowFlushes@agiTexSorter@@2HA
    ARTS_IMPORT static i32 OverflowFlushes;

    // 0x71977C | ?TotalTris@agiTexSorter@@2HA
    ARTS_IMPORT static i32 TotalTris;

private:
    // 0x719624 | ?Instance@agiTexSorter@@0PAV1@A
    ARTS_IMPORT static class agiTexSorter* Instance;
};

check_size(agiTexSorter, 0x1);

// 0x5043E0 | ?GetPackedTexture@@YAPAVagiTexDef@@PADH@Z
ARTS_EXPORT RcOwner<class agiTexDef> GetPackedTexture(char* name, i32 variation);

// 0x719838 | ?DisableFogOnAlphaGlow@@3HA
ARTS_IMPORT extern i32 DisableFogOnAlphaGlow;

// 0x64A3F0 | ?EnableTexSorting@@3HA
ARTS_IMPORT extern i32 EnableTexSorting;

// 0x71962C | ?EnvMapFlushes@@3HA
ARTS_IMPORT extern i32 EnvMapFlushes;

// 0x719628 | ?TextureSuffix@@3PADA
ARTS_IMPORT extern char* TextureSuffix;

class agiPolySet
{
public:
    constexpr agiPolySet() = default;

    agiPolySet(i32 verts, i32 indices);
    ~agiPolySet();

    // 0x510480 | ?Triangle@agiPolySet@@QAEXHHH@Z | inline
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

    agiScreenVtx* Vert()
    {
        ArAssert(!MultiTex, "PolySet is MultiTex");

        if (VertCount == MaxVerts)
            Quitf("Vertex pool overrun.");

        return &Verts[VertCount++];
    }

    agiScreenVtx2* Vert2()
    {
        ArAssert(MultiTex, "PolySet is not MultiTex");

        if (VertCount == MaxVerts)
            Quitf("Vertex pool overrun.");

        return &Verts2[VertCount++];
    }

    void Init(i32 verts, i32 indices);
    void Kill();

    u16* Indices {nullptr};
    agiScreenVtx* Verts {nullptr};
    agiScreenVtx2* Verts2 {nullptr};
    agiTexDef* Textures[2] {};
    i32 VertCount {0};
    i32 IndexCount {0};
    i32 BaseIndex {0};
    i32 MaxVerts {0};
    i32 MaxIndices {0};
    i32 MultiTex {0};

    // 0x719738 | ?TriCount@agiPolySet@@2HA
    ARTS_IMPORT static i32 TriCount;
};

check_size(agiPolySet, 0x2C);
