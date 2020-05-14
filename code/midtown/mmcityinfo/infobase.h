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
    mmcityinfo:infobase

    0x4D12B0 | public: __thiscall mmInfoBase::mmInfoBase(void) | ??0mmInfoBase@@QAE@XZ
    0x4D12E0 | public: int __thiscall mmInfoBase::Load(char *) | ?Load@mmInfoBase@@QAEHPAD@Z
    0x4D1390 | public: int __thiscall mmInfoBase::Save(char *) | ?Save@mmInfoBase@@QAEHPAD@Z
    0x4D1440 | public: void __thiscall mmInfoBase::SetIOPath(char *) | ?SetIOPath@mmInfoBase@@QAEXPAD@Z
    0x4D1460 | public: static void __cdecl mmInfoBase::DeclareFields(void) | ?DeclareFields@mmInfoBase@@SAXXZ
    0x4D15D0 | public: virtual class MetaClass * __thiscall mmInfoBase::GetClass(void) | ?GetClass@mmInfoBase@@UAEPAVMetaClass@@XZ
    0x4D15E0 | public: virtual void * __thiscall mmInfoBase::`vector deleting destructor'(unsigned int) | ??_EmmInfoBase@@UAEPAXI@Z
    0x7085C8 | class MetaClass mmInfoBaseMetaClass | ?mmInfoBaseMetaClass@@3VMetaClass@@A
*/

#include "data7/base.h"

class mmInfoBase : public Base
{
    // const mmInfoBase::`vftable' @ 0x61A620

public:
    // 0x4D12B0 | ??0mmInfoBase@@QAE@XZ
    mmInfoBase();

    // 0x4D15E0 | ??_EmmInfoBase@@UAEPAXI@Z
    // 0x414B90 | ??_GmmInfoBase@@UAEPAXI@Z
    // 0x414BC0 | ??1mmInfoBase@@UAE@XZ
    ~mmInfoBase() override;

    // 0x4D15D0 | ?GetClass@mmInfoBase@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4D12E0 | ?Load@mmInfoBase@@QAEHPAD@Z
    i32 Load(char* arg1);

    // 0x4D1390 | ?Save@mmInfoBase@@QAEHPAD@Z
    i32 Save(char* arg1);

    // 0x4D1440 | ?SetIOPath@mmInfoBase@@QAEXPAD@Z
    void SetIOPath(char* arg1);

    // 0x4D1460 | ?DeclareFields@mmInfoBase@@SAXXZ
    static void DeclareFields();
};

check_size(mmInfoBase, 0x88);

// 0x7085C8 | ?mmInfoBaseMetaClass@@3VMetaClass@@A
inline extern_var(0x7085C8, class MetaClass, mmInfoBaseMetaClass);
