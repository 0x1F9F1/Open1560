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

class agiPipeline;

// ?d3dCreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
ARTS_EXPORT Owner<agiPipeline> d3dCreatePipeline(i32 argc, char** argv);

// ?AutoMip@@3HA
ARTS_IMPORT extern b32 AutoMip;

// ?DrawLabelFArg@@3HA
ARTS_IMPORT extern b32 DrawLabelFArg;

// ?DrawLabelPArg@@3HA
ARTS_IMPORT extern b32 DrawLabelPArg;

// ?ForceSquare@@3HA
ARTS_IMPORT extern b32 ForceSquare;

// ?FullMip@@3HA
ARTS_IMPORT extern b32 FullMip;

// ?MaxTexMem@@3HA
ARTS_IMPORT extern i32 MaxTexMem;

// ?NoBlitHack@@3HA
ARTS_IMPORT extern b32 NoBlitHack;

// ?NoMip@@3HA
ARTS_IMPORT extern b32 NoMip;

// ?NoMultiTexture@@3HA
ARTS_IMPORT extern b32 NoMultiTexture;

// ?NormalizedFog@@3HA
ARTS_IMPORT extern b32 NormalizedFog;
