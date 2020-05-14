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

define_dummy_symbol(mmui_cr_settings);

#include "cr_settings.h"

CRSettings::CRSettings(i32 arg1)
{
    unimplemented(arg1);
}

CRSettings::~CRSettings()
{
    unimplemented();
}

i32 CRSettings::AddPlayerRecord(char* arg1, i32 arg2, i32 arg3, char* arg4)
{
    return stub<thiscall_t<i32, CRSettings*, char*, i32, i32, char*>>(0x4A1120, this, arg1, arg2, arg3, arg4);
}

void CRSettings::DecodeCRData(i32 arg1)
{
    return stub<thiscall_t<void, CRSettings*, i32>>(0x4A14E0, this, arg1);
}

i32 CRSettings::EncodeCRData()
{
    return stub<thiscall_t<i32, CRSettings*>>(0x4A1490, this);
}

i32 CRSettings::GetGoldMass()
{
    return stub<thiscall_t<i32, CRSettings*>>(0x4A1650, this);
}

i32 CRSettings::GetGoldMassVal()
{
    return stub<thiscall_t<i32, CRSettings*>>(0x4A16B0, this);
}

void CRSettings::GetLimit(i32& arg1, i32& arg2)
{
    return stub<thiscall_t<void, CRSettings*, i32&, i32&>>(0x4A1550, this, arg1, arg2);
}

i32 CRSettings::GetLimitVal(i32& arg1)
{
    return stub<thiscall_t<i32, CRSettings*, i32&>>(0x4A1660, this, arg1);
}

void CRSettings::InitPlayerRecord()
{
    return stub<thiscall_t<void, CRSettings*>>(0x4A1050, this);
}

void CRSettings::ResetPlayerRecord()
{
    return stub<thiscall_t<void, CRSettings*>>(0x4A12A0, this);
}

void CRSettings::SetGameClassCallback()
{
    return stub<thiscall_t<void, CRSettings*>>(0x4A16C0, this);
}

void CRSettings::SetGoldMass(i32 arg1)
{
    return stub<thiscall_t<void, CRSettings*, i32>>(0x4A1620, this, arg1);
}

void CRSettings::SetHost(i32 arg1)
{
    return stub<thiscall_t<void, CRSettings*, i32>>(0x4A0F50, this, arg1);
}

void CRSettings::SetLimit(i32& arg1, i32& arg2)
{
    return stub<thiscall_t<void, CRSettings*, i32&, i32&>>(0x4A15A0, this, arg1, arg2);
}

void CRSettings::SetLimitControl()
{
    return stub<thiscall_t<void, CRSettings*>>(0x4A1330, this);
}

void CRSettings::SetPlayerScore(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, CRSettings*, i32, i32>>(0x4A1260, this, arg1, arg2);
}

void CRSettings::SetTeam()
{
    return stub<thiscall_t<void, CRSettings*>>(0x4A0F20, this);
}

void CRSettings::SetTeamWidget()
{
    return stub<thiscall_t<void, CRSettings*>>(0x4A0F40, this);
}

void CRSettings::SetTeamWidgets()
{
    return stub<thiscall_t<void, CRSettings*>>(0x4A16E0, this);
}

void CRSettings::SettingsCB()
{
    return stub<thiscall_t<void, CRSettings*>>(0x4A0F10, this);
}
