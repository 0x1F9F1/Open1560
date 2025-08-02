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

class Dialog_ControlAssign final : public PUMenuBase
{
public:
    // ??0Dialog_ControlAssign@@QAE@HMMMMPAD@Z
    ARTS_IMPORT Dialog_ControlAssign(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // ??_GDialog_ControlAssign@@UAEPAXI@Z
    // ??_EDialog_ControlAssign@@UAEPAXI@Z
    // ??1Dialog_ControlAssign@@UAE@XZ
    ARTS_EXPORT ~Dialog_ControlAssign() override = default;

    // ?PreSetup@Dialog_ControlAssign@@UAEXXZ
    ARTS_EXPORT void PreSetup() override;
};

check_size(Dialog_ControlAssign, 0xC0);
