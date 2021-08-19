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
    mmcamcs:povcamcs

    0x4F62B0 | public: __thiscall PovCamCS::PovCamCS(void) | ??0PovCamCS@@QAE@XZ
    0x4F63B0 | public: virtual __thiscall PovCamCS::~PovCamCS(void) | ??1PovCamCS@@UAE@XZ
    0x4F63C0 | public: virtual void __thiscall PovCamCS::MakeActive(void) | ?MakeActive@PovCamCS@@UAEXXZ
    0x4F6410 | public: virtual void __thiscall PovCamCS::AfterLoad(void) | ?AfterLoad@PovCamCS@@UAEXXZ
    0x4F6420 | public: virtual void __thiscall PovCamCS::Reset(void) | ?Reset@PovCamCS@@UAEXXZ
    0x4F6460 | public: virtual void __thiscall PovCamCS::AddWidgets(class Bank *) | ?AddWidgets@PovCamCS@@UAEXPAVBank@@@Z
    0x4F6530 | public: virtual void __thiscall PovCamCS::Update(void) | ?Update@PovCamCS@@UAEXXZ
    0x4F6550 | public: virtual void __thiscall PovCamCS::UpdateInput(void) | ?UpdateInput@PovCamCS@@UAEXXZ
    0x4F6560 | private: void __thiscall PovCamCS::UpdatePOV(void) | ?UpdatePOV@PovCamCS@@AAEXXZ
    0x4F6800 | public: static void __cdecl PovCamCS::DeclareFields(void) | ?DeclareFields@PovCamCS@@SAXXZ
    0x4F69B0 | public: virtual class MetaClass * __thiscall PovCamCS::GetClass(void) | ?GetClass@PovCamCS@@UAEPAVMetaClass@@XZ
    0x4F69F0 | public: virtual void * __thiscall PovCamCS::`vector deleting destructor'(unsigned int) | ??_EPovCamCS@@UAEPAXI@Z
    0x4F6A50 | public: virtual void __thiscall BaseCamCS::SetST(float *) | ?SetST@BaseCamCS@@UAEXPAM@Z
    0x620000 | const PovCamCS::`vftable' | ??_7PovCamCS@@6B@
    0x719350 | class MetaClass PovCamCSMetaClass | ?PovCamCSMetaClass@@3VMetaClass@@A
*/

#include "carcamcs.h"

class PovCamCS final : public CarCamCS
{
public:
    // ??0PovCamCS@@QAE@XZ
    ARTS_IMPORT PovCamCS();

    // ??_EPovCamCS@@UAEPAXI@Z
    // ??1PovCamCS@@UAE@XZ
    ARTS_IMPORT ~PovCamCS() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@PovCamCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // ?AfterLoad@PovCamCS@@UAEXXZ
    ARTS_IMPORT void AfterLoad() override;

    // ?GetClass@PovCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?MakeActive@PovCamCS@@UAEXXZ
    ARTS_IMPORT void MakeActive() override;

    // ?Reset@PovCamCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@PovCamCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateInput@PovCamCS@@UAEXXZ
    ARTS_EXPORT void UpdateInput() override;

    // ?DeclareFields@PovCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?UpdatePOV@PovCamCS@@AAEXXZ
    ARTS_IMPORT void UpdatePOV();

    u8 gap118[0x2C];
};

check_size(PovCamCS, 0x144);
