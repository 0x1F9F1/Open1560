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

#include "eventq7/geinputLib.h"
#include "eventq7/keys.h"
#include "mmcityinfo/state.h"

#include "io.h"

enum
{
    kcaCantAssign = 0,
    kcaCanAssign = 1,
    kcaAlreadyAssigned = 2,
};

void mmInput::AutoSetup()
{
    MMSTATE.EnableFF = false;

    if (DeviceConnected())
    {
        MMSTATE.InputType = mmInputType::Joystick;

        if (JoystickConnected())
            MMSTATE.InputType = mmInputType::Joystick;
        else if (GamepadConnected())
            MMSTATE.InputType = mmInputType::Gamepad;
        else if (WheelConnected())
            MMSTATE.InputType = mmInputType::Wheel2Axis;

        Init(static_cast<i32>(MMSTATE.InputType));

        if (HasForceFeedback)
            MMSTATE.EnableFF = true;

        GameInput()->HasCoolie = JoystickHasCoolie();
    }
    else
    {
        // Used to be mouse. Bleh.
        MMSTATE.InputType = mmInputType::Keyboard;

        Init(static_cast<i32>(MMSTATE.InputType));
    }
}

void mmInput::FlagIODevChanged()
{
    for (i32 i = 0; i < IOID_COUNT; ++i)
        IO[i].Changed = true;
}

void mmInput::Flush()
{
    ProcessJoyEvents();

    CurrentState = 0;
    QueuedEvents = 0;

    eqEvent event;

    while (Events->Pop(&event))
        ;

    GetBufferedKeyboardData();
    NumKeyboardInputs = 0;

    ClearEventHitFlags();
}

b32 mmInput::GamepadConnected()
{
    // TODO: Decide type of connected joystick (mmJoystick::DevInfo::dwDevType)
    return false;
}

f32 mmInput::GetBrakes()
{
    return SwapThrottle ? GetThrottleVal() : GetBrakesVal();
}

f32 mmInput::GetBrakesVal()
{
    switch (IO[IOID_BRAKE].GetIODev().IoType)
    {
        case ioType::Discrete: return IsInputPressed(IOID_BRAKE) ? 1.0f : 0.0f;
        case ioType::Continuous: return BrakesVal;
    }

    return 0.0f;
}

b32 mmInput::JoystickConnected()
{
    // TODO: Decide type of connected joystick (mmJoystick::DevInfo::dwDevType)
    return false;
}

b32 mmInput::WheelConnected()
{
    // TODO: Decide type of connected joystick (mmJoystick::DevInfo::dwDevType)
    return false;
}

void mmInput::ProcessEvents()
{
    ProcessMouseEvents();
    ProcessKeyboardEvents();
    ProcessJoyEvents();
    ClearEventHitFlags();
}

void mmInput::ProcessKeyboardEvents()
{
    eqEvent event;

    while (Events->Pop(&event))
    {
        bool scan = false;

        if (event.Type == eqEventType::Keyboard)
        {
            if (event.Key.Char == 0) // Ignore WM_CHAR/SDL_TEXTINPUT
            {
                event.Key.Key = VirtualKeyToScanCode(event.Key.Key);

                if (event.Key.Key == 0)
                    event.Key.Key = ((event.Key.State >> 16) & 0xFF) | ((event.Key.State >> 17) & 0x80);

                scan = (event.Key.Key != 0) && (event.Key.Modifiers & EQ_KMOD_DOWN) &&
                    !(event.Key.Modifiers & EQ_KMOD_REPEAT);
            }
        }
        else if (event.Type == eqEventType::Mouse)
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

i64 mmInput::ScanForEvent(eqEvent* event)
{
    for (i32 i = 0; i < NumControls; ++i)
    {
        mmIO& io = IO[i];

        if (io.GetIODev().IoType == ioType::Event && !io.Pressed && (io == event))
        {
            io.Pressed = true;

            return i + 1;
        }
    }

    return 0;
}

void mmInput::GetBufferedKeyboardData()
{
    NumKeyboardInputs = geinputGetBufferedKeyboard(KeyboardPresses);
}

b32 mmInput::GetNextKeyboardEvent(eqEvent* event)
{
    if (NumKeyboardInputs == 0)
        return false;

    event->Key = {{nullptr, eqEventType::Keyboard}, EQ_KMOD_DOWN, KeyboardPresses[--NumKeyboardInputs], 0, 0};

    return true;
}

hook_func(INIT_main,
    [] { create_patch("mmInput::BuildCaptureIO", "Fix controller button mask", 0x4E1F56, "\x83\xE6\x7F", 3); });
