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
    mmeffects:damage

    0x502220 | public: __thiscall mmDamage::mmDamage(void) | ??0mmDamage@@QAE@XZ
    0x502230 | public: __thiscall mmDamage::~mmDamage(void) | ??1mmDamage@@QAE@XZ
    0x502240 | public: void __thiscall mmDamage::Init(class agiMeshSet *) | ?Init@mmDamage@@QAEXPAVagiMeshSet@@@Z
    0x502420 | public: void __thiscall mmDamage::Reset(int) | ?Reset@mmDamage@@QAEXH@Z
    0x502470 | public: void __thiscall mmDamage::Apply(class Vector3 &,float) | ?Apply@mmDamage@@QAEXAAVVector3@@M@Z
*/

class agiMeshSet;

struct mmDamage
{
public:
    // ??0mmDamage@@QAE@XZ
    ARTS_IMPORT mmDamage();

    // ??1mmDamage@@QAE@XZ
    ARTS_IMPORT ~mmDamage();

    // ?Apply@mmDamage@@QAEXAAVVector3@@M@Z
    ARTS_IMPORT void Apply(Vector3& arg1, f32 arg2);

    // ?Init@mmDamage@@QAEXPAVagiMeshSet@@@Z
    ARTS_IMPORT void Init(agiMeshSet* arg1);

    // ?Reset@mmDamage@@QAEXH@Z
    ARTS_IMPORT void Reset(i32 arg1);

private:
    agiMeshSet* mesh_ {nullptr};
    u8* surfaces_ {nullptr}; // agiMeshSet::TextureIndices
    i8 remap_[24];
};

check_size(mmDamage, 0x20);
