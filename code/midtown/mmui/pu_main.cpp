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

define_dummy_symbol(mmui_pu_main);

#include "pu_main.h"

#include "arts7/sim.h"
#include "mmgame/popup.h"

PUMain::PUMain(i32 menu_id, f32 x, f32 y, f32 width, f32 height, char* background)
    : PUMenuBase(menu_id, x, y, width, height, background)
{
    AssignName(LOC_STRING(MM_IDS_PU_MAIN_NAME));

    CreateTitle();
    AddExit(0.65f, 0.0f, 0.35f, 0.075f);

#define X(IDC, LABEL, POS) AddButton(IDC, LABEL, 0.0f, POS / 7.0f, 1.0f, widget_height_, widget_font_size_, 2, nullptr);

    X(IDC_PU_MAIN_RESTART, LOC_STRING(MM_IDS_PU_MAIN_RESTART), 1);
    X(IDC_PU_MAIN_OPTIONS, LOC_STRING(MM_IDS_PU_MAIN_OPTIONS), 2);
    X(IDC_PU_MAIN_DEBUG, LOC_TEXT("Debug"), 3);
    X(IDC_PU_MAIN_HELP, LOC_STRING(MM_IDS_PU_MAIN_HELP), 3);
    X(IDC_PU_MAIN_QUIT, LOC_STRING(MM_IDS_PU_MAIN_QUIT), 4);
    X(IDC_PU_MAIN_EXIT, LOC_STRING(MM_IDS_PU_MAIN_EXIT), 5);

    SetBstate(0);
}

void PUMain::PreSetup()
{
    bool debug = Sim()->IsDebug();
    FindWidget(IDC_PU_MAIN_HELP)->SetEnabled(!debug);
    FindWidget(IDC_PU_MAIN_DEBUG)->SetEnabled(debug);
}
