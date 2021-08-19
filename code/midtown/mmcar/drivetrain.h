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

class mmDrivetrain final : public asNode
{
public:
    // ??0mmDrivetrain@@QAE@XZ
    ARTS_IMPORT mmDrivetrain();

    // ??_EmmDrivetrain@@UAEPAXI@Z
    // ??1mmDrivetrain@@UAE@XZ | inline
    ARTS_IMPORT ~mmDrivetrain() override = default;

    // ?AddWheel@mmDrivetrain@@QAEHPAVmmWheel@@@Z
    ARTS_IMPORT i32 AddWheel(class mmWheel* arg1);

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmDrivetrain@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // ?Attach@mmDrivetrain@@QAEXXZ
    ARTS_IMPORT void Attach();

    // ?Detach@mmDrivetrain@@QAEXXZ
    ARTS_IMPORT void Detach();

    // ?GetClass@mmDrivetrain@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?Init@mmDrivetrain@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void Init(class mmCarSim* arg1);

    // ?Reset@mmDrivetrain@@UAEXXZ | inline
    ARTS_EXPORT void Reset() override;

    // ?Update@mmDrivetrain@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmDrivetrain@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x28];
};

check_size(mmDrivetrain, 0x48);

// ?mmDrivetrainMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmDrivetrainMetaClass;
