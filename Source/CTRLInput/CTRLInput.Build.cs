// SPDX-FileCopyrightText: © 2025 NTY.studio
// SPDX-License-Identifier: MIT

using UnrealBuildTool;

public class CTRLInput : ModuleRules
{
	public CTRLInput(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"DeveloperSettings"
		});


		PrivateDependencyModuleNames.AddRange(new[]
		{
			"CoreUObject",
			"CTRLGas",
			"Engine",
			"EnhancedInput",
			"GameplayTags",
			"Slate",
			"SlateCore",
		});
	}
}