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
    mminput:road

    0x4E77C0 | public: virtual int __thiscall mmRoadFF::Init(struct IDirectInputDevice2A *) | ?Init@mmRoadFF@@UAEHPAUIDirectInputDevice2A@@@Z
    0x4E78C0 | public: virtual int __thiscall mmRoadFF::SetValues(float,float) | ?SetValues@mmRoadFF@@UAEHMM@Z
    0x4E78F0 | public: int __thiscall mmRoadFF::Assign(long,long) | ?Assign@mmRoadFF@@QAEHJJ@Z
    0x4E79E0 | public: virtual int __thiscall mmRoadFF::Play(void) | ?Play@mmRoadFF@@UAEHXZ
    0x4E7A50 | public: virtual int __thiscall mmRoadFF::Stop(void) | ?Stop@mmRoadFF@@UAEHXZ
*/

#include "effect.h"

class mmRoadFF final : public mmEffectFF
{
public:
    // ?Assign@mmRoadFF@@QAEHJJ@Z
    ARTS_IMPORT i32 Assign(ilong arg1, ilong arg2);

    // ?Init@mmRoadFF@@UAEHPAUIDirectInputDevice2A@@@Z
    ARTS_IMPORT i32 Init(IDirectInputDevice2A* arg1) override;

    // ?Play@mmRoadFF@@UAEHXZ
    ARTS_IMPORT i32 Play() override;

    // ?SetValues@mmRoadFF@@UAEHMM@Z
    ARTS_IMPORT i32 SetValues(f32 arg1, f32 arg2) override;

    // ?Stop@mmRoadFF@@UAEHXZ
    ARTS_IMPORT i32 Stop() override;

    u8 gap80[0x14];
};

check_size(mmRoadFF, 0x94);
