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
#include "sim.h"

static mem::cmd_param PARAM_fovfix {"fovfix"};

void asCamera::SetView(f32 horz_fov, f32 aspect, f32 near_clip, f32 far_clip)
{
    // Aspect is supposed to represent the intended aspect ratio for the provided horizontal FOV
    // However, if it is ever set to 0, it will always be ignored from then on (this is the case in-game)
    // This means the value is basically useless, so instead assume it was intended for a 4:3 display
    // This preserves intended vertical FOV on wider screens, including in the dash view
    //
    // TODO: Store the vertical fov instead, and handle this in asCamera::Update
    // https://forum.unity.com/threads/adjust-fov-based-on-aspect-ratio-how.474627/#post-3097919
    if (PARAM_fovfix.get_or(true))
    {
        // Calculate the horizontal tangent
        f32 horz_tan = std::tan(horz_fov * 0.5f);

        aspect = 640.0f / 480.0f;

        // Calculate the vertical tangent, based on the intended (4:3) aspect ratio
        f32 vert_tan = horz_tan / aspect;

        // Now calculate the actual aspect ratio
        aspect = static_cast<f32>(Pipe()->GetWidth()) / static_cast<f32>(Pipe()->GetHeight());

        // Calculate the horizontal FOV, based on the actual aspect ratio
        horz_fov = 2.0f * std::atan(vert_tan * aspect);

        // Use auto aspect
        aspect = 0.0f;
    }

    fov_ = horz_fov;
    near_clip_ = near_clip;
    far_clip_ = far_clip;

    if (aspect == 0.0f)
    {
        auto_aspect_ = true;
        aspect_ = 1.0f;
    }
    else
    {
        // auto_aspect_ = false;
        aspect_ = aspect;
    }
}

void asCamera::DrawBegin()
{
    i32 draw_mode = ARTSPTR->GetDrawMode();

    if (draw_mode == agiDrawTextured)
        draw_mode = draw_mode_;

    agiCurState.SetDrawMode(static_cast<agiDrawMode>(draw_mode));

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

    if (draw_mode < agiDrawSolid
#ifdef ARTS_DEV_BUILD
        || ARTSPTR->IsDebugDrawEnabled()
#endif
    )
    {
        clear_flags |= AGI_VIEW_CLEAR_TARGET;
    }

    if (underlay_bitmap_ && !underlay_callback_ && agiCurState.GetDrawMode() != agiDrawDepth)
    {
        clear_flags &= ~AGI_VIEW_CLEAR_TARGET;
    }

    viewport_->Clear(clear_flags);

    if (light_model_)
        light_model_->Activate();
}
