workspace "Wonder"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Wonder"
	location "Wonder"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WD_PLATFORM_WINDOWS",
			"WD_BUILD_DLL"
		}	

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "WD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WD_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "WD_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
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
		"Wonder/vendor/spdlog/include",
		"Wonder/src"
	}

	links
	{
		"Wonder"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "WD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "WD_DIST"
		optimize "On"