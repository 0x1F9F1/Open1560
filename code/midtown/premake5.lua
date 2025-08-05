ARTS_TARGET_BUILD = 1560
ARTS_DEV_BUILD = true

include "core"

include "agi"

include "agigl"
include "agisdl"
include "agisw"
include "agiworld"
include "arts7"
include "data7"
include "dyna7"
include "eventq7"
include "localize"
include "memory"
include "mmai"
include "mmanim"
include "mmaudio"
include "mmbangers"
include "mmcamcs"
include "mmcar"
include "mmcity"
include "mmcityinfo"
include "mmdjpeg"
include "mmdyna"
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
    include "mmcamtour"
    include "toolmgr"

    project "*"
        defines { "ARTS_DEV_BUILD" }
end

project "Open1560"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"
    warnings "Extra"

    filter "toolset:msc-v*"
        flags { "FatalWarnings", "Maps" }
    filter {}

    includeARTS()

    targetname "Open1560"

    files {
        "midtown.cpp",
        "midtown.h",

        "patches.cpp",
        "patches.h",

        "game.asm",
        "midtown.rc",
    }

    links {
        "arts_core",

        "arts_agi",
        "arts_agigl",
        "arts_agisdl",
        "arts_agisw",
        "arts_agiworld",
        "arts_arts7",
        "arts_data7",
        "arts_dyna7",
        "arts_eventq7",
        "arts_localize",
        "arts_memory",
        "arts_mmai",
        "arts_mmanim",
        "arts_mmaudio",
        "arts_mmbangers",
        "arts_mmcamcs",
        "arts_mmcar",
        "arts_mmcity",
        "arts_mmcityinfo",
        "arts_mmdjpeg",
        "arts_mmdyna",
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
    }

    if ARTS_DEV_BUILD then
        links {
            "arts_agirend",
            "arts_mmcamtour",
            "arts_toolmgr",
        }
    end

    includeSDL3()
    linkSDL3()

    links { "DbgHelp", "Winmm" }

    linkoptions { "/SAFESEH:NO", path.join(os.getcwd(), "NoExports.exp") }
    -- linkoptions { "/PDBALTPATH:%_PDB%" } -- Remove full PDB path

    copyToGameDir ("%{cfg.buildtarget.abspath}")
    -- copyToGameDir ("%{cfg.buildtarget.directory}%{cfg.buildtarget.basename}.pdb")
    copyToGameDir ("%{cfg.buildtarget.directory}%{cfg.buildtarget.basename}.map")
    copyToGameDir (path.join(ROOT_DIR, "game"))
    copyToGameDir (path.join(SDL3_DIR, "lib/x86/SDL3.dll"))

    if MM1_GAME_DIRECTORY ~= nil then
        for _, path in ipairs(GAME_FILES) do
            postbuildcommands {
                '{COPY} "' .. path .. '" "' .. MM1_GAME_DIRECTORY .. '"',
            }
        end

        debugdir (MM1_GAME_DIRECTORY)
        debugargs { '-adir "' .. string.gsub(MM1_GAME_DIRECTORY, "\\", "/") .. '"' }

        if MM1_COMMAND_LINE ~= nil then
            debugargs (MM1_COMMAND_LINE)
        end
    end