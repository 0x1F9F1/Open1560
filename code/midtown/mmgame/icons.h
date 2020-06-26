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
    mmgame:icons

    0x426390 | public: __thiscall mmIcons::mmIcons(void) | ??0mmIcons@@QAE@XZ
    0x426410 | public: virtual __thiscall mmIcons::~mmIcons(void) | ??1mmIcons@@UAE@XZ
    0x426470 | public: void __thiscall mmIcons::Init(class Matrix34 *,float,float) | ?Init@mmIcons@@QAEXPAVMatrix34@@MM@Z
    0x4264B0 | public: void __thiscall mmIcons::RegisterOpponents(struct OppIconInfo *,int,void *) | ?RegisterOpponents@mmIcons@@QAEXPAUOppIconInfo@@HPAX@Z
    0x426530 | public: virtual void __thiscall mmIcons::Update(void) | ?Update@mmIcons@@UAEXXZ
    0x426570 | public: virtual void __thiscall mmIcons::Cull(void) | ?Cull@mmIcons@@UAEXXZ
    0x426B70 | public: virtual void * __thiscall mmIcons::`vector deleting destructor'(unsigned int) | ??_EmmIcons@@UAEPAXI@Z
    0x426B70 | public: virtual void * __thiscall mmIcons::`scalar deleting destructor'(unsigned int) | ??_GmmIcons@@UAEPAXI@Z
    0x61AD28 | const mmIcons::`vftable' | ??_7mmIcons@@6B@
*/

#include "arts7/node.h"

class mmIcons : public asNode
{
    // const mmIcons::`vftable' @ 0x61AD28

public:
    // 0x426390 | ??0mmIcons@@QAE@XZ
    ARTS_IMPORT mmIcons();

    // 0x426B70 | ??_GmmIcons@@UAEPAXI@Z
    // 0x426410 | ??1mmIcons@@UAE@XZ
    ARTS_IMPORT ~mmIcons() override;

    // 0x426570 | ?Cull@mmIcons@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x426470 | ?Init@mmIcons@@QAEXPAVMatrix34@@MM@Z
    ARTS_IMPORT void Init(class Matrix34* arg1, f32 arg2, f32 arg3);

    // 0x4264B0 | ?RegisterOpponents@mmIcons@@QAEXPAUOppIconInfo@@HPAX@Z
    ARTS_IMPORT void RegisterOpponents(struct OppIconInfo* arg1, i32 arg2, void* arg3);

    // 0x426530 | ?Update@mmIcons@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x3C];
};

check_size(mmIcons, 0x5C);
