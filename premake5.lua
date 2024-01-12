workspace "KoEngine" -- Solution name
    configurations
    { 
        "Debug",
        "Release"
    }
    startproject "MyGameExample"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" -- output example: Debug-windows-x86_64
vulkanpath = os.getenv("VULKAN_SDK") -- Gets the Vulkan's environment variable

project "KoEngine"
    location "KoEngine" -- Project's file location
    kind "SharedLib" -- .dll
    language "C++"
    architecture "x64"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- General -> Output Directory
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}") -- General -> Intermediate Directory
 
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs -- C/C++ -> General -> Additional Include Directories
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/vendor/The-Forge/Common_3",
        "%{vulkanpath}/Include"
    }

    syslibdirs -- VC++ lib directory
    {
        "%{vulkanpath}/Lib"
    }

    externalincludedirs -- VC++ external include
    {
        "%{vulkanpath}/Include"
    }

    libdirs -- Linker -> General -> Additional Library Directories
    {
        "%{prj.name}/lib"
    }

    links -- Linker -> Input -> Additional Dependencies
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
        systemversion "10.0.17763.0" -- General -> Windows SDK Version
		toolset "v141" -- General -> Platform Toolset

        defines -- Ifdefs
        {
            "KE_WINDOWS_PLATFORM",
            "KE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/MyGameExample") -- Copy bin files from KoEngine to MyGameExample
        }
 
    filter "configurations:Debug"
        staticruntime "off" -- C/C++ -> Code Generation -> Runtime Library (/MD)
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
        "KoEngine/src",
        "%{vulkanpath}/Include"
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
		toolset "v141"

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