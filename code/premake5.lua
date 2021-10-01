ARTS_DIR = path.join(os.getcwd(), "midtown")

function includeARTS()
    includedirs { ARTS_DIR }
    forceincludes { "arts_pch.h" }

    includeHedley()
    includeMem()
end

function useARTSPCH()
    includedirs { ARTS_DIR }
    pchheader("arts_pch.h")

    files { path.join(ARTS_DIR, "arts_pch.cpp"), path.join(ARTS_DIR, "arts_pch.h") }
    pchsource(path.join(ARTS_DIR, "arts_pch.cpp"))
end

function arts_component(name)
    project("arts_" .. name)

    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    warnings "Extra"
    exceptionhandling "Off"
    floatingpoint "Fast"

    useARTSPCH()
    includeARTS()

    filter { "configurations:Final", "toolset:not msc-ClangCL" }
        flags "FatalWarnings"
    filter {}
end

include "midtown"
include "loader"
