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

#include "arts7/node.h"

enum class mmCRGameClass : i32;
class asLinearCS;

class mmWPHUD final : public asNode
{
public:
    // ??0mmWPHUD@@QAE@XZ
    ARTS_IMPORT mmWPHUD();

    // ??_GmmWPHUD@@UAEPAXI@Z
    // ??_EmmWPHUD@@UAEPAXI@Z
    // ??1mmWPHUD@@UAE@XZ
    ARTS_IMPORT ~mmWPHUD() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmWPHUD@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@mmWPHUD@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?Init@mmWPHUD@@QAEXHPAH0H@Z
    ARTS_IMPORT void Init(i32 arg1, i32* arg2, i32* arg3, i32 arg4);

    // ?Reset@mmWPHUD@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetStandings@mmWPHUD@@QAEXHH@Z
    ARTS_IMPORT void SetStandings(i32 arg1, i32 arg2);

    // ?SetWPCleared@mmWPHUD@@QAEXXZ
    ARTS_IMPORT void SetWPCleared();

    // ?Update@mmWPHUD@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x78];
};

check_size(mmWPHUD, 0x98);

class mmCircuitHUD final : public asNode
{
public:
    // ??0mmCircuitHUD@@QAE@XZ
    ARTS_IMPORT mmCircuitHUD();

    // ??_EmmCircuitHUD@@UAEPAXI@Z
    // ??_GmmCircuitHUD@@UAEPAXI@Z
    // ??1mmCircuitHUD@@UAE@XZ
    ARTS_IMPORT ~mmCircuitHUD() override;

    // ?Init@mmCircuitHUD@@QAEXXZ
    ARTS_IMPORT void Init();

    // ?Reset@mmCircuitHUD@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetLapTime@mmCircuitHUD@@QAEXHMPADH@Z
    ARTS_IMPORT void SetLapTime(i32 arg1, f32 arg2, char* arg3, i32 arg4);

    // ?SetStandings@mmCircuitHUD@@QAEXHH@Z
    ARTS_IMPORT void SetStandings(i32 arg1, i32 arg2);

    // ?SetWPCleared@mmCircuitHUD@@QAEXHH@Z
    ARTS_IMPORT void SetWPCleared(i32 arg1, i32 arg2);

    // ?Update@mmCircuitHUD@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x7C];
};

check_size(mmCircuitHUD, 0x9C);

class mmCRHUD final : public asNode
{
public:
    // ??0mmCRHUD@@QAE@XZ
    ARTS_IMPORT mmCRHUD();

    // ??_EmmCRHUD@@UAEPAXI@Z
    // ??_GmmCRHUD@@UAEPAXI@Z
    // ??1mmCRHUD@@UAE@XZ
    ARTS_IMPORT ~mmCRHUD() override;

    // ?ActivateGold@mmCRHUD@@QAEXXZ
    ARTS_IMPORT void ActivateGold();

    // ?ActivateRosterGold@mmCRHUD@@QAEXK@Z
    ARTS_IMPORT void ActivateRosterGold(ulong arg1);

    // ?AddPlayer@mmCRHUD@@QAEXPADKHI@Z
    ARTS_IMPORT void AddPlayer(char* arg1, ulong arg2, i32 arg3, u32 arg4);

    // ?DeactivateGold@mmCRHUD@@QAEXXZ
    ARTS_IMPORT void DeactivateGold();

    // ?DeactivateRosterGold@mmCRHUD@@QAEXXZ
    ARTS_IMPORT void DeactivateRosterGold();

    // ?Init@mmCRHUD@@QAEXPAVasLinearCS@@PADW4mmCRGameClass@@@Z
    ARTS_IMPORT void Init(asLinearCS* arg1, char* arg2, mmCRGameClass arg3);

    // ?RemovePlayer@mmCRHUD@@QAEXK@Z
    ARTS_IMPORT void RemovePlayer(ulong arg1);

    // ?Reset@mmCRHUD@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetBlueScore@mmCRHUD@@QAEXH@Z
    ARTS_IMPORT void SetBlueScore(i32 arg1);

    // ?SetName@mmCRHUD@@QAEXPADH@Z
    ARTS_IMPORT void SetName(char* arg1, i32 arg2);

    // ?SetRedScore@mmCRHUD@@QAEXH@Z
    ARTS_IMPORT void SetRedScore(i32 arg1);

    // ?SetScore@mmCRHUD@@QAEXPAD@Z
    ARTS_IMPORT void SetScore(char* arg1);

    // ?SetScore@mmCRHUD@@QAEXKH@Z
    ARTS_IMPORT void SetScore(ulong arg1, i32 arg2);

    // ?UnPackColor@mmCRHUD@@QAEXIAAVVector4@@@Z
    ARTS_IMPORT void UnPackColor(u32 arg1, Vector4& arg2);

    // ?Update@mmCRHUD@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateGold@mmCRHUD@@QAEXXZ
    ARTS_IMPORT void UpdateGold();

    u8 gap20[0x1F8];
};

check_size(mmCRHUD, 0x218);

// ?fontscalar@@3MA
ARTS_IMPORT extern f32 fontscalar;
