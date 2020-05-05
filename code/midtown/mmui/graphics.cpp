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

define_dummy_symbol(mmui_graphics);

#include "graphics.h"

void AutoDetect(i32 arg1, i32 arg2)
{
    return stub<cdecl_t<void, i32, i32>>(0x99710_Offset, arg1, arg2);
}

GraphicsOptions::GraphicsOptions(i32 arg1)
{
    unimplemented(arg1);
}

GraphicsOptions::~GraphicsOptions()
{
    unimplemented(arg1);
}

void GraphicsOptions::CancelAction()
{
    return stub<thiscall_t<void, GraphicsOptions*>>(0x9A610_Offset, this);
}

void GraphicsOptions::DoneAction()
{
    return stub<thiscall_t<void, GraphicsOptions*>>(0x9A640_Offset, this);
}

void GraphicsOptions::PreSetup()
{
    return stub<thiscall_t<void, GraphicsOptions*>>(0x9A5A0_Offset, this);
}

void GraphicsOptions::ResetDefaultAction()
{
    return stub<thiscall_t<void, GraphicsOptions*>>(0x9A5C0_Offset, this);
}

void GraphicsOptions::SetLightQuality()
{
    return stub<thiscall_t<void, GraphicsOptions*>>(0x9A370_Offset, this);
}

void GraphicsOptions::SetRenderer()
{
    return stub<thiscall_t<void, GraphicsOptions*>>(0x9A390_Offset, this);
}

void GraphicsOptions::SetResolution()
{
    return stub<thiscall_t<void, GraphicsOptions*>>(0x9A350_Offset, this);
}
