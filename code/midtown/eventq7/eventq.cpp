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

define_dummy_symbol(eventq7_eventq);

#include "eventq.h"

eqEventQ::eqEventQ(i32 arg1, i32 enabled_events, i32 max_events)
    : eqEventMonitor(arg1)
{
    events_ = new eqEvent[max_events];
    enabled_events_ = enabled_events;
    max_events_ = max_events;

    if (eqEventHandler::SuperQ)
    {
        eqEventHandler::SuperQ->AddClient(this);

        registered_ = true;
    }
    else
    {
        registered_ = false;
    }
}

eqEventQ::~eqEventQ()
{
    delete[] events_;

    if (registered_)
        eqEventHandler::SuperQ->RemoveClient(this);
}

#define EQ_QUEUE_IF_ENABLED(EVENT)                          \
    if (enabled_events_ & EQ_EVENT_MASK(EVENT.Common.Type)) \
    {                                                       \
        Queue(EVENT);                                       \
    }

void eqEventQ::Activate(void* window, b32 active)
{
    eqEvent event;
    event.Activate = {{window, eqEventType::Activate}, active};
    EQ_QUEUE_IF_ENABLED(event);

    eqEventMonitor::Activate(window, active);
}

void eqEventQ::Destroy(void* window)
{
    eqEvent event;
    event.Destroy = {{window, eqEventType::Destroy}};
    EQ_QUEUE_IF_ENABLED(event);

    eqEventMonitor::Destroy(window);
}

void eqEventQ::Keyboard(void* window, i32 modifiers, i32 virtual_key, i32 ascii_key, i32 state)
{
    eqEvent event;
    event.Key = {{window, eqEventType::Keyboard}, modifiers, virtual_key, ascii_key, state};
    EQ_QUEUE_IF_ENABLED(event);

    eqEventMonitor::Keyboard(window, modifiers, virtual_key, ascii_key, state);
}

void eqEventQ::Mouse(void* window, i32 new_buttons, i32 changed_buttons, i32 buttons, i32 mouse_x, i32 mouse_y,
    i32 window_x, i32 window_y)
{
    eqEvent event;
    event.Mouse = {
        {window, eqEventType::Mouse}, new_buttons, changed_buttons, buttons, mouse_x, mouse_y, window_x, window_y};
    EQ_QUEUE_IF_ENABLED(event);

    eqEventMonitor::Mouse(window, new_buttons, changed_buttons, buttons, mouse_x, mouse_y, window_x, window_y);
}

b32 eqEventQ::Pop(eqEvent* event)
{
    if (eqEventHandler::SuperQ == nullptr)
        return false;

    if (!registered_)
    {
        eqEventHandler::SuperQ->AddClient(this);

        registered_ = true;
    }

    u32 head = read_head_;

    if (write_head_ == head)
        return false;

    head = (head + 1) & (max_events_ - 1);

    read_head_ = head;

    if (event)
        *event = events_[head];

    return true;
}

void eqEventQ::Redraw(void* window, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    eqEvent event;
    event.Redraw = {{window, eqEventType::Redraw}, arg2, arg3, arg4, arg5};
    EQ_QUEUE_IF_ENABLED(event);

    eqEventMonitor::Redraw(window, arg2, arg3, arg4, arg5);
}

void eqEventQ::Refocus(void* window, i32 focused)
{
    eqEvent event;
    event.Refocus = {{window, eqEventType::Refocus}, focused};
    EQ_QUEUE_IF_ENABLED(event);

    eqEventMonitor::Refocus(window, focused);
}

void eqEventQ::Clear()
{
    read_head_ = write_head_;
}

void eqEventQ::Queue(eqEvent& event)
{
    u32 head = (write_head_ + 1) & (max_events_ - 1);

    if (head != read_head_)
    {
        write_head_ = head;
        events_[head] = event;
    }
}
