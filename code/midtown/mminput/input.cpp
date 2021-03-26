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

define_dummy_symbol(mminput_input);

#include "input.h"

#include "eventq7/eventq.h"
#include "eventq7/keys.h"

i32 mmInput::GamepadConnected()
{
    return 0;
}

i32 mmInput::JoystickConnected()
{
    return 0;
}

i32 mmInput::WheelConnected()
{
    return 0;
}

void mmInput::ProcessKeyboardEvents()
{
    eqEvent event;

    while (Events->Pop(&event))
    {
        bool scan = false;

        if (event.Common.Type == eqEventType::Keyboard)
        {
            event.Key.VirtualKey = VirtualKeyToScanCode(event.Key.VirtualKey);
            scan = (event.Key.Modifiers & EQ_KMOD_DOWN) && !(event.Key.Modifiers & EQ_KMOD_REPEAT);
        }
        else if (event.Common.Type == eqEventType::Mouse)
        {
            scan = event.Mouse.Buttons;
        }

        if (scan)
        {
            if (i64 index = ScanForEvent(&event); index > 0)
                PutEventInQueue(index);
        }
    }
}

void mmInput::ProcessMouseEvents()
{
    // Merged with ProcessKeyboardEvents
}

b32 mmInput::GetNextKeyboardEvent(eqEvent* event)
{
    if (NumKeyboardInputs == 0)
        return false;

    event->Key = {{nullptr, eqEventType::Keyboard}, EQ_KMOD_DOWN, KeyboardPresses[--NumKeyboardInputs], 0, 0};

    return true;
}

run_once([] { create_patch("mmInput::BuildCaptureIO", "Fix controller button mask", 0x4E1F56, "\x83\xE6\x7F", 3); });