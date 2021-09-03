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

define_dummy_symbol(mmui_pu_key);

#include "pu_key.h"

#include "agi/bitmap.h"
#include "agi/pipeline.h"
#include "arts7/cullmgr.h"
#include "mmeffects/mmtext.h"
#include "mminput/input.h"
#include "mminput/io.h"
#include "mmwidget/manager.h"

PUKey::PUKey(i32 menu_id, f32 x, f32 y, f32 width, f32 height)
    : PUMenuBase(menu_id, x, y, width, height, nullptr)
{
    AssignName(LOC_STRING(MM_IDS_PU_KEYS_NAME));
    title_pos_ = CreateTitle();
    AddExit(0.65f, 0.0f, 0.35f, 0.075f);
}

PUKey::~PUKey() = default;

void PUKey::PreSetup()
{
    key_count_ = 0;

    for (i32 i = 0; i < GameInputPtr->NumControls; ++i)
    {
        if (GameInputPtr->IO[i].Enabled)
            ++key_count_;
    }

    text_node_ = CreateTextNode(0.0f, 0.0f, 1.0f, 1.0f, 2 * key_count_, BITMAP_TRANSPARENT);
    AddChild(text_node_.get());

    f32 left_column_name_x = 0.05f / 0.9f;
    f32 left_column_desc_x = 0.25f / 0.9f;

    f32 right_column_name_x = 0.5f / 0.9f;
    f32 right_column_desc_x = 0.7f / 0.9f;

    f32 y = 0.075f / 0.9f;
    f32 y_step = 0.03f / 0.9f;

    if (Pipe()->GetWidth() < 512)
    {
        left_column_name_x = 0.0f;
        left_column_desc_x = 0.28f;

        right_column_name_x = 0.5f;
        right_column_desc_x = 0.78f;

        y = 0.05f;
        y_step = 0.05f;
    }

    for (i32 i = 0, total = 0; i < GameInputPtr->NumControls; ++i)
    {
        if (mmIO* io = &GameInputPtr->IO[i]; io->Enabled)
        {
            char text[40];
            char desc[40];
            bool right = total % 2;

            arts_sprintf(text, "%-23s", io->Name);
            AddText(text_node_.get(), Menus()->GetFont(16), LOC_TEXT(text), 0,
                right ? right_column_name_x : left_column_name_x, y);

            io->GetDescription(desc);
            arts_sprintf(text, "%.23s", desc);
            AddText(text_node_.get(), Menus()->GetFont(16), LOC_TEXT(text), 0,
                right ? right_column_desc_x : left_column_desc_x, y);

            if (right)
                y += y_step;

            ++total;
        }
    }
}

void PUKey::PostSetup()
{
    CULLMGR->Reset();

    if (text_node_)
    {
        RemoveChild(text_node_.get());

        text_node_ = nullptr;
    }
}
