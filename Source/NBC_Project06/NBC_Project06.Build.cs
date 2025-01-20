// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NBC_Project06 : ModuleRules
{
	public NBC_Project06(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
