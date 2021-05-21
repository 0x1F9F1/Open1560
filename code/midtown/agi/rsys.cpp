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

define_dummy_symbol(agi_rsys);

#include "rsys.h"

#include "pipeline.h"

agiRasterizer* RAST = nullptr;

// Unused
struct agiRenderOpts
{};

agiRenderOpts ROPTS {};
agiRendState agiCurState {};
agiRendStateStruct agiLastState {};

agiRasterizer::agiRasterizer(agiPipeline* pipe)
    : agiRefreshable(pipe)
{
    agiLastState.Reset();

    agiCurState.SetDrawMode(15);
    agiCurState.SetZFunc(agiCmpFunc::LessEqual);
    agiCurState.SetSpecularEnable(false);
    agiCurState.Setbyte30(0);
    agiCurState.SetCullMode(agiCullMode::CCW);

    if (pipe->IsHardware())
    {
        agiCurState.SetBlendOp(agiBlendOp::Modulate);
    }

    agiCurState.SetAlphaRef(0);

    RAST = this;
}

void agiRasterizer::BeginGroup()
{}

void agiRasterizer::EndGroup()
{}

void agiRasterizer::Quad(i32 v0, i32 v1, i32 v2, i32 v3)
{
    Triangle(v0, v1, v2);
    Triangle(v0, v2, v3);
}

void agiRasterizer::Poly(i32* indices, i32 count)
{
    for (i32 i = 0; i + 2 < count; ++i)
    {
        Triangle(indices[0], indices[i + 1], indices[i + 2]);
    }
}

void agiRasterizer::Mesh2(agiScreenVtx2*, i32, u16*, i32)
{
    Quitf("agiRasterizer::Mesh2 not implemented for this renderer.");
}

void agiRasterizer::LineList(agiVtxType type, agiVtx* vertices, i32 vertex_count)
{
    BeginGroup();

    Verts(type, vertices, vertex_count);

    for (i32 i = 0; i < vertex_count; i += 2)
        Line(i, i + 1);

    EndGroup();
}

void agiRendStateStruct::Reset()
{
    std::memset(this, 0xFF, sizeof(*this));

    FogDensity = -99.0f;
    FogEnd = -99.0f;
    FogStart = -99.0f;
    LodBias = -99.0f;
}
