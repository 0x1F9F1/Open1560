newoption {
   trigger     = "MM1_GAME_DIRECTORY",
   description = "Path to MM1 Game Directory",
}

newoption {
   trigger     = "MM1_COMMAND_LINE",
   description = "Command Line for MM1",
}

ROOT_DIR = os.getcwd()

local function read_file_line(file)
    if not os.isfile(file) then
        return nil
    end

    return io.lines(file)()
end

MM1_GAME_DIRECTORY = _OPTIONS['MM1_GAME_DIRECTORY'] or read_file_line('GameDirectory.txt')
MM1_COMMAND_LINE = _OPTIONS['MM1_COMMAND_LINE'] or read_file_line('CommandLine.txt')

workspace "Open1560"
    location "build"

    -- No longer works, thanks to broken (missing) virtual vector deleting destructors
    -- toolset "msc-llvm"

    configurations { "Debug", "Release", "Final" }
    platforms { "Win32" }

    local ci_build_string = os.getenv("APPVEYOR_BUILD_NUMBER")

    if ci_build_string ~= nil then
        defines { "CI_BUILD_STRING=\"" .. ci_build_string .. "\"" }
    end

    flags "MultiProcessorCompile"

    editAndContinue "Off"
    symbols "On"
    debugformat "c7"
    inlining "Auto"

    filter "kind:*App or SharedLib"
        targetdir "bin/%{prj.name}/%{cfg.platform}_%{cfg.buildcfg}"

    filter "configurations:Debug"
        optimize "Debug"
        defines { "_DEBUG", "ARTS_DEBUG" }

    filter "configurations:Release"
        optimize "On"

    filter "configurations:Final"
        optimize "Full"
        defines { "NDEBUG", "ARTS_FINAL" }
        flags { "LinkTimeOptimization", "NoIncrementalLink" }
        functionlevellinking "On"

    filter "platforms:Win32"
        architecture "x86"
        vectorextensions "SSE2"

    -- filter "platforms:Win64"
    --     architecture "x86_64"

    filter "toolset:msc*"
        buildoptions { "/permissive-", "/utf-8" }

    filter "toolset:msc-v*"
        buildoptions { "/Zc:throwingNew" }

    filter {}

group "Third Party"
    include "vendor"

group ""
    include "code"
