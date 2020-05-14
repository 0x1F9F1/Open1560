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

define_dummy_symbol(data7_timer);

#include "timer.h"

#include "core/minwin.h"

#include <timeapi.h>

static extern_var(0x90A674, i32, TimerMode);

Timer::Timer()
{
    if (TicksToSeconds == 0.0f)
    {
        LARGE_INTEGER frequency;

        TimerMode = QueryPerformanceFrequency(&frequency) ? 2 : 1;

        if (TimerMode == 1)
            TicksToSeconds = 0.001f;
        else
            TicksToSeconds = 1.0f / frequency.QuadPart;
    }

    Reset();
}

static extern_var(0x90A670, u32, TimerOldPriorityClass);
static extern_var(0x90A678, u32, TimerOldPriority);

void Timer::BeginBenchmark()
{
    TimerOldPriorityClass = GetPriorityClass(GetCurrentProcess());
    TimerOldPriority = GetThreadPriority(GetCurrentThread());

    if (!SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS))
        Errorf("SetPriorityClass failed.");

    if (!SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL))
        Errorf("SetThreadPriority failed.");
}

void Timer::EndBenchmark()
{
    SetPriorityClass(GetCurrentProcess(), TimerOldPriorityClass);
    SetThreadPriority(GetCurrentThread(), TimerOldPriority);
}

void Timer::Sleep(i32 ms)
{
    ::Sleep(ms);
}

u32 Timer::Ticks()
{
    if (TimerMode == 1)
    {
        return timeGetTime();
    }
    else
    {
        LARGE_INTEGER perf_count;
        QueryPerformanceCounter(&perf_count);
        return perf_count.LowPart;
    }
}
