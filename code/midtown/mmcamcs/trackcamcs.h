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
    mmcamcs:trackcamcs

    0x4F6A60 | public: __thiscall TrackCamCS::TrackCamCS(void) | ??0TrackCamCS@@QAE@XZ
    0x4F6D00 | public: virtual __thiscall TrackCamCS::~TrackCamCS(void) | ??1TrackCamCS@@UAE@XZ
    0x4F6D50 | public: virtual void __thiscall TrackCamCS::MakeActive(void) | ?MakeActive@TrackCamCS@@UAEXXZ
    0x4F6D90 | public: virtual void __thiscall TrackCamCS::AfterLoad(void) | ?AfterLoad@TrackCamCS@@UAEXXZ
    0x4F6DA0 | public: virtual void __thiscall TrackCamCS::Reset(void) | ?Reset@TrackCamCS@@UAEXXZ
    0x4F6DE0 | public: virtual void __thiscall TrackCamCS::AddWidgets(class Bank *) | ?AddWidgets@TrackCamCS@@UAEXPAVBank@@@Z
    0x4F7270 | public: virtual void __thiscall TrackCamCS::Update(void) | ?Update@TrackCamCS@@UAEXXZ
    0x4F7350 | public: virtual void __thiscall TrackCamCS::UpdateInput(void) | ?UpdateInput@TrackCamCS@@UAEXXZ
    0x4F7360 | private: void __thiscall TrackCamCS::UpdateCar(void) | ?UpdateCar@TrackCamCS@@AAEXXZ
    0x4F7500 | private: void __thiscall TrackCamCS::UpdateHill(void) | ?UpdateHill@TrackCamCS@@AAEXXZ
    0x4F7510 | private: void __thiscall TrackCamCS::UpdateTrack(void) | ?UpdateTrack@TrackCamCS@@AAEXXZ
    0x4F7E50 | private: void __thiscall TrackCamCS::UpdateSwing(void) | ?UpdateSwing@TrackCamCS@@AAEXXZ
    0x4F8230 | private: void __thiscall TrackCamCS::PreApproach(void) | ?PreApproach@TrackCamCS@@AAEXXZ
    0x4F8430 | private: void __thiscall TrackCamCS::MinMax(class Matrix34) | ?MinMax@TrackCamCS@@AAEXVMatrix34@@@Z
    0x4F85D0 | private: void __thiscall TrackCamCS::Collide(class Vector3) | ?Collide@TrackCamCS@@AAEXVVector3@@@Z
    0x4F8A70 | public: void __thiscall TrackCamCS::SwingToRear(void) | ?SwingToRear@TrackCamCS@@QAEXXZ
    0x4F8AE0 | private: void __thiscall TrackCamCS::Front(float) | ?Front@TrackCamCS@@AAEXM@Z
    0x4F8B60 | private: void __thiscall TrackCamCS::Rear(float) | ?Rear@TrackCamCS@@AAEXM@Z
    0x4F8BE0 | public: static void __cdecl TrackCamCS::DeclareFields(void) | ?DeclareFields@TrackCamCS@@SAXXZ
    0x4F8F00 | public: virtual class MetaClass * __thiscall TrackCamCS::GetClass(void) | ?GetClass@TrackCamCS@@UAEPAVMetaClass@@XZ
    0x4F8F40 | public: virtual __thiscall Spline::~Spline(void) | ??1Spline@@UAE@XZ
    0x4F8F50 | public: virtual void * __thiscall TrackCamCS::`vector deleting destructor'(unsigned int) | ??_ETrackCamCS@@UAEPAXI@Z
    0x6200C8 | const TrackCamCS::`vftable' | ??_7TrackCamCS@@6B@
    0x719380 | class MetaClass TrackCamCSMetaClass | ?TrackCamCSMetaClass@@3VMetaClass@@A
*/

#include "carcamcs.h"

class TrackCamCS final : public CarCamCS
{
    // const TrackCamCS::`vftable' @ 0x6200C8

public:
    // 0x4F6A60 | ??0TrackCamCS@@QAE@XZ
    ARTS_IMPORT TrackCamCS();

    // 0x4F8F50 | ??_ETrackCamCS@@UAEPAXI@Z
    // 0x4F6D00 | ??1TrackCamCS@@UAE@XZ
    ARTS_IMPORT ~TrackCamCS() override;

    // 0x4F6DE0 | ?AddWidgets@TrackCamCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x4F6D90 | ?AfterLoad@TrackCamCS@@UAEXXZ
    ARTS_IMPORT void AfterLoad() override;

    // 0x4F8F00 | ?GetClass@TrackCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4F6D50 | ?MakeActive@TrackCamCS@@UAEXXZ
    ARTS_IMPORT void MakeActive() override;

    // 0x4F6DA0 | ?Reset@TrackCamCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4F8A70 | ?SwingToRear@TrackCamCS@@QAEXXZ
    ARTS_IMPORT void SwingToRear();

    // 0x4F7270 | ?Update@TrackCamCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4F7350 | ?UpdateInput@TrackCamCS@@UAEXXZ
    ARTS_EXPORT void UpdateInput() override;

    // 0x4F8BE0 | ?DeclareFields@TrackCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // 0x4F85D0 | ?Collide@TrackCamCS@@AAEXVVector3@@@Z
    ARTS_IMPORT void Collide(class Vector3 arg1);

    // 0x4F8AE0 | ?Front@TrackCamCS@@AAEXM@Z | unused
    ARTS_IMPORT void Front(f32 arg1);

    // 0x4F8430 | ?MinMax@TrackCamCS@@AAEXVMatrix34@@@Z
    ARTS_IMPORT void MinMax(class Matrix34 arg1);

    // 0x4F8230 | ?PreApproach@TrackCamCS@@AAEXXZ
    ARTS_IMPORT void PreApproach();

    // 0x4F8B60 | ?Rear@TrackCamCS@@AAEXM@Z
    ARTS_IMPORT void Rear(f32 arg1);

    // 0x4F7360 | ?UpdateCar@TrackCamCS@@AAEXXZ
    ARTS_IMPORT void UpdateCar();

    // 0x4F7500 | ?UpdateHill@TrackCamCS@@AAEXXZ
    ARTS_EXPORT void UpdateHill();

    // 0x4F7E50 | ?UpdateSwing@TrackCamCS@@AAEXXZ
    ARTS_IMPORT void UpdateSwing();

    // 0x4F7510 | ?UpdateTrack@TrackCamCS@@AAEXXZ
    ARTS_IMPORT void UpdateTrack();

    u8 gap118[0x20C];
};

check_size(TrackCamCS, 0x324);

// 0x719380 | ?TrackCamCSMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass TrackCamCSMetaClass;
