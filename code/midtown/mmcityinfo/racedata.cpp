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

#pragma once

define_dummy_symbol(mmcityinfo_racedata);

#include "racedata.h"

#include "state.h"

#include "stream/fsystem.h"
#include "stream/stream.h"

mmRaceData::mmRaceData() = default;

mmRaceData::~mmRaceData() = default;

f32 mmRaceData::GetAmbientDensity(i32 race_index, mmSkillLevel skill)
{
    if (skill == mmSkillLevel::Professional)
        return ProAmbientDensity[race_index];
    else
        return AmateurAmbientDensity[race_index];
}

i32 mmRaceData::GetCarType(i32 race_index, mmSkillLevel skill)
{
    if (skill == mmSkillLevel::Professional)
        return ProCarTypes[race_index];
    else
        return AmateurCarTypes[race_index];
}

f32 mmRaceData::GetDifficulty(i32 race_index, mmSkillLevel skill)
{
    if (skill == mmSkillLevel::Professional)
        return ProDifficulty[race_index];
    else
        return AmateurDifficulty[race_index];
}

i32 mmRaceData::GetNumCops(i32 race_index, mmSkillLevel skill)
{
    if (skill == mmSkillLevel::Professional)
        return ProNumCops[race_index];
    else
        return AmateurNumCops[race_index];
}

i32 mmRaceData::GetNumLaps(i32 race_index, mmSkillLevel skill)
{
    if (skill == mmSkillLevel::Professional)
        return ProNumLaps[race_index];
    else
        return AmateurNumLaps[race_index];
}

i32 mmRaceData::GetNumOpponents(i32 race_index, mmSkillLevel skill)
{
    if (skill == mmSkillLevel::Professional)
        return ProNumOpps[race_index];
    else
        return AmateurNumOpps[race_index];
}

i32 mmRaceData::GetNumRaces()
{
    return NumRaces;
}

f32 mmRaceData::GetPedDensity(i32 race_index, mmSkillLevel skill)
{
    if (skill == mmSkillLevel::Professional)
        return ProPedDensity[race_index];
    else
        return AmateurPedDensity[race_index];
}

char* mmRaceData::GetRaceName([[maybe_unused]] i32 race_index)
{
    return nullptr;
}

f32 mmRaceData::GetTimeLimit(i32 race_index, mmSkillLevel skill)
{
    if (skill == mmSkillLevel::Professional)
        return ProTimeLimit[race_index];
    else
        return AmateurTimeLimit[race_index];
}

i32 mmRaceData::GetTimeOfDay(i32 race_index, mmSkillLevel skill)
{
    if (skill == mmSkillLevel::Professional)
        return ProTimeOfDay[race_index];
    else
        return AmateurTimeOfDay[race_index];
}

i32 mmRaceData::GetWeather(i32 race_index, mmSkillLevel skill)
{
    if (skill == mmSkillLevel::Professional)
        return ProWeather[race_index];
    else
        return AmateurWeather[race_index];
}

i32 mmRaceData::Load(char* file)
{
    Ptr<Stream> stream {OpenFile(file, "race", ".csv", 0, "race data")};

    if (!stream)
    {
        Errorf("RaceData::Can't open %s", file);
        return 0;
    }

    NumRaces = 0;

    char buffer[256];

    stream->Gets(buffer, sizeof(buffer));

    while (stream->Gets(buffer, sizeof(buffer)))
    {
        char* ctx = nullptr;

        (void) arts_strtok(buffer, ",", &ctx);

        AmateurCarTypes[NumRaces] = std::atoi(arts_strtok(nullptr, ",", &ctx));
        AmateurTimeOfDay[NumRaces] = std::atoi(arts_strtok(nullptr, ",", &ctx));
        AmateurWeather[NumRaces] = std::atoi(arts_strtok(nullptr, ",", &ctx));
        AmateurNumOpps[NumRaces] = std::atoi(arts_strtok(nullptr, ",", &ctx));
        AmateurNumCops[NumRaces] = std::atoi(arts_strtok(nullptr, ",", &ctx));
        AmateurAmbientDensity[NumRaces] = std::strtof(arts_strtok(nullptr, ",", &ctx), nullptr);
        AmateurPedDensity[NumRaces] = std::strtof(arts_strtok(nullptr, ",", &ctx), nullptr);
        AmateurNumLaps[NumRaces] = std::atoi(arts_strtok(nullptr, ",", &ctx));
        AmateurTimeLimit[NumRaces] = std::strtof(arts_strtok(nullptr, ",", &ctx), nullptr);
        AmateurDifficulty[NumRaces] = std::strtof(arts_strtok(nullptr, ",", &ctx), nullptr);

        ProCarTypes[NumRaces] = std::atoi(arts_strtok(nullptr, ",", &ctx));
        ProTimeOfDay[NumRaces] = std::atoi(arts_strtok(nullptr, ",", &ctx));
        ProWeather[NumRaces] = std::atoi(arts_strtok(nullptr, ",", &ctx));
        ProNumOpps[NumRaces] = std::atoi(arts_strtok(nullptr, ",", &ctx));
        ProNumCops[NumRaces] = std::atoi(arts_strtok(nullptr, ",", &ctx));
        ProAmbientDensity[NumRaces] = std::strtof(arts_strtok(nullptr, ",", &ctx), nullptr);
        ProPedDensity[NumRaces] = std::strtof(arts_strtok(nullptr, ",", &ctx), nullptr);
        ProNumLaps[NumRaces] = std::atoi(arts_strtok(nullptr, ",", &ctx));
        ProTimeLimit[NumRaces] = std::strtof(arts_strtok(nullptr, ",", &ctx), nullptr);
        ProDifficulty[NumRaces] = std::strtof(arts_strtok(nullptr, "\r\n", &ctx), nullptr);

        ++NumRaces;
    }

    return 1;
}