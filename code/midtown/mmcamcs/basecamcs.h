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
    mmcamcs:basecamcs

    0x4FBE00 | public: __thiscall BaseCamCS::BaseCamCS(void) | ??0BaseCamCS@@QAE@XZ
    0x4FBEA0 | public: virtual __thiscall BaseCamCS::~BaseCamCS(void) | ??1BaseCamCS@@UAE@XZ
    0x4FBEB0 | public: virtual void __thiscall BaseCamCS::AfterLoad(void) | ?AfterLoad@BaseCamCS@@UAEXXZ
    0x4FBEC0 | public: int __thiscall BaseCamCS::IsViewCSInTransition(void) | ?IsViewCSInTransition@BaseCamCS@@QAEHXZ
    0x4FBEF0 | public: void __thiscall BaseCamCS::UpdateView(void) | ?UpdateView@BaseCamCS@@QAEXXZ
    0x4FBF40 | public: virtual void __thiscall BaseCamCS::AddWidgets(class Bank *) | ?AddWidgets@BaseCamCS@@UAEXPAVBank@@@Z
    0x4FC090 | public: virtual void __thiscall BaseCamCS::ForceMatrixDelta(class Vector3 const &) | ?ForceMatrixDelta@BaseCamCS@@UAEXABVVector3@@@Z
    0x4FC0E0 | public: static void __cdecl BaseCamCS::DeclareFields(void) | ?DeclareFields@BaseCamCS@@SAXXZ
    0x4FC2C0 | public: virtual class MetaClass * __thiscall BaseCamCS::GetClass(void) | ?GetClass@BaseCamCS@@UAEPAVMetaClass@@XZ
    0x4FC2D0 | public: virtual void * __thiscall BaseCamCS::`vector deleting destructor'(unsigned int) | ??_EBaseCamCS@@UAEPAXI@Z
    0x620488 | const BaseCamCS::`vftable' | ??_7BaseCamCS@@6B@
    0x7194F8 | class MetaClass BaseCamCSMetaClass | ?BaseCamCSMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class BaseCamCS : public asNode
{
    // const BaseCamCS::`vftable' @ 0x620488

public:
    // 0x4FBE00 | ??0BaseCamCS@@QAE@XZ
    ARTS_IMPORT BaseCamCS();

    // 0x4FC2D0 | ??_EBaseCamCS@@UAEPAXI@Z
    // 0x4FBEA0 | ??1BaseCamCS@@UAE@XZ
    ARTS_IMPORT ~BaseCamCS() override;

    // 0x4FB4A0 | ?MakeActive@BaseCamCS@@UAEXXZ | inline
    ARTS_IMPORT virtual void MakeActive();

    // 0x4F99D0 | ?UpdateInput@BaseCamCS@@UAEXXZ | inline
    ARTS_IMPORT virtual void UpdateInput();

    // 0x4FC090 | ?ForceMatrixDelta@BaseCamCS@@UAEXABVVector3@@@Z
    ARTS_IMPORT virtual void ForceMatrixDelta(class Vector3 const& arg1);

    // 0x4F6A50 | ?SetST@BaseCamCS@@UAEXPAM@Z | inline
    ARTS_IMPORT virtual void SetST(f32* arg1);

    // 0x4FBF40 | ?AddWidgets@BaseCamCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x4FBEB0 | ?AfterLoad@BaseCamCS@@UAEXXZ
    ARTS_IMPORT void AfterLoad() override;

    // 0x4FC2C0 | ?GetClass@BaseCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4FBEC0 | ?IsViewCSInTransition@BaseCamCS@@QAEHXZ
    ARTS_IMPORT i32 IsViewCSInTransition();

    // 0x4FBEF0 | ?UpdateView@BaseCamCS@@QAEXXZ
    ARTS_IMPORT void UpdateView();

    // 0x4FC0E0 | ?DeclareFields@BaseCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x7C];
};

check_size(BaseCamCS, 0x9C);

// 0x7194F8 | ?BaseCamCSMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass BaseCamCSMetaClass;
