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

#include "agi/dlp.h"
#include "agi/dyndlp.h"

struct agiPatch;

class RDLP final : public DLP
{
public:
    // ??0RDLP@@QAE@PAVagiPipeline@@@Z
    ARTS_IMPORT RDLP(agiPipeline* arg1);

    // ??1RDLP@@UAE@XZ
    ARTS_IMPORT ~RDLP() override;

    // ?BeginGfx@RDLP@@UAEHXZ
    ARTS_IMPORT i32 BeginGfx() override;

    // ?EndGfx@RDLP@@UAEXXZ
    ARTS_IMPORT void EndGfx() override;

    // ?FixROpts@RDLP@@UAEXHH@Z
    ARTS_IMPORT void FixROpts(i32 arg1, i32 arg2) override;

    // ?GetDynamic@RDLP@@UAEPAVDynamicDLP@@H@Z
    ARTS_IMPORT DynamicDLP* GetDynamic(i32 arg1) override;

    // ?GetMultipass@RDLP@@UAEPAVMultipassDLP@@H@Z
    ARTS_EXPORT MultipassDLP* GetMultipass(i32 arg1) override;

private:
    // ?InitFacet@RDLP@@AAEHPAUagiPatch@@HHHH@Z
    ARTS_IMPORT i32 InitFacet(agiPatch* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5);

    u8 gap94[0x18];
};

check_size(RDLP, 0xAC);

class RDynamicDLP final : public DynamicDLP
{
public:
    // ??0RDynamicDLP@@QAE@HPAVRDLP@@@Z
    ARTS_IMPORT RDynamicDLP(i32 arg1, RDLP* arg2);

    // ??1RDynamicDLP@@UAE@XZ
    ARTS_IMPORT ~RDynamicDLP() override;

    // ?Init@RDynamicDLP@@UAEHPAD@Z
    ARTS_IMPORT i32 Init(char* arg1) override;

    // ?Lock@RDynamicDLP@@UAEXXZ
    ARTS_IMPORT void Lock() override;

    // ?SetTexture@RDynamicDLP@@UAEXF@Z
    ARTS_IMPORT void SetTexture(i16 arg1) override;

    // ?Unlock@RDynamicDLP@@UAEXXZ
    ARTS_IMPORT void Unlock() override;

    u8 gap24[0x4];
};

check_size(RDynamicDLP, 0x28);
