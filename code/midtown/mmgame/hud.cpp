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

define_dummy_symbol(mmgame_hud);

#include "hud.h"

void mmHUD::TogglePositionDisplay(i32 mode)
{
    // FIXME: Move to constructor
    if (DashView.GetParent() == &HudElements)
    {
        // DashView is not a HUD element, and should not be hidden when a menu is shown.
        // To avoid drawing over the HUD, it should also come before HudElements
        HudElements.RemoveChild(&DashView);
        InsertChild(1, &DashView);

        // Show position text while paused
        PositionText.SetUpdateWhilePaused(true);
    }

    if (mode == -1)
        ShowPosition = !ShowPosition;
    else
        ShowPosition = mode != 0;

    PositionText.SetActive(ShowPosition);
}

void mmHUD::UpdatePaused()
{}