workspace "KoEngine"
    configurations 
    { 
        "Debug", 
        "Release" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "KoEngine"
    location "KoEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
 
    files 
    { 
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/vendor/The-Forge/Common_3"
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "10.0.17763.0"

        defines
        {
            "KE_WINDOWS_PLATFORM",
            "KE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/MyGameExample")
        }
 
    filter "configurations:Debug"
        defines 
        {
            "DEBUG" 
        }
        symbols "On"
 
    filter "configurations:Release"
        defines 
        { 
            "NDEBUG"
        }
        optimize "On"


project "MyGameExample"
    location "MyGameExample" 
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
 
    files 
    { 
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "../KoEngine/vendor/spdlog/include",
        "../KoEngine/vendor/The-Forge/Common_3",
        "../KoEngine/src"
    }

    links
    {
        "KoEngine"
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "10.0.17763.0"

        defines
        {
            "KE_WINDOWS_PLATFORM"
        }

        postbuildcommands
        {
            ("{COPY} ../required-dlls ../bin/" .. outputdir .. "/MyGameExample")
        }
 
    filter "configurations:Debug"
        defines 
        {
            "DEBUG" 
        }
        symbols "On"
 
    filter "configurations:Release"
        defines 
        { 
            "NDEBUG"
        }
        optimize "On"