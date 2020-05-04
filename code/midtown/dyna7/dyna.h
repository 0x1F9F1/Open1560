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
    dyna7:dyna

    0x64E358 | int DynaDrawMode | ?DynaDrawMode@@3HA
    0x64E35C | float DynaDrawScale | ?DynaDrawScale@@3MA
    0x790CD8 | class Vector3 CollTestColor | ?CollTestColor@@3VVector3@@A
    0x790CE8 | class Vector3 PushColor | ?PushColor@@3VVector3@@A
    0x790CF8 | class Vector3 NormalColor | ?NormalColor@@3VVector3@@A
    0x790D08 | class Vector3 TestColor | ?TestColor@@3VVector3@@A
    0x790D18 | class Vector3 CloseColor | ?CloseColor@@3VVector3@@A
    0x790D28 | class Vector3 SpringColor | ?SpringColor@@3VVector3@@A
    0x790D38 | class Vector3 TorqueColor | ?TorqueColor@@3VVector3@@A
    0x790D48 | class Vector3 ForceColor | ?ForceColor@@3VVector3@@A
    0x790D58 | class Vector3 HitColor | ?HitColor@@3VVector3@@A
    0x790D68 | class Vector3 FluidColor | ?FluidColor@@3VVector3@@A
    0x790D78 | class Vector3 ImpulseColor | ?ImpulseColor@@3VVector3@@A
    0x790D88 | class Vector3 MissColor | ?MissColor@@3VVector3@@A
    0x790D98 | class Vector3 VolumeColor | ?VolumeColor@@3VVector3@@A
    0x790DA4 | int SphVSph | ?SphVSph@@3HA
    0x790DA8 | int SphVCyl | ?SphVCyl@@3HA
    0x790DAC | int SphVPoly | ?SphVPoly@@3HA
    0x790DB0 | int SphVCPoly | ?SphVCPoly@@3HA
    0x790DB4 | int SegVSph | ?SegVSph@@3HA
    0x790DB8 | int SegVCyl | ?SegVCyl@@3HA
    0x790DBC | int SegVPoly | ?SegVPoly@@3HA
    0x790DC0 | int SegVCPoly | ?SegVCPoly@@3HA
*/

// 0x790D18 | ?CloseColor@@3VVector3@@A
inline extern_var(0x390D18_Offset, class Vector3, CloseColor);

// 0x790CD8 | ?CollTestColor@@3VVector3@@A
inline extern_var(0x390CD8_Offset, class Vector3, CollTestColor);

// 0x64E358 | ?DynaDrawMode@@3HA
inline extern_var(0x24E358_Offset, i32, DynaDrawMode);

// 0x64E35C | ?DynaDrawScale@@3MA
inline extern_var(0x24E35C_Offset, f32, DynaDrawScale);

// 0x790D68 | ?FluidColor@@3VVector3@@A
inline extern_var(0x390D68_Offset, class Vector3, FluidColor);

// 0x790D48 | ?ForceColor@@3VVector3@@A
inline extern_var(0x390D48_Offset, class Vector3, ForceColor);

// 0x790D58 | ?HitColor@@3VVector3@@A
inline extern_var(0x390D58_Offset, class Vector3, HitColor);

// 0x790D78 | ?ImpulseColor@@3VVector3@@A
inline extern_var(0x390D78_Offset, class Vector3, ImpulseColor);

// 0x790D88 | ?MissColor@@3VVector3@@A
inline extern_var(0x390D88_Offset, class Vector3, MissColor);

// 0x790CF8 | ?NormalColor@@3VVector3@@A
inline extern_var(0x390CF8_Offset, class Vector3, NormalColor);

// 0x790CE8 | ?PushColor@@3VVector3@@A
inline extern_var(0x390CE8_Offset, class Vector3, PushColor);

// 0x790DC0 | ?SegVCPoly@@3HA
inline extern_var(0x390DC0_Offset, i32, SegVCPoly);

// 0x790DB8 | ?SegVCyl@@3HA
inline extern_var(0x390DB8_Offset, i32, SegVCyl);

// 0x790DBC | ?SegVPoly@@3HA
inline extern_var(0x390DBC_Offset, i32, SegVPoly);

// 0x790DB4 | ?SegVSph@@3HA
inline extern_var(0x390DB4_Offset, i32, SegVSph);

// 0x790DB0 | ?SphVCPoly@@3HA
inline extern_var(0x390DB0_Offset, i32, SphVCPoly);

// 0x790DA8 | ?SphVCyl@@3HA
inline extern_var(0x390DA8_Offset, i32, SphVCyl);

// 0x790DAC | ?SphVPoly@@3HA
inline extern_var(0x390DAC_Offset, i32, SphVPoly);

// 0x790DA4 | ?SphVSph@@3HA
inline extern_var(0x390DA4_Offset, i32, SphVSph);

// 0x790D28 | ?SpringColor@@3VVector3@@A
inline extern_var(0x390D28_Offset, class Vector3, SpringColor);

// 0x790D08 | ?TestColor@@3VVector3@@A
inline extern_var(0x390D08_Offset, class Vector3, TestColor);

// 0x790D38 | ?TorqueColor@@3VVector3@@A
inline extern_var(0x390D38_Offset, class Vector3, TorqueColor);

// 0x790D98 | ?VolumeColor@@3VVector3@@A
inline extern_var(0x390D98_Offset, class Vector3, VolumeColor);
