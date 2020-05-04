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
    mmaudio:mmvoicecommentary

    0x4EC070 | public: __thiscall mmVoiceCommentary::mmVoiceCommentary(void) | ??0mmVoiceCommentary@@QAE@XZ
    0x4EC110 | public: __thiscall mmVoiceCommentary::~mmVoiceCommentary(void) | ??1mmVoiceCommentary@@QAE@XZ
    0x4EC130 | public: void __thiscall mmVoiceCommentary::ValidateCity(char *) | ?ValidateCity@mmVoiceCommentary@@QAEXPAD@Z
    0x4EC170 | public: void __thiscall mmVoiceCommentary::SetFrequency(float) | ?SetFrequency@mmVoiceCommentary@@QAEXM@Z
    0x4EC190 | public: void __thiscall mmVoiceCommentary::Stop(void) | ?Stop@mmVoiceCommentary@@QAEXXZ
    0x4EC1A0 | public: void __thiscall mmVoiceCommentary::StopNow(void) | ?StopNow@mmVoiceCommentary@@QAEXXZ
    0x4EC1F0 | public: void __thiscall mmVoiceCommentary::PlayAirBorne(void) | ?PlayAirBorne@mmVoiceCommentary@@QAEXXZ
    0x4EC260 | public: void __thiscall mmVoiceCommentary::PlayRoam(void) | ?PlayRoam@mmVoiceCommentary@@QAEXXZ
    0x4EC2D0 | public: void __thiscall mmVoiceCommentary::PlayCheckPoint(void) | ?PlayCheckPoint@mmVoiceCommentary@@QAEXXZ
    0x4EC320 | public: void __thiscall mmVoiceCommentary::PlayFinalCheckPoint(void) | ?PlayFinalCheckPoint@mmVoiceCommentary@@QAEXXZ
    0x4EC390 | public: void __thiscall mmVoiceCommentary::PlayLap(short) | ?PlayLap@mmVoiceCommentary@@QAEXF@Z
    0x4EC3A0 | public: void __thiscall mmVoiceCommentary::PlayFinalLap(void) | ?PlayFinalLap@mmVoiceCommentary@@QAEXXZ
    0x4EC410 | public: void __thiscall mmVoiceCommentary::Play(char *) | ?Play@mmVoiceCommentary@@QAEXPAD@Z
    0x4EC460 | public: void __thiscall mmVoiceCommentary::PlayPreRace(void) | ?PlayPreRace@mmVoiceCommentary@@QAEXXZ
    0x4EC4D0 | public: char * __thiscall mmVoiceCommentary::GetRandomPreRace(void) | ?GetRandomPreRace@mmVoiceCommentary@@QAEPADXZ
    0x4EC650 | public: char * __thiscall mmVoiceCommentary::GetRandomPreBlitz(void) | ?GetRandomPreBlitz@mmVoiceCommentary@@QAEPADXZ
    0x4EC730 | public: char * __thiscall mmVoiceCommentary::GetRandomPreCircuit(void) | ?GetRandomPreCircuit@mmVoiceCommentary@@QAEPADXZ
    0x4EC810 | public: char * __thiscall mmVoiceCommentary::GetRandomPreCheckPoint(void) | ?GetRandomPreCheckPoint@mmVoiceCommentary@@QAEPADXZ
    0x4EC920 | public: void __thiscall mmVoiceCommentary::PlayWinResults(void) | ?PlayWinResults@mmVoiceCommentary@@QAEXXZ
    0x4EC990 | public: void __thiscall mmVoiceCommentary::PlayMidResults(void) | ?PlayMidResults@mmVoiceCommentary@@QAEXXZ
    0x4ECA00 | public: void __thiscall mmVoiceCommentary::PlayResults(short) | ?PlayResults@mmVoiceCommentary@@QAEXF@Z
    0x4ECA70 | public: char * __thiscall mmVoiceCommentary::GetRandomResults(short) | ?GetRandomResults@mmVoiceCommentary@@QAEPADF@Z
    0x4ECB50 | public: char * __thiscall mmVoiceCommentary::GetRandomPreRaceVeh(void) | ?GetRandomPreRaceVeh@mmVoiceCommentary@@QAEPADXZ
    0x4ECBB0 | public: char * __thiscall mmVoiceCommentary::GetRandomResultsWin(void) | ?GetRandomResultsWin@mmVoiceCommentary@@QAEPADXZ
    0x4ECD50 | public: char * __thiscall mmVoiceCommentary::GetRandomResultsPoor(void) | ?GetRandomResultsPoor@mmVoiceCommentary@@QAEPADXZ
    0x4ECEF0 | public: char * __thiscall mmVoiceCommentary::GetRandomResultsMid(void) | ?GetRandomResultsMid@mmVoiceCommentary@@QAEPADXZ
    0x4ED090 | public: char * __thiscall mmVoiceCommentary::GetRandomTOD(void) | ?GetRandomTOD@mmVoiceCommentary@@QAEPADXZ
    0x4ED0F0 | public: char * __thiscall mmVoiceCommentary::GetRandomWeather(void) | ?GetRandomWeather@mmVoiceCommentary@@QAEPADXZ
    0x4ED190 | public: char * __thiscall mmVoiceCommentary::CatName(char *,int,int) | ?CatName@mmVoiceCommentary@@QAEPADPADHH@Z
    0x4ED390 | public: char * __thiscall mmVoiceCommentary::GetLapName(short) | ?GetLapName@mmVoiceCommentary@@QAEPADF@Z
    0x4ED450 | public: void __thiscall mmVoiceCommentary::PlayNetworkPreRace(void) | ?PlayNetworkPreRace@mmVoiceCommentary@@QAEXXZ
    0x4ED4C0 | public: void __thiscall mmVoiceCommentary::PlayCRPreRace(void) | ?PlayCRPreRace@mmVoiceCommentary@@QAEXXZ
    0x4ED5C0 | public: void __thiscall mmVoiceCommentary::PlayCollision(void) | ?PlayCollision@mmVoiceCommentary@@QAEXXZ
    0x4ED630 | public: void __thiscall mmVoiceCommentary::PlayCR(short,short) | ?PlayCR@mmVoiceCommentary@@QAEXFF@Z
    0x4ED6C0 | public: void __thiscall mmVoiceCommentary::PlayTeamCR(short,short) | ?PlayTeamCR@mmVoiceCommentary@@QAEXFF@Z
    0x4ED730 | public: char * __thiscall mmVoiceCommentary::GetRandomRobber(short) | ?GetRandomRobber@mmVoiceCommentary@@QAEPADF@Z
    0x4ED7B0 | public: char * __thiscall mmVoiceCommentary::GetRandomRedCR(short) | ?GetRandomRedCR@mmVoiceCommentary@@QAEPADF@Z
    0x4ED830 | public: char * __thiscall mmVoiceCommentary::GetRandomBlueCR(short) | ?GetRandomBlueCR@mmVoiceCommentary@@QAEPADF@Z
    0x4ED8B0 | public: char * __thiscall mmVoiceCommentary::GetRandomCop(short) | ?GetRandomCop@mmVoiceCommentary@@QAEPADF@Z
    0x4ED930 | public: void __thiscall mmVoiceCommentary::PlayOpponentFinish(short) | ?PlayOpponentFinish@mmVoiceCommentary@@QAEXF@Z
    0x4EDA90 | public: void __thiscall mmVoiceCommentary::PlayTimePenalty(void) | ?PlayTimePenalty@mmVoiceCommentary@@QAEXXZ
    0x4EDB60 | public: void __thiscall mmVoiceCommentary::PlayEndRaceDamage(void) | ?PlayEndRaceDamage@mmVoiceCommentary@@QAEXXZ
    0x4EDBD0 | public: void __thiscall mmVoiceCommentary::PlayUnlock(int) | ?PlayUnlock@mmVoiceCommentary@@QAEXH@Z
    0x4EDC20 | public: void __thiscall mmVoiceCommentary::PlayGTUnlocked(void) | ?PlayGTUnlocked@mmVoiceCommentary@@QAEXXZ
    0x4EDC80 | public: void __thiscall mmVoiceCommentary::PlayBusUnlocked(void) | ?PlayBusUnlocked@mmVoiceCommentary@@QAEXXZ
    0x4EDCE0 | public: void __thiscall mmVoiceCommentary::PlayCopCarUnlocked(void) | ?PlayCopCarUnlocked@mmVoiceCommentary@@QAEXXZ
    0x4EDDE0 | public: void __thiscall mmVoiceCommentary::PlayBulletUnlocked(void) | ?PlayBulletUnlocked@mmVoiceCommentary@@QAEXXZ
    0x4EDE40 | public: void __thiscall mmVoiceCommentary::PlaySemiUnlocked(void) | ?PlaySemiUnlocked@mmVoiceCommentary@@QAEXXZ
    0x4EDEA0 | public: void __thiscall mmVoiceCommentary::PlayNextRacesUnlocked(void) | ?PlayNextRacesUnlocked@mmVoiceCommentary@@QAEXXZ
    0x4EDF70 | public: void __thiscall mmVoiceCommentary::Update(void) | ?Update@mmVoiceCommentary@@QAEXXZ
