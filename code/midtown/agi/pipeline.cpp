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

define_dummy_symbol(agi_pipeline);

#include "pipeline.h"

i32 agiPipeline::Validate()
{
    return 0;
}

void agiPipeline::BeginFrame()
{
    STATS = {};
}

void agiPipeline::EndScene()
{}

void agiPipeline::EndFrame()
{}

class agiMtlDef* agiPipeline::CreateMtlDef()
{
    return nullptr;
}

class agiLight* agiPipeline::CreateLight()
{
    return nullptr;
}

class agiLightModel* agiPipeline::CreateLightModel()
{
    return nullptr;
}

class agiBitmap* agiPipeline::CreateBitmap()
{
    return nullptr;
}

void agiPipeline::CopyBitmap(
    i32 /*dst_x*/, i32 /*dst_y*/, agiBitmap* /*src*/, i32 /*src_x*/, i32 /*src_y*/, i32 /*width*/, i32 /*height*/)
{}

void agiPipeline::ClearRect(i32 /*x*/, i32 /*y*/, i32 /*width*/, i32 /*height*/, u32 /*color*/)
{}

void agiPipeline::Defragment()
{}

i32 agiPipeline::LockFrameBuffer(class agiSurfaceDesc& /*arg1*/)
{
    return 0;
}

void agiPipeline::UnlockFrameBuffer()
{}

void agiPipeline::DumpStatus(struct agiMemStatus& /*arg1*/)
{}

void DestroyPipelineAttachableWindow()
{}
