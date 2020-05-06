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

define_dummy_symbol(mmgame_cd);

#include "cd.h"

mmCDPlayer::mmCDPlayer()
{
    unimplemented();
}

mmCDPlayer::~mmCDPlayer()
{
    unimplemented(arg1);
}

void mmCDPlayer::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmCDPlayer*, class Bank*>>(0x4234C0, this, arg1);
}

void mmCDPlayer::Cull()
{
    return stub<thiscall_t<void, mmCDPlayer*>>(0x423210, this);
}

void mmCDPlayer::Init(class mmHUD* arg1)
{
    return stub<thiscall_t<void, mmCDPlayer*, class mmHUD*>>(0x423080, this, arg1);
}

void mmCDPlayer::NextTrack()
{
    return stub<thiscall_t<void, mmCDPlayer*>>(0x423450, this);
}

void mmCDPlayer::PlayStop()
{
    return stub<thiscall_t<void, mmCDPlayer*>>(0x423400, this);
}

void mmCDPlayer::PrevTrack()
{
    return stub<thiscall_t<void, mmCDPlayer*>>(0x423750, this);
}

void mmCDPlayer::Reset()
{
    return stub<thiscall_t<void, mmCDPlayer*>>(0x423190, this);
}

void mmCDPlayer::Toggle()
{
    return stub<thiscall_t<void, mmCDPlayer*>>(0x4237C0, this);
}

void mmCDPlayer::Update()
{
    return stub<thiscall_t<void, mmCDPlayer*>>(0x4231A0, this);
}
