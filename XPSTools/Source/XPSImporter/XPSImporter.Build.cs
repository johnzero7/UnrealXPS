using UnrealBuildTool;

public class XPSImporter : ModuleRules
{
	public XPSImporter(TargetInfo Target)
	{
		PrivateIncludePathModuleNames.AddRange(
			new string[] {
			});

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"XPS",
				"UnrealEd",
			});

		DynamicallyLoadedModuleNames.AddRange(
			new string[] {
			});
	}
}
