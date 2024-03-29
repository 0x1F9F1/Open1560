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
    mmcamcs:transitioncs

    0x4FB4B0 | public: __thiscall TransitionCS::TransitionCS(void) | ??0TransitionCS@@QAE@XZ
    0x4FB540 | public: virtual __thiscall TransitionCS::~TransitionCS(void) | ??1TransitionCS@@UAE@XZ
    0x4FB550 | public: void __thiscall TransitionCS::Init(class mmCar *) | ?Init@TransitionCS@@QAEXPAVmmCar@@@Z
    0x4FB570 | public: virtual void __thiscall TransitionCS::Reset(void) | ?Reset@TransitionCS@@UAEXXZ
    0x4FB580 | public: virtual void __thiscall TransitionCS::Update(void) | ?Update@TransitionCS@@UAEXXZ
    0x4FBC00 | public: virtual void __thiscall TransitionCS::ForceMatrixDelta(class Vector3 const &) | ?ForceMatrixDelta@TransitionCS@@UAEXABVVector3@@@Z
    0x4FBC30 | public: void __thiscall TransitionCS::NewTransition(class CarCamCS *,class CarCamCS *) | ?NewTransition@TransitionCS@@QAEXPAVCarCamCS@@0@Z
    0x4FBC60 | public: void __thiscall TransitionCS::NextTransition(class CarCamCS *) | ?NextTransition@TransitionCS@@QAEXPAVCarCamCS@@@Z
    0x4FBCA0 | public: void __thiscall TransitionCS::StartTransition(void) | ?StartTransition@TransitionCS@@QAEXXZ
    0x4FBD10 | public: void __thiscall TransitionCS::StartNextTransition(void) | ?StartNextTransition@TransitionCS@@QAEXXZ
    0x4FBD50 | public: void __thiscall TransitionCS::ReverseTransition(void) | ?ReverseTransition@TransitionCS@@QAEXXZ
    0x4FBDD0 | public: virtual void * __thiscall TransitionCS::`vector deleting destructor'(unsigned int) | ??_ETransitionCS@@UAEPAXI@Z
    0x4FBDD0 | public: virtual void * __thiscall TransitionCS::`scalar deleting destructor'(unsigned int) | ??_GTransitionCS@@UAEPAXI@Z
    0x620438 | const TransitionCS::`vftable' | ??_7TransitionCS@@6B@
*/

#include "carcamcs.h"

class TransitionCS final : public CarCamCS
{
public:
    // ??0TransitionCS@@QAE@XZ
    ARTS_IMPORT TransitionCS();

    // ??_GTransitionCS@@UAEPAXI@Z
    // ??_ETransitionCS@@UAEPAXI@Z
    // ??1TransitionCS@@UAE@XZ
    ARTS_IMPORT ~TransitionCS() override = default;

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
