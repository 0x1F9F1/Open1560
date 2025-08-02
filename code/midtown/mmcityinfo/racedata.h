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

/*
    mmcityinfo:racedata

    0x4D1BC0 | public: __thiscall mmRaceData::mmRaceData(void) | ??0mmRaceData@@QAE@XZ
    0x4D1BD0 | public: __thiscall mmRaceData::~mmRaceData(void) | ??1mmRaceData@@QAE@XZ
    0x4D1BE0 | public: int __thiscall mmRaceData::Load(char *) | ?Load@mmRaceData@@QAEHPAD@Z
    0x4D1F60 | public: int __thiscall mmRaceData::GetNumRaces(void) | ?GetNumRaces@mmRaceData@@QAEHXZ
    0x4D1F70 | public: char * __thiscall mmRaceData::GetRaceName(int) | ?GetRaceName@mmRaceData@@QAEPADH@Z
    0x4D1F80 | public: int __thiscall mmRaceData::GetCarType(int,enum mmSkillLevel) | ?GetCarType@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    0x4D1FB0 | public: int __thiscall mmRaceData::GetNumLaps(int,enum mmSkillLevel) | ?GetNumLaps@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    0x4D1FE0 | public: float __thiscall mmRaceData::GetTimeLimit(int,enum mmSkillLevel) | ?GetTimeLimit@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    0x4D2010 | public: int __thiscall mmRaceData::GetNumOpponents(int,enum mmSkillLevel) | ?GetNumOpponents@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    0x4D2040 | public: int __thiscall mmRaceData::GetNumCops(int,enum mmSkillLevel) | ?GetNumCops@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    0x4D2070 | public: int __thiscall mmRaceData::GetTimeOfDay(int,enum mmSkillLevel) | ?GetTimeOfDay@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    0x4D20A0 | public: int __thiscall mmRaceData::GetWeather(int,enum mmSkillLevel) | ?GetWeather@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    0x4D20D0 | public: float __thiscall mmRaceData::GetPedDensity(int,enum mmSkillLevel) | ?GetPedDensity@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    0x4D2100 | public: float __thiscall mmRaceData::GetAmbientDensity(int,enum mmSkillLevel) | ?GetAmbientDensity@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    0x4D2130 | public: float __thiscall mmRaceData::GetDifficulty(int,enum mmSkillLevel) | ?GetDifficulty@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
*/

enum class mmSkillLevel : i32;

class mmRaceData
{
public:
    // ??0mmRaceData@@QAE@XZ
    ARTS_IMPORT mmRaceData();

    // ??1mmRaceData@@QAE@XZ
    ARTS_EXPORT ~mmRaceData() = default;

    // ?GetAmbientDensity@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    ARTS_IMPORT f32 GetAmbientDensity(i32 arg1, mmSkillLevel arg2);

    // ?GetDifficulty@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    ARTS_IMPORT f32 GetDifficulty(i32 arg1, mmSkillLevel arg2);

    // ?GetNumCops@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    ARTS_IMPORT i32 GetNumCops(i32 arg1, mmSkillLevel arg2);

    // ?GetNumLaps@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    ARTS_IMPORT i32 GetNumLaps(i32 arg1, mmSkillLevel arg2);

    // ?GetNumOpponents@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    ARTS_IMPORT i32 GetNumOpponents(i32 arg1, mmSkillLevel arg2);

    // ?GetNumRaces@mmRaceData@@QAEHXZ
    ARTS_IMPORT i32 GetNumRaces();

    // ?GetPedDensity@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    ARTS_IMPORT f32 GetPedDensity(i32 arg1, mmSkillLevel arg2);

    // ?GetRaceName@mmRaceData@@QAEPADH@Z | unused
    ARTS_EXPORT char* GetRaceName(i32 arg1);

    // ?GetTimeLimit@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    ARTS_IMPORT f32 GetTimeLimit(i32 arg1, mmSkillLevel arg2);

    // ?GetTimeOfDay@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    ARTS_IMPORT i32 GetTimeOfDay(i32 arg1, mmSkillLevel arg2);

    // ?GetWeather@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    ARTS_IMPORT i32 GetWeather(i32 arg1, mmSkillLevel arg2);

    // ?Load@mmRaceData@@QAEHPAD@Z
    ARTS_IMPORT i32 Load(char* arg1);

    u8 gap0[0x4B4];
};

check_size(mmRaceData, 0x4B4);
