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

// ?CloseColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 CloseColor;

// ?CollTestColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 CollTestColor;

#define DYNA_DRAW_GEOMETRY 0x1
#define DYNA_DRAW_STATUS 0x2
#define DYNA_DRAW_BOUNDS 0x4
#define DYNA_DRAW_INTERSECT 0x8
#define DYNA_DRAW_APPLIED_FORCES 0x10
#define DYNA_DRAW_RESULT_FORCES 0x20
#define DYNA_DRAW_VOLUME_SAMPLES 0x40
#define DYNA_DRAW_FLUID_SAMPLES 0x80
#define DYNA_DRAW_SPRINGS 0x100
#define DYNA_DRAW_MATRIX 0x200
#define DYNA_DRAW_TABLES 0x400
#define DYNA_DRAW_CULL_SPHERES 0x800
#define DYNA_DRAW_APPLIED_PUSHES 0x1000

// ?DynaDrawMode@@3HA
ARTS_IMPORT extern i32 DynaDrawMode;

// ?DynaDrawScale@@3MA
ARTS_IMPORT extern f32 DynaDrawScale;

// ?FluidColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 FluidColor;

// ?ForceColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 ForceColor;

// ?HitColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 HitColor;

// ?ImpulseColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 ImpulseColor;

// ?MissColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 MissColor;

// ?NormalColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 NormalColor;

// ?PushColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 PushColor;

// ?SegVCPoly@@3HA
ARTS_IMPORT extern i32 SegVCPoly;

// ?SegVCyl@@3HA
ARTS_IMPORT extern i32 SegVCyl;

// ?SegVPoly@@3HA
ARTS_IMPORT extern i32 SegVPoly;

// ?SegVSph@@3HA
ARTS_IMPORT extern i32 SegVSph;

// ?SphVCPoly@@3HA
ARTS_IMPORT extern i32 SphVCPoly;

// ?SphVCyl@@3HA
ARTS_IMPORT extern i32 SphVCyl;

// ?SphVPoly@@3HA
ARTS_IMPORT extern i32 SphVPoly;

// ?SphVSph@@3HA
ARTS_IMPORT extern i32 SphVSph;

// ?SpringColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 SpringColor;

// ?TestColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 TestColor;

// ?TorqueColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 TorqueColor;

// ?VolumeColor@@3VVector3@@A
ARTS_IMPORT extern Vector3 VolumeColor;
