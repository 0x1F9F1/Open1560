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

#include "core/minwin.h"
#include "data7/hash.h"
#include "error.h"
#include "pcwindis/dxinit.h"
#include "refresh.h"

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

void* CreatePipelineAttachableWindow(
    char* /*title*/, i32 /*x*/, i32 /*y*/, i32 /*width*/, i32 /*height*/, void* /*ptr*/)
{
    return hwndMain;
}

void DestroyPipelineAttachableWindow()
{}

void* GetRootWindow()
{
    return GetDesktopWindow();
}

i32 agiPipeline::Init(const char* name, i32 x, i32 y, i32 width, i32 height, i32 bit_depth, i32 flags, void* window)
{
    EndAllGfx();

    name_ = name;
    x_ = x;
    y_ = y;
    width_ = width;
    height_ = height;
    bit_depth_ = bit_depth;
    device_flags_1_ = flags;
    window_ = window;

    return BeginAllGfx();
}

void agiPipeline::NotifyDelete(agiRefreshable* ptr)
{
    if (ptr == objects_)
        objects_ = ptr->next_;
    else
        ptr->prev_->next_ = ptr->next_;

    if (ptr->next_)
        ptr->next_->prev_ = ptr->prev_;
}

void agiPipeline::NotifyNew(agiRefreshable* ptr)
{
    ptr->next_ = objects_;

    if (ptr->next_)
        ptr->next_->prev_ = ptr;

    objects_ = ptr;
}

void agiPipeline::RestoreAll()
{
    agiDisplayf("Restoring lost objects");

    for (agiRefreshable* i = objects_; i; i = i->next_)
        i->Restore();

    agiDisplayf("Done restoring lost objects");
}

void agiPipeline::ValidateObject(agiRefreshable* ptr)
{
    if (this != ptr->pipe_)
        Quitf("PIPE::ValidateObject: I don't own this.");

    for (agiRefreshable* i = objects_; i != ptr; i = i->next_)
    {
        if (i == nullptr)
            Quitf("PIPE::ValidateObject: Not in my list.");
    }
}