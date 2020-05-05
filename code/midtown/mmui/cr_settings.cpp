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
    unimplemented(arg1);
}

i32 CRSettings::AddPlayerRecord(char* arg1, i32 arg2, i32 arg3, char* arg4)
{
    return stub<thiscall_t<i32, CRSettings*, char*, i32, i32, char*>>(0xA1120_Offset, this, arg1, arg2, arg3, arg4);
}

void CRSettings::DecodeCRData(i32 arg1)
{
    return stub<thiscall_t<void, CRSettings*, i32>>(0xA14E0_Offset, this, arg1);
}

i32 CRSettings::EncodeCRData()
{
    return stub<thiscall_t<i32, CRSettings*>>(0xA1490_Offset, this);
}

i32 CRSettings::GetGoldMass()
{
    return stub<thiscall_t<i32, CRSettings*>>(0xA1650_Offset, this);
}

i32 CRSettings::GetGoldMassVal()
{
    return stub<thiscall_t<i32, CRSettings*>>(0xA16B0_Offset, this);
}

void CRSettings::GetLimit(i32& arg1, i32& arg2)
{
    return stub<thiscall_t<void, CRSettings*, i32&, i32&>>(0xA1550_Offset, this, arg1, arg2);
}

i32 CRSettings::GetLimitVal(i32& arg1)
{
    return stub<thiscall_t<i32, CRSettings*, i32&>>(0xA1660_Offset, this, arg1);
}

void CRSettings::InitPlayerRecord()
{
    return stub<thiscall_t<void, CRSettings*>>(0xA1050_Offset, this);
}

void CRSettings::ResetPlayerRecord()
{
    return stub<thiscall_t<void, CRSettings*>>(0xA12A0_Offset, this);
}

void CRSettings::SetGameClassCallback()
{
    return stub<thiscall_t<void, CRSettings*>>(0xA16C0_Offset, this);
}

void CRSettings::SetGoldMass(i32 arg1)
{
    return stub<thiscall_t<void, CRSettings*, i32>>(0xA1620_Offset, this, arg1);
}

void CRSettings::SetHost(i32 arg1)
{
    return stub<thiscall_t<void, CRSettings*, i32>>(0xA0F50_Offset, this, arg1);
}

void CRSettings::SetLimit(i32& arg1, i32& arg2)
{
    return stub<thiscall_t<void, CRSettings*, i32&, i32&>>(0xA15A0_Offset, this, arg1, arg2);
}

void CRSettings::SetLimitControl()
{
    return stub<thiscall_t<void, CRSettings*>>(0xA1330_Offset, this);
}

void CRSettings::SetPlayerScore(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, CRSettings*, i32, i32>>(0xA1260_Offset, this, arg1, arg2);
}

void CRSettings::SetTeam()
{
    return stub<thiscall_t<void, CRSettings*>>(0xA0F20_Offset, this);
}

void CRSettings::SetTeamWidget()
{
    return stub<thiscall_t<void, CRSettings*>>(0xA0F40_Offset, this);
}

void CRSettings::SetTeamWidgets()
{
    return stub<thiscall_t<void, CRSettings*>>(0xA16E0_Offset, this);
}

void CRSettings::SettingsCB()
{
    return stub<thiscall_t<void, CRSettings*>>(0xA0F10_Offset, this);
}
