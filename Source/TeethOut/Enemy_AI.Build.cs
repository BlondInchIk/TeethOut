// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

//Объявление модулей
public class Enemy_AI : ModuleRules
{
	public Enemy_AI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", 
			"InputCore", "HeadMountedDisplay", "NavigationSystem" });
	}
}
