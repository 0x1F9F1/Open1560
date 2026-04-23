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

static constexpr i32 MAX_VISIBLE_ROWS = 15;

mmDropDown::mmDropDown() = default;

mmDropDown::~mmDropDown() = default;

void mmDropDown::InitString(string values)
{
    ValueNodes = nullptr;
    DropIndex = nullptr;

    NumValues = values.NumSubStrings();
    ScrollOffset = 0;

    const i32 visibleCount = (NumValues < MAX_VISIBLE_ROWS) ? NumValues : MAX_VISIBLE_ROWS;

    ValueNodes = arnewa mmTextNode[visibleCount] {};
    DropIndex = arnewa u32[visibleCount] {};

    DropHeight = visibleCount * Height;
    Highlighted = -1;

    SetString(std::move(values));

    for (i32 i = 0; i < visibleCount; ++i)
    {
        mmTextNode* node = &ValueNodes[i];
        const i32 realIndex = ScrollOffset + i;
        string value = ValuesString.SubString(realIndex + 1);

        AddChild(node);
        node->Init(X, Bottom + (i * Height), Width, Height, 1, 0);
        DropIndex[i] = node->AddText(Font, value.get_loc(), MM_DROP_TEXT_EFFECTS, 0.0f, 0.0f);
    }

    if (DisabledMask)
        SetDisabledColors();
}

void mmDropDown::SetHighlight(i32 index)
{
    const i32 visibleCount = GetVisibleCount();

    // Clamp index
    if (index < -1)
        index = -1;
    if (index >= NumValues)
        index = NumValues - 1;

    // Auto scroll if needed
    if (index >= 0)
    {
        if (index < ScrollOffset)
            ScrollOffset = index;
        else if (index >= ScrollOffset + visibleCount)
            ScrollOffset = index - (visibleCount - 1);
    }

    // Clamp ScrollOffset
    if (ScrollOffset < 0)
        ScrollOffset = 0;

    const i32 maxScroll = (NumValues > visibleCount) ? (NumValues - visibleCount) : 0;
    if (ScrollOffset > maxScroll)
        ScrollOffset = maxScroll;

    // Refresh visible text to match scroll
    RefreshVisible();

    // Clear effects for all visible rows (prevents duplicate highlight)
    for (i32 i = 0; i < visibleCount; ++i)
    {
        ValueNodes[i].SetEffects(0, MM_DROP_TEXT_EFFECTS);
    }

    // Apply new highlight if it is visible
    if (index >= ScrollOffset && index < ScrollOffset + visibleCount)
    {
        const i32 vis = index - ScrollOffset;

        i32 effects = MM_DROP_TEXT_EFFECTS | MM_TEXT_BORDER;

        if (!(DisabledMask & (1 << index)))
            effects |= MM_TEXT_HIGHLIGHT;

        ValueNodes[vis].SetEffects(0, effects);
    }

    Highlighted = index;
}

i32 mmDropDown::GetVisibleCount() const
{
    return (NumValues < MAX_VISIBLE_ROWS) ? NumValues : MAX_VISIBLE_ROWS;
}

void mmDropDown::RefreshVisible()
{
    const i32 visibleCount = GetVisibleCount();

    // Clamp ScrollOffset
    if (ScrollOffset < 0)
        ScrollOffset = 0;

    const i32 maxScroll = (NumValues > visibleCount) ? (NumValues - visibleCount) : 0;
    if (ScrollOffset > maxScroll)
        ScrollOffset = maxScroll;

    for (i32 i = 0; i < visibleCount; ++i)
    {
        const i32 realIndex = ScrollOffset + i;

        string value = ValuesString.SubString(realIndex + 1);

        // Update existing line instead of adding a new one
        ValueNodes[i].SetString(DropIndex[i], value.get_loc());
    }
}

META_DEFINE_CHILD("mmDropDown", mmDropDown, asNode)
{}