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
    mmcar:transmission

    0x470430 | public: __thiscall mmTransmission::mmTransmission(void) | ??0mmTransmission@@QAE@XZ
    0x470500 | public: void __thiscall mmTransmission::Init(class mmCarSim *) | ?Init@mmTransmission@@QAEXPAVmmCarSim@@@Z
    0x470540 | public: virtual void __thiscall mmTransmission::Reset(void) | ?Reset@mmTransmission@@UAEXXZ
    0x470570 | public: int __thiscall mmTransmission::Upshift(void) | ?Upshift@mmTransmission@@QAEHXZ
    0x4705A0 | public: int __thiscall mmTransmission::Downshift(void) | ?Downshift@mmTransmission@@QAEHXZ
    0x4705C0 | public: virtual void __thiscall mmTransmission::Update(void) | ?Update@mmTransmission@@UAEXXZ
    0x4706C0 | public: void __thiscall mmTransmission::CopyTrans(void) | ?CopyTrans@mmTransmission@@QAEXXZ
    0x4706F0 | public: void __thiscall mmTransmission::Automatic(int) | ?Automatic@mmTransmission@@QAEXH@Z
    0x470710 | public: void __thiscall mmTransmission::SetReverse(void) | ?SetReverse@mmTransmission@@QAEXXZ
    0x470720 | public: void __thiscall mmTransmission::SetDrive(void) | ?SetDrive@mmTransmission@@QAEXXZ
    0x470740 | public: int __thiscall mmTransmission::GetCurrentGear(void) | ?GetCurrentGear@mmTransmission@@QAEHXZ
    0x470750 | public: int __thiscall mmTransmission::SetCurrentGear(int) | ?SetCurrentGear@mmTransmission@@QAEHH@Z
    0x470790 | public: virtual void __thiscall mmTransmission::AddWidgets(class Bank *) | ?AddWidgets@mmTransmission@@UAEXPAVBank@@@Z
    0x470A30 | public: static void __cdecl mmTransmission::DeclareFields(void) | ?DeclareFields@mmTransmission@@SAXXZ
    0x470C80 | public: virtual class MetaClass * __thiscall mmTransmission::GetClass(void) | ?GetClass@mmTransmission@@UAEPAVMetaClass@@XZ
    0x470CC0 | struct MetaType * __cdecl ArrayOf(struct MetaType *,int) | ?ArrayOf@@YAPAUMetaType@@PAU1@H@Z
    0x470CF0 | public: virtual void * __thiscall mmTransmission::`vector deleting destructor'(unsigned int) | ??_EmmTransmission@@UAEPAXI@Z
    0x61BF18 | const mmTransmission::`vftable' | ??_7mmTransmission@@6B@
    0x61BF58 | const ArrayOfType::`vftable' | ??_7ArrayOfType@@6B@
    0x6A7CB8 | class MetaClass mmTransmissionMetaClass | ?mmTransmissionMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class mmTransmission : public asNode
{
    // const mmTransmission::`vftable' @ 0x61BF18

public:
    // 0x470430 | ??0mmTransmission@@QAE@XZ
    mmTransmission();

    // 0x470CF0 | ??_EmmTransmission@@UAEPAXI@Z
    // 0x470390 | ??1mmTransmission@@UAE@XZ
    ~mmTransmission() override;

    // 0x470790 | ?AddWidgets@mmTransmission@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x4706F0 | ?Automatic@mmTransmission@@QAEXH@Z
    void Automatic(i32 arg1);

    // 0x4706C0 | ?CopyTrans@mmTransmission@@QAEXXZ
    void CopyTrans();

    // 0x4705A0 | ?Downshift@mmTransmission@@QAEHXZ
    i32 Downshift();

    // 0x470C80 | ?GetClass@mmTransmission@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x470740 | ?GetCurrentGear@mmTransmission@@QAEHXZ
    i32 GetCurrentGear();

    // 0x470500 | ?Init@mmTransmission@@QAEXPAVmmCarSim@@@Z
    void Init(class mmCarSim* arg1);

    // 0x470540 | ?Reset@mmTransmission@@UAEXXZ
    void Reset() override;

    // 0x470750 | ?SetCurrentGear@mmTransmission@@QAEHH@Z
    i32 SetCurrentGear(i32 arg1);

    // 0x470720 | ?SetDrive@mmTransmission@@QAEXXZ
    void SetDrive();

    // 0x470710 | ?SetReverse@mmTransmission@@QAEXXZ
    void SetReverse();

    // 0x4705C0 | ?Update@mmTransmission@@UAEXXZ
    void Update() override;

    // 0x470570 | ?Upshift@mmTransmission@@QAEHXZ
    i32 Upshift();

    // 0x470A30 | ?DeclareFields@mmTransmission@@SAXXZ
    static void DeclareFields();
};

check_size(mmTransmission, 0xD4);

// 0x470CC0 | ?ArrayOf@@YAPAUMetaType@@PAU1@H@Z
struct MetaType* ArrayOf(struct MetaType* arg1, i32 arg2);

// 0x6A7CB8 | ?mmTransmissionMetaClass@@3VMetaClass@@A
inline extern_var(0x2A7CB8_Offset, class MetaClass, mmTransmissionMetaClass);
