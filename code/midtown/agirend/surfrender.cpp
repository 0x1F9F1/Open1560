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

define_dummy_symbol(agirend_surfrender);

#include "surfrender.h"

#include "agi/lmodel.h"
#include "agi/rsys.h"
#include "agiworld/meshset.h"
#include "lighter.h"
#include "projvtx.h"

void agiSurfRenderer::BeginDraw(i32 flags)
{
    agiProjVtx::Init(flags & 1, lighter_, 0xFFFFFFFF);

    BeginGroup();
}

void agiSurfRenderer::BeginGroup()
{
    agiSurfRenderer::VertexCount = 1;
    agiSurfRenderer::SurfaceCount = 0;

    if (agiLighter::LMODEL)
    {
        if (agiLighter::LMODEL->Params.Monochromatic)
            lighter_ = &MONOLIGHTER;
        else
            lighter_ = &RGBLIGHTER;
    }
}

void UpdateZTrick()
{
    if (ZTrick)
    {
        if (agiCurState.GetZFunc() == agiCmpFunc::LessEqual)
        {
            agiCurState.SetZFunc(agiCmpFunc::GreaterEqual);
            DepthScale = -0.24f;
            DepthOffset = 0.75f;
        }
        else
        {
            agiCurState.SetZFunc(agiCmpFunc::LessEqual);
            DepthScale = 0.24f;
            DepthOffset = 0.25f;
        }
    }
    else
    {
        agiCurState.SetZFunc(agiCmpFunc::LessEqual);
        DepthScale = agiMeshSet::DepthScale;
        DepthOffset = agiMeshSet::DepthOffset;
    }
}