*/

class mmVoiceCommentary
{
public:
    // 0x4EC070 | ??0mmVoiceCommentary@@QAE@XZ
    mmVoiceCommentary();

    // 0x4EC110 | ??1mmVoiceCommentary@@QAE@XZ
    ~mmVoiceCommentary();

    // 0x4ED190 | ?CatName@mmVoiceCommentary@@QAEPADPADHH@Z
    char* CatName(char* arg1, i32 arg2, i32 arg3);

    // 0x4ED390 | ?GetLapName@mmVoiceCommentary@@QAEPADF@Z
    char* GetLapName(i16 arg1);

    // 0x4ED830 | ?GetRandomBlueCR@mmVoiceCommentary@@QAEPADF@Z
    char* GetRandomBlueCR(i16 arg1);

    // 0x4ED8B0 | ?GetRandomCop@mmVoiceCommentary@@QAEPADF@Z
    char* GetRandomCop(i16 arg1);

    // 0x4EC650 | ?GetRandomPreBlitz@mmVoiceCommentary@@QAEPADXZ
    char* GetRandomPreBlitz();

    // 0x4EC810 | ?GetRandomPreCheckPoint@mmVoiceCommentary@@QAEPADXZ
    char* GetRandomPreCheckPoint();

    // 0x4EC730 | ?GetRandomPreCircuit@mmVoiceCommentary@@QAEPADXZ
    char* GetRandomPreCircuit();

