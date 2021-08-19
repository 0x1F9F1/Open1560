ARTS_ENABLE_KNI = true

if ARTS_ENABLE_KNI then
    project "*"
        defines { "ARTS_ENABLE_KNI" }
end

arts_component "agiworld"
    files {
        -- "bone.cpp",
        "bone.h",
        "getmesh.cpp",
        "getmesh.h",
        -- "getmodel.cpp",
        "getmodel.h",
        "meshlight.cpp",
        "meshlight.h",
        "meshload.cpp",
        "meshload.h",
        -- "meshmodel.cpp",
        "meshmodel.h",
        "meshrend.cpp",
        "meshrend.h",
        "meshsave.cpp",
        "meshsave.h",
        "meshset.cpp",
        "meshset.h",
        "packnorm.cpp",
        "packnorm.h",
        "quality.cpp",
        "quality.h",
        -- "skeleton.cpp",
        "skeleton.h",
        "texsheet.cpp",
        "texsheet.h",
        "texsort.cpp",
        "texsort.h",

        "mmx.h",
    }

    if ARTS_ENABLE_KNI then
        files {
            "mrkni.cpp",
            "mrkni.h",
        }
    end
