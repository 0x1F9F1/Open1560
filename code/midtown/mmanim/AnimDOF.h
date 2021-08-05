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
    mmanim:AnimDOF

    0x4C4460 | public: virtual void __fastcall mmDrawbridgeInstance::Draw(int) | ?Draw@mmDrawbridgeInstance@@UAIXH@Z
    0x4C4510 | public: int __thiscall mmDrawbridgeInstance::InitBridge(char *,char *,int,class Matrix34 *,class Vector3 *) | ?InitBridge@mmDrawbridgeInstance@@QAEHPAD0HPAVMatrix34@@PAVVector3@@@Z
    0x4C4550 | public: __thiscall mmAnimDOF::mmAnimDOF(void) | ??0mmAnimDOF@@QAE@XZ
    0x4C4570 | public: __thiscall mmAnimDOF::~mmAnimDOF(void) | ??1mmAnimDOF@@QAE@XZ
    0x4C4580 | public: int __thiscall mmAnimDOF::Init(class mmAnimTrigger *,char *,class Vector3 &,class Vector3 &,int,int *) | ?Init@mmAnimDOF@@QAEHPAVmmAnimTrigger@@PADAAVVector3@@2HPAH@Z
    0x4C4900 | public: void __thiscall mmAnimDOF::Reset(void) | ?Reset@mmAnimDOF@@QAEXXZ
    0x4C4940 | public: void __thiscall mmAnimDOF::Update(void) | ?Update@mmAnimDOF@@QAEXXZ
    0x4C4B60 | public: void __thiscall mmAnimDOF::SetSwitch(int) | ?SetSwitch@mmAnimDOF@@QAEXH@Z
    0x4C4BB0 | public: void __thiscall mmAnimDOF::SetState(int) | ?SetState@mmAnimDOF@@QAEXH@Z
    0x4C4BF0 | public: static void __cdecl mmAnimDOF::DeclareFields(void) | ?DeclareFields@mmAnimDOF@@SAXXZ
    0x4C4D80 | public: virtual class MetaClass * __thiscall mmAnimDOF::GetClass(void) | ?GetClass@mmAnimDOF@@UAEPAVMetaClass@@XZ
    0x4C4D90 | public: virtual void * __thiscall mmDrawbridgeInstance::`vector deleting destructor'(unsigned int) | ??_EmmDrawbridgeInstance@@UAEPAXI@Z
    0x4C4D90 | public: virtual void * __thiscall mmDrawbridgeInstance::`scalar deleting destructor'(unsigned int) | ??_GmmDrawbridgeInstance@@UAEPAXI@Z
    0x4C4DB0 | public: virtual __thiscall mmDrawbridgeInstance::~mmDrawbridgeInstance(void) | ??1mmDrawbridgeInstance@@UAE@XZ
    0x4C4DC0 | public: void * __thiscall mmAnimDOF::`vector deleting destructor'(unsigned int) | ??_EmmAnimDOF@@QAEPAXI@Z
    0x4C4E20 | public: __thiscall mmUnhitBangerInstance::mmUnhitBangerInstance(void) | ??0mmUnhitBangerInstance@@QAE@XZ
    0x4C4E50 | public: virtual void __fastcall mmDofBangerInstance::FromMatrix(class Matrix34 const &) | ?FromMatrix@mmDofBangerInstance@@UAIXABVMatrix34@@@Z
    0x4C4E60 | public: virtual class Matrix34 & __fastcall mmDofBangerInstance::ToMatrix(class Matrix34 &) | ?ToMatrix@mmDofBangerInstance@@UAIAAVMatrix34@@AAV2@@Z
    0x4C4E90 | public: virtual class Vector3 & __fastcall mmDofBangerInstance::GetPos(void) | ?GetPos@mmDofBangerInstance@@UAIAAVVector3@@XZ
    0x4C4EC0 | public: virtual void * __thiscall mmDofBangerInstance::`vector deleting destructor'(unsigned int) | ??_EmmDofBangerInstance@@UAEPAXI@Z
    0x4C4EC0 | public: virtual void * __thiscall mmDofBangerInstance::`scalar deleting destructor'(unsigned int) | ??_GmmDofBangerInstance@@UAEPAXI@Z
    0x4C4EE0 | public: virtual __thiscall mmDofBangerInstance::~mmDofBangerInstance(void) | ??1mmDofBangerInstance@@UAE@XZ
    0x61F470 | const mmAnimDOF::`vftable' | ??_7mmAnimDOF@@6B@
    0x61F478 | const mmDofBangerInstance::`vftable' | ??_7mmDofBangerInstance@@6B@
    0x61F4D8 | const mmDrawbridgeInstance::`vftable' | ??_7mmDrawbridgeInstance@@6B@
    0x705E20 | class MetaClass mmAnimDOFMetaClass | ?mmAnimDOFMetaClass@@3VMetaClass@@A
*/

#include "mmbangers/dof.h"

class mmDrawbridgeInstance final : public mmDofBangerInstance
{
    // const mmDrawbridgeInstance::`vftable'

public:
    // ??_GmmDrawbridgeInstance@@UAEPAXI@Z
    // ??_EmmDrawbridgeInstance@@UAEPAXI@Z
    // ??1mmDrawbridgeInstance@@UAE@XZ | inline
    ARTS_IMPORT ~mmDrawbridgeInstance() override = default;

    // ?Draw@mmDrawbridgeInstance@@UAIXH@Z
    ARTS_EXPORT void ARTS_FASTCALL Draw(i32 lod) override;

    // ?InitBridge@mmDrawbridgeInstance@@QAEHPAD0HPAVMatrix34@@PAVVector3@@@Z
    ARTS_IMPORT i32 InitBridge(char* arg1, char* arg2, i32 arg3, class Matrix34* arg4, class Vector3* arg5);
};

check_size(mmDrawbridgeInstance, 0x34);

class mmAnimDOF final
{
    // const mmAnimDOF::`vftable'

public:
    // ??0mmAnimDOF@@QAE@XZ
    ARTS_IMPORT mmAnimDOF();

    // ??_EmmAnimDOF@@QAEPAXI@Z | unused
    // ??1mmAnimDOF@@QAE@XZ
    ARTS_IMPORT ~mmAnimDOF() = default;

    // ?GetClass@mmAnimDOF@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT virtual class MetaClass* GetClass();

    // ?Init@mmAnimDOF@@QAEHPAVmmAnimTrigger@@PADAAVVector3@@2HPAH@Z
    ARTS_IMPORT i32 Init(
        class mmAnimTrigger* arg1, char* arg2, class Vector3& arg3, class Vector3& arg4, i32 arg5, i32* arg6);

    // ?Reset@mmAnimDOF@@QAEXXZ
    ARTS_IMPORT void Reset();

    // ?SetState@mmAnimDOF@@QAEXH@Z
    ARTS_IMPORT void SetState(i32 arg1);

    // ?SetSwitch@mmAnimDOF@@QAEXH@Z
    ARTS_IMPORT void SetSwitch(i32 arg1);

    // ?Update@mmAnimDOF@@QAEXXZ
    ARTS_IMPORT void Update();

    // ?DeclareFields@mmAnimDOF@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap4[0x94];
};

check_size(mmAnimDOF, 0x98);

// ?mmAnimDOFMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmAnimDOFMetaClass;