    // 0x4EC4D0 | ?GetRandomPreRace@mmVoiceCommentary@@QAEPADXZ
    char* GetRandomPreRace();

    // 0x4ECB50 | ?GetRandomPreRaceVeh@mmVoiceCommentary@@QAEPADXZ
    char* GetRandomPreRaceVeh();

    // 0x4ED7B0 | ?GetRandomRedCR@mmVoiceCommentary@@QAEPADF@Z
    char* GetRandomRedCR(i16 arg1);

    // 0x4ECA70 | ?GetRandomResults@mmVoiceCommentary@@QAEPADF@Z
    char* GetRandomResults(i16 arg1);

    // 0x4ECEF0 | ?GetRandomResultsMid@mmVoiceCommentary@@QAEPADXZ
    char* GetRandomResultsMid();

    // 0x4ECD50 | ?GetRandomResultsPoor@mmVoiceCommentary@@QAEPADXZ
    char* GetRandomResultsPoor();

    // 0x4ECBB0 | ?GetRandomResultsWin@mmVoiceCommentary@@QAEPADXZ
    char* GetRandomResultsWin();

    // 0x4ED730 | ?GetRandomRobber@mmVoiceCommentary@@QAEPADF@Z
    char* GetRandomRobber(i16 arg1);

    // 0x4ED090 | ?GetRandomTOD@mmVoiceCommentary@@QAEPADXZ
    char* GetRandomTOD();

    // 0x4ED0F0 | ?GetRandomWeather@mmVoiceCommentary@@QAEPADXZ
    char* GetRandomWeather();

    // 0x4EC410 | ?Play@mmVoiceCommentary@@QAEXPAD@Z
    void Play(char* arg1);

    // 0x4EC1F0 | ?PlayAirBorne@mmVoiceCommentary@@QAEXXZ
    void PlayAirBorne();

