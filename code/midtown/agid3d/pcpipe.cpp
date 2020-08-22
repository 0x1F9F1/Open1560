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

define_dummy_symbol(agid3d_pcpipe);

#include "pcpipe.h"

#include "agi/error.h"

#ifndef ARTS_DISABLE_DDRAW
#    include "d3drpipe.h"
#endif

#ifdef ARTS_ENABLE_OPENGL
#    include "agigl/glpipe.h"

static mem::cmd_param PARAM_glpipe {"glpipe"};
#endif

Owner<agiPipeline> d3dCreatePipeline([[maybe_unused]] i32 argc, [[maybe_unused]] char** argv)
{
#ifdef ARTS_ENABLE_OPENGL
    if (
#    ifdef ARTS_DISABLE_DDRAW
        true
#    else
        PARAM_glpipe.get_or(false)
#    endif
    )
    {
        Ptr<agiGLPipeline> result = MakeUnique<agiGLPipeline>();
        result->Init();
        return AsOwner(result);
    }
    else
#endif
    {
#ifndef ARTS_DISABLE_DDRAW
        Ptr<agiD3DRPipeline> result = MakeUnique<agiD3DRPipeline>();
        result->Init();
        return AsOwner(result);
#endif
    }
}
