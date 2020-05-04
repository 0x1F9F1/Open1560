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

#include "timer.h"

Timer::Timer()
{
    unimplemented();
}

void Timer::Reset()
{
    return stub<thiscall_t<void, Timer*>>(0x1768E0_Offset, this);
}

f32 Timer::Time()
{
    return stub<thiscall_t<f32, Timer*>>(0x1768F0_Offset, this);
}

void Timer::BeginBenchmark()
{
    return stub<cdecl_t<void>>(0x176920_Offset);
}

void Timer::EndBenchmark()
{
    return stub<cdecl_t<void>>(0x176990_Offset);
}

void Timer::Sleep(i32 arg1)
{
    return stub<cdecl_t<void, i32>>(0x176860_Offset, arg1);
}

u32 Timer::Ticks()
{
    return stub<cdecl_t<u32>>(0x176830_Offset);
}

define_dummy_symbol(data7_timer);
