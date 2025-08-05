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

#pragma once

#include "event.h"

typedef union SDL_Event SDL_Event;
typedef struct SDL_WindowEvent SDL_WindowEvent;

class SDLEventHandler final : public eqEventHandler
{
public:
    i32 BeginGfx(i32 width, i32 height, b32 fullscreen) override;
    void EndGfx() override;
    void Update(i32 arg1) override;
    void BeginTracking() override;
    void EndTracking() override;
    const char* GKeyName(i32 arg1) override;

private:
    void HandleEvent(const SDL_Event& event);

    i32 mouse_width_ {};
    i32 mouse_height_ {};

    bool mouse_moved_ {};
};
