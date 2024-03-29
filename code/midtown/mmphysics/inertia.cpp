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

define_dummy_symbol(mmphysics_inertia);

#include "inertia.h"

void asInertialCS::FileIO(MiniParser* /*arg1*/)
{}

asInertialCS::asInertialCS()
{
    Global = true;
    SetDensity(1.0f, 1.0f, 1.0f, 1.0f);
    Zero();
}

void asInertialCS::SetDensity(f32 size_x, f32 size_y, f32 size_z, f32 density)
{
    SetMass(size_x, size_y, size_z, size_x * size_y * size_z * density * 1000.0f);
}

void asInertialCS::SetMass(f32 size_x, f32 size_y, f32 size_z, f32 mass)
{
    Size = Vector3(size_x, size_y, size_z);
    Mass = mass;
    InvMass = 1.0f / mass;

    size_x *= size_x;
    size_y *= size_y;
    size_z *= size_z;
    Inertia = Vector3(size_y + size_z, size_x + size_z, size_x + size_y) * (mass / 12.0f);
    InvInertia = 1.0f / Inertia;
}
