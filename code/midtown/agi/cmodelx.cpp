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

define_dummy_symbol(agi_cmodelx);

#include "cmodelx.h"

#include "surface.h"

RcOwner<class agiColorModel> agiColorModel::FindMatch(agiSurfaceDesc* surface)
{
    return FindMatch(surface->PixelFormat.RBitMask, surface->PixelFormat.GBitMask, surface->PixelFormat.BBitMask,
        surface->PixelFormat.RGBAlphaBitMask);
}

static agiColorModel* const ColorModels[] {
    &ColorModelRGB888,
    &ColorModelRGB888_Rev,
    &ColorModelRGB555,
    &ColorModelRGB565,
    &ColorModelRGB555_Rev,
    &ColorModelRGB565_Rev,
    &ColorModelRGBA5551,
    &ColorModelRGBA4444,
    &ColorModelARGB,
    &ColorModelABGR,
    nullptr,
};

RcOwner<class agiColorModel> agiColorModel::FindMatch(i32 mask_r, i32 mask_g, i32 mask_b, i32 mask_a)
{
    for (agiColorModel* const* models = ColorModels; *models; ++models)
    {
        agiColorModel* model = *models;

        if ((static_cast<u32>(mask_r) == model->GetMaskR()) && (static_cast<u32>(mask_g) == model->GetMaskG()) &&
            (static_cast<u32>(mask_b) == model->GetMaskB()) && (static_cast<u32>(mask_a) == model->GetMaskA()))
        {
            return AsOwner(AddRc(model));
        }
    }

    Quitf("Couldn't find match for R=%x G=%x B=%x A=%x", mask_r, mask_g, mask_b, mask_a);
}
