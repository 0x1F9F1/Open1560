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

#include "basecamcs.h"

class AppCamCS : public BaseCamCS
{
public:
    // ??0AppCamCS@@QAE@XZ
    ARTS_IMPORT AppCamCS();

    // ??_EAppCamCS@@UAEPAXI@Z
    // ??1AppCamCS@@UAE@XZ
    ARTS_EXPORT ~AppCamCS() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@AppCamCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@AppCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?DeclareFields@AppCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

protected:
    // ?ApproachIt@AppCamCS@@IAEXXZ
    ARTS_IMPORT void ApproachIt();

private:
    // ?DApproach@AppCamCS@@AAEHAAMMMM0M@Z
    ARTS_IMPORT i32 DApproach(f32& arg1, f32 arg2, f32 arg3, f32 arg4, f32& arg5, f32 arg6);

    // ?UpdateApproach@AppCamCS@@AAEXXZ
    ARTS_IMPORT void UpdateApproach();

    // ?UpdateMaxDist@AppCamCS@@AAEXXZ
    ARTS_IMPORT void UpdateMaxDist();

    u8 gap9C[0x78];
};

check_size(AppCamCS, 0x114);
