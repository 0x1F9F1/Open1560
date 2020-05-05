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

define_dummy_symbol(agisw_swpipe);

#include "swpipe.h"

agiSWPipeline::agiSWPipeline(i32 arg1, char** arg2)
{
    unimplemented(arg1, arg2);
}

agiSWPipeline::~agiSWPipeline()
{
    unimplemented(arg1);
}

void agiSWPipeline::BeginFrame()
{
    return stub<thiscall_t<void, agiSWPipeline*>>(0x134030_Offset, this);
}

i32 agiSWPipeline::BeginGfx()
{
    return stub<thiscall_t<i32, agiSWPipeline*>>(0x133E60_Offset, this);
}

void agiSWPipeline::BeginScene()
{
    return stub<thiscall_t<void, agiSWPipeline*>>(0x134070_Offset, this);
}

void agiSWPipeline::ClearAll(i32 arg1)
{
    return stub<thiscall_t<void, agiSWPipeline*, i32>>(0x1341A0_Offset, this, arg1);
}

void agiSWPipeline::ClearRect(i32 arg1, i32 arg2, i32 arg3, i32 arg4, u32 arg5)
{
    return stub<thiscall_t<void, agiSWPipeline*, i32, i32, i32, i32, u32>>(
        0x134230_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void agiSWPipeline::CopyBitmap(i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, agiSWPipeline*, i32, i32, class agiBitmap*, i32, i32, i32, i32>>(
        0x1344C0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

class agiBitmap* agiSWPipeline::CreateBitmap()
{
    return stub<thiscall_t<class agiBitmap*, agiSWPipeline*>>(0x134450_Offset, this);
}

class DLP* agiSWPipeline::CreateDLP()
{
    return stub<thiscall_t<class DLP*, agiSWPipeline*>>(0x1340E0_Offset, this);
}

class agiLight* agiSWPipeline::CreateLight()
{
    return stub<thiscall_t<class agiLight*, agiSWPipeline*>>(0x134140_Offset, this);
}

class agiLightModel* agiSWPipeline::CreateLightModel()
{
    return stub<thiscall_t<class agiLightModel*, agiSWPipeline*>>(0x134320_Offset, this);
}

class agiMtlDef* agiSWPipeline::CreateMtlDef()
{
    return stub<thiscall_t<class agiMtlDef*, agiSWPipeline*>>(0x134440_Offset, this);
}

class agiTexDef* agiSWPipeline::CreateTexDef()
{
    return stub<thiscall_t<class agiTexDef*, agiSWPipeline*>>(0x134380_Offset, this);
}

class agiTexLut* agiSWPipeline::CreateTexLut()
{
    return stub<thiscall_t<class agiTexLut*, agiSWPipeline*>>(0x1343E0_Offset, this);
}

class agiViewport* agiSWPipeline::CreateViewport()
{
    return stub<thiscall_t<class agiViewport*, agiSWPipeline*>>(0x134290_Offset, this);
}

void agiSWPipeline::EndFrame()
{
    return stub<thiscall_t<void, agiSWPipeline*>>(0x1340C0_Offset, this);
}

void agiSWPipeline::EndGfx()
{
    return stub<thiscall_t<void, agiSWPipeline*>>(0x134010_Offset, this);
}

void agiSWPipeline::EndScene()
{
    return stub<thiscall_t<void, agiSWPipeline*>>(0x1340A0_Offset, this);
}

i32 agiSWPipeline::Validate()
{
    return stub<thiscall_t<i32, agiSWPipeline*>>(0x133DC0_Offset, this);
}

class agiPipeline* swCreatePipeline(i32 arg1, char** arg2)
{
    return stub<cdecl_t<class agiPipeline*, i32, char**>>(0x134690_Offset, arg1, arg2);
}

agiSWViewport::~agiSWViewport()
{
    unimplemented(arg1);
}

void agiSWViewport::Activate()
{
    return stub<thiscall_t<void, agiSWViewport*>>(0x134930_Offset, this);
}

i32 agiSWViewport::BeginGfx()
{
    return stub<thiscall_t<i32, agiSWViewport*>>(0x134BC0_Offset, this);
}

void agiSWViewport::Clear(i32 arg1)
{
    return stub<thiscall_t<void, agiSWViewport*, i32>>(0x1349B0_Offset, this, arg1);
}

void agiSWViewport::EndGfx()
{
    return stub<thiscall_t<void, agiSWViewport*>>(0x134BD0_Offset, this);
}

void agiSWViewport::SetBackground(class Vector3& arg1)
{
    return stub<thiscall_t<void, agiSWViewport*, class Vector3&>>(0x134950_Offset, this, arg1);
}

agiSWBitmap::~agiSWBitmap()
{
    unimplemented(arg1);
}

i32 agiSWBitmap::BeginGfx()
{
    return stub<thiscall_t<i32, agiSWBitmap*>>(0x134C20_Offset, this);
}

void agiSWBitmap::EndGfx()
{
    return stub<thiscall_t<void, agiSWBitmap*>>(0x134DC0_Offset, this);
}

void agiSWBitmap::Restore()
{
    return stub<thiscall_t<void, agiSWBitmap*>>(0x134DE0_Offset, this);
}

void agiSWBitmap::UpdateFlags()
{
    return stub<thiscall_t<void, agiSWBitmap*>>(0x134DA0_Offset, this);
}
