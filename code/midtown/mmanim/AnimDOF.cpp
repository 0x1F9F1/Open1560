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
    if (agiMeshSet* mesh = GetResidentMeshSet(lod, (asRenderWeb::PassMask & 1) ? 0 : 1, 0))
    {
        bool zenable = agiCurState.GetZEnable();

        // TODO: Why is this only enabled when software rendering?
        if (agiCurState.GetSoftwareRendering())
            agiCurState.SetZEnable(true);

        Matrix34 world;
        Viewport()->SetWorld(ToMatrix(world));

        mesh->DrawLitEnv(mmInstance::DynamicLighter, CullCity()->ShadowMap, CullCity()->EnvMatrix, AGI_MESH_DRAW_CLIP);

        agiCurState.SetZEnable(zenable);
    }
}
