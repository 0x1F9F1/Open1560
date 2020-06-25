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

define_dummy_symbol(agiworld_meshrend);

#include "meshrend.h"

// 0x506380 | ?ClipNX@@YIXAAUCV@@0@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL ClipNX(struct CV& arg1, struct CV& arg2);

// 0x506260 | ?ClipNX@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ClipNX(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x5067A0 | ?ClipNY@@YIXAAUCV@@0@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL ClipNY(struct CV& arg1, struct CV& arg2);

// 0x506680 | ?ClipNY@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ClipNY(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x506BB0 | ?ClipNZ@@YIXAAUCV@@0@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL ClipNZ(struct CV& arg1, struct CV& arg2);

// 0x506A90 | ?ClipNZ@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ClipNZ(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x506590 | ?ClipPX@@YIXAAUCV@@0@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL ClipPX(struct CV& arg1, struct CV& arg2);

// 0x506470 | ?ClipPX@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ClipPX(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x5069B0 | ?ClipPY@@YIXAAUCV@@0@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL ClipPY(struct CV& arg1, struct CV& arg2);

// 0x506890 | ?ClipPY@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ClipPY(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x506DC0 | ?ClipPZ@@YIXAAUCV@@0@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL ClipPZ(struct CV& arg1, struct CV& arg2);

// 0x506CA0 | ?ClipPZ@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ClipPZ(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x5061B0 | ?FullClip@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 FullClip(struct CV* arg1, struct CV* arg2, i32 arg3);

// 0x506EA0 | ?ZClipOnly@@YAHPAUCV@@0H@Z
ARTS_IMPORT /*static*/ i32 ZClipOnly(struct CV* arg1, struct CV* arg2, i32 arg3);
