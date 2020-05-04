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

#include "arts7/node.h"

/*
    mmcar:stuck

    0x47C480 | public: __thiscall mmStuck::mmStuck(void) | ??0mmStuck@@QAE@XZ
    0x47C520 | public: void __thiscall mmStuck::Init(class mmCarSim *) | ?Init@mmStuck@@QAEXPAVmmCarSim@@@Z
    0x47C540 | public: void __thiscall mmStuck::Impact(void) | ?Impact@mmStuck@@QAEXXZ
    0x47C550 | public: virtual void __thiscall mmStuck::Reset(void) | ?Reset@mmStuck@@UAEXXZ
    0x47C560 | public: int __thiscall mmStuck::Pegged(void) | ?Pegged@mmStuck@@QAEHXZ
    0x47C5B0 | public: virtual void __thiscall mmStuck::Update(void) | ?Update@mmStuck@@UAEXXZ
    0x47C7D0 | public: virtual void __thiscall mmStuck::AddWidgets(class Bank *) | ?AddWidgets@mmStuck@@UAEXPAVBank@@@Z
    0x47C900 | public: virtual void * __thiscall mmStuck::`vector deleting destructor'(unsigned int) | ??_EmmStuck@@UAEPAXI@Z
    0x47C900 | public: virtual void * __thiscall mmStuck::`scalar deleting destructor'(unsigned int) | ??_GmmStuck@@UAEPAXI@Z
    0x61C540 | const mmStuck::`vftable' | ??_7mmStuck@@6B@
*/

class mmStuck : public asNode
{
    // const mmStuck::`vftable' @ 0x61C540

public:
    // 0x47C480 | ??0mmStuck@@QAE@XZ
    mmStuck();

    // 0x47C900 | ??_GmmStuck@@UAEPAXI@Z
    // 0x470300 | ??1mmStuck@@UAE@XZ
    ~mmStuck() override;

    // 0x47C7D0 | ?AddWidgets@mmStuck@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x47C540 | ?Impact@mmStuck@@QAEXXZ
    void Impact();

    // 0x47C520 | ?Init@mmStuck@@QAEXPAVmmCarSim@@@Z
    void Init(class mmCarSim* arg1);

    // 0x47C560 | ?Pegged@mmStuck@@QAEHXZ
    i32 Pegged();

    // 0x47C550 | ?Reset@mmStuck@@UAEXXZ
    void Reset() override;

    // 0x47C5B0 | ?Update@mmStuck@@UAEXXZ
    void Update() override;
};

check_size(mmStuck, 0x0);
