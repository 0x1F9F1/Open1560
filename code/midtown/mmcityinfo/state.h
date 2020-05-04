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
    mmcityinfo:state

    0x4CBB40 | public: virtual __thiscall mmPlayerData::~mmPlayerData(void) | ??1mmPlayerData@@UAE@XZ
    0x4CBBE0 | public: virtual void * __thiscall mmPlayerData::`scalar deleting destructor'(unsigned int) | ??_GmmPlayerData@@UAEPAXI@Z
    0x61F898 | const mmPlayerData::`vftable' | ??_7mmPlayerData@@6B@
    0x706068 | struct mmStatePack MMSTATE | ?MMSTATE@@3UmmStatePack@@A
    0x706360 | int CHEATING | ?CHEATING@@3HA
    0x706368 | class mmPlayerData MMCURRPLAYER | ?MMCURRPLAYER@@3VmmPlayerData@@A
    0x7084E0 | int CHICAGO | ?CHICAGO@@3HA
*/

// 0x706360 | ?CHEATING@@3HA
inline extern_var(0x306360_Offset, i32, CHEATING);

// 0x7084E0 | ?CHICAGO@@3HA
inline extern_var(0x3084E0_Offset, i32, CHICAGO);

// 0x706368 | ?MMCURRPLAYER@@3VmmPlayerData@@A
inline extern_var(0x306368_Offset, class mmPlayerData, MMCURRPLAYER);

// 0x706068 | ?MMSTATE@@3UmmStatePack@@A
inline extern_var(0x306068_Offset, struct mmStatePack, MMSTATE);
