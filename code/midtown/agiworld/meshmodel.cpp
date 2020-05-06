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

define_dummy_symbol(agiworld_meshmodel);

#include "meshmodel.h"

i32 agiMeshModel::ModelDraw(u32 arg1, class agiLitAnimation* arg2, i32 arg3)
{
    return stub<thiscall_t<i32, agiMeshModel*, u32, class agiLitAnimation*, i32>>(0x5142B0, this, arg1, arg2, arg3);
}

i32 agiMeshModel::ModelDraw(u32 arg1, class bnAnimation* arg2, i32 arg3)
{
    return stub<thiscall_t<i32, agiMeshModel*, u32, class bnAnimation*, i32>>(0x5142D0, this, arg1, arg2, arg3);
}

i32 agiMeshModel::ModelDrawLit(
    void (*arg1)(u8*, u32*, u32*, class agiMeshSet*), u32 arg2, class agiLitAnimation* arg3, i32 arg4)
{
    return stub<
        thiscall_t<i32, agiMeshModel*, void (*)(u8*, u32*, u32*, class agiMeshSet*), u32, class agiLitAnimation*, i32>>(
        0x5144F0, this, arg1, arg2, arg3, arg4);
}

i32 agiMeshModel::ModelDrawSkel(u32 arg1, class bnAnimation* arg2, i32 arg3)
{
    return stub<thiscall_t<i32, agiMeshModel*, u32, class bnAnimation*, i32>>(0x514330, this, arg1, arg2, arg3);
}

i32 agiMeshModel::ModelGeometry(u32 arg1, class bnAnimation* arg2, i32 arg3)
{
    return stub<thiscall_t<i32, agiMeshModel*, u32, class bnAnimation*, i32>>(0x5141B0, this, arg1, arg2, arg3);
}

agiLitAnimation::agiLitAnimation(class agiMeshModel* arg1, class bnAnimation* arg2, class Stream* arg3)
{
    unimplemented(arg1, arg2, arg3);
}
