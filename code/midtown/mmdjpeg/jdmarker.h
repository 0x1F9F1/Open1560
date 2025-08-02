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

struct jpeg_decompress_struct;

// ?jinit_marker_reader@@YAXPAUjpeg_decompress_struct@@@Z
ARTS_IMPORT void jinit_marker_reader(jpeg_decompress_struct* arg1);

// ?jpeg_resync_to_restart@@YAEPAUjpeg_decompress_struct@@H@Z
ARTS_IMPORT u8 jpeg_resync_to_restart(jpeg_decompress_struct* arg1, i32 arg2);
