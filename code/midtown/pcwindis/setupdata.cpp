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

// ?guidtostr@@YAXPADPAU_GUID@@@Z
ARTS_IMPORT /*static*/ void guidtostr(char* arg1, _GUID* arg2);

// ?strtoguid@@YAXPAU_GUID@@PAD@Z
ARTS_IMPORT /*static*/ void strtoguid(_GUID* arg1, char* arg2);

dxiRendererInfo_t dxiInfo[16];
i32 dxiRendererChoice = -1;
i32 dxiRendererCount = 0;

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

    if ((dxiRendererCount == 0) || (dxiRendererCount > ARTS_SSIZE(dxiInfo)))
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

        strtoguid(&info.DX6.Interface, interface_guid);
        strtoguid(&info.DX6.Driver, driver_guid);

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

void dxiWriteConfigFile()
{
    Ptr<Stream> output {arts_fopen(".\\video.cfg", "w")};

    if (output == nullptr)
        return;

    output->Printf("FileVersion=%d\n", ConfigFileVersion);
    output->Printf("RendererCount=%d\n", dxiRendererCount);
    output->Printf("RendererChoice=%d\n", dxiRendererChoice);

    for (i32 i = 0; i < dxiRendererCount; ++i)
    {
        dxiRendererInfo_t& info = dxiInfo[i];

        output->Printf("[%s]\n", info.Name);
        output->Printf("Type=%d\n", info.Type);

        char guid[64];
        guidtostr(guid, &info.DX6.Interface);
        output->Printf("InterfaceGuid=%s\n", guid);
        guidtostr(guid, &info.DX6.Driver);
        output->Printf("DriverGuid=%s\n", guid);

        output->Printf("bSmoothAlpha=%d\n", info.SmoothAlpha);
        output->Printf("bAdditiveBlending=%d\n", info.AdditiveBlending);
        output->Printf("bVertexFog=%d\n", info.VertexFog);
        output->Printf("bMultiTexture=%d\n", info.MultiTexture);
        output->Printf("bTexturePalette=%d\n", info.TexturePalette);
        output->Printf("bHaveMipmaps=%d\n", info.HaveMipmaps);
        output->Printf("uSpecialFlags=%d\n", info.SpecialFlags);
        output->Printf("Resolutions=%d\n", info.ResCount);

        for (i32 j = 0; j < info.ResCount; ++j)
        {
            dxiResolution& res = info.Resolutions[j];

            output->Printf("%d %d %u\n", res.uWidth, res.uHeight, res.uTexMem);
        }

        output->Printf("ResChoice=%d\n", info.ResChoice);
    }
}

i32 dxiResClosestMatch(i32 renderer, i32 width, i32 height)
{
    dxiRendererInfo_t& info = dxiInfo[renderer];

    i32 best_index = 0;
    i32 best_extra = INT32_MAX;

    for (i32 i = 0; i < info.ResCount; ++i)
    {
        dxiResolution& res = info.Resolutions[i];

        if (i32 extra = std::abs(width - res.uWidth) * height + std::abs(height - res.uHeight) * width;
            extra < best_extra)
        {
            best_index = i;
            best_extra = extra;
        }
    }

    return best_index;
}

i32 dxiResGetRecommended(i32 renderer, [[maybe_unused]] i32 cpu_speed)
{
    dxiRendererInfo_t& info = dxiInfo[renderer];

    // Assume largest resolution is native
    dxiResolution* native_res = nullptr;
    u32 best_total = 0;

    for (i32 i = 0; i < info.ResCount; ++i)
    {
        dxiResolution& res = info.Resolutions[i];

        if (u32 total = res.uWidth * res.uHeight; total > best_total)
        {
            native_res = &res;
            best_total = total;
        }
    }

    u32 target_height = std::min<u32>(IsSoftwareRenderer(info.Type) ? 480 : 768, native_res->uHeight);

    return dxiResClosestMatch(renderer, (target_height * native_res->uWidth) / native_res->uHeight, target_height);
}
