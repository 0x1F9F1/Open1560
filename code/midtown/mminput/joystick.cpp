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

        case mmJoyInput::XaxisLeft: return (std::max) (-XAxis.Value, 0.0f);
        case mmJoyInput::XaxisRight: return (std::max) (+XAxis.Value, 0.0f);

        case mmJoyInput::YaxisUp: return (std::max) (-YAxis.Value, 0.0f);
        case mmJoyInput::YaxisDown: return (std::max) (+YAxis.Value, 0.0f);

        case mmJoyInput::ZaxisUp: return (std::max) (-ZAxis.Value, 0.0f);
        case mmJoyInput::ZaxisDown: return (std::max) (+ZAxis.Value, 0.0f);

        case mmJoyInput::RaxisUp: return (std::max) (-RAxis.Value, 0.0f);
        case mmJoyInput::RaxisDown: return (std::max) (+RAxis.Value, 0.0f);

        default: return 0.0f;
    }
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
        else if ((state = UAxis.Capture()) != 0) // FIXME: Needs to be updated in mmJoystick::Poll
        {
            State = mmJoyInput::Uaxis; // TODO: Separate Up/Down
        }
        else if ((state = RAxis.Capture()) != 0)
        {
            State = (state == 1) ? mmJoyInput::RaxisDown : mmJoyInput::RaxisUp;
        }
        else if ((state = VAxis.Capture()) != 0) // FIXME: Needs to be updated in mmJoystick::Poll
        {
            State = mmJoyInput::Vaxis; // TODO: Separate Up/Down
        }
    }
}
