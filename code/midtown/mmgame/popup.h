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

#include "arts7/node.h"

class mmGame;
class PUMain;
class PUQuit;
class PUExit;
class PUChat;
class PUAudioOptions;
class PUOptions;
class PUDebug;
class PUControl;
class PUGraphics;
class PUResults;
class PURoster;
class PUKey;

enum
{
    IDD_PU_MAIN = 1,
    IDD_PU_QUIT = 2,
    IDD_PU_EXIT = 3,
    IDD_PU_CHAT = 4,
    IDD_PU_OPTIONS = 5,
    IDD_PU_AUDIO = 6,
    IDD_PU_CONTROL = 7,
    IDD_PU_GRAPHICS = 8,
    IDD_PU_RESULTS = 9,
    IDD_PU_ROSTER = 10,
    IDD_PU_KEY = 11,
    IDD_PU_DEBUG = 12,
};

class mmPopup final : public asNode
{
public:
    // ??0mmPopup@@QAE@PAVmmGame@@MMMM@Z
    ARTS_IMPORT mmPopup(mmGame* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // ??1mmPopup@@UAE@XZ
    ARTS_EXPORT ~mmPopup() override;

    // ?ChatCB@mmPopup@@QAEXXZ
    ARTS_IMPORT void ChatCB();

    // ?DisablePU@mmPopup@@QAEXH@Z
    ARTS_EXPORT void DisablePU(b32 resume_cd);

    // ?ForceRoster@mmPopup@@QAEXXZ
    ARTS_IMPORT void ForceRoster();

    // ?GetComment@mmPopup@@QAEPADXZ
    ARTS_IMPORT char* GetComment();

    // ?IsEnabled@mmPopup@@QAEHXZ
    ARTS_EXPORT b32 IsEnabled();

    // ?Lock@mmPopup@@QAEXXZ
    ARTS_EXPORT void Lock();

    // ?ProcessChat@mmPopup@@QAEXXZ
    ARTS_IMPORT void ProcessChat();

    // ?ProcessEscape@mmPopup@@QAEXH@Z
    ARTS_IMPORT void ProcessEscape(i32 arg1);

    // ?ProcessKeymap@mmPopup@@QAEXH@Z
    ARTS_IMPORT void ProcessKeymap(i32 arg1);

    // ?RecordPosition@mmPopup@@QAEXXZ
    ARTS_IMPORT void RecordPosition();

    // ?Reset@mmPopup@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetComment@mmPopup@@QAEXPAD@Z
    ARTS_IMPORT void SetComment(char* arg1);

    // ?ShowResults@mmPopup@@QAEXXZ
    ARTS_IMPORT void ShowResults();

    // ?ShowRoster@mmPopup@@QAEXXZ
    ARTS_IMPORT void ShowRoster();

    // ?Unlock@mmPopup@@QAEXXZ
    ARTS_IMPORT void Unlock();

    // ?Update@mmPopup@@UAEXXZ
    ARTS_IMPORT void Update() override;

    mmGame* Game {};

    Ptr<PUMain> Main;
    Ptr<PUQuit> Quit;
    Ptr<PUExit> Exit;
    Ptr<PUChat> Chat;
    Ptr<PUAudioOptions> Audio;
    Ptr<PUOptions> Options;
    Ptr<PUDebug> Debug;
    Ptr<PUControl> Controls;
    Ptr<PUGraphics> Graphics;
    Ptr<PUResults> Results;
    Ptr<PURoster> Roster;
    Ptr<PUKey> Keys;

    b32 WantsFlush {};
    b32 WasPaused {};
    b32 Locked {};
};

check_size(mmPopup, 0x60);
