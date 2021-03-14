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

define_dummy_symbol(mminput_iodev);

#include "iodev.h"

#include "input.h"

using namespace ioType;
using namespace mmJoyInput;

i32 mmIODev::GetComponentType(i32 device, i32 component)
{
    switch (device)
    {
        case MM_MOUSE: {
            if (component == kXaxis || component == kYaxis)
                return kContinuous;

            return kDiscrete;
        }

        case MM_JOYSTICK1:
        case MM_JOYSTICK2:
        case MM_JOYSTICK3:
        case MM_JOYSTICK4: {
            if (component >= kJButton1 && component <= kJButton12)
                return kDiscrete;

            return kContinuous;
        }

        default: return kDiscrete;
    }
}
