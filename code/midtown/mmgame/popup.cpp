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

define_dummy_symbol(mmgame_popup);

#include "popup.h"

#include "arts7/sim.h"
#include "mmaudio/manager.h"
#include "mmcity/renderweb.h"
#include "mmcityinfo/state.h"
#include "mmgame/game.h"
#include "mmgame/player.h"
#include "mminput/input.h"
#include "mmwidget/manager.h"

#include "mmui/pu_audio.h"
#include "mmui/pu_chat.h"
#include "mmui/pu_control.h"
#include "mmui/pu_debug.h"
#include "mmui/pu_exit.h"
#include "mmui/pu_graphics.h"
#include "mmui/pu_key.h"
#include "mmui/pu_main.h"
#include "mmui/pu_options.h"
#include "mmui/pu_quit.h"
#include "mmui/pu_results.h"
#include "mmui/pu_roster.h"

ARTS_IMPORT extern u8 PopupCDTrack;
ARTS_IMPORT extern u8 PopupCDMinute;
ARTS_IMPORT extern u8 PopupCDSecond;
ARTS_IMPORT extern u8 PopupCDFrame;

mmPopup::~mmPopup() = default;

void mmPopup::DisablePU(b32 resume_cd)
{
    if (MenuMgr()->IsPopupOpen())
    {
        MenuMgr()->Switch(1);
        MenuMgr()->DisablePU();

        if (Sim()->IsPaused() && !WasPaused)
            Sim()->SetPause(false);

        GameInput()->Flush();
        GameInput()->Update();

        Game->Player->Hud.Enable();
        Game->Player->HudMap.Activate();

        PopupEnabled = false;
    }

    if (resume_cd && MMSTATE.HasMidtownCD)
    {
        AudMgr()->PlayCDTrack(PopupCDTrack, PopupCDMinute, PopupCDSecond, PopupCDFrame, true);
    }
}

b32 mmPopup::IsEnabled()
{
    return MenuMgr()->IsPopupOpen();
}

void mmPopup::Lock()
{
    Locked = true;

    Main->DisableExit();
}
