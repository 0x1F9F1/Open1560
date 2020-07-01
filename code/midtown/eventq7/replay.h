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

/*
    eventq7:replay

    0x564620 | protected: __thiscall eqReplayChannel::eqReplayChannel(unsigned long) | ??0eqReplayChannel@@IAE@K@Z
    0x564650 | public: __thiscall eqReplayChannel::~eqReplayChannel(void) | ??1eqReplayChannel@@QAE@XZ
    0x564680 | public: virtual void __thiscall eqReplayChannel::InitRecord(void) | ?InitRecord@eqReplayChannel@@UAEXXZ
    0x564690 | public: virtual void __thiscall eqReplayChannel::InitPlayback(void) | ?InitPlayback@eqReplayChannel@@UAEXXZ
    0x5646A0 | public: virtual void __thiscall eqReplayChannel::ShutdownRecord(void) | ?ShutdownRecord@eqReplayChannel@@UAEXXZ
    0x5646B0 | public: virtual void __thiscall eqReplayChannel::ShutdownPlayback(void) | ?ShutdownPlayback@eqReplayChannel@@UAEXXZ
    0x5646C0 | public: static void __cdecl eqReplay::InitRecord(char *) | ?InitRecord@eqReplay@@SAXPAD@Z
    0x564750 | public: static void __cdecl eqReplay::InitPlayback(char *) | ?InitPlayback@eqReplay@@SAXPAD@Z
    0x564800 | public: static void __cdecl eqReplay::ShutdownRecord(void) | ?ShutdownRecord@eqReplay@@SAXXZ
    0x564860 | public: static void __cdecl eqReplay::ShutdownPlayback(void) | ?ShutdownPlayback@eqReplay@@SAXXZ
    0x5648C0 | public: static void __cdecl eqReplay::DoRecord(void) | ?DoRecord@eqReplay@@SAXXZ
    0x564920 | public: static void __cdecl eqReplay::DoPlayback(void) | ?DoPlayback@eqReplay@@SAXXZ
    0x621B20 | const eqReplayChannel::`vftable' | ??_7eqReplayChannel@@6B@
    0x909438 | private: static class eqReplayChannel * eqReplayChannel::First | ?First@eqReplayChannel@@0PAV1@A
    0x90943C | private: static class Stream * eqReplay::ReplayStream | ?ReplayStream@eqReplay@@0PAVStream@@A
    0x909440 | public: static int eqReplay::Playback | ?Playback@eqReplay@@2HA
    0x909444 | public: static int eqReplay::Recording | ?Recording@eqReplay@@2HA
*/

class eqReplayChannel
{
    // const eqReplayChannel::`vftable' @ 0x621B20

public:
    // 0x564650 | ??1eqReplayChannel@@QAE@XZ
    ARTS_IMPORT ~eqReplayChannel();

    // 0x564680 | ?InitRecord@eqReplayChannel@@UAEXXZ
    ARTS_EXPORT virtual void InitRecord();

    // 0x564690 | ?InitPlayback@eqReplayChannel@@UAEXXZ
    ARTS_EXPORT virtual void InitPlayback();

    virtual void DoRecord(class Stream* arg1) = 0;

    virtual void DoPlayback(class Stream* arg1) = 0;

    // 0x5646A0 | ?ShutdownRecord@eqReplayChannel@@UAEXXZ
    ARTS_EXPORT virtual void ShutdownRecord();

    // 0x5646B0 | ?ShutdownPlayback@eqReplayChannel@@UAEXXZ
    ARTS_EXPORT virtual void ShutdownPlayback();

protected:
    // 0x564620 | ??0eqReplayChannel@@IAE@K@Z
    ARTS_IMPORT eqReplayChannel(u32 arg1);

private:
    // 0x909438 | ?First@eqReplayChannel@@0PAV1@A
    ARTS_IMPORT static class eqReplayChannel* First;

    u8 gap4[0x8];
};

check_size(eqReplayChannel, 0xC);

class eqReplay
{
public:
    // 0x564920 | ?DoPlayback@eqReplay@@SAXXZ
    ARTS_IMPORT static void DoPlayback();

    // 0x5648C0 | ?DoRecord@eqReplay@@SAXXZ
    ARTS_IMPORT static void DoRecord();

    // 0x564750 | ?InitPlayback@eqReplay@@SAXPAD@Z
    ARTS_IMPORT static void InitPlayback(char* arg1);

    // 0x5646C0 | ?InitRecord@eqReplay@@SAXPAD@Z
    ARTS_IMPORT static void InitRecord(char* arg1);

    // 0x564860 | ?ShutdownPlayback@eqReplay@@SAXXZ
    ARTS_IMPORT static void ShutdownPlayback();

    // 0x564800 | ?ShutdownRecord@eqReplay@@SAXXZ
    ARTS_IMPORT static void ShutdownRecord();

    // 0x909440 | ?Playback@eqReplay@@2HA
    ARTS_IMPORT static i32 Playback;

    // 0x909444 | ?Recording@eqReplay@@2HA
    ARTS_IMPORT static i32 Recording;

private:
    // 0x90943C | ?ReplayStream@eqReplay@@0PAVStream@@A
    ARTS_IMPORT static class Stream* ReplayStream;
};
