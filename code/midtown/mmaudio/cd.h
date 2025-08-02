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

#include "eventq7/dispatchable.h"

#include <mciapi.h>

class CDMan final : public Dispatchable
{
public:
    CDMan(HWND window);

    // ??1CDMan@@QAE@XZ
    ARTS_EXPORT ~CDMan();

    // ?GetNumTracks@CDMan@@QAEFXZ
    ARTS_EXPORT i16 GetNumTracks();

    // FIXME: Is actually b32
    // ?GetPosition@CDMan@@QAEKPAE000@Z
    ARTS_EXPORT MCIERROR GetPosition(u8* track, u8* minute, u8* second, u8* frame);

    // ?Init@CDMan@@QAEKF@Z
    ARTS_EXPORT MCIERROR Init(b16 close);

    // FIXME: Is actually b32
    // ?PlayTrack@CDMan@@QAEKEE@Z
    ARTS_EXPORT MCIERROR PlayTrack(u8 track, u8 restart);

    // ?PlayTrack@CDMan@@QAEKEEEEE@Z
    ARTS_EXPORT MCIERROR PlayTrack(u8 track, u8 minute, u8 second, u8 frame, u8 restart);

    // ?ResumePlay@CDMan@@QAEKXZ
    ARTS_EXPORT MCIERROR ResumePlay();

    // ?SeekTrack@CDMan@@QAEKE@Z | unused
    ARTS_EXPORT MCIERROR SeekTrack(u8 track);

    // ?Stop@CDMan@@QAEKXZ
    ARTS_EXPORT MCIERROR Stop();

private:
    // ?WindowProc@CDMan@@EAEJPAUHWND__@@IIJ@Z
    ARTS_EXPORT LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;

    u16 word4 {};
    i16 track_count_ {};
    b16 is_playing_ {};
    b16 is_opened_ {};
    HWND window_ {};
    u8 current_track_ {1};
    u8 current_minute_ {};
    u8 current_second_ {};
    u8 current_frame_ {};

    // 0 - Repeat
    // 1 - Regular
    u8 play_mode_ {};

    MCIDEVICEID device_id_ {};
    MCI_OPEN_PARMSA open_params_ {};
};

check_size(CDMan, 0x30);
