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

define_dummy_symbol(mmanim_traincar);

#include "traincar.h"

mmAnimTrainCar::mmAnimTrainCar()
{
    unimplemented();
}

mmAnimTrainCar::~mmAnimTrainCar()
{
    unimplemented();
}

void __fastcall mmAnimTrainCar::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmAnimTrainCar*, i32>>(0x4C8100, this, arg1);
}

void mmAnimTrainCar::Init(char* arg1, char* arg2)
{
    return stub<thiscall_t<void, mmAnimTrainCar*, char*, char*>>(0x4C8060, this, arg1, arg2);
}

void mmAnimTrainCar::Reset()
{
    return stub<thiscall_t<void, mmAnimTrainCar*>>(0x4C8150, this);
}

void mmAnimTrainCar::SetMatrix(class Matrix34& arg1)
{
    return stub<thiscall_t<void, mmAnimTrainCar*, class Matrix34&>>(0x4C80E0, this, arg1);
}

void mmAnimTrainCar::SetStart(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmAnimTrainCar*, f32, f32>>(0x4C8160, this, arg1, arg2);
}
