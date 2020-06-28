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
    mmcar:shock

    0x47D1F0 | public: __thiscall mmShock::mmShock(void) | ??0mmShock@@QAE@XZ
    0x47D210 | public: void __thiscall mmShock::Init(char *,char *,class mmWheel *) | ?Init@mmShock@@QAEXPAD0PAVmmWheel@@@Z
    0x47D270 | public: virtual void __thiscall mmShock::Update(void) | ?Update@mmShock@@UAEXXZ
    0x47D280 | public: virtual void __thiscall mmShock::AddWidgets(class Bank *) | ?AddWidgets@mmShock@@UAEXPAVBank@@@Z
    0x47D2A0 | public: static void __cdecl mmShock::DeclareFields(void) | ?DeclareFields@mmShock@@SAXXZ
    0x47D410 | public: virtual class MetaClass * __thiscall mmShock::GetClass(void) | ?GetClass@mmShock@@UAEPAVMetaClass@@XZ
    0x47D420 | public: virtual void * __thiscall mmShock::`vector deleting destructor'(unsigned int) | ??_EmmShock@@UAEPAXI@Z
    0x61C640 | const mmShock::`vftable' | ??_7mmShock@@6B@
    0x6A8058 | class MetaClass mmShockMetaClass | ?mmShockMetaClass@@3VMetaClass@@A
*/

#include "arts7/linear.h"

class mmShock : public asLinearCS
{
    // const mmShock::`vftable' @ 0x61C640

public:
    // 0x47D1F0 | ??0mmShock@@QAE@XZ
    ARTS_IMPORT mmShock();

    // 0x47D420 | ??_EmmShock@@UAEPAXI@Z
    // 0x470380 | ??1mmShock@@UAE@XZ | inline
    ARTS_IMPORT ~mmShock() override = default;

    // 0x47D280 | ?AddWidgets@mmShock@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x47D410 | ?GetClass@mmShock@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x47D210 | ?Init@mmShock@@QAEXPAD0PAVmmWheel@@@Z | unused
    ARTS_IMPORT void Init(char* arg1, char* arg2, class mmWheel* arg3);

    // 0x47D270 | ?Update@mmShock@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x47D2A0 | ?DeclareFields@mmShock@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0x10];
};

check_size(mmShock, 0x98);

// 0x6A8058 | ?mmShockMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmShockMetaClass;
