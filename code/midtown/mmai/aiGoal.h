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
    mmai:aiGoal
*/

class aiGoal
{
public:
    // ??1aiGoal@@QAE@XZ | inline
    ARTS_EXPORT ~aiGoal();

    virtual void Init() = 0;

    virtual void Reset() = 0;

    virtual b32 Context() = 0;

    virtual b32 Priority() = 0;

    // ?Update@aiGoal@@UAEXXZ | inline
    ARTS_EXPORT virtual void Update()
    {
        ++UpdateCount;
    }

    i32 UpdateCount {};
};

check_size(aiGoal, 0x8);

inline aiGoal::~aiGoal() = default;