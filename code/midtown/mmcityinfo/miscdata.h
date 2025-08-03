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

class mmRecord;

class mmMiscData final : public mmInfoBase
{
public:
    // ??0mmMiscData@@QAE@XZ
    ARTS_IMPORT mmMiscData();

    // ??1mmMiscData@@UAE@XZ
    ARTS_IMPORT ~mmMiscData() override;

    // ?CheckBlitz@mmMiscData@@QAEHPADMH0HH@Z
    ARTS_IMPORT i32 CheckBlitz(char* arg1, f32 arg2, i32 arg3, char* arg4, i32 arg5, i32 arg6);

    // ?CheckCheckpoint@mmMiscData@@QAEHPADMH0HH@Z
    ARTS_IMPORT i32 CheckCheckpoint(char* arg1, f32 arg2, i32 arg3, char* arg4, i32 arg5, i32 arg6);

    // ?CheckCircuit@mmMiscData@@QAEHPADMH0HH@Z
    ARTS_IMPORT i32 CheckCircuit(char* arg1, f32 arg2, i32 arg3, char* arg4, i32 arg5, i32 arg6);

    // ?GetBestBlitzScore@mmMiscData@@QAE?AVmmRecord@@HH@Z
    ARTS_IMPORT mmRecord GetBestBlitzScore(i32 arg1, i32 arg2);

    // ?GetBestBlitzTime@mmMiscData@@QAE?AVmmRecord@@HH@Z
    ARTS_IMPORT mmRecord GetBestBlitzTime(i32 arg1, i32 arg2);

    // ?GetBestCircuitScore@mmMiscData@@QAE?AVmmRecord@@HH@Z
    ARTS_IMPORT mmRecord GetBestCircuitScore(i32 arg1, i32 arg2);

    // ?GetBestCircuitTime@mmMiscData@@QAE?AVmmRecord@@HH@Z
    ARTS_IMPORT mmRecord GetBestCircuitTime(i32 arg1, i32 arg2);

    // ?GetBestRaceScore@mmMiscData@@QAE?AVmmRecord@@HH@Z
    ARTS_IMPORT mmRecord GetBestRaceScore(i32 arg1, i32 arg2);

    // ?GetBestRaceTime@mmMiscData@@QAE?AVmmRecord@@HH@Z
    ARTS_IMPORT mmRecord GetBestRaceTime(i32 arg1, i32 arg2);

    // ?GetClass@mmMiscData@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Load@mmMiscData@@QAEHPAD@Z
    ARTS_IMPORT i32 Load(char* arg1);

    // ?LoadBinary@mmMiscData@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadBinary(char* arg1);

    // ?Save@mmMiscData@@QAEHPADH@Z
    ARTS_IMPORT i32 Save(char* arg1, i32 arg2);

    // ?SaveBinary@mmMiscData@@QAEHPAD@Z
    ARTS_IMPORT i32 SaveBinary(char* arg1);

    // ?DeclareFields@mmMiscData@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0x17340];
};

check_size(mmMiscData, 0x173C8);
