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
    mmcar:carsimcheap

    0x474880 | public: __thiscall mmWheelCheap::mmWheelCheap(void) | ??0mmWheelCheap@@QAE@XZ
    0x474950 | public: void __thiscall mmWheelCheap::Init(class Vector3 *,class aiVehicleData *,class asInertialCS *) | ?Init@mmWheelCheap@@QAEXPAVVector3@@PAVaiVehicleData@@PAVasInertialCS@@@Z
    0x474A20 | public: virtual void __thiscall mmWheelCheap::Update(void) | ?Update@mmWheelCheap@@UAEXXZ
    0x475180 | public: virtual void __thiscall mmWheelCheap::Reset(void) | ?Reset@mmWheelCheap@@UAEXXZ
    0x4751A0 | public: virtual void * __thiscall mmWheelCheap::`scalar deleting destructor'(unsigned int) | ??_GmmWheelCheap@@UAEPAXI@Z
    0x4751A0 | public: virtual void * __thiscall mmWheelCheap::`vector deleting destructor'(unsigned int) | ??_EmmWheelCheap@@UAEPAXI@Z
    0x61C170 | const mmWheelCheap::`vftable' | ??_7mmWheelCheap@@6B@
    0x6A7E7C | float EggFriction | ?EggFriction@@3MA
*/

#include "arts7/linear.h"

#include "mmdyna/isect.h"

class aiVehicleData;
class asInertialCS;
class agiPhysParameters;

class mmWheelCheap final : public asLinearCS
{
public:
    // ??0mmWheelCheap@@QAE@XZ
    ARTS_IMPORT mmWheelCheap();

    // ??_EmmWheelCheap@@UAEPAXI@Z
    // ??_GmmWheelCheap@@UAEPAXI@Z
    // ??1mmWheelCheap@@UAE@XZ | inline
    ARTS_IMPORT ~mmWheelCheap() override = default;

    // ?Init@mmWheelCheap@@QAEXPAVVector3@@PAVaiVehicleData@@PAVasInertialCS@@@Z
    ARTS_EXPORT void Init(Vector3* offset, aiVehicleData* data, asInertialCS* ics);

    // ?Reset@mmWheelCheap@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@mmWheelCheap@@UAEXXZ
    ARTS_IMPORT void Update() override;

    asInertialCS* VehicleICS;
    f32 Spring;
    f32 Damping;
    mmIntersection ISect;
    i32 OnGround;
    Vector3 WheelOffset;
    f32 Radius;
    f32 Load;
    f32 SuspensionY;
    f32 SuspensionX;
    f32 SuspensionZ;
    f32 RubberSpring;
    f32 RubberDamp;
    f32 SuspensionLimit;
    mmPolygon* LastHitPoly;
    agiPhysParameters* Phys;
};

check_size(mmWheelCheap, 0x17C);

// ?EggFriction@@3MA
ARTS_IMPORT extern f32 EggFriction;
