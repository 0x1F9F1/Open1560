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

define_dummy_symbol(mmwidget_manager);

#include "manager.h"

#include "agi/pipeline.h"

void MenuManager::AddPointer()
{}

void MenuManager::AddWidgets(class Bank* /*arg1*/)
{}

// 0x4B1B30 | ?HelpWatcher@@YGKPAX@Z
ARTS_IMPORT /*static*/ u32 ARTS_STDCALL HelpWatcher(void* arg1);

void MenuManager::GetScale(f32& x, f32& y, f32& width, f32& height)
{
    if (HasScale())
    {
        x = StartX;
        y = StartY;

        width = ScaleX;
        height = ScaleY;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;

        width = 1.0f;
        height = 1.0f;
    }

    // TODO: Move scaling to MenuManager::Init?
    x = UI_StartX + (x * UI_ScaleX);
    y = UI_StartY + (y * UI_ScaleY);

    width = width * UI_ScaleX;
    height = height * UI_ScaleY;
}
