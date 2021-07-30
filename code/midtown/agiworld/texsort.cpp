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

define_dummy_symbol(agiworld_texsort);

#include "texsort.h"

#include "agi/pipeline.h"
#include "agi/rsys.h"
#include "agi/texdef.h"
#include "agi/texlib.h"
#include "arts7/bank.h"
#include "getmesh.h"
#include "quality.h"
#include "texsheet.h"

// Note: codes/fogout/nextFactet/out are limited to 16384

// Default: 3000
static constexpr i32 BigVtxSize = 16384;
static constexpr i32 BigIdxSize = BigVtxSize * 3;

// Default: 1024
static constexpr i32 EnvVtxSize = 16384;
static constexpr i32 EnvIdxSize = EnvVtxSize * 3;

static i32 VtxSize = 0;
static i32 IdxSize = 0;

ARTS_IMPORT extern agiPolySet BigPolySet;

static mem::cmd_param PARAM_max_verts_per_set {"maxverts"};

class agiPolySet* agiTexSorter::AlphaPolySets[32];
class agiPolySet* agiTexSorter::OpaquePolySets[128];

agiTexSorter::agiTexSorter()
{
    if (Instance)
        Quitf("Already have a TexSorter");

    Instance = this;

    VtxSize = std::min<i32>(PARAM_max_verts_per_set.get_or<i32>(1024), 8192);
    IdxSize = VtxSize * 3;

    MaxVertsPerSet = VtxSize;
    MaxIndicesPerSet = IdxSize;

    MaxOpaqueSetCount = ARTS_SSIZE32(OpaquePolySets);
    MaxAlphaSetCount = ARTS_SSIZE32(AlphaPolySets);

    BigPolySet.Init(BigVtxSize, BigIdxSize);

    for (usize i = 0; i < ARTS_SIZE(OpaquePolySets); ++i)
        OpaquePolySets[i] = new agiPolySet(MaxVertsPerSet, MaxIndicesPerSet);

    for (usize i = 0; i < ARTS_SIZE(AlphaPolySets); ++i)
        AlphaPolySets[i] = new agiPolySet(MaxVertsPerSet, MaxIndicesPerSet);

    EnvPolySet.Init(EnvVtxSize, EnvIdxSize);
}

agiTexSorter::~agiTexSorter()
{
    BigPolySet.Kill();

    for (usize i = 0; i < ARTS_SIZE(OpaquePolySets); ++i)
        delete std::exchange(OpaquePolySets[i], nullptr);

    for (usize i = 0; i < ARTS_SIZE(AlphaPolySets); ++i)
        delete std::exchange(AlphaPolySets[i], nullptr);

    EnvPolySet.Kill();

    Instance = nullptr;
}

#ifdef ARTS_DEV_BUILD
void agiTexSorter::AddWidgets(Bank* bank)
{
    bank->AddSlider("MaxVertsPerSet", &MaxVertsPerSet, 8, VtxSize, 4.0f, NullCallback);
    bank->AddSlider("MaxIndicesPerSet", &MaxIndicesPerSet, 8, IdxSize, 4.0f, NullCallback);
}
#endif

ARTS_IMPORT extern agiPolySet* ColoredPolySet;
ARTS_IMPORT extern agiPolySet* LastPolySet;

static agiPolySet** ActivePolySet(agiTexDef* texture)
{
    return texture ? &texture->PolySet : &ColoredPolySet;
}

void agiTexSorter::Cull(b32 alpha)
{
    for (i32 i = 0; i < OpaqueSetCount; ++i)
    {
        DoTexture(OpaquePolySets[i]);
        *ActivePolySet(OpaquePolySets[i]->Textures[0]) = nullptr;
    }

    OpaqueSetCount = 0;

    if (alpha)
    {
        if (EnvPolySet.Textures[0])
        {
            DoTexture(&EnvPolySet);
            EnvPolySet.Textures[0]->PolySet = nullptr;
            EnvPolySet.Textures[0] = nullptr;
        }

        for (i32 i = 0; i < AlphaSetCount; ++i)
        {
            DoTexture(AlphaPolySets[i]);
            AlphaPolySets[i]->Textures[0]->PolySet = nullptr;
        }

        AlphaSetCount = 0;
    }
}

