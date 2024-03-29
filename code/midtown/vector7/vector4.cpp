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

define_dummy_symbol(vector7_vector4);

#include "vector4.h"

#include "vector3.h"

Vector3::operator Vector4() const
{
    return Vector4(x, y, z, 0.0f);
}

void Vector4::CalculatePlane(const Vector3& v0, const Vector3& v1, const Vector3& v2)
{
    Vector3 plane = ~((v2 - v1) % (v0 - v1));

    Set(plane.x, plane.y, plane.z, -(plane ^ v1));
}
