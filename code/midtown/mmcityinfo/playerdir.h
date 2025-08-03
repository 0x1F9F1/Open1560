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

class mmPlayerDirectory final : public mmInfoBase
{
public:
    // ??0mmPlayerDirectory@@QAE@XZ
    ARTS_IMPORT mmPlayerDirectory();

    // ??1mmPlayerDirectory@@UAE@XZ
    ARTS_IMPORT ~mmPlayerDirectory() override;

    // ?AddPlayer@mmPlayerDirectory@@QAEHPAD@Z
    ARTS_IMPORT i32 AddPlayer(char* arg1);

    // ?FindPlayer@mmPlayerDirectory@@QAEHPAD@Z
    ARTS_IMPORT i32 FindPlayer(char* arg1);

    // ?GetClass@mmPlayerDirectory@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetFileName@mmPlayerDirectory@@QAEPADPAD@Z
    ARTS_IMPORT char* GetFileName(char* arg1);

    // ?GetFileName@mmPlayerDirectory@@QAEPADH@Z
    ARTS_IMPORT char* GetFileName(i32 arg1);

    // ?GetLastPlayer@mmPlayerDirectory@@QAEPADXZ
    ARTS_IMPORT char* GetLastPlayer();

    // ?GetNumPlayers@mmPlayerDirectory@@QAEHXZ
    ARTS_IMPORT i32 GetNumPlayers();

    // ?GetPlayer@mmPlayerDirectory@@QAEPADH@Z
    ARTS_IMPORT char* GetPlayer(i32 arg1);

    // ?Load@mmPlayerDirectory@@QAEHPAD@Z
    ARTS_IMPORT i32 Load(char* arg1);

    // ?LoadBinary@mmPlayerDirectory@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadBinary(char* arg1);

    // ?NewDirectory@mmPlayerDirectory@@QAEXH@Z
    ARTS_IMPORT void NewDirectory(i32 arg1);

    // ?RemovePlayer@mmPlayerDirectory@@QAEHPAD@Z
    ARTS_IMPORT i32 RemovePlayer(char* arg1);

    // ?Save@mmPlayerDirectory@@QAEHPADH@Z
    ARTS_IMPORT i32 Save(char* arg1, i32 arg2);

    // ?SaveBinary@mmPlayerDirectory@@QAEHPAD@Z
    ARTS_IMPORT i32 SaveBinary(char* arg1);

    // ?SetLastPlayer@mmPlayerDirectory@@QAEXPAD@Z
    ARTS_IMPORT void SetLastPlayer(char* arg1);

    // ?SetPlayer@mmPlayerDirectory@@QAEXHPAD0@Z
    ARTS_IMPORT void SetPlayer(i32 arg1, char* arg2, char* arg3);

    // ?DeclareFields@mmPlayerDirectory@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?MakeFileName@mmPlayerDirectory@@AAEPADXZ
    ARTS_IMPORT char* MakeFileName();

    u8 gap88[0x5C];
};

check_size(mmPlayerDirectory, 0xE4);

// ?RefTo@@YAPAUMetaType@@PAU1@HPAH@Z | inline
// ARTS_IMPORT MetaType* RefTo(MetaType* arg1, i32 arg2, i32* arg3);
