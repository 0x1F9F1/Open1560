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

define_dummy_symbol(agid3d_d3dmtldef);

#include "d3dmtldef.h"

#include "agi/error.h"
#include "dderror.h"

#include <d3dtypes.h>

// ?xlat@@YAXAAU_D3DCOLORVALUE@@AAVVector4@@@Z
ARTS_EXPORT /*static*/ void xlat(D3DCOLORVALUE& dst, Vector4& src)
{
    dst.r = src.x;
    dst.g = src.y;
    dst.b = src.z;
    dst.a = src.w;
}

void agiD3DMtlDef::Activate()
{
    if (HaveGfxStarted() && Mtl.Touched)
    {
        D3DMATERIAL mat {};

        mat.dwSize = sizeof(mat);
        xlat(mat.diffuse, Mtl.Diffuse);
        xlat(mat.ambient, Mtl.Ambient);
        xlat(mat.specular, Mtl.Specular);
        xlat(mat.emissive, Mtl.Emmisive);
        mat.power = Mtl.Power;
        mat.hTexture = 0;
        mat.dwRampSize = 8;

        DD_TRY(material_->SetMaterial(&mat));

        Mtl.Touched = false;
    }
}

i32 agiD3DMtlDef::BeginGfx()
{
    if (Pipe()->HaveGfxStarted())
    {
        if (HaveGfxStarted())
            return AGI_ERROR_ALREADY_INITIALIZED;

        DD_TRY(Pipe()->GetD3D()->CreateMaterial(&material_, NULL));
        state_ = 1;
        Activate();
        DD_TRY(material_->GetHandle(Pipe()->GetD3DDevice(), &handle_));
    }

    return AGI_ERROR_SUCCESS;
}

void agiD3DMtlDef::EndGfx()
{
    DD_RELEASE(material_);
    handle_ = 0;
    state_ = 0;
}