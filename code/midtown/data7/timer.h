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
    data7:timer

    0x576830 | public: static unsigned long __cdecl Timer::Ticks(void) | ?Ticks@Timer@@SAKXZ
    0x576860 | public: static void __cdecl Timer::Sleep(int) | ?Sleep@Timer@@SAXH@Z
    0x576870 | public: __thiscall Timer::Timer(void) | ??0Timer@@QAE@XZ
    0x5768E0 | public: void __thiscall Timer::Reset(void) | ?Reset@Timer@@QAEXXZ
    0x5768F0 | public: float __thiscall Timer::Time(void) | ?Time@Timer@@QAEMXZ
    0x576920 | public: static void __cdecl Timer::BeginBenchmark(void) | ?BeginBenchmark@Timer@@SAXXZ
    0x576990 | public: static void __cdecl Timer::EndBenchmark(void) | ?EndBenchmark@Timer@@SAXXZ
    0x90A66C | public: static float Timer::TicksToSeconds | ?TicksToSeconds@Timer@@2MA
*/

class Timer
{
public:
    // 0x576870 | ??0Timer@@QAE@XZ
    ARTS_EXPORT Timer();

    // 0x5768E0 | ?Reset@Timer@@QAEXXZ
    ARTS_EXPORT void Reset()
    {
        start_ticks_ = Ticks();
    }

    // 0x5768F0 | ?Time@Timer@@QAEMXZ
    ARTS_EXPORT f32 Time()
    {
        return (Ticks() - start_ticks_) * TicksToSeconds;
    }

    f32 TimeMS()
    {
        return (Ticks() - start_ticks_) * TicksToMilliseconds;
    }

    // 0x576920 | ?BeginBenchmark@Timer@@SAXXZ | unused
    ARTS_EXPORT static void BeginBenchmark();

    // 0x576990 | ?EndBenchmark@Timer@@SAXXZ | unused
    ARTS_EXPORT static void EndBenchmark();

    // 0x576860 | ?Sleep@Timer@@SAXH@Z
    ARTS_EXPORT static void Sleep(i32 ms);

    // 0x576830 | ?Ticks@Timer@@SAKXZ
    ARTS_EXPORT static ulong Ticks();

    // 0x90A66C | ?TicksToSeconds@Timer@@2MA
    static f32 TicksToSeconds;

    static f32 TicksToMilliseconds;

private:
    ulong start_ticks_ {0};
};

check_size(Timer, 0x4);
