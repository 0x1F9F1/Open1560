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
    dyna7:gfx

    0x52D020 | void __cdecl DrawColor(class Vector3 &) | ?DrawColor@@YAXAAVVector3@@@Z
    0x52D080 | void __cdecl DrawColor2(class Vector3 &) | ?DrawColor2@@YAXAAVVector3@@@Z
    0x52D0D0 | void __cdecl DrawColor(class Vector4 &) | ?DrawColor@@YAXAAVVector4@@@Z
    0x52D130 | void __cdecl DrawColor2(class Vector4 &) | ?DrawColor2@@YAXAAVVector4@@@Z
    0x52D190 | void __cdecl DrawLine(float,float,float,float,float,float) | ?DrawLine@@YAXMMMMMM@Z
    0x52D230 | void __cdecl DrawLine(class Vector3 &,class Vector3 &) | ?DrawLine@@YAXAAVVector3@@0@Z
    0x52D260 | void __cdecl DrawTri(class Vector3 *,class Vector3 &,class Vector3 &,class Vector3 &) | ?DrawTri@@YAXPAVVector3@@AAV1@11@Z
    0x52D320 | void __cdecl DrawWireSphere(class Vector3 &,float) | ?DrawWireSphere@@YAXAAVVector3@@M@Z
    0x52D620 | void __cdecl DrawWireSphere(class Vector4 &) | ?DrawWireSphere@@YAXAAVVector4@@@Z
    0x52D640 | void __cdecl DrawWireBox(class Vector3 &,class Vector3 &) | ?DrawWireBox@@YAXAAVVector3@@0@Z
    0x52D800 | void __cdecl DrawBegin(class Matrix34 &) | ?DrawBegin@@YAXAAVMatrix34@@@Z
    0x52D8C0 | void __cdecl DrawQuad(class Vector3 *,class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &) | ?DrawQuad@@YAXPAVVector3@@AAV1@111@Z
    0x52D9C0 | void __cdecl DrawLabelf(class Vector3 &,char *,...) | ?DrawLabelf@@YAXAAVVector3@@PADZZ
    0x52DA30 | void __cdecl DrawEnd(void) | ?DrawEnd@@YAXXZ
    0x7909E0 | class Vector3 ColLightCyan | ?ColLightCyan@@3VVector3@@A
    0x7909F0 | class Vector3 ColCyan | ?ColCyan@@3VVector3@@A
    0x790A60 | class Vector3 ColGreen | ?ColGreen@@3VVector3@@A
    0x790A70 | class Vector3 ColLightGreen | ?ColLightGreen@@3VVector3@@A
    0x790A80 | class Vector3 ColGrey | ?ColGrey@@3VVector3@@A
    0x790A98 | class Vector3 ColBlack | ?ColBlack@@3VVector3@@A
    0x790AA8 | class Vector3 ColDarkRed | ?ColDarkRed@@3VVector3@@A
    0x790AB8 | class Vector3 ColDarkYellow | ?ColDarkYellow@@3VVector3@@A
    0x790AC8 | class Vector3 ColLightPurple | ?ColLightPurple@@3VVector3@@A
    0x790AD8 | class Vector3 ColLightOrange | ?ColLightOrange@@3VVector3@@A
    0x790AE8 | class Vector3 ColLightRed | ?ColLightRed@@3VVector3@@A
    0x790B28 | class Vector3 ColDarkPurple | ?ColDarkPurple@@3VVector3@@A
    0x790B38 | class Vector3 ColDarkBlue | ?ColDarkBlue@@3VVector3@@A
    0x790B48 | class Vector3 ColDarkOrange | ?ColDarkOrange@@3VVector3@@A
    0x790B58 | class Vector3 ColDarkCyan | ?ColDarkCyan@@3VVector3@@A
    0x790B68 | class Vector3 ColPurple | ?ColPurple@@3VVector3@@A
    0x790B78 | class Vector3 ColDarkGreen | ?ColDarkGreen@@3VVector3@@A
    0x790BA8 | class Vector3 ColYellow | ?ColYellow@@3VVector3@@A
    0x790BB8 | class Vector3 ColRed | ?ColRed@@3VVector3@@A
    0x790BC8 | class Vector3 ColLightYellow | ?ColLightYellow@@3VVector3@@A
    0x790C18 | class Vector3 ColLightBlue | ?ColLightBlue@@3VVector3@@A
    0x790C28 | class Vector3 ColOrange | ?ColOrange@@3VVector3@@A
    0x790CB8 | class Vector3 ColBlue | ?ColBlue@@3VVector3@@A
    0x790CC8 | class Vector3 ColWhite | ?ColWhite@@3VVector3@@A
