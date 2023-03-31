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

define_dummy_symbol(mminput_io);

#include "io.h"

b32 mmIO::operator==(eqEvent* event)
{
    return GetIODev() == event;
}

void mmIO::Assign(i32 device, i32 component)
{
    GetIODev().Assign(device, component, Flags);

    Changed = true;
}

void mmIO::Clear()
{
    Name = nullptr;
    Changed = false;
    Flags = 0;
    IoIndex = 0;
}

b32 mmIO::CompareComponent(i32 component)
{
    mmIODev& iod = GetIODev();

    if (iod.Component == component)
        return true;

    switch (iod.Device)
    {
        case mmIODevice::Joystick1:
        case mmIODevice::Joystick2:
        case mmIODevice::Joystick3:
        case mmIODevice::Joystick4:
            switch (iod.Component)
            {
                case mmJoyInput::Xaxis:
                    return (component == mmJoyInput::XaxisLeft) || (component == mmJoyInput::XaxisRight);
                case mmJoyInput::Yaxis:
                    return (component == mmJoyInput::YaxisUp) || (component == mmJoyInput::YaxisDown);
                case mmJoyInput::Zaxis:
                    return (component == mmJoyInput::ZaxisUp) || (component == mmJoyInput::ZaxisDown);
                case mmJoyInput::Raxis:
                    return (component == mmJoyInput::RaxisUp) || (component == mmJoyInput::RaxisDown);
            }
            break;
    }

    return false;
}

void mmIO::GetDescription(char* buffer)
{
    return GetDescription(buffer, 40);
}

void mmIO::GetDescription(char* buffer, usize buflen)
{
    return GetIODev().GetDescription(buffer, buflen);
}

void mmIO::Init(char* name, i32 ioid, ilong flags)
{
    Name = name;
    IoIndex = ioid;
    Flags = static_cast<u32>(flags);
}

void mmIO::InitDev(i32 type, i64, i32 device, i32 component, i32)
{
    mmIODev& iod = GetIODev();
    iod.Init(type, 1_i64 << IoIndex);
    iod.Assign(device, component, Flags);

    Changed = true;
}
