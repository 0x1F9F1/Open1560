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

define_dummy_symbol(eventq7_event);

#include "event.h"

#include "key_codes.h"
#include "stream/stream.h"

static mem::cmd_param PARAM_event_dbg {"eventdbg"};

eqEventHandler::eqEventHandler()
{
    debug_ = PARAM_event_dbg.get<bool>();
}

eqEventHandler::~eqEventHandler()
{
    for (eqEventMonitor* monitor : monitors_)
    {
        if (monitor)
            RemoveClient(monitor);
    }
}

void eqEventHandler::AddClient(eqEventMonitor* monitor)
{
    if (monitor->handler_)
    {
        Errorf("AddClient: already added somewhere");
        return;
    }

    usize index = 0;

    for (; index < std::size(monitors_); ++index)
    {
        if (monitors_[index] == nullptr)
            break;
    }

    if (index >= std::size(monitors_))
    {
        Errorf("AddClient: already too many clients");
        return;
    }

    monitors_[index] = monitor;
    monitor->handler_index_ = index;
    monitor->handler_ = this;
}

void eqEventHandler::RemoveClient(eqEventMonitor* monitor)
{
    if (monitor->handler_ == nullptr)
    {
        Errorf("RemoveClient: not added?");
        return;
    }

    monitors_[monitor->handler_index_] = nullptr;
    monitor->handler_index_ = -1;
    monitor->handler_ = nullptr;
}

const char* eqEventHandler::EKeyName(i32 key_code)
{
    switch (key_code)
    {
        case EQ_KEY_ESCAPE: return "ESCAPE";

        case EQ_KEY_1: return "1";
        case EQ_KEY_2: return "2";
        case EQ_KEY_3: return "3";
        case EQ_KEY_4: return "4";
        case EQ_KEY_5: return "5";
        case EQ_KEY_6: return "6";
        case EQ_KEY_7: return "7";
        case EQ_KEY_8: return "8";
        case EQ_KEY_9: return "9";
        case EQ_KEY_0: return "0";

        case EQ_KEY_BACK: return "BACK";
        case EQ_KEY_TAB: return "TAB";

        case EQ_KEY_Q: return "Q";
        case EQ_KEY_W: return "W";
        case EQ_KEY_E: return "E";
        case EQ_KEY_R: return "R";
        case EQ_KEY_T: return "T";
        case EQ_KEY_Y: return "Y";
        case EQ_KEY_U: return "U";
        case EQ_KEY_I: return "I";
        case EQ_KEY_O: return "O";
        case EQ_KEY_P: return "P";

        case EQ_KEY_RETURN: return "RETURN";

        case EQ_KEY_A: return "A";
        case EQ_KEY_S: return "S";
        case EQ_KEY_D: return "D";
        case EQ_KEY_F: return "F";
        case EQ_KEY_G: return "G";
        case EQ_KEY_H: return "H";
        case EQ_KEY_J: return "J";
        case EQ_KEY_K: return "K";
        case EQ_KEY_L: return "L";

        case EQ_KEY_Z: return "Z";
        case EQ_KEY_X: return "X";
        case EQ_KEY_C: return "C";
        case EQ_KEY_V: return "V";
        case EQ_KEY_B: return "B";
        case EQ_KEY_N: return "N";
        case EQ_KEY_M: return "M";

        case EQ_KEY_SPACE: return "SPACE";

        case EQ_KEY_F1: return "F1";
        case EQ_KEY_F2: return "F2";
        case EQ_KEY_F3: return "F3";
        case EQ_KEY_F4: return "F4";
        case EQ_KEY_F5: return "F5";
        case EQ_KEY_F6: return "F6";
        case EQ_KEY_F7: return "F7";
        case EQ_KEY_F8: return "F8";
        case EQ_KEY_F9: return "F9";
        case EQ_KEY_F10: return "F10";
        case EQ_KEY_F11: return "F11";
        case EQ_KEY_F12: return "F12";

        default: return "[Unknown]";
    }
}

eqEventMonitor::eqEventMonitor(i32 arg1)
    : dword10(arg1)
{}

eqEventMonitor::~eqEventMonitor()
{
    if (handler_)
        handler_->RemoveClient(this);
}

void eqEventMonitor::Redraw(void* window, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    if (handler_->debug_)
    {
        Displayf("Redraw(%p %d,%d,%d,%d)", window, arg2, arg3, arg4, arg5);
    }
}

void eqEventMonitor::Refocus(void* window, i32 focused)
{
    if (handler_->debug_)
    {
        Displayf("Refocus(%p %s)", window, focused ? "gaining" : "losing");
    }
}

void eqEventMonitor::Mouse(void* window, i32 new_buttons, i32 changed_buttons, i32 buttons, i32 mouse_x, i32 mouse_y,
    i32 window_x, i32 window_y)
{
    if (handler_->debug_)
    {
        Displayf("Mouse(%p %s %d %s %s %s,%d,%d %d %d)", window, new_buttons ? "PRESSED" : "RELEASED/MOTION",
            changed_buttons, (buttons & EQ_BUTTON_LEFT) ? "LEFT" : "", (buttons & EQ_BUTTON_MIDDLE) ? "MIDDLE" : "",
            (buttons & EQ_BUTTON_RIGHT) ? "RIGHT" : "", mouse_x, mouse_y, window_x, window_y);
    }
}

