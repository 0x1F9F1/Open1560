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
    mmgame:multicr

    0x41BFB0 | public: __thiscall mmMultiCR::mmMultiCR(void) | ??0mmMultiCR@@QAE@XZ
    0x41C070 | public: virtual __thiscall mmMultiCR::~mmMultiCR(void) | ??1mmMultiCR@@UAE@XZ
    0x41C140 | public: int __thiscall mmMultiCR::Init(void) | ?Init@mmMultiCR@@QAEHXZ
    0x41C2A0 | public: virtual void __thiscall mmMultiCR::InitMyPlayer(void) | ?InitMyPlayer@mmMultiCR@@UAEXXZ
    0x41C3A0 | public: virtual void __thiscall mmMultiCR::InitHUD(void) | ?InitHUD@mmMultiCR@@UAEXXZ
    0x41C4E0 | public: virtual void __thiscall mmMultiCR::InitGameObjects(void) | ?InitGameObjects@mmMultiCR@@UAEXXZ
    0x41C940 | public: virtual void __thiscall mmMultiCR::InitNetworkPlayers(void) | ?InitNetworkPlayers@mmMultiCR@@UAEXXZ
    0x41CCC0 | public: virtual void __thiscall mmMultiCR::Reset(void) | ?Reset@mmMultiCR@@UAEXXZ
    0x41CEA0 | public: int __thiscall mmMultiCR::LoadSets(char *) | ?LoadSets@mmMultiCR@@QAEHPAD@Z
    0x41CF40 | public: int __thiscall mmMultiCR::LoadCSV(char *) | ?LoadCSV@mmMultiCR@@QAEHPAD@Z
    0x41D090 | public: void __thiscall mmMultiCR::ImpactCallback(void) | ?ImpactCallback@mmMultiCR@@QAEXXZ
    0x41D180 | public: void __thiscall mmMultiCR::FondleCarMass(class mmCar *,float) | ?FondleCarMass@mmMultiCR@@QAEXPAVmmCar@@M@Z
    0x41D1A0 | public: void __thiscall mmMultiCR::ChangePlayerData(void) | ?ChangePlayerData@mmMultiCR@@QAEXXZ
    0x41D1F0 | private: int __thiscall mmMultiCR::GetRandomIndex(void) | ?GetRandomIndex@mmMultiCR@@AAEHXZ
    0x41D210 | public: void __thiscall mmMultiCR::ResetPositions(int) | ?ResetPositions@mmMultiCR@@QAEXH@Z
    0x41D330 | private: int __thiscall mmMultiCR::SelectTeams(void) | ?SelectTeams@mmMultiCR@@AAEHXZ
    0x41D340 | public: virtual void __thiscall mmMultiCR::UpdateGameInput(int) | ?UpdateGameInput@mmMultiCR@@UAEXH@Z
    0x41D380 | public: virtual void __thiscall mmMultiCR::UpdateGame(void) | ?UpdateGame@mmMultiCR@@UAEXXZ
    0x41D760 | public: virtual void __thiscall mmMultiCR::HitWaterHandler(void) | ?HitWaterHandler@mmMultiCR@@UAEXXZ
    0x41D810 | public: virtual void __thiscall mmMultiCR::DropThruCityHandler(void) | ?DropThruCityHandler@mmMultiCR@@UAEXXZ
    0x41D8C0 | private: void __thiscall mmMultiCR::StealGold(class mmCar *) | ?StealGold@mmMultiCR@@AAEXPAVmmCar@@@Z
    0x41D900 | private: void __thiscall mmMultiCR::OppStealGold(int) | ?OppStealGold@mmMultiCR@@AAEXH@Z
    0x41D970 | private: void __thiscall mmMultiCR::FindGround(class Vector3,class Vector3 &) | ?FindGround@mmMultiCR@@AAEXVVector3@@AAV2@@Z
    0x41DA30 | private: void __thiscall mmMultiCR::DropGold(class Vector3,int) | ?DropGold@mmMultiCR@@AAEXVVector3@@H@Z
    0x41DC20 | private: void __thiscall mmMultiCR::UpdateGold(void) | ?UpdateGold@mmMultiCR@@AAEXXZ
    0x41DE50 | private: void __thiscall mmMultiCR::UpdateHideout(void) | ?UpdateHideout@mmMultiCR@@AAEXXZ
    0x41DFA0 | private: void __thiscall mmMultiCR::UpdateBank(void) | ?UpdateBank@mmMultiCR@@AAEXXZ
    0x41E0F0 | private: void __thiscall mmMultiCR::UpdateLimit(void) | ?UpdateLimit@mmMultiCR@@AAEXXZ
    0x41E290 | private: void __thiscall mmMultiCR::FillResults(void) | ?FillResults@mmMultiCR@@AAEXXZ
    0x41E490 | public: virtual void __thiscall mmMultiCR::SystemMessage(struct NETSYS_MSG *) | ?SystemMessage@mmMultiCR@@UAEXPAUNETSYS_MSG@@@Z
    0x41E6E0 | public: virtual void __thiscall mmMultiCR::GameMessage(struct NETGAME_MSG *) | ?GameMessage@mmMultiCR@@UAEXPAUNETGAME_MSG@@@Z
    0x41EFC0 | private: void __thiscall mmMultiCR::UpdateTimeWarning(void) | ?UpdateTimeWarning@mmMultiCR@@AAEXXZ
    0x41F130 | private: void __thiscall mmMultiCR::DisplayTimeWarning(int) | ?DisplayTimeWarning@mmMultiCR@@AAEXH@Z
    0x41F1C0 | private: void __thiscall mmMultiCR::SendGameState(unsigned long) | ?SendGameState@mmMultiCR@@AAEXK@Z
    0x41F260 | private: void __thiscall mmMultiCR::SendSetup(unsigned long) | ?SendSetup@mmMultiCR@@AAEXK@Z
    0x41F270 | private: void __thiscall mmMultiCR::SendGoldDrop(class Vector3) | ?SendGoldDrop@mmMultiCR@@AAEXVVector3@@@Z
    0x41F2C0 | private: void __thiscall mmMultiCR::SendGoldAck(unsigned long) | ?SendGoldAck@mmMultiCR@@AAEXK@Z
    0x41F300 | private: void __thiscall mmMultiCR::SendGoldDeliver(void) | ?SendGoldDeliver@mmMultiCR@@AAEXXZ
    0x41F350 | private: void __thiscall mmMultiCR::SendChangeSet(int) | ?SendChangeSet@mmMultiCR@@AAEXH@Z
    0x41F390 | private: void __thiscall mmMultiCR::SendLimitReached(int) | ?SendLimitReached@mmMultiCR@@AAEXH@Z
    0x41F3D0 | private: void __thiscall mmMultiCR::SendTimeWarning(int) | ?SendTimeWarning@mmMultiCR@@AAEXH@Z
    0x41F410 | private: void __thiscall mmMultiCR::UpdateHUD(void) | ?UpdateHUD@mmMultiCR@@AAEXXZ
    0x41F530 | private: void __thiscall mmMultiCR::Score(int) | ?Score@mmMultiCR@@AAEXH@Z
    0x41F560 | public: virtual void __thiscall mmMultiCR::UpdateDebugKeyInput(int) | ?UpdateDebugKeyInput@mmMultiCR@@UAEXH@Z
    0x41F570 | private: void __thiscall mmMultiCR::CycleInterest(int) | ?CycleInterest@mmMultiCR@@AAEXH@Z
    0x41F5E0 | public: static void __cdecl mmMultiCR::DeclareFields(void) | ?DeclareFields@mmMultiCR@@SAXXZ
    0x41F760 | public: virtual class MetaClass * __thiscall mmMultiCR::GetClass(void) | ?GetClass@mmMultiCR@@UAEPAVMetaClass@@XZ
    0x41F8C0 | public: virtual void * __thiscall mmMultiCR::`vector deleting destructor'(unsigned int) | ??_EmmMultiCR@@UAEPAXI@Z
    0x41F920 | public: virtual class mmWaypoints * __thiscall mmMultiCR::GetWaypoints(void) | ?GetWaypoints@mmMultiCR@@UAEPAVmmWaypoints@@XZ
    0x61A960 | const mmMultiCR::`vftable' | ??_7mmMultiCR@@6B@
    0x6A7210 | class MetaClass mmMultiCRMetaClass | ?mmMultiCRMetaClass@@3VMetaClass@@A
    0x6A7240 | int TwoPlayers | ?TwoPlayers@@3HA
