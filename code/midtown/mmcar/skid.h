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
    mmcar:skid

    0x477850 | public: __thiscall mmSkid::mmSkid(void) | ??0mmSkid@@QAE@XZ
    0x477870 | public: void __thiscall mmSkid::Init(char *) | ?Init@mmSkid@@QAEXPAD@Z
    0x477890 | public: virtual __thiscall mmSkid::~mmSkid(void) | ??1mmSkid@@UAE@XZ
    0x4778A0 | public: void __thiscall mmSkid::AddSkid(class Matrix34 &,class Vector3 *,class agiPhysParameters *,float) | ?AddSkid@mmSkid@@QAEXAAVMatrix34@@PAVVector3@@PAVagiPhysParameters@@M@Z
    0x477A60 | public: virtual void __fastcall mmSkid::FromMatrix(class Matrix34 const &) | ?FromMatrix@mmSkid@@UAIXABVMatrix34@@@Z
    0x477A70 | public: virtual class Matrix34 & __fastcall mmSkid::ToMatrix(class Matrix34 &) | ?ToMatrix@mmSkid@@UAIAAVMatrix34@@AAV2@@Z
    0x477A80 | public: virtual class Vector3 & __fastcall mmSkid::GetPos(void) | ?GetPos@mmSkid@@UAIAAVVector3@@XZ
    0x477A90 | public: void __thiscall mmSkid::Update(void) | ?Update@mmSkid@@QAEXXZ
    0x477AA0 | public: virtual void __fastcall mmSkid::Draw(int) | ?Draw@mmSkid@@UAIXH@Z
    0x477B30 | public: virtual void __fastcall mmSkid::DrawShadow(void) | ?DrawShadow@mmSkid@@UAIXXZ
    0x477B40 | public: __thiscall mmSkidManager::mmSkidManager(void) | ??0mmSkidManager@@QAE@XZ
    0x477B70 | public: virtual __thiscall mmSkidManager::~mmSkidManager(void) | ??1mmSkidManager@@UAE@XZ
    0x477BD0 | public: void __thiscall mmSkidManager::Init(char *,int,class mmWheel *) | ?Init@mmSkidManager@@QAEXPADHPAVmmWheel@@@Z
    0x477C90 | public: void __thiscall mmSkidManager::ReInit(class mmWheel *) | ?ReInit@mmSkidManager@@QAEXPAVmmWheel@@@Z
    0x477CC0 | public: virtual void __thiscall mmSkidManager::Reset(void) | ?Reset@mmSkidManager@@UAEXXZ
    0x477D10 | public: void __thiscall mmSkidManager::LayTrack(void) | ?LayTrack@mmSkidManager@@QAEXXZ
    0x4780A0 | public: virtual void __thiscall mmSkidManager::Update(void) | ?Update@mmSkidManager@@UAEXXZ
    0x478180 | public: static void __cdecl mmSkid::DeclareFields(void) | ?DeclareFields@mmSkid@@SAXXZ
    0x478300 | public: virtual class MetaClass * __thiscall mmSkid::GetClass(void) | ?GetClass@mmSkid@@UAEPAVMetaClass@@XZ
    0x478310 | public: static void __cdecl mmSkidManager::DeclareFields(void) | ?DeclareFields@mmSkidManager@@SAXXZ
    0x478470 | public: virtual class MetaClass * __thiscall mmSkidManager::GetClass(void) | ?GetClass@mmSkidManager@@UAEPAVMetaClass@@XZ
    0x478480 | public: virtual void * __thiscall mmSkid::`vector deleting destructor'(unsigned int) | ??_EmmSkid@@UAEPAXI@Z
    0x4784E0 | public: virtual void * __thiscall mmSkidManager::`vector deleting destructor'(unsigned int) | ??_EmmSkidManager@@UAEPAXI@Z
    0x478540 | public: __thiscall Matrix34::Matrix34(void) | ??0Matrix34@@QAE@XZ
    0x478550 | public: virtual void __thiscall mmSkid::AddWidgets(class Bank *) | ?AddWidgets@mmSkid@@UAEXPAVBank@@@Z
    0x61C208 | const mmSkid::`vftable' | ??_7mmSkid@@6B@
    0x61C280 | const mmSkidManager::`vftable' | ??_7mmSkidManager@@6B@
    0x6A7EA0 | class MetaClass mmSkidMetaClass | ?mmSkidMetaClass@@3VMetaClass@@A
    0x6A7EC8 | class MetaClass mmSkidManagerMetaClass | ?mmSkidManagerMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"