void eqEventMonitor::Keyboard(void* window, i32 modifiers, i32 virtual_key, i32 ascii_key, i32 /*state*/)
{
    if (handler_->debug_)
    {
        Displayf("Key win=%p key=0x%x(%s) ascii=%d(0x%x) state=%x(%s %s %s %s)", window, virtual_key,
            handler_->GKeyName(virtual_key), ascii_key, ascii_key, modifiers,
            (modifiers & EQ_KMOD_DOWN) ? "DOWN" : "UP", (modifiers & EQ_KMOD_SHIFT) ? "SHIFT" : "",
            (modifiers & EQ_KMOD_ALT) ? "ALT" : "", (modifiers & EQ_KMOD_CTRL) ? "CTRL" : "");
    }
}

void eqEventMonitor::Destroy(void* window)
{
    if (handler_->debug_)
    {
        Displayf("Win ID %p", window);
    }
}

void eqEventMonitor::Activate(void* window, b32 active)
{
    if (handler_->debug_)
    {
        Displayf("%s: Win ID %p", active ? "Activate" : "Deactivate", window);
    }
}

void eqEventMonitor::SetWantMotion(i32 enabled)
{
    if (handler_)
    {
        u32 flag = 1 << handler_index_;

        if (enabled)
            handler_->wants_motion_ |= flag;
        else
            handler_->wants_motion_ &= ~flag;
    }
}

eqEventReplayChannelClass::eqEventReplayChannelClass()
    : eqReplayChannel('EQ01')
{}

void eqEventReplayChannelClass::DoPlayback(Stream* file)
{
    // UNTESTED

    [[maybe_unused]] u32 size = file->Get<u32>();

    u32 flags = file->Get<u32>();

    if (flags & 0x1)
    {
        EventCount = file->Get<u32>();

        if (static_cast<u32>(EventCount) > std::size(Events))
            Quitf("Corrupt replay");

        file->Get(Events, EventCount);
    }

    if (flags & 0x2)
    {
        u8 states[0x20];

        file->Get(states, std::size(states));

        for (i32 i = 0; i < 256; ++i)
            KeyStates[i] = (states[i >> 3] & (0x80 >> (i & 7))) != 0;
    }

    if (flags & 0x4)
    {
        MouseX = file->Get<u32>();
        MouseY = file->Get<u32>();
        MouseDeltaX = file->Get<u32>();
        MouseDeltaY = file->Get<u32>();
        Flags = file->Get<u32>();
    }
}

void eqEventReplayChannelClass::DoRecord(Stream* file)
{
    // UNTESTED

    u32 flags = 0;

    if (EventCount != 0)
        flags |= 0x1;

    if (std::memcmp(KeyStates, PrevKeyStates, sizeof(KeyStates)) != 0)
        flags |= 0x2;

    if ((MouseX != PrevMouseX) || (MouseY != PrevMouseY) || (MouseDeltaX != PrevMouseDeltaX) ||
        (MouseDeltaY != PrevMouseDeltaY) || (Flags != PrevFlags))
        flags |= 0x4;

    if (flags == 0)
        return;

    file->Put(GetMagic());

    // NOTE: Original code adds an extra 4
    u32 size = 0;

    if (flags & 0x1)
        size += sizeof(u32) + sizeof(u32) * EventCount;

    if (flags & 0x2)
        size += sizeof(u8[0x20]);

    if (flags & 0x4)
        size += sizeof(u32) * 5;

    file->Put(size);

    if (flags & 0x1)
    {
        file->Put(static_cast<u32>(EventCount));
        file->Put(Events, EventCount);
        EventCount = 0;
    }

    if (flags & 0x2)
    {
        u8 states[0x20] {};

        for (i32 i = 0; i < 256; ++i)
        {
            if (KeyStates[i])
            {
                states[i >> 3] |= 0x80 >> (i & 7);
            }
        }

        file->Put(states, std::size(states));

        std::memcpy(PrevKeyStates, KeyStates, sizeof(PrevKeyStates));
    }

    if (flags & 0x4)
    {
        file->Put(MouseX);
        file->Put(MouseY);
        file->Put(MouseDeltaX);
        file->Put(MouseDeltaY);
        file->Put(Flags);

        PrevMouseX = MouseX;
        PrevMouseY = MouseY;
        PrevMouseDeltaX = MouseDeltaX;
        PrevMouseDeltaY = MouseDeltaY;
        PrevFlags = Flags;
    }
}

void eqEventReplayChannelClass::QueueKeyboard(i32 arg1, i32 arg2, i32 arg3, i32 /*arg4*/)
{
    // UNTESTED

    u32 count = EventCount;

    if (count + 4 > std::size(Events))
    {
        Errorf("eqEventReplay: Too many events in frame");
    }
    else
    {
        Events[count] = 'KEYB';
        Events[count + 1] = arg1;
        Events[count + 2] = arg2;
        Events[count + 3] = arg3;
        // Events[count + 4] = arg4;

        EventCount += 4;
    }
}

void eqEventReplayChannelClass::QueueMouse(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7)
{
    // UNTESTED

    u32 count = EventCount;

    if (count + 8 > std::size(Events))
    {
        Errorf("eqEventReplay: Too many events in frame");
    }
    else
    {
        Events[count] = 'MOUS';
        Events[count + 1] = arg1;
        Events[count + 2] = arg2;
        Events[count + 3] = arg3;
        Events[count + 4] = arg4;
        Events[count + 5] = arg5;
        Events[count + 6] = arg6;
        Events[count + 7] = arg7;

        EventCount += 8;
    }
}
