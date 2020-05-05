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

define_dummy_symbol(stream_vstream);

#include "vstream.h"

VirtualStream::VirtualStream(
    class Stream* arg1, struct VirtualFileInode* arg2, void* arg3, i32 arg4, class FileSystem* arg5)
{
    unimplemented(arg1, arg2, arg3, arg4, arg5);
}

VirtualStream::~VirtualStream()
{
    unimplemented(arg1);
}

void* VirtualStream::GetMapping()
{
    return stub<thiscall_t<void*, VirtualStream*>>(0x161D40_Offset, this);
}

i32 VirtualStream::GetPagingInfo(u32& arg1, u32& arg2, u32& arg3)
{
    return stub<thiscall_t<i32, VirtualStream*, u32&, u32&, u32&>>(0x161BD0_Offset, this, arg1, arg2, arg3);
}

i32 VirtualStream::RawRead(void* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, VirtualStream*, void*, i32>>(0x161C60_Offset, this, arg1, arg2);
}

i32 VirtualStream::RawSeek(i32 arg1)
{
    return stub<thiscall_t<i32, VirtualStream*, i32>>(0x161CE0_Offset, this, arg1);
}

i32 VirtualStream::RawSize()
{
    return stub<thiscall_t<i32, VirtualStream*>>(0x161D30_Offset, this);
}

i32 VirtualStream::RawTell()
{
    return stub<thiscall_t<i32, VirtualStream*>>(0x161D10_Offset, this);
}

i32 VirtualStream::RawWrite(void* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, VirtualStream*, void*, i32>>(0x161CD0_Offset, this, arg1, arg2);
}