agiPolySet* agiTexSorter::BeginVerts(agiTexDef* texture, i32 vert_count, i32 index_count)
{
    ArAssert(!LastPolySet, "Missing EndVerts call");

    if (!EnableTexSorting || vert_count > MaxVertsPerSet || index_count > MaxIndicesPerSet)
    {
        ArAssert(vert_count <= BigVtxSize && index_count <= BigIdxSize, "Too many verts");

        BigPolySet.Textures[0] = texture;
        BigPolySet.MultiTex = false;
        ++BigPoolFlushes;
        LastPolySet = &BigPolySet;
        return &BigPolySet;
    }

    agiPolySet** active_set = ActivePolySet(texture);
    agiPolySet* result = *active_set;

    if (result)
    {
        if ((vert_count + result->VertCount > MaxVertsPerSet) ||
            (index_count + result->IndexCount > MaxIndicesPerSet) || result->MultiTex)
        {
            ++OverflowFlushes;

            if (texture && (texture->Tex.HasAlpha() || (texture->Tex.Props & agiTexProp::AlphaGlow)))
                Instance->Cull(false);

            DoTexture(result);
            result->MultiTex = false;
        }
        else
        {
            result->BaseIndex = result->VertCount;
        }
    }
    else
    {
        if (texture && (texture->Tex.HasAlpha() || (texture->Tex.Props & agiTexProp::AlphaGlow)))
        {
            if (AlphaSetCount >= MaxAlphaSetCount)
            {
                for (i32 i = 0; i < AlphaSetCount; ++i)
                    Displayf("Texture '%s'", AlphaPolySets[i]->Textures[0]->Tex.Name);

                Quitf("Too many alpha textures in scene!");
            }

            result = AlphaPolySets[AlphaSetCount++];
        }
        else if (OpaqueSetCount >= MaxOpaqueSetCount)
        {
            // Find and flush the largest vert set
            result = OpaquePolySets[0];
            i32 best_verts = OpaquePolySets[0]->VertCount;

            for (i32 i = 1; i < OpaqueSetCount; ++i)
            {
                if (best_verts < OpaquePolySets[i]->VertCount)
                {
                    best_verts = OpaquePolySets[i]->VertCount;
                    result = OpaquePolySets[i];
                }
            }

            ++OutOfPoolFlushes;
            DoTexture(result);
            *ActivePolySet(result->Textures[0]) = nullptr;
        }
        else
        {
            result = OpaquePolySets[OpaqueSetCount++];
        }

        *active_set = result;
        result->Textures[0] = texture;
        result->MultiTex = false;
    }

    LastPolySet = result;
    return result;
}

void agiTexSorter::EndVerts()
{
    ArAssert(LastPolySet, "Missing BeginVerts call");

    if (LastPolySet == &BigPolySet)
        DoTexture(&BigPolySet);

    LastPolySet = nullptr;
}

agiPolySet* agiTexSorter::GetEnv(agiTexDef* texture, i32 vert_count, i32 index_count)
{
    ArAssert(vert_count <= EnvVtxSize && index_count <= EnvIdxSize, "Too many verts");

    if (!texture->PolySet && EnvPolySet.Textures[0])
    {
        ++EnvMapFlushes;
        Instance->Cull(false);
        DoTexture(&EnvPolySet);
        EnvPolySet.Textures[0]->PolySet = nullptr;
    }

    texture->PolySet = &EnvPolySet;

    if ((vert_count + EnvPolySet.VertCount <= EnvVtxSize) && (index_count + EnvPolySet.IndexCount <= EnvIdxSize))
    {
        EnvPolySet.BaseIndex = EnvPolySet.VertCount;
        EnvPolySet.Textures[0] = texture;
    }
    else
    {
        ++EnvMapFlushes;
        Instance->Cull(false);
        DoTexture(&EnvPolySet);
    }

    return &EnvPolySet;
}

