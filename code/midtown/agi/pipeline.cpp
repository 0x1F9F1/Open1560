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

#include "bitmap.h"
#include "core/minwin.h"
#include "data7/hash.h"
#include "data7/ipc.h"
#include "dlptmpl.h"
#include "error.h"
#include "eventq7/eventq.h"
#include "eventq7/winevent.h"
#include "light.h"
#include "lmodel.h"
#include "mtldef.h"
#include "pcwindis/dxinit.h"
#include "refresh.h"
#include "rsys.h"
#include "texdef.h"

i32 agiPipeline::Validate()
{
    return 0;
}

void agiPipeline::BeginFrame()
{
    STATS = {};
}

void agiPipeline::BeginScene()
{
    UpdateLutQueue();

    ++scene_index_;
}

void agiPipeline::EndScene()
{}

void agiPipeline::EndFrame()
{}

RcOwner<class agiMtlDef> agiPipeline::CreateMtlDef()
{
    return nullptr;
}

RcOwner<class agiLight> agiPipeline::CreateLight()
{
    return nullptr;
}

RcOwner<class agiLightModel> agiPipeline::CreateLightModel()
{
    return nullptr;
}

RcOwner<class agiBitmap> agiPipeline::CreateBitmap()
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

b32 agiPipeline::LockFrameBuffer(class agiSurfaceDesc& /*arg1*/)
{
    return 0;
}

void agiPipeline::UnlockFrameBuffer()
{}

void agiPipeline::DumpStatus(struct agiMemStatus& /*arg1*/)
{}

static extern_var(0x8FAC78, ipcMessageQueue, GFXPAGER);

i32 UI_XPos = 0;
i32 UI_YPos = 0;

i32 UI_Width = 0;
i32 UI_Height = 0;

f32 UI_StartX = 0.0f;
f32 UI_StartY = 0.0f;

f32 UI_ScaleX = 0.0f;
f32 UI_ScaleY = 0.0f;

f32 UI_FullW = 0.0f;
f32 UI_FullH = 0.0f;

i32 agiPipeline::BeginAllGfx()
{
    i32 error = BeginGfx();

    agiLastState.Reset();

    if (error != AGI_ERROR_SUCCESS)
    {
        Displayf("Pipeline.BeginGfx: %s", agiGetError(error));
        EndGfx();
        return error;
    }

    CurrentRenderer = renderer_.get();

    // TODO: Move scaling to MenuManager::Init?
    UI_Width = width_;
    UI_Height = height_;

    f32 game_aspect = 640.0f / 480.0f;
    f32 ui_aspect = static_cast<f32>(UI_Width) / static_cast<f32>(UI_Height);

    if (ui_aspect > game_aspect)
        UI_Width = static_cast<i32>(UI_Width * (game_aspect / ui_aspect));
    else if (ui_aspect < game_aspect)
        UI_Height = static_cast<i32>(UI_Height * (ui_aspect / game_aspect));

    UI_XPos = (width_ - UI_Width) / 2;
    UI_YPos = (height_ - UI_Height) / 2;

    Displayf("UI Position: x=%i, y=%i, w=%i, h=%i", UI_XPos, UI_YPos, UI_Width, UI_Height);

    UI_ScaleX = static_cast<f32>(UI_Width) / static_cast<f32>(width_);
    UI_ScaleY = static_cast<f32>(UI_Height) / static_cast<f32>(height_);

    UI_StartX = static_cast<f32>(UI_XPos) / static_cast<f32>(width_);
    UI_StartY = static_cast<f32>(UI_YPos) / static_cast<f32>(height_);

    UI_FullW = 640.0f / UI_ScaleX;
    UI_FullH = 480.0f / UI_ScaleY;

    agiDisplayf("Refreshing objects");

    for (agiRefreshable* i = objects_; i; i = i->next_)
    {
        error = i->SafeBeginGfx();

        if (error != AGI_ERROR_SUCCESS && error != AGI_ERROR_ALREADY_INITIALIZED)
        {
            Quitf("Error resurrecting object: %s: %s", i->GetName(), agiGetError(error));
        }
    }

    agiDisplayf("Done with object refresh");

    if (eqEventHandler::SuperQ == nullptr)
        InitEventQueue();

    if (dxiIsFullScreen())
        error = eqEventHandler::SuperQ->BeginGfx(640, 480, true);
    else
        error = eqEventHandler::SuperQ->BeginGfx(width_, height_, false);

    GFXPAGER.Init(64, false);

    return error;
}

