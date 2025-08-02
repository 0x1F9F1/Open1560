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

class mmVoiceCommentary
{
public:
    // ??0mmVoiceCommentary@@QAE@XZ
    ARTS_IMPORT mmVoiceCommentary();

    // ?CatName@mmVoiceCommentary@@QAEPADPADHH@Z
    ARTS_IMPORT char* CatName(char* arg1, i32 arg2, i32 arg3);

    // ?GetRandomBlueCR@mmVoiceCommentary@@QAEPADF@Z
    ARTS_IMPORT char* GetRandomBlueCR(i16 arg1);

    // ?GetRandomCop@mmVoiceCommentary@@QAEPADF@Z
    ARTS_IMPORT char* GetRandomCop(i16 arg1);

    // ?GetRandomPreBlitz@mmVoiceCommentary@@QAEPADXZ
    ARTS_IMPORT char* GetRandomPreBlitz();

    // ?GetRandomPreCheckPoint@mmVoiceCommentary@@QAEPADXZ
    ARTS_IMPORT char* GetRandomPreCheckPoint();

    // ?GetRandomPreCircuit@mmVoiceCommentary@@QAEPADXZ
    ARTS_IMPORT char* GetRandomPreCircuit();

    // ?GetRandomPreRace@mmVoiceCommentary@@QAEPADXZ
    ARTS_IMPORT char* GetRandomPreRace();

    // ?GetRandomPreRaceVeh@mmVoiceCommentary@@QAEPADXZ
    ARTS_IMPORT char* GetRandomPreRaceVeh();

    // ?GetRandomRedCR@mmVoiceCommentary@@QAEPADF@Z
    ARTS_IMPORT char* GetRandomRedCR(i16 arg1);

    // ?GetRandomResults@mmVoiceCommentary@@QAEPADF@Z
    ARTS_IMPORT char* GetRandomResults(i16 arg1);

    // ?GetRandomResultsMid@mmVoiceCommentary@@QAEPADXZ
    ARTS_IMPORT char* GetRandomResultsMid();

    // ?GetRandomResultsPoor@mmVoiceCommentary@@QAEPADXZ
    ARTS_IMPORT char* GetRandomResultsPoor();

    // ?GetRandomResultsWin@mmVoiceCommentary@@QAEPADXZ
    ARTS_IMPORT char* GetRandomResultsWin();

    // ?GetRandomRobber@mmVoiceCommentary@@QAEPADF@Z
    ARTS_IMPORT char* GetRandomRobber(i16 arg1);

    // ?GetRandomTOD@mmVoiceCommentary@@QAEPADXZ
    ARTS_IMPORT char* GetRandomTOD();

    // ?GetRandomWeather@mmVoiceCommentary@@QAEPADXZ
    ARTS_IMPORT char* GetRandomWeather();

    // ?Play@mmVoiceCommentary@@QAEXPAD@Z
    ARTS_IMPORT void Play(char* arg1);

    // ?PlayBulletUnlocked@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlayBulletUnlocked();

    // ?PlayBusUnlocked@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlayBusUnlocked();

    // ?PlayCR@mmVoiceCommentary@@QAEXFF@Z
    ARTS_IMPORT void PlayCR(i16 arg1, i16 arg2);

    // ?PlayCRPreRace@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlayCRPreRace();

    // ?PlayCopCarUnlocked@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlayCopCarUnlocked();

    // ?PlayEndRaceDamage@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlayEndRaceDamage();

    // ?PlayFinalCheckPoint@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlayFinalCheckPoint();

    // ?PlayFinalLap@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlayFinalLap();

    // ?PlayGTUnlocked@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlayGTUnlocked();

    // ?PlayLap@mmVoiceCommentary@@QAEXF@Z | unused
    ARTS_EXPORT void PlayLap(i16 arg1);

    // ?PlayNextRacesUnlocked@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlayNextRacesUnlocked();

    // ?PlayPreRace@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlayPreRace();

    // ?PlayResults@mmVoiceCommentary@@QAEXF@Z
    ARTS_IMPORT void PlayResults(i16 arg1);

    // ?PlayRoam@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlayRoam();

    // ?PlaySemiUnlocked@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlaySemiUnlocked();

    // ?PlayTeamCR@mmVoiceCommentary@@QAEXFF@Z
    ARTS_IMPORT void PlayTeamCR(i16 arg1, i16 arg2);

    // ?PlayTimePenalty@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlayTimePenalty();

    // ?PlayUnlock@mmVoiceCommentary@@QAEXH@Z
    ARTS_IMPORT void PlayUnlock(i32 arg1);

    // ?PlayWinResults@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void PlayWinResults();

    // ?SetFrequency@mmVoiceCommentary@@QAEXM@Z
    ARTS_IMPORT void SetFrequency(f32 arg1);

    // ?StopNow@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void StopNow();

    // ?Update@mmVoiceCommentary@@QAEXXZ
    ARTS_IMPORT void Update();

    // ?ValidateCity@mmVoiceCommentary@@QAEXPAD@Z
    ARTS_IMPORT void ValidateCity(char* arg1);

    u8 gap0[0x158];
};

check_size(mmVoiceCommentary, 0x158);
