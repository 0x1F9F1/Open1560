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
    mmcamcs:appcamcs

    0x4FC330 | public: __thiscall AppCamCS::AppCamCS(void) | ??0AppCamCS@@QAE@XZ
    0x4FC420 | public: virtual __thiscall AppCamCS::~AppCamCS(void) | ??1AppCamCS@@UAE@XZ
    0x4FC430 | protected: void __thiscall AppCamCS::ApproachIt(void) | ?ApproachIt@AppCamCS@@IAEXXZ
    0x4FC460 | private: void __thiscall AppCamCS::UpdateApproach(void) | ?UpdateApproach@AppCamCS@@AAEXXZ
    0x4FC9D0 | private: void __thiscall AppCamCS::UpdateMaxDist(void) | ?UpdateMaxDist@AppCamCS@@AAEXXZ
    0x4FCC60 | private: int __thiscall AppCamCS::DApproach(float &,float,float,float,float &,float) | ?DApproach@AppCamCS@@AAEHAAMMMM0M@Z
    0x4FCDB0 | public: virtual void __thiscall AppCamCS::AddWidgets(class Bank *) | ?AddWidgets@AppCamCS@@UAEXPAVBank@@@Z
    0x4FD0D0 | public: static void __cdecl AppCamCS::DeclareFields(void) | ?DeclareFields@AppCamCS@@SAXXZ
    0x4FD380 | public: virtual class MetaClass * __thiscall AppCamCS::GetClass(void) | ?GetClass@AppCamCS@@UAEPAVMetaClass@@XZ
    0x4FD390 | public: virtual void * __thiscall AppCamCS::`vector deleting destructor'(unsigned int) | ??_EAppCamCS@@UAEPAXI@Z
    0x6204D8 | const AppCamCS::`vftable' | ??_7AppCamCS@@6B@
    0x719520 | class MetaClass AppCamCSMetaClass | ?AppCamCSMetaClass@@3VMetaClass@@A
*/

#include "basecamcs.h"

class AppCamCS : public BaseCamCS
{
    // const AppCamCS::`vftable' @ 0x6204D8

public:
    // 0x4FC330 | ??0AppCamCS@@QAE@XZ
    ARTS_IMPORT AppCamCS();

    // 0x4FD390 | ??_EAppCamCS@@UAEPAXI@Z
    // 0x4FC420 | ??1AppCamCS@@UAE@XZ
    ARTS_IMPORT ~AppCamCS() override;

    // 0x4FCDB0 | ?AddWidgets@AppCamCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x4FD380 | ?GetClass@AppCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4FD0D0 | ?DeclareFields@AppCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

protected:
    // 0x4FC430 | ?ApproachIt@AppCamCS@@IAEXXZ
    ARTS_IMPORT void ApproachIt();

private:
    // 0x4FCC60 | ?DApproach@AppCamCS@@AAEHAAMMMM0M@Z
    ARTS_IMPORT i32 DApproach(f32& arg1, f32 arg2, f32 arg3, f32 arg4, f32& arg5, f32 arg6);

    // 0x4FC460 | ?UpdateApproach@AppCamCS@@AAEXXZ
    ARTS_IMPORT void UpdateApproach();

    // 0x4FC9D0 | ?UpdateMaxDist@AppCamCS@@AAEXXZ
    ARTS_IMPORT void UpdateMaxDist();
};

check_size(AppCamCS, 0x114);

// 0x719520 | ?AppCamCSMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass AppCamCSMetaClass;
