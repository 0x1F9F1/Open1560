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

#include "mmcityinfo/infobase.h"

union eqEvent;

class mmIODev final : public mmInfoBase
{
public:
    // ??0mmIODev@@QAE@XZ
    ARTS_EXPORT mmIODev() = default;

    // ??1mmIODev@@UAE@XZ
    ARTS_EXPORT ~mmIODev() override = default;

    // ??8mmIODev@@QAEHPATeqEvent@@@Z
    b32 operator==(eqEvent* event);

    // ?Assign@mmIODev@@QAEXHHH@Z
    ARTS_IMPORT void Assign(i32 arg1, i32 arg2, i32 arg3);

    // ?GetComponentType@mmIODev@@QAEHHH@Z
    ARTS_EXPORT i32 GetComponentType(i32 device, i32 component);

    // ?GetDescription@mmIODev@@QAEXPAD@Z
    [[deprecated]] ARTS_EXPORT void GetDescription(char* buffer);

    void GetDescription(char* buffer, usize buflen);

    // ?Init@mmIODev@@QAEXH_J@Z
    ARTS_IMPORT void Init(i32 arg1, i64 arg2);

    // ?Print@mmIODev@@QAEXH@Z
    ARTS_IMPORT void Print(i32 arg1);

    // ?Read@mmIODev@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 Read(Stream* arg1);

    // ?ReadBinary@mmIODev@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 ReadBinary(Stream* arg1);

    // ?SanityCheckioType@mmIODev@@QAEHHHH@Z
    ARTS_IMPORT i32 SanityCheckioType(i32 arg1, i32 arg2, i32 arg3);

    // ?Write@mmIODev@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 Write(Stream* arg1);

    // ?WriteBinary@mmIODev@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 WriteBinary(Stream* arg1);

    i32 IoType {}; // ioType
    i64 IoidBits {};

    i32 Device {};    // eqEventType, mmIODevice
    i32 Component {}; // i32, mmJoyInput

    u64 State {};

    VIRTUAL_META_DECLARE;
};

check_size(mmIODev, 0xA8);

// ?ConvertDItoString@@YAHHPADH@Z
b32 ConvertDItoString(i32 vsc, char* buffer, i32 buflen);
