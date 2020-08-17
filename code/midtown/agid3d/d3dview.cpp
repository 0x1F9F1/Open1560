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

define_dummy_symbol(agid3d_d3dview);

#include "d3dview.h"

#include "agi/error.h"
#include "agi/pipeline.h"
#include "data7/utimer.h"
#include "dderror.h"

#include <d3d.h>

void agiD3DViewport::Activate()
{
    if (state_ == 0)
    {
        if (BeginGfx() != AGI_ERROR_SUCCESS)
            return;
    }

    ++agiViewParameters::ViewSerial;
    ++agiViewParameters::MtxSerial;

    D3DVIEWPORT vp {sizeof(vp)};

    vp.dwX = 0;
    vp.dwY = 0;
    vp.dwWidth = Pipe()->GetWidth();
    vp.dwHeight = Pipe()->GetHeight();
    vp.dvScaleX = vp.dwWidth * 0.5f;
    vp.dvScaleY = vp.dwHeight * 0.5f;
    vp.dvMaxX = 1.0f;
    vp.dvMaxY = 1.0f;
    vp.dvMinZ = 0.0f;
    vp.dvMaxZ = 1.0f;

    DD_TRY(Pipe()->GetD3DView()->SetViewport(&vp));

    agiViewport::Active = this;
}

i32 agiD3DViewport::BeginGfx()
{
    if (Pipe()->HaveGfxStarted())
    {
        if (state_)
            return AGI_ERROR_ALREADY_INITIALIZED;

        state_ = 1;
    }

    return AGI_ERROR_SUCCESS;
}

void agiD3DViewport::Clear(i32 flags)
{
    ARTS_TIMED(agiClearViewport);

    i32 width = Pipe()->GetWidth();
    i32 height = Pipe()->GetHeight();

    f32 bottom = 1.0f - params_.Y;

    D3DRECT rect {};
    rect.x1 = static_cast<LONG>(width * params_.X);
    rect.y2 = static_cast<LONG>(height * (bottom - params_.Height));
    rect.x2 = static_cast<LONG>(width * (params_.X + params_.Width));
    rect.y2 = static_cast<LONG>(height * bottom);

    if (!agiEnableZBuffer)
        flags &= ~D3DCLEAR_ZBUFFER;

    if (flags)
    {
        DD_TRY(Pipe()->GetD3DView()->Clear2(1, &rect, flags, clear_color_, 1.0f, 0));
    }
}

void agiD3DViewport::EndGfx()
{
    state_ = 0;
}

void agiD3DViewport::SetBackground(Vector3& color)
{
    clear_color_ = (static_cast<u8>(color.x * 255.0f) << 16) | (static_cast<u8>(color.y * 255.0f) << 8) |
        static_cast<u8>(color.z * 255.0f);
}
