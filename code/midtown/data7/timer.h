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

// TODO: Use u64 for ticks
class Timer
{
public:
    // ??0Timer@@QAE@XZ
    ARTS_EXPORT Timer();

    // ?Reset@Timer@@QAEXXZ
    ARTS_EXPORT void Reset()
    {
        start_ticks_ = Ticks();
    }

    // ?Time@Timer@@QAEMXZ
    ARTS_EXPORT f32 Time()
    {
        return (Ticks() - start_ticks_) * TicksToSeconds;
    }

    f32 TimeMS()
    {
        return (Ticks() - start_ticks_) * TicksToMilliseconds;
    }

    f32 WaitUntil(f32 target);

    // ?BeginBenchmark@Timer@@SAXXZ | unused
    static void BeginBenchmark();

    // ?EndBenchmark@Timer@@SAXXZ | unused
    static void EndBenchmark();

    // ?Sleep@Timer@@SAXH@Z
    static void Sleep(i32 ms);

    // ?Ticks@Timer@@SAKXZ
    static ulong Ticks();

    // ?TicksToSeconds@Timer@@2MA
    static f32 TicksToSeconds;

    static f32 TicksToMilliseconds;

private:
    static void Init();

    ulong start_ticks_;
};

check_size(Timer, 0x4);
