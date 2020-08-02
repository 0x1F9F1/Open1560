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

#include "agi/pipeline.h"

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
