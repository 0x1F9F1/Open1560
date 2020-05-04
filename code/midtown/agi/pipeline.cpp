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

#include "pipeline.h"

agiPipeline::~agiPipeline()
{
    unimplemented();
}

i32 agiPipeline::Validate()
{
    return stub<thiscall_t<i32, agiPipeline*>>(0x155540_Offset, this);
}

i32 agiPipeline::BeginGfx()
{
    return stub<thiscall_t<i32, agiPipeline*>>(0x - 400000_Offset, this);
}

void agiPipeline::EndGfx()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x - 400000_Offset, this);
}

void agiPipeline::BeginFrame()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x155D10_Offset, this);
}

void agiPipeline::BeginScene()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x156000_Offset, this);
}

void agiPipeline::EndScene()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x156020_Offset, this);
}

void agiPipeline::EndFrame()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x156030_Offset, this);
}

class agiTexDef* agiPipeline::CreateTexDef()
{
    return stub<thiscall_t<class agiTexDef*, agiPipeline*>>(0x - 400000_Offset, this);
}

class agiTexLut* agiPipeline::CreateTexLut()
{
    return stub<thiscall_t<class agiTexLut*, agiPipeline*>>(0x - 400000_Offset, this);
}

class agiMtlDef* agiPipeline::CreateMtlDef()
{
    return stub<thiscall_t<class agiMtlDef*, agiPipeline*>>(0x155B10_Offset, this);
}

class DLP* agiPipeline::CreateDLP()
{
    return stub<thiscall_t<class DLP*, agiPipeline*>>(0x - 400000_Offset, this);
}

class agiViewport* agiPipeline::CreateViewport()
{
    return stub<thiscall_t<class agiViewport*, agiPipeline*>>(0x - 400000_Offset, this);
}

class agiLight* agiPipeline::CreateLight()
{
    return stub<thiscall_t<class agiLight*, agiPipeline*>>(0x155B20_Offset, this);
}

class agiLightModel* agiPipeline::CreateLightModel()
{
    return stub<thiscall_t<class agiLightModel*, agiPipeline*>>(0x155B30_Offset, this);
}

class agiBitmap* agiPipeline::CreateBitmap()
{
    return stub<thiscall_t<class agiBitmap*, agiPipeline*>>(0x155D30_Offset, this);
}

void agiPipeline::CopyBitmap(i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, agiPipeline*, i32, i32, class agiBitmap*, i32, i32, i32, i32>>(
        0x155D40_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void agiPipeline::ClearAll(i32 arg1)
{
    return stub<thiscall_t<void, agiPipeline*, i32>>(0x - 400000_Offset, this, arg1);
}

void agiPipeline::ClearRect(i32 arg1, i32 arg2, i32 arg3, i32 arg4, u32 arg5)
{
    return stub<thiscall_t<void, agiPipeline*, i32, i32, i32, i32, u32>>(
        0x156070_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void agiPipeline::Print(i32 arg1, i32 arg2, i32 arg3, char const* arg4)
{
    return stub<thiscall_t<void, agiPipeline*, i32, i32, i32, char const*>>(
        0x157F20_Offset, this, arg1, arg2, arg3, arg4);
}

i32 agiPipeline::PrintIs3D()
{
    return stub<thiscall_t<i32, agiPipeline*>>(0x158110_Offset, this);
}

void agiPipeline::PrintInit()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x158130_Offset, this);
}

void agiPipeline::PrintShutdown()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x158140_Offset, this);
}

void agiPipeline::Defragment()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x156080_Offset, this);
}

i32 agiPipeline::LockFrameBuffer(class agiSurfaceDesc& arg1)
{
    return stub<thiscall_t<i32, agiPipeline*, class agiSurfaceDesc&>>(0x156040_Offset, this, arg1);
}

void agiPipeline::UnlockFrameBuffer()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x156050_Offset, this);
}

void agiPipeline::DumpStatus(struct agiMemStatus& arg1)
{
    return stub<thiscall_t<void, agiPipeline*, struct agiMemStatus&>>(0x156060_Offset, this, arg1);
}

