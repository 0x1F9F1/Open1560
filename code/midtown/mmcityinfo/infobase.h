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
public:
    // ??0mmInfoBase@@QAE@XZ
    ARTS_EXPORT mmInfoBase() = default;

    // ??_EmmInfoBase@@UAEPAXI@Z
    // ??_GmmInfoBase@@UAEPAXI@Z | unused
    // ??1mmInfoBase@@UAE@XZ | inline
    ARTS_EXPORT ~mmInfoBase() override = default;

    // ?Load@mmInfoBase@@QAEHPAD@Z
    ARTS_EXPORT b32 Load(const char* path);

    // ?Save@mmInfoBase@@QAEHPAD@Z
    ARTS_EXPORT b32 Save(const char* path);

    // ?SetIOPath@mmInfoBase@@QAEXPAD@Z
    ARTS_EXPORT void SetIOPath(const char* path);

    char FilePath[128] {};
    i32 Type {1234};

    VIRTUAL_META_DECLARE;
};

check_size(mmInfoBase, 0x88);
