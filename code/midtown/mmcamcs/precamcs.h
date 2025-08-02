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

#include "carcamcs.h"

class PreCamCS final : public CarCamCS
{
public:
    // ??0PreCamCS@@QAE@XZ
    ARTS_EXPORT PreCamCS() = default;

    // ??_EPreCamCS@@UAEPAXI@Z
    // ??1PreCamCS@@UAE@XZ | inline
    ARTS_EXPORT ~PreCamCS() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@PreCamCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@PreCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@PreCamCS@@QAEXPAVmmCar@@@Z
    ARTS_EXPORT void Init(mmCar* car);

    // ?MakeActive@PreCamCS@@UAEXXZ
    ARTS_EXPORT void MakeActive() override;

    // ?Reset@PreCamCS@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?Update@PreCamCS@@UAEXXZ
    ARTS_EXPORT void Update() override;

    // ?DeclareFields@PreCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    f32 PolarHeight {2.0f};
    f32 PolarDistance {22.0f};
    f32 PolarAngle {0.0f};
    f32 PolarIncline {1.1f};
    f32 field_128 {2.0f};
    f32 AzimuthOffset {0.0f};
};

check_size(PreCamCS, 0x130);