    // 0x4EDDE0 | ?PlayBulletUnlocked@mmVoiceCommentary@@QAEXXZ
    void PlayBulletUnlocked();

    // 0x4EDC80 | ?PlayBusUnlocked@mmVoiceCommentary@@QAEXXZ
    void PlayBusUnlocked();

    // 0x4ED630 | ?PlayCR@mmVoiceCommentary@@QAEXFF@Z
    void PlayCR(i16 arg1, i16 arg2);

    // 0x4ED4C0 | ?PlayCRPreRace@mmVoiceCommentary@@QAEXXZ
    void PlayCRPreRace();

    // 0x4EC2D0 | ?PlayCheckPoint@mmVoiceCommentary@@QAEXXZ
    void PlayCheckPoint();

    // 0x4ED5C0 | ?PlayCollision@mmVoiceCommentary@@QAEXXZ
    void PlayCollision();

    // 0x4EDCE0 | ?PlayCopCarUnlocked@mmVoiceCommentary@@QAEXXZ
    void PlayCopCarUnlocked();

    // 0x4EDB60 | ?PlayEndRaceDamage@mmVoiceCommentary@@QAEXXZ
    void PlayEndRaceDamage();

    // 0x4EC320 | ?PlayFinalCheckPoint@mmVoiceCommentary@@QAEXXZ
    void PlayFinalCheckPoint();

    // 0x4EC3A0 | ?PlayFinalLap@mmVoiceCommentary@@QAEXXZ
    void PlayFinalLap();

    // 0x4EDC20 | ?PlayGTUnlocked@mmVoiceCommentary@@QAEXXZ
    void PlayGTUnlocked();

    // 0x4EC390 | ?PlayLap@mmVoiceCommentary@@QAEXF@Z
    void PlayLap(i16 arg1);

    // 0x4EC990 | ?PlayMidResults@mmVoiceCommentary@@QAEXXZ
    void PlayMidResults();

    // 0x4ED450 | ?PlayNetworkPreRace@mmVoiceCommentary@@QAEXXZ
    void PlayNetworkPreRace();

    // 0x4EDEA0 | ?PlayNextRacesUnlocked@mmVoiceCommentary@@QAEXXZ
    void PlayNextRacesUnlocked();

    // 0x4ED930 | ?PlayOpponentFinish@mmVoiceCommentary@@QAEXF@Z
    void PlayOpponentFinish(i16 arg1);

    // 0x4EC460 | ?PlayPreRace@mmVoiceCommentary@@QAEXXZ
    void PlayPreRace();

    // 0x4ECA00 | ?PlayResults@mmVoiceCommentary@@QAEXF@Z
    void PlayResults(i16 arg1);

    // 0x4EC260 | ?PlayRoam@mmVoiceCommentary@@QAEXXZ
    void PlayRoam();

    // 0x4EDE40 | ?PlaySemiUnlocked@mmVoiceCommentary@@QAEXXZ
    void PlaySemiUnlocked();

    // 0x4ED6C0 | ?PlayTeamCR@mmVoiceCommentary@@QAEXFF@Z
    void PlayTeamCR(i16 arg1, i16 arg2);

    // 0x4EDA90 | ?PlayTimePenalty@mmVoiceCommentary@@QAEXXZ
    void PlayTimePenalty();

    // 0x4EDBD0 | ?PlayUnlock@mmVoiceCommentary@@QAEXH@Z
    void PlayUnlock(i32 arg1);

    // 0x4EC920 | ?PlayWinResults@mmVoiceCommentary@@QAEXXZ
    void PlayWinResults();

    // 0x4EC170 | ?SetFrequency@mmVoiceCommentary@@QAEXM@Z
    void SetFrequency(f32 arg1);

    // 0x4EC190 | ?Stop@mmVoiceCommentary@@QAEXXZ
    void Stop();

    // 0x4EC1A0 | ?StopNow@mmVoiceCommentary@@QAEXXZ
    void StopNow();

    // 0x4EDF70 | ?Update@mmVoiceCommentary@@QAEXXZ
    void Update();

    // 0x4EC130 | ?ValidateCity@mmVoiceCommentary@@QAEXPAD@Z
    void ValidateCity(char* arg1);
};

check_size(mmVoiceCommentary, 0x158);
