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

define_dummy_symbol(mmanim_AnimDOF);

#include "AnimDOF.h"

#include "agi/rsys.h"
#include "agi/viewport.h"
#include "agiworld/meshset.h"
#include "mmcity/cullcity.h"
#include "mmcity/renderweb.h"

void mmDrawbridgeInstance::Draw(i32 lod)
{
    enum
    {
        BRIDGE = 0,
        RAIL = 1,
    };

    Matrix34 world;
    Viewport()->SetWorld(ToMatrix(world));

    // FIXME: The main part of the bridge is drawn during the terrain pass, which has depth testing disabled with the software renderer
    // This can cause other terrain to become visible through the bridge
    auto zwrite = agiCurState.SetZWrite(true);
    auto zenable = agiCurState.SetZEnable(true);

    if (asRenderWeb::PassMask & RENDER_PASS_TERRAIN)
    {
        if (agiMeshSet* mesh = GetResidentMeshSet(lod, BRIDGE))
            mesh->DrawLitEnv(DynamicLighter, CullCity()->ShadowMap, CullCity()->EnvMatrix, MESH_DRAW_CLIP);
    }

    if (asRenderWeb::PassMask & RENDER_PASS_OBJECTS)
    {
        if (agiMeshSet* mesh = GetResidentMeshSet(lod, RAIL))
            mesh->DrawLit(DynamicLighter, MESH_DRAW_CLIP, nullptr);
    }

    agiCurState.SetZWrite(zwrite);
    agiCurState.SetZEnable(zenable);
}
