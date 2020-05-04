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

#include "data7/base.h"

/*
    arts7:cullable

    0x5258C0 | public: virtual void __thiscall asCullable::Cull(void) | ?Cull@asCullable@@UAEXXZ
    0x5258D0 | public: void __thiscall asCullable::AddWidgets(class Bank *) | ?AddWidgets@asCullable@@QAEXPAVBank@@@Z
    0x5258E0 | public: static void __cdecl asCullable::DeclareFields(void) | ?DeclareFields@asCullable@@SAXXZ
    0x525A30 | public: virtual class MetaClass * __thiscall asCullable::GetClass(void) | ?GetClass@asCullable@@UAEPAVMetaClass@@XZ
    0x525A40 | public: virtual void * __thiscall asCullable::`vector deleting destructor'(unsigned int) | ??_EasCullable@@UAEPAXI@Z
    0x525AA0 | public: __thiscall asCullable::asCullable(void) | ??0asCullable@@QAE@XZ
    0x7908B0 | class MetaClass asCullableMetaClass | ?asCullableMetaClass@@3VMetaClass@@A
*/

class asCullable : public Base
{
    // const asCullable::`vftable' @ 0x61CBE0

public:
    // 0x525AA0 | ??0asCullable@@QAE@XZ
    asCullable();

    // 0x525A40 | ??_EasCullable@@UAEPAXI@Z
    // 0x48BB80 | ??1asCullable@@UAE@XZ
    // 0x48BB50 | ??_GasCullable@@UAEPAXI@Z
    ~asCullable() override;

    // 0x5258C0 | ?Cull@asCullable@@UAEXXZ
    virtual void Cull();

    // 0x5258D0 | ?AddWidgets@asCullable@@QAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1);

    // 0x525A30 | ?GetClass@asCullable@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x5258E0 | ?DeclareFields@asCullable@@SAXXZ
    static void DeclareFields();
};

check_size(asCullable, 0x4);

// 0x7908B0 | ?asCullableMetaClass@@3VMetaClass@@A
inline extern_var(0x3908B0_Offset, class MetaClass, asCullableMetaClass);
