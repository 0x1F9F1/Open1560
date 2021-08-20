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

define_dummy_symbol(agid3d_d3dlight);

#include "d3dlight.h"

#include "agi/error.h"
#include "dderror.h"

agiD3DLight::agiD3DLight(agiPipeline* pipe)
    : agiLight(pipe)
{
    ++LightCount;
}

agiD3DLight::~agiD3DLight()
{
    EndGfx();

    --LightCount;
}

i32 agiD3DLight::BeginGfx()
{
    if (Pipe()->HaveGfxStarted())
        return AGI_ERROR_SUCCESS;

    if (state_ != 0)
        return AGI_ERROR_ALREADY_INITIALIZED;

    DD_TRY(Pipe()->GetD3D()->CreateLight(&d_light_, nullptr));
    DD_TRY(Pipe()->GetD3DView()->AddLight(d_light_));

    return Update();
}

void agiD3DLight::EndGfx()
{
    if (d_light_)
    {
        DD_TRY(Pipe()->GetD3DView()->DeleteLight(d_light_));

        SafeRelease(d_light_);
    }
}

i32 agiD3DLight::Update()
{
    if (d_light_ && Params.Touched)
    {
        D3DLIGHT lp {sizeof(lp)};

        lp.dltType = D3DLIGHT_POINT;

        lp.dcvColor.r = Params.Diffuse.x;
        lp.dcvColor.g = Params.Diffuse.y;
        lp.dcvColor.b = Params.Diffuse.z;
        lp.dcvColor.a = Params.Alpha;

        lp.dvPosition.x = Params.Position.x;
        lp.dvPosition.y = Params.Position.y;
        lp.dvPosition.z = Params.Position.z;

        lp.dvDirection.x = Params.Direction.x;
        lp.dvDirection.y = Params.Direction.y;
        lp.dvDirection.z = Params.Direction.z;

        lp.dvRange = 8192.0f;

        DD_TRY(d_light_->SetLight(&lp));

        Params.Touched = false;
    }

    return AGI_ERROR_SUCCESS;
}
