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

define_dummy_symbol(arts7_camera);

#include "camera.h"

#include "agi/bitmap.h"
#include "agi/lmodel.h"
#include "agi/pipeline.h"
#include "agi/rsys.h"
#include "agi/viewport.h"
#include "arts7/sim.h"

static mem::cmd_param PARAM_fovfix {"fovfix"};

void asCamera::SetView(f32 horz_fov, f32 vert_fov, f32 near_clip, f32 far_clip)
{
    if (PARAM_fovfix.get_or(true))
    {
        f32 fov_scale = (Pipe()->GetWidth() * x_size_) / (Pipe()->GetHeight() * y_size_);

        if (vert_fov == 1.25f)
        {
            horz_fov *= fov_scale * 0.75f;
        }
    }

    fov_ = horz_fov;
    auto_aspect_ = true;
    near_clip_ = near_clip;
    far_clip_ = far_clip;
}

void asCamera::DrawBegin()
{
    i32 draw_mode = ARTSPTR->GetDrawMode();

    if (draw_mode == 15)
        draw_mode = draw_mode_;

    agiCurState.SetDrawMode(static_cast<u8>(draw_mode));

    if (fog_density_ != 0.0f)
    {
        agiCurState.SetFogMode(agiFogMode::Pixel);
        agiCurState.SetFogStart(fog_start_);
        agiCurState.SetFogEnd(fog_end_);
        agiCurState.SetFogDensity(fog_density_);
        agiCurState.SetFogColor((static_cast<u32>(fog_color_.x * 255.0) << 16) |
            (static_cast<u32>(fog_color_.y * 255.0) << 8) | static_cast<u32>(fog_color_.z * 255.0));
    }
    else
    {
        agiCurState.SetFogMode(agiFogMode::None);
    }

    viewport_->Activate();

    if (underlay_bitmap_)
    {
        if (underlay_callback_)
        {
            underlay_callback_->Call();
        }
        else
        {
            Pipe()->CopyBitmap(
                UI_XPos, UI_YPos, underlay_bitmap_, 0, 0, underlay_bitmap_->GetWidth(), underlay_bitmap_->GetHeight());
        }

        if (!underlay_bitmap_->Is3D())
            Pipe()->BeginScene();
    }

    i32 clear_flags = clear_flags_;

    if (draw_mode < 11 || ARTSPTR->IsDebugDrawEnabled())
        clear_flags |= AGI_VIEW_CLEAR_TARGET;

    if (underlay_bitmap_ && !underlay_callback_ && agiCurState.GetDrawMode() != 3)
        clear_flags &= ~AGI_VIEW_CLEAR_TARGET;

    viewport_->Clear(clear_flags);

    if (light_model_)
        light_model_->Activate();
}
