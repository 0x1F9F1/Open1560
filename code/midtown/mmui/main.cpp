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

define_dummy_symbol(mmui_main);

#include "main.h"

#include "mmnetwork/network.h"

MainMenu::MainMenu(i32 idd)
    : UIMenu(idd)
{
    AssignName(LOC_TEXT("Main Menu"));

    AddBMButton(IDC_MAIN_MENU_QUICK, "main_quick"_xconst, UI_LEFT_MARGIN, 0.1f, 4);
    AddBMButton(IDC_MAIN_MENU_SINGLE, "main_single"_xconst, UI_LEFT_MARGIN, 0.25f, 4);
    AddBMButton(IDC_MAIN_MENU_MULTI, "main_multi"_xconst, UI_LEFT_MARGIN, 0.4f, 4);
    AddBMButton(IDC_MAIN_MENU_RECORDS, "race_rec"_xconst, UI_LEFT_MARGIN, 0.55f, 4);

    SetBstate(0);
}

void MainMenu::PreSetup()
{
    NETMGR.SetState(0);
}
