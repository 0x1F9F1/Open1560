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
    mmcar:splash

    0x480FF0 | public: __thiscall mmSplash::mmSplash(void) | ??0mmSplash@@QAE@XZ
    0x481050 | void __cdecl SplashCB(class mmSplash *) | ?SplashCB@@YAXPAVmmSplash@@@Z
    0x481060 | public: virtual void __thiscall mmSplash::Reset(void) | ?Reset@mmSplash@@UAEXXZ
    0x481070 | public: void __thiscall mmSplash::Init(class asInertialCS *,class Vector3,class Vector3) | ?Init@mmSplash@@QAEXPAVasInertialCS@@VVector3@@1@Z
    0x4811C0 | public: void __thiscall mmSplash::Activate(float) | ?Activate@mmSplash@@QAEXM@Z
    0x4811E0 | public: virtual void __thiscall mmSplash::Update(void) | ?Update@mmSplash@@UAEXXZ
    0x481420 | public: virtual void __thiscall mmSplash::AddWidgets(class Bank *) | ?AddWidgets@mmSplash@@UAEXPAVBank@@@Z
    0x4814A0 | public: virtual void * __thiscall mmSplash::`vector deleting destructor'(unsigned int) | ??_EmmSplash@@UAEPAXI@Z
    0x4814A0 | public: virtual void * __thiscall mmSplash::`scalar deleting destructor'(unsigned int) | ??_GmmSplash@@UAEPAXI@Z
    0x61C8B0 | const mmSplash::`vftable' | ??_7mmSplash@@6B@
*/

#include "arts7/node.h"

class mmSplash : public asNode
{
    // const mmSplash::`vftable' @ 0x61C8B0

public:
    // 0x480FF0 | ??0mmSplash@@QAE@XZ
    ARTS_IMPORT mmSplash();

    // 0x4814A0 | ??_GmmSplash@@UAEPAXI@Z
    // 0x470310 | ??1mmSplash@@UAE@XZ | inline
    ARTS_IMPORT ~mmSplash() override;

    // 0x4811C0 | ?Activate@mmSplash@@QAEXM@Z
    ARTS_IMPORT void Activate(f32 arg1);

    // 0x481420 | ?AddWidgets@mmSplash@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x481070 | ?Init@mmSplash@@QAEXPAVasInertialCS@@VVector3@@1@Z
    ARTS_IMPORT void Init(class asInertialCS* arg1, class Vector3 arg2, class Vector3 arg3);

    // 0x481060 | ?Reset@mmSplash@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4811E0 | ?Update@mmSplash@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x310];
};

check_size(mmSplash, 0x330);
