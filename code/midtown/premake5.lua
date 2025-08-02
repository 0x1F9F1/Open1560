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

if ARTS_ENABLE_OPENGL then
    include "agigl"
    include "agisdl"

    project "*"
        defines { "ARTS_ENABLE_OPENGL" }
end

project "*"
    includeSDL2()

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
        "arts_agid3d",
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

        -- "lua",
        "SDL2",
        "SDL2main",
    }

    if ARTS_DEV_BUILD then
        links {
            "arts_agirend",
            "arts_mmcamtour",
            "arts_toolmgr",
        }
    end

    if ARTS_ENABLE_OPENGL then
        links {
            "arts_agigl",
            "arts_agisdl",
        }
    end

    links { "DbgHelp", "Winmm" }

    linkoptions { "/SAFESEH:NO", path.join(os.getcwd(), "NoExports.exp") }
    -- linkoptions { "/PDBALTPATH:%_PDB%" } -- Remove full PDB path

    copyToGameDir ("%{cfg.buildtarget.abspath}")
    -- copyToGameDir ("%{cfg.buildtarget.directory}%{cfg.buildtarget.basename}.pdb")
    copyToGameDir ("%{cfg.buildtarget.directory}%{cfg.buildtarget.basename}.map")
    copyToGameDir (path.join(ROOT_DIR, "game"))
    copyToGameDir (path.join(SDL2_DIR, "lib/x86/SDL2.dll"))

    if MM1_GAME_DIRECTORY ~= nil then
        for _, path in ipairs(GAME_FILES) do
            postbuildcommands {
                '{COPY} "' .. path .. '" "' .. MM1_GAME_DIRECTORY .. '"',
            }
        end

        debugdir (MM1_GAME_DIRECTORY)
        debugcommand (MM1_GAME_DIRECTORY .. 'Open1560.exe')

        if MM1_COMMAND_LINE ~= nil then
            debugargs (MM1_COMMAND_LINE)
        end
    end