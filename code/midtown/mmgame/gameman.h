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

/*
    mmgame:gameman

    0x403CE0 | public: virtual void __thiscall mmScreenClearFlunky::Update(void) | ?Update@mmScreenClearFlunky@@UAEXXZ
    0x403D10 | public: virtual void __thiscall mmScreenClearFlunky::Cull(void) | ?Cull@mmScreenClearFlunky@@UAEXXZ
    0x403E50 | public: __thiscall mmGameManager::mmGameManager(void) | ??0mmGameManager@@QAE@XZ
    0x4043B0 | public: virtual __thiscall mmGameManager::~mmGameManager(void) | ??1mmGameManager@@UAE@XZ
    0x4044C0 | public: void __thiscall mmGameManager::BeDone(void) | ?BeDone@mmGameManager@@QAEXXZ
    0x4044D0 | public: virtual void __thiscall mmGameManager::Update(void) | ?Update@mmGameManager@@UAEXXZ
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

class mmScreenClearFlunky : public asNode
{
    // const mmScreenClearFlunky::`vftable' @ 0x61A0D8

public:
    // 0x404B70 | ??_EmmScreenClearFlunky@@UAEPAXI@Z
    // 0x404BA0 | ??1mmScreenClearFlunky@@UAE@XZ
    ~mmScreenClearFlunky() override;

    // 0x403D10 | ?Cull@mmScreenClearFlunky@@UAEXXZ
    void Cull() override;

    // 0x403CE0 | ?Update@mmScreenClearFlunky@@UAEXXZ
    void Update() override;
};

check_size(mmScreenClearFlunky, 0x0);

class mmGameManager : public asNode
{
    // const mmGameManager::`vftable' @ 0x61A118

public:
    // 0x403E50 | ??0mmGameManager@@QAE@XZ
    mmGameManager();

    // 0x404BC0 | ??_EmmGameManager@@UAEPAXI@Z
    // 0x4043B0 | ??1mmGameManager@@UAE@XZ
    ~mmGameManager() override;

    // 0x4049B0 | ?AddWidgets@mmGameManager@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x4044C0 | ?BeDone@mmGameManager@@QAEXXZ
    void BeDone();

    // 0x404750 | ?Cull@mmGameManager@@UAEXXZ
    void Cull() override;

    // 0x404920 | ?GetBrakes@mmGameManager@@QAEMXZ
    f32 GetBrakes();

    // 0x404B30 | ?GetClass@mmGameManager@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x404950 | ?GetSteering@mmGameManager@@QAEMXZ
    f32 GetSteering();

    // 0x404980 | ?GetThrottle@mmGameManager@@QAEMXZ
    f32 GetThrottle();

    // 0x4047B0 | ?LoadReplay@mmGameManager@@QAEXPAD@Z
    void LoadReplay(char* arg1);

    // 0x404910 | ?Reset@mmGameManager@@UAEXXZ
    void Reset() override;

    // 0x404880 | ?SaveReplay@mmGameManager@@QAEXPAD@Z
    void SaveReplay(char* arg1);

    // 0x404790 | ?StartReplay@mmGameManager@@QAEXXZ
    void StartReplay();

    // 0x4044D0 | ?Update@mmGameManager@@UAEXXZ
    void Update() override;

    // 0x4049C0 | ?DeclareFields@mmGameManager@@SAXXZ
    static void DeclareFields();

private:
    // 0x6A6D94 | ?Instance@mmGameManager@@0PAV1@A
    static inline extern_var(0x2A6D94_Offset, class mmGameManager*, Instance);
};

check_size(mmGameManager, 0x5C);

// 0x6A6D60 | ?ReplayLog@@3PAVStream@@A
inline extern_var(0x2A6D60_Offset, class Stream*, ReplayLog);

// 0x6A6D58 | ?ScreenClearCount@@3HA
inline extern_var(0x2A6D58_Offset, i32, ScreenClearCount);

// 0x67216C | ?dummyGlobal2@@3EA
inline extern_var(0x27216C_Offset, u8, dummyGlobal2);

// 0x6A6D68 | ?mmGameManagerMetaClass@@3VMetaClass@@A
inline extern_var(0x2A6D68_Offset, class MetaClass, mmGameManagerMetaClass);
