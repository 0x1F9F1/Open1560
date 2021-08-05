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
    agiworld:meshlight

    0x510640 | void __cdecl agiMeshLighterReset(void) | ?agiMeshLighterReset@@YAXXZ
    0x510730 | void __cdecl agiMeshLighterQuarter(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *) | ?agiMeshLighterQuarter@@YAXPAEPAI1PAVagiMeshSet@@@Z
    0x5108F0 | void __cdecl agiMeshLighterUpdateColors(void) | ?agiMeshLighterUpdateColors@@YAXXZ
    0x510AE0 | void __cdecl agiMeshLighterTriple(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *) | ?agiMeshLighterTriple@@YAXPAEPAI1PAVagiMeshSet@@@Z
    0x510EE0 | void __cdecl mmxTriple(unsigned int *,unsigned int *,int,unsigned char *,int) | ?mmxTriple@@YAXPAI0HPAEH@Z
    0x511010 | void __cdecl agiMeshPrelight(unsigned int *,class agiMeshSet *,class Matrix34 &) | ?agiMeshPrelight@@YAXPAIPAVagiMeshSet@@AAVMatrix34@@@Z
    0x5111E0 | void __cdecl agiBeginCones(void) | ?agiBeginCones@@YAXXZ
    0x5111F0 | void __cdecl agiDeclareCone(class Vector3 &,class Vector3 &,class Vector3 &,float,float,class Vector3 &,int) | ?agiDeclareCone@@YAXAAVVector3@@00MM0H@Z
    0x5112C0 | void __cdecl agiConeLighter(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *) | ?agiConeLighter@@YAXPAEPAI1PAVagiMeshSet@@@Z
    0x5116B0 | void __cdecl agiInitCones(class Matrix34 &,float) | ?agiInitCones@@YAXAAVMatrix34@@M@Z
    0x5118F0 | void __cdecl agiDrawCones(void) | ?agiDrawCones@@YAXXZ
    0x5119F0 | void __cdecl agiMeshLighterSpecular(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *) | ?agiMeshLighterSpecular@@YAXPAEPAI1PAVagiMeshSet@@@Z
    0x64ABB8 | float agiMeshLighterMin | ?agiMeshLighterMin@@3MA
    0x64ABBC | float agiMeshLighterMax | ?agiMeshLighterMax@@3MA
    0x64ABC0 | float agiMeshLighterConeRange2 | ?agiMeshLighterConeRange2@@3MA
    0x64ABC8 | float agiMeshLighterSpecularExponent | ?agiMeshLighterSpecularExponent@@3MA
    0x73D3D8 | union mmx minus1 | ?minus1@@3Tmmx@@A
    0x73D3E0 | class Vector3 agiMeshLighterSunColor | ?agiMeshLighterSunColor@@3VVector3@@A
    0x73D3F0 | union mmx zero | ?zero@@3Tmmx@@A
    0x73D3F8 | union mmx keyColor | ?keyColor@@3Tmmx@@A
    0x73E618 | class Vector3 agiMeshLighterSun | ?agiMeshLighterSun@@3VVector3@@A
    0x73E628 | class Vector3 agiMeshLighterFill1 | ?agiMeshLighterFill1@@3VVector3@@A
    0x73E638 | class Vector3 agiMeshLighterFill2 | ?agiMeshLighterFill2@@3VVector3@@A
    0x73E648 | class Vector3 agiMeshLighterSpecularColor | ?agiMeshLighterSpecularColor@@3VVector3@@A
    0x73E658 | union mmx unclampSSS_3_10 | ?unclampSSS_3_10@@3Tmmx@@A
    0x73E660 | class Vector3 agiMeshLighterAmbient | ?agiMeshLighterAmbient@@3VVector3@@A
    0x73E670 | union mmx ambColor | ?ambColor@@3Tmmx@@A
    0x73E678 | union mmx clampSSS_3_10 | ?clampSSS_3_10@@3Tmmx@@A
    0x73E680 | union mmx fill1Color | ?fill1Color@@3Tmmx@@A
    0x73E688 | class Vector3 agiMeshLighterFill2Color | ?agiMeshLighterFill2Color@@3VVector3@@A
    0x73E6A8 | class Vector3 agiMeshLighterFill1Color | ?agiMeshLighterFill1Color@@3VVector3@@A
    0x73E6B8 | union mmx fill2Color | ?fill2Color@@3Tmmx@@A
*/

// ?agiBeginCones@@YAXXZ
ARTS_IMPORT void agiBeginCones();

