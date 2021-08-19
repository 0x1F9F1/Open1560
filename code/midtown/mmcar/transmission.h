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

class mmCarSim;

class mmTransmission final : public asNode
{
public:
    // ??0mmTransmission@@QAE@XZ
    ARTS_IMPORT mmTransmission();

    // ??_EmmTransmission@@UAEPAXI@Z
    // ??1mmTransmission@@UAE@XZ | inline
    ARTS_IMPORT ~mmTransmission() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmTransmission@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // ?Automatic@mmTransmission@@QAEXH@Z
    ARTS_IMPORT void Automatic(i32 arg1);

    // ?CopyTrans@mmTransmission@@QAEXXZ
    ARTS_IMPORT void CopyTrans();

    // ?Downshift@mmTransmission@@QAEHXZ
    ARTS_IMPORT i32 Downshift();

    // ?GetClass@mmTransmission@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?GetCurrentGear@mmTransmission@@QAEHXZ
    ARTS_IMPORT i32 GetCurrentGear();

    // ?Init@mmTransmission@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void Init(class mmCarSim* arg1);

    // ?Reset@mmTransmission@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetCurrentGear@mmTransmission@@QAEHH@Z
    ARTS_IMPORT i32 SetCurrentGear(i32 arg1);

    // ?SetDrive@mmTransmission@@QAEXXZ
    ARTS_IMPORT void SetDrive();

    // ?SetReverse@mmTransmission@@QAEXXZ
    ARTS_IMPORT void SetReverse();

    // ?Update@mmTransmission@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?Upshift@mmTransmission@@QAEHXZ
    ARTS_IMPORT i32 Upshift();

    // ?DeclareFields@mmTransmission@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    mmCarSim* CarSim;
    b32 IsAutomatic;
    f32 Clutch;
    f32 UpshiftThreshold;
    f32 DownshiftThreshold;
    i32 NumGears;
    f32 GearRatios[8];
    f32 UpshiftRPM[8];
    f32 DownshiftRPM[8];
    f32 ManualGearRatios[8];
    i32 ManualNumGears;
    f32 DownshiftBias;
    b32 GearChanged;
    b32 InPark;
    i32 CurrentGear;
    f32 TimeInGear;
    f32 GearChangeDelay;
};

check_size(mmTransmission, 0xD4);

// ?ArrayOf@@YAPAUMetaType@@PAU1@H@Z | inline
ARTS_IMPORT struct MetaType* ArrayOf(struct MetaType* arg1, i32 arg2);

// ?mmTransmissionMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmTransmissionMetaClass;
