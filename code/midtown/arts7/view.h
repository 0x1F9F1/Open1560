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
    arts7:view

    0x52BBA0 | public: __thiscall asViewCS::asViewCS(void) | ??0asViewCS@@QAE@XZ
    0x52BCD0 | public: void __thiscall asViewCS::SetAzimuth(void) | ?SetAzimuth@asViewCS@@QAEXXZ
    0x52BD30 | public: virtual void __thiscall asViewCS::Reset(void) | ?Reset@asViewCS@@UAEXXZ
    0x52BF00 | public: virtual void __thiscall asViewCS::Update(void) | ?Update@asViewCS@@UAEXXZ
    0x52BF80 | public: void __thiscall asViewCS::UpdatePolar(void) | ?UpdatePolar@asViewCS@@QAEXXZ
    0x52C0C0 | public: void __thiscall asViewCS::UpdateRoam(void) | ?UpdateRoam@asViewCS@@QAEXXZ
    0x52C1D0 | public: void __thiscall asViewCS::UpdatePOV(void) | ?UpdatePOV@asViewCS@@QAEXXZ
    0x52C220 | public: void __thiscall asViewCS::UpdateLookAt(void) | ?UpdateLookAt@asViewCS@@QAEXXZ
    0x52C280 | public: void __thiscall asViewCS::UpdateTrack(void) | ?UpdateTrack@asViewCS@@QAEXXZ
    0x52C640 | public: void __thiscall asViewCS::UpdateStereo(void) | ?UpdateStereo@asViewCS@@QAEXXZ
    0x52C770 | public: void __thiscall asViewCS::FileIO(class MiniParser *) | ?FileIO@asViewCS@@QAEXPAVMiniParser@@@Z
    0x52C780 | public: virtual void __thiscall asViewCS::AddWidgets(class Bank *) | ?AddWidgets@asViewCS@@UAEXPAVBank@@@Z
    0x52CC70 | public: static void __cdecl asViewCS::DeclareFields(void) | ?DeclareFields@asViewCS@@SAXXZ
    0x52CDE0 | public: virtual class MetaClass * __thiscall asViewCS::GetClass(void) | ?GetClass@asViewCS@@UAEPAVMetaClass@@XZ
    0x52CDF0 | public: virtual void * __thiscall asViewCS::`vector deleting destructor'(unsigned int) | ??_EasViewCS@@UAEPAXI@Z
    0x52CE50 | public: virtual __thiscall asViewCS::~asViewCS(void) | ??1asViewCS@@UAE@XZ
    0x620E40 | const asViewCS::`vftable' | ??_7asViewCS@@6B@
    0x7909B8 | class MetaClass asViewCSMetaClass | ?asViewCSMetaClass@@3VMetaClass@@A
*/

#include "linear.h"

class asViewCS final : public asLinearCS
{
    // const asViewCS::`vftable'

public:
    // ??0asViewCS@@QAE@XZ
    ARTS_IMPORT asViewCS();

    // ??_EasViewCS@@UAEPAXI@Z
    // ??1asViewCS@@UAE@XZ | inline
    ARTS_IMPORT ~asViewCS() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asViewCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // ?FileIO@asViewCS@@QAEXPAVMiniParser@@@Z | unused
    ARTS_EXPORT void FileIO(class MiniParser* arg1);

    // ?GetClass@asViewCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?Reset@asViewCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetAzimuth@asViewCS@@QAEXXZ
    ARTS_IMPORT void SetAzimuth();

    // ?Update@asViewCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateLookAt@asViewCS@@QAEXXZ
    ARTS_IMPORT void UpdateLookAt();

    // ?UpdatePOV@asViewCS@@QAEXXZ
    ARTS_IMPORT void UpdatePOV();

    // ?UpdatePolar@asViewCS@@QAEXXZ
    ARTS_IMPORT void UpdatePolar();

    // ?UpdateRoam@asViewCS@@QAEXXZ
    ARTS_IMPORT void UpdateRoam();

    // ?UpdateStereo@asViewCS@@QAEXXZ
    ARTS_IMPORT void UpdateStereo();

    // ?UpdateTrack@asViewCS@@QAEXXZ
    ARTS_IMPORT void UpdateTrack();

    // ?DeclareFields@asViewCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0x9C];
};

check_size(asViewCS, 0x124);

// ?asViewCSMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass asViewCSMetaClass;
