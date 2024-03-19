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

define_dummy_symbol(mmdyna_poly);

#include "poly.h"

#include "mmdyna/bndtmpl.h"

f32 mmPolygon::CheckCellXSide(f32 x_plane, f32 z_min, f32 z_max)
{
    f32 max_y = -999999.0f;
    i32 vert_count = (Flags & 4) != 0 ? 4 : 3;

    for (i32 i = 0; i < vert_count; ++i)
    {
        const Vector3& cur_vert = mmBoundTemplate::VertPtr[VertIndices[i % vert_count]];
        const Vector3& next_vert = mmBoundTemplate::VertPtr[VertIndices[(i + 1) % vert_count]];

        if ((cur_vert.x < x_plane && next_vert.x > x_plane) || (cur_vert.x > x_plane && next_vert.x < x_plane))
        {
            f32 factor = (x_plane - cur_vert.x) / (next_vert.x - cur_vert.x);
            f32 z_int = (next_vert.z - cur_vert.z) * factor + cur_vert.z;

            if (z_int >= z_min && z_int <= z_max)
            {
                f32 y_int = (next_vert.y - cur_vert.y) * factor + cur_vert.y;

                if (y_int > max_y)
                {
                    max_y = y_int;
                }
            }
        }
    }

    return max_y;
}

f32 mmPolygon::CheckCellZSide(f32 z_plane, f32 x_min, f32 x_max)
{
    f32 max_y = -999999.0f;
    i32 vert_count = (Flags & 4) != 0 ? 4 : 3;

    for (i32 i = 0; i < vert_count; ++i)
    {
        const Vector3& cur_vert = mmBoundTemplate::VertPtr[VertIndices[i % vert_count]];
        const Vector3& next_vert = mmBoundTemplate::VertPtr[VertIndices[(i + 1) % vert_count]];

        if ((cur_vert.z < z_plane && next_vert.z > z_plane) || (cur_vert.z > z_plane && next_vert.z < z_plane))
        {
            f32 factor = (z_plane - cur_vert.z) / (next_vert.z - cur_vert.z);
            f32 x_int = (next_vert.x - cur_vert.x) * factor + cur_vert.x;

            if (x_int >= x_min && x_int <= x_max)
            {
                f32 y_int = (next_vert.y - cur_vert.y) * factor + cur_vert.y;

                if (y_int > max_y)
                {
                    max_y = y_int;
                }
            }
        }
    }

    return max_y;
}

f32 mmPolygon::CheckCorner(f32 x, f32 z, f32* x_plane, f32* z_plane, f32* const_plane)
{
    if (PlaneN.y == 0.0f)
    {
        return -999999.0f;
    }

    i32 vert_count = (Flags & 4) ? 4 : 3;

    for (i32 i = 0; i < vert_count; ++i)
    {
        if (x * x_plane[i] + z * z_plane[i] + const_plane[i] < 0.0f)
        {
            return -999999.0f;
        }
    }

    return -(PlaneN.x * x + PlaneD + PlaneN.z * z) / PlaneN.y;
}

f32 mmPolygon::CornersHeight(f32 x1, f32 z1, f32 x2, f32 z2)
{
    f32 max_y = -999999.0f;
    i32 vert_count = (Flags & 4) ? 4 : 3;
    f32 adjusted_sign = (PlaneN.y <= 0.0f) ? 1.0f : -1.0f;
    f32 x_plane[4], z_plane[4], const_plane[4], length, inverse_length;

    for (i32 i = 0; i < vert_count; ++i)
    {
        Vector3& cur_vert = mmBoundTemplate::VertPtr[VertIndices[i]];
        Vector3& next_vert = mmBoundTemplate::VertPtr[VertIndices[(i + 1) % vert_count]];

        x_plane[i] = -(next_vert.z - cur_vert.z) * adjusted_sign;
        z_plane[i] = (next_vert.x - cur_vert.x) * adjusted_sign;
        const_plane[i] = -(x_plane[i] * cur_vert.x + z_plane[i] * cur_vert.z);

        length = std::sqrt(x_plane[i] * x_plane[i] + z_plane[i] * z_plane[i]);

        if (length < 1e-9)
            return -999999.0f;

        inverse_length = 1.0f / length;
        x_plane[i] *= inverse_length;
        z_plane[i] *= inverse_length;
        const_plane[i] *= inverse_length;
    }

    for (i32 i = 0; i < 4; ++i)
    {
        f32 corner_height;

        corner_height = CheckCorner(x1, z1, x_plane, z_plane, const_plane);
        max_y = std::max(max_y, corner_height);

        corner_height = CheckCorner(x1, z2, x_plane, z_plane, const_plane);
        max_y = std::max(max_y, corner_height);

        corner_height = CheckCorner(x2, z1, x_plane, z_plane, const_plane);
        max_y = std::max(max_y, corner_height);

        corner_height = CheckCorner(x2, z2, x_plane, z_plane, const_plane);
        max_y = std::max(max_y, corner_height);
    }

    return max_y;
}

f32 mmPolygon::MaxY(f32 x_min, f32 z_min, f32 x_max, f32 z_max)
{
    f32 max_y = -999999.0f;                   
    i32 vert_count = (Flags & 4) != 0 ? 4 : 3; 

    for (i32 i = 0; i < vert_count; ++i)
    {
        Vector3& vert = mmBoundTemplate::VertPtr[VertIndices[i]];

        if (vert.x >= x_min && vert.x <= x_max && vert.z >= z_min && vert.z <= z_max)
        {
            max_y = std::max(max_y, vert.y); 
        }
    }

    f32 corner_height = CornersHeight(x_min, z_min, x_max, z_max);
    max_y = std::max(max_y, corner_height);

    f32 cell_x_side_min = CheckCellXSide(x_min, z_min, z_max);
    max_y = std::max(max_y, cell_x_side_min);

    f32 cell_x_side_max = CheckCellXSide(x_max, z_min, z_max);
    max_y = std::max(max_y, cell_x_side_max);

    f32 cell_z_side_min = CheckCellZSide(z_min, x_min, x_max);
    max_y = std::max(max_y, cell_z_side_min);

    f32 cell_z_side_max = CheckCellZSide(z_max, x_min, x_max);
    max_y = std::max(max_y, cell_z_side_max);

    return max_y;
}

void mmPolygon::Plot(mmBoundTemplate* t, i32 poly_index)
{
    if (Flags & 4)
    {
        PlotTriangle(0, 1, 2, t, poly_index);
        PlotTriangle(0, 2, 3, t, poly_index);
    }
    else
    {
        PlotTriangle(0, 1, 2, t, poly_index);
    }
}

void mmPolygon::PlotScan(i32 x1, i32 x2, i32 z, mmBoundTemplate* t, i32 poly_index)
{
    if (!t)
        return;

    z = std::clamp(z, 0, t->ZDim - 1);
    x1 = std::clamp(x1, 0, t->XDim - 1);
    x2 = std::clamp(x2, 0, t->XDim - 1);

    for (i32 x = x1; x <= x2; ++x)
    {
        t->AddIndex(x, z, poly_index);
    }
}