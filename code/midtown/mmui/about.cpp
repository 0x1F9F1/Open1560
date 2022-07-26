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

define_dummy_symbol(mmui_about);

#include "about.h"

#if 0
#    include "core/minwin.h"
#endif

void GetMidtownRegString(char* buffer, i32 buffer_len, [[maybe_unused]] char* key, [[maybe_unused]] char* default_value)
{
#if 0
    arts_strcpy(buffer, buffer_len, default_value);

    if (HKEY hkey; RegOpenKeyExA(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Microsoft Games\\Midtown Madness\\1.0", 0,
                       KEY_ALL_ACCESS, &hkey) == ERROR_SUCCESS)
    {
        DWORD cb_data = buffer_len;
        RegQueryValueExA(hkey, key, 0, 0, (BYTE*) buffer, &cb_data);
        RegCloseKey(hkey);
    }
#else
    arts_strcpy(buffer, buffer_len, "Open1560");
#endif
}

hook_func(INIT_main, [] {
    char patch[] {"\x83\xC4\x04\x50\x68\x4A\x11\x64\x00\x8D\x85\xEC\xFE\xFF\xFF\x68\x00\x01\x00\x00\x50\xE8\xCC\xCC\xCC"
                  "\xCC\x83\xC4\x10\xEB\x4D"};

    *(i32*) (patch + 0x16) = mem::pointer(GetMidtownRegString).sub(0x4A5F8D + 0x1A).as<i32>();

    create_patch("AboutMenu", "AboutMenu PID", 0x4A5F8D, patch, 0x1F);

    // create_hook("AboutMenu", "Credits Image", 0x4A5EB7, "credits", hook_type::push);
});
