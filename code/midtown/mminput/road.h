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

class mmRoadFF : public mmEffectFF
{
    // const mmRoadFF::`vftable' @ 0x61FD00

public:
    // 0x4E78F0 | ?Assign@mmRoadFF@@QAEHJJ@Z
    ARTS_IMPORT i32 Assign(i32 arg1, i32 arg2);

    // 0x4E77C0 | ?Init@mmRoadFF@@UAEHPAUIDirectInputDevice2A@@@Z
    ARTS_IMPORT i32 Init(struct IDirectInputDevice2A* arg1) override;

    // 0x4E79E0 | ?Play@mmRoadFF@@UAEHXZ
    ARTS_IMPORT i32 Play() override;

    // 0x4E78C0 | ?SetValues@mmRoadFF@@UAEHMM@Z
    ARTS_IMPORT i32 SetValues(f32 arg1, f32 arg2) override;

    // 0x4E7A50 | ?Stop@mmRoadFF@@UAEHXZ
    ARTS_IMPORT i32 Stop() override;
};

check_size(mmRoadFF, 0x94);
