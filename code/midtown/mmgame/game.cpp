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

define_dummy_symbol(mmgame_game);

#include "game.h"

#include "arts7/sim.h"
#include "eventq7/eventq.h"
#include "eventq7/keys.h"
#include "mmnetwork/network.h"
#include "player.h"
#include "popup.h"

u32 IconColor[8] {
    0xFF0000EF, // Blue
    0xFF00EF00, // Green
    0xFFEF0000, // Red
    0xFFFFFF00, // Yellow
    0xFFFF5A00, // Orange
    0xFFB400FF, // Purple
    0xFF00FFFF, // Cyan
    0xFFFF0390, // Pink
};

void mmGame::UpdatePaused()
{
    eqEvent& event = CurrentEvent;

    while (EventQueue->Pop(&event))
    {
        if ((event.Common.Type == eqEventType::Keyboard) && (event.Key.Key != 0) &&
            !(event.Key.Modifiers & EQ_KMOD_DOWN))
        {
            switch (event.Key.Key)
            {
                case EQ_VK_C: Player->ToggleCam(); break;
                case EQ_VK_V: Player->ToggleExternalView(); break;
                case EQ_VK_F1: Popup->ProcessKeymap(!NETMGR.InSession()); break;
                case EQ_VK_F2:
                    if (!NETMGR.InSession() && !IsPopupEnabled())
                        ARTSPTR->TogglePause();
                    break;
            }
        }
    }
}

b32 mmGame::IsPopupEnabled()
{
    return Popup->IsEnabled();
}

run_once([] {
    create_hook("IconColor", "Add Player 8 Icon", 0x40E9AC, IconColor + ARTS_SIZE(IconColor), hook_type::pointer);
});
