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
public:
    // ??1eqReplayChannel@@QAE@XZ
    ARTS_EXPORT ~eqReplayChannel();

    // ?InitRecord@eqReplayChannel@@UAEXXZ
    ARTS_EXPORT virtual void InitRecord();

    // ?InitPlayback@eqReplayChannel@@UAEXXZ
    ARTS_EXPORT virtual void InitPlayback();

    virtual void DoRecord(class Stream* arg1) = 0;

    virtual void DoPlayback(class Stream* arg1) = 0;

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
    ARTS_IMPORT static class eqReplayChannel* First;

    u32 magic_ {0};
    eqReplayChannel* next_ {nullptr};

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
    ARTS_IMPORT static b32 Playback;

    // ?Recording@eqReplay@@2HA
    ARTS_IMPORT static b32 Recording;

private:
    // ?ReplayStream@eqReplay@@0PAVStream@@A
    ARTS_IMPORT static class Stream* ReplayStream;
};
