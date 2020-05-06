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

define_dummy_symbol(dyna7_gfx);

#include "gfx.h"

void DrawBegin(class Matrix34& arg1)
{
    return stub<cdecl_t<void, class Matrix34&>>(0x52D800, arg1);
}

void DrawColor(class Vector3& arg1)
{
    return stub<cdecl_t<void, class Vector3&>>(0x52D020, arg1);
}

void DrawColor(class Vector4& arg1)
{
    return stub<cdecl_t<void, class Vector4&>>(0x52D0D0, arg1);
}

void DrawColor2(class Vector3& arg1)
{
    return stub<cdecl_t<void, class Vector3&>>(0x52D080, arg1);
}

void DrawColor2(class Vector4& arg1)
{
    return stub<cdecl_t<void, class Vector4&>>(0x52D130, arg1);
}

void DrawEnd()
{
    return stub<cdecl_t<void>>(0x52DA30);
}

void DrawLabelf(class Vector3& arg1, char* arg2, ...)
{
    unimplemented(arg1, arg2);
}

void DrawLine(class Vector3& arg1, class Vector3& arg2)
{
    return stub<cdecl_t<void, class Vector3&, class Vector3&>>(0x52D230, arg1, arg2);
}

void DrawLine(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6)
{
    return stub<cdecl_t<void, f32, f32, f32, f32, f32, f32>>(0x52D190, arg1, arg2, arg3, arg4, arg5, arg6);
}

void DrawQuad(class Vector3* arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4, class Vector3& arg5)
{
    return stub<cdecl_t<void, class Vector3*, class Vector3&, class Vector3&, class Vector3&, class Vector3&>>(
        0x52D8C0, arg1, arg2, arg3, arg4, arg5);
}

void DrawTri(class Vector3* arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4)
{
    return stub<cdecl_t<void, class Vector3*, class Vector3&, class Vector3&, class Vector3&>>(
        0x52D260, arg1, arg2, arg3, arg4);
}

void DrawWireBox(class Vector3& arg1, class Vector3& arg2)
{
    return stub<cdecl_t<void, class Vector3&, class Vector3&>>(0x52D640, arg1, arg2);
}

void DrawWireSphere(class Vector4& arg1)
{
    return stub<cdecl_t<void, class Vector4&>>(0x52D620, arg1);
}

void DrawWireSphere(class Vector3& arg1, f32 arg2)
{
    return stub<cdecl_t<void, class Vector3&, f32>>(0x52D320, arg1, arg2);
}
