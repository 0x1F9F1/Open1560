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
class mmGameSingle;
class mmSingleCircuit;
class mmSingleBlitz;
class mmMultiRace;
class mmMultiCR;
class mmMultiCircuit;
class mmMultiBlitz;
class mmGameEdit;
class agiBitmap;

class mmScreenClearFlunky final : public asNode
{
public:
    // ??1mmScreenClearFlunky@@UAE@XZ | inline
    ARTS_EXPORT ~mmScreenClearFlunky() override = default;

    // ?Cull@mmScreenClearFlunky@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Update@mmScreenClearFlunky@@UAEXXZ
    ARTS_IMPORT void Update() override;
};

check_size(mmScreenClearFlunky, 0x20);

class mmGameManager final : public asNode
{
public:
    // ??0mmGameManager@@QAE@XZ
    ARTS_IMPORT mmGameManager();

    // ??1mmGameManager@@UAE@XZ
    ARTS_IMPORT ~mmGameManager() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmGameManager@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?BeDone@mmGameManager@@QAEXXZ
    void BeDone();

    // ?Cull@mmGameManager@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?GetBrakes@mmGameManager@@QAEMXZ
    ARTS_IMPORT f32 GetBrakes();

    // ?GetClass@mmGameManager@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetSteering@mmGameManager@@QAEMXZ
    ARTS_IMPORT f32 GetSteering();

    // ?GetThrottle@mmGameManager@@QAEMXZ
    ARTS_IMPORT f32 GetThrottle();

    // ?LoadReplay@mmGameManager@@QAEXPAD@Z
    ARTS_IMPORT void LoadReplay(aconst char* arg1);

    // ?Reset@mmGameManager@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?SaveReplay@mmGameManager@@QAEXPAD@Z
    ARTS_IMPORT void SaveReplay(aconst char* arg1);

    // ?StartReplay@mmGameManager@@QAEXXZ
    ARTS_IMPORT void StartReplay();

    // ?Update@mmGameManager@@UAEXXZ
    ARTS_EXPORT void Update() override;

    // ?DeclareFields@mmGameManager@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    mmGame* Current;

private:
    friend mmGameManager* GameMgr();

    // ?Instance@mmGameManager@@0PAV1@A
    ARTS_IMPORT static mmGameManager* Instance;

    mmGameSingle* GameSingle;
    mmSingleCircuit* SingleCircuit;
    mmSingleBlitz* SingleBlitz;
    mmMultiRace* MultiRace;
    mmMultiCR* MultiCR;
    mmMultiCircuit* MultiCircuit;
    mmMultiBlitz* MultiBlitz;
    mmGameEdit* GameEdit;
    b32 InReplay;
    u32 Frame;
    u32 PendingFrames;
    b32 NeedsReset;
    agiBitmap* ReplayBitmap;
    i32 field_58;
};

check_size(mmGameManager, 0x5C);

inline mmGameManager* GameMgr()
{
    return mmGameManager::Instance;
}

// ?ScreenClearCount@@3HA
ARTS_EXPORT extern i32 ScreenClearCount;