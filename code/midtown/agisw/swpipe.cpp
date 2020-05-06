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
    return stub<thiscall_t<void, agiSWPipeline*>>(0x534030, this);
}

i32 agiSWPipeline::BeginGfx()
{
    return stub<thiscall_t<i32, agiSWPipeline*>>(0x533E60, this);
}

void agiSWPipeline::BeginScene()
{
    return stub<thiscall_t<void, agiSWPipeline*>>(0x534070, this);
}

void agiSWPipeline::ClearAll(i32 arg1)
{
    return stub<thiscall_t<void, agiSWPipeline*, i32>>(0x5341A0, this, arg1);
}

void agiSWPipeline::ClearRect(i32 arg1, i32 arg2, i32 arg3, i32 arg4, u32 arg5)
{
    return stub<thiscall_t<void, agiSWPipeline*, i32, i32, i32, i32, u32>>(
        0x534230, this, arg1, arg2, arg3, arg4, arg5);
}

void agiSWPipeline::CopyBitmap(i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, agiSWPipeline*, i32, i32, class agiBitmap*, i32, i32, i32, i32>>(
        0x5344C0, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

class agiBitmap* agiSWPipeline::CreateBitmap()
{
    return stub<thiscall_t<class agiBitmap*, agiSWPipeline*>>(0x534450, this);
}

class DLP* agiSWPipeline::CreateDLP()
{
    return stub<thiscall_t<class DLP*, agiSWPipeline*>>(0x5340E0, this);
}

class agiLight* agiSWPipeline::CreateLight()
{
    return stub<thiscall_t<class agiLight*, agiSWPipeline*>>(0x534140, this);
}

class agiLightModel* agiSWPipeline::CreateLightModel()
{
    return stub<thiscall_t<class agiLightModel*, agiSWPipeline*>>(0x534320, this);
}

class agiMtlDef* agiSWPipeline::CreateMtlDef()
{
    return stub<thiscall_t<class agiMtlDef*, agiSWPipeline*>>(0x534440, this);
}

class agiTexDef* agiSWPipeline::CreateTexDef()
{
    return stub<thiscall_t<class agiTexDef*, agiSWPipeline*>>(0x534380, this);
}

class agiTexLut* agiSWPipeline::CreateTexLut()
{
    return stub<thiscall_t<class agiTexLut*, agiSWPipeline*>>(0x5343E0, this);
}

class agiViewport* agiSWPipeline::CreateViewport()
{
    return stub<thiscall_t<class agiViewport*, agiSWPipeline*>>(0x534290, this);
}

void agiSWPipeline::EndFrame()
{
    return stub<thiscall_t<void, agiSWPipeline*>>(0x5340C0, this);
}

void agiSWPipeline::EndGfx()
{
    return stub<thiscall_t<void, agiSWPipeline*>>(0x534010, this);
}

void agiSWPipeline::EndScene()
{
    return stub<thiscall_t<void, agiSWPipeline*>>(0x5340A0, this);
}

i32 agiSWPipeline::Validate()
{
    return stub<thiscall_t<i32, agiSWPipeline*>>(0x533DC0, this);
}

class agiPipeline* swCreatePipeline(i32 arg1, char** arg2)
{
    return stub<cdecl_t<class agiPipeline*, i32, char**>>(0x534690, arg1, arg2);
}

agiSWViewport::~agiSWViewport()
{
    unimplemented(arg1);
}

void agiSWViewport::Activate()
{
    return stub<thiscall_t<void, agiSWViewport*>>(0x534930, this);
}

i32 agiSWViewport::BeginGfx()
{
    return stub<thiscall_t<i32, agiSWViewport*>>(0x534BC0, this);
}

void agiSWViewport::Clear(i32 arg1)
{
    return stub<thiscall_t<void, agiSWViewport*, i32>>(0x5349B0, this, arg1);
}

void agiSWViewport::EndGfx()
{
    return stub<thiscall_t<void, agiSWViewport*>>(0x534BD0, this);
}

void agiSWViewport::SetBackground(class Vector3& arg1)
{
    return stub<thiscall_t<void, agiSWViewport*, class Vector3&>>(0x534950, this, arg1);
}

agiSWBitmap::~agiSWBitmap()
{
    unimplemented(arg1);
}

i32 agiSWBitmap::BeginGfx()
{
    return stub<thiscall_t<i32, agiSWBitmap*>>(0x534C20, this);
}

void agiSWBitmap::EndGfx()
{
    return stub<thiscall_t<void, agiSWBitmap*>>(0x534DC0, this);
}

void agiSWBitmap::Restore()
{
    return stub<thiscall_t<void, agiSWBitmap*>>(0x534DE0, this);
}

void agiSWBitmap::UpdateFlags()
{
    return stub<thiscall_t<void, agiSWBitmap*>>(0x534DA0, this);
}
