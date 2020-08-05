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
    data7:utimer

    0x57C4C0 | unsigned long __cdecl utimer(void) | ?utimer@@YAKXZ
    0x90B4B4 | float ut2float | ?ut2float@@3MA
*/

// 0x57C4C0 | ?utimer@@YAKXZ
ARTS_IMPORT ulong utimer();

// 0x90B4B4 | ?ut2float@@3MA
ARTS_IMPORT extern f32 ut2float;

struct u_timer
{
    u_timer(ulong* total)
        : start_(utimer())
        , total_(total)
    {}

    ~u_timer()
    {
        *total_ += utimer() - start_;
    }

    ulong start_ {0};
    ulong* const total_ {nullptr};
};

#define ARTS_TIMED(VAR)                   \
    u_timer ARTS_CONCAT(timer_, __LINE__) \
    {                                     \
        &VAR                              \
    }
