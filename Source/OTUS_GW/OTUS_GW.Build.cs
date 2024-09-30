// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OTUS_GW : ModuleRules
{
	public OTUS_GW(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
