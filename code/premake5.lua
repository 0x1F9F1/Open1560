ARTS_DIR = path.join(os.getcwd(), "midtown")

function includeARTS()
    includedirs { ARTS_DIR }

    includeHedley()
    includeMem()

    -- includeLua()
    -- includeSol()
end

function useARTSPCH()
    files { path.join(ARTS_DIR, "arts_pch.cpp") }
    includedirs { ARTS_DIR }
    forceincludes { "arts_pch.h" }

    pchsource(path.join(ARTS_DIR, "arts_pch.cpp"))
    pchheader("arts_pch.h")
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

    filter "configurations:Final"
        flags "FatalWarnings"
    filter {}
end

include "midtown"
include "loader"
