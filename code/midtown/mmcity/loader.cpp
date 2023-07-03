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
#include "arts7/cullmgr.h"
#include "eventq7/event.h"
#include "localize/localize.h"

void mmLoader::Init(aconst char* underlay_name, f32 bar_x, f32 bar_y)
{
    bar_x_ = UI_XPos + std::lround(UI_Width * bar_x);
    bar_y_ = UI_YPos + std::lround(UI_Height * bar_y);

    camera_.SetUnderlay(underlay_name);

    task_text_.Init(0.25f, 0.85f, 0.5f, 0.0729f, 2, BITMAP_TRANSPARENT);
    task_text_.AddText(myFont, LOC_TEXT(""), MM_TEXT_CENTER, 0.0f, 0.0f);
    task_text_.AddText(myFont, LOC_TEXT(""), MM_TEXT_CENTER, 0.0f, 0.075f);

    intro_text_.Init(0.25f, 0.07f, 0.5f, 0.2f, 1, 0);
    intro_text_.AddText(myFont, LOC_TEXT(""), MM_TEXT_PADDING | MM_TEXT_WORDBREAK, 0.0f, 0.0f);

    Update();
}

void mmLoader::Update()
{
    eqEventHandler::SuperQ->Update();

    camera_.Update();

    if (bar_active_)
    {
        current_task_percent_ = task_start_percent_;

        CullMgr()->DeclareBitmap(this, bar_active_);
    }

#ifndef ARTS_FINAL
    // if ((current_task_percent_ == 1.0f) && (static_cast<i32>(timer_.Time()) % 2))
    {
        task_text_.Update();
    }
#endif

    CullMgr()->Update();
}
