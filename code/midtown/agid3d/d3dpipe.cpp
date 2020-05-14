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

define_dummy_symbol(agid3d_d3dpipe);

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
    return stub<thiscall_t<void, agiD3DPipeline*>>(0x530A40, this);
}

i32 agiD3DPipeline::BeginGfx()
{
    return stub<thiscall_t<i32, agiD3DPipeline*>>(0x52FB90, this);
}

void agiD3DPipeline::BeginScene()
{
    return stub<thiscall_t<void, agiD3DPipeline*>>(0x530AF0, this);
}

void agiD3DPipeline::ClearAll(i32 arg1)
{
    return stub<thiscall_t<void, agiD3DPipeline*, i32>>(0x531400, this, arg1);
}

void agiD3DPipeline::CopyBitmap(i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, agiD3DPipeline*, i32, i32, class agiBitmap*, i32, i32, i32, i32>>(
        0x531520, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

class agiBitmap* agiD3DPipeline::CreateBitmap()
{
    return stub<thiscall_t<class agiBitmap*, agiD3DPipeline*>>(0x5314C0, this);
}

class agiLight* agiD3DPipeline::CreateLight()
{
    return stub<thiscall_t<class agiLight*, agiD3DPipeline*>>(0x5313A0, this);
}

class agiMtlDef* agiD3DPipeline::CreateMtlDef()
{
    return stub<thiscall_t<class agiMtlDef*, agiD3DPipeline*>>(0x531250, this);
}

class agiTexDef* agiD3DPipeline::CreateTexDef()
{
    return stub<thiscall_t<class agiTexDef*, agiD3DPipeline*>>(0x5312B0, this);
}

class agiTexLut* agiD3DPipeline::CreateTexLut()
{
    return stub<thiscall_t<class agiTexLut*, agiD3DPipeline*>>(0x531310, this);
}

class agiViewport* agiD3DPipeline::CreateViewport()
{
    return stub<thiscall_t<class agiViewport*, agiD3DPipeline*>>(0x5311F0, this);
}

void agiD3DPipeline::Defragment()
{
    return stub<thiscall_t<void, agiD3DPipeline*>>(0x531580, this);
}

void agiD3DPipeline::DumpStatus(struct agiMemStatus& arg1)
{
    return stub<thiscall_t<void, agiD3DPipeline*, struct agiMemStatus&>>(0x530FE0, this, arg1);
}

void agiD3DPipeline::EndFrame()
{
    return stub<thiscall_t<void, agiD3DPipeline*>>(0x530BD0, this);
}

void agiD3DPipeline::EndGfx()
{
    return stub<thiscall_t<void, agiD3DPipeline*>>(0x531100, this);
}

void agiD3DPipeline::EndScene()
{
    return stub<thiscall_t<void, agiD3DPipeline*>>(0x530B60, this);
}

i32 __stdcall RestoreCallback(struct IDirectDrawSurface4* arg1, struct _DDSURFACEDESC2* arg2, void* arg3)
{
    return stub<stdcall_t<i32, struct IDirectDrawSurface4*, struct _DDSURFACEDESC2*, void*>>(
        0x530A20, arg1, arg2, arg3);
}

i32 __stdcall callb(struct IDirectDrawSurface4* arg1, struct _DDSURFACEDESC2* arg2, void* arg3)
{
    return stub<stdcall_t<i32, struct IDirectDrawSurface4*, struct _DDSURFACEDESC2*, void*>>(
        0x530D30, arg1, arg2, arg3);
}

static i32 __stdcall EnumCallback(
    struct _GUID* arg1, char* arg2, char* arg3, struct _D3DDeviceDesc* arg4, struct _D3DDeviceDesc* arg5, void* arg6)
{
    return stub<stdcall_t<i32, struct _GUID*, char*, char*, struct _D3DDeviceDesc*, struct _D3DDeviceDesc*, void*>>(
        0x5307B0, arg1, arg2, arg3, arg4, arg5, arg6);
}

static i32 __stdcall EnumTextureCallback(struct _DDPIXELFORMAT* arg1, void* arg2)
{
    return stub<stdcall_t<i32, struct _DDPIXELFORMAT*, void*>>(0x5308B0, arg1, arg2);
}

agiD3DTexLut::~agiD3DTexLut()
{
    unimplemented();
}

i32 agiD3DTexLut::BeginGfx()
{
    return stub<thiscall_t<i32, agiD3DTexLut*>>(0x531FD0, this);
}

void agiD3DTexLut::EndGfx()
{
    return stub<thiscall_t<void, agiD3DTexLut*>>(0x532020, this);
}
