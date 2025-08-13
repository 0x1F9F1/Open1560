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

#include "mmnetwork/netobject.h"
#include "vector7/matrix34.h"
#include "vector7/vector3.h"

class mmCar;

struct NETGAME_MSG
{
    i32 MessageId;
    i32 SenderId;
    f32 Steering;
    char Throttle;
    char Brakes;
    Vector3 Rotation;
    Vector3 Position;
    Vector3 Velocity;
    f32 Time;
    f32 Damage;
    u16 Score;
    u16 Flags;
    i32 LastUpdateIdx;
    char StringValue[4];
};

#define NET_FLAG_HORN 0x2
#define NET_FLAG_REVERSE 0x4
#define NET_FLAG_SIREN 0x8

class mmNetObject final : public asNetObject
{
public:
    // ??0mmNetObject@@QAE@XZ
    ARTS_EXPORT mmNetObject();

    // ??1mmNetObject@@UAE@XZ
    ARTS_EXPORT ~mmNetObject() override = default;

    // ?Activate@mmNetObject@@QAEXXZ
    ARTS_EXPORT void Activate();

    // ?Clear@mmNetObject@@QAEXXZ
    ARTS_EXPORT void Clear();

    // ?Deactivate@mmNetObject@@QAEXXZ
    ARTS_EXPORT void Deactivate();

    // ?Init@mmNetObject@@QAEXPAVmmCar@@PADHK1@Z
    ARTS_EXPORT void Init(mmCar* car, char* vehicle, i32 variant, ulong player_id, char* name);

    // ?PositionUpdate@mmNetObject@@QAEXPAUNETGAME_MSG@@@Z
    ARTS_EXPORT void PositionUpdate(NETGAME_MSG* msg);

    // ?Predict@mmNetObject@@QAEXXZ
    ARTS_EXPORT void Predict();

    // ?ReInit@mmNetObject@@QAEXPAVmmCar@@PADHK1@Z
    ARTS_EXPORT void ReInit(mmCar* car, char* vehicle, i32 variant, ulong player_id, char* name);

    // ?SetActive@mmNetObject@@QAEXH@Z
    ARTS_EXPORT void SetActive(i32 active);

    // ?SetCar@mmNetObject@@QAEXPAVmmCar@@@Z
    ARTS_EXPORT void SetCar(mmCar* car);

    // ?SetLocalData@mmNetObject@@UAEXXZ
    ARTS_EXPORT void SetLocalData() override;

    // ?Update@mmNetObject@@UAEXXZ
    ARTS_EXPORT void Update() override;

    u32 field_28;
    u32 Flags;
    i32 Score;
    f32 Time;
    NETGAME_MSG LocalData;
    mmCar* Car;
    b32 IsEnabled;
    u32 Active;
    u32 UpdateCount;
    b32 MatrixChanged;
    f32 ActivateTime;
    f32 Steering;
    f32 PrevSteering;
    f32 SteeringDelta;
    f32 Throttle;
    f32 PrevThrottle;
    f32 ThrottleDelta;
    f32 Brakes;
    f32 PrevBrakes;
    f32 BrakesDelta;
    f32 field_BC;
    f32 field_C0;
    Matrix34 Matrix;
};

check_size(mmNetObject, 0xF4);

// ?time_delta@@3MA
ARTS_IMPORT extern f32 time_delta;
