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
    agid3d:pcpipe

    0x52DFC0 | class agiPipeline * __cdecl d3dCreatePipeline(int,char * *) | ?d3dCreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
    0x790DC4 | int NoMultiTexture | ?NoMultiTexture@@3HA
    0x790DC8 | int MaxTexMem | ?MaxTexMem@@3HA
    0x790DCC | int AutoMip | ?AutoMip@@3HA
    0x790DD0 | int DrawLabelFArg | ?DrawLabelFArg@@3HA
    0x790DD4 | int NoMip | ?NoMip@@3HA
    0x790DD8 | int NormalizedFog | ?NormalizedFog@@3HA
    0x790DDC | int FullMip | ?FullMip@@3HA
    0x790DE0 | int ForceSquare | ?ForceSquare@@3HA
    0x790DE4 | int NoBlitHack | ?NoBlitHack@@3HA
    0x790DE8 | int DrawLabelPArg | ?DrawLabelPArg@@3HA
*/

// 0x52DFC0 | ?d3dCreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
class agiPipeline* d3dCreatePipeline(i32 arg1, char** arg2);

// 0x790DCC | ?AutoMip@@3HA
inline extern_var(0x790DCC, i32, AutoMip);

// 0x790DD0 | ?DrawLabelFArg@@3HA
inline extern_var(0x790DD0, i32, DrawLabelFArg);

// 0x790DE8 | ?DrawLabelPArg@@3HA
inline extern_var(0x790DE8, i32, DrawLabelPArg);

// 0x790DE0 | ?ForceSquare@@3HA
inline extern_var(0x790DE0, i32, ForceSquare);

// 0x790DDC | ?FullMip@@3HA
inline extern_var(0x790DDC, i32, FullMip);

// 0x790DC8 | ?MaxTexMem@@3HA
inline extern_var(0x790DC8, i32, MaxTexMem);

// 0x790DE4 | ?NoBlitHack@@3HA
inline extern_var(0x790DE4, i32, NoBlitHack);

// 0x790DD4 | ?NoMip@@3HA
inline extern_var(0x790DD4, i32, NoMip);

// 0x790DC4 | ?NoMultiTexture@@3HA
inline extern_var(0x790DC4, i32, NoMultiTexture);

// 0x790DD8 | ?NormalizedFog@@3HA
inline extern_var(0x790DD8, i32, NormalizedFog);
