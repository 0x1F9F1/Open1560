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
    mmeffects:mousesteerbar

    0x502930 | public: __thiscall mmMouseSteerBar::mmMouseSteerBar(void) | ??0mmMouseSteerBar@@QAE@XZ
    0x502950 | public: virtual __thiscall mmMouseSteerBar::~mmMouseSteerBar(void) | ??1mmMouseSteerBar@@UAE@XZ
    0x502960 | public: void __thiscall mmMouseSteerBar::Init(float,float,float *) | ?Init@mmMouseSteerBar@@QAEXMMPAM@Z
    0x502A00 | public: virtual void __thiscall mmMouseSteerBar::Update(void) | ?Update@mmMouseSteerBar@@UAEXXZ
    0x502A30 | public: virtual void __thiscall mmMouseSteerBar::Cull(void) | ?Cull@mmMouseSteerBar@@UAEXXZ
    0x502AB0 | public: virtual void __thiscall mmMouseSteerBar::AddWidgets(class Bank *) | ?AddWidgets@mmMouseSteerBar@@UAEXPAVBank@@@Z
    0x502BA0 | public: virtual void * __thiscall mmMouseSteerBar::`vector deleting destructor'(unsigned int) | ??_EmmMouseSteerBar@@UAEPAXI@Z
    0x502BA0 | public: virtual void * __thiscall mmMouseSteerBar::`scalar deleting destructor'(unsigned int) | ??_GmmMouseSteerBar@@UAEPAXI@Z
    0x6207E0 | const mmMouseSteerBar::`vftable' | ??_7mmMouseSteerBar@@6B@
*/

#include "arts7/node.h"

class mmMouseSteerBar final : public asNode
{
    // const mmMouseSteerBar::`vftable' @ 0x6207E0

public:
    // 0x502930 | ??0mmMouseSteerBar@@QAE@XZ
    ARTS_IMPORT mmMouseSteerBar();

    // 0x502BA0 | ??_GmmMouseSteerBar@@UAEPAXI@Z
    // 0x502BA0 | ??_EmmMouseSteerBar@@UAEPAXI@Z
    // 0x502950 | ??1mmMouseSteerBar@@UAE@XZ
    ARTS_IMPORT ~mmMouseSteerBar() override = default;

    // 0x502AB0 | ?AddWidgets@mmMouseSteerBar@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x502A30 | ?Cull@mmMouseSteerBar@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x502960 | ?Init@mmMouseSteerBar@@QAEXMMPAM@Z
    ARTS_IMPORT void Init(f32 arg1, f32 arg2, f32* arg3);

    // 0x502A00 | ?Update@mmMouseSteerBar@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x24];
};

check_size(mmMouseSteerBar, 0x44);
