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

#include "pcwindis/dxinit.h"
#include "pcwindis/setupdata.h"

#include <SDL_video.h>

static mem::cmd_param PARAM_border {"border"};
static mem::cmd_param PARAM_scaling {"scaling"};

i32 agiSDLPipeline::BeginGfx()
{
    dxiRendererInfo_t& info = GetRendererInfo();

    if (dxiIsFullScreen())
    {
        if (info.SDL.Index != SDL_GetWindowDisplayIndex(window_))
        {
            // Cannot move/resize window when fullscreen
            SDL_SetWindowFullscreen(window_, 0);
            SDL_SetWindowPosition(window_, SDL_WINDOWPOS_CENTERED_DISPLAY(info.SDL.Index),
                SDL_WINDOWPOS_CENTERED_DISPLAY(info.SDL.Index));
        }

        SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN_DESKTOP);
    }
    else
    {
        SDL_SetWindowFullscreen(window_, 0);
        SDL_SetWindowBordered(window_, PARAM_border.get_or(true) ? SDL_TRUE : SDL_FALSE);
        SDL_SetWindowSize(window_, width_, height_);
        SDL_SetWindowPosition(
            window_, SDL_WINDOWPOS_CENTERED_DISPLAY(info.SDL.Index), SDL_WINDOWPOS_CENTERED_DISPLAY(info.SDL.Index));
    }

    return 0;
}

void agiSDLPipeline::InitScaling()
{
    dxiWidth = horz_res_;
    dxiHeight = vert_res_;
    dxiDepth = bit_depth_;

    switch (i32 scaling_mode = PARAM_scaling.get_or(0))
    {
        case 0: // Stretched, Keep Aspect
        case 1: // Stretched
        {
            blit_width_ = horz_res_;
            blit_height_ = vert_res_;

            if (scaling_mode == 0)
            {
                f32 game_aspect = static_cast<f32>(width_) / static_cast<f32>(height_);
                f32 draw_aspect = static_cast<f32>(blit_width_) / static_cast<f32>(blit_height_);

                if (draw_aspect > game_aspect)
                    blit_width_ = static_cast<i32>(blit_width_ * (game_aspect / draw_aspect));
                else if (draw_aspect < game_aspect)
                    blit_height_ = static_cast<i32>(blit_height_ * (draw_aspect / game_aspect));
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
