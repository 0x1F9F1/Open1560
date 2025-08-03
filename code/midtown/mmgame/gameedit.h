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

#include "game.h"

class mmGameEdit final : public mmGame
{
public:
    // ??0mmGameEdit@@QAE@XZ
    ARTS_IMPORT mmGameEdit();

    // ??1mmGameEdit@@UAE@XZ
    ARTS_IMPORT ~mmGameEdit() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmGameEdit@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

#ifdef ARTS_DEV_BUILD
    // ?ChangeWPCallback@mmGameEdit@@QAEXXZ
    ARTS_IMPORT void ChangeWPCallback();
#endif

    // ?GetClass@mmGameEdit@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetWaypoints@mmGameEdit@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_EXPORT mmWaypoints* GetWaypoints() override;

    // ?Init@mmGameEdit@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // ?InitGameObjects@mmGameEdit@@UAEXXZ
    ARTS_IMPORT void InitGameObjects() override;

    // ?InitHUD@mmGameEdit@@UAEXXZ
    ARTS_IMPORT void InitHUD() override;

    // ?InitMyPlayer@mmGameEdit@@UAEXXZ
    ARTS_IMPORT void InitMyPlayer() override;

    // ?InitOtherPlayers@mmGameEdit@@UAEXXZ | inline
    ARTS_EXPORT void InitOtherPlayers() override;

    // ?NextRace@mmGameEdit@@UAEXXZ | inline
    ARTS_EXPORT void NextRace() override;

    // ?RegisterMapObjects@mmGameEdit@@QAEXXZ
    ARTS_IMPORT void RegisterMapObjects();

    // ?Reset@mmGameEdit@@UAEXXZ
    ARTS_IMPORT void Reset() override;

#ifdef ARTS_DEV_BUILD
    // ?SetWPCallback@mmGameEdit@@QAEXXZ
    ARTS_IMPORT void SetWPCallback();
#endif

    // ?Update@mmGameEdit@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateDebugKeyInput@mmGameEdit@@UAEXH@Z
    ARTS_IMPORT void UpdateDebugKeyInput(i32 arg1) override;

    // ?UpdateGame@mmGameEdit@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // ?UpdateGameInput@mmGameEdit@@UAEXH@Z
    ARTS_EXPORT void UpdateGameInput(i32 arg1) override;

    // ?DeclareFields@mmGameEdit@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap1E570[0x1C8];
};

check_size(mmGameEdit, 0x1E738);
