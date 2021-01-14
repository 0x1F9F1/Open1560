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

define_dummy_symbol(mmcity_loader);

#include "loader.h"

#include "agi/bitmap.h"
#include "agi/pipeline.h"
#include "localize/localize.h"

void mmLoader::Init(char* underlay_name, f32 bar_x, f32 bar_y)
{
    bar_x_ = UI_XPos + static_cast<i32>(UI_Width * bar_x);
    bar_y_ = UI_YPos + static_cast<i32>(UI_Height * bar_y);

    camera_.SetUnderlay(underlay_name);

    task_text_.Init(0.25f, 0.85f, 0.5f, 0.0729f, 2, AGI_BITMAP_TRANSPARENT);
    task_text_.AddText(myFont, LOC_TEXT(""), MM_TEXT_CENTER, 0.0f, 0.0f);
    task_text_.AddText(myFont, LOC_TEXT(""), MM_TEXT_CENTER, 0.0f, 0.075f);

    intro_text_.Init(0.25f, 0.07f, 0.5f, 0.2f, 1, 0);
    intro_text_.AddText(myFont, LOC_TEXT(""), MM_TEXT_PADDING | MM_TEXT_WORDBREAK, 0.0f, 0.0f);

    Update();
}
