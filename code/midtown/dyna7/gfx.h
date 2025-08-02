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

#ifdef ARTS_DEV_BUILD
// ?DrawBegin@@YAXAAVMatrix34@@@Z
ARTS_IMPORT void DrawBegin(aconst Matrix34& arg1);

// ?DrawColor@@YAXAAVVector3@@@Z
ARTS_IMPORT void DrawColor(aconst Vector3& arg1);

// ?DrawColor@@YAXAAVVector4@@@Z
ARTS_IMPORT void DrawColor(aconst Vector4& arg1);

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
