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

define_dummy_symbol(vector7_geomath);

#include "geomath.h"

#include "matrix34.h"
#include "vector4.h"

void ComputeShadowMatrix(Matrix34& matrix, Vector4& normal)
{
    matrix.m0.x = -(normal.x * normal.x) + 1.0f;
    matrix.m0.y = -(normal.x * normal.y);
    matrix.m0.z = -(normal.x * normal.z);

    matrix.m1.x = -(normal.x * normal.y);
    matrix.m1.y = -(normal.y * normal.y) + 1.0f;
    matrix.m1.z = -(normal.z * normal.y);

    matrix.m2.x = -(normal.x * normal.z);
    matrix.m2.y = -(normal.z * normal.y);
    matrix.m2.z = -(normal.z * normal.z) + 1.0f;

    matrix.m3.x = -(normal.x * normal.w);
    matrix.m3.y = -(normal.w * normal.y);
    matrix.m3.z = -(normal.w * normal.z);
}
