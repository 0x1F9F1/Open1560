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

ulong adjust_utimer(f32 elapsed, ulong prev);

// ?utimer@@YAKXZ
ARTS_EXPORT ulong utimer();

// ?ut2float@@3MA
ARTS_EXPORT extern f32 ut2float;

#ifdef ARTS_DEV_BUILD
struct scoped_utimer
{
    scoped_utimer(ulong* total)
        : start_(utimer())
        , total_(total)
    {}

    ~scoped_utimer()
    {
        *total_ += utimer() - start_;
    }

    ulong start_ {0};
    ulong* const total_ {nullptr};
};

#    define ARTS_UTIMED(VAR)                        \
        scoped_utimer ARTS_CONCAT(timer_, __LINE__) \
        {                                           \
            &VAR                                    \
        }
#else
#    define ARTS_UTIMED(VAR)
#endif
