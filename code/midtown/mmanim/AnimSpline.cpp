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

define_dummy_symbol(mmanim_AnimSpline);

#include "AnimSpline.h"

mmAnimSpline::mmAnimSpline()
{
    unimplemented();
}

mmAnimSpline::~mmAnimSpline()
{
    unimplemented(arg1);
}

void mmAnimSpline::AddVector(class Vector3& arg1)
{
    return stub<thiscall_t<void, mmAnimSpline*, class Vector3&>>(0xC39F0_Offset, this, arg1);
}

void mmAnimSpline::AirlinerSwap()
{
    return stub<thiscall_t<void, mmAnimSpline*>>(0xC3C10_Offset, this);
}

void mmAnimSpline::ClearVectors()
{
    return stub<thiscall_t<void, mmAnimSpline*>>(0xC39D0_Offset, this);
}

i32 mmAnimSpline::Init(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmAnimSpline*, char*, i32>>(0xC3850_Offset, this, arg1, arg2);
}

i32 mmAnimSpline::InitBoat()
{
    return stub<thiscall_t<i32, mmAnimSpline*>>(0xC3A90_Offset, this);
}

i32 mmAnimSpline::InitPlane()
{
    return stub<thiscall_t<i32, mmAnimSpline*>>(0xC3AA0_Offset, this);
}

i32 mmAnimSpline::InitTrain()
{
    return stub<thiscall_t<i32, mmAnimSpline*>>(0xC3B40_Offset, this);
}

i32 mmAnimSpline::LoadFile(char* arg1)
{
    return stub<thiscall_t<i32, mmAnimSpline*, char*>>(0xC38F0_Offset, this, arg1);
}

void mmAnimSpline::Reset()
{
    return stub<thiscall_t<void, mmAnimSpline*>>(0xC3BF0_Offset, this);
}

void mmAnimSpline::UFOSwap()
{
    return stub<thiscall_t<void, mmAnimSpline*>>(0xC3CC0_Offset, this);
}

void mmAnimSpline::Update()
{
    return stub<thiscall_t<void, mmAnimSpline*>>(0xC3BC0_Offset, this);
}
