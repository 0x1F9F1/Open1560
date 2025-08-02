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

#include "arts7/node.h"

#include "damage.h"

class agiMeshSet;
class agiTexDef;

class mmVehicleForm final : public asNode
{
public:
    // ??0mmVehicleForm@@QAE@XZ
    ARTS_EXPORT mmVehicleForm();

    // ??_EmmVehicleForm@@UAEPAXI@Z
    // ??_GmmVehicleForm@@UAEPAXI@Z | unused
    // ??1mmVehicleForm@@UAE@XZ | inline
    ARTS_EXPORT ~mmVehicleForm() override;

    // ?Cull@mmVehicleForm@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?SetShape@mmVehicleForm@@QAEXPAD00PAVVector3@@@Z
    ARTS_IMPORT void SetShape(char* arg1, char* arg2, char* arg3, Vector3* arg4);

    // ?Update@mmVehicleForm@@UAEXXZ
    ARTS_EXPORT void Update() override;

    // ?Lighter@mmVehicleForm@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    ARTS_IMPORT static void (*Lighter)(u8*, u32*, u32*, agiMeshSet*);

    // ?SphMapTex@mmVehicleForm@@2PAVagiTexDef@@A
    ARTS_IMPORT static agiTexDef* SphMapTex;

private:
    agiMeshSet* vehicle_mesh_ {};
    agiMeshSet* shadow_mesh_ {};
    u32 draw_color_ {};
    i32* color_pointer {};
    i32 color_index_ {};
    mmDamage damage_ {};
};

check_size(mmVehicleForm, 0x54);
