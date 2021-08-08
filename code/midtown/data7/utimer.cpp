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

define_dummy_symbol(data7_utimer);

#include "utimer.h"
#include "timer.h"

#include "core/minwin.h"

static i32 utimer_mode = 1;
f32 ut2float = 0.0f;

#define ARTS_RDTSC() static_cast<utimer_t>(__rdtsc())

utimer_t adjust_utimer(f32 elapsed, utimer_t prev)
{
    if (utimer_mode == 2)
        return 0;

    ulong now = ARTS_RDTSC();

    if (prev)
        ut2float = (elapsed * 1000.0f) / (now - prev);

    return now;
}

static ARTS_NOINLINE utimer_t init_utimer()
{
    if (utimer_mode == 2)
        return 0;

    __try
    {
        Timer t;
        utimer_t start = ARTS_RDTSC();

        Timer::Sleep(100);
        adjust_utimer(t.Time(), start);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        utimer_mode = 2;
        return 0;
    }

    utimer_mode = 0;
    return ARTS_RDTSC();
}

ARTS_NOINLINE utimer_t utimer()
{
    if (utimer_mode)
        return init_utimer();

    return ARTS_RDTSC();
}
