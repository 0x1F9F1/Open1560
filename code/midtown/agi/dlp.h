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

#include "refresh.h"

class DLPTemplate;
class DynamicDLP;
class MultipassDLP;

class DLP : public agiRefreshable
{
public:
    // ??0DLP@@QAE@PAVagiPipeline@@@Z
    ARTS_IMPORT DLP(agiPipeline* arg1);

    // ??_GDLP@@UAEPAXI@Z
    // ??_EDLP@@UAEPAXI@Z
    // ??1DLP@@UAE@XZ
    ARTS_IMPORT ~DLP() override;

    // ?Cull@DLP@@UAEXH@Z
    ARTS_IMPORT virtual void Cull(i32 arg1);

    // ?FixROpts@DLP@@UAEXHH@Z
    ARTS_IMPORT virtual void FixROpts(i32 arg1, i32 arg2);

    virtual DynamicDLP* GetDynamic(i32 arg1) = 0;

    virtual MultipassDLP* GetMultipass(i32 arg1) = 0;

    // ?BeginGfx@DLP@@UAEHXZ
    ARTS_IMPORT i32 BeginGfx() override;

    // ?EndGfx@DLP@@UAEXXZ
    ARTS_EXPORT void EndGfx() override;

    // ?GetName@DLP@@UAEPADXZ
    ARTS_IMPORT aconst char* GetName() override;

    // ?Init@DLP@@QAEHPAD0PAVVector3@@@Z
    ARTS_IMPORT i32 Init(char* arg1, char* arg2, Vector3* arg3);

    // ?Init@DLP@@QAEHPAVDLPTemplate@@PADPAVVector3@@@Z
    ARTS_IMPORT i32 Init(DLPTemplate* arg1, char* arg2, Vector3* arg3);

protected:
    // ?FixTemplateRefs@DLP@@IAEXH@Z
    ARTS_IMPORT void FixTemplateRefs(i32 arg1);

    u8 gap18[0x7C];
};

check_size(DLP, 0x94);

// ?DLPHash@@3VHashTable@@A
ARTS_IMPORT extern HashTable DLPHash;
