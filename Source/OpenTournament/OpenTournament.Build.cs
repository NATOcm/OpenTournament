// Copyright (c) 2019-2020 Open Tournament Project, All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class OpenTournament : ModuleRules
{
    public OpenTournament(ReadOnlyTargetRules Target) : base(Target)
    {
        bLegacyPublicIncludePaths = true;
        ShadowVariableWarningLevel = WarningLevel.Error;

        PrivatePCHHeaderFile = "OpenTournament.h";
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Slate", "SlateCore", "GameplayAbilities", "GameplayTags", "GameplayTasks" });

        // Reference:
        // https://docs.unrealengine.com/en-US/Programming/BuildTools/UnrealBuildTool/ModuleFiles/index.html
        PublicIncludePaths.AddRange(new string[] { "OpenTournament", "OpenTournament/Data", "OpenTournament/Enums", "OpenTournament/GAS", "OpenTournament/Widgets" });
    }
}
