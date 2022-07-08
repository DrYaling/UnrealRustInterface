// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class unreal_rs : ModuleRules
{
	public unreal_rs(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            // Add the import library
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "../ThirdParty/UnrealRsLibrary/Win64", "unreal_rs.dll.lib"));

            // Delay-load the DLL, so we can load it from the right place first
            PublicDelayLoadDLLs.Add("unreal_rs.dll");

            // Ensure that the DLL is staged along with the executable
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/UnrealRsLibrary/Win64/unreal_rs.dll");
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            //PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "libExampleLibrary.dylib"));
            //RuntimeDependencies.Add(
            //    "$(PluginDir)/Source/ThirdParty/UnrealRsLibrary/Mac/Release/libExampleLibrary.dylib");
        }
PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Projects"
        });
		
		DynamicallyLoadedModuleNames.AddRange(new string[]
		{
			// ... add any modules that your module loads dynamically here ...
		});
	}
}
