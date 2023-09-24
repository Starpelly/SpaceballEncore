local dolphinPath = "C:/Users/Braedon/Documents/Dolphin-x64/Dolphin.exe";

workspace "Spaceball"
	architecture "x64"
	startproject "Wii"

	configurations
	{
		"Debug",
		"Release"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Wii"
	kind "Makefile"
	location "Wii"

	targetdir ("%{wks.location}/bin/%{cfg.buildcfg}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	buildcommands
	{
		"make",
		dolphinPath .. " %%{prj.name}.dol" .. " /b /e"
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

		"Spaceball/src/**.cpp",
		"Spaceball/src/**.hpp",
	}

	includedirs
	{
		"C:/GRRLIB/GRRLIB/GRRLIB",
		"C:/devkitPro/libogc/include",

		"Spaceball/src",
	}