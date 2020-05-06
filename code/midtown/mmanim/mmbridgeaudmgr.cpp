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

define_dummy_symbol(mmanim_mmbridgeaudmgr);

#include "mmbridgeaudmgr.h"

mmBridgeAudMgr::mmBridgeAudMgr()
{
    unimplemented();
}

mmBridgeAudMgr::~mmBridgeAudMgr()
{
    unimplemented(arg1);
}

i16 mmBridgeAudMgr::Add(class mmBridgeSet* arg1)
{
    return stub<thiscall_t<i16, mmBridgeAudMgr*, class mmBridgeSet*>>(0x4C3F80, this, arg1);
}

void mmBridgeAudMgr::AssignSounds(i16 arg1)
{
    return stub<thiscall_t<void, mmBridgeAudMgr*, i16>>(0x4C4180, this, arg1);
}

i16 mmBridgeAudMgr::FindGreatestDistance(class mmBridgeSet* arg1)
{
    return stub<thiscall_t<i16, mmBridgeAudMgr*, class mmBridgeSet*>>(0x4C4070, this, arg1);
}

i16 mmBridgeAudMgr::FindUnusedSlot()
{
    return stub<thiscall_t<i16, mmBridgeAudMgr*>>(0x4C4110, this);
}

void mmBridgeAudMgr::Remove(class mmBridgeSet* arg1, i16 arg2)
{
    return stub<thiscall_t<void, mmBridgeAudMgr*, class mmBridgeSet*, i16>>(0x4C4010, this, arg1, arg2);
}

void mmBridgeAudMgr::Update()
{
    return stub<thiscall_t<void, mmBridgeAudMgr*>>(0x4C4150, this);
}
