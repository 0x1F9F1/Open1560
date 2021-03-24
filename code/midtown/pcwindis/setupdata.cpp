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

define_dummy_symbol(pcwindis_setupdata);

#include "setupdata.h"

#include "stream/stream.h"

// 0x575090 | ?guidtostr@@YAXPADPAU_GUID@@@Z
ARTS_IMPORT /*static*/ void guidtostr(char* arg1, struct _GUID* arg2);

// 0x574DF0 | ?strtoguid@@YAXPAU_GUID@@PAD@Z
ARTS_IMPORT /*static*/ void strtoguid(struct _GUID* arg1, char* arg2);

static const u32 ConfigFileVersion = 112;

b32 dxiReadConfigFile()
{
    Ptr<Stream> input {arts_fopen(".\\video.cfg", "r")};

    if (input == nullptr)
        return false;

    i32 version = 0;

    if ((input->Scanf("FileVersion=%d", &version) != 1) || (version != ConfigFileVersion) ||
        (input->Scanf("RendererCount=%d", &dxiRendererCount) != 1) ||
        (input->Scanf("RendererChoice=%d", &dxiRendererChoice) != 1))
    {
        return false;
    }

    if (dxiRendererCount > ARTS_SSIZE(dxiInfo))
        return false;

    for (i32 i = 0; i < dxiRendererCount; ++i)
    {
        dxiRendererInfo_t& info = dxiInfo[i];

        char name[256];
        char interface_guid[64];
        char driver_guid[64];

        if (input->Gets(name, 256) < 3 || name[0] != '[')
            return false;
        if (input->Scanf("Type=%d", &info.Type) != 1)
            return false;
        if (input->Scanf("InterfaceGuid=%s", &interface_guid) != 1)
            return false;
        if (input->Scanf("DriverGuid=%s", &driver_guid) != 1)
            return false;
        if (input->Scanf("bSmoothAlpha=%d", &info.SmoothAlpha) != 1)
            return false;
        if (input->Scanf("bAdditiveBlending=%d", &info.AdditiveBlending) != 1)
            return false;
        if (input->Scanf("bVertexFog=%d", &info.VertexFog) != 1)
            return false;
        if (input->Scanf("bMultiTexture=%d", &info.MultiTexture) != 1)
            return false;
        if (input->Scanf("bTexturePalette=%d", &info.TexturePalette) != 1)
            return false;
        if (input->Scanf("bHaveMipmaps=%d", &info.HaveMipmaps) != 1)
            return false;
        if (input->Scanf("uSpecialFlags=%d", &info.SpecialFlags) != 1)
            return false;
        if (input->Scanf("Resolutions=%d", &info.ResCount) != 1)
            return false;

        *std::strrchr(name, ']') = '\0';
        arts_strcpy(info.Name, &name[1]);

        strtoguid(&info.Guid.Interface, interface_guid);
        strtoguid(&info.Guid.Driver, driver_guid);

        for (i32 j = 0; j < info.ResCount; ++j)
        {
            dxiResolution& res = info.Resolutions[j];

            if (input->Scanf("%hd %hd %u", &res.uWidth, &res.uHeight, &res.uTexMem) != 3)
                return false;
        }

        if (input->Scanf("ResChoice=%d", &info.ResChoice) != 1)
            return false;
    }

    return true;
}

i32 dxiResGetRecommended(i32 renderer, [[maybe_unused]] i32 cpu_speed)
{
    dxiRendererInfo_t& info = dxiInfo[renderer];

    if (info.Type == 0)
        return dxiResClosestMatch(renderer, 640, 480);
    else
        return dxiResClosestMatch(renderer, 1280, 720);
}
