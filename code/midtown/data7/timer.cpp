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

// https://randomascii.wordpress.com/2012/06/05/in-praise-of-idleness/
// https://randomascii.wordpress.com/2013/04/02/sleep-variation-investigated/
// https://randomascii.wordpress.com/2020/10/04/windows-timer-resolution-the-great-rule-change/

f32 Timer::TicksToSeconds = 0.0f;
f32 Timer::TicksToMilliseconds = 0.0f;

Timer::Timer()
{
    if (TicksToSeconds == 0.0f)
        Init();

    Reset();
}

f32 Timer::WaitUntil(f32 target)
{
    while (true)
    {
        f32 now = Time();
        f32 wait = target - now;

        if (wait <= 0.0f)
            return now;

        if (wait >= 0.002f) // 2 ms
        {
            // Sleep is generally accurate to at least ~15.6 ms (1000 ms / 64).
            // timeBeginPeriod(1) increases this to ~0.97 ms (1000 ms / 1024).
            // Fugde the last 1.5 ms just in case.
            Sleep(static_cast<i32>((wait - 0.0015f) * 1000.0f));
        }
        else
        {
            // If there is more than 1 ms left, try yielding.
            // If that fails, or there is less time, busy loop.
            if ((wait <= 0.001f) || !SwitchToThread()) // 1 ms
            {
                for (u32 count = static_cast<u32>(wait * 1000000.0f); count; --count)
                    YieldProcessor();
            }
        }
    }
}

static u32 TimerOldPriorityClass = 0;
static u32 TimerOldPriority = 0;

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

ulong Timer::Ticks()
{
    LARGE_INTEGER perf_count;
    QueryPerformanceCounter(&perf_count);
    return perf_count.LowPart;
}

u32 Timer::SetPeriod(u32 period)
{
    static u32 TimerPeriod = 0;

    if (period != TimerPeriod)
    {
        if (TimerPeriod)
            timeEndPeriod(TimerPeriod);

        TimerPeriod = period;

        if (TimerPeriod && timeBeginPeriod(TimerPeriod) != TIMERR_NOERROR)
            TimerPeriod = 0;
    }

    return TimerPeriod;
}

ARTS_NOINLINE void Timer::Init()
{
    LARGE_INTEGER frequency;
    ArAssert(QueryPerformanceFrequency(&frequency) && frequency.QuadPart, "Failed to query performance frequency");

    TicksToSeconds = 1.0f / frequency.QuadPart;
    TicksToMilliseconds = 1000.0f / frequency.QuadPart;
}
