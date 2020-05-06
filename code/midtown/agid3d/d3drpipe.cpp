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

define_dummy_symbol(agid3d_d3drpipe);

#include "d3drpipe.h"

agiD3DRPipeline::agiD3DRPipeline()
{
    unimplemented();
}

agiD3DRPipeline::~agiD3DRPipeline()
{
    unimplemented(arg1);
}

i32 agiD3DRPipeline::BeginGfx()
{
    return stub<thiscall_t<i32, agiD3DRPipeline*>>(0x531630, this);
}

void agiD3DRPipeline::BeginScene()
{
    return stub<thiscall_t<void, agiD3DRPipeline*>>(0x5317F0, this);
}

class DLP* agiD3DRPipeline::CreateDLP()
{
    return stub<thiscall_t<class DLP*, agiD3DRPipeline*>>(0x531790, this);
}

class agiLight* agiD3DRPipeline::CreateLight()
{
    return stub<thiscall_t<class agiLight*, agiD3DRPipeline*>>(0x531910, this);
}

class agiLightModel* agiD3DRPipeline::CreateLightModel()
{
    return stub<thiscall_t<class agiLightModel*, agiD3DRPipeline*>>(0x5318B0, this);
}

class agiViewport* agiD3DRPipeline::CreateViewport()
{
    return stub<thiscall_t<class agiViewport*, agiD3DRPipeline*>>(0x531730, this);
}

void agiD3DRPipeline::EndGfx()
{
    return stub<thiscall_t<void, agiD3DRPipeline*>>(0x531700, this);
}

void agiD3DRPipeline::EndScene()
{
    return stub<thiscall_t<void, agiD3DRPipeline*>>(0x531890, this);
}
