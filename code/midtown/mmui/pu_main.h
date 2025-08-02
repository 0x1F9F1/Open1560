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

#pragma once

#include "pu_menu.h"

enum
{
    IDC_PU_MAIN_RESTART = 10,
    IDC_PU_MAIN_OPTIONS = 11,
    IDC_PU_MAIN_HELP = 12,
    IDC_PU_MAIN_QUIT = 13,
    IDC_PU_MAIN_EXIT = 14,
    IDC_PU_MAIN_DEBUG = 15,
};

class PUMain final : public PUMenuBase
{
public:
    // ??0PUMain@@QAE@HMMMMPAD@Z
    ARTS_EXPORT PUMain(i32 menu_id, f32 x, f32 y, f32 width, f32 height, char* background);

    // ??_GPUMain@@UAEPAXI@Z
    // ??_EPUMain@@UAEPAXI@Z
    // ??1PUMain@@UAE@XZ
    ARTS_EXPORT ~PUMain() override = default;

    void PreSetup() override;
};

check_size(PUMain, 0xC0);
