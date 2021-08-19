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
    mmcamcs:precamcs

    0x4F99E0 | public: __thiscall PreCamCS::PreCamCS(void) | ??0PreCamCS@@QAE@XZ
    0x4F9A30 | public: void __thiscall PreCamCS::Init(class mmCar *) | ?Init@PreCamCS@@QAEXPAVmmCar@@@Z
    0x4F9A60 | public: virtual void __thiscall PreCamCS::Reset(void) | ?Reset@PreCamCS@@UAEXXZ
    0x4F9A70 | public: virtual void __thiscall PreCamCS::MakeActive(void) | ?MakeActive@PreCamCS@@UAEXXZ
    0x4F9AC0 | public: virtual void __thiscall PreCamCS::Update(void) | ?Update@PreCamCS@@UAEXXZ
    0x4F9B20 | public: virtual void __thiscall PreCamCS::AddWidgets(class Bank *) | ?AddWidgets@PreCamCS@@UAEXPAVBank@@@Z
    0x4F9C10 | public: static void __cdecl PreCamCS::DeclareFields(void) | ?DeclareFields@PreCamCS@@SAXXZ
    0x4F9D80 | public: virtual class MetaClass * __thiscall PreCamCS::GetClass(void) | ?GetClass@PreCamCS@@UAEPAVMetaClass@@XZ
    0x4F9DC0 | public: virtual void * __thiscall PreCamCS::`vector deleting destructor'(unsigned int) | ??_EPreCamCS@@UAEPAXI@Z
    0x6201E8 | const PreCamCS::`vftable' | ??_7PreCamCS@@6B@
    0x719400 | class MetaClass PreCamCSMetaClass | ?PreCamCSMetaClass@@3VMetaClass@@A
*/

#include "carcamcs.h"

class PreCamCS final : public CarCamCS
{
public:
    // ??0PreCamCS@@QAE@XZ
    ARTS_IMPORT PreCamCS();

    // ??_EPreCamCS@@UAEPAXI@Z
    // ??1PreCamCS@@UAE@XZ | inline
    ARTS_IMPORT ~PreCamCS() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@PreCamCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // ?GetClass@PreCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?Init@PreCamCS@@QAEXPAVmmCar@@@Z
    ARTS_IMPORT void Init(class mmCar* arg1);

    // ?MakeActive@PreCamCS@@UAEXXZ
    ARTS_IMPORT void MakeActive() override;

    // ?Reset@PreCamCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@PreCamCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@PreCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap118[0x18];
};

check_size(PreCamCS, 0x130);
