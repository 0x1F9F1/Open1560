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

#include "arts7/node.h"

class sfPointer final : public asNode
{
public:
    // ??0sfPointer@@QAE@XZ
    ARTS_IMPORT sfPointer();

    // ??_EsfPointer@@UAEPAXI@Z
    // ??1sfPointer@@UAE@XZ
    ARTS_IMPORT ~sfPointer() override;

    // ?Cull@sfPointer@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?GetClass@sfPointer@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?GetPointerHeight@sfPointer@@QAEMXZ
    ARTS_IMPORT f32 GetPointerHeight();

    // ?Init@sfPointer@@QAEXXZ
    ARTS_IMPORT void Init();

    // ?ResChange@sfPointer@@UAEXHH@Z
    ARTS_IMPORT void ResChange(i32 arg1, i32 arg2) override;

    // ?Update@sfPointer@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?WaitForRelease@sfPointer@@QAEXXZ
    ARTS_IMPORT void WaitForRelease();

    // ?DeclareFields@sfPointer@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?UpdateAttached@sfPointer@@AAEXXZ | unused
    ARTS_EXPORT void UpdateAttached();

    u8 gap20[0x34];
};

check_size(sfPointer, 0x54);
