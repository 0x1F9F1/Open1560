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

class agiMeshSet;
union mmx;

// ?agiBeginCones@@YAXXZ
ARTS_IMPORT void agiBeginCones();

// ?agiConeLighter@@YAXPAEPAI1PAVagiMeshSet@@@Z
ARTS_IMPORT void agiConeLighter(u8* arg1, u32* arg2, u32* arg3, agiMeshSet* arg4);

// ?agiDeclareCone@@YAXAAVVector3@@00MM0H@Z
ARTS_IMPORT void agiDeclareCone(
    Vector3& arg1, Vector3& arg2, Vector3& arg3, f32 arg4, f32 arg5, Vector3& arg6, i32 arg7);

// ?agiMeshLighterQuarter@@YAXPAEPAI1PAVagiMeshSet@@@Z
ARTS_IMPORT void agiMeshLighterQuarter(u8* arg1, u32* arg2, u32* arg3, agiMeshSet* arg4);

// ?agiMeshLighterReset@@YAXXZ
ARTS_IMPORT void agiMeshLighterReset();

// ?agiMeshLighterTriple@@YAXPAEPAI1PAVagiMeshSet@@@Z
ARTS_EXPORT void agiMeshLighterTriple(
    u8* ARTS_RESTRICT codes, u32* ARTS_RESTRICT output, u32* ARTS_RESTRICT colors, agiMeshSet* mesh);

// ?agiMeshLighterUpdateColors@@YAXXZ
ARTS_IMPORT void agiMeshLighterUpdateColors();

// ?agiMeshLighterAmbient@@3VVector3@@A
ARTS_IMPORT extern Vector3 agiMeshLighterAmbient;

// ?agiMeshLighterConeRange2@@3MA
ARTS_IMPORT extern f32 agiMeshLighterConeRange2;

// ?agiMeshLighterFill1@@3VVector3@@A
ARTS_IMPORT extern Vector3 agiMeshLighterFill1;

// ?agiMeshLighterFill1Color@@3VVector3@@A
ARTS_IMPORT extern Vector3 agiMeshLighterFill1Color;

// ?agiMeshLighterFill2@@3VVector3@@A
ARTS_IMPORT extern Vector3 agiMeshLighterFill2;

// ?agiMeshLighterFill2Color@@3VVector3@@A
ARTS_IMPORT extern Vector3 agiMeshLighterFill2Color;

// ?agiMeshLighterMax@@3MA
ARTS_IMPORT extern f32 agiMeshLighterMax;

// ?agiMeshLighterMin@@3MA
ARTS_IMPORT extern f32 agiMeshLighterMin;

// ?agiMeshLighterSpecularColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 agiMeshLighterSpecularColor;

// ?agiMeshLighterSpecularExponent@@3MA
ARTS_IMPORT extern f32 agiMeshLighterSpecularExponent;

// ?agiMeshLighterSun@@3VVector3@@A
ARTS_IMPORT extern Vector3 agiMeshLighterSun;

// ?agiMeshLighterSunColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 agiMeshLighterSunColor;

// ?ambColor@@3Tmmx@@A
ARTS_IMPORT extern mmx ambColor;

// ?clampSSS_3_10@@3Tmmx@@A
ARTS_IMPORT extern mmx clampSSS_3_10;

// ?fill1Color@@3Tmmx@@A
ARTS_IMPORT extern mmx fill1Color;

// ?fill2Color@@3Tmmx@@A
ARTS_IMPORT extern mmx fill2Color;

// ?keyColor@@3Tmmx@@A
ARTS_IMPORT extern mmx keyColor;

// ?minus1@@3Tmmx@@A
ARTS_IMPORT extern mmx minus1;

// ?unclampSSS_3_10@@3Tmmx@@A
ARTS_IMPORT extern mmx unclampSSS_3_10;

// ?zero@@3Tmmx@@A
ARTS_IMPORT extern mmx zero;
