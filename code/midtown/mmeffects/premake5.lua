ARTS_USE_FREETYPE = true

arts_component "mmeffects"
    files {
        "birth.cpp",
        "birth.h",
        "card2d.cpp",
        "card2d.h",
        "damage.cpp",
        "damage.h",
        "linespark.cpp",
        "linespark.h",
        "meshform.cpp",
        "meshform.h",
        "mmnumber.cpp",
        "mmnumber.h",
        "mmtext.cpp",
        "mmtext.h",
        "mousesteerbar.cpp",
        "mousesteerbar.h",
        "ptx.cpp",
        "ptx.h",
        "vehform.cpp",
        "vehform.h",
    }

    if ARTS_USE_FREETYPE then
        files { "mmtext_freetype.cpp" }
        includeFreetype()
        linkFreetype()
    else
        files { "mmtext_win32.cpp" }
    end
