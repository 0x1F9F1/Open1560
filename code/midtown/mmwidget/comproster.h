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

class mmCompRoster final : public mmCompBase
{
public:
    // ??0mmCompRoster@@QAE@XZ
    ARTS_IMPORT mmCompRoster();

    // ??_EmmCompRoster@@UAEPAXI@Z
    // ??_GmmCompRoster@@UAEPAXI@Z
    // ??1mmCompRoster@@UAE@XZ
    ARTS_IMPORT ~mmCompRoster() override;

    // ?Cull@mmCompRoster@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Init@mmCompRoster@@QAEXPAD00K@Z
    ARTS_IMPORT void Init(char* arg1, char* arg2, char* arg3, ulong arg4);

    // ?InitTitle@mmCompRoster@@QAEXMMMMPAULocString@@000H@Z | unused
    ARTS_EXPORT void InitTitle(f32 arg1, f32 arg2, f32 arg3, f32 arg4, LocString* arg5, LocString* arg6,
        LocString* arg7, LocString* arg8, i32 arg9);

    // ?LoadBitmap@mmCompRoster@@QAEXPAD@Z
    ARTS_IMPORT void LoadBitmap(char* arg1);

    // ?Reset@mmCompRoster@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetBltXY@mmCompRoster@@UAEXMM@Z
    ARTS_IMPORT void SetBltXY(f32 arg1, f32 arg2) override;

    // ?SetGeometry@mmCompRoster@@UAEXMMMM@Z
    ARTS_IMPORT void SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4) override;

    // ?SetPosition@mmCompRoster@@UAEXPAVmmTextNode@@HM@Z
    ARTS_IMPORT void SetPosition(mmTextNode* arg1, i32 arg2, f32 arg3) override;

    // ?SetReady@mmCompRoster@@QAEXH@Z
    ARTS_IMPORT void SetReady(i32 arg1);

    // ?SetSubwidgetGeometry@mmCompRoster@@QAEXXZ
    ARTS_IMPORT void SetSubwidgetGeometry();

    // ?Update@mmCompRoster@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap48[0x48];
};

check_size(mmCompRoster, 0x90);