*/

#include "gamemulti.h"

class mmMultiCR : public mmGameMulti
{
    // const mmMultiCR::`vftable' @ 0x61A960

public:
    // 0x41BFB0 | ??0mmMultiCR@@QAE@XZ
    ARTS_IMPORT mmMultiCR();

    // 0x41F8C0 | ??_EmmMultiCR@@UAEPAXI@Z
    // 0x41C070 | ??1mmMultiCR@@UAE@XZ
    ARTS_IMPORT ~mmMultiCR() override;

    // 0x41D1A0 | ?ChangePlayerData@mmMultiCR@@QAEXXZ
    ARTS_IMPORT void ChangePlayerData();

    // 0x41D810 | ?DropThruCityHandler@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void DropThruCityHandler() override;

    // 0x41D180 | ?FondleCarMass@mmMultiCR@@QAEXPAVmmCar@@M@Z
    ARTS_IMPORT void FondleCarMass(class mmCar* arg1, f32 arg2);

    // 0x41E6E0 | ?GameMessage@mmMultiCR@@UAEXPAUNETGAME_MSG@@@Z
    ARTS_IMPORT void GameMessage(struct NETGAME_MSG* arg1) override;

    // 0x41F760 | ?GetClass@mmMultiCR@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x41F920 | ?GetWaypoints@mmMultiCR@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_EXPORT class mmWaypoints* GetWaypoints() override;

