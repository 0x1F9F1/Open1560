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

#include "ticketlock.h"

#include "core/minwin.h"

void RecursiveTicketLock::lock()
{
    if (u32 my_thread_id = GetCurrentThreadId(); my_thread_id != thread_id.load(std::memory_order_acquire))
    {
        u32 my_ticket = next_ticket.fetch_add(1, std::memory_order_acq_rel);

        while (true)
        {
            u32 serving = now_serving.load(std::memory_order_acquire);
            u32 delay_slots = my_ticket - serving;

            if (delay_slots == 0)
                break;

            if (delay_slots > 2)
            {
                ArDebugAssert(serving < my_ticket, "Ticket lock corrupt");

                Sleep(0);
            }
            else
            {
                delay_slots <<= 4;

                do
                {
                    _mm_pause();
                } while (--delay_slots);
            }
        }

        thread_id.store(my_thread_id, std::memory_order_relaxed);
    }

    ++lock_count;
}

void RecursiveTicketLock::unlock()
{
    if (--lock_count == 0)
    {
        thread_id.store(0, std::memory_order_relaxed);
        now_serving.fetch_add(1, std::memory_order_release);
    }
}
