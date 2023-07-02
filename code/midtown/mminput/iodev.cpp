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

#include "data7/metadefine.h"
#include "eventq7/keys.h"
#include "input.h"
#include "localize.h"

#include "core/minwin.h"

b32 mmIODev::operator==(eqEvent* event)
{
    if ((IoType == ioType::Event) && (static_cast<eqEventType>(Device) == event->Type))
    {
        switch (event->Type)
        {
            case eqEventType::Mouse: return (Component == event->Mouse.Buttons);
            case eqEventType::Keyboard: return (Component == event->Key.Key);
        }
    }

    return false;
}

i32 mmIODev::GetComponentType(i32 device, i32 component)
{
    switch (device)
    {
        case mmIODevice::Mouse: {
            if (component == mmJoyInput::Xaxis || component == mmJoyInput::Yaxis)
                return ioType::Continuous;

            return ioType::Discrete;
        }

        case mmIODevice::Joystick1:
        case mmIODevice::Joystick2:
        case mmIODevice::Joystick3:
        case mmIODevice::Joystick4: {
            if (component >= mmJoyInput::JButton1 && component <= mmJoyInput::JButton12)
                return ioType::Discrete;

            if (component >= mmJoyInput::JButton13 && component <= mmJoyInput::JButton32)
                return ioType::Discrete;

            return ioType::Continuous;
        }

        default: return ioType::Discrete;
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
        case mmIODevice::Mouse: {
            const char* desc = LocStrUndef;

            switch (Component)
            {
                case mmJoyInput::MButtonLeft: desc = LOC_STR(MM_IDS_LEFT_MOUSE_BUTTON); break;
                case mmJoyInput::MButtonRight: desc = LOC_STR(MM_IDS_RIGHT_MOUSE_BUTTON); break;
                case mmJoyInput::Xaxis: desc = LOC_STR(MM_IDS_MOUSE_X_AXIS); break;
                case mmJoyInput::Yaxis: desc = LOC_STR(MM_IDS_MOUSE_Y_AXIS); break;
            }

            arts_strcpy(buffer, buflen, desc);
            break;
        }

        case mmIODevice::Keyboard: {
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

        case mmIODevice::Joystick1:
        case mmIODevice::Joystick2:
        case mmIODevice::Joystick3:
        case mmIODevice::Joystick4: {
            if (Component >= mmJoyInput::JButton1 && Component <= mmJoyInput::JButton12)
            {
                arts_sprintf(
                    buffer, buflen, "%s %s %d", LocStrJoystick, LocStrButton, (Component - mmJoyInput::JButton1) + 1);
            }
            else if (Component >= mmJoyInput::JButton13 && Component <= mmJoyInput::JButton32)
            {
                arts_sprintf(
                    buffer, buflen, "%s %s %d", LocStrJoystick, LocStrButton, (Component - mmJoyInput::JButton13) + 13);
            }
            else
            {
                const char* desc = LocStrUndef;

                switch (Component)
                {
                    case mmJoyInput::Xaxis: desc = LOC_STR(MM_IDS_X_AXIS); break;
                    case mmJoyInput::Yaxis: desc = LOC_STR(MM_IDS_Y_AXIS); break;
                    case mmJoyInput::Zaxis: desc = LOC_STR(MM_IDS_Z_AXIS); break;
                    case mmJoyInput::Uaxis: desc = LOC_STR(MM_IDS_U_AXIS); break;
                    case mmJoyInput::Raxis: desc = LOC_STR(MM_IDS_R_AXIS); break;
                    case mmJoyInput::Vaxis: desc = LOC_STR(MM_IDS_V_AXIS); break;
                    case mmJoyInput::POVaxis: desc = LOC_STR(MM_IDS_POV_AXIS); break;
                    case mmJoyInput::XaxisLeft: desc = LOC_STR(MM_IDS_X_AXIS_LEFT); break;
                    case mmJoyInput::XaxisRight: desc = LOC_STR(MM_IDS_X_AXIS_RIGHT); break;
                    case mmJoyInput::YaxisUp: desc = LOC_STR(MM_IDS_Y_AXIS_UP); break;
                    case mmJoyInput::YaxisDown: desc = LOC_STR(MM_IDS_Y_AXIS_DOWN); break;

                    case mmJoyInput::ZaxisUp: desc = "Z Axis Up"; break;     // TODO: Localize
                    case mmJoyInput::ZaxisDown: desc = "Z Axis Down"; break; // TODO: Localize

                    case mmJoyInput::RaxisUp: desc = "R Axis Up"; break;     // TODO: Localize
                    case mmJoyInput::RaxisDown: desc = "R Axis Down"; break; // TODO: Localize
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

b32 ConvertDItoString(i32 vsc, char* buffer, i32 buflen)
{
    u32 lparam = ((vsc & 0x7F) << 16) | ((vsc & 0x80) << 17);

    if (GetKeyNameTextA(lparam, buffer, buflen))
        return true;

    arts_sprintf(buffer, buflen, "Key #%x", vsc);
    return false;
}

META_DEFINE_CHILD("mmIODev", mmIODev, mmInfoBase)
{
    META_FIELD("ioType", IoType);
    META_FIELD("Device", Device);
    META_FIELD("Component", Component);
}