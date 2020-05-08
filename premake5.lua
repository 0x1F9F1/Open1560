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

    flags "MultiProcessorCompile"

    configurations { "Debug", "Release", "Final" }
    platforms { "Win32" }

    filter "kind:*App or SharedLib"
        targetdir "bin/%{prj.name}/%{cfg.platform}_%{cfg.buildcfg}"

    local ci_build_string = os.getenv("APPVEYOR_BUILD_NUMBER")

    if ci_build_string ~= nil then
        defines { "CI_BUILD_STRING=\"" .. ci_build_string .. "\"" }
    end

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
        architecture "x86"

    -- filter "platforms:Win64"
    --     architecture "x86_64"

    filter {}

group "Third Party"
    include "vendor"

group ""
    include "code"
