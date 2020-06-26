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
    mmai:aiVehicle

    0x4658F0 | public: __thiscall aiVehicle::aiVehicle(void) | ??0aiVehicle@@QAE@XZ
    0x465910 | public: __thiscall aiVehicle::~aiVehicle(void) | ??1aiVehicle@@QAE@XZ
    0x465920 | public: void __thiscall aiVehicle::Init(int) | ?Init@aiVehicle@@QAEXH@Z
    0x465930 | public: virtual void __thiscall aiVehicle::Reset(void) | ?Reset@aiVehicle@@UAEXXZ
    0x465940 | public: virtual void __thiscall aiVehicle::Update(void) | ?Update@aiVehicle@@UAEXXZ
    0x61BC40 | const aiVehicle::`vftable' | ??_7aiVehicle@@6B@
*/

struct aiVehicle
{
    // const aiVehicle::`vftable' @ 0x61BC40

public:
    // 0x4658F0 | ??0aiVehicle@@QAE@XZ
    ARTS_IMPORT aiVehicle();

    // 0x465910 | ??1aiVehicle@@QAE@XZ
    ARTS_IMPORT ~aiVehicle();

    // 0x465940 | ?Update@aiVehicle@@UAEXXZ
    ARTS_IMPORT virtual void Update();

    // 0x465930 | ?Reset@aiVehicle@@UAEXXZ
    ARTS_IMPORT virtual void Reset();

    virtual i32 Type() = 0;

    virtual void DrawId() = 0;

    // 0x465920 | ?Init@aiVehicle@@QAEXH@Z
    ARTS_IMPORT void Init(i32 arg1);
};

check_size(aiVehicle, 0x14);