// ?agiConeLighter@@YAXPAEPAI1PAVagiMeshSet@@@Z
ARTS_IMPORT void agiConeLighter(u8* arg1, u32* arg2, u32* arg3, class agiMeshSet* arg4);

// ?agiDeclareCone@@YAXAAVVector3@@00MM0H@Z
ARTS_IMPORT void agiDeclareCone(
    class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, f32 arg5, class Vector3& arg6, i32 arg7);

// ?agiDrawCones@@YAXXZ | unused
ARTS_IMPORT void agiDrawCones();

// ?agiMeshLighterQuarter@@YAXPAEPAI1PAVagiMeshSet@@@Z
ARTS_IMPORT void agiMeshLighterQuarter(u8* arg1, u32* arg2, u32* arg3, class agiMeshSet* arg4);

// ?agiMeshLighterReset@@YAXXZ
ARTS_IMPORT void agiMeshLighterReset();

// ?agiMeshLighterSpecular@@YAXPAEPAI1PAVagiMeshSet@@@Z | unused
ARTS_IMPORT void agiMeshLighterSpecular(u8* arg1, u32* arg2, u32* arg3, class agiMeshSet* arg4);

// ?agiMeshLighterTriple@@YAXPAEPAI1PAVagiMeshSet@@@Z
ARTS_EXPORT void agiMeshLighterTriple(
    u8* ARTS_RESTRICT codes, u32* ARTS_RESTRICT output, u32* ARTS_RESTRICT colors, class agiMeshSet* mesh);

// ?agiMeshLighterUpdateColors@@YAXXZ
ARTS_IMPORT void agiMeshLighterUpdateColors();

// ?agiMeshPrelight@@YAXPAIPAVagiMeshSet@@AAVMatrix34@@@Z | unused
ARTS_IMPORT void agiMeshPrelight(u32* arg1, class agiMeshSet* arg2, class Matrix34& arg3);

// ?agiMeshLighterAmbient@@3VVector3@@A
ARTS_IMPORT extern class Vector3 agiMeshLighterAmbient;

// ?agiMeshLighterConeRange2@@3MA
ARTS_IMPORT extern f32 agiMeshLighterConeRange2;

// ?agiMeshLighterFill1@@3VVector3@@A
ARTS_IMPORT extern class Vector3 agiMeshLighterFill1;

// ?agiMeshLighterFill1Color@@3VVector3@@A
ARTS_IMPORT extern class Vector3 agiMeshLighterFill1Color;

// ?agiMeshLighterFill2@@3VVector3@@A
ARTS_IMPORT extern class Vector3 agiMeshLighterFill2;

// ?agiMeshLighterFill2Color@@3VVector3@@A
ARTS_IMPORT extern class Vector3 agiMeshLighterFill2Color;

// ?agiMeshLighterMax@@3MA
ARTS_IMPORT extern f32 agiMeshLighterMax;

// ?agiMeshLighterMin@@3MA
ARTS_IMPORT extern f32 agiMeshLighterMin;

// ?agiMeshLighterSpecularColor@@3VVector3@@A
ARTS_IMPORT extern class Vector3 agiMeshLighterSpecularColor;

// ?agiMeshLighterSpecularExponent@@3MA
ARTS_IMPORT extern f32 agiMeshLighterSpecularExponent;

// ?agiMeshLighterSun@@3VVector3@@A
ARTS_IMPORT extern class Vector3 agiMeshLighterSun;

// ?agiMeshLighterSunColor@@3VVector3@@A
ARTS_IMPORT extern class Vector3 agiMeshLighterSunColor;

// ?ambColor@@3Tmmx@@A
ARTS_IMPORT extern union mmx ambColor;

// ?clampSSS_3_10@@3Tmmx@@A
ARTS_IMPORT extern union mmx clampSSS_3_10;

// ?fill1Color@@3Tmmx@@A
ARTS_IMPORT extern union mmx fill1Color;

// ?fill2Color@@3Tmmx@@A
ARTS_IMPORT extern union mmx fill2Color;

// ?keyColor@@3Tmmx@@A
ARTS_IMPORT extern union mmx keyColor;

// ?minus1@@3Tmmx@@A
ARTS_IMPORT extern union mmx minus1;

// ?unclampSSS_3_10@@3Tmmx@@A
ARTS_IMPORT extern union mmx unclampSSS_3_10;

// ?zero@@3Tmmx@@A
ARTS_IMPORT extern union mmx zero;
