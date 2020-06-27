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

class mmScreenClearFlunky : public asNode
{
    // const mmScreenClearFlunky::`vftable' @ 0x61A0D8

public:
    // 0x404B70 | ??_EmmScreenClearFlunky@@UAEPAXI@Z
    // 0x404B70 | ??_GmmScreenClearFlunky@@UAEPAXI@Z
    // 0x404BA0 | ??1mmScreenClearFlunky@@UAE@XZ | inline
    ARTS_IMPORT ~mmScreenClearFlunky() override = default;

    // 0x403D10 | ?Cull@mmScreenClearFlunky@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x403CE0 | ?Update@mmScreenClearFlunky@@UAEXXZ
    ARTS_IMPORT void Update() override;
};

check_size(mmScreenClearFlunky, 0x20);

class mmGameManager : public asNode
{
    // const mmGameManager::`vftable' @ 0x61A118

public:
    // 0x403E50 | ??0mmGameManager@@QAE@XZ
    ARTS_IMPORT mmGameManager();

    // 0x404BC0 | ??_EmmGameManager@@UAEPAXI@Z
    // 0x4043B0 | ??1mmGameManager@@UAE@XZ
    ARTS_IMPORT ~mmGameManager() override;

    // 0x4049B0 | ?AddWidgets@mmGameManager@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x4044C0 | ?BeDone@mmGameManager@@QAEXXZ
    ARTS_IMPORT void BeDone();

    // 0x404750 | ?Cull@mmGameManager@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x404920 | ?GetBrakes@mmGameManager@@QAEMXZ
    ARTS_IMPORT f32 GetBrakes();

    // 0x404B30 | ?GetClass@mmGameManager@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x404950 | ?GetSteering@mmGameManager@@QAEMXZ
    ARTS_IMPORT f32 GetSteering();

    // 0x404980 | ?GetThrottle@mmGameManager@@QAEMXZ
    ARTS_IMPORT f32 GetThrottle();

    // 0x4047B0 | ?LoadReplay@mmGameManager@@QAEXPAD@Z
    ARTS_IMPORT void LoadReplay(char* arg1);

    // 0x404910 | ?Reset@mmGameManager@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x404880 | ?SaveReplay@mmGameManager@@QAEXPAD@Z
    ARTS_IMPORT void SaveReplay(char* arg1);

    // 0x404790 | ?StartReplay@mmGameManager@@QAEXXZ
    ARTS_IMPORT void StartReplay();

    // 0x4044D0 | ?Update@mmGameManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4049C0 | ?DeclareFields@mmGameManager@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // 0x6A6D94 | ?Instance@mmGameManager@@0PAV1@A
    ARTS_IMPORT static class mmGameManager* Instance;

    u8 gap20[0x3C];
};

check_size(mmGameManager, 0x5C);

// 0x6A6D60 | ?ReplayLog@@3PAVStream@@A
ARTS_IMPORT extern class Stream* ReplayLog;

// 0x6A6D58 | ?ScreenClearCount@@3HA
ARTS_IMPORT extern i32 ScreenClearCount;

// 0x67216C | ?dummyGlobal2@@3EA
ARTS_IMPORT extern u8 dummyGlobal2;

// 0x6A6D68 | ?mmGameManagerMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmGameManagerMetaClass;
