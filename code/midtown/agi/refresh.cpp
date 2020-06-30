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

define_dummy_symbol(agi_refresh);

#include "refresh.h"

#include "pipeline.h"

agiRefreshable::agiRefreshable(agiPipeline* pipe)
    : pipe_(pipe)
{
    pipe_->NotifyNew(this);
}

void agiRefreshable::Restore()
{}

const char* agiRefreshable::GetName()
{
    return "generic refreshable";
}

agiRefreshable::~agiRefreshable()
{
    if (state_ != 0)
        Quitf("agiRefreshable subclass didn't clean up");

    if (ref_count_)
        Errorf("agiRefreshable subclass deleted instead of Release'd?");

    if (pipe_)
        pipe_->NotifyDelete(this);
}

void agiRefreshable::AddRef()
{
    ValidatePtr("AddRef");

    ++ref_count_;
}

i32 agiRefreshable::Release()
{
    ValidatePtr("Release");

    i32 refs = --ref_count_;

    if (refs == 0)
    {
        EndGfx();

        delete this;
    }

    return refs;
}

i32 agiRefreshable::SafeBeginGfx()
{
    if (!pipe_ || !pipe_->GfxStarted)
        return 0;

    if (state_ != 0)
        return -3;

    return BeginGfx();
}

b32 agiRefreshable::IsTexture()
{
    return false;
}

void agiRefreshable::ValidatePtr(const char* reason)
{
    usize volatile ptr = reinterpret_cast<usize>(this);

    switch (ptr)
    {
        case 0x00000000: Quitf("'%s' on NULL ptr", reason);
        case 0xCDCDCDCD: Quitf("'%s' on uninitialized ptr (0xCD).", reason);
        case 0xDDDDDDDD: Quitf("'%s' on deleted ptr (0xDD).", reason);

        default: break;
    }
}
