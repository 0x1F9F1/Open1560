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

#include "pcwindis/pcwindis.h"

void DeallocateEventQueue()
{
    delete eqEventHandler::SuperQ;

    eqEventHandler::SuperQ = nullptr;
}

void InitEventQueue()
{
    if (eqEventHandler::SuperQ == nullptr)
    {
        eqEventHandler::SuperQ = new WINEventHandler();
    }
}

static u32 WinEventHandlerMsgs[18] = {WM_MOUSEMOVE, WM_LBUTTONDOWN, WM_RBUTTONDOWN, WM_MBUTTONDOWN, WM_LBUTTONUP,
    WM_RBUTTONUP, WM_MBUTTONUP, WM_KILLFOCUS, WM_SETFOCUS, WM_KEYDOWN, WM_KEYUP, WM_CHAR, WM_ACTIVATE, WM_SIZE,
    WM_CLOSE, WM_SYSCOMMAND, WM_SETCURSOR, WM_MOUSEWHEEL};

WINEventHandler::WINEventHandler()
{
    RegisterMap("EventQ", WinEventHandlerMsgs, std::size(WinEventHandlerMsgs), this);
}

WINEventHandler::~WINEventHandler()
{
    UnregisterMap("EventQ");
}
