include "core"

-- include "agi"
-- include "agid3d"
-- include "agirend"
-- include "agisw"
-- include "agiworld"
-- include "arts7"
include "data7"
-- include "dyna7"
-- include "eventq7"
-- include "localize"
-- include "memory"
-- include "mmai"
-- include "mmanim"
-- include "mmaudio"
-- include "mmbangers"
-- include "mmcamcs"
-- include "mmcamtour"
-- include "mmcar"
-- include "mmcity"
-- include "mmcityinfo"
-- include "mmdjpeg"
-- include "mmdyna"
-- include "mmeffects"
-- include "mmgame"
-- include "mminput"
-- include "mmnetwork"
-- include "mmphysics"
-- include "mmui"
-- include "mmwidget"
include "pcwindis"
-- include "stream"
-- include "vector7"

arts_component "midtown"
    files {
        "midtown.cpp",
        "midtown.h",
    }

    links {
        "arts_core",

        -- "arts_agi",
        -- "arts_agid3d",
        -- "arts_agirend",
        -- "arts_agisw",
        -- "arts_agiworld",
        -- "arts_arts7",
        "arts_data7",
        -- "arts_dyna7",
        -- "arts_eventq7",
        -- "arts_localize",
        -- "arts_memory",
        -- "arts_mmai",
        -- "arts_mmanim",
        -- "arts_mmaudio",
        -- "arts_mmbangers",
        -- "arts_mmcamcs",
        -- "arts_mmcamtour",
        -- "arts_mmcar",
        -- "arts_mmcity",
        -- "arts_mmcityinfo",
        -- "arts_mmdjpeg",
        -- "arts_mmdyna",
        -- "arts_mmeffects",
        -- "arts_mmgame",
        -- "arts_mminput",
        -- "arts_mmnetwork",
        -- "arts_mmphysics",
        -- "arts_mmui",
        -- "arts_mmwidget",
        "arts_pcwindis",
        -- "arts_stream",
        -- "arts_vector7",

        "lua",
    }
