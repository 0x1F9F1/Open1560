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

#pragma once

class eqReplayChannel
{
public:
    // ??1eqReplayChannel@@QAE@XZ
    ARTS_EXPORT ~eqReplayChannel();

    // ?InitRecord@eqReplayChannel@@UAEXXZ
    ARTS_EXPORT virtual void InitRecord();

    // ?InitPlayback@eqReplayChannel@@UAEXXZ
    ARTS_EXPORT virtual void InitPlayback();

    virtual void DoRecord(Stream* arg1) = 0;

    virtual void DoPlayback(Stream* arg1) = 0;

    // ?ShutdownRecord@eqReplayChannel@@UAEXXZ
    ARTS_EXPORT virtual void ShutdownRecord();

    // ?ShutdownPlayback@eqReplayChannel@@UAEXXZ
    ARTS_EXPORT virtual void ShutdownPlayback();

    u32 GetMagic() const
    {
        return magic_;
    }

protected:
    // ??0eqReplayChannel@@IAE@K@Z
    ARTS_EXPORT eqReplayChannel(ulong magic);

private:
    // ?First@eqReplayChannel@@0PAV1@A
    ARTS_EXPORT static eqReplayChannel* First;

    u32 magic_ {};
    eqReplayChannel* next_ {};

    friend class eqReplay;
};

check_size(eqReplayChannel, 0xC);

class eqReplay
{
public:
    // ?DoPlayback@eqReplay@@SAXXZ
    ARTS_EXPORT static void DoPlayback();

    // ?DoRecord@eqReplay@@SAXXZ
    ARTS_EXPORT static void DoRecord();

    // ?InitPlayback@eqReplay@@SAXPAD@Z
    ARTS_EXPORT static void InitPlayback(const char* path);

    // ?InitRecord@eqReplay@@SAXPAD@Z
    ARTS_EXPORT static void InitRecord(const char* path);

    // ?ShutdownPlayback@eqReplay@@SAXXZ
    ARTS_EXPORT static void ShutdownPlayback();

    // ?ShutdownRecord@eqReplay@@SAXXZ
    ARTS_EXPORT static void ShutdownRecord();

    // ?Playback@eqReplay@@2HA
    ARTS_EXPORT static b32 Playback;

    // ?Recording@eqReplay@@2HA
    ARTS_EXPORT static b32 Recording;

private:
    // ?ReplayStream@eqReplay@@0PAVStream@@A
    ARTS_EXPORT static Stream* ReplayStream;
};
