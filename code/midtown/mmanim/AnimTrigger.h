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

class mmInstance;

class mmAnimTrigger
{
public:
    // ??0mmAnimTrigger@@QAE@XZ
    ARTS_IMPORT mmAnimTrigger();

    // ??1mmAnimTrigger@@QAE@XZ
    ARTS_EXPORT ~mmAnimTrigger() = default;

    // ?CheckCondition@mmAnimTrigger@@QAEHXZ
    ARTS_IMPORT i32 CheckCondition();

    // ?CheckObjectDistance@mmAnimTrigger@@QAEHXZ
    ARTS_IMPORT i32 CheckObjectDistance();

    // ?CheckObjectHit@mmAnimTrigger@@QAEHXZ
    ARTS_IMPORT i32 CheckObjectHit();

    // ?CheckStateStatus@mmAnimTrigger@@QAEHXZ
    ARTS_IMPORT i32 CheckStateStatus();

    // ?CheckTimeDelay@mmAnimTrigger@@QAEHXZ
    ARTS_IMPORT i32 CheckTimeDelay();

    // ?Init@mmAnimTrigger@@QAEXPAVVector3@@PAM@Z
    ARTS_IMPORT void Init(Vector3* arg1, f32* arg2);

    // ?Reset@mmAnimTrigger@@QAEXXZ
    ARTS_IMPORT void Reset();

    u8 gap0[0x24];
};

check_size(mmAnimTrigger, 0x24);