#include "mmcity/inst.h"

class mmSkid : public mmInstance
{
    // const mmSkid::`vftable' @ 0x61C208

public:
    // 0x477850 | ??0mmSkid@@QAE@XZ
    ARTS_IMPORT mmSkid();

    // 0x478480 | ??_EmmSkid@@UAEPAXI@Z
    // 0x477890 | ??1mmSkid@@UAE@XZ
    ARTS_IMPORT ~mmSkid() override;

    // 0x4778A0 | ?AddSkid@mmSkid@@QAEXAAVMatrix34@@PAVVector3@@PAVagiPhysParameters@@M@Z
    ARTS_IMPORT void AddSkid(class Matrix34& arg1, class Vector3* arg2, class agiPhysParameters* arg3, f32 arg4);

    // 0x478550 | ?AddWidgets@mmSkid@@UAEXPAVBank@@@Z | inline
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x477AA0 | ?Draw@mmSkid@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // 0x477B30 | ?DrawShadow@mmSkid@@UAIXXZ
    ARTS_IMPORT void ARTS_FASTCALL DrawShadow() override;

    // 0x477A60 | ?FromMatrix@mmSkid@@UAIXABVMatrix34@@@Z
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(class Matrix34 const& arg1) override;

    // 0x478300 | ?GetClass@mmSkid@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x477A80 | ?GetPos@mmSkid@@UAIAAVVector3@@XZ
    ARTS_IMPORT class Vector3& ARTS_FASTCALL GetPos() override;

    // 0x477870 | ?Init@mmSkid@@QAEXPAD@Z
    ARTS_IMPORT void Init(char* arg1);

    // 0x477A70 | ?ToMatrix@mmSkid@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT class Matrix34& ARTS_FASTCALL ToMatrix(class Matrix34& arg1) override;

    // 0x477A90 | ?Update@mmSkid@@QAEXXZ | unused
    ARTS_IMPORT void Update();

    // 0x478180 | ?DeclareFields@mmSkid@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap14[0x34];
};

check_size(mmSkid, 0x48);

class mmSkidManager : public asNode
{
    // const mmSkidManager::`vftable' @ 0x61C280

public:
    // 0x477B40 | ??0mmSkidManager@@QAE@XZ
    ARTS_IMPORT mmSkidManager();

    // 0x4784E0 | ??_EmmSkidManager@@UAEPAXI@Z
    // 0x477B70 | ??1mmSkidManager@@UAE@XZ
    ARTS_IMPORT ~mmSkidManager() override;

    // 0x478470 | ?GetClass@mmSkidManager@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x477BD0 | ?Init@mmSkidManager@@QAEXPADHPAVmmWheel@@@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2, class mmWheel* arg3);

    // 0x477D10 | ?LayTrack@mmSkidManager@@QAEXXZ
    ARTS_IMPORT void LayTrack();

    // 0x477C90 | ?ReInit@mmSkidManager@@QAEXPAVmmWheel@@@Z
    ARTS_IMPORT void ReInit(class mmWheel* arg1);

    // 0x477CC0 | ?Reset@mmSkidManager@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4780A0 | ?Update@mmSkidManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x478310 | ?DeclareFields@mmSkidManager@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x48];
};

check_size(mmSkidManager, 0x68);

// 0x6A7EC8 | ?mmSkidManagerMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmSkidManagerMetaClass;

// 0x6A7EA0 | ?mmSkidMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmSkidMetaClass;
