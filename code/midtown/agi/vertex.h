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

enum agiVtxType : i32
{
    VtxType0,
    VtxType1,
    VtxType2,
    VtxType3, // agiScreenVtx
};

// D3DFVF_TLVERTEX
struct agiScreenVtx
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    u32 specular;
    u32 diffuse;
    f32 tu;
    f32 tv;
};

check_size(agiScreenVtx, 0x20);

// (D3DFVF_TLVERTEX | D3DFVF_TEX2) & ~D3DFVF_TEX1
struct agiScreenVtx2
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    u32 specular;
    u32 diffuse;
    f32 tu1;
    f32 tv1;
    f32 tu2;
    f32 tv2;
};

check_size(agiScreenVtx2, 0x28);

union agiVtx
{
    agiScreenVtx Screen;
};

check_size(agiVtx, 0x20);
