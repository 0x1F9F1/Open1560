arts_component "arts7"
    files {

        "benchstats.cpp",
        "benchstats.h",
        "camera.cpp",
        "camera.h",
        "cullable.cpp",
        "cullable.h",
        "cullmgr.cpp",
        "cullmgr.h",
        -- "dof.cpp",
        -- "dof.h",
        -- "form.cpp",
        -- "form.h",
        -- "lamp.cpp",
        -- "lamp.h",
        "linear.cpp",
        "linear.h",

        "node.cpp",
        "node.h",

        "sim.cpp",
        "sim.h",
        -- "view.cpp",
        -- "view.h",
    }

    if ARTS_DEV_BUILD then
        files {
            "bank.cpp",
            "bank.h",
            "midgets.cpp",
            "midgets.h",
            "pgraph.cpp",
            "pgraph.h",
        }
    end
