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
	location "Desktop"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/%{cfg.buildcfg}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",

		"%{prj.name}/vendor/raylib/src/*.c",
		"%{prj.name}/vendor/raylib/src/*.h",
		"%{prj.name}/vendor/raylib/src/external/*.h",
		"%{prj.name}/vendor/raylib/src/external/*.c",
	}

	removefiles
	{
		"%{prj.name}/vendor/raylib/src/external/qoaplay.c"
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/raylib/src/external",
		"%{prj.name}/vendor/raylib/src/external/glfw/include",
		"%{prj.name}/vendor/raylib/src",
	}

	links
	{
		"opengl32.lib",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PLATFORM_DESKTOP", "GRAPHICS_API_OPENGL_33", "WIN32"
		}

		links
		{
			"imm32",
			"winmm",
			"version"
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
	kind "Makefile"
	location "Wii"

	targetdir ("%{wks.location}/bin/%{cfg.buildcfg}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	buildcommands
	{
		"make"
	}

	rebuildcommands
	{
		"make -B"
	}

	cleancommands
	{
		"make clean"
	}

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"C:/GRRLIB/GRRLIB/GRRLIB",
		"C:/devkitPro/libogc/include"
	}