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

#include "mmvoicecommentary.h"

mmVoiceCommentary::mmVoiceCommentary()
{
    unimplemented();
}

mmVoiceCommentary::~mmVoiceCommentary()
{
    unimplemented();
}

char* mmVoiceCommentary::CatName(char* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<char*, mmVoiceCommentary*, char*, i32, i32>>(0xED190_Offset, this, arg1, arg2, arg3);
}

char* mmVoiceCommentary::GetLapName(i16 arg1)
{
    return stub<thiscall_t<char*, mmVoiceCommentary*, i16>>(0xED390_Offset, this, arg1);
}

char* mmVoiceCommentary::GetRandomBlueCR(i16 arg1)
{
    return stub<thiscall_t<char*, mmVoiceCommentary*, i16>>(0xED830_Offset, this, arg1);
}

char* mmVoiceCommentary::GetRandomCop(i16 arg1)
{
    return stub<thiscall_t<char*, mmVoiceCommentary*, i16>>(0xED8B0_Offset, this, arg1);
}

char* mmVoiceCommentary::GetRandomPreBlitz()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0xEC650_Offset, this);
}

char* mmVoiceCommentary::GetRandomPreCheckPoint()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0xEC810_Offset, this);
}

char* mmVoiceCommentary::GetRandomPreCircuit()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0xEC730_Offset, this);
}

char* mmVoiceCommentary::GetRandomPreRace()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0xEC4D0_Offset, this);
}

char* mmVoiceCommentary::GetRandomPreRaceVeh()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0xECB50_Offset, this);
}

char* mmVoiceCommentary::GetRandomRedCR(i16 arg1)
{
    return stub<thiscall_t<char*, mmVoiceCommentary*, i16>>(0xED7B0_Offset, this, arg1);
}

char* mmVoiceCommentary::GetRandomResults(i16 arg1)
{
    return stub<thiscall_t<char*, mmVoiceCommentary*, i16>>(0xECA70_Offset, this, arg1);
}

char* mmVoiceCommentary::GetRandomResultsMid()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0xECEF0_Offset, this);
}

char* mmVoiceCommentary::GetRandomResultsPoor()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0xECD50_Offset, this);
}

char* mmVoiceCommentary::GetRandomResultsWin()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0xECBB0_Offset, this);
}

char* mmVoiceCommentary::GetRandomRobber(i16 arg1)
{
    return stub<thiscall_t<char*, mmVoiceCommentary*, i16>>(0xED730_Offset, this, arg1);
}

char* mmVoiceCommentary::GetRandomTOD()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0xED090_Offset, this);
}

char* mmVoiceCommentary::GetRandomWeather()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0xED0F0_Offset, this);
}

void mmVoiceCommentary::Play(char* arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, char*>>(0xEC410_Offset, this, arg1);
}

void mmVoiceCommentary::PlayAirBorne()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEC1F0_Offset, this);
}

void mmVoiceCommentary::PlayBulletUnlocked()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEDDE0_Offset, this);
}

void mmVoiceCommentary::PlayBusUnlocked()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEDC80_Offset, this);
}

void mmVoiceCommentary::PlayCR(i16 arg1, i16 arg2)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, i16, i16>>(0xED630_Offset, this, arg1, arg2);
}

void mmVoiceCommentary::PlayCRPreRace()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xED4C0_Offset, this);
}

void mmVoiceCommentary::PlayCheckPoint()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEC2D0_Offset, this);
}

void mmVoiceCommentary::PlayCollision()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xED5C0_Offset, this);
}

void mmVoiceCommentary::PlayCopCarUnlocked()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEDCE0_Offset, this);
}

void mmVoiceCommentary::PlayEndRaceDamage()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEDB60_Offset, this);
}

void mmVoiceCommentary::PlayFinalCheckPoint()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEC320_Offset, this);
}

void mmVoiceCommentary::PlayFinalLap()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEC3A0_Offset, this);
}

void mmVoiceCommentary::PlayGTUnlocked()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEDC20_Offset, this);
}

void mmVoiceCommentary::PlayLap(i16 arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, i16>>(0xEC390_Offset, this, arg1);
}

void mmVoiceCommentary::PlayMidResults()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEC990_Offset, this);
}

void mmVoiceCommentary::PlayNetworkPreRace()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xED450_Offset, this);
}

void mmVoiceCommentary::PlayNextRacesUnlocked()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEDEA0_Offset, this);
}

void mmVoiceCommentary::PlayOpponentFinish(i16 arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, i16>>(0xED930_Offset, this, arg1);
}

void mmVoiceCommentary::PlayPreRace()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEC460_Offset, this);
}

void mmVoiceCommentary::PlayResults(i16 arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, i16>>(0xECA00_Offset, this, arg1);
}

void mmVoiceCommentary::PlayRoam()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEC260_Offset, this);
}

void mmVoiceCommentary::PlaySemiUnlocked()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEDE40_Offset, this);
}

void mmVoiceCommentary::PlayTeamCR(i16 arg1, i16 arg2)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, i16, i16>>(0xED6C0_Offset, this, arg1, arg2);
}

void mmVoiceCommentary::PlayTimePenalty()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEDA90_Offset, this);
}

void mmVoiceCommentary::PlayUnlock(i32 arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, i32>>(0xEDBD0_Offset, this, arg1);
}

void mmVoiceCommentary::PlayWinResults()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEC920_Offset, this);
}

void mmVoiceCommentary::SetFrequency(f32 arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, f32>>(0xEC170_Offset, this, arg1);
}

void mmVoiceCommentary::Stop()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEC190_Offset, this);
}

void mmVoiceCommentary::StopNow()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEC1A0_Offset, this);
}

void mmVoiceCommentary::Update()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0xEDF70_Offset, this);
}

void mmVoiceCommentary::ValidateCity(char* arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, char*>>(0xEC130_Offset, this, arg1);
}

define_dummy_symbol(mmaudio_mmvoicecommentary);
