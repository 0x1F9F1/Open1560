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

define_dummy_symbol(agid3d_d3drpipe);

#include "d3drpipe.h"

#include "agi/error.h"
#include "agi/render.h"
#include "agi/rsys.h"

#include "agirend/bilight.h"
#include "agirend/bilmodel.h"
#include "agirend/lighter.h"
#include "agirend/projvtx.h"
#include "agirend/rdlp.h"
#include "agirend/zbrender.h"
#include "d3drsys.h"
#include "d3dview.h"

i32 agiD3DRPipeline::BeginGfx()
{
    if (i32 error = agiD3DPipeline::BeginGfx())
        return error;

    SafeRelease(renderer_);
    SafeRelease(rasterizer_);

    rasterizer_ = new agiD3DRasterizer(this);
    renderer_ = new agiZBufRenderer(rasterizer_);

    return AGI_ERROR_SUCCESS;
}

void agiD3DRPipeline::BeginScene()
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
        DepthScale = 0.5f;
        DepthOffset = 0.5f;
    }

    agiD3DPipeline::BeginScene();
    agiLighter::BeginScene();
}

DLP* agiD3DRPipeline::CreateDLP()
{
    return new RDLP(this);
}

agiLight* agiD3DRPipeline::CreateLight()
{
    return new agiBILight(this);
}

agiLightModel* agiD3DRPipeline::CreateLightModel()
{
    return new agiBILightModel(this);
}

agiViewport* agiD3DRPipeline::CreateViewport()
{
    return new agiD3DViewport(this);
}

void agiD3DRPipeline::EndGfx()
{
    SafeRelease(rasterizer_);

    agiD3DPipeline::EndGfx();
}

void agiD3DRPipeline::EndScene()
{
    rasterizer_->EndGroup();

    agiD3DPipeline::EndScene();
}