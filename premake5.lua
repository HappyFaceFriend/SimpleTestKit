workspace "SimpleTestKit"
	architecture "x64"
	platforms {"Win64"}
	configurations {"Debug", "Release"}

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	project "SimpleTestKit"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"
		
		outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
		
		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
		}
		includedirs
		{
			"%{prj.name}/src",
		}


		filter "configurations:Debug"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			runtime "Release"
			optimize "on"