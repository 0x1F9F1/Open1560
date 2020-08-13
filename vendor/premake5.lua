VENDOR_DIR = os.getcwd()

MEM_DIR = path.join(VENDOR_DIR, "mem")
HEDLEY_DIR = path.join(VENDOR_DIR, "hedley")
LUA_DIR = path.join(VENDOR_DIR, "lua-5.3.5")
SOL_DIR = path.join(VENDOR_DIR, "sol-3.0.3")
FREETYPE_DIR = path.join(VENDOR_DIR, "freetype-2.10.2")

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

-- function includeLua()
--     includedirs { LUA_DIR }
-- end

-- function includeSol()
--     includedirs { SOL_DIR }
--     defines { "SOL_ALL_SAFETIES_ON=1", "_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING" }
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
