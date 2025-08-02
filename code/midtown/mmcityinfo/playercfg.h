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

#include "infobase.h"

class mmPlayerConfig final : public mmInfoBase
{
public:
    // ??0mmPlayerConfig@@QAE@XZ
    ARTS_IMPORT mmPlayerConfig();

    // ??_EmmPlayerConfig@@UAEPAXI@Z
    // ??1mmPlayerConfig@@UAE@XZ
    ARTS_IMPORT ~mmPlayerConfig() override;

    // ?DefaultAudio@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void DefaultAudio();

    // ?DefaultControls@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void DefaultControls();

    // ?DefaultViewSettings@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void DefaultViewSettings();

    // ?GetAudio@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void GetAudio();

    // ?GetClass@mmPlayerConfig@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetControls@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void GetControls();

    // ?GetGraphics@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void GetGraphics();

    // ?GetViewSettings@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void GetViewSettings();

    // ?Load@mmPlayerConfig@@QAEHPAD@Z
    ARTS_IMPORT i32 Load(char* arg1);

    // ?LoadBinary@mmPlayerConfig@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadBinary(char* arg1);

    // ?Reset@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void Reset();

    // ?Save@mmPlayerConfig@@QAEHPADH@Z
    ARTS_IMPORT b32 Save(char* path, b32 binary);

    // ?SaveBinary@mmPlayerConfig@@QAEHPAD@Z
    ARTS_IMPORT i32 SaveBinary(char* arg1);

    // ?SetAudio@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void SetAudio();

    // ?SetControls@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void SetControls();

    // ?SetGraphics@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void SetGraphics();

    // ?SetViewSettings@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void SetViewSettings();

    // ?DeclareFields@mmPlayerConfig@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    alignas(8) u8 gap88[0x6DA8];
};

check_size(mmPlayerConfig, 0x6E30);

struct mmGfxCFG
{
public:
    // ?Get@mmGfxCFG@@QAEXXZ
    ARTS_IMPORT void Get();

    // ?Set@mmGfxCFG@@QAEXXZ
    ARTS_IMPORT void Set();

    u8 gap0[0x34];
};

check_size(mmGfxCFG, 0x34);

struct mmCtrlCFG
{
public:
    // ??1mmCtrlCFG@@QAE@XZ | inline
    ARTS_IMPORT ~mmCtrlCFG();

    u8 gap0[0x6C80];
};

check_size(mmCtrlCFG, 0x6C80);
