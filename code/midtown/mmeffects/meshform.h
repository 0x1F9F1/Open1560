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

class agiMeshSet;
class agiTexDef;

class asMeshSetForm final : public asNode
{
public:
    // ??0asMeshSetForm@@QAE@XZ
    ARTS_IMPORT asMeshSetForm();

    // ??_GasMeshSetForm@@UAEPAXI@Z
    // ??_EasMeshSetForm@@UAEPAXI@Z
    // ??1asMeshSetForm@@UAE@XZ | inline
    ARTS_EXPORT ~asMeshSetForm() override = default;

    // ?Cull@asMeshSetForm@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?SetShape@asMeshSetForm@@QAEXPAD0PAVVector3@@@Z
    ARTS_IMPORT void SetShape(char* arg1, char* arg2, Vector3* arg3);

    // ?SetZRead@asMeshSetForm@@QAEXH@Z
    ARTS_IMPORT void SetZRead(i32 arg1);

    // ?SetZWrite@asMeshSetForm@@QAEXH@Z
    ARTS_IMPORT void SetZWrite(i32 arg1);

    // ?Update@asMeshSetForm@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?Lighter@asMeshSetForm@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    ARTS_IMPORT static void (*Lighter)(u8*, u32*, u32*, agiMeshSet*);

    // ?SphMapTex@asMeshSetForm@@2PAVagiTexDef@@A
    ARTS_IMPORT static agiTexDef* SphMapTex;

    u8 gap20[0xC];
};

check_size(asMeshSetForm, 0x2C);
