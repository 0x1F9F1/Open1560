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

struct IDirectSoundBuffer;
struct tWAVEFORMATEX;

class DupBuffCreator
{
public:
    // ??0DupBuffCreator@@QAE@XZ
    ARTS_IMPORT DupBuffCreator();

    // ??1DupBuffCreator@@QAE@XZ
    ARTS_IMPORT ~DupBuffCreator();

    // ?Add@DupBuffCreator@@QAEXPADPAUIDirectSoundBuffer@@@Z
    ARTS_IMPORT void Add(char* arg1, IDirectSoundBuffer* arg2);

    // ?Create@DupBuffCreator@@QAEPAUIDirectSoundBuffer@@PADPAFPAH@Z
    ARTS_IMPORT IDirectSoundBuffer* Create(char* arg1, i16* arg2, i32* arg3);

    // ?FindOriginal@DupBuffCreator@@QAEPAUIDirectSoundBuffer@@PADPAF@Z
    ARTS_IMPORT IDirectSoundBuffer* FindOriginal(char* arg1, i16* arg2);

private:
    // ?GetWAVEFORMATEX@DupBuffCreator@@AAEPAUtWAVEFORMATEX@@PAUIDirectSoundBuffer@@@Z
    ARTS_IMPORT tWAVEFORMATEX* GetWAVEFORMATEX(IDirectSoundBuffer* arg1);

    // ?IntegrityCheck@DupBuffCreator@@AAEHPAUIDirectSoundBuffer@@0PAH@Z
    ARTS_IMPORT i32 IntegrityCheck(IDirectSoundBuffer* arg1, IDirectSoundBuffer* arg2, i32* arg3);

    u8 gap0[0x8];
};

check_size(DupBuffCreator, 0x8);

// ?DUPBUFCREATORPTR@@3PAVDupBuffCreator@@A
ARTS_IMPORT extern DupBuffCreator* DUPBUFCREATORPTR;