    // 0x41D760 | ?HitWaterHandler@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void HitWaterHandler() override;

    // 0x41D090 | ?ImpactCallback@mmMultiCR@@QAEXXZ
    ARTS_IMPORT void ImpactCallback();

    // 0x41C140 | ?Init@mmMultiCR@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // 0x41C4E0 | ?InitGameObjects@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void InitGameObjects() override;

    // 0x41C3A0 | ?InitHUD@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void InitHUD() override;

    // 0x41C2A0 | ?InitMyPlayer@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void InitMyPlayer() override;

    // 0x41C940 | ?InitNetworkPlayers@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void InitNetworkPlayers() override;

    // 0x41CF40 | ?LoadCSV@mmMultiCR@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadCSV(char* arg1);

    // 0x41CEA0 | ?LoadSets@mmMultiCR@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadSets(char* arg1);

    // 0x41CCC0 | ?Reset@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x41D210 | ?ResetPositions@mmMultiCR@@QAEXH@Z
    ARTS_IMPORT void ResetPositions(i32 arg1);

    // 0x41E490 | ?SystemMessage@mmMultiCR@@UAEXPAUNETSYS_MSG@@@Z
    ARTS_IMPORT void SystemMessage(struct NETSYS_MSG* arg1) override;

    // 0x41F560 | ?UpdateDebugKeyInput@mmMultiCR@@UAEXH@Z
    ARTS_EXPORT void UpdateDebugKeyInput(i32 arg1) override;

    // 0x41D380 | ?UpdateGame@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // 0x41D340 | ?UpdateGameInput@mmMultiCR@@UAEXH@Z
    ARTS_IMPORT void UpdateGameInput(i32 arg1) override;

