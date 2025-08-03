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
