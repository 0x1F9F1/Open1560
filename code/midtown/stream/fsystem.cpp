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

define_dummy_symbol(stream_fsystem);

#include "fsystem.h"

FileSystem::FileSystem()
{
    if (FSCount >= MAX_FILESYSTEMS)
        Abortf("Out of FileSystems, raise MAX_FILESYSTEMS");

    FS[FSCount++] = this;

    fs_index_ = FSCount;
}

FileSystem::~FileSystem()
{
    if (fs_index_ != FSCount)
        Errorf("FileSystems destructed out of order.");

    --FSCount;
}

b32 FileSystem::PagerInfo(const char*, struct PagerInfo_t&)
{
    return false;
}

static inline constexpr bool IsSubStringBorder(char c)
{
    return (c == '|') || (c == ';');
}

static i32 NumSubStrings(const char* strs)
{
    i32 num = 1;

    for (; *strs; ++strs)
    {
        if (IsSubStringBorder(*strs))
            ++num;
    }

    return num;
}

// TODO: Avoid this static buffer
static char SubStringBuffer[256];

static const char* SubString(i32 idx, const char* strs)
{
    i32 num = 1;
    i32 start = 0;

    for (; num != idx; ++start)
    {
        char c = strs[start];

        if (c == '\0')
            break;

        if (IsSubStringBorder(c))
            ++num;
    }

    if (num == idx)
    {
        i32 i = 0;

        for (; i < 255; ++i)
        {
            char c = strs[start + i];

            if (c == '\0')
                break;

            // TODO: Is this check correct? It was originally `(c == '|' && c != ';')`, but that doesn't make much sense
            if (IsSubStringBorder(c))
                break;

            SubStringBuffer[i] = c;
        }

        SubStringBuffer[i] = '\0';
        return SubStringBuffer;
    }
    else
    {
        SubStringBuffer[0] = '\0';
    }

    return SubStringBuffer;
}

static i32 Contains(const char* strs, const char* str)
{
    for (i32 i = 1, num = NumSubStrings(strs); i <= num; ++i)
    {
        if (!std::strcmp(str, SubString(i, strs)))
            return true;
    }

    return false;
}

static void ExpandEnvs(char* /*str*/)
{}

b32 FileSystem::Search(const char* file, const char* folder, const char* ext, i32 ext_id, char* output, i32 buffer_len)
{
    // NOTE: Incompatible

    char file_path[256];
    file_path[0] = '\0';

    char file_name[256];
    arts_strcpy(file_name, file);

    if (IsPhysicalPath(file_name))
    {
        for (i32 i = std::strlen(file) - 1; i >= 0; --i)
        {
            if (IsPathSeparator(file[i]))
            {
                arts_strncpy(file_path, file, i);
                arts_strcpy(file_name, file + i + 1);
                break;
            }
        }
    }

    char file_ext[256];
    file_ext[0] = '\0';

    if (ext)
    {
        for (i32 i = std::strlen(file_name) - 1; i >= 0; --i)
        {
            if (file_name[i] == '.')
            {
                arts_strcpy(file_ext, file_name + i);

                if (Contains(ext, file_ext))
                    file_name[i] = '\0';
                else
                    file_ext[0] = '\0';

                break;
            }
        }
    }

    if (ext_id >= 1 && ext_id <= 9999)
    {
        char ext_id_str[256];
        arts_sprintf(ext_id_str, ".%04d", ext_id);
        arts_strcat(file_name, ext_id_str);
    }

    char folders[256];
    arts_strcpy(folders, file_path[0] ? file_path : (folder && *folder) ? folder : ".");

    char exts[256];
    arts_strcpy(exts, file_ext[0] ? file_ext : (ext && *ext) ? ext : "");

    i32 num_folders = NumSubStrings(folders);
    i32 num_exts = NumSubStrings(exts);

    for (i32 i = 1; i <= num_folders; ++i)
    {
        arts_strcpy(file_path, SubString(i, folders));
        ExpandEnvs(file_path);

        if (!ValidPath(file_path))
            continue;

        arts_strcat(file_path, "\\");
        arts_strcat(file_path, file_name);

        for (i32 j = 1; j <= num_exts; ++j)
        {
            char full_path[256];
            arts_strcpy(full_path, file_path);
            arts_strcat(full_path, SubString(j, exts));

            if (!QueryOn(full_path))
                continue;

            arts_strcpy(output, buffer_len, full_path);
            return true;
        }
    }

    return false;
}

Owner<class Stream*> FileSystem::OpenAny(const char* path, b32 read_only, void* buffer, i32 buffer_len)
{
    for (i32 i = 0; i < FSCount; ++i)
    {
        FileSystem* f = FS[i];

        if (f->QueryOn(path))
            return f->OpenOn(path, read_only, buffer, buffer_len);
    }

    return nullptr;
}

b32 FileSystem::PagerInfoAny(const char* path, struct PagerInfo_t& pager)
{
    for (i32 i = 0; i < FSCount; ++i)
    {
        FileSystem* f = FS[i];

        if (f->PagerInfo(path, pager))
            return true;
    }

    return false;
}

class FileSystem* FileSystem::SearchAll(
    const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer, i32 buffer_len)
{
    // NOTE: Incompatible

    for (i32 i = 0; i < FSCount; ++i)
    {
        FileSystem* f = FS[i];

        if (f->Search(file, folder, ext, ext_id, buffer, buffer_len))
            return f;
    }

    return nullptr;
}

void FileSystem::NotifyDelete()
{}

class FileSystem* FindFile(
    const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer, i32 buffer_len)
{
    // NOTE: Incompatible

    return FileSystem::SearchAll(file, folder, ext, ext_id, buffer, buffer_len);
}

class FileSystem* FindFile(const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer)
{
    // TODO: Avoid hardcoded buffer size (chosen as smallest buffer buffer size passed by the game)
    return FindFile(file, folder, ext, ext_id, buffer, 120);
}

Owner<class Stream*> OpenFile(
    const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer, const char* desc)
{
    // TODO: Avoid hardcoded buffer size (chosen as smallest buffer buffer size passed by the game)
    return OpenFile(file, folder, ext, ext_id, buffer, 128, desc);
}

Owner<class Stream*> OpenFile(
    const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer, i32 buffer_len, const char* desc)
{
    // NOTE: Incompatible

    char path[256];

    FileSystem* fs = FindFile(file, folder, ext, ext_id, path, std::size(path));

    Stream* result = nullptr;

    if (; fs && (result = fs->OpenOn(path, 1, 0, 4096)) != nullptr)
    {
        if (fsVerbose)
        {
            if (desc)
                Displayf("Opening %s `%s'", desc, path);
            else
                Displayf("Opening `%s'", path);
        }

        if (buffer)
            arts_strcpy(buffer, buffer_len, path);
    }

    else
    {
        if (fsVerbose)
            Errorf("OpenFile()- Can't find `%s'", fs ? path : file);

        result = nullptr;
    }

    return result;
}

class FileSystem* FileSystem::FS[MAX_FILESYSTEMS] {};

run_once([] {
    // Fix references to FileSystem::FS
    u32 fs_addr = reinterpret_cast<u32>(FileSystem::FS);
    write_protected(0x4CBFDF + 1, &fs_addr, 4); // mmCityList::LoadAll
    write_protected(0x4CC3EF + 1, &fs_addr, 4); // mmVehList::LoadAll

    fs_addr -= 4;
    write_protected(0x402DD0 + 3, &fs_addr, 4); // ApplicationHelper
});
