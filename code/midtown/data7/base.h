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
    data7:base

    0x5791A0 | public: virtual char * __thiscall Base::GetTypeNameV(void) | ?GetTypeNameV@Base@@UAEPADXZ
    0x5791B0 | public: char * __thiscall Base::GetTypeName(void) | ?GetTypeName@Base@@QAEPADXZ
    0x5791C0 | public: virtual void __thiscall Base::BeforeSave(void) | ?BeforeSave@Base@@UAEXXZ
    0x5791D0 | public: virtual void __thiscall Base::AfterLoad(void) | ?AfterLoad@Base@@UAEXXZ
    0x5791E0 | public: virtual __thiscall Base::~Base(void) | ??1Base@@UAE@XZ
    0x5791F0 | public: static void __cdecl Base::DeclareFields(void) | ?DeclareFields@Base@@SAXXZ
    0x579290 | public: virtual class MetaClass * __thiscall Base::GetClass(void) | ?GetClass@Base@@UAEPAVMetaClass@@XZ
    0x90B100 | class MetaClass BaseMetaClass | ?BaseMetaClass@@3VMetaClass@@A
*/

class Base
{
    // const Base::`vftable' @ 0x61A638

public:
    // 0x414AD0 | ??_GBase@@UAEPAXI@Z
    // 0x5791E0 | ??1Base@@UAE@XZ
    virtual ~Base() noexcept = 0;

    // 0x579290 | ?GetClass@Base@@UAEPAVMetaClass@@XZ
    virtual class MetaClass* GetClass();

    // 0x5791A0 | ?GetTypeNameV@Base@@UAEPADXZ
    virtual const char* GetTypeNameV();

    // 0x5791C0 | ?BeforeSave@Base@@UAEXXZ
    virtual void BeforeSave();

    // 0x5791D0 | ?AfterLoad@Base@@UAEXXZ
    virtual void AfterLoad();

    // 0x5791B0 | ?GetTypeName@Base@@QAEPADXZ
    const char* GetTypeName();

    META_DECLARE;
};

inline Base::~Base() = default;

check_size(Base, 0x4);

// 0x90B100 | ?BaseMetaClass@@3VMetaClass@@A
// inline extern_var(0x90B100, class MetaClass, BaseMetaClass);
