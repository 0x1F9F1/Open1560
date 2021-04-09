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

HANDLE CopyIoHandle(i32 handle)
{
    DWORD std_handle = 0;

    switch (handle)
    {
        case 0: std_handle = STD_INPUT_HANDLE; break;
        case 1: std_handle = STD_OUTPUT_HANDLE; break;
        case 2: std_handle = STD_ERROR_HANDLE; break;

        default: Quitf("Invalid IO handle %i", handle);
    }

    HANDLE result = NULL;

    return DuplicateHandle(GetCurrentProcess(), GetStdHandle(std_handle), GetCurrentProcess(), &result, 0, FALSE,
               DUPLICATE_SAME_ACCESS)
        ? result
        : INVALID_HANDLE_VALUE;
}

FileStream::FileStream(i32 handle)
    : Stream(nullptr, 0, nullptr)
    , file_handle_(CopyIoHandle(handle))
    , pager_handle_(INVALID_HANDLE_VALUE)
{}

FileStream::FileStream(void* buffer, isize buffer_size, class FileSystem* file_system)
    : Stream(buffer, buffer_size, file_system)
    , file_handle_(INVALID_HANDLE_VALUE)
    , pager_handle_(INVALID_HANDLE_VALUE)
{}

FileStream::~FileStream()
{
    Close();
}

i32 FileStream::Close()
{
    Flush();

    i32 result = -1;

    if (file_mapping_ != nullptr)
    {
        UnmapViewOfFile(file_mapping_);
        file_mapping_ = nullptr;
    }

    if (pager_handle_ != INVALID_HANDLE_VALUE)
    {
        CloseHandle(pager_handle_);
        pager_handle_ = INVALID_HANDLE_VALUE;
    }

    if (file_handle_ != INVALID_HANDLE_VALUE)
    {
        result = CloseHandle(pager_handle_) ? 1 : -1;
        pager_handle_ = INVALID_HANDLE_VALUE;
    }

    return result;
}

i32 FileStream::Create(const char* path)
{
    if (file_handle_ != INVALID_HANDLE_VALUE)
        return -1;

    file_handle_ = CreateFileA(path, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
        CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    return (file_handle_ != INVALID_HANDLE_VALUE) ? 1 : -1;
}

void* FileStream::GetMapping()
{
    return file_mapping_;
}

usize FileStream::GetPagerHandle()
{
    return reinterpret_cast<usize>(pager_handle_);
}

i32 FileStream::Open(const char* path, b32 read_only)
{
    if (file_handle_ != INVALID_HANDLE_VALUE)
        return -1;

    file_handle_ = CreateFileA(path, read_only ? GENERIC_READ : (GENERIC_READ | GENERIC_WRITE),
        FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (file_handle_ == INVALID_HANDLE_VALUE)
        return -1;

    if (read_only)
    {
        pager_handle_ = ReOpenFile(file_handle_, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 0);

        if (pager_handle_ == INVALID_HANDLE_VALUE)
            return -1;

        if (EnableBinaryFileMapping)
        {
            // TODO: Only map .ar files?
            // TODO: Only map when requested?
            HANDLE mapping = CreateFileMappingA(pager_handle_, NULL, PAGE_READONLY, 0, 0, NULL);
            file_mapping_ = MapViewOfFile(mapping, FILE_MAP_READ | FILE_MAP_COPY, 0, 0, 0);
            CloseHandle(mapping);

            if (file_mapping_ == nullptr)
                return -1;

            flags_ |= AGI_STREAM_SUPPORTS_MAPPING;
        }
    }

    return 1;
}

isize FileStream::RawRead(void* ptr, isize size)
{
    DWORD result = 0;

    return ReadFile(file_handle_, ptr, static_cast<DWORD>(size), &result, NULL) ? result : 0;
}

i32 FileStream::RawSeek(i32 pos)
{
    return SetFilePointer(file_handle_, pos, NULL, FILE_BEGIN);
}

i32 FileStream::RawSize()
{
    return GetFileSize(file_handle_, NULL);
}

i32 FileStream::RawTell()
{
    return SetFilePointer(file_handle_, 0, NULL, FILE_CURRENT);
}

isize FileStream::RawWrite(const void* ptr, isize size)
{
    DWORD result = 0;

    return WriteFile(file_handle_, ptr, static_cast<DWORD>(size), &result, NULL) ? result : 0;
}

i32 FileStream::Stderr()
{
    if (file_handle_ != INVALID_HANDLE_VALUE)
        return -1;

    file_handle_ = CopyIoHandle(2);

    return (file_handle_ != INVALID_HANDLE_VALUE) ? 1 : -1;
}

i32 FileStream::Stdin()
{
    if (file_handle_ != INVALID_HANDLE_VALUE)
        return -1;

    file_handle_ = CopyIoHandle(0);

    return (file_handle_ != INVALID_HANDLE_VALUE) ? 1 : -1;
}

i32 FileStream::Stdout()
{
    if (file_handle_ != INVALID_HANDLE_VALUE)
        return -1;

    file_handle_ = CopyIoHandle(1);

    return (file_handle_ != INVALID_HANDLE_VALUE) ? 1 : -1;
}

i32 FileStream::GetError(char* buf, isize buf_len)
{
    DWORD error = GetLastError();
    FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, NULL, error, LANG_SYSTEM_DEFAULT, buf, buf_len, NULL);
    return static_cast<i32>(error);
}

FileStream __stdin(0);
FileStream __stdout(1);

static mem::cmd_param PARAM_mapping {"mapping"};

run_once([] {
    EnableBinaryFileMapping = PARAM_mapping.get_or(false);

    if (EnableBinaryFileMapping) // Sliding modifies TexCoords inplace, which crashes when read-only mapping
        patch_jmp("mmCellRenderer::Cull", "No Sliding", 0x4990FF, jump_type::always);

    create_patch("FileStream", "Custom FileStream", 0x561AB0, "\xC3", 1);
});
