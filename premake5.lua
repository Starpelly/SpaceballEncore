workspace "Kiki"
    architecture "x64"
    startproject "Kiki"

    configurations
    {
        "Debug",
        "Release"
    }
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Kiki"
	-- location "Fant"
    kind "ConsoleApp"
    language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/%{cfg.buildcfg}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.c",
        "src/**.hpp",
        "src/**.cpp",

        "vendor/raylib/src/*.c",
        "vendor/raylib/src/*.h",
        "vendor/raylib/src/external/*.h",
        "vendor/raylib/src/external/*.c",
    }

    removefiles
    {
        "vendor/raylib/src/external/qoaplay.c"
    }
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

    includedirs
    {
        "src",
        "vendor/raylib/src/external",
        "vendor/raylib/src/external/glfw/include",
		"vendor/raylib/src",
    }

    links
    {
        -- "%{wks.location}/bin/" .. outputdir .. "/raylib/raylib.lib",
        -- "GLFW",
		-- "glfw3.lib",
		"opengl32.lib",
        "winmm"
    }

    filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
        systemversion "latest"

        defines
        {
            "PLATFORM_DESKTOP", "GRAPHICS_API_OPENGL_33", "_WINSOCK_DEPRECATED_NO_WARNINGS", "_WIN32"
        }

    filter "configurations:Debug"
        symbols "on"
        runtime "Debug"
		buildoptions "/MTd"
    filter "configurations:Release"
		defines "TRINKIT_RELEASE"
        optimize "on"
        runtime "Release"
		buildoptions "/MT"