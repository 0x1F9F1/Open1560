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

/*
    mmui:driver

    0x4A5350 | public: __thiscall DriverMenu::DriverMenu(int) | ??0DriverMenu@@QAE@H@Z
    0x4A5430 | public: virtual void __thiscall DriverMenu::PreSetup(void) | ?PreSetup@DriverMenu@@UAEXXZ
    0x4A5460 | public: void __thiscall DriverMenu::InitPlayerSelection(void) | ?InitPlayerSelection@DriverMenu@@QAEXXZ
    0x4A5850 | public: virtual __thiscall DriverMenu::~DriverMenu(void) | ??1DriverMenu@@UAE@XZ
    0x4A58C0 | public: void __thiscall DriverMenu::RemovePlayer(char *) | ?RemovePlayer@DriverMenu@@QAEXPAD@Z
    0x4A5B00 | public: void __thiscall DriverMenu::SetPlayerPick(int) | ?SetPlayerPick@DriverMenu@@QAEXH@Z
    0x4A5B10 | public: void __thiscall DriverMenu::DecPlayer(void) | ?DecPlayer@DriverMenu@@QAEXXZ
    0x4A5B40 | public: void __thiscall DriverMenu::IncPlayer(void) | ?IncPlayer@DriverMenu@@QAEXXZ
    0x4A5B70 | public: void __thiscall DriverMenu::RemoveAllPlayers(void) | ?RemoveAllPlayers@DriverMenu@@QAEXXZ
    0x4A5B80 | public: void __thiscall DriverMenu::AddPlayer(char *) | ?AddPlayer@DriverMenu@@QAEXPAD@Z
    0x4A5C90 | public: void __thiscall DriverMenu::TDPickCB(void) | ?TDPickCB@DriverMenu@@QAEXXZ
    0x4A5CA0 | public: void __thiscall DriverMenu::DeleteCB(void) | ?DeleteCB@DriverMenu@@QAEXXZ
    0x4A5CB0 | public: void __thiscall DriverMenu::NewPlayer(void) | ?NewPlayer@DriverMenu@@QAEXXZ
    0x4A5CC0 | public: char * __thiscall DriverMenu::GetNewDriverName(void) | ?GetNewDriverName@DriverMenu@@QAEPADXZ
    0x4A5CD0 | public: void __thiscall DriverMenu::EnterNewPlayer(void) | ?EnterNewPlayer@DriverMenu@@QAEXXZ
    0x4A5CE0 | public: void __thiscall DriverMenu::DisplayDriverInfo(char *,char *,char *,char *,char *,int) | ?DisplayDriverInfo@DriverMenu@@QAEXPAD0000H@Z
    0x4A5DA0 | public: void __thiscall DriverMenu::SetController(char *) | ?SetController@DriverMenu@@QAEXPAD@Z
    0x4A5DC0 | public: void __thiscall DriverMenu::SetNetName(char *) | ?SetNetName@DriverMenu@@QAEXPAD@Z
    0x4A5E00 | public: virtual void * __thiscall DriverMenu::`scalar deleting destructor'(unsigned int) | ??_GDriverMenu@@UAEPAXI@Z
    0x4A5E00 | public: virtual void * __thiscall DriverMenu::`vector deleting destructor'(unsigned int) | ??_EDriverMenu@@UAEPAXI@Z
    0x61DBF0 | const DriverMenu::`vftable' | ??_7DriverMenu@@6B@
*/

#include "mmwidget/menu.h"

class DriverMenu /*final*/ : public UIMenu
{
    // const DriverMenu::`vftable' @ 0x61DBF0

public:
    // 0x4A5350 | ??0DriverMenu@@QAE@H@Z
    ARTS_IMPORT DriverMenu(i32 arg1);

    // 0x4A5E00 | ??_EDriverMenu@@UAEPAXI@Z
    // 0x4A5E00 | ??_GDriverMenu@@UAEPAXI@Z
    // 0x4A5850 | ??1DriverMenu@@UAE@XZ
    ARTS_IMPORT ~DriverMenu() override;

    // 0x4A5B80 | ?AddPlayer@DriverMenu@@QAEXPAD@Z
    ARTS_IMPORT void AddPlayer(char* arg1);

    // 0x4A5B10 | ?DecPlayer@DriverMenu@@QAEXXZ | unused
    ARTS_IMPORT void DecPlayer();

    // 0x4A5CA0 | ?DeleteCB@DriverMenu@@QAEXXZ
    ARTS_IMPORT void DeleteCB();

    // 0x4A5CE0 | ?DisplayDriverInfo@DriverMenu@@QAEXPAD0000H@Z
    ARTS_IMPORT void DisplayDriverInfo(char* arg1, char* arg2, char* arg3, char* arg4, char* arg5, i32 arg6);

    // 0x4A5CD0 | ?EnterNewPlayer@DriverMenu@@QAEXXZ | unused
    ARTS_IMPORT void EnterNewPlayer();

    // 0x4A5CC0 | ?GetNewDriverName@DriverMenu@@QAEPADXZ | unused
    ARTS_IMPORT char* GetNewDriverName();

    // 0x4A5B40 | ?IncPlayer@DriverMenu@@QAEXXZ | unused
    ARTS_IMPORT void IncPlayer();

    // 0x4A5460 | ?InitPlayerSelection@DriverMenu@@QAEXXZ
    ARTS_IMPORT void InitPlayerSelection();

    // 0x4A5CB0 | ?NewPlayer@DriverMenu@@QAEXXZ | unused
    ARTS_EXPORT void NewPlayer();

    // 0x4A5430 | ?PreSetup@DriverMenu@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // 0x4A5B70 | ?RemoveAllPlayers@DriverMenu@@QAEXXZ
    ARTS_IMPORT void RemoveAllPlayers();

    // 0x4A58C0 | ?RemovePlayer@DriverMenu@@QAEXPAD@Z
    ARTS_IMPORT void RemovePlayer(char* arg1);

    // 0x4A5DA0 | ?SetController@DriverMenu@@QAEXPAD@Z
    ARTS_IMPORT void SetController(char* arg1);

    // 0x4A5DC0 | ?SetNetName@DriverMenu@@QAEXPAD@Z
    ARTS_IMPORT void SetNetName(char* arg1);

    // 0x4A5B00 | ?SetPlayerPick@DriverMenu@@QAEXH@Z
    ARTS_IMPORT void SetPlayerPick(i32 arg1);

    // 0x4A5C90 | ?TDPickCB@DriverMenu@@QAEXXZ
    ARTS_IMPORT void TDPickCB();

    u8 gap90[0x9C];
};

check_size(DriverMenu, 0x12C);
