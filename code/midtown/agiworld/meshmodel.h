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
    agiworld:meshmodel

    0x5141B0 | public: int __thiscall agiMeshModel::ModelGeometry(unsigned int,class bnAnimation *,int) | ?ModelGeometry@agiMeshModel@@QAEHIPAVbnAnimation@@H@Z
    0x5142B0 | public: int __thiscall agiMeshModel::ModelDraw(unsigned int,class agiLitAnimation *,int) | ?ModelDraw@agiMeshModel@@QAEHIPAVagiLitAnimation@@H@Z
    0x5142D0 | public: int __thiscall agiMeshModel::ModelDraw(unsigned int,class bnAnimation *,int) | ?ModelDraw@agiMeshModel@@QAEHIPAVbnAnimation@@H@Z
    0x514330 | public: int __thiscall agiMeshModel::ModelDrawSkel(unsigned int,class bnAnimation *,int) | ?ModelDrawSkel@agiMeshModel@@QAEHIPAVbnAnimation@@H@Z
    0x5144F0 | public: int __thiscall agiMeshModel::ModelDrawLit(void (__cdecl*)(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *),unsigned int,class agiLitAnimation *,int) | ?ModelDrawLit@agiMeshModel@@QAEHP6AXPAEPAI1PAVagiMeshSet@@@ZIPAVagiLitAnimation@@H@Z
    0x5145C0 | public: __thiscall agiLitAnimation::agiLitAnimation(class agiMeshModel *,class bnAnimation *,class Stream *) | ??0agiLitAnimation@@QAE@PAVagiMeshModel@@PAVbnAnimation@@PAVStream@@@Z
*/

#include "meshset.h"

class agiMeshModel;
class bnAnimation;

class agiLitAnimation
{
public:
    // ??0agiLitAnimation@@QAE@PAVagiMeshModel@@PAVbnAnimation@@PAVStream@@@Z
    ARTS_IMPORT agiLitAnimation(agiMeshModel* arg1, bnAnimation* arg2, Stream* arg3);

    u8 gap0[0x10];
};

check_size(agiLitAnimation, 0x10);

class agiMeshModel final : public agiMeshSet
{
public:
    // ?ModelDraw@agiMeshModel@@QAEHIPAVagiLitAnimation@@H@Z
    ARTS_IMPORT i32 ModelDraw(u32 arg1, agiLitAnimation* arg2, i32 arg3);

    // ?ModelDraw@agiMeshModel@@QAEHIPAVbnAnimation@@H@Z
    ARTS_IMPORT i32 ModelDraw(u32 arg1, bnAnimation* arg2, i32 arg3);

    // ?ModelDrawLit@agiMeshModel@@QAEHP6AXPAEPAI1PAVagiMeshSet@@@ZIPAVagiLitAnimation@@H@Z
    ARTS_IMPORT i32 ModelDrawLit(void (*arg1)(u8*, u32*, u32*, agiMeshSet*), u32 arg2, agiLitAnimation* arg3, i32 arg4);

    // ?ModelDrawSkel@agiMeshModel@@QAEHIPAVbnAnimation@@H@Z
    ARTS_IMPORT i32 ModelDrawSkel(u32 arg1, bnAnimation* arg2, i32 arg3);

    // ?ModelGeometry@agiMeshModel@@QAEHIPAVbnAnimation@@H@Z
    ARTS_IMPORT i32 ModelGeometry(u32 arg1, bnAnimation* arg2, i32 arg3);

    u8 gap64[0x44];
};

check_size(agiMeshModel, 0xA8);
