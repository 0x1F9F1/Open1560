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

#include "mmwidget/menu.h"

class DriverMenu final : public UIMenu
{
public:
    // ??0DriverMenu@@QAE@H@Z
    ARTS_IMPORT DriverMenu(i32 arg1);

    // ??_EDriverMenu@@UAEPAXI@Z
    // ??_GDriverMenu@@UAEPAXI@Z
    // ??1DriverMenu@@UAE@XZ
    ARTS_IMPORT ~DriverMenu() override;

    // ?AddPlayer@DriverMenu@@QAEXPAD@Z
    ARTS_IMPORT void AddPlayer(char* arg1);

    // ?DeleteCB@DriverMenu@@QAEXXZ
    ARTS_IMPORT void DeleteCB();

    // ?DisplayDriverInfo@DriverMenu@@QAEXPAD0000H@Z
    ARTS_IMPORT void DisplayDriverInfo(char* arg1, char* arg2, char* arg3, char* arg4, char* arg5, i32 arg6);

    // ?InitPlayerSelection@DriverMenu@@QAEXXZ
    ARTS_IMPORT void InitPlayerSelection();

    // ?NewPlayer@DriverMenu@@QAEXXZ | unused
    ARTS_EXPORT void NewPlayer();

    // ?PreSetup@DriverMenu@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // ?RemoveAllPlayers@DriverMenu@@QAEXXZ
    ARTS_IMPORT void RemoveAllPlayers();

    // ?RemovePlayer@DriverMenu@@QAEXPAD@Z
    ARTS_IMPORT void RemovePlayer(char* arg1);

    // ?SetController@DriverMenu@@QAEXPAD@Z
    ARTS_IMPORT void SetController(char* arg1);

    // ?SetNetName@DriverMenu@@QAEXPAD@Z
    ARTS_IMPORT void SetNetName(char* arg1);

    // ?SetPlayerPick@DriverMenu@@QAEXH@Z
    ARTS_IMPORT void SetPlayerPick(i32 arg1);

    // ?TDPickCB@DriverMenu@@QAEXXZ
    ARTS_IMPORT void TDPickCB();

    u8 gap90[0x9C];
};

check_size(DriverMenu, 0x12C);
