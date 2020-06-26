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
    mmcamcs:polarcamcs

    0x4FAB60 | public: __thiscall PolarCamCS::PolarCamCS(void) | ??0PolarCamCS@@QAE@XZ
    0x4FABB0 | public: void __thiscall PolarCamCS::Init(class mmCar *) | ?Init@PolarCamCS@@QAEXPAVmmCar@@@Z
    0x4FABE0 | public: virtual void __thiscall PolarCamCS::Reset(void) | ?Reset@PolarCamCS@@UAEXXZ
    0x4FABF0 | public: virtual void __thiscall PolarCamCS::MakeActive(void) | ?MakeActive@PolarCamCS@@UAEXXZ
    0x4FAC20 | public: virtual void __thiscall PolarCamCS::Update(void) | ?Update@PolarCamCS@@UAEXXZ
    0x4FB010 | public: static void __cdecl PolarCamCS::DeclareFields(void) | ?DeclareFields@PolarCamCS@@SAXXZ
    0x4FB180 | public: virtual class MetaClass * __thiscall PolarCamCS::GetClass(void) | ?GetClass@PolarCamCS@@UAEPAVMetaClass@@XZ
    0x4FB1C0 | public: virtual void * __thiscall PolarCamCS::`vector deleting destructor'(unsigned int) | ??_EPolarCamCS@@UAEPAXI@Z
    0x620348 | const PolarCamCS::`vftable' | ??_7PolarCamCS@@6B@
    0x719498 | class MetaClass PolarCamCSMetaClass | ?PolarCamCSMetaClass@@3VMetaClass@@A
*/

#include "carcamcs.h"

class PolarCamCS : public CarCamCS
{
    // const PolarCamCS::`vftable' @ 0x620348

public:
    // 0x4FAB60 | ??0PolarCamCS@@QAE@XZ
    ARTS_IMPORT PolarCamCS();

    // 0x4FB1C0 | ??_EPolarCamCS@@UAEPAXI@Z
    // 0x42D2B0 | ??1PolarCamCS@@UAE@XZ | inline
    ARTS_IMPORT ~PolarCamCS() override;

    // 0x4FB180 | ?GetClass@PolarCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4FABB0 | ?Init@PolarCamCS@@QAEXPAVmmCar@@@Z
    ARTS_IMPORT void Init(class mmCar* arg1);

    // 0x4FABF0 | ?MakeActive@PolarCamCS@@UAEXXZ
    ARTS_IMPORT void MakeActive() override;

    // 0x4FABE0 | ?Reset@PolarCamCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4FAC20 | ?Update@PolarCamCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4FB010 | ?DeclareFields@PolarCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap118[0x18];
};

check_size(PolarCamCS, 0x130);

// 0x719498 | ?PolarCamCSMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass PolarCamCSMetaClass;
