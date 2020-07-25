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

#include "agi/rsys.h"
#include "arts7/bank.h"

// TODO: Use CMD arguments
static constexpr i32 BigVtxSize = 65536;
static constexpr i32 BigIdxSize = BigVtxSize * 3;

static constexpr i32 EnvVtxSize = 32768;
static constexpr i32 EnvIdxSize = EnvVtxSize * 3;

static constexpr i32 VtxSize = 2048;
static constexpr i32 IdxSize = VtxSize * 3;

static extern_var(0x719808, agiPolySet, BigPolySet);

agiTexSorter::agiTexSorter()
{
    if (Instance)
        Quitf("Already have a TexSorter");

    Instance = this;

    MaxVertsPerSet = VtxSize;
    MaxIndicesPerSet = IdxSize;

    BigPolySet.Init(BigVtxSize, BigIdxSize);

    for (usize i = 0; i < std::size(OpaquePolySets); ++i)
        OpaquePolySets[i] = new agiPolySet(MaxVertsPerSet, MaxIndicesPerSet);

    for (usize i = 0; i < std::size(AlphaPolySets); ++i)
        AlphaPolySets[i] = new agiPolySet(MaxVertsPerSet, MaxIndicesPerSet);

    EnvPolySet.Init(EnvVtxSize, EnvIdxSize);
}

agiTexSorter::~agiTexSorter()
{
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

void agiPolySet::Init(i32 verts, i32 indices)
{
    // NOTE: Currently only vert type 1 is used (no multi texture)

    if (agiCurState.GetVertType() <= 1)
    {
        Verts = new agiScreenVtx[verts];
    }
    else
    {
        Verts2 = new agiScreenVtx2[verts];
        Verts = reinterpret_cast<agiScreenVtx*>(Verts2);
    }

    MaxVerts = verts;
    MaxIndices = indices;
    Indices = new u16[indices];
}

run_once([] {
    create_patch("BigVtxSize", "agiTexSorter::BeginVerts", 0x503B29 + 2, &BigVtxSize, 4);
    create_patch("BigIdxSize", "agiTexSorter::BeginVerts", 0x503B31 + 3, &BigIdxSize, 4);

    create_patch("BigVtxSize", "agiTexSorter::BeginVerts2", 0x503D79 + 2, &BigVtxSize, 4);
    create_patch("BigIdxSize", "agiTexSorter::BeginVerts2", 0x503D81 + 3, &BigIdxSize, 4);

    create_patch("EnvVtxSize", "agiTexSorter::GetEnv", 0x503AB9 + 2, &EnvVtxSize, 4);
    create_patch("EnvIdxSize", "agiTexSorter::GetEnv", 0x503ACC + 2, &EnvIdxSize, 4);
});