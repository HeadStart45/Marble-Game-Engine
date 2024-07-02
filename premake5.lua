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

IncludeDir = {}
IncludeDir["GLFW"] = "Marble/vendor/GLFW/include"
IncludeDir["Glad"] = "Marble/vendor/Glad/include"
IncludeDir["Imgui"] = "Marble/vendor/imgui/include"
include "Marble/vendor/GLFW"
include "Marble/vendor/Glad"
include "Marble/vendor/imgui"

project "Marble"
	location "Marble"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "mbpch.h"
	pchsource "Marble/src/mbpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.Imgui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"Imgui",
		"opengl32.lib",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MB_BUILD_DLL",
			"MB_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines
		{
			"MB_DEBUG",
			"MB_ENABLE_ASSERTS"
		}
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "MB_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "MB_DIST"
		buildoptions "/MD"
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
		defines
		{
			"MB_DEBUG",
			"MB_ENABLE_ASSERTS"
		} 
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "MB_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "MB_DIST"
		buildoptions "/MD"
		optimize "On"