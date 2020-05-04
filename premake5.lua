GAME_DIR = _OPTIONS['gamedir'] or 'X:/Games/Other/Midtown Madness Sneak Preview/'

workspace "Open1560"
    location "build"

    flags "MultiProcessorCompile"

    configurations { "Debug", "Release", "Final" }
    platforms { "Win32" }

    filter "kind:*App or SharedLib"
        targetdir "bin/%{prj.name}/%{cfg.platform}_%{cfg.buildcfg}"

    filter "configurations:Debug"
        optimize "Debug"
        symbols "On"
        defines { "_DEBUG", "ARTS_DEBUG" }

    filter "configurations:Release"
        optimize "On"
        symbols "On"

    filter "configurations:Final"
        optimize "Full"
        symbols "FastLink"
        defines { "NDEBUG", "ARTS_FINAL" }
        flags { "LinkTimeOptimization", "NoIncrementalLink" }

    filter "platforms:Win32"
        architecture "x32"

    -- filter "platforms:Win64"
    --     architecture "x86_64"

    filter {}

group "Third Party"
    include "vendor"

group ""
    include "code"
