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

define_dummy_symbol(agid3d_d3dpipe);

#include "d3dpipe.h"

// 0x5307B0 | ?EnumCallback@@YGJPAU_GUID@@PAD1PAU_D3DDeviceDesc@@2PAX@Z
ARTS_IMPORT /*static*/ i32 ARTS_STDCALL EnumCallback(
    struct _GUID* arg1, char* arg2, char* arg3, struct _D3DDeviceDesc* arg4, struct _D3DDeviceDesc* arg5, void* arg6);

// 0x5308B0 | ?EnumTextureCallback@@YGJPAU_DDPIXELFORMAT@@PAX@Z
ARTS_IMPORT /*static*/ i32 ARTS_STDCALL EnumTextureCallback(struct _DDPIXELFORMAT* arg1, void* arg2);

// 0x530980 | ?EnumZ@@YGJPAU_DDPIXELFORMAT@@PAX@Z
ARTS_IMPORT /*static*/ i32 ARTS_STDCALL EnumZ(struct _DDPIXELFORMAT* arg1, void* arg2);
