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

define_dummy_symbol(eventq7_geinputLib);

#include "geinputLib.h"

#include "pcwindis/dxinit.h"

#include <dinput.h>

static extern_var(0x909424, IDirectInputDeviceA*, MouseDevice);
static extern_var(0x909428, IDirectInputDeviceA*, KeyboardDevice);

void geinputAcquireMouse()
{
    if (MouseDevice)
        MouseDevice->Acquire();
}

void geinputUnacquireMouse()
{
    if (MouseDevice)
        MouseDevice->Unacquire();
}

void geinputClearCache()
{}

// TODO: Pass in max number of presses
i32 geinputGetBufferedKeyboard(i8* presses)
{
    DIDEVICEOBJECTDATA data[32];
    DWORD dwItems = std::size(data);

    HRESULT hres = KeyboardDevice->GetDeviceData(sizeof(*data), data, &dwItems, 0);

    if (FAILED(hres))
        return 0;

    if (presses == nullptr)
        return 0;

    if (hres == DI_BUFFEROVERFLOW)
        Errorf("Keyboard buffer had overflowed.");

    i32 count = 0;
    i32 num_items = std::min<i32>(dwItems, std::size(data));

    for (i32 i = 0; i < num_items; ++i)
    {
        if (data[i].dwData & 0x80)
        {
            presses[count++] = static_cast<i8>(data[i].dwOfs);
        }
    }

    return count;
}

static i8 KeyboardState[256] {};

i8* geinputGetKeyboard()
{
    if (KeyboardDevice && FAILED(KeyboardDevice->GetDeviceState(std::size(KeyboardState), KeyboardState)))
    {
        if (KeyboardDevice)
            KeyboardDevice->Acquire();

        if (FAILED(KeyboardDevice->GetDeviceState(std::size(KeyboardState), KeyboardState)))
        {
            std::memset(KeyboardState, 0, sizeof(KeyboardState));
        }
    }

    return KeyboardState;
}

void geinputAcquireKeyboard()
{
    if (KeyboardDevice)
        KeyboardDevice->Acquire();
}

void geinputUnacquireKeyboard()
{
    if (KeyboardDevice)
        KeyboardDevice->Unacquire();
}

// 0x564050 | ?DIError@@YAPADH@Z
ARTS_EXPORT /*static*/ const char* DIError(i32 error)
{
    static char buffer[64]; // FIXME: Static buffer
    arts_sprintf(buffer, "Error 0x%08X", error);
    return buffer;
}
