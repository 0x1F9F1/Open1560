arts_component "eventq7"
    files {
        "active.h",
        "dispatchable.cpp",
        "dispatchable.h",
        "event.cpp",
        "event.h",
        "eventq.cpp",
        "eventq.h",
        "replay.cpp",
        "replay.h",
        "sdlevent.cpp",
        "sdlevent.h",

        "keys.cpp",
        "keys.h",
    }

    links { "dinput8" }

    includeSDL3()