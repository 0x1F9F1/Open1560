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
    mmcity:ped

    0x497800 | public: __thiscall mmPed::mmPed(void) | ??0mmPed@@QAE@XZ
    0x497820 | public: void __thiscall mmPed::Init(char *,class Vector3 &) | ?Init@mmPed@@QAEXPADAAVVector3@@@Z
    0x4978B0 | public: virtual __thiscall mmPed::~mmPed(void) | ??1mmPed@@UAE@XZ
    0x4978C0 | public: void __thiscall mmPed::Update(void) | ?Update@mmPed@@QAEXXZ
    0x4978E0 | public: virtual void __fastcall mmPed::Draw(int) | ?Draw@mmPed@@UAIXH@Z
    0x497930 | public: virtual class Matrix34 & __fastcall mmPed::ToMatrix(class Matrix34 &) | ?ToMatrix@mmPed@@UAIAAVMatrix34@@AAV2@@Z
    0x497980 | public: __thiscall mmPedManager::mmPedManager(void) | ??0mmPedManager@@QAE@XZ
    0x4979A0 | public: virtual __thiscall mmPedManager::~mmPedManager(void) | ??1mmPedManager@@UAE@XZ
    0x4979B0 | public: void __thiscall mmPedManager::Init(int) | ?Init@mmPedManager@@QAEXH@Z
    0x497A60 | public: virtual void __thiscall mmPedManager::Update(void) | ?Update@mmPedManager@@UAEXXZ
    0x497A90 | public: static void __cdecl mmPed::DeclareFields(void) | ?DeclareFields@mmPed@@SAXXZ
    0x497C10 | public: virtual class MetaClass * __thiscall mmPed::GetClass(void) | ?GetClass@mmPed@@UAEPAVMetaClass@@XZ
    0x497C20 | public: static void __cdecl mmPedManager::DeclareFields(void) | ?DeclareFields@mmPedManager@@SAXXZ
    0x497D80 | public: virtual class MetaClass * __thiscall mmPedManager::GetClass(void) | ?GetClass@mmPedManager@@UAEPAVMetaClass@@XZ
    0x497D90 | public: virtual void * __thiscall mmPed::`vector deleting destructor'(unsigned int) | ??_EmmPed@@UAEPAXI@Z
    0x497DF0 | public: virtual void * __thiscall mmPedManager::`vector deleting destructor'(unsigned int) | ??_EmmPedManager@@UAEPAXI@Z
    0x61D268 | const mmPed::`vftable' | ??_7mmPed@@6B@
    0x61D2D0 | const mmPedManager::`vftable' | ??_7mmPedManager@@6B@
    0x705740 | class MetaClass mmPedManagerMetaClass | ?mmPedManagerMetaClass@@3VMetaClass@@A
    0x705768 | class MetaClass mmPedMetaClass | ?mmPedMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"
#include "inst.h"

class mmPed /*final*/ : public mmYInstance
{
    // const mmPed::`vftable' @ 0x61D268

public:
    // 0x497800 | ??0mmPed@@QAE@XZ
    ARTS_IMPORT mmPed();

    // 0x497D90 | ??_EmmPed@@UAEPAXI@Z
    // 0x4978B0 | ??1mmPed@@UAE@XZ
    ARTS_IMPORT ~mmPed() override = default;

    // 0x4978E0 | ?Draw@mmPed@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // 0x497C10 | ?GetClass@mmPed@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x497820 | ?Init@mmPed@@QAEXPADAAVVector3@@@Z
    ARTS_IMPORT void Init(char* arg1, class Vector3& arg2);

    // 0x497930 | ?ToMatrix@mmPed@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT class Matrix34& ARTS_FASTCALL ToMatrix(class Matrix34& arg1) override;

    // 0x4978C0 | ?Update@mmPed@@QAEXXZ
    ARTS_IMPORT void Update();

    // 0x497A90 | ?DeclareFields@mmPed@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap2C[0x8];
};

check_size(mmPed, 0x34);

class mmPedManager /*final*/ : public asNode
{
    // const mmPedManager::`vftable' @ 0x61D2D0

public:
    // 0x497980 | ??0mmPedManager@@QAE@XZ
    ARTS_IMPORT mmPedManager();

    // 0x497DF0 | ??_EmmPedManager@@UAEPAXI@Z
    // 0x4979A0 | ??1mmPedManager@@UAE@XZ
    ARTS_IMPORT ~mmPedManager() override = default;

    // 0x497D80 | ?GetClass@mmPedManager@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4979B0 | ?Init@mmPedManager@@QAEXH@Z | unused
    ARTS_IMPORT void Init(i32 arg1);

    // 0x497A60 | ?Update@mmPedManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x497C20 | ?DeclareFields@mmPedManager@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0xC];
};

check_size(mmPedManager, 0x2C);

// 0x705740 | ?mmPedManagerMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmPedManagerMetaClass;

// 0x705768 | ?mmPedMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmPedMetaClass;
