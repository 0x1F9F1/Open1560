newoption {
   trigger     = "ARTS_DISABLE_OPENGL",
   description = "Compile OpenGL Renderer",
}

ARTS_TARGET_BUILD = 1560
ARTS_DEV_BUILD = true
ARTS_ENABLE_OPENGL = not (_OPTIONS['ARTS_DISABLE_OPENGL'] or false)

include "core"

include "agi"
include "agid3d"

include "agisw"
include "agiworld"
include "arts7"
include "data7"
-- include "dyna7"
include "eventq7"
include "localize"
include "memory"
include "mmai"
include "mmanim"
include "mmaudio"
-- include "mmbangers"
-- include "mmcamcs"
include "mmcar"
include "mmcity"
include "mmcityinfo"
-- include "mmdjpeg"
-- include "mmdyna"
include "mmeffects"
include "mmgame"
include "mminput"
include "mmnetwork"
include "mmphysics"
include "mmui"
include "mmwidget"
include "pcwindis"
include "stream"
include "vector7"

project "*"
    defines { "ARTS_TARGET_BUILD=" .. ARTS_TARGET_BUILD }

if ARTS_DEV_BUILD then
    include "agirend"
    -- include "mmcamtour"

    project "*"
        defines { "ARTS_DEV_BUILD" }
end

if ARTS_ENABLE_OPENGL then
    include "agigl"
    include "agisdl"

    project "*"
        defines { "ARTS_ENABLE_OPENGL" }
end

project "*"
    includeSDL2()

arts_component "midtown"
    files {
        "midtown.cpp",
        "midtown.h",
    }

    links {
        "arts_core",

        "arts_agi",
        "arts_agid3d",
        "arts_agisw",
        "arts_agiworld",
        "arts_arts7",
        "arts_data7",
        -- "arts_dyna7",
        "arts_eventq7",
        "arts_localize",
        "arts_memory",
        "arts_mmai",
        "arts_mmanim",
        "arts_mmaudio",
        -- "arts_mmbangers",
        -- "arts_mmcamcs",
        "arts_mmcar",
        "arts_mmcity",
        "arts_mmcityinfo",
        -- "arts_mmdjpeg",
        -- "arts_mmdyna",
        "arts_mmeffects",
        "arts_mmgame",
        "arts_mminput",
        "arts_mmnetwork",
        "arts_mmphysics",
        "arts_mmui",
        "arts_mmwidget",
        "arts_pcwindis",
        "arts_stream",
        "arts_vector7",

        -- "lua",
        "SDL2",
        "SDL2main",
    }

    if ARTS_DEV_BUILD then
        links {
            "arts_agirend",
            -- "arts_mmcamtour",
        }
    end

    if ARTS_ENABLE_OPENGL then
        links {
            "arts_agigl",
            "arts_agisdl",
        }
    end
