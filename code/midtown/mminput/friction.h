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
    mminput:friction

    0x4E7AA0 | public: virtual int __thiscall mmFrictionFF::Init(struct IDirectInputDevice2A *) | ?Init@mmFrictionFF@@UAEHPAUIDirectInputDevice2A@@@Z
    0x4E7BB0 | public: virtual int __thiscall mmFrictionFF::SetValues(float,float) | ?SetValues@mmFrictionFF@@UAEHMM@Z
    0x4E7BE0 | public: int __thiscall mmFrictionFF::Assign(long) | ?Assign@mmFrictionFF@@QAEHJ@Z
    0x4E7CB0 | public: virtual int __thiscall mmFrictionFF::Play(void) | ?Play@mmFrictionFF@@UAEHXZ
    0x4E7D10 | public: virtual int __thiscall mmFrictionFF::Stop(void) | ?Stop@mmFrictionFF@@UAEHXZ
*/

#include "effect.h"

class mmFrictionFF final : public mmEffectFF
{
public:
    // ?Assign@mmFrictionFF@@QAEHJ@Z
    ARTS_IMPORT i32 Assign(ilong arg1);

    // ?Init@mmFrictionFF@@UAEHPAUIDirectInputDevice2A@@@Z
    ARTS_IMPORT i32 Init(IDirectInputDevice2A* arg1) override;

    // ?Play@mmFrictionFF@@UAEHXZ
    ARTS_IMPORT i32 Play() override;

    // ?SetValues@mmFrictionFF@@UAEHMM@Z
    ARTS_IMPORT i32 SetValues(f32 arg1, f32 arg2) override;

    // ?Stop@mmFrictionFF@@UAEHXZ
    ARTS_IMPORT i32 Stop() override;

    u8 gap80[0x1C];
};

check_size(mmFrictionFF, 0x9C);