i32 agiPipeline::BeginAllGfx()
{
    return stub<thiscall_t<i32, agiPipeline*>>(0x155B40_Offset, this);
}

i32 agiPipeline::CopyClippedBitmap(i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<i32, agiPipeline*, i32, i32, class agiBitmap*, i32, i32, i32, i32>>(
        0x155D50_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

i32 agiPipeline::CopyClippedBitmap(i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7,
    i32 arg8, i32 arg9, i32 arg10, i32 arg11)
{
    return stub<thiscall_t<i32, agiPipeline*, i32, i32, class agiBitmap*, i32, i32, i32, i32, i32, i32, i32, i32>>(
        0x155D90_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}

void agiPipeline::DumpStatus()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x155F00_Offset, this);
}

void agiPipeline::EndAllGfx()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x155C40_Offset, this);
}

class agiBitmap* agiPipeline::GetBitmap(char* arg1, f32 arg2, f32 arg3, i32 arg4)
{
    return stub<thiscall_t<class agiBitmap*, agiPipeline*, char*, f32, f32, i32>>(
        0x155750_Offset, this, arg1, arg2, arg3, arg4);
}

class DLP* agiPipeline::GetDLP(char* arg1, char* arg2, class Vector3* arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<class DLP*, agiPipeline*, char*, char*, class Vector3*, i32, i32>>(
        0x155950_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

class agiMtlDef* agiPipeline::GetMaterial(char* arg1)
{
    return stub<thiscall_t<class agiMtlDef*, agiPipeline*, char*>>(0x155860_Offset, this, arg1);
}

class agiMtlDef* agiPipeline::GetMaterial(i32 arg1)
{
    return stub<thiscall_t<class agiMtlDef*, agiPipeline*, i32>>(0x1558C0_Offset, this, arg1);
}

class agiTexLut* agiPipeline::GetTexLut(char* arg1)
{
    return stub<thiscall_t<class agiTexLut*, agiPipeline*, char*>>(0x1557F0_Offset, this, arg1);
}

class agiTexDef* agiPipeline::GetTexture(char* arg1, i32 arg2)
{
    return stub<thiscall_t<class agiTexDef*, agiPipeline*, char*, i32>>(0x1555C0_Offset, this, arg1, arg2);
}

class agiTexDef* agiPipeline::GetTexture(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<class agiTexDef*, agiPipeline*, i32, i32>>(0x155620_Offset, this, arg1, arg2);
}

i32 agiPipeline::Init(char* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, void* arg8)
{
    return stub<thiscall_t<i32, agiPipeline*, char*, i32, i32, i32, i32, i32, i32, void*>>(
        0x155550_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

void agiPipeline::NotifyDelete(class agiRefreshable* arg1)
{
    return stub<thiscall_t<void, agiPipeline*, class agiRefreshable*>>(0x155E70_Offset, this, arg1);
}

void agiPipeline::NotifyNew(class agiRefreshable* arg1)
{
    return stub<thiscall_t<void, agiPipeline*, class agiRefreshable*>>(0x155E40_Offset, this, arg1);
}

void agiPipeline::RestoreAll()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x155CD0_Offset, this);
}

void agiPipeline::ValidateObject(class agiRefreshable* arg1)
{
    return stub<thiscall_t<void, agiPipeline*, class agiRefreshable*>>(0x155EB0_Offset, this, arg1);
}

agiPipeline::agiPipeline()
{
    unimplemented();
}

void* CreatePipelineAttachableWindow(char* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, void* arg6)
{
    return stub<cdecl_t<void*, char*, i32, i32, i32, i32, void*>>(0x155F80_Offset, arg1, arg2, arg3, arg4, arg5, arg6);
}

void DestroyPipelineAttachableWindow()
{
    return stub<cdecl_t<void>>(0x155F90_Offset);
}

void* GetRootWindow()
{
    return stub<cdecl_t<void*>>(0x155F70_Offset);
}

define_dummy_symbol(agi_pipeline);
