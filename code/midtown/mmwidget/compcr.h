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

class mmCompCRPlayer final : public mmCompBase
{
public:
    // ??0mmCompCRPlayer@@QAE@XZ
    ARTS_IMPORT mmCompCRPlayer();

    // ??1mmCompCRPlayer@@UAE@XZ
    ARTS_IMPORT ~mmCompCRPlayer() override;

    // ?Cull@mmCompCRPlayer@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Init@mmCompCRPlayer@@QAEXPADH0HH@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2, char* arg3, i32 arg4, i32 arg5);

    // ?InitTitle@mmCompCRPlayer@@QAEXMMMMPAULocString@@000H@Z | unused
    void InitTitle(f32 arg1, f32 arg2, f32 arg3, f32 arg4, LocString* arg5, LocString* arg6, LocString* arg7,
        LocString* arg8, i32 arg9);

    // ?Reset@mmCompCRPlayer@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetGeometry@mmCompCRPlayer@@UAEXMMMM@Z
    ARTS_IMPORT void SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4) override;

    // ?SetPoints@mmCompCRPlayer@@QAEXH@Z
    ARTS_IMPORT void SetPoints(i32 arg1);

    // ?SetPosition@mmCompCRPlayer@@UAEXPAVmmTextNode@@HM@Z
    ARTS_IMPORT void SetPosition(mmTextNode* arg1, i32 arg2, f32 arg3) override;

    // ?SetSubwidgetGeometry@mmCompCRPlayer@@QAEXXZ
    ARTS_IMPORT void SetSubwidgetGeometry();

    // ?Update@mmCompCRPlayer@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap48[0x50];
};

check_size(mmCompCRPlayer, 0x98);
