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

define_dummy_symbol(mmui_pu_results);

#include "pu_results.h"

#include "agi/bitmap.h"
#include "agi/pipeline.h"
#include "mmeffects/mmtext.h"
#include "mmgame/popup.h"
#include "mmwidget/manager.h"

PUResults::PUResults(i32 menu_id, f32 x, f32 y, f32 width, f32 height, char* background)
    : PUMenuBase(menu_id, x, y, width, height, background)
{
    AssignName(LOC_STRING(MM_IDS_PU_RESULTS_NAME));

    RestartRace = LOC_STR(MM_IDS_PU_RESULTS_RESTART);
    NextRace = LOC_STR(MM_IDS_PU_RESULTS_NEXT);
    ShowRoster = LOC_STR(MM_IDS_PU_RESULTS_ROSTER);
    RaceMenu = LOC_STR(MM_IDS_PU_RESULTS_QUIT);
    ExitToWindows = LOC_STR(MM_IDS_PU_RESULTS_EXIT);

    if (Pipe()->GetWidth() >= 640)
        Init640();
    else
        Init320();

    SetBstate(0);
}

PUResults::~PUResults() = default;

void PUResults::Init640()
{
#define SX(VALUE) ((VALUE) / 640.0f)
#define SY(VALUE) ((VALUE) / 480.0f)

    RaceType = CreateTextNode(SX(124), SY(121), SX(160), SY(20), 1, BITMAP_TRANSPARENT);
    AddText(RaceType.get(), Menus()->GetFont(20), LOC_TEXT("Checkpoint"), MM_TEXT_CENTER, 0, 0);

    RaceName = CreateTextNode(SX(124), SY(141), SX(160), SY(20), 1, BITMAP_TRANSPARENT);
    AddText(RaceName.get(), Menus()->GetFont(20), LOC_TEXT("Tough Turns & a Tunnel"), MM_TEXT_CENTER, 0, 0);

    Message = CreateTextNode(SX(124), SY(161), SX(160), SY(60), 1, BITMAP_TRANSPARENT);
    AddText(Message.get(), Menus()->GetFont(20),
        LOC_TEXT("Congratulations!\nYou have just unlocked the next level of races"), MM_TEXT_WORDBREAK, 0, 0);

    Names = CreateTextNode(SX(300), SY(63), SX(300), SY(163), 30, BITMAP_TRANSPARENT);

    f32 text_w = 0.0f;
    f32 text_h = 0.0f;
    Names->GetTextDimensions(Menus()->GetFont(16), LOC_TEXT("Just the Height"), text_w, text_h);

    AddChild(RaceType.get());
    AddChild(RaceName.get());
    AddChild(Message.get());
    AddChild(Names.get());

    for (i32 i = 0; i < 10; ++i)
    {
        char buffer[40];
        arts_strcpy(buffer, " ");
        i32 y = i * 16;

        AddText(Names.get(), Menus()->GetFont(20), LOC_TEXT(buffer), 0, SX(0), SY(y));
        AddText(Names.get(), Menus()->GetFont(20), LOC_TEXT(buffer), 0, SX(21), SY(y));
        AddText(Names.get(), Menus()->GetFont(20), LOC_TEXT(buffer), 0, SX(203), SY(y));
    }

#define X(IDC, LABEL, X, Y, W) \
    AddButton(IDC, LOC_TEXT(LABEL.get()), X, Y, W, widget_height_, widget_font_size_, 0, nullptr)

    RestartButton = X(IDC_PU_RESULTS_RESTART, RestartRace, SX(268), SY(240), SX(135));
    NextButton = X(IDC_PU_RESULTS_NEXT, NextRace, SX(407), SY(240), SX(135));
    RosterButton = X(IDC_PU_RESULTS_ROSTER, ShowRoster, SX(268), SY(285), SX(135));

    X(IDC_PU_RESULTS_QUIT, RaceMenu, SX(407), SY(285), SX(135));
    X(IDC_PU_RESULTS_EXIT, ExitToWindows, SX(300), SY(330), SX(202));

#undef X
#undef SX
#undef SY
}
