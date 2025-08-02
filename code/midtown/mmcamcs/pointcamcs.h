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

class PointCamCS final : public CarCamCS
{
public:
    // ??0PointCamCS@@QAE@XZ
    ARTS_IMPORT PointCamCS();

    // ??_EPointCamCS@@UAEPAXI@Z
    // ??1PointCamCS@@UAE@XZ | inline
    ARTS_EXPORT ~PointCamCS() override = default;

    // ?GetClass@PointCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@PointCamCS@@QAEXPAVmmCar@@@Z
    ARTS_IMPORT void Init(mmCar* arg1);

    // ?MakeActive@PointCamCS@@UAEXXZ
    ARTS_IMPORT void MakeActive() override;

    // ?Reset@PointCamCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetAppRate@PointCamCS@@QAEXM@Z
    ARTS_IMPORT void SetAppRate(f32 arg1);

    // ?SetMaxDist@PointCamCS@@QAEXM@Z
    ARTS_IMPORT void SetMaxDist(f32 arg1);

    // ?SetMinDist@PointCamCS@@QAEXM@Z
    ARTS_IMPORT void SetMinDist(f32 arg1);

    // ?SetPos@PointCamCS@@QAEXAAVVector3@@@Z
    ARTS_IMPORT void SetPos(Vector3& arg1);

    // ?SetVel@PointCamCS@@QAEXAAVVector3@@@Z
    ARTS_IMPORT void SetVel(Vector3& arg1);

    // ?Update@PointCamCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@PointCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap118[0x2C];
};

check_size(PointCamCS, 0x144);