*/

#ifdef ARTS_DEV_BUILD
// ?DrawBegin@@YAXAAVMatrix34@@@Z
ARTS_IMPORT void DrawBegin(aconst Matrix34& arg1);

// ?DrawColor@@YAXAAVVector3@@@Z
ARTS_IMPORT void DrawColor(aconst Vector3& arg1);

// ?DrawColor@@YAXAAVVector4@@@Z
ARTS_IMPORT void DrawColor(aconst Vector4& arg1);

// ?DrawColor2@@YAXAAVVector3@@@Z | unused
ARTS_IMPORT void DrawColor2(aconst Vector3& arg1);

// ?DrawColor2@@YAXAAVVector4@@@Z | unused
ARTS_IMPORT void DrawColor2(aconst Vector4& arg1);

// ?DrawEnd@@YAXXZ
ARTS_IMPORT void DrawEnd();

// ?DrawLabelf@@YAXAAVVector3@@PADZZ
ARTS_IMPORT void DrawLabelf(Vector3& arg1, aconst char* arg2, ...);

// ?DrawLine@@YAXAAVVector3@@0@Z
ARTS_IMPORT void DrawLine(Vector3& arg1, Vector3& arg2);

// ?DrawLine@@YAXMMMMMM@Z
ARTS_IMPORT void DrawLine(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);

// ?DrawQuad@@YAXPAVVector3@@AAV1@111@Z
ARTS_IMPORT void DrawQuad(Vector3* arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4, Vector3& arg5);

// ?DrawTri@@YAXPAVVector3@@AAV1@11@Z
ARTS_IMPORT void DrawTri(Vector3* arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4);

// ?DrawWireBox@@YAXAAVVector3@@0@Z
ARTS_IMPORT void DrawWireBox(Vector3& arg1, Vector3& arg2);

// ?DrawWireSphere@@YAXAAVVector4@@@Z
ARTS_IMPORT void DrawWireSphere(Vector4& arg1);

// ?DrawWireSphere@@YAXAAVVector3@@M@Z
ARTS_IMPORT void DrawWireSphere(Vector3& arg1, f32 arg2);
#endif

// ?ColBlack@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColBlack;

// ?ColBlue@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColBlue;

// ?ColCyan@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColCyan;

// ?ColDarkBlue@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColDarkBlue;

// ?ColDarkCyan@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColDarkCyan;

// ?ColDarkGreen@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColDarkGreen;

// ?ColDarkOrange@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColDarkOrange;

// ?ColDarkPurple@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColDarkPurple;

// ?ColDarkRed@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColDarkRed;

// ?ColDarkYellow@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColDarkYellow;

// ?ColGreen@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColGreen;

// ?ColGrey@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColGrey;

// ?ColLightBlue@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColLightBlue;

// ?ColLightCyan@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColLightCyan;

// ?ColLightGreen@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColLightGreen;

// ?ColLightOrange@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColLightOrange;

// ?ColLightPurple@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColLightPurple;

// ?ColLightRed@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColLightRed;

// ?ColLightYellow@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColLightYellow;

// ?ColOrange@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColOrange;

// ?ColPurple@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColPurple;

// ?ColRed@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColRed;

// ?ColWhite@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColWhite;

// ?ColYellow@@3VVector3@@A
ARTS_IMPORT extern Vector3 ColYellow;
