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
    mmcar:drivetrain

    0x47FE60 | public: __thiscall mmDrivetrain::mmDrivetrain(void) | ??0mmDrivetrain@@QAE@XZ
    0x47FE90 | public: void __thiscall mmDrivetrain::Init(class mmCarSim *) | ?Init@mmDrivetrain@@QAEXPAVmmCarSim@@@Z
    0x47FEC0 | public: void __thiscall mmDrivetrain::Attach(void) | ?Attach@mmDrivetrain@@QAEXXZ
    0x47FEE0 | public: void __thiscall mmDrivetrain::Detach(void) | ?Detach@mmDrivetrain@@QAEXXZ
    0x47FEF0 | public: int __thiscall mmDrivetrain::AddWheel(class mmWheel *) | ?AddWheel@mmDrivetrain@@QAEHPAVmmWheel@@@Z
    0x47FF30 | public: virtual void __thiscall mmDrivetrain::Update(void) | ?Update@mmDrivetrain@@UAEXXZ
    0x4803E0 | public: virtual void __thiscall mmDrivetrain::AddWidgets(class Bank *) | ?AddWidgets@mmDrivetrain@@UAEXPAVBank@@@Z
    0x480460 | public: static void __cdecl mmDrivetrain::DeclareFields(void) | ?DeclareFields@mmDrivetrain@@SAXXZ
    0x4805E0 | public: virtual class MetaClass * __thiscall mmDrivetrain::GetClass(void) | ?GetClass@mmDrivetrain@@UAEPAVMetaClass@@XZ
    0x4805F0 | public: virtual void * __thiscall mmDrivetrain::`vector deleting destructor'(unsigned int) | ??_EmmDrivetrain@@UAEPAXI@Z
    0x480650 | public: virtual void __thiscall mmDrivetrain::Reset(void) | ?Reset@mmDrivetrain@@UAEXXZ
    0x61C780 | const mmDrivetrain::`vftable' | ??_7mmDrivetrain@@6B@
    0x6A80F8 | class MetaClass mmDrivetrainMetaClass | ?mmDrivetrainMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class mmDrivetrain : public asNode
{
    // const mmDrivetrain::`vftable' @ 0x61C780

public:
    // 0x47FE60 | ??0mmDrivetrain@@QAE@XZ
    mmDrivetrain();

    // 0x4805F0 | ??_EmmDrivetrain@@UAEPAXI@Z
    // 0x470350 | ??1mmDrivetrain@@UAE@XZ
    ~mmDrivetrain() override;

    // 0x47FEF0 | ?AddWheel@mmDrivetrain@@QAEHPAVmmWheel@@@Z
    i32 AddWheel(class mmWheel* arg1);

    // 0x4803E0 | ?AddWidgets@mmDrivetrain@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x47FEC0 | ?Attach@mmDrivetrain@@QAEXXZ
    void Attach();

    // 0x47FEE0 | ?Detach@mmDrivetrain@@QAEXXZ
    void Detach();

    // 0x4805E0 | ?GetClass@mmDrivetrain@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x47FE90 | ?Init@mmDrivetrain@@QAEXPAVmmCarSim@@@Z
    void Init(class mmCarSim* arg1);

    // 0x480650 | ?Reset@mmDrivetrain@@UAEXXZ
    void Reset() override;

    // 0x47FF30 | ?Update@mmDrivetrain@@UAEXXZ
    void Update() override;

    // 0x480460 | ?DeclareFields@mmDrivetrain@@SAXXZ
    static void DeclareFields();
};

check_size(mmDrivetrain, 0x48);

// 0x6A80F8 | ?mmDrivetrainMetaClass@@3VMetaClass@@A
inline extern_var(0x2A80F8_Offset, class MetaClass, mmDrivetrainMetaClass);
