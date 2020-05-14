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
    unimplemented();
}

void mmAnimSpline::AddVector(class Vector3& arg1)
{
    return stub<thiscall_t<void, mmAnimSpline*, class Vector3&>>(0x4C39F0, this, arg1);
}

void mmAnimSpline::AirlinerSwap()
{
    return stub<thiscall_t<void, mmAnimSpline*>>(0x4C3C10, this);
}

void mmAnimSpline::ClearVectors()
{
    return stub<thiscall_t<void, mmAnimSpline*>>(0x4C39D0, this);
}

i32 mmAnimSpline::Init(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmAnimSpline*, char*, i32>>(0x4C3850, this, arg1, arg2);
}

i32 mmAnimSpline::InitBoat()
{
    return stub<thiscall_t<i32, mmAnimSpline*>>(0x4C3A90, this);
}

i32 mmAnimSpline::InitPlane()
{
    return stub<thiscall_t<i32, mmAnimSpline*>>(0x4C3AA0, this);
}

i32 mmAnimSpline::InitTrain()
{
    return stub<thiscall_t<i32, mmAnimSpline*>>(0x4C3B40, this);
}

i32 mmAnimSpline::LoadFile(char* arg1)
{
    return stub<thiscall_t<i32, mmAnimSpline*, char*>>(0x4C38F0, this, arg1);
}

void mmAnimSpline::Reset()
{
    return stub<thiscall_t<void, mmAnimSpline*>>(0x4C3BF0, this);
}

void mmAnimSpline::UFOSwap()
{
    return stub<thiscall_t<void, mmAnimSpline*>>(0x4C3CC0, this);
}

void mmAnimSpline::Update()
{
    return stub<thiscall_t<void, mmAnimSpline*>>(0x4C3BC0, this);
}
