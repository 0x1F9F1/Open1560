ARTS_DIR = path.join(os.getcwd(), "midtown")

function includeARTS()
    includedirs { ARTS_DIR }
    forceincludes { "arts_pch.h" }

    files { path.join(ARTS_DIR, "arts_pch.cpp"), path.join(ARTS_DIR, "arts_pch.h") }
    pchheader("arts_pch.h")
    pchsource(path.join(ARTS_DIR, "arts_pch.cpp"))

    includeHedley()
    includeMem()
end

function arts_component(name)
    project("arts_" .. name)

    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    warnings "Extra"
    exceptionhandling "Off"
    floatingpoint "Fast"

    includeARTS()

    filter { "configurations:Final", "toolset:not msc-ClangCL" }
        flags "FatalWarnings"
    filter {}
end

include "midtown"
include "loader"
