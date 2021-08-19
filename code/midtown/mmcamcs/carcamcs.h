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
    mmcamcs:carcamcs

    0x4FB220 | public: __thiscall CarCamCS::CarCamCS(void) | ??0CarCamCS@@QAE@XZ
    0x4FB240 | public: virtual __thiscall CarCamCS::~CarCamCS(void) | ??1CarCamCS@@UAE@XZ
    0x4FB250 | public: void __thiscall CarCamCS::Init(class mmCar *,char *) | ?Init@CarCamCS@@QAEXPAVmmCar@@PAD@Z
    0x4FB280 | public: virtual void __thiscall CarCamCS::AddWidgets(class Bank *) | ?AddWidgets@CarCamCS@@UAEXPAVBank@@@Z
    0x4FB290 | public: static void __cdecl CarCamCS::DeclareFields(void) | ?DeclareFields@CarCamCS@@SAXXZ
    0x4FB400 | public: virtual class MetaClass * __thiscall CarCamCS::GetClass(void) | ?GetClass@CarCamCS@@UAEPAVMetaClass@@XZ
    0x4FB440 | public: virtual void * __thiscall CarCamCS::`vector deleting destructor'(unsigned int) | ??_ECarCamCS@@UAEPAXI@Z
    0x4FB4A0 | public: virtual void __thiscall BaseCamCS::MakeActive(void) | ?MakeActive@BaseCamCS@@UAEXXZ
    0x6203A0 | const CarCamCS::`vftable' | ??_7CarCamCS@@6B@
    0x7194C8 | class MetaClass CarCamCSMetaClass | ?CarCamCSMetaClass@@3VMetaClass@@A
*/

#include "appcamcs.h"

class CarCamCS : public AppCamCS
{
public:
    // ??0CarCamCS@@QAE@XZ
    ARTS_IMPORT CarCamCS();

    // ??_ECarCamCS@@UAEPAXI@Z
    // ??1CarCamCS@@UAE@XZ
    ARTS_IMPORT ~CarCamCS() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@CarCamCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // ?GetClass@CarCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?Init@CarCamCS@@QAEXPAVmmCar@@PAD@Z
    ARTS_IMPORT void Init(class mmCar* arg1, char* arg2);

    // ?DeclareFields@CarCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap114[0x4];
};

check_size(CarCamCS, 0x118);
