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

define_dummy_symbol(mmaudio_mmvoicecommentary);

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
    return stub<thiscall_t<char*, mmVoiceCommentary*, char*, i32, i32>>(0x4ED190, this, arg1, arg2, arg3);
}

char* mmVoiceCommentary::GetLapName(i16 arg1)
{
    return stub<thiscall_t<char*, mmVoiceCommentary*, i16>>(0x4ED390, this, arg1);
}

char* mmVoiceCommentary::GetRandomBlueCR(i16 arg1)
{
    return stub<thiscall_t<char*, mmVoiceCommentary*, i16>>(0x4ED830, this, arg1);
}

char* mmVoiceCommentary::GetRandomCop(i16 arg1)
{
    return stub<thiscall_t<char*, mmVoiceCommentary*, i16>>(0x4ED8B0, this, arg1);
}

char* mmVoiceCommentary::GetRandomPreBlitz()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0x4EC650, this);
}

char* mmVoiceCommentary::GetRandomPreCheckPoint()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0x4EC810, this);
}

char* mmVoiceCommentary::GetRandomPreCircuit()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0x4EC730, this);
}

char* mmVoiceCommentary::GetRandomPreRace()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0x4EC4D0, this);
}

char* mmVoiceCommentary::GetRandomPreRaceVeh()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0x4ECB50, this);
}

char* mmVoiceCommentary::GetRandomRedCR(i16 arg1)
{
    return stub<thiscall_t<char*, mmVoiceCommentary*, i16>>(0x4ED7B0, this, arg1);
}

char* mmVoiceCommentary::GetRandomResults(i16 arg1)
{
    return stub<thiscall_t<char*, mmVoiceCommentary*, i16>>(0x4ECA70, this, arg1);
}

char* mmVoiceCommentary::GetRandomResultsMid()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0x4ECEF0, this);
}

char* mmVoiceCommentary::GetRandomResultsPoor()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0x4ECD50, this);
}

char* mmVoiceCommentary::GetRandomResultsWin()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0x4ECBB0, this);
}

char* mmVoiceCommentary::GetRandomRobber(i16 arg1)
{
    return stub<thiscall_t<char*, mmVoiceCommentary*, i16>>(0x4ED730, this, arg1);
}

char* mmVoiceCommentary::GetRandomTOD()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0x4ED090, this);
}

char* mmVoiceCommentary::GetRandomWeather()
{
    return stub<thiscall_t<char*, mmVoiceCommentary*>>(0x4ED0F0, this);
}

void mmVoiceCommentary::Play(char* arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, char*>>(0x4EC410, this, arg1);
}

void mmVoiceCommentary::PlayAirBorne()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EC1F0, this);
}

void mmVoiceCommentary::PlayBulletUnlocked()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EDDE0, this);
}

void mmVoiceCommentary::PlayBusUnlocked()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EDC80, this);
}

void mmVoiceCommentary::PlayCR(i16 arg1, i16 arg2)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, i16, i16>>(0x4ED630, this, arg1, arg2);
}

void mmVoiceCommentary::PlayCRPreRace()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4ED4C0, this);
}

void mmVoiceCommentary::PlayCheckPoint()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EC2D0, this);
}

void mmVoiceCommentary::PlayCollision()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4ED5C0, this);
}

void mmVoiceCommentary::PlayCopCarUnlocked()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EDCE0, this);
}

void mmVoiceCommentary::PlayEndRaceDamage()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EDB60, this);
}

void mmVoiceCommentary::PlayFinalCheckPoint()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EC320, this);
}

void mmVoiceCommentary::PlayFinalLap()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EC3A0, this);
}

void mmVoiceCommentary::PlayGTUnlocked()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EDC20, this);
}

void mmVoiceCommentary::PlayLap(i16 arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, i16>>(0x4EC390, this, arg1);
}

void mmVoiceCommentary::PlayMidResults()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EC990, this);
}

void mmVoiceCommentary::PlayNetworkPreRace()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4ED450, this);
}

void mmVoiceCommentary::PlayNextRacesUnlocked()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EDEA0, this);
}

void mmVoiceCommentary::PlayOpponentFinish(i16 arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, i16>>(0x4ED930, this, arg1);
}

void mmVoiceCommentary::PlayPreRace()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EC460, this);
}

void mmVoiceCommentary::PlayResults(i16 arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, i16>>(0x4ECA00, this, arg1);
}

void mmVoiceCommentary::PlayRoam()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EC260, this);
}

void mmVoiceCommentary::PlaySemiUnlocked()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EDE40, this);
}

void mmVoiceCommentary::PlayTeamCR(i16 arg1, i16 arg2)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, i16, i16>>(0x4ED6C0, this, arg1, arg2);
}

void mmVoiceCommentary::PlayTimePenalty()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EDA90, this);
}

void mmVoiceCommentary::PlayUnlock(i32 arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, i32>>(0x4EDBD0, this, arg1);
}

void mmVoiceCommentary::PlayWinResults()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EC920, this);
}

void mmVoiceCommentary::SetFrequency(f32 arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, f32>>(0x4EC170, this, arg1);
}

void mmVoiceCommentary::Stop()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EC190, this);
}

void mmVoiceCommentary::StopNow()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EC1A0, this);
}

void mmVoiceCommentary::Update()
{
    return stub<thiscall_t<void, mmVoiceCommentary*>>(0x4EDF70, this);
}

void mmVoiceCommentary::ValidateCity(char* arg1)
{
    return stub<thiscall_t<void, mmVoiceCommentary*, char*>>(0x4EC130, this, arg1);
}
