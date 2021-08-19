arts_component "mmcityinfo"
    files {
        "cityinfo.cpp",
        "cityinfo.h",
        "citylist.cpp",
        "citylist.h",
        -- "crc.cpp",
        "crc.h",
        -- "infobase.cpp",
        "infobase.h",

        -- "miscdata.cpp",
        "miscdata.h",
        -- "playercfg.cpp",
        "playercfg.h",
        -- "playerdata.cpp",
        "playerdata.h",
        -- "playerdir.cpp",
        "playerdir.h",
        -- "racedata.cpp",
        "racedata.h",
        -- "racerecord.cpp",
        "racerecord.h",
        -- "roadsect.cpp",
        "roadsect.h",
        "state.cpp",
        "state.h",
        "vehinfo.cpp",
        "vehinfo.h",
        "vehlist.cpp",
        "vehlist.h",
    }

    if ARTS_DEV_BUILD then
        files {
            "mapdata.cpp",
            "mapdata.h",
        }
    end
