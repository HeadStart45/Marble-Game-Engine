workspace "Marble"
	architecture "x64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist",
	}


outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "Marble"
	location "Marble"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"

		defines
		{
			"MB_BUILD_DLL",
			"MB_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MB_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Marble/vendor/spdlog/include",
		"Marble/src"
	}

	links
	{
		"Marble"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"

		defines
		{
			"MB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MB_DIST"
		optimize "On"