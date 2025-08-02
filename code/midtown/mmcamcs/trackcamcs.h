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

#define TRACK_CAM_NEAR 0
#define TRACK_CAM_BASE 1
#define TRACK_CAM_FAR 2
#define TRACK_CAM_XCAM 3
#define TRACK_CAM_HELICOPTER 4

class TrackCamCS final : public CarCamCS
{
public:
    // ??0TrackCamCS@@QAE@XZ
    ARTS_IMPORT TrackCamCS();

    // ??_ETrackCamCS@@UAEPAXI@Z
    // ??1TrackCamCS@@UAE@XZ
    ARTS_IMPORT ~TrackCamCS() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@TrackCamCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AfterLoad@TrackCamCS@@UAEXXZ
    ARTS_IMPORT void AfterLoad() override;

    // ?GetClass@TrackCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?MakeActive@TrackCamCS@@UAEXXZ
    ARTS_IMPORT void MakeActive() override;

    // ?Reset@TrackCamCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SwingToRear@TrackCamCS@@QAEXXZ
    ARTS_IMPORT void SwingToRear();

    // ?Update@TrackCamCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateInput@TrackCamCS@@UAEXXZ
    ARTS_EXPORT void UpdateInput() override;

    // ?DeclareFields@TrackCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?Collide@TrackCamCS@@AAEXVVector3@@@Z
    ARTS_IMPORT void Collide(Vector3 arg1);

    // ?MinMax@TrackCamCS@@AAEXVMatrix34@@@Z
    ARTS_IMPORT void MinMax(Matrix34 arg1);

    // ?PreApproach@TrackCamCS@@AAEXXZ
    ARTS_IMPORT void PreApproach();

    // ?Rear@TrackCamCS@@AAEXM@Z
    ARTS_IMPORT void Rear(f32 arg1);

    // ?UpdateCar@TrackCamCS@@AAEXXZ
    ARTS_IMPORT void UpdateCar();

    // ?UpdateHill@TrackCamCS@@AAEXXZ
    ARTS_EXPORT void UpdateHill();

    // ?UpdateSwing@TrackCamCS@@AAEXXZ
    ARTS_IMPORT void UpdateSwing();

    // ?UpdateTrack@TrackCamCS@@AAEXXZ
    ARTS_IMPORT void UpdateTrack();

    u8 gap118[0x20C];
};

check_size(TrackCamCS, 0x324);
