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

#include "dupbufcreator.h"

DupBuffCreator::DupBuffCreator()
{
    unimplemented();
}

DupBuffCreator::~DupBuffCreator()
{
    unimplemented();
}

void DupBuffCreator::Add(char* arg1, struct IDirectSoundBuffer* arg2)
{
    return stub<thiscall_t<void, DupBuffCreator*, char*, struct IDirectSoundBuffer*>>(0xEED60_Offset, this, arg1, arg2);
}

struct IDirectSoundBuffer* DupBuffCreator::Create(char* arg1, i16* arg2, i32* arg3)
{
    return stub<thiscall_t<struct IDirectSoundBuffer*, DupBuffCreator*, char*, i16*, i32*>>(
        0xEEC60_Offset, this, arg1, arg2, arg3);
}

struct IDirectSoundBuffer* DupBuffCreator::FindOriginal(char* arg1, i16* arg2)
{
    return stub<thiscall_t<struct IDirectSoundBuffer*, DupBuffCreator*, char*, i16*>>(0xEEF00_Offset, this, arg1, arg2);
}

struct tWAVEFORMATEX* DupBuffCreator::GetWAVEFORMATEX(struct IDirectSoundBuffer* arg1)
{
    return stub<thiscall_t<struct tWAVEFORMATEX*, DupBuffCreator*, struct IDirectSoundBuffer*>>(
        0xEEF90_Offset, this, arg1);
}

i32 DupBuffCreator::IntegrityCheck(struct IDirectSoundBuffer* arg1, struct IDirectSoundBuffer* arg2, i32* arg3)
{
    return stub<thiscall_t<i32, DupBuffCreator*, struct IDirectSoundBuffer*, struct IDirectSoundBuffer*, i32*>>(
        0xEF010_Offset, this, arg1, arg2, arg3);
}

define_dummy_symbol(mmaudio_dupbufcreator);
