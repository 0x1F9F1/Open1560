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

define_dummy_symbol(eventq7_replay);

#include "replay.h"

#include "stream/stream.h"

eqReplayChannel* eqReplayChannel::First = nullptr;
b32 eqReplay::Playback = false;
b32 eqReplay::Recording = false;
Stream* eqReplay::ReplayStream = nullptr;

eqReplayChannel::~eqReplayChannel()
{
    if (this == First)
    {
        First = next_;
    }
    else
    {
        Errorf("eqReplayChannel destructed, not top of stack!");
    }
}

void eqReplayChannel::InitRecord()
{}

void eqReplayChannel::InitPlayback()
{}

void eqReplayChannel::ShutdownRecord()
{}

void eqReplayChannel::ShutdownPlayback()
{}

eqReplayChannel::eqReplayChannel(ulong magic)
    : magic_(magic)
    , next_(First)
{
    First = this;
}

void eqReplay::DoPlayback()
{
    ArAssert(Playback, "Not playing back");

    while (true)
    {
        u32 magic = 0;

        if (!ReplayStream->Get(&magic, 1))
        {
            Warningf("End of playback reached, returning to normal.");
            ShutdownPlayback();
            return;
        }

        if (magic == 'ENDF')
            break;

        eqReplayChannel* channel = eqReplayChannel::First;

        while (channel && channel->magic_ != magic)
            channel = channel->next_;

        if (channel)
        {
            channel->DoPlayback(ReplayStream);
        }
        else
        {
            u32 size = ReplayStream->Get<u32>();
            ReplayStream->Seek(ReplayStream->Tell() + size);
        }
    }
}

void eqReplay::DoRecord()
{
    ArAssert(Recording, "Not recording");

    for (eqReplayChannel* i = eqReplayChannel::First; i; i = i->next_)
        i->DoRecord(ReplayStream);

    ReplayStream->Put(u32('ENDF'));
}

void eqReplay::InitPlayback(const char* path)
{
    ArAssert(!Playback && !Recording, "Already opened replay");

    ReplayStream = arts_fopen(path, "r");

    if (!ReplayStream)
        Quitf("asReplay: Cannot open '%s' for playback.", path);

    u32 magic = 0;

    if (!ReplayStream->Get(&magic, 1) || magic != 'EQR1')
        Quitf("Replay file '%s' is truncated, or old version.", path);

    Playback = true;

    for (eqReplayChannel* i = eqReplayChannel::First; i; i = i->next_)
        i->InitPlayback();
}

void eqReplay::InitRecord(const char* path)
{
    ArAssert(!Playback && !Recording, "Already opened replay");

    ReplayStream = arts_fopen(path, "w");

    if (!ReplayStream)
        Quitf("asReplay: Cannot create '%s' for recording.", path);

    ReplayStream->Put(u32('EQR1'));

    Recording = true;

    for (eqReplayChannel* i = eqReplayChannel::First; i; i = i->next_)
        i->InitRecord();
}

void eqReplay::ShutdownPlayback()
{
    ArAssert(Playback, "Not playing back");

    delete ReplayStream;

    Playback = false;

    for (eqReplayChannel* i = eqReplayChannel::First; i; i = i->next_)
        i->ShutdownPlayback();
}

void eqReplay::ShutdownRecord()
{
    ArAssert(Recording, "Not recording");

    delete ReplayStream;

    Recording = false;

    for (eqReplayChannel* i = eqReplayChannel::First; i; i = i->next_)
        i->ShutdownRecord();
}
