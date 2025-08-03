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

#include "compbase.h"

class mmCompRaceRecord final : public mmCompBase
{
public:
    // ??0mmCompRaceRecord@@QAE@XZ
    ARTS_IMPORT mmCompRaceRecord();

    // ??1mmCompRaceRecord@@UAE@XZ
    ARTS_IMPORT ~mmCompRaceRecord() override;

    // ?Cull@mmCompRaceRecord@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Init@mmCompRaceRecord@@QAEXHPAD0000HH@Z
    ARTS_IMPORT void Init(i32 arg1, char* arg2, char* arg3, char* arg4, char* arg5, char* arg6, i32 arg7, i32 arg8);

    // ?InitTitle@mmCompRaceRecord@@QAEXMMMMPAULocString@@00000H@Z
    ARTS_IMPORT void InitTitle(f32 arg1, f32 arg2, f32 arg3, f32 arg4, LocString* arg5, LocString* arg6,
        LocString* arg7, LocString* arg8, LocString* arg9, LocString* arg10, i32 arg11);

    // ?LoadBitmap@mmCompRaceRecord@@QAEXPAD@Z
    ARTS_IMPORT void LoadBitmap(char* arg1);

    // ?Reset@mmCompRaceRecord@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SelectIfRaceType@mmCompRaceRecord@@QAEXHH@Z
    ARTS_IMPORT void SelectIfRaceType(i32 arg1, i32 arg2);

    // ?SetGeometry@mmCompRaceRecord@@UAEXMMMM@Z
    ARTS_IMPORT void SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4) override;

    // ?SetPosition@mmCompRaceRecord@@UAEXPAVmmTextNode@@HM@Z
    ARTS_IMPORT void SetPosition(mmTextNode* arg1, i32 arg2, f32 arg3) override;

    // ?SetSubwidgetGeometry@mmCompRaceRecord@@QAEXXZ
    ARTS_IMPORT void SetSubwidgetGeometry();

    // ?Update@mmCompRaceRecord@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap48[0x60];
};

check_size(mmCompRaceRecord, 0xA8);
