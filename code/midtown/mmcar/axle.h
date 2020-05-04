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

#include "arts7/linear.h"

/*
    mmcar:axle

    0x47D480 | public: __thiscall mmAxle::mmAxle(void) | ??0mmAxle@@QAE@XZ
    0x47D4A0 | public: void __thiscall mmAxle::Init(char *,char *,class mmWheel *,class mmWheel *) | ?Init@mmAxle@@QAEXPAD0PAVmmWheel@@1@Z
    0x47D4F0 | public: virtual void __thiscall mmAxle::Update(void) | ?Update@mmAxle@@UAEXXZ
    0x47D590 | public: virtual void __thiscall mmAxle::AddWidgets(class Bank *) | ?AddWidgets@mmAxle@@UAEXPAVBank@@@Z
    0x47D5B0 | public: static void __cdecl mmAxle::DeclareFields(void) | ?DeclareFields@mmAxle@@SAXXZ
    0x47D720 | public: virtual class MetaClass * __thiscall mmAxle::GetClass(void) | ?GetClass@mmAxle@@UAEPAVMetaClass@@XZ
    0x47D730 | public: virtual void * __thiscall mmAxle::`vector deleting destructor'(unsigned int) | ??_EmmAxle@@UAEPAXI@Z
    0x61C680 | const mmAxle::`vftable' | ??_7mmAxle@@6B@
    0x6A8080 | class MetaClass mmAxleMetaClass | ?mmAxleMetaClass@@3VMetaClass@@A
*/

class mmAxle : public asLinearCS
{
    // const mmAxle::`vftable' @ 0x61C680

public:
    // 0x47D480 | ??0mmAxle@@QAE@XZ
    mmAxle();

    // 0x47D730 | ??_EmmAxle@@UAEPAXI@Z
    // 0x470370 | ??1mmAxle@@UAE@XZ
    ~mmAxle() override;

    // 0x47D590 | ?AddWidgets@mmAxle@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x47D720 | ?GetClass@mmAxle@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x47D4A0 | ?Init@mmAxle@@QAEXPAD0PAVmmWheel@@1@Z
    void Init(char* arg1, char* arg2, class mmWheel* arg3, class mmWheel* arg4);

    // 0x47D4F0 | ?Update@mmAxle@@UAEXXZ
    void Update() override;

    // 0x47D5B0 | ?DeclareFields@mmAxle@@SAXXZ
    static void DeclareFields();
};

check_size(mmAxle, 0x9C);

// 0x6A8080 | ?mmAxleMetaClass@@3VMetaClass@@A
inline extern_var(0x2A8080_Offset, class MetaClass, mmAxleMetaClass);
