using UnrealBuildTool;
using System.IO;
 
public class XPS : ModuleRules
{
    public XPS(TargetInfo Target)
    {
        PrivateIncludePaths.AddRange(new string[] { "XPS/Private" });
        PublicIncludePaths.AddRange(new string[] { "XPS/Public" });
 
        PublicDependencyModuleNames.AddRange(
            new string[] {
                "Engine",
                "InputCore",
                "Core",
                "CoreUObject",
				"Slate",
                "SlateCore",
                "EditorStyle",
            }
            );
        PublicDependencyModuleNames.AddRange(
            new string[] {
				//"LevelEditor",
            }
            );

        DynamicallyLoadedModuleNames.AddRange(
            new string[] {
                //"LevelEditor"
            }
            );

    }
}