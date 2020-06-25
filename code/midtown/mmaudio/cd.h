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

struct CDMan
{
    // const CDMan::`vftable' @ 0x61FEF8

public:
    // 0x4F4240 | ??1CDMan@@QAE@XZ
    ARTS_IMPORT ~CDMan();

    // 0x4F4700 | ?GetNumTracks@CDMan@@QAEFXZ
    ARTS_IMPORT i16 GetNumTracks();

    // 0x4F4610 | ?GetPosition@CDMan@@QAEKPAE000@Z
    ARTS_IMPORT u32 GetPosition(u8* arg1, u8* arg2, u8* arg3, u8* arg4);

    // 0x4F4280 | ?Init@CDMan@@QAEKF@Z
    ARTS_IMPORT u32 Init(i16 arg1);

    // 0x4F4340 | ?PlayTrack@CDMan@@QAEKEE@Z
    ARTS_IMPORT u32 PlayTrack(u8 arg1, u8 arg2);

    // 0x4F4450 | ?PlayTrack@CDMan@@QAEKEEEEE@Z
    ARTS_IMPORT u32 PlayTrack(u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5);

    // 0x4F4430 | ?ResumePlay@CDMan@@QAEKXZ
    ARTS_IMPORT u32 ResumePlay();

    // 0x4F45A0 | ?SeekTrack@CDMan@@QAEKE@Z | unused
    ARTS_IMPORT u32 SeekTrack(u8 arg1);

    // 0x4F4560 | ?Stop@CDMan@@QAEKXZ
    ARTS_IMPORT u32 Stop();

private:
    // 0x4F4690 | ?WindowProc@CDMan@@EAEJPAUHWND__@@IIJ@Z
    ARTS_IMPORT virtual i32 WindowProc(struct HWND__* arg1, u32 arg2, u32 arg3, i32 arg4);
};

check_size(CDMan, 0x0);
