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

define_dummy_symbol(agid3d_ddpipe);

#include "ddpipe.h"

agiDDPipeline::agiDDPipeline()
{
    unimplemented();
}

agiDDPipeline::~agiDDPipeline()
{
    unimplemented(arg1);
}

void agiDDPipeline::BeginFrame()
{
    return stub<thiscall_t<void, agiDDPipeline*>>(0x132F40_Offset, this);
}

i32 agiDDPipeline::BeginGfx()
{
    return stub<thiscall_t<i32, agiDDPipeline*>>(0x132AE0_Offset, this);
}

void agiDDPipeline::BeginScene()
{
    return stub<thiscall_t<void, agiDDPipeline*>>(0x132FA0_Offset, this);
}

void agiDDPipeline::ClearRect(i32 arg1, i32 arg2, i32 arg3, i32 arg4, u32 arg5)
{
    return stub<thiscall_t<void, agiDDPipeline*, i32, i32, i32, i32, u32>>(
        0x133240_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void agiDDPipeline::CopyBitmap(i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, agiDDPipeline*, i32, i32, class agiBitmap*, i32, i32, i32, i32>>(
        0x133070_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

class agiBitmap* agiDDPipeline::CreateBitmap()
{
    return stub<thiscall_t<class agiBitmap*, agiDDPipeline*>>(0x133010_Offset, this);
}

void agiDDPipeline::EndFrame()
{
    return stub<thiscall_t<void, agiDDPipeline*>>(0x133000_Offset, this);
}

void agiDDPipeline::EndGfx()
{
    return stub<thiscall_t<void, agiDDPipeline*>>(0x132E30_Offset, this);
}

void agiDDPipeline::EndScene()
{
    return stub<thiscall_t<void, agiDDPipeline*>>(0x132FF0_Offset, this);
}

i32 agiDDPipeline::LockFrameBuffer(class agiSurfaceDesc& arg1)
{
    return stub<thiscall_t<i32, agiDDPipeline*, class agiSurfaceDesc&>>(0x1331E0_Offset, this, arg1);
}

void agiDDPipeline::UnlockFrameBuffer()
{
    return stub<thiscall_t<void, agiDDPipeline*>>(0x133220_Offset, this);
}

i32 agiDDPipeline::Validate()
{
    return stub<thiscall_t<i32, agiDDPipeline*>>(0x1328C0_Offset, this);
}

i32 __stdcall DDCallback(struct _GUID* arg1, char* arg2, char* arg3, void* arg4)
{
    return stub<stdcall_t<i32, struct _GUID*, char*, char*, void*>>(0x1328D0_Offset, arg1, arg2, arg3, arg4);
}

i32 __stdcall EnumModesCallback(struct _DDSURFACEDESC2* arg1, void* arg2)
{
    return stub<stdcall_t<i32, struct _DDSURFACEDESC2*, void*>>(0x132950_Offset, arg1, arg2);
}

i32 __stdcall EnumSurfsCallback(struct IDirectDrawSurface* arg1, struct _DDSURFACEDESC* arg2, void* arg3)
{
    return stub<stdcall_t<i32, struct IDirectDrawSurface*, struct _DDSURFACEDESC*, void*>>(
        0x132A00_Offset, arg1, arg2, arg3);
}
