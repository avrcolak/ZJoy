// This is free and unencumbered software released into the public domain.

using UnrealBuildTool;
using System.Collections.Generic;

public class ZJoyTarget : TargetRules
{
	public ZJoyTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "ZJoy" } );
	}
}