agiPolySet::agiPolySet(i32 verts, i32 indices)
{
    Init(verts, indices);
}

agiPolySet::~agiPolySet()
{
    Kill();
}

static constexpr usize PolyAlignment = 64;

void agiPolySet::Init(i32 verts, i32 indices)
{
    if (agiCurState.GetMaxTextures() <= 1)
    {
        Verts = static_cast<agiScreenVtx*>(arts_aligned_alloc(verts * sizeof(agiScreenVtx), PolyAlignment));
    }
    else
    {
        Verts2 = static_cast<agiScreenVtx2*>(arts_aligned_alloc(verts * sizeof(agiScreenVtx2), PolyAlignment));
        Verts = reinterpret_cast<agiScreenVtx*>(Verts2);
    }

    MaxVerts = verts;
    MaxIndices = indices;
    Indices = static_cast<u16*>(arts_aligned_alloc(indices * sizeof(u16), PolyAlignment));
}

void agiPolySet::Kill()
{
    if (Verts2)
        arts_aligned_free(Verts2, PolyAlignment);
    else
        arts_aligned_free(Verts, PolyAlignment);

    arts_aligned_free(Indices, PolyAlignment);

    Verts = nullptr;
    Verts2 = nullptr;
    Indices = nullptr;
}

RcOwner<class agiTexDef> GetPackedTexture(char* name, i32 variation)
{
    static i32 mutex = 0;
    ArAssert(++mutex == 1, "Wow, what a great mutex");

    InitTexSheet();

    char full_name[64];
    arts_strcpy(full_name, name);

    if (TextureSuffix)
        arts_strcat(full_name, TextureSuffix);

    agiTexProp* prop = TEXSHEET.Lookup(full_name);

    if (!prop)
    {
        arts_strcpy(full_name, name);
        prop = TEXSHEET.Lookup(full_name);
    }

    if (!prop)
        Quitf("Trying to load texture not in texsheet: '%s' (mesh = %s)", name, MeshCurrentObject);

    agiTexParameters tex;
    arts_strcpy(tex.Name, full_name);

    FixTexFlags(tex);
    arts_strcpy(tex.Name, TEXSHEET.RemapName(full_name, variation));

    agiTexParameters& lib_tex = agiTexLib[agiTexLib.Add(tex)];

    lib_tex.Flags &= ~(agiTexParameters::Alpha | agiTexParameters::WrapU | agiTexParameters::WrapV);
    lib_tex.Flags |= tex.Flags;
    lib_tex.Props |= tex.Props;

    // NOTE: Originally checked if prop is null, but that isn't possible

    i32 pack_shift = (agiRQ.TextureQuality >= AGI_QUALITY_HIGH) ? prop->High
        : (agiRQ.TextureQuality >= AGI_QUALITY_MEDIUM)          ? prop->Medium
                                                                : prop->Low;

    lib_tex.field_28 = (prop->Flags & agiTexProp::Snowable) ? 4.0f : 2.0f;

    Rc<agiTexDef> texture = AsRc(Pipe()->GetTexture(tex.Name, pack_shift));

    if (!texture)
        Warningf("HEY!  Texture '%s' (%s,var=%d,pack=%d) didn't load.", full_name, tex.Name, variation, pack_shift);

    --mutex;

    return AsOwner(texture);
}

run_once([] {
    create_patch("BigVtxSize", "agiTexSorter::BeginVerts2", 0x503D79 + 2, &BigVtxSize, 4);
    create_patch("BigIdxSize", "agiTexSorter::BeginVerts2", 0x503D81 + 3, &BigIdxSize, 4);

    create_patch("agiMeshSet::DrawCard", "Invalid indices count", 0x50F718, "\x8D\x0C\x52", 3);

    for (usize addr : {0x499281, 0x4991B9})
        create_patch("mmCellRenderer::Cull", "Don't flush TexSorter", addr, "\x83\xC4\x04\x90\x90", 5);
});
