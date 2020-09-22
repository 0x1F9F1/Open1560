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

void TicketLock::lock()
{
    usize my_ticket = next_ticket_.fetch_add(1, std::memory_order_acq_rel);

    while (true)
    {
        usize serving = now_serving_.load(std::memory_order_acquire);
        usize delay_slots = my_ticket - serving;

        if (delay_slots == 0)
            break;

        if (delay_slots > 2)
        {
            ArDebugAssert(serving < my_ticket, "Ticket lock corrupt");

            std::this_thread::yield();
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
}
