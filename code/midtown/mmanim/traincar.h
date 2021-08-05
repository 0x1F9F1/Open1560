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
    mmanim:traincar

    0x4C8030 | public: __thiscall mmAnimTrainCar::mmAnimTrainCar(void) | ??0mmAnimTrainCar@@QAE@XZ
    0x4C8050 | public: virtual __thiscall mmAnimTrainCar::~mmAnimTrainCar(void) | ??1mmAnimTrainCar@@UAE@XZ
    0x4C8060 | public: void __thiscall mmAnimTrainCar::Init(char *,char *) | ?Init@mmAnimTrainCar@@QAEXPAD0@Z
    0x4C80E0 | public: void __thiscall mmAnimTrainCar::SetMatrix(class Matrix34 &) | ?SetMatrix@mmAnimTrainCar@@QAEXAAVMatrix34@@@Z
    0x4C8100 | public: virtual void __fastcall mmAnimTrainCar::Draw(int) | ?Draw@mmAnimTrainCar@@UAIXH@Z
    0x4C8150 | public: virtual void __thiscall mmAnimTrainCar::Reset(void) | ?Reset@mmAnimTrainCar@@UAEXXZ
    0x4C8160 | public: void __thiscall mmAnimTrainCar::SetStart(float,float) | ?SetStart@mmAnimTrainCar@@QAEXMM@Z
    0x4C8190 | public: virtual void * __thiscall mmAnimTrainCar::`scalar deleting destructor'(unsigned int) | ??_GmmAnimTrainCar@@UAEPAXI@Z
    0x61F658 | const mmAnimTrainCar::`vftable' | ??_7mmAnimTrainCar@@6B@
*/

#include "mmcity/inst.h"

class mmAnimTrainCar final : public mmMatrixInstance
{
    // const mmAnimTrainCar::`vftable'

public:
    // ??0mmAnimTrainCar@@QAE@XZ
    ARTS_IMPORT mmAnimTrainCar();

    // ??_EmmAnimTrainCar@@UAEPAXI@Z
    // ??_GmmAnimTrainCar@@UAEPAXI@Z | unused
    // ??1mmAnimTrainCar@@UAE@XZ
    ARTS_IMPORT ~mmAnimTrainCar() override = default;

    // ?Draw@mmAnimTrainCar@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?Init@mmAnimTrainCar@@QAEXPAD0@Z
    ARTS_IMPORT void Init(char* arg1, char* arg2);

    // ?Reset@mmAnimTrainCar@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetMatrix@mmAnimTrainCar@@QAEXAAVMatrix34@@@Z
    ARTS_IMPORT void SetMatrix(class Matrix34& arg1);

    // ?SetStart@mmAnimTrainCar@@QAEXMM@Z
    ARTS_IMPORT void SetStart(f32 arg1, f32 arg2);

    u8 gap44[0x14];
};

check_size(mmAnimTrainCar, 0x58);
