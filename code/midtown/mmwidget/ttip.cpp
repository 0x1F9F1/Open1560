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

#include "ttip.h"

mmToolTip::mmToolTip()
{
    unimplemented();
}

mmToolTip::~mmToolTip()
{
    unimplemented();
}

void mmToolTip::Init(class UIMenu* arg1, struct LocString* arg2)
{
    return stub<thiscall_t<void, mmToolTip*, class UIMenu*, struct LocString*>>(0xBF1B0_Offset, this, arg1, arg2);
}

void mmToolTip::SetText(struct LocString* arg1)
{
    return stub<thiscall_t<void, mmToolTip*, struct LocString*>>(0xBF260_Offset, this, arg1);
}

void mmToolTip::Switch(i32 arg1)
{
    return stub<thiscall_t<void, mmToolTip*, i32>>(0xBF280_Offset, this, arg1);
}

void mmToolTip::Update()
{
    return stub<thiscall_t<void, mmToolTip*>>(0xBF290_Offset, this);
}

define_dummy_symbol(mmwidget_ttip);
