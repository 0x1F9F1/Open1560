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

enum class agiVtxType : i32
{
    VtxType0,
    VtxType1,
    VtxType2,
    Screen, // agiScreenVtx
};

// D3DFVF_TLVERTEX
struct agiScreenVtx
{
    f32 x, y;     // screen position
    f32 z;        // Z-buffer depth
    f32 w;        // reciprocal homogeneous W
    u32 color;    // diffuse color
    u32 specular; // specular color
    f32 tu, tv;   // texture coordinates
};

check_size(agiScreenVtx, 0x20);

// (D3DFVF_TLVERTEX | D3DFVF_TEX2) & ~D3DFVF_TEX1
struct agiScreenVtx2
{
    f32 x, y;     // screen position
    f32 z;        // Z-buffer depth
    f32 w;        // reciprocal homogeneous W
    u32 color;    // diffuse color
    u32 specular; // specular color
    f32 tu1, tv1; // texture 1 coordinates
    f32 tu2, tv2; // texture 2 coordinates
};

check_size(agiScreenVtx2, 0x28);

union agiVtx
{
    agiScreenVtx Screen;
};

check_size(agiVtx, 0x20);
