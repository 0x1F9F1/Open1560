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

struct aiGoalAvoidPlayer
{
    // const aiGoalAvoidPlayer::`vftable' @ 0x61BD10

public:
    // 0x46A370 | ??0aiGoalAvoidPlayer@@QAE@PAVaiRailSet@@PAVaiVehicleAmbient@@@Z
    aiGoalAvoidPlayer(class aiRailSet* arg1, class aiVehicleAmbient* arg2);

    // 0x46A3A0 | ??1aiGoalAvoidPlayer@@QAE@XZ
    ~aiGoalAvoidPlayer();

    // 0x46A3B0 | ?Init@aiGoalAvoidPlayer@@UAEXXZ
    virtual void Init();

    // 0x46A3C0 | ?Reset@aiGoalAvoidPlayer@@UAEXXZ
    virtual void Reset();

    // 0x46A970 | ?Context@aiGoalAvoidPlayer@@UAEHXZ
    virtual i32 Context();

    // 0x46A990 | ?Priority@aiGoalAvoidPlayer@@UAEHXZ
    virtual i32 Priority();

    // 0x46A530 | ?Update@aiGoalAvoidPlayer@@UAEXXZ
    virtual void Update();

    // 0x46A9A0 | ?Dump@aiGoalAvoidPlayer@@QAEXXZ
    void Dump();

private:
    // 0x46A700 | ?AvoidPlayer@aiGoalAvoidPlayer@@AAEXXZ
    void AvoidPlayer();
};

check_size(aiGoalAvoidPlayer, 0x1C);
