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

class mmWheelCheap : public asLinearCS
{
    // const mmWheelCheap::`vftable' @ 0x61C170

public:
    // 0x474880 | ??0mmWheelCheap@@QAE@XZ
    mmWheelCheap();

    // 0x4751A0 | ??_EmmWheelCheap@@UAEPAXI@Z
    // 0x453A50 | ??1mmWheelCheap@@UAE@XZ
    ~mmWheelCheap() override;

    // 0x474950 | ?Init@mmWheelCheap@@QAEXPAVVector3@@PAVaiVehicleData@@PAVasInertialCS@@@Z
    void Init(class Vector3* arg1, class aiVehicleData* arg2, class asInertialCS* arg3);

    // 0x475180 | ?Reset@mmWheelCheap@@UAEXXZ
    void Reset() override;

    // 0x474A20 | ?Update@mmWheelCheap@@UAEXXZ
    void Update() override;
};

check_size(mmWheelCheap, 0x0);

// 0x6A7E7C | ?EggFriction@@3MA
inline extern_var(0x2A7E7C_Offset, f32, EggFriction);
