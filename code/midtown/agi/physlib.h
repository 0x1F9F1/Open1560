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
    agi:physlib

    0x557120 | public: __thiscall agiLib<class agiPhysParameters,class agiPhysDef>::agiLib<class agiPhysParameters,class agiPhysDef>(void) | ??0?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAE@XZ
    0x557150 | public: __thiscall agiLib<class agiPhysParameters,class agiPhysDef>::~agiLib<class agiPhysParameters,class agiPhysDef>(void) | ??1?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAE@XZ
    0x8FAFE8 | class agiLib<class agiPhysParameters,class agiPhysDef> agiPhysLib | ?agiPhysLib@@3V?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@A
*/

class agiLib<class agiPhysParameters, class agiPhysDef>
{
public:
    // 0x557120 | ??0?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAE@XZ | inline
    ARTS_IMPORT agiLib<class agiPhysParameters, class agiPhysDef>();

    // 0x557150 | ??1?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAE@XZ | inline
    ARTS_IMPORT ~agiLib<class agiPhysParameters, class agiPhysDef>();

    // 0x559EF0 | ?Add@?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAEHAAVagiPhysParameters@@@Z | inline
    ARTS_IMPORT i32 Add(class agiPhysParameters& arg1);

    // 0x55A290 | ?Init@?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAEXH@Z | inline
    ARTS_IMPORT void Init(i32 arg1);

    // 0x55A250 | ?Kill@?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAEXXZ | inline
    ARTS_IMPORT void Kill();
};

check_size(agiLib<class agiPhysParameters, class agiPhysDef>, 0x4014);

// 0x8FAFE8 | ?agiPhysLib@@3V?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@A
ARTS_IMPORT extern class agiLib<class agiPhysParameters, class agiPhysDef> agiPhysLib;
