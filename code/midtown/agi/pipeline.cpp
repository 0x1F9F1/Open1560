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
    return stub<thiscall_t<i32, agiPipeline*>>(0x555540, this);
}

void agiPipeline::BeginFrame()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x555D10, this);
}

void agiPipeline::BeginScene()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x556000, this);
}

void agiPipeline::EndScene()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x556020, this);
}

void agiPipeline::EndFrame()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x556030, this);
}

class agiMtlDef* agiPipeline::CreateMtlDef()
{
    return stub<thiscall_t<class agiMtlDef*, agiPipeline*>>(0x555B10, this);
}

class agiLight* agiPipeline::CreateLight()
{
    return stub<thiscall_t<class agiLight*, agiPipeline*>>(0x555B20, this);
}

class agiLightModel* agiPipeline::CreateLightModel()
{
    return stub<thiscall_t<class agiLightModel*, agiPipeline*>>(0x555B30, this);
}

class agiBitmap* agiPipeline::CreateBitmap()
{
    return stub<thiscall_t<class agiBitmap*, agiPipeline*>>(0x555D30, this);
}

void agiPipeline::CopyBitmap(i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, agiPipeline*, i32, i32, class agiBitmap*, i32, i32, i32, i32>>(
        0x555D40, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void agiPipeline::ClearRect(i32 arg1, i32 arg2, i32 arg3, i32 arg4, u32 arg5)
{
    return stub<thiscall_t<void, agiPipeline*, i32, i32, i32, i32, u32>>(0x556070, this, arg1, arg2, arg3, arg4, arg5);
}

void agiPipeline::Defragment()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x556080, this);
}

i32 agiPipeline::LockFrameBuffer(class agiSurfaceDesc& arg1)
{
    return stub<thiscall_t<i32, agiPipeline*, class agiSurfaceDesc&>>(0x556040, this, arg1);
}

void agiPipeline::UnlockFrameBuffer()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x556050, this);
}

void agiPipeline::DumpStatus(struct agiMemStatus& arg1)
{
    return stub<thiscall_t<void, agiPipeline*, struct agiMemStatus&>>(0x556060, this, arg1);
}

i32 agiPipeline::BeginAllGfx()
{
    return stub<thiscall_t<i32, agiPipeline*>>(0x555B40, this);
}

i32 agiPipeline::CopyClippedBitmap(i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<i32, agiPipeline*, i32, i32, class agiBitmap*, i32, i32, i32, i32>>(
        0x555D50, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

i32 agiPipeline::CopyClippedBitmap(i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7,
    i32 arg8, i32 arg9, i32 arg10, i32 arg11)
{
    return stub<thiscall_t<i32, agiPipeline*, i32, i32, class agiBitmap*, i32, i32, i32, i32, i32, i32, i32, i32>>(
        0x555D90, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}

void agiPipeline::DumpStatus()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x555F00, this);
}

void agiPipeline::EndAllGfx()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x555C40, this);
}

class agiBitmap* agiPipeline::GetBitmap(char* arg1, f32 arg2, f32 arg3, i32 arg4)
{
    return stub<thiscall_t<class agiBitmap*, agiPipeline*, char*, f32, f32, i32>>(
        0x555750, this, arg1, arg2, arg3, arg4);
}

class DLP* agiPipeline::GetDLP(char* arg1, char* arg2, class Vector3* arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<class DLP*, agiPipeline*, char*, char*, class Vector3*, i32, i32>>(
        0x555950, this, arg1, arg2, arg3, arg4, arg5);
}

class agiMtlDef* agiPipeline::GetMaterial(char* arg1)
{
    return stub<thiscall_t<class agiMtlDef*, agiPipeline*, char*>>(0x555860, this, arg1);
}

class agiMtlDef* agiPipeline::GetMaterial(i32 arg1)
{
    return stub<thiscall_t<class agiMtlDef*, agiPipeline*, i32>>(0x5558C0, this, arg1);
}

class agiTexLut* agiPipeline::GetTexLut(char* arg1)
{
    return stub<thiscall_t<class agiTexLut*, agiPipeline*, char*>>(0x5557F0, this, arg1);
}

class agiTexDef* agiPipeline::GetTexture(char* arg1, i32 arg2)
{
    return stub<thiscall_t<class agiTexDef*, agiPipeline*, char*, i32>>(0x5555C0, this, arg1, arg2);
}

class agiTexDef* agiPipeline::GetTexture(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<class agiTexDef*, agiPipeline*, i32, i32>>(0x555620, this, arg1, arg2);
}

i32 agiPipeline::Init(char* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, void* arg8)
{
    return stub<thiscall_t<i32, agiPipeline*, char*, i32, i32, i32, i32, i32, i32, void*>>(
        0x555550, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

void agiPipeline::NotifyDelete(class agiRefreshable* arg1)
{
    return stub<thiscall_t<void, agiPipeline*, class agiRefreshable*>>(0x555E70, this, arg1);
}

void agiPipeline::NotifyNew(class agiRefreshable* arg1)
{
    return stub<thiscall_t<void, agiPipeline*, class agiRefreshable*>>(0x555E40, this, arg1);
}

void agiPipeline::RestoreAll()
{
    return stub<thiscall_t<void, agiPipeline*>>(0x555CD0, this);
}

void agiPipeline::ValidateObject(class agiRefreshable* arg1)
{
    return stub<thiscall_t<void, agiPipeline*, class agiRefreshable*>>(0x555EB0, this, arg1);
}

agiPipeline::agiPipeline()
{
    unimplemented();
}

void* CreatePipelineAttachableWindow(char* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, void* arg6)
{
    return stub<cdecl_t<void*, char*, i32, i32, i32, i32, void*>>(0x555F80, arg1, arg2, arg3, arg4, arg5, arg6);
}

void DestroyPipelineAttachableWindow()
{
    return stub<cdecl_t<void>>(0x555F90);
}

void* GetRootWindow()
{
    return stub<cdecl_t<void*>>(0x555F70);
}
