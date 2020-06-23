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

define_dummy_symbol(stream_filestream);

#include "filestream.h"

// TODO: Avoid using io.h functions

#include "core/minwin.h"
#include <fcntl.h>
#include <io.h>

FileStream::FileStream(i32 handle)
    : Stream(nullptr, 0, nullptr)
    , file_handle_(handle)
{}

FileStream::FileStream(void* buffer, i32 buffer_size, class FileSystem* file_system)
    : Stream(buffer, buffer_size, file_system)
{}

FileStream::~FileStream()
{
    Close();
}

i32 FileStream::Close()
{
    Flush();

    i32 result = -1;

    if (file_handle_ != -1)
    {
        result = _close(file_handle_);
        file_handle_ = -1;
    }

    if (pager_handle_)
    {
        CloseHandle(pager_handle_);
        pager_handle_ = nullptr;
    }

    return result;
}

i32 FileStream::Create(const char* path)
{
    if (file_handle_ != -1)
        return -1;

    if (_sopen_s(&file_handle_, path, _O_WRONLY | _O_TRUNC | _O_CREAT | _O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE) !=
        0)
        file_handle_ = -1;

    return file_handle_;
}

usize FileStream::GetPagerHandle()
{
    return reinterpret_cast<usize>(pager_handle_);
}

i32 FileStream::Open(const char* path, b32 read_only)
{
    if (file_handle_ != -1)
        return -1;

    pager_handle_ = read_only
        ? CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr)
        : nullptr;

    if (_sopen_s(
            &file_handle_, path, (read_only ? _O_RDONLY : _O_RDWR) | _O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE) != 0)
        file_handle_ = -1;

    return file_handle_;
}

i32 FileStream::RawRead(void* ptr, i32 size)
{
    return _read(file_handle_, ptr, size);
}

i32 FileStream::RawSeek(i32 pos)
{
    return _lseek(file_handle_, pos, SEEK_SET);
}

i32 FileStream::RawSize()
{
    i32 pos = RawTell();
    i32 end = _lseek(file_handle_, 0, SEEK_END);

    if (pos != end)
        RawSeek(pos);

    return end;
}

i32 FileStream::RawTell()
{
    return _lseek(file_handle_, 0, SEEK_CUR);
}

i32 FileStream::RawWrite(const void* ptr, i32 size)
{
    return _write(file_handle_, ptr, size);
}

i32 FileStream::Stderr()
{
    if (file_handle_ != -1)
        return -1;

    file_handle_ = 2;

    return file_handle_;
}

i32 FileStream::Stdin()
{
    if (file_handle_ != -1)
        return -1;

    file_handle_ = 0;

    return file_handle_;
}

i32 FileStream::Stdout()
{
    if (file_handle_ != -1)
        return -1;

    file_handle_ = 1;

    return file_handle_;
}
