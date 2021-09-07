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
    mmgame:gameman

    0x403CE0 | public: virtual void __thiscall mmScreenClearFlunky::Update(void) | ?Update@mmScreenClearFlunky@@UAEXXZ
    0x403D10 | public: virtual void __thiscall mmScreenClearFlunky::Cull(void) | ?Cull@mmScreenClearFlunky@@UAEXXZ
    0x403E50 | public: __thiscall mmGameManager::mmGameManager(void) | ??0mmGameManager@@QAE@XZ
    0x404390 | void __cdecl randcall(void) | ?randcall@@YAXXZ
    0x4043B0 | public: virtual __thiscall mmGameManager::~mmGameManager(void) | ??1mmGameManager@@UAE@XZ
    0x4044C0 | public: void __thiscall mmGameManager::BeDone(void) | ?BeDone@mmGameManager@@QAEXXZ
    0x4044D0 | public: virtual void __thiscall mmGameManager::Update(void) | ?Update@mmGameManager@@UAEXXZ
    0x4046D0 | void __cdecl DoScan(void *) | ?DoScan@@YAXPAX@Z
    0x404750 | public: virtual void __thiscall mmGameManager::Cull(void) | ?Cull@mmGameManager@@UAEXXZ
    0x404790 | public: void __thiscall mmGameManager::StartReplay(void) | ?StartReplay@mmGameManager@@QAEXXZ
    0x4047B0 | public: void __thiscall mmGameManager::LoadReplay(char *) | ?LoadReplay@mmGameManager@@QAEXPAD@Z
    0x404880 | public: void __thiscall mmGameManager::SaveReplay(char *) | ?SaveReplay@mmGameManager@@QAEXPAD@Z
    0x404910 | public: virtual void __thiscall mmGameManager::Reset(void) | ?Reset@mmGameManager@@UAEXXZ
    0x404920 | public: float __thiscall mmGameManager::GetBrakes(void) | ?GetBrakes@mmGameManager@@QAEMXZ
    0x404950 | public: float __thiscall mmGameManager::GetSteering(void) | ?GetSteering@mmGameManager@@QAEMXZ
    0x404980 | public: float __thiscall mmGameManager::GetThrottle(void) | ?GetThrottle@mmGameManager@@QAEMXZ
    0x4049B0 | public: virtual void __thiscall mmGameManager::AddWidgets(class Bank *) | ?AddWidgets@mmGameManager@@UAEXPAVBank@@@Z
    0x4049C0 | public: static void __cdecl mmGameManager::DeclareFields(void) | ?DeclareFields@mmGameManager@@SAXXZ
    0x404B30 | public: virtual class MetaClass * __thiscall mmGameManager::GetClass(void) | ?GetClass@mmGameManager@@UAEPAVMetaClass@@XZ
    0x404B70 | public: virtual void * __thiscall mmScreenClearFlunky::`scalar deleting destructor'(unsigned int) | ??_GmmScreenClearFlunky@@UAEPAXI@Z
    0x404B70 | public: virtual void * __thiscall mmScreenClearFlunky::`vector deleting destructor'(unsigned int) | ??_EmmScreenClearFlunky@@UAEPAXI@Z
    0x404BA0 | public: virtual __thiscall mmScreenClearFlunky::~mmScreenClearFlunky(void) | ??1mmScreenClearFlunky@@UAE@XZ
    0x404BB0 | public: virtual void __thiscall asNode::UpdatePaused(void) | ?UpdatePaused@asNode@@UAEXXZ
    0x404BC0 | public: virtual void * __thiscall mmGameManager::`vector deleting destructor'(unsigned int) | ??_EmmGameManager@@UAEPAXI@Z
    0x61A0D8 | const mmScreenClearFlunky::`vftable' | ??_7mmScreenClearFlunky@@6B@
    0x61A118 | const mmGameManager::`vftable' | ??_7mmGameManager@@6B@
    0x67216C | unsigned char dummyGlobal2 | ?dummyGlobal2@@3EA
    0x6A6D58 | int ScreenClearCount | ?ScreenClearCount@@3HA
    0x6A6D60 | class Stream * ReplayLog | ?ReplayLog@@3PAVStream@@A
    0x6A6D68 | class MetaClass mmGameManagerMetaClass | ?mmGameManagerMetaClass@@3VMetaClass@@A
    0x6A6D94 | private: static class mmGameManager * mmGameManager::Instance | ?Instance@mmGameManager@@0PAV1@A
*/

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
    // ??_EmmScreenClearFlunky@@UAEPAXI@Z
    // ??_GmmScreenClearFlunky@@UAEPAXI@Z
    // ??1mmScreenClearFlunky@@UAE@XZ | inline
    ARTS_IMPORT ~mmScreenClearFlunky() override = default;

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

    // ??_EmmGameManager@@UAEPAXI@Z
    // ??1mmGameManager@@UAE@XZ
    ARTS_IMPORT ~mmGameManager() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmGameManager@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?BeDone@mmGameManager@@QAEXXZ
    ARTS_IMPORT void BeDone();

    // ?Cull@mmGameManager@@UAEXXZ
    ARTS_IMPORT void Cull() override;

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
    ARTS_IMPORT void Reset() override;

    // ?SaveReplay@mmGameManager@@QAEXPAD@Z
    ARTS_IMPORT void SaveReplay(aconst char* arg1);

    // ?StartReplay@mmGameManager@@QAEXXZ
    ARTS_IMPORT void StartReplay();

    // ?Update@mmGameManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmGameManager@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    mmGame* Current;

private:
    friend mmGameManager* GameManager();

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
    i32 Frame;
    i32 PendingFrames;
    b32 NeedsReset;
    agiBitmap* ReplayBitmap;
    i32 field_58;
};

check_size(mmGameManager, 0x5C);

inline mmGameManager* GameManager()
{
    return mmGameManager::Instance;
}

// ?ReplayLog@@3PAVStream@@A
ARTS_IMPORT extern Stream* ReplayLog;

// ?ScreenClearCount@@3HA
ARTS_IMPORT extern i32 ScreenClearCount;

// ?dummyGlobal2@@3EA
ARTS_IMPORT extern u8 dummyGlobal2;
