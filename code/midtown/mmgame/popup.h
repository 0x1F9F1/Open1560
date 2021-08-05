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
    mmgame:popup

    0x426BA0 | public: __thiscall mmPopup::mmPopup(class mmGame *,float,float,float,float) | ??0mmPopup@@QAE@PAVmmGame@@MMMM@Z
    0x427010 | public: virtual __thiscall mmPopup::~mmPopup(void) | ??1mmPopup@@UAE@XZ
    0x427020 | public: int __thiscall mmPopup::IsEnabled(void) | ?IsEnabled@mmPopup@@QAEHXZ
    0x427030 | public: void __thiscall mmPopup::DisablePU(int) | ?DisablePU@mmPopup@@QAEXH@Z
    0x427110 | public: void __thiscall mmPopup::ProcessEscape(int) | ?ProcessEscape@mmPopup@@QAEXH@Z
    0x427250 | public: void __thiscall mmPopup::ProcessChat(void) | ?ProcessChat@mmPopup@@QAEXXZ
    0x427350 | public: void __thiscall mmPopup::ProcessKeymap(int) | ?ProcessKeymap@mmPopup@@QAEXH@Z
    0x4274D0 | public: void __thiscall mmPopup::ShowResults(void) | ?ShowResults@mmPopup@@QAEXXZ
    0x427560 | public: void __thiscall mmPopup::ShowRoster(void) | ?ShowRoster@mmPopup@@QAEXXZ
    0x427600 | public: void __thiscall mmPopup::ForceRoster(void) | ?ForceRoster@mmPopup@@QAEXXZ
    0x427680 | public: virtual void __thiscall mmPopup::Update(void) | ?Update@mmPopup@@UAEXXZ
    0x427C50 | public: virtual void __thiscall mmPopup::Reset(void) | ?Reset@mmPopup@@UAEXXZ
    0x427C70 | public: char * __thiscall mmPopup::GetComment(void) | ?GetComment@mmPopup@@QAEPADXZ
    0x427C80 | public: void __thiscall mmPopup::SetComment(char *) | ?SetComment@mmPopup@@QAEXPAD@Z
    0x427CA0 | public: void __thiscall mmPopup::RecordPosition(void) | ?RecordPosition@mmPopup@@QAEXXZ
    0x427CD0 | public: void __thiscall mmPopup::Lock(void) | ?Lock@mmPopup@@QAEXXZ
    0x427CE0 | public: void __thiscall mmPopup::Unlock(void) | ?Unlock@mmPopup@@QAEXXZ
    0x427CF0 | public: void __thiscall mmPopup::ChatCB(void) | ?ChatCB@mmPopup@@QAEXXZ
    0x427D80 | public: virtual void * __thiscall mmPopup::`vector deleting destructor'(unsigned int) | ??_EmmPopup@@UAEPAXI@Z
    0x427D80 | public: virtual void * __thiscall mmPopup::`scalar deleting destructor'(unsigned int) | ??_GmmPopup@@UAEPAXI@Z
    0x61AD80 | const mmPopup::`vftable' | ??_7mmPopup@@6B@
*/

#include "arts7/node.h"

class mmPopup final : public asNode
{
    // const mmPopup::`vftable'

public:
    // ??0mmPopup@@QAE@PAVmmGame@@MMMM@Z
    ARTS_IMPORT mmPopup(class mmGame* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // ??_GmmPopup@@UAEPAXI@Z
    // ??_EmmPopup@@UAEPAXI@Z
    // ??1mmPopup@@UAE@XZ
    ARTS_IMPORT ~mmPopup() override = default;

    // ?ChatCB@mmPopup@@QAEXXZ
    ARTS_IMPORT void ChatCB();

    // ?DisablePU@mmPopup@@QAEXH@Z
    ARTS_IMPORT void DisablePU(i32 arg1);

    // ?ForceRoster@mmPopup@@QAEXXZ
    ARTS_IMPORT void ForceRoster();

    // ?GetComment@mmPopup@@QAEPADXZ
    ARTS_IMPORT char* GetComment();

    // ?IsEnabled@mmPopup@@QAEHXZ
    ARTS_IMPORT i32 IsEnabled();

    // ?Lock@mmPopup@@QAEXXZ
    ARTS_IMPORT void Lock();

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

    u8 gap20[0x40];
};

check_size(mmPopup, 0x60);
