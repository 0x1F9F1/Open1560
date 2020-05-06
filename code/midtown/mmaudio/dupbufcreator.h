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
    mmaudio:dupbufcreator

    0x4EEBC0 | public: __thiscall DupBuffCreator::DupBuffCreator(void) | ??0DupBuffCreator@@QAE@XZ
    0x4EEC00 | public: __thiscall DupBuffCreator::~DupBuffCreator(void) | ??1DupBuffCreator@@QAE@XZ
    0x4EEC60 | public: struct IDirectSoundBuffer * __thiscall DupBuffCreator::Create(char *,short *,int *) | ?Create@DupBuffCreator@@QAEPAUIDirectSoundBuffer@@PADPAFPAH@Z
    0x4EED60 | public: void __thiscall DupBuffCreator::Add(char *,struct IDirectSoundBuffer *) | ?Add@DupBuffCreator@@QAEXPADPAUIDirectSoundBuffer@@@Z
    0x4EEF00 | public: struct IDirectSoundBuffer * __thiscall DupBuffCreator::FindOriginal(char *,short *) | ?FindOriginal@DupBuffCreator@@QAEPAUIDirectSoundBuffer@@PADPAF@Z
    0x4EEF90 | private: struct tWAVEFORMATEX * __thiscall DupBuffCreator::GetWAVEFORMATEX(struct IDirectSoundBuffer *) | ?GetWAVEFORMATEX@DupBuffCreator@@AAEPAUtWAVEFORMATEX@@PAUIDirectSoundBuffer@@@Z
    0x4EF010 | private: int __thiscall DupBuffCreator::IntegrityCheck(struct IDirectSoundBuffer *,struct IDirectSoundBuffer *,int *) | ?IntegrityCheck@DupBuffCreator@@AAEHPAUIDirectSoundBuffer@@0PAH@Z
    0x719330 | class DupBuffCreator * DUPBUFCREATORPTR | ?DUPBUFCREATORPTR@@3PAVDupBuffCreator@@A
*/

class DupBuffCreator
{
public:
    // 0x4EEBC0 | ??0DupBuffCreator@@QAE@XZ
    DupBuffCreator();

    // 0x4EEC00 | ??1DupBuffCreator@@QAE@XZ
    ~DupBuffCreator();

    // 0x4EED60 | ?Add@DupBuffCreator@@QAEXPADPAUIDirectSoundBuffer@@@Z
    void Add(char* arg1, struct IDirectSoundBuffer* arg2);

    // 0x4EEC60 | ?Create@DupBuffCreator@@QAEPAUIDirectSoundBuffer@@PADPAFPAH@Z
    struct IDirectSoundBuffer* Create(char* arg1, i16* arg2, i32* arg3);

    // 0x4EEF00 | ?FindOriginal@DupBuffCreator@@QAEPAUIDirectSoundBuffer@@PADPAF@Z
    struct IDirectSoundBuffer* FindOriginal(char* arg1, i16* arg2);

private:
    // 0x4EEF90 | ?GetWAVEFORMATEX@DupBuffCreator@@AAEPAUtWAVEFORMATEX@@PAUIDirectSoundBuffer@@@Z
    struct tWAVEFORMATEX* GetWAVEFORMATEX(struct IDirectSoundBuffer* arg1);

    // 0x4EF010 | ?IntegrityCheck@DupBuffCreator@@AAEHPAUIDirectSoundBuffer@@0PAH@Z
    i32 IntegrityCheck(struct IDirectSoundBuffer* arg1, struct IDirectSoundBuffer* arg2, i32* arg3);
};

check_size(DupBuffCreator, 0x8);

// 0x719330 | ?DUPBUFCREATORPTR@@3PAVDupBuffCreator@@A
inline extern_var(0x719330, class DupBuffCreator*, DUPBUFCREATORPTR);
