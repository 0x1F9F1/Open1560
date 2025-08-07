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

#include "sdlpipe.h"

#include "agi/error.h"
#include "pcwindis/dxinit.h"
#include "pcwindis/setupdata.h"

#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_video.h>

static mem::cmd_param PARAM_border {"border"};
static mem::cmd_param PARAM_scaling {"scaling"};

i32 agiSDLPipeline::BeginGfx()
{
    dxiRendererInfo_t& info = GetRendererInfo();

    if (dxiIsFullScreen())
    {
        SDL_Rect rect {};

        if (!SDL_GetDisplayBounds(info.SDL.DisplayID, &rect))
        {
            Errorf("Failed to get display bounds for display %u: %s", info.SDL.DisplayID, SDL_GetError());
            return AGI_ERROR_NO_DEVICE;
        }

        SDL_SetWindowPosition(window_, rect.x, rect.y);
        SDL_SetWindowFullscreen(window_, true);
    }
    else
    {
        SDL_SetWindowFullscreen(window_, false);
        SDL_SetWindowBordered(window_, PARAM_border.get_or(true));
        SDL_SetWindowSize(window_, width_, height_);
        SDL_SetWindowPosition(window_, SDL_WINDOWPOS_CENTERED_DISPLAY(info.SDL.DisplayID),
            SDL_WINDOWPOS_CENTERED_DISPLAY(info.SDL.DisplayID));
    }

    return 0;
}

void agiSDLPipeline::InitScaling()
{
    switch (i32 scaling_mode = PARAM_scaling.get_or(0))
    {
        case 0: // Stretched, Keep Aspect
        case 1: // Stretched
        {
            blit_width_ = horz_res_;
            blit_height_ = vert_res_;

            if (scaling_mode == 0)
            {
                i32 w_factor = width_ * blit_height_;
                i32 h_factor = height_ * blit_width_;

                // Avoid stretching when there is only a small difference
                if (std::abs(w_factor - h_factor) > (height_ * blit_height_) / 100)
                {
                    if (w_factor < h_factor)
                        blit_width_ = w_factor / height_;
                    else
                        blit_height_ = h_factor / width_;
                }
            }

            break;
        }

        case 2: // Centered
        case 3: // Centered, Integer Scaled
        {
            i32 scale = 1;

            if (scaling_mode == 3)
            {
                scale = std::max(1, std::min(horz_res_ / width_, vert_res_ / height_));
            }

            blit_width_ = width_ * scale;
            blit_height_ = height_ * scale;

            break;
        }
    }

    blit_x_ = (horz_res_ - blit_width_) / 2;
    blit_y_ = (vert_res_ - blit_height_) / 2;
}
