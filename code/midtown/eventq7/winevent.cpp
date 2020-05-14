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

define_dummy_symbol(eventq7_winevent);

#include "winevent.h"

WINEventHandler::WINEventHandler()
{
    unimplemented();
}

WINEventHandler::~WINEventHandler()
{
    unimplemented();
}

void WINEventHandler::AdjustMouse(i32& arg1, i32& arg2)
{
    return stub<thiscall_t<void, WINEventHandler*, i32&, i32&>>(0x562660, this, arg1, arg2);
}

i32 WINEventHandler::BeginGfx(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<i32, WINEventHandler*, i32, i32, i32>>(0x561F20, this, arg1, arg2, arg3);
}

void WINEventHandler::BeginTracking()
{
    return stub<thiscall_t<void, WINEventHandler*>>(0x562610, this);
}

void WINEventHandler::EndGfx()
{
    return stub<thiscall_t<void, WINEventHandler*>>(0x561FC0, this);
}

void WINEventHandler::EndTracking()
{
    return stub<thiscall_t<void, WINEventHandler*>>(0x562640, this);
}

char* WINEventHandler::GKeyName(i32 arg1)
{
    return stub<thiscall_t<char*, WINEventHandler*, i32>>(0x561FE0, this, arg1);
}

void WINEventHandler::Update(i32 arg1)
{
    return stub<thiscall_t<void, WINEventHandler*, i32>>(0x562350, this, arg1);
}

i32 WINEventHandler::WindowProc(struct HWND__* arg1, u32 arg2, u32 arg3, i32 arg4)
{
    return stub<thiscall_t<i32, WINEventHandler*, struct HWND__*, u32, u32, i32>>(
        0x562720, this, arg1, arg2, arg3, arg4);
}

void DeallocateEventQueue()
{
    return stub<cdecl_t<void>>(0x562E60);
}

void InitEventQueue()
{
    return stub<cdecl_t<void>>(0x562DF0);
}
