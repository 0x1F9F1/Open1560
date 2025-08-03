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

class TransitionCS final : public CarCamCS
{
public:
    // ??0TransitionCS@@QAE@XZ
    ARTS_IMPORT TransitionCS();

    // ??1TransitionCS@@UAE@XZ
    ARTS_EXPORT ~TransitionCS() override = default;

    // ?ForceMatrixDelta@TransitionCS@@UAEXABVVector3@@@Z
    ARTS_IMPORT void ForceMatrixDelta(const Vector3& arg1) override;

    // ?Init@TransitionCS@@QAEXPAVmmCar@@@Z
    ARTS_IMPORT void Init(mmCar* arg1);

    // ?NewTransition@TransitionCS@@QAEXPAVCarCamCS@@0@Z
    ARTS_IMPORT void NewTransition(CarCamCS* arg1, CarCamCS* arg2);

    // ?NextTransition@TransitionCS@@QAEXPAVCarCamCS@@@Z
    ARTS_IMPORT void NextTransition(CarCamCS* arg1);

    // ?Reset@TransitionCS@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?ReverseTransition@TransitionCS@@QAEXXZ
    ARTS_IMPORT void ReverseTransition();

    // ?StartNextTransition@TransitionCS@@QAEXXZ
    ARTS_IMPORT void StartNextTransition();

    // ?StartTransition@TransitionCS@@QAEXXZ
    ARTS_IMPORT void StartTransition();

    // ?Update@TransitionCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap118[0x18];
};

check_size(TransitionCS, 0x130);
