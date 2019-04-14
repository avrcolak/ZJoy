"C:\Program Files\Epic Games\UE_4.22\Engine\Binaries\DotNET\UnrealBuildTool.exe" -projectfiles -project="%CI_PROJECT_DIR%\ZJoy.uproject" -game -rocket -progress

"C:\Program Files\Epic Games\UE_4.22\Engine\Binaries\DotNET\UnrealBuildTool.exe" ZJoy Development Win64 -project="%CI_PROJECT_DIR%\ZJoy.uproject" -rocket -editorrecompile -progress -noubtmakefiles -NoHotReloadFromIDE -2019

call "C:\Program Files\Epic Games\UE_4.22\Engine\Build\BatchFiles\RunUAT.bat" BuildCookRun -project="%CI_PROJECT_DIR%\ZJoy.uproject" -noP4 -platform=Win64 -clientconfig=Development -cook -allmaps -build -stage -pak -archive
