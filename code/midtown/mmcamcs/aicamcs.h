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
    mmcamcs:aicamcs

    0x4FA490 | public: __thiscall AICamCS::AICamCS(void) | ??0AICamCS@@QAE@XZ
    0x4FA4C0 | public: void __thiscall AICamCS::Init(class mmCar *) | ?Init@AICamCS@@QAEXPAVmmCar@@@Z
    0x4FA4D0 | public: virtual void __thiscall AICamCS::Reset(void) | ?Reset@AICamCS@@UAEXXZ
    0x4FA4E0 | public: virtual void __thiscall AICamCS::MakeActive(void) | ?MakeActive@AICamCS@@UAEXXZ
    0x4FA5F0 | public: virtual void __thiscall AICamCS::Update(void) | ?Update@AICamCS@@UAEXXZ
    0x4FA950 | public: static void __cdecl AICamCS::DeclareFields(void) | ?DeclareFields@AICamCS@@SAXXZ
    0x4FAAC0 | public: virtual class MetaClass * __thiscall AICamCS::GetClass(void) | ?GetClass@AICamCS@@UAEPAVMetaClass@@XZ
    0x4FAB00 | public: virtual void * __thiscall AICamCS::`vector deleting destructor'(unsigned int) | ??_EAICamCS@@UAEPAXI@Z
    0x6202B8 | const AICamCS::`vftable' | ??_7AICamCS@@6B@
    0x719468 | class MetaClass AICamCSMetaClass | ?AICamCSMetaClass@@3VMetaClass@@A
*/

#include "carcamcs.h"

class AICamCS : public CarCamCS
{
    // const AICamCS::`vftable' @ 0x6202B8

public:
    // 0x4FA490 | ??0AICamCS@@QAE@XZ
    AICamCS();

    // 0x4FAB00 | ??_EAICamCS@@UAEPAXI@Z
    // 0x42D2C0 | ??1AICamCS@@UAE@XZ | inline
    ~AICamCS() override;

    // 0x4FAAC0 | ?GetClass@AICamCS@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4FA4C0 | ?Init@AICamCS@@QAEXPAVmmCar@@@Z
    void Init(class mmCar* arg1);

    // 0x4FA4E0 | ?MakeActive@AICamCS@@UAEXXZ
    void MakeActive() override;

    // 0x4FA4D0 | ?Reset@AICamCS@@UAEXXZ
    void Reset() override;

    // 0x4FA5F0 | ?Update@AICamCS@@UAEXXZ
    void Update() override;

    // 0x4FA950 | ?DeclareFields@AICamCS@@SAXXZ
    static void DeclareFields();
};

check_size(AICamCS, 0x120);

// 0x719468 | ?AICamCSMetaClass@@3VMetaClass@@A
inline extern_var(0x719468, class MetaClass, AICamCSMetaClass);
