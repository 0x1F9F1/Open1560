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

#include "linear.h"

class asViewCS final : public asLinearCS
{
public:
    // ??0asViewCS@@QAE@XZ
    ARTS_IMPORT asViewCS();

    // ??_EasViewCS@@UAEPAXI@Z
    // ??1asViewCS@@UAE@XZ | inline
    ARTS_EXPORT ~asViewCS() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asViewCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?FileIO@asViewCS@@QAEXPAVMiniParser@@@Z | unused
    ARTS_EXPORT void FileIO(MiniParser* arg1);

    // ?GetClass@asViewCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

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
