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
    mmaudio:cd

    0x4F4240 | public: __thiscall CDMan::~CDMan(void) | ??1CDMan@@QAE@XZ
    0x4F4280 | public: unsigned long __thiscall CDMan::Init(short) | ?Init@CDMan@@QAEKF@Z
    0x4F4340 | public: unsigned long __thiscall CDMan::PlayTrack(unsigned char,unsigned char) | ?PlayTrack@CDMan@@QAEKEE@Z
    0x4F4430 | public: unsigned long __thiscall CDMan::ResumePlay(void) | ?ResumePlay@CDMan@@QAEKXZ
    0x4F4450 | public: unsigned long __thiscall CDMan::PlayTrack(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char) | ?PlayTrack@CDMan@@QAEKEEEEE@Z
    0x4F4560 | public: unsigned long __thiscall CDMan::Stop(void) | ?Stop@CDMan@@QAEKXZ
    0x4F45A0 | public: unsigned long __thiscall CDMan::SeekTrack(unsigned char) | ?SeekTrack@CDMan@@QAEKE@Z
    0x4F4610 | public: unsigned long __thiscall CDMan::GetPosition(unsigned char *,unsigned char *,unsigned char *,unsigned char *) | ?GetPosition@CDMan@@QAEKPAE000@Z
    0x4F4690 | private: virtual long __thiscall CDMan::WindowProc(struct HWND__ *,unsigned int,unsigned int,long) | ?WindowProc@CDMan@@EAEJPAUHWND__@@IIJ@Z
    0x4F4700 | public: short __thiscall CDMan::GetNumTracks(void) | ?GetNumTracks@CDMan@@QAEFXZ
*/

#include "eventq7/dispatchable.h"

#include <mciapi.h>

class CDMan final : public Dispatchable
{
    // const CDMan::`vftable' @ 0x61FEF8

public:
    CDMan(HWND window);

    // 0x4F4240 | ??1CDMan@@QAE@XZ
    ARTS_EXPORT ~CDMan();

    // 0x4F4700 | ?GetNumTracks@CDMan@@QAEFXZ
    ARTS_EXPORT i16 GetNumTracks();

    // FIXME: Is actually b32
    // 0x4F4610 | ?GetPosition@CDMan@@QAEKPAE000@Z
    ARTS_EXPORT MCIERROR GetPosition(u8* track, u8* minute, u8* second, u8* frame);

    // 0x4F4280 | ?Init@CDMan@@QAEKF@Z
    ARTS_EXPORT MCIERROR Init(b16 close);

    // FIXME: Is actually b32
    // 0x4F4340 | ?PlayTrack@CDMan@@QAEKEE@Z
    ARTS_EXPORT MCIERROR PlayTrack(u8 track, u8 restart);

    // 0x4F4450 | ?PlayTrack@CDMan@@QAEKEEEEE@Z
    ARTS_EXPORT MCIERROR PlayTrack(u8 track, u8 minute, u8 second, u8 frame, u8 restart);

    // 0x4F4430 | ?ResumePlay@CDMan@@QAEKXZ
    ARTS_EXPORT MCIERROR ResumePlay();

    // 0x4F45A0 | ?SeekTrack@CDMan@@QAEKE@Z | unused
    ARTS_EXPORT MCIERROR SeekTrack(u8 track);

    // 0x4F4560 | ?Stop@CDMan@@QAEKXZ
    ARTS_EXPORT MCIERROR Stop();

private:
    // 0x4F4690 | ?WindowProc@CDMan@@EAEJPAUHWND__@@IIJ@Z
    ARTS_EXPORT LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;

    u16 word4 {0};
    i16 track_count_ {0};
    b16 is_playing_ {0};
    b16 is_opened_ {0};
    HWND window_ {NULL};
    u8 current_track_ {1};
    u8 current_minute_ {0};
    u8 current_second_ {0};
    u8 current_frame_ {0};

    // 0 - Repeat
    // 1 - Regular
    u8 play_mode_ {0};

    MCIDEVICEID device_id_ {0};
    MCI_OPEN_PARMSA open_params_ {};
};

check_size(CDMan, 0x30);
