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

#include "d3dpipe.h"

agiD3DPipeline::agiD3DPipeline()
{
    unimplemented();
}

agiD3DPipeline::~agiD3DPipeline()
{
    unimplemented();
}

void agiD3DPipeline::BeginFrame()
{
    return stub<thiscall_t<void, agiD3DPipeline*>>(0x130A40_Offset, this);
}

i32 agiD3DPipeline::BeginGfx()
{
    return stub<thiscall_t<i32, agiD3DPipeline*>>(0x12FB90_Offset, this);
}

void agiD3DPipeline::BeginScene()
{
    return stub<thiscall_t<void, agiD3DPipeline*>>(0x130AF0_Offset, this);
}

void agiD3DPipeline::ClearAll(i32 arg1)
{
    return stub<thiscall_t<void, agiD3DPipeline*, i32>>(0x131400_Offset, this, arg1);
}

void agiD3DPipeline::CopyBitmap(i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, agiD3DPipeline*, i32, i32, class agiBitmap*, i32, i32, i32, i32>>(
        0x131520_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

class agiBitmap* agiD3DPipeline::CreateBitmap()
{
    return stub<thiscall_t<class agiBitmap*, agiD3DPipeline*>>(0x1314C0_Offset, this);
}

class agiLight* agiD3DPipeline::CreateLight()
{
    return stub<thiscall_t<class agiLight*, agiD3DPipeline*>>(0x1313A0_Offset, this);
}

class agiMtlDef* agiD3DPipeline::CreateMtlDef()
{
    return stub<thiscall_t<class agiMtlDef*, agiD3DPipeline*>>(0x131250_Offset, this);
}

class agiTexDef* agiD3DPipeline::CreateTexDef()
{
    return stub<thiscall_t<class agiTexDef*, agiD3DPipeline*>>(0x1312B0_Offset, this);
}

class agiTexLut* agiD3DPipeline::CreateTexLut()
{
    return stub<thiscall_t<class agiTexLut*, agiD3DPipeline*>>(0x131310_Offset, this);
}

class agiViewport* agiD3DPipeline::CreateViewport()
{
    return stub<thiscall_t<class agiViewport*, agiD3DPipeline*>>(0x1311F0_Offset, this);
}

void agiD3DPipeline::Defragment()
{
    return stub<thiscall_t<void, agiD3DPipeline*>>(0x131580_Offset, this);
}

void agiD3DPipeline::DumpStatus(struct agiMemStatus& arg1)
{
    return stub<thiscall_t<void, agiD3DPipeline*, struct agiMemStatus&>>(0x130FE0_Offset, this, arg1);
}

void agiD3DPipeline::EndFrame()
{
    return stub<thiscall_t<void, agiD3DPipeline*>>(0x130BD0_Offset, this);
}

void agiD3DPipeline::EndGfx()
{
    return stub<thiscall_t<void, agiD3DPipeline*>>(0x131100_Offset, this);
}

void agiD3DPipeline::EndScene()
{
    return stub<thiscall_t<void, agiD3DPipeline*>>(0x130B60_Offset, this);
}

i32 __stdcall RestoreCallback(struct IDirectDrawSurface4* arg1, struct _DDSURFACEDESC2* arg2, void* arg3)
{
    return stub<stdcall_t<i32, struct IDirectDrawSurface4*, struct _DDSURFACEDESC2*, void*>>(
        0x130A20_Offset, arg1, arg2, arg3);
}

i32 __stdcall callb(struct IDirectDrawSurface4* arg1, struct _DDSURFACEDESC2* arg2, void* arg3)
{
    return stub<stdcall_t<i32, struct IDirectDrawSurface4*, struct _DDSURFACEDESC2*, void*>>(
        0x130D30_Offset, arg1, arg2, arg3);
}

agiD3DTexLut::~agiD3DTexLut()
{
    unimplemented();
}

i32 agiD3DTexLut::BeginGfx()
{
    return stub<thiscall_t<i32, agiD3DTexLut*>>(0x131FD0_Offset, this);
}

void agiD3DTexLut::EndGfx()
{
    return stub<thiscall_t<void, agiD3DTexLut*>>(0x132020_Offset, this);
}

define_dummy_symbol(agid3d_d3dpipe);
