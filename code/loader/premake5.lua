project "Open1560"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    warnings "Extra"

    filter "toolset:msc-v*"
        flags "FatalWarnings"
    filter {}

    includeARTS()

    targetname "dinput"

    files {
        "loader.cpp",
        "loader.def",
        "symbols.cpp",
        "symbols.h",
    }

    links { "arts_midtown", "DbgHelp", "Winmm" }

    linkoptions {
        "/DEFAULTLIB:\"" .. path.join(os.getcwd(), "Open1560_stubs.lib") .. "\""
    }

    copyToGameDir ("%{cfg.buildtarget.abspath}")
    copyToGameDir ("%{cfg.buildtarget.directory}%{cfg.buildtarget.basename}.pdb")
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
