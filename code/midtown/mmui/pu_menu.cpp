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

define_dummy_symbol(mmui_pu_menu);

#include "pu_menu.h"

#include "agi/bitmap.h"
#include "agi/pipeline.h"
#include "mmwidget/manager.h"

PUMenuBase::PUMenuBase(
    i32 menu_id, [[maybe_unused]] f32 x, [[maybe_unused]] f32 y, f32 width, f32 height, char* background)
    : UIMenu(menu_id)
{
    if (background)
    {
        if (MenuManager::Instance->HasScale())
        {
            if (menu_id == 9) // FIXME: Need to adjust PUResults text positions
                bg_bitmap_ = AsRc(Pipe()->GetBitmap(background, UI_FullW, UI_FullH, 0));
            else
                bg_bitmap_ = AsRc(Pipe()->GetBitmap(background, 1.0f, 1.0f, 0));
        }
        else
        {
            bg_bitmap_ = AsRc(Pipe()->GetBitmap(background, 0.0f, 0.0f, 1));
        }

        if (!bg_bitmap_)
        {
            bg_bitmap_ = AsRc(CreateDummyBitmap());

            ArAssert(bg_bitmap_, "Could not create backgrond");
        }

        menu_width_ = static_cast<f32>(bg_bitmap_->GetWidth()) / static_cast<f32>(Pipe()->GetWidth());
        menu_height_ = static_cast<f32>(bg_bitmap_->GetHeight()) / static_cast<f32>(Pipe()->GetHeight());
    }
    else if (width > 0.0f && height > 0.0f)
    {
        // FIXME: Need to adjust PUKey control positions
        if (menu_id != 11)
        {
            width *= UI_ScaleX;
            height *= UI_ScaleY;
        }

        menu_width_ = width;
        menu_height_ = height;
    }

    menu_x_ = UI_StartX + (UI_ScaleX - menu_width_) / 2.0f;
    menu_y_ = UI_StartY + (UI_ScaleY - menu_height_) / 2.0f;

    if (bg_bitmap_)
    {
        bg_x_ = static_cast<i32>(Pipe()->GetWidth() * menu_x_);
        bg_y_ = static_cast<i32>(Pipe()->GetHeight() * menu_y_);
    }

    field_AC = 0.075f;
    field_A8 = 0.1f;
    field_68 = 1;
    field_BC = 0.1f;
    field_B4 = 0.9f;
    field_A4 = MenuManager::Instance->GetFieldD0() ? 24 : 32;
    field_B0 = 0.5f;
    field_B8 = 0.5f;
}
