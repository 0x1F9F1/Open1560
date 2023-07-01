VENDOR_DIR = os.getcwd()

MEM_DIR = path.join(VENDOR_DIR, "mem")
HEDLEY_DIR = path.join(VENDOR_DIR, "hedley")
LUA_DIR = path.join(VENDOR_DIR, "lua-5.3.5")
FREETYPE_DIR = path.join(VENDOR_DIR, "freetype-2.10.4")
GLAD_DIR = path.join(VENDOR_DIR, "glad")
WGL_DIR = path.join(VENDOR_DIR, "wgl")
MINIZ_DIR = path.join(VENDOR_DIR, "miniz")
DX6_DIR = path.join(VENDOR_DIR, "dx6")
SDL2_DIR = path.join(VENDOR_DIR, "SDL2")

function includeMem()
    includedirs { MEM_DIR }
end

function includeHedley()
    includedirs { HEDLEY_DIR }
end

function includeFreetype()
    includedirs { path.join(FREETYPE_DIR, "include") }
    libdirs { path.join(FREETYPE_DIR, "bin") }
end

function includeGlad()
    includedirs { path.join(GLAD_DIR, "include") }
end

function includeWgl()
    includedirs { WGL_DIR }
end

function includeMiniz()
    includedirs { MINIZ_DIR }
end

function includeDX6()
    includedirs { path.join(DX6_DIR, "include") }
end

function includeSDL2()
    includedirs { path.join(SDL2_DIR, "include") }
    libdirs { path.join(SDL2_DIR, "lib/x86") }
end

-- function includeLua()
--     includedirs { LUA_DIR }
-- end

-- project "lua"
--     kind "StaticLib"
--     language "C++"
--     warnings "Off"

--     files
--     {
--         path.join(LUA_DIR, "*.h"),
--         path.join(LUA_DIR, "*.c")
--     }

--     excludes
--     {
--         path.join(LUA_DIR, "lua.c"),
--         path.join(LUA_DIR, "luac.c"),
--     }

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
