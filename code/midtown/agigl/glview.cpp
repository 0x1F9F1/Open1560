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
#include "glerror.h"
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
        i32 x = Pipe()->GetRenderX();
        i32 y = Pipe()->GetRenderY();

        i32 width = Pipe()->GetRenderWidth();
        i32 height = Pipe()->GetRenderHeight();

        agiGL->EnableDisable(GL_SCISSOR_TEST, true);

        glScissor(x + static_cast<GLint>(width * params_.X), y + static_cast<GLint>(height * params_.Y),
            static_cast<GLsizei>(std::ceil(width * params_.Width)),
            static_cast<GLsizei>(std::ceil(height * params_.Height)));

        glClear(mask);

        agiGL->EnableDisable(GL_SCISSOR_TEST, false);
    }
}
