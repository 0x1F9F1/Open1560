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

define_dummy_symbol(pcwindis_dxsetup);

#include "dxsetup.h"

#include "data7/speed.h"
#include "data7/timer.h"
#include "dxinit.h"
#include "localize/localize.h"
#include "midtown.h"
#include "mmui/graphics.h"
#include "setupdata.h"

#ifdef ARTS_ENABLE_OPENGL
#    include "agisdl/sdlsetup.h"
#endif

#include "core/minwin.h"

static mem::cmd_param PARAM_config {"config"};
static mem::cmd_param PARAM_sw {"sw"};

void dxiConfig([[maybe_unused]] i32 argc, [[maybe_unused]] char** argv)
{
    dxiCpuSpeed = ComputeCpuSpeed();

    bool (*validate)() = nullptr;
    void (*enumerate)() = nullptr;
    bool show_message = false;

#ifdef ARTS_ENABLE_OPENGL
    {
        validate = ValidateRenderersSDL;
        enumerate = EnumerateRenderersSDL;
        show_message = false;
    }
#else
#    error No valid renderer backends
#endif

    if (PARAM_config.get_or(false) || !dxiReadConfigFile() || !validate())
    {
        if (show_message)
        {
            if (MessageBoxA(NULL, LOC_STR(MM_IDS_DETECTING_GPU), APPTITLE, MB_OKCANCEL) != IDOK)
            {
                Errorf("User declined GPU detection");
                ExitProcess(0);
            }
        }

        std::memset(dxiInfo, 0, sizeof(dxiInfo));
        dxiRendererChoice = -1;
        dxiRendererCount = 0;

        Timer detect_time;
        enumerate();
        Displayf("DETECT TIME: %f ms", detect_time.TimeMS());

        if (dxiRendererCount == 0)
        {
            MessageBoxA(NULL, LOC_STR(MM_IDS_NO_RENDERERS), APPTITLE, MB_OK);
            ExitProcess(0);
        }

        if (dxiRendererChoice == -1)
            dxiRendererChoice = std::min<i32>(1, dxiRendererCount - 1);

        dxiWriteConfigFile();
        AutoDetect(-1, -1);
    }

    if (PARAM_sw)
    {
        for (i32 i = 0; i < dxiRendererCount; ++i)
        {
            if (IsSoftwareRenderer(dxiInfo[i].Type))
            {
                dxiRendererChoice = i;
                break;
            }
        }
    }
}