workspace "KoEngine"
    configurations 
    { 
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
vulkanpath = os.getenv("VULKAN_SDK")

project "KoEngine"
    location "KoEngine"
    kind "SharedLib"
    language "C++"
    architecture "x64"

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

    syslibdirs -- VC++ lib directory
    {
        "%{vulkanpath}/Lib"
    }

    externalincludedirs -- VC++ external include
    {
        "%{vulkanpath}/Include"
    }

    libdirs 
    {
        "%{prj.name}/lib"
    }

    links
    {
        "kernel32.lib",
        "user32.lib",
        "comdlg32.lib",
        "advapi32.lib",
        "shell32.lib",
        "ole32.lib",
        "oleaut32.lib",
        "gdi32.lib",
        "winmm.lib",
        "Xinput9_1_0.lib",
        "ws2_32.lib",
        "vulkan-1.lib",
        "OS.lib",
        "Renderer.lib",
        "gainputstatic.lib"
    }

    filter "system:windows"
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
        staticruntime "off"
        defines 
        {
            "DEBUG" 
        }
        symbols "On"
 
    filter "configurations:Release"
        staticruntime "off"
        defines 
        { 
            "NDEBUG"
        }
        optimize "On"


project "MyGameExample"
    location "MyGameExample"
    kind "ConsoleApp"
    language "C++"
    architecture "x64"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
 
    files 
    { 
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "KoEngine/vendor/spdlog/include",
        "KoEngine/vendor/The-Forge/Common_3",
        "KoEngine/src"
    }

    syslibdirs
    {
        "%{vulkanpath}/Lib"
    }

    externalincludedirs
    {
        "%{vulkanpath}/Include"
    }

    libdirs 
    {
        "KoEngine/lib"
    }

    links
    {
        "kernel32.lib",
        "user32.lib",
        "comdlg32.lib",
        "advapi32.lib",
        "shell32.lib",
        "ole32.lib",
        "oleaut32.lib",
        "gdi32.lib",
        "winmm.lib",
        "KoEngine",
        "Xinput9_1_0.lib",
        "ws2_32.lib",
        "vulkan-1.lib",
        "OS.lib",
        "Renderer.lib",
        "gainputstatic.lib"
    }

    filter "system:windows"
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
        staticruntime "off"
        defines 
        {
            "DEBUG" 
        }
        symbols "On"
 
    filter "configurations:Release"
        staticruntime "off"
        defines 
        { 
            "NDEBUG"
        }
        optimize "On"