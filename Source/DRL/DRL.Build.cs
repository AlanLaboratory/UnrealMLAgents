// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;
using System.IO;
using System.Collections.Generic;
using System.Reflection;

public class DRL : ModuleRules
{
	public DRL(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
            new string[] {
				Path.Combine(ModuleDirectory, "Public"),
			}
		);

		PrivateIncludePathModuleNames.AddRange(
			new string[]
			{ 
                "Policies",
				"Communicator",
			}
		);

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "UMG",
                "Json"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"Sensors",
				"Actuators",
			}
		);
	}

}
