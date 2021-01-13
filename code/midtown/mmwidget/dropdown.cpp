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

define_dummy_symbol(mmwidget_dropdown);

#include "dropdown.h"

#include "data7/metadefine.h"
#include "mmeffects/mmtext.h"

#define MM_DROP_TEXT_EFFECTS (MM_TEXT_VCENTER | MM_TEXT_PADDING | MM_TEXT_REQUIRED)

mmDropDown::mmDropDown() = default;

mmDropDown::~mmDropDown() = default;

void mmDropDown::InitString(string values)
{
    ValueNodes = nullptr;
    DropIndex = nullptr;

    NumValues = values.NumSubStrings();
    ValueNodes = MakeUnique<mmTextNode[]>(NumValues);
    DropIndex = MakeUnique<u32[]>(NumValues);

    DropHeight = NumValues * Height;
    Highlighted = -1;

    SetString(std::move(values));

    for (i32 i = 0; i < NumValues; ++i)
    {
        mmTextNode* node = &ValueNodes[i];
        string value = ValuesString.SubString(i + 1);

        AddChild(node);
        node->Init(X, Bottom + (i * Height), Width, Height, 1, 0);
        DropIndex[i] = node->AddText(Font, value.get_loc(), MM_DROP_TEXT_EFFECTS, 0.0f, 0.0f);
    }

    if (DisabledMask)
        SetDisabledColors();
}

void mmDropDown::SetHighlight(i32 index)
{
    if (Highlighted >= 0 && Highlighted < NumValues)
    {
        ValueNodes[Highlighted].SetEffects(0, MM_DROP_TEXT_EFFECTS);
    }

    if (index >= 0 && index < NumValues)
    {
        i32 effects = MM_DROP_TEXT_EFFECTS | MM_TEXT_BORDER;

        if (!(DisabledMask & (1 << index)))
            effects |= MM_TEXT_HIGHLIGHT;

        ValueNodes[index].SetEffects(0, effects);
    }

    Highlighted = index;
}

META_DEFINE_CHILD("mmDropDown", mmDropDown, asNode)
{}