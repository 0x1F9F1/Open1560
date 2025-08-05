VENDOR_DIR = os.getcwd()

MEM_DIR = path.join(VENDOR_DIR, "mem")
HEDLEY_DIR = path.join(VENDOR_DIR, "hedley")
FREETYPE_DIR = path.join(VENDOR_DIR, "freetype-2.10.4")
GLAD_DIR = path.join(VENDOR_DIR, "glad")
MINIZ_DIR = path.join(VENDOR_DIR, "miniz")
DX6_DIR = path.join(VENDOR_DIR, "dx6")
SDL3_DIR = path.join(VENDOR_DIR, "SDL3")

function includeMem()
    includedirs { MEM_DIR }
end

function includeHedley()
    includedirs { HEDLEY_DIR }
end

function includeFreetype()
    includedirs { path.join(FREETYPE_DIR, "include") }
end

-- Compiled with:
-- cmake --fresh -B build -A Win32 -T v141 -DFT_DISABLE_ZLIB=ON -DFT_DISABLE_BZIP2=ON -DFT_DISABLE_PNG=ON -DFT_DISABLE_HARFBUZZ=ON -DFT_DISABLE_BROTLI=ON
--
-- And override CRT:
-- cmake_policy(SET CMP0091 NEW)
-- set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
function linkFreetype()
    local libdir = path.join(FREETYPE_DIR, "bin")
    libdirs { libdir }

    filter "configurations:Debug"
        links { path.join(libdir, "freetyped.lib") }
    filter "configurations:not Debug"
        links { path.join(libdir, "freetype.lib") }
    filter {}
end

function includeGlad()
    includedirs { path.join(GLAD_DIR, "include") }
end

function includeMiniz()
    includedirs { MINIZ_DIR }
end

function includeDX6()
    includedirs { path.join(DX6_DIR, "include") }
end

function includeSDL3()
    includedirs { path.join(SDL3_DIR, "include") }
end

function linkSDL3()
    links { path.join(SDL3_DIR, "lib/x86/SDL3.lib") }
end

project "glad"
    kind "StaticLib"
    language "C"
    warnings "Off"

    files
    {
        path.join(GLAD_DIR, "**.h"),
        path.join(GLAD_DIR, "**.c")
    }

    includeGlad()

project "miniz"
    kind "StaticLib"
    language "C"
    warnings "Off"

    files
    {
        path.join(MINIZ_DIR, "**.h"),
        path.join(MINIZ_DIR, "**.c")
    }

    includeMiniz()

    defines {
        "MINIZ_NO_ARCHIVE_APIS",
        "MINIZ_NO_ZLIB_APIS",
        "MINIZ_NO_STDIO",
        "MINIZ_NO_TIME"
    }
