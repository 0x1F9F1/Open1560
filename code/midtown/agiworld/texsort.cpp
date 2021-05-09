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

static extern_var(0x719808, agiPolySet, BigPolySet);

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

void agiTexSorter::AddWidgets(Bank* bank)
{
    bank->AddSlider("MaxVertsPerSet", &MaxVertsPerSet, 8, VtxSize, 4.0f, NullCallback);
    bank->AddSlider("MaxIndicesPerSet", &MaxIndicesPerSet, 8, IdxSize, 4.0f, NullCallback);
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

    // NOTE: Originally chcked if prop is null, but that isn't possible

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
    create_patch("BigVtxSize", "agiTexSorter::BeginVerts", 0x503B29 + 2, &BigVtxSize, 4);
    create_patch("BigIdxSize", "agiTexSorter::BeginVerts", 0x503B31 + 3, &BigIdxSize, 4);

    create_patch("BigVtxSize", "agiTexSorter::BeginVerts2", 0x503D79 + 2, &BigVtxSize, 4);
    create_patch("BigIdxSize", "agiTexSorter::BeginVerts2", 0x503D81 + 3, &BigIdxSize, 4);

    create_patch("EnvVtxSize", "agiTexSorter::GetEnv", 0x503AB9 + 2, &EnvVtxSize, 4);
    create_patch("EnvIdxSize", "agiTexSorter::GetEnv", 0x503ACC + 2, &EnvIdxSize, 4);
});
