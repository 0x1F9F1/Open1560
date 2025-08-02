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

struct JHUFF_TBL;
struct jpeg_common_struct;
struct JQUANT_TBL;

// ?jpeg_abort@@YAXPAUjpeg_common_struct@@@Z
ARTS_IMPORT void jpeg_abort(jpeg_common_struct* arg1);

// ?jpeg_alloc_huff_table@@YAPAUJHUFF_TBL@@PAUjpeg_common_struct@@@Z
ARTS_IMPORT JHUFF_TBL* jpeg_alloc_huff_table(jpeg_common_struct* arg1);

// ?jpeg_alloc_quant_table@@YAPAUJQUANT_TBL@@PAUjpeg_common_struct@@@Z
ARTS_IMPORT JQUANT_TBL* jpeg_alloc_quant_table(jpeg_common_struct* arg1);

// ?jpeg_destroy@@YAXPAUjpeg_common_struct@@@Z
ARTS_IMPORT void jpeg_destroy(jpeg_common_struct* arg1);
