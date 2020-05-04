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
    mmai:aiPoliceForce

    0x44E7E0 | public: __thiscall aiPoliceForce::aiPoliceForce(void) | ??0aiPoliceForce@@QAE@XZ
    0x44E800 | public: __thiscall aiPoliceForce::~aiPoliceForce(void) | ??1aiPoliceForce@@QAE@XZ
    0x44E810 | public: void __thiscall aiPoliceForce::Reset(void) | ?Reset@aiPoliceForce@@QAEXXZ
    0x44E850 | public: void __thiscall aiPoliceForce::Update(void) | ?Update@aiPoliceForce@@QAEXXZ
    0x44E860 | public: int __thiscall aiPoliceForce::Find(class mmCar *,class mmCar *) | ?Find@aiPoliceForce@@QAEHPAVmmCar@@0@Z
    0x44E8D0 | public: int __thiscall aiPoliceForce::RegisterPerp(class mmCar *,class mmCar *) | ?RegisterPerp@aiPoliceForce@@QAEHPAVmmCar@@0@Z
    0x44E970 | public: int __thiscall aiPoliceForce::UnRegisterCop(class mmCar *,class mmCar *) | ?UnRegisterCop@aiPoliceForce@@QAEHPAVmmCar@@0@Z
    0x44EA60 | public: int __thiscall aiPoliceForce::State(class mmCar *,class mmCar *,float) | ?State@aiPoliceForce@@QAEHPAVmmCar@@0M@Z
*/

struct aiPoliceForce
{
public:
    // 0x44E7E0 | ??0aiPoliceForce@@QAE@XZ
    aiPoliceForce();

    // 0x44E800 | ??1aiPoliceForce@@QAE@XZ
    ~aiPoliceForce();

    // 0x44E860 | ?Find@aiPoliceForce@@QAEHPAVmmCar@@0@Z
    i32 Find(class mmCar* arg1, class mmCar* arg2);

    // 0x44E8D0 | ?RegisterPerp@aiPoliceForce@@QAEHPAVmmCar@@0@Z
    i32 RegisterPerp(class mmCar* arg1, class mmCar* arg2);

    // 0x44E810 | ?Reset@aiPoliceForce@@QAEXXZ
    void Reset();

    // 0x44EA60 | ?State@aiPoliceForce@@QAEHPAVmmCar@@0M@Z
    i32 State(class mmCar* arg1, class mmCar* arg2, f32 arg3);

    // 0x44E970 | ?UnRegisterCop@aiPoliceForce@@QAEHPAVmmCar@@0@Z
    i32 UnRegisterCop(class mmCar* arg1, class mmCar* arg2);

    // 0x44E850 | ?Update@aiPoliceForce@@QAEXXZ
    void Update();
};

check_size(aiPoliceForce, 0x3C);
