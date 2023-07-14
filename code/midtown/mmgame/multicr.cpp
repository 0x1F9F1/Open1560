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

define_dummy_symbol(mmgame_multicr);

#include "multicr.h"
#include "mmnetwork/network.h"
#include "player.h"
#include "wphud.h"

mmWaypoints* mmMultiCR::GetWaypoints()
{
    return nullptr;
}

void mmMultiCR::UpdateDebugKeyInput(i32 /*arg1*/)
{}

void mmMultiCR::OppStealGold(i32 player)
{
    StealGold(Cars[player]);
    Player->Hud.CrHud->ActivateRosterGold(NetObjects[player].PlayerID);

    OppIconInfo& icon = OppIcons[player];
    icon.Place = OPP_ICON_GOLD;
    icon.Enabled = true;

    if (NETMGR.IsHost())
        ++TimesGoldStolen;
}

i32 mmMultiCR::SelectTeams()
{
    return 0;
}

void mmMultiCR::SendSetup(ulong /*arg1*/)
{}
