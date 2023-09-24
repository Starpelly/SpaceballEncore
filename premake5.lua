local devkitpro = os.getenv("DEVKITPRO");
local devkitarm = os.getenv("DEVKITARM");

workspace "Spaceball"
	architecture "x64"
	startproject "Spaceball"

	configurations
	{
		"Debug",
		"Release"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Desktop"
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
		"opengl32.lib",
		"winmm"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PLATFORM_DESKTOP", "ENGINE_RAYLIB", "GRAPHICS_API_OPENGL_33", "_WINSOCK_DEPRECATED_NO_WARNINGS", "_WIN32"
		}

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "on"
		runtime "Debug"
		buildoptions "/MTd"

	filter "configurations:Release"
		defines "RELEASE"
		optimize "on"
		runtime "Release"
		buildoptions "/MT"

project "Wii"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/%{cfg.buildcfg}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	makesettings [[
		CXX = arm-none-eabi-g++
		LD = arm-none-eabi-ld
	]]

	files
	{
		"src/**.h",
		"src/**.c",
		"src/**.hpp",
		"src/**.cpp",
	}

	includedirs
	{
		"src"
	}
	
	filter "configurations:Debug"
		defines "DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE"
		optimize "on"