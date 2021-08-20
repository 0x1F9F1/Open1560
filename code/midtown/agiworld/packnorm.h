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

union mmx;

// ?PackNormal@@YAEAAVVector3@@@Z
ARTS_IMPORT u8 PackNormal(Vector3& normal);

// ?PackNormalSlow@@YAEAAVVector3@@@Z | unused
ARTS_IMPORT u8 PackNormalSlow(Vector3& normal);

// ?UnpackNormal@@3PAVVector3@@A
ARTS_EXPORT extern Vector3 UnpackNormal[198];

// ?UnpackNormalMMX@@3PATmmx@@A
ARTS_IMPORT extern mmx UnpackNormalMMX[198];
