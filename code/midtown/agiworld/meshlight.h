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
    0x511010 | void __cdecl agiMeshPrelight(unsigned int *,class agiMeshSet *,class Matrix34 &) | ?agiMeshPrelight@@YAXPAIPAVagiMeshSet@@AAVMatrix34@@@Z
    0x5111E0 | void __cdecl agiBeginCones(void) | ?agiBeginCones@@YAXXZ
    0x5111F0 | void __cdecl agiDeclareCone(class Vector3 &,class Vector3 &,class Vector3 &,float,float,class Vector3 &,int) | ?agiDeclareCone@@YAXAAVVector3@@00MM0H@Z
    0x5112C0 | void __cdecl agiConeLighter(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *) | ?agiConeLighter@@YAXPAEPAI1PAVagiMeshSet@@@Z
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

// 0x5111E0 | ?agiBeginCones@@YAXXZ
void agiBeginCones();

// 0x5112C0 | ?agiConeLighter@@YAXPAEPAI1PAVagiMeshSet@@@Z
void agiConeLighter(u8* arg1, u32* arg2, u32* arg3, class agiMeshSet* arg4);

// 0x5111F0 | ?agiDeclareCone@@YAXAAVVector3@@00MM0H@Z
void agiDeclareCone(
    class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, f32 arg5, class Vector3& arg6, i32 arg7);

// 0x5118F0 | ?agiDrawCones@@YAXXZ
void agiDrawCones();

// 0x510730 | ?agiMeshLighterQuarter@@YAXPAEPAI1PAVagiMeshSet@@@Z
void agiMeshLighterQuarter(u8* arg1, u32* arg2, u32* arg3, class agiMeshSet* arg4);

// 0x510640 | ?agiMeshLighterReset@@YAXXZ
void agiMeshLighterReset();

// 0x5119F0 | ?agiMeshLighterSpecular@@YAXPAEPAI1PAVagiMeshSet@@@Z
void agiMeshLighterSpecular(u8* arg1, u32* arg2, u32* arg3, class agiMeshSet* arg4);

// 0x510AE0 | ?agiMeshLighterTriple@@YAXPAEPAI1PAVagiMeshSet@@@Z
void agiMeshLighterTriple(u8* arg1, u32* arg2, u32* arg3, class agiMeshSet* arg4);

// 0x5108F0 | ?agiMeshLighterUpdateColors@@YAXXZ
void agiMeshLighterUpdateColors();

// 0x511010 | ?agiMeshPrelight@@YAXPAIPAVagiMeshSet@@AAVMatrix34@@@Z
void agiMeshPrelight(u32* arg1, class agiMeshSet* arg2, class Matrix34& arg3);

// 0x73E660 | ?agiMeshLighterAmbient@@3VVector3@@A
inline extern_var(0x73E660, class Vector3, agiMeshLighterAmbient);

// 0x64ABC0 | ?agiMeshLighterConeRange2@@3MA
inline extern_var(0x64ABC0, f32, agiMeshLighterConeRange2);

// 0x73E628 | ?agiMeshLighterFill1@@3VVector3@@A
inline extern_var(0x73E628, class Vector3, agiMeshLighterFill1);

// 0x73E6A8 | ?agiMeshLighterFill1Color@@3VVector3@@A
inline extern_var(0x73E6A8, class Vector3, agiMeshLighterFill1Color);

// 0x73E638 | ?agiMeshLighterFill2@@3VVector3@@A
inline extern_var(0x73E638, class Vector3, agiMeshLighterFill2);

// 0x73E688 | ?agiMeshLighterFill2Color@@3VVector3@@A
inline extern_var(0x73E688, class Vector3, agiMeshLighterFill2Color);

// 0x64ABBC | ?agiMeshLighterMax@@3MA
inline extern_var(0x64ABBC, f32, agiMeshLighterMax);

// 0x64ABB8 | ?agiMeshLighterMin@@3MA
inline extern_var(0x64ABB8, f32, agiMeshLighterMin);

// 0x73E648 | ?agiMeshLighterSpecularColor@@3VVector3@@A
inline extern_var(0x73E648, class Vector3, agiMeshLighterSpecularColor);

// 0x64ABC8 | ?agiMeshLighterSpecularExponent@@3MA
inline extern_var(0x64ABC8, f32, agiMeshLighterSpecularExponent);

// 0x73E618 | ?agiMeshLighterSun@@3VVector3@@A
inline extern_var(0x73E618, class Vector3, agiMeshLighterSun);

// 0x73D3E0 | ?agiMeshLighterSunColor@@3VVector3@@A
inline extern_var(0x73D3E0, class Vector3, agiMeshLighterSunColor);

// 0x73E670 | ?ambColor@@3Tmmx@@A
inline extern_var(0x73E670, union mmx, ambColor);

// 0x73E678 | ?clampSSS_3_10@@3Tmmx@@A
inline extern_var(0x73E678, union mmx, clampSSS_3_10);

// 0x73E680 | ?fill1Color@@3Tmmx@@A
inline extern_var(0x73E680, union mmx, fill1Color);

// 0x73E6B8 | ?fill2Color@@3Tmmx@@A
inline extern_var(0x73E6B8, union mmx, fill2Color);

// 0x73D3F8 | ?keyColor@@3Tmmx@@A
inline extern_var(0x73D3F8, union mmx, keyColor);

// 0x73D3D8 | ?minus1@@3Tmmx@@A
inline extern_var(0x73D3D8, union mmx, minus1);

// 0x73E658 | ?unclampSSS_3_10@@3Tmmx@@A
inline extern_var(0x73E658, union mmx, unclampSSS_3_10);

// 0x73D3F0 | ?zero@@3Tmmx@@A
inline extern_var(0x73D3F0, union mmx, zero);
