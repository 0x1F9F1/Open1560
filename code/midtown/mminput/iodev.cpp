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

#include "eventq7/key_codes.h"
#include "input.h"
#include "localize.h"

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

void mmIODev::GetDescription(char* buffer)
{
    return GetDescription(buffer, 40);
}

void mmIODev::GetDescription(char* buffer, usize buflen)
{
    switch (Device)
    {
        case MM_MOUSE: {
            const char* desc = LocStrUndef;

            switch (Component)
            {
                case EQ_BUTTON_LEFT: desc = LOC_STR(MM_IDS_LEFT_MOUSE_BUTTON); break;
                case EQ_BUTTON_RIGHT: desc = LOC_STR(MM_IDS_RIGHT_MOUSE_BUTTON); break;
                case kXaxis: desc = LOC_STR(MM_IDS_MOUSE_X_AXIS); break;
                case kYaxis: desc = LOC_STR(MM_IDS_MOUSE_Y_AXIS); break;
            }

            arts_strcpy(buffer, buflen, desc);
            break;
        }

        case MM_KEYBOARD: {
            if (UseDIKey)
            {
                arts_strcpy(buffer, buflen, AngelReadKeyString(Component)->Text);
            }
            else
            {
                ConvertDItoString(Component, buffer, static_cast<i32>(buflen));
            }
            break;
        }

        case MM_JOYSTICK1:
        case MM_JOYSTICK2:
        case MM_JOYSTICK3:
        case MM_JOYSTICK4: {
            if (Component >= kJButton1 && Component <= kJButton12)
            {
                arts_sprintf(buffer, buflen, "%s %s %d", LocStrJoystick, LocStrButton, (Component - kJButton1) + 1);
            }
            else
            {
                const char* desc = LocStrUndef;

                switch (Component)
                {
                    case kXaxis: desc = LOC_STR(MM_IDS_X_AXIS); break;
                    case kYaxis: desc = LOC_STR(MM_IDS_Y_AXIS); break;
                    case kZaxis: desc = LOC_STR(MM_IDS_Z_AXIS); break;
                    case kUaxis: desc = LOC_STR(MM_IDS_U_AXIS); break;
                    case kRaxis: desc = LOC_STR(MM_IDS_R_AXIS); break;
                    case kVaxis: desc = LOC_STR(MM_IDS_V_AXIS); break;
                    case kPOVaxis: desc = LOC_STR(MM_IDS_POV_AXIS); break;
                    case kXaxisLeft: desc = LOC_STR(MM_IDS_X_AXIS_LEFT); break;
                    case kXaxisRight: desc = LOC_STR(MM_IDS_X_AXIS_RIGHT); break;
                    case kYaxisUp: desc = LOC_STR(MM_IDS_Y_AXIS_UP); break;
                    case kYaxisDown: desc = LOC_STR(MM_IDS_Y_AXIS_DOWN); break;

                    case kZaxisUp: desc = "Z Axis Up"; break;     // TODO: Localize
                    case kZaxisDown: desc = "Z Axis Down"; break; // TODO: Localize

                    case kRaxisUp: desc = "R Axis Up"; break;     // TODO: Localize
                    case kRaxisDown: desc = "R Axis Down"; break; // TODO: Localize
                }

                arts_sprintf(buffer, buflen, "%s %s", LocStrJoystick, desc);
            }

            break;
        }

        default: {
            arts_strcpy(buffer, buflen, LocStrUndef);

            break;
        }
    }
}
