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
    agi:mtllib

    0x55B9B0 | public: __thiscall agiLib<class agiMtlParameters,class agiMtlDef>::agiLib<class agiMtlParameters,class agiMtlDef>(void) | ??0?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAE@XZ
    0x903198 | class agiLib<class agiMtlParameters,class agiMtlDef> agiMtlLib | ?agiMtlLib@@3V?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@A
*/

#include "agilib.h"

#include "mtldef.h"

#if 0
class agiLib<class agiMtlParameters, class agiMtlDef>
{
public:
    // 0x55B9B0 | ??0?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAE@XZ | inline
    ARTS_IMPORT agiLib<class agiMtlParameters, class agiMtlDef>();

    // 0x559CF0 | ??1?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAE@XZ | inline
    ARTS_IMPORT ~agiLib<class agiMtlParameters, class agiMtlDef>();

    // 0x559D90 | ?Add@?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAEHAAVagiMtlParameters@@@Z | inline
    ARTS_IMPORT i32 Add(class agiMtlParameters& arg1);

    // 0x55A080 | ?Init@?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAEXH@Z | inline
    ARTS_IMPORT void Init(i32 arg1);

    // 0x55A030 | ?Kill@?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAEXXZ | inline
    ARTS_IMPORT void Kill();

    u8 gap0[0x4014];
};
#endif

check_size(Ty(agiLib<class agiMtlParameters, class agiMtlDef>), 0x4014);

// 0x903198 | ?agiMtlLib@@3V?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@A
ARTS_IMPORT extern class agiLib<class agiMtlParameters, class agiMtlDef> agiMtlLib;
