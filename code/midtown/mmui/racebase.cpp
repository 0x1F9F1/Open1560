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

define_dummy_symbol(mmui_racebase);

#include "racebase.h"

RaceMenuBase::RaceMenuBase(i32 arg1)
{
    unimplemented(arg1);
}

RaceMenuBase::~RaceMenuBase()
{
    unimplemented(arg1);
}

void RaceMenuBase::UsesLobby(i32 arg1)
{
    return stub<thiscall_t<void, RaceMenuBase*, i32>>(0x4A4F60, this, arg1);
}

void RaceMenuBase::AICallback()
{
    return stub<thiscall_t<void, RaceMenuBase*>>(0x4A79B0, this);
}

void RaceMenuBase::ChangeLocalVals()
{
    return stub<thiscall_t<void, RaceMenuBase*>>(0x4A7A20, this);
}

void RaceMenuBase::CheatCallback()
{
    return stub<thiscall_t<void, RaceMenuBase*>>(0x4A7690, this);
}

void RaceMenuBase::CityChange()
{
    return stub<thiscall_t<void, RaceMenuBase*>>(0x4A7750, this);
}

void RaceMenuBase::FocusDescription(i32 arg1)
{
    return stub<thiscall_t<void, RaceMenuBase*, i32>>(0x4A7340, this, arg1);
}

void RaceMenuBase::GameCallback()
{
    return stub<thiscall_t<void, RaceMenuBase*>>(0x4A78D0, this);
}

void RaceMenuBase::Init(i32 arg1)
{
    return stub<thiscall_t<void, RaceMenuBase*, i32>>(0x4A6500, this, arg1);
}

i32 RaceMenuBase::IsEnvEnabled()
{
    return stub<thiscall_t<i32, RaceMenuBase*>>(0x4A7670, this);
}

void RaceMenuBase::LapsCallback()
{
    return stub<thiscall_t<void, RaceMenuBase*>>(0x4A7950, this);
}

void RaceMenuBase::SetRW()
{
    return stub<thiscall_t<void, RaceMenuBase*>>(0x4A73A0, this);
}

void RaceMenuBase::SetStateRace()
{
    return stub<thiscall_t<void, RaceMenuBase*>>(0x4A7CB0, this);
}

void RaceMenuBase::SyncRaceState()
{
    return stub<thiscall_t<void, RaceMenuBase*>>(0x4A76A0, this);
}

void RaceMenuBase::TimeCallback()
{
    return stub<thiscall_t<void, RaceMenuBase*>>(0x4A7A10, this);
}

void RaceMenuBase::WPCallback()
{
    return stub<thiscall_t<void, RaceMenuBase*>>(0x4A7960, this);
}

void RaceMenuBase::WeatherCallback()
{
    return stub<thiscall_t<void, RaceMenuBase*>>(0x4A7A00, this);
}

void RaceMenuBase::WidgetOnOff(i32 arg1, class uiWidget* arg2)
{
    return stub<thiscall_t<void, RaceMenuBase*, i32, class uiWidget*>>(0x4A7370, this, arg1, arg2);
}
