arts_component "agigl"
    files {
        "glpipe.cpp",
        "glpipe.h",
        "glcontext.cpp",
        "glcontext.h",
        "gltexdef.cpp",
        "gltexdef.h",
        "glview.cpp",
        "glview.h",
        "glbitmap.cpp",
        "glbitmap.h",
        "glrsys.cpp",
        "glrsys.h",
        "glstream.cpp",
        "glstream.h",
    }

    links {
        "glad",
        "opengl32",
    }

    includeGlad()