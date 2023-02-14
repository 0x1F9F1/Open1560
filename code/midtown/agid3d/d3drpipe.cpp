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
#include "agirend/rdlp.h"
#include "agirend/zbrender.h"
#include "d3drsys.h"
#include "d3dview.h"

i32 agiD3DRPipeline::BeginGfx()
{
    if (i32 error = agiD3DPipeline::BeginGfx())
        return error;

    rasterizer_ = arref agiD3DRasterizer(this);
    renderer_ = arref agiZBufRenderer(rasterizer_.get());

    return AGI_ERROR_SUCCESS;
}

void agiD3DRPipeline::BeginScene()
{
    UpdateZTrick();

    agiD3DPipeline::BeginScene();
    agiLighter::BeginScene();
}

RcOwner<DLP> agiD3DRPipeline::CreateDLP()
{
    return as_owner arref RDLP(this);
}

RcOwner<agiLight> agiD3DRPipeline::CreateLight()
{
    return as_owner arref agiBILight(this);
}

RcOwner<agiLightModel> agiD3DRPipeline::CreateLightModel()
{
    return as_owner arref agiBILightModel(this);
}

RcOwner<agiViewport> agiD3DRPipeline::CreateViewport()
{
    return as_owner arref agiD3DViewport(this);
}

void agiD3DRPipeline::EndGfx()
{
    renderer_ = nullptr;
    rasterizer_ = nullptr;

    agiD3DPipeline::EndGfx();
}

void agiD3DRPipeline::EndScene()
{
    rasterizer_->EndGroup();

    agiD3DPipeline::EndScene();
}
