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

define_dummy_symbol(mminput_joystick);

#include "joystick.h"

#include "input.h"

f32 mmJoystick::GetAxis(i32 axis)
{
    switch (axis)
    {
        case mmJoyInput::Xaxis: return XAxis.Value;
        case mmJoyInput::Yaxis: return YAxis.Value;
        case mmJoyInput::Zaxis: return -ZAxis.Value;
        case mmJoyInput::Uaxis: return UAxis.Value;
        case mmJoyInput::Raxis: return RAxis.Value;
        case mmJoyInput::Vaxis: return VAxis.Value;
        case mmJoyInput::POVaxis: return PovAxis.Value;

        case mmJoyInput::XaxisLeft: return (std::max)(-XAxis.Value, 0.0f);
        case mmJoyInput::XaxisRight: return (std::max)(+XAxis.Value, 0.0f);

        case mmJoyInput::YaxisUp: return (std::max)(-YAxis.Value, 0.0f);
        case mmJoyInput::YaxisDown: return (std::max)(+YAxis.Value, 0.0f);

        case mmJoyInput::ZaxisUp: return (std::max)(-ZAxis.Value, 0.0f);
        case mmJoyInput::ZaxisDown: return (std::max)(+ZAxis.Value, 0.0f);

        case mmJoyInput::RaxisUp: return (std::max)(-RAxis.Value, 0.0f);
        case mmJoyInput::RaxisDown: return (std::max)(+RAxis.Value, 0.0f);

        default: return 0.0f;
    }
}

ulong mmJoystick::Poll()
{
    HRESULT error = Device->Poll();

    if (FAILED(error))
    {
        DecodeDIErrorMFlag(error);

        if (error == DIERR_INPUTLOST || error == DIERR_NOTACQUIRED)
        {
            error = Device->Acquire();

            DecodeDIErrorMFlag(error);

            if (HasFF == 1)
                InputStopEffect();
        }

        return 0;
    }

    error = Device->GetDeviceState(sizeof(JoyState), &JoyState);

    if (FAILED(error))
    {
        if (error == DIERR_INPUTLOST)
            Device->Acquire();

        return 0;
    }

    ButtonFlags = 0;

    i32 num_buttons = (std::min<i32>) (DevCaps.dwButtons, 32);

    for (i32 i = 0; i < num_buttons; ++i)
        ButtonFlags |= u32(JoyState.rgbButtons[i] >> 7) << i;

    XAxis.Normalize(static_cast<f32>(JoyState.lX));
    YAxis.Normalize(static_cast<f32>(JoyState.lY));
    ZAxis.Normalize(static_cast<f32>(JoyState.lZ));
    RAxis.Normalize(static_cast<f32>(JoyState.lRz));

    // Untested
    // UAxis.Normalize(static_cast<f32>(JoyState.rglSlider[0]));
    // VAxis.Normalize(static_cast<f32>(JoyState.rglSlider[1]));

    PovAxis.NormalizePOV(JoyState.rgdwPOV[0]);

    return 0;
}

void mmJoystick::Update()
{
    Poll();

    if (Capture)
    {
        State = 0;
        i32 state = 0;

        if ((state = XAxis.Capture()) != 0)
        {
            State = (state == 1) ? mmJoyInput::XaxisRight : mmJoyInput::XaxisLeft;
        }
        else if ((state = YAxis.Capture()) != 0)
        {
            State = (state == 1) ? mmJoyInput::YaxisDown : mmJoyInput::YaxisUp;
        }
        else if ((state = ZAxis.Capture()) != 0)
        {
            State = (state == 1) ? mmJoyInput::ZaxisDown : mmJoyInput::ZaxisUp;
        }
        else if ((state = UAxis.Capture()) != 0)
        {
            State = mmJoyInput::Uaxis; // TODO: Separate Up/Down
        }
        else if ((state = RAxis.Capture()) != 0)
        {
            State = (state == 1) ? mmJoyInput::RaxisDown : mmJoyInput::RaxisUp;
        }
        else if ((state = VAxis.Capture()) != 0)
        {
            State = mmJoyInput::Vaxis; // TODO: Separate Up/Down
        }
    }
}
