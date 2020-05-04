project "Open1560"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    warnings "Extra"
    flags "FatalWarnings"

    useARTSPCH()
    includeARTS()

    targetname "dinput"

    files {
        "loader.cpp"
    }

    links {
        "arts_midtown",
        "DbgHelp",
    }

    postbuildcommands {
        '{COPY} "%{cfg.buildtarget.abspath}" "' .. GAME_DIR .. '"',
        '{COPY} "%{cfg.buildtarget.directory}%{cfg.buildtarget.basename}.pdb" "' .. GAME_DIR .. '"',
    }

    debugdir (GAME_DIR)
    debugcommand (GAME_DIR .. 'Open1560.exe')
    debugargs {}
