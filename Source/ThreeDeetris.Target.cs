// Copyright (c) 2022 Gargowle. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ThreeDeetrisTarget : TargetRules
{
	public ThreeDeetrisTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ThreeDeetris" } );
	}
}
