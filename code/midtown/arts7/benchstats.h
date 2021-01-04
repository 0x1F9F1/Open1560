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
    arts7:benchstats

    0x52CE60 | public: void __thiscall asBenchStats::Reset(void) | ?Reset@asBenchStats@@QAEXXZ
    0x52CEA0 | public: void __thiscall asBenchStats::Print(void) | ?Print@asBenchStats@@QAEXXZ
    0x52CEB0 | public: void __thiscall asBenchStats::Average(class asBenchStats *,float,int) | ?Average@asBenchStats@@QAEXPAV1@MH@Z
    0x52CFD0 | public: void __thiscall asBenchStats::Current(class asBenchStats *) | ?Current@asBenchStats@@QAEXPAV1@@Z
*/

class asBenchStats
{
public:
    // 0x52CEB0 | ?Average@asBenchStats@@QAEXPAV1@MH@Z
    ARTS_IMPORT void Average(class asBenchStats* arg1, f32 arg2, i32 arg3);

    // 0x52CFD0 | ?Current@asBenchStats@@QAEXPAV1@@Z
    ARTS_IMPORT void Current(class asBenchStats* arg1);

    // 0x52CEA0 | ?Print@asBenchStats@@QAEXXZ
    ARTS_EXPORT void Print();

    // 0x52CE60 | ?Reset@asBenchStats@@QAEXXZ
    ARTS_IMPORT void Reset();

    i32 field_0;
    i32 field_4;
    i32 field_8;
    i32 field_C;
    i32 field_10;
    i32 field_14;
    i32 field_18;
    f32 UpdateTime;
    f32 DeviceTime;
    f32 field_24;
    f32 Widgets;
    f32 field_2C;
    f32 field_30;
    i32 field_34;
    i32 field_38;
    i32 field_3C;
    i32 LCSUpdates;
    i32 field_44;
    i32 field_48;
    i32 field_4C;
};

check_size(asBenchStats, 0x50);
