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
    mmgame:gameedit

    0x412150 | public: __thiscall mmGameEdit::mmGameEdit(void) | ??0mmGameEdit@@QAE@XZ
    0x412220 | public: virtual __thiscall mmGameEdit::~mmGameEdit(void) | ??1mmGameEdit@@UAE@XZ
    0x4122D0 | public: int __thiscall mmGameEdit::Init(void) | ?Init@mmGameEdit@@QAEHXZ
    0x412380 | public: virtual void __thiscall mmGameEdit::InitMyPlayer(void) | ?InitMyPlayer@mmGameEdit@@UAEXXZ
    0x4123F0 | public: virtual void __thiscall mmGameEdit::InitHUD(void) | ?InitHUD@mmGameEdit@@UAEXXZ
    0x412430 | public: virtual void __thiscall mmGameEdit::InitGameObjects(void) | ?InitGameObjects@mmGameEdit@@UAEXXZ
    0x412520 | public: void __thiscall mmGameEdit::RegisterMapObjects(void) | ?RegisterMapObjects@mmGameEdit@@QAEXXZ
    0x412570 | public: virtual void __thiscall mmGameEdit::UpdateDebugKeyInput(int) | ?UpdateDebugKeyInput@mmGameEdit@@UAEXH@Z
    0x412760 | public: virtual void __thiscall mmGameEdit::Reset(void) | ?Reset@mmGameEdit@@UAEXXZ
    0x4127F0 | public: virtual void __thiscall mmGameEdit::Update(void) | ?Update@mmGameEdit@@UAEXXZ
    0x412810 | public: virtual void __thiscall mmGameEdit::UpdateGameInput(int) | ?UpdateGameInput@mmGameEdit@@UAEXH@Z
    0x412820 | public: virtual void __thiscall mmGameEdit::UpdateGame(void) | ?UpdateGame@mmGameEdit@@UAEXXZ
    0x412860 | public: virtual void __thiscall mmGameEdit::AddWidgets(class Bank *) | ?AddWidgets@mmGameEdit@@UAEXPAVBank@@@Z
    0x412A80 | public: void __thiscall mmGameEdit::SetWPCallback(void) | ?SetWPCallback@mmGameEdit@@QAEXXZ
    0x412B20 | public: void __thiscall mmGameEdit::ChangeWPCallback(void) | ?ChangeWPCallback@mmGameEdit@@QAEXXZ
    0x412B80 | public: static void __cdecl mmGameEdit::DeclareFields(void) | ?DeclareFields@mmGameEdit@@SAXXZ
    0x412D00 | public: virtual class MetaClass * __thiscall mmGameEdit::GetClass(void) | ?GetClass@mmGameEdit@@UAEPAVMetaClass@@XZ
    0x412E60 | public: virtual void * __thiscall mmGameEdit::`vector deleting destructor'(unsigned int) | ??_EmmGameEdit@@UAEPAXI@Z
    0x412EC0 | public: virtual void __thiscall mmGameEdit::InitOtherPlayers(void) | ?InitOtherPlayers@mmGameEdit@@UAEXXZ
    0x412ED0 | public: virtual void __thiscall mmGameEdit::NextRace(void) | ?NextRace@mmGameEdit@@UAEXXZ
    0x412EE0 | public: virtual class mmWaypoints * __thiscall mmGameEdit::GetWaypoints(void) | ?GetWaypoints@mmGameEdit@@UAEPAVmmWaypoints@@XZ
    0x61A4A0 | const mmGameEdit::`vftable' | ??_7mmGameEdit@@6B@
    0x6A6FE0 | class MetaClass mmGameEditMetaClass | ?mmGameEditMetaClass@@3VMetaClass@@A
*/

#include "game.h"

class mmGameEdit /*final*/ : public mmGame
{
    // const mmGameEdit::`vftable' @ 0x61A4A0

public:
    // 0x412150 | ??0mmGameEdit@@QAE@XZ
    ARTS_IMPORT mmGameEdit();

    // 0x412E60 | ??_EmmGameEdit@@UAEPAXI@Z
    // 0x412220 | ??1mmGameEdit@@UAE@XZ
    ARTS_IMPORT ~mmGameEdit() override;

    // 0x412860 | ?AddWidgets@mmGameEdit@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x412B20 | ?ChangeWPCallback@mmGameEdit@@QAEXXZ
    ARTS_IMPORT void ChangeWPCallback();

    // 0x412D00 | ?GetClass@mmGameEdit@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x412EE0 | ?GetWaypoints@mmGameEdit@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_EXPORT class mmWaypoints* GetWaypoints() override;

    // 0x4122D0 | ?Init@mmGameEdit@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // 0x412430 | ?InitGameObjects@mmGameEdit@@UAEXXZ
    ARTS_IMPORT void InitGameObjects() override;

    // 0x4123F0 | ?InitHUD@mmGameEdit@@UAEXXZ
    ARTS_IMPORT void InitHUD() override;

    // 0x412380 | ?InitMyPlayer@mmGameEdit@@UAEXXZ
    ARTS_IMPORT void InitMyPlayer() override;

    // 0x412EC0 | ?InitOtherPlayers@mmGameEdit@@UAEXXZ | inline
    ARTS_EXPORT void InitOtherPlayers() override;

    // 0x412ED0 | ?NextRace@mmGameEdit@@UAEXXZ | inline
    ARTS_EXPORT void NextRace() override;

    // 0x412520 | ?RegisterMapObjects@mmGameEdit@@QAEXXZ
    ARTS_IMPORT void RegisterMapObjects();

    // 0x412760 | ?Reset@mmGameEdit@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x412A80 | ?SetWPCallback@mmGameEdit@@QAEXXZ
    ARTS_IMPORT void SetWPCallback();

    // 0x4127F0 | ?Update@mmGameEdit@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x412570 | ?UpdateDebugKeyInput@mmGameEdit@@UAEXH@Z
    ARTS_IMPORT void UpdateDebugKeyInput(i32 arg1) override;

    // 0x412820 | ?UpdateGame@mmGameEdit@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // 0x412810 | ?UpdateGameInput@mmGameEdit@@UAEXH@Z
    ARTS_EXPORT void UpdateGameInput(i32 arg1) override;

    // 0x412B80 | ?DeclareFields@mmGameEdit@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap1E570[0x1C8];
};

check_size(mmGameEdit, 0x1E738);

// 0x6A6FE0 | ?mmGameEditMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmGameEditMetaClass;
