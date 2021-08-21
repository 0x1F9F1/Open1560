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

#include "glview.h"

#include "agi/error.h"
#include "agi/pipeline.h"
#include "agi/rsys.h"
#include "data7/utimer.h"

#include "glcontext.h"
#include "glrsys.h"

#include <glad/glad.h>

void agiGLViewport::EndGfx()
{
    state_ = 0;
}

i32 agiGLViewport::BeginGfx()
{
    if (Pipe()->HaveGfxStarted())
    {
        if (state_)
            return AGI_ERROR_ALREADY_INITIALIZED;

        state_ = 1;
    }

    return AGI_ERROR_SUCCESS;
}

void agiGLViewport::Activate()
{
    if (state_ == 0)
    {
        if (BeginGfx() != AGI_ERROR_SUCCESS)
            return;
    }

    ++agiViewParameters::ViewSerial;
    ++agiViewParameters::MtxSerial;

    agiViewport::Active = this;
}

void agiGLViewport::SetBackground(Vector3& color)
{
    clear_color_ = color;
}

void agiGLViewport::Clear(i32 flags)
{
    ARTS_UTIMED(agiClearViewport);

    GLbitfield mask = 0;

    if (flags & AGI_VIEW_CLEAR_ZBUFFER)
    {
        mask |= GL_DEPTH_BUFFER_BIT;

        agiCurState.SetZWrite(true);
        agiGL->DepthMask(true);
    }

    if (flags & AGI_VIEW_CLEAR_TARGET)
    {
        mask |= GL_COLOR_BUFFER_BIT;

        glClearColor(clear_color_.x, clear_color_.y, clear_color_.z, 1.0f);
    }

    if (mask)
    {
        i32 pipe_width = Pipe()->GetWidth();
        i32 pipe_height = Pipe()->GetHeight();

        i32 x = static_cast<i32>(std::round(pipe_width * params_.X));
        i32 y = static_cast<i32>(std::round(pipe_height * params_.Y));
        i32 w = static_cast<i32>(std::round(pipe_width * (params_.X + params_.Width))) - x;
        i32 h = static_cast<i32>(std::round(pipe_height * (params_.Y + params_.Height))) - y;

        i32 render_width = Pipe()->GetRenderWidth();
        i32 render_height = Pipe()->GetRenderHeight();

        // Scale by output size after rounding to match renderer calculations
        x = (x * render_width) / pipe_width;
        y = (y * render_height) / pipe_height;
        w = (w * render_width) / pipe_width;
        h = (h * render_height) / pipe_height;

        x += Pipe()->GetRenderX();
        y += Pipe()->GetRenderY();

        agiGL->EnableDisable(GL_SCISSOR_TEST, true);

        glScissor(x, y, w, h);
        glClear(mask);

        agiGL->EnableDisable(GL_SCISSOR_TEST, false);
    }
}
