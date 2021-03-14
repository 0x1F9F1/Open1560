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

using namespace mmJoyInput;

f32 mmJoystick::GetAxis(i32 axis)
{
    switch (axis)
    {
        case kXaxis: return XAxis.Value;
        case kYaxis: return YAxis.Value;
        case kZaxis: return ZAxis.Value;
        case kUaxis: return UAxis.Value;
        case kRaxis: return RAxis.Value;
        case kVaxis: return VAxis.Value;
        case kPOVaxis: return PovAxis.Value;

        case kXaxisLeft: return (std::max)(-XAxis.Value, 0.0f);
        case kXaxisRight: return (std::max)(+XAxis.Value, 0.0f);

        case kYaxisUp: return (std::max)(-YAxis.Value, 0.0f);
        case kYaxisDown: return (std::max)(+YAxis.Value, 0.0f);

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
            State = (state == 1) ? kXaxisRight : kXaxisLeft;
        }
        else if ((state = YAxis.Capture()) != 0)
        {
            State = (state == 1) ? kYaxisDown : kYaxisUp;
        }
        else if ((state = ZAxis.Capture()) != 0)
        {
            State = kZaxis; // TODO: Allow separate ZAxis Up/Down
        }
        else if ((state = RAxis.Capture()) != 0)
        {
            State = kRaxis;
        }
    }
}
