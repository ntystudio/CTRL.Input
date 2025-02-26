// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CTRLInput : ModuleRules
{
	public CTRLInput(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
		[
			"Core",
			"DeveloperSettings"
		]);


		PrivateDependencyModuleNames.AddRange(
		[
			"CoreUObject",
			"CTRLGas",
			"Engine",
			"EnhancedInput",
			"GameplayTags",
			"Slate",
			"SlateCore",
		]);
	}
}