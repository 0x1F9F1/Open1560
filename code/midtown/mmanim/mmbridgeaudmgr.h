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
    mmanim:mmbridgeaudmgr

    0x4C3D10 | public: __thiscall mmBridgeAudMgr::mmBridgeAudMgr(void) | ??0mmBridgeAudMgr@@QAE@XZ
    0x4C3EC0 | public: virtual __thiscall mmBridgeAudMgr::~mmBridgeAudMgr(void) | ??1mmBridgeAudMgr@@UAE@XZ
    0x4C3F80 | public: short __thiscall mmBridgeAudMgr::Add(class mmBridgeSet *) | ?Add@mmBridgeAudMgr@@QAEFPAVmmBridgeSet@@@Z
    0x4C4010 | public: void __thiscall mmBridgeAudMgr::Remove(class mmBridgeSet *,short) | ?Remove@mmBridgeAudMgr@@QAEXPAVmmBridgeSet@@F@Z
    0x4C4070 | public: short __thiscall mmBridgeAudMgr::FindGreatestDistance(class mmBridgeSet *) | ?FindGreatestDistance@mmBridgeAudMgr@@QAEFPAVmmBridgeSet@@@Z
    0x4C4110 | public: short __thiscall mmBridgeAudMgr::FindUnusedSlot(void) | ?FindUnusedSlot@mmBridgeAudMgr@@QAEFXZ
    0x4C4150 | public: virtual void __thiscall mmBridgeAudMgr::Update(void) | ?Update@mmBridgeAudMgr@@UAEXXZ
    0x4C4180 | public: void __thiscall mmBridgeAudMgr::AssignSounds(short) | ?AssignSounds@mmBridgeAudMgr@@QAEXF@Z
    0x4C41B0 | public: virtual void * __thiscall mmBridgeAudMgr::`vector deleting destructor'(unsigned int) | ??_EmmBridgeAudMgr@@UAEPAXI@Z
    0x4C41B0 | public: virtual void * __thiscall mmBridgeAudMgr::`scalar deleting destructor'(unsigned int) | ??_GmmBridgeAudMgr@@UAEPAXI@Z
    0x61F430 | const mmBridgeAudMgr::`vftable' | ??_7mmBridgeAudMgr@@6B@
    0x705E1C | class mmBridgeAudMgr * MMBRIDGEAUDMGRPTR | ?MMBRIDGEAUDMGRPTR@@3PAVmmBridgeAudMgr@@A
*/

#include "arts7/node.h"

class mmBridgeAudMgr : public asNode
{
    // const mmBridgeAudMgr::`vftable' @ 0x61F430

public:
    // 0x4C3D10 | ??0mmBridgeAudMgr@@QAE@XZ
    ARTS_IMPORT mmBridgeAudMgr();

    // 0x4C41B0 | ??_GmmBridgeAudMgr@@UAEPAXI@Z
    // 0x4C41B0 | ??_EmmBridgeAudMgr@@UAEPAXI@Z
    // 0x4C3EC0 | ??1mmBridgeAudMgr@@UAE@XZ
    ARTS_IMPORT ~mmBridgeAudMgr() override;

    // 0x4C3F80 | ?Add@mmBridgeAudMgr@@QAEFPAVmmBridgeSet@@@Z
    ARTS_IMPORT i16 Add(class mmBridgeSet* arg1);

    // 0x4C4180 | ?AssignSounds@mmBridgeAudMgr@@QAEXF@Z
    ARTS_IMPORT void AssignSounds(i16 arg1);

    // 0x4C4070 | ?FindGreatestDistance@mmBridgeAudMgr@@QAEFPAVmmBridgeSet@@@Z
    ARTS_IMPORT i16 FindGreatestDistance(class mmBridgeSet* arg1);

    // 0x4C4110 | ?FindUnusedSlot@mmBridgeAudMgr@@QAEFXZ
    ARTS_IMPORT i16 FindUnusedSlot();

    // 0x4C4010 | ?Remove@mmBridgeAudMgr@@QAEXPAVmmBridgeSet@@F@Z
    ARTS_IMPORT void Remove(class mmBridgeSet* arg1, i16 arg2);

    // 0x4C4150 | ?Update@mmBridgeAudMgr@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x18];
};

check_size(mmBridgeAudMgr, 0x38);

// 0x705E1C | ?MMBRIDGEAUDMGRPTR@@3PAVmmBridgeAudMgr@@A
ARTS_IMPORT extern class mmBridgeAudMgr* MMBRIDGEAUDMGRPTR;