    // 0x41F5E0 | ?DeclareFields@mmMultiCR@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // 0x41F570 | ?CycleInterest@mmMultiCR@@AAEXH@Z | unused
    ARTS_IMPORT void CycleInterest(i32 arg1);

    // 0x41F130 | ?DisplayTimeWarning@mmMultiCR@@AAEXH@Z
    ARTS_IMPORT void DisplayTimeWarning(i32 arg1);

    // 0x41DA30 | ?DropGold@mmMultiCR@@AAEXVVector3@@H@Z
    ARTS_IMPORT void DropGold(class Vector3 arg1, i32 arg2);

    // 0x41E290 | ?FillResults@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void FillResults();

    // 0x41D970 | ?FindGround@mmMultiCR@@AAEXVVector3@@AAV2@@Z
    ARTS_IMPORT void FindGround(class Vector3 arg1, class Vector3& arg2);

    // 0x41D1F0 | ?GetRandomIndex@mmMultiCR@@AAEHXZ
    ARTS_IMPORT i32 GetRandomIndex();

    // 0x41D900 | ?OppStealGold@mmMultiCR@@AAEXH@Z
    ARTS_IMPORT void OppStealGold(i32 arg1);

    // 0x41F530 | ?Score@mmMultiCR@@AAEXH@Z
    ARTS_IMPORT void Score(i32 arg1);

    // 0x41D330 | ?SelectTeams@mmMultiCR@@AAEHXZ | unused
    ARTS_EXPORT i32 SelectTeams();

    // 0x41F350 | ?SendChangeSet@mmMultiCR@@AAEXH@Z | unused
    ARTS_IMPORT void SendChangeSet(i32 arg1);

    // 0x41F1C0 | ?SendGameState@mmMultiCR@@AAEXK@Z
    ARTS_IMPORT void SendGameState(u32 arg1);

    // 0x41F2C0 | ?SendGoldAck@mmMultiCR@@AAEXK@Z
    ARTS_IMPORT void SendGoldAck(u32 arg1);

    // 0x41F300 | ?SendGoldDeliver@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void SendGoldDeliver();

    // 0x41F270 | ?SendGoldDrop@mmMultiCR@@AAEXVVector3@@@Z
    ARTS_IMPORT void SendGoldDrop(class Vector3 arg1);

    // 0x41F390 | ?SendLimitReached@mmMultiCR@@AAEXH@Z
    ARTS_IMPORT void SendLimitReached(i32 arg1);

    // 0x41F260 | ?SendSetup@mmMultiCR@@AAEXK@Z | unused
    ARTS_EXPORT void SendSetup(u32 arg1);

    // 0x41F3D0 | ?SendTimeWarning@mmMultiCR@@AAEXH@Z
    ARTS_IMPORT void SendTimeWarning(i32 arg1);

    // 0x41D8C0 | ?StealGold@mmMultiCR@@AAEXPAVmmCar@@@Z
    ARTS_IMPORT void StealGold(class mmCar* arg1);

    // 0x41DFA0 | ?UpdateBank@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void UpdateBank();

    // 0x41DC20 | ?UpdateGold@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void UpdateGold();

    // 0x41F410 | ?UpdateHUD@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void UpdateHUD();

    // 0x41DE50 | ?UpdateHideout@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void UpdateHideout();

    // 0x41E0F0 | ?UpdateLimit@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void UpdateLimit();

    // 0x41EFC0 | ?UpdateTimeWarning@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void UpdateTimeWarning();

    u8 gap1EEA8[0x88];
};

check_size(mmMultiCR, 0x1EF30);

// 0x6A7240 | ?TwoPlayers@@3HA
ARTS_IMPORT extern i32 TwoPlayers;

// 0x6A7210 | ?mmMultiCRMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmMultiCRMetaClass;
