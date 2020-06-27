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
    mmwidget:ttip

    0x4BF0E0 | public: __thiscall mmToolTip::mmToolTip(void) | ??0mmToolTip@@QAE@XZ
    0x4BF150 | public: virtual __thiscall mmToolTip::~mmToolTip(void) | ??1mmToolTip@@UAE@XZ
    0x4BF1B0 | public: void __thiscall mmToolTip::Init(class UIMenu *,struct LocString *) | ?Init@mmToolTip@@QAEXPAVUIMenu@@PAULocString@@@Z
    0x4BF260 | public: void __thiscall mmToolTip::SetText(struct LocString *) | ?SetText@mmToolTip@@QAEXPAULocString@@@Z
    0x4BF280 | public: void __thiscall mmToolTip::Switch(int) | ?Switch@mmToolTip@@QAEXH@Z
    0x4BF290 | public: virtual void __thiscall mmToolTip::Update(void) | ?Update@mmToolTip@@UAEXXZ
    0x4BF2A0 | public: virtual void * __thiscall mmToolTip::`vector deleting destructor'(unsigned int) | ??_EmmToolTip@@UAEPAXI@Z
    0x4BF2A0 | public: virtual void * __thiscall mmToolTip::`scalar deleting destructor'(unsigned int) | ??_GmmToolTip@@UAEPAXI@Z
    0x61F190 | const mmToolTip::`vftable' | ??_7mmToolTip@@6B@
*/

#include "arts7/node.h"

class mmToolTip : public asNode
{
    // const mmToolTip::`vftable' @ 0x61F190

public:
    // 0x4BF0E0 | ??0mmToolTip@@QAE@XZ | unused
    ARTS_IMPORT mmToolTip();

    // 0x4BF2A0 | ??_GmmToolTip@@UAEPAXI@Z
    // 0x4BF2A0 | ??_EmmToolTip@@UAEPAXI@Z
    // 0x4BF150 | ??1mmToolTip@@UAE@XZ
    ARTS_IMPORT ~mmToolTip() override;

    // 0x4BF1B0 | ?Init@mmToolTip@@QAEXPAVUIMenu@@PAULocString@@@Z | unused
    ARTS_IMPORT void Init(class UIMenu* arg1, struct LocString* arg2);

    // 0x4BF260 | ?SetText@mmToolTip@@QAEXPAULocString@@@Z
    ARTS_IMPORT void SetText(struct LocString* arg1);

    // 0x4BF280 | ?Switch@mmToolTip@@QAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1);

    // 0x4BF290 | ?Update@mmToolTip@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x14];
};

check_size(mmToolTip, 0x34);