b32 agiPipeline::CopyClippedBitmap(i32 dst_x, i32 dst_y, agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height)
{
    return CopyClippedBitmap(dst_x, dst_y, src, src_x, src_y, width, height, 0, 0, GetWidth(), GetHeight());
}

b32 agiPipeline::CopyClippedBitmap(i32 dst_x, i32 dst_y, agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height,
    i32 min_x, i32 min_y, i32 max_x, i32 max_y)
{
    if (dst_x < min_x) // NOTE: Originally checked dst_x < 0
    {
        width -= min_x - dst_x;
        src_x += min_x - dst_x;
        dst_x = min_x;
    }
    else if (dst_x >= max_x)
    {
        return false;
    }

    if (dst_y < min_y)
    {
        height -= min_y - dst_y;
        src_y += min_y - dst_y;
        dst_y = min_y;
    }
    else if (dst_y >= max_y)
    {
        return false;
    }

    if (width <= 0 || height <= 0)
    {
        return false;
    }

    if (width + dst_x > max_x)
        width = max_x - dst_x;

    if (height + dst_y > max_y)
        height = max_y - dst_y;

    CopyBitmap(dst_x, dst_y, src, src_x, src_y, width, height);

    return true;
}

void agiPipeline::DumpStatus()
{
    for (agiRefreshable* i = objects_; i; i = i->next_)
        agiDisplayf("Refreshable: %s", i->GetName());

    for (HashIterator i(&DLPTemplateHash); i.Next();)
        agiDisplayf("Template %s @ %p", i->Key.get(), i->Value);
}

void agiPipeline::EndAllGfx()
{
    CurrentRenderer = nullptr;

    GFXPAGER.Shutdown();

    if (!gfx_started_)
        return;

    ShutdownLutQueue();

    if (eqEventHandler::SuperQ)
        eqEventHandler::SuperQ->EndGfx();

    agiCurState.SetTexture(nullptr);
    agiCurState.SetMtl(nullptr);

    for (agiRefreshable* i = objects_; i; i = i->next_)
        i->EndGfx();

    EndGfx();
}

RcOwner<agiBitmap> agiPipeline::GetBitmap(const char* name, f32 sx, f32 sy, i32 flags)
{
    char buffer[64];
    arts_sprintf(buffer, "%s.%x.%x.%d", name, mem::bit_cast<u32>(sx), mem::bit_cast<u32>(sy), flags);

    if (agiBitmap* result = static_cast<agiBitmap*>(BitmapHash.Access(buffer)))
    {
        return AsOwner(AddRc(result));
    }

    Rc<agiBitmap> result {CreateBitmap()};

    if (result->Init(name, sx, sy, flags) != AGI_ERROR_SUCCESS)
        return nullptr;

    BitmapHash.Insert(buffer, result.get());

    return AsOwner(result);
}

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

static mem::cmd_param PARAM_agi_verbose {"agiverbose"};

agiPipeline::agiPipeline()
{
    agiVerbose = PARAM_agi_verbose.get_or(false);

    window_ = GetRootWindow();

    unsigned int current = 0;
    _controlfp_s(&current, 0x20000, 0x30000);

    PROBER = 0;
}

agiPipeline::~agiPipeline()
{
    if (agiRefreshable* i = objects_)
    {
        Errorf("Pipeline didn't release all its objects.");

        for (; i; i = i->next_)
        {
            i->AddRef();
            agiDisplayf("Refreshable '%s' ref count = %d", i->GetName(), i->Release());
            i->pipe_ = nullptr;
        }
    }
}
