// This is free and unencumbered software released into the public domain.

using UnrealBuildTool;
using System.Collections.Generic;

public class ZJoyEditorTarget : TargetRules
{
	public ZJoyEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "ZJoy" } );
	}
}
