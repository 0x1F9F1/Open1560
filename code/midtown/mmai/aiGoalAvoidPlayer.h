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
    mmai:aiGoalAvoidPlayer

    0x46A370 | public: __thiscall aiGoalAvoidPlayer::aiGoalAvoidPlayer(class aiRailSet *,class aiVehicleAmbient *) | ??0aiGoalAvoidPlayer@@QAE@PAVaiRailSet@@PAVaiVehicleAmbient@@@Z
    0x46A3A0 | public: __thiscall aiGoalAvoidPlayer::~aiGoalAvoidPlayer(void) | ??1aiGoalAvoidPlayer@@QAE@XZ
    0x46A3B0 | public: virtual void __thiscall aiGoalAvoidPlayer::Init(void) | ?Init@aiGoalAvoidPlayer@@UAEXXZ
    0x46A3C0 | public: virtual void __thiscall aiGoalAvoidPlayer::Reset(void) | ?Reset@aiGoalAvoidPlayer@@UAEXXZ
    0x46A530 | public: virtual void __thiscall aiGoalAvoidPlayer::Update(void) | ?Update@aiGoalAvoidPlayer@@UAEXXZ
    0x46A700 | private: void __thiscall aiGoalAvoidPlayer::AvoidPlayer(void) | ?AvoidPlayer@aiGoalAvoidPlayer@@AAEXXZ
    0x46A970 | public: virtual int __thiscall aiGoalAvoidPlayer::Context(void) | ?Context@aiGoalAvoidPlayer@@UAEHXZ
    0x46A990 | public: virtual int __thiscall aiGoalAvoidPlayer::Priority(void) | ?Priority@aiGoalAvoidPlayer@@UAEHXZ
    0x46A9A0 | public: void __thiscall aiGoalAvoidPlayer::Dump(void) | ?Dump@aiGoalAvoidPlayer@@QAEXXZ
    0x61BD10 | const aiGoalAvoidPlayer::`vftable' | ??_7aiGoalAvoidPlayer@@6B@
*/

#include "aiGoal.h"

class aiGoalAvoidPlayer final : public aiGoal
{
    // const aiGoalAvoidPlayer::`vftable'

public:
    // ??0aiGoalAvoidPlayer@@QAE@PAVaiRailSet@@PAVaiVehicleAmbient@@@Z
    ARTS_IMPORT aiGoalAvoidPlayer(class aiRailSet* arg1, class aiVehicleAmbient* arg2);

    // ??1aiGoalAvoidPlayer@@QAE@XZ
    ARTS_IMPORT ~aiGoalAvoidPlayer() = default;

    // ?Context@aiGoalAvoidPlayer@@UAEHXZ
    ARTS_IMPORT i32 Context() override;

    // ?Dump@aiGoalAvoidPlayer@@QAEXXZ
    ARTS_IMPORT void Dump();

    // ?Init@aiGoalAvoidPlayer@@UAEXXZ
    ARTS_IMPORT void Init() override;

    // ?Priority@aiGoalAvoidPlayer@@UAEHXZ
    ARTS_IMPORT i32 Priority() override;

    // ?Reset@aiGoalAvoidPlayer@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@aiGoalAvoidPlayer@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // ?AvoidPlayer@aiGoalAvoidPlayer@@AAEXXZ
    ARTS_IMPORT void AvoidPlayer();

    u8 gap8[0x14];
};

check_size(aiGoalAvoidPlayer, 0x1C);
