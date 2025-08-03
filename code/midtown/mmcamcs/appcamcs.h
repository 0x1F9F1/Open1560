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

public:
    Matrix34* CarMatrix;
    Vector3 TrackTo;
    f32 ApproachOn;
    f32 AppAppOn;
    f32 AppRot;
    f32 AppXRot;
    f32 AppYPos;
    f32 AppXZPos;
    f32 AppApp;
    f32 AppRotMin;
    f32 AppPosMin;
    b32 LookAbove;
    b32 OneShot;
    f32 MaxDist;
    f32 MinDist;
    f32 LookAt;
    f32 field_E4;
    f32 field_E8;
    f32 field_EC;
    Vector3 field_F0;
    Vector3 field_FC;
    Vector3 field_108;
};

check_size(AppCamCS, 0x114);
