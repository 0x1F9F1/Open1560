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

enum class mmSkillLevel : i32;

inline constexpr i32 MAX_RACES = 15;

class mmRaceData
{
public:
    // ??0mmRaceData@@QAE@XZ
    ARTS_EXPORT mmRaceData();

    // ??1mmRaceData@@QAE@XZ
    ARTS_EXPORT ~mmRaceData() = default;

    // ?GetAmbientDensity@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    ARTS_EXPORT f32 GetAmbientDensity(i32 race_index, mmSkillLevel skill);

    // ?GetCarType@mmRaceData@@QAEHHW4mmSkillLevel@@@Z | unused
    i32 GetCarType(i32 race_index, mmSkillLevel skill);

    // ?GetDifficulty@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    ARTS_EXPORT f32 GetDifficulty(i32 race_index, mmSkillLevel skill);

    // ?GetNumCops@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    ARTS_EXPORT i32 GetNumCops(i32 race_index, mmSkillLevel skill);

    // ?GetNumLaps@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    ARTS_EXPORT i32 GetNumLaps(i32 race_index, mmSkillLevel skill);

    // ?GetNumOpponents@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    ARTS_EXPORT i32 GetNumOpponents(i32 race_index, mmSkillLevel skill);

    // ?GetNumRaces@mmRaceData@@QAEHXZ
    ARTS_EXPORT i32 GetNumRaces();

    // ?GetPedDensity@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    ARTS_EXPORT f32 GetPedDensity(i32 race_index, mmSkillLevel skill);

    // ?GetRaceName@mmRaceData@@QAEPADH@Z | unused
    char* GetRaceName(i32 race_index);

    // ?GetTimeLimit@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    ARTS_EXPORT f32 GetTimeLimit(i32 race_index, mmSkillLevel skill);

    // ?GetTimeOfDay@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    ARTS_EXPORT i32 GetTimeOfDay(i32 race_index, mmSkillLevel skill);

    // ?GetWeather@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    ARTS_EXPORT i32 GetWeather(i32 race_index, mmSkillLevel skill);

    // ?Load@mmRaceData@@QAEHPAD@Z
    ARTS_EXPORT i32 Load(char* file);

private:
    i32 NumRaces {};
    i32 AmateurCarTypes[MAX_RACES] {};
    i32 AmateurNumLaps[MAX_RACES] {};
    i32 AmateurNumOpps[MAX_RACES] {};
    i32 AmateurNumCops[MAX_RACES] {};
    i32 AmateurTimeOfDay[MAX_RACES] {};
    i32 AmateurWeather[MAX_RACES] {};
    f32 AmateurPedDensity[MAX_RACES] {};
    f32 AmateurAmbientDensity[MAX_RACES] {};
    f32 AmateurTimeLimit[MAX_RACES] {};
    f32 AmateurDifficulty[MAX_RACES] {};
    i32 ProCarTypes[MAX_RACES] {};
    i32 ProNumLaps[MAX_RACES] {};
    i32 ProNumOpps[MAX_RACES] {};
    i32 ProNumCops[MAX_RACES] {};
    i32 ProTimeOfDay[MAX_RACES] {};
    i32 ProWeather[MAX_RACES] {};
    f32 ProPedDensity[MAX_RACES] {};
    f32 ProAmbientDensity[MAX_RACES] {};
    f32 ProTimeLimit[MAX_RACES] {};
    f32 ProDifficulty[MAX_RACES] {};
};

check_size(mmRaceData, 0x4B4);