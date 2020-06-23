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
    agiworld:packnorm

    0x516400 | unsigned char __cdecl PackNormalSlow(class Vector3 &) | ?PackNormalSlow@@YAEAAVVector3@@@Z
    0x5164B0 | unsigned char __cdecl PackNormal(class Vector3 &) | ?PackNormal@@YAEAAVVector3@@@Z
    0x64B6A0 | class Vector3 * UnpackNormal | ?UnpackNormal@@3PAVVector3@@A
    0x73E738 | union mmx * UnpackNormalMMX | ?UnpackNormalMMX@@3PATmmx@@A
*/

// 0x5164B0 | ?PackNormal@@YAEAAVVector3@@@Z
u8 PackNormal(class Vector3& arg1);

// 0x516400 | ?PackNormalSlow@@YAEAAVVector3@@@Z | unused
u8 PackNormalSlow(class Vector3& arg1);

// 0x64B6A0 | ?UnpackNormal@@3PAVVector3@@A
inline extern_var(0x64B6A0, class Vector3[198], UnpackNormal);

// 0x73E738 | ?UnpackNormalMMX@@3PATmmx@@A
inline extern_var(0x73E738, union mmx[198], UnpackNormalMMX);
