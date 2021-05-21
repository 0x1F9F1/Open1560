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

define_dummy_symbol(agiworld_getmesh);

#include "getmesh.h"
#include "agi/texdef.h"
#include "pcwindis/setupdata.h"
#include "texsheet.h"

#include <algorithm>

static bool CheckEquals(const char* name, std::initializer_list<const char*> names)
{
    return std::find_if(names.begin(), names.end(), [name](const char* other) { return !std::strcmp(name, other); }) !=
        names.end();
}

void FixTexFlags(agiTexParameters& tex)
{
    agiTexProp* prop = TEXSHEET.Lookup(tex.Name, 0);

    if (!prop)
        return;

    tex.Flags |= agiTexParameters::WrapU | agiTexParameters::WrapV;

    switch (prop->Flags & agiTexProp::ClampModeMask)
    {
        case agiTexProp::ClampUOrBoth:
        case agiTexProp::ClampUOrNeither: tex.Flags &= ~agiTexParameters::WrapU; break;

        case agiTexProp::ClampVOrBoth:
        case agiTexProp::ClampVOrNeither: tex.Flags &= ~agiTexParameters::WrapV; break;

        case agiTexProp::ClampBoth: tex.Flags &= ~(agiTexParameters::WrapU | agiTexParameters::WrapV); break;
    }

    if (prop->Flags & agiTexProp::Transparent)
        tex.Flags |= agiTexParameters::Alpha;

    if (prop->Flags & (agiTexProp::Chromakey | (GetRendererInfo().AdditiveBlending ? agiTexProp::AlphaGlow : 0)))
        tex.Flags |= agiTexParameters::Chromakey;

    tex.Color = prop->Color; // TODO: TEXSHEET.AllowRemapping ? prop->NightColor : prop->DayColor

    if (prop->Flags & agiTexProp::AlphaGlow)
    {
        tex.Props |= agiTexProp::AlphaGlow;

        if (!GetRendererInfo().AdditiveBlending)
            tex.Flags |= agiTexParameters::Alpha;
    }

    if (prop->Flags & agiTexProp::Snowable)
    {
        tex.Props |= agiTexProp::Snowable;
        tex.Flags |= agiTexParameters::KeepLoaded | agiTexParameters::NoMipMaps;
    }

    if (prop->Flags & agiTexProp::Shadow)
        tex.Props |= agiTexProp::Shadow;

    if (prop->Flags & agiTexProp::DullOrDamaged)
        tex.Props |= agiTexProp::DullOrDamaged;

    if (prop->Flags & agiTexProp::NotLit)
        tex.Props |= agiTexProp::NotLit;

    if (prop->Flags & agiTexProp::RoadFloorCeiling)
        tex.Flags |= agiTexParameters::NoMipMaps;

    if (CheckEquals(tex.Name, {"WOMFACE", "MANFACE", "37_INSIDE"}))
        tex.Props |= agiTexProp::AlwaysModulate;

    if (!std::strcmp(tex.Name, "SNOW"))
        tex.Flags |= agiTexParameters::KeepLoaded;

    if (CheckEquals(tex.Name,
            {"T_STOP", "CHECK_POINT_02", "T_1WAY", "T_2WAY", "T_75", "T_DO_NOT_ENTER", "T_EXIT", "T_GLASS", "T_L_ONLY",
                "T_PARK02", "T_WRONGWAY", "FREEWAY_EXITS", "VPSEMI_TRAILER_BED", "T_TUN_TOP", "VABUS_SD"}))
        tex.Props |= agiTexProp::AlwaysPerspCorrect;

    // Reflections will draw over a transparent texture even if part of it is not visible
    if (tex.Flags & agiTexParameters::Alpha)
        tex.Props |= agiTexProp::DullOrDamaged;
}
