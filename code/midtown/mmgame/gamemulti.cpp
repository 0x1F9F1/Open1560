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

define_dummy_symbol(mmgame_gamemulti);

#include "gamemulti.h"

#include "mmcar/car.h"
#include "mmnetwork/network.h"

void mmGameMulti::NextRace()
{}

void mmGameMulti::QuitNetwork()
{
    if (NETMGR.InLobby())
    {
        NETMGR.Logout();
    }
    else
    {
        NETMGR.DestroyPlayer();
        NETMGR.CloseSession();
        NETMGR.Deallocate();
    }
}

void mmGameMulti::UpdateDebugKeyInput(i32 /*arg1*/)
{}

void mmGameMulti::ActivateMapNetObject(i32 player)
{
    OppIconInfo& icon = OppIcons[player];

    icon.Position = &Cars[player]->GetICS()->Matrix;
    icon.Enabled = true;
}

void mmGameMulti::DeactivateMapNetObject(i32 player)
{
    OppIconInfo& icon = OppIcons[player];

    icon.Position = 0;
    icon.Place = OPP_ICON_BLANK;
    icon.Enabled = false;
}
