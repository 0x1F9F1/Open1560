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

#include "arts7/node.h"

/*
    mmwidget:pointer

    0x4BD970 | public: __thiscall sfPointer::sfPointer(void) | ??0sfPointer@@QAE@XZ
    0x4BD9A0 | public: virtual __thiscall sfPointer::~sfPointer(void) | ??1sfPointer@@UAE@XZ
    0x4BDA00 | public: void __thiscall sfPointer::Init(void) | ?Init@sfPointer@@QAEXXZ
    0x4BDA20 | public: virtual void __thiscall sfPointer::ResChange(int,int) | ?ResChange@sfPointer@@UAEXHH@Z
    0x4BDA80 | public: float __thiscall sfPointer::GetPointerHeight(void) | ?GetPointerHeight@sfPointer@@QAEMXZ
    0x4BDA90 | public: virtual void __thiscall sfPointer::Update(void) | ?Update@sfPointer@@UAEXXZ
    0x4BDD10 | private: void __thiscall sfPointer::UpdateAttached(void) | ?UpdateAttached@sfPointer@@AAEXXZ
    0x4BDD20 | public: void __thiscall sfPointer::WaitForRelease(void) | ?WaitForRelease@sfPointer@@QAEXXZ
    0x4BDD30 | public: virtual void __thiscall sfPointer::Cull(void) | ?Cull@sfPointer@@UAEXXZ
    0x4BDDB0 | public: static void __cdecl sfPointer::DeclareFields(void) | ?DeclareFields@sfPointer@@SAXXZ
    0x4BDF20 | public: virtual class MetaClass * __thiscall sfPointer::GetClass(void) | ?GetClass@sfPointer@@UAEPAVMetaClass@@XZ
    0x4BDF30 | public: virtual void * __thiscall sfPointer::`vector deleting destructor'(unsigned int) | ??_EsfPointer@@UAEPAXI@Z
    0x61F0A8 | const sfPointer::`vftable' | ??_7sfPointer@@6B@
    0x705C50 | class MetaClass sfPointerMetaClass | ?sfPointerMetaClass@@3VMetaClass@@A
*/

class sfPointer : public asNode
{
    // const sfPointer::`vftable' @ 0x61F0A8

public:
    // 0x4BD970 | ??0sfPointer@@QAE@XZ
    sfPointer();

    // 0x4BDF30 | ??_EsfPointer@@UAEPAXI@Z
    // 0x4BD9A0 | ??1sfPointer@@UAE@XZ
    ~sfPointer() override;

    // 0x4BDD30 | ?Cull@sfPointer@@UAEXXZ
    void Cull() override;

    // 0x4BDF20 | ?GetClass@sfPointer@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4BDA80 | ?GetPointerHeight@sfPointer@@QAEMXZ
    f32 GetPointerHeight();

    // 0x4BDA00 | ?Init@sfPointer@@QAEXXZ
    void Init();

    // 0x4BDA20 | ?ResChange@sfPointer@@UAEXHH@Z
    void ResChange(i32 arg1, i32 arg2) override;

    // 0x4BDA90 | ?Update@sfPointer@@UAEXXZ
    void Update() override;

    // 0x4BDD20 | ?WaitForRelease@sfPointer@@QAEXXZ
    void WaitForRelease();

    // 0x4BDDB0 | ?DeclareFields@sfPointer@@SAXXZ
    static void DeclareFields();

private:
    // 0x4BDD10 | ?UpdateAttached@sfPointer@@AAEXXZ
    void UpdateAttached();
};

check_size(sfPointer, 0x54);

// 0x705C50 | ?sfPointerMetaClass@@3VMetaClass@@A
inline extern_var(0x305C50_Offset, class MetaClass, sfPointerMetaClass);
