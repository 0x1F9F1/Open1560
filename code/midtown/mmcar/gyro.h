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
    mmcar:gyro

    0x480660 | public: __thiscall VehGyro::VehGyro(void) | ??0VehGyro@@QAE@XZ
    0x480690 | public: void __thiscall VehGyro::Load(class Stream *) | ?Load@VehGyro@@QAEXPAVStream@@@Z
    0x480700 | public: void __thiscall VehGyro::Save(class Stream *) | ?Save@VehGyro@@QAEXPAVStream@@@Z
    0x480780 | public: virtual void __thiscall VehGyro::Update(void) | ?Update@VehGyro@@UAEXXZ
    0x480930 | public: virtual void __thiscall VehGyro::AddWidgets(class Bank *) | ?AddWidgets@VehGyro@@UAEXPAVBank@@@Z
    0x4809E0 | public: static void __cdecl VehGyro::DeclareFields(void) | ?DeclareFields@VehGyro@@SAXXZ
    0x480B70 | public: virtual class MetaClass * __thiscall VehGyro::GetClass(void) | ?GetClass@VehGyro@@UAEPAVMetaClass@@XZ
    0x480B80 | public: virtual void * __thiscall VehGyro::`vector deleting destructor'(unsigned int) | ??_EVehGyro@@UAEPAXI@Z
    0x61C810 | const VehGyro::`vftable' | ??_7VehGyro@@6B@
    0x6A8120 | class MetaClass VehGyroMetaClass | ?VehGyroMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class VehGyro final : public asNode
{
    // const VehGyro::`vftable' @ 0x61C810

public:
    // 0x480660 | ??0VehGyro@@QAE@XZ
    ARTS_IMPORT VehGyro();

    // 0x480B80 | ??_EVehGyro@@UAEPAXI@Z
    // 0x470340 | ??1VehGyro@@UAE@XZ | inline
    ARTS_IMPORT ~VehGyro() override = default;

    // 0x480930 | ?AddWidgets@VehGyro@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x480B70 | ?GetClass@VehGyro@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x480690 | ?Load@VehGyro@@QAEXPAVStream@@@Z | unused
    ARTS_IMPORT void Load(class Stream* arg1);

    // 0x480700 | ?Save@VehGyro@@QAEXPAVStream@@@Z | unused
    ARTS_IMPORT void Save(class Stream* arg1);

    // 0x480780 | ?Update@VehGyro@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4809E0 | ?DeclareFields@VehGyro@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x14];
};

check_size(VehGyro, 0x34);

// 0x6A8120 | ?VehGyroMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass VehGyroMetaClass;
